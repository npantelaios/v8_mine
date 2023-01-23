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
#include "torque-generated/src/builtins/promise-all-element-closure-tq-csa.h"
#include "torque-generated/src/builtins/array-join-tq-csa.h"
#include "torque-generated/src/builtins/base-tq-csa.h"
#include "torque-generated/src/builtins/conversion-tq-csa.h"
#include "torque-generated/src/builtins/convert-tq-csa.h"
#include "torque-generated/src/builtins/promise-abstract-operations-tq-csa.h"
#include "torque-generated/src/builtins/promise-all-tq-csa.h"
#include "torque-generated/src/builtins/promise-all-element-closure-tq-csa.h"
#include "torque-generated/src/builtins/torque-internal-tq-csa.h"
#include "torque-generated/src/objects/contexts-tq-csa.h"
#include "torque-generated/src/objects/fixed-array-tq-csa.h"
#include "torque-generated/src/objects/js-array-tq-csa.h"
#include "torque-generated/src/objects/js-objects-tq-csa.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-all-element-closure.tq?l=66&c=1
TNode<IntPtrT> FromConstexpr_PromiseAllResolveElementContextSlots_constexpr_kPromiseAllResolveElementRemainingSlot_0(compiler::CodeAssemblerState* state_, PromiseBuiltins::PromiseAllResolveElementContextSlots p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 66);
    tmp0 = ca_.IntPtrConstant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<IntPtrT>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<IntPtrT>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-all-element-closure.tq?l=66&c=1
TNode<IntPtrT> FromConstexpr_PromiseAllResolveElementContextSlots_constexpr_kPromiseAllResolveElementCapabilitySlot_0(compiler::CodeAssemblerState* state_, PromiseBuiltins::PromiseAllResolveElementContextSlots p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 66);
    tmp0 = ca_.IntPtrConstant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<IntPtrT>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<IntPtrT>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-all-element-closure.tq?l=66&c=1
TNode<IntPtrT> FromConstexpr_PromiseAllResolveElementContextSlots_constexpr_kPromiseAllResolveElementValuesSlot_0(compiler::CodeAssemblerState* state_, PromiseBuiltins::PromiseAllResolveElementContextSlots p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 66);
    tmp0 = ca_.IntPtrConstant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<IntPtrT>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<IntPtrT>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-all-element-closure.tq?l=66&c=1
TNode<IntPtrT> FromConstexpr_PromiseAllResolveElementContextSlots_constexpr_kPromiseAllResolveElementLength_0(compiler::CodeAssemblerState* state_, PromiseBuiltins::PromiseAllResolveElementContextSlots p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 66);
    tmp0 = ca_.IntPtrConstant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<IntPtrT>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<IntPtrT>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-all-element-closure.tq?l=66&c=1
TNode<IntPtrT> kPromiseAllResolveElementRemainingSlot_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 66);
  TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_PromiseAllResolveElementContextSlots_constexpr_kPromiseAllResolveElementRemainingSlot_0(state_, PromiseBuiltins::PromiseAllResolveElementContextSlots::kPromiseAllResolveElementRemainingSlot);
  TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT>{tmp0});
  return TNode<IntPtrT>{tmp1};}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-all-element-closure.tq?l=66&c=1
TNode<IntPtrT> kPromiseAllResolveElementCapabilitySlot_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 66);
  TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_PromiseAllResolveElementContextSlots_constexpr_kPromiseAllResolveElementCapabilitySlot_0(state_, PromiseBuiltins::PromiseAllResolveElementContextSlots::kPromiseAllResolveElementCapabilitySlot);
  TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT>{tmp0});
  return TNode<IntPtrT>{tmp1};}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-all-element-closure.tq?l=66&c=1
TNode<IntPtrT> kPromiseAllResolveElementValuesSlot_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 66);
  TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_PromiseAllResolveElementContextSlots_constexpr_kPromiseAllResolveElementValuesSlot_0(state_, PromiseBuiltins::PromiseAllResolveElementContextSlots::kPromiseAllResolveElementValuesSlot);
  TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT>{tmp0});
  return TNode<IntPtrT>{tmp1};}

TF_BUILTIN(PromiseAllResolveElementClosure, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kReceiver);
  USE(parameter1);
  TNode<JSFunction> parameter2 = UncheckedParameter<JSFunction>(Descriptor::kJSTarget);
USE(parameter2);
  TNode<Object> parameter3 = UncheckedParameter<Object>(Descriptor::kValue);
  USE(parameter3);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Context> tmp0;
  TNode<Object> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 194);
    tmp0 = (TNode<Context>{parameter0});
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 195);
    tmp1 = PromiseAllResolveElementClosure_PromiseAllWrapResultAsFulfilledFunctor_0(state_, TNode<Context>{tmp0}, TNode<Object>{parameter3}, TNode<JSFunction>{parameter2}, TorqueStructPromiseAllWrapResultAsFulfilledFunctor_0{}, false);
    CodeStubAssembler(state_).Return(tmp1);
  }
}

TF_BUILTIN(PromiseAllSettledResolveElementClosure, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kReceiver);
  USE(parameter1);
  TNode<JSFunction> parameter2 = UncheckedParameter<JSFunction>(Descriptor::kJSTarget);
USE(parameter2);
  TNode<Object> parameter3 = UncheckedParameter<Object>(Descriptor::kValue);
  USE(parameter3);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Context> tmp0;
  TNode<Object> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 204);
    tmp0 = (TNode<Context>{parameter0});
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 205);
    tmp1 = PromiseAllResolveElementClosure_PromiseAllSettledWrapResultAsFulfilledFunctor_0(state_, TNode<Context>{tmp0}, TNode<Object>{parameter3}, TNode<JSFunction>{parameter2}, TorqueStructPromiseAllSettledWrapResultAsFulfilledFunctor_0{}, true);
    CodeStubAssembler(state_).Return(tmp1);
  }
}

TF_BUILTIN(PromiseAllSettledRejectElementClosure, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kReceiver);
  USE(parameter1);
  TNode<JSFunction> parameter2 = UncheckedParameter<JSFunction>(Descriptor::kJSTarget);
