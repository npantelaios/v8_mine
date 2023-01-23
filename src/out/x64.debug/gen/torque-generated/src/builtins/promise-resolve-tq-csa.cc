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
#include "torque-generated/src/builtins/promise-resolve-tq-csa.h"
#include "torque-generated/src/builtins/array-every-tq-csa.h"
#include "torque-generated/src/builtins/array-from-tq-csa.h"
#include "torque-generated/src/builtins/array-splice-tq-csa.h"
#include "torque-generated/src/builtins/base-tq-csa.h"
#include "torque-generated/src/builtins/boolean-tq-csa.h"
#include "torque-generated/src/builtins/convert-tq-csa.h"
#include "torque-generated/src/builtins/promise-abstract-operations-tq-csa.h"
#include "torque-generated/src/builtins/promise-all-tq-csa.h"
#include "torque-generated/src/builtins/promise-misc-tq-csa.h"
#include "torque-generated/src/builtins/promise-resolve-tq-csa.h"
#include "torque-generated/src/builtins/promise-jobs-tq-csa.h"
#include "torque-generated/src/builtins/torque-internal-tq-csa.h"
#include "torque-generated/src/objects/contexts-tq-csa.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-resolve.tq?l=14&c=1
TNode<String> kConstructorString_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/promise-resolve.tq", 14);
  TNode<String> tmp0;
    tmp0 = CodeStubAssembler(state_).ConstructorStringConstant();
  return TNode<String>{tmp0};}

TF_BUILTIN(PromiseResolveTrampoline, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kReceiver);
  USE(parameter1);
  TNode<Object> parameter2 = UncheckedParameter<Object>(Descriptor::kValue);
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<JSReceiver> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/promise-resolve.tq", 22);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = Cast_JSReceiver_1(state_, TNode<Context>{parameter0}, TNode<Object>{parameter1}, &label1);
    ca_.Goto(&block3);
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block4);
    }
  }

  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.SetSourcePosition("../../../src/builtins/promise-resolve.tq", 23);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{parameter0}, MessageTemplate::kCalledOnNonObject, "PromiseResolve");
  }

  TNode<Object> tmp2;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    ca_.SetSourcePosition("../../../src/builtins/promise-resolve.tq", 26);
    tmp2 = ca_.CallStub<Object>(Builtins::CallableFor(ca_.isolate(), Builtin::kPromiseResolve), parameter0, tmp0, parameter2);
    CodeStubAssembler(state_).Return(tmp2);
  }
}

