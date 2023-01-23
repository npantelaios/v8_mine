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
#include "torque-generated/src/builtins/ic-callable-tq-csa.h"
#include "torque-generated/src/builtins/base-tq-csa.h"
#include "torque-generated/src/builtins/cast-tq-csa.h"
#include "torque-generated/src/builtins/convert-tq-csa.h"
#include "torque-generated/src/builtins/frames-tq-csa.h"
#include "torque-generated/src/builtins/ic-callable-tq-csa.h"
#include "torque-generated/src/builtins/ic-tq-csa.h"
#include "torque-generated/src/objects/feedback-vector-tq-csa.h"
#include "torque-generated/src/objects/js-function-tq-csa.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/ic-callable.tq?l=14&c=1
TNode<BoolT> IsMonomorphic_0(compiler::CodeAssemblerState* state_, TNode<MaybeObject> p_feedback, TNode<Object> p_target) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<BoolT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 15);
    tmp0 = CodeStubAssembler(state_).IsWeakReferenceToObject(TNode<MaybeObject>{p_feedback}, TNode<Object>{p_target});
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 14);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<BoolT>{tmp0};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/ic-callable.tq?l=18&c=1
TNode<BoolT> InSameNativeContext_0(compiler::CodeAssemblerState* state_, TNode<Context> p_lhs, TNode<Context> p_rhs) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<NativeContext> tmp0;
  TNode<NativeContext> tmp1;
  TNode<BoolT> tmp2;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 19);
    tmp0 = CodeStubAssembler(state_).LoadNativeContext(TNode<Context>{p_lhs});
    tmp1 = CodeStubAssembler(state_).LoadNativeContext(TNode<Context>{p_rhs});
    tmp2 = CodeStubAssembler(state_).TaggedEqual(TNode<HeapObject>{tmp0}, TNode<HeapObject>{tmp1});
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 18);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<BoolT>{tmp2};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/ic-callable.tq?l=22&c=1
TNode<HeapObject> MaybeObjectToStrong_0(compiler::CodeAssemblerState* state_, TNode<MaybeObject> p_maybeObject, compiler::CodeAssemblerLabel* label_IfCleared) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<BoolT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 24);
    tmp0 = CodeStubAssembler(state_).IsWeakOrCleared(TNode<MaybeObject>{p_maybeObject});
    ca_.Branch(tmp0, &block3, std::vector<compiler::Node*>{}, &block4, std::vector<compiler::Node*>{});
  }

  if (block4.is_used()) {
    ca_.Bind(&block4);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/ic-callable.tq", 24});
      CodeStubAssembler(state_).FailAssert("Torque assert 'IsWeakOrCleared(maybeObject)' failed", pos_stack);
    }
  }

  TNode<MaybeObject> tmp1;
  TNode<HeapObject> tmp2;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 25);
    tmp1 = (TNode<MaybeObject>{p_maybeObject});
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 26);
    compiler::CodeAssemblerLabel label3(&ca_);
    tmp2 = WeakToStrong_HeapObject_0(state_, TNode<MaybeObject>{tmp1}, &label3);
    ca_.Goto(&block5);
    if (label3.is_used()) {
      ca_.Bind(&label3);
      ca_.Goto(&block6);
    }
  }

  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 22);
    ca_.Goto(label_IfCleared);
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    ca_.Goto(&block7);
  }

    ca_.Bind(&block7);
  return TNode<HeapObject>{tmp2};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/ic-callable.tq?l=29&c=1
void TryInitializeAsMonomorphic_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_maybeTarget, TNode<FeedbackVector> p_feedbackVector, TNode<UintPtrT> p_slotId, compiler::CodeAssemblerLabel* label_TransitionToMegamorphic) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, HeapObject> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, HeapObject> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<HeapObject> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 33);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = Cast_HeapObject_1(state_, TNode<Context>{p_context}, TNode<Object>{p_maybeTarget}, &label1);
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

  if (block3.is_used()) {
    ca_.Bind(&block3);
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 36);
    ca_.Goto(&block7, tmp0);
  }

  TNode<HeapObject> phi_bb7_5;
  TNode<BoolT> tmp2;
  if (block7.is_used()) {
    ca_.Bind(&block7, &phi_bb7_5);
    tmp2 = Is_JSBoundFunction_HeapObject_0(state_, TNode<Context>{p_context}, TNode<HeapObject>{phi_bb7_5});
    ca_.Branch(tmp2, &block5, std::vector<compiler::Node*>{phi_bb7_5}, &block6, std::vector<compiler::Node*>{phi_bb7_5});
  }

  TNode<HeapObject> phi_bb5_5;
  TNode<JSBoundFunction> tmp3;
  TNode<IntPtrT> tmp4;
  TNode<JSReceiver> tmp5;
  if (block5.is_used()) {
    ca_.Bind(&block5, &phi_bb5_5);
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 38);
    tmp3 = UnsafeCast_JSBoundFunction_0(state_, TNode<Context>{p_context}, TNode<Object>{phi_bb5_5});
    tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp5 = CodeStubAssembler(state_).LoadReference<JSReceiver>(CodeStubAssembler::Reference{tmp3, tmp4});
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 36);
    ca_.Goto(&block7, tmp5);
  }

  TNode<HeapObject> phi_bb6_5;
  TNode<JSFunction> tmp6;
  if (block6.is_used()) {
    ca_.Bind(&block6, &phi_bb6_5);
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 42);
    compiler::CodeAssemblerLabel label7(&ca_);
    tmp6 = Cast_JSFunction_0(state_, TNode<HeapObject>{phi_bb6_5}, &label7);
    ca_.Goto(&block8, phi_bb6_5, phi_bb6_5);
    if (label7.is_used()) {
      ca_.Bind(&label7);
      ca_.Goto(&block9, phi_bb6_5, phi_bb6_5);
    }
  }

  TNode<HeapObject> phi_bb9_5;
  TNode<HeapObject> phi_bb9_6;
  if (block9.is_used()) {
    ca_.Bind(&block9, &phi_bb9_5, &phi_bb9_6);
    ca_.Goto(&block1);
  }

  TNode<HeapObject> phi_bb8_5;
  TNode<HeapObject> phi_bb8_6;
  TNode<IntPtrT> tmp8;
  TNode<Context> tmp9;
  TNode<BoolT> tmp10;
  TNode<BoolT> tmp11;
  if (block8.is_used()) {
    ca_.Bind(&block8, &phi_bb8_5, &phi_bb8_6);
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 43);
    tmp8 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    tmp9 = CodeStubAssembler(state_).LoadReference<Context>(CodeStubAssembler::Reference{tmp6, tmp8});
    tmp10 = InSameNativeContext_0(state_, TNode<Context>{tmp9}, TNode<Context>{p_context});
    tmp11 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp10});
    ca_.Branch(tmp11, &block10, std::vector<compiler::Node*>{phi_bb8_5}, &block11, std::vector<compiler::Node*>{phi_bb8_5});
  }

  TNode<HeapObject> phi_bb10_5;
  if (block10.is_used()) {
    ca_.Bind(&block10, &phi_bb10_5);
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 44);
    ca_.Goto(&block1);
  }

  TNode<HeapObject> phi_bb11_5;
  TNode<MaybeObject> tmp12;
  if (block11.is_used()) {
    ca_.Bind(&block11, &phi_bb11_5);
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 47);
    tmp12 = CodeStubAssembler(state_).StoreWeakReferenceInFeedbackVector(TNode<FeedbackVector>{p_feedbackVector}, TNode<UintPtrT>{p_slotId}, TNode<HeapObject>{tmp0});
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 48);
    CodeStubAssembler(state_).ReportFeedbackUpdate(TNode<FeedbackVector>{p_feedbackVector}, TNode<UintPtrT>{p_slotId}, "Call:Initialize");
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 29);
    ca_.Goto(&block12);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_TransitionToMegamorphic);
  }

    ca_.Bind(&block12);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/ic-callable.tq?l=51&c=1
