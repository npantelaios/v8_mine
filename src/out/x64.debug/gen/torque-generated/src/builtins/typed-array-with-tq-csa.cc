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
#include "torque-generated/src/builtins/typed-array-with-tq-csa.h"
#include "torque-generated/src/builtins/base-tq-csa.h"
#include "torque-generated/src/builtins/convert-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-createtypedarray-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-every-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-with-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-tq-csa.h"
#include "torque-generated/src/objects/js-array-buffer-tq-csa.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/typed-array-with.tq?l=6&c=1
const char* kBuiltinNameWith_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
  return "%TypedArray%.prototype.with";}

TF_BUILTIN(TypedArrayPrototypeWith, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kReceiver);
  USE(parameter1);
  TNode<Object> parameter2 = UncheckedParameter<Object>(Descriptor::kIndex);
  USE(parameter2);
  TNode<Object> parameter3 = UncheckedParameter<Object>(Descriptor::kValueArg);
  USE(parameter3);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block25(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block26(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block27(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block28(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block29(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block30(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block34(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block35(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block37(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block36(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<UintPtrT> block40(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<UintPtrT> block38(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<UintPtrT, UintPtrT, UintPtrT> block44(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<UintPtrT, UintPtrT, UintPtrT> block45(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<UintPtrT, UintPtrT, UintPtrT> block47(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<UintPtrT, UintPtrT, UintPtrT> block46(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<UintPtrT> block39(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    ca_.Goto(&block0);

  TNode<JSTypedArray> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-with.tq", 17);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = Cast_JSTypedArray_1(state_, TNode<Context>{parameter0}, TNode<Object>{parameter1}, &label1);
    ca_.Goto(&block7);
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block8);
    }
  }

  if (block8.is_used()) {
    ca_.Bind(&block8);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-with.tq", 88);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{parameter0}, MessageTemplate::kNotTypedArray, kBuiltinNameWith_0(state_));
  }

  TNode<JSTypedArray> tmp2;
  TNode<UintPtrT> tmp3;
  if (block7.is_used()) {
    ca_.Bind(&block7);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-with.tq", 18);
    compiler::CodeAssemblerLabel label4(&ca_);
    std::tie(tmp2, tmp3) = EnsureAttachedAndReadLength_0(state_, TNode<JSTypedArray>{tmp0}, &label4).Flatten();
    ca_.Goto(&block9);
    if (label4.is_used()) {
      ca_.Bind(&label4);
      ca_.Goto(&block10);
    }
  }

  if (block10.is_used()) {
    ca_.Bind(&block10);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-with.tq", 90);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{parameter0}, MessageTemplate::kDetachedOperation, kBuiltinNameWith_0(state_));
  }

  TNode<Int32T> tmp5;
  TNode<BoolT> tmp6;
  if (block9.is_used()) {
    ca_.Bind(&block9);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-with.tq", 23);
    tmp5 = CodeStubAssembler(state_).LoadElementsKind(TNode<JSTypedArray>{tmp0});
    tmp6 = TypedArrayBuiltinsAssembler(state_).IsBigInt64ElementsKind(TNode<Int32T>{tmp5});
    ca_.Branch(tmp6, &block11, std::vector<compiler::Node*>{}, &block12, std::vector<compiler::Node*>{});
  }

  TNode<BigInt> tmp7;
  if (block11.is_used()) {
    ca_.Bind(&block11);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-with.tq", 25);
    tmp7 = CodeStubAssembler(state_).ToBigInt(TNode<Context>{parameter0}, TNode<Object>{parameter3});
    ca_.SetSourcePosition("../../../src/builtins/typed-array-with.tq", 23);
    ca_.Goto(&block13, tmp7);
  }

  TNode<Number> tmp8;
  if (block12.is_used()) {
    ca_.Bind(&block12);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-with.tq", 28);
    tmp8 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context>{parameter0}, TNode<Object>{parameter3});
    ca_.SetSourcePosition("../../../src/builtins/typed-array-with.tq", 23);
    ca_.Goto(&block13, tmp8);
  }

  TNode<Object> phi_bb13_8;
  TNode<Number> tmp9;
  TNode<UintPtrT> tmp10;
  if (block13.is_used()) {
    ca_.Bind(&block13, &phi_bb13_8);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-with.tq", 32);
    tmp9 = ToInteger_Inline_0(state_, TNode<Context>{parameter0}, TNode<Object>{parameter2});
    ca_.SetSourcePosition("../../../src/builtins/typed-array-with.tq", 36);
    compiler::CodeAssemblerLabel label11(&ca_);
    compiler::CodeAssemblerLabel label12(&ca_);
    tmp10 = ConvertRelativeIndex_1(state_, TNode<Number>{tmp9}, TNode<UintPtrT>{tmp3}, &label11, &label12);
    ca_.Goto(&block14);
    if (label11.is_used()) {
      ca_.Bind(&label11);
      ca_.Goto(&block15);
    }
    if (label12.is_used()) {
      ca_.Bind(&label12);
      ca_.Goto(&block16);
    }
  }

  if (block15.is_used()) {
    ca_.Bind(&block15);
    ca_.Goto(&block6);
  }

  if (block16.is_used()) {
    ca_.Bind(&block16);
    ca_.Goto(&block6);
  }

  TNode<JSTypedArray> tmp13;
  TNode<UintPtrT> tmp14;
  if (block14.is_used()) {
    ca_.Bind(&block14);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-with.tq", 42);
    compiler::CodeAssemblerLabel label15(&ca_);
    std::tie(tmp13, tmp14) = EnsureAttachedAndReadLength_0(state_, TNode<JSTypedArray>{tmp0}, &label15).Flatten();
    ca_.Goto(&block17);
    if (label15.is_used()) {
      ca_.Bind(&label15);
      ca_.Goto(&block18);
    }
  }

  if (block18.is_used()) {
    ca_.Bind(&block18);
    ca_.Goto(&block6);
  }

  TNode<BoolT> tmp16;
  if (block17.is_used()) {
    ca_.Bind(&block17);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-with.tq", 44);
    tmp16 = CodeStubAssembler(state_).UintPtrGreaterThanOrEqual(TNode<UintPtrT>{tmp10}, TNode<UintPtrT>{tmp14});
    ca_.Branch(tmp16, &block19, std::vector<compiler::Node*>{}, &block20, std::vector<compiler::Node*>{});
  }

  if (block19.is_used()) {
    ca_.Bind(&block19);
    ca_.Goto(&block6);
  }

  TNode<JSTypedArray> tmp17;
  TNode<UintPtrT> tmp18;
  TNode<UintPtrT> tmp19;
  TNode<Int32T> tmp20;
  TNode<UintPtrT> tmp21;
  TNode<BoolT> tmp22;
  if (block20.is_used()) {
    ca_.Bind(&block20);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-with.tq", 47);
    tmp17 = TypedArrayCreateSameType_0(state_, TNode<Context>{parameter0}, TNode<JSTypedArray>{tmp0}, TNode<UintPtrT>{tmp3});
    ca_.SetSourcePosition("../../../src/builtins/typed-array-with.tq", 49);
    tmp18 = CodeStubAssembler(state_).UintPtrMin(TNode<UintPtrT>{tmp3}, TNode<UintPtrT>{tmp14});
    ca_.SetSourcePosition("../../../src/builtins/typed-array-with.tq", 52);
    std::tie(tmp19, tmp20) = TypedArrayBuiltinsAssembler(state_).GetTypedArrayElementsInfo(TNode<JSTypedArray>{tmp17}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/typed-array.tq", 28);
    tmp21 = FromConstexpr_uintptr_constexpr_uintptr_0(state_, JSTypedArray::kMaxLength);
    tmp22 = CodeStubAssembler(state_).UintPtrGreaterThan(TNode<UintPtrT>{tmp18}, TNode<UintPtrT>{tmp21});
    ca_.Branch(tmp22, &block24, std::vector<compiler::Node*>{}, &block25, std::vector<compiler::Node*>{});
  }

  if (block24.is_used()) {
    ca_.Bind(&block24);
    ca_.Goto(&block22);
  }

  TNode<UintPtrT> tmp23;
  TNode<UintPtrT> tmp24;
  TNode<BoolT> tmp25;
  if (block25.is_used()) {
    ca_.Bind(&block25);
    ca_.SetSourcePosition("../../../src/builtins/typed-array.tq", 29);
    tmp23 = FromConstexpr_uintptr_constexpr_uintptr_0(state_, JSArrayBuffer::kMaxByteLength);
    tmp24 = CodeStubAssembler(state_).WordShr(TNode<UintPtrT>{tmp23}, TNode<UintPtrT>{tmp19});
    ca_.SetSourcePosition("../../../src/builtins/typed-array.tq", 30);
    tmp25 = CodeStubAssembler(state_).UintPtrGreaterThan(TNode<UintPtrT>{tmp18}, TNode<UintPtrT>{tmp24});
    ca_.Branch(tmp25, &block26, std::vector<compiler::Node*>{}, &block27, std::vector<compiler::Node*>{});
  }

  if (block26.is_used()) {
    ca_.Bind(&block26);
    ca_.Goto(&block22);
  }

  TNode<UintPtrT> tmp26;
  TNode<RawPtrT> tmp27;
  TNode<IntPtrT> tmp28;
  TNode<JSArrayBuffer> tmp29;
  TNode<BoolT> tmp30;
  if (block27.is_used()) {
    ca_.Bind(&block27);
    ca_.SetSourcePosition("../../../src/builtins/typed-array.tq", 31);
    tmp26 = CodeStubAssembler(state_).WordShl(TNode<UintPtrT>{tmp18}, TNode<UintPtrT>{tmp19});
    ca_.SetSourcePosition("../../../src/builtins/typed-array-with.tq", 57);
    tmp27 = CodeStubAssembler(state_).LoadJSTypedArrayDataPtr(TNode<JSTypedArray>{tmp0});
    ca_.SetSourcePosition("../../../src/builtins/typed-array-with.tq", 59);
    tmp28 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp29 = CodeStubAssembler(state_).LoadReference<JSArrayBuffer>(CodeStubAssembler::Reference{tmp0, tmp28});
    tmp30 = IsSharedArrayBuffer_0(state_, TNode<JSArrayBuffer>{tmp29});
    ca_.Branch(tmp30, &block28, std::vector<compiler::Node*>{}, &block29, std::vector<compiler::Node*>{});
  }

  if (block22.is_used()) {
    ca_.Bind(&block22);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-with.tq", 54);
    CodeStubAssembler(state_).PrintErr("halting because of unreachable code at src/builtins/typed-array-with.tq:54:64");
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<RawPtrT> tmp31;
  if (block28.is_used()) {
    ca_.Bind(&block28);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-with.tq", 60);
    tmp31 = CodeStubAssembler(state_).LoadJSTypedArrayDataPtr(TNode<JSTypedArray>{tmp17});
    TypedArrayBuiltinsAssembler(state_).CallCRelaxedMemmove(TNode<RawPtrT>{tmp31}, TNode<RawPtrT>{tmp27}, TNode<UintPtrT>{tmp26});
    ca_.SetSourcePosition("../../../src/builtins/typed-array-with.tq", 59);
    ca_.Goto(&block30);
  }

  TNode<RawPtrT> tmp32;
  if (block29.is_used()) {
    ca_.Bind(&block29);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-with.tq", 62);
    tmp32 = CodeStubAssembler(state_).LoadJSTypedArrayDataPtr(TNode<JSTypedArray>{tmp17});
    TypedArrayBuiltinsAssembler(state_).CallCMemmove(TNode<RawPtrT>{tmp32}, TNode<RawPtrT>{tmp27}, TNode<UintPtrT>{tmp26});
    ca_.SetSourcePosition("../../../src/builtins/typed-array-with.tq", 59);
    ca_.Goto(&block30);
  }

  TNode<Int32T> tmp33;
  TNode<BuiltinPtr> tmp34;
  TNode<BuiltinPtr> tmp35;
  TNode<BuiltinPtr> tmp36;
  TNode<Smi> tmp37;
  TNode<Smi> tmp38;
  TNode<BoolT> tmp39;
  if (block30.is_used()) {
    ca_.Bind(&block30);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-with.tq", 68);
    tmp33 = CodeStubAssembler(state_).LoadElementsKind(TNode<JSTypedArray>{tmp17});
    std::tie(tmp34, tmp35, tmp36) = GetTypedArrayAccessor_0(state_, TNode<Int32T>{tmp33}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/typed-array.tq", 120);
tmp37 = TORQUE_CAST(CodeStubAssembler(state_).CallBuiltinPointer(Builtins::CallableFor(ca_.isolate(),ExampleBuiltinForTorqueFunctionPointerType(3)).descriptor(), tmp36, parameter0, tmp17, tmp10, phi_bb13_8));
    ca_.SetSourcePosition("../../../src/builtins/typed-array.tq", 121);
    tmp38 = kStoreFailureArrayDetached_0(state_);
    tmp39 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp37}, TNode<Smi>{tmp38});
    ca_.Branch(tmp39, &block34, std::vector<compiler::Node*>{}, &block35, std::vector<compiler::Node*>{});
  }

  if (block34.is_used()) {
    ca_.Bind(&block34);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-with.tq", 70);
    CodeStubAssembler(state_).PrintErr("halting because of unreachable code at src/builtins/typed-array-with.tq:70:19");
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<Smi> tmp40;
  TNode<BoolT> tmp41;
  if (block35.is_used()) {
    ca_.Bind(&block35);
    ca_.SetSourcePosition("../../../src/builtins/typed-array.tq", 124);
    tmp40 = kStoreSucceded_0(state_);
    tmp41 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp37}, TNode<Smi>{tmp40});
    ca_.Branch(tmp41, &block36, std::vector<compiler::Node*>{}, &block37, std::vector<compiler::Node*>{});
  }

  if (block37.is_used()) {
    ca_.Bind(&block37);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/typed-array.tq", 124});
      CodeStubAssembler(state_).FailAssert("Torque assert 'result == kStoreSucceded' failed", pos_stack);
    }
  }

  if (block36.is_used()) {
    ca_.Bind(&block36);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-with.tq", 78);
    ca_.Goto(&block40, tmp18);
  }

  TNode<UintPtrT> phi_bb40_20;
  TNode<UintPtrT> tmp42;
  TNode<BoolT> tmp43;
  if (block40.is_used()) {
    ca_.Bind(&block40, &phi_bb40_20);
    tmp42 = CodeStubAssembler(state_).LoadJSTypedArrayLength(TNode<JSTypedArray>{tmp17});
    tmp43 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{phi_bb40_20}, TNode<UintPtrT>{tmp42});
    ca_.Branch(tmp43, &block38, std::vector<compiler::Node*>{phi_bb40_20}, &block39, std::vector<compiler::Node*>{phi_bb40_20});
  }

  TNode<UintPtrT> phi_bb38_20;
  TNode<Oddball> tmp44;
  TNode<Smi> tmp45;
  TNode<Smi> tmp46;
  TNode<BoolT> tmp47;
  if (block38.is_used()) {
    ca_.Bind(&block38, &phi_bb38_20);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-with.tq", 79);
    tmp44 = Undefined_0(state_);
    ca_.SetSourcePosition("../../../src/builtins/typed-array.tq", 120);
tmp45 = TORQUE_CAST(CodeStubAssembler(state_).CallBuiltinPointer(Builtins::CallableFor(ca_.isolate(),ExampleBuiltinForTorqueFunctionPointerType(3)).descriptor(), tmp36, parameter0, tmp17, phi_bb38_20, tmp44));
    ca_.SetSourcePosition("../../../src/builtins/typed-array.tq", 121);
    tmp46 = kStoreFailureArrayDetached_0(state_);
    tmp47 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp45}, TNode<Smi>{tmp46});
    ca_.Branch(tmp47, &block44, std::vector<compiler::Node*>{phi_bb38_20, phi_bb38_20, phi_bb38_20}, &block45, std::vector<compiler::Node*>{phi_bb38_20, phi_bb38_20, phi_bb38_20});
  }

  TNode<UintPtrT> phi_bb44_20;
  TNode<UintPtrT> phi_bb44_26;
  TNode<UintPtrT> phi_bb44_30;
  if (block44.is_used()) {
    ca_.Bind(&block44, &phi_bb44_20, &phi_bb44_26, &phi_bb44_30);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-with.tq", 79);
    CodeStubAssembler(state_).PrintErr("halting because of unreachable code at src/builtins/typed-array-with.tq:79:66");
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<UintPtrT> phi_bb45_20;
  TNode<UintPtrT> phi_bb45_26;
  TNode<UintPtrT> phi_bb45_30;
  TNode<Smi> tmp48;
  TNode<BoolT> tmp49;
  if (block45.is_used()) {
    ca_.Bind(&block45, &phi_bb45_20, &phi_bb45_26, &phi_bb45_30);
    ca_.SetSourcePosition("../../../src/builtins/typed-array.tq", 124);
    tmp48 = kStoreSucceded_0(state_);
    tmp49 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp45}, TNode<Smi>{tmp48});
    ca_.Branch(tmp49, &block46, std::vector<compiler::Node*>{phi_bb45_20, phi_bb45_26, phi_bb45_30}, &block47, std::vector<compiler::Node*>{phi_bb45_20, phi_bb45_26, phi_bb45_30});
  }

  TNode<UintPtrT> phi_bb47_20;
  TNode<UintPtrT> phi_bb47_26;
  TNode<UintPtrT> phi_bb47_30;
  if (block47.is_used()) {
    ca_.Bind(&block47, &phi_bb47_20, &phi_bb47_26, &phi_bb47_30);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/typed-array.tq", 124});
      CodeStubAssembler(state_).FailAssert("Torque assert 'result == kStoreSucceded' failed", pos_stack);
    }
  }

  TNode<UintPtrT> phi_bb46_20;
  TNode<UintPtrT> phi_bb46_26;
  TNode<UintPtrT> phi_bb46_30;
  TNode<UintPtrT> tmp50;
  TNode<UintPtrT> tmp51;
  if (block46.is_used()) {
    ca_.Bind(&block46, &phi_bb46_20, &phi_bb46_26, &phi_bb46_30);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-with.tq", 80);
    tmp50 = FromConstexpr_uintptr_constexpr_int31_0(state_, 1);
    tmp51 = CodeStubAssembler(state_).UintPtrAdd(TNode<UintPtrT>{phi_bb46_20}, TNode<UintPtrT>{tmp50});
    ca_.SetSourcePosition("../../../src/builtins/typed-array-with.tq", 78);
    ca_.Goto(&block40, tmp51);
  }

  TNode<UintPtrT> phi_bb39_20;
  if (block39.is_used()) {
    ca_.Bind(&block39, &phi_bb39_20);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-with.tq", 84);
    CodeStubAssembler(state_).Return(tmp17);
  }

  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-with.tq", 86);
    CodeStubAssembler(state_).ThrowRangeError(TNode<Context>{parameter0}, MessageTemplate::kInvalidTypedArrayIndex);
  }
}

} // namespace internal
} // namespace v8