TF_BUILTIN(PromiseResolve, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedParameter<Context>(Descriptor::kContext);
  USE(parameter0);
  TNode<JSReceiver> parameter1 = UncheckedParameter<JSReceiver>(Descriptor::kConstructor);
  USE(parameter1);
  TNode<Object> parameter2 = UncheckedParameter<Object>(Descriptor::kValue);
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    ca_.Goto(&block0);

  TNode<NativeContext> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<Object> tmp2;
  TNode<IntPtrT> tmp3;
  TNode<JSFunction> tmp4;
  TNode<JSPromise> tmp5;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/promise-resolve.tq", 32);
    tmp0 = CodeStubAssembler(state_).LoadNativeContext(TNode<Context>{parameter0});
    ca_.SetSourcePosition("../../../src/builtins/promise-resolve.tq", 34);
    tmp1 = PROMISE_FUNCTION_INDEX_0(state_);
    ca_.SetSourcePosition("../../../src/builtins/promise-resolve.tq", 33);
    std::tie(tmp2, tmp3) = NativeContextSlot_JSFunction_0(state_, TNode<NativeContext>{tmp0}, TNode<IntPtrT>{tmp1}).Flatten();
    tmp4 = CodeStubAssembler(state_).LoadReference<JSFunction>(CodeStubAssembler::Reference{tmp2, tmp3});
    ca_.SetSourcePosition("../../../src/builtins/promise-resolve.tq", 37);
    compiler::CodeAssemblerLabel label6(&ca_);
    tmp5 = Cast_JSPromise_1(state_, TNode<Context>{parameter0}, TNode<Object>{parameter2}, &label6);
    ca_.Goto(&block5);
    if (label6.is_used()) {
      ca_.Bind(&label6);
      ca_.Goto(&block6);
    }
  }

  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.Goto(&block2);
  }

  TNode<IntPtrT> tmp7;
  TNode<Object> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<JSObject> tmp10;
  TNode<NativeContext> tmp11;
  TNode<BoolT> tmp12;
  TNode<IntPtrT> tmp13;
  TNode<Map> tmp14;
  TNode<IntPtrT> tmp15;
  TNode<HeapObject> tmp16;
  TNode<BoolT> tmp17;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    ca_.SetSourcePosition("../../../src/builtins/promise-resolve.tq", 45);
    tmp7 = PROMISE_PROTOTYPE_INDEX_0(state_);
    ca_.SetSourcePosition("../../../src/builtins/promise-resolve.tq", 44);
    std::tie(tmp8, tmp9) = NativeContextSlot_JSObject_0(state_, TNode<NativeContext>{tmp0}, TNode<IntPtrT>{tmp7}).Flatten();
    tmp10 = CodeStubAssembler(state_).LoadReference<JSObject>(CodeStubAssembler::Reference{tmp8, tmp9});
    ca_.SetSourcePosition("../../../src/builtins/promise-resolve.tq", 47);
    tmp11 = CodeStubAssembler(state_).LoadNativeContext(TNode<Context>{parameter0});
    tmp12 = CodeStubAssembler(state_).TaggedEqual(TNode<HeapObject>{tmp0}, TNode<HeapObject>{tmp11});
    CodeStubAssembler(state_).StaticAssert(TNode<BoolT>{tmp12}, "static_assert(nativeContext == LoadNativeContext(context)) at https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-resolve.tq?l=47&c=5");
    ca_.SetSourcePosition("../../../src/builtins/promise-resolve.tq", 48);
    tmp13 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp14 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference{tmp5, tmp13});
    tmp15 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    tmp16 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{tmp14, tmp15});
    tmp17 = CodeStubAssembler(state_).TaggedNotEqual(TNode<HeapObject>{tmp16}, TNode<HeapObject>{tmp10});
    ca_.Branch(tmp17, &block7, std::vector<compiler::Node*>{}, &block8, std::vector<compiler::Node*>{});
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    ca_.SetSourcePosition("../../../src/builtins/promise-resolve.tq", 49);
    ca_.Goto(&block4);
  }

  TNode<BoolT> tmp18;
  if (block8.is_used()) {
    ca_.Bind(&block8);
    ca_.SetSourcePosition("../../../src/builtins/promise-resolve.tq", 52);
    tmp18 = CodeStubAssembler(state_).IsPromiseSpeciesProtectorCellInvalid();
    ca_.Branch(tmp18, &block9, std::vector<compiler::Node*>{}, &block10, std::vector<compiler::Node*>{});
  }

  if (block9.is_used()) {
    ca_.Bind(&block9);
    ca_.Goto(&block4);
  }

  TNode<BoolT> tmp19;
  if (block10.is_used()) {
    ca_.Bind(&block10);
    ca_.SetSourcePosition("../../../src/builtins/promise-resolve.tq", 57);
    tmp19 = CodeStubAssembler(state_).TaggedNotEqual(TNode<HeapObject>{tmp4}, TNode<HeapObject>{parameter1});
    ca_.Branch(tmp19, &block11, std::vector<compiler::Node*>{}, &block12, std::vector<compiler::Node*>{});
  }

  if (block11.is_used()) {
    ca_.Bind(&block11);
    ca_.Goto(&block4);
  }

  if (block12.is_used()) {
    ca_.Bind(&block12);
    ca_.SetSourcePosition("../../../src/builtins/promise-resolve.tq", 58);
    CodeStubAssembler(state_).Return(tmp5);
  }

  TNode<String> tmp20;
  TNode<Object> tmp21;
  TNode<BoolT> tmp22;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.SetSourcePosition("../../../src/builtins/promise-resolve.tq", 62);
    tmp20 = kConstructorString_0(state_);
    tmp21 = CodeStubAssembler(state_).GetProperty(TNode<Context>{parameter0}, TNode<Object>{parameter2}, TNode<Object>{tmp20});
    ca_.SetSourcePosition("../../../src/builtins/promise-resolve.tq", 63);
    tmp22 = CodeStubAssembler(state_).TaggedNotEqual(TNode<Object>{tmp21}, TNode<HeapObject>{parameter1});
    ca_.Branch(tmp22, &block13, std::vector<compiler::Node*>{}, &block14, std::vector<compiler::Node*>{});
  }

  if (block13.is_used()) {
    ca_.Bind(&block13);
    ca_.Goto(&block2);
  }

  if (block14.is_used()) {
    ca_.Bind(&block14);
    ca_.SetSourcePosition("../../../src/builtins/promise-resolve.tq", 64);
    CodeStubAssembler(state_).Return(parameter2);
  }

  TNode<BoolT> tmp23;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    ca_.SetSourcePosition("../../../src/builtins/promise-resolve.tq", 66);
    tmp23 = CodeStubAssembler(state_).TaggedEqual(TNode<HeapObject>{tmp4}, TNode<HeapObject>{parameter1});
    ca_.Branch(tmp23, &block15, std::vector<compiler::Node*>{}, &block16, std::vector<compiler::Node*>{});
  }

  TNode<JSPromise> tmp24;
  TNode<Object> tmp25;
  if (block15.is_used()) {
    ca_.Bind(&block15);
    ca_.SetSourcePosition("../../../src/builtins/promise-resolve.tq", 69);
    tmp24 = NewJSPromise_1(state_, TNode<Context>{parameter0});
    ca_.SetSourcePosition("../../../src/builtins/promise-resolve.tq", 70);
    tmp25 = ca_.CallStub<Object>(Builtins::CallableFor(ca_.isolate(), Builtin::kResolvePromise), parameter0, tmp24, parameter2);
    ca_.SetSourcePosition("../../../src/builtins/promise-resolve.tq", 71);
    CodeStubAssembler(state_).Return(tmp24);
  }

  TNode<Oddball> tmp26;
  TNode<PromiseCapability> tmp27;
  TNode<IntPtrT> tmp28;
  TNode<Object> tmp29;
  TNode<JSReceiver> tmp30;
  TNode<Oddball> tmp31;
  TNode<Object> tmp32;
  TNode<IntPtrT> tmp33;
  TNode<HeapObject> tmp34;
  if (block16.is_used()) {
    ca_.Bind(&block16);
    ca_.SetSourcePosition("../../../src/builtins/promise-resolve.tq", 74);
    tmp26 = True_0(state_);
    tmp27 = ca_.CallStub<PromiseCapability>(Builtins::CallableFor(ca_.isolate(), Builtin::kNewPromiseCapability), parameter0, parameter1, tmp26);
    ca_.SetSourcePosition("../../../src/builtins/promise-resolve.tq", 75);
    tmp28 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp29 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp27, tmp28});
    tmp30 = UnsafeCast_Callable_0(state_, TNode<Context>{parameter0}, TNode<Object>{tmp29});
    ca_.SetSourcePosition("../../../src/builtins/promise-resolve.tq", 76);
    tmp31 = Undefined_0(state_);
    tmp32 = CodeStubAssembler(state_).Call(TNode<Context>{parameter0}, TNode<Object>{tmp30}, TNode<Object>{tmp31}, TNode<Object>{parameter2});
    ca_.SetSourcePosition("../../../src/builtins/promise-resolve.tq", 77);
    tmp33 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp34 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{tmp27, tmp33});
    CodeStubAssembler(state_).Return(tmp34);
  }
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-resolve.tq?l=88&c=1
TNode<String> kThenString_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/promise-resolve.tq", 88);
  TNode<String> tmp0;
    tmp0 = CodeStubAssembler(state_).ThenStringConstant();
  return TNode<String>{tmp0};}