void TransitionToMegamorphic_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<FeedbackVector> p_feedbackVector, TNode<UintPtrT> p_slotId) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Symbol> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 53);
    tmp0 = kMegamorphicSymbol_0(state_);
    CodeStubAssembler(state_).StoreFeedbackVectorSlot(TNode<FeedbackVector>{p_feedbackVector}, TNode<UintPtrT>{p_slotId}, TNode<MaybeObject>{tmp0});
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 54);
    CodeStubAssembler(state_).ReportFeedbackUpdate(TNode<FeedbackVector>{p_feedbackVector}, TNode<UintPtrT>{p_slotId}, "Call:TransitionMegamorphic");
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 51);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/ic-callable.tq?l=57&c=1
TNode<BoolT> TaggedEqualPrototypeApplyFunction_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_target) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<JSFunction> tmp0;
  TNode<BoolT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 59);
    tmp0 = GetPrototypeApplyFunction_0(state_, TNode<Context>{p_context});
    tmp1 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{p_target}, TNode<HeapObject>{tmp0});
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 57);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<BoolT>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/ic-callable.tq?l=62&c=1
TNode<BoolT> FeedbackValueIsReceiver_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<FeedbackVector> p_feedbackVector, TNode<UintPtrT> p_slotId) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<MaybeObject> tmp0;
  TNode<Smi> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 64);
    tmp0 = CodeStubAssembler(state_).LoadFeedbackVectorSlot(TNode<FeedbackVector>{p_feedbackVector}, TNode<UintPtrT>{p_slotId}, kTaggedSize);
    compiler::CodeAssemblerLabel label2(&ca_);
    tmp1 = Cast_Smi_1(state_, TNode<Context>{p_context}, TNode<MaybeObject>{tmp0}, &label2);
    ca_.Goto(&block4);
    if (label2.is_used()) {
      ca_.Bind(&label2);
      ca_.Goto(&block5);
    }
  }

  TNode<BoolT> tmp3;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 65);
    tmp3 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp3);
  }

  TNode<IntPtrT> tmp4;
  TNode<IntPtrT> tmp5;
  TNode<IntPtrT> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<BoolT> tmp8;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 64);
    tmp4 = CodeStubAssembler(state_).SmiUntag(TNode<Smi>{tmp1});
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 66);
    tmp5 = CodeStubAssembler(state_).IntPtrConstant(FeedbackNexus::CallFeedbackContentField::kMask);
    tmp6 = CodeStubAssembler(state_).WordAnd(TNode<IntPtrT>{tmp4}, TNode<IntPtrT>{tmp5});
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 67);
    tmp7 = IntPtrConstant_0(state_, IntegerLiteral(false, 0x0ull));
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 66);
    tmp8 = CodeStubAssembler(state_).WordNotEqual(TNode<IntPtrT>{tmp6}, TNode<IntPtrT>{tmp7});
    ca_.Goto(&block1, tmp8);
  }

  TNode<BoolT> phi_bb1_3;
  if (block1.is_used()) {
    ca_.Bind(&block1, &phi_bb1_3);
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 62);
    ca_.Goto(&block6);
  }

    ca_.Bind(&block6);
  return TNode<BoolT>{phi_bb1_3};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/ic-callable.tq?l=70&c=1
void SetCallFeedbackContent_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<FeedbackVector> p_feedbackVector, TNode<UintPtrT> p_slotId, CallFeedbackContent p_callFeedbackContent) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<MaybeObject> tmp0;
  TNode<Smi> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 74);
    tmp0 = CodeStubAssembler(state_).LoadFeedbackVectorSlot(TNode<FeedbackVector>{p_feedbackVector}, TNode<UintPtrT>{p_slotId}, kTaggedSize);
    compiler::CodeAssemblerLabel label2(&ca_);
    tmp1 = Cast_Smi_1(state_, TNode<Context>{p_context}, TNode<MaybeObject>{tmp0}, &label2);
    ca_.Goto(&block4);
    if (label2.is_used()) {
      ca_.Bind(&label2);
      ca_.Goto(&block5);
    }
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 75);
    ca_.Goto(&block1);
  }

  TNode<IntPtrT> tmp3;
  TNode<IntPtrT> tmp4;
  TNode<IntPtrT> tmp5;
  TNode<IntPtrT> tmp6;
  TNode<Uint32T> tmp7;
  TNode<Uint32T> tmp8;
  TNode<Uint32T> tmp9;
  TNode<Int32T> tmp10;
  TNode<IntPtrT> tmp11;
  TNode<IntPtrT> tmp12;
  TNode<Smi> tmp13;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 74);
    tmp3 = CodeStubAssembler(state_).SmiUntag(TNode<Smi>{tmp1});
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 80);
    tmp4 = CodeStubAssembler(state_).IntPtrConstant(FeedbackNexus::CallFeedbackContentField::kMask);
    tmp5 = CodeStubAssembler(state_).WordNot(TNode<IntPtrT>{tmp4});
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 81);
    tmp6 = CodeStubAssembler(state_).WordAnd(TNode<IntPtrT>{tmp3}, TNode<IntPtrT>{tmp5});
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 83);
    tmp7 = FromConstexpr_uint32_constexpr_uint32_0(state_, static_cast<uint32_t>(p_callFeedbackContent));
    tmp8 = FromConstexpr_uint32_constexpr_uint32_0(state_, FeedbackNexus::CallFeedbackContentField::kShift);
    tmp9 = CodeStubAssembler(state_).Word32Shl(TNode<Uint32T>{tmp7}, TNode<Uint32T>{tmp8});
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 82);
    tmp10 = CodeStubAssembler(state_).Signed(TNode<Uint32T>{tmp9});
    tmp11 = Convert_intptr_int32_0(state_, TNode<Int32T>{tmp10});
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 81);
    tmp12 = CodeStubAssembler(state_).WordOr(TNode<IntPtrT>{tmp6}, TNode<IntPtrT>{tmp11});
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 86);
    tmp13 = CodeStubAssembler(state_).SmiTag(TNode<IntPtrT>{tmp12});
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 85);
    CodeStubAssembler(state_).StoreFeedbackVectorSlot(TNode<FeedbackVector>{p_feedbackVector}, TNode<UintPtrT>{p_slotId}, TNode<MaybeObject>{tmp13}, SKIP_WRITE_BARRIER, kTaggedSize);
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 88);
    CodeStubAssembler(state_).ReportFeedbackUpdate(TNode<FeedbackVector>{p_feedbackVector}, TNode<UintPtrT>{p_slotId}, "Call:SetCallFeedbackContent");
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 70);
    ca_.Goto(&block1);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(&block6);
  }

    ca_.Bind(&block6);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/ic-callable.tq?l=91&c=1