USE(parameter2);
  TNode<Object> parameter3 = UncheckedParameter<Object>(Descriptor::kValue);
  USE(parameter3);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Context> tmp0;
  TNode<Object> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 214);
    tmp0 = (TNode<Context>{parameter0});
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 215);
    tmp1 = PromiseAllResolveElementClosure_PromiseAllSettledWrapResultAsRejectedFunctor_0(state_, TNode<Context>{tmp0}, TNode<Object>{parameter3}, TNode<JSFunction>{parameter2}, TorqueStructPromiseAllSettledWrapResultAsRejectedFunctor_0{}, true);
    CodeStubAssembler(state_).Return(tmp1);
  }
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-all-element-closure.tq?l=195&c=10
TNode<Object> PromiseAllResolveElementClosure_PromiseAllWrapResultAsFulfilledFunctor_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_value, TNode<JSFunction> p_function, TorqueStructPromiseAllWrapResultAsFulfilledFunctor_0 p_wrapResultFunctor, bool p_hasResolveAndRejectClosures) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block26(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block27(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block20(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block35(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block36(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block40(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block39(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block41(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block43(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block44(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block42(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block45(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<NativeContext> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 98);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = Cast_NativeContext_0(state_, TNode<HeapObject>{p_context}, &label1);
    ca_.Goto(&block4);
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block5);
    }
  }

  TNode<IntPtrT> tmp2;
  TNode<Smi> tmp3;
  TNode<IntPtrT> tmp4;
  TNode<Smi> tmp5;
  TNode<BoolT> tmp6;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 107);
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp3 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{ca_.UncheckedCast<Context>(p_context), tmp2});
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 108);
    tmp4 = FromConstexpr_intptr_constexpr_intptr_0(state_, PromiseBuiltins::PromiseAllResolveElementContextSlots::kPromiseAllResolveElementLength);
    tmp5 = CodeStubAssembler(state_).SmiTag(TNode<IntPtrT>{tmp4});
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 107);
    tmp6 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp3}, TNode<Smi>{tmp5});
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 106);
    ca_.Branch(tmp6, &block6, std::vector<compiler::Node*>{}, &block7, std::vector<compiler::Node*>{});
  }

  TNode<Oddball> tmp7;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 99);
    tmp7 = Undefined_0(state_);
    ca_.Goto(&block1, tmp7);
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 106);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/promise-all-element-closure.tq", 106});
      CodeStubAssembler(state_).FailAssert("Torque assert 'promiseContext.length == SmiTag(PromiseAllResolveElementContextSlots:: kPromiseAllResolveElementLength)' failed", pos_stack);
    }
  }

  TNode<NativeContext> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<BoolT> tmp10;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 110);
    tmp8 = CodeStubAssembler(state_).LoadNativeContext(TNode<Context>{ca_.UncheckedCast<Context>(p_context)});
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 111);
    tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    CodeStubAssembler(state_).StoreReference<Context>(CodeStubAssembler::Reference{p_function, tmp9}, tmp8);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 114);
    tmp10 = FromConstexpr_bool_constexpr_bool_0(state_, (CodeStubAssembler(state_).ConstexprInt31Equal(PropertyArray::kNoHashSentinel, (FromConstexpr_constexpr_int31_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull))))));
    ca_.Branch(tmp10, &block8, std::vector<compiler::Node*>{}, &block9, std::vector<compiler::Node*>{});
  }

  if (block9.is_used()) {
    ca_.Bind(&block9);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/promise-all-element-closure.tq", 114});
      CodeStubAssembler(state_).FailAssert("Torque assert 'kPropertyArrayNoHashSentinel == 0' failed", pos_stack);
    }
  }

  TNode<IntPtrT> tmp11;
  if (block8.is_used()) {
    ca_.Bind(&block8);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 116);
    compiler::CodeAssemblerLabel label12(&ca_);
    tmp11 = CodeStubAssembler(state_).LoadJSReceiverIdentityHash(TNode<JSReceiver>{p_function}, &label12);
    ca_.Goto(&block12);
    if (label12.is_used()) {
      ca_.Bind(&label12);
      ca_.Goto(&block13);
    }
  }

  if (block13.is_used()) {
    ca_.Bind(&block13);
    CodeStubAssembler(state_).PrintErr("halting because of unreachable code at src/builtins/promise-all-element-closure.tq:116:54");
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<IntPtrT> tmp13;
  TNode<BoolT> tmp14;
  if (block12.is_used()) {
    ca_.Bind(&block12);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 117);
    tmp13 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp14 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{tmp11}, TNode<IntPtrT>{tmp13});
    ca_.Branch(tmp14, &block14, std::vector<compiler::Node*>{}, &block15, std::vector<compiler::Node*>{});
  }

  if (block15.is_used()) {
    ca_.Bind(&block15);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/promise-all-element-closure.tq", 117});
      CodeStubAssembler(state_).FailAssert("Torque assert 'identityHash > 0' failed", pos_stack);
    }
  }

  TNode<IntPtrT> tmp15;
  TNode<IntPtrT> tmp16;
  TNode<IntPtrT> tmp17;
  TNode<Object> tmp18;
  TNode<IntPtrT> tmp19;
  TNode<Smi> tmp20;
  TNode<IntPtrT> tmp21;
  TNode<Object> tmp22;
  TNode<IntPtrT> tmp23;
  TNode<FixedArray> tmp24;
  TNode<IntPtrT> tmp25;
  TNode<IntPtrT> tmp26;
  TNode<IntPtrT> tmp27;
  TNode<BoolT> tmp28;
  if (block14.is_used()) {
    ca_.Bind(&block14);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 118);
    tmp15 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp16 = CodeStubAssembler(state_).IntPtrSub(TNode<IntPtrT>{tmp11}, TNode<IntPtrT>{tmp15});
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 122);
    tmp17 = kPromiseAllResolveElementRemainingSlot_0(state_);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 120);
    std::tie(tmp18, tmp19) = ContextSlot_PromiseAllResolveElementContext_PromiseAllResolveElementContext_Smi_0(state_, TNode<Context>{ca_.UncheckedCast<Context>(p_context)}, TNode<IntPtrT>{tmp17}).Flatten();
    tmp20 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp18, tmp19});
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 127);
    tmp21 = kPromiseAllResolveElementValuesSlot_0(state_);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 125);
    std::tie(tmp22, tmp23) = ContextSlot_PromiseAllResolveElementContext_PromiseAllResolveElementContext_FixedArray_0(state_, TNode<Context>{ca_.UncheckedCast<Context>(p_context)}, TNode<IntPtrT>{tmp21}).Flatten();
    tmp24 = CodeStubAssembler(state_).LoadReference<FixedArray>(CodeStubAssembler::Reference{tmp22, tmp23});
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 129);
    tmp25 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp26 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp16}, TNode<IntPtrT>{tmp25});
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 130);
    tmp27 = CodeStubAssembler(state_).LoadAndUntagFixedArrayBaseLength(TNode<FixedArrayBase>{tmp24});
    tmp28 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{tmp26}, TNode<IntPtrT>{tmp27});
    ca_.Branch(tmp28, &block16, std::vector<compiler::Node*>{}, &block17, std::vector<compiler::Node*>{tmp24});
  }

  TNode<IntPtrT> tmp29;
  TNode<IntPtrT> tmp30;
  TNode<FixedArray> tmp31;
  TNode<IntPtrT> tmp32;
  TNode<Object> tmp33;
  TNode<IntPtrT> tmp34;
  if (block16.is_used()) {
    ca_.Bind(&block16);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 132);
    tmp29 = CodeStubAssembler(state_).LoadAndUntagFixedArrayBaseLength(TNode<FixedArrayBase>{tmp24});
    tmp30 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp31 = ExtractFixedArray_0(state_, TNode<FixedArray>{tmp24}, TNode<IntPtrT>{tmp30}, TNode<IntPtrT>{tmp29}, TNode<IntPtrT>{tmp26});
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 135);
    tmp32 = kPromiseAllResolveElementValuesSlot_0(state_);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 133);
    std::tie(tmp33, tmp34) = ContextSlot_PromiseAllResolveElementContext_PromiseAllResolveElementContext_FixedArray_0(state_, TNode<Context>{ca_.UncheckedCast<Context>(p_context)}, TNode<IntPtrT>{tmp32}).Flatten();
    CodeStubAssembler(state_).StoreReference<FixedArray>(CodeStubAssembler::Reference{tmp33, tmp34}, tmp31);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 130);
    ca_.Goto(&block17, tmp31);
  }

  TNode<FixedArray> phi_bb17_8;
  TNode<BoolT> tmp35;
  if (block17.is_used()) {
    ca_.Bind(&block17, &phi_bb17_8);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 149);
    tmp35 = FromConstexpr_bool_constexpr_bool_0(state_, p_hasResolveAndRejectClosures);
    ca_.Branch(tmp35, &block18, std::vector<compiler::Node*>{}, &block19, std::vector<compiler::Node*>{});
  }

  TNode<Object> tmp36;
  TNode<IntPtrT> tmp37;
  TNode<IntPtrT> tmp38;
  TNode<UintPtrT> tmp39;
  TNode<UintPtrT> tmp40;
  TNode<BoolT> tmp41;
  if (block18.is_used()) {
    ca_.Bind(&block18);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 150);
    std::tie(tmp36, tmp37, tmp38) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray>{phi_bb17_8}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 89);
    tmp39 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp16});
    tmp40 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp38});
    tmp41 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp39}, TNode<UintPtrT>{tmp40});
    ca_.Branch(tmp41, &block26, std::vector<compiler::Node*>{}, &block27, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp42;
  TNode<IntPtrT> tmp43;
  TNode<Object> tmp44;
  TNode<IntPtrT> tmp45;
  TNode<Object> tmp46;
  TNode<Oddball> tmp47;
  TNode<BoolT> tmp48;
  if (block26.is_used()) {
    ca_.Bind(&block26);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 97);
    tmp42 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{tmp16});
    tmp43 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp37}, TNode<IntPtrT>{tmp42});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 96);
    std::tie(tmp44, tmp45) = NewReference_Object_0(state_, TNode<Object>{tmp36}, TNode<IntPtrT>{tmp43}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 150);
    tmp46 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp44, tmp45});
    tmp47 = TheHole_0(state_);
    tmp48 = CodeStubAssembler(state_).TaggedNotEqual(TNode<Object>{tmp46}, TNode<HeapObject>{tmp47});
    ca_.Branch(tmp48, &block20, std::vector<compiler::Node*>{}, &block21, std::vector<compiler::Node*>{});
  }

  if (block27.is_used()) {
    ca_.Bind(&block27);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 101);
    CodeStubAssembler(state_).PrintErr("halting because of unreachable code at src/builtins/torque-internal.tq:101:45");
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<Oddball> tmp49;
  if (block20.is_used()) {
    ca_.Bind(&block20);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 151);
    tmp49 = Undefined_0(state_);
    ca_.Goto(&block1, tmp49);
  }

  if (block21.is_used()) {
    ca_.Bind(&block21);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 149);
    ca_.Goto(&block19);
  }

  TNode<Object> tmp50;
  TNode<IntPtrT> tmp51;
  TNode<IntPtrT> tmp52;
  TNode<UintPtrT> tmp53;
  TNode<UintPtrT> tmp54;
  TNode<BoolT> tmp55;
  if (block19.is_used()) {
    ca_.Bind(&block19);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 159);
    std::tie(tmp50, tmp51, tmp52) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray>{phi_bb17_8}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 89);
    tmp53 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp16});
    tmp54 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp52});
    tmp55 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp53}, TNode<UintPtrT>{tmp54});
    ca_.Branch(tmp55, &block35, std::vector<compiler::Node*>{}, &block36, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp56;
  TNode<IntPtrT> tmp57;
  TNode<Object> tmp58;
  TNode<IntPtrT> tmp59;
  TNode<Smi> tmp60;
  TNode<Smi> tmp61;
  TNode<Smi> tmp62;
  TNode<BoolT> tmp63;
  if (block35.is_used()) {
    ca_.Bind(&block35);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 97);
    tmp56 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{tmp16});
    tmp57 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp51}, TNode<IntPtrT>{tmp56});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 96);
    std::tie(tmp58, tmp59) = NewReference_Object_0(state_, TNode<Object>{tmp50}, TNode<IntPtrT>{tmp57}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 159);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp58, tmp59}, p_value);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 161);
    tmp60 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp61 = CodeStubAssembler(state_).SmiSub(TNode<Smi>{tmp20}, TNode<Smi>{tmp60});
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 162);
    tmp62 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp63 = CodeStubAssembler(state_).SmiGreaterThanOrEqual(TNode<Smi>{tmp61}, TNode<Smi>{tmp62});
    ca_.Branch(tmp63, &block39, std::vector<compiler::Node*>{}, &block40, std::vector<compiler::Node*>{});
  }

  if (block36.is_used()) {
    ca_.Bind(&block36);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 101);
    CodeStubAssembler(state_).PrintErr("halting because of unreachable code at src/builtins/torque-internal.tq:101:45");
    CodeStubAssembler(state_).Unreachable();
  }

  if (block40.is_used()) {
    ca_.Bind(&block40);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 162);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/promise-all-element-closure.tq", 162});
      CodeStubAssembler(state_).FailAssert("Torque assert 'remainingElementsCount >= 0' failed", pos_stack);
    }
  }

  TNode<IntPtrT> tmp64;
  TNode<Object> tmp65;
  TNode<IntPtrT> tmp66;
  TNode<Smi> tmp67;
  TNode<BoolT> tmp68;
  if (block39.is_used()) {
    ca_.Bind(&block39);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 166);
    tmp64 = kPromiseAllResolveElementRemainingSlot_0(state_);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 164);
    std::tie(tmp65, tmp66) = ContextSlot_PromiseAllResolveElementContext_PromiseAllResolveElementContext_Smi_0(state_, TNode<Context>{ca_.UncheckedCast<Context>(p_context)}, TNode<IntPtrT>{tmp64}).Flatten();
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{tmp65, tmp66}, tmp61);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 168);
    tmp67 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp68 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp61}, TNode<Smi>{tmp67});
    ca_.Branch(tmp68, &block41, std::vector<compiler::Node*>{}, &block42, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp69;
  TNode<Object> tmp70;
  TNode<IntPtrT> tmp71;
  TNode<PromiseCapability> tmp72;
  TNode<IntPtrT> tmp73;
  TNode<Object> tmp74;
  TNode<Object> tmp75;
  TNode<IntPtrT> tmp76;
  TNode<Object> tmp77;
  TNode<IntPtrT> tmp78;
  TNode<Map> tmp79;
  TNode<BoolT> tmp80;
  if (block41.is_used()) {
    ca_.Bind(&block41);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 171);
    tmp69 = kPromiseAllResolveElementCapabilitySlot_0(state_);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 169);
    std::tie(tmp70, tmp71) = ContextSlot_PromiseAllResolveElementContext_PromiseAllResolveElementContext_PromiseCapability_0(state_, TNode<Context>{ca_.UncheckedCast<Context>(p_context)}, TNode<IntPtrT>{tmp69}).Flatten();
    tmp72 = CodeStubAssembler(state_).LoadReference<PromiseCapability>(CodeStubAssembler::Reference{tmp70, tmp71});
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 173);
    tmp73 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp74 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp72, tmp73});
    tmp75 = UnsafeCast_JSAny_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp74});
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 176);
    tmp76 = JS_ARRAY_PACKED_ELEMENTS_MAP_INDEX_0(state_);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 175);
    std::tie(tmp77, tmp78) = NativeContextSlot_Map_1(state_, TNode<NativeContext>{tmp8}, TNode<IntPtrT>{tmp76}).Flatten();
    tmp79 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference{tmp77, tmp78});
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 181);
    tmp80 = FromConstexpr_bool_constexpr_bool_0(state_, p_hasResolveAndRejectClosures);
    ca_.Branch(tmp80, &block43, std::vector<compiler::Node*>{}, &block44, std::vector<compiler::Node*>{});
  }

  if (block43.is_used()) {
    ca_.Bind(&block43);
    CodeStubAssembler(state_).MakeFixedArrayCOW(TNode<FixedArray>{phi_bb17_8});
    ca_.Goto(&block44);
  }

  TNode<JSArray> tmp81;
  TNode<Oddball> tmp82;
  TNode<Object> tmp83;
  if (block44.is_used()) {
    ca_.Bind(&block44);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 183);
    tmp81 = NewJSArray_0(state_, TNode<Context>{p_context}, TNode<Map>{tmp79}, TNode<FixedArrayBase>{phi_bb17_8});
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 184);
    tmp82 = Undefined_0(state_);
    tmp83 = CodeStubAssembler(state_).Call(TNode<Context>{ca_.UncheckedCast<Context>(p_context)}, TNode<Object>{tmp75}, TNode<Object>{tmp82}, TNode<Object>{tmp81});
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 168);
    ca_.Goto(&block42);
  }

  TNode<Oddball> tmp84;
  if (block42.is_used()) {
    ca_.Bind(&block42);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 186);
    tmp84 = Undefined_0(state_);
    ca_.Goto(&block1, tmp84);
  }

  TNode<Object> phi_bb1_3;
  if (block1.is_used()) {
    ca_.Bind(&block1, &phi_bb1_3);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 195);
    ca_.Goto(&block45, phi_bb1_3);
  }

  TNode<Object> phi_bb45_3;
    ca_.Bind(&block45, &phi_bb45_3);
  return TNode<Object>{phi_bb45_3};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-all-element-closure.tq?l=205&c=10