TF_BUILTIN(ResolvePromise, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedParameter<Context>(Descriptor::kContext);
  USE(parameter0);
  TNode<JSPromise> parameter1 = UncheckedParameter<JSPromise>(Descriptor::kPromise);
  USE(parameter1);
  TNode<Object> parameter2 = UncheckedParameter<Object>(Descriptor::kResolution);
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block21(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block23(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block25(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block27(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block28(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block31(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block32(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block33(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<BoolT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/promise-resolve.tq", 102);
    tmp0 = PromiseBuiltinsAssembler(state_).IsIsolatePromiseHookEnabledOrDebugIsActiveOrHasAsyncEventDelegate();
    ca_.Branch(tmp0, &block3, std::vector<compiler::Node*>{}, &block4, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp1;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    tmp1 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block5, tmp1);
  }

  TNode<BoolT> tmp2;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.SetSourcePosition("../../../src/builtins/promise-resolve.tq", 103);
    tmp2 = CodeStubAssembler(state_).TaggedEqual(TNode<HeapObject>{parameter1}, TNode<Object>{parameter2});
    ca_.SetSourcePosition("../../../src/builtins/promise-resolve.tq", 102);
    ca_.Goto(&block5, tmp2);
  }

  TNode<BoolT> phi_bb5_4;
  if (block5.is_used()) {
    ca_.Bind(&block5, &phi_bb5_4);
    ca_.Branch(phi_bb5_4, &block1, std::vector<compiler::Node*>{}, &block2, std::vector<compiler::Node*>{});
  }

  TNode<Object> tmp3;
  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.SetSourcePosition("../../../src/builtins/promise-resolve.tq", 105);
    tmp3 = CodeStubAssembler(state_).CallRuntime(Runtime::kResolvePromise, parameter0, parameter1, parameter2); 
    CodeStubAssembler(state_).Return(tmp3);
  }

  TNode<Oddball> tmp4;
  TNode<BoolT> tmp5;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    ca_.SetSourcePosition("../../../src/builtins/promise-resolve.tq", 108);
    tmp4 = Undefined_0(state_);
    ca_.SetSourcePosition("../../../src/builtins/promise-resolve.tq", 112);
    tmp5 = CodeStubAssembler(state_).TaggedIsSmi(TNode<Object>{parameter2});
    ca_.Branch(tmp5, &block10, std::vector<compiler::Node*>{}, &block11, std::vector<compiler::Node*>{});
  }

  TNode<Oddball> tmp6;
  if (block10.is_used()) {
    ca_.Bind(&block10);
    ca_.SetSourcePosition("../../../src/builtins/promise-resolve.tq", 113);
    tmp6 = ca_.CallStub<Oddball>(Builtins::CallableFor(ca_.isolate(), Builtin::kFulfillPromise), parameter0, parameter1, parameter2);
    CodeStubAssembler(state_).Return(tmp6);
  }

  TNode<HeapObject> tmp7;
  TNode<IntPtrT> tmp8;
  TNode<Map> tmp9;
  TNode<BoolT> tmp10;
  TNode<BoolT> tmp11;
  if (block11.is_used()) {
    ca_.Bind(&block11);
    ca_.SetSourcePosition("../../../src/builtins/promise-resolve.tq", 116);
    tmp7 = UnsafeCast_HeapObject_0(state_, TNode<Context>{parameter0}, TNode<Object>{parameter2});
    ca_.SetSourcePosition("../../../src/builtins/promise-resolve.tq", 117);
    tmp8 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp9 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference{tmp7, tmp8});
    ca_.SetSourcePosition("../../../src/builtins/promise-resolve.tq", 118);
    tmp10 = CodeStubAssembler(state_).IsJSReceiverMap(TNode<Map>{tmp9});
    tmp11 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp10});
    ca_.Branch(tmp11, &block12, std::vector<compiler::Node*>{}, &block13, std::vector<compiler::Node*>{});
  }

  TNode<Oddball> tmp12;
  if (block12.is_used()) {
    ca_.Bind(&block12);
    ca_.SetSourcePosition("../../../src/builtins/promise-resolve.tq", 119);
    tmp12 = ca_.CallStub<Oddball>(Builtins::CallableFor(ca_.isolate(), Builtin::kFulfillPromise), parameter0, parameter1, parameter2);
    CodeStubAssembler(state_).Return(tmp12);
  }

  TNode<BoolT> tmp13;
  if (block13.is_used()) {
    ca_.Bind(&block13);
    ca_.SetSourcePosition("../../../src/builtins/promise-resolve.tq", 126);
    tmp13 = IsForceSlowPath_0(state_);
    ca_.Branch(tmp13, &block14, std::vector<compiler::Node*>{}, &block15, std::vector<compiler::Node*>{});
  }

  if (block14.is_used()) {
    ca_.Bind(&block14);
    ca_.SetSourcePosition("../../../src/builtins/promise-resolve.tq", 127);
    ca_.Goto(&block9);
  }

  TNode<BoolT> tmp14;
  if (block15.is_used()) {
    ca_.Bind(&block15);
    ca_.SetSourcePosition("../../../src/builtins/promise-resolve.tq", 130);
    tmp14 = CodeStubAssembler(state_).IsPromiseThenProtectorCellInvalid();
    ca_.Branch(tmp14, &block16, std::vector<compiler::Node*>{}, &block17, std::vector<compiler::Node*>{});
  }

  if (block16.is_used()) {
    ca_.Bind(&block16);
    ca_.SetSourcePosition("../../../src/builtins/promise-resolve.tq", 131);
    ca_.Goto(&block9);
  }

  TNode<NativeContext> tmp15;
  TNode<BoolT> tmp16;
  TNode<BoolT> tmp17;
  if (block17.is_used()) {
    ca_.Bind(&block17);
    ca_.SetSourcePosition("../../../src/builtins/promise-resolve.tq", 134);
    tmp15 = CodeStubAssembler(state_).LoadNativeContext(TNode<Context>{parameter0});
    ca_.SetSourcePosition("../../../src/builtins/promise-resolve.tq", 135);
    tmp16 = CodeStubAssembler(state_).IsJSPromiseMap(TNode<Map>{tmp9});
    tmp17 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp16});
    ca_.Branch(tmp17, &block18, std::vector<compiler::Node*>{}, &block19, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp18;
  if (block18.is_used()) {
    ca_.Bind(&block18);
    ca_.SetSourcePosition("../../../src/builtins/promise-resolve.tq", 141);
    tmp18 = CodeStubAssembler(state_).IsJSReceiverMap(TNode<Map>{tmp9});
    ca_.Branch(tmp18, &block20, std::vector<compiler::Node*>{}, &block21, std::vector<compiler::Node*>{});
  }

  if (block21.is_used()) {
    ca_.Bind(&block21);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/promise-resolve.tq", 141});
      CodeStubAssembler(state_).FailAssert("Torque assert 'IsJSReceiverMap(resolutionMap)' failed", pos_stack);
    }
  }

  TNode<BoolT> tmp19;
  TNode<BoolT> tmp20;
  if (block20.is_used()) {
    ca_.Bind(&block20);
    ca_.SetSourcePosition("../../../src/builtins/promise-resolve.tq", 142);
    tmp19 = CodeStubAssembler(state_).IsPromiseThenProtectorCellInvalid();
    tmp20 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp19});
    ca_.Branch(tmp20, &block22, std::vector<compiler::Node*>{}, &block23, std::vector<compiler::Node*>{});
  }

  if (block23.is_used()) {
    ca_.Bind(&block23);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/promise-resolve.tq", 142});
      CodeStubAssembler(state_).FailAssert("Torque assert '!IsPromiseThenProtectorCellInvalid()' failed", pos_stack);
    }
  }

  TNode<IntPtrT> tmp21;
  TNode<Object> tmp22;
  TNode<IntPtrT> tmp23;
  TNode<Map> tmp24;
  TNode<BoolT> tmp25;
  if (block22.is_used()) {
    ca_.Bind(&block22);
    ca_.SetSourcePosition("../../../src/builtins/promise-resolve.tq", 145);
    tmp21 = ITERATOR_RESULT_MAP_INDEX_0(state_);
    ca_.SetSourcePosition("../../../src/builtins/promise-resolve.tq", 144);
    std::tie(tmp22, tmp23) = NativeContextSlot_Map_1(state_, TNode<NativeContext>{tmp15}, TNode<IntPtrT>{tmp21}).Flatten();
    tmp24 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference{tmp22, tmp23});
    ca_.SetSourcePosition("../../../src/builtins/promise-resolve.tq", 143);
    tmp25 = CodeStubAssembler(state_).TaggedEqual(TNode<HeapObject>{tmp9}, TNode<HeapObject>{tmp24});
    ca_.Branch(tmp25, &block24, std::vector<compiler::Node*>{}, &block25, std::vector<compiler::Node*>{});
  }

  TNode<Oddball> tmp26;
  if (block24.is_used()) {
    ca_.Bind(&block24);
    ca_.SetSourcePosition("../../../src/builtins/promise-resolve.tq", 146);
    tmp26 = ca_.CallStub<Oddball>(Builtins::CallableFor(ca_.isolate(), Builtin::kFulfillPromise), parameter0, parameter1, parameter2);
    CodeStubAssembler(state_).Return(tmp26);
  }

  if (block25.is_used()) {
    ca_.Bind(&block25);
    ca_.SetSourcePosition("../../../src/builtins/promise-resolve.tq", 148);
    ca_.Goto(&block9);
  }

  TNode<IntPtrT> tmp27;
  TNode<Object> tmp28;
  TNode<IntPtrT> tmp29;
  TNode<JSObject> tmp30;
  TNode<IntPtrT> tmp31;
  TNode<HeapObject> tmp32;
  TNode<BoolT> tmp33;
  if (block19.is_used()) {
    ca_.Bind(&block19);
    ca_.SetSourcePosition("../../../src/builtins/promise-resolve.tq", 154);
    tmp27 = PROMISE_PROTOTYPE_INDEX_0(state_);
    ca_.SetSourcePosition("../../../src/builtins/promise-resolve.tq", 153);
    std::tie(tmp28, tmp29) = NativeContextSlot_JSObject_0(state_, TNode<NativeContext>{tmp15}, TNode<IntPtrT>{tmp27}).Flatten();
    tmp30 = CodeStubAssembler(state_).LoadReference<JSObject>(CodeStubAssembler::Reference{tmp28, tmp29});
    ca_.SetSourcePosition("../../../src/builtins/promise-resolve.tq", 155);
    tmp31 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    tmp32 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{tmp9, tmp31});
    tmp33 = CodeStubAssembler(state_).TaggedEqual(TNode<HeapObject>{tmp32}, TNode<HeapObject>{tmp30});
    ca_.Branch(tmp33, &block27, std::vector<compiler::Node*>{}, &block28, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp34;
  TNode<Object> tmp35;
  TNode<IntPtrT> tmp36;
  TNode<JSFunction> tmp37;
  TNode<NativeContext> tmp38;
  TNode<BoolT> tmp39;
  if (block27.is_used()) {
    ca_.Bind(&block27);
    ca_.SetSourcePosition("../../../src/builtins/promise-resolve.tq", 157);
    tmp34 = PROMISE_THEN_INDEX_0(state_);
    std::tie(tmp35, tmp36) = NativeContextSlot_JSFunction_0(state_, TNode<NativeContext>{tmp15}, TNode<IntPtrT>{tmp34}).Flatten();
    tmp37 = CodeStubAssembler(state_).LoadReference<JSFunction>(CodeStubAssembler::Reference{tmp35, tmp36});
    ca_.SetSourcePosition("../../../src/builtins/promise-resolve.tq", 159);
    tmp38 = CodeStubAssembler(state_).LoadNativeContext(TNode<Context>{parameter0});
    tmp39 = CodeStubAssembler(state_).TaggedEqual(TNode<HeapObject>{tmp15}, TNode<HeapObject>{tmp38});
    CodeStubAssembler(state_).StaticAssert(TNode<BoolT>{tmp39}, "static_assert(nativeContext == LoadNativeContext(context)) at https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-resolve.tq?l=159&c=7");
    ca_.SetSourcePosition("../../../src/builtins/promise-resolve.tq", 160);
    ca_.Goto(&block7, tmp37);
  }

  if (block28.is_used()) {
    ca_.Bind(&block28);
    ca_.SetSourcePosition("../../../src/builtins/promise-resolve.tq", 162);
    ca_.Goto(&block9);
  }

  TNode<String> tmp40;
  TNode<Object> tmp41;
      TNode<Object> tmp43;
  TNode<BoolT> tmp44;
  TNode<BoolT> tmp45;
  if (block9.is_used()) {
    ca_.Bind(&block9);
    ca_.SetSourcePosition("../../../src/builtins/promise-resolve.tq", 167);
    tmp40 = kThenString_0(state_);
    compiler::CodeAssemblerExceptionHandlerLabel catch42__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch42__label);
    tmp41 = CodeStubAssembler(state_).GetProperty(TNode<Context>{parameter0}, TNode<Object>{parameter2}, TNode<Object>{tmp40});
    }
    if (catch42__label.is_used()) {
      compiler::CodeAssemblerLabel catch42_skip(&ca_);
      ca_.Goto(&catch42_skip);
      ca_.Bind(&catch42__label, &tmp43);
      ca_.Goto(&block31);
      ca_.Bind(&catch42_skip);
    }
    ca_.SetSourcePosition("../../../src/builtins/promise-resolve.tq", 175);
    tmp44 = Is_Callable_Object_0(state_, TNode<Context>{parameter0}, TNode<Object>{tmp41});
    tmp45 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp44});
    ca_.Branch(tmp45, &block32, std::vector<compiler::Node*>{}, &block33, std::vector<compiler::Node*>{});
  }

  TNode<HeapObject> tmp46;
  TNode<Oddball> tmp47;
  TNode<Object> tmp48;
  if (block31.is_used()) {
    ca_.Bind(&block31);
    ca_.SetSourcePosition("../../../src/builtins/promise-resolve.tq", 167);
    tmp46 = GetAndResetPendingMessage_0(state_);
    ca_.SetSourcePosition("../../../src/builtins/promise-resolve.tq", 170);
    tmp47 = False_0(state_);
    tmp48 = ca_.CallStub<Object>(Builtins::CallableFor(ca_.isolate(), Builtin::kRejectPromise), parameter0, parameter1, tmp43, tmp47);
    CodeStubAssembler(state_).Return(tmp48);
  }

  TNode<Oddball> tmp49;
  if (block32.is_used()) {
    ca_.Bind(&block32);
    ca_.SetSourcePosition("../../../src/builtins/promise-resolve.tq", 177);
    tmp49 = ca_.CallStub<Oddball>(Builtins::CallableFor(ca_.isolate(), Builtin::kFulfillPromise), parameter0, parameter1, parameter2);
    CodeStubAssembler(state_).Return(tmp49);
  }

  if (block33.is_used()) {
    ca_.Bind(&block33);
    ca_.SetSourcePosition("../../../src/builtins/promise-resolve.tq", 179);
    ca_.Goto(&block7, tmp41);
  }

  TNode<Object> phi_bb7_3;
  TNode<JSReceiver> tmp50;
  TNode<JSReceiver> tmp51;
  TNode<PromiseResolveThenableJobTask> tmp52;
  TNode<IntPtrT> tmp53;
  TNode<Context> tmp54;
  TNode<Oddball> tmp55;
  if (block7.is_used()) {
    ca_.Bind(&block7, &phi_bb7_3);
    ca_.SetSourcePosition("../../../src/builtins/promise-resolve.tq", 184);
    tmp50 = UnsafeCast_JSReceiver_0(state_, TNode<Context>{parameter0}, TNode<Object>{parameter2});
    ca_.SetSourcePosition("../../../src/builtins/promise-resolve.tq", 185);
    tmp51 = UnsafeCast_Callable_0(state_, TNode<Context>{parameter0}, TNode<Object>{phi_bb7_3});
    ca_.SetSourcePosition("../../../src/builtins/promise-resolve.tq", 183);
    tmp52 = NewPromiseResolveThenableJobTask_0(state_, TNode<Context>{parameter0}, TNode<JSPromise>{parameter1}, TNode<JSReceiver>{tmp50}, TNode<JSReceiver>{tmp51});
    ca_.SetSourcePosition("../../../src/builtins/promise-resolve.tq", 189);
    tmp53 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp54 = CodeStubAssembler(state_).LoadReference<Context>(CodeStubAssembler::Reference{tmp52, tmp53});
    tmp55 = ca_.CallStub<Oddball>(Builtins::CallableFor(ca_.isolate(), Builtin::kEnqueueMicrotask), tmp54, tmp52);
    CodeStubAssembler(state_).Return(tmp55);
  }
}

} // namespace internal
} // namespace v8