void CollectCallFeedback_0(compiler::CodeAssemblerState* state_, TNode<Object> p_maybeTarget, std::function<TNode<Object>()> p_maybeReceiver, TNode<Context> p_context, TNode<HeapObject> p_maybeFeedbackVector, TNode<UintPtrT> p_slotId) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block27(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block28(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block29(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block25(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block30(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block31(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block34(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block33(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block26(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block36(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block35(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block37(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block38(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block40(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block39(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block41(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block42(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block43(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block44(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block47(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block46(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block45(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object> block49(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object> block48(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block50(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<BoolT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 98);
    tmp0 = CodeStubAssembler(state_).IsUndefined(TNode<Object>{p_maybeFeedbackVector});
    ca_.Branch(tmp0, &block4, std::vector<compiler::Node*>{}, &block5, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp1;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    tmp1 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block6, tmp1);
  }

  TNode<BoolT> tmp2;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 99);
    tmp2 = Is_FeedbackVector_Undefined_OR_FeedbackVector_0(state_, TNode<Context>{p_context}, TNode<HeapObject>{p_maybeFeedbackVector});
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 98);
    ca_.Goto(&block6, tmp2);
  }

  TNode<BoolT> phi_bb6_6;
  if (block6.is_used()) {
    ca_.Bind(&block6, &phi_bb6_6);
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 97);
    ca_.Branch(phi_bb6_6, &block2, std::vector<compiler::Node*>{}, &block3, std::vector<compiler::Node*>{});
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/ic-callable.tq", 97});
      CodeStubAssembler(state_).FailAssert("Torque assert 'IsUndefined(maybeFeedbackVector) || Is<FeedbackVector>(maybeFeedbackVector)' failed", pos_stack);
    }
  }

  TNode<FeedbackVector> tmp3;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 101);
    compiler::CodeAssemblerLabel label4(&ca_);
    tmp3 = Cast_FeedbackVector_0(state_, TNode<HeapObject>{p_maybeFeedbackVector}, &label4);
    ca_.Goto(&block9);
    if (label4.is_used()) {
      ca_.Bind(&label4);
      ca_.Goto(&block10);
    }
  }

  if (block10.is_used()) {
    ca_.Bind(&block10);
    ca_.Goto(&block1);
  }

  TNode<MaybeObject> tmp5;
  TNode<BoolT> tmp6;
  if (block9.is_used()) {
    ca_.Bind(&block9);
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 102);
    CodeStubAssembler(state_).IncrementCallCount(TNode<FeedbackVector>{tmp3}, TNode<UintPtrT>{p_slotId});
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 106);
    tmp5 = CodeStubAssembler(state_).LoadFeedbackVectorSlot(TNode<FeedbackVector>{tmp3}, TNode<UintPtrT>{p_slotId});
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 107);
    tmp6 = IsMonomorphic_0(state_, TNode<MaybeObject>{tmp5}, TNode<Object>{p_maybeTarget});
    ca_.Branch(tmp6, &block17, std::vector<compiler::Node*>{}, &block18, std::vector<compiler::Node*>{});
  }

  if (block17.is_used()) {
    ca_.Bind(&block17);
    ca_.Goto(&block1);
  }

  TNode<BoolT> tmp7;
  if (block18.is_used()) {
    ca_.Bind(&block18);
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 108);
    tmp7 = IsMegamorphic_0(state_, TNode<MaybeObject>{tmp5});
    ca_.Branch(tmp7, &block19, std::vector<compiler::Node*>{}, &block20, std::vector<compiler::Node*>{});
  }

  if (block19.is_used()) {
    ca_.Bind(&block19);
    ca_.Goto(&block1);
  }

  TNode<BoolT> tmp8;
  if (block20.is_used()) {
    ca_.Bind(&block20);
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 109);
    tmp8 = IsUninitialized_0(state_, TNode<MaybeObject>{tmp5});
    ca_.Branch(tmp8, &block21, std::vector<compiler::Node*>{}, &block22, std::vector<compiler::Node*>{});
  }

  if (block21.is_used()) {
    ca_.Bind(&block21);
    ca_.Goto(&block14);
  }

  TNode<HeapObject> tmp9;
  if (block22.is_used()) {
    ca_.Bind(&block22);
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 113);
    compiler::CodeAssemblerLabel label10(&ca_);
    tmp9 = MaybeObjectToStrong_0(state_, TNode<MaybeObject>{tmp5}, &label10);
    ca_.Goto(&block23);
    if (label10.is_used()) {
      ca_.Bind(&label10);
      ca_.Goto(&block24);
    }
  }

  if (block24.is_used()) {
    ca_.Bind(&block24);
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 151);
    SetCallFeedbackContent_0(state_, TNode<Context>{p_context}, TNode<FeedbackVector>{tmp3}, TNode<UintPtrT>{p_slotId}, CallFeedbackContent::kTarget);
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 153);
    ca_.Goto(&block14);
  }

  TNode<BoolT> tmp11;
  if (block23.is_used()) {
    ca_.Bind(&block23);
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 115);
    tmp11 = FeedbackValueIsReceiver_0(state_, TNode<Context>{p_context}, TNode<FeedbackVector>{tmp3}, TNode<UintPtrT>{p_slotId});
    ca_.Branch(tmp11, &block27, std::vector<compiler::Node*>{}, &block28, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp12;
  if (block27.is_used()) {
    ca_.Bind(&block27);
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 116);
    tmp12 = TaggedEqualPrototypeApplyFunction_0(state_, TNode<Context>{p_context}, TNode<Object>{p_maybeTarget});
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 115);
    ca_.Goto(&block29, tmp12);
  }

  TNode<BoolT> tmp13;
  if (block28.is_used()) {
    ca_.Bind(&block28);
    tmp13 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block29, tmp13);
  }

  TNode<BoolT> phi_bb29_9;
  if (block29.is_used()) {
    ca_.Bind(&block29, &phi_bb29_9);
    ca_.Branch(phi_bb29_9, &block25, std::vector<compiler::Node*>{}, &block26, std::vector<compiler::Node*>{});
  }

  TNode<Object> tmp14;
  TNode<BoolT> tmp15;
  if (block25.is_used()) {
    ca_.Bind(&block25);
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 120);
    tmp14 = CodeStubAssembler(state_).RunLazy(std::function<TNode<Object>()>{p_maybeReceiver});
    tmp15 = IsMonomorphic_0(state_, TNode<MaybeObject>{tmp5}, TNode<Object>{tmp14});
    ca_.Branch(tmp15, &block30, std::vector<compiler::Node*>{}, &block31, std::vector<compiler::Node*>{});
  }

  if (block30.is_used()) {
    ca_.Bind(&block30);
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 121);
    ca_.Goto(&block1);
  }

  if (block31.is_used()) {
    ca_.Bind(&block31);
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 124);
    SetCallFeedbackContent_0(state_, TNode<Context>{p_context}, TNode<FeedbackVector>{tmp3}, TNode<UintPtrT>{p_slotId}, CallFeedbackContent::kTarget);
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 126);
    compiler::CodeAssemblerLabel label16(&ca_);
    TryInitializeAsMonomorphic_0(state_, TNode<Context>{p_context}, TNode<Object>{p_maybeTarget}, TNode<FeedbackVector>{tmp3}, TNode<UintPtrT>{p_slotId}, &label16);
    ca_.Goto(&block33);
    if (label16.is_used()) {
      ca_.Bind(&label16);
      ca_.Goto(&block34);
    }
  }

  if (block34.is_used()) {
    ca_.Bind(&block34);
    ca_.Goto(&block12);
  }

  if (block33.is_used()) {
    ca_.Bind(&block33);
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 128);
    ca_.Goto(&block1);
  }

  TNode<JSFunction> tmp17;
  if (block26.is_used()) {
    ca_.Bind(&block26);
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 135);
    compiler::CodeAssemblerLabel label18(&ca_);
    tmp17 = Cast_JSFunction_1(state_, TNode<Context>{p_context}, TNode<Object>{p_maybeTarget}, &label18);
    ca_.Goto(&block35);
    if (label18.is_used()) {
      ca_.Bind(&label18);
      ca_.Goto(&block36);
    }
  }

  if (block36.is_used()) {
    ca_.Bind(&block36);
    ca_.Goto(&block12);
  }

  TNode<IntPtrT> tmp19;
  TNode<FeedbackCell> tmp20;
  TNode<BoolT> tmp21;
  if (block35.is_used()) {
    ca_.Bind(&block35);
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 136);
    tmp19 = FromConstexpr_intptr_constexpr_int31_0(state_, 20);
    tmp20 = CodeStubAssembler(state_).LoadReference<FeedbackCell>(CodeStubAssembler::Reference{tmp17, tmp19});
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 137);
    tmp21 = CodeStubAssembler(state_).TaggedEqual(TNode<MaybeObject>{tmp9}, TNode<MaybeObject>{tmp20});
    ca_.Branch(tmp21, &block37, std::vector<compiler::Node*>{}, &block38, std::vector<compiler::Node*>{});
  }

  if (block37.is_used()) {
    ca_.Bind(&block37);
    ca_.Goto(&block1);
  }

  TNode<JSFunction> tmp22;
  if (block38.is_used()) {
    ca_.Bind(&block38);
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 143);
    compiler::CodeAssemblerLabel label23(&ca_);
    tmp22 = Cast_JSFunction_0(state_, TNode<HeapObject>{tmp9}, &label23);
    ca_.Goto(&block39);
    if (label23.is_used()) {
      ca_.Bind(&label23);
      ca_.Goto(&block40);
    }
  }

  if (block40.is_used()) {
    ca_.Bind(&block40);
    ca_.Goto(&block12);
  }

  TNode<IntPtrT> tmp24;
  TNode<FeedbackCell> tmp25;
  TNode<BoolT> tmp26;
  TNode<BoolT> tmp27;
  if (block39.is_used()) {
    ca_.Bind(&block39);
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 144);
    tmp24 = FromConstexpr_intptr_constexpr_int31_0(state_, 20);
    tmp25 = CodeStubAssembler(state_).LoadReference<FeedbackCell>(CodeStubAssembler::Reference{tmp22, tmp24});
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 145);
    tmp26 = CodeStubAssembler(state_).TaggedEqual(TNode<MaybeObject>{tmp25}, TNode<MaybeObject>{tmp20});
    tmp27 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp26});
    ca_.Branch(tmp27, &block41, std::vector<compiler::Node*>{}, &block42, std::vector<compiler::Node*>{});
  }

  if (block41.is_used()) {
    ca_.Bind(&block41);
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 146);
    ca_.Goto(&block12);
  }

  TNode<MaybeObject> tmp28;
  if (block42.is_used()) {
    ca_.Bind(&block42);
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 148);
    tmp28 = CodeStubAssembler(state_).StoreWeakReferenceInFeedbackVector(TNode<FeedbackVector>{tmp3}, TNode<UintPtrT>{p_slotId}, TNode<HeapObject>{tmp25});
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 149);
    CodeStubAssembler(state_).ReportFeedbackUpdate(TNode<FeedbackVector>{tmp3}, TNode<UintPtrT>{p_slotId}, "Call:FeedbackVectorCell");
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 154);
    ca_.Goto(&block13);
  }

  TNode<BoolT> tmp29;
  if (block14.is_used()) {
    ca_.Bind(&block14);
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 156);
    tmp29 = TaggedEqualPrototypeApplyFunction_0(state_, TNode<Context>{p_context}, TNode<Object>{p_maybeTarget});
    ca_.Branch(tmp29, &block43, std::vector<compiler::Node*>{}, &block44, std::vector<compiler::Node*>{});
  }

  TNode<Object> tmp30;
  if (block43.is_used()) {
    ca_.Bind(&block43);
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 157);
    tmp30 = CodeStubAssembler(state_).RunLazy(std::function<TNode<Object>()>{p_maybeReceiver});
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 158);
    SetCallFeedbackContent_0(state_, TNode<Context>{p_context}, TNode<FeedbackVector>{tmp3}, TNode<UintPtrT>{p_slotId}, CallFeedbackContent::kReceiver);
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 156);
    ca_.Goto(&block45, tmp30);
  }

  TNode<BoolT> tmp31;
  TNode<BoolT> tmp32;
  if (block44.is_used()) {
    ca_.Bind(&block44);
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 161);
    tmp31 = FeedbackValueIsReceiver_0(state_, TNode<Context>{p_context}, TNode<FeedbackVector>{tmp3}, TNode<UintPtrT>{p_slotId});
    tmp32 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp31});
    ca_.Branch(tmp32, &block46, std::vector<compiler::Node*>{}, &block47, std::vector<compiler::Node*>{});
  }

  if (block47.is_used()) {
    ca_.Bind(&block47);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/ic-callable.tq", 161});
      CodeStubAssembler(state_).FailAssert("Torque assert '!FeedbackValueIsReceiver(feedbackVector, slotId)' failed", pos_stack);
    }
  }

  if (block46.is_used()) {
    ca_.Bind(&block46);
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 156);
    ca_.Goto(&block45, p_maybeTarget);
  }

  TNode<Object> phi_bb45_6;
  if (block45.is_used()) {
    ca_.Bind(&block45, &phi_bb45_6);
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 163);
    compiler::CodeAssemblerLabel label33(&ca_);
    TryInitializeAsMonomorphic_0(state_, TNode<Context>{p_context}, TNode<Object>{phi_bb45_6}, TNode<FeedbackVector>{tmp3}, TNode<UintPtrT>{p_slotId}, &label33);
    ca_.Goto(&block48, phi_bb45_6, phi_bb45_6);
    if (label33.is_used()) {
      ca_.Bind(&label33);
      ca_.Goto(&block49, phi_bb45_6, phi_bb45_6);
    }
  }

  TNode<Object> phi_bb49_6;
  TNode<Object> phi_bb49_7;
  if (block49.is_used()) {
    ca_.Bind(&block49, &phi_bb49_6, &phi_bb49_7);
    ca_.Goto(&block12);
  }

  TNode<Object> phi_bb48_6;
  TNode<Object> phi_bb48_7;
  if (block48.is_used()) {
    ca_.Bind(&block48, &phi_bb48_6, &phi_bb48_7);
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 104);
    ca_.Goto(&block13);
  }

  if (block13.is_used()) {
    ca_.Bind(&block13);
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 165);
    ca_.Goto(&block11);
  }

  if (block12.is_used()) {
    ca_.Bind(&block12);
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 166);
    TransitionToMegamorphic_0(state_, TNode<Context>{p_context}, TNode<FeedbackVector>{tmp3}, TNode<UintPtrT>{p_slotId});
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 104);
    ca_.Goto(&block11);
  }

  if (block11.is_used()) {
    ca_.Bind(&block11);
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 91);
    ca_.Goto(&block1);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(&block50);
  }

    ca_.Bind(&block50);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/ic-callable.tq?l=170&c=1