TNode<Object> PromiseAllResolveElementClosure_PromiseAllSettledWrapResultAsFulfilledFunctor_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_value, TNode<JSFunction> p_function, TorqueStructPromiseAllSettledWrapResultAsFulfilledFunctor_0 p_wrapResultFunctor, bool p_hasResolveAndRejectClosures) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block26(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block27(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block20(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block35(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block36(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block40(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block39(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block41(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block43(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block44(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block42(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block45(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<NativeContext> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 98);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = Cast_NativeContext_0(state_, TNode<HeapObject>{p_context}, &label1);
    ca_.Goto(&block4);
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block5);
    }
  }

  TNode<IntPtrT> tmp2;
  TNode<Smi> tmp3;
  TNode<IntPtrT> tmp4;
  TNode<Smi> tmp5;
  TNode<BoolT> tmp6;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 107);
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp3 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{ca_.UncheckedCast<Context>(p_context), tmp2});
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 108);
    tmp4 = FromConstexpr_intptr_constexpr_intptr_0(state_, PromiseBuiltins::PromiseAllResolveElementContextSlots::kPromiseAllResolveElementLength);
    tmp5 = CodeStubAssembler(state_).SmiTag(TNode<IntPtrT>{tmp4});
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 107);
    tmp6 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp3}, TNode<Smi>{tmp5});
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 106);
    ca_.Branch(tmp6, &block6, std::vector<compiler::Node*>{}, &block7, std::vector<compiler::Node*>{});
  }

  TNode<Oddball> tmp7;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 99);
    tmp7 = Undefined_0(state_);
    ca_.Goto(&block1, tmp7);
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 106);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/promise-all-element-closure.tq", 106});
      CodeStubAssembler(state_).FailAssert("Torque assert 'promiseContext.length == SmiTag(PromiseAllResolveElementContextSlots:: kPromiseAllResolveElementLength)' failed", pos_stack);
    }
  }

  TNode<NativeContext> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<BoolT> tmp10;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 110);
    tmp8 = CodeStubAssembler(state_).LoadNativeContext(TNode<Context>{ca_.UncheckedCast<Context>(p_context)});
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 111);
    tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    CodeStubAssembler(state_).StoreReference<Context>(CodeStubAssembler::Reference{p_function, tmp9}, tmp8);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 114);
    tmp10 = FromConstexpr_bool_constexpr_bool_0(state_, (CodeStubAssembler(state_).ConstexprInt31Equal(PropertyArray::kNoHashSentinel, (FromConstexpr_constexpr_int31_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull))))));
    ca_.Branch(tmp10, &block8, std::vector<compiler::Node*>{}, &block9, std::vector<compiler::Node*>{});
  }

  if (block9.is_used()) {
    ca_.Bind(&block9);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/promise-all-element-closure.tq", 114});
      CodeStubAssembler(state_).FailAssert("Torque assert 'kPropertyArrayNoHashSentinel == 0' failed", pos_stack);
    }
  }

  TNode<IntPtrT> tmp11;
  if (block8.is_used()) {
    ca_.Bind(&block8);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 116);
    compiler::CodeAssemblerLabel label12(&ca_);
    tmp11 = CodeStubAssembler(state_).LoadJSReceiverIdentityHash(TNode<JSReceiver>{p_function}, &label12);
    ca_.Goto(&block12);
    if (label12.is_used()) {
      ca_.Bind(&label12);
      ca_.Goto(&block13);
    }
  }

  if (block13.is_used()) {
    ca_.Bind(&block13);
    CodeStubAssembler(state_).PrintErr("halting because of unreachable code at src/builtins/promise-all-element-closure.tq:116:54");
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<IntPtrT> tmp13;
  TNode<BoolT> tmp14;
  if (block12.is_used()) {
    ca_.Bind(&block12);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 117);
    tmp13 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp14 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{tmp11}, TNode<IntPtrT>{tmp13});
    ca_.Branch(tmp14, &block14, std::vector<compiler::Node*>{}, &block15, std::vector<compiler::Node*>{});
  }

  if (block15.is_used()) {
    ca_.Bind(&block15);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/promise-all-element-closure.tq", 117});
      CodeStubAssembler(state_).FailAssert("Torque assert 'identityHash > 0' failed", pos_stack);
    }
  }

  TNode<IntPtrT> tmp15;
  TNode<IntPtrT> tmp16;
  TNode<IntPtrT> tmp17;
  TNode<Object> tmp18;
  TNode<IntPtrT> tmp19;
  TNode<Smi> tmp20;
  TNode<IntPtrT> tmp21;
  TNode<Object> tmp22;
  TNode<IntPtrT> tmp23;
  TNode<FixedArray> tmp24;
  TNode<IntPtrT> tmp25;
  TNode<IntPtrT> tmp26;
  TNode<IntPtrT> tmp27;
  TNode<BoolT> tmp28;
  if (block14.is_used()) {
    ca_.Bind(&block14);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 118);
    tmp15 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp16 = CodeStubAssembler(state_).IntPtrSub(TNode<IntPtrT>{tmp11}, TNode<IntPtrT>{tmp15});
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 122);
    tmp17 = kPromiseAllResolveElementRemainingSlot_0(state_);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 120);
    std::tie(tmp18, tmp19) = ContextSlot_PromiseAllResolveElementContext_PromiseAllResolveElementContext_Smi_0(state_, TNode<Context>{ca_.UncheckedCast<Context>(p_context)}, TNode<IntPtrT>{tmp17}).Flatten();
    tmp20 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp18, tmp19});
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 127);
    tmp21 = kPromiseAllResolveElementValuesSlot_0(state_);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 125);
    std::tie(tmp22, tmp23) = ContextSlot_PromiseAllResolveElementContext_PromiseAllResolveElementContext_FixedArray_0(state_, TNode<Context>{ca_.UncheckedCast<Context>(p_context)}, TNode<IntPtrT>{tmp21}).Flatten();
    tmp24 = CodeStubAssembler(state_).LoadReference<FixedArray>(CodeStubAssembler::Reference{tmp22, tmp23});
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 129);
    tmp25 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp26 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp16}, TNode<IntPtrT>{tmp25});
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 130);
    tmp27 = CodeStubAssembler(state_).LoadAndUntagFixedArrayBaseLength(TNode<FixedArrayBase>{tmp24});
    tmp28 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{tmp26}, TNode<IntPtrT>{tmp27});
    ca_.Branch(tmp28, &block16, std::vector<compiler::Node*>{}, &block17, std::vector<compiler::Node*>{tmp24});
  }

  TNode<IntPtrT> tmp29;
  TNode<IntPtrT> tmp30;
  TNode<FixedArray> tmp31;
  TNode<IntPtrT> tmp32;
  TNode<Object> tmp33;
  TNode<IntPtrT> tmp34;
  if (block16.is_used()) {
    ca_.Bind(&block16);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 132);
    tmp29 = CodeStubAssembler(state_).LoadAndUntagFixedArrayBaseLength(TNode<FixedArrayBase>{tmp24});
    tmp30 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp31 = ExtractFixedArray_0(state_, TNode<FixedArray>{tmp24}, TNode<IntPtrT>{tmp30}, TNode<IntPtrT>{tmp29}, TNode<IntPtrT>{tmp26});
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 135);
    tmp32 = kPromiseAllResolveElementValuesSlot_0(state_);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 133);
    std::tie(tmp33, tmp34) = ContextSlot_PromiseAllResolveElementContext_PromiseAllResolveElementContext_FixedArray_0(state_, TNode<Context>{ca_.UncheckedCast<Context>(p_context)}, TNode<IntPtrT>{tmp32}).Flatten();
    CodeStubAssembler(state_).StoreReference<FixedArray>(CodeStubAssembler::Reference{tmp33, tmp34}, tmp31);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 130);
    ca_.Goto(&block17, tmp31);
  }

  TNode<FixedArray> phi_bb17_8;
  TNode<BoolT> tmp35;
  if (block17.is_used()) {
    ca_.Bind(&block17, &phi_bb17_8);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 149);
    tmp35 = FromConstexpr_bool_constexpr_bool_0(state_, p_hasResolveAndRejectClosures);
    ca_.Branch(tmp35, &block18, std::vector<compiler::Node*>{}, &block19, std::vector<compiler::Node*>{});
  }

  TNode<Object> tmp36;
  TNode<IntPtrT> tmp37;
  TNode<IntPtrT> tmp38;
  TNode<UintPtrT> tmp39;
  TNode<UintPtrT> tmp40;
  TNode<BoolT> tmp41;
  if (block18.is_used()) {
    ca_.Bind(&block18);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 150);
    std::tie(tmp36, tmp37, tmp38) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray>{phi_bb17_8}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 89);
    tmp39 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp16});
    tmp40 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp38});
    tmp41 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp39}, TNode<UintPtrT>{tmp40});
    ca_.Branch(tmp41, &block26, std::vector<compiler::Node*>{}, &block27, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp42;
  TNode<IntPtrT> tmp43;
  TNode<Object> tmp44;
  TNode<IntPtrT> tmp45;
  TNode<Object> tmp46;
  TNode<Oddball> tmp47;
  TNode<BoolT> tmp48;
  if (block26.is_used()) {
    ca_.Bind(&block26);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 97);
    tmp42 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{tmp16});
    tmp43 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp37}, TNode<IntPtrT>{tmp42});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 96);
    std::tie(tmp44, tmp45) = NewReference_Object_0(state_, TNode<Object>{tmp36}, TNode<IntPtrT>{tmp43}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 150);
    tmp46 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp44, tmp45});
    tmp47 = TheHole_0(state_);
    tmp48 = CodeStubAssembler(state_).TaggedNotEqual(TNode<Object>{tmp46}, TNode<HeapObject>{tmp47});
    ca_.Branch(tmp48, &block20, std::vector<compiler::Node*>{}, &block21, std::vector<compiler::Node*>{});
  }

  if (block27.is_used()) {
    ca_.Bind(&block27);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 101);
    CodeStubAssembler(state_).PrintErr("halting because of unreachable code at src/builtins/torque-internal.tq:101:45");
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<Oddball> tmp49;
  if (block20.is_used()) {
    ca_.Bind(&block20);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 151);
    tmp49 = Undefined_0(state_);
    ca_.Goto(&block1, tmp49);
  }

  if (block21.is_used()) {
    ca_.Bind(&block21);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 149);
    ca_.Goto(&block19);
  }

  TNode<IntPtrT> tmp50;
  TNode<Object> tmp51;
  TNode<IntPtrT> tmp52;
  TNode<JSFunction> tmp53;
  TNode<IntPtrT> tmp54;
  TNode<HeapObject> tmp55;
  TNode<Map> tmp56;
  TNode<JSObject> tmp57;
  TNode<String> tmp58;
  TNode<String> tmp59;
  TNode<Object> tmp60;
  TNode<String> tmp61;
  TNode<Object> tmp62;
  TNode<Object> tmp63;
  TNode<IntPtrT> tmp64;
  TNode<IntPtrT> tmp65;
  TNode<UintPtrT> tmp66;
  TNode<UintPtrT> tmp67;
  TNode<BoolT> tmp68;
  if (block19.is_used()) {
    ca_.Bind(&block19);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 25);
    tmp50 = OBJECT_FUNCTION_INDEX_0(state_);
    std::tie(tmp51, tmp52) = NativeContextSlot_JSFunction_0(state_, TNode<NativeContext>{tmp8}, TNode<IntPtrT>{tmp50}).Flatten();
    tmp53 = CodeStubAssembler(state_).LoadReference<JSFunction>(CodeStubAssembler::Reference{tmp51, tmp52});
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 27);
    tmp54 = FromConstexpr_intptr_constexpr_int31_0(state_, 28);
    tmp55 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{tmp53, tmp54});
    tmp56 = UnsafeCast_Map_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp55});
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 28);
    tmp57 = CodeStubAssembler(state_).AllocateJSObjectFromMap(TNode<Map>{tmp56});
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 32);
    tmp58 = CodeStubAssembler(state_).StringConstant("status");
    tmp59 = CodeStubAssembler(state_).StringConstant("fulfilled");
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 31);
    tmp60 = ca_.CallStub<Object>(Builtins::CallableFor(ca_.isolate(), Builtin::kFastCreateDataProperty), p_context, tmp57, tmp58, tmp59);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 35);
    tmp61 = CodeStubAssembler(state_).StringConstant("value");
    tmp62 = ca_.CallStub<Object>(Builtins::CallableFor(ca_.isolate(), Builtin::kFastCreateDataProperty), p_context, tmp57, tmp61, p_value);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 159);
    std::tie(tmp63, tmp64, tmp65) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray>{phi_bb17_8}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 89);
    tmp66 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp16});
    tmp67 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp65});
    tmp68 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp66}, TNode<UintPtrT>{tmp67});
    ca_.Branch(tmp68, &block35, std::vector<compiler::Node*>{}, &block36, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp69;
  TNode<IntPtrT> tmp70;
  TNode<Object> tmp71;
  TNode<IntPtrT> tmp72;
  TNode<Smi> tmp73;
  TNode<Smi> tmp74;
  TNode<Smi> tmp75;
  TNode<BoolT> tmp76;
  if (block35.is_used()) {
    ca_.Bind(&block35);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 97);
    tmp69 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{tmp16});
    tmp70 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp64}, TNode<IntPtrT>{tmp69});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 96);
    std::tie(tmp71, tmp72) = NewReference_Object_0(state_, TNode<Object>{tmp63}, TNode<IntPtrT>{tmp70}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 159);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp71, tmp72}, tmp57);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 161);
    tmp73 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp74 = CodeStubAssembler(state_).SmiSub(TNode<Smi>{tmp20}, TNode<Smi>{tmp73});
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 162);
    tmp75 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp76 = CodeStubAssembler(state_).SmiGreaterThanOrEqual(TNode<Smi>{tmp74}, TNode<Smi>{tmp75});
    ca_.Branch(tmp76, &block39, std::vector<compiler::Node*>{}, &block40, std::vector<compiler::Node*>{});
  }

  if (block36.is_used()) {
    ca_.Bind(&block36);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 101);
    CodeStubAssembler(state_).PrintErr("halting because of unreachable code at src/builtins/torque-internal.tq:101:45");
    CodeStubAssembler(state_).Unreachable();
  }

  if (block40.is_used()) {
    ca_.Bind(&block40);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 162);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/promise-all-element-closure.tq", 162});
      CodeStubAssembler(state_).FailAssert("Torque assert 'remainingElementsCount >= 0' failed", pos_stack);
    }
  }

  TNode<IntPtrT> tmp77;
  TNode<Object> tmp78;
  TNode<IntPtrT> tmp79;
  TNode<Smi> tmp80;
  TNode<BoolT> tmp81;
  if (block39.is_used()) {
    ca_.Bind(&block39);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 166);
    tmp77 = kPromiseAllResolveElementRemainingSlot_0(state_);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 164);
    std::tie(tmp78, tmp79) = ContextSlot_PromiseAllResolveElementContext_PromiseAllResolveElementContext_Smi_0(state_, TNode<Context>{ca_.UncheckedCast<Context>(p_context)}, TNode<IntPtrT>{tmp77}).Flatten();
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{tmp78, tmp79}, tmp74);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 168);
    tmp80 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp81 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp74}, TNode<Smi>{tmp80});
    ca_.Branch(tmp81, &block41, std::vector<compiler::Node*>{}, &block42, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp82;
  TNode<Object> tmp83;
  TNode<IntPtrT> tmp84;
  TNode<PromiseCapability> tmp85;
  TNode<IntPtrT> tmp86;
  TNode<Object> tmp87;
  TNode<Object> tmp88;
  TNode<IntPtrT> tmp89;
  TNode<Object> tmp90;
  TNode<IntPtrT> tmp91;
  TNode<Map> tmp92;
  TNode<BoolT> tmp93;
  if (block41.is_used()) {
    ca_.Bind(&block41);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 171);
    tmp82 = kPromiseAllResolveElementCapabilitySlot_0(state_);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 169);
    std::tie(tmp83, tmp84) = ContextSlot_PromiseAllResolveElementContext_PromiseAllResolveElementContext_PromiseCapability_0(state_, TNode<Context>{ca_.UncheckedCast<Context>(p_context)}, TNode<IntPtrT>{tmp82}).Flatten();
    tmp85 = CodeStubAssembler(state_).LoadReference<PromiseCapability>(CodeStubAssembler::Reference{tmp83, tmp84});
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 173);
    tmp86 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp87 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp85, tmp86});
    tmp88 = UnsafeCast_JSAny_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp87});
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 176);
    tmp89 = JS_ARRAY_PACKED_ELEMENTS_MAP_INDEX_0(state_);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 175);
    std::tie(tmp90, tmp91) = NativeContextSlot_Map_1(state_, TNode<NativeContext>{tmp8}, TNode<IntPtrT>{tmp89}).Flatten();
    tmp92 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference{tmp90, tmp91});
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 181);
    tmp93 = FromConstexpr_bool_constexpr_bool_0(state_, p_hasResolveAndRejectClosures);
    ca_.Branch(tmp93, &block43, std::vector<compiler::Node*>{}, &block44, std::vector<compiler::Node*>{});
  }

  if (block43.is_used()) {
    ca_.Bind(&block43);
    CodeStubAssembler(state_).MakeFixedArrayCOW(TNode<FixedArray>{phi_bb17_8});
    ca_.Goto(&block44);
  }

  TNode<JSArray> tmp94;
  TNode<Oddball> tmp95;
  TNode<Object> tmp96;
  if (block44.is_used()) {
    ca_.Bind(&block44);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 183);
    tmp94 = NewJSArray_0(state_, TNode<Context>{p_context}, TNode<Map>{tmp92}, TNode<FixedArrayBase>{phi_bb17_8});
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 184);
    tmp95 = Undefined_0(state_);
    tmp96 = CodeStubAssembler(state_).Call(TNode<Context>{ca_.UncheckedCast<Context>(p_context)}, TNode<Object>{tmp88}, TNode<Object>{tmp95}, TNode<Object>{tmp94});
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 168);
    ca_.Goto(&block42);
  }

  TNode<Oddball> tmp97;
  if (block42.is_used()) {
    ca_.Bind(&block42);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 186);
    tmp97 = Undefined_0(state_);
    ca_.Goto(&block1, tmp97);
  }

  TNode<Object> phi_bb1_3;
  if (block1.is_used()) {
    ca_.Bind(&block1, &phi_bb1_3);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 205);
    ca_.Goto(&block45, phi_bb1_3);
  }

  TNode<Object> phi_bb45_3;
    ca_.Bind(&block45, &phi_bb45_3);
  return TNode<Object>{phi_bb45_3};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-all-element-closure.tq?l=215&c=10
