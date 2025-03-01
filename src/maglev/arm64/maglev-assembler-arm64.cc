// Copyright 2022 the V8 project authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "src/codegen/interface-descriptors-inl.h"
#include "src/deoptimizer/deoptimizer.h"
#include "src/maglev/arm64/maglev-assembler-arm64-inl.h"
#include "src/maglev/maglev-graph.h"

namespace v8 {
namespace internal {
namespace maglev {

#define __ masm->

void MaglevAssembler::Allocate(RegisterSnapshot& register_snapshot,
                               Register object, int size_in_bytes,
                               AllocationType alloc_type,
                               AllocationAlignment alignment) {
  // TODO(victorgomes): Call the runtime for large object allocation.
  // TODO(victorgomes): Support double alignment.
  DCHECK_EQ(alignment, kTaggedAligned);
  size_in_bytes = ALIGN_TO_ALLOCATION_ALIGNMENT(size_in_bytes);
  if (v8_flags.single_generation) {
    alloc_type = AllocationType::kOld;
  }
  bool in_new_space = alloc_type == AllocationType::kYoung;
  ExternalReference top =
      in_new_space
          ? ExternalReference::new_space_allocation_top_address(isolate_)
          : ExternalReference::old_space_allocation_top_address(isolate_);
  ExternalReference limit =
      in_new_space
          ? ExternalReference::new_space_allocation_limit_address(isolate_)
          : ExternalReference::old_space_allocation_limit_address(isolate_);

  ZoneLabelRef done(this);
  UseScratchRegisterScope temps(this);
  Register scratch = temps.AcquireX();
  // We are a bit short on registers, so we use the same register for {object}
  // and {new_top}. Once we have defined {new_top}, we don't use {object} until
  // {new_top} is used for the last time. And there (at the end of this
  // function), we recover the original {object} from {new_top} by subtracting
  // {size_in_bytes}.
  Register new_top = object;
  // Check if there is enough space.
  Ldr(object, ExternalReferenceAsOperand(top, scratch));
  Add(new_top, object, size_in_bytes);
  Ldr(scratch, ExternalReferenceAsOperand(limit, scratch));
  Cmp(new_top, scratch);
  // Otherwise call runtime.
  JumpToDeferredIf(
      ge,
      [](MaglevAssembler* masm, RegisterSnapshot register_snapshot,
         Register object, Builtin builtin, int size_in_bytes,
         ZoneLabelRef done) {
        // Remove {object} from snapshot, since it is the returned allocated
        // HeapObject.
        register_snapshot.live_registers.clear(object);
        register_snapshot.live_tagged_registers.clear(object);
        {
          SaveRegisterStateForCall save_register_state(masm, register_snapshot);
          using D = AllocateDescriptor;
          __ Move(D::GetRegisterParameter(D::kRequestedSize), size_in_bytes);
          __ CallBuiltin(builtin);
          save_register_state.DefineSafepoint();
          __ Move(object, kReturnRegister0);
        }
        __ jmp(*done);
      },
      register_snapshot, object,
      in_new_space ? Builtin::kAllocateRegularInYoungGeneration
                   : Builtin::kAllocateRegularInOldGeneration,
      size_in_bytes, done);
  // Store new top and tag object.
  Move(ExternalReferenceAsOperand(top, scratch), new_top);
  Add(object, object, kHeapObjectTag - size_in_bytes);
  bind(*done);
}

void MaglevAssembler::AllocateHeapNumber(RegisterSnapshot register_snapshot,
                                         Register result,
                                         DoubleRegister value) {
  // In the case we need to call the runtime, we should spill the value
  // register. Even if it is not live in the next node, otherwise the
  // allocation call might trash it.
  register_snapshot.live_double_registers.set(value);
  Allocate(register_snapshot, result, HeapNumber::kSize);
  // `Allocate` needs 2 scratch registers, so it's important to `AcquireX` after
  // `Allocate` is done and not before.
  UseScratchRegisterScope temps(this);
  Register scratch = temps.AcquireX();
  LoadRoot(scratch, RootIndex::kHeapNumberMap);
  StoreTaggedField(scratch, FieldMemOperand(result, HeapObject::kMapOffset));
  Str(value, FieldMemOperand(result, HeapNumber::kValueOffset));
}

void MaglevAssembler::ToBoolean(Register value, ZoneLabelRef is_true,
                                ZoneLabelRef is_false,
                                bool fallthrough_when_true) {
  UseScratchRegisterScope temps(this);
  Register map = temps.AcquireX();

  // Check if {{value}} is Smi.
  Condition is_smi = CheckSmi(value);
  JumpToDeferredIf(
      is_smi,
      [](MaglevAssembler* masm, Register value, ZoneLabelRef is_true,
         ZoneLabelRef is_false) {
        // Check if {value} is not zero.
        __ CmpTagged(value, Smi::FromInt(0));
        __ JumpIf(eq, *is_false);
        __ Jump(*is_true);
      },
      value, is_true, is_false);

  // Check if {{value}} is false.
  CompareRoot(value, RootIndex::kFalseValue);
  JumpIf(eq, *is_false);

  // Check if {{value}} is empty string.
  CompareRoot(value, RootIndex::kempty_string);
  JumpIf(eq, *is_false);

  // Check if {{value}} is undetectable.
  LoadMap(map, value);
  {
    UseScratchRegisterScope scope(this);
    Register tmp = scope.AcquireW();
    Move(tmp, FieldMemOperand(map, Map::kBitFieldOffset));
    Tst(tmp, Immediate(Map::Bits1::IsUndetectableBit::kMask));
    JumpIf(ne, *is_false);
  }

  // Check if {{value}} is a HeapNumber.
  CompareRoot(map, RootIndex::kHeapNumberMap);
  JumpToDeferredIf(
      eq,
      [](MaglevAssembler* masm, Register value, ZoneLabelRef is_true,
         ZoneLabelRef is_false) {
        UseScratchRegisterScope scope(masm);
        DoubleRegister value_double = scope.AcquireD();
        __ Ldr(value_double, FieldMemOperand(value, HeapNumber::kValueOffset));
        __ Fcmp(value_double, 0.0);
        __ JumpIf(eq, *is_false);
        __ JumpIf(vs, *is_false);  // NaN check
        __ Jump(*is_true);
      },
      value, is_true, is_false);

  // Check if {{value}} is a BigInt.
  CompareRoot(map, RootIndex::kBigIntMap);
  JumpToDeferredIf(
      eq,
      [](MaglevAssembler* masm, Register value, ZoneLabelRef is_true,
         ZoneLabelRef is_false) {
        UseScratchRegisterScope scope(masm);
        Register tmp = scope.AcquireW();
        __ Ldr(tmp, FieldMemOperand(value, BigInt::kBitfieldOffset));
        __ Tst(tmp, Immediate(BigInt::LengthBits::kMask));
        __ JumpIf(eq, *is_false);
        __ Jump(*is_true);
      },
      value, is_true, is_false);

  // Otherwise true.
  if (!fallthrough_when_true) {
    Jump(*is_true);
  }
}

void MaglevAssembler::Prologue(Graph* graph) {
  if (v8_flags.maglev_ool_prologue) {
    // TODO(v8:7700): Implement!
    UNREACHABLE();
  }

  CallTarget();

  BailoutIfDeoptimized();

  // Tiering support.
  // TODO(jgruber): Extract to a builtin.
  {
    UseScratchRegisterScope temps(this);
    Register flags = temps.AcquireX();
    // TODO(v8:7700): There are only 2 available scratch registers, we use x9,
    // which is a local caller saved register instead here, since
    // LoadFeedbackVectorFlagsAndJumpIfNeedsProcessing requests a scratch
    // register as well.
    Register feedback_vector = x9;

    DeferredCodeInfo* deferred_flags_need_processing = PushDeferredCode(
        [](MaglevAssembler* masm, Register feedback_vector) {
          ASM_CODE_COMMENT_STRING(masm, "Optimized marker check");
          // TODO(leszeks): This could definitely be a builtin that we
          // tail-call.
          UseScratchRegisterScope temps(masm);
          Register flags = temps.AcquireX();
          __ OptimizeCodeOrTailCallOptimizedCodeSlot(flags, feedback_vector);
          __ Trap();
        },
        feedback_vector);

    Move(feedback_vector,
         compilation_info()->toplevel_compilation_unit()->feedback().object());
    LoadFeedbackVectorFlagsAndJumpIfNeedsProcessing(
        flags, feedback_vector, CodeKind::MAGLEV,
        &deferred_flags_need_processing->deferred_code_label);
  }

  EnterFrame(StackFrame::MAGLEV);

  // Save arguments in frame.
  // TODO(leszeks): Consider eliding this frame if we don't make any calls
  // that could clobber these registers.
  // Push the context and the JSFunction.
  Push(kContextRegister, kJSFunctionRegister);
  // Push the actual argument count and a _possible_ stack slot.
  Push(kJavaScriptCallArgCountRegister, xzr);
  int remaining_stack_slots = code_gen_state()->stack_slots() - 1;
  DCHECK_GE(remaining_stack_slots, 0);
  {
    ASM_CODE_COMMENT_STRING(this, " Stack/interrupt check");
    // Stack check. This folds the checks for both the interrupt stack limit
    // check and the real stack limit into one by just checking for the
    // interrupt limit. The interrupt limit is either equal to the real
    // stack limit or tighter. By ensuring we have space until that limit
    // after building the frame we can quickly precheck both at once.
    UseScratchRegisterScope temps(this);
    Register stack_slots_size = temps.AcquireX();
    Mov(stack_slots_size, fp);
    // Round up the stack slots and max call args separately, since both will be
    // padded by their respective uses.
    const int max_stack_slots_used = RoundUp<2>(remaining_stack_slots) +
                                     RoundUp<2>(graph->max_call_stack_args());
    const int max_stack_size =
        std::max(static_cast<int>(graph->max_deopted_stack_size()),
                 max_stack_slots_used * kSystemPointerSize);
    Sub(stack_slots_size, stack_slots_size, Immediate(max_stack_size));
    Register interrupt_stack_limit = temps.AcquireX();
    LoadStackLimit(interrupt_stack_limit, StackLimitKind::kInterruptStackLimit);
    Cmp(stack_slots_size, interrupt_stack_limit);

    ZoneLabelRef deferred_call_stack_guard_return(this);
    JumpToDeferredIf(
        lo,
        [](MaglevAssembler* masm, ZoneLabelRef done, RegList register_inputs,
           int max_stack_size) {
          ASM_CODE_COMMENT_STRING(masm, "Stack/interrupt call");
          __ PushAll(register_inputs);
          UseScratchRegisterScope temps(masm);
          Register scratch = temps.AcquireX();
          __ Mov(scratch, Smi::FromInt(max_stack_size * kSystemPointerSize));
          __ PushArgument(scratch);
          __ CallRuntime(Runtime::kStackGuardWithGap, 1);
          auto safepoint =
              masm->safepoint_table_builder()->DefineSafepoint(masm);
          safepoint.DefineStackGuardSafepoint(
              RoundUp<2>(register_inputs.Count()));
          __ PopAll(register_inputs);
          __ B(*done);
        },
        deferred_call_stack_guard_return, graph->register_inputs(),
        max_stack_size);
    bind(*deferred_call_stack_guard_return);
  }

  // Initialize stack slots.
  if (graph->tagged_stack_slots() > 0) {
    ASM_CODE_COMMENT_STRING(this, "Initializing stack slots");

    // If tagged_stack_slots is divisible by 2, we overshoot and allocate one
    // extra stack slot, otherwise we allocate exactly the right amount, since
    // one stack has already been allocated.
    int tagged_two_slots_count = graph->tagged_stack_slots() / 2;
    remaining_stack_slots -= 2 * tagged_two_slots_count;

    // Magic value. Experimentally, an unroll size of 8 doesn't seem any
    // worse than fully unrolled pushes.
    const int kLoopUnrollSize = 8;
    if (tagged_two_slots_count < kLoopUnrollSize) {
      for (int i = 0; i < tagged_two_slots_count; i++) {
        Push(xzr, xzr);
      }
    } else {
      UseScratchRegisterScope temps(this);
      Register count = temps.AcquireX();
      // Extract the first few slots to round to the unroll size.
      int first_slots = tagged_two_slots_count % kLoopUnrollSize;
      for (int i = 0; i < first_slots; ++i) {
        Push(xzr, xzr);
      }
      Move(count, tagged_two_slots_count / kLoopUnrollSize);
      // We enter the loop unconditionally, so make sure we need to loop at
      // least once.
      DCHECK_GT(tagged_two_slots_count / kLoopUnrollSize, 0);
      Label loop;
      bind(&loop);
      for (int i = 0; i < kLoopUnrollSize; ++i) {
        Push(xzr, xzr);
      }
      Subs(count, count, Immediate(1));
      b(&loop, gt);
    }
  }
  if (remaining_stack_slots > 0) {
    // Round up.
    remaining_stack_slots += (remaining_stack_slots % 2);
    // Extend sp by the size of the remaining untagged part of the frame,
    // no need to initialise these.
    sub(sp, sp, Immediate(remaining_stack_slots * kSystemPointerSize));
  }
}

void MaglevAssembler::MaybeEmitDeoptBuiltinsCall(size_t eager_deopt_count,
                                                 Label* eager_deopt_entry,
                                                 size_t lazy_deopt_count,
                                                 Label* lazy_deopt_entry) {
  ForceConstantPoolEmissionWithoutJump();

  DCHECK_GE(Deoptimizer::kLazyDeoptExitSize, Deoptimizer::kEagerDeoptExitSize);
  size_t deopt_count = eager_deopt_count + lazy_deopt_count;
  CheckVeneerPool(
      false, false,
      static_cast<int>(deopt_count) * Deoptimizer::kLazyDeoptExitSize);

  UseScratchRegisterScope scope(this);
  Register scratch = scope.AcquireX();
  if (eager_deopt_count > 0) {
    Bind(eager_deopt_entry);
    LoadEntryFromBuiltin(Builtin::kDeoptimizationEntry_Eager, scratch);
    MacroAssembler::Jump(scratch);
  }
  if (lazy_deopt_count > 0) {
    Bind(lazy_deopt_entry);
    LoadEntryFromBuiltin(Builtin::kDeoptimizationEntry_Lazy, scratch);
    MacroAssembler::Jump(scratch);
  }
}

void MaglevAssembler::AllocateTwoByteString(RegisterSnapshot register_snapshot,
                                            Register result, int length) {
  int size = SeqTwoByteString::SizeFor(length);
  Allocate(register_snapshot, result, size);
  UseScratchRegisterScope scope(this);
  Register scratch = scope.AcquireX();
  Move(scratch, 0);
  StoreTaggedField(scratch, FieldMemOperand(result, size - kObjectAlignment));
  LoadRoot(scratch, RootIndex::kStringMap);
  StoreTaggedField(scratch, FieldMemOperand(result, HeapObject::kMapOffset));
  Move(scratch, Name::kEmptyHashField);
  StoreTaggedField(scratch, FieldMemOperand(result, Name::kRawHashFieldOffset));
  Move(scratch, length);
  StoreTaggedField(scratch, FieldMemOperand(result, String::kLengthOffset));
}

void MaglevAssembler::LoadSingleCharacterString(Register result,
                                                Register char_code,
                                                Register scratch) {
  DCHECK_NE(char_code, scratch);
  if (v8_flags.debug_code) {
    Cmp(char_code, Immediate(String::kMaxOneByteCharCode));
    Assert(ls, AbortReason::kUnexpectedValue);
  }
  Register table = scratch;
  LoadRoot(table, RootIndex::kSingleCharacterStringTable);
  Add(table, table, Operand(char_code, LSL, kTaggedSizeLog2));
  DecompressAnyTagged(result, FieldMemOperand(table, FixedArray::kHeaderSize));
}

void MaglevAssembler::StringFromCharCode(RegisterSnapshot register_snapshot,
                                         Label* char_code_fits_one_byte,
                                         Register result, Register char_code,
                                         Register scratch) {
  AssertZeroExtended(char_code);
  DCHECK_NE(char_code, scratch);
  ZoneLabelRef done(this);
  Cmp(char_code, Immediate(String::kMaxOneByteCharCode));
  JumpToDeferredIf(
      hi,
      [](MaglevAssembler* masm, RegisterSnapshot register_snapshot,
         ZoneLabelRef done, Register result, Register char_code,
         Register scratch) {
        // Be sure to save {char_code}. If it aliases with {result}, use
        // the scratch register.
        if (char_code == result) {
          // This is guaranteed to be true since we've already checked
          // char_code != scratch.
          DCHECK_NE(scratch, result);
          __ Move(scratch, char_code);
          char_code = scratch;
        }
        DCHECK(!register_snapshot.live_tagged_registers.has(char_code));
        register_snapshot.live_registers.set(char_code);
        __ AllocateTwoByteString(register_snapshot, result, 1);
        __ And(scratch, char_code, Immediate(0xFFFF));
        __ Strh(scratch.W(),
                FieldMemOperand(result, SeqTwoByteString::kHeaderSize));
        __ B(*done);
      },
      register_snapshot, done, result, char_code, scratch);
  if (char_code_fits_one_byte != nullptr) {
    bind(char_code_fits_one_byte);
  }
  LoadSingleCharacterString(result, char_code, scratch);
  bind(*done);
}

void MaglevAssembler::StringCharCodeAt(RegisterSnapshot& register_snapshot,
                                       Register result, Register string,
                                       Register index, Register instance_type,
                                       Label* result_fits_one_byte) {
  ZoneLabelRef done(this);
  Label seq_string;
  Label cons_string;
  Label sliced_string;

  DeferredCodeInfo* deferred_runtime_call = PushDeferredCode(
      [](MaglevAssembler* masm, RegisterSnapshot register_snapshot,
         ZoneLabelRef done, Register result, Register string, Register index) {
        DCHECK(!register_snapshot.live_registers.has(result));
        DCHECK(!register_snapshot.live_registers.has(string));
        DCHECK(!register_snapshot.live_registers.has(index));
        {
          SaveRegisterStateForCall save_register_state(masm, register_snapshot);
          __ SmiTag(index);
          __ Push(string, index);
          __ Move(kContextRegister, masm->native_context().object());
          // This call does not throw nor can deopt.
          __ CallRuntime(Runtime::kStringCharCodeAt);
          save_register_state.DefineSafepoint();
          __ SmiUntag(kReturnRegister0);
          __ Move(result, kReturnRegister0);
        }
        __ jmp(*done);
      },
      register_snapshot, done, result, string, index);

  // We might need to try more than one time for ConsString, SlicedString and
  // ThinString.
  Label loop;
  bind(&loop);

  if (v8_flags.debug_code) {
    Register scratch = instance_type;

    // Check if {string} is a string.
    AssertNotSmi(string);
    LoadMap(scratch, string);
    CompareInstanceTypeRange(scratch, scratch, FIRST_STRING_TYPE,
                             LAST_STRING_TYPE);
    Check(ls, AbortReason::kUnexpectedValue);

    Ldr(scratch.W(), FieldMemOperand(string, String::kLengthOffset));
    Cmp(index.W(), scratch.W());
    Check(lo, AbortReason::kUnexpectedValue);
  }

  // Get instance type.
  LoadMap(instance_type, string);
  Ldr(instance_type.W(),
      FieldMemOperand(instance_type, Map::kInstanceTypeOffset));

  {
    UseScratchRegisterScope temps(this);
    Register representation = temps.AcquireW();

    // TODO(victorgomes): Add fast path for external strings.
    And(representation, instance_type.W(),
        Immediate(kStringRepresentationMask));
    Cmp(representation, Immediate(kSeqStringTag));
    B(&seq_string, eq);
    Cmp(representation, Immediate(kConsStringTag));
    B(&cons_string, eq);
    Cmp(representation, Immediate(kSlicedStringTag));
    B(&sliced_string, eq);
    Cmp(representation, Immediate(kThinStringTag));
    B(&deferred_runtime_call->deferred_code_label, ne);
    // Fallthrough to thin string.
  }

  // Is a thin string.
  {
    DecompressAnyTagged(string,
                        FieldMemOperand(string, ThinString::kActualOffset));
    B(&loop);
  }

  bind(&sliced_string);
  {
    UseScratchRegisterScope temps(this);
    Register offset = temps.AcquireX();

    Ldr(offset.W(), FieldMemOperand(string, SlicedString::kOffsetOffset));
    SmiUntag(offset);
    DecompressAnyTagged(string,
                        FieldMemOperand(string, SlicedString::kParentOffset));
    Add(index, index, offset);
    B(&loop);
  }

  bind(&cons_string);
  {
    // Reuse {instance_type} register here, since CompareRoot requires a scratch
    // register as well.
    Register second_string = instance_type;
    Ldr(second_string, FieldMemOperand(string, ConsString::kSecondOffset));
    CompareRoot(second_string, RootIndex::kempty_string);
    B(&deferred_runtime_call->deferred_code_label, ne);
    DecompressAnyTagged(string,
                        FieldMemOperand(string, ConsString::kFirstOffset));
    B(&loop);  // Try again with first string.
  }

  bind(&seq_string);
  {
    Label two_byte_string;
    TestAndBranchIfAllClear(instance_type, kOneByteStringTag, &two_byte_string);
    Add(index, index, SeqOneByteString::kHeaderSize - kHeapObjectTag);
    Ldrb(result, MemOperand(string, index));
    B(result_fits_one_byte);

    bind(&two_byte_string);
    Lsl(index, index, 1);
    Add(index, index, SeqTwoByteString::kHeaderSize - kHeapObjectTag);
    Ldrh(result, MemOperand(string, index));
    // Fallthrough.
  }

  bind(*done);

  if (v8_flags.debug_code) {
    // We make sure that the user of this macro is not relying in string and
    // index to not be clobbered.
    if (result != string) {
      Mov(string, Immediate(0xdeadbeef));
    }
    if (result != index) {
      Mov(index, Immediate(0xdeadbeef));
    }
  }
}

void MaglevAssembler::TruncateDoubleToInt32(Register dst, DoubleRegister src) {
  if (CpuFeatures::IsSupported(JSCVT)) {
    Fjcvtzs(dst.W(), src);
    return;
  }

  ZoneLabelRef done(this);
  // Try to convert with an FPU convert instruction. It's trivial to compute
  // the modulo operation on an integer register so we convert to a 64-bit
  // integer.
  //
  // Fcvtzs will saturate to INT64_MIN (0x800...00) or INT64_MAX (0x7FF...FF)
  // when the double is out of range. NaNs and infinities will be converted to 0
  // (as ECMA-262 requires).
  Fcvtzs(dst.X(), src);

  // The values INT64_MIN (0x800...00) or INT64_MAX (0x7FF...FF) are not
  // representable using a double, so if the result is one of those then we know
  // that saturation occurred, and we need to manually handle the conversion.
  //
  // It is easy to detect INT64_MIN and INT64_MAX because adding or subtracting
  // 1 will cause signed overflow.
  Cmp(dst.X(), 1);
  Ccmp(dst.X(), -1, VFlag, vc);

  JumpToDeferredIf(
      vs,
      [](MaglevAssembler* masm, DoubleRegister src, Register dst,
         ZoneLabelRef done) {
        __ MacroAssembler::Push(xzr, src);
        __ CallBuiltin(Builtin::kDoubleToI);
        __ Ldr(dst.W(), MemOperand(sp, 0));
        DCHECK_EQ(xzr.SizeInBytes(), src.SizeInBytes());
        __ Drop(2);
        __ B(*done);
      },
      src, dst, done);

  Bind(*done);
  // Zero extend the converted value to complete the truncation.
  Mov(dst, Operand(dst.W(), UXTW));
}

}  // namespace maglev
}  // namespace internal
}  // namespace v8