void CollectInstanceOfFeedback_0(compiler::CodeAssemblerState* state_, TNode<Object> p_maybeTarget, TNode<Context> p_context, TNode<HeapObject> p_maybeFeedbackVector, TNode<UintPtrT> p_slotId) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block25(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<BoolT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 177);
    tmp0 = CodeStubAssembler(state_).IsUndefined(TNode<Object>{p_maybeFeedbackVector});
    ca_.Branch(tmp0, &block4, std::vector<compiler::Node*>{}, &block5, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp1;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    tmp1 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block6, tmp1);
  }

  TNode<BoolT> tmp2;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 178);
    tmp2 = Is_FeedbackVector_Undefined_OR_FeedbackVector_0(state_, TNode<Context>{p_context}, TNode<HeapObject>{p_maybeFeedbackVector});
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 177);
    ca_.Goto(&block6, tmp2);
  }

  TNode<BoolT> phi_bb6_5;
  if (block6.is_used()) {
    ca_.Bind(&block6, &phi_bb6_5);
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 176);
    ca_.Branch(phi_bb6_5, &block2, std::vector<compiler::Node*>{}, &block3, std::vector<compiler::Node*>{});
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/ic-callable.tq", 176});
      CodeStubAssembler(state_).FailAssert("Torque assert 'IsUndefined(maybeFeedbackVector) || Is<FeedbackVector>(maybeFeedbackVector)' failed", pos_stack);
    }
  }

  TNode<FeedbackVector> tmp3;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 180);
    compiler::CodeAssemblerLabel label4(&ca_);
    tmp3 = Cast_FeedbackVector_0(state_, TNode<HeapObject>{p_maybeFeedbackVector}, &label4);
    ca_.Goto(&block9);
    if (label4.is_used()) {
      ca_.Bind(&label4);
      ca_.Goto(&block10);
    }
  }

  if (block10.is_used()) {
    ca_.Bind(&block10);
    ca_.Goto(&block1);
  }

  TNode<MaybeObject> tmp5;
  TNode<BoolT> tmp6;
  if (block9.is_used()) {
    ca_.Bind(&block9);
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 185);
    tmp5 = CodeStubAssembler(state_).LoadFeedbackVectorSlot(TNode<FeedbackVector>{tmp3}, TNode<UintPtrT>{p_slotId});
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 186);
    tmp6 = IsMonomorphic_0(state_, TNode<MaybeObject>{tmp5}, TNode<Object>{p_maybeTarget});
    ca_.Branch(tmp6, &block15, std::vector<compiler::Node*>{}, &block16, std::vector<compiler::Node*>{});
  }

  if (block15.is_used()) {
    ca_.Bind(&block15);
    ca_.Goto(&block1);
  }

  TNode<BoolT> tmp7;
  if (block16.is_used()) {
    ca_.Bind(&block16);
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 187);
    tmp7 = IsMegamorphic_0(state_, TNode<MaybeObject>{tmp5});
    ca_.Branch(tmp7, &block17, std::vector<compiler::Node*>{}, &block18, std::vector<compiler::Node*>{});
  }

  if (block17.is_used()) {
    ca_.Bind(&block17);
    ca_.Goto(&block1);
  }

  TNode<BoolT> tmp8;
  if (block18.is_used()) {
    ca_.Bind(&block18);
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 188);
    tmp8 = IsUninitialized_0(state_, TNode<MaybeObject>{tmp5});
    ca_.Branch(tmp8, &block19, std::vector<compiler::Node*>{}, &block20, std::vector<compiler::Node*>{});
  }

  if (block19.is_used()) {
    ca_.Bind(&block19);
    ca_.Goto(&block14);
  }

  TNode<HeapObject> tmp9;
  if (block20.is_used()) {
    ca_.Bind(&block20);
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 192);
    compiler::CodeAssemblerLabel label10(&ca_);
    tmp9 = MaybeObjectToStrong_0(state_, TNode<MaybeObject>{tmp5}, &label10);
    ca_.Goto(&block21);
    if (label10.is_used()) {
      ca_.Bind(&label10);
      ca_.Goto(&block22);
    }
  }

  if (block22.is_used()) {
    ca_.Bind(&block22);
    ca_.Goto(&block14);
  }

  if (block21.is_used()) {
    ca_.Bind(&block21);
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 194);
    ca_.Goto(&block12);
  }

  if (block14.is_used()) {
    ca_.Bind(&block14);
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 196);
    compiler::CodeAssemblerLabel label11(&ca_);
    TryInitializeAsMonomorphic_0(state_, TNode<Context>{p_context}, TNode<Object>{p_maybeTarget}, TNode<FeedbackVector>{tmp3}, TNode<UintPtrT>{p_slotId}, &label11);
    ca_.Goto(&block23);
    if (label11.is_used()) {
      ca_.Bind(&label11);
      ca_.Goto(&block24);
    }
  }

  if (block24.is_used()) {
    ca_.Bind(&block24);
    ca_.Goto(&block12);
  }

  if (block23.is_used()) {
    ca_.Bind(&block23);
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 198);
    ca_.Goto(&block11);
  }

  if (block12.is_used()) {
    ca_.Bind(&block12);
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 199);
    TransitionToMegamorphic_0(state_, TNode<Context>{p_context}, TNode<FeedbackVector>{tmp3}, TNode<UintPtrT>{p_slotId});
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 183);
    ca_.Goto(&block11);
  }

  if (block11.is_used()) {
    ca_.Bind(&block11);
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 170);
    ca_.Goto(&block1);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(&block25);
  }

    ca_.Bind(&block25);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/ic-callable.tq?l=203&c=1
