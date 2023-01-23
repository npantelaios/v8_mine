#include "src/ast/ast.h"
#include "src/builtins/builtins-array-gen.h"
#include "src/builtins/builtins-bigint-gen.h"
#include "src/builtins/builtins-collections-gen.h"
#include "src/builtins/builtins-constructor-gen.h"
#include "src/builtins/builtins-data-view-gen.h"
#include "src/builtins/builtins-iterator-gen.h"
#include "src/builtins/builtins-object-gen.h"
#include "src/builtins/builtins-promise-gen.h"
#include "src/builtins/builtins-promise.h"
#include "src/builtins/builtins-proxy-gen.h"
#include "src/builtins/builtins-regexp-gen.h"
#include "src/builtins/builtins-string-gen.h"
#include "src/builtins/builtins-typed-array-gen.h"
#include "src/builtins/builtins-utils-gen.h"
#include "src/builtins/builtins-wasm-gen.h"
#include "src/builtins/builtins.h"
#include "src/codegen/code-factory.h"
#include "src/debug/debug-wasm-objects.h"
#include "src/heap/factory-inl.h"
#include "src/ic/binary-op-assembler.h"
#include "src/ic/handler-configuration-inl.h"
#include "src/objects/arguments.h"
#include "src/objects/bigint.h"
#include "src/objects/call-site-info.h"
#include "src/objects/elements-kind.h"
#include "src/objects/free-space.h"
#include "src/objects/intl-objects.h"
#include "src/objects/js-atomics-synchronization.h"
#include "src/objects/js-break-iterator.h"
#include "src/objects/js-collator.h"
#include "src/objects/js-date-time-format.h"
#include "src/objects/js-display-names.h"
#include "src/objects/js-duration-format.h"
#include "src/objects/js-function.h"
#include "src/objects/js-generator.h"
#include "src/objects/js-list-format.h"
#include "src/objects/js-locale.h"
#include "src/objects/js-number-format.h"
#include "src/objects/js-objects.h"
#include "src/objects/js-plural-rules.h"
#include "src/objects/js-promise.h"
#include "src/objects/js-raw-json.h"
#include "src/objects/js-regexp-string-iterator.h"
#include "src/objects/js-relative-time-format.h"
#include "src/objects/js-segment-iterator.h"
#include "src/objects/js-segmenter.h"
#include "src/objects/js-segments.h"
#include "src/objects/js-shadow-realm.h"
#include "src/objects/js-shared-array.h"
#include "src/objects/js-struct.h"
#include "src/objects/js-temporal-objects.h"
#include "src/objects/js-weak-refs.h"
#include "src/objects/objects.h"
#include "src/objects/ordered-hash-table.h"
#include "src/objects/property-array.h"
#include "src/objects/property-descriptor-object.h"
#include "src/objects/source-text-module.h"
#include "src/objects/swiss-hash-table-helpers.h"
#include "src/objects/swiss-name-dictionary.h"
#include "src/objects/synthetic-module.h"
#include "src/objects/template-objects.h"
#include "src/objects/torque-defined-classes.h"
#include "src/objects/turbofan-types.h"
#include "src/objects/turboshaft-types.h"
#include "src/torque/runtime-support.h"
// Required Builtins:
#include "torque-generated/src/builtins/wasm-tq-csa.h"
#include "torque-generated/src/builtins/array-join-tq-csa.h"
#include "torque-generated/src/builtins/array-slice-tq-csa.h"
#include "torque-generated/src/builtins/base-tq-csa.h"
#include "torque-generated/src/builtins/builtins-string-tq-csa.h"
#include "torque-generated/src/builtins/cast-tq-csa.h"
#include "torque-generated/src/builtins/convert-tq-csa.h"
#include "torque-generated/src/builtins/frame-arguments-tq-csa.h"
#include "torque-generated/src/builtins/ic-tq-csa.h"
#include "torque-generated/src/builtins/math-tq-csa.h"
#include "torque-generated/src/builtins/promise-abstract-operations-tq-csa.h"
#include "torque-generated/src/builtins/torque-internal-tq-csa.h"
#include "torque-generated/src/objects/fixed-array-tq-csa.h"
#include "torque-generated/src/objects/heap-number-tq-csa.h"
#include "torque-generated/src/objects/js-array-tq-csa.h"
#include "torque-generated/src/objects/js-objects-tq-csa.h"
#include "torque-generated/src/objects/name-tq-csa.h"
#include "torque-generated/src/objects/string-tq-csa.h"
#include "torque-generated/test/torque/test-torque-tq-csa.h"
#include "torque-generated/src/objects/intl-objects-tq-csa.h"
#include "torque-generated/src/builtins/wasm-tq-csa.h"
#include "torque-generated/src/wasm/wasm-objects-tq-csa.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm.tq?l=89&c=1
TNode<NativeContext> LoadContextFromFrame_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<WasmInstanceObject> tmp0;
  TNode<NativeContext> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 90);
    tmp0 = WasmBuiltinsAssembler(state_).LoadInstanceFromFrame();
    tmp1 = WasmBuiltinsAssembler(state_).LoadContextFromInstance(TNode<WasmInstanceObject>{tmp0});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 89);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<NativeContext>{tmp1};
}

TF_BUILTIN(WasmInt32ToHeapNumber, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Int32T> parameter0 = UncheckedParameter<Int32T>(Descriptor::kVal);
  USE(parameter0);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Float64T> tmp0;
  TNode<HeapNumber> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 94);
    tmp0 = Convert_float64_int32_0(state_, TNode<Int32T>{parameter0});
    tmp1 = CodeStubAssembler(state_).AllocateHeapNumberWithValue(TNode<Float64T>{tmp0});
    CodeStubAssembler(state_).Return(tmp1);
  }
}

TF_BUILTIN(WasmFuncRefToJS, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<HeapObject> parameter0 = UncheckedParameter<HeapObject>(Descriptor::kVal);
  USE(parameter0);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Oddball> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 100);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = Cast_Null_0(state_, TNode<HeapObject>{parameter0}, &label1);
    ca_.Goto(&block3);
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block4);
    }
  }

  TNode<IntPtrT> tmp2;
  TNode<HeapObject> tmp3;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 104);
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp3 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{ca_.UncheckedCast<WasmInternalFunction>(parameter0), tmp2});
    CodeStubAssembler(state_).Return(tmp3);
  }

  TNode<Oddball> tmp4;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 101);
    tmp4 = Null_0(state_);
    CodeStubAssembler(state_).Return(tmp4);
  }
}

TF_BUILTIN(WasmTaggedNonSmiToInt32, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedParameter<Context>(Descriptor::kContext);
  USE(parameter0);
  TNode<HeapObject> parameter1 = UncheckedParameter<HeapObject>(Descriptor::kVal);
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Int32T> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 111);
    tmp0 = CodeStubAssembler(state_).ChangeTaggedNonSmiToInt32(TNode<Context>{parameter0}, TNode<HeapObject>{parameter1});
    CodeStubAssembler(state_).Return(tmp0);
  }
}

TF_BUILTIN(WasmTaggedToFloat64, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedParameter<Context>(Descriptor::kContext);
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kVal);
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Float64T> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 115);
    tmp0 = CodeStubAssembler(state_).ChangeTaggedToFloat64(TNode<Context>{parameter0}, TNode<Object>{parameter1});
    CodeStubAssembler(state_).Return(tmp0);
  }
}

TF_BUILTIN(WasmMemoryGrow, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Int32T> parameter0 = UncheckedParameter<Int32T>(Descriptor::kNumPages);
  USE(parameter0);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<BoolT> tmp1;
  TNode<BoolT> tmp2;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 119);
    tmp0 = CodeStubAssembler(state_).ChangeInt32ToIntPtr(TNode<Int32T>{parameter0});
    tmp1 = CodeStubAssembler(state_).IsValidPositiveSmi(TNode<IntPtrT>{tmp0});
    tmp2 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp1});
    ca_.Branch(tmp2, &block1, std::vector<compiler::Node*>{}, &block2, std::vector<compiler::Node*>{});
  }

  TNode<Int32T> tmp3;
  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 120);
    tmp3 = Int32Constant_0(state_, IntegerLiteral(true, 0x1ull));
    CodeStubAssembler(state_).Return(tmp3);
  }

  TNode<WasmInstanceObject> tmp4;
  TNode<NativeContext> tmp5;
  TNode<Smi> tmp6;
  TNode<Smi> tmp7;
  TNode<Int32T> tmp8;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 121);
    tmp4 = WasmBuiltinsAssembler(state_).LoadInstanceFromFrame();
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 122);
    tmp5 = WasmBuiltinsAssembler(state_).LoadContextFromInstance(TNode<WasmInstanceObject>{tmp4});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 124);
    tmp6 = CodeStubAssembler(state_).SmiFromInt32(TNode<Int32T>{parameter0});
    tmp7 = TORQUE_CAST(CodeStubAssembler(state_).CallRuntime(Runtime::kWasmMemoryGrow, tmp5, tmp4, tmp6)); 
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 125);
    tmp8 = CodeStubAssembler(state_).SmiToInt32(TNode<Smi>{tmp7});
    CodeStubAssembler(state_).Return(tmp8);
  }
}

TF_BUILTIN(WasmTableInit, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Uint32T> parameter0 = UncheckedParameter<Uint32T>(Descriptor::kDstRaw);
  USE(parameter0);
  TNode<Uint32T> parameter1 = UncheckedParameter<Uint32T>(Descriptor::kSrcRaw);
  USE(parameter1);
  TNode<Uint32T> parameter2 = UncheckedParameter<Uint32T>(Descriptor::kSizeRaw);
  USE(parameter2);
  TNode<Smi> parameter3 = UncheckedParameter<Smi>(Descriptor::kTableIndex);
  USE(parameter3);
  TNode<Smi> parameter4 = UncheckedParameter<Smi>(Descriptor::kSegmentIndex);
  USE(parameter4);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    ca_.Goto(&block0);

  TNode<WasmInstanceObject> tmp0;
  TNode<Smi> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 132);
    tmp0 = WasmBuiltinsAssembler(state_).LoadInstanceFromFrame();
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 133);
    compiler::CodeAssemblerLabel label2(&ca_);
    tmp1 = Convert_PositiveSmi_uint32_0(state_, TNode<Uint32T>{parameter0}, &label2);
    ca_.Goto(&block3);
    if (label2.is_used()) {
      ca_.Bind(&label2);
      ca_.Goto(&block4);
    }
  }

  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.Goto(&block2);
  }

  TNode<Smi> tmp3;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 134);
    compiler::CodeAssemblerLabel label4(&ca_);
    tmp3 = Convert_PositiveSmi_uint32_0(state_, TNode<Uint32T>{parameter1}, &label4);
    ca_.Goto(&block5);
    if (label4.is_used()) {
      ca_.Bind(&label4);
      ca_.Goto(&block6);
    }
  }

  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.Goto(&block2);
  }

  TNode<Smi> tmp5;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 135);
    compiler::CodeAssemblerLabel label6(&ca_);
    tmp5 = Convert_PositiveSmi_uint32_0(state_, TNode<Uint32T>{parameter2}, &label6);
    ca_.Goto(&block7);
    if (label6.is_used()) {
      ca_.Bind(&label6);
      ca_.Goto(&block8);
    }
  }

  if (block8.is_used()) {
    ca_.Bind(&block8);
    ca_.Goto(&block2);
  }

  TNode<NativeContext> tmp7;
  if (block7.is_used()) {
    ca_.Bind(&block7);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 137);
    tmp7 = WasmBuiltinsAssembler(state_).LoadContextFromInstance(TNode<WasmInstanceObject>{tmp0});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 136);
    CodeStubAssembler(state_).TailCallRuntime(Runtime::kWasmTableInit, tmp7, tmp0, parameter3, parameter4, tmp1, tmp3, tmp5);
  }

  if (block2.is_used()) {
    ca_.Bind(&block2);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 140);
   CodeStubAssembler(state_).TailCallBuiltin(Builtin::kThrowWasmTrapTableOutOfBounds, TNode<Object>());
  }
}

TF_BUILTIN(WasmTableCopy, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Uint32T> parameter0 = UncheckedParameter<Uint32T>(Descriptor::kDstRaw);
  USE(parameter0);
  TNode<Uint32T> parameter1 = UncheckedParameter<Uint32T>(Descriptor::kSrcRaw);
  USE(parameter1);
  TNode<Uint32T> parameter2 = UncheckedParameter<Uint32T>(Descriptor::kSizeRaw);
  USE(parameter2);
  TNode<Smi> parameter3 = UncheckedParameter<Smi>(Descriptor::kDstTable);
  USE(parameter3);
  TNode<Smi> parameter4 = UncheckedParameter<Smi>(Descriptor::kSrcTable);
  USE(parameter4);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    ca_.Goto(&block0);

  TNode<WasmInstanceObject> tmp0;
  TNode<Smi> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 148);
    tmp0 = WasmBuiltinsAssembler(state_).LoadInstanceFromFrame();
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 149);
    compiler::CodeAssemblerLabel label2(&ca_);
    tmp1 = Convert_PositiveSmi_uint32_0(state_, TNode<Uint32T>{parameter0}, &label2);
    ca_.Goto(&block3);
    if (label2.is_used()) {
      ca_.Bind(&label2);
      ca_.Goto(&block4);
    }
  }

  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.Goto(&block2);
  }

  TNode<Smi> tmp3;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 150);
    compiler::CodeAssemblerLabel label4(&ca_);
    tmp3 = Convert_PositiveSmi_uint32_0(state_, TNode<Uint32T>{parameter1}, &label4);
    ca_.Goto(&block5);
    if (label4.is_used()) {
      ca_.Bind(&label4);
      ca_.Goto(&block6);
    }
  }

  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.Goto(&block2);
  }

  TNode<Smi> tmp5;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 151);
    compiler::CodeAssemblerLabel label6(&ca_);
    tmp5 = Convert_PositiveSmi_uint32_0(state_, TNode<Uint32T>{parameter2}, &label6);
    ca_.Goto(&block7);
    if (label6.is_used()) {
      ca_.Bind(&label6);
      ca_.Goto(&block8);
    }
  }

  if (block8.is_used()) {
    ca_.Bind(&block8);
    ca_.Goto(&block2);
  }

  TNode<NativeContext> tmp7;
  if (block7.is_used()) {
    ca_.Bind(&block7);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 153);
    tmp7 = WasmBuiltinsAssembler(state_).LoadContextFromInstance(TNode<WasmInstanceObject>{tmp0});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 152);
    CodeStubAssembler(state_).TailCallRuntime(Runtime::kWasmTableCopy, tmp7, tmp0, parameter3, parameter4, tmp1, tmp3, tmp5);
  }

  if (block2.is_used()) {
    ca_.Bind(&block2);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 156);
   CodeStubAssembler(state_).TailCallBuiltin(Builtin::kThrowWasmTrapTableOutOfBounds, TNode<Object>());
  }
}

TF_BUILTIN(WasmTableFill, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Smi> parameter0 = UncheckedParameter<Smi>(Descriptor::kTable);
  USE(parameter0);
  TNode<Uint32T> parameter1 = UncheckedParameter<Uint32T>(Descriptor::kStartRaw);
  USE(parameter1);
  TNode<Uint32T> parameter2 = UncheckedParameter<Uint32T>(Descriptor::kCountRaw);
  USE(parameter2);
  TNode<Object> parameter3 = UncheckedParameter<Object>(Descriptor::kValue);
  USE(parameter3);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    ca_.Goto(&block0);

  TNode<WasmInstanceObject> tmp0;
  TNode<Smi> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 163);
    tmp0 = WasmBuiltinsAssembler(state_).LoadInstanceFromFrame();
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 165);
    compiler::CodeAssemblerLabel label2(&ca_);
    tmp1 = Convert_PositiveSmi_uint32_0(state_, TNode<Uint32T>{parameter1}, &label2);
    ca_.Goto(&block3);
    if (label2.is_used()) {
      ca_.Bind(&label2);
      ca_.Goto(&block4);
    }
  }

  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.Goto(&block2);
  }

  TNode<Smi> tmp3;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 167);
    compiler::CodeAssemblerLabel label4(&ca_);
    tmp3 = Convert_PositiveSmi_uint32_0(state_, TNode<Uint32T>{parameter2}, &label4);
    ca_.Goto(&block5);
    if (label4.is_used()) {
      ca_.Bind(&label4);
      ca_.Goto(&block6);
    }
  }

  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.Goto(&block2);
  }

  TNode<NativeContext> tmp5;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 169);
    tmp5 = WasmBuiltinsAssembler(state_).LoadContextFromInstance(TNode<WasmInstanceObject>{tmp0});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 168);
    CodeStubAssembler(state_).TailCallRuntime(Runtime::kWasmTableFill, tmp5, tmp0, parameter0, tmp1, parameter3, tmp3);
  }

  if (block2.is_used()) {
    ca_.Bind(&block2);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 172);
   CodeStubAssembler(state_).TailCallBuiltin(Builtin::kThrowWasmTrapTableOutOfBounds, TNode<Object>());
  }
}

TF_BUILTIN(WasmTableGrow, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Smi> parameter0 = UncheckedParameter<Smi>(Descriptor::kTable);
  USE(parameter0);
  TNode<Uint32T> parameter1 = UncheckedParameter<Uint32T>(Descriptor::kDeltaRaw);
  USE(parameter1);
  TNode<Object> parameter2 = UncheckedParameter<Object>(Descriptor::kValue);
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<WasmInstanceObject> tmp0;
  TNode<Smi> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 178);
    tmp0 = WasmBuiltinsAssembler(state_).LoadInstanceFromFrame();
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 180);
    compiler::CodeAssemblerLabel label2(&ca_);
    tmp1 = Convert_PositiveSmi_uint32_0(state_, TNode<Uint32T>{parameter1}, &label2);
    ca_.Goto(&block3);
    if (label2.is_used()) {
      ca_.Bind(&label2);
      ca_.Goto(&block4);
    }
  }

  TNode<Smi> tmp3;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 184);
    tmp3 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(true, 0x1ull));
    CodeStubAssembler(state_).Return(tmp3);
  }

  TNode<NativeContext> tmp4;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 182);
    tmp4 = WasmBuiltinsAssembler(state_).LoadContextFromInstance(TNode<WasmInstanceObject>{tmp0});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 181);
    CodeStubAssembler(state_).TailCallRuntime(Runtime::kWasmTableGrow, tmp4, tmp0, parameter0, parameter2, tmp1);
  }
}

TF_BUILTIN(WasmTableGet, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<IntPtrT> parameter0 = UncheckedParameter<IntPtrT>(Descriptor::kTableIndex);
  USE(parameter0);
  TNode<Int32T> parameter1 = UncheckedParameter<Int32T>(Descriptor::kIndex);
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    ca_.Goto(&block0);

  TNode<WasmInstanceObject> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<BoolT> tmp2;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 189);
    tmp0 = WasmBuiltinsAssembler(state_).LoadInstanceFromFrame();
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 190);
    tmp1 = CodeStubAssembler(state_).ChangeInt32ToIntPtr(TNode<Int32T>{parameter1});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 192);
    tmp2 = CodeStubAssembler(state_).IsValidPositiveSmi(TNode<IntPtrT>{parameter0});
    ca_.Branch(tmp2, &block3, std::vector<compiler::Node*>{}, &block4, std::vector<compiler::Node*>{});
  }

  if (block4.is_used()) {
    ca_.Bind(&block4);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/wasm.tq", 192});
      CodeStubAssembler(state_).FailAssert("Torque assert 'IsValidPositiveSmi(tableIndex)' failed", pos_stack);
    }
  }

  TNode<BoolT> tmp3;
  TNode<BoolT> tmp4;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 193);
    tmp3 = CodeStubAssembler(state_).IsValidPositiveSmi(TNode<IntPtrT>{tmp1});
    tmp4 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp3});
    ca_.Branch(tmp4, &block5, std::vector<compiler::Node*>{}, &block6, std::vector<compiler::Node*>{});
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    ca_.Goto(&block2);
  }

  TNode<FixedArray> tmp5;
  TNode<Object> tmp6;
  TNode<WasmTableObject> tmp7;
  TNode<IntPtrT> tmp8;
  TNode<Smi> tmp9;
  TNode<IntPtrT> tmp10;
  TNode<BoolT> tmp11;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 195);
    tmp5 = WasmBuiltinsAssembler(state_).LoadTablesFromInstance(TNode<WasmInstanceObject>{tmp0});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 197);
    tmp6 = CodeStubAssembler(state_).LoadFixedArrayElement(TNode<FixedArray>{tmp5}, TNode<IntPtrT>{parameter0});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 196);
    tmp7 = TORQUE_CAST(TNode<Object>{tmp6});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 198);
    tmp8 = FromConstexpr_intptr_constexpr_int31_0(state_, 20);
    tmp9 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp7, tmp8});
    tmp10 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp9});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 199);
    tmp11 = CodeStubAssembler(state_).IntPtrGreaterThanOrEqual(TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp10});
    ca_.Branch(tmp11, &block7, std::vector<compiler::Node*>{}, &block8, std::vector<compiler::Node*>{});
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    ca_.Goto(&block2);
  }

  TNode<IntPtrT> tmp12;
  TNode<FixedArray> tmp13;
  TNode<Object> tmp14;
  if (block8.is_used()) {
    ca_.Bind(&block8);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 201);
    tmp12 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    tmp13 = CodeStubAssembler(state_).LoadReference<FixedArray>(CodeStubAssembler::Reference{tmp7, tmp12});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 202);
    tmp14 = CodeStubAssembler(state_).LoadFixedArrayElement(TNode<FixedArray>{tmp13}, TNode<IntPtrT>{tmp1});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 203);
    CodeStubAssembler(state_).Return(tmp14);
  }

  if (block2.is_used()) {
    ca_.Bind(&block2);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 205);
   CodeStubAssembler(state_).TailCallBuiltin(Builtin::kThrowWasmTrapTableOutOfBounds, TNode<Object>());
  }
}

TF_BUILTIN(WasmTableSet, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<IntPtrT> parameter0 = UncheckedParameter<IntPtrT>(Descriptor::kTableIndex);
  USE(parameter0);
  TNode<Int32T> parameter1 = UncheckedParameter<Int32T>(Descriptor::kIndex);
  USE(parameter1);
  TNode<Object> parameter2 = UncheckedParameter<Object>(Descriptor::kValue);
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    ca_.Goto(&block0);

  TNode<WasmInstanceObject> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<BoolT> tmp2;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 210);
    tmp0 = WasmBuiltinsAssembler(state_).LoadInstanceFromFrame();
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 211);
    tmp1 = CodeStubAssembler(state_).ChangeInt32ToIntPtr(TNode<Int32T>{parameter1});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 213);
    tmp2 = CodeStubAssembler(state_).IsValidPositiveSmi(TNode<IntPtrT>{parameter0});
    ca_.Branch(tmp2, &block3, std::vector<compiler::Node*>{}, &block4, std::vector<compiler::Node*>{});
  }

  if (block4.is_used()) {
    ca_.Bind(&block4);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/wasm.tq", 213});
      CodeStubAssembler(state_).FailAssert("Torque assert 'IsValidPositiveSmi(tableIndex)' failed", pos_stack);
    }
  }

  TNode<BoolT> tmp3;
  TNode<BoolT> tmp4;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 214);
    tmp3 = CodeStubAssembler(state_).IsValidPositiveSmi(TNode<IntPtrT>{tmp1});
    tmp4 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp3});
    ca_.Branch(tmp4, &block5, std::vector<compiler::Node*>{}, &block6, std::vector<compiler::Node*>{});
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    ca_.Goto(&block2);
  }

  TNode<FixedArray> tmp5;
  TNode<Object> tmp6;
  TNode<WasmTableObject> tmp7;
  TNode<IntPtrT> tmp8;
  TNode<Smi> tmp9;
  TNode<IntPtrT> tmp10;
  TNode<BoolT> tmp11;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 216);
    tmp5 = WasmBuiltinsAssembler(state_).LoadTablesFromInstance(TNode<WasmInstanceObject>{tmp0});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 218);
    tmp6 = CodeStubAssembler(state_).LoadFixedArrayElement(TNode<FixedArray>{tmp5}, TNode<IntPtrT>{parameter0});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 217);
    tmp7 = TORQUE_CAST(TNode<Object>{tmp6});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 220);
    tmp8 = FromConstexpr_intptr_constexpr_int31_0(state_, 20);
    tmp9 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp7, tmp8});
    tmp10 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp9});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 221);
    tmp11 = CodeStubAssembler(state_).IntPtrGreaterThanOrEqual(TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp10});
    ca_.Branch(tmp11, &block7, std::vector<compiler::Node*>{}, &block8, std::vector<compiler::Node*>{});
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    ca_.Goto(&block2);
  }

  TNode<IntPtrT> tmp12;
  TNode<FixedArray> tmp13;
  TNode<Oddball> tmp14;
  if (block8.is_used()) {
    ca_.Bind(&block8);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 223);
    tmp12 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    tmp13 = CodeStubAssembler(state_).LoadReference<FixedArray>(CodeStubAssembler::Reference{tmp7, tmp12});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 224);
    CodeStubAssembler(state_).StoreFixedArrayElement(TNode<FixedArray>{tmp13}, TNode<IntPtrT>{tmp1}, TNode<Object>{parameter2});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 225);
    tmp14 = Undefined_0(state_);
    CodeStubAssembler(state_).Return(tmp14);
  }

  if (block2.is_used()) {
    ca_.Bind(&block2);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 227);
   CodeStubAssembler(state_).TailCallBuiltin(Builtin::kThrowWasmTrapTableOutOfBounds, TNode<Object>());
  }
}

TF_BUILTIN(WasmTableGetFuncRef, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<IntPtrT> parameter0 = UncheckedParameter<IntPtrT>(Descriptor::kTableIndex);
  USE(parameter0);
  TNode<Int32T> parameter1 = UncheckedParameter<Int32T>(Descriptor::kIndex);
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    ca_.Goto(&block0);

  TNode<WasmInstanceObject> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<BoolT> tmp2;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 232);
    tmp0 = WasmBuiltinsAssembler(state_).LoadInstanceFromFrame();
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 233);
    tmp1 = CodeStubAssembler(state_).ChangeInt32ToIntPtr(TNode<Int32T>{parameter1});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 235);
    tmp2 = CodeStubAssembler(state_).IsValidPositiveSmi(TNode<IntPtrT>{parameter0});
    ca_.Branch(tmp2, &block5, std::vector<compiler::Node*>{}, &block6, std::vector<compiler::Node*>{});
  }

  if (block6.is_used()) {
    ca_.Bind(&block6);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/wasm.tq", 235});
      CodeStubAssembler(state_).FailAssert("Torque assert 'IsValidPositiveSmi(tableIndex)' failed", pos_stack);
    }
  }

  TNode<BoolT> tmp3;
  TNode<BoolT> tmp4;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 236);
    tmp3 = CodeStubAssembler(state_).IsValidPositiveSmi(TNode<IntPtrT>{tmp1});
    tmp4 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp3});
    ca_.Branch(tmp4, &block7, std::vector<compiler::Node*>{}, &block8, std::vector<compiler::Node*>{});
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    ca_.Goto(&block2);
  }

  TNode<FixedArray> tmp5;
  TNode<Object> tmp6;
  TNode<WasmTableObject> tmp7;
  TNode<IntPtrT> tmp8;
  TNode<Smi> tmp9;
  TNode<IntPtrT> tmp10;
  TNode<BoolT> tmp11;
  if (block8.is_used()) {
    ca_.Bind(&block8);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 238);
    tmp5 = WasmBuiltinsAssembler(state_).LoadTablesFromInstance(TNode<WasmInstanceObject>{tmp0});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 240);
    tmp6 = CodeStubAssembler(state_).LoadFixedArrayElement(TNode<FixedArray>{tmp5}, TNode<IntPtrT>{parameter0});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 239);
    tmp7 = TORQUE_CAST(TNode<Object>{tmp6});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 241);
    tmp8 = FromConstexpr_intptr_constexpr_int31_0(state_, 20);
    tmp9 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp7, tmp8});
    tmp10 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp9});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 242);
    tmp11 = CodeStubAssembler(state_).IntPtrGreaterThanOrEqual(TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp10});
    ca_.Branch(tmp11, &block9, std::vector<compiler::Node*>{}, &block10, std::vector<compiler::Node*>{});
  }

  if (block9.is_used()) {
    ca_.Bind(&block9);
    ca_.Goto(&block2);
  }

  TNode<IntPtrT> tmp12;
  TNode<FixedArray> tmp13;
  TNode<Object> tmp14;
  TNode<HeapObject> tmp15;
  if (block10.is_used()) {
    ca_.Bind(&block10);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 244);
    tmp12 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    tmp13 = CodeStubAssembler(state_).LoadReference<FixedArray>(CodeStubAssembler::Reference{tmp7, tmp12});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 245);
    tmp14 = CodeStubAssembler(state_).LoadFixedArrayElement(TNode<FixedArray>{tmp13}, TNode<IntPtrT>{tmp1});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 249);
    compiler::CodeAssemblerLabel label16(&ca_);
    tmp15 = CodeStubAssembler(state_).TaggedToHeapObject(TNode<Object>{tmp14}, &label16);
    ca_.Goto(&block13);
    if (label16.is_used()) {
      ca_.Bind(&label16);
      ca_.Goto(&block14);
    }
  }

  if (block14.is_used()) {
    ca_.Bind(&block14);
    ca_.Goto(&block12);
  }

  TNode<IntPtrT> tmp17;
  TNode<Map> tmp18;
  TNode<BoolT> tmp19;
  if (block13.is_used()) {
    ca_.Bind(&block13);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 250);
    tmp17 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp18 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference{tmp15, tmp17});
    tmp19 = CodeStubAssembler(state_).IsTuple2Map(TNode<Map>{tmp18});
    ca_.Branch(tmp19, &block15, std::vector<compiler::Node*>{}, &block16, std::vector<compiler::Node*>{});
  }

  TNode<NativeContext> tmp20;
  TNode<Smi> tmp21;
  TNode<Smi> tmp22;
  if (block15.is_used()) {
    ca_.Bind(&block15);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 257);
    tmp20 = WasmBuiltinsAssembler(state_).LoadContextFromInstance(TNode<WasmInstanceObject>{tmp0});
    tmp21 = CodeStubAssembler(state_).SmiFromIntPtr(TNode<IntPtrT>{parameter0});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 258);
    tmp22 = CodeStubAssembler(state_).SmiFromIntPtr(TNode<IntPtrT>{tmp1});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 256);
    CodeStubAssembler(state_).TailCallRuntime(Runtime::kWasmFunctionTableGet, tmp20, tmp0, tmp21, tmp22);
  }

  if (block16.is_used()) {
    ca_.Bind(&block16);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 251);
    ca_.Goto(&block12);
  }

  if (block12.is_used()) {
    ca_.Bind(&block12);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 253);
    CodeStubAssembler(state_).Return(tmp14);
  }

  if (block2.is_used()) {
    ca_.Bind(&block2);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 260);
   CodeStubAssembler(state_).TailCallBuiltin(Builtin::kThrowWasmTrapTableOutOfBounds, TNode<Object>());
  }
}

TF_BUILTIN(WasmTableSetFuncRef, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<IntPtrT> parameter0 = UncheckedParameter<IntPtrT>(Descriptor::kTableIndex);
  USE(parameter0);
  TNode<Int32T> parameter1 = UncheckedParameter<Int32T>(Descriptor::kIndex);
  USE(parameter1);
  TNode<Object> parameter2 = UncheckedParameter<Object>(Descriptor::kValue);
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    ca_.Goto(&block0);

  TNode<WasmInstanceObject> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<BoolT> tmp2;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 266);
    tmp0 = WasmBuiltinsAssembler(state_).LoadInstanceFromFrame();
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 267);
    tmp1 = CodeStubAssembler(state_).ChangeInt32ToIntPtr(TNode<Int32T>{parameter1});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 269);
    tmp2 = CodeStubAssembler(state_).IsValidPositiveSmi(TNode<IntPtrT>{parameter0});
    ca_.Branch(tmp2, &block3, std::vector<compiler::Node*>{}, &block4, std::vector<compiler::Node*>{});
  }

  if (block4.is_used()) {
    ca_.Bind(&block4);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/wasm.tq", 269});
      CodeStubAssembler(state_).FailAssert("Torque assert 'IsValidPositiveSmi(tableIndex)' failed", pos_stack);
    }
  }

  TNode<BoolT> tmp3;
  TNode<BoolT> tmp4;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 270);
    tmp3 = CodeStubAssembler(state_).IsValidPositiveSmi(TNode<IntPtrT>{tmp1});
    tmp4 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp3});
    ca_.Branch(tmp4, &block5, std::vector<compiler::Node*>{}, &block6, std::vector<compiler::Node*>{});
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    ca_.Goto(&block2);
  }

  TNode<FixedArray> tmp5;
  TNode<Object> tmp6;
  TNode<WasmTableObject> tmp7;
  TNode<IntPtrT> tmp8;
  TNode<Smi> tmp9;
  TNode<IntPtrT> tmp10;
  TNode<BoolT> tmp11;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 272);
    tmp5 = WasmBuiltinsAssembler(state_).LoadTablesFromInstance(TNode<WasmInstanceObject>{tmp0});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 274);
    tmp6 = CodeStubAssembler(state_).LoadFixedArrayElement(TNode<FixedArray>{tmp5}, TNode<IntPtrT>{parameter0});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 273);
    tmp7 = TORQUE_CAST(TNode<Object>{tmp6});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 276);
    tmp8 = FromConstexpr_intptr_constexpr_int31_0(state_, 20);
    tmp9 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp7, tmp8});
    tmp10 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp9});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 277);
    tmp11 = CodeStubAssembler(state_).IntPtrGreaterThanOrEqual(TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp10});
    ca_.Branch(tmp11, &block7, std::vector<compiler::Node*>{}, &block8, std::vector<compiler::Node*>{});
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    ca_.Goto(&block2);
  }

  TNode<NativeContext> tmp12;
  TNode<Smi> tmp13;
  TNode<Smi> tmp14;
  if (block8.is_used()) {
    ca_.Bind(&block8);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 280);
    tmp12 = WasmBuiltinsAssembler(state_).LoadContextFromInstance(TNode<WasmInstanceObject>{tmp0});
    tmp13 = CodeStubAssembler(state_).SmiFromIntPtr(TNode<IntPtrT>{parameter0});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 281);
    tmp14 = CodeStubAssembler(state_).SmiFromIntPtr(TNode<IntPtrT>{tmp1});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 279);
    CodeStubAssembler(state_).TailCallRuntime(Runtime::kWasmFunctionTableSet, tmp12, tmp0, tmp13, tmp14, parameter2);
  }

  if (block2.is_used()) {
    ca_.Bind(&block2);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 283);
   CodeStubAssembler(state_).TailCallBuiltin(Builtin::kThrowWasmTrapTableOutOfBounds, TNode<Object>());
  }
}

TF_BUILTIN(WasmRefFunc, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Uint32T> parameter0 = UncheckedParameter<Uint32T>(Descriptor::kIndex);
  USE(parameter0);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<WasmInstanceObject> tmp0;
  TNode<FixedArray> tmp1;
  TNode<UintPtrT> tmp2;
  TNode<IntPtrT> tmp3;
  TNode<Object> tmp4;
  TNode<BoolT> tmp5;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 288);
    tmp0 = WasmBuiltinsAssembler(state_).LoadInstanceFromFrame();
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 290);
    tmp1 = WasmBuiltinsAssembler(state_).LoadInternalFunctionsFromInstance(TNode<WasmInstanceObject>{tmp0});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 291);
    tmp2 = CodeStubAssembler(state_).ChangeUint32ToWord(TNode<Uint32T>{parameter0});
    tmp3 = CodeStubAssembler(state_).Signed(TNode<UintPtrT>{tmp2});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 292);
    tmp4 = CodeStubAssembler(state_).LoadFixedArrayElement(TNode<FixedArray>{tmp1}, TNode<IntPtrT>{tmp3});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 295);
    tmp5 = CodeStubAssembler(state_).TaggedIsSmi(TNode<Object>{tmp4});
    ca_.Branch(tmp5, &block3, std::vector<compiler::Node*>{}, &block4, std::vector<compiler::Node*>{});
  }

  TNode<NativeContext> tmp6;
  TNode<Smi> tmp7;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 299);
    tmp6 = WasmBuiltinsAssembler(state_).LoadContextFromInstance(TNode<WasmInstanceObject>{tmp0});
    tmp7 = CodeStubAssembler(state_).SmiFromUint32(TNode<Uint32T>{parameter0});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 298);
    CodeStubAssembler(state_).TailCallRuntime(Runtime::kWasmRefFunc, tmp6, tmp0, tmp7);
  }

  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 296);
    CodeStubAssembler(state_).Return(tmp4);
  }
}

TF_BUILTIN(WasmAllocateFixedArray, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<IntPtrT> parameter0 = UncheckedParameter<IntPtrT>(Descriptor::kSize);
  USE(parameter0);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<BoolT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 304);
    tmp0 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp1 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{parameter0}, TNode<IntPtrT>{tmp0});
    ca_.Branch(tmp1, &block1, std::vector<compiler::Node*>{}, &block2, std::vector<compiler::Node*>{});
  }

  TNode<FixedArray> tmp2;
  if (block1.is_used()) {
    ca_.Bind(&block1);
    tmp2 = kEmptyFixedArray_0(state_);
    CodeStubAssembler(state_).Return(tmp2);
  }

  TNode<FixedArrayBase> tmp3;
  TNode<HeapObject> tmp4;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 305);
    tmp3 = CodeStubAssembler(state_).AllocateFixedArray(ElementsKind::PACKED_ELEMENTS, TNode<IntPtrT>{parameter0}, CodeStubAssembler::AllocationFlag::kNone);
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 162);
    compiler::CodeAssemblerLabel label5(&ca_);
    tmp4 = CodeStubAssembler(state_).TaggedToHeapObject(TNode<Object>{tmp3}, &label5);
    ca_.Goto(&block10);
    if (label5.is_used()) {
      ca_.Bind(&label5);
      ca_.Goto(&block11);
    }
  }

  if (block11.is_used()) {
    ca_.Bind(&block11);
    ca_.Goto(&block8);
  }

  TNode<FixedArray> tmp6;
  if (block10.is_used()) {
    ca_.Bind(&block10);
    compiler::CodeAssemblerLabel label7(&ca_);
    tmp6 = Cast_FixedArray_0(state_, TNode<HeapObject>{tmp4}, &label7);
    ca_.Goto(&block12);
    if (label7.is_used()) {
      ca_.Bind(&label7);
      ca_.Goto(&block13);
    }
  }

  if (block13.is_used()) {
    ca_.Bind(&block13);
    ca_.Goto(&block8);
  }

  TNode<BoolT> tmp8;
  if (block12.is_used()) {
    ca_.Bind(&block12);
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 809);
    tmp8 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block6, tmp8);
  }

  TNode<BoolT> tmp9;
  if (block8.is_used()) {
    ca_.Bind(&block8);
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 808);
    tmp9 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block6, tmp9);
  }

  TNode<BoolT> phi_bb6_5;
  if (block6.is_used()) {
    ca_.Bind(&block6, &phi_bb6_5);
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 814);
    ca_.Branch(phi_bb6_5, &block4, std::vector<compiler::Node*>{}, &block5, std::vector<compiler::Node*>{});
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/cast.tq", 814});
      CodeStubAssembler(state_).FailAssert("Torque assert 'Is<A>(o)' failed", pos_stack);
    }
  }

  TNode<FixedArray> tmp10;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 815);
    tmp10 = TORQUE_CAST(TNode<Object>{tmp3});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 305);
    CodeStubAssembler(state_).Return(tmp10);
  }
}

TF_BUILTIN(WasmThrow, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Object> parameter0 = UncheckedParameter<Object>(Descriptor::kTag);
  USE(parameter0);
  TNode<FixedArray> parameter1 = UncheckedParameter<FixedArray>(Descriptor::kValues);
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<NativeContext> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 310);
    tmp0 = LoadContextFromFrame_0(state_);
    CodeStubAssembler(state_).TailCallRuntime(Runtime::kWasmThrow, tmp0, parameter0, parameter1);
  }
}

TF_BUILTIN(WasmRethrow, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Object> parameter0 = UncheckedParameter<Object>(Descriptor::kException);
  USE(parameter0);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Oddball> tmp0;
  TNode<BoolT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 314);
    tmp0 = Null_0(state_);
    tmp1 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{parameter0}, TNode<HeapObject>{tmp0});
    ca_.Branch(tmp1, &block1, std::vector<compiler::Node*>{}, &block2, std::vector<compiler::Node*>{});
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
   CodeStubAssembler(state_).TailCallBuiltin(Builtin::kThrowWasmTrapRethrowNull, TNode<Object>());
  }

  TNode<NativeContext> tmp2;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 315);
    tmp2 = LoadContextFromFrame_0(state_);
    CodeStubAssembler(state_).TailCallRuntime(Runtime::kWasmReThrow, tmp2, parameter0);
  }
}

TF_BUILTIN(WasmRethrowExplicitContext, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Object> parameter0 = UncheckedParameter<Object>(Descriptor::kException);
  USE(parameter0);
  TNode<Context> parameter1 = UncheckedParameter<Context>(Descriptor::kExplicitContext);
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Oddball> tmp0;
  TNode<BoolT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 322);
    tmp0 = Null_0(state_);
    tmp1 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{parameter0}, TNode<HeapObject>{tmp0});
    ca_.Branch(tmp1, &block1, std::vector<compiler::Node*>{}, &block2, std::vector<compiler::Node*>{});
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
   CodeStubAssembler(state_).TailCallBuiltin(Builtin::kThrowWasmTrapRethrowNull, TNode<Object>());
  }

  if (block2.is_used()) {
    ca_.Bind(&block2);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 323);
    CodeStubAssembler(state_).TailCallRuntime(Runtime::kWasmReThrow, parameter1, parameter0);
  }
}

TF_BUILTIN(WasmTriggerTierUp, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<WasmInstanceObject> tmp0;
  TNode<NativeContext> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 327);
    tmp0 = WasmBuiltinsAssembler(state_).LoadInstanceFromFrame();
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 328);
    tmp1 = LoadContextFromFrame_0(state_);
    CodeStubAssembler(state_).TailCallRuntime(Runtime::kWasmTriggerTierUp, tmp1, tmp0);
  }
}

TF_BUILTIN(WasmStackGuard, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<NativeContext> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 332);
    tmp0 = LoadContextFromFrame_0(state_);
    CodeStubAssembler(state_).TailCallRuntime(Runtime::kWasmStackGuard, tmp0);
  }
}

TF_BUILTIN(WasmStackOverflow, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<NativeContext> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 336);
    tmp0 = LoadContextFromFrame_0(state_);
    CodeStubAssembler(state_).TailCallRuntime(Runtime::kThrowWasmStackOverflow, tmp0);
  }
}

TF_BUILTIN(WasmTraceMemory, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Smi> parameter0 = UncheckedParameter<Smi>(Descriptor::kInfo);
  USE(parameter0);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<NativeContext> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 340);
    tmp0 = LoadContextFromFrame_0(state_);
    CodeStubAssembler(state_).TailCallRuntime(Runtime::kWasmTraceMemory, tmp0, parameter0);
  }
}

TF_BUILTIN(WasmTraceEnter, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<NativeContext> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 344);
    tmp0 = LoadContextFromFrame_0(state_);
    CodeStubAssembler(state_).TailCallRuntime(Runtime::kWasmTraceEnter, tmp0);
  }
}

TF_BUILTIN(WasmTraceExit, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Smi> parameter0 = UncheckedParameter<Smi>(Descriptor::kInfo);
  USE(parameter0);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<NativeContext> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 348);
    tmp0 = LoadContextFromFrame_0(state_);
    CodeStubAssembler(state_).TailCallRuntime(Runtime::kWasmTraceExit, tmp0, parameter0);
  }
}

TF_BUILTIN(WasmAllocateJSArray, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedParameter<Context>(Descriptor::kContext);
  USE(parameter0);
  TNode<Smi> parameter1 = UncheckedParameter<Smi>(Descriptor::kSize);
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Map> tmp0;
  TNode<JSArray> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 352);
    tmp0 = GetFastPackedElementsJSArrayMap_0(state_, TNode<Context>{parameter0});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 353);
    tmp1 = CodeStubAssembler(state_).AllocateJSArray(ElementsKind::PACKED_ELEMENTS, TNode<Map>{tmp0}, TNode<Smi>{parameter1}, TNode<Smi>{parameter1});
    CodeStubAssembler(state_).Return(tmp1);
  }
}

TF_BUILTIN(WasmAllocateStructWithRtt, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Map> parameter0 = UncheckedParameter<Map>(Descriptor::kRtt);
  USE(parameter0);
  TNode<Int32T> parameter1 = UncheckedParameter<Int32T>(Descriptor::kInstanceSize);
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<HeapObject> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<Object> tmp3;
  TNode<IntPtrT> tmp4;
  TNode<WasmStruct> tmp5;
  TNode<IntPtrT> tmp6;
  TNode<FixedArray> tmp7;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 358);
    tmp0 = Convert_intptr_int32_0(state_, TNode<Int32T>{parameter1});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 357);
    tmp1 = CodeStubAssembler(state_).Allocate(TNode<IntPtrT>{tmp0}, CodeStubAssembler::AllocationFlag::kAllowLargeObjectAllocation);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 360);
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    std::tie(tmp3, tmp4) = UnsafeConstCast_Map_0(state_, TorqueStructReference_Map_0{TNode<Object>{tmp1}, TNode<IntPtrT>{tmp2}, TorqueStructUnsafe_0{}}).Flatten();
    CodeStubAssembler(state_).StoreReference<Map>(CodeStubAssembler::Reference{tmp3, tmp4}, parameter0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 362);
    tmp5 = TORQUE_CAST(TNode<HeapObject>{tmp1});
    tmp6 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp7 = kEmptyFixedArray_0(state_);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp5, tmp6}, tmp7);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 363);
    CodeStubAssembler(state_).Return(tmp1);
  }
}

TF_BUILTIN(WasmAllocateArray_Uninitialized, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Map> parameter0 = UncheckedParameter<Map>(Descriptor::kRtt);
  USE(parameter0);
  TNode<Uint32T> parameter1 = UncheckedParameter<Uint32T>(Descriptor::kLength);
  USE(parameter1);
  TNode<Uint32T> parameter2 = UncheckedParameter<Uint32T>(Descriptor::kElementSize);
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<IntPtrT> tmp3;
  TNode<IntPtrT> tmp4;
  TNode<IntPtrT> tmp5;
  TNode<HeapObject> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<Object> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<WasmArray> tmp10;
  TNode<IntPtrT> tmp11;
  TNode<FixedArray> tmp12;
  TNode<WasmArray> tmp13;
  TNode<IntPtrT> tmp14;
  TNode<WasmArray> tmp15;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 372);
    tmp0 = Convert_intptr_uint32_0(state_, TNode<Uint32T>{parameter1});
    tmp1 = Convert_intptr_uint32_0(state_, TNode<Uint32T>{parameter2});
    tmp2 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp0}, TNode<IntPtrT>{tmp1});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 371);
    tmp3 = AlignTagged_0(state_, TNode<IntPtrT>{tmp2});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 373);
    tmp4 = Convert_intptr_constexpr_int32_0(state_, WasmArray::kHeaderSize);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 371);
    tmp5 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp3}, TNode<IntPtrT>{tmp4});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 374);
    tmp6 = CodeStubAssembler(state_).Allocate(TNode<IntPtrT>{tmp5}, CodeStubAssembler::AllocationFlag::kAllowLargeObjectAllocation);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 376);
    tmp7 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    std::tie(tmp8, tmp9) = UnsafeConstCast_Map_0(state_, TorqueStructReference_Map_0{TNode<Object>{tmp6}, TNode<IntPtrT>{tmp7}, TorqueStructUnsafe_0{}}).Flatten();
    CodeStubAssembler(state_).StoreReference<Map>(CodeStubAssembler::Reference{tmp8, tmp9}, parameter0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 378);
    tmp10 = TORQUE_CAST(TNode<HeapObject>{tmp6});
    tmp11 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp12 = kEmptyFixedArray_0(state_);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp10, tmp11}, tmp12);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 379);
    tmp13 = TORQUE_CAST(TNode<HeapObject>{tmp6});
    tmp14 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    CodeStubAssembler(state_).StoreReference<Uint32T>(CodeStubAssembler::Reference{tmp13, tmp14}, parameter1);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 380);
    tmp15 = TORQUE_CAST(TNode<HeapObject>{tmp6});
    CodeStubAssembler(state_).Return(tmp15);
  }
}

TF_BUILTIN(WasmArrayNewSegment, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Uint32T> parameter0 = UncheckedParameter<Uint32T>(Descriptor::kDataSegment);
  USE(parameter0);
  TNode<Uint32T> parameter1 = UncheckedParameter<Uint32T>(Descriptor::kOffset);
  USE(parameter1);
  TNode<Uint32T> parameter2 = UncheckedParameter<Uint32T>(Descriptor::kLength);
  USE(parameter2);
  TNode<Map> parameter3 = UncheckedParameter<Map>(Descriptor::kRtt);
  USE(parameter3);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<WasmInstanceObject> tmp0;
  TNode<Smi> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 385);
    tmp0 = WasmBuiltinsAssembler(state_).LoadInstanceFromFrame();
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 388);
    compiler::CodeAssemblerLabel label2(&ca_);
    tmp1 = Convert_PositiveSmi_uint32_0(state_, TNode<Uint32T>{parameter1}, &label2);
    ca_.Goto(&block5);
    if (label2.is_used()) {
      ca_.Bind(&label2);
      ca_.Goto(&block6);
    }
  }

  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 394);
   CodeStubAssembler(state_).TailCallBuiltin(Builtin::kThrowWasmTrapElementSegmentOutOfBounds, TNode<Object>());
  }

  TNode<Smi> tmp3;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 389);
    compiler::CodeAssemblerLabel label4(&ca_);
    tmp3 = Convert_PositiveSmi_uint32_0(state_, TNode<Uint32T>{parameter2}, &label4);
    ca_.Goto(&block7);
    if (label4.is_used()) {
      ca_.Bind(&label4);
      ca_.Goto(&block8);
    }
  }

  if (block8.is_used()) {
    ca_.Bind(&block8);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 396);
   CodeStubAssembler(state_).TailCallBuiltin(Builtin::kThrowWasmTrapArrayTooLarge, TNode<Object>());
  }

  TNode<NativeContext> tmp5;
  TNode<Smi> tmp6;
  if (block7.is_used()) {
    ca_.Bind(&block7);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 391);
    tmp5 = WasmBuiltinsAssembler(state_).LoadContextFromInstance(TNode<WasmInstanceObject>{tmp0});
    tmp6 = CodeStubAssembler(state_).SmiFromUint32(TNode<Uint32T>{parameter0});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 390);
    CodeStubAssembler(state_).TailCallRuntime(Runtime::kWasmArrayNewSegment, tmp5, tmp0, tmp6, tmp1, tmp3, parameter3);
  }
}

TF_BUILTIN(WasmArrayCopyWithChecks, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Uint32T> parameter0 = UncheckedParameter<Uint32T>(Descriptor::kDstIndex);
  USE(parameter0);
  TNode<Uint32T> parameter1 = UncheckedParameter<Uint32T>(Descriptor::kSrcIndex);
  USE(parameter1);
  TNode<Uint32T> parameter2 = UncheckedParameter<Uint32T>(Descriptor::kLength);
  USE(parameter2);
  TNode<Object> parameter3 = UncheckedParameter<Object>(Descriptor::kDstObject);
  USE(parameter3);
  TNode<Object> parameter4 = UncheckedParameter<Object>(Descriptor::kSrcObject);
  USE(parameter4);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Oddball> tmp0;
  TNode<BoolT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 405);
    tmp0 = Null_0(state_);
    tmp1 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{parameter3}, TNode<HeapObject>{tmp0});
    ca_.Branch(tmp1, &block1, std::vector<compiler::Node*>{}, &block2, std::vector<compiler::Node*>{});
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
   CodeStubAssembler(state_).TailCallBuiltin(Builtin::kThrowWasmTrapNullDereference, TNode<Object>());
  }

  TNode<Oddball> tmp2;
  TNode<BoolT> tmp3;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 406);
    tmp2 = Null_0(state_);
    tmp3 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{parameter4}, TNode<HeapObject>{tmp2});
    ca_.Branch(tmp3, &block3, std::vector<compiler::Node*>{}, &block4, std::vector<compiler::Node*>{});
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
   CodeStubAssembler(state_).TailCallBuiltin(Builtin::kThrowWasmTrapNullDereference, TNode<Object>());
  }

  TNode<WasmArray> tmp4;
  TNode<WasmArray> tmp5;
  TNode<Uint32T> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<Uint32T> tmp8;
  TNode<BoolT> tmp9;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 407);
    tmp4 = TORQUE_CAST(TNode<Object>{parameter3});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 408);
    tmp5 = TORQUE_CAST(TNode<Object>{parameter4});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 411);
    tmp6 = CodeStubAssembler(state_).Uint32Add(TNode<Uint32T>{parameter0}, TNode<Uint32T>{parameter2});
    tmp7 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp8 = CodeStubAssembler(state_).LoadReference<Uint32T>(CodeStubAssembler::Reference{tmp4, tmp7});
    tmp9 = CodeStubAssembler(state_).Uint32GreaterThan(TNode<Uint32T>{tmp6}, TNode<Uint32T>{tmp8});
    ca_.Branch(tmp9, &block7, std::vector<compiler::Node*>{}, &block8, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp10;
  if (block7.is_used()) {
    ca_.Bind(&block7);
    tmp10 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block9, tmp10);
  }

  TNode<Uint32T> tmp11;
  TNode<BoolT> tmp12;
  if (block8.is_used()) {
    ca_.Bind(&block8);
    tmp11 = CodeStubAssembler(state_).Uint32Add(TNode<Uint32T>{parameter0}, TNode<Uint32T>{parameter2});
    tmp12 = CodeStubAssembler(state_).Uint32LessThan(TNode<Uint32T>{tmp11}, TNode<Uint32T>{parameter0});
    ca_.Goto(&block9, tmp12);
  }

  TNode<BoolT> phi_bb9_8;
  if (block9.is_used()) {
    ca_.Bind(&block9, &phi_bb9_8);
    ca_.Branch(phi_bb9_8, &block10, std::vector<compiler::Node*>{}, &block11, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp13;
  if (block10.is_used()) {
    ca_.Bind(&block10);
    tmp13 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block12, tmp13);
  }

  TNode<Uint32T> tmp14;
  TNode<IntPtrT> tmp15;
  TNode<Uint32T> tmp16;
  TNode<BoolT> tmp17;
  if (block11.is_used()) {
    ca_.Bind(&block11);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 412);
    tmp14 = CodeStubAssembler(state_).Uint32Add(TNode<Uint32T>{parameter1}, TNode<Uint32T>{parameter2});
    tmp15 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp16 = CodeStubAssembler(state_).LoadReference<Uint32T>(CodeStubAssembler::Reference{tmp5, tmp15});
    tmp17 = CodeStubAssembler(state_).Uint32GreaterThan(TNode<Uint32T>{tmp14}, TNode<Uint32T>{tmp16});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 411);
    ca_.Goto(&block12, tmp17);
  }

  TNode<BoolT> phi_bb12_8;
  if (block12.is_used()) {
    ca_.Bind(&block12, &phi_bb12_8);
    ca_.Branch(phi_bb12_8, &block13, std::vector<compiler::Node*>{}, &block14, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp18;
  if (block13.is_used()) {
    ca_.Bind(&block13);
    tmp18 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block15, tmp18);
  }

  TNode<Uint32T> tmp19;
  TNode<BoolT> tmp20;
  if (block14.is_used()) {
    ca_.Bind(&block14);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 412);
    tmp19 = CodeStubAssembler(state_).Uint32Add(TNode<Uint32T>{parameter1}, TNode<Uint32T>{parameter2});
    tmp20 = CodeStubAssembler(state_).Uint32LessThan(TNode<Uint32T>{tmp19}, TNode<Uint32T>{parameter1});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 411);
    ca_.Goto(&block15, tmp20);
  }

  TNode<BoolT> phi_bb15_8;
  if (block15.is_used()) {
    ca_.Bind(&block15, &phi_bb15_8);
    ca_.Branch(phi_bb15_8, &block5, std::vector<compiler::Node*>{}, &block6, std::vector<compiler::Node*>{});
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 413);
   CodeStubAssembler(state_).TailCallBuiltin(Builtin::kThrowWasmTrapArrayOutOfBounds, TNode<Object>());
  }

  TNode<Uint32T> tmp21;
  TNode<BoolT> tmp22;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 415);
    tmp21 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp22 = CodeStubAssembler(state_).Word32Equal(TNode<Uint32T>{parameter2}, TNode<Uint32T>{tmp21});
    ca_.Branch(tmp22, &block16, std::vector<compiler::Node*>{}, &block17, std::vector<compiler::Node*>{});
  }

  TNode<Oddball> tmp23;
  if (block16.is_used()) {
    ca_.Bind(&block16);
    tmp23 = Undefined_0(state_);
    CodeStubAssembler(state_).Return(tmp23);
  }

  TNode<NativeContext> tmp24;
  TNode<Smi> tmp25;
  TNode<Smi> tmp26;
  TNode<Smi> tmp27;
  if (block17.is_used()) {
    ca_.Bind(&block17);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 417);
    tmp24 = LoadContextFromFrame_0(state_);
    tmp25 = CodeStubAssembler(state_).SmiFromUint32(TNode<Uint32T>{parameter0});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 418);
    tmp26 = CodeStubAssembler(state_).SmiFromUint32(TNode<Uint32T>{parameter1});
    tmp27 = CodeStubAssembler(state_).SmiFromUint32(TNode<Uint32T>{parameter2});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 416);
    CodeStubAssembler(state_).TailCallRuntime(Runtime::kWasmArrayCopy, tmp24, tmp4, tmp25, tmp5, tmp26, tmp27);
  }
}

TF_BUILTIN(WasmArrayCopy, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Uint32T> parameter0 = UncheckedParameter<Uint32T>(Descriptor::kDstIndex);
  USE(parameter0);
  TNode<Uint32T> parameter1 = UncheckedParameter<Uint32T>(Descriptor::kSrcIndex);
  USE(parameter1);
  TNode<Uint32T> parameter2 = UncheckedParameter<Uint32T>(Descriptor::kLength);
  USE(parameter2);
  TNode<WasmArray> parameter3 = UncheckedParameter<WasmArray>(Descriptor::kDstArray);
  USE(parameter3);
  TNode<WasmArray> parameter4 = UncheckedParameter<WasmArray>(Descriptor::kSrcArray);
  USE(parameter4);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Uint32T> tmp0;
  TNode<BoolT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 424);
    tmp0 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp1 = CodeStubAssembler(state_).Word32Equal(TNode<Uint32T>{parameter2}, TNode<Uint32T>{tmp0});
    ca_.Branch(tmp1, &block1, std::vector<compiler::Node*>{}, &block2, std::vector<compiler::Node*>{});
  }

  TNode<Oddball> tmp2;
  if (block1.is_used()) {
    ca_.Bind(&block1);
    tmp2 = Undefined_0(state_);
    CodeStubAssembler(state_).Return(tmp2);
  }

  TNode<NativeContext> tmp3;
  TNode<Smi> tmp4;
  TNode<Smi> tmp5;
  TNode<Smi> tmp6;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 426);
    tmp3 = LoadContextFromFrame_0(state_);
    tmp4 = CodeStubAssembler(state_).SmiFromUint32(TNode<Uint32T>{parameter0});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 427);
    tmp5 = CodeStubAssembler(state_).SmiFromUint32(TNode<Uint32T>{parameter1});
    tmp6 = CodeStubAssembler(state_).SmiFromUint32(TNode<Uint32T>{parameter2});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 425);
    CodeStubAssembler(state_).TailCallRuntime(Runtime::kWasmArrayCopy, tmp3, parameter3, tmp4, parameter4, tmp5, tmp6);
  }
}

TF_BUILTIN(WasmAllocateObjectWrapper, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedParameter<Context>(Descriptor::kContext);
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kObj);
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<JSObject> tmp0;
  TNode<Symbol> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 437);
    tmp0 = NewJSObject_0(state_, TNode<Context>{parameter0});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 438);
    tmp1 = CodeStubAssembler(state_).WasmWrappedObjectSymbolConstant();
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 439);
    CodeStubAssembler(state_).CallRuntime(Runtime::kCreateDataProperty, parameter0, tmp0, tmp1, parameter1);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 440);
    CodeStubAssembler(state_).Return(tmp0);
  }
}

TF_BUILTIN(WasmSubtypeCheck, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<FixedArray> parameter0 = UncheckedParameter<FixedArray>(Descriptor::kObjectSupertypes);
  USE(parameter0);
  TNode<Map> parameter1 = UncheckedParameter<Map>(Descriptor::kRtt);
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Object> tmp1;
  TNode<WasmTypeInfo> tmp2;
  TNode<IntPtrT> tmp3;
  TNode<Smi> tmp4;
  TNode<IntPtrT> tmp5;
  TNode<Smi> tmp6;
  TNode<BoolT> tmp7;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 446);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 20);
    tmp1 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{parameter1, tmp0});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 445);
    tmp2 = TORQUE_CAST(TNode<Object>{tmp1});
    tmp3 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    tmp4 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp2, tmp3});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 449);
    tmp5 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp6 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{parameter0, tmp5});
    tmp7 = CodeStubAssembler(state_).SmiLessThanOrEqual(TNode<Smi>{tmp6}, TNode<Smi>{tmp4});
    ca_.Branch(tmp7, &block1, std::vector<compiler::Node*>{}, &block2, std::vector<compiler::Node*>{});
  }

  TNode<Int32T> tmp8;
  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 450);
    tmp8 = FromConstexpr_int32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    CodeStubAssembler(state_).Return(tmp8);
  }

  TNode<Object> tmp9;
  TNode<Map> tmp10;
  TNode<BoolT> tmp11;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 454);
    tmp9 = CodeStubAssembler(state_).LoadFixedArrayElement(TNode<FixedArray>{parameter0}, TNode<Smi>{tmp4});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 453);
    tmp10 = TORQUE_CAST(TNode<Object>{tmp9});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 456);
    tmp11 = CodeStubAssembler(state_).TaggedEqual(TNode<HeapObject>{tmp10}, TNode<HeapObject>{parameter1});
    ca_.Branch(tmp11, &block3, std::vector<compiler::Node*>{}, &block4, std::vector<compiler::Node*>{});
  }

  TNode<Int32T> tmp12;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    tmp12 = FromConstexpr_int32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    CodeStubAssembler(state_).Return(tmp12);
  }

  TNode<Int32T> tmp13;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 457);
    tmp13 = FromConstexpr_int32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    CodeStubAssembler(state_).Return(tmp13);
  }
}

TF_BUILTIN(WasmInt32ToNumber, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Int32T> parameter0 = UncheckedParameter<Int32T>(Descriptor::kValue);
  USE(parameter0);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Number> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 461);
    tmp0 = CodeStubAssembler(state_).ChangeInt32ToTagged(TNode<Int32T>{parameter0});
    CodeStubAssembler(state_).Return(tmp0);
  }
}

TF_BUILTIN(WasmUint32ToNumber, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Uint32T> parameter0 = UncheckedParameter<Uint32T>(Descriptor::kValue);
  USE(parameter0);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Number> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 465);
    tmp0 = CodeStubAssembler(state_).ChangeUint32ToTagged(TNode<Uint32T>{parameter0});
    CodeStubAssembler(state_).Return(tmp0);
  }
}

TF_BUILTIN(UintPtr53ToNumber, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<UintPtrT> parameter0 = UncheckedParameter<UintPtrT>(Descriptor::kValue);
  USE(parameter0);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<UintPtrT> tmp0;
  TNode<BoolT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 469);
    tmp0 = FromConstexpr_uintptr_constexpr_uintptr_0(state_, kSmiMaxValue);
    tmp1 = CodeStubAssembler(state_).UintPtrLessThanOrEqual(TNode<UintPtrT>{parameter0}, TNode<UintPtrT>{tmp0});
    ca_.Branch(tmp1, &block1, std::vector<compiler::Node*>{}, &block2, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp2;
  TNode<Smi> tmp3;
  if (block1.is_used()) {
    ca_.Bind(&block1);
    tmp2 = Convert_intptr_uintptr_0(state_, TNode<UintPtrT>{parameter0});
    tmp3 = Convert_Smi_intptr_0(state_, TNode<IntPtrT>{tmp2});
    CodeStubAssembler(state_).Return(tmp3);
  }

  TNode<Float64T> tmp4;
  TNode<UintPtrT> tmp5;
  TNode<BoolT> tmp6;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 470);
    tmp4 = CodeStubAssembler(state_).ChangeUintPtrToFloat64(TNode<UintPtrT>{parameter0});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 473);
    tmp5 = CodeStubAssembler(state_).ChangeFloat64ToUintPtr(TNode<Float64T>{tmp4});
    tmp6 = CodeStubAssembler(state_).WordEqual(TNode<UintPtrT>{tmp5}, TNode<UintPtrT>{parameter0});
    ca_.Branch(tmp6, &block3, std::vector<compiler::Node*>{}, &block4, std::vector<compiler::Node*>{});
  }

  if (block4.is_used()) {
    ca_.Bind(&block4);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/wasm.tq", 473});
      CodeStubAssembler(state_).FailAssert("Torque assert 'ChangeFloat64ToUintPtr(valueFloat) == value' failed", pos_stack);
    }
  }

  TNode<HeapNumber> tmp7;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 474);
    tmp7 = CodeStubAssembler(state_).AllocateHeapNumberWithValue(TNode<Float64T>{tmp4});
    CodeStubAssembler(state_).Return(tmp7);
  }
}

TF_BUILTIN(WasmAtomicNotify, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<UintPtrT> parameter0 = UncheckedParameter<UintPtrT>(Descriptor::kOffset);
  USE(parameter0);
  TNode<Uint32T> parameter1 = UncheckedParameter<Uint32T>(Descriptor::kCount);
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<WasmInstanceObject> tmp0;
  TNode<NativeContext> tmp1;
  TNode<Number> tmp2;
  TNode<Number> tmp3;
  TNode<Smi> tmp4;
  TNode<Int32T> tmp5;
  TNode<Uint32T> tmp6;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 480);
    tmp0 = WasmBuiltinsAssembler(state_).LoadInstanceFromFrame();
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 482);
    tmp1 = WasmBuiltinsAssembler(state_).LoadContextFromInstance(TNode<WasmInstanceObject>{tmp0});
    tmp2 = ca_.CallStub<Number>(Builtins::CallableFor(ca_.isolate(), Builtin::kUintPtr53ToNumber), TNode<Object>(), parameter0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 483);
    tmp3 = ca_.CallStub<Number>(Builtins::CallableFor(ca_.isolate(), Builtin::kWasmUint32ToNumber), TNode<Object>(), parameter1);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 481);
    tmp4 = TORQUE_CAST(CodeStubAssembler(state_).CallRuntime(Runtime::kWasmAtomicNotify, tmp1, tmp0, tmp2, tmp3)); 
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 484);
    tmp5 = CodeStubAssembler(state_).SmiToInt32(TNode<Smi>{tmp4});
    tmp6 = CodeStubAssembler(state_).Unsigned(TNode<Int32T>{tmp5});
    CodeStubAssembler(state_).Return(tmp6);
  }
}

TF_BUILTIN(WasmI32AtomicWait, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<UintPtrT> parameter0 = UncheckedParameter<UintPtrT>(Descriptor::kOffset);
  USE(parameter0);
  TNode<Int32T> parameter1 = UncheckedParameter<Int32T>(Descriptor::kExpectedValue);
  USE(parameter1);
  TNode<BigInt> parameter2 = UncheckedParameter<BigInt>(Descriptor::kTimeout);
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<WasmInstanceObject> tmp0;
  TNode<NativeContext> tmp1;
  TNode<Number> tmp2;
  TNode<Number> tmp3;
  TNode<Smi> tmp4;
  TNode<Int32T> tmp5;
  TNode<Uint32T> tmp6;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 489);
    tmp0 = WasmBuiltinsAssembler(state_).LoadInstanceFromFrame();
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 491);
    tmp1 = WasmBuiltinsAssembler(state_).LoadContextFromInstance(TNode<WasmInstanceObject>{tmp0});
    tmp2 = ca_.CallStub<Number>(Builtins::CallableFor(ca_.isolate(), Builtin::kUintPtr53ToNumber), TNode<Object>(), parameter0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 492);
    tmp3 = ca_.CallStub<Number>(Builtins::CallableFor(ca_.isolate(), Builtin::kWasmInt32ToNumber), TNode<Object>(), parameter1);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 490);
    tmp4 = TORQUE_CAST(CodeStubAssembler(state_).CallRuntime(Runtime::kWasmI32AtomicWait, tmp1, tmp0, tmp2, tmp3, parameter2)); 
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 493);
    tmp5 = CodeStubAssembler(state_).SmiToInt32(TNode<Smi>{tmp4});
    tmp6 = CodeStubAssembler(state_).Unsigned(TNode<Int32T>{tmp5});
    CodeStubAssembler(state_).Return(tmp6);
  }
}

TF_BUILTIN(WasmI64AtomicWait, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<UintPtrT> parameter0 = UncheckedParameter<UintPtrT>(Descriptor::kOffset);
  USE(parameter0);
  TNode<BigInt> parameter1 = UncheckedParameter<BigInt>(Descriptor::kExpectedValue);
  USE(parameter1);
  TNode<BigInt> parameter2 = UncheckedParameter<BigInt>(Descriptor::kTimeout);
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<WasmInstanceObject> tmp0;
  TNode<NativeContext> tmp1;
  TNode<Number> tmp2;
  TNode<Smi> tmp3;
  TNode<Int32T> tmp4;
  TNode<Uint32T> tmp5;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 498);
    tmp0 = WasmBuiltinsAssembler(state_).LoadInstanceFromFrame();
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 500);
    tmp1 = WasmBuiltinsAssembler(state_).LoadContextFromInstance(TNode<WasmInstanceObject>{tmp0});
    tmp2 = ca_.CallStub<Number>(Builtins::CallableFor(ca_.isolate(), Builtin::kUintPtr53ToNumber), TNode<Object>(), parameter0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 499);
    tmp3 = TORQUE_CAST(CodeStubAssembler(state_).CallRuntime(Runtime::kWasmI64AtomicWait, tmp1, tmp0, tmp2, parameter1, parameter2)); 
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 502);
    tmp4 = CodeStubAssembler(state_).SmiToInt32(TNode<Smi>{tmp3});
    tmp5 = CodeStubAssembler(state_).Unsigned(TNode<Int32T>{tmp4});
    CodeStubAssembler(state_).Return(tmp5);
  }
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm.tq?l=515&c=1
TorqueStructTargetAndInstance_0 GetTargetAndInstance_0(compiler::CodeAssemblerState* state_, TNode<WasmInternalFunction> p_funcref) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<HeapObject> tmp1;
  TNode<RawPtrT> tmp2;
  TNode<IntPtrT> tmp3;
  TNode<IntPtrT> tmp4;
  TNode<BoolT> tmp5;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 516);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp1 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{p_funcref, tmp0});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 517);
    tmp2 = CodeStubAssembler(state_).LoadWasmInternalFunctionCallTargetPtr(TNode<WasmInternalFunction>{p_funcref});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 518);
    tmp3 = CodeStubAssembler(state_).Signed(TNode<RawPtrT>{tmp2});
    tmp4 = IntPtrConstant_0(state_, IntegerLiteral(false, 0x0ull));
    tmp5 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{tmp3}, TNode<IntPtrT>{tmp4});
    ca_.Branch(tmp5, &block2, std::vector<compiler::Node*>{}, &block3, std::vector<compiler::Node*>{tmp2});
  }

  TNode<IntPtrT> tmp6;
  TNode<Code> tmp7;
  TNode<RawPtrT> tmp8;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 519);
    tmp6 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp7 = CodeStubAssembler(state_).LoadReference<Code>(CodeStubAssembler::Reference{p_funcref, tmp6});
    tmp8 = CodeStubAssembler(state_).GetCodeEntry(TNode<Code>{tmp7});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 518);
    ca_.Goto(&block3, tmp8);
  }

  TNode<RawPtrT> phi_bb3_2;
  if (block3.is_used()) {
    ca_.Bind(&block3, &phi_bb3_2);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 515);
    ca_.Goto(&block4);
  }

    ca_.Bind(&block4);
  return TorqueStructTargetAndInstance_0{TNode<RawPtrT>{phi_bb3_2}, TNode<HeapObject>{tmp1}};
}

TF_BUILTIN(CallRefIC, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<FixedArray> parameter0 = UncheckedParameter<FixedArray>(Descriptor::kVector);
  USE(parameter0);
  TNode<IntPtrT> parameter1 = UncheckedParameter<IntPtrT>(Descriptor::kIndex);
  USE(parameter1);
  TNode<WasmInternalFunction> parameter2 = UncheckedParameter<WasmInternalFunction>(Descriptor::kFuncref);
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block26(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block25(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block21(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block31(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block32(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block42(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block41(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block44(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block43(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block39(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block37(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block35(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block53(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block52(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block55(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block54(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block50(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block48(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block47(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block46(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block58(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block56(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block66(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block67(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block60(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block74(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block75(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block85(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block84(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, BoolT> block81(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block80(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block79(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block90(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block91(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block61(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block57(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block36(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block94(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block101(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block102(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block109(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block110(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block95(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block120(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block119(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block122(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block121(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block117(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block115(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block113(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block132(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block131(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block134(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block133(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block129(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block127(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block126(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block125(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block135(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block142(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block143(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block150(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block151(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block136(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block162(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block161(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block164(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block163(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block159(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block157(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block156(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block155(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block167(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block165(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block173(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block174(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block181(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block182(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block166(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block189(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block190(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block197(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block198(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block205(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block206(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block137(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block114(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block216(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block215(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block218(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block217(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block213(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block211(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block209(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block227(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block226(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block229(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block228(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block224(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block222(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block221(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block220(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block235(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block236(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block244(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block245(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block252(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block253(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block261(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block262(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block270(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block271(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block278(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block279(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block286(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block287(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block210(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block123(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block96(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Object> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<UintPtrT> tmp3;
  TNode<UintPtrT> tmp4;
  TNode<BoolT> tmp5;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 539);
    std::tie(tmp0, tmp1, tmp2) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray>{parameter0}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 89);
    tmp3 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{parameter1});
    tmp4 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp2});
    tmp5 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp3}, TNode<UintPtrT>{tmp4});
    ca_.Branch(tmp5, &block5, std::vector<compiler::Node*>{}, &block6, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<Object> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<Object> tmp10;
  TNode<BoolT> tmp11;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 97);
    tmp6 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{parameter1});
    tmp7 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp6});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 96);
    std::tie(tmp8, tmp9) = NewReference_Object_0(state_, TNode<Object>{tmp0}, TNode<IntPtrT>{tmp7}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 539);
    tmp10 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp8, tmp9});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 540);
    tmp11 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp10}, TNode<HeapObject>{parameter2});
    ca_.Branch(tmp11, &block9, std::vector<compiler::Node*>{}, &block10, std::vector<compiler::Node*>{});
  }

  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 101);
    CodeStubAssembler(state_).PrintErr("halting because of unreachable code at src/builtins/torque-internal.tq:101:45");
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<Object> tmp12;
  TNode<IntPtrT> tmp13;
  TNode<IntPtrT> tmp14;
  TNode<IntPtrT> tmp15;
  TNode<IntPtrT> tmp16;
  TNode<UintPtrT> tmp17;
  TNode<UintPtrT> tmp18;
  TNode<BoolT> tmp19;
  if (block9.is_used()) {
    ca_.Bind(&block9);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 542);
    std::tie(tmp12, tmp13, tmp14) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray>{parameter0}).Flatten();
    tmp15 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp16 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{parameter1}, TNode<IntPtrT>{tmp15});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 89);
    tmp17 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp16});
    tmp18 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp14});
    tmp19 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp17}, TNode<UintPtrT>{tmp18});
    ca_.Branch(tmp19, &block15, std::vector<compiler::Node*>{}, &block16, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp20;
  TNode<IntPtrT> tmp21;
  TNode<Object> tmp22;
  TNode<IntPtrT> tmp23;
  TNode<Object> tmp24;
  TNode<Smi> tmp25;
  if (block15.is_used()) {
    ca_.Bind(&block15);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 97);
    tmp20 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{tmp16});
    tmp21 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp13}, TNode<IntPtrT>{tmp20});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 96);
    std::tie(tmp22, tmp23) = NewReference_Object_0(state_, TNode<Object>{tmp12}, TNode<IntPtrT>{tmp21}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 542);
    tmp24 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp22, tmp23});
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 808);
    compiler::CodeAssemblerLabel label26(&ca_);
    tmp25 = Cast_Smi_0(state_, TNode<Object>{tmp24}, &label26);
    ca_.Goto(&block25);
    if (label26.is_used()) {
      ca_.Bind(&label26);
      ca_.Goto(&block26);
    }
  }

  if (block16.is_used()) {
    ca_.Bind(&block16);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 101);
    CodeStubAssembler(state_).PrintErr("halting because of unreachable code at src/builtins/torque-internal.tq:101:45");
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<BoolT> tmp27;
  if (block26.is_used()) {
    ca_.Bind(&block26);
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 808);
    tmp27 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block22, tmp27);
  }

  TNode<BoolT> tmp28;
  if (block25.is_used()) {
    ca_.Bind(&block25);
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 809);
    tmp28 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block22, tmp28);
  }

  TNode<BoolT> phi_bb22_8;
  if (block22.is_used()) {
    ca_.Bind(&block22, &phi_bb22_8);
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 814);
    ca_.Branch(phi_bb22_8, &block20, std::vector<compiler::Node*>{}, &block21, std::vector<compiler::Node*>{});
  }

  if (block21.is_used()) {
    ca_.Bind(&block21);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/cast.tq", 814});
      CodeStubAssembler(state_).FailAssert("Torque assert 'Is<A>(o)' failed", pos_stack);
    }
  }

  TNode<Smi> tmp29;
  TNode<Smi> tmp30;
  TNode<Smi> tmp31;
  TNode<Object> tmp32;
  TNode<IntPtrT> tmp33;
  TNode<IntPtrT> tmp34;
  TNode<IntPtrT> tmp35;
  TNode<IntPtrT> tmp36;
  TNode<UintPtrT> tmp37;
  TNode<UintPtrT> tmp38;
  TNode<BoolT> tmp39;
  if (block20.is_used()) {
    ca_.Bind(&block20);
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 815);
    tmp29 = TORQUE_CAST(TNode<Object>{tmp24});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 542);
    tmp30 = SmiConstant_0(state_, IntegerLiteral(false, 0x1ull));
    tmp31 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp29}, TNode<Smi>{tmp30});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 543);
    std::tie(tmp32, tmp33, tmp34) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray>{parameter0}).Flatten();
    tmp35 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp36 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{parameter1}, TNode<IntPtrT>{tmp35});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 89);
    tmp37 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp36});
    tmp38 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp34});
    tmp39 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp37}, TNode<UintPtrT>{tmp38});
    ca_.Branch(tmp39, &block31, std::vector<compiler::Node*>{}, &block32, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp40;
  TNode<IntPtrT> tmp41;
  TNode<Object> tmp42;
  TNode<IntPtrT> tmp43;
  TNode<RawPtrT> tmp44;
  TNode<HeapObject> tmp45;
  if (block31.is_used()) {
    ca_.Bind(&block31);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 97);
    tmp40 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{tmp36});
    tmp41 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp33}, TNode<IntPtrT>{tmp40});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 96);
    std::tie(tmp42, tmp43) = NewReference_Object_0(state_, TNode<Object>{tmp32}, TNode<IntPtrT>{tmp41}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 543);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp42, tmp43}, tmp31);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 544);
    std::tie(tmp44, tmp45) = GetTargetAndInstance_0(state_, TNode<WasmInternalFunction>{parameter2}).Flatten();
    CodeStubAssembler(state_).Return(tmp44, tmp45);
  }

  if (block32.is_used()) {
    ca_.Bind(&block32);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 101);
    CodeStubAssembler(state_).PrintErr("halting because of unreachable code at src/builtins/torque-internal.tq:101:45");
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<HeapObject> tmp46;
  if (block10.is_used()) {
    ca_.Bind(&block10);
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 162);
    compiler::CodeAssemblerLabel label47(&ca_);
    tmp46 = CodeStubAssembler(state_).TaggedToHeapObject(TNode<Object>{tmp10}, &label47);
    ca_.Goto(&block41);
    if (label47.is_used()) {
      ca_.Bind(&label47);
      ca_.Goto(&block42);
    }
  }

  if (block42.is_used()) {
    ca_.Bind(&block42);
    ca_.Goto(&block39);
  }

  TNode<FixedArray> tmp48;
  if (block41.is_used()) {
    ca_.Bind(&block41);
    compiler::CodeAssemblerLabel label49(&ca_);
    tmp48 = Cast_FixedArray_0(state_, TNode<HeapObject>{tmp46}, &label49);
    ca_.Goto(&block43);
    if (label49.is_used()) {
      ca_.Bind(&label49);
      ca_.Goto(&block44);
    }
  }

  if (block44.is_used()) {
    ca_.Bind(&block44);
    ca_.Goto(&block39);
  }

  TNode<BoolT> tmp50;
  if (block43.is_used()) {
    ca_.Bind(&block43);
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 809);
    tmp50 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block37, tmp50);
  }

  TNode<BoolT> tmp51;
  if (block39.is_used()) {
    ca_.Bind(&block39);
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 808);
    tmp51 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block37, tmp51);
  }

  TNode<BoolT> phi_bb37_6;
  if (block37.is_used()) {
    ca_.Bind(&block37, &phi_bb37_6);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 547);
    ca_.Branch(phi_bb37_6, &block35, std::vector<compiler::Node*>{}, &block36, std::vector<compiler::Node*>{});
  }

  TNode<HeapObject> tmp52;
  if (block35.is_used()) {
    ca_.Bind(&block35);
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 162);
    compiler::CodeAssemblerLabel label53(&ca_);
    tmp52 = CodeStubAssembler(state_).TaggedToHeapObject(TNode<Object>{tmp10}, &label53);
    ca_.Goto(&block52);
    if (label53.is_used()) {
      ca_.Bind(&label53);
      ca_.Goto(&block53);
    }
  }

  if (block53.is_used()) {
    ca_.Bind(&block53);
    ca_.Goto(&block50);
  }

  TNode<FixedArray> tmp54;
  if (block52.is_used()) {
    ca_.Bind(&block52);
    compiler::CodeAssemblerLabel label55(&ca_);
    tmp54 = Cast_FixedArray_0(state_, TNode<HeapObject>{tmp52}, &label55);
    ca_.Goto(&block54);
    if (label55.is_used()) {
      ca_.Bind(&label55);
      ca_.Goto(&block55);
    }
  }

  if (block55.is_used()) {
    ca_.Bind(&block55);
    ca_.Goto(&block50);
  }

  TNode<BoolT> tmp56;
  if (block54.is_used()) {
    ca_.Bind(&block54);
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 809);
    tmp56 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block48, tmp56);
  }

  TNode<BoolT> tmp57;
  if (block50.is_used()) {
    ca_.Bind(&block50);
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 808);
    tmp57 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block48, tmp57);
  }

  TNode<BoolT> phi_bb48_8;
  if (block48.is_used()) {
    ca_.Bind(&block48, &phi_bb48_8);
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 814);
    ca_.Branch(phi_bb48_8, &block46, std::vector<compiler::Node*>{}, &block47, std::vector<compiler::Node*>{});
  }

  if (block47.is_used()) {
    ca_.Bind(&block47);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/cast.tq", 814});
      CodeStubAssembler(state_).FailAssert("Torque assert 'Is<A>(o)' failed", pos_stack);
    }
  }

  TNode<FixedArray> tmp58;
  TNode<IntPtrT> tmp59;
  if (block46.is_used()) {
    ca_.Bind(&block46);
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 815);
    tmp58 = TORQUE_CAST(TNode<Object>{tmp10});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 549);
    tmp59 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    ca_.Goto(&block58, tmp59);
  }

  TNode<IntPtrT> phi_bb58_5;
  TNode<IntPtrT> tmp60;
  TNode<BoolT> tmp61;
  if (block58.is_used()) {
    ca_.Bind(&block58, &phi_bb58_5);
    tmp60 = CodeStubAssembler(state_).LoadAndUntagFixedArrayBaseLength(TNode<FixedArrayBase>{tmp58});
    tmp61 = CodeStubAssembler(state_).IntPtrLessThan(TNode<IntPtrT>{phi_bb58_5}, TNode<IntPtrT>{tmp60});
    ca_.Branch(tmp61, &block56, std::vector<compiler::Node*>{phi_bb58_5}, &block57, std::vector<compiler::Node*>{phi_bb58_5});
  }

  TNode<IntPtrT> phi_bb56_5;
  TNode<Object> tmp62;
  TNode<IntPtrT> tmp63;
  TNode<IntPtrT> tmp64;
  TNode<UintPtrT> tmp65;
  TNode<UintPtrT> tmp66;
  TNode<BoolT> tmp67;
  if (block56.is_used()) {
    ca_.Bind(&block56, &phi_bb56_5);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 550);
    std::tie(tmp62, tmp63, tmp64) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray>{tmp58}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 89);
    tmp65 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{phi_bb56_5});
    tmp66 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp64});
    tmp67 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp65}, TNode<UintPtrT>{tmp66});
    ca_.Branch(tmp67, &block66, std::vector<compiler::Node*>{phi_bb56_5, phi_bb56_5, phi_bb56_5, phi_bb56_5, phi_bb56_5}, &block67, std::vector<compiler::Node*>{phi_bb56_5, phi_bb56_5, phi_bb56_5, phi_bb56_5, phi_bb56_5});
  }

  TNode<IntPtrT> phi_bb66_5;
  TNode<IntPtrT> phi_bb66_10;
  TNode<IntPtrT> phi_bb66_11;
  TNode<IntPtrT> phi_bb66_15;
  TNode<IntPtrT> phi_bb66_16;
  TNode<IntPtrT> tmp68;
  TNode<IntPtrT> tmp69;
  TNode<Object> tmp70;
  TNode<IntPtrT> tmp71;
  TNode<Object> tmp72;
  TNode<BoolT> tmp73;
  if (block66.is_used()) {
    ca_.Bind(&block66, &phi_bb66_5, &phi_bb66_10, &phi_bb66_11, &phi_bb66_15, &phi_bb66_16);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 97);
    tmp68 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{phi_bb66_16});
    tmp69 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp63}, TNode<IntPtrT>{tmp68});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 96);
    std::tie(tmp70, tmp71) = NewReference_Object_0(state_, TNode<Object>{tmp62}, TNode<IntPtrT>{tmp69}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 550);
    tmp72 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp70, tmp71});
    tmp73 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp72}, TNode<HeapObject>{parameter2});
    ca_.Branch(tmp73, &block60, std::vector<compiler::Node*>{phi_bb66_5}, &block61, std::vector<compiler::Node*>{phi_bb66_5});
  }

  TNode<IntPtrT> phi_bb67_5;
  TNode<IntPtrT> phi_bb67_10;
  TNode<IntPtrT> phi_bb67_11;
  TNode<IntPtrT> phi_bb67_15;
  TNode<IntPtrT> phi_bb67_16;
  if (block67.is_used()) {
    ca_.Bind(&block67, &phi_bb67_5, &phi_bb67_10, &phi_bb67_11, &phi_bb67_15, &phi_bb67_16);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 101);
    CodeStubAssembler(state_).PrintErr("halting because of unreachable code at src/builtins/torque-internal.tq:101:45");
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<IntPtrT> phi_bb60_5;
  TNode<Object> tmp74;
  TNode<IntPtrT> tmp75;
  TNode<IntPtrT> tmp76;
  TNode<IntPtrT> tmp77;
  TNode<IntPtrT> tmp78;
  TNode<UintPtrT> tmp79;
  TNode<UintPtrT> tmp80;
  TNode<BoolT> tmp81;
  if (block60.is_used()) {
    ca_.Bind(&block60, &phi_bb60_5);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 552);
    std::tie(tmp74, tmp75, tmp76) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray>{tmp58}).Flatten();
    tmp77 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp78 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb60_5}, TNode<IntPtrT>{tmp77});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 89);
    tmp79 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp78});
    tmp80 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp76});
    tmp81 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp79}, TNode<UintPtrT>{tmp80});
    ca_.Branch(tmp81, &block74, std::vector<compiler::Node*>{phi_bb60_5}, &block75, std::vector<compiler::Node*>{phi_bb60_5});
  }

  TNode<IntPtrT> phi_bb74_5;
  TNode<IntPtrT> tmp82;
  TNode<IntPtrT> tmp83;
  TNode<Object> tmp84;
  TNode<IntPtrT> tmp85;
  TNode<Object> tmp86;
  TNode<Smi> tmp87;
  if (block74.is_used()) {
    ca_.Bind(&block74, &phi_bb74_5);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 97);
    tmp82 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{tmp78});
    tmp83 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp75}, TNode<IntPtrT>{tmp82});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 96);
    std::tie(tmp84, tmp85) = NewReference_Object_0(state_, TNode<Object>{tmp74}, TNode<IntPtrT>{tmp83}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 552);
    tmp86 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp84, tmp85});
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 808);
    compiler::CodeAssemblerLabel label88(&ca_);
    tmp87 = Cast_Smi_0(state_, TNode<Object>{tmp86}, &label88);
    ca_.Goto(&block84, phi_bb74_5);
    if (label88.is_used()) {
      ca_.Bind(&label88);
      ca_.Goto(&block85, phi_bb74_5);
    }
  }

  TNode<IntPtrT> phi_bb75_5;
  if (block75.is_used()) {
    ca_.Bind(&block75, &phi_bb75_5);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 101);
    CodeStubAssembler(state_).PrintErr("halting because of unreachable code at src/builtins/torque-internal.tq:101:45");
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<IntPtrT> phi_bb85_5;
  TNode<BoolT> tmp89;
  if (block85.is_used()) {
    ca_.Bind(&block85, &phi_bb85_5);
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 808);
    tmp89 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block81, phi_bb85_5, tmp89);
  }

  TNode<IntPtrT> phi_bb84_5;
  TNode<BoolT> tmp90;
  if (block84.is_used()) {
    ca_.Bind(&block84, &phi_bb84_5);
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 809);
    tmp90 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block81, phi_bb84_5, tmp90);
  }

  TNode<IntPtrT> phi_bb81_5;
  TNode<BoolT> phi_bb81_10;
  if (block81.is_used()) {
    ca_.Bind(&block81, &phi_bb81_5, &phi_bb81_10);
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 814);
    ca_.Branch(phi_bb81_10, &block79, std::vector<compiler::Node*>{phi_bb81_5}, &block80, std::vector<compiler::Node*>{phi_bb81_5});
  }

  TNode<IntPtrT> phi_bb80_5;
  if (block80.is_used()) {
    ca_.Bind(&block80, &phi_bb80_5);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/cast.tq", 814});
      CodeStubAssembler(state_).FailAssert("Torque assert 'Is<A>(o)' failed", pos_stack);
    }
  }

  TNode<IntPtrT> phi_bb79_5;
  TNode<Smi> tmp91;
  TNode<Smi> tmp92;
  TNode<Smi> tmp93;
  TNode<Object> tmp94;
  TNode<IntPtrT> tmp95;
  TNode<IntPtrT> tmp96;
  TNode<IntPtrT> tmp97;
  TNode<IntPtrT> tmp98;
  TNode<UintPtrT> tmp99;
  TNode<UintPtrT> tmp100;
  TNode<BoolT> tmp101;
  if (block79.is_used()) {
    ca_.Bind(&block79, &phi_bb79_5);
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 815);
    tmp91 = TORQUE_CAST(TNode<Object>{tmp86});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 552);
    tmp92 = SmiConstant_0(state_, IntegerLiteral(false, 0x1ull));
    tmp93 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp91}, TNode<Smi>{tmp92});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 553);
    std::tie(tmp94, tmp95, tmp96) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray>{tmp58}).Flatten();
    tmp97 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp98 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb79_5}, TNode<IntPtrT>{tmp97});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 89);
    tmp99 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp98});
    tmp100 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp96});
    tmp101 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp99}, TNode<UintPtrT>{tmp100});
    ca_.Branch(tmp101, &block90, std::vector<compiler::Node*>{phi_bb79_5}, &block91, std::vector<compiler::Node*>{phi_bb79_5});
  }

  TNode<IntPtrT> phi_bb90_5;
  TNode<IntPtrT> tmp102;
  TNode<IntPtrT> tmp103;
  TNode<Object> tmp104;
  TNode<IntPtrT> tmp105;
  TNode<RawPtrT> tmp106;
  TNode<HeapObject> tmp107;
  if (block90.is_used()) {
    ca_.Bind(&block90, &phi_bb90_5);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 97);
    tmp102 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{tmp98});
    tmp103 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp95}, TNode<IntPtrT>{tmp102});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 96);
    std::tie(tmp104, tmp105) = NewReference_Object_0(state_, TNode<Object>{tmp94}, TNode<IntPtrT>{tmp103}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 553);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp104, tmp105}, tmp93);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 554);
    std::tie(tmp106, tmp107) = GetTargetAndInstance_0(state_, TNode<WasmInternalFunction>{parameter2}).Flatten();
    CodeStubAssembler(state_).Return(tmp106, tmp107);
  }

  TNode<IntPtrT> phi_bb91_5;
  if (block91.is_used()) {
    ca_.Bind(&block91, &phi_bb91_5);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 101);
    CodeStubAssembler(state_).PrintErr("halting because of unreachable code at src/builtins/torque-internal.tq:101:45");
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<IntPtrT> phi_bb61_5;
  TNode<IntPtrT> tmp108;
  TNode<IntPtrT> tmp109;
  if (block61.is_used()) {
    ca_.Bind(&block61, &phi_bb61_5);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 549);
    tmp108 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x2ull));
    tmp109 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb61_5}, TNode<IntPtrT>{tmp108});
    ca_.Goto(&block58, tmp109);
  }

  TNode<IntPtrT> phi_bb57_5;
  if (block57.is_used()) {
    ca_.Bind(&block57, &phi_bb57_5);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 547);
    ca_.Goto(&block36);
  }

  TNode<RawPtrT> tmp110;
  TNode<HeapObject> tmp111;
  TNode<Smi> tmp112;
  TNode<BoolT> tmp113;
  if (block36.is_used()) {
    ca_.Bind(&block36);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 560);
    std::tie(tmp110, tmp111) = GetTargetAndInstance_0(state_, TNode<WasmInternalFunction>{parameter2}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 561);
    tmp112 = SmiConstant_0(state_, IntegerLiteral(false, 0x0ull));
    tmp113 = CodeStubAssembler(state_).TaggedEqual(TNode<MaybeObject>{tmp10}, TNode<MaybeObject>{tmp112});
    ca_.Branch(tmp113, &block94, std::vector<compiler::Node*>{}, &block95, std::vector<compiler::Node*>{});
  }

  TNode<Object> tmp114;
  TNode<IntPtrT> tmp115;
  TNode<IntPtrT> tmp116;
  TNode<UintPtrT> tmp117;
  TNode<UintPtrT> tmp118;
  TNode<BoolT> tmp119;
  if (block94.is_used()) {
    ca_.Bind(&block94);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 563);
    std::tie(tmp114, tmp115, tmp116) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray>{parameter0}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 89);
    tmp117 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{parameter1});
    tmp118 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp116});
    tmp119 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp117}, TNode<UintPtrT>{tmp118});
    ca_.Branch(tmp119, &block101, std::vector<compiler::Node*>{}, &block102, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp120;
  TNode<IntPtrT> tmp121;
  TNode<Object> tmp122;
  TNode<IntPtrT> tmp123;
  TNode<Object> tmp124;
  TNode<IntPtrT> tmp125;
  TNode<IntPtrT> tmp126;
  TNode<IntPtrT> tmp127;
  TNode<IntPtrT> tmp128;
  TNode<UintPtrT> tmp129;
  TNode<UintPtrT> tmp130;
  TNode<BoolT> tmp131;
  if (block101.is_used()) {
    ca_.Bind(&block101);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 97);
    tmp120 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{parameter1});
    tmp121 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp115}, TNode<IntPtrT>{tmp120});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 96);
    std::tie(tmp122, tmp123) = NewReference_Object_0(state_, TNode<Object>{tmp114}, TNode<IntPtrT>{tmp121}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 563);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp122, tmp123}, parameter2);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 564);
    std::tie(tmp124, tmp125, tmp126) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray>{parameter0}).Flatten();
    tmp127 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp128 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{parameter1}, TNode<IntPtrT>{tmp127});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 89);
    tmp129 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp128});
    tmp130 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp126});
    tmp131 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp129}, TNode<UintPtrT>{tmp130});
    ca_.Branch(tmp131, &block109, std::vector<compiler::Node*>{}, &block110, std::vector<compiler::Node*>{});
  }

  if (block102.is_used()) {
    ca_.Bind(&block102);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 101);
    CodeStubAssembler(state_).PrintErr("halting because of unreachable code at src/builtins/torque-internal.tq:101:45");
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<IntPtrT> tmp132;
  TNode<IntPtrT> tmp133;
  TNode<Object> tmp134;
  TNode<IntPtrT> tmp135;
  TNode<Smi> tmp136;
  if (block109.is_used()) {
    ca_.Bind(&block109);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 97);
    tmp132 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{tmp128});
    tmp133 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp125}, TNode<IntPtrT>{tmp132});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 96);
    std::tie(tmp134, tmp135) = NewReference_Object_0(state_, TNode<Object>{tmp124}, TNode<IntPtrT>{tmp133}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 564);
    tmp136 = SmiConstant_0(state_, IntegerLiteral(false, 0x1ull));
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp134, tmp135}, tmp136);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 561);
    ca_.Goto(&block96);
  }

  if (block110.is_used()) {
    ca_.Bind(&block110);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 101);
    CodeStubAssembler(state_).PrintErr("halting because of unreachable code at src/builtins/torque-internal.tq:101:45");
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<HeapObject> tmp137;
  if (block95.is_used()) {
    ca_.Bind(&block95);
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 162);
    compiler::CodeAssemblerLabel label138(&ca_);
    tmp137 = CodeStubAssembler(state_).TaggedToHeapObject(TNode<Object>{tmp10}, &label138);
    ca_.Goto(&block119);
    if (label138.is_used()) {
      ca_.Bind(&label138);
      ca_.Goto(&block120);
    }
  }

  if (block120.is_used()) {
    ca_.Bind(&block120);
    ca_.Goto(&block117);
  }

  TNode<FixedArray> tmp139;
  if (block119.is_used()) {
    ca_.Bind(&block119);
    compiler::CodeAssemblerLabel label140(&ca_);
    tmp139 = Cast_FixedArray_0(state_, TNode<HeapObject>{tmp137}, &label140);
    ca_.Goto(&block121);
    if (label140.is_used()) {
      ca_.Bind(&label140);
      ca_.Goto(&block122);
    }
  }

  if (block122.is_used()) {
    ca_.Bind(&block122);
    ca_.Goto(&block117);
  }

  TNode<BoolT> tmp141;
  if (block121.is_used()) {
    ca_.Bind(&block121);
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 809);
    tmp141 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block115, tmp141);
  }

  TNode<BoolT> tmp142;
  if (block117.is_used()) {
    ca_.Bind(&block117);
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 808);
    tmp142 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block115, tmp142);
  }

  TNode<BoolT> phi_bb115_8;
  if (block115.is_used()) {
    ca_.Bind(&block115, &phi_bb115_8);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 565);
    ca_.Branch(phi_bb115_8, &block113, std::vector<compiler::Node*>{}, &block114, std::vector<compiler::Node*>{});
  }

  TNode<HeapObject> tmp143;
  if (block113.is_used()) {
    ca_.Bind(&block113);
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 162);
    compiler::CodeAssemblerLabel label144(&ca_);
    tmp143 = CodeStubAssembler(state_).TaggedToHeapObject(TNode<Object>{tmp10}, &label144);
    ca_.Goto(&block131);
    if (label144.is_used()) {
      ca_.Bind(&label144);
      ca_.Goto(&block132);
    }
  }

  if (block132.is_used()) {
    ca_.Bind(&block132);
    ca_.Goto(&block129);
  }

  TNode<FixedArray> tmp145;
  if (block131.is_used()) {
    ca_.Bind(&block131);
    compiler::CodeAssemblerLabel label146(&ca_);
    tmp145 = Cast_FixedArray_0(state_, TNode<HeapObject>{tmp143}, &label146);
    ca_.Goto(&block133);
    if (label146.is_used()) {
      ca_.Bind(&label146);
      ca_.Goto(&block134);
    }
  }

  if (block134.is_used()) {
    ca_.Bind(&block134);
    ca_.Goto(&block129);
  }

  TNode<BoolT> tmp147;
  if (block133.is_used()) {
    ca_.Bind(&block133);
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 809);
    tmp147 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block127, tmp147);
  }

  TNode<BoolT> tmp148;
  if (block129.is_used()) {
    ca_.Bind(&block129);
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 808);
    tmp148 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block127, tmp148);
  }

  TNode<BoolT> phi_bb127_10;
  if (block127.is_used()) {
    ca_.Bind(&block127, &phi_bb127_10);
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 814);
    ca_.Branch(phi_bb127_10, &block125, std::vector<compiler::Node*>{}, &block126, std::vector<compiler::Node*>{});
  }

  if (block126.is_used()) {
    ca_.Bind(&block126);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/cast.tq", 814});
      CodeStubAssembler(state_).FailAssert("Torque assert 'Is<A>(o)' failed", pos_stack);
    }
  }

  TNode<FixedArray> tmp149;
  TNode<IntPtrT> tmp150;
  TNode<Smi> tmp151;
  TNode<Smi> tmp152;
  TNode<BoolT> tmp153;
  if (block125.is_used()) {
    ca_.Bind(&block125);
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 815);
    tmp149 = TORQUE_CAST(TNode<Object>{tmp10});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 569);
    tmp150 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp151 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp149, tmp150});
    tmp152 = CodeStubAssembler(state_).SmiConstant((CodeStubAssembler(state_).ConstexprInt31Mul(wasm::kMaxPolymorphism, (FromConstexpr_constexpr_int31_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x2ull))))));
    tmp153 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp151}, TNode<Smi>{tmp152});
    ca_.Branch(tmp153, &block135, std::vector<compiler::Node*>{}, &block136, std::vector<compiler::Node*>{});
  }

  TNode<Object> tmp154;
  TNode<IntPtrT> tmp155;
  TNode<IntPtrT> tmp156;
  TNode<UintPtrT> tmp157;
  TNode<UintPtrT> tmp158;
  TNode<BoolT> tmp159;
  if (block135.is_used()) {
    ca_.Bind(&block135);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 570);
    std::tie(tmp154, tmp155, tmp156) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray>{parameter0}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 89);
    tmp157 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{parameter1});
    tmp158 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp156});
    tmp159 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp157}, TNode<UintPtrT>{tmp158});
    ca_.Branch(tmp159, &block142, std::vector<compiler::Node*>{}, &block143, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp160;
  TNode<IntPtrT> tmp161;
  TNode<Object> tmp162;
  TNode<IntPtrT> tmp163;
  TNode<Symbol> tmp164;
  TNode<Object> tmp165;
  TNode<IntPtrT> tmp166;
  TNode<IntPtrT> tmp167;
  TNode<IntPtrT> tmp168;
  TNode<IntPtrT> tmp169;
  TNode<UintPtrT> tmp170;
  TNode<UintPtrT> tmp171;
  TNode<BoolT> tmp172;
  if (block142.is_used()) {
    ca_.Bind(&block142);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 97);
    tmp160 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{parameter1});
    tmp161 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp155}, TNode<IntPtrT>{tmp160});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 96);
    std::tie(tmp162, tmp163) = NewReference_Object_0(state_, TNode<Object>{tmp154}, TNode<IntPtrT>{tmp161}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 570);
    tmp164 = kMegamorphicSymbol_0(state_);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp162, tmp163}, tmp164);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 571);
    std::tie(tmp165, tmp166, tmp167) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray>{parameter0}).Flatten();
    tmp168 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp169 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{parameter1}, TNode<IntPtrT>{tmp168});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 89);
    tmp170 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp169});
    tmp171 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp167});
    tmp172 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp170}, TNode<UintPtrT>{tmp171});
    ca_.Branch(tmp172, &block150, std::vector<compiler::Node*>{}, &block151, std::vector<compiler::Node*>{});
  }

  if (block143.is_used()) {
    ca_.Bind(&block143);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 101);
    CodeStubAssembler(state_).PrintErr("halting because of unreachable code at src/builtins/torque-internal.tq:101:45");
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<IntPtrT> tmp173;
  TNode<IntPtrT> tmp174;
  TNode<Object> tmp175;
  TNode<IntPtrT> tmp176;
  TNode<Symbol> tmp177;
  if (block150.is_used()) {
    ca_.Bind(&block150);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 97);
    tmp173 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{tmp169});
    tmp174 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp166}, TNode<IntPtrT>{tmp173});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 96);
    std::tie(tmp175, tmp176) = NewReference_Object_0(state_, TNode<Object>{tmp165}, TNode<IntPtrT>{tmp174}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 571);
    tmp177 = kMegamorphicSymbol_0(state_);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp175, tmp176}, tmp177);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 569);
    ca_.Goto(&block137);
  }

  if (block151.is_used()) {
    ca_.Bind(&block151);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 101);
    CodeStubAssembler(state_).PrintErr("halting because of unreachable code at src/builtins/torque-internal.tq:101:45");
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<IntPtrT> tmp178;
  TNode<IntPtrT> tmp179;
  TNode<IntPtrT> tmp180;
  TNode<FixedArrayBase> tmp181;
  TNode<HeapObject> tmp182;
  if (block136.is_used()) {
    ca_.Bind(&block136);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 574);
    tmp178 = CodeStubAssembler(state_).LoadAndUntagFixedArrayBaseLength(TNode<FixedArrayBase>{tmp149});
    tmp179 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x2ull));
    tmp180 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp178}, TNode<IntPtrT>{tmp179});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 573);
    tmp181 = CodeStubAssembler(state_).AllocateFixedArray(ElementsKind::PACKED_ELEMENTS, TNode<IntPtrT>{tmp180}, CodeStubAssembler::AllocationFlag::kNone);
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 162);
    compiler::CodeAssemblerLabel label183(&ca_);
    tmp182 = CodeStubAssembler(state_).TaggedToHeapObject(TNode<Object>{tmp181}, &label183);
    ca_.Goto(&block161);
    if (label183.is_used()) {
      ca_.Bind(&label183);
      ca_.Goto(&block162);
    }
  }

  if (block162.is_used()) {
    ca_.Bind(&block162);
    ca_.Goto(&block159);
  }

  TNode<FixedArray> tmp184;
  if (block161.is_used()) {
    ca_.Bind(&block161);
    compiler::CodeAssemblerLabel label185(&ca_);
    tmp184 = Cast_FixedArray_0(state_, TNode<HeapObject>{tmp182}, &label185);
    ca_.Goto(&block163);
    if (label185.is_used()) {
      ca_.Bind(&label185);
      ca_.Goto(&block164);
    }
  }

  if (block164.is_used()) {
    ca_.Bind(&block164);
    ca_.Goto(&block159);
  }

  TNode<BoolT> tmp186;
  if (block163.is_used()) {
    ca_.Bind(&block163);
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 809);
    tmp186 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block157, tmp186);
  }

  TNode<BoolT> tmp187;
  if (block159.is_used()) {
    ca_.Bind(&block159);
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 808);
    tmp187 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block157, tmp187);
  }

  TNode<BoolT> phi_bb157_11;
  if (block157.is_used()) {
    ca_.Bind(&block157, &phi_bb157_11);
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 814);
    ca_.Branch(phi_bb157_11, &block155, std::vector<compiler::Node*>{}, &block156, std::vector<compiler::Node*>{});
  }

  if (block156.is_used()) {
    ca_.Bind(&block156);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/cast.tq", 814});
      CodeStubAssembler(state_).FailAssert("Torque assert 'Is<A>(o)' failed", pos_stack);
    }
  }

  TNode<FixedArray> tmp188;
  TNode<IntPtrT> tmp189;
  if (block155.is_used()) {
    ca_.Bind(&block155);
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 815);
    tmp188 = TORQUE_CAST(TNode<Object>{tmp181});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 576);
    tmp189 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    ca_.Goto(&block167, tmp189);
  }

  TNode<IntPtrT> phi_bb167_8;
  TNode<IntPtrT> tmp190;
  TNode<BoolT> tmp191;
  if (block167.is_used()) {
    ca_.Bind(&block167, &phi_bb167_8);
    tmp190 = CodeStubAssembler(state_).LoadAndUntagFixedArrayBaseLength(TNode<FixedArrayBase>{tmp149});
    tmp191 = CodeStubAssembler(state_).IntPtrLessThan(TNode<IntPtrT>{phi_bb167_8}, TNode<IntPtrT>{tmp190});
    ca_.Branch(tmp191, &block165, std::vector<compiler::Node*>{phi_bb167_8}, &block166, std::vector<compiler::Node*>{phi_bb167_8});
  }

  TNode<IntPtrT> phi_bb165_8;
  TNode<Object> tmp192;
  TNode<IntPtrT> tmp193;
  TNode<IntPtrT> tmp194;
  TNode<UintPtrT> tmp195;
  TNode<UintPtrT> tmp196;
  TNode<BoolT> tmp197;
  if (block165.is_used()) {
    ca_.Bind(&block165, &phi_bb165_8);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 577);
    std::tie(tmp192, tmp193, tmp194) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray>{tmp188}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 89);
    tmp195 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{phi_bb165_8});
    tmp196 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp194});
    tmp197 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp195}, TNode<UintPtrT>{tmp196});
    ca_.Branch(tmp197, &block173, std::vector<compiler::Node*>{phi_bb165_8, phi_bb165_8, phi_bb165_8, phi_bb165_8, phi_bb165_8}, &block174, std::vector<compiler::Node*>{phi_bb165_8, phi_bb165_8, phi_bb165_8, phi_bb165_8, phi_bb165_8});
  }

  TNode<IntPtrT> phi_bb173_8;
  TNode<IntPtrT> phi_bb173_13;
  TNode<IntPtrT> phi_bb173_14;
  TNode<IntPtrT> phi_bb173_18;
  TNode<IntPtrT> phi_bb173_19;
  TNode<IntPtrT> tmp198;
  TNode<IntPtrT> tmp199;
  TNode<Object> tmp200;
  TNode<IntPtrT> tmp201;
  TNode<Object> tmp202;
  TNode<IntPtrT> tmp203;
  TNode<IntPtrT> tmp204;
  TNode<UintPtrT> tmp205;
  TNode<UintPtrT> tmp206;
  TNode<BoolT> tmp207;
  if (block173.is_used()) {
    ca_.Bind(&block173, &phi_bb173_8, &phi_bb173_13, &phi_bb173_14, &phi_bb173_18, &phi_bb173_19);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 97);
    tmp198 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{phi_bb173_19});
    tmp199 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp193}, TNode<IntPtrT>{tmp198});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 96);
    std::tie(tmp200, tmp201) = NewReference_Object_0(state_, TNode<Object>{tmp192}, TNode<IntPtrT>{tmp199}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 577);
    std::tie(tmp202, tmp203, tmp204) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray>{tmp149}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 89);
    tmp205 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{phi_bb173_8});
    tmp206 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp204});
    tmp207 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp205}, TNode<UintPtrT>{tmp206});
    ca_.Branch(tmp207, &block181, std::vector<compiler::Node*>{phi_bb173_8, phi_bb173_13, phi_bb173_14, phi_bb173_8, phi_bb173_8, phi_bb173_8, phi_bb173_8}, &block182, std::vector<compiler::Node*>{phi_bb173_8, phi_bb173_13, phi_bb173_14, phi_bb173_8, phi_bb173_8, phi_bb173_8, phi_bb173_8});
  }

  TNode<IntPtrT> phi_bb174_8;
  TNode<IntPtrT> phi_bb174_13;
  TNode<IntPtrT> phi_bb174_14;
  TNode<IntPtrT> phi_bb174_18;
  TNode<IntPtrT> phi_bb174_19;
  if (block174.is_used()) {
    ca_.Bind(&block174, &phi_bb174_8, &phi_bb174_13, &phi_bb174_14, &phi_bb174_18, &phi_bb174_19);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 101);
    CodeStubAssembler(state_).PrintErr("halting because of unreachable code at src/builtins/torque-internal.tq:101:45");
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<IntPtrT> phi_bb181_8;
  TNode<IntPtrT> phi_bb181_13;
  TNode<IntPtrT> phi_bb181_14;
  TNode<IntPtrT> phi_bb181_21;
  TNode<IntPtrT> phi_bb181_22;
  TNode<IntPtrT> phi_bb181_26;
  TNode<IntPtrT> phi_bb181_27;
  TNode<IntPtrT> tmp208;
  TNode<IntPtrT> tmp209;
  TNode<Object> tmp210;
  TNode<IntPtrT> tmp211;
  TNode<Object> tmp212;
  TNode<IntPtrT> tmp213;
  TNode<IntPtrT> tmp214;
  if (block181.is_used()) {
    ca_.Bind(&block181, &phi_bb181_8, &phi_bb181_13, &phi_bb181_14, &phi_bb181_21, &phi_bb181_22, &phi_bb181_26, &phi_bb181_27);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 97);
    tmp208 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{phi_bb181_27});
    tmp209 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp203}, TNode<IntPtrT>{tmp208});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 96);
    std::tie(tmp210, tmp211) = NewReference_Object_0(state_, TNode<Object>{tmp202}, TNode<IntPtrT>{tmp209}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 577);
    tmp212 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp210, tmp211});
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp200, tmp201}, tmp212);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 576);
    tmp213 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp214 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb181_8}, TNode<IntPtrT>{tmp213});
    ca_.Goto(&block167, tmp214);
  }

  TNode<IntPtrT> phi_bb182_8;
  TNode<IntPtrT> phi_bb182_13;
  TNode<IntPtrT> phi_bb182_14;
  TNode<IntPtrT> phi_bb182_21;
  TNode<IntPtrT> phi_bb182_22;
  TNode<IntPtrT> phi_bb182_26;
  TNode<IntPtrT> phi_bb182_27;
  if (block182.is_used()) {
    ca_.Bind(&block182, &phi_bb182_8, &phi_bb182_13, &phi_bb182_14, &phi_bb182_21, &phi_bb182_22, &phi_bb182_26, &phi_bb182_27);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 101);
    CodeStubAssembler(state_).PrintErr("halting because of unreachable code at src/builtins/torque-internal.tq:101:45");
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<IntPtrT> phi_bb166_8;
  TNode<IntPtrT> tmp215;
  TNode<Object> tmp216;
  TNode<IntPtrT> tmp217;
  TNode<IntPtrT> tmp218;
  TNode<UintPtrT> tmp219;
  TNode<UintPtrT> tmp220;
  TNode<BoolT> tmp221;
  if (block166.is_used()) {
    ca_.Bind(&block166, &phi_bb166_8);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 579);
    tmp215 = CodeStubAssembler(state_).LoadAndUntagFixedArrayBaseLength(TNode<FixedArrayBase>{tmp149});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 580);
    std::tie(tmp216, tmp217, tmp218) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray>{tmp188}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 89);
    tmp219 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp215});
    tmp220 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp218});
    tmp221 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp219}, TNode<UintPtrT>{tmp220});
    ca_.Branch(tmp221, &block189, std::vector<compiler::Node*>{}, &block190, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp222;
  TNode<IntPtrT> tmp223;
  TNode<Object> tmp224;
  TNode<IntPtrT> tmp225;
  TNode<Object> tmp226;
  TNode<IntPtrT> tmp227;
  TNode<IntPtrT> tmp228;
  TNode<IntPtrT> tmp229;
  TNode<IntPtrT> tmp230;
  TNode<UintPtrT> tmp231;
  TNode<UintPtrT> tmp232;
  TNode<BoolT> tmp233;
  if (block189.is_used()) {
    ca_.Bind(&block189);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 97);
    tmp222 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{tmp215});
    tmp223 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp217}, TNode<IntPtrT>{tmp222});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 96);
    std::tie(tmp224, tmp225) = NewReference_Object_0(state_, TNode<Object>{tmp216}, TNode<IntPtrT>{tmp223}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 580);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp224, tmp225}, parameter2);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 581);
    std::tie(tmp226, tmp227, tmp228) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray>{tmp188}).Flatten();
    tmp229 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp230 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp215}, TNode<IntPtrT>{tmp229});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 89);
    tmp231 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp230});
    tmp232 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp228});
    tmp233 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp231}, TNode<UintPtrT>{tmp232});
    ca_.Branch(tmp233, &block197, std::vector<compiler::Node*>{}, &block198, std::vector<compiler::Node*>{});
  }

  if (block190.is_used()) {
    ca_.Bind(&block190);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 101);
    CodeStubAssembler(state_).PrintErr("halting because of unreachable code at src/builtins/torque-internal.tq:101:45");
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<IntPtrT> tmp234;
  TNode<IntPtrT> tmp235;
  TNode<Object> tmp236;
  TNode<IntPtrT> tmp237;
  TNode<Smi> tmp238;
  TNode<Object> tmp239;
  TNode<IntPtrT> tmp240;
  TNode<IntPtrT> tmp241;
  TNode<UintPtrT> tmp242;
  TNode<UintPtrT> tmp243;
  TNode<BoolT> tmp244;
  if (block197.is_used()) {
    ca_.Bind(&block197);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 97);
    tmp234 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{tmp230});
    tmp235 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp227}, TNode<IntPtrT>{tmp234});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 96);
    std::tie(tmp236, tmp237) = NewReference_Object_0(state_, TNode<Object>{tmp226}, TNode<IntPtrT>{tmp235}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 581);
    tmp238 = SmiConstant_0(state_, IntegerLiteral(false, 0x1ull));
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp236, tmp237}, tmp238);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 582);
    std::tie(tmp239, tmp240, tmp241) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray>{parameter0}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 89);
    tmp242 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{parameter1});
    tmp243 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp241});
    tmp244 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp242}, TNode<UintPtrT>{tmp243});
    ca_.Branch(tmp244, &block205, std::vector<compiler::Node*>{}, &block206, std::vector<compiler::Node*>{});
  }

  if (block198.is_used()) {
    ca_.Bind(&block198);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 101);
    CodeStubAssembler(state_).PrintErr("halting because of unreachable code at src/builtins/torque-internal.tq:101:45");
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<IntPtrT> tmp245;
  TNode<IntPtrT> tmp246;
  TNode<Object> tmp247;
  TNode<IntPtrT> tmp248;
  if (block205.is_used()) {
    ca_.Bind(&block205);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 97);
    tmp245 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{parameter1});
    tmp246 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp240}, TNode<IntPtrT>{tmp245});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 96);
    std::tie(tmp247, tmp248) = NewReference_Object_0(state_, TNode<Object>{tmp239}, TNode<IntPtrT>{tmp246}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 582);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp247, tmp248}, tmp188);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 569);
    ca_.Goto(&block137);
  }

  if (block206.is_used()) {
    ca_.Bind(&block206);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 101);
    CodeStubAssembler(state_).PrintErr("halting because of unreachable code at src/builtins/torque-internal.tq:101:45");
    CodeStubAssembler(state_).Unreachable();
  }

  if (block137.is_used()) {
    ca_.Bind(&block137);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 565);
    ca_.Goto(&block123);
  }

  TNode<HeapObject> tmp249;
  if (block114.is_used()) {
    ca_.Bind(&block114);
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 162);
    compiler::CodeAssemblerLabel label250(&ca_);
    tmp249 = CodeStubAssembler(state_).TaggedToHeapObject(TNode<Object>{tmp10}, &label250);
    ca_.Goto(&block215);
    if (label250.is_used()) {
      ca_.Bind(&label250);
      ca_.Goto(&block216);
    }
  }

  if (block216.is_used()) {
    ca_.Bind(&block216);
    ca_.Goto(&block213);
  }

  TNode<WasmInternalFunction> tmp251;
  if (block215.is_used()) {
    ca_.Bind(&block215);
    compiler::CodeAssemblerLabel label252(&ca_);
    tmp251 = Cast_WasmInternalFunction_0(state_, TNode<HeapObject>{tmp249}, &label252);
    ca_.Goto(&block217);
    if (label252.is_used()) {
      ca_.Bind(&label252);
      ca_.Goto(&block218);
    }
  }

  if (block218.is_used()) {
    ca_.Bind(&block218);
    ca_.Goto(&block213);
  }

  TNode<BoolT> tmp253;
  if (block217.is_used()) {
    ca_.Bind(&block217);
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 809);
    tmp253 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block211, tmp253);
  }

  TNode<BoolT> tmp254;
  if (block213.is_used()) {
    ca_.Bind(&block213);
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 808);
    tmp254 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block211, tmp254);
  }

  TNode<BoolT> phi_bb211_8;
  if (block211.is_used()) {
    ca_.Bind(&block211, &phi_bb211_8);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 584);
    ca_.Branch(phi_bb211_8, &block209, std::vector<compiler::Node*>{}, &block210, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp255;
  TNode<FixedArrayBase> tmp256;
  TNode<HeapObject> tmp257;
  if (block209.is_used()) {
    ca_.Bind(&block209);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 586);
    tmp255 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x4ull));
    tmp256 = CodeStubAssembler(state_).AllocateFixedArray(ElementsKind::PACKED_ELEMENTS, TNode<IntPtrT>{tmp255}, CodeStubAssembler::AllocationFlag::kNone);
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 162);
    compiler::CodeAssemblerLabel label258(&ca_);
    tmp257 = CodeStubAssembler(state_).TaggedToHeapObject(TNode<Object>{tmp256}, &label258);
    ca_.Goto(&block226);
    if (label258.is_used()) {
      ca_.Bind(&label258);
      ca_.Goto(&block227);
    }
  }

  if (block227.is_used()) {
    ca_.Bind(&block227);
    ca_.Goto(&block224);
  }

  TNode<FixedArray> tmp259;
  if (block226.is_used()) {
    ca_.Bind(&block226);
    compiler::CodeAssemblerLabel label260(&ca_);
    tmp259 = Cast_FixedArray_0(state_, TNode<HeapObject>{tmp257}, &label260);
    ca_.Goto(&block228);
    if (label260.is_used()) {
      ca_.Bind(&label260);
      ca_.Goto(&block229);
    }
  }

  if (block229.is_used()) {
    ca_.Bind(&block229);
    ca_.Goto(&block224);
  }

  TNode<BoolT> tmp261;
  if (block228.is_used()) {
    ca_.Bind(&block228);
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 809);
    tmp261 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block222, tmp261);
  }

  TNode<BoolT> tmp262;
  if (block224.is_used()) {
    ca_.Bind(&block224);
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 808);
    tmp262 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block222, tmp262);
  }

  TNode<BoolT> phi_bb222_10;
  if (block222.is_used()) {
    ca_.Bind(&block222, &phi_bb222_10);
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 814);
    ca_.Branch(phi_bb222_10, &block220, std::vector<compiler::Node*>{}, &block221, std::vector<compiler::Node*>{});
  }

  if (block221.is_used()) {
    ca_.Bind(&block221);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/cast.tq", 814});
      CodeStubAssembler(state_).FailAssert("Torque assert 'Is<A>(o)' failed", pos_stack);
    }
  }

  TNode<FixedArray> tmp263;
  TNode<Object> tmp264;
  TNode<IntPtrT> tmp265;
  TNode<IntPtrT> tmp266;
  TNode<UintPtrT> tmp267;
  TNode<IntPtrT> tmp268;
  TNode<UintPtrT> tmp269;
  TNode<UintPtrT> tmp270;
  TNode<BoolT> tmp271;
  if (block220.is_used()) {
    ca_.Bind(&block220);
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 815);
    tmp263 = TORQUE_CAST(TNode<Object>{tmp256});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 588);
    std::tie(tmp264, tmp265, tmp266) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray>{tmp263}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 109);
    tmp267 = FromConstexpr_uintptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 105);
    tmp268 = Convert_intptr_uintptr_0(state_, TNode<UintPtrT>{tmp267});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 89);
    tmp269 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp268});
    tmp270 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp266});
    tmp271 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp269}, TNode<UintPtrT>{tmp270});
    ca_.Branch(tmp271, &block235, std::vector<compiler::Node*>{}, &block236, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp272;
  TNode<IntPtrT> tmp273;
  TNode<Object> tmp274;
  TNode<IntPtrT> tmp275;
  TNode<Object> tmp276;
  TNode<IntPtrT> tmp277;
  TNode<IntPtrT> tmp278;
  TNode<UintPtrT> tmp279;
  TNode<IntPtrT> tmp280;
  TNode<UintPtrT> tmp281;
  TNode<UintPtrT> tmp282;
  TNode<BoolT> tmp283;
  if (block235.is_used()) {
    ca_.Bind(&block235);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 97);
    tmp272 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{tmp268});
    tmp273 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp265}, TNode<IntPtrT>{tmp272});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 96);
    std::tie(tmp274, tmp275) = NewReference_Object_0(state_, TNode<Object>{tmp264}, TNode<IntPtrT>{tmp273}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 588);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp274, tmp275}, tmp10);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 589);
    std::tie(tmp276, tmp277, tmp278) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray>{tmp263}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 109);
    tmp279 = FromConstexpr_uintptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 105);
    tmp280 = Convert_intptr_uintptr_0(state_, TNode<UintPtrT>{tmp279});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 89);
    tmp281 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp280});
    tmp282 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp278});
    tmp283 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp281}, TNode<UintPtrT>{tmp282});
    ca_.Branch(tmp283, &block244, std::vector<compiler::Node*>{}, &block245, std::vector<compiler::Node*>{});
  }

  if (block236.is_used()) {
    ca_.Bind(&block236);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 105);
    CodeStubAssembler(state_).PrintErr("halting because of unreachable code at src/builtins/torque-internal.tq:105:62");
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<IntPtrT> tmp284;
  TNode<IntPtrT> tmp285;
  TNode<Object> tmp286;
  TNode<IntPtrT> tmp287;
  TNode<Object> tmp288;
  TNode<IntPtrT> tmp289;
  TNode<IntPtrT> tmp290;
  TNode<IntPtrT> tmp291;
  TNode<IntPtrT> tmp292;
  TNode<UintPtrT> tmp293;
  TNode<UintPtrT> tmp294;
  TNode<BoolT> tmp295;
  if (block244.is_used()) {
    ca_.Bind(&block244);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 97);
    tmp284 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{tmp280});
    tmp285 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp277}, TNode<IntPtrT>{tmp284});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 96);
    std::tie(tmp286, tmp287) = NewReference_Object_0(state_, TNode<Object>{tmp276}, TNode<IntPtrT>{tmp285}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 589);
    std::tie(tmp288, tmp289, tmp290) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray>{parameter0}).Flatten();
    tmp291 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp292 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{parameter1}, TNode<IntPtrT>{tmp291});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 89);
    tmp293 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp292});
    tmp294 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp290});
    tmp295 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp293}, TNode<UintPtrT>{tmp294});
    ca_.Branch(tmp295, &block252, std::vector<compiler::Node*>{}, &block253, std::vector<compiler::Node*>{});
  }

  if (block245.is_used()) {
    ca_.Bind(&block245);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 105);
    CodeStubAssembler(state_).PrintErr("halting because of unreachable code at src/builtins/torque-internal.tq:105:62");
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<IntPtrT> tmp296;
  TNode<IntPtrT> tmp297;
  TNode<Object> tmp298;
  TNode<IntPtrT> tmp299;
  TNode<Object> tmp300;
  TNode<Object> tmp301;
  TNode<IntPtrT> tmp302;
  TNode<IntPtrT> tmp303;
  TNode<UintPtrT> tmp304;
  TNode<IntPtrT> tmp305;
  TNode<UintPtrT> tmp306;
  TNode<UintPtrT> tmp307;
  TNode<BoolT> tmp308;
  if (block252.is_used()) {
    ca_.Bind(&block252);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 97);
    tmp296 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{tmp292});
    tmp297 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp289}, TNode<IntPtrT>{tmp296});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 96);
    std::tie(tmp298, tmp299) = NewReference_Object_0(state_, TNode<Object>{tmp288}, TNode<IntPtrT>{tmp297}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 589);
    tmp300 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp298, tmp299});
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp286, tmp287}, tmp300);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 590);
    std::tie(tmp301, tmp302, tmp303) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray>{tmp263}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 109);
    tmp304 = FromConstexpr_uintptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x2ull));
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 105);
    tmp305 = Convert_intptr_uintptr_0(state_, TNode<UintPtrT>{tmp304});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 89);
    tmp306 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp305});
    tmp307 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp303});
    tmp308 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp306}, TNode<UintPtrT>{tmp307});
    ca_.Branch(tmp308, &block261, std::vector<compiler::Node*>{}, &block262, std::vector<compiler::Node*>{});
  }

  if (block253.is_used()) {
    ca_.Bind(&block253);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 101);
    CodeStubAssembler(state_).PrintErr("halting because of unreachable code at src/builtins/torque-internal.tq:101:45");
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<IntPtrT> tmp309;
  TNode<IntPtrT> tmp310;
  TNode<Object> tmp311;
  TNode<IntPtrT> tmp312;
  TNode<Object> tmp313;
  TNode<IntPtrT> tmp314;
  TNode<IntPtrT> tmp315;
  TNode<UintPtrT> tmp316;
  TNode<IntPtrT> tmp317;
  TNode<UintPtrT> tmp318;
  TNode<UintPtrT> tmp319;
  TNode<BoolT> tmp320;
  if (block261.is_used()) {
    ca_.Bind(&block261);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 97);
    tmp309 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{tmp305});
    tmp310 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp302}, TNode<IntPtrT>{tmp309});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 96);
    std::tie(tmp311, tmp312) = NewReference_Object_0(state_, TNode<Object>{tmp301}, TNode<IntPtrT>{tmp310}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 590);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp311, tmp312}, parameter2);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 591);
    std::tie(tmp313, tmp314, tmp315) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray>{tmp263}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 109);
    tmp316 = FromConstexpr_uintptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x3ull));
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 105);
    tmp317 = Convert_intptr_uintptr_0(state_, TNode<UintPtrT>{tmp316});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 89);
    tmp318 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp317});
    tmp319 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp315});
    tmp320 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp318}, TNode<UintPtrT>{tmp319});
    ca_.Branch(tmp320, &block270, std::vector<compiler::Node*>{}, &block271, std::vector<compiler::Node*>{});
  }

  if (block262.is_used()) {
    ca_.Bind(&block262);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 105);
    CodeStubAssembler(state_).PrintErr("halting because of unreachable code at src/builtins/torque-internal.tq:105:62");
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<IntPtrT> tmp321;
  TNode<IntPtrT> tmp322;
  TNode<Object> tmp323;
  TNode<IntPtrT> tmp324;
  TNode<Smi> tmp325;
  TNode<Object> tmp326;
  TNode<IntPtrT> tmp327;
  TNode<IntPtrT> tmp328;
  TNode<UintPtrT> tmp329;
  TNode<UintPtrT> tmp330;
  TNode<BoolT> tmp331;
  if (block270.is_used()) {
    ca_.Bind(&block270);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 97);
    tmp321 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{tmp317});
    tmp322 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp314}, TNode<IntPtrT>{tmp321});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 96);
    std::tie(tmp323, tmp324) = NewReference_Object_0(state_, TNode<Object>{tmp313}, TNode<IntPtrT>{tmp322}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 591);
    tmp325 = SmiConstant_0(state_, IntegerLiteral(false, 0x1ull));
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp323, tmp324}, tmp325);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 592);
    std::tie(tmp326, tmp327, tmp328) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray>{parameter0}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 89);
    tmp329 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{parameter1});
    tmp330 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp328});
    tmp331 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp329}, TNode<UintPtrT>{tmp330});
    ca_.Branch(tmp331, &block278, std::vector<compiler::Node*>{}, &block279, std::vector<compiler::Node*>{});
  }

  if (block271.is_used()) {
    ca_.Bind(&block271);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 105);
    CodeStubAssembler(state_).PrintErr("halting because of unreachable code at src/builtins/torque-internal.tq:105:62");
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<IntPtrT> tmp332;
  TNode<IntPtrT> tmp333;
  TNode<Object> tmp334;
  TNode<IntPtrT> tmp335;
  TNode<Object> tmp336;
  TNode<IntPtrT> tmp337;
  TNode<IntPtrT> tmp338;
  TNode<IntPtrT> tmp339;
  TNode<IntPtrT> tmp340;
  TNode<UintPtrT> tmp341;
  TNode<UintPtrT> tmp342;
  TNode<BoolT> tmp343;
  if (block278.is_used()) {
    ca_.Bind(&block278);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 97);
    tmp332 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{parameter1});
    tmp333 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp327}, TNode<IntPtrT>{tmp332});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 96);
    std::tie(tmp334, tmp335) = NewReference_Object_0(state_, TNode<Object>{tmp326}, TNode<IntPtrT>{tmp333}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 592);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp334, tmp335}, tmp263);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 595);
    std::tie(tmp336, tmp337, tmp338) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray>{parameter0}).Flatten();
    tmp339 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp340 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{parameter1}, TNode<IntPtrT>{tmp339});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 89);
    tmp341 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp340});
    tmp342 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp338});
    tmp343 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp341}, TNode<UintPtrT>{tmp342});
    ca_.Branch(tmp343, &block286, std::vector<compiler::Node*>{}, &block287, std::vector<compiler::Node*>{});
  }

  if (block279.is_used()) {
    ca_.Bind(&block279);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 101);
    CodeStubAssembler(state_).PrintErr("halting because of unreachable code at src/builtins/torque-internal.tq:101:45");
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<IntPtrT> tmp344;
  TNode<IntPtrT> tmp345;
  TNode<Object> tmp346;
  TNode<IntPtrT> tmp347;
  TNode<Oddball> tmp348;
  if (block286.is_used()) {
    ca_.Bind(&block286);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 97);
    tmp344 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{tmp340});
    tmp345 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp337}, TNode<IntPtrT>{tmp344});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 96);
    std::tie(tmp346, tmp347) = NewReference_Object_0(state_, TNode<Object>{tmp336}, TNode<IntPtrT>{tmp345}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 595);
    tmp348 = Undefined_0(state_);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp346, tmp347}, tmp348);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 584);
    ca_.Goto(&block210);
  }

  if (block287.is_used()) {
    ca_.Bind(&block287);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 101);
    CodeStubAssembler(state_).PrintErr("halting because of unreachable code at src/builtins/torque-internal.tq:101:45");
    CodeStubAssembler(state_).Unreachable();
  }

  if (block210.is_used()) {
    ca_.Bind(&block210);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 565);
    ca_.Goto(&block123);
  }

  if (block123.is_used()) {
    ca_.Bind(&block123);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 561);
    ca_.Goto(&block96);
  }

  if (block96.is_used()) {
    ca_.Bind(&block96);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 598);
    CodeStubAssembler(state_).Return(tmp110, tmp111);
  }
}

TF_BUILTIN(WasmGetOwnProperty, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedParameter<Context>(Descriptor::kContext);
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kObject);
  USE(parameter1);
  TNode<Name> parameter2 = UncheckedParameter<Name>(Descriptor::kUniqueName);
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    ca_.Goto(&block0);

  TNode<HeapObject> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 614);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = CodeStubAssembler(state_).TaggedToHeapObject(TNode<Object>{parameter1}, &label1);
    ca_.Goto(&block3);
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block4);
    }
  }

  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.Goto(&block2);
  }

  TNode<JSReceiver> tmp2;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 616);
    compiler::CodeAssemblerLabel label3(&ca_);
    tmp2 = Cast_JSReceiver_0(state_, TNode<HeapObject>{tmp0}, &label3);
    ca_.Goto(&block5);
    if (label3.is_used()) {
      ca_.Bind(&label3);
      ca_.Goto(&block6);
    }
  }

  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.Goto(&block2);
  }

  TNode<IntPtrT> tmp4;
  TNode<Map> tmp5;
  TNode<Uint16T> tmp6;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 619);
    tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp5 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference{tmp2, tmp4});
    tmp6 = CodeStubAssembler(state_).LoadInstanceType(TNode<HeapObject>{tmp2});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 618);
    compiler::CodeAssemblerLabel label7(&ca_);
    compiler::CodeAssemblerLabel label8(&ca_);
    compiler::CodeAssemblerLabel label9(&ca_);
    CodeStubAssembler(state_).TryHasOwnProperty(TNode<HeapObject>{tmp2}, TNode<Map>{tmp5}, TNode<Uint16T>{tmp6}, TNode<Name>{parameter2}, &label7, &label8, &label9);
    if (label7.is_used()) {
      ca_.Bind(&label7);
      ca_.Goto(&block9);
    }
    if (label8.is_used()) {
      ca_.Bind(&label8);
      ca_.Goto(&block10);
    }
    if (label9.is_used()) {
      ca_.Bind(&label9);
      ca_.Goto(&block11);
    }
  }

  TNode<Smi> tmp10;
  if (block9.is_used()) {
    ca_.Bind(&block9);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 623);
    tmp10 = CodeStubAssembler(state_).SmiConstant(OnNonExistent::kReturnUndefined);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 622);
   CodeStubAssembler(state_).TailCallBuiltin(Builtin::kGetPropertyWithReceiver, parameter0, tmp2, parameter2, tmp2, tmp10);
  }

  if (block10.is_used()) {
    ca_.Bind(&block10);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 618);
    ca_.Goto(&block2);
  }

  if (block11.is_used()) {
    ca_.Bind(&block11);
    ca_.Goto(&block2);
  }

  TNode<Oddball> tmp11;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 626);
    tmp11 = Undefined_0(state_);
    CodeStubAssembler(state_).Return(tmp11);
  }
}

TF_BUILTIN(WasmTrap, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Smi> parameter0 = UncheckedParameter<Smi>(Descriptor::kError);
  USE(parameter0);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<NativeContext> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 633);
    tmp0 = LoadContextFromFrame_0(state_);
    CodeStubAssembler(state_).TailCallRuntime(Runtime::kThrowWasmError, tmp0, parameter0);
  }
}

TF_BUILTIN(ThrowWasmTrapUnreachable, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Smi> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 637);
    tmp0 = CodeStubAssembler(state_).SmiConstant(MessageTemplate::kWasmTrapUnreachable);
   CodeStubAssembler(state_).TailCallBuiltin(Builtin::kWasmTrap, TNode<Object>(), tmp0);
  }
}

TF_BUILTIN(ThrowWasmTrapMemOutOfBounds, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Smi> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 641);
    tmp0 = CodeStubAssembler(state_).SmiConstant(MessageTemplate::kWasmTrapMemOutOfBounds);
   CodeStubAssembler(state_).TailCallBuiltin(Builtin::kWasmTrap, TNode<Object>(), tmp0);
  }
}

TF_BUILTIN(ThrowWasmTrapUnalignedAccess, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Smi> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 645);
    tmp0 = CodeStubAssembler(state_).SmiConstant(MessageTemplate::kWasmTrapUnalignedAccess);
   CodeStubAssembler(state_).TailCallBuiltin(Builtin::kWasmTrap, TNode<Object>(), tmp0);
  }
}

TF_BUILTIN(ThrowWasmTrapDivByZero, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Smi> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 649);
    tmp0 = CodeStubAssembler(state_).SmiConstant(MessageTemplate::kWasmTrapDivByZero);
   CodeStubAssembler(state_).TailCallBuiltin(Builtin::kWasmTrap, TNode<Object>(), tmp0);
  }
}

TF_BUILTIN(ThrowWasmTrapDivUnrepresentable, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Smi> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 653);
    tmp0 = CodeStubAssembler(state_).SmiConstant(MessageTemplate::kWasmTrapDivUnrepresentable);
   CodeStubAssembler(state_).TailCallBuiltin(Builtin::kWasmTrap, TNode<Object>(), tmp0);
  }
}

TF_BUILTIN(ThrowWasmTrapRemByZero, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Smi> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 657);
    tmp0 = CodeStubAssembler(state_).SmiConstant(MessageTemplate::kWasmTrapRemByZero);
   CodeStubAssembler(state_).TailCallBuiltin(Builtin::kWasmTrap, TNode<Object>(), tmp0);
  }
}

TF_BUILTIN(ThrowWasmTrapFloatUnrepresentable, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Smi> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 661);
    tmp0 = CodeStubAssembler(state_).SmiConstant(MessageTemplate::kWasmTrapFloatUnrepresentable);
   CodeStubAssembler(state_).TailCallBuiltin(Builtin::kWasmTrap, TNode<Object>(), tmp0);
  }
}

TF_BUILTIN(ThrowWasmTrapFuncSigMismatch, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Smi> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 665);
    tmp0 = CodeStubAssembler(state_).SmiConstant(MessageTemplate::kWasmTrapFuncSigMismatch);
   CodeStubAssembler(state_).TailCallBuiltin(Builtin::kWasmTrap, TNode<Object>(), tmp0);
  }
}

TF_BUILTIN(ThrowWasmTrapDataSegmentOutOfBounds, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Smi> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 669);
    tmp0 = CodeStubAssembler(state_).SmiConstant(MessageTemplate::kWasmTrapDataSegmentOutOfBounds);
   CodeStubAssembler(state_).TailCallBuiltin(Builtin::kWasmTrap, TNode<Object>(), tmp0);
  }
}

TF_BUILTIN(ThrowWasmTrapElementSegmentOutOfBounds, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Smi> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 674);
    tmp0 = CodeStubAssembler(state_).SmiConstant(MessageTemplate::kWasmTrapElementSegmentOutOfBounds);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 673);
   CodeStubAssembler(state_).TailCallBuiltin(Builtin::kWasmTrap, TNode<Object>(), tmp0);
  }
}

TF_BUILTIN(ThrowWasmTrapTableOutOfBounds, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Smi> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 678);
    tmp0 = CodeStubAssembler(state_).SmiConstant(MessageTemplate::kWasmTrapTableOutOfBounds);
   CodeStubAssembler(state_).TailCallBuiltin(Builtin::kWasmTrap, TNode<Object>(), tmp0);
  }
}

TF_BUILTIN(ThrowWasmTrapRethrowNull, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Smi> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 682);
    tmp0 = CodeStubAssembler(state_).SmiConstant(MessageTemplate::kWasmTrapRethrowNull);
   CodeStubAssembler(state_).TailCallBuiltin(Builtin::kWasmTrap, TNode<Object>(), tmp0);
  }
}

TF_BUILTIN(ThrowWasmTrapNullDereference, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Smi> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 686);
    tmp0 = CodeStubAssembler(state_).SmiConstant(MessageTemplate::kWasmTrapNullDereference);
   CodeStubAssembler(state_).TailCallBuiltin(Builtin::kWasmTrap, TNode<Object>(), tmp0);
  }
}

TF_BUILTIN(ThrowWasmTrapIllegalCast, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Smi> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 690);
    tmp0 = CodeStubAssembler(state_).SmiConstant(MessageTemplate::kWasmTrapIllegalCast);
   CodeStubAssembler(state_).TailCallBuiltin(Builtin::kWasmTrap, TNode<Object>(), tmp0);
  }
}

TF_BUILTIN(ThrowWasmTrapArrayOutOfBounds, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Smi> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 694);
    tmp0 = CodeStubAssembler(state_).SmiConstant(MessageTemplate::kWasmTrapArrayOutOfBounds);
   CodeStubAssembler(state_).TailCallBuiltin(Builtin::kWasmTrap, TNode<Object>(), tmp0);
  }
}

TF_BUILTIN(ThrowWasmTrapArrayTooLarge, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Smi> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 698);
    tmp0 = CodeStubAssembler(state_).SmiConstant(MessageTemplate::kWasmTrapArrayTooLarge);
   CodeStubAssembler(state_).TailCallBuiltin(Builtin::kWasmTrap, TNode<Object>(), tmp0);
  }
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm.tq?l=701&c=1
TNode<IntPtrT> TryNumberToIntptr_0(compiler::CodeAssemblerState* state_, TNode<Object> p_value, compiler::CodeAssemblerLabel* label_Failure) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Smi> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 703);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = Cast_Smi_0(state_, TNode<Object>{p_value}, &label1);
    ca_.Goto(&block5);
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block6);
    }
  }

  TNode<HeapNumber> tmp2;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 706);
    compiler::CodeAssemblerLabel label3(&ca_);
    tmp2 = Cast_HeapNumber_0(state_, TNode<HeapObject>{ca_.UncheckedCast<HeapObject>(p_value)}, &label3);
    ca_.Goto(&block9);
    if (label3.is_used()) {
      ca_.Bind(&label3);
      ca_.Goto(&block10);
    }
  }

  TNode<IntPtrT> tmp4;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 704);
    tmp4 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp0});
    ca_.Goto(&block2, tmp4);
  }

  if (block10.is_used()) {
    ca_.Bind(&block10);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 713);
    ca_.Goto(&block1);
  }

  TNode<Float64T> tmp5;
  TNode<BoolT> tmp6;
  if (block9.is_used()) {
    ca_.Bind(&block9);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 707);
    tmp5 = Convert_float64_HeapNumber_0(state_, TNode<HeapNumber>{tmp2});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 708);
    tmp6 = Float64IsNaN_0(state_, TNode<Float64T>{tmp5});
    ca_.Branch(tmp6, &block11, std::vector<compiler::Node*>{}, &block12, std::vector<compiler::Node*>{});
  }

  if (block11.is_used()) {
    ca_.Bind(&block11);
    ca_.Goto(&block1);
  }

  TNode<Float64T> tmp7;
  TNode<IntPtrT> tmp8;
  if (block12.is_used()) {
    ca_.Bind(&block12);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 709);
    tmp7 = CodeStubAssembler(state_).Float64Trunc(TNode<Float64T>{tmp5});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 710);
    tmp8 = CodeStubAssembler(state_).ChangeFloat64ToIntPtr(TNode<Float64T>{tmp7});
    ca_.Goto(&block2, tmp8);
  }

  TNode<IntPtrT> phi_bb2_1;
  if (block2.is_used()) {
    ca_.Bind(&block2, &phi_bb2_1);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 701);
    ca_.Goto(&block13, phi_bb2_1);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_Failure);
  }

  TNode<IntPtrT> phi_bb13_1;
    ca_.Bind(&block13, &phi_bb13_1);
  return TNode<IntPtrT>{phi_bb13_1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm.tq?l=718&c=1
TNode<WasmTypeInfo> WasmTypeInfo_0(compiler::CodeAssemblerState* state_, TNode<Map> p_map) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Object> tmp1;
  TNode<HeapObject> tmp2;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 720);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 20);
    tmp1 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{p_map, tmp0});
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 162);
    compiler::CodeAssemblerLabel label3(&ca_);
    tmp2 = CodeStubAssembler(state_).TaggedToHeapObject(TNode<Object>{tmp1}, &label3);
    ca_.Goto(&block9);
    if (label3.is_used()) {
      ca_.Bind(&label3);
      ca_.Goto(&block10);
    }
  }

  if (block10.is_used()) {
    ca_.Bind(&block10);
    ca_.Goto(&block7);
  }

  TNode<WasmTypeInfo> tmp4;
  if (block9.is_used()) {
    ca_.Bind(&block9);
    compiler::CodeAssemblerLabel label5(&ca_);
    tmp4 = Cast_WasmTypeInfo_0(state_, TNode<HeapObject>{tmp2}, &label5);
    ca_.Goto(&block11);
    if (label5.is_used()) {
      ca_.Bind(&label5);
      ca_.Goto(&block12);
    }
  }

  if (block12.is_used()) {
    ca_.Bind(&block12);
    ca_.Goto(&block7);
  }

  TNode<BoolT> tmp6;
  if (block11.is_used()) {
    ca_.Bind(&block11);
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 809);
    tmp6 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block5, tmp6);
  }

  TNode<BoolT> tmp7;
  if (block7.is_used()) {
    ca_.Bind(&block7);
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 808);
    tmp7 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block5, tmp7);
  }

  TNode<BoolT> phi_bb5_5;
  if (block5.is_used()) {
    ca_.Bind(&block5, &phi_bb5_5);
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 814);
    ca_.Branch(phi_bb5_5, &block3, std::vector<compiler::Node*>{}, &block4, std::vector<compiler::Node*>{});
  }

  if (block4.is_used()) {
    ca_.Bind(&block4);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/cast.tq", 814});
      CodeStubAssembler(state_).FailAssert("Torque assert 'Is<A>(o)' failed", pos_stack);
    }
  }

  TNode<WasmTypeInfo> tmp8;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 815);
    tmp8 = TORQUE_CAST(TNode<Object>{tmp1});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 718);
    ca_.Goto(&block13);
  }

    ca_.Bind(&block13);
  return TNode<WasmTypeInfo>{tmp8};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm.tq?l=731&c=1
TNode<BoolT> IsWord16WasmArrayMap_0(compiler::CodeAssemblerState* state_, TNode<Map> p_map) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<WasmTypeInfo> tmp0;
  TNode<RawPtrT> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<RawPtrT> tmp3;
  TNode<IntPtrT> tmp4;
  TNode<RawPtrT> tmp5;
  TNode<RawPtrT> tmp6;
  TNode<Object> tmp7;
  TNode<IntPtrT> tmp8;
  TNode<Int32T> tmp9;
  TNode<Int32T> tmp10;
  TNode<BoolT> tmp11;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 733);
    tmp0 = WasmTypeInfo_0(state_, TNode<Map>{p_map});
    tmp1 = CodeStubAssembler(state_).LoadWasmTypeInfoNativeTypePtr(TNode<WasmTypeInfo>{tmp0});
    tmp2 = FromConstexpr_intptr_constexpr_intptr_0(state_, wasm::ArrayType::kRepOffset);
    tmp3 = CodeStubAssembler(state_).RawPtrAdd(TNode<RawPtrT>{tmp1}, TNode<IntPtrT>{tmp2});
    tmp4 = FromConstexpr_intptr_constexpr_intptr_0(state_, wasm::ValueType::kBitFieldOffset);
    tmp5 = CodeStubAssembler(state_).RawPtrAdd(TNode<RawPtrT>{tmp3}, TNode<IntPtrT>{tmp4});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 732);
    tmp6 = (TNode<RawPtrT>{tmp5});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 736);
    std::tie(tmp7, tmp8) = NewOffHeapReference_int32_0(state_, TNode<RawPtrT>{tmp6}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 737);
    tmp9 = CodeStubAssembler(state_).LoadReference<Int32T>(CodeStubAssembler::Reference{tmp7, tmp8});
    tmp10 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::ValueType::Primitive(wasm::kI16).raw_bit_field());
    tmp11 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp9}, TNode<Int32T>{tmp10});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 731);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<BoolT>{tmp11};
}

TF_BUILTIN(ExperimentalWasmConvertArrayToString, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Word32T> argc = UncheckedParameter<Word32T>(Descriptor::kJSActualArgumentsCount);
  TNode<IntPtrT> arguments_length(ChangeInt32ToIntPtr(UncheckedCast<Int32T>(argc)));
  TNode<RawPtrT> arguments_frame = UncheckedCast<RawPtrT>(LoadFramePointer());
  TorqueStructArguments torque_arguments(GetFrameArguments(arguments_frame, arguments_length, FrameArgumentsArgcType::kCountIncludesReceiver));
  CodeStubArguments arguments(this, torque_arguments);
  TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
  USE(parameter0);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<BoolT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 745);
    tmp0 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x3ull));
    tmp1 = CodeStubAssembler(state_).WordNotEqual(TNode<IntPtrT>{torque_arguments.length}, TNode<IntPtrT>{tmp0});
    ca_.Branch(tmp1, &block3, std::vector<compiler::Node*>{}, &block4, std::vector<compiler::Node*>{});
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    ca_.Goto(&block2);
  }

  TNode<IntPtrT> tmp2;
  TNode<Object> tmp3;
  TNode<WasmArray> tmp4;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 746);
    tmp2 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp3 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{torque_arguments.frame}, TNode<RawPtrT>{torque_arguments.base}, TNode<IntPtrT>{torque_arguments.length}, TNode<IntPtrT>{torque_arguments.actual_count}}, TNode<IntPtrT>{tmp2});
    compiler::CodeAssemblerLabel label5(&ca_);
    tmp4 = Cast_WasmArray_1(state_, TNode<Context>{parameter0}, TNode<Object>{tmp3}, &label5);
    ca_.Goto(&block7);
    if (label5.is_used()) {
      ca_.Bind(&label5);
      ca_.Goto(&block8);
    }
  }

  if (block8.is_used()) {
    ca_.Bind(&block8);
    ca_.Goto(&block2);
  }

  TNode<IntPtrT> tmp6;
  TNode<Object> tmp7;
  TNode<IntPtrT> tmp8;
  if (block7.is_used()) {
    ca_.Bind(&block7);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 747);
    tmp6 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp7 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{torque_arguments.frame}, TNode<RawPtrT>{torque_arguments.base}, TNode<IntPtrT>{torque_arguments.length}, TNode<IntPtrT>{torque_arguments.actual_count}}, TNode<IntPtrT>{tmp6});
    compiler::CodeAssemblerLabel label9(&ca_);
    tmp8 = TryNumberToIntptr_0(state_, TNode<Object>{tmp7}, &label9);
    ca_.Goto(&block11);
    if (label9.is_used()) {
      ca_.Bind(&label9);
      ca_.Goto(&block12);
    }
  }

  if (block12.is_used()) {
    ca_.Bind(&block12);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 748);
    ca_.Goto(&block2);
  }

  TNode<IntPtrT> tmp10;
  TNode<Object> tmp11;
  TNode<IntPtrT> tmp12;
  if (block11.is_used()) {
    ca_.Bind(&block11);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 749);
    tmp10 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x2ull));
    tmp11 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{torque_arguments.frame}, TNode<RawPtrT>{torque_arguments.base}, TNode<IntPtrT>{torque_arguments.length}, TNode<IntPtrT>{torque_arguments.actual_count}}, TNode<IntPtrT>{tmp10});
    compiler::CodeAssemblerLabel label13(&ca_);
    tmp12 = TryNumberToIntptr_0(state_, TNode<Object>{tmp11}, &label13);
    ca_.Goto(&block15);
    if (label13.is_used()) {
      ca_.Bind(&label13);
      ca_.Goto(&block16);
    }
  }

  if (block16.is_used()) {
    ca_.Bind(&block16);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 750);
    ca_.Goto(&block2);
  }

  TNode<IntPtrT> tmp14;
  TNode<Map> tmp15;
  TNode<BoolT> tmp16;
  TNode<BoolT> tmp17;
  if (block15.is_used()) {
    ca_.Bind(&block15);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 752);
    tmp14 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp15 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference{tmp4, tmp14});
    tmp16 = IsWord16WasmArrayMap_0(state_, TNode<Map>{tmp15});
    tmp17 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp16});
    ca_.Branch(tmp17, &block17, std::vector<compiler::Node*>{}, &block18, std::vector<compiler::Node*>{});
  }

  if (block17.is_used()) {
    ca_.Bind(&block17);
    ca_.Goto(&block2);
  }

  TNode<IntPtrT> tmp18;
  TNode<Uint32T> tmp19;
  TNode<IntPtrT> tmp20;
  TNode<IntPtrT> tmp21;
  TNode<Object> tmp22;
  TNode<IntPtrT> tmp23;
  TNode<IntPtrT> tmp24;
  TNode<UintPtrT> tmp25;
  TNode<Uint32T> tmp26;
  TNode<Object> tmp27;
  TNode<IntPtrT> tmp28;
  TNode<IntPtrT> tmp29;
  if (block18.is_used()) {
    ca_.Bind(&block18);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 754);
    tmp18 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp19 = CodeStubAssembler(state_).LoadReference<Uint32T>(CodeStubAssembler::Reference{tmp4, tmp18});
    tmp20 = Convert_intptr_uint32_0(state_, TNode<Uint32T>{tmp19});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 753);
    tmp21 = FromConstexpr_intptr_constexpr_int32_0(state_, WasmArray::kHeaderSize);
    std::tie(tmp22, tmp23, tmp24) = NewConstSlice_char16_0(state_, TNode<Object>{tmp4}, TNode<IntPtrT>{tmp21}, TNode<IntPtrT>{tmp20}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 757);
    tmp25 = CodeStubAssembler(state_).Unsigned(TNode<IntPtrT>{tmp12});
    tmp26 = Convert_uint32_uintptr_0(state_, TNode<UintPtrT>{tmp25});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 758);
    compiler::CodeAssemblerLabel label30(&ca_);
    std::tie(tmp27, tmp28, tmp29) = Subslice_char16_0(state_, TorqueStructSlice_char16_ConstReference_char16_0{TNode<Object>{tmp22}, TNode<IntPtrT>{tmp23}, TNode<IntPtrT>{tmp24}, TorqueStructUnsafe_0{}}, TNode<IntPtrT>{tmp8}, TNode<IntPtrT>{tmp12}, &label30).Flatten();
    ca_.Goto(&block21);
    if (label30.is_used()) {
      ca_.Bind(&label30);
      ca_.Goto(&block22);
    }
  }

  if (block22.is_used()) {
    ca_.Bind(&block22);
    ca_.Goto(&block2);
  }

  TNode<IntPtrT> tmp31;
  TNode<IntPtrT> tmp32;
  TNode<String> tmp33;
  if (block21.is_used()) {
    ca_.Bind(&block21);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 128);
    tmp31 = TimesSizeOf_char16_0(state_, TNode<IntPtrT>{tmp29});
    tmp32 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp28}, TNode<IntPtrT>{tmp31});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 756);
    tmp33 = AllocateSeqTwoByteString_SliceIterator_char16_ConstReference_char16_0(state_, TNode<Uint32T>{tmp26}, TorqueStructSliceIterator_char16_ConstReference_char16_0{TNode<Object>{tmp27}, TNode<IntPtrT>{tmp28}, TNode<IntPtrT>{tmp32}, TorqueStructUnsafe_0{}});
    arguments.PopAndReturn(tmp33);
  }

  if (block2.is_used()) {
    ca_.Bind(&block2);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 761);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{parameter0}, MessageTemplate::kInvalidArgument);
  }
}

TF_BUILTIN(ExperimentalWasmConvertStringToArray, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Word32T> argc = UncheckedParameter<Word32T>(Descriptor::kJSActualArgumentsCount);
  TNode<IntPtrT> arguments_length(ChangeInt32ToIntPtr(UncheckedCast<Int32T>(argc)));
  TNode<RawPtrT> arguments_frame = UncheckedCast<RawPtrT>(LoadFramePointer());
  TorqueStructArguments torque_arguments(GetFrameArguments(arguments_frame, arguments_length, FrameArgumentsArgcType::kCountIncludesReceiver));
  CodeStubArguments arguments(this, torque_arguments);
  TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
  USE(parameter0);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<String, IntPtrT> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<String, IntPtrT> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<String, IntPtrT, String, String> block25(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<String, IntPtrT, String, String> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<String, IntPtrT, String, IntPtrT> block29(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<String, IntPtrT, String, IntPtrT> block28(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<String, IntPtrT, String> block33(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<String, IntPtrT, String> block32(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<String, IntPtrT, String, IntPtrT> block37(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<String, IntPtrT, String, IntPtrT> block36(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<String, IntPtrT, String> block41(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<String, IntPtrT, String> block40(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<String, IntPtrT, String> block45(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<String, IntPtrT, String> block44(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<String, IntPtrT, String> block49(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<String, IntPtrT, String> block48(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<String, IntPtrT, String> block53(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<String, IntPtrT, String> block52(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<String, IntPtrT, String, IntPtrT> block57(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<String, IntPtrT, String, IntPtrT> block56(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<String, IntPtrT, String> block61(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<String, IntPtrT, String> block60(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<String, IntPtrT, String, IntPtrT> block65(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<String, IntPtrT, String, IntPtrT> block64(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<String, IntPtrT, String> block42(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<String, IntPtrT, String> block38(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<String, IntPtrT> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, IntPtrT> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, IntPtrT, Object, IntPtrT, IntPtrT> block70(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, IntPtrT, Object, IntPtrT, IntPtrT> block68(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, IntPtrT, Object, IntPtrT, IntPtrT> block74(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, IntPtrT, Object, IntPtrT, IntPtrT> block75(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, IntPtrT, Object, IntPtrT> block81(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, IntPtrT, Object, IntPtrT> block80(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, IntPtrT, Object, IntPtrT, IntPtrT> block69(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, IntPtrT> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, IntPtrT, Object, IntPtrT, IntPtrT> block87(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, IntPtrT, Object, IntPtrT, IntPtrT> block85(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, IntPtrT, Object, IntPtrT, IntPtrT> block91(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, IntPtrT, Object, IntPtrT, IntPtrT> block92(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, IntPtrT, Object, IntPtrT> block98(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, IntPtrT, Object, IntPtrT> block97(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, IntPtrT, Object, IntPtrT, IntPtrT> block86(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<BoolT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 770);
    tmp0 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x2ull));
    tmp1 = CodeStubAssembler(state_).WordNotEqual(TNode<IntPtrT>{torque_arguments.length}, TNode<IntPtrT>{tmp0});
    ca_.Branch(tmp1, &block3, std::vector<compiler::Node*>{}, &block4, std::vector<compiler::Node*>{});
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    ca_.Goto(&block2);
  }

  TNode<IntPtrT> tmp2;
  TNode<Object> tmp3;
  TNode<String> tmp4;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 771);
    tmp2 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp3 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{torque_arguments.frame}, TNode<RawPtrT>{torque_arguments.base}, TNode<IntPtrT>{torque_arguments.length}, TNode<IntPtrT>{torque_arguments.actual_count}}, TNode<IntPtrT>{tmp2});
    compiler::CodeAssemblerLabel label5(&ca_);
    tmp4 = Cast_String_1(state_, TNode<Context>{parameter0}, TNode<Object>{tmp3}, &label5);
    ca_.Goto(&block7);
    if (label5.is_used()) {
      ca_.Bind(&label5);
      ca_.Goto(&block8);
    }
  }

  if (block8.is_used()) {
    ca_.Bind(&block8);
    ca_.Goto(&block2);
  }

  TNode<IntPtrT> tmp6;
  TNode<Object> tmp7;
  TNode<WasmArray> tmp8;
  if (block7.is_used()) {
    ca_.Bind(&block7);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 773);
    tmp6 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp7 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{torque_arguments.frame}, TNode<RawPtrT>{torque_arguments.base}, TNode<IntPtrT>{torque_arguments.length}, TNode<IntPtrT>{torque_arguments.actual_count}}, TNode<IntPtrT>{tmp6});
    compiler::CodeAssemblerLabel label9(&ca_);
    tmp8 = Cast_WasmArray_1(state_, TNode<Context>{parameter0}, TNode<Object>{tmp7}, &label9);
    ca_.Goto(&block11);
    if (label9.is_used()) {
      ca_.Bind(&label9);
      ca_.Goto(&block12);
    }
  }

  if (block12.is_used()) {
    ca_.Bind(&block12);
    ca_.Goto(&block2);
  }

  TNode<IntPtrT> tmp10;
  TNode<Map> tmp11;
  TNode<BoolT> tmp12;
  TNode<BoolT> tmp13;
  if (block11.is_used()) {
    ca_.Bind(&block11);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 774);
    tmp10 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp11 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference{tmp8, tmp10});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 775);
    tmp12 = IsWord16WasmArrayMap_0(state_, TNode<Map>{tmp11});
    tmp13 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp12});
    ca_.Branch(tmp13, &block13, std::vector<compiler::Node*>{}, &block14, std::vector<compiler::Node*>{});
  }

  if (block13.is_used()) {
    ca_.Bind(&block13);
    ca_.Goto(&block2);
  }

  TNode<IntPtrT> tmp14;
  TNode<Int32T> tmp15;
  TNode<Uint32T> tmp16;
  TNode<Uint32T> tmp17;
  TNode<WasmArray> tmp18;
  TNode<IntPtrT> tmp19;
  TNode<IntPtrT> tmp20;
  TNode<Object> tmp21;
  TNode<IntPtrT> tmp22;
  TNode<IntPtrT> tmp23;
  TNode<IntPtrT> tmp24;
  TNode<IntPtrT> tmp25;
  TNode<Int32T> tmp26;
  TNode<IntPtrT> tmp27;
  if (block14.is_used()) {
    ca_.Bind(&block14);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 777);
    tmp14 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp15 = CodeStubAssembler(state_).LoadReference<Int32T>(CodeStubAssembler::Reference{tmp4, tmp14});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 780);
    tmp16 = CodeStubAssembler(state_).Unsigned(TNode<Int32T>{tmp15});
    tmp17 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x2ull));
    tmp18 = ca_.CallStub<WasmArray>(Builtins::CallableFor(ca_.isolate(), Builtin::kWasmAllocateArray_Uninitialized), TNode<Object>(), tmp11, tmp16, tmp17);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 782);
    tmp19 = Convert_intptr_int32_0(state_, TNode<Int32T>{tmp15});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 781);
    tmp20 = FromConstexpr_intptr_constexpr_int32_0(state_, WasmArray::kHeaderSize);
    std::tie(tmp21, tmp22, tmp23) = NewMutableSlice_char16_0(state_, TNode<Object>{tmp18}, TNode<IntPtrT>{tmp20}, TNode<IntPtrT>{tmp19}).Flatten();
    ca_.SetSourcePosition("../../../src/objects/string.tq", 249);
    tmp24 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    ca_.SetSourcePosition("../../../src/objects/string.tq", 250);
    tmp25 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp26 = CodeStubAssembler(state_).LoadReference<Int32T>(CodeStubAssembler::Reference{tmp4, tmp25});
    tmp27 = Convert_intptr_int32_0(state_, TNode<Int32T>{tmp26});
    ca_.SetSourcePosition("../../../src/objects/string.tq", 251);
    ca_.Goto(&block21, tmp4, tmp24);
  }

  TNode<String> phi_bb21_15;
  TNode<IntPtrT> phi_bb21_16;
  TNode<BoolT> tmp28;
  if (block21.is_used()) {
    ca_.Bind(&block21, &phi_bb21_15, &phi_bb21_16);
    tmp28 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Branch(tmp28, &block19, std::vector<compiler::Node*>{phi_bb21_15, phi_bb21_16}, &block20, std::vector<compiler::Node*>{phi_bb21_15, phi_bb21_16});
  }

  TNode<String> phi_bb19_15;
  TNode<IntPtrT> phi_bb19_16;
  TNode<SeqOneByteString> tmp29;
  if (block19.is_used()) {
    ca_.Bind(&block19, &phi_bb19_15, &phi_bb19_16);
    ca_.SetSourcePosition("../../../src/objects/string.tq", 253);
    compiler::CodeAssemblerLabel label30(&ca_);
    tmp29 = Cast_SeqOneByteString_1(state_, TNode<String>{phi_bb19_15}, &label30);
    ca_.Goto(&block24, phi_bb19_15, phi_bb19_16, phi_bb19_15, phi_bb19_15);
    if (label30.is_used()) {
      ca_.Bind(&label30);
      ca_.Goto(&block25, phi_bb19_15, phi_bb19_16, phi_bb19_15, phi_bb19_15);
    }
  }

  TNode<String> phi_bb25_15;
  TNode<IntPtrT> phi_bb25_16;
  TNode<String> phi_bb25_18;
  TNode<String> phi_bb25_19;
  TNode<SeqTwoByteString> tmp31;
  if (block25.is_used()) {
    ca_.Bind(&block25, &phi_bb25_15, &phi_bb25_16, &phi_bb25_18, &phi_bb25_19);
    ca_.SetSourcePosition("../../../src/objects/string.tq", 256);
    compiler::CodeAssemblerLabel label32(&ca_);
    tmp31 = Cast_SeqTwoByteString_1(state_, TNode<String>{ca_.UncheckedCast<String>(phi_bb25_18)}, &label32);
    ca_.Goto(&block32, phi_bb25_15, phi_bb25_16, phi_bb25_18);
    if (label32.is_used()) {
      ca_.Bind(&label32);
      ca_.Goto(&block33, phi_bb25_15, phi_bb25_16, phi_bb25_18);
    }
  }

  TNode<String> phi_bb24_15;
  TNode<IntPtrT> phi_bb24_16;
  TNode<String> phi_bb24_18;
  TNode<String> phi_bb24_19;
  TNode<Object> tmp33;
  TNode<IntPtrT> tmp34;
  TNode<IntPtrT> tmp35;
  TNode<Object> tmp36;
  TNode<IntPtrT> tmp37;
  TNode<IntPtrT> tmp38;
  if (block24.is_used()) {
    ca_.Bind(&block24, &phi_bb24_15, &phi_bb24_16, &phi_bb24_18, &phi_bb24_19);
    ca_.SetSourcePosition("../../../src/objects/string.tq", 254);
    std::tie(tmp33, tmp34, tmp35) = FieldSliceSeqOneByteStringChars_0(state_, TNode<SeqOneByteString>{tmp29}).Flatten();
    compiler::CodeAssemblerLabel label39(&ca_);
    std::tie(tmp36, tmp37, tmp38) = Subslice_char8_0(state_, TorqueStructSlice_char8_ConstReference_char8_0{TNode<Object>{tmp33}, TNode<IntPtrT>{tmp34}, TNode<IntPtrT>{tmp35}, TorqueStructUnsafe_0{}}, TNode<IntPtrT>{phi_bb24_16}, TNode<IntPtrT>{tmp27}, &label39).Flatten();
    ca_.Goto(&block28, phi_bb24_15, phi_bb24_16, phi_bb24_18, phi_bb24_16);
    if (label39.is_used()) {
      ca_.Bind(&label39);
      ca_.Goto(&block29, phi_bb24_15, phi_bb24_16, phi_bb24_18, phi_bb24_16);
    }
  }

  TNode<String> phi_bb29_15;
  TNode<IntPtrT> phi_bb29_16;
  TNode<String> phi_bb29_18;
  TNode<IntPtrT> phi_bb29_23;
  if (block29.is_used()) {
    ca_.Bind(&block29, &phi_bb29_15, &phi_bb29_16, &phi_bb29_18, &phi_bb29_23);
    CodeStubAssembler(state_).PrintErr("halting because of unreachable code at src/objects/string.tq:254:67");
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<String> phi_bb28_15;
  TNode<IntPtrT> phi_bb28_16;
  TNode<String> phi_bb28_18;
  TNode<IntPtrT> phi_bb28_23;
  if (block28.is_used()) {
    ca_.Bind(&block28, &phi_bb28_15, &phi_bb28_16, &phi_bb28_18, &phi_bb28_23);
    ca_.Goto(&block18, tmp36, tmp37, tmp38);
  }

  TNode<String> phi_bb33_15;
  TNode<IntPtrT> phi_bb33_16;
  TNode<String> phi_bb33_18;
  TNode<ThinString> tmp40;
  if (block33.is_used()) {
    ca_.Bind(&block33, &phi_bb33_15, &phi_bb33_16, &phi_bb33_18);
    ca_.SetSourcePosition("../../../src/objects/string.tq", 259);
    compiler::CodeAssemblerLabel label41(&ca_);
    tmp40 = Cast_ThinString_1(state_, TNode<String>{ca_.UncheckedCast<String>(phi_bb33_18)}, &label41);
    ca_.Goto(&block40, phi_bb33_15, phi_bb33_16, phi_bb33_18);
    if (label41.is_used()) {
      ca_.Bind(&label41);
      ca_.Goto(&block41, phi_bb33_15, phi_bb33_16, phi_bb33_18);
    }
  }

  TNode<String> phi_bb32_15;
  TNode<IntPtrT> phi_bb32_16;
  TNode<String> phi_bb32_18;
  TNode<Object> tmp42;
  TNode<IntPtrT> tmp43;
  TNode<IntPtrT> tmp44;
  TNode<Object> tmp45;
  TNode<IntPtrT> tmp46;
  TNode<IntPtrT> tmp47;
  if (block32.is_used()) {
    ca_.Bind(&block32, &phi_bb32_15, &phi_bb32_16, &phi_bb32_18);
    ca_.SetSourcePosition("../../../src/objects/string.tq", 257);
    std::tie(tmp42, tmp43, tmp44) = FieldSliceSeqTwoByteStringChars_0(state_, TNode<SeqTwoByteString>{tmp31}).Flatten();
    compiler::CodeAssemblerLabel label48(&ca_);
    std::tie(tmp45, tmp46, tmp47) = Subslice_char16_0(state_, TorqueStructSlice_char16_ConstReference_char16_0{TNode<Object>{tmp42}, TNode<IntPtrT>{tmp43}, TNode<IntPtrT>{tmp44}, TorqueStructUnsafe_0{}}, TNode<IntPtrT>{phi_bb32_16}, TNode<IntPtrT>{tmp27}, &label48).Flatten();
    ca_.Goto(&block36, phi_bb32_15, phi_bb32_16, phi_bb32_18, phi_bb32_16);
    if (label48.is_used()) {
      ca_.Bind(&label48);
      ca_.Goto(&block37, phi_bb32_15, phi_bb32_16, phi_bb32_18, phi_bb32_16);
    }
  }

  TNode<String> phi_bb37_15;
  TNode<IntPtrT> phi_bb37_16;
  TNode<String> phi_bb37_18;
  TNode<IntPtrT> phi_bb37_23;
  if (block37.is_used()) {
    ca_.Bind(&block37, &phi_bb37_15, &phi_bb37_16, &phi_bb37_18, &phi_bb37_23);
    CodeStubAssembler(state_).PrintErr("halting because of unreachable code at src/objects/string.tq:257:67");
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<String> phi_bb36_15;
  TNode<IntPtrT> phi_bb36_16;
  TNode<String> phi_bb36_18;
  TNode<IntPtrT> phi_bb36_23;
  if (block36.is_used()) {
    ca_.Bind(&block36, &phi_bb36_15, &phi_bb36_16, &phi_bb36_18, &phi_bb36_23);
    ca_.Goto(&block16, tmp45, tmp46, tmp47);
  }

  TNode<String> phi_bb41_15;
  TNode<IntPtrT> phi_bb41_16;
  TNode<String> phi_bb41_18;
  TNode<ConsString> tmp49;
  if (block41.is_used()) {
    ca_.Bind(&block41, &phi_bb41_15, &phi_bb41_16, &phi_bb41_18);
    ca_.SetSourcePosition("../../../src/objects/string.tq", 262);
    compiler::CodeAssemblerLabel label50(&ca_);
    tmp49 = Cast_ConsString_1(state_, TNode<String>{ca_.UncheckedCast<String>(phi_bb41_18)}, &label50);
    ca_.Goto(&block44, phi_bb41_15, phi_bb41_16, phi_bb41_18);
    if (label50.is_used()) {
      ca_.Bind(&label50);
      ca_.Goto(&block45, phi_bb41_15, phi_bb41_16, phi_bb41_18);
    }
  }

  TNode<String> phi_bb40_15;
  TNode<IntPtrT> phi_bb40_16;
  TNode<String> phi_bb40_18;
  TNode<IntPtrT> tmp51;
  TNode<String> tmp52;
  if (block40.is_used()) {
    ca_.Bind(&block40, &phi_bb40_15, &phi_bb40_16, &phi_bb40_18);
    ca_.SetSourcePosition("../../../src/objects/string.tq", 260);
    tmp51 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp52 = CodeStubAssembler(state_).LoadReference<String>(CodeStubAssembler::Reference{tmp40, tmp51});
    ca_.SetSourcePosition("../../../src/objects/string.tq", 259);
    ca_.Goto(&block38, tmp52, phi_bb40_16, phi_bb40_18);
  }

  TNode<String> phi_bb45_15;
  TNode<IntPtrT> phi_bb45_16;
  TNode<String> phi_bb45_18;
  TNode<SlicedString> tmp53;
  if (block45.is_used()) {
    ca_.Bind(&block45, &phi_bb45_15, &phi_bb45_16, &phi_bb45_18);
    ca_.SetSourcePosition("../../../src/objects/string.tq", 265);
    compiler::CodeAssemblerLabel label54(&ca_);
    tmp53 = Cast_SlicedString_1(state_, TNode<String>{ca_.UncheckedCast<String>(phi_bb45_18)}, &label54);
    ca_.Goto(&block48, phi_bb45_15, phi_bb45_16, phi_bb45_18);
    if (label54.is_used()) {
      ca_.Bind(&label54);
      ca_.Goto(&block49, phi_bb45_15, phi_bb45_16, phi_bb45_18);
    }
  }

  TNode<String> phi_bb44_15;
  TNode<IntPtrT> phi_bb44_16;
  TNode<String> phi_bb44_18;
  TNode<String> tmp55;
  if (block44.is_used()) {
    ca_.Bind(&block44, &phi_bb44_15, &phi_bb44_16, &phi_bb44_18);
    ca_.SetSourcePosition("../../../src/objects/string.tq", 263);
    tmp55 = Flatten_1(state_, TNode<ConsString>{tmp49});
    ca_.SetSourcePosition("../../../src/objects/string.tq", 262);
    ca_.Goto(&block42, tmp55, phi_bb44_16, phi_bb44_18);
  }

  TNode<String> phi_bb49_15;
  TNode<IntPtrT> phi_bb49_16;
  TNode<String> phi_bb49_18;
  TNode<ExternalOneByteString> tmp56;
  if (block49.is_used()) {
    ca_.Bind(&block49, &phi_bb49_15, &phi_bb49_16, &phi_bb49_18);
    ca_.SetSourcePosition("../../../src/objects/string.tq", 269);
    compiler::CodeAssemblerLabel label57(&ca_);
    tmp56 = Cast_ExternalOneByteString_1(state_, TNode<String>{ca_.UncheckedCast<String>(phi_bb49_18)}, &label57);
    ca_.Goto(&block52, phi_bb49_15, phi_bb49_16, phi_bb49_18);
    if (label57.is_used()) {
      ca_.Bind(&label57);
      ca_.Goto(&block53, phi_bb49_15, phi_bb49_16, phi_bb49_18);
    }
  }

  TNode<String> phi_bb48_15;
  TNode<IntPtrT> phi_bb48_16;
  TNode<String> phi_bb48_18;
  TNode<IntPtrT> tmp58;
  TNode<Smi> tmp59;
  TNode<IntPtrT> tmp60;
  TNode<IntPtrT> tmp61;
  TNode<IntPtrT> tmp62;
  TNode<String> tmp63;
  if (block48.is_used()) {
    ca_.Bind(&block48, &phi_bb48_15, &phi_bb48_16, &phi_bb48_18);
    ca_.SetSourcePosition("../../../src/objects/string.tq", 266);
    tmp58 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    tmp59 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp53, tmp58});
    tmp60 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp59});
    tmp61 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb48_16}, TNode<IntPtrT>{tmp60});
    ca_.SetSourcePosition("../../../src/objects/string.tq", 267);
    tmp62 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp63 = CodeStubAssembler(state_).LoadReference<String>(CodeStubAssembler::Reference{tmp53, tmp62});
    ca_.SetSourcePosition("../../../src/objects/string.tq", 262);
    ca_.Goto(&block42, tmp63, tmp61, phi_bb48_18);
  }

  TNode<String> phi_bb53_15;
  TNode<IntPtrT> phi_bb53_16;
  TNode<String> phi_bb53_18;
  TNode<ExternalTwoByteString> tmp64;
  if (block53.is_used()) {
    ca_.Bind(&block53, &phi_bb53_15, &phi_bb53_16, &phi_bb53_18);
    ca_.SetSourcePosition("../../../src/objects/string.tq", 274);
    compiler::CodeAssemblerLabel label65(&ca_);
    tmp64 = Cast_ExternalTwoByteString_1(state_, TNode<String>{ca_.UncheckedCast<String>(phi_bb53_18)}, &label65);
    ca_.Goto(&block60, phi_bb53_15, phi_bb53_16, phi_bb53_18);
    if (label65.is_used()) {
      ca_.Bind(&label65);
      ca_.Goto(&block61, phi_bb53_15, phi_bb53_16, phi_bb53_18);
    }
  }

  TNode<String> phi_bb52_15;
  TNode<IntPtrT> phi_bb52_16;
  TNode<String> phi_bb52_18;
  TNode<RawPtrT> tmp66;
  TNode<IntPtrT> tmp67;
  TNode<Int32T> tmp68;
  TNode<IntPtrT> tmp69;
  TNode<Object> tmp70;
  TNode<IntPtrT> tmp71;
  TNode<IntPtrT> tmp72;
  TNode<Object> tmp73;
  TNode<IntPtrT> tmp74;
  TNode<IntPtrT> tmp75;
  if (block52.is_used()) {
    ca_.Bind(&block52, &phi_bb52_15, &phi_bb52_16, &phi_bb52_18);
    ca_.SetSourcePosition("../../../src/objects/string.tq", 271);
    tmp66 = Method_ExternalOneByteString_GetChars_0(state_, TNode<ExternalOneByteString>{tmp56});
    tmp67 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp68 = CodeStubAssembler(state_).LoadReference<Int32T>(CodeStubAssembler::Reference{tmp56, tmp67});
    tmp69 = Convert_intptr_int32_0(state_, TNode<Int32T>{tmp68});
    ca_.SetSourcePosition("../../../src/objects/string.tq", 270);
    std::tie(tmp70, tmp71, tmp72) = NewOffHeapConstSlice_char8_0(state_, TNode<RawPtrT>{tmp66}, TNode<IntPtrT>{tmp69}).Flatten();
    ca_.SetSourcePosition("../../../src/objects/string.tq", 272);
    compiler::CodeAssemblerLabel label76(&ca_);
    std::tie(tmp73, tmp74, tmp75) = Subslice_char8_0(state_, TorqueStructSlice_char8_ConstReference_char8_0{TNode<Object>{tmp70}, TNode<IntPtrT>{tmp71}, TNode<IntPtrT>{tmp72}, TorqueStructUnsafe_0{}}, TNode<IntPtrT>{phi_bb52_16}, TNode<IntPtrT>{tmp27}, &label76).Flatten();
    ca_.Goto(&block56, phi_bb52_15, phi_bb52_16, phi_bb52_18, phi_bb52_16);
    if (label76.is_used()) {
      ca_.Bind(&label76);
      ca_.Goto(&block57, phi_bb52_15, phi_bb52_16, phi_bb52_18, phi_bb52_16);
    }
  }

  TNode<String> phi_bb57_15;
  TNode<IntPtrT> phi_bb57_16;
  TNode<String> phi_bb57_18;
  TNode<IntPtrT> phi_bb57_26;
  if (block57.is_used()) {
    ca_.Bind(&block57, &phi_bb57_15, &phi_bb57_16, &phi_bb57_18, &phi_bb57_26);
    CodeStubAssembler(state_).PrintErr("halting because of unreachable code at src/objects/string.tq:272:63");
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<String> phi_bb56_15;
  TNode<IntPtrT> phi_bb56_16;
  TNode<String> phi_bb56_18;
  TNode<IntPtrT> phi_bb56_26;
  if (block56.is_used()) {
    ca_.Bind(&block56, &phi_bb56_15, &phi_bb56_16, &phi_bb56_18, &phi_bb56_26);
    ca_.Goto(&block18, tmp73, tmp74, tmp75);
  }

  TNode<String> phi_bb61_15;
  TNode<IntPtrT> phi_bb61_16;
  TNode<String> phi_bb61_18;
  if (block61.is_used()) {
    ca_.Bind(&block61, &phi_bb61_15, &phi_bb61_16, &phi_bb61_18);
    ca_.SetSourcePosition("../../../src/objects/string.tq", 280);
    CodeStubAssembler(state_).PrintErr("halting because of unreachable code at src/objects/string.tq:280:9");
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<String> phi_bb60_15;
  TNode<IntPtrT> phi_bb60_16;
  TNode<String> phi_bb60_18;
  TNode<RawPtrT> tmp77;
  TNode<IntPtrT> tmp78;
  TNode<Int32T> tmp79;
  TNode<IntPtrT> tmp80;
  TNode<Object> tmp81;
  TNode<IntPtrT> tmp82;
  TNode<IntPtrT> tmp83;
  TNode<Object> tmp84;
  TNode<IntPtrT> tmp85;
  TNode<IntPtrT> tmp86;
  if (block60.is_used()) {
    ca_.Bind(&block60, &phi_bb60_15, &phi_bb60_16, &phi_bb60_18);
    ca_.SetSourcePosition("../../../src/objects/string.tq", 276);
    tmp77 = Method_ExternalTwoByteString_GetChars_0(state_, TNode<ExternalTwoByteString>{tmp64});
    tmp78 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp79 = CodeStubAssembler(state_).LoadReference<Int32T>(CodeStubAssembler::Reference{tmp64, tmp78});
    tmp80 = Convert_intptr_int32_0(state_, TNode<Int32T>{tmp79});
    ca_.SetSourcePosition("../../../src/objects/string.tq", 275);
    std::tie(tmp81, tmp82, tmp83) = NewOffHeapConstSlice_char16_0(state_, TNode<RawPtrT>{tmp77}, TNode<IntPtrT>{tmp80}).Flatten();
    ca_.SetSourcePosition("../../../src/objects/string.tq", 277);
    compiler::CodeAssemblerLabel label87(&ca_);
    std::tie(tmp84, tmp85, tmp86) = Subslice_char16_0(state_, TorqueStructSlice_char16_ConstReference_char16_0{TNode<Object>{tmp81}, TNode<IntPtrT>{tmp82}, TNode<IntPtrT>{tmp83}, TorqueStructUnsafe_0{}}, TNode<IntPtrT>{phi_bb60_16}, TNode<IntPtrT>{tmp27}, &label87).Flatten();
    ca_.Goto(&block64, phi_bb60_15, phi_bb60_16, phi_bb60_18, phi_bb60_16);
    if (label87.is_used()) {
      ca_.Bind(&label87);
      ca_.Goto(&block65, phi_bb60_15, phi_bb60_16, phi_bb60_18, phi_bb60_16);
    }
  }

  TNode<String> phi_bb65_15;
  TNode<IntPtrT> phi_bb65_16;
  TNode<String> phi_bb65_18;
  TNode<IntPtrT> phi_bb65_26;
  if (block65.is_used()) {
    ca_.Bind(&block65, &phi_bb65_15, &phi_bb65_16, &phi_bb65_18, &phi_bb65_26);
    CodeStubAssembler(state_).PrintErr("halting because of unreachable code at src/objects/string.tq:277:63");
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<String> phi_bb64_15;
  TNode<IntPtrT> phi_bb64_16;
  TNode<String> phi_bb64_18;
  TNode<IntPtrT> phi_bb64_26;
  if (block64.is_used()) {
    ca_.Bind(&block64, &phi_bb64_15, &phi_bb64_16, &phi_bb64_18, &phi_bb64_26);
    ca_.Goto(&block16, tmp84, tmp85, tmp86);
  }

  TNode<String> phi_bb42_15;
  TNode<IntPtrT> phi_bb42_16;
  TNode<String> phi_bb42_18;
  if (block42.is_used()) {
    ca_.Bind(&block42, &phi_bb42_15, &phi_bb42_16, &phi_bb42_18);
    ca_.SetSourcePosition("../../../src/objects/string.tq", 259);
    ca_.Goto(&block38, phi_bb42_15, phi_bb42_16, phi_bb42_18);
  }

  TNode<String> phi_bb38_15;
  TNode<IntPtrT> phi_bb38_16;
  TNode<String> phi_bb38_18;
  if (block38.is_used()) {
    ca_.Bind(&block38, &phi_bb38_15, &phi_bb38_16, &phi_bb38_18);
    ca_.SetSourcePosition("../../../src/objects/string.tq", 251);
    ca_.Goto(&block21, phi_bb38_15, phi_bb38_16);
  }

  TNode<String> phi_bb20_15;
  TNode<IntPtrT> phi_bb20_16;
  if (block20.is_used()) {
    ca_.Bind(&block20, &phi_bb20_15, &phi_bb20_16);
    ca_.SetSourcePosition("../../../src/objects/string.tq", 284);
    VerifiedUnreachable_0(state_);
  }

  TNode<Object> phi_bb18_13;
  TNode<IntPtrT> phi_bb18_14;
  TNode<IntPtrT> phi_bb18_15;
  TNode<IntPtrT> tmp88;
  TNode<IntPtrT> tmp89;
  TNode<IntPtrT> tmp90;
  TNode<IntPtrT> tmp91;
  if (block18.is_used()) {
    ca_.Bind(&block18, &phi_bb18_13, &phi_bb18_14, &phi_bb18_15);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 128);
    tmp88 = TimesSizeOf_char8_0(state_, TNode<IntPtrT>{phi_bb18_15});
    tmp89 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb18_14}, TNode<IntPtrT>{tmp88});
    tmp90 = TimesSizeOf_char16_0(state_, TNode<IntPtrT>{tmp23});
    tmp91 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp22}, TNode<IntPtrT>{tmp90});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 788);
    ca_.Goto(&block70, phi_bb18_13, phi_bb18_14, phi_bb18_15, phi_bb18_13, phi_bb18_14, tmp22);
  }

  TNode<Object> phi_bb70_13;
  TNode<IntPtrT> phi_bb70_14;
  TNode<IntPtrT> phi_bb70_15;
  TNode<Object> phi_bb70_16;
  TNode<IntPtrT> phi_bb70_17;
  TNode<IntPtrT> phi_bb70_20;
  TNode<BoolT> tmp92;
  if (block70.is_used()) {
    ca_.Bind(&block70, &phi_bb70_13, &phi_bb70_14, &phi_bb70_15, &phi_bb70_16, &phi_bb70_17, &phi_bb70_20);
    tmp92 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Branch(tmp92, &block68, std::vector<compiler::Node*>{phi_bb70_13, phi_bb70_14, phi_bb70_15, phi_bb70_16, phi_bb70_17, phi_bb70_20}, &block69, std::vector<compiler::Node*>{phi_bb70_13, phi_bb70_14, phi_bb70_15, phi_bb70_16, phi_bb70_17, phi_bb70_20});
  }

  TNode<Object> phi_bb68_13;
  TNode<IntPtrT> phi_bb68_14;
  TNode<IntPtrT> phi_bb68_15;
  TNode<Object> phi_bb68_16;
  TNode<IntPtrT> phi_bb68_17;
  TNode<IntPtrT> phi_bb68_20;
  TNode<BoolT> tmp93;
  if (block68.is_used()) {
    ca_.Bind(&block68, &phi_bb68_13, &phi_bb68_14, &phi_bb68_15, &phi_bb68_16, &phi_bb68_17, &phi_bb68_20);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 201);
    tmp93 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{phi_bb68_20}, TNode<IntPtrT>{tmp91});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 213);
    ca_.Branch(tmp93, &block74, std::vector<compiler::Node*>{phi_bb68_13, phi_bb68_14, phi_bb68_15, phi_bb68_16, phi_bb68_17, phi_bb68_20}, &block75, std::vector<compiler::Node*>{phi_bb68_13, phi_bb68_14, phi_bb68_15, phi_bb68_16, phi_bb68_17, phi_bb68_20});
  }

  TNode<Object> phi_bb74_13;
  TNode<IntPtrT> phi_bb74_14;
  TNode<IntPtrT> phi_bb74_15;
  TNode<Object> phi_bb74_16;
  TNode<IntPtrT> phi_bb74_17;
  TNode<IntPtrT> phi_bb74_20;
  if (block74.is_used()) {
    ca_.Bind(&block74, &phi_bb74_13, &phi_bb74_14, &phi_bb74_15, &phi_bb74_16, &phi_bb74_17, &phi_bb74_20);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 789);
    ca_.Goto(&block69, phi_bb74_13, phi_bb74_14, phi_bb74_15, phi_bb74_16, phi_bb74_17, phi_bb74_20);
  }

  TNode<Object> phi_bb75_13;
  TNode<IntPtrT> phi_bb75_14;
  TNode<IntPtrT> phi_bb75_15;
  TNode<Object> phi_bb75_16;
  TNode<IntPtrT> phi_bb75_17;
  TNode<IntPtrT> phi_bb75_20;
  TNode<Object> tmp94;
  TNode<IntPtrT> tmp95;
  TNode<IntPtrT> tmp96;
  TNode<IntPtrT> tmp97;
  TNode<BoolT> tmp98;
  TNode<BoolT> tmp99;
  if (block75.is_used()) {
    ca_.Bind(&block75, &phi_bb75_13, &phi_bb75_14, &phi_bb75_15, &phi_bb75_16, &phi_bb75_17, &phi_bb75_20);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 216);
    std::tie(tmp94, tmp95) = NewReference_char16_0(state_, TNode<Object>{tmp21}, TNode<IntPtrT>{phi_bb75_20}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 217);
    tmp96 = FromConstexpr_intptr_constexpr_int31_0(state_, kUInt16Size);
    tmp97 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb75_20}, TNode<IntPtrT>{tmp96});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 201);
    tmp98 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{phi_bb75_17}, TNode<IntPtrT>{tmp89});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 223);
    tmp99 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp98});
    ca_.Branch(tmp99, &block80, std::vector<compiler::Node*>{phi_bb75_13, phi_bb75_14, phi_bb75_15, phi_bb75_16, phi_bb75_17}, &block81, std::vector<compiler::Node*>{phi_bb75_13, phi_bb75_14, phi_bb75_15, phi_bb75_16, phi_bb75_17});
  }

  TNode<Object> phi_bb81_13;
  TNode<IntPtrT> phi_bb81_14;
  TNode<IntPtrT> phi_bb81_15;
  TNode<Object> phi_bb81_16;
  TNode<IntPtrT> phi_bb81_17;
  if (block81.is_used()) {
    ca_.Bind(&block81, &phi_bb81_13, &phi_bb81_14, &phi_bb81_15, &phi_bb81_16, &phi_bb81_17);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/torque-internal.tq", 223});
      CodeStubAssembler(state_).FailAssert("Torque assert '!this.Empty()' failed", pos_stack);
    }
  }

  TNode<Object> phi_bb80_13;
  TNode<IntPtrT> phi_bb80_14;
  TNode<IntPtrT> phi_bb80_15;
  TNode<Object> phi_bb80_16;
  TNode<IntPtrT> phi_bb80_17;
  TNode<Object> tmp100;
  TNode<IntPtrT> tmp101;
  TNode<IntPtrT> tmp102;
  TNode<IntPtrT> tmp103;
  TNode<Uint8T> tmp104;
  TNode<Uint16T> tmp105;
  TNode<Uint16T> tmp106;
  if (block80.is_used()) {
    ca_.Bind(&block80, &phi_bb80_13, &phi_bb80_14, &phi_bb80_15, &phi_bb80_16, &phi_bb80_17);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 224);
    std::tie(tmp100, tmp101) = NewReference_char8_0(state_, TNode<Object>{phi_bb80_16}, TNode<IntPtrT>{phi_bb80_17}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 225);
    tmp102 = FromConstexpr_intptr_constexpr_int31_0(state_, kUInt8Size);
    tmp103 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb80_17}, TNode<IntPtrT>{tmp102});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 209);
    tmp104 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference{tmp100, tmp101});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 790);
    tmp105 = Convert_uint16_char8_0(state_, TNode<Uint8T>{tmp104});
    tmp106 = (TNode<Uint16T>{tmp105});
    CodeStubAssembler(state_).StoreReference<Uint16T>(CodeStubAssembler::Reference{tmp94, tmp95}, tmp106);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 788);
    ca_.Goto(&block70, phi_bb80_13, phi_bb80_14, phi_bb80_15, phi_bb80_16, tmp103, tmp97);
  }

  TNode<Object> phi_bb69_13;
  TNode<IntPtrT> phi_bb69_14;
  TNode<IntPtrT> phi_bb69_15;
  TNode<Object> phi_bb69_16;
  TNode<IntPtrT> phi_bb69_17;
  TNode<IntPtrT> phi_bb69_20;
  if (block69.is_used()) {
    ca_.Bind(&block69, &phi_bb69_13, &phi_bb69_14, &phi_bb69_15, &phi_bb69_16, &phi_bb69_17, &phi_bb69_20);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 792);
    ca_.Goto(&block15);
  }

  TNode<Object> phi_bb16_13;
  TNode<IntPtrT> phi_bb16_14;
  TNode<IntPtrT> phi_bb16_15;
  TNode<IntPtrT> tmp107;
  TNode<IntPtrT> tmp108;
  TNode<IntPtrT> tmp109;
  TNode<IntPtrT> tmp110;
  if (block16.is_used()) {
    ca_.Bind(&block16, &phi_bb16_13, &phi_bb16_14, &phi_bb16_15);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 128);
    tmp107 = TimesSizeOf_char16_0(state_, TNode<IntPtrT>{phi_bb16_15});
    tmp108 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb16_14}, TNode<IntPtrT>{tmp107});
    tmp109 = TimesSizeOf_char16_0(state_, TNode<IntPtrT>{tmp23});
    tmp110 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp22}, TNode<IntPtrT>{tmp109});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 795);
    ca_.Goto(&block87, phi_bb16_13, phi_bb16_14, phi_bb16_15, phi_bb16_13, phi_bb16_14, tmp22);
  }

  TNode<Object> phi_bb87_13;
  TNode<IntPtrT> phi_bb87_14;
  TNode<IntPtrT> phi_bb87_15;
  TNode<Object> phi_bb87_16;
  TNode<IntPtrT> phi_bb87_17;
  TNode<IntPtrT> phi_bb87_20;
  TNode<BoolT> tmp111;
  if (block87.is_used()) {
    ca_.Bind(&block87, &phi_bb87_13, &phi_bb87_14, &phi_bb87_15, &phi_bb87_16, &phi_bb87_17, &phi_bb87_20);
    tmp111 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Branch(tmp111, &block85, std::vector<compiler::Node*>{phi_bb87_13, phi_bb87_14, phi_bb87_15, phi_bb87_16, phi_bb87_17, phi_bb87_20}, &block86, std::vector<compiler::Node*>{phi_bb87_13, phi_bb87_14, phi_bb87_15, phi_bb87_16, phi_bb87_17, phi_bb87_20});
  }

  TNode<Object> phi_bb85_13;
  TNode<IntPtrT> phi_bb85_14;
  TNode<IntPtrT> phi_bb85_15;
  TNode<Object> phi_bb85_16;
  TNode<IntPtrT> phi_bb85_17;
  TNode<IntPtrT> phi_bb85_20;
  TNode<BoolT> tmp112;
  if (block85.is_used()) {
    ca_.Bind(&block85, &phi_bb85_13, &phi_bb85_14, &phi_bb85_15, &phi_bb85_16, &phi_bb85_17, &phi_bb85_20);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 201);
    tmp112 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{phi_bb85_20}, TNode<IntPtrT>{tmp110});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 213);
    ca_.Branch(tmp112, &block91, std::vector<compiler::Node*>{phi_bb85_13, phi_bb85_14, phi_bb85_15, phi_bb85_16, phi_bb85_17, phi_bb85_20}, &block92, std::vector<compiler::Node*>{phi_bb85_13, phi_bb85_14, phi_bb85_15, phi_bb85_16, phi_bb85_17, phi_bb85_20});
  }

  TNode<Object> phi_bb91_13;
  TNode<IntPtrT> phi_bb91_14;
  TNode<IntPtrT> phi_bb91_15;
  TNode<Object> phi_bb91_16;
  TNode<IntPtrT> phi_bb91_17;
  TNode<IntPtrT> phi_bb91_20;
  if (block91.is_used()) {
    ca_.Bind(&block91, &phi_bb91_13, &phi_bb91_14, &phi_bb91_15, &phi_bb91_16, &phi_bb91_17, &phi_bb91_20);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 796);
    ca_.Goto(&block86, phi_bb91_13, phi_bb91_14, phi_bb91_15, phi_bb91_16, phi_bb91_17, phi_bb91_20);
  }

  TNode<Object> phi_bb92_13;
  TNode<IntPtrT> phi_bb92_14;
  TNode<IntPtrT> phi_bb92_15;
  TNode<Object> phi_bb92_16;
  TNode<IntPtrT> phi_bb92_17;
  TNode<IntPtrT> phi_bb92_20;
  TNode<Object> tmp113;
  TNode<IntPtrT> tmp114;
  TNode<IntPtrT> tmp115;
  TNode<IntPtrT> tmp116;
  TNode<BoolT> tmp117;
  TNode<BoolT> tmp118;
  if (block92.is_used()) {
    ca_.Bind(&block92, &phi_bb92_13, &phi_bb92_14, &phi_bb92_15, &phi_bb92_16, &phi_bb92_17, &phi_bb92_20);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 216);
    std::tie(tmp113, tmp114) = NewReference_char16_0(state_, TNode<Object>{tmp21}, TNode<IntPtrT>{phi_bb92_20}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 217);
    tmp115 = FromConstexpr_intptr_constexpr_int31_0(state_, kUInt16Size);
    tmp116 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb92_20}, TNode<IntPtrT>{tmp115});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 201);
    tmp117 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{phi_bb92_17}, TNode<IntPtrT>{tmp108});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 223);
    tmp118 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp117});
    ca_.Branch(tmp118, &block97, std::vector<compiler::Node*>{phi_bb92_13, phi_bb92_14, phi_bb92_15, phi_bb92_16, phi_bb92_17}, &block98, std::vector<compiler::Node*>{phi_bb92_13, phi_bb92_14, phi_bb92_15, phi_bb92_16, phi_bb92_17});
  }

  TNode<Object> phi_bb98_13;
  TNode<IntPtrT> phi_bb98_14;
  TNode<IntPtrT> phi_bb98_15;
  TNode<Object> phi_bb98_16;
  TNode<IntPtrT> phi_bb98_17;
  if (block98.is_used()) {
    ca_.Bind(&block98, &phi_bb98_13, &phi_bb98_14, &phi_bb98_15, &phi_bb98_16, &phi_bb98_17);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/torque-internal.tq", 223});
      CodeStubAssembler(state_).FailAssert("Torque assert '!this.Empty()' failed", pos_stack);
    }
  }

  TNode<Object> phi_bb97_13;
  TNode<IntPtrT> phi_bb97_14;
  TNode<IntPtrT> phi_bb97_15;
  TNode<Object> phi_bb97_16;
  TNode<IntPtrT> phi_bb97_17;
  TNode<Object> tmp119;
  TNode<IntPtrT> tmp120;
  TNode<IntPtrT> tmp121;
  TNode<IntPtrT> tmp122;
  TNode<Uint16T> tmp123;
  if (block97.is_used()) {
    ca_.Bind(&block97, &phi_bb97_13, &phi_bb97_14, &phi_bb97_15, &phi_bb97_16, &phi_bb97_17);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 224);
    std::tie(tmp119, tmp120) = NewReference_char16_0(state_, TNode<Object>{phi_bb97_16}, TNode<IntPtrT>{phi_bb97_17}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 225);
    tmp121 = FromConstexpr_intptr_constexpr_int31_0(state_, kUInt16Size);
    tmp122 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb97_17}, TNode<IntPtrT>{tmp121});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 209);
    tmp123 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference{tmp119, tmp120});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 797);
    CodeStubAssembler(state_).StoreReference<Uint16T>(CodeStubAssembler::Reference{tmp113, tmp114}, tmp123);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 795);
    ca_.Goto(&block87, phi_bb97_13, phi_bb97_14, phi_bb97_15, phi_bb97_16, tmp122, tmp116);
  }

  TNode<Object> phi_bb86_13;
  TNode<IntPtrT> phi_bb86_14;
  TNode<IntPtrT> phi_bb86_15;
  TNode<Object> phi_bb86_16;
  TNode<IntPtrT> phi_bb86_17;
  TNode<IntPtrT> phi_bb86_20;
  if (block86.is_used()) {
    ca_.Bind(&block86, &phi_bb86_13, &phi_bb86_14, &phi_bb86_15, &phi_bb86_16, &phi_bb86_17, &phi_bb86_20);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 783);
    ca_.Goto(&block15);
  }

  if (block15.is_used()) {
    ca_.Bind(&block15);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 800);
    arguments.PopAndReturn(tmp18);
  }

  if (block2.is_used()) {
    ca_.Bind(&block2);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 802);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{parameter0}, MessageTemplate::kInvalidArgument);
  }
}

TF_BUILTIN(WasmStringNewWtf8, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Uint32T> parameter0 = UncheckedParameter<Uint32T>(Descriptor::kOffset);
  USE(parameter0);
  TNode<Uint32T> parameter1 = UncheckedParameter<Uint32T>(Descriptor::kSize);
  USE(parameter1);
  TNode<Smi> parameter2 = UncheckedParameter<Smi>(Descriptor::kMemory);
  USE(parameter2);
  TNode<Smi> parameter3 = UncheckedParameter<Smi>(Descriptor::kUtf8Variant);
  USE(parameter3);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<WasmInstanceObject> tmp0;
  TNode<NativeContext> tmp1;
  TNode<Number> tmp2;
  TNode<Number> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 808);
    tmp0 = WasmBuiltinsAssembler(state_).LoadInstanceFromFrame();
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 810);
    tmp1 = WasmBuiltinsAssembler(state_).LoadContextFromInstance(TNode<WasmInstanceObject>{tmp0});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 811);
    tmp2 = ca_.CallStub<Number>(Builtins::CallableFor(ca_.isolate(), Builtin::kWasmUint32ToNumber), TNode<Object>(), parameter0);
    tmp3 = ca_.CallStub<Number>(Builtins::CallableFor(ca_.isolate(), Builtin::kWasmUint32ToNumber), TNode<Object>(), parameter1);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 809);
    CodeStubAssembler(state_).TailCallRuntime(Runtime::kWasmStringNewWtf8, tmp1, tmp0, parameter2, parameter3, tmp2, tmp3);
  }
}

TF_BUILTIN(WasmStringNewWtf8Array, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Uint32T> parameter0 = UncheckedParameter<Uint32T>(Descriptor::kStart);
  USE(parameter0);
  TNode<Uint32T> parameter1 = UncheckedParameter<Uint32T>(Descriptor::kEnd);
  USE(parameter1);
  TNode<WasmArray> parameter2 = UncheckedParameter<WasmArray>(Descriptor::kArray);
  USE(parameter2);
  TNode<Smi> parameter3 = UncheckedParameter<Smi>(Descriptor::kUtf8Variant);
  USE(parameter3);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    ca_.Goto(&block0);

  TNode<NativeContext> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<Uint32T> tmp2;
  TNode<BoolT> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 815);
    tmp0 = LoadContextFromFrame_0(state_);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 817);
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp2 = CodeStubAssembler(state_).LoadReference<Uint32T>(CodeStubAssembler::Reference{parameter2, tmp1});
    tmp3 = CodeStubAssembler(state_).Uint32LessThan(TNode<Uint32T>{tmp2}, TNode<Uint32T>{parameter1});
    ca_.Branch(tmp3, &block3, std::vector<compiler::Node*>{}, &block4, std::vector<compiler::Node*>{});
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    ca_.Goto(&block2);
  }

  TNode<BoolT> tmp4;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 818);
    tmp4 = CodeStubAssembler(state_).Uint32LessThan(TNode<Uint32T>{parameter1}, TNode<Uint32T>{parameter0});
    ca_.Branch(tmp4, &block5, std::vector<compiler::Node*>{}, &block6, std::vector<compiler::Node*>{});
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    ca_.Goto(&block2);
  }

  TNode<Smi> tmp5;
  TNode<Smi> tmp6;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 820);
    tmp5 = CodeStubAssembler(state_).SmiFromUint32(TNode<Uint32T>{parameter0});
    tmp6 = CodeStubAssembler(state_).SmiFromUint32(TNode<Uint32T>{parameter1});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 819);
    CodeStubAssembler(state_).TailCallRuntime(Runtime::kWasmStringNewWtf8Array, tmp0, parameter3, parameter2, tmp5, tmp6);
  }

  TNode<Smi> tmp7;
  TNode<Object> tmp8;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 823);
    tmp7 = CodeStubAssembler(state_).SmiConstant(MessageTemplate::kWasmTrapArrayOutOfBounds);
    tmp8 = CodeStubAssembler(state_).CallRuntime(Runtime::kThrowWasmError, tmp0, tmp7); 
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 824);
    CodeStubAssembler(state_).PrintErr("halting because of unreachable code at src/builtins/wasm.tq:824:5");
    CodeStubAssembler(state_).Unreachable();
  }
}

TF_BUILTIN(WasmStringNewWtf16, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Uint32T> parameter0 = UncheckedParameter<Uint32T>(Descriptor::kMemory);
  USE(parameter0);
  TNode<Uint32T> parameter1 = UncheckedParameter<Uint32T>(Descriptor::kOffset);
  USE(parameter1);
  TNode<Uint32T> parameter2 = UncheckedParameter<Uint32T>(Descriptor::kSize);
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<WasmInstanceObject> tmp0;
  TNode<NativeContext> tmp1;
  TNode<Smi> tmp2;
  TNode<Number> tmp3;
  TNode<Number> tmp4;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 829);
    tmp0 = WasmBuiltinsAssembler(state_).LoadInstanceFromFrame();
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 831);
    tmp1 = WasmBuiltinsAssembler(state_).LoadContextFromInstance(TNode<WasmInstanceObject>{tmp0});
    tmp2 = CodeStubAssembler(state_).SmiFromUint32(TNode<Uint32T>{parameter0});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 832);
    tmp3 = ca_.CallStub<Number>(Builtins::CallableFor(ca_.isolate(), Builtin::kWasmUint32ToNumber), TNode<Object>(), parameter1);
    tmp4 = ca_.CallStub<Number>(Builtins::CallableFor(ca_.isolate(), Builtin::kWasmUint32ToNumber), TNode<Object>(), parameter2);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 830);
    CodeStubAssembler(state_).TailCallRuntime(Runtime::kWasmStringNewWtf16, tmp1, tmp0, tmp2, tmp3, tmp4);
  }
}

TF_BUILTIN(WasmStringNewWtf16Array, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<WasmArray> parameter0 = UncheckedParameter<WasmArray>(Descriptor::kArray);
  USE(parameter0);
  TNode<Uint32T> parameter1 = UncheckedParameter<Uint32T>(Descriptor::kStart);
  USE(parameter1);
  TNode<Uint32T> parameter2 = UncheckedParameter<Uint32T>(Descriptor::kEnd);
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block30(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block31(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, Uint32T> block34(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, Uint32T> block32(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, Uint32T> block33(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, Uint32T> block36(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, Uint32T> block37(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Uint32T> tmp1;
  TNode<BoolT> tmp2;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 853);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp1 = CodeStubAssembler(state_).LoadReference<Uint32T>(CodeStubAssembler::Reference{parameter0, tmp0});
    tmp2 = CodeStubAssembler(state_).Uint32LessThan(TNode<Uint32T>{tmp1}, TNode<Uint32T>{parameter2});
    ca_.Branch(tmp2, &block5, std::vector<compiler::Node*>{}, &block6, std::vector<compiler::Node*>{});
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    ca_.Goto(&block4);
  }

  TNode<BoolT> tmp3;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 854);
    tmp3 = CodeStubAssembler(state_).Uint32LessThan(TNode<Uint32T>{parameter2}, TNode<Uint32T>{parameter1});
    ca_.Branch(tmp3, &block7, std::vector<compiler::Node*>{}, &block8, std::vector<compiler::Node*>{});
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    ca_.Goto(&block4);
  }

  TNode<Uint32T> tmp4;
  TNode<Uint32T> tmp5;
  TNode<BoolT> tmp6;
  if (block8.is_used()) {
    ca_.Bind(&block8);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 855);
    tmp4 = CodeStubAssembler(state_).Uint32Sub(TNode<Uint32T>{parameter2}, TNode<Uint32T>{parameter1});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 856);
    tmp5 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp6 = CodeStubAssembler(state_).Word32Equal(TNode<Uint32T>{tmp4}, TNode<Uint32T>{tmp5});
    ca_.Branch(tmp6, &block9, std::vector<compiler::Node*>{}, &block10, std::vector<compiler::Node*>{});
  }

  TNode<String> tmp7;
  if (block9.is_used()) {
    ca_.Bind(&block9);
    tmp7 = kEmptyString_0(state_);
    CodeStubAssembler(state_).Return(tmp7);
  }

  TNode<Uint32T> tmp8;
  TNode<BoolT> tmp9;
  if (block10.is_used()) {
    ca_.Bind(&block10);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 860);
    tmp8 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x20ull));
    tmp9 = CodeStubAssembler(state_).Uint32GreaterThanOrEqual(TNode<Uint32T>{tmp4}, TNode<Uint32T>{tmp8});
    ca_.Branch(tmp9, &block11, std::vector<compiler::Node*>{}, &block12, std::vector<compiler::Node*>{});
  }

  TNode<NativeContext> tmp10;
  TNode<Smi> tmp11;
  TNode<Smi> tmp12;
  if (block11.is_used()) {
    ca_.Bind(&block11);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 934);
    tmp10 = LoadContextFromFrame_0(state_);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 936);
    tmp11 = CodeStubAssembler(state_).SmiFromUint32(TNode<Uint32T>{parameter1});
    tmp12 = CodeStubAssembler(state_).SmiFromUint32(TNode<Uint32T>{parameter2});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 935);
    CodeStubAssembler(state_).TailCallRuntime(Runtime::kWasmStringNewWtf16Array, tmp10, parameter0, tmp11, tmp12);
  }

  TNode<IntPtrT> tmp13;
  TNode<IntPtrT> tmp14;
  TNode<Uint32T> tmp15;
  TNode<IntPtrT> tmp16;
  TNode<IntPtrT> tmp17;
  TNode<Object> tmp18;
  TNode<IntPtrT> tmp19;
  TNode<IntPtrT> tmp20;
  TNode<IntPtrT> tmp21;
  TNode<Object> tmp22;
  TNode<IntPtrT> tmp23;
  TNode<IntPtrT> tmp24;
  if (block12.is_used()) {
    ca_.Bind(&block12);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 861);
    tmp13 = Convert_intptr_uint32_0(state_, TNode<Uint32T>{tmp4});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 863);
    tmp14 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp15 = CodeStubAssembler(state_).LoadReference<Uint32T>(CodeStubAssembler::Reference{parameter0, tmp14});
    tmp16 = Convert_intptr_uint32_0(state_, TNode<Uint32T>{tmp15});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 862);
    tmp17 = FromConstexpr_intptr_constexpr_int32_0(state_, WasmArray::kHeaderSize);
    std::tie(tmp18, tmp19, tmp20) = NewConstSlice_char16_0(state_, TNode<Object>{parameter0}, TNode<IntPtrT>{tmp17}, TNode<IntPtrT>{tmp16}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 865);
    tmp21 = Convert_intptr_uint32_0(state_, TNode<Uint32T>{parameter1});
    compiler::CodeAssemblerLabel label25(&ca_);
    std::tie(tmp22, tmp23, tmp24) = Subslice_char16_0(state_, TorqueStructSlice_char16_ConstReference_char16_0{TNode<Object>{tmp18}, TNode<IntPtrT>{tmp19}, TNode<IntPtrT>{tmp20}, TorqueStructUnsafe_0{}}, TNode<IntPtrT>{tmp21}, TNode<IntPtrT>{tmp13}, &label25).Flatten();
    ca_.Goto(&block15);
    if (label25.is_used()) {
      ca_.Bind(&label25);
      ca_.Goto(&block16);
    }
  }

  if (block16.is_used()) {
    ca_.Bind(&block16);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 866);
    ca_.Goto(&block4);
  }

  TNode<IntPtrT> tmp26;
  TNode<IntPtrT> tmp27;
  TNode<IntPtrT> tmp28;
  if (block15.is_used()) {
    ca_.Bind(&block15);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 897);
    tmp26 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 898);
    tmp27 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x8ull));
    tmp28 = CodeStubAssembler(state_).IntPtrSub(TNode<IntPtrT>{tmp13}, TNode<IntPtrT>{tmp27});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 899);
    ca_.Goto(&block21, tmp26);
  }

  TNode<IntPtrT> phi_bb21_11;
  TNode<BoolT> tmp29;
  if (block21.is_used()) {
    ca_.Bind(&block21, &phi_bb21_11);
    tmp29 = CodeStubAssembler(state_).IntPtrLessThanOrEqual(TNode<IntPtrT>{phi_bb21_11}, TNode<IntPtrT>{tmp28});
    ca_.Branch(tmp29, &block19, std::vector<compiler::Node*>{phi_bb21_11}, &block20, std::vector<compiler::Node*>{phi_bb21_11});
  }

  TNode<IntPtrT> phi_bb19_11;
  TNode<IntPtrT> tmp30;
  TNode<IntPtrT> tmp31;
  TNode<Object> tmp32;
  TNode<IntPtrT> tmp33;
  TNode<Uint16T> tmp34;
  TNode<Uint32T> tmp35;
  TNode<IntPtrT> tmp36;
  TNode<IntPtrT> tmp37;
  TNode<IntPtrT> tmp38;
  TNode<IntPtrT> tmp39;
  TNode<Object> tmp40;
  TNode<IntPtrT> tmp41;
  TNode<Uint16T> tmp42;
  TNode<Uint32T> tmp43;
  TNode<Uint32T> tmp44;
  TNode<IntPtrT> tmp45;
  TNode<IntPtrT> tmp46;
  TNode<IntPtrT> tmp47;
  TNode<IntPtrT> tmp48;
  TNode<Object> tmp49;
  TNode<IntPtrT> tmp50;
  TNode<Uint16T> tmp51;
  TNode<Uint32T> tmp52;
  TNode<Uint32T> tmp53;
  TNode<IntPtrT> tmp54;
  TNode<IntPtrT> tmp55;
  TNode<IntPtrT> tmp56;
  TNode<IntPtrT> tmp57;
  TNode<Object> tmp58;
  TNode<IntPtrT> tmp59;
  TNode<Uint16T> tmp60;
  TNode<Uint32T> tmp61;
  TNode<Uint32T> tmp62;
  TNode<IntPtrT> tmp63;
  TNode<IntPtrT> tmp64;
  TNode<IntPtrT> tmp65;
  TNode<IntPtrT> tmp66;
  TNode<Object> tmp67;
  TNode<IntPtrT> tmp68;
  TNode<Uint16T> tmp69;
  TNode<Uint32T> tmp70;
  TNode<Uint32T> tmp71;
  TNode<IntPtrT> tmp72;
  TNode<IntPtrT> tmp73;
  TNode<IntPtrT> tmp74;
  TNode<IntPtrT> tmp75;
  TNode<Object> tmp76;
  TNode<IntPtrT> tmp77;
  TNode<Uint16T> tmp78;
  TNode<Uint32T> tmp79;
  TNode<Uint32T> tmp80;
  TNode<IntPtrT> tmp81;
  TNode<IntPtrT> tmp82;
  TNode<IntPtrT> tmp83;
  TNode<IntPtrT> tmp84;
  TNode<Object> tmp85;
  TNode<IntPtrT> tmp86;
  TNode<Uint16T> tmp87;
  TNode<Uint32T> tmp88;
  TNode<Uint32T> tmp89;
  TNode<IntPtrT> tmp90;
  TNode<IntPtrT> tmp91;
  TNode<IntPtrT> tmp92;
  TNode<IntPtrT> tmp93;
  TNode<Object> tmp94;
  TNode<IntPtrT> tmp95;
  TNode<Uint16T> tmp96;
  TNode<Uint32T> tmp97;
  TNode<Uint32T> tmp98;
  TNode<Uint32T> tmp99;
  TNode<BoolT> tmp100;
  if (block19.is_used()) {
    ca_.Bind(&block19, &phi_bb19_11);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 97);
    tmp30 = TimesSizeOf_char16_0(state_, TNode<IntPtrT>{phi_bb19_11});
    tmp31 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp23}, TNode<IntPtrT>{tmp30});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 96);
    std::tie(tmp32, tmp33) = NewReference_char16_0(state_, TNode<Object>{tmp22}, TNode<IntPtrT>{tmp31}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 900);
    tmp34 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference{tmp32, tmp33});
    tmp35 = Convert_uint32_char16_0(state_, TNode<Uint16T>{tmp34});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 901);
    tmp36 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp37 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb19_11}, TNode<IntPtrT>{tmp36});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 97);
    tmp38 = TimesSizeOf_char16_0(state_, TNode<IntPtrT>{tmp37});
    tmp39 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp23}, TNode<IntPtrT>{tmp38});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 96);
    std::tie(tmp40, tmp41) = NewReference_char16_0(state_, TNode<Object>{tmp22}, TNode<IntPtrT>{tmp39}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 901);
    tmp42 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference{tmp40, tmp41});
    tmp43 = Convert_uint32_char16_0(state_, TNode<Uint16T>{tmp42});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 900);
    tmp44 = CodeStubAssembler(state_).Word32Or(TNode<Uint32T>{tmp35}, TNode<Uint32T>{tmp43});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 902);
    tmp45 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x2ull));
    tmp46 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb19_11}, TNode<IntPtrT>{tmp45});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 97);
    tmp47 = TimesSizeOf_char16_0(state_, TNode<IntPtrT>{tmp46});
    tmp48 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp23}, TNode<IntPtrT>{tmp47});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 96);
    std::tie(tmp49, tmp50) = NewReference_char16_0(state_, TNode<Object>{tmp22}, TNode<IntPtrT>{tmp48}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 902);
    tmp51 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference{tmp49, tmp50});
    tmp52 = Convert_uint32_char16_0(state_, TNode<Uint16T>{tmp51});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 900);
    tmp53 = CodeStubAssembler(state_).Word32Or(TNode<Uint32T>{tmp44}, TNode<Uint32T>{tmp52});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 903);
    tmp54 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x3ull));
    tmp55 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb19_11}, TNode<IntPtrT>{tmp54});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 97);
    tmp56 = TimesSizeOf_char16_0(state_, TNode<IntPtrT>{tmp55});
    tmp57 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp23}, TNode<IntPtrT>{tmp56});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 96);
    std::tie(tmp58, tmp59) = NewReference_char16_0(state_, TNode<Object>{tmp22}, TNode<IntPtrT>{tmp57}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 903);
    tmp60 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference{tmp58, tmp59});
    tmp61 = Convert_uint32_char16_0(state_, TNode<Uint16T>{tmp60});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 900);
    tmp62 = CodeStubAssembler(state_).Word32Or(TNode<Uint32T>{tmp53}, TNode<Uint32T>{tmp61});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 904);
    tmp63 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x4ull));
    tmp64 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb19_11}, TNode<IntPtrT>{tmp63});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 97);
    tmp65 = TimesSizeOf_char16_0(state_, TNode<IntPtrT>{tmp64});
    tmp66 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp23}, TNode<IntPtrT>{tmp65});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 96);
    std::tie(tmp67, tmp68) = NewReference_char16_0(state_, TNode<Object>{tmp22}, TNode<IntPtrT>{tmp66}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 904);
    tmp69 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference{tmp67, tmp68});
    tmp70 = Convert_uint32_char16_0(state_, TNode<Uint16T>{tmp69});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 900);
    tmp71 = CodeStubAssembler(state_).Word32Or(TNode<Uint32T>{tmp62}, TNode<Uint32T>{tmp70});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 905);
    tmp72 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x5ull));
    tmp73 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb19_11}, TNode<IntPtrT>{tmp72});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 97);
    tmp74 = TimesSizeOf_char16_0(state_, TNode<IntPtrT>{tmp73});
    tmp75 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp23}, TNode<IntPtrT>{tmp74});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 96);
    std::tie(tmp76, tmp77) = NewReference_char16_0(state_, TNode<Object>{tmp22}, TNode<IntPtrT>{tmp75}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 905);
    tmp78 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference{tmp76, tmp77});
    tmp79 = Convert_uint32_char16_0(state_, TNode<Uint16T>{tmp78});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 900);
    tmp80 = CodeStubAssembler(state_).Word32Or(TNode<Uint32T>{tmp71}, TNode<Uint32T>{tmp79});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 906);
    tmp81 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x6ull));
    tmp82 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb19_11}, TNode<IntPtrT>{tmp81});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 97);
    tmp83 = TimesSizeOf_char16_0(state_, TNode<IntPtrT>{tmp82});
    tmp84 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp23}, TNode<IntPtrT>{tmp83});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 96);
    std::tie(tmp85, tmp86) = NewReference_char16_0(state_, TNode<Object>{tmp22}, TNode<IntPtrT>{tmp84}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 906);
    tmp87 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference{tmp85, tmp86});
    tmp88 = Convert_uint32_char16_0(state_, TNode<Uint16T>{tmp87});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 900);
    tmp89 = CodeStubAssembler(state_).Word32Or(TNode<Uint32T>{tmp80}, TNode<Uint32T>{tmp88});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 907);
    tmp90 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x7ull));
    tmp91 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb19_11}, TNode<IntPtrT>{tmp90});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 97);
    tmp92 = TimesSizeOf_char16_0(state_, TNode<IntPtrT>{tmp91});
    tmp93 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp23}, TNode<IntPtrT>{tmp92});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 96);
    std::tie(tmp94, tmp95) = NewReference_char16_0(state_, TNode<Object>{tmp22}, TNode<IntPtrT>{tmp93}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 907);
    tmp96 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference{tmp94, tmp95});
    tmp97 = Convert_uint32_char16_0(state_, TNode<Uint16T>{tmp96});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 900);
    tmp98 = CodeStubAssembler(state_).Word32Or(TNode<Uint32T>{tmp89}, TNode<Uint32T>{tmp97});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 908);
    tmp99 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0xffull));
    tmp100 = CodeStubAssembler(state_).Uint32GreaterThan(TNode<Uint32T>{tmp98}, TNode<Uint32T>{tmp99});
    ca_.Branch(tmp100, &block30, std::vector<compiler::Node*>{phi_bb19_11}, &block31, std::vector<compiler::Node*>{phi_bb19_11});
  }

  TNode<IntPtrT> phi_bb30_11;
  if (block30.is_used()) {
    ca_.Bind(&block30, &phi_bb30_11);
    ca_.Goto(&block18);
  }

  TNode<IntPtrT> phi_bb31_11;
  TNode<IntPtrT> tmp101;
  TNode<IntPtrT> tmp102;
  if (block31.is_used()) {
    ca_.Bind(&block31, &phi_bb31_11);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 909);
    tmp101 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x8ull));
    tmp102 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb31_11}, TNode<IntPtrT>{tmp101});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 899);
    ca_.Goto(&block21, tmp102);
  }

  TNode<IntPtrT> phi_bb20_11;
  TNode<Uint32T> tmp103;
  if (block20.is_used()) {
    ca_.Bind(&block20, &phi_bb20_11);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 911);
    tmp103 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 912);
    ca_.Goto(&block34, phi_bb20_11, tmp103);
  }

  TNode<IntPtrT> phi_bb34_11;
  TNode<Uint32T> phi_bb34_13;
  TNode<BoolT> tmp104;
  if (block34.is_used()) {
    ca_.Bind(&block34, &phi_bb34_11, &phi_bb34_13);
    tmp104 = CodeStubAssembler(state_).IntPtrLessThan(TNode<IntPtrT>{phi_bb34_11}, TNode<IntPtrT>{tmp13});
    ca_.Branch(tmp104, &block32, std::vector<compiler::Node*>{phi_bb34_11, phi_bb34_13}, &block33, std::vector<compiler::Node*>{phi_bb34_11, phi_bb34_13});
  }

  TNode<IntPtrT> phi_bb32_11;
  TNode<Uint32T> phi_bb32_13;
  TNode<IntPtrT> tmp105;
  TNode<IntPtrT> tmp106;
  TNode<Object> tmp107;
  TNode<IntPtrT> tmp108;
  TNode<Uint16T> tmp109;
  TNode<Uint32T> tmp110;
  TNode<Uint32T> tmp111;
  TNode<IntPtrT> tmp112;
  TNode<IntPtrT> tmp113;
  if (block32.is_used()) {
    ca_.Bind(&block32, &phi_bb32_11, &phi_bb32_13);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 97);
    tmp105 = TimesSizeOf_char16_0(state_, TNode<IntPtrT>{phi_bb32_11});
    tmp106 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp23}, TNode<IntPtrT>{tmp105});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 96);
    std::tie(tmp107, tmp108) = NewReference_char16_0(state_, TNode<Object>{tmp22}, TNode<IntPtrT>{tmp106}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 913);
    tmp109 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference{tmp107, tmp108});
    tmp110 = Convert_uint32_char16_0(state_, TNode<Uint16T>{tmp109});
    tmp111 = CodeStubAssembler(state_).Word32Or(TNode<Uint32T>{phi_bb32_13}, TNode<Uint32T>{tmp110});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 914);
    tmp112 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp113 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb32_11}, TNode<IntPtrT>{tmp112});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 912);
    ca_.Goto(&block34, tmp113, tmp111);
  }

  TNode<IntPtrT> phi_bb33_11;
  TNode<Uint32T> phi_bb33_13;
  TNode<Uint32T> tmp114;
  TNode<BoolT> tmp115;
  if (block33.is_used()) {
    ca_.Bind(&block33, &phi_bb33_11, &phi_bb33_13);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 916);
    tmp114 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0xffull));
    tmp115 = CodeStubAssembler(state_).Uint32GreaterThan(TNode<Uint32T>{phi_bb33_13}, TNode<Uint32T>{tmp114});
    ca_.Branch(tmp115, &block36, std::vector<compiler::Node*>{phi_bb33_11, phi_bb33_13}, &block37, std::vector<compiler::Node*>{phi_bb33_11, phi_bb33_13});
  }

  TNode<IntPtrT> phi_bb36_11;
  TNode<Uint32T> phi_bb36_13;
  if (block36.is_used()) {
    ca_.Bind(&block36, &phi_bb36_11, &phi_bb36_13);
    ca_.Goto(&block18);
  }

  TNode<IntPtrT> phi_bb37_11;
  TNode<Uint32T> phi_bb37_13;
  TNode<IntPtrT> tmp116;
  TNode<IntPtrT> tmp117;
  TNode<IntPtrT> tmp118;
  TNode<IntPtrT> tmp119;
  TNode<IntPtrT> tmp120;
  TNode<IntPtrT> tmp121;
  TNode<IntPtrT> tmp122;
  TNode<IntPtrT> tmp123;
  TNode<SeqOneByteString> tmp124;
  if (block37.is_used()) {
    ca_.Bind(&block37, &phi_bb37_11, &phi_bb37_13);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 924);
    tmp116 = Convert_intptr_uint32_0(state_, TNode<Uint32T>{parameter1});
    tmp117 = TimesSizeOf_char16_0(state_, TNode<IntPtrT>{tmp116});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 923);
    tmp118 = FromConstexpr_intptr_constexpr_int32_0(state_, WasmArray::kHeaderSize);
    tmp119 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp118}, TNode<IntPtrT>{tmp117});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 926);
    tmp120 = Convert_intptr_uint32_0(state_, TNode<Uint32T>{parameter2});
    tmp121 = TimesSizeOf_char16_0(state_, TNode<IntPtrT>{tmp120});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 925);
    tmp122 = FromConstexpr_intptr_constexpr_int32_0(state_, WasmArray::kHeaderSize);
    tmp123 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp122}, TNode<IntPtrT>{tmp121});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 921);
    tmp124 = AllocateNonEmptySeqOneByteString_TwoByteToOneByteIterator_0(state_, TNode<Uint32T>{tmp4}, TorqueStructTwoByteToOneByteIterator_0{TNode<WasmArray>{parameter0}, TNode<IntPtrT>{tmp119}, TNode<IntPtrT>{tmp123}});
    CodeStubAssembler(state_).Return(tmp124);
  }

  TNode<IntPtrT> tmp125;
  TNode<IntPtrT> tmp126;
  TNode<String> tmp127;
  if (block18.is_used()) {
    ca_.Bind(&block18);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 128);
    tmp125 = TimesSizeOf_char16_0(state_, TNode<IntPtrT>{tmp24});
    tmp126 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp23}, TNode<IntPtrT>{tmp125});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 918);
    tmp127 = AllocateSeqTwoByteString_SliceIterator_char16_ConstReference_char16_0(state_, TNode<Uint32T>{tmp4}, TorqueStructSliceIterator_char16_ConstReference_char16_0{TNode<Object>{tmp22}, TNode<IntPtrT>{tmp23}, TNode<IntPtrT>{tmp126}, TorqueStructUnsafe_0{}});
    CodeStubAssembler(state_).Return(tmp127);
  }

  TNode<NativeContext> tmp128;
  TNode<Smi> tmp129;
  TNode<Object> tmp130;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 929);
    tmp128 = LoadContextFromFrame_0(state_);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 931);
    tmp129 = CodeStubAssembler(state_).SmiConstant(MessageTemplate::kWasmTrapArrayOutOfBounds);
    tmp130 = CodeStubAssembler(state_).CallRuntime(Runtime::kThrowWasmError, tmp128, tmp129); 
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 932);
    CodeStubAssembler(state_).PrintErr("halting because of unreachable code at src/builtins/wasm.tq:932:5");
    CodeStubAssembler(state_).Unreachable();
  }
}

TF_BUILTIN(WasmStringConst, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Uint32T> parameter0 = UncheckedParameter<Uint32T>(Descriptor::kIndex);
  USE(parameter0);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<WasmInstanceObject> tmp0;
  TNode<NativeContext> tmp1;
  TNode<Smi> tmp2;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 941);
    tmp0 = WasmBuiltinsAssembler(state_).LoadInstanceFromFrame();
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 943);
    tmp1 = WasmBuiltinsAssembler(state_).LoadContextFromInstance(TNode<WasmInstanceObject>{tmp0});
    tmp2 = CodeStubAssembler(state_).SmiFromUint32(TNode<Uint32T>{parameter0});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 942);
    CodeStubAssembler(state_).TailCallRuntime(Runtime::kWasmStringConst, tmp1, tmp0, tmp2);
  }
}

TF_BUILTIN(WasmStringMeasureUtf8, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<String> parameter0 = UncheckedParameter<String>(Descriptor::kString);
  USE(parameter0);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<NativeContext> tmp0;
  TNode<Number> tmp1;
  TNode<Uint32T> tmp2;
  TNode<Int32T> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 946);
    tmp0 = LoadContextFromFrame_0(state_);
    tmp1 = TORQUE_CAST(CodeStubAssembler(state_).CallRuntime(Runtime::kWasmStringMeasureUtf8, tmp0, parameter0)); 
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 947);
    tmp2 = CodeStubAssembler(state_).ChangeNumberToUint32(TNode<Number>{tmp1});
    tmp3 = CodeStubAssembler(state_).Signed(TNode<Uint32T>{tmp2});
    CodeStubAssembler(state_).Return(tmp3);
  }
}

TF_BUILTIN(WasmStringMeasureWtf8, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<String> parameter0 = UncheckedParameter<String>(Descriptor::kString);
  USE(parameter0);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<NativeContext> tmp0;
  TNode<Number> tmp1;
  TNode<Uint32T> tmp2;
  TNode<Int32T> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 950);
    tmp0 = LoadContextFromFrame_0(state_);
    tmp1 = TORQUE_CAST(CodeStubAssembler(state_).CallRuntime(Runtime::kWasmStringMeasureWtf8, tmp0, parameter0)); 
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 951);
    tmp2 = CodeStubAssembler(state_).ChangeNumberToUint32(TNode<Number>{tmp1});
    tmp3 = CodeStubAssembler(state_).Signed(TNode<Uint32T>{tmp2});
    CodeStubAssembler(state_).Return(tmp3);
  }
}

TF_BUILTIN(WasmStringEncodeWtf8, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<String> parameter0 = UncheckedParameter<String>(Descriptor::kString);
  USE(parameter0);
  TNode<Uint32T> parameter1 = UncheckedParameter<Uint32T>(Descriptor::kOffset);
  USE(parameter1);
  TNode<Smi> parameter2 = UncheckedParameter<Smi>(Descriptor::kMemory);
  USE(parameter2);
  TNode<Smi> parameter3 = UncheckedParameter<Smi>(Descriptor::kUtf8Variant);
  USE(parameter3);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<WasmInstanceObject> tmp0;
  TNode<NativeContext> tmp1;
  TNode<Number> tmp2;
  TNode<Number> tmp3;
  TNode<Uint32T> tmp4;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 955);
    tmp0 = WasmBuiltinsAssembler(state_).LoadInstanceFromFrame();
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 957);
    tmp1 = WasmBuiltinsAssembler(state_).LoadContextFromInstance(TNode<WasmInstanceObject>{tmp0});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 958);
    tmp2 = ca_.CallStub<Number>(Builtins::CallableFor(ca_.isolate(), Builtin::kWasmUint32ToNumber), TNode<Object>(), parameter1);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 956);
    tmp3 = TORQUE_CAST(CodeStubAssembler(state_).CallRuntime(Runtime::kWasmStringEncodeWtf8, tmp1, tmp0, parameter2, parameter3, parameter0, tmp2)); 
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 959);
    tmp4 = CodeStubAssembler(state_).ChangeNumberToUint32(TNode<Number>{tmp3});
    CodeStubAssembler(state_).Return(tmp4);
  }
}

TF_BUILTIN(WasmStringEncodeWtf8Array, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<String> parameter0 = UncheckedParameter<String>(Descriptor::kString);
  USE(parameter0);
  TNode<WasmArray> parameter1 = UncheckedParameter<WasmArray>(Descriptor::kArray);
  USE(parameter1);
  TNode<Uint32T> parameter2 = UncheckedParameter<Uint32T>(Descriptor::kStart);
  USE(parameter2);
  TNode<Smi> parameter3 = UncheckedParameter<Smi>(Descriptor::kUtf8Variant);
  USE(parameter3);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<WasmInstanceObject> tmp0;
  TNode<NativeContext> tmp1;
  TNode<Number> tmp2;
  TNode<Number> tmp3;
  TNode<Uint32T> tmp4;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 963);
    tmp0 = WasmBuiltinsAssembler(state_).LoadInstanceFromFrame();
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 965);
    tmp1 = WasmBuiltinsAssembler(state_).LoadContextFromInstance(TNode<WasmInstanceObject>{tmp0});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 966);
    tmp2 = ca_.CallStub<Number>(Builtins::CallableFor(ca_.isolate(), Builtin::kWasmUint32ToNumber), TNode<Object>(), parameter2);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 964);
    tmp3 = TORQUE_CAST(CodeStubAssembler(state_).CallRuntime(Runtime::kWasmStringEncodeWtf8Array, tmp1, parameter3, parameter0, parameter1, tmp2)); 
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 967);
    tmp4 = CodeStubAssembler(state_).ChangeNumberToUint32(TNode<Number>{tmp3});
    CodeStubAssembler(state_).Return(tmp4);
  }
}

TF_BUILTIN(WasmStringEncodeWtf16, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<String> parameter0 = UncheckedParameter<String>(Descriptor::kString);
  USE(parameter0);
  TNode<Uint32T> parameter1 = UncheckedParameter<Uint32T>(Descriptor::kOffset);
  USE(parameter1);
  TNode<Smi> parameter2 = UncheckedParameter<Smi>(Descriptor::kMemory);
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<WasmInstanceObject> tmp0;
  TNode<NativeContext> tmp1;
  TNode<Number> tmp2;
  TNode<Smi> tmp3;
  TNode<IntPtrT> tmp4;
  TNode<Int32T> tmp5;
  TNode<Smi> tmp6;
  TNode<Object> tmp7;
  TNode<IntPtrT> tmp8;
  TNode<Int32T> tmp9;
  TNode<Uint32T> tmp10;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 971);
    tmp0 = WasmBuiltinsAssembler(state_).LoadInstanceFromFrame();
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 973);
    tmp1 = WasmBuiltinsAssembler(state_).LoadContextFromInstance(TNode<WasmInstanceObject>{tmp0});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 974);
    tmp2 = ca_.CallStub<Number>(Builtins::CallableFor(ca_.isolate(), Builtin::kWasmUint32ToNumber), TNode<Object>(), parameter1);
    tmp3 = SmiConstant_0(state_, IntegerLiteral(false, 0x0ull));
    tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp5 = CodeStubAssembler(state_).LoadReference<Int32T>(CodeStubAssembler::Reference{parameter0, tmp4});
    tmp6 = CodeStubAssembler(state_).SmiFromInt32(TNode<Int32T>{tmp5});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 972);
    tmp7 = CodeStubAssembler(state_).CallRuntime(Runtime::kWasmStringEncodeWtf16, tmp1, tmp0, parameter2, parameter0, tmp2, tmp3, tmp6); 
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 975);
    tmp8 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp9 = CodeStubAssembler(state_).LoadReference<Int32T>(CodeStubAssembler::Reference{parameter0, tmp8});
    tmp10 = CodeStubAssembler(state_).Unsigned(TNode<Int32T>{tmp9});
    CodeStubAssembler(state_).Return(tmp10);
  }
}

TF_BUILTIN(WasmStringEncodeWtf16Array, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<String> parameter0 = UncheckedParameter<String>(Descriptor::kString);
  USE(parameter0);
  TNode<WasmArray> parameter1 = UncheckedParameter<WasmArray>(Descriptor::kArray);
  USE(parameter1);
  TNode<Uint32T> parameter2 = UncheckedParameter<Uint32T>(Descriptor::kStart);
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<String, IntPtrT> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<String, IntPtrT> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<String, IntPtrT, String, String> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<String, IntPtrT, String, String> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<String, IntPtrT, String, IntPtrT> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<String, IntPtrT, String, IntPtrT> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<String, IntPtrT, String> block25(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<String, IntPtrT, String> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<String, IntPtrT, String, IntPtrT> block29(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<String, IntPtrT, String, IntPtrT> block28(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<String, IntPtrT, String> block33(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<String, IntPtrT, String> block32(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<String, IntPtrT, String> block37(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<String, IntPtrT, String> block36(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<String, IntPtrT, String> block41(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<String, IntPtrT, String> block40(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<String, IntPtrT, String> block45(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<String, IntPtrT, String> block44(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<String, IntPtrT, String, IntPtrT> block49(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<String, IntPtrT, String, IntPtrT> block48(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<String, IntPtrT, String> block53(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<String, IntPtrT, String> block52(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<String, IntPtrT, String, IntPtrT> block57(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<String, IntPtrT, String, IntPtrT> block56(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<String, IntPtrT, String> block34(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<String, IntPtrT, String> block30(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<String, IntPtrT> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, IntPtrT> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, IntPtrT, Object, IntPtrT, IntPtrT> block62(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, IntPtrT, Object, IntPtrT, IntPtrT> block60(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, IntPtrT, Object, IntPtrT, IntPtrT> block66(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, IntPtrT, Object, IntPtrT, IntPtrT> block67(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, IntPtrT, Object, IntPtrT> block73(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, IntPtrT, Object, IntPtrT> block72(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, IntPtrT, Object, IntPtrT, IntPtrT> block61(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, IntPtrT> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, IntPtrT, Object, IntPtrT, IntPtrT> block79(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, IntPtrT, Object, IntPtrT, IntPtrT> block77(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, IntPtrT, Object, IntPtrT, IntPtrT> block83(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, IntPtrT, Object, IntPtrT, IntPtrT> block84(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, IntPtrT, Object, IntPtrT> block90(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, IntPtrT, Object, IntPtrT> block89(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, IntPtrT, Object, IntPtrT, IntPtrT> block78(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Uint32T> tmp1;
  TNode<BoolT> tmp2;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 980);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp1 = CodeStubAssembler(state_).LoadReference<Uint32T>(CodeStubAssembler::Reference{parameter1, tmp0});
    tmp2 = CodeStubAssembler(state_).Uint32GreaterThan(TNode<Uint32T>{parameter2}, TNode<Uint32T>{tmp1});
    ca_.Branch(tmp2, &block3, std::vector<compiler::Node*>{}, &block4, std::vector<compiler::Node*>{});
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    ca_.Goto(&block2);
  }

  TNode<IntPtrT> tmp3;
  TNode<Uint32T> tmp4;
  TNode<Uint32T> tmp5;
  TNode<IntPtrT> tmp6;
  TNode<Int32T> tmp7;
  TNode<Uint32T> tmp8;
  TNode<BoolT> tmp9;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 981);
    tmp3 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp4 = CodeStubAssembler(state_).LoadReference<Uint32T>(CodeStubAssembler::Reference{parameter1, tmp3});
    tmp5 = CodeStubAssembler(state_).Uint32Sub(TNode<Uint32T>{tmp4}, TNode<Uint32T>{parameter2});
    tmp6 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp7 = CodeStubAssembler(state_).LoadReference<Int32T>(CodeStubAssembler::Reference{parameter0, tmp6});
    tmp8 = CodeStubAssembler(state_).Unsigned(TNode<Int32T>{tmp7});
    tmp9 = CodeStubAssembler(state_).Uint32LessThan(TNode<Uint32T>{tmp5}, TNode<Uint32T>{tmp8});
    ca_.Branch(tmp9, &block5, std::vector<compiler::Node*>{}, &block6, std::vector<compiler::Node*>{});
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    ca_.Goto(&block2);
  }

  TNode<IntPtrT> tmp10;
  TNode<IntPtrT> tmp11;
  TNode<IntPtrT> tmp12;
  TNode<IntPtrT> tmp13;
  TNode<IntPtrT> tmp14;
  TNode<Int32T> tmp15;
  TNode<IntPtrT> tmp16;
  TNode<Object> tmp17;
  TNode<IntPtrT> tmp18;
  TNode<IntPtrT> tmp19;
  TNode<IntPtrT> tmp20;
  TNode<IntPtrT> tmp21;
  TNode<Int32T> tmp22;
  TNode<IntPtrT> tmp23;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 984);
    tmp10 = Convert_intptr_uint32_0(state_, TNode<Uint32T>{parameter2});
    tmp11 = TimesSizeOf_char16_0(state_, TNode<IntPtrT>{tmp10});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 983);
    tmp12 = FromConstexpr_intptr_constexpr_int32_0(state_, WasmArray::kHeaderSize);
    tmp13 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp12}, TNode<IntPtrT>{tmp11});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 986);
    tmp14 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp15 = CodeStubAssembler(state_).LoadReference<Int32T>(CodeStubAssembler::Reference{parameter0, tmp14});
    tmp16 = Convert_intptr_int32_0(state_, TNode<Int32T>{tmp15});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 985);
    std::tie(tmp17, tmp18, tmp19) = NewMutableSlice_char16_0(state_, TNode<Object>{parameter1}, TNode<IntPtrT>{tmp13}, TNode<IntPtrT>{tmp16}).Flatten();
    ca_.SetSourcePosition("../../../src/objects/string.tq", 249);
    tmp20 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    ca_.SetSourcePosition("../../../src/objects/string.tq", 250);
    tmp21 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp22 = CodeStubAssembler(state_).LoadReference<Int32T>(CodeStubAssembler::Reference{parameter0, tmp21});
    tmp23 = Convert_intptr_int32_0(state_, TNode<Int32T>{tmp22});
    ca_.SetSourcePosition("../../../src/objects/string.tq", 251);
    ca_.Goto(&block13, parameter0, tmp20);
  }

  TNode<String> phi_bb13_9;
  TNode<IntPtrT> phi_bb13_10;
  TNode<BoolT> tmp24;
  if (block13.is_used()) {
    ca_.Bind(&block13, &phi_bb13_9, &phi_bb13_10);
    tmp24 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Branch(tmp24, &block11, std::vector<compiler::Node*>{phi_bb13_9, phi_bb13_10}, &block12, std::vector<compiler::Node*>{phi_bb13_9, phi_bb13_10});
  }

  TNode<String> phi_bb11_9;
  TNode<IntPtrT> phi_bb11_10;
  TNode<SeqOneByteString> tmp25;
  if (block11.is_used()) {
    ca_.Bind(&block11, &phi_bb11_9, &phi_bb11_10);
    ca_.SetSourcePosition("../../../src/objects/string.tq", 253);
    compiler::CodeAssemblerLabel label26(&ca_);
    tmp25 = Cast_SeqOneByteString_1(state_, TNode<String>{phi_bb11_9}, &label26);
    ca_.Goto(&block16, phi_bb11_9, phi_bb11_10, phi_bb11_9, phi_bb11_9);
    if (label26.is_used()) {
      ca_.Bind(&label26);
      ca_.Goto(&block17, phi_bb11_9, phi_bb11_10, phi_bb11_9, phi_bb11_9);
    }
  }

  TNode<String> phi_bb17_9;
  TNode<IntPtrT> phi_bb17_10;
  TNode<String> phi_bb17_12;
  TNode<String> phi_bb17_13;
  TNode<SeqTwoByteString> tmp27;
  if (block17.is_used()) {
    ca_.Bind(&block17, &phi_bb17_9, &phi_bb17_10, &phi_bb17_12, &phi_bb17_13);
    ca_.SetSourcePosition("../../../src/objects/string.tq", 256);
    compiler::CodeAssemblerLabel label28(&ca_);
    tmp27 = Cast_SeqTwoByteString_1(state_, TNode<String>{ca_.UncheckedCast<String>(phi_bb17_12)}, &label28);
    ca_.Goto(&block24, phi_bb17_9, phi_bb17_10, phi_bb17_12);
    if (label28.is_used()) {
      ca_.Bind(&label28);
      ca_.Goto(&block25, phi_bb17_9, phi_bb17_10, phi_bb17_12);
    }
  }

  TNode<String> phi_bb16_9;
  TNode<IntPtrT> phi_bb16_10;
  TNode<String> phi_bb16_12;
  TNode<String> phi_bb16_13;
  TNode<Object> tmp29;
  TNode<IntPtrT> tmp30;
  TNode<IntPtrT> tmp31;
  TNode<Object> tmp32;
  TNode<IntPtrT> tmp33;
  TNode<IntPtrT> tmp34;
  if (block16.is_used()) {
    ca_.Bind(&block16, &phi_bb16_9, &phi_bb16_10, &phi_bb16_12, &phi_bb16_13);
    ca_.SetSourcePosition("../../../src/objects/string.tq", 254);
    std::tie(tmp29, tmp30, tmp31) = FieldSliceSeqOneByteStringChars_0(state_, TNode<SeqOneByteString>{tmp25}).Flatten();
    compiler::CodeAssemblerLabel label35(&ca_);
    std::tie(tmp32, tmp33, tmp34) = Subslice_char8_0(state_, TorqueStructSlice_char8_ConstReference_char8_0{TNode<Object>{tmp29}, TNode<IntPtrT>{tmp30}, TNode<IntPtrT>{tmp31}, TorqueStructUnsafe_0{}}, TNode<IntPtrT>{phi_bb16_10}, TNode<IntPtrT>{tmp23}, &label35).Flatten();
    ca_.Goto(&block20, phi_bb16_9, phi_bb16_10, phi_bb16_12, phi_bb16_10);
    if (label35.is_used()) {
      ca_.Bind(&label35);
      ca_.Goto(&block21, phi_bb16_9, phi_bb16_10, phi_bb16_12, phi_bb16_10);
    }
  }

  TNode<String> phi_bb21_9;
  TNode<IntPtrT> phi_bb21_10;
  TNode<String> phi_bb21_12;
  TNode<IntPtrT> phi_bb21_17;
  if (block21.is_used()) {
    ca_.Bind(&block21, &phi_bb21_9, &phi_bb21_10, &phi_bb21_12, &phi_bb21_17);
    CodeStubAssembler(state_).PrintErr("halting because of unreachable code at src/objects/string.tq:254:67");
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<String> phi_bb20_9;
  TNode<IntPtrT> phi_bb20_10;
  TNode<String> phi_bb20_12;
  TNode<IntPtrT> phi_bb20_17;
  if (block20.is_used()) {
    ca_.Bind(&block20, &phi_bb20_9, &phi_bb20_10, &phi_bb20_12, &phi_bb20_17);
    ca_.Goto(&block10, tmp32, tmp33, tmp34);
  }

  TNode<String> phi_bb25_9;
  TNode<IntPtrT> phi_bb25_10;
  TNode<String> phi_bb25_12;
  TNode<ThinString> tmp36;
  if (block25.is_used()) {
    ca_.Bind(&block25, &phi_bb25_9, &phi_bb25_10, &phi_bb25_12);
    ca_.SetSourcePosition("../../../src/objects/string.tq", 259);
    compiler::CodeAssemblerLabel label37(&ca_);
    tmp36 = Cast_ThinString_1(state_, TNode<String>{ca_.UncheckedCast<String>(phi_bb25_12)}, &label37);
    ca_.Goto(&block32, phi_bb25_9, phi_bb25_10, phi_bb25_12);
    if (label37.is_used()) {
      ca_.Bind(&label37);
      ca_.Goto(&block33, phi_bb25_9, phi_bb25_10, phi_bb25_12);
    }
  }

  TNode<String> phi_bb24_9;
  TNode<IntPtrT> phi_bb24_10;
  TNode<String> phi_bb24_12;
  TNode<Object> tmp38;
  TNode<IntPtrT> tmp39;
  TNode<IntPtrT> tmp40;
  TNode<Object> tmp41;
  TNode<IntPtrT> tmp42;
  TNode<IntPtrT> tmp43;
  if (block24.is_used()) {
    ca_.Bind(&block24, &phi_bb24_9, &phi_bb24_10, &phi_bb24_12);
    ca_.SetSourcePosition("../../../src/objects/string.tq", 257);
    std::tie(tmp38, tmp39, tmp40) = FieldSliceSeqTwoByteStringChars_0(state_, TNode<SeqTwoByteString>{tmp27}).Flatten();
    compiler::CodeAssemblerLabel label44(&ca_);
    std::tie(tmp41, tmp42, tmp43) = Subslice_char16_0(state_, TorqueStructSlice_char16_ConstReference_char16_0{TNode<Object>{tmp38}, TNode<IntPtrT>{tmp39}, TNode<IntPtrT>{tmp40}, TorqueStructUnsafe_0{}}, TNode<IntPtrT>{phi_bb24_10}, TNode<IntPtrT>{tmp23}, &label44).Flatten();
    ca_.Goto(&block28, phi_bb24_9, phi_bb24_10, phi_bb24_12, phi_bb24_10);
    if (label44.is_used()) {
      ca_.Bind(&label44);
      ca_.Goto(&block29, phi_bb24_9, phi_bb24_10, phi_bb24_12, phi_bb24_10);
    }
  }

  TNode<String> phi_bb29_9;
  TNode<IntPtrT> phi_bb29_10;
  TNode<String> phi_bb29_12;
  TNode<IntPtrT> phi_bb29_17;
  if (block29.is_used()) {
    ca_.Bind(&block29, &phi_bb29_9, &phi_bb29_10, &phi_bb29_12, &phi_bb29_17);
    CodeStubAssembler(state_).PrintErr("halting because of unreachable code at src/objects/string.tq:257:67");
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<String> phi_bb28_9;
  TNode<IntPtrT> phi_bb28_10;
  TNode<String> phi_bb28_12;
  TNode<IntPtrT> phi_bb28_17;
  if (block28.is_used()) {
    ca_.Bind(&block28, &phi_bb28_9, &phi_bb28_10, &phi_bb28_12, &phi_bb28_17);
    ca_.Goto(&block8, tmp41, tmp42, tmp43);
  }

  TNode<String> phi_bb33_9;
  TNode<IntPtrT> phi_bb33_10;
  TNode<String> phi_bb33_12;
  TNode<ConsString> tmp45;
  if (block33.is_used()) {
    ca_.Bind(&block33, &phi_bb33_9, &phi_bb33_10, &phi_bb33_12);
    ca_.SetSourcePosition("../../../src/objects/string.tq", 262);
    compiler::CodeAssemblerLabel label46(&ca_);
    tmp45 = Cast_ConsString_1(state_, TNode<String>{ca_.UncheckedCast<String>(phi_bb33_12)}, &label46);
    ca_.Goto(&block36, phi_bb33_9, phi_bb33_10, phi_bb33_12);
    if (label46.is_used()) {
      ca_.Bind(&label46);
      ca_.Goto(&block37, phi_bb33_9, phi_bb33_10, phi_bb33_12);
    }
  }

  TNode<String> phi_bb32_9;
  TNode<IntPtrT> phi_bb32_10;
  TNode<String> phi_bb32_12;
  TNode<IntPtrT> tmp47;
  TNode<String> tmp48;
  if (block32.is_used()) {
    ca_.Bind(&block32, &phi_bb32_9, &phi_bb32_10, &phi_bb32_12);
    ca_.SetSourcePosition("../../../src/objects/string.tq", 260);
    tmp47 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp48 = CodeStubAssembler(state_).LoadReference<String>(CodeStubAssembler::Reference{tmp36, tmp47});
    ca_.SetSourcePosition("../../../src/objects/string.tq", 259);
    ca_.Goto(&block30, tmp48, phi_bb32_10, phi_bb32_12);
  }

  TNode<String> phi_bb37_9;
  TNode<IntPtrT> phi_bb37_10;
  TNode<String> phi_bb37_12;
  TNode<SlicedString> tmp49;
  if (block37.is_used()) {
    ca_.Bind(&block37, &phi_bb37_9, &phi_bb37_10, &phi_bb37_12);
    ca_.SetSourcePosition("../../../src/objects/string.tq", 265);
    compiler::CodeAssemblerLabel label50(&ca_);
    tmp49 = Cast_SlicedString_1(state_, TNode<String>{ca_.UncheckedCast<String>(phi_bb37_12)}, &label50);
    ca_.Goto(&block40, phi_bb37_9, phi_bb37_10, phi_bb37_12);
    if (label50.is_used()) {
      ca_.Bind(&label50);
      ca_.Goto(&block41, phi_bb37_9, phi_bb37_10, phi_bb37_12);
    }
  }

  TNode<String> phi_bb36_9;
  TNode<IntPtrT> phi_bb36_10;
  TNode<String> phi_bb36_12;
  TNode<String> tmp51;
  if (block36.is_used()) {
    ca_.Bind(&block36, &phi_bb36_9, &phi_bb36_10, &phi_bb36_12);
    ca_.SetSourcePosition("../../../src/objects/string.tq", 263);
    tmp51 = Flatten_1(state_, TNode<ConsString>{tmp45});
    ca_.SetSourcePosition("../../../src/objects/string.tq", 262);
    ca_.Goto(&block34, tmp51, phi_bb36_10, phi_bb36_12);
  }

  TNode<String> phi_bb41_9;
  TNode<IntPtrT> phi_bb41_10;
  TNode<String> phi_bb41_12;
  TNode<ExternalOneByteString> tmp52;
  if (block41.is_used()) {
    ca_.Bind(&block41, &phi_bb41_9, &phi_bb41_10, &phi_bb41_12);
    ca_.SetSourcePosition("../../../src/objects/string.tq", 269);
    compiler::CodeAssemblerLabel label53(&ca_);
    tmp52 = Cast_ExternalOneByteString_1(state_, TNode<String>{ca_.UncheckedCast<String>(phi_bb41_12)}, &label53);
    ca_.Goto(&block44, phi_bb41_9, phi_bb41_10, phi_bb41_12);
    if (label53.is_used()) {
      ca_.Bind(&label53);
      ca_.Goto(&block45, phi_bb41_9, phi_bb41_10, phi_bb41_12);
    }
  }

  TNode<String> phi_bb40_9;
  TNode<IntPtrT> phi_bb40_10;
  TNode<String> phi_bb40_12;
  TNode<IntPtrT> tmp54;
  TNode<Smi> tmp55;
  TNode<IntPtrT> tmp56;
  TNode<IntPtrT> tmp57;
  TNode<IntPtrT> tmp58;
  TNode<String> tmp59;
  if (block40.is_used()) {
    ca_.Bind(&block40, &phi_bb40_9, &phi_bb40_10, &phi_bb40_12);
    ca_.SetSourcePosition("../../../src/objects/string.tq", 266);
    tmp54 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    tmp55 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp49, tmp54});
    tmp56 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp55});
    tmp57 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb40_10}, TNode<IntPtrT>{tmp56});
    ca_.SetSourcePosition("../../../src/objects/string.tq", 267);
    tmp58 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp59 = CodeStubAssembler(state_).LoadReference<String>(CodeStubAssembler::Reference{tmp49, tmp58});
    ca_.SetSourcePosition("../../../src/objects/string.tq", 262);
    ca_.Goto(&block34, tmp59, tmp57, phi_bb40_12);
  }

  TNode<String> phi_bb45_9;
  TNode<IntPtrT> phi_bb45_10;
  TNode<String> phi_bb45_12;
  TNode<ExternalTwoByteString> tmp60;
  if (block45.is_used()) {
    ca_.Bind(&block45, &phi_bb45_9, &phi_bb45_10, &phi_bb45_12);
    ca_.SetSourcePosition("../../../src/objects/string.tq", 274);
    compiler::CodeAssemblerLabel label61(&ca_);
    tmp60 = Cast_ExternalTwoByteString_1(state_, TNode<String>{ca_.UncheckedCast<String>(phi_bb45_12)}, &label61);
    ca_.Goto(&block52, phi_bb45_9, phi_bb45_10, phi_bb45_12);
    if (label61.is_used()) {
      ca_.Bind(&label61);
      ca_.Goto(&block53, phi_bb45_9, phi_bb45_10, phi_bb45_12);
    }
  }

  TNode<String> phi_bb44_9;
  TNode<IntPtrT> phi_bb44_10;
  TNode<String> phi_bb44_12;
  TNode<RawPtrT> tmp62;
  TNode<IntPtrT> tmp63;
  TNode<Int32T> tmp64;
  TNode<IntPtrT> tmp65;
  TNode<Object> tmp66;
  TNode<IntPtrT> tmp67;
  TNode<IntPtrT> tmp68;
  TNode<Object> tmp69;
  TNode<IntPtrT> tmp70;
  TNode<IntPtrT> tmp71;
  if (block44.is_used()) {
    ca_.Bind(&block44, &phi_bb44_9, &phi_bb44_10, &phi_bb44_12);
    ca_.SetSourcePosition("../../../src/objects/string.tq", 271);
    tmp62 = Method_ExternalOneByteString_GetChars_0(state_, TNode<ExternalOneByteString>{tmp52});
    tmp63 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp64 = CodeStubAssembler(state_).LoadReference<Int32T>(CodeStubAssembler::Reference{tmp52, tmp63});
    tmp65 = Convert_intptr_int32_0(state_, TNode<Int32T>{tmp64});
    ca_.SetSourcePosition("../../../src/objects/string.tq", 270);
    std::tie(tmp66, tmp67, tmp68) = NewOffHeapConstSlice_char8_0(state_, TNode<RawPtrT>{tmp62}, TNode<IntPtrT>{tmp65}).Flatten();
    ca_.SetSourcePosition("../../../src/objects/string.tq", 272);
    compiler::CodeAssemblerLabel label72(&ca_);
    std::tie(tmp69, tmp70, tmp71) = Subslice_char8_0(state_, TorqueStructSlice_char8_ConstReference_char8_0{TNode<Object>{tmp66}, TNode<IntPtrT>{tmp67}, TNode<IntPtrT>{tmp68}, TorqueStructUnsafe_0{}}, TNode<IntPtrT>{phi_bb44_10}, TNode<IntPtrT>{tmp23}, &label72).Flatten();
    ca_.Goto(&block48, phi_bb44_9, phi_bb44_10, phi_bb44_12, phi_bb44_10);
    if (label72.is_used()) {
      ca_.Bind(&label72);
      ca_.Goto(&block49, phi_bb44_9, phi_bb44_10, phi_bb44_12, phi_bb44_10);
    }
  }

  TNode<String> phi_bb49_9;
  TNode<IntPtrT> phi_bb49_10;
  TNode<String> phi_bb49_12;
  TNode<IntPtrT> phi_bb49_20;
  if (block49.is_used()) {
    ca_.Bind(&block49, &phi_bb49_9, &phi_bb49_10, &phi_bb49_12, &phi_bb49_20);
    CodeStubAssembler(state_).PrintErr("halting because of unreachable code at src/objects/string.tq:272:63");
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<String> phi_bb48_9;
  TNode<IntPtrT> phi_bb48_10;
  TNode<String> phi_bb48_12;
  TNode<IntPtrT> phi_bb48_20;
  if (block48.is_used()) {
    ca_.Bind(&block48, &phi_bb48_9, &phi_bb48_10, &phi_bb48_12, &phi_bb48_20);
    ca_.Goto(&block10, tmp69, tmp70, tmp71);
  }

  TNode<String> phi_bb53_9;
  TNode<IntPtrT> phi_bb53_10;
  TNode<String> phi_bb53_12;
  if (block53.is_used()) {
    ca_.Bind(&block53, &phi_bb53_9, &phi_bb53_10, &phi_bb53_12);
    ca_.SetSourcePosition("../../../src/objects/string.tq", 280);
    CodeStubAssembler(state_).PrintErr("halting because of unreachable code at src/objects/string.tq:280:9");
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<String> phi_bb52_9;
  TNode<IntPtrT> phi_bb52_10;
  TNode<String> phi_bb52_12;
  TNode<RawPtrT> tmp73;
  TNode<IntPtrT> tmp74;
  TNode<Int32T> tmp75;
  TNode<IntPtrT> tmp76;
  TNode<Object> tmp77;
  TNode<IntPtrT> tmp78;
  TNode<IntPtrT> tmp79;
  TNode<Object> tmp80;
  TNode<IntPtrT> tmp81;
  TNode<IntPtrT> tmp82;
  if (block52.is_used()) {
    ca_.Bind(&block52, &phi_bb52_9, &phi_bb52_10, &phi_bb52_12);
    ca_.SetSourcePosition("../../../src/objects/string.tq", 276);
    tmp73 = Method_ExternalTwoByteString_GetChars_0(state_, TNode<ExternalTwoByteString>{tmp60});
    tmp74 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp75 = CodeStubAssembler(state_).LoadReference<Int32T>(CodeStubAssembler::Reference{tmp60, tmp74});
    tmp76 = Convert_intptr_int32_0(state_, TNode<Int32T>{tmp75});
    ca_.SetSourcePosition("../../../src/objects/string.tq", 275);
    std::tie(tmp77, tmp78, tmp79) = NewOffHeapConstSlice_char16_0(state_, TNode<RawPtrT>{tmp73}, TNode<IntPtrT>{tmp76}).Flatten();
    ca_.SetSourcePosition("../../../src/objects/string.tq", 277);
    compiler::CodeAssemblerLabel label83(&ca_);
    std::tie(tmp80, tmp81, tmp82) = Subslice_char16_0(state_, TorqueStructSlice_char16_ConstReference_char16_0{TNode<Object>{tmp77}, TNode<IntPtrT>{tmp78}, TNode<IntPtrT>{tmp79}, TorqueStructUnsafe_0{}}, TNode<IntPtrT>{phi_bb52_10}, TNode<IntPtrT>{tmp23}, &label83).Flatten();
    ca_.Goto(&block56, phi_bb52_9, phi_bb52_10, phi_bb52_12, phi_bb52_10);
    if (label83.is_used()) {
      ca_.Bind(&label83);
      ca_.Goto(&block57, phi_bb52_9, phi_bb52_10, phi_bb52_12, phi_bb52_10);
    }
  }

  TNode<String> phi_bb57_9;
  TNode<IntPtrT> phi_bb57_10;
  TNode<String> phi_bb57_12;
  TNode<IntPtrT> phi_bb57_20;
  if (block57.is_used()) {
    ca_.Bind(&block57, &phi_bb57_9, &phi_bb57_10, &phi_bb57_12, &phi_bb57_20);
    CodeStubAssembler(state_).PrintErr("halting because of unreachable code at src/objects/string.tq:277:63");
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<String> phi_bb56_9;
  TNode<IntPtrT> phi_bb56_10;
  TNode<String> phi_bb56_12;
  TNode<IntPtrT> phi_bb56_20;
  if (block56.is_used()) {
    ca_.Bind(&block56, &phi_bb56_9, &phi_bb56_10, &phi_bb56_12, &phi_bb56_20);
    ca_.Goto(&block8, tmp80, tmp81, tmp82);
  }

  TNode<String> phi_bb34_9;
  TNode<IntPtrT> phi_bb34_10;
  TNode<String> phi_bb34_12;
  if (block34.is_used()) {
    ca_.Bind(&block34, &phi_bb34_9, &phi_bb34_10, &phi_bb34_12);
    ca_.SetSourcePosition("../../../src/objects/string.tq", 259);
    ca_.Goto(&block30, phi_bb34_9, phi_bb34_10, phi_bb34_12);
  }

  TNode<String> phi_bb30_9;
  TNode<IntPtrT> phi_bb30_10;
  TNode<String> phi_bb30_12;
  if (block30.is_used()) {
    ca_.Bind(&block30, &phi_bb30_9, &phi_bb30_10, &phi_bb30_12);
    ca_.SetSourcePosition("../../../src/objects/string.tq", 251);
    ca_.Goto(&block13, phi_bb30_9, phi_bb30_10);
  }

  TNode<String> phi_bb12_9;
  TNode<IntPtrT> phi_bb12_10;
  if (block12.is_used()) {
    ca_.Bind(&block12, &phi_bb12_9, &phi_bb12_10);
    ca_.SetSourcePosition("../../../src/objects/string.tq", 284);
    VerifiedUnreachable_0(state_);
  }

  TNode<Object> phi_bb10_7;
  TNode<IntPtrT> phi_bb10_8;
  TNode<IntPtrT> phi_bb10_9;
  TNode<IntPtrT> tmp84;
  TNode<IntPtrT> tmp85;
  TNode<IntPtrT> tmp86;
  TNode<IntPtrT> tmp87;
  if (block10.is_used()) {
    ca_.Bind(&block10, &phi_bb10_7, &phi_bb10_8, &phi_bb10_9);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 128);
    tmp84 = TimesSizeOf_char8_0(state_, TNode<IntPtrT>{phi_bb10_9});
    tmp85 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb10_8}, TNode<IntPtrT>{tmp84});
    tmp86 = TimesSizeOf_char16_0(state_, TNode<IntPtrT>{tmp19});
    tmp87 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp18}, TNode<IntPtrT>{tmp86});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 992);
    ca_.Goto(&block62, phi_bb10_7, phi_bb10_8, phi_bb10_9, phi_bb10_7, phi_bb10_8, tmp18);
  }

  TNode<Object> phi_bb62_7;
  TNode<IntPtrT> phi_bb62_8;
  TNode<IntPtrT> phi_bb62_9;
  TNode<Object> phi_bb62_10;
  TNode<IntPtrT> phi_bb62_11;
  TNode<IntPtrT> phi_bb62_14;
  TNode<BoolT> tmp88;
  if (block62.is_used()) {
    ca_.Bind(&block62, &phi_bb62_7, &phi_bb62_8, &phi_bb62_9, &phi_bb62_10, &phi_bb62_11, &phi_bb62_14);
    tmp88 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Branch(tmp88, &block60, std::vector<compiler::Node*>{phi_bb62_7, phi_bb62_8, phi_bb62_9, phi_bb62_10, phi_bb62_11, phi_bb62_14}, &block61, std::vector<compiler::Node*>{phi_bb62_7, phi_bb62_8, phi_bb62_9, phi_bb62_10, phi_bb62_11, phi_bb62_14});
  }

  TNode<Object> phi_bb60_7;
  TNode<IntPtrT> phi_bb60_8;
  TNode<IntPtrT> phi_bb60_9;
  TNode<Object> phi_bb60_10;
  TNode<IntPtrT> phi_bb60_11;
  TNode<IntPtrT> phi_bb60_14;
  TNode<BoolT> tmp89;
  if (block60.is_used()) {
    ca_.Bind(&block60, &phi_bb60_7, &phi_bb60_8, &phi_bb60_9, &phi_bb60_10, &phi_bb60_11, &phi_bb60_14);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 201);
    tmp89 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{phi_bb60_14}, TNode<IntPtrT>{tmp87});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 213);
    ca_.Branch(tmp89, &block66, std::vector<compiler::Node*>{phi_bb60_7, phi_bb60_8, phi_bb60_9, phi_bb60_10, phi_bb60_11, phi_bb60_14}, &block67, std::vector<compiler::Node*>{phi_bb60_7, phi_bb60_8, phi_bb60_9, phi_bb60_10, phi_bb60_11, phi_bb60_14});
  }

  TNode<Object> phi_bb66_7;
  TNode<IntPtrT> phi_bb66_8;
  TNode<IntPtrT> phi_bb66_9;
  TNode<Object> phi_bb66_10;
  TNode<IntPtrT> phi_bb66_11;
  TNode<IntPtrT> phi_bb66_14;
  if (block66.is_used()) {
    ca_.Bind(&block66, &phi_bb66_7, &phi_bb66_8, &phi_bb66_9, &phi_bb66_10, &phi_bb66_11, &phi_bb66_14);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 993);
    ca_.Goto(&block61, phi_bb66_7, phi_bb66_8, phi_bb66_9, phi_bb66_10, phi_bb66_11, phi_bb66_14);
  }

  TNode<Object> phi_bb67_7;
  TNode<IntPtrT> phi_bb67_8;
  TNode<IntPtrT> phi_bb67_9;
  TNode<Object> phi_bb67_10;
  TNode<IntPtrT> phi_bb67_11;
  TNode<IntPtrT> phi_bb67_14;
  TNode<Object> tmp90;
  TNode<IntPtrT> tmp91;
  TNode<IntPtrT> tmp92;
  TNode<IntPtrT> tmp93;
  TNode<BoolT> tmp94;
  TNode<BoolT> tmp95;
  if (block67.is_used()) {
    ca_.Bind(&block67, &phi_bb67_7, &phi_bb67_8, &phi_bb67_9, &phi_bb67_10, &phi_bb67_11, &phi_bb67_14);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 216);
    std::tie(tmp90, tmp91) = NewReference_char16_0(state_, TNode<Object>{tmp17}, TNode<IntPtrT>{phi_bb67_14}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 217);
    tmp92 = FromConstexpr_intptr_constexpr_int31_0(state_, kUInt16Size);
    tmp93 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb67_14}, TNode<IntPtrT>{tmp92});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 201);
    tmp94 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{phi_bb67_11}, TNode<IntPtrT>{tmp85});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 223);
    tmp95 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp94});
    ca_.Branch(tmp95, &block72, std::vector<compiler::Node*>{phi_bb67_7, phi_bb67_8, phi_bb67_9, phi_bb67_10, phi_bb67_11}, &block73, std::vector<compiler::Node*>{phi_bb67_7, phi_bb67_8, phi_bb67_9, phi_bb67_10, phi_bb67_11});
  }

  TNode<Object> phi_bb73_7;
  TNode<IntPtrT> phi_bb73_8;
  TNode<IntPtrT> phi_bb73_9;
  TNode<Object> phi_bb73_10;
  TNode<IntPtrT> phi_bb73_11;
  if (block73.is_used()) {
    ca_.Bind(&block73, &phi_bb73_7, &phi_bb73_8, &phi_bb73_9, &phi_bb73_10, &phi_bb73_11);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/torque-internal.tq", 223});
      CodeStubAssembler(state_).FailAssert("Torque assert '!this.Empty()' failed", pos_stack);
    }
  }

  TNode<Object> phi_bb72_7;
  TNode<IntPtrT> phi_bb72_8;
  TNode<IntPtrT> phi_bb72_9;
  TNode<Object> phi_bb72_10;
  TNode<IntPtrT> phi_bb72_11;
  TNode<Object> tmp96;
  TNode<IntPtrT> tmp97;
  TNode<IntPtrT> tmp98;
  TNode<IntPtrT> tmp99;
  TNode<Uint8T> tmp100;
  TNode<Uint16T> tmp101;
  TNode<Uint16T> tmp102;
  if (block72.is_used()) {
    ca_.Bind(&block72, &phi_bb72_7, &phi_bb72_8, &phi_bb72_9, &phi_bb72_10, &phi_bb72_11);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 224);
    std::tie(tmp96, tmp97) = NewReference_char8_0(state_, TNode<Object>{phi_bb72_10}, TNode<IntPtrT>{phi_bb72_11}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 225);
    tmp98 = FromConstexpr_intptr_constexpr_int31_0(state_, kUInt8Size);
    tmp99 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb72_11}, TNode<IntPtrT>{tmp98});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 209);
    tmp100 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference{tmp96, tmp97});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 994);
    tmp101 = Convert_uint16_char8_0(state_, TNode<Uint8T>{tmp100});
    tmp102 = (TNode<Uint16T>{tmp101});
    CodeStubAssembler(state_).StoreReference<Uint16T>(CodeStubAssembler::Reference{tmp90, tmp91}, tmp102);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 992);
    ca_.Goto(&block62, phi_bb72_7, phi_bb72_8, phi_bb72_9, phi_bb72_10, tmp99, tmp93);
  }

  TNode<Object> phi_bb61_7;
  TNode<IntPtrT> phi_bb61_8;
  TNode<IntPtrT> phi_bb61_9;
  TNode<Object> phi_bb61_10;
  TNode<IntPtrT> phi_bb61_11;
  TNode<IntPtrT> phi_bb61_14;
  if (block61.is_used()) {
    ca_.Bind(&block61, &phi_bb61_7, &phi_bb61_8, &phi_bb61_9, &phi_bb61_10, &phi_bb61_11, &phi_bb61_14);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 996);
    ca_.Goto(&block7);
  }

  TNode<Object> phi_bb8_7;
  TNode<IntPtrT> phi_bb8_8;
  TNode<IntPtrT> phi_bb8_9;
  TNode<IntPtrT> tmp103;
  TNode<IntPtrT> tmp104;
  TNode<IntPtrT> tmp105;
  TNode<IntPtrT> tmp106;
  if (block8.is_used()) {
    ca_.Bind(&block8, &phi_bb8_7, &phi_bb8_8, &phi_bb8_9);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 128);
    tmp103 = TimesSizeOf_char16_0(state_, TNode<IntPtrT>{phi_bb8_9});
    tmp104 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb8_8}, TNode<IntPtrT>{tmp103});
    tmp105 = TimesSizeOf_char16_0(state_, TNode<IntPtrT>{tmp19});
    tmp106 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp18}, TNode<IntPtrT>{tmp105});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 999);
    ca_.Goto(&block79, phi_bb8_7, phi_bb8_8, phi_bb8_9, phi_bb8_7, phi_bb8_8, tmp18);
  }

  TNode<Object> phi_bb79_7;
  TNode<IntPtrT> phi_bb79_8;
  TNode<IntPtrT> phi_bb79_9;
  TNode<Object> phi_bb79_10;
  TNode<IntPtrT> phi_bb79_11;
  TNode<IntPtrT> phi_bb79_14;
  TNode<BoolT> tmp107;
  if (block79.is_used()) {
    ca_.Bind(&block79, &phi_bb79_7, &phi_bb79_8, &phi_bb79_9, &phi_bb79_10, &phi_bb79_11, &phi_bb79_14);
    tmp107 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Branch(tmp107, &block77, std::vector<compiler::Node*>{phi_bb79_7, phi_bb79_8, phi_bb79_9, phi_bb79_10, phi_bb79_11, phi_bb79_14}, &block78, std::vector<compiler::Node*>{phi_bb79_7, phi_bb79_8, phi_bb79_9, phi_bb79_10, phi_bb79_11, phi_bb79_14});
  }

  TNode<Object> phi_bb77_7;
  TNode<IntPtrT> phi_bb77_8;
  TNode<IntPtrT> phi_bb77_9;
  TNode<Object> phi_bb77_10;
  TNode<IntPtrT> phi_bb77_11;
  TNode<IntPtrT> phi_bb77_14;
  TNode<BoolT> tmp108;
  if (block77.is_used()) {
    ca_.Bind(&block77, &phi_bb77_7, &phi_bb77_8, &phi_bb77_9, &phi_bb77_10, &phi_bb77_11, &phi_bb77_14);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 201);
    tmp108 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{phi_bb77_14}, TNode<IntPtrT>{tmp106});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 213);
    ca_.Branch(tmp108, &block83, std::vector<compiler::Node*>{phi_bb77_7, phi_bb77_8, phi_bb77_9, phi_bb77_10, phi_bb77_11, phi_bb77_14}, &block84, std::vector<compiler::Node*>{phi_bb77_7, phi_bb77_8, phi_bb77_9, phi_bb77_10, phi_bb77_11, phi_bb77_14});
  }

  TNode<Object> phi_bb83_7;
  TNode<IntPtrT> phi_bb83_8;
  TNode<IntPtrT> phi_bb83_9;
  TNode<Object> phi_bb83_10;
  TNode<IntPtrT> phi_bb83_11;
  TNode<IntPtrT> phi_bb83_14;
  if (block83.is_used()) {
    ca_.Bind(&block83, &phi_bb83_7, &phi_bb83_8, &phi_bb83_9, &phi_bb83_10, &phi_bb83_11, &phi_bb83_14);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1000);
    ca_.Goto(&block78, phi_bb83_7, phi_bb83_8, phi_bb83_9, phi_bb83_10, phi_bb83_11, phi_bb83_14);
  }

  TNode<Object> phi_bb84_7;
  TNode<IntPtrT> phi_bb84_8;
  TNode<IntPtrT> phi_bb84_9;
  TNode<Object> phi_bb84_10;
  TNode<IntPtrT> phi_bb84_11;
  TNode<IntPtrT> phi_bb84_14;
  TNode<Object> tmp109;
  TNode<IntPtrT> tmp110;
  TNode<IntPtrT> tmp111;
  TNode<IntPtrT> tmp112;
  TNode<BoolT> tmp113;
  TNode<BoolT> tmp114;
  if (block84.is_used()) {
    ca_.Bind(&block84, &phi_bb84_7, &phi_bb84_8, &phi_bb84_9, &phi_bb84_10, &phi_bb84_11, &phi_bb84_14);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 216);
    std::tie(tmp109, tmp110) = NewReference_char16_0(state_, TNode<Object>{tmp17}, TNode<IntPtrT>{phi_bb84_14}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 217);
    tmp111 = FromConstexpr_intptr_constexpr_int31_0(state_, kUInt16Size);
    tmp112 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb84_14}, TNode<IntPtrT>{tmp111});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 201);
    tmp113 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{phi_bb84_11}, TNode<IntPtrT>{tmp104});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 223);
    tmp114 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp113});
    ca_.Branch(tmp114, &block89, std::vector<compiler::Node*>{phi_bb84_7, phi_bb84_8, phi_bb84_9, phi_bb84_10, phi_bb84_11}, &block90, std::vector<compiler::Node*>{phi_bb84_7, phi_bb84_8, phi_bb84_9, phi_bb84_10, phi_bb84_11});
  }

  TNode<Object> phi_bb90_7;
  TNode<IntPtrT> phi_bb90_8;
  TNode<IntPtrT> phi_bb90_9;
  TNode<Object> phi_bb90_10;
  TNode<IntPtrT> phi_bb90_11;
  if (block90.is_used()) {
    ca_.Bind(&block90, &phi_bb90_7, &phi_bb90_8, &phi_bb90_9, &phi_bb90_10, &phi_bb90_11);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/torque-internal.tq", 223});
      CodeStubAssembler(state_).FailAssert("Torque assert '!this.Empty()' failed", pos_stack);
    }
  }

  TNode<Object> phi_bb89_7;
  TNode<IntPtrT> phi_bb89_8;
  TNode<IntPtrT> phi_bb89_9;
  TNode<Object> phi_bb89_10;
  TNode<IntPtrT> phi_bb89_11;
  TNode<Object> tmp115;
  TNode<IntPtrT> tmp116;
  TNode<IntPtrT> tmp117;
  TNode<IntPtrT> tmp118;
  TNode<Uint16T> tmp119;
  if (block89.is_used()) {
    ca_.Bind(&block89, &phi_bb89_7, &phi_bb89_8, &phi_bb89_9, &phi_bb89_10, &phi_bb89_11);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 224);
    std::tie(tmp115, tmp116) = NewReference_char16_0(state_, TNode<Object>{phi_bb89_10}, TNode<IntPtrT>{phi_bb89_11}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 225);
    tmp117 = FromConstexpr_intptr_constexpr_int31_0(state_, kUInt16Size);
    tmp118 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb89_11}, TNode<IntPtrT>{tmp117});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 209);
    tmp119 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference{tmp115, tmp116});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1001);
    CodeStubAssembler(state_).StoreReference<Uint16T>(CodeStubAssembler::Reference{tmp109, tmp110}, tmp119);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 999);
    ca_.Goto(&block79, phi_bb89_7, phi_bb89_8, phi_bb89_9, phi_bb89_10, tmp118, tmp112);
  }

  TNode<Object> phi_bb78_7;
  TNode<IntPtrT> phi_bb78_8;
  TNode<IntPtrT> phi_bb78_9;
  TNode<Object> phi_bb78_10;
  TNode<IntPtrT> phi_bb78_11;
  TNode<IntPtrT> phi_bb78_14;
  if (block78.is_used()) {
    ca_.Bind(&block78, &phi_bb78_7, &phi_bb78_8, &phi_bb78_9, &phi_bb78_10, &phi_bb78_11, &phi_bb78_14);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 987);
    ca_.Goto(&block7);
  }

  TNode<IntPtrT> tmp120;
  TNode<Int32T> tmp121;
  TNode<Uint32T> tmp122;
  if (block7.is_used()) {
    ca_.Bind(&block7);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1004);
    tmp120 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp121 = CodeStubAssembler(state_).LoadReference<Int32T>(CodeStubAssembler::Reference{parameter0, tmp120});
    tmp122 = CodeStubAssembler(state_).Unsigned(TNode<Int32T>{tmp121});
    CodeStubAssembler(state_).Return(tmp122);
  }

  TNode<NativeContext> tmp123;
  TNode<Smi> tmp124;
  TNode<Object> tmp125;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1007);
    tmp123 = LoadContextFromFrame_0(state_);
    tmp124 = CodeStubAssembler(state_).SmiConstant(MessageTemplate::kWasmTrapArrayOutOfBounds);
    tmp125 = CodeStubAssembler(state_).CallRuntime(Runtime::kThrowWasmError, tmp123, tmp124); 
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1008);
    CodeStubAssembler(state_).PrintErr("halting because of unreachable code at src/builtins/wasm.tq:1008:5");
    CodeStubAssembler(state_).Unreachable();
  }
}

TF_BUILTIN(WasmStringConcat, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<String> parameter0 = UncheckedParameter<String>(Descriptor::kA);
  USE(parameter0);
  TNode<String> parameter1 = UncheckedParameter<String>(Descriptor::kB);
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<NativeContext> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1012);
    tmp0 = LoadContextFromFrame_0(state_);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1013);
   CodeStubAssembler(state_).TailCallBuiltin(Builtin::kStringAdd_CheckNone, tmp0, parameter0, parameter1);
  }
}

TF_BUILTIN(WasmStringEqual, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<String> parameter0 = UncheckedParameter<String>(Descriptor::kA);
  USE(parameter0);
  TNode<String> parameter1 = UncheckedParameter<String>(Descriptor::kB);
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<BoolT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1016);
    tmp0 = CodeStubAssembler(state_).TaggedEqual(TNode<MaybeObject>{parameter0}, TNode<MaybeObject>{parameter1});
    ca_.Branch(tmp0, &block1, std::vector<compiler::Node*>{}, &block2, std::vector<compiler::Node*>{});
  }

  TNode<Int32T> tmp1;
  if (block1.is_used()) {
    ca_.Bind(&block1);
    tmp1 = FromConstexpr_int32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    CodeStubAssembler(state_).Return(tmp1);
  }

  TNode<IntPtrT> tmp2;
  TNode<Int32T> tmp3;
  TNode<IntPtrT> tmp4;
  TNode<Int32T> tmp5;
  TNode<BoolT> tmp6;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1017);
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp3 = CodeStubAssembler(state_).LoadReference<Int32T>(CodeStubAssembler::Reference{parameter0, tmp2});
    tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp5 = CodeStubAssembler(state_).LoadReference<Int32T>(CodeStubAssembler::Reference{parameter1, tmp4});
    tmp6 = CodeStubAssembler(state_).Word32NotEqual(TNode<Int32T>{tmp3}, TNode<Int32T>{tmp5});
    ca_.Branch(tmp6, &block3, std::vector<compiler::Node*>{}, &block4, std::vector<compiler::Node*>{});
  }

  TNode<Int32T> tmp7;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    tmp7 = FromConstexpr_int32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    CodeStubAssembler(state_).Return(tmp7);
  }

  TNode<NativeContext> tmp8;
  TNode<Oddball> tmp9;
  TNode<Oddball> tmp10;
  TNode<BoolT> tmp11;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1018);
    tmp8 = LoadContextFromFrame_0(state_);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1019);
    tmp9 = TORQUE_CAST(CodeStubAssembler(state_).CallRuntime(Runtime::kStringEqual, tmp8, parameter0, parameter1)); 
    tmp10 = True_0(state_);
    tmp11 = CodeStubAssembler(state_).TaggedEqual(TNode<HeapObject>{tmp9}, TNode<HeapObject>{tmp10});
    ca_.Branch(tmp11, &block5, std::vector<compiler::Node*>{}, &block6, std::vector<compiler::Node*>{});
  }

  TNode<Int32T> tmp12;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    tmp12 = FromConstexpr_int32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    CodeStubAssembler(state_).Return(tmp12);
  }

  TNode<Int32T> tmp13;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1020);
    tmp13 = FromConstexpr_int32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    CodeStubAssembler(state_).Return(tmp13);
  }
}

TF_BUILTIN(WasmStringIsUSVSequence, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<String> parameter0 = UncheckedParameter<String>(Descriptor::kStr);
  USE(parameter0);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Uint16T> tmp0;
  TNode<BoolT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1023);
    tmp0 = CodeStubAssembler(state_).LoadInstanceType(TNode<HeapObject>{parameter0});
    tmp1 = CodeStubAssembler(state_).IsOneByteStringInstanceType(TNode<Uint16T>{tmp0});
    ca_.Branch(tmp1, &block1, std::vector<compiler::Node*>{}, &block2, std::vector<compiler::Node*>{});
  }

  TNode<Int32T> tmp2;
  if (block1.is_used()) {
    ca_.Bind(&block1);
    tmp2 = FromConstexpr_int32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    CodeStubAssembler(state_).Return(tmp2);
  }

  TNode<NativeContext> tmp3;
  TNode<Number> tmp4;
  TNode<Uint32T> tmp5;
  TNode<Int32T> tmp6;
  TNode<Int32T> tmp7;
  TNode<BoolT> tmp8;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1024);
    tmp3 = LoadContextFromFrame_0(state_);
    tmp4 = TORQUE_CAST(CodeStubAssembler(state_).CallRuntime(Runtime::kWasmStringMeasureUtf8, tmp3, parameter0)); 
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1025);
    tmp5 = CodeStubAssembler(state_).ChangeNumberToUint32(TNode<Number>{tmp4});
    tmp6 = CodeStubAssembler(state_).Signed(TNode<Uint32T>{tmp5});
    tmp7 = FromConstexpr_int32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp8 = CodeStubAssembler(state_).Int32LessThan(TNode<Int32T>{tmp6}, TNode<Int32T>{tmp7});
    ca_.Branch(tmp8, &block3, std::vector<compiler::Node*>{}, &block4, std::vector<compiler::Node*>{});
  }

  TNode<Int32T> tmp9;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    tmp9 = FromConstexpr_int32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    CodeStubAssembler(state_).Return(tmp9);
  }

  TNode<Int32T> tmp10;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1026);
    tmp10 = FromConstexpr_int32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    CodeStubAssembler(state_).Return(tmp10);
  }
}

TF_BUILTIN(WasmStringAsWtf8, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<String> parameter0 = UncheckedParameter<String>(Descriptor::kStr);
  USE(parameter0);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<NativeContext> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1029);
    tmp0 = LoadContextFromFrame_0(state_);
    CodeStubAssembler(state_).TailCallRuntime(Runtime::kWasmStringAsWtf8, tmp0, parameter0);
  }
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm.tq?l=1031&c=1
TNode<BoolT> IsWtf8CodepointStart_0(compiler::CodeAssemblerState* state_, TNode<ByteArray> p_view, TNode<Uint32T> p_pos) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Object> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<UintPtrT> tmp3;
  TNode<IntPtrT> tmp4;
  TNode<UintPtrT> tmp5;
  TNode<UintPtrT> tmp6;
  TNode<BoolT> tmp7;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1034);
    std::tie(tmp0, tmp1, tmp2) = FieldSliceByteArrayBytes_0(state_, TNode<ByteArray>{p_view}).Flatten();
    tmp3 = Convert_uintptr_uint32_0(state_, TNode<Uint32T>{p_pos});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 105);
    tmp4 = Convert_intptr_uintptr_0(state_, TNode<UintPtrT>{tmp3});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 89);
    tmp5 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp4});
    tmp6 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp2});
    tmp7 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp5}, TNode<UintPtrT>{tmp6});
    ca_.Branch(tmp7, &block6, std::vector<compiler::Node*>{}, &block7, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<Object> tmp10;
  TNode<IntPtrT> tmp11;
  TNode<Uint8T> tmp12;
  TNode<Uint32T> tmp13;
  TNode<Uint32T> tmp14;
  TNode<Uint32T> tmp15;
  TNode<BoolT> tmp16;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 97);
    tmp8 = TimesSizeOf_uint8_0(state_, TNode<IntPtrT>{tmp4});
    tmp9 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp8});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 96);
    std::tie(tmp10, tmp11) = NewReference_uint8_0(state_, TNode<Object>{tmp0}, TNode<IntPtrT>{tmp9}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1034);
    tmp12 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference{tmp10, tmp11});
    tmp13 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0xc0ull));
    tmp14 = CodeStubAssembler(state_).Word32And(TNode<Uint32T>{tmp12}, TNode<Uint32T>{tmp13});
    tmp15 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x80ull));
    tmp16 = CodeStubAssembler(state_).Word32NotEqual(TNode<Uint32T>{tmp14}, TNode<Uint32T>{tmp15});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1031);
    ca_.Goto(&block10);
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 105);
    CodeStubAssembler(state_).PrintErr("halting because of unreachable code at src/builtins/torque-internal.tq:105:62");
    CodeStubAssembler(state_).Unreachable();
  }

    ca_.Bind(&block10);
  return TNode<BoolT>{tmp16};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm.tq?l=1036&c=1
TNode<Uint32T> AlignWtf8PositionForward_0(compiler::CodeAssemblerState* state_, TNode<ByteArray> p_view, TNode<Uint32T> p_pos) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint32T> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint32T> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Smi> tmp1;
  TNode<Int32T> tmp2;
  TNode<Uint32T> tmp3;
  TNode<BoolT> tmp4;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1037);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp1 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{p_view, tmp0});
    tmp2 = CodeStubAssembler(state_).SmiToInt32(TNode<Smi>{tmp1});
    tmp3 = CodeStubAssembler(state_).Unsigned(TNode<Int32T>{tmp2});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1038);
    tmp4 = CodeStubAssembler(state_).Uint32GreaterThanOrEqual(TNode<Uint32T>{p_pos}, TNode<Uint32T>{tmp3});
    ca_.Branch(tmp4, &block2, std::vector<compiler::Node*>{}, &block3, std::vector<compiler::Node*>{});
  }

  if (block2.is_used()) {
    ca_.Bind(&block2);
    ca_.Goto(&block1, tmp3);
  }

  TNode<BoolT> tmp5;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1040);
    tmp5 = IsWtf8CodepointStart_0(state_, TNode<ByteArray>{p_view}, TNode<Uint32T>{p_pos});
    ca_.Branch(tmp5, &block4, std::vector<compiler::Node*>{}, &block5, std::vector<compiler::Node*>{});
  }

  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.Goto(&block1, p_pos);
  }

  TNode<Uint32T> tmp6;
  TNode<Uint32T> tmp7;
  TNode<BoolT> tmp8;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1045);
    tmp6 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp7 = CodeStubAssembler(state_).Uint32Add(TNode<Uint32T>{p_pos}, TNode<Uint32T>{tmp6});
    tmp8 = CodeStubAssembler(state_).Word32Equal(TNode<Uint32T>{tmp7}, TNode<Uint32T>{tmp3});
    ca_.Branch(tmp8, &block6, std::vector<compiler::Node*>{}, &block7, std::vector<compiler::Node*>{});
  }

  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.Goto(&block1, tmp3);
  }

  TNode<Uint32T> tmp9;
  TNode<Uint32T> tmp10;
  TNode<BoolT> tmp11;
  if (block7.is_used()) {
    ca_.Bind(&block7);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1046);
    tmp9 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp10 = CodeStubAssembler(state_).Uint32Add(TNode<Uint32T>{p_pos}, TNode<Uint32T>{tmp9});
    tmp11 = IsWtf8CodepointStart_0(state_, TNode<ByteArray>{p_view}, TNode<Uint32T>{tmp10});
    ca_.Branch(tmp11, &block8, std::vector<compiler::Node*>{}, &block9, std::vector<compiler::Node*>{});
  }

  TNode<Uint32T> tmp12;
  TNode<Uint32T> tmp13;
  if (block8.is_used()) {
    ca_.Bind(&block8);
    tmp12 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp13 = CodeStubAssembler(state_).Uint32Add(TNode<Uint32T>{p_pos}, TNode<Uint32T>{tmp12});
    ca_.Goto(&block1, tmp13);
  }

  TNode<Uint32T> tmp14;
  TNode<Uint32T> tmp15;
  TNode<BoolT> tmp16;
  if (block9.is_used()) {
    ca_.Bind(&block9);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1048);
    tmp14 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x2ull));
    tmp15 = CodeStubAssembler(state_).Uint32Add(TNode<Uint32T>{p_pos}, TNode<Uint32T>{tmp14});
    tmp16 = CodeStubAssembler(state_).Word32Equal(TNode<Uint32T>{tmp15}, TNode<Uint32T>{tmp3});
    ca_.Branch(tmp16, &block10, std::vector<compiler::Node*>{}, &block11, std::vector<compiler::Node*>{});
  }

  if (block10.is_used()) {
    ca_.Bind(&block10);
    ca_.Goto(&block1, tmp3);
  }

  TNode<Uint32T> tmp17;
  TNode<Uint32T> tmp18;
  TNode<BoolT> tmp19;
  if (block11.is_used()) {
    ca_.Bind(&block11);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1049);
    tmp17 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x2ull));
    tmp18 = CodeStubAssembler(state_).Uint32Add(TNode<Uint32T>{p_pos}, TNode<Uint32T>{tmp17});
    tmp19 = IsWtf8CodepointStart_0(state_, TNode<ByteArray>{p_view}, TNode<Uint32T>{tmp18});
    ca_.Branch(tmp19, &block12, std::vector<compiler::Node*>{}, &block13, std::vector<compiler::Node*>{});
  }

  TNode<Uint32T> tmp20;
  TNode<Uint32T> tmp21;
  if (block12.is_used()) {
    ca_.Bind(&block12);
    tmp20 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x2ull));
    tmp21 = CodeStubAssembler(state_).Uint32Add(TNode<Uint32T>{p_pos}, TNode<Uint32T>{tmp20});
    ca_.Goto(&block1, tmp21);
  }

  TNode<Uint32T> tmp22;
  TNode<Uint32T> tmp23;
  if (block13.is_used()) {
    ca_.Bind(&block13);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1051);
    tmp22 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x3ull));
    tmp23 = CodeStubAssembler(state_).Uint32Add(TNode<Uint32T>{p_pos}, TNode<Uint32T>{tmp22});
    ca_.Goto(&block1, tmp23);
  }

  TNode<Uint32T> phi_bb1_2;
  if (block1.is_used()) {
    ca_.Bind(&block1, &phi_bb1_2);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1036);
    ca_.Goto(&block14, phi_bb1_2);
  }

  TNode<Uint32T> phi_bb14_2;
    ca_.Bind(&block14, &phi_bb14_2);
  return TNode<Uint32T>{phi_bb14_2};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm.tq?l=1053&c=1
TNode<Uint32T> AlignWtf8PositionBackward_0(compiler::CodeAssemblerState* state_, TNode<ByteArray> p_view, TNode<Uint32T> p_pos) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint32T> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint32T> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<BoolT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1057);
    tmp0 = IsWtf8CodepointStart_0(state_, TNode<ByteArray>{p_view}, TNode<Uint32T>{p_pos});
    ca_.Branch(tmp0, &block2, std::vector<compiler::Node*>{}, &block3, std::vector<compiler::Node*>{});
  }

  if (block2.is_used()) {
    ca_.Bind(&block2);
    ca_.Goto(&block1, p_pos);
  }

  TNode<Uint32T> tmp1;
  TNode<Uint32T> tmp2;
  TNode<BoolT> tmp3;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1058);
    tmp1 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp2 = CodeStubAssembler(state_).Uint32Sub(TNode<Uint32T>{p_pos}, TNode<Uint32T>{tmp1});
    tmp3 = IsWtf8CodepointStart_0(state_, TNode<ByteArray>{p_view}, TNode<Uint32T>{tmp2});
    ca_.Branch(tmp3, &block4, std::vector<compiler::Node*>{}, &block5, std::vector<compiler::Node*>{});
  }

  TNode<Uint32T> tmp4;
  TNode<Uint32T> tmp5;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    tmp4 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp5 = CodeStubAssembler(state_).Uint32Sub(TNode<Uint32T>{p_pos}, TNode<Uint32T>{tmp4});
    ca_.Goto(&block1, tmp5);
  }

  TNode<Uint32T> tmp6;
  TNode<Uint32T> tmp7;
  TNode<BoolT> tmp8;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1059);
    tmp6 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x2ull));
    tmp7 = CodeStubAssembler(state_).Uint32Sub(TNode<Uint32T>{p_pos}, TNode<Uint32T>{tmp6});
    tmp8 = IsWtf8CodepointStart_0(state_, TNode<ByteArray>{p_view}, TNode<Uint32T>{tmp7});
    ca_.Branch(tmp8, &block6, std::vector<compiler::Node*>{}, &block7, std::vector<compiler::Node*>{});
  }

  TNode<Uint32T> tmp9;
  TNode<Uint32T> tmp10;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp9 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x2ull));
    tmp10 = CodeStubAssembler(state_).Uint32Sub(TNode<Uint32T>{p_pos}, TNode<Uint32T>{tmp9});
    ca_.Goto(&block1, tmp10);
  }

  TNode<Uint32T> tmp11;
  TNode<Uint32T> tmp12;
  if (block7.is_used()) {
    ca_.Bind(&block7);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1060);
    tmp11 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x3ull));
    tmp12 = CodeStubAssembler(state_).Uint32Sub(TNode<Uint32T>{p_pos}, TNode<Uint32T>{tmp11});
    ca_.Goto(&block1, tmp12);
  }

  TNode<Uint32T> phi_bb1_2;
  if (block1.is_used()) {
    ca_.Bind(&block1, &phi_bb1_2);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1053);
    ca_.Goto(&block8, phi_bb1_2);
  }

  TNode<Uint32T> phi_bb8_2;
    ca_.Bind(&block8, &phi_bb8_2);
  return TNode<Uint32T>{phi_bb8_2};
}

TF_BUILTIN(WasmStringViewWtf8Advance, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<ByteArray> parameter0 = UncheckedParameter<ByteArray>(Descriptor::kView);
  USE(parameter0);
  TNode<Uint32T> parameter1 = UncheckedParameter<Uint32T>(Descriptor::kPos);
  USE(parameter1);
  TNode<Uint32T> parameter2 = UncheckedParameter<Uint32T>(Descriptor::kBytes);
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Uint32T> tmp0;
  TNode<Uint32T> tmp1;
  TNode<BoolT> tmp2;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1064);
    tmp0 = AlignWtf8PositionForward_0(state_, TNode<ByteArray>{parameter0}, TNode<Uint32T>{parameter1});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1065);
    tmp1 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp2 = CodeStubAssembler(state_).Word32Equal(TNode<Uint32T>{parameter2}, TNode<Uint32T>{tmp1});
    ca_.Branch(tmp2, &block1, std::vector<compiler::Node*>{}, &block2, std::vector<compiler::Node*>{});
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    CodeStubAssembler(state_).Return(tmp0);
  }

  TNode<IntPtrT> tmp3;
  TNode<Smi> tmp4;
  TNode<Int32T> tmp5;
  TNode<Uint32T> tmp6;
  TNode<Uint32T> tmp7;
  TNode<BoolT> tmp8;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1066);
    tmp3 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp4 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{parameter0, tmp3});
    tmp5 = CodeStubAssembler(state_).SmiToInt32(TNode<Smi>{tmp4});
    tmp6 = CodeStubAssembler(state_).Unsigned(TNode<Int32T>{tmp5});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1067);
    tmp7 = CodeStubAssembler(state_).Uint32Sub(TNode<Uint32T>{tmp6}, TNode<Uint32T>{tmp0});
    tmp8 = CodeStubAssembler(state_).Uint32GreaterThanOrEqual(TNode<Uint32T>{parameter2}, TNode<Uint32T>{tmp7});
    ca_.Branch(tmp8, &block3, std::vector<compiler::Node*>{}, &block4, std::vector<compiler::Node*>{});
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    CodeStubAssembler(state_).Return(tmp6);
  }

  TNode<Uint32T> tmp9;
  TNode<Uint32T> tmp10;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1068);
    tmp9 = CodeStubAssembler(state_).Uint32Add(TNode<Uint32T>{tmp0}, TNode<Uint32T>{parameter2});
    tmp10 = AlignWtf8PositionBackward_0(state_, TNode<ByteArray>{parameter0}, TNode<Uint32T>{tmp9});
    CodeStubAssembler(state_).Return(tmp10);
  }
}

TF_BUILTIN(WasmStringViewWtf8Encode, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Uint32T> parameter0 = UncheckedParameter<Uint32T>(Descriptor::kAddr);
  USE(parameter0);
  TNode<Uint32T> parameter1 = UncheckedParameter<Uint32T>(Descriptor::kPos);
  USE(parameter1);
  TNode<Uint32T> parameter2 = UncheckedParameter<Uint32T>(Descriptor::kBytes);
  USE(parameter2);
  TNode<ByteArray> parameter3 = UncheckedParameter<ByteArray>(Descriptor::kView);
  USE(parameter3);
  TNode<Smi> parameter4 = UncheckedParameter<Smi>(Descriptor::kMemory);
  USE(parameter4);
  TNode<Smi> parameter5 = UncheckedParameter<Smi>(Descriptor::kUtf8Variant);
  USE(parameter5);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Uint32T> tmp0;
  TNode<Uint32T> tmp1;
  TNode<Uint32T> tmp2;
  TNode<WasmInstanceObject> tmp3;
  TNode<NativeContext> tmp4;
  TNode<Int32T> tmp5;
  TNode<Smi> tmp6;
  TNode<BoolT> tmp7;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1077);
    tmp0 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp1 = ca_.CallStub<Uint32T>(Builtins::CallableFor(ca_.isolate(), Builtin::kWasmStringViewWtf8Advance), TNode<Object>(), parameter3, parameter1, tmp0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1078);
    tmp2 = ca_.CallStub<Uint32T>(Builtins::CallableFor(ca_.isolate(), Builtin::kWasmStringViewWtf8Advance), TNode<Object>(), parameter3, tmp1, parameter2);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1079);
    tmp3 = WasmBuiltinsAssembler(state_).LoadInstanceFromFrame();
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1080);
    tmp4 = WasmBuiltinsAssembler(state_).LoadContextFromInstance(TNode<WasmInstanceObject>{tmp3});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1086);
    tmp5 = FromConstexpr_int32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp6 = CodeStubAssembler(state_).SmiFromInt32(TNode<Int32T>{tmp5});
    tmp7 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{parameter4}, TNode<Smi>{tmp6});
    ca_.Branch(tmp7, &block1, std::vector<compiler::Node*>{}, &block2, std::vector<compiler::Node*>{});
  }

  if (block2.is_used()) {
    ca_.Bind(&block2);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/wasm.tq", 1086});
      CodeStubAssembler(state_).FailAssert("Torque assert 'memory == SmiFromInt32(0)' failed", pos_stack);
    }
  }

  TNode<Number> tmp8;
  TNode<Number> tmp9;
  TNode<Number> tmp10;
  TNode<Object> tmp11;
  TNode<UintPtrT> tmp12;
  TNode<Uint32T> tmp13;
  TNode<UintPtrT> tmp14;
  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1090);
    tmp8 = ca_.CallStub<Number>(Builtins::CallableFor(ca_.isolate(), Builtin::kWasmUint32ToNumber), TNode<Object>(), parameter0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1091);
    tmp9 = ca_.CallStub<Number>(Builtins::CallableFor(ca_.isolate(), Builtin::kWasmUint32ToNumber), TNode<Object>(), tmp1);
    tmp10 = ca_.CallStub<Number>(Builtins::CallableFor(ca_.isolate(), Builtin::kWasmUint32ToNumber), TNode<Object>(), tmp2);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1089);
    tmp11 = CodeStubAssembler(state_).CallRuntime(Runtime::kWasmStringViewWtf8Encode, tmp4, tmp3, parameter5, parameter3, tmp8, tmp9, tmp10); 
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1094);
    tmp12 = Convert_uintptr_uint32_0(state_, TNode<Uint32T>{tmp2});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1095);
    tmp13 = CodeStubAssembler(state_).Uint32Sub(TNode<Uint32T>{tmp2}, TNode<Uint32T>{tmp1});
    tmp14 = Convert_uintptr_uint32_0(state_, TNode<Uint32T>{tmp13});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1093);
    CodeStubAssembler(state_).Return(tmp12, tmp14);
  }
}

TF_BUILTIN(WasmStringViewWtf8Slice, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<ByteArray> parameter0 = UncheckedParameter<ByteArray>(Descriptor::kView);
  USE(parameter0);
  TNode<Uint32T> parameter1 = UncheckedParameter<Uint32T>(Descriptor::kStart);
  USE(parameter1);
  TNode<Uint32T> parameter2 = UncheckedParameter<Uint32T>(Descriptor::kEnd);
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Uint32T> tmp0;
  TNode<Uint32T> tmp1;
  TNode<Uint32T> tmp2;
  TNode<Uint32T> tmp3;
  TNode<BoolT> tmp4;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1100);
    tmp0 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp1 = ca_.CallStub<Uint32T>(Builtins::CallableFor(ca_.isolate(), Builtin::kWasmStringViewWtf8Advance), TNode<Object>(), parameter0, parameter1, tmp0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1101);
    tmp2 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp3 = ca_.CallStub<Uint32T>(Builtins::CallableFor(ca_.isolate(), Builtin::kWasmStringViewWtf8Advance), TNode<Object>(), parameter0, parameter2, tmp2);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1103);
    tmp4 = CodeStubAssembler(state_).Uint32LessThanOrEqual(TNode<Uint32T>{tmp3}, TNode<Uint32T>{tmp1});
    ca_.Branch(tmp4, &block1, std::vector<compiler::Node*>{}, &block2, std::vector<compiler::Node*>{});
  }

  TNode<String> tmp5;
  if (block1.is_used()) {
    ca_.Bind(&block1);
    tmp5 = kEmptyString_0(state_);
    CodeStubAssembler(state_).Return(tmp5);
  }

  TNode<NativeContext> tmp6;
  TNode<Number> tmp7;
  TNode<Number> tmp8;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1106);
    tmp6 = LoadContextFromFrame_0(state_);
    tmp7 = ca_.CallStub<Number>(Builtins::CallableFor(ca_.isolate(), Builtin::kWasmUint32ToNumber), TNode<Object>(), tmp1);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1107);
    tmp8 = ca_.CallStub<Number>(Builtins::CallableFor(ca_.isolate(), Builtin::kWasmUint32ToNumber), TNode<Object>(), tmp3);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1105);
    CodeStubAssembler(state_).TailCallRuntime(Runtime::kWasmStringViewWtf8Slice, tmp6, parameter0, tmp7, tmp8);
  }
}

TF_BUILTIN(WasmStringViewWtf16GetCodeUnit, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<String> parameter0 = UncheckedParameter<String>(Descriptor::kString);
  USE(parameter0);
  TNode<Uint32T> parameter1 = UncheckedParameter<Uint32T>(Descriptor::kOffset);
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Int32T> tmp1;
  TNode<Uint32T> tmp2;
  TNode<BoolT> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1112);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp1 = CodeStubAssembler(state_).LoadReference<Int32T>(CodeStubAssembler::Reference{parameter0, tmp0});
    tmp2 = CodeStubAssembler(state_).Unsigned(TNode<Int32T>{tmp1});
    tmp3 = CodeStubAssembler(state_).Uint32LessThanOrEqual(TNode<Uint32T>{tmp2}, TNode<Uint32T>{parameter1});
    ca_.Branch(tmp3, &block3, std::vector<compiler::Node*>{}, &block4, std::vector<compiler::Node*>{});
  }

  TNode<NativeContext> tmp4;
  TNode<Smi> tmp5;
  TNode<Object> tmp6;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1117);
    tmp4 = LoadContextFromFrame_0(state_);
    tmp5 = CodeStubAssembler(state_).SmiConstant(MessageTemplate::kWasmTrapStringOffsetOutOfBounds);
    tmp6 = CodeStubAssembler(state_).CallRuntime(Runtime::kThrowWasmError, tmp4, tmp5); 
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1118);
    CodeStubAssembler(state_).PrintErr("halting because of unreachable code at src/builtins/wasm.tq:1118:5");
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<UintPtrT> tmp7;
  TNode<Uint16T> tmp8;
  TNode<Uint32T> tmp9;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1113);
    tmp7 = Convert_uintptr_uint32_0(state_, TNode<Uint32T>{parameter1});
    tmp8 = CodeStubAssembler(state_).StringCharCodeAt(TNode<String>{parameter0}, TNode<UintPtrT>{tmp7});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1114);
    tmp9 = Convert_uint32_char16_0(state_, TNode<Uint16T>{tmp8});
    CodeStubAssembler(state_).Return(tmp9);
  }
}

TF_BUILTIN(WasmStringViewWtf16Encode, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Uint32T> parameter0 = UncheckedParameter<Uint32T>(Descriptor::kOffset);
  USE(parameter0);
  TNode<Uint32T> parameter1 = UncheckedParameter<Uint32T>(Descriptor::kStart);
  USE(parameter1);
  TNode<Uint32T> parameter2 = UncheckedParameter<Uint32T>(Descriptor::kLength);
  USE(parameter2);
  TNode<String> parameter3 = UncheckedParameter<String>(Descriptor::kString);
  USE(parameter3);
  TNode<Smi> parameter4 = UncheckedParameter<Smi>(Descriptor::kMemory);
  USE(parameter4);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint32T> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint32T> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<WasmInstanceObject> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<Int32T> tmp2;
  TNode<Uint32T> tmp3;
  TNode<BoolT> tmp4;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1124);
    tmp0 = WasmBuiltinsAssembler(state_).LoadInstanceFromFrame();
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1126);
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp2 = CodeStubAssembler(state_).LoadReference<Int32T>(CodeStubAssembler::Reference{parameter3, tmp1});
    tmp3 = CodeStubAssembler(state_).Unsigned(TNode<Int32T>{tmp2});
    tmp4 = CodeStubAssembler(state_).Uint32LessThan(TNode<Uint32T>{parameter1}, TNode<Uint32T>{tmp3});
    ca_.Branch(tmp4, &block1, std::vector<compiler::Node*>{}, &block2, std::vector<compiler::Node*>{});
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(&block3, parameter1);
  }

  TNode<IntPtrT> tmp5;
  TNode<Int32T> tmp6;
  TNode<Uint32T> tmp7;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    tmp5 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp6 = CodeStubAssembler(state_).LoadReference<Int32T>(CodeStubAssembler::Reference{parameter3, tmp5});
    tmp7 = CodeStubAssembler(state_).Unsigned(TNode<Int32T>{tmp6});
    ca_.Goto(&block3, tmp7);
  }

  TNode<Uint32T> phi_bb3_6;
  TNode<IntPtrT> tmp8;
  TNode<Int32T> tmp9;
  TNode<Uint32T> tmp10;
  TNode<Uint32T> tmp11;
  TNode<BoolT> tmp12;
  if (block3.is_used()) {
    ca_.Bind(&block3, &phi_bb3_6);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1127);
    tmp8 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp9 = CodeStubAssembler(state_).LoadReference<Int32T>(CodeStubAssembler::Reference{parameter3, tmp8});
    tmp10 = CodeStubAssembler(state_).Unsigned(TNode<Int32T>{tmp9});
    tmp11 = CodeStubAssembler(state_).Uint32Sub(TNode<Uint32T>{tmp10}, TNode<Uint32T>{phi_bb3_6});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1128);
    tmp12 = CodeStubAssembler(state_).Uint32LessThan(TNode<Uint32T>{parameter2}, TNode<Uint32T>{tmp11});
    ca_.Branch(tmp12, &block5, std::vector<compiler::Node*>{}, &block6, std::vector<compiler::Node*>{});
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    ca_.Goto(&block7, parameter2);
  }

  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.Goto(&block7, tmp11);
  }

  TNode<Uint32T> phi_bb7_8;
  TNode<NativeContext> tmp13;
  TNode<Number> tmp14;
  TNode<Smi> tmp15;
  TNode<Smi> tmp16;
  TNode<Object> tmp17;
  if (block7.is_used()) {
    ca_.Bind(&block7, &phi_bb7_8);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1130);
    tmp13 = WasmBuiltinsAssembler(state_).LoadContextFromInstance(TNode<WasmInstanceObject>{tmp0});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1131);
    tmp14 = ca_.CallStub<Number>(Builtins::CallableFor(ca_.isolate(), Builtin::kWasmUint32ToNumber), TNode<Object>(), parameter0);
    tmp15 = CodeStubAssembler(state_).SmiFromUint32(TNode<Uint32T>{phi_bb3_6});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1132);
    tmp16 = CodeStubAssembler(state_).SmiFromUint32(TNode<Uint32T>{phi_bb7_8});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1129);
    tmp17 = CodeStubAssembler(state_).CallRuntime(Runtime::kWasmStringEncodeWtf16, tmp13, tmp0, parameter4, parameter3, tmp14, tmp15, tmp16); 
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1133);
    CodeStubAssembler(state_).Return(phi_bb7_8);
  }
}

TF_BUILTIN(WasmStringViewWtf16Slice, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<String> parameter0 = UncheckedParameter<String>(Descriptor::kString);
  USE(parameter0);
  TNode<Uint32T> parameter1 = UncheckedParameter<Uint32T>(Descriptor::kStart);
  USE(parameter1);
  TNode<Uint32T> parameter2 = UncheckedParameter<Uint32T>(Descriptor::kEnd);
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint32T> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Int32T> tmp1;
  TNode<Uint32T> tmp2;
  TNode<BoolT> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1137);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp1 = CodeStubAssembler(state_).LoadReference<Int32T>(CodeStubAssembler::Reference{parameter0, tmp0});
    tmp2 = CodeStubAssembler(state_).Unsigned(TNode<Int32T>{tmp1});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1138);
    tmp3 = CodeStubAssembler(state_).Uint32GreaterThanOrEqual(TNode<Uint32T>{parameter1}, TNode<Uint32T>{tmp2});
    ca_.Branch(tmp3, &block1, std::vector<compiler::Node*>{}, &block2, std::vector<compiler::Node*>{});
  }

  TNode<String> tmp4;
  if (block1.is_used()) {
    ca_.Bind(&block1);
    tmp4 = kEmptyString_0(state_);
    CodeStubAssembler(state_).Return(tmp4);
  }

  TNode<BoolT> tmp5;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1139);
    tmp5 = CodeStubAssembler(state_).Uint32LessThanOrEqual(TNode<Uint32T>{parameter2}, TNode<Uint32T>{parameter1});
    ca_.Branch(tmp5, &block3, std::vector<compiler::Node*>{}, &block4, std::vector<compiler::Node*>{});
  }

  TNode<String> tmp6;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    tmp6 = kEmptyString_0(state_);
    CodeStubAssembler(state_).Return(tmp6);
  }

  TNode<BoolT> tmp7;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1140);
    tmp7 = CodeStubAssembler(state_).Uint32LessThanOrEqual(TNode<Uint32T>{parameter2}, TNode<Uint32T>{tmp2});
    ca_.Branch(tmp7, &block5, std::vector<compiler::Node*>{}, &block6, std::vector<compiler::Node*>{});
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    ca_.Goto(&block7, parameter2);
  }

  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.Goto(&block7, tmp2);
  }

  TNode<Uint32T> phi_bb7_4;
  TNode<UintPtrT> tmp8;
  TNode<UintPtrT> tmp9;
  TNode<String> tmp10;
  if (block7.is_used()) {
    ca_.Bind(&block7, &phi_bb7_4);
    tmp8 = Convert_uintptr_uint32_0(state_, TNode<Uint32T>{phi_bb7_4});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1141);
    tmp9 = Convert_uintptr_uint32_0(state_, TNode<Uint32T>{parameter1});
    tmp10 = StringBuiltinsAssembler(state_).SubString(TNode<String>{parameter0}, TNode<UintPtrT>{tmp9}, TNode<UintPtrT>{tmp8});
    CodeStubAssembler(state_).Return(tmp10);
  }
}

TF_BUILTIN(WasmStringAsIter, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<String> parameter0 = UncheckedParameter<String>(Descriptor::kString);
  USE(parameter0);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Map> tmp0;
  TNode<BoolT> tmp1;
  TNode<BoolT> tmp2;
  TNode<IntPtrT> tmp3;
  TNode<HeapObject> tmp4;
  TNode<IntPtrT> tmp5;
  TNode<IntPtrT> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<Uint32T> tmp8;
  TNode<WasmStringViewIter> tmp9;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1144);
    tmp0 = CodeStubAssembler(state_).GetInstanceTypeMap(WASM_STRING_VIEW_ITER_TYPE);
    tmp1 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    tmp2 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    tmp3 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp4 = AllocateFromNew_0(state_, TNode<IntPtrT>{tmp3}, TNode<Map>{tmp0}, TNode<BoolT>{tmp1}, TNode<BoolT>{tmp2});
    tmp5 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    CodeStubAssembler(state_).StoreReference<Map>(CodeStubAssembler::Reference{tmp4, tmp5}, tmp0);
    tmp6 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    CodeStubAssembler(state_).StoreReference<String>(CodeStubAssembler::Reference{tmp4, tmp6}, parameter0);
    tmp7 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp8 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    CodeStubAssembler(state_).StoreReference<Uint32T>(CodeStubAssembler::Reference{tmp4, tmp7}, tmp8);
    tmp9 = TORQUE_CAST(TNode<HeapObject>{tmp4});
    CodeStubAssembler(state_).Return(tmp9);
  }
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm.tq?l=1146&c=1
TNode<BoolT> IsLeadSurrogate_0(compiler::CodeAssemblerState* state_, TNode<Uint16T> p_code) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Uint32T> tmp0;
  TNode<Uint32T> tmp1;
  TNode<Uint32T> tmp2;
  TNode<BoolT> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1147);
    tmp0 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0xfc00ull));
    tmp1 = CodeStubAssembler(state_).Word32And(TNode<Uint32T>{p_code}, TNode<Uint32T>{tmp0});
    tmp2 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0xd800ull));
    tmp3 = CodeStubAssembler(state_).Word32Equal(TNode<Uint32T>{tmp1}, TNode<Uint32T>{tmp2});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1146);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<BoolT>{tmp3};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm.tq?l=1149&c=1
TNode<BoolT> IsTrailSurrogate_0(compiler::CodeAssemblerState* state_, TNode<Uint16T> p_code) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Uint32T> tmp0;
  TNode<Uint32T> tmp1;
  TNode<Uint32T> tmp2;
  TNode<BoolT> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1150);
    tmp0 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0xfc00ull));
    tmp1 = CodeStubAssembler(state_).Word32And(TNode<Uint32T>{p_code}, TNode<Uint32T>{tmp0});
    tmp2 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0xdc00ull));
    tmp3 = CodeStubAssembler(state_).Word32Equal(TNode<Uint32T>{tmp1}, TNode<Uint32T>{tmp2});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1149);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<BoolT>{tmp3};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm.tq?l=1152&c=1
TNode<Int32T> CombineSurrogatePair_0(compiler::CodeAssemblerState* state_, TNode<Uint16T> p_lead, TNode<Uint16T> p_trail) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Uint32T> tmp0;
  TNode<Uint32T> tmp1;
  TNode<Uint32T> tmp2;
  TNode<Uint32T> tmp3;
  TNode<Uint32T> tmp4;
  TNode<Uint32T> tmp5;
  TNode<Uint32T> tmp6;
  TNode<Int32T> tmp7;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1153);
    tmp0 = Convert_uint32_char16_0(state_, TNode<Uint16T>{p_lead});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1154);
    tmp1 = Convert_uint32_char16_0(state_, TNode<Uint16T>{p_trail});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1159);
    tmp2 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0xfca02400ull));
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1160);
    tmp3 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0xaull));
    tmp4 = CodeStubAssembler(state_).Word32Shl(TNode<Uint32T>{tmp0}, TNode<Uint32T>{tmp3});
    tmp5 = CodeStubAssembler(state_).Uint32Add(TNode<Uint32T>{tmp4}, TNode<Uint32T>{tmp1});
    tmp6 = CodeStubAssembler(state_).Uint32Add(TNode<Uint32T>{tmp5}, TNode<Uint32T>{tmp2});
    tmp7 = CodeStubAssembler(state_).Signed(TNode<Uint32T>{tmp6});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1152);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Int32T>{tmp7};
}

TF_BUILTIN(WasmStringViewIterNext, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<WasmStringViewIter> parameter0 = UncheckedParameter<WasmStringViewIter>(Descriptor::kView);
  USE(parameter0);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<String> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<Uint32T> tmp3;
  TNode<IntPtrT> tmp4;
  TNode<Int32T> tmp5;
  TNode<Uint32T> tmp6;
  TNode<BoolT> tmp7;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1163);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp1 = CodeStubAssembler(state_).LoadReference<String>(CodeStubAssembler::Reference{parameter0, tmp0});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1164);
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp3 = CodeStubAssembler(state_).LoadReference<Uint32T>(CodeStubAssembler::Reference{parameter0, tmp2});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1165);
    tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp5 = CodeStubAssembler(state_).LoadReference<Int32T>(CodeStubAssembler::Reference{tmp1, tmp4});
    tmp6 = CodeStubAssembler(state_).Unsigned(TNode<Int32T>{tmp5});
    tmp7 = CodeStubAssembler(state_).Uint32GreaterThanOrEqual(TNode<Uint32T>{tmp3}, TNode<Uint32T>{tmp6});
    ca_.Branch(tmp7, &block1, std::vector<compiler::Node*>{}, &block2, std::vector<compiler::Node*>{});
  }

  TNode<Int32T> tmp8;
  if (block1.is_used()) {
    ca_.Bind(&block1);
    tmp8 = FromConstexpr_int32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(true, 0x1ull));
    CodeStubAssembler(state_).Return(tmp8);
  }

  TNode<UintPtrT> tmp9;
  TNode<Uint16T> tmp10;
  TNode<BoolT> tmp11;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1166);
    tmp9 = Convert_uintptr_uint32_0(state_, TNode<Uint32T>{tmp3});
    tmp10 = CodeStubAssembler(state_).StringCharCodeAt(TNode<String>{tmp1}, TNode<UintPtrT>{tmp9});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1168);
    tmp11 = IsLeadSurrogate_0(state_, TNode<Uint16T>{tmp10});
    ca_.Branch(tmp11, &block7, std::vector<compiler::Node*>{}, &block8, std::vector<compiler::Node*>{});
  }

  TNode<Uint32T> tmp12;
  TNode<Uint32T> tmp13;
  TNode<IntPtrT> tmp14;
  TNode<Int32T> tmp15;
  TNode<Uint32T> tmp16;
  TNode<BoolT> tmp17;
  if (block7.is_used()) {
    ca_.Bind(&block7);
    tmp12 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp13 = CodeStubAssembler(state_).Uint32Add(TNode<Uint32T>{tmp3}, TNode<Uint32T>{tmp12});
    tmp14 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp15 = CodeStubAssembler(state_).LoadReference<Int32T>(CodeStubAssembler::Reference{tmp1, tmp14});
    tmp16 = CodeStubAssembler(state_).Unsigned(TNode<Int32T>{tmp15});
    tmp17 = CodeStubAssembler(state_).Uint32LessThan(TNode<Uint32T>{tmp13}, TNode<Uint32T>{tmp16});
    ca_.Goto(&block9, tmp17);
  }

  TNode<BoolT> tmp18;
  if (block8.is_used()) {
    ca_.Bind(&block8);
    tmp18 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block9, tmp18);
  }

  TNode<BoolT> phi_bb9_5;
  if (block9.is_used()) {
    ca_.Bind(&block9, &phi_bb9_5);
    ca_.Branch(phi_bb9_5, &block5, std::vector<compiler::Node*>{}, &block6, std::vector<compiler::Node*>{});
  }

  TNode<Uint32T> tmp19;
  TNode<Uint32T> tmp20;
  TNode<UintPtrT> tmp21;
  TNode<Uint16T> tmp22;
  TNode<BoolT> tmp23;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1173);
    tmp19 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp20 = CodeStubAssembler(state_).Uint32Add(TNode<Uint32T>{tmp3}, TNode<Uint32T>{tmp19});
    tmp21 = Convert_uintptr_uint32_0(state_, TNode<Uint32T>{tmp20});
    tmp22 = CodeStubAssembler(state_).StringCharCodeAt(TNode<String>{tmp1}, TNode<UintPtrT>{tmp21});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1174);
    tmp23 = IsTrailSurrogate_0(state_, TNode<Uint16T>{tmp22});
    ca_.Branch(tmp23, &block10, std::vector<compiler::Node*>{}, &block11, std::vector<compiler::Node*>{});
  }

  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1171);
    ca_.Goto(&block3);
  }

  TNode<IntPtrT> tmp24;
  TNode<Uint32T> tmp25;
  TNode<Uint32T> tmp26;
  TNode<Int32T> tmp27;
  if (block10.is_used()) {
    ca_.Bind(&block10);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1175);
    tmp24 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp25 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x2ull));
    tmp26 = CodeStubAssembler(state_).Uint32Add(TNode<Uint32T>{tmp3}, TNode<Uint32T>{tmp25});
    CodeStubAssembler(state_).StoreReference<Uint32T>(CodeStubAssembler::Reference{parameter0, tmp24}, tmp26);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1176);
    tmp27 = CombineSurrogatePair_0(state_, TNode<Uint16T>{tmp10}, TNode<Uint16T>{tmp22});
    CodeStubAssembler(state_).Return(tmp27);
  }

  if (block11.is_used()) {
    ca_.Bind(&block11);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1167);
    ca_.Goto(&block3);
  }

  TNode<IntPtrT> tmp28;
  TNode<Uint32T> tmp29;
  TNode<Uint32T> tmp30;
  TNode<Uint32T> tmp31;
  TNode<Int32T> tmp32;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1179);
    tmp28 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp29 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp30 = CodeStubAssembler(state_).Uint32Add(TNode<Uint32T>{tmp3}, TNode<Uint32T>{tmp29});
    CodeStubAssembler(state_).StoreReference<Uint32T>(CodeStubAssembler::Reference{parameter0, tmp28}, tmp30);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1180);
    tmp31 = Convert_uint32_char16_0(state_, TNode<Uint16T>{tmp10});
    tmp32 = CodeStubAssembler(state_).Signed(TNode<Uint32T>{tmp31});
    CodeStubAssembler(state_).Return(tmp32);
  }
}

TF_BUILTIN(WasmStringViewIterAdvance, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<WasmStringViewIter> parameter0 = UncheckedParameter<WasmStringViewIter>(Descriptor::kView);
  USE(parameter0);
  TNode<Uint32T> parameter1 = UncheckedParameter<Uint32T>(Descriptor::kCodepoints);
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint32T, Uint32T> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint32T, Uint32T> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint32T, Uint32T> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint32T, Uint32T> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint32T> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint32T> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint32T, BoolT> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint32T> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint32T> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint32T, BoolT> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint32T> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint32T> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint32T> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint32T, Uint32T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<String> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<Uint32T> tmp3;
  TNode<Uint32T> tmp4;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1184);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp1 = CodeStubAssembler(state_).LoadReference<String>(CodeStubAssembler::Reference{parameter0, tmp0});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1185);
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp3 = CodeStubAssembler(state_).LoadReference<Uint32T>(CodeStubAssembler::Reference{parameter0, tmp2});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1186);
    tmp4 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1187);
    ca_.Goto(&block3, tmp3, tmp4);
  }

  TNode<Uint32T> phi_bb3_3;
  TNode<Uint32T> phi_bb3_4;
  TNode<BoolT> tmp5;
  if (block3.is_used()) {
    ca_.Bind(&block3, &phi_bb3_3, &phi_bb3_4);
    tmp5 = CodeStubAssembler(state_).Uint32LessThan(TNode<Uint32T>{phi_bb3_4}, TNode<Uint32T>{parameter1});
    ca_.Branch(tmp5, &block1, std::vector<compiler::Node*>{phi_bb3_3, phi_bb3_4}, &block2, std::vector<compiler::Node*>{phi_bb3_3, phi_bb3_4});
  }

  TNode<Uint32T> phi_bb1_3;
  TNode<Uint32T> phi_bb1_4;
  TNode<IntPtrT> tmp6;
  TNode<Int32T> tmp7;
  TNode<Uint32T> tmp8;
  TNode<BoolT> tmp9;
  if (block1.is_used()) {
    ca_.Bind(&block1, &phi_bb1_3, &phi_bb1_4);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1188);
    tmp6 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp7 = CodeStubAssembler(state_).LoadReference<Int32T>(CodeStubAssembler::Reference{tmp1, tmp6});
    tmp8 = CodeStubAssembler(state_).Unsigned(TNode<Int32T>{tmp7});
    tmp9 = CodeStubAssembler(state_).Word32Equal(TNode<Uint32T>{phi_bb1_3}, TNode<Uint32T>{tmp8});
    ca_.Branch(tmp9, &block4, std::vector<compiler::Node*>{phi_bb1_3, phi_bb1_4}, &block5, std::vector<compiler::Node*>{phi_bb1_3, phi_bb1_4});
  }

  TNode<Uint32T> phi_bb4_3;
  TNode<Uint32T> phi_bb4_4;
  if (block4.is_used()) {
    ca_.Bind(&block4, &phi_bb4_3, &phi_bb4_4);
    ca_.Goto(&block2, phi_bb4_3, phi_bb4_4);
  }

  TNode<Uint32T> phi_bb5_3;
  TNode<Uint32T> phi_bb5_4;
  TNode<Uint32T> tmp10;
  TNode<Uint32T> tmp11;
  TNode<Uint32T> tmp12;
  TNode<Uint32T> tmp13;
  TNode<IntPtrT> tmp14;
  TNode<Int32T> tmp15;
  TNode<Uint32T> tmp16;
  TNode<BoolT> tmp17;
  if (block5.is_used()) {
    ca_.Bind(&block5, &phi_bb5_3, &phi_bb5_4);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1189);
    tmp10 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp11 = CodeStubAssembler(state_).Uint32Add(TNode<Uint32T>{phi_bb5_4}, TNode<Uint32T>{tmp10});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1190);
    tmp12 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp13 = CodeStubAssembler(state_).Uint32Add(TNode<Uint32T>{phi_bb5_3}, TNode<Uint32T>{tmp12});
    tmp14 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp15 = CodeStubAssembler(state_).LoadReference<Int32T>(CodeStubAssembler::Reference{tmp1, tmp14});
    tmp16 = CodeStubAssembler(state_).Unsigned(TNode<Int32T>{tmp15});
    tmp17 = CodeStubAssembler(state_).Uint32LessThan(TNode<Uint32T>{tmp13}, TNode<Uint32T>{tmp16});
    ca_.Branch(tmp17, &block8, std::vector<compiler::Node*>{phi_bb5_3}, &block9, std::vector<compiler::Node*>{phi_bb5_3});
  }

  TNode<Uint32T> phi_bb8_3;
  TNode<UintPtrT> tmp18;
  TNode<Uint16T> tmp19;
  TNode<BoolT> tmp20;
  if (block8.is_used()) {
    ca_.Bind(&block8, &phi_bb8_3);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1191);
    tmp18 = Convert_uintptr_uint32_0(state_, TNode<Uint32T>{phi_bb8_3});
    tmp19 = CodeStubAssembler(state_).StringCharCodeAt(TNode<String>{tmp1}, TNode<UintPtrT>{tmp18});
    tmp20 = IsLeadSurrogate_0(state_, TNode<Uint16T>{tmp19});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1190);
    ca_.Goto(&block10, phi_bb8_3, tmp20);
  }

  TNode<Uint32T> phi_bb9_3;
  TNode<BoolT> tmp21;
  if (block9.is_used()) {
    ca_.Bind(&block9, &phi_bb9_3);
    tmp21 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block10, phi_bb9_3, tmp21);
  }

  TNode<Uint32T> phi_bb10_3;
  TNode<BoolT> phi_bb10_6;
  if (block10.is_used()) {
    ca_.Bind(&block10, &phi_bb10_3, &phi_bb10_6);
    ca_.Branch(phi_bb10_6, &block11, std::vector<compiler::Node*>{phi_bb10_3}, &block12, std::vector<compiler::Node*>{phi_bb10_3});
  }

  TNode<Uint32T> phi_bb11_3;
  TNode<Uint32T> tmp22;
  TNode<Uint32T> tmp23;
  TNode<UintPtrT> tmp24;
  TNode<Uint16T> tmp25;
  TNode<BoolT> tmp26;
  if (block11.is_used()) {
    ca_.Bind(&block11, &phi_bb11_3);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1193);
    tmp22 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp23 = CodeStubAssembler(state_).Uint32Add(TNode<Uint32T>{phi_bb11_3}, TNode<Uint32T>{tmp22});
    tmp24 = Convert_uintptr_uint32_0(state_, TNode<Uint32T>{tmp23});
    tmp25 = CodeStubAssembler(state_).StringCharCodeAt(TNode<String>{tmp1}, TNode<UintPtrT>{tmp24});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1192);
    tmp26 = IsTrailSurrogate_0(state_, TNode<Uint16T>{tmp25});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1190);
    ca_.Goto(&block13, phi_bb11_3, tmp26);
  }

  TNode<Uint32T> phi_bb12_3;
  TNode<BoolT> tmp27;
  if (block12.is_used()) {
    ca_.Bind(&block12, &phi_bb12_3);
    tmp27 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block13, phi_bb12_3, tmp27);
  }

  TNode<Uint32T> phi_bb13_3;
  TNode<BoolT> phi_bb13_6;
  if (block13.is_used()) {
    ca_.Bind(&block13, &phi_bb13_3, &phi_bb13_6);
    ca_.Branch(phi_bb13_6, &block6, std::vector<compiler::Node*>{phi_bb13_3}, &block7, std::vector<compiler::Node*>{phi_bb13_3});
  }

  TNode<Uint32T> phi_bb6_3;
  TNode<Uint32T> tmp28;
  TNode<Uint32T> tmp29;
  if (block6.is_used()) {
    ca_.Bind(&block6, &phi_bb6_3);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1194);
    tmp28 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x2ull));
    tmp29 = CodeStubAssembler(state_).Uint32Add(TNode<Uint32T>{phi_bb6_3}, TNode<Uint32T>{tmp28});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1190);
    ca_.Goto(&block14, tmp29);
  }

  TNode<Uint32T> phi_bb7_3;
  TNode<Uint32T> tmp30;
  TNode<Uint32T> tmp31;
  if (block7.is_used()) {
    ca_.Bind(&block7, &phi_bb7_3);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1196);
    tmp30 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp31 = CodeStubAssembler(state_).Uint32Add(TNode<Uint32T>{phi_bb7_3}, TNode<Uint32T>{tmp30});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1190);
    ca_.Goto(&block14, tmp31);
  }

  TNode<Uint32T> phi_bb14_3;
  if (block14.is_used()) {
    ca_.Bind(&block14, &phi_bb14_3);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1187);
    ca_.Goto(&block3, phi_bb14_3, tmp11);
  }

  TNode<Uint32T> phi_bb2_3;
  TNode<Uint32T> phi_bb2_4;
  TNode<IntPtrT> tmp32;
  if (block2.is_used()) {
    ca_.Bind(&block2, &phi_bb2_3, &phi_bb2_4);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1199);
    tmp32 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    CodeStubAssembler(state_).StoreReference<Uint32T>(CodeStubAssembler::Reference{parameter0, tmp32}, phi_bb2_3);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1200);
    CodeStubAssembler(state_).Return(phi_bb2_4);
  }
}

TF_BUILTIN(WasmStringViewIterRewind, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<WasmStringViewIter> parameter0 = UncheckedParameter<WasmStringViewIter>(Descriptor::kView);
  USE(parameter0);
  TNode<Uint32T> parameter1 = UncheckedParameter<Uint32T>(Descriptor::kCodepoints);
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint32T, Uint32T> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint32T, Uint32T> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint32T, Uint32T> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint32T, Uint32T> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint32T> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint32T> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint32T, BoolT> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint32T> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint32T> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint32T, BoolT> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint32T> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint32T> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint32T> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint32T, Uint32T> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<String> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<Uint32T> tmp3;
  TNode<Uint32T> tmp4;
  TNode<IntPtrT> tmp5;
  TNode<Int32T> tmp6;
  TNode<Int32T> tmp7;
  TNode<BoolT> tmp8;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1204);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp1 = CodeStubAssembler(state_).LoadReference<String>(CodeStubAssembler::Reference{parameter0, tmp0});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1205);
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp3 = CodeStubAssembler(state_).LoadReference<Uint32T>(CodeStubAssembler::Reference{parameter0, tmp2});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1206);
    tmp4 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1207);
    tmp5 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp6 = CodeStubAssembler(state_).LoadReference<Int32T>(CodeStubAssembler::Reference{tmp1, tmp5});
    tmp7 = FromConstexpr_int32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp8 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp6}, TNode<Int32T>{tmp7});
    ca_.Branch(tmp8, &block1, std::vector<compiler::Node*>{}, &block2, std::vector<compiler::Node*>{});
  }

  TNode<Uint32T> tmp9;
  if (block1.is_used()) {
    ca_.Bind(&block1);
    tmp9 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    CodeStubAssembler(state_).Return(tmp9);
  }

  if (block2.is_used()) {
    ca_.Bind(&block2);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1208);
    ca_.Goto(&block5, tmp3, tmp4);
  }

  TNode<Uint32T> phi_bb5_3;
  TNode<Uint32T> phi_bb5_4;
  TNode<BoolT> tmp10;
  if (block5.is_used()) {
    ca_.Bind(&block5, &phi_bb5_3, &phi_bb5_4);
    tmp10 = CodeStubAssembler(state_).Uint32LessThan(TNode<Uint32T>{phi_bb5_4}, TNode<Uint32T>{parameter1});
    ca_.Branch(tmp10, &block3, std::vector<compiler::Node*>{phi_bb5_3, phi_bb5_4}, &block4, std::vector<compiler::Node*>{phi_bb5_3, phi_bb5_4});
  }

  TNode<Uint32T> phi_bb3_3;
  TNode<Uint32T> phi_bb3_4;
  TNode<Uint32T> tmp11;
  TNode<BoolT> tmp12;
  if (block3.is_used()) {
    ca_.Bind(&block3, &phi_bb3_3, &phi_bb3_4);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1209);
    tmp11 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp12 = CodeStubAssembler(state_).Word32Equal(TNode<Uint32T>{phi_bb3_3}, TNode<Uint32T>{tmp11});
    ca_.Branch(tmp12, &block6, std::vector<compiler::Node*>{phi_bb3_3, phi_bb3_4}, &block7, std::vector<compiler::Node*>{phi_bb3_3, phi_bb3_4});
  }

  TNode<Uint32T> phi_bb6_3;
  TNode<Uint32T> phi_bb6_4;
  if (block6.is_used()) {
    ca_.Bind(&block6, &phi_bb6_3, &phi_bb6_4);
    ca_.Goto(&block4, phi_bb6_3, phi_bb6_4);
  }

  TNode<Uint32T> phi_bb7_3;
  TNode<Uint32T> phi_bb7_4;
  TNode<Uint32T> tmp13;
  TNode<Uint32T> tmp14;
  TNode<Uint32T> tmp15;
  TNode<BoolT> tmp16;
  if (block7.is_used()) {
    ca_.Bind(&block7, &phi_bb7_3, &phi_bb7_4);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1210);
    tmp13 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp14 = CodeStubAssembler(state_).Uint32Add(TNode<Uint32T>{phi_bb7_4}, TNode<Uint32T>{tmp13});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1211);
    tmp15 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x2ull));
    tmp16 = CodeStubAssembler(state_).Uint32GreaterThanOrEqual(TNode<Uint32T>{phi_bb7_3}, TNode<Uint32T>{tmp15});
    ca_.Branch(tmp16, &block10, std::vector<compiler::Node*>{phi_bb7_3}, &block11, std::vector<compiler::Node*>{phi_bb7_3});
  }

  TNode<Uint32T> phi_bb10_3;
  TNode<Uint32T> tmp17;
  TNode<Uint32T> tmp18;
  TNode<UintPtrT> tmp19;
  TNode<Uint16T> tmp20;
  TNode<BoolT> tmp21;
  if (block10.is_used()) {
    ca_.Bind(&block10, &phi_bb10_3);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1213);
    tmp17 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp18 = CodeStubAssembler(state_).Uint32Sub(TNode<Uint32T>{phi_bb10_3}, TNode<Uint32T>{tmp17});
    tmp19 = Convert_uintptr_uint32_0(state_, TNode<Uint32T>{tmp18});
    tmp20 = CodeStubAssembler(state_).StringCharCodeAt(TNode<String>{tmp1}, TNode<UintPtrT>{tmp19});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1212);
    tmp21 = IsTrailSurrogate_0(state_, TNode<Uint16T>{tmp20});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1211);
    ca_.Goto(&block12, phi_bb10_3, tmp21);
  }

  TNode<Uint32T> phi_bb11_3;
  TNode<BoolT> tmp22;
  if (block11.is_used()) {
    ca_.Bind(&block11, &phi_bb11_3);
    tmp22 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block12, phi_bb11_3, tmp22);
  }

  TNode<Uint32T> phi_bb12_3;
  TNode<BoolT> phi_bb12_6;
  if (block12.is_used()) {
    ca_.Bind(&block12, &phi_bb12_3, &phi_bb12_6);
    ca_.Branch(phi_bb12_6, &block13, std::vector<compiler::Node*>{phi_bb12_3}, &block14, std::vector<compiler::Node*>{phi_bb12_3});
  }

  TNode<Uint32T> phi_bb13_3;
  TNode<Uint32T> tmp23;
  TNode<Uint32T> tmp24;
  TNode<UintPtrT> tmp25;
  TNode<Uint16T> tmp26;
  TNode<BoolT> tmp27;
  if (block13.is_used()) {
    ca_.Bind(&block13, &phi_bb13_3);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1215);
    tmp23 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x2ull));
    tmp24 = CodeStubAssembler(state_).Uint32Sub(TNode<Uint32T>{phi_bb13_3}, TNode<Uint32T>{tmp23});
    tmp25 = Convert_uintptr_uint32_0(state_, TNode<Uint32T>{tmp24});
    tmp26 = CodeStubAssembler(state_).StringCharCodeAt(TNode<String>{tmp1}, TNode<UintPtrT>{tmp25});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1214);
    tmp27 = IsLeadSurrogate_0(state_, TNode<Uint16T>{tmp26});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1211);
    ca_.Goto(&block15, phi_bb13_3, tmp27);
  }

  TNode<Uint32T> phi_bb14_3;
  TNode<BoolT> tmp28;
  if (block14.is_used()) {
    ca_.Bind(&block14, &phi_bb14_3);
    tmp28 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block15, phi_bb14_3, tmp28);
  }

  TNode<Uint32T> phi_bb15_3;
  TNode<BoolT> phi_bb15_6;
  if (block15.is_used()) {
    ca_.Bind(&block15, &phi_bb15_3, &phi_bb15_6);
    ca_.Branch(phi_bb15_6, &block8, std::vector<compiler::Node*>{phi_bb15_3}, &block9, std::vector<compiler::Node*>{phi_bb15_3});
  }

  TNode<Uint32T> phi_bb8_3;
  TNode<Uint32T> tmp29;
  TNode<Uint32T> tmp30;
  if (block8.is_used()) {
    ca_.Bind(&block8, &phi_bb8_3);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1216);
    tmp29 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x2ull));
    tmp30 = CodeStubAssembler(state_).Uint32Sub(TNode<Uint32T>{phi_bb8_3}, TNode<Uint32T>{tmp29});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1211);
    ca_.Goto(&block16, tmp30);
  }

  TNode<Uint32T> phi_bb9_3;
  TNode<Uint32T> tmp31;
  TNode<Uint32T> tmp32;
  if (block9.is_used()) {
    ca_.Bind(&block9, &phi_bb9_3);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1218);
    tmp31 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp32 = CodeStubAssembler(state_).Uint32Sub(TNode<Uint32T>{phi_bb9_3}, TNode<Uint32T>{tmp31});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1211);
    ca_.Goto(&block16, tmp32);
  }

  TNode<Uint32T> phi_bb16_3;
  if (block16.is_used()) {
    ca_.Bind(&block16, &phi_bb16_3);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1208);
    ca_.Goto(&block5, phi_bb16_3, tmp14);
  }

  TNode<Uint32T> phi_bb4_3;
  TNode<Uint32T> phi_bb4_4;
  TNode<IntPtrT> tmp33;
  if (block4.is_used()) {
    ca_.Bind(&block4, &phi_bb4_3, &phi_bb4_4);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1221);
    tmp33 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    CodeStubAssembler(state_).StoreReference<Uint32T>(CodeStubAssembler::Reference{parameter0, tmp33}, phi_bb4_3);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1222);
    CodeStubAssembler(state_).Return(phi_bb4_4);
  }
}

TF_BUILTIN(WasmStringViewIterSlice, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<WasmStringViewIter> parameter0 = UncheckedParameter<WasmStringViewIter>(Descriptor::kView);
  USE(parameter0);
  TNode<Uint32T> parameter1 = UncheckedParameter<Uint32T>(Descriptor::kCodepoints);
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint32T, Uint32T> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint32T, Uint32T> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint32T, Uint32T> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint32T, Uint32T> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint32T> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint32T> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint32T, BoolT> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint32T> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint32T> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint32T, BoolT> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint32T> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint32T> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint32T> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint32T, Uint32T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint32T, Uint32T> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint32T, Uint32T> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint32T, Uint32T, String> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<String> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<Uint32T> tmp3;
  TNode<IntPtrT> tmp4;
  TNode<Uint32T> tmp5;
  TNode<Uint32T> tmp6;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1226);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp1 = CodeStubAssembler(state_).LoadReference<String>(CodeStubAssembler::Reference{parameter0, tmp0});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1227);
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp3 = CodeStubAssembler(state_).LoadReference<Uint32T>(CodeStubAssembler::Reference{parameter0, tmp2});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1228);
    tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp5 = CodeStubAssembler(state_).LoadReference<Uint32T>(CodeStubAssembler::Reference{parameter0, tmp4});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1229);
    tmp6 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1230);
    ca_.Goto(&block3, tmp5, tmp6);
  }

  TNode<Uint32T> phi_bb3_4;
  TNode<Uint32T> phi_bb3_5;
  TNode<BoolT> tmp7;
  if (block3.is_used()) {
    ca_.Bind(&block3, &phi_bb3_4, &phi_bb3_5);
    tmp7 = CodeStubAssembler(state_).Uint32LessThan(TNode<Uint32T>{phi_bb3_5}, TNode<Uint32T>{parameter1});
    ca_.Branch(tmp7, &block1, std::vector<compiler::Node*>{phi_bb3_4, phi_bb3_5}, &block2, std::vector<compiler::Node*>{phi_bb3_4, phi_bb3_5});
  }

  TNode<Uint32T> phi_bb1_4;
  TNode<Uint32T> phi_bb1_5;
  TNode<IntPtrT> tmp8;
  TNode<Int32T> tmp9;
  TNode<Uint32T> tmp10;
  TNode<BoolT> tmp11;
  if (block1.is_used()) {
    ca_.Bind(&block1, &phi_bb1_4, &phi_bb1_5);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1231);
    tmp8 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp9 = CodeStubAssembler(state_).LoadReference<Int32T>(CodeStubAssembler::Reference{tmp1, tmp8});
    tmp10 = CodeStubAssembler(state_).Unsigned(TNode<Int32T>{tmp9});
    tmp11 = CodeStubAssembler(state_).Word32Equal(TNode<Uint32T>{phi_bb1_4}, TNode<Uint32T>{tmp10});
    ca_.Branch(tmp11, &block4, std::vector<compiler::Node*>{phi_bb1_4, phi_bb1_5}, &block5, std::vector<compiler::Node*>{phi_bb1_4, phi_bb1_5});
  }

  TNode<Uint32T> phi_bb4_4;
  TNode<Uint32T> phi_bb4_5;
  if (block4.is_used()) {
    ca_.Bind(&block4, &phi_bb4_4, &phi_bb4_5);
    ca_.Goto(&block2, phi_bb4_4, phi_bb4_5);
  }

  TNode<Uint32T> phi_bb5_4;
  TNode<Uint32T> phi_bb5_5;
  TNode<Uint32T> tmp12;
  TNode<Uint32T> tmp13;
  TNode<Uint32T> tmp14;
  TNode<Uint32T> tmp15;
  TNode<IntPtrT> tmp16;
  TNode<Int32T> tmp17;
  TNode<Uint32T> tmp18;
  TNode<BoolT> tmp19;
  if (block5.is_used()) {
    ca_.Bind(&block5, &phi_bb5_4, &phi_bb5_5);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1232);
    tmp12 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp13 = CodeStubAssembler(state_).Uint32Add(TNode<Uint32T>{phi_bb5_5}, TNode<Uint32T>{tmp12});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1233);
    tmp14 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp15 = CodeStubAssembler(state_).Uint32Add(TNode<Uint32T>{phi_bb5_4}, TNode<Uint32T>{tmp14});
    tmp16 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp17 = CodeStubAssembler(state_).LoadReference<Int32T>(CodeStubAssembler::Reference{tmp1, tmp16});
    tmp18 = CodeStubAssembler(state_).Unsigned(TNode<Int32T>{tmp17});
    tmp19 = CodeStubAssembler(state_).Uint32LessThan(TNode<Uint32T>{tmp15}, TNode<Uint32T>{tmp18});
    ca_.Branch(tmp19, &block8, std::vector<compiler::Node*>{phi_bb5_4}, &block9, std::vector<compiler::Node*>{phi_bb5_4});
  }

  TNode<Uint32T> phi_bb8_4;
  TNode<UintPtrT> tmp20;
  TNode<Uint16T> tmp21;
  TNode<BoolT> tmp22;
  if (block8.is_used()) {
    ca_.Bind(&block8, &phi_bb8_4);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1234);
    tmp20 = Convert_uintptr_uint32_0(state_, TNode<Uint32T>{phi_bb8_4});
    tmp21 = CodeStubAssembler(state_).StringCharCodeAt(TNode<String>{tmp1}, TNode<UintPtrT>{tmp20});
    tmp22 = IsLeadSurrogate_0(state_, TNode<Uint16T>{tmp21});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1233);
    ca_.Goto(&block10, phi_bb8_4, tmp22);
  }

  TNode<Uint32T> phi_bb9_4;
  TNode<BoolT> tmp23;
  if (block9.is_used()) {
    ca_.Bind(&block9, &phi_bb9_4);
    tmp23 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block10, phi_bb9_4, tmp23);
  }

  TNode<Uint32T> phi_bb10_4;
  TNode<BoolT> phi_bb10_7;
  if (block10.is_used()) {
    ca_.Bind(&block10, &phi_bb10_4, &phi_bb10_7);
    ca_.Branch(phi_bb10_7, &block11, std::vector<compiler::Node*>{phi_bb10_4}, &block12, std::vector<compiler::Node*>{phi_bb10_4});
  }

  TNode<Uint32T> phi_bb11_4;
  TNode<Uint32T> tmp24;
  TNode<Uint32T> tmp25;
  TNode<UintPtrT> tmp26;
  TNode<Uint16T> tmp27;
  TNode<BoolT> tmp28;
  if (block11.is_used()) {
    ca_.Bind(&block11, &phi_bb11_4);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1235);
    tmp24 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp25 = CodeStubAssembler(state_).Uint32Add(TNode<Uint32T>{phi_bb11_4}, TNode<Uint32T>{tmp24});
    tmp26 = Convert_uintptr_uint32_0(state_, TNode<Uint32T>{tmp25});
    tmp27 = CodeStubAssembler(state_).StringCharCodeAt(TNode<String>{tmp1}, TNode<UintPtrT>{tmp26});
    tmp28 = IsTrailSurrogate_0(state_, TNode<Uint16T>{tmp27});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1233);
    ca_.Goto(&block13, phi_bb11_4, tmp28);
  }

  TNode<Uint32T> phi_bb12_4;
  TNode<BoolT> tmp29;
  if (block12.is_used()) {
    ca_.Bind(&block12, &phi_bb12_4);
    tmp29 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block13, phi_bb12_4, tmp29);
  }

  TNode<Uint32T> phi_bb13_4;
  TNode<BoolT> phi_bb13_7;
  if (block13.is_used()) {
    ca_.Bind(&block13, &phi_bb13_4, &phi_bb13_7);
    ca_.Branch(phi_bb13_7, &block6, std::vector<compiler::Node*>{phi_bb13_4}, &block7, std::vector<compiler::Node*>{phi_bb13_4});
  }

  TNode<Uint32T> phi_bb6_4;
  TNode<Uint32T> tmp30;
  TNode<Uint32T> tmp31;
  if (block6.is_used()) {
    ca_.Bind(&block6, &phi_bb6_4);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1236);
    tmp30 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x2ull));
    tmp31 = CodeStubAssembler(state_).Uint32Add(TNode<Uint32T>{phi_bb6_4}, TNode<Uint32T>{tmp30});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1233);
    ca_.Goto(&block14, tmp31);
  }

  TNode<Uint32T> phi_bb7_4;
  TNode<Uint32T> tmp32;
  TNode<Uint32T> tmp33;
  if (block7.is_used()) {
    ca_.Bind(&block7, &phi_bb7_4);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1238);
    tmp32 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp33 = CodeStubAssembler(state_).Uint32Add(TNode<Uint32T>{phi_bb7_4}, TNode<Uint32T>{tmp32});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1233);
    ca_.Goto(&block14, tmp33);
  }

  TNode<Uint32T> phi_bb14_4;
  if (block14.is_used()) {
    ca_.Bind(&block14, &phi_bb14_4);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1230);
    ca_.Goto(&block3, phi_bb14_4, tmp13);
  }

  TNode<Uint32T> phi_bb2_4;
  TNode<Uint32T> phi_bb2_5;
  TNode<BoolT> tmp34;
  if (block2.is_used()) {
    ca_.Bind(&block2, &phi_bb2_4, &phi_bb2_5);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1241);
    tmp34 = CodeStubAssembler(state_).Word32Equal(TNode<Uint32T>{tmp3}, TNode<Uint32T>{phi_bb2_4});
    ca_.Branch(tmp34, &block15, std::vector<compiler::Node*>{phi_bb2_4, phi_bb2_5}, &block16, std::vector<compiler::Node*>{phi_bb2_4, phi_bb2_5});
  }

  TNode<Uint32T> phi_bb15_4;
  TNode<Uint32T> phi_bb15_5;
  TNode<String> tmp35;
  if (block15.is_used()) {
    ca_.Bind(&block15, &phi_bb15_4, &phi_bb15_5);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1242);
    tmp35 = kEmptyString_0(state_);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1241);
    ca_.Goto(&block17, phi_bb15_4, phi_bb15_5, tmp35);
  }

  TNode<Uint32T> phi_bb16_4;
  TNode<Uint32T> phi_bb16_5;
  TNode<UintPtrT> tmp36;
  TNode<UintPtrT> tmp37;
  TNode<String> tmp38;
  if (block16.is_used()) {
    ca_.Bind(&block16, &phi_bb16_4, &phi_bb16_5);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1243);
    tmp36 = Convert_uintptr_uint32_0(state_, TNode<Uint32T>{tmp3});
    tmp37 = Convert_uintptr_uint32_0(state_, TNode<Uint32T>{phi_bb16_4});
    tmp38 = StringBuiltinsAssembler(state_).SubString(TNode<String>{tmp1}, TNode<UintPtrT>{tmp36}, TNode<UintPtrT>{tmp37});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1241);
    ca_.Goto(&block17, phi_bb16_4, phi_bb16_5, tmp38);
  }

  TNode<Uint32T> phi_bb17_4;
  TNode<Uint32T> phi_bb17_5;
  TNode<String> phi_bb17_6;
  if (block17.is_used()) {
    ca_.Bind(&block17, &phi_bb17_4, &phi_bb17_5, &phi_bb17_6);
    CodeStubAssembler(state_).Return(phi_bb17_6);
  }
}

TF_BUILTIN(WasmExternInternalize, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Object> parameter0 = UncheckedParameter<Object>(Descriptor::kExternObject);
  USE(parameter0);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<WasmInstanceObject> tmp0;
  TNode<NativeContext> tmp1;
  TNode<Smi> tmp2;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1247);
    tmp0 = WasmBuiltinsAssembler(state_).LoadInstanceFromFrame();
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1248);
    tmp1 = WasmBuiltinsAssembler(state_).LoadContextFromInstance(TNode<WasmInstanceObject>{tmp0});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1251);
    tmp2 = CodeStubAssembler(state_).SmiConstant(wasm::kWasmAnyRef.raw_bit_field());
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 1250);
    CodeStubAssembler(state_).TailCallRuntime(Runtime::kWasmJSToWasmObject, tmp1, parameter0, tmp2);
  }
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm.tq?l=373&c=7
TNode<IntPtrT> Convert_intptr_constexpr_int32_0(compiler::CodeAssemblerState* state_, int32_t p_i) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/convert.tq", 187);
    tmp0 = FromConstexpr_intptr_constexpr_int32_0(state_, p_i);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 373);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<IntPtrT>{tmp0};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm.tq?l=584&c=14
TNode<BoolT> Is_WasmInternalFunction_Object_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<WasmInternalFunction> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 808);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = Cast_WasmInternalFunction_1(state_, TNode<Context>{p_context}, TNode<Object>{p_o}, &label1);
    ca_.Goto(&block4);
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block5);
    }
  }

  TNode<BoolT> tmp2;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    tmp2 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp2);
  }

  TNode<BoolT> tmp3;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 809);
    tmp3 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block1, tmp3);
  }

  TNode<BoolT> phi_bb1_2;
  if (block1.is_used()) {
    ca_.Bind(&block1, &phi_bb1_2);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 584);
    ca_.Goto(&block6);
  }

    ca_.Bind(&block6);
  return TNode<BoolT>{phi_bb1_2};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm.tq?l=719&c=10
TNode<WasmTypeInfo> UnsafeCast_WasmTypeInfo_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<BoolT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 814);
    tmp0 = Is_WasmTypeInfo_Object_0(state_, TNode<Context>{p_context}, TNode<Object>{p_o});
    ca_.Branch(tmp0, &block2, std::vector<compiler::Node*>{}, &block3, std::vector<compiler::Node*>{});
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/cast.tq", 814});
      CodeStubAssembler(state_).FailAssert("Torque assert 'Is<A>(o)' failed", pos_stack);
    }
  }

  TNode<WasmTypeInfo> tmp1;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 815);
    tmp1 = TORQUE_CAST(TNode<Object>{p_o});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 719);
    ca_.Goto(&block4);
  }

    ca_.Bind(&block4);
  return TNode<WasmTypeInfo>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm.tq?l=736&c=7
TorqueStructReference_int32_0 NewOffHeapReference_int32_0(compiler::CodeAssemblerState* state_, TNode<RawPtrT> p_ptr) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<TaggedIndex> tmp0;
  TNode<RawPtrT> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<IntPtrT> tmp3;
  TNode<IntPtrT> tmp4;
  TNode<Object> tmp5;
  TNode<IntPtrT> tmp6;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 71);
    tmp0 = kZeroBitPattern_0(state_);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 72);
    tmp1 = Convert_RawPtr_RawPtr_int32_0(state_, TNode<RawPtrT>{p_ptr});
    tmp2 = Convert_intptr_RawPtr_0(state_, TNode<RawPtrT>{tmp1});
    tmp3 = FromConstexpr_intptr_constexpr_int31_0(state_, kHeapObjectTag);
    tmp4 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp2}, TNode<IntPtrT>{tmp3});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 70);
    std::tie(tmp5, tmp6) = (TorqueStructReference_int32_0{TNode<Object>{tmp0}, TNode<IntPtrT>{tmp4}, TorqueStructUnsafe_0{}}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 736);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TorqueStructReference_int32_0{TNode<Object>{tmp5}, TNode<IntPtrT>{tmp6}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm.tq?l=746&c=19
TNode<WasmArray> Cast_WasmArray_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<HeapObject> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 162);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = CodeStubAssembler(state_).TaggedToHeapObject(TNode<Object>{p_o}, &label1);
    ca_.Goto(&block3);
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block4);
    }
  }

  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.Goto(&block1);
  }

  TNode<WasmArray> tmp2;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    compiler::CodeAssemblerLabel label3(&ca_);
    tmp2 = Cast_WasmArray_0(state_, TNode<HeapObject>{tmp0}, &label3);
    ca_.Goto(&block5);
    if (label3.is_used()) {
      ca_.Bind(&label3);
      ca_.Goto(&block6);
    }
  }

  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.Goto(&block1);
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 746);
    ca_.Goto(&block7);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_CastError);
  }

    ca_.Bind(&block7);
  return TNode<WasmArray>{tmp2};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm.tq?l=753&c=26
TorqueStructSlice_char16_ConstReference_char16_0 NewConstSlice_char16_0(compiler::CodeAssemblerState* state_, TNode<Object> p_object, TNode<IntPtrT> p_offset, TNode<IntPtrT> p_length) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Object> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<IntPtrT> tmp2;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 179);
    std::tie(tmp0, tmp1, tmp2) = (TorqueStructSlice_char16_ConstReference_char16_0{TNode<Object>{p_object}, TNode<IntPtrT>{p_offset}, TNode<IntPtrT>{p_length}, TorqueStructUnsafe_0{}}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 753);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TorqueStructSlice_char16_ConstReference_char16_0{TNode<Object>{tmp0}, TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp2}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm.tq?l=756&c=12
TNode<String> AllocateSeqTwoByteString_SliceIterator_char16_ConstReference_char16_0(compiler::CodeAssemblerState* state_, TNode<Uint32T> p_length, TorqueStructSliceIterator_char16_ConstReference_char16_0 p_content) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<String> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Uint32T> tmp0;
  TNode<BoolT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/objects/string.tq", 171);
    tmp0 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp1 = CodeStubAssembler(state_).Word32Equal(TNode<Uint32T>{p_length}, TNode<Uint32T>{tmp0});
    ca_.Branch(tmp1, &block2, std::vector<compiler::Node*>{}, &block3, std::vector<compiler::Node*>{});
  }

  TNode<String> tmp2;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    tmp2 = kEmptyString_0(state_);
    ca_.Goto(&block1, tmp2);
  }

  TNode<SeqTwoByteString> tmp3;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    ca_.SetSourcePosition("../../../src/objects/string.tq", 172);
    tmp3 = AllocateNonEmptySeqTwoByteString_SliceIterator_char16_ConstReference_char16_0(state_, TNode<Uint32T>{p_length}, TorqueStructSliceIterator_char16_ConstReference_char16_0{TNode<Object>{p_content.object}, TNode<IntPtrT>{p_content.start}, TNode<IntPtrT>{p_content.end}, TorqueStructUnsafe_0{}});
    ca_.Goto(&block1, tmp3);
  }

  TNode<String> phi_bb1_4;
  if (block1.is_used()) {
    ca_.Bind(&block1, &phi_bb1_4);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 756);
    ca_.Goto(&block4);
  }

    ca_.Bind(&block4);
  return TNode<String>{phi_bb1_4};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm.tq?l=781&c=26
TorqueStructSlice_char16_MutableReference_char16_0 NewMutableSlice_char16_0(compiler::CodeAssemblerState* state_, TNode<Object> p_object, TNode<IntPtrT> p_offset, TNode<IntPtrT> p_length) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Object> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<IntPtrT> tmp2;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 168);
    std::tie(tmp0, tmp1, tmp2) = (TorqueStructSlice_char16_MutableReference_char16_0{TNode<Object>{p_object}, TNode<IntPtrT>{p_offset}, TNode<IntPtrT>{p_length}, TorqueStructUnsafe_0{}}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 781);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TorqueStructSlice_char16_MutableReference_char16_0{TNode<Object>{tmp0}, TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp2}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm.tq?l=790&c=39
TNode<Uint16T> Convert_uint16_char8_0(compiler::CodeAssemblerState* state_, TNode<Uint8T> p_i) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 790);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Uint16T>{p_i};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm.tq?l=921&c=12
TNode<SeqOneByteString> AllocateNonEmptySeqOneByteString_TwoByteToOneByteIterator_0(compiler::CodeAssemblerState* state_, TNode<Uint32T> p_length, TorqueStructTwoByteToOneByteIterator_0 p_content) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Uint32T> tmp0;
  TNode<BoolT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/objects/string.tq", 136);
    tmp0 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp1 = CodeStubAssembler(state_).Word32NotEqual(TNode<Uint32T>{p_length}, TNode<Uint32T>{tmp0});
    ca_.Branch(tmp1, &block4, std::vector<compiler::Node*>{}, &block5, std::vector<compiler::Node*>{});
  }

  TNode<Uint32T> tmp2;
  TNode<BoolT> tmp3;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    tmp2 = FromConstexpr_uint32_constexpr_int31_0(state_, String::kMaxLength);
    tmp3 = CodeStubAssembler(state_).Uint32LessThanOrEqual(TNode<Uint32T>{p_length}, TNode<Uint32T>{tmp2});
    ca_.Goto(&block6, tmp3);
  }

  TNode<BoolT> tmp4;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    tmp4 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block6, tmp4);
  }

  TNode<BoolT> phi_bb6_5;
  if (block6.is_used()) {
    ca_.Bind(&block6, &phi_bb6_5);
    ca_.Branch(phi_bb6_5, &block2, std::vector<compiler::Node*>{}, &block3, std::vector<compiler::Node*>{});
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/objects/string.tq", 136});
      CodeStubAssembler(state_).FailAssert("Torque assert 'length != 0 && length <= kStringMaxLength' failed", pos_stack);
    }
  }

  TNode<Map> tmp5;
  TNode<Uint32T> tmp6;
  TNode<Int32T> tmp7;
  TNode<IntPtrT> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<IntPtrT> tmp10;
  TNode<IntPtrT> tmp11;
  TNode<BoolT> tmp12;
  TNode<BoolT> tmp13;
  TNode<HeapObject> tmp14;
  TNode<IntPtrT> tmp15;
  TNode<IntPtrT> tmp16;
  TNode<IntPtrT> tmp17;
  TNode<IntPtrT> tmp18;
  TNode<SeqOneByteString> tmp19;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    ca_.SetSourcePosition("../../../src/objects/string.tq", 138);
    tmp5 = kOneByteStringMap_0(state_);
    ca_.SetSourcePosition("../../../src/objects/string.tq", 139);
    tmp6 = kNameEmptyHashField_0(state_);
    ca_.SetSourcePosition("../../../src/objects/string.tq", 140);
    tmp7 = CodeStubAssembler(state_).Signed(TNode<Uint32T>{p_length});
    ca_.SetSourcePosition("../../../src/objects/string.tq", 109);
    tmp8 = Convert_intptr_int32_0(state_, TNode<Int32T>{tmp7});
    ca_.SetSourcePosition("../../../src/objects/string.tq", 137);
    tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp10 = AddIndexedFieldSizeToObjectSize_0(state_, TNode<IntPtrT>{tmp9}, TNode<IntPtrT>{tmp8}, kUInt8Size);
    tmp11 = AlignTagged_0(state_, TNode<IntPtrT>{tmp10});
    tmp12 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    tmp13 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    tmp14 = AllocateFromNew_0(state_, TNode<IntPtrT>{tmp11}, TNode<Map>{tmp5}, TNode<BoolT>{tmp12}, TNode<BoolT>{tmp13});
    tmp15 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    CodeStubAssembler(state_).StoreReference<Map>(CodeStubAssembler::Reference{tmp14, tmp15}, tmp5);
    tmp16 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    CodeStubAssembler(state_).StoreReference<Uint32T>(CodeStubAssembler::Reference{tmp14, tmp16}, tmp6);
    tmp17 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    CodeStubAssembler(state_).StoreReference<Int32T>(CodeStubAssembler::Reference{tmp14, tmp17}, tmp7);
    tmp18 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    InitializeFieldsFromIterator_char8_TwoByteToOneByteIterator_0(state_, TorqueStructSlice_char8_MutableReference_char8_0{TNode<Object>{tmp14}, TNode<IntPtrT>{tmp18}, TNode<IntPtrT>{tmp8}, TorqueStructUnsafe_0{}}, TorqueStructTwoByteToOneByteIterator_0{TNode<WasmArray>{p_content.array}, TNode<IntPtrT>{p_content.offset}, TNode<IntPtrT>{p_content.end_offset}});
    tmp19 = TORQUE_CAST(TNode<HeapObject>{tmp14});
    ca_.SetSourcePosition("../../../src/builtins/wasm.tq", 921);
    ca_.Goto(&block7);
  }

    ca_.Bind(&block7);
  return TNode<SeqOneByteString>{tmp19};
}

} // namespace internal
} // namespace v8