TNode<Object> PromiseAllResolveElementClosure_PromiseAllSettledWrapResultAsRejectedFunctor_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_value, TNode<JSFunction> p_function, TorqueStructPromiseAllSettledWrapResultAsRejectedFunctor_0 p_wrapResultFunctor, bool p_hasResolveAndRejectClosures) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block26(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block27(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block20(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block35(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block36(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block40(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block39(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block41(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block43(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block44(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block42(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block45(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<NativeContext> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 98);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = Cast_NativeContext_0(state_, TNode<HeapObject>{p_context}, &label1);
    ca_.Goto(&block4);
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block5);
    }
  }

  TNode<IntPtrT> tmp2;
  TNode<Smi> tmp3;
  TNode<IntPtrT> tmp4;
  TNode<Smi> tmp5;
  TNode<BoolT> tmp6;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 107);
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp3 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{ca_.UncheckedCast<Context>(p_context), tmp2});
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 108);
    tmp4 = FromConstexpr_intptr_constexpr_intptr_0(state_, PromiseBuiltins::PromiseAllResolveElementContextSlots::kPromiseAllResolveElementLength);
    tmp5 = CodeStubAssembler(state_).SmiTag(TNode<IntPtrT>{tmp4});
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 107);
    tmp6 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp3}, TNode<Smi>{tmp5});
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 106);
    ca_.Branch(tmp6, &block6, std::vector<compiler::Node*>{}, &block7, std::vector<compiler::Node*>{});
  }

  TNode<Oddball> tmp7;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 99);
    tmp7 = Undefined_0(state_);
    ca_.Goto(&block1, tmp7);
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 106);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/promise-all-element-closure.tq", 106});
      CodeStubAssembler(state_).FailAssert("Torque assert 'promiseContext.length == SmiTag(PromiseAllResolveElementContextSlots:: kPromiseAllResolveElementLength)' failed", pos_stack);
    }
  }

  TNode<NativeContext> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<BoolT> tmp10;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 110);
    tmp8 = CodeStubAssembler(state_).LoadNativeContext(TNode<Context>{ca_.UncheckedCast<Context>(p_context)});
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 111);
    tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    CodeStubAssembler(state_).StoreReference<Context>(CodeStubAssembler::Reference{p_function, tmp9}, tmp8);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 114);
    tmp10 = FromConstexpr_bool_constexpr_bool_0(state_, (CodeStubAssembler(state_).ConstexprInt31Equal(PropertyArray::kNoHashSentinel, (FromConstexpr_constexpr_int31_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull))))));
    ca_.Branch(tmp10, &block8, std::vector<compiler::Node*>{}, &block9, std::vector<compiler::Node*>{});
  }

  if (block9.is_used()) {
    ca_.Bind(&block9);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/promise-all-element-closure.tq", 114});
      CodeStubAssembler(state_).FailAssert("Torque assert 'kPropertyArrayNoHashSentinel == 0' failed", pos_stack);
    }
  }

  TNode<IntPtrT> tmp11;
  if (block8.is_used()) {
    ca_.Bind(&block8);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 116);
    compiler::CodeAssemblerLabel label12(&ca_);
    tmp11 = CodeStubAssembler(state_).LoadJSReceiverIdentityHash(TNode<JSReceiver>{p_function}, &label12);
    ca_.Goto(&block12);
    if (label12.is_used()) {
      ca_.Bind(&label12);
      ca_.Goto(&block13);
    }
  }

  if (block13.is_used()) {
    ca_.Bind(&block13);
    CodeStubAssembler(state_).PrintErr("halting because of unreachable code at src/builtins/promise-all-element-closure.tq:116:54");
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<IntPtrT> tmp13;
  TNode<BoolT> tmp14;
  if (block12.is_used()) {
    ca_.Bind(&block12);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 117);
    tmp13 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp14 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{tmp11}, TNode<IntPtrT>{tmp13});
    ca_.Branch(tmp14, &block14, std::vector<compiler::Node*>{}, &block15, std::vector<compiler::Node*>{});
  }

  if (block15.is_used()) {
    ca_.Bind(&block15);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/promise-all-element-closure.tq", 117});
      CodeStubAssembler(state_).FailAssert("Torque assert 'identityHash > 0' failed", pos_stack);
    }
  }

  TNode<IntPtrT> tmp15;
  TNode<IntPtrT> tmp16;
  TNode<IntPtrT> tmp17;
  TNode<Object> tmp18;
  TNode<IntPtrT> tmp19;
  TNode<Smi> tmp20;
  TNode<IntPtrT> tmp21;
  TNode<Object> tmp22;
  TNode<IntPtrT> tmp23;
  TNode<FixedArray> tmp24;
  TNode<IntPtrT> tmp25;
  TNode<IntPtrT> tmp26;
  TNode<IntPtrT> tmp27;
  TNode<BoolT> tmp28;
  if (block14.is_used()) {
    ca_.Bind(&block14);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 118);
    tmp15 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp16 = CodeStubAssembler(state_).IntPtrSub(TNode<IntPtrT>{tmp11}, TNode<IntPtrT>{tmp15});
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 122);
    tmp17 = kPromiseAllResolveElementRemainingSlot_0(state_);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 120);
    std::tie(tmp18, tmp19) = ContextSlot_PromiseAllResolveElementContext_PromiseAllResolveElementContext_Smi_0(state_, TNode<Context>{ca_.UncheckedCast<Context>(p_context)}, TNode<IntPtrT>{tmp17}).Flatten();
    tmp20 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp18, tmp19});
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 127);
    tmp21 = kPromiseAllResolveElementValuesSlot_0(state_);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 125);
    std::tie(tmp22, tmp23) = ContextSlot_PromiseAllResolveElementContext_PromiseAllResolveElementContext_FixedArray_0(state_, TNode<Context>{ca_.UncheckedCast<Context>(p_context)}, TNode<IntPtrT>{tmp21}).Flatten();
    tmp24 = CodeStubAssembler(state_).LoadReference<FixedArray>(CodeStubAssembler::Reference{tmp22, tmp23});
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 129);
    tmp25 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp26 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp16}, TNode<IntPtrT>{tmp25});
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 130);
    tmp27 = CodeStubAssembler(state_).LoadAndUntagFixedArrayBaseLength(TNode<FixedArrayBase>{tmp24});
    tmp28 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{tmp26}, TNode<IntPtrT>{tmp27});
    ca_.Branch(tmp28, &block16, std::vector<compiler::Node*>{}, &block17, std::vector<compiler::Node*>{tmp24});
  }

  TNode<IntPtrT> tmp29;
  TNode<IntPtrT> tmp30;
  TNode<FixedArray> tmp31;
  TNode<IntPtrT> tmp32;
  TNode<Object> tmp33;
  TNode<IntPtrT> tmp34;
  if (block16.is_used()) {
    ca_.Bind(&block16);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 132);
    tmp29 = CodeStubAssembler(state_).LoadAndUntagFixedArrayBaseLength(TNode<FixedArrayBase>{tmp24});
    tmp30 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp31 = ExtractFixedArray_0(state_, TNode<FixedArray>{tmp24}, TNode<IntPtrT>{tmp30}, TNode<IntPtrT>{tmp29}, TNode<IntPtrT>{tmp26});
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 135);
    tmp32 = kPromiseAllResolveElementValuesSlot_0(state_);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 133);
    std::tie(tmp33, tmp34) = ContextSlot_PromiseAllResolveElementContext_PromiseAllResolveElementContext_FixedArray_0(state_, TNode<Context>{ca_.UncheckedCast<Context>(p_context)}, TNode<IntPtrT>{tmp32}).Flatten();
    CodeStubAssembler(state_).StoreReference<FixedArray>(CodeStubAssembler::Reference{tmp33, tmp34}, tmp31);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 130);
    ca_.Goto(&block17, tmp31);
  }

  TNode<FixedArray> phi_bb17_8;
  TNode<BoolT> tmp35;
  if (block17.is_used()) {
    ca_.Bind(&block17, &phi_bb17_8);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 149);
    tmp35 = FromConstexpr_bool_constexpr_bool_0(state_, p_hasResolveAndRejectClosures);
    ca_.Branch(tmp35, &block18, std::vector<compiler::Node*>{}, &block19, std::vector<compiler::Node*>{});
  }

  TNode<Object> tmp36;
  TNode<IntPtrT> tmp37;
  TNode<IntPtrT> tmp38;
  TNode<UintPtrT> tmp39;
  TNode<UintPtrT> tmp40;
  TNode<BoolT> tmp41;
  if (block18.is_used()) {
    ca_.Bind(&block18);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 150);
    std::tie(tmp36, tmp37, tmp38) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray>{phi_bb17_8}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 89);
    tmp39 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp16});
    tmp40 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp38});
    tmp41 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp39}, TNode<UintPtrT>{tmp40});
    ca_.Branch(tmp41, &block26, std::vector<compiler::Node*>{}, &block27, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp42;
  TNode<IntPtrT> tmp43;
  TNode<Object> tmp44;
  TNode<IntPtrT> tmp45;
  TNode<Object> tmp46;
  TNode<Oddball> tmp47;
  TNode<BoolT> tmp48;
  if (block26.is_used()) {
    ca_.Bind(&block26);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 97);
    tmp42 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{tmp16});
    tmp43 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp37}, TNode<IntPtrT>{tmp42});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 96);
    std::tie(tmp44, tmp45) = NewReference_Object_0(state_, TNode<Object>{tmp36}, TNode<IntPtrT>{tmp43}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 150);
    tmp46 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp44, tmp45});
    tmp47 = TheHole_0(state_);
    tmp48 = CodeStubAssembler(state_).TaggedNotEqual(TNode<Object>{tmp46}, TNode<HeapObject>{tmp47});
    ca_.Branch(tmp48, &block20, std::vector<compiler::Node*>{}, &block21, std::vector<compiler::Node*>{});
  }

  if (block27.is_used()) {
    ca_.Bind(&block27);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 101);
    CodeStubAssembler(state_).PrintErr("halting because of unreachable code at src/builtins/torque-internal.tq:101:45");
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<Oddball> tmp49;
  if (block20.is_used()) {
    ca_.Bind(&block20);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 151);
    tmp49 = Undefined_0(state_);
    ca_.Goto(&block1, tmp49);
  }

  if (block21.is_used()) {
    ca_.Bind(&block21);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 149);
    ca_.Goto(&block19);
  }

  TNode<IntPtrT> tmp50;
  TNode<Object> tmp51;
  TNode<IntPtrT> tmp52;
  TNode<JSFunction> tmp53;
  TNode<IntPtrT> tmp54;
  TNode<HeapObject> tmp55;
  TNode<Map> tmp56;
  TNode<JSObject> tmp57;
  TNode<String> tmp58;
  TNode<String> tmp59;
  TNode<Object> tmp60;
  TNode<String> tmp61;
  TNode<Object> tmp62;
  TNode<Object> tmp63;
  TNode<IntPtrT> tmp64;
  TNode<IntPtrT> tmp65;
  TNode<UintPtrT> tmp66;
  TNode<UintPtrT> tmp67;
  TNode<BoolT> tmp68;
  if (block19.is_used()) {
    ca_.Bind(&block19);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 48);
    tmp50 = OBJECT_FUNCTION_INDEX_0(state_);
    std::tie(tmp51, tmp52) = NativeContextSlot_JSFunction_0(state_, TNode<NativeContext>{tmp8}, TNode<IntPtrT>{tmp50}).Flatten();
    tmp53 = CodeStubAssembler(state_).LoadReference<JSFunction>(CodeStubAssembler::Reference{tmp51, tmp52});
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 50);
    tmp54 = FromConstexpr_intptr_constexpr_int31_0(state_, 28);
    tmp55 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{tmp53, tmp54});
    tmp56 = UnsafeCast_Map_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp55});
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 51);
    tmp57 = CodeStubAssembler(state_).AllocateJSObjectFromMap(TNode<Map>{tmp56});
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 55);
    tmp58 = CodeStubAssembler(state_).StringConstant("status");
    tmp59 = CodeStubAssembler(state_).StringConstant("rejected");
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 54);
    tmp60 = ca_.CallStub<Object>(Builtins::CallableFor(ca_.isolate(), Builtin::kFastCreateDataProperty), p_context, tmp57, tmp58, tmp59);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 58);
    tmp61 = CodeStubAssembler(state_).StringConstant("reason");
    tmp62 = ca_.CallStub<Object>(Builtins::CallableFor(ca_.isolate(), Builtin::kFastCreateDataProperty), p_context, tmp57, tmp61, p_value);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 159);
    std::tie(tmp63, tmp64, tmp65) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray>{phi_bb17_8}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 89);
    tmp66 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp16});
    tmp67 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp65});
    tmp68 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp66}, TNode<UintPtrT>{tmp67});
    ca_.Branch(tmp68, &block35, std::vector<compiler::Node*>{}, &block36, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp69;
  TNode<IntPtrT> tmp70;
  TNode<Object> tmp71;
  TNode<IntPtrT> tmp72;
  TNode<Smi> tmp73;
  TNode<Smi> tmp74;
  TNode<Smi> tmp75;
  TNode<BoolT> tmp76;
  if (block35.is_used()) {
    ca_.Bind(&block35);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 97);
    tmp69 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{tmp16});
    tmp70 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp64}, TNode<IntPtrT>{tmp69});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 96);
    std::tie(tmp71, tmp72) = NewReference_Object_0(state_, TNode<Object>{tmp63}, TNode<IntPtrT>{tmp70}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 159);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp71, tmp72}, tmp57);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 161);
    tmp73 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp74 = CodeStubAssembler(state_).SmiSub(TNode<Smi>{tmp20}, TNode<Smi>{tmp73});
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 162);
    tmp75 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp76 = CodeStubAssembler(state_).SmiGreaterThanOrEqual(TNode<Smi>{tmp74}, TNode<Smi>{tmp75});
    ca_.Branch(tmp76, &block39, std::vector<compiler::Node*>{}, &block40, std::vector<compiler::Node*>{});
  }

  if (block36.is_used()) {
    ca_.Bind(&block36);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 101);
    CodeStubAssembler(state_).PrintErr("halting because of unreachable code at src/builtins/torque-internal.tq:101:45");
    CodeStubAssembler(state_).Unreachable();
  }

  if (block40.is_used()) {
    ca_.Bind(&block40);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 162);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/promise-all-element-closure.tq", 162});
      CodeStubAssembler(state_).FailAssert("Torque assert 'remainingElementsCount >= 0' failed", pos_stack);
    }
  }

  TNode<IntPtrT> tmp77;
  TNode<Object> tmp78;
  TNode<IntPtrT> tmp79;
  TNode<Smi> tmp80;
  TNode<BoolT> tmp81;
  if (block39.is_used()) {
    ca_.Bind(&block39);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 166);
    tmp77 = kPromiseAllResolveElementRemainingSlot_0(state_);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 164);
    std::tie(tmp78, tmp79) = ContextSlot_PromiseAllResolveElementContext_PromiseAllResolveElementContext_Smi_0(state_, TNode<Context>{ca_.UncheckedCast<Context>(p_context)}, TNode<IntPtrT>{tmp77}).Flatten();
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{tmp78, tmp79}, tmp74);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 168);
    tmp80 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp81 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp74}, TNode<Smi>{tmp80});
    ca_.Branch(tmp81, &block41, std::vector<compiler::Node*>{}, &block42, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp82;
  TNode<Object> tmp83;
  TNode<IntPtrT> tmp84;
  TNode<PromiseCapability> tmp85;
  TNode<IntPtrT> tmp86;
  TNode<Object> tmp87;
  TNode<Object> tmp88;
  TNode<IntPtrT> tmp89;
  TNode<Object> tmp90;
  TNode<IntPtrT> tmp91;
  TNode<Map> tmp92;
  TNode<BoolT> tmp93;
  if (block41.is_used()) {
    ca_.Bind(&block41);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 171);
    tmp82 = kPromiseAllResolveElementCapabilitySlot_0(state_);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 169);
    std::tie(tmp83, tmp84) = ContextSlot_PromiseAllResolveElementContext_PromiseAllResolveElementContext_PromiseCapability_0(state_, TNode<Context>{ca_.UncheckedCast<Context>(p_context)}, TNode<IntPtrT>{tmp82}).Flatten();
    tmp85 = CodeStubAssembler(state_).LoadReference<PromiseCapability>(CodeStubAssembler::Reference{tmp83, tmp84});
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 173);
    tmp86 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp87 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp85, tmp86});
    tmp88 = UnsafeCast_JSAny_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp87});
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 176);
    tmp89 = JS_ARRAY_PACKED_ELEMENTS_MAP_INDEX_0(state_);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 175);
    std::tie(tmp90, tmp91) = NativeContextSlot_Map_1(state_, TNode<NativeContext>{tmp8}, TNode<IntPtrT>{tmp89}).Flatten();
    tmp92 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference{tmp90, tmp91});
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 181);
    tmp93 = FromConstexpr_bool_constexpr_bool_0(state_, p_hasResolveAndRejectClosures);
    ca_.Branch(tmp93, &block43, std::vector<compiler::Node*>{}, &block44, std::vector<compiler::Node*>{});
  }

  if (block43.is_used()) {
    ca_.Bind(&block43);
    CodeStubAssembler(state_).MakeFixedArrayCOW(TNode<FixedArray>{phi_bb17_8});
    ca_.Goto(&block44);
  }

  TNode<JSArray> tmp94;
  TNode<Oddball> tmp95;
  TNode<Object> tmp96;
  if (block44.is_used()) {
    ca_.Bind(&block44);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 183);
    tmp94 = NewJSArray_0(state_, TNode<Context>{p_context}, TNode<Map>{tmp92}, TNode<FixedArrayBase>{phi_bb17_8});
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 184);
    tmp95 = Undefined_0(state_);
    tmp96 = CodeStubAssembler(state_).Call(TNode<Context>{ca_.UncheckedCast<Context>(p_context)}, TNode<Object>{tmp88}, TNode<Object>{tmp95}, TNode<Object>{tmp94});
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 168);
    ca_.Goto(&block42);
  }

  TNode<Oddball> tmp97;
  if (block42.is_used()) {
    ca_.Bind(&block42);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 186);
    tmp97 = Undefined_0(state_);
    ca_.Goto(&block1, tmp97);
  }

  TNode<Object> phi_bb1_3;
  if (block1.is_used()) {
    ca_.Bind(&block1, &phi_bb1_3);
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 215);
    ca_.Goto(&block45, phi_bb1_3);
  }

  TNode<Object> phi_bb45_3;
    ca_.Bind(&block45, &phi_bb45_3);
  return TNode<Object>{phi_bb45_3};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-all-element-closure.tq?l=120&c=33