TNode<BoolT> BothTaggedEqualArrayFunction_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_first, TNode<Object> p_second) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<BoolT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 205);
    tmp0 = CodeStubAssembler(state_).TaggedEqual(TNode<MaybeObject>{p_first}, TNode<MaybeObject>{p_second});
    ca_.Branch(tmp0, &block2, std::vector<compiler::Node*>{}, &block3, std::vector<compiler::Node*>{});
  }

  TNode<JSFunction> tmp1;
  TNode<BoolT> tmp2;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    tmp1 = GetArrayFunction_0(state_, TNode<Context>{p_context});
    tmp2 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{p_second}, TNode<HeapObject>{tmp1});
    ca_.Goto(&block4, tmp2);
  }

  TNode<BoolT> tmp3;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    tmp3 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block4, tmp3);
  }

  TNode<BoolT> phi_bb4_4;
  if (block4.is_used()) {
    ca_.Bind(&block4, &phi_bb4_4);
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 203);
    ca_.Goto(&block5);
  }

    ca_.Bind(&block5);
  return TNode<BoolT>{phi_bb4_4};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/ic-callable.tq?l=211&c=1
TNode<FeedbackVector> CastFeedbackVector_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_maybeFeedbackVector, UpdateFeedbackMode p_updateFeedbackMode, compiler::CodeAssemblerLabel* label_Fallback) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FeedbackVector> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FeedbackVector> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 215);
    if (((CodeStubAssembler(state_).UpdateFeedbackModeEqual(p_updateFeedbackMode, UpdateFeedbackMode::kGuaranteedFeedback)))) {
      ca_.Goto(&block3);
    } else {
      ca_.Goto(&block4);
    }
  }

  TNode<HeapObject> tmp0;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 162);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = CodeStubAssembler(state_).TaggedToHeapObject(TNode<Object>{p_maybeFeedbackVector}, &label1);
    ca_.Goto(&block13);
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block14);
    }
  }

  if (block14.is_used()) {
    ca_.Bind(&block14);
    ca_.Goto(&block11);
  }

  TNode<FeedbackVector> tmp2;
  if (block13.is_used()) {
    ca_.Bind(&block13);
    compiler::CodeAssemblerLabel label3(&ca_);
    tmp2 = Cast_FeedbackVector_0(state_, TNode<HeapObject>{tmp0}, &label3);
    ca_.Goto(&block15);
    if (label3.is_used()) {
      ca_.Bind(&label3);
      ca_.Goto(&block16);
    }
  }

  if (block16.is_used()) {
    ca_.Bind(&block16);
    ca_.Goto(&block11);
  }

  TNode<BoolT> tmp4;
  if (block15.is_used()) {
    ca_.Bind(&block15);
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 809);
    tmp4 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block9, tmp4);
  }

  TNode<BoolT> tmp5;
  if (block11.is_used()) {
    ca_.Bind(&block11);
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 808);
    tmp5 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block9, tmp5);
  }

  TNode<BoolT> phi_bb9_5;
  if (block9.is_used()) {
    ca_.Bind(&block9, &phi_bb9_5);
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 814);
    ca_.Branch(phi_bb9_5, &block7, std::vector<compiler::Node*>{}, &block8, std::vector<compiler::Node*>{});
  }

  if (block8.is_used()) {
    ca_.Bind(&block8);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/cast.tq", 814});
      CodeStubAssembler(state_).FailAssert("Torque assert 'Is<A>(o)' failed", pos_stack);
    }
  }

  TNode<FeedbackVector> tmp6;
  if (block7.is_used()) {
    ca_.Bind(&block7);
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 815);
    tmp6 = TORQUE_CAST(TNode<Object>{p_maybeFeedbackVector});
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 216);
    ca_.Goto(&block2, tmp6);
  }

  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 217);
    if (((CodeStubAssembler(state_).UpdateFeedbackModeEqual(p_updateFeedbackMode, UpdateFeedbackMode::kOptionalFeedback)))) {
      ca_.Goto(&block17);
    } else {
      ca_.Goto(&block18);
    }
  }

  TNode<FeedbackVector> tmp7;
  if (block17.is_used()) {
    ca_.Bind(&block17);
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 219);
    compiler::CodeAssemblerLabel label8(&ca_);
    tmp7 = Cast_FeedbackVector_0(state_, TNode<HeapObject>{p_maybeFeedbackVector}, &label8);
    ca_.Goto(&block22);
    if (label8.is_used()) {
      ca_.Bind(&label8);
      ca_.Goto(&block23);
    }
  }

  if (block23.is_used()) {
    ca_.Bind(&block23);
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 211);
    ca_.Goto(label_Fallback);
  }

  if (block22.is_used()) {
    ca_.Bind(&block22);
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 219);
    ca_.Goto(&block2, tmp7);
  }

  if (block18.is_used()) {
    ca_.Bind(&block18);
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 221);
    CodeStubAssembler(state_).PrintErr("halting because of unreachable code at src/builtins/ic-callable.tq:221:5");
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<FeedbackVector> phi_bb2_1;
  if (block2.is_used()) {
    ca_.Bind(&block2, &phi_bb2_1);
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 211);
    ca_.Goto(&block24, phi_bb2_1);
  }

  TNode<FeedbackVector> phi_bb24_1;
    ca_.Bind(&block24, &phi_bb24_1);
  return TNode<FeedbackVector>{phi_bb24_1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/ic-callable.tq?l=225&c=1
void CollectConstructFeedback_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_target, TNode<Object> p_newTarget, TNode<HeapObject> p_maybeFeedbackVector, TNode<UintPtrT> p_slotId, UpdateFeedbackMode p_updateFeedbackMode, compiler::CodeAssemblerLabel* label_ConstructGeneric, compiler::CodeAssemblerLabel* label_ConstructArray, compiler::TypedCodeAssemblerVariable<AllocationSite>* label_ConstructArray_parameter_0) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block26(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block27(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block25(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block29(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block28(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block30(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block31(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block33(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block32(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<AllocationSite> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<BoolT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 235);
    tmp0 = CodeStubAssembler(state_).IsUndefined(TNode<Object>{p_maybeFeedbackVector});
    ca_.Branch(tmp0, &block5, std::vector<compiler::Node*>{}, &block6, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp1;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    tmp1 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block7, tmp1);
  }

  TNode<BoolT> tmp2;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 236);
    tmp2 = Is_FeedbackVector_Undefined_OR_FeedbackVector_0(state_, TNode<Context>{p_context}, TNode<HeapObject>{p_maybeFeedbackVector});
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 235);
    ca_.Goto(&block7, tmp2);
  }

  TNode<BoolT> phi_bb7_6;
  if (block7.is_used()) {
    ca_.Bind(&block7, &phi_bb7_6);
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 234);
    ca_.Branch(phi_bb7_6, &block3, std::vector<compiler::Node*>{}, &block4, std::vector<compiler::Node*>{});
  }

  if (block4.is_used()) {
    ca_.Bind(&block4);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/ic-callable.tq", 234});
      CodeStubAssembler(state_).FailAssert("Torque assert 'IsUndefined(maybeFeedbackVector) || Is<FeedbackVector>(maybeFeedbackVector)' failed", pos_stack);
    }
  }

  TNode<FeedbackVector> tmp3;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 238);
    compiler::CodeAssemblerLabel label4(&ca_);
    tmp3 = CastFeedbackVector_0(state_, TNode<HeapObject>{p_maybeFeedbackVector}, p_updateFeedbackMode, &label4);
    ca_.Goto(&block10);
    if (label4.is_used()) {
      ca_.Bind(&label4);
      ca_.Goto(&block11);
    }
  }

  if (block11.is_used()) {
    ca_.Bind(&block11);
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 239);
    ca_.Goto(&block1);
  }

  TNode<MaybeObject> tmp5;
  TNode<BoolT> tmp6;
  if (block10.is_used()) {
    ca_.Bind(&block10);
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 241);
    CodeStubAssembler(state_).IncrementCallCount(TNode<FeedbackVector>{tmp3}, TNode<UintPtrT>{p_slotId});
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 245);
    tmp5 = CodeStubAssembler(state_).LoadFeedbackVectorSlot(TNode<FeedbackVector>{tmp3}, TNode<UintPtrT>{p_slotId});
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 246);
    tmp6 = IsMonomorphic_0(state_, TNode<MaybeObject>{tmp5}, TNode<Object>{p_newTarget});
    ca_.Branch(tmp6, &block16, std::vector<compiler::Node*>{}, &block17, std::vector<compiler::Node*>{});
  }

  if (block16.is_used()) {
    ca_.Bind(&block16);
    ca_.Goto(&block1);
  }

  TNode<BoolT> tmp7;
  if (block17.is_used()) {
    ca_.Bind(&block17);
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 247);
    tmp7 = IsMegamorphic_0(state_, TNode<MaybeObject>{tmp5});
    ca_.Branch(tmp7, &block18, std::vector<compiler::Node*>{}, &block19, std::vector<compiler::Node*>{});
  }

  if (block18.is_used()) {
    ca_.Bind(&block18);
    ca_.Goto(&block1);
  }

  TNode<BoolT> tmp8;
  if (block19.is_used()) {
    ca_.Bind(&block19);
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 248);
    tmp8 = IsUninitialized_0(state_, TNode<MaybeObject>{tmp5});
    ca_.Branch(tmp8, &block20, std::vector<compiler::Node*>{}, &block21, std::vector<compiler::Node*>{});
  }

  if (block20.is_used()) {
    ca_.Bind(&block20);
    ca_.Goto(&block15);
  }

  TNode<BoolT> tmp9;
  TNode<BoolT> tmp10;
  if (block21.is_used()) {
    ca_.Bind(&block21);
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 250);
    tmp9 = CodeStubAssembler(state_).IsWeakOrCleared(TNode<MaybeObject>{tmp5});
    tmp10 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp9});
    ca_.Branch(tmp10, &block22, std::vector<compiler::Node*>{}, &block23, std::vector<compiler::Node*>{});
  }

  TNode<Object> tmp11;
  TNode<BoolT> tmp12;
  if (block22.is_used()) {
    ca_.Bind(&block22);
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 251);
    tmp11 = TORQUE_CAST(TNode<MaybeObject>{tmp5});
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 252);
    tmp12 = Is_AllocationSite_Object_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp11});
    ca_.Branch(tmp12, &block24, std::vector<compiler::Node*>{}, &block25, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp13;
  if (block24.is_used()) {
    ca_.Bind(&block24);
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 253);
    tmp13 = BothTaggedEqualArrayFunction_0(state_, TNode<Context>{p_context}, TNode<Object>{p_target}, TNode<Object>{p_newTarget});
    ca_.Branch(tmp13, &block26, std::vector<compiler::Node*>{}, &block27, std::vector<compiler::Node*>{});
  }

  TNode<AllocationSite> tmp14;
  if (block26.is_used()) {
    ca_.Bind(&block26);
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 254);
    tmp14 = UnsafeCast_AllocationSite_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp11});
    ca_.Goto(&block2, tmp14);
  }

  if (block27.is_used()) {
    ca_.Bind(&block27);
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 256);
    ca_.Goto(&block13);
  }

  if (block25.is_used()) {
    ca_.Bind(&block25);
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 250);
    ca_.Goto(&block23);
  }

  TNode<HeapObject> tmp15;
  if (block23.is_used()) {
    ca_.Bind(&block23);
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 262);
    compiler::CodeAssemblerLabel label16(&ca_);
    tmp15 = MaybeObjectToStrong_0(state_, TNode<MaybeObject>{tmp5}, &label16);
    ca_.Goto(&block28);
    if (label16.is_used()) {
      ca_.Bind(&label16);
      ca_.Goto(&block29);
    }
  }

  if (block29.is_used()) {
    ca_.Bind(&block29);
    ca_.Goto(&block15);
  }

  if (block28.is_used()) {
    ca_.Bind(&block28);
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 264);
    ca_.Goto(&block13);
  }

  TNode<BoolT> tmp17;
  if (block15.is_used()) {
    ca_.Bind(&block15);
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 266);
    tmp17 = BothTaggedEqualArrayFunction_0(state_, TNode<Context>{p_context}, TNode<Object>{p_target}, TNode<Object>{p_newTarget});
    ca_.Branch(tmp17, &block30, std::vector<compiler::Node*>{}, &block31, std::vector<compiler::Node*>{});
  }

  TNode<AllocationSite> tmp18;
  if (block30.is_used()) {
    ca_.Bind(&block30);
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 270);
    tmp18 = CodeStubAssembler(state_).CreateAllocationSiteInFeedbackVector(TNode<FeedbackVector>{tmp3}, TNode<UintPtrT>{p_slotId});
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 271);
    CodeStubAssembler(state_).ReportFeedbackUpdate(TNode<FeedbackVector>{tmp3}, TNode<UintPtrT>{p_slotId}, "Construct:CreateAllocationSite");
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 273);
    ca_.Goto(&block2, tmp18);
  }

  if (block31.is_used()) {
    ca_.Bind(&block31);
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 276);
    compiler::CodeAssemblerLabel label19(&ca_);
    TryInitializeAsMonomorphic_0(state_, TNode<Context>{p_context}, TNode<Object>{p_newTarget}, TNode<FeedbackVector>{tmp3}, TNode<UintPtrT>{p_slotId}, &label19);
    ca_.Goto(&block32);
    if (label19.is_used()) {
      ca_.Bind(&label19);
      ca_.Goto(&block33);
    }
  }

  if (block33.is_used()) {
    ca_.Bind(&block33);
    ca_.Goto(&block13);
  }

  if (block32.is_used()) {
    ca_.Bind(&block32);
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 278);
    ca_.Goto(&block12);
  }

  if (block13.is_used()) {
    ca_.Bind(&block13);
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 279);
    TransitionToMegamorphic_0(state_, TNode<Context>{p_context}, TNode<FeedbackVector>{tmp3}, TNode<UintPtrT>{p_slotId});
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 243);
    ca_.Goto(&block12);
  }

  if (block12.is_used()) {
    ca_.Bind(&block12);
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 281);
    ca_.Goto(&block1);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 225);
    ca_.Goto(label_ConstructGeneric);
  }

  TNode<AllocationSite> phi_bb2_0;
  if (block2.is_used()) {
    ca_.Bind(&block2, &phi_bb2_0);
    *label_ConstructArray_parameter_0 = phi_bb2_0;
    ca_.Goto(label_ConstructArray);
  }
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/ic-callable.tq?l=26&c=10
TNode<HeapObject> WeakToStrong_HeapObject_0(compiler::CodeAssemblerState* state_, TNode<MaybeObject> p_x, compiler::CodeAssemblerLabel* label_ClearedWeakPointer) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<HeapObject> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/base.tq", 71);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = CodeStubAssembler(state_).GetHeapObjectAssumeWeak(TNode<MaybeObject>{p_x}, &label1);
    ca_.Goto(&block3);
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block4);
    }
  }

  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 26);
    ca_.Goto(label_ClearedWeakPointer);
  }

  TNode<HeapObject> tmp2;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    ca_.SetSourcePosition("../../../src/builtins/base.tq", 72);
    tmp2 = (TNode<HeapObject>{tmp0});
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 26);
    ca_.Goto(&block5);
  }

    ca_.Bind(&block5);
  return TNode<HeapObject>{tmp2};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/ic-callable.tq?l=36&c=10
TNode<BoolT> Is_JSBoundFunction_HeapObject_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<HeapObject> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<JSBoundFunction> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 808);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = Cast_JSBoundFunction_0(state_, TNode<HeapObject>{p_o}, &label1);
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
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 36);
    ca_.Goto(&block6);
  }

    ca_.Bind(&block6);
  return TNode<BoolT>{phi_bb1_2};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/ic-callable.tq?l=38&c=9
TNode<JSBoundFunction> UnsafeCast_JSBoundFunction_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
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
    tmp0 = Is_JSBoundFunction_Object_0(state_, TNode<Context>{p_context}, TNode<Object>{p_o});
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

  TNode<JSBoundFunction> tmp1;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 815);
    tmp1 = TORQUE_CAST(TNode<Object>{p_o});
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 38);
    ca_.Goto(&block4);
  }

    ca_.Bind(&block4);
  return TNode<JSBoundFunction>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/ic-callable.tq?l=64&c=38
TNode<Smi> Cast_Smi_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<MaybeObject> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<MaybeObject> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 146);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = Cast_WeakHeapObject_0(state_, TNode<MaybeObject>{p_o}, &label1);
    ca_.Goto(&block5);
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block6);
    }
  }

  TNode<Smi> tmp2;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 150);
    compiler::CodeAssemblerLabel label3(&ca_);
    tmp2 = Cast_Smi_0(state_, TNode<Object>{ca_.UncheckedCast<Object>(p_o)}, &label3);
    ca_.Goto(&block7);
    if (label3.is_used()) {
      ca_.Bind(&label3);
      ca_.Goto(&block8);
    }
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 147);
    ca_.Goto(&block1);
  }

  if (block8.is_used()) {
    ca_.Bind(&block8);
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 150);
    ca_.Goto(&block1);
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 64);
    ca_.Goto(&block9);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_CastError);
  }

    ca_.Bind(&block9);
  return TNode<Smi>{tmp2};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/ic-callable.tq?l=99&c=7