TorqueStructReference_Smi_0 ContextSlot_PromiseAllResolveElementContext_PromiseAllResolveElementContext_Smi_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<IntPtrT> p_index) {
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
  TNode<UintPtrT> tmp4;
  TNode<BoolT> tmp5;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/objects/contexts.tq", 74);
    std::tie(tmp0, tmp1, tmp2) = FieldSliceContextElements_0(state_, TNode<Context>{p_context}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 89);
    tmp3 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{p_index});
    tmp4 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp2});
    tmp5 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp3}, TNode<UintPtrT>{tmp4});
    ca_.Branch(tmp5, &block6, std::vector<compiler::Node*>{}, &block7, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<Object> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<Object> tmp10;
  TNode<IntPtrT> tmp11;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 97);
    tmp6 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{p_index});
    tmp7 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp6});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 96);
    std::tie(tmp8, tmp9) = NewReference_Object_0(state_, TNode<Object>{tmp0}, TNode<IntPtrT>{tmp7}).Flatten();
    ca_.SetSourcePosition("../../../src/objects/contexts.tq", 74);
    std::tie(tmp10, tmp11) = ReferenceCast_Smi_Object_0(state_, TorqueStructReference_Object_0{TNode<Object>{tmp8}, TNode<IntPtrT>{tmp9}, TorqueStructUnsafe_0{}}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 120);
    ca_.Goto(&block10);
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 101);
    CodeStubAssembler(state_).PrintErr("halting because of unreachable code at src/builtins/torque-internal.tq:101:45");
    CodeStubAssembler(state_).Unreachable();
  }

    ca_.Bind(&block10);
  return TorqueStructReference_Smi_0{TNode<Object>{tmp10}, TNode<IntPtrT>{tmp11}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-all-element-closure.tq?l=125&c=17
TorqueStructReference_FixedArray_0 ContextSlot_PromiseAllResolveElementContext_PromiseAllResolveElementContext_FixedArray_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<IntPtrT> p_index) {
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
  TNode<UintPtrT> tmp4;
  TNode<BoolT> tmp5;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/objects/contexts.tq", 74);
    std::tie(tmp0, tmp1, tmp2) = FieldSliceContextElements_0(state_, TNode<Context>{p_context}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 89);
    tmp3 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{p_index});
    tmp4 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp2});
    tmp5 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp3}, TNode<UintPtrT>{tmp4});
    ca_.Branch(tmp5, &block6, std::vector<compiler::Node*>{}, &block7, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<Object> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<Object> tmp10;
  TNode<IntPtrT> tmp11;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 97);
    tmp6 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{p_index});
    tmp7 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp6});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 96);
    std::tie(tmp8, tmp9) = NewReference_Object_0(state_, TNode<Object>{tmp0}, TNode<IntPtrT>{tmp7}).Flatten();
    ca_.SetSourcePosition("../../../src/objects/contexts.tq", 74);
    std::tie(tmp10, tmp11) = ReferenceCast_FixedArray_Object_0(state_, TorqueStructReference_Object_0{TNode<Object>{tmp8}, TNode<IntPtrT>{tmp9}, TorqueStructUnsafe_0{}}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 125);
    ca_.Goto(&block10);
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 101);
    CodeStubAssembler(state_).PrintErr("halting because of unreachable code at src/builtins/torque-internal.tq:101:45");
    CodeStubAssembler(state_).Unreachable();
  }

    ca_.Bind(&block10);
  return TorqueStructReference_FixedArray_0{TNode<Object>{tmp10}, TNode<IntPtrT>{tmp11}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-all-element-closure.tq?l=169&c=25
TorqueStructReference_PromiseCapability_0 ContextSlot_PromiseAllResolveElementContext_PromiseAllResolveElementContext_PromiseCapability_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<IntPtrT> p_index) {
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
  TNode<UintPtrT> tmp4;
  TNode<BoolT> tmp5;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/objects/contexts.tq", 74);
    std::tie(tmp0, tmp1, tmp2) = FieldSliceContextElements_0(state_, TNode<Context>{p_context}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 89);
    tmp3 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{p_index});
    tmp4 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp2});
    tmp5 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp3}, TNode<UintPtrT>{tmp4});
    ca_.Branch(tmp5, &block6, std::vector<compiler::Node*>{}, &block7, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<Object> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<Object> tmp10;
  TNode<IntPtrT> tmp11;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 97);
    tmp6 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{p_index});
    tmp7 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp6});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 96);
    std::tie(tmp8, tmp9) = NewReference_Object_0(state_, TNode<Object>{tmp0}, TNode<IntPtrT>{tmp7}).Flatten();
    ca_.SetSourcePosition("../../../src/objects/contexts.tq", 74);
    std::tie(tmp10, tmp11) = ReferenceCast_PromiseCapability_Object_0(state_, TorqueStructReference_Object_0{TNode<Object>{tmp8}, TNode<IntPtrT>{tmp9}, TorqueStructUnsafe_0{}}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/promise-all-element-closure.tq", 169);
    ca_.Goto(&block10);
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 101);
    CodeStubAssembler(state_).PrintErr("halting because of unreachable code at src/builtins/torque-internal.tq:101:45");
    CodeStubAssembler(state_).Unreachable();
  }

    ca_.Bind(&block10);
  return TorqueStructReference_PromiseCapability_0{TNode<Object>{tmp10}, TNode<IntPtrT>{tmp11}, TorqueStructUnsafe_0{}};
}

} // namespace internal
} // namespace v8