TNode<BoolT> Is_FeedbackVector_Undefined_OR_FeedbackVector_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<HeapObject> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<FeedbackVector> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 808);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = Cast_FeedbackVector_0(state_, TNode<HeapObject>{p_o}, &label1);
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
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 99);
    ca_.Goto(&block6);
  }

    ca_.Bind(&block6);
  return TNode<BoolT>{phi_bb1_2};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/ic-callable.tq?l=216&c=12
TNode<FeedbackVector> UnsafeCast_FeedbackVector_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
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
    tmp0 = Is_FeedbackVector_Object_0(state_, TNode<Context>{p_context}, TNode<Object>{p_o});
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

  TNode<FeedbackVector> tmp1;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 815);
    tmp1 = TORQUE_CAST(TNode<Object>{p_o});
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 216);
    ca_.Goto(&block4);
  }

    ca_.Bind(&block4);
  return TNode<FeedbackVector>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/ic-callable.tq?l=252&c=11
TNode<BoolT> Is_AllocationSite_Object_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<AllocationSite> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 808);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = Cast_AllocationSite_1(state_, TNode<Context>{p_context}, TNode<Object>{p_o}, &label1);
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
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 252);
    ca_.Goto(&block6);
  }

    ca_.Bind(&block6);
  return TNode<BoolT>{phi_bb1_2};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/ic-callable.tq?l=254&c=31
TNode<AllocationSite> UnsafeCast_AllocationSite_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
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
    tmp0 = Is_AllocationSite_Object_0(state_, TNode<Context>{p_context}, TNode<Object>{p_o});
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

  TNode<AllocationSite> tmp1;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 815);
    tmp1 = TORQUE_CAST(TNode<Object>{p_o});
    ca_.SetSourcePosition("../../../src/builtins/ic-callable.tq", 254);
    ca_.Goto(&block4);
  }

    ca_.Bind(&block4);
  return TNode<AllocationSite>{tmp1};
}

} // namespace internal
} // namespace v8
