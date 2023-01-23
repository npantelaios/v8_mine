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
#include "torque-generated/src/builtins/array-to-spliced-tq-csa.h"
#include "torque-generated/src/builtins/array-join-tq-csa.h"
#include "torque-generated/src/builtins/array-splice-tq-csa.h"
#include "torque-generated/src/builtins/array-to-spliced-tq-csa.h"
#include "torque-generated/src/builtins/base-tq-csa.h"
#include "torque-generated/src/builtins/cast-tq-csa.h"
#include "torque-generated/src/builtins/convert-tq-csa.h"
#include "torque-generated/src/builtins/frame-arguments-tq-csa.h"
#include "torque-generated/src/builtins/number-tq-csa.h"
#include "torque-generated/src/objects/fixed-array-tq-csa.h"
#include "torque-generated/src/objects/js-array-tq-csa.h"
#include "torque-generated/test/torque/test-torque-tq-csa.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-to-spliced.tq?l=8&c=1
TNode<JSArray> CopyFastPackedArrayForToSpliced_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, ElementsKind p_kind, TNode<JSArray> p_array, TNode<Smi> p_newLenSmi, TNode<Smi> p_actualStartSmi, TNode<Smi> p_insertCountSmi, TNode<Smi> p_actualDeleteCountSmi) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<IntPtrT> tmp3;
  TNode<FixedArrayBase> tmp4;
  TNode<IntPtrT> tmp5;
  TNode<BoolT> tmp6;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 12);
    tmp0 = Convert_intptr_Smi_0(state_, TNode<Smi>{p_newLenSmi});
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 13);
    tmp1 = Convert_intptr_Smi_0(state_, TNode<Smi>{p_actualStartSmi});
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 14);
    tmp2 = Convert_intptr_Smi_0(state_, TNode<Smi>{p_insertCountSmi});
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 15);
    tmp3 = Convert_intptr_Smi_0(state_, TNode<Smi>{p_actualDeleteCountSmi});
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 17);
    tmp4 = CodeStubAssembler(state_).AllocateFixedArray(p_kind, TNode<IntPtrT>{tmp0}, CodeStubAssembler::AllocationFlag::kAllowLargeObjectAllocation);
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 20);
    tmp5 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp6 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp5});
    ca_.Branch(tmp6, &block2, std::vector<compiler::Node*>{}, &block3, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp7;
  TNode<FixedArrayBase> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<IntPtrT> tmp10;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 22);
    tmp7 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp8 = CodeStubAssembler(state_).LoadReference<FixedArrayBase>(CodeStubAssembler::Reference{p_array, tmp7});
    tmp9 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp10 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    CodeStubAssembler(state_).CopyElements(p_kind, TNode<FixedArrayBase>{tmp4}, TNode<IntPtrT>{tmp9}, TNode<FixedArrayBase>{tmp8}, TNode<IntPtrT>{tmp10}, TNode<IntPtrT>{tmp1});
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 20);
    ca_.Goto(&block3);
  }

  TNode<IntPtrT> tmp11;
  TNode<BoolT> tmp12;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 28);
    tmp11 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp12 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{tmp2}, TNode<IntPtrT>{tmp11});
    ca_.Branch(tmp12, &block4, std::vector<compiler::Node*>{}, &block5, std::vector<compiler::Node*>{});
  }

  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 29);
    if (((CodeStubAssembler(state_).ElementsKindEqual(p_kind, ElementsKind::PACKED_DOUBLE_ELEMENTS)))) {
      ca_.Goto(&block6);
    } else {
      ca_.Goto(&block7);
    }
  }

  TNode<FixedDoubleArray> tmp13;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 31);
    tmp13 = UnsafeCast_FixedDoubleArray_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp4});
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 30);
    CodeStubAssembler(state_).FillFixedDoubleArrayWithZero(TNode<FixedDoubleArray>{tmp13}, TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp2});
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 29);
    ca_.Goto(&block8);
  }

  TNode<FixedArray> tmp14;
  if (block7.is_used()) {
    ca_.Bind(&block7);
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 34);
    tmp14 = UnsafeCast_FixedArray_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp4});
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 33);
    CodeStubAssembler(state_).FillFixedArrayWithSmiZero(p_kind, TNode<FixedArray>{tmp14}, TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp2});
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 29);
    ca_.Goto(&block8);
  }

  if (block8.is_used()) {
    ca_.Bind(&block8);
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 28);
    ca_.Goto(&block5);
  }

  TNode<IntPtrT> tmp15;
  TNode<IntPtrT> tmp16;
  TNode<IntPtrT> tmp17;
  TNode<BoolT> tmp18;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 39);
    tmp15 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp2});
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 40);
    tmp16 = CodeStubAssembler(state_).IntPtrSub(TNode<IntPtrT>{tmp0}, TNode<IntPtrT>{tmp15});
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 41);
    tmp17 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp18 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{tmp16}, TNode<IntPtrT>{tmp17});
    ca_.Branch(tmp18, &block9, std::vector<compiler::Node*>{}, &block10, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp19;
  TNode<IntPtrT> tmp20;
  TNode<Smi> tmp21;
  TNode<IntPtrT> tmp22;
  TNode<Number> tmp23;
  TNode<BoolT> tmp24;
  if (block9.is_used()) {
    ca_.Bind(&block9);
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 42);
    tmp19 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp3});
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 43);
    tmp20 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp19}, TNode<IntPtrT>{tmp16});
    tmp21 = Convert_Smi_intptr_0(state_, TNode<IntPtrT>{tmp20});
    tmp22 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp23 = CodeStubAssembler(state_).LoadReference<Number>(CodeStubAssembler::Reference{p_array, tmp22});
    tmp24 = NumberIsLessThanOrEqual_0(state_, TNode<Number>{tmp21}, TNode<Number>{tmp23});
    ca_.Branch(tmp24, &block11, std::vector<compiler::Node*>{}, &block12, std::vector<compiler::Node*>{});
  }

  if (block12.is_used()) {
    ca_.Bind(&block12);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/array-to-spliced.tq", 43});
      CodeStubAssembler(state_).FailAssert("Torque assert 'Convert<Smi>(r + secondPartLen) <= array.length' failed", pos_stack);
    }
  }

  TNode<IntPtrT> tmp25;
  TNode<FixedArrayBase> tmp26;
  if (block11.is_used()) {
    ca_.Bind(&block11);
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 44);
    tmp25 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp26 = CodeStubAssembler(state_).LoadReference<FixedArrayBase>(CodeStubAssembler::Reference{p_array, tmp25});
    CodeStubAssembler(state_).CopyElements(p_kind, TNode<FixedArrayBase>{tmp4}, TNode<IntPtrT>{tmp15}, TNode<FixedArrayBase>{tmp26}, TNode<IntPtrT>{tmp19}, TNode<IntPtrT>{tmp16});
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 41);
    ca_.Goto(&block10);
  }

  TNode<NativeContext> tmp27;
  TNode<Map> tmp28;
  TNode<JSArray> tmp29;
  if (block10.is_used()) {
    ca_.Bind(&block10);
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 47);
    tmp27 = CodeStubAssembler(state_).LoadNativeContext(TNode<Context>{p_context});
    tmp28 = CodeStubAssembler(state_).LoadJSArrayElementsMap(p_kind, TNode<NativeContext>{tmp27});
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 48);
    tmp29 = NewJSArray_0(state_, TNode<Context>{p_context}, TNode<Map>{tmp28}, TNode<FixedArrayBase>{tmp4});
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 8);
    ca_.Goto(&block13);
  }

    ca_.Bind(&block13);
  return TNode<JSArray>{tmp29};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-to-spliced.tq?l=51&c=1
TNode<JSArray> TryFastArrayToSpliced_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TorqueStructArguments p_args, TNode<JSReceiver> p_o, TNode<Number> p_originalLenNumber, TNode<Number> p_newLenNumber, TNode<Number> p_actualStartNumber, TNode<Smi> p_insertCount, TNode<Number> p_actualDeleteCountNumber, compiler::CodeAssemblerLabel* label_Slow) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block24(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSArray> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSArray> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSArray> block26(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSArray> block25(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSArray> block27(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSArray> block28(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSArray> block29(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSArray> block30(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Smi> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 55);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = Cast_Smi_0(state_, TNode<Object>{p_newLenNumber}, &label1);
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

  TNode<Smi> tmp2;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 56);
    compiler::CodeAssemblerLabel label3(&ca_);
    tmp2 = Cast_Smi_0(state_, TNode<Object>{p_actualStartNumber}, &label3);
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

  TNode<Smi> tmp4;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 58);
    compiler::CodeAssemblerLabel label5(&ca_);
    tmp4 = Cast_Smi_0(state_, TNode<Object>{p_actualDeleteCountNumber}, &label5);
    ca_.Goto(&block7);
    if (label5.is_used()) {
      ca_.Bind(&label5);
      ca_.Goto(&block8);
    }
  }

  if (block8.is_used()) {
    ca_.Bind(&block8);
    ca_.Goto(&block1);
  }

  TNode<JSArray> tmp6;
  if (block7.is_used()) {
    ca_.Bind(&block7);
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 60);
    compiler::CodeAssemblerLabel label7(&ca_);
    tmp6 = Cast_FastJSArray_0(state_, TNode<Context>{p_context}, TNode<HeapObject>{p_o}, &label7);
    ca_.Goto(&block9);
    if (label7.is_used()) {
      ca_.Bind(&label7);
      ca_.Goto(&block10);
    }
  }

  if (block10.is_used()) {
    ca_.Bind(&block10);
    ca_.Goto(&block1);
  }

  TNode<Smi> tmp8;
  if (block9.is_used()) {
    ca_.Bind(&block9);
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 63);
    compiler::CodeAssemblerLabel label9(&ca_);
    tmp8 = Cast_Smi_0(state_, TNode<Object>{p_originalLenNumber}, &label9);
    ca_.Goto(&block11);
    if (label9.is_used()) {
      ca_.Bind(&label9);
      ca_.Goto(&block12);
    }
  }

  if (block12.is_used()) {
    ca_.Bind(&block12);
    ca_.Goto(&block1);
  }

  TNode<Smi> tmp10;
  TNode<BoolT> tmp11;
  if (block11.is_used()) {
    ca_.Bind(&block11);
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 64);
    tmp10 = CodeStubAssembler(state_).LoadFastJSArrayLength(TNode<JSArray>{tmp6});
    tmp11 = CodeStubAssembler(state_).SmiGreaterThan(TNode<Smi>{tmp8}, TNode<Smi>{tmp10});
    ca_.Branch(tmp11, &block13, std::vector<compiler::Node*>{}, &block14, std::vector<compiler::Node*>{});
  }

  if (block13.is_used()) {
    ca_.Bind(&block13);
    ca_.Goto(&block1);
  }

  TNode<IntPtrT> tmp12;
  TNode<Map> tmp13;
  TNode<Int32T> tmp14;
  TNode<BoolT> tmp15;
  TNode<BoolT> tmp16;
  if (block14.is_used()) {
    ca_.Bind(&block14);
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 70);
    tmp12 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp13 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference{tmp6, tmp12});
    tmp14 = CodeStubAssembler(state_).LoadMapElementsKind(TNode<Map>{tmp13});
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 71);
    tmp15 = CodeStubAssembler(state_).IsFastPackedElementsKind(TNode<Int32T>{tmp14});
    tmp16 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp15});
    ca_.Branch(tmp16, &block15, std::vector<compiler::Node*>{}, &block16, std::vector<compiler::Node*>{});
  }

  if (block15.is_used()) {
    ca_.Bind(&block15);
    ca_.Goto(&block1);
  }

  TNode<Int32T> tmp17;
  TNode<BoolT> tmp18;
  if (block16.is_used()) {
    ca_.Bind(&block16);
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 76);
    tmp17 = FromConstexpr_ElementsKind_constexpr_PACKED_SMI_ELEMENTS_0(state_, ElementsKind::PACKED_SMI_ELEMENTS);
    tmp18 = CodeStubAssembler(state_).ElementsKindEqual(TNode<Int32T>{tmp14}, TNode<Int32T>{tmp17});
    ca_.Branch(tmp18, &block17, std::vector<compiler::Node*>{}, &block18, std::vector<compiler::Node*>{});
  }

  TNode<JSArray> tmp19;
  if (block17.is_used()) {
    ca_.Bind(&block17);
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 77);
    tmp19 = CopyFastPackedArrayForToSpliced_0(state_, TNode<Context>{p_context}, ElementsKind::PACKED_SMI_ELEMENTS, TNode<JSArray>{tmp6}, TNode<Smi>{tmp0}, TNode<Smi>{tmp2}, TNode<Smi>{p_insertCount}, TNode<Smi>{tmp4});
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 76);
    ca_.Goto(&block19, tmp19);
  }

  TNode<Int32T> tmp20;
  TNode<BoolT> tmp21;
  if (block18.is_used()) {
    ca_.Bind(&block18);
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 80);
    tmp20 = FromConstexpr_ElementsKind_constexpr_PACKED_ELEMENTS_0(state_, ElementsKind::PACKED_ELEMENTS);
    tmp21 = CodeStubAssembler(state_).ElementsKindEqual(TNode<Int32T>{tmp14}, TNode<Int32T>{tmp20});
    ca_.Branch(tmp21, &block20, std::vector<compiler::Node*>{}, &block21, std::vector<compiler::Node*>{});
  }

  TNode<JSArray> tmp22;
  if (block20.is_used()) {
    ca_.Bind(&block20);
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 81);
    tmp22 = CopyFastPackedArrayForToSpliced_0(state_, TNode<Context>{p_context}, ElementsKind::PACKED_ELEMENTS, TNode<JSArray>{tmp6}, TNode<Smi>{tmp0}, TNode<Smi>{tmp2}, TNode<Smi>{p_insertCount}, TNode<Smi>{tmp4});
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 80);
    ca_.Goto(&block22, tmp22);
  }

  TNode<Int32T> tmp23;
  TNode<BoolT> tmp24;
  if (block21.is_used()) {
    ca_.Bind(&block21);
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 85);
    tmp23 = FromConstexpr_ElementsKind_constexpr_PACKED_DOUBLE_ELEMENTS_0(state_, ElementsKind::PACKED_DOUBLE_ELEMENTS);
    tmp24 = CodeStubAssembler(state_).ElementsKindEqual(TNode<Int32T>{tmp14}, TNode<Int32T>{tmp23});
    ca_.Branch(tmp24, &block23, std::vector<compiler::Node*>{}, &block24, std::vector<compiler::Node*>{});
  }

  if (block24.is_used()) {
    ca_.Bind(&block24);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/array-to-spliced.tq", 85});
      CodeStubAssembler(state_).FailAssert("Torque assert 'elementsKind == ElementsKind::PACKED_DOUBLE_ELEMENTS' failed", pos_stack);
    }
  }

  TNode<JSArray> tmp25;
  if (block23.is_used()) {
    ca_.Bind(&block23);
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 86);
    tmp25 = CopyFastPackedArrayForToSpliced_0(state_, TNode<Context>{p_context}, ElementsKind::PACKED_DOUBLE_ELEMENTS, TNode<JSArray>{tmp6}, TNode<Smi>{tmp0}, TNode<Smi>{tmp2}, TNode<Smi>{p_insertCount}, TNode<Smi>{tmp4});
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 80);
    ca_.Goto(&block22, tmp25);
  }

  TNode<JSArray> phi_bb22_17;
  if (block22.is_used()) {
    ca_.Bind(&block22, &phi_bb22_17);
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 76);
    ca_.Goto(&block19, phi_bb22_17);
  }

  TNode<JSArray> phi_bb19_17;
  TNode<Int32T> tmp26;
  TNode<BoolT> tmp27;
  if (block19.is_used()) {
    ca_.Bind(&block19, &phi_bb19_17);
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 94);
    tmp26 = TransitionElementsKindForInsertionIfNeeded_0(state_, TNode<Context>{p_context}, TNode<JSArray>{phi_bb19_17}, TNode<Int32T>{tmp14}, TorqueStructArguments{TNode<RawPtrT>{p_args.frame}, TNode<RawPtrT>{p_args.base}, TNode<IntPtrT>{p_args.length}, TNode<IntPtrT>{p_args.actual_count}}, IntegerLiteral(false, 0x2ull));
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 98);
    tmp27 = CodeStubAssembler(state_).IsFastPackedElementsKind(TNode<Int32T>{tmp26});
    ca_.Branch(tmp27, &block25, std::vector<compiler::Node*>{phi_bb19_17}, &block26, std::vector<compiler::Node*>{phi_bb19_17});
  }

  TNode<JSArray> phi_bb26_17;
  if (block26.is_used()) {
    ca_.Bind(&block26, &phi_bb26_17);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/array-to-spliced.tq", 98});
      CodeStubAssembler(state_).FailAssert("Torque assert 'IsFastPackedElementsKind(elementsKind)' failed", pos_stack);
    }
  }

  TNode<JSArray> phi_bb25_17;
  TNode<BoolT> tmp28;
  if (block25.is_used()) {
    ca_.Bind(&block25, &phi_bb25_17);
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 99);
    tmp28 = CodeStubAssembler(state_).IsFastSmiOrTaggedElementsKind(TNode<Int32T>{tmp26});
    ca_.Branch(tmp28, &block27, std::vector<compiler::Node*>{phi_bb25_17}, &block28, std::vector<compiler::Node*>{phi_bb25_17});
  }

  TNode<JSArray> phi_bb27_17;
  if (block27.is_used()) {
    ca_.Bind(&block27, &phi_bb27_17);
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 100);
    InsertArgumentsIntoFastPackedArray_FixedArray_JSAny_0(state_, TNode<JSArray>{phi_bb27_17}, TNode<Smi>{tmp2}, TorqueStructArguments{TNode<RawPtrT>{p_args.frame}, TNode<RawPtrT>{p_args.base}, TNode<IntPtrT>{p_args.length}, TNode<IntPtrT>{p_args.actual_count}}, IntegerLiteral(false, 0x2ull), TNode<Smi>{p_insertCount});
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 99);
    ca_.Goto(&block29, phi_bb27_17);
  }

  TNode<JSArray> phi_bb28_17;
  if (block28.is_used()) {
    ca_.Bind(&block28, &phi_bb28_17);
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 103);
    InsertArgumentsIntoFastPackedArray_FixedDoubleArray_Number_0(state_, TNode<JSArray>{phi_bb28_17}, TNode<Smi>{tmp2}, TorqueStructArguments{TNode<RawPtrT>{p_args.frame}, TNode<RawPtrT>{p_args.base}, TNode<IntPtrT>{p_args.length}, TNode<IntPtrT>{p_args.actual_count}}, IntegerLiteral(false, 0x2ull), TNode<Smi>{p_insertCount});
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 99);
    ca_.Goto(&block29, phi_bb28_17);
  }

  TNode<JSArray> phi_bb29_17;
  if (block29.is_used()) {
    ca_.Bind(&block29, &phi_bb29_17);
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 51);
    ca_.Goto(&block30, phi_bb29_17);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_Slow);
  }

  TNode<JSArray> phi_bb30_11;
    ca_.Bind(&block30, &phi_bb30_11);
  return TNode<JSArray>{phi_bb30_11};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-to-spliced.tq?l=110&c=1
TNode<JSArray> GenericArrayToSpliced_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TorqueStructArguments p_args, TNode<JSReceiver> p_o, TNode<Number> p_newLen, TNode<Number> p_actualStart, TNode<Number> p_actualDeleteCount) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, IntPtrT> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, IntPtrT> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, IntPtrT> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, Number> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, Number> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, Number> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<JSArray> tmp0;
  TNode<Number> tmp1;
  TNode<Number> tmp2;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 114);
    tmp0 = CodeStubAssembler(state_).ArrayCreate(TNode<Context>{p_context}, TNode<Number>{p_newLen});
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 117);
    tmp1 = FromConstexpr_Number_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 120);
    tmp2 = CodeStubAssembler(state_).NumberAdd(TNode<Number>{p_actualStart}, TNode<Number>{p_actualDeleteCount});
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 123);
    ca_.Goto(&block4, tmp1);
  }

  TNode<Number> phi_bb4_10;
  TNode<BoolT> tmp3;
  if (block4.is_used()) {
    ca_.Bind(&block4, &phi_bb4_10);
    tmp3 = NumberIsLessThan_0(state_, TNode<Number>{phi_bb4_10}, TNode<Number>{p_actualStart});
    ca_.Branch(tmp3, &block2, std::vector<compiler::Node*>{phi_bb4_10}, &block3, std::vector<compiler::Node*>{phi_bb4_10});
  }

  TNode<Number> phi_bb2_10;
  TNode<Object> tmp4;
  TNode<Object> tmp5;
  TNode<Number> tmp6;
  TNode<Number> tmp7;
  if (block2.is_used()) {
    ca_.Bind(&block2, &phi_bb2_10);
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 126);
    tmp4 = CodeStubAssembler(state_).GetProperty(TNode<Context>{p_context}, TNode<Object>{p_o}, TNode<Object>{phi_bb2_10});
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 129);
    tmp5 = ca_.CallStub<Object>(Builtins::CallableFor(ca_.isolate(), Builtin::kFastCreateDataProperty), p_context, tmp0, phi_bb2_10, tmp4);
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 132);
    tmp6 = FromConstexpr_Number_constexpr_int31_0(state_, 1);
    tmp7 = CodeStubAssembler(state_).NumberAdd(TNode<Number>{phi_bb2_10}, TNode<Number>{tmp6});
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 123);
    ca_.Goto(&block4, tmp7);
  }

  TNode<Number> phi_bb3_10;
  TNode<IntPtrT> tmp8;
  TNode<BoolT> tmp9;
  if (block3.is_used()) {
    ca_.Bind(&block3, &phi_bb3_10);
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 135);
    tmp8 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x2ull));
    tmp9 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{p_args.length}, TNode<IntPtrT>{tmp8});
    ca_.Branch(tmp9, &block5, std::vector<compiler::Node*>{phi_bb3_10}, &block6, std::vector<compiler::Node*>{phi_bb3_10});
  }

  TNode<Number> phi_bb5_10;
  TNode<IntPtrT> tmp10;
  if (block5.is_used()) {
    ca_.Bind(&block5, &phi_bb5_10);
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 137);
    tmp10 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x2ull));
    ca_.Goto(&block9, phi_bb5_10, tmp10);
  }

  TNode<Number> phi_bb9_10;
  TNode<IntPtrT> phi_bb9_12;
  TNode<BoolT> tmp11;
  if (block9.is_used()) {
    ca_.Bind(&block9, &phi_bb9_10, &phi_bb9_12);
    tmp11 = CodeStubAssembler(state_).IntPtrLessThan(TNode<IntPtrT>{phi_bb9_12}, TNode<IntPtrT>{p_args.length});
    ca_.Branch(tmp11, &block7, std::vector<compiler::Node*>{phi_bb9_10, phi_bb9_12}, &block8, std::vector<compiler::Node*>{phi_bb9_10, phi_bb9_12});
  }

  TNode<Number> phi_bb7_10;
  TNode<IntPtrT> phi_bb7_12;
  TNode<Object> tmp12;
  TNode<Object> tmp13;
  TNode<Number> tmp14;
  TNode<Number> tmp15;
  TNode<IntPtrT> tmp16;
  TNode<IntPtrT> tmp17;
  if (block7.is_used()) {
    ca_.Bind(&block7, &phi_bb7_10, &phi_bb7_12);
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 138);
    tmp12 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{p_args.frame}, TNode<RawPtrT>{p_args.base}, TNode<IntPtrT>{p_args.length}, TNode<IntPtrT>{p_args.actual_count}}, TNode<IntPtrT>{phi_bb7_12});
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 142);
    tmp13 = ca_.CallStub<Object>(Builtins::CallableFor(ca_.isolate(), Builtin::kFastCreateDataProperty), p_context, tmp0, phi_bb7_10, tmp12);
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 145);
    tmp14 = FromConstexpr_Number_constexpr_int31_0(state_, 1);
    tmp15 = CodeStubAssembler(state_).NumberAdd(TNode<Number>{phi_bb7_10}, TNode<Number>{tmp14});
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 137);
    tmp16 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp17 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb7_12}, TNode<IntPtrT>{tmp16});
    ca_.Goto(&block9, tmp15, tmp17);
  }

  TNode<Number> phi_bb8_10;
  TNode<IntPtrT> phi_bb8_12;
  if (block8.is_used()) {
    ca_.Bind(&block8, &phi_bb8_10, &phi_bb8_12);
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 135);
    ca_.Goto(&block6, phi_bb8_10);
  }

  TNode<Number> phi_bb6_10;
  if (block6.is_used()) {
    ca_.Bind(&block6, &phi_bb6_10);
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 150);
    ca_.Goto(&block13, phi_bb6_10, tmp2);
  }

  TNode<Number> phi_bb13_10;
  TNode<Number> phi_bb13_11;
  TNode<BoolT> tmp18;
  if (block13.is_used()) {
    ca_.Bind(&block13, &phi_bb13_10, &phi_bb13_11);
    tmp18 = NumberIsLessThan_0(state_, TNode<Number>{phi_bb13_10}, TNode<Number>{p_newLen});
    ca_.Branch(tmp18, &block11, std::vector<compiler::Node*>{phi_bb13_10, phi_bb13_11}, &block12, std::vector<compiler::Node*>{phi_bb13_10, phi_bb13_11});
  }

  TNode<Number> phi_bb11_10;
  TNode<Number> phi_bb11_11;
  TNode<Object> tmp19;
  TNode<Object> tmp20;
  TNode<Number> tmp21;
  TNode<Number> tmp22;
  TNode<Number> tmp23;
  TNode<Number> tmp24;
  if (block11.is_used()) {
    ca_.Bind(&block11, &phi_bb11_10, &phi_bb11_11);
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 154);
    tmp19 = CodeStubAssembler(state_).GetProperty(TNode<Context>{p_context}, TNode<Object>{p_o}, TNode<Object>{phi_bb11_11});
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 157);
    tmp20 = ca_.CallStub<Object>(Builtins::CallableFor(ca_.isolate(), Builtin::kFastCreateDataProperty), p_context, tmp0, phi_bb11_10, tmp19);
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 160);
    tmp21 = FromConstexpr_Number_constexpr_int31_0(state_, 1);
    tmp22 = CodeStubAssembler(state_).NumberAdd(TNode<Number>{phi_bb11_10}, TNode<Number>{tmp21});
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 163);
    tmp23 = FromConstexpr_Number_constexpr_int31_0(state_, 1);
    tmp24 = CodeStubAssembler(state_).NumberAdd(TNode<Number>{phi_bb11_11}, TNode<Number>{tmp23});
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 150);
    ca_.Goto(&block13, tmp22, tmp24);
  }

  TNode<Number> phi_bb12_10;
  TNode<Number> phi_bb12_11;
  if (block12.is_used()) {
    ca_.Bind(&block12, &phi_bb12_10, &phi_bb12_11);
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 110);
    ca_.Goto(&block14);
  }

    ca_.Bind(&block14);
  return TNode<JSArray>{tmp0};
}

TF_BUILTIN(ArrayPrototypeToSpliced, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Word32T> argc = UncheckedParameter<Word32T>(Descriptor::kJSActualArgumentsCount);
  TNode<IntPtrT> arguments_length(ChangeInt32ToIntPtr(UncheckedCast<Int32T>(argc)));
  TNode<RawPtrT> arguments_frame = UncheckedCast<RawPtrT>(LoadFramePointer());
  TorqueStructArguments torque_arguments(GetFrameArguments(arguments_frame, arguments_length, FrameArgumentsArgcType::kCountIncludesReceiver));
  CodeStubArguments arguments(this, torque_arguments);
  TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
  USE(parameter0);
  TNode<Object> parameter1 = arguments.GetReceiver();
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Number> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Number> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Number> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Number> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Number> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Number> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Number> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Number> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Number, Smi, Number> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Number, Smi, Number> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Number> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Object> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<Object> tmp3;
  TNode<JSReceiver> tmp4;
  TNode<Number> tmp5;
  TNode<Number> tmp6;
  TNode<Number> tmp7;
  TNode<BoolT> tmp8;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 173);
    tmp0 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp1 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{torque_arguments.frame}, TNode<RawPtrT>{torque_arguments.base}, TNode<IntPtrT>{torque_arguments.length}, TNode<IntPtrT>{torque_arguments.actual_count}}, TNode<IntPtrT>{tmp0});
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 174);
    tmp2 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp3 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{torque_arguments.frame}, TNode<RawPtrT>{torque_arguments.base}, TNode<IntPtrT>{torque_arguments.length}, TNode<IntPtrT>{torque_arguments.actual_count}}, TNode<IntPtrT>{tmp2});
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 177);
    tmp4 = ca_.CallStub<JSReceiver>(Builtins::CallableFor(ca_.isolate(), Builtin::kToObject), parameter0, parameter1);
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 180);
    tmp5 = GetLengthProperty_0(state_, TNode<Context>{parameter0}, TNode<Object>{tmp4});
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 183);
    tmp6 = ToInteger_Inline_0(state_, TNode<Context>{parameter0}, TNode<Object>{tmp1});
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 191);
    tmp7 = FromConstexpr_Number_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp8 = NumberIsLessThan_0(state_, TNode<Number>{tmp6}, TNode<Number>{tmp7});
    ca_.Branch(tmp8, &block1, std::vector<compiler::Node*>{}, &block2, std::vector<compiler::Node*>{});
  }

  TNode<Number> tmp9;
  TNode<Number> tmp10;
  TNode<Number> tmp11;
  if (block1.is_used()) {
    ca_.Bind(&block1);
    tmp9 = CodeStubAssembler(state_).NumberAdd(TNode<Number>{tmp5}, TNode<Number>{tmp6});
    tmp10 = FromConstexpr_Number_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp11 = Max_0(state_, TNode<Number>{tmp9}, TNode<Number>{tmp10});
    ca_.Goto(&block3, tmp11);
  }

  TNode<Number> tmp12;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 192);
    tmp12 = Min_0(state_, TNode<Number>{tmp6}, TNode<Number>{tmp5});
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 191);
    ca_.Goto(&block3, tmp12);
  }

  TNode<Number> phi_bb3_11;
  TNode<IntPtrT> tmp13;
  TNode<BoolT> tmp14;
  if (block3.is_used()) {
    ca_.Bind(&block3, &phi_bb3_11);
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 196);
    tmp13 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp14 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{torque_arguments.length}, TNode<IntPtrT>{tmp13});
    ca_.Branch(tmp14, &block5, std::vector<compiler::Node*>{}, &block6, std::vector<compiler::Node*>{});
  }

  TNode<Smi> tmp15;
  TNode<Number> tmp16;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 198);
    tmp15 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 202);
    tmp16 = FromConstexpr_Number_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 196);
    ca_.Goto(&block7, tmp15, tmp16);
  }

  TNode<IntPtrT> tmp17;
  TNode<BoolT> tmp18;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 203);
    tmp17 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp18 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{torque_arguments.length}, TNode<IntPtrT>{tmp17});
    ca_.Branch(tmp18, &block8, std::vector<compiler::Node*>{}, &block9, std::vector<compiler::Node*>{});
  }

  TNode<Smi> tmp19;
  TNode<Number> tmp20;
  if (block8.is_used()) {
    ca_.Bind(&block8);
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 205);
    tmp19 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 209);
    tmp20 = CodeStubAssembler(state_).NumberSub(TNode<Number>{tmp5}, TNode<Number>{phi_bb3_11});
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 203);
    ca_.Goto(&block10, tmp19, tmp20);
  }

  TNode<Smi> tmp21;
  TNode<Smi> tmp22;
  TNode<Smi> tmp23;
  TNode<Number> tmp24;
  TNode<Number> tmp25;
  TNode<Number> tmp26;
  TNode<Number> tmp27;
  TNode<Number> tmp28;
  if (block9.is_used()) {
    ca_.Bind(&block9);
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 212);
    tmp21 = Convert_Smi_intptr_0(state_, TNode<IntPtrT>{torque_arguments.length});
    tmp22 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x2ull));
    tmp23 = CodeStubAssembler(state_).SmiSub(TNode<Smi>{tmp21}, TNode<Smi>{tmp22});
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 218);
    tmp24 = ToInteger_Inline_0(state_, TNode<Context>{parameter0}, TNode<Object>{tmp3});
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 219);
    tmp25 = FromConstexpr_Number_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp26 = Max_0(state_, TNode<Number>{tmp25}, TNode<Number>{tmp24});
    tmp27 = CodeStubAssembler(state_).NumberSub(TNode<Number>{tmp5}, TNode<Number>{phi_bb3_11});
    tmp28 = Min_0(state_, TNode<Number>{tmp26}, TNode<Number>{tmp27});
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 203);
    ca_.Goto(&block10, tmp23, tmp28);
  }

  TNode<Smi> phi_bb10_12;
  TNode<Number> phi_bb10_13;
  if (block10.is_used()) {
    ca_.Bind(&block10, &phi_bb10_12, &phi_bb10_13);
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 196);
    ca_.Goto(&block7, phi_bb10_12, phi_bb10_13);
  }

  TNode<Smi> phi_bb7_12;
  TNode<Number> phi_bb7_13;
  TNode<Number> tmp29;
  TNode<Number> tmp30;
  TNode<Number> tmp31;
  TNode<BoolT> tmp32;
  if (block7.is_used()) {
    ca_.Bind(&block7, &phi_bb7_12, &phi_bb7_13);
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 223);
    tmp29 = CodeStubAssembler(state_).NumberAdd(TNode<Number>{tmp5}, TNode<Number>{phi_bb7_12});
    tmp30 = CodeStubAssembler(state_).NumberSub(TNode<Number>{tmp29}, TNode<Number>{phi_bb7_13});
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 226);
    tmp31 = FromConstexpr_Number_constexpr_float64_0(state_, kMaxSafeInteger);
    tmp32 = NumberIsGreaterThan_0(state_, TNode<Number>{tmp30}, TNode<Number>{tmp31});
    ca_.Branch(tmp32, &block11, std::vector<compiler::Node*>{phi_bb7_12, phi_bb7_13}, &block12, std::vector<compiler::Node*>{phi_bb7_12, phi_bb7_13});
  }

  TNode<Smi> phi_bb11_12;
  TNode<Number> phi_bb11_13;
  if (block11.is_used()) {
    ca_.Bind(&block11, &phi_bb11_12, &phi_bb11_13);
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 227);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{parameter0}, MessageTemplate::kInvalidArrayLength, TNode<Object>{tmp30});
  }

  TNode<Smi> phi_bb12_12;
  TNode<Number> phi_bb12_13;
  TNode<Number> tmp33;
  TNode<BoolT> tmp34;
  if (block12.is_used()) {
    ca_.Bind(&block12, &phi_bb12_12, &phi_bb12_13);
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 230);
    tmp33 = FromConstexpr_Number_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp34 = IsNumberEqual_0(state_, TNode<Number>{tmp30}, TNode<Number>{tmp33});
    ca_.Branch(tmp34, &block13, std::vector<compiler::Node*>{phi_bb12_12, phi_bb12_13}, &block14, std::vector<compiler::Node*>{phi_bb12_12, phi_bb12_13});
  }

  TNode<Smi> phi_bb13_12;
  TNode<Number> phi_bb13_13;
  TNode<Number> tmp35;
  TNode<JSArray> tmp36;
  if (block13.is_used()) {
    ca_.Bind(&block13, &phi_bb13_12, &phi_bb13_13);
    tmp35 = FromConstexpr_Number_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp36 = CodeStubAssembler(state_).ArrayCreate(TNode<Context>{parameter0}, TNode<Number>{tmp35});
    arguments.PopAndReturn(tmp36);
  }

  TNode<Smi> phi_bb14_12;
  TNode<Number> phi_bb14_13;
  TNode<Number> tmp37;
  TNode<BoolT> tmp38;
  if (block14.is_used()) {
    ca_.Bind(&block14, &phi_bb14_12, &phi_bb14_13);
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 233);
    tmp37 = FromConstexpr_Number_constexpr_int31_0(state_, JSArray::kMaxFastArrayLength);
    tmp38 = NumberIsGreaterThan_0(state_, TNode<Number>{tmp30}, TNode<Number>{tmp37});
    ca_.Branch(tmp38, &block17, std::vector<compiler::Node*>{phi_bb14_12, phi_bb14_13}, &block18, std::vector<compiler::Node*>{phi_bb14_12, phi_bb14_13});
  }

  TNode<Smi> phi_bb17_12;
  TNode<Number> phi_bb17_13;
  if (block17.is_used()) {
    ca_.Bind(&block17, &phi_bb17_12, &phi_bb17_13);
    ca_.Goto(&block16, phi_bb17_12, phi_bb17_13);
  }

  TNode<Smi> phi_bb18_12;
  TNode<Number> phi_bb18_13;
  TNode<JSArray> tmp39;
  if (block18.is_used()) {
    ca_.Bind(&block18, &phi_bb18_12, &phi_bb18_13);
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 234);
    compiler::CodeAssemblerLabel label40(&ca_);
    tmp39 = TryFastArrayToSpliced_0(state_, TNode<Context>{parameter0}, TorqueStructArguments{TNode<RawPtrT>{torque_arguments.frame}, TNode<RawPtrT>{torque_arguments.base}, TNode<IntPtrT>{torque_arguments.length}, TNode<IntPtrT>{torque_arguments.actual_count}}, TNode<JSReceiver>{tmp4}, TNode<Number>{tmp5}, TNode<Number>{tmp30}, TNode<Number>{phi_bb3_11}, TNode<Smi>{phi_bb18_12}, TNode<Number>{phi_bb18_13}, &label40);
    ca_.Goto(&block19, phi_bb18_12, phi_bb18_13, phi_bb18_12, phi_bb18_13);
    if (label40.is_used()) {
      ca_.Bind(&label40);
      ca_.Goto(&block20, phi_bb18_12, phi_bb18_13, phi_bb18_12, phi_bb18_13);
    }
  }

  TNode<Smi> phi_bb20_12;
  TNode<Number> phi_bb20_13;
  TNode<Smi> phi_bb20_23;
  TNode<Number> phi_bb20_24;
  if (block20.is_used()) {
    ca_.Bind(&block20, &phi_bb20_12, &phi_bb20_13, &phi_bb20_23, &phi_bb20_24);
    ca_.Goto(&block16, phi_bb20_12, phi_bb20_13);
  }

  TNode<Smi> phi_bb19_12;
  TNode<Number> phi_bb19_13;
  TNode<Smi> phi_bb19_23;
  TNode<Number> phi_bb19_24;
  if (block19.is_used()) {
    ca_.Bind(&block19, &phi_bb19_12, &phi_bb19_13, &phi_bb19_23, &phi_bb19_24);
    arguments.PopAndReturn(tmp39);
  }

  TNode<Smi> phi_bb16_12;
  TNode<Number> phi_bb16_13;
  TNode<JSArray> tmp41;
  if (block16.is_used()) {
    ca_.Bind(&block16, &phi_bb16_12, &phi_bb16_13);
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 238);
    tmp41 = GenericArrayToSpliced_0(state_, TNode<Context>{parameter0}, TorqueStructArguments{TNode<RawPtrT>{torque_arguments.frame}, TNode<RawPtrT>{torque_arguments.base}, TNode<IntPtrT>{torque_arguments.length}, TNode<IntPtrT>{torque_arguments.actual_count}}, TNode<JSReceiver>{tmp4}, TNode<Number>{tmp30}, TNode<Number>{phi_bb3_11}, TNode<Number>{phi_bb16_13});
    arguments.PopAndReturn(tmp41);
  }
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-to-spliced.tq?l=100&c=5
void InsertArgumentsIntoFastPackedArray_FixedArray_JSAny_0(compiler::CodeAssemblerState* state_, TNode<JSArray> p_dst, TNode<Smi> p_dstStart, TorqueStructArguments p_args, IntegerLiteral p_argsStart, TNode<Smi> p_insertCount) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, IntPtrT> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, IntPtrT> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, Smi> block28(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, Smi> block27(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, Smi, BoolT> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, Smi> block23(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, Smi> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, IntPtrT> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block29(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Smi> tmp0;
  TNode<BoolT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/array-splice.tq", 67);
    tmp0 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp1 = CodeStubAssembler(state_).SmiGreaterThan(TNode<Smi>{p_insertCount}, TNode<Smi>{tmp0});
    ca_.Branch(tmp1, &block2, std::vector<compiler::Node*>{}, &block3, std::vector<compiler::Node*>{p_dstStart});
  }

  TNode<IntPtrT> tmp2;
  TNode<IntPtrT> tmp3;
  TNode<IntPtrT> tmp4;
  TNode<BoolT> tmp5;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    ca_.SetSourcePosition("../../../src/builtins/array-splice.tq", 68);
    tmp2 = Convert_intptr_Smi_0(state_, TNode<Smi>{p_insertCount});
    tmp3 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, p_argsStart);
    tmp4 = CodeStubAssembler(state_).IntPtrSub(TNode<IntPtrT>{p_args.length}, TNode<IntPtrT>{tmp3});
    tmp5 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{tmp2}, TNode<IntPtrT>{tmp4});
    ca_.Branch(tmp5, &block4, std::vector<compiler::Node*>{}, &block5, std::vector<compiler::Node*>{});
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/array-splice.tq", 68});
      CodeStubAssembler(state_).FailAssert("Torque assert 'Convert<intptr>(insertCount) == args.length - argsStart' failed", pos_stack);
    }
  }

  TNode<IntPtrT> tmp6;
  TNode<FixedArrayBase> tmp7;
  TNode<HeapObject> tmp8;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.SetSourcePosition("../../../src/builtins/array-splice.tq", 70);
    tmp6 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp7 = CodeStubAssembler(state_).LoadReference<FixedArrayBase>(CodeStubAssembler::Reference{p_dst, tmp6});
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 162);
    compiler::CodeAssemblerLabel label9(&ca_);
    tmp8 = CodeStubAssembler(state_).TaggedToHeapObject(TNode<Object>{tmp7}, &label9);
    ca_.Goto(&block13);
    if (label9.is_used()) {
      ca_.Bind(&label9);
      ca_.Goto(&block14);
    }
  }

  if (block14.is_used()) {
    ca_.Bind(&block14);
    ca_.Goto(&block11);
  }

  TNode<FixedArray> tmp10;
  if (block13.is_used()) {
    ca_.Bind(&block13);
    compiler::CodeAssemblerLabel label11(&ca_);
    tmp10 = Cast_FixedArray_0(state_, TNode<HeapObject>{tmp8}, &label11);
    ca_.Goto(&block15);
    if (label11.is_used()) {
      ca_.Bind(&label11);
      ca_.Goto(&block16);
    }
  }

  if (block16.is_used()) {
    ca_.Bind(&block16);
    ca_.Goto(&block11);
  }

  TNode<BoolT> tmp12;
  if (block15.is_used()) {
    ca_.Bind(&block15);
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 809);
    tmp12 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block9, tmp12);
  }

  TNode<BoolT> tmp13;
  if (block11.is_used()) {
    ca_.Bind(&block11);
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 808);
    tmp13 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block9, tmp13);
  }

  TNode<BoolT> phi_bb9_12;
  if (block9.is_used()) {
    ca_.Bind(&block9, &phi_bb9_12);
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 814);
    ca_.Branch(phi_bb9_12, &block7, std::vector<compiler::Node*>{}, &block8, std::vector<compiler::Node*>{});
  }

  if (block8.is_used()) {
    ca_.Bind(&block8);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/cast.tq", 814});
      CodeStubAssembler(state_).FailAssert("Torque assert 'Is<A>(o)' failed", pos_stack);
    }
  }

  TNode<FixedArray> tmp14;
  TNode<IntPtrT> tmp15;
  if (block7.is_used()) {
    ca_.Bind(&block7);
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 815);
    tmp14 = TORQUE_CAST(TNode<Object>{tmp7});
    ca_.SetSourcePosition("../../../src/builtins/array-splice.tq", 71);
    tmp15 = FromConstexpr_intptr_constexpr_intptr_0(state_, (CodeStubAssembler(state_).ConstexprIntegerLiteralToIntptr(p_argsStart)));
    ca_.Goto(&block19, p_dstStart, tmp15);
  }

  TNode<Smi> phi_bb19_7;
  TNode<IntPtrT> phi_bb19_9;
  TNode<BoolT> tmp16;
  if (block19.is_used()) {
    ca_.Bind(&block19, &phi_bb19_7, &phi_bb19_9);
    ca_.SetSourcePosition("../../../src/builtins/array-splice.tq", 72);
    tmp16 = CodeStubAssembler(state_).IntPtrLessThan(TNode<IntPtrT>{phi_bb19_9}, TNode<IntPtrT>{p_args.length});
    ca_.SetSourcePosition("../../../src/builtins/array-splice.tq", 71);
    ca_.Branch(tmp16, &block17, std::vector<compiler::Node*>{phi_bb19_7, phi_bb19_9}, &block18, std::vector<compiler::Node*>{phi_bb19_7, phi_bb19_9});
  }

  TNode<Smi> phi_bb17_7;
  TNode<IntPtrT> phi_bb17_9;
  TNode<Object> tmp17;
  TNode<Smi> tmp18;
  TNode<Smi> tmp19;
  TNode<Object> tmp20;
  if (block17.is_used()) {
    ca_.Bind(&block17, &phi_bb17_7, &phi_bb17_9);
    ca_.SetSourcePosition("../../../src/builtins/array-splice.tq", 73);
    tmp17 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{p_args.frame}, TNode<RawPtrT>{p_args.base}, TNode<IntPtrT>{p_args.length}, TNode<IntPtrT>{p_args.actual_count}}, TNode<IntPtrT>{phi_bb17_9});
    ca_.SetSourcePosition("../../../src/builtins/array-splice.tq", 76);
    tmp18 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    tmp19 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{phi_bb17_7}, TNode<Smi>{tmp18});
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 808);
    compiler::CodeAssemblerLabel label21(&ca_);
    tmp20 = Cast_JSAny_0(state_, TNode<Object>{tmp17}, &label21);
    ca_.Goto(&block27, phi_bb17_9, phi_bb17_7);
    if (label21.is_used()) {
      ca_.Bind(&label21);
      ca_.Goto(&block28, phi_bb17_9, phi_bb17_7);
    }
  }

  TNode<IntPtrT> phi_bb28_9;
  TNode<Smi> phi_bb28_11;
  TNode<BoolT> tmp22;
  if (block28.is_used()) {
    ca_.Bind(&block28, &phi_bb28_9, &phi_bb28_11);
    tmp22 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block24, phi_bb28_9, phi_bb28_11, tmp22);
  }

  TNode<IntPtrT> phi_bb27_9;
  TNode<Smi> phi_bb27_11;
  TNode<BoolT> tmp23;
  if (block27.is_used()) {
    ca_.Bind(&block27, &phi_bb27_9, &phi_bb27_11);
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 809);
    tmp23 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block24, phi_bb27_9, phi_bb27_11, tmp23);
  }

  TNode<IntPtrT> phi_bb24_9;
  TNode<Smi> phi_bb24_11;
  TNode<BoolT> phi_bb24_17;
  if (block24.is_used()) {
    ca_.Bind(&block24, &phi_bb24_9, &phi_bb24_11, &phi_bb24_17);
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 814);
    ca_.Branch(phi_bb24_17, &block22, std::vector<compiler::Node*>{phi_bb24_9, phi_bb24_11}, &block23, std::vector<compiler::Node*>{phi_bb24_9, phi_bb24_11});
  }

  TNode<IntPtrT> phi_bb23_9;
  TNode<Smi> phi_bb23_11;
  if (block23.is_used()) {
    ca_.Bind(&block23, &phi_bb23_9, &phi_bb23_11);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/cast.tq", 814});
      CodeStubAssembler(state_).FailAssert("Torque assert 'Is<A>(o)' failed", pos_stack);
    }
  }

  TNode<IntPtrT> phi_bb22_9;
  TNode<Smi> phi_bb22_11;
  TNode<Object> tmp24;
  TNode<IntPtrT> tmp25;
  TNode<IntPtrT> tmp26;
  if (block22.is_used()) {
    ca_.Bind(&block22, &phi_bb22_9, &phi_bb22_11);
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 815);
    tmp24 = (TNode<Object>{tmp17});
    ca_.SetSourcePosition("../../../src/builtins/array-splice.tq", 76);
    StoreFixedArrayDirect_0(state_, TNode<FixedArray>{tmp14}, TNode<Smi>{phi_bb22_11}, TNode<Object>{tmp24});
    ca_.SetSourcePosition("../../../src/builtins/array-splice.tq", 72);
    tmp25 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp26 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb22_9}, TNode<IntPtrT>{tmp25});
    ca_.SetSourcePosition("../../../src/builtins/array-splice.tq", 71);
    ca_.Goto(&block19, tmp19, tmp26);
  }

  TNode<Smi> phi_bb18_7;
  TNode<IntPtrT> phi_bb18_9;
  if (block18.is_used()) {
    ca_.Bind(&block18, &phi_bb18_7, &phi_bb18_9);
    ca_.SetSourcePosition("../../../src/builtins/array-splice.tq", 67);
    ca_.Goto(&block3, phi_bb18_7);
  }

  TNode<Smi> phi_bb3_7;
  if (block3.is_used()) {
    ca_.Bind(&block3, &phi_bb3_7);
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 100);
    ca_.Goto(&block29);
  }

    ca_.Bind(&block29);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-to-spliced.tq?l=103&c=5
void InsertArgumentsIntoFastPackedArray_FixedDoubleArray_Number_0(compiler::CodeAssemblerState* state_, TNode<JSArray> p_dst, TNode<Smi> p_dstStart, TorqueStructArguments p_args, IntegerLiteral p_argsStart, TNode<Smi> p_insertCount) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, IntPtrT> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, IntPtrT> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, Smi> block28(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, Smi> block27(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, Smi, BoolT> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, Smi> block23(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, Smi> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, IntPtrT> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block29(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Smi> tmp0;
  TNode<BoolT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/array-splice.tq", 67);
    tmp0 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp1 = CodeStubAssembler(state_).SmiGreaterThan(TNode<Smi>{p_insertCount}, TNode<Smi>{tmp0});
    ca_.Branch(tmp1, &block2, std::vector<compiler::Node*>{}, &block3, std::vector<compiler::Node*>{p_dstStart});
  }

  TNode<IntPtrT> tmp2;
  TNode<IntPtrT> tmp3;
  TNode<IntPtrT> tmp4;
  TNode<BoolT> tmp5;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    ca_.SetSourcePosition("../../../src/builtins/array-splice.tq", 68);
    tmp2 = Convert_intptr_Smi_0(state_, TNode<Smi>{p_insertCount});
    tmp3 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, p_argsStart);
    tmp4 = CodeStubAssembler(state_).IntPtrSub(TNode<IntPtrT>{p_args.length}, TNode<IntPtrT>{tmp3});
    tmp5 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{tmp2}, TNode<IntPtrT>{tmp4});
    ca_.Branch(tmp5, &block4, std::vector<compiler::Node*>{}, &block5, std::vector<compiler::Node*>{});
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/array-splice.tq", 68});
      CodeStubAssembler(state_).FailAssert("Torque assert 'Convert<intptr>(insertCount) == args.length - argsStart' failed", pos_stack);
    }
  }

  TNode<IntPtrT> tmp6;
  TNode<FixedArrayBase> tmp7;
  TNode<HeapObject> tmp8;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.SetSourcePosition("../../../src/builtins/array-splice.tq", 70);
    tmp6 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp7 = CodeStubAssembler(state_).LoadReference<FixedArrayBase>(CodeStubAssembler::Reference{p_dst, tmp6});
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 162);
    compiler::CodeAssemblerLabel label9(&ca_);
    tmp8 = CodeStubAssembler(state_).TaggedToHeapObject(TNode<Object>{tmp7}, &label9);
    ca_.Goto(&block13);
    if (label9.is_used()) {
      ca_.Bind(&label9);
      ca_.Goto(&block14);
    }
  }

  if (block14.is_used()) {
    ca_.Bind(&block14);
    ca_.Goto(&block11);
  }

  TNode<FixedDoubleArray> tmp10;
  if (block13.is_used()) {
    ca_.Bind(&block13);
    compiler::CodeAssemblerLabel label11(&ca_);
    tmp10 = Cast_FixedDoubleArray_0(state_, TNode<HeapObject>{tmp8}, &label11);
    ca_.Goto(&block15);
    if (label11.is_used()) {
      ca_.Bind(&label11);
      ca_.Goto(&block16);
    }
  }

  if (block16.is_used()) {
    ca_.Bind(&block16);
    ca_.Goto(&block11);
  }

  TNode<BoolT> tmp12;
  if (block15.is_used()) {
    ca_.Bind(&block15);
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 809);
    tmp12 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block9, tmp12);
  }

  TNode<BoolT> tmp13;
  if (block11.is_used()) {
    ca_.Bind(&block11);
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 808);
    tmp13 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block9, tmp13);
  }

  TNode<BoolT> phi_bb9_12;
  if (block9.is_used()) {
    ca_.Bind(&block9, &phi_bb9_12);
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 814);
    ca_.Branch(phi_bb9_12, &block7, std::vector<compiler::Node*>{}, &block8, std::vector<compiler::Node*>{});
  }

  if (block8.is_used()) {
    ca_.Bind(&block8);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/cast.tq", 814});
      CodeStubAssembler(state_).FailAssert("Torque assert 'Is<A>(o)' failed", pos_stack);
    }
  }

  TNode<FixedDoubleArray> tmp14;
  TNode<IntPtrT> tmp15;
  if (block7.is_used()) {
    ca_.Bind(&block7);
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 815);
    tmp14 = TORQUE_CAST(TNode<Object>{tmp7});
    ca_.SetSourcePosition("../../../src/builtins/array-splice.tq", 71);
    tmp15 = FromConstexpr_intptr_constexpr_intptr_0(state_, (CodeStubAssembler(state_).ConstexprIntegerLiteralToIntptr(p_argsStart)));
    ca_.Goto(&block19, p_dstStart, tmp15);
  }

  TNode<Smi> phi_bb19_7;
  TNode<IntPtrT> phi_bb19_9;
  TNode<BoolT> tmp16;
  if (block19.is_used()) {
    ca_.Bind(&block19, &phi_bb19_7, &phi_bb19_9);
    ca_.SetSourcePosition("../../../src/builtins/array-splice.tq", 72);
    tmp16 = CodeStubAssembler(state_).IntPtrLessThan(TNode<IntPtrT>{phi_bb19_9}, TNode<IntPtrT>{p_args.length});
    ca_.SetSourcePosition("../../../src/builtins/array-splice.tq", 71);
    ca_.Branch(tmp16, &block17, std::vector<compiler::Node*>{phi_bb19_7, phi_bb19_9}, &block18, std::vector<compiler::Node*>{phi_bb19_7, phi_bb19_9});
  }

  TNode<Smi> phi_bb17_7;
  TNode<IntPtrT> phi_bb17_9;
  TNode<Object> tmp17;
  TNode<Smi> tmp18;
  TNode<Smi> tmp19;
  TNode<Number> tmp20;
  if (block17.is_used()) {
    ca_.Bind(&block17, &phi_bb17_7, &phi_bb17_9);
    ca_.SetSourcePosition("../../../src/builtins/array-splice.tq", 73);
    tmp17 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{p_args.frame}, TNode<RawPtrT>{p_args.base}, TNode<IntPtrT>{p_args.length}, TNode<IntPtrT>{p_args.actual_count}}, TNode<IntPtrT>{phi_bb17_9});
    ca_.SetSourcePosition("../../../src/builtins/array-splice.tq", 76);
    tmp18 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    tmp19 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{phi_bb17_7}, TNode<Smi>{tmp18});
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 808);
    compiler::CodeAssemblerLabel label21(&ca_);
    tmp20 = Cast_Number_0(state_, TNode<Object>{tmp17}, &label21);
    ca_.Goto(&block27, phi_bb17_9, phi_bb17_7);
    if (label21.is_used()) {
      ca_.Bind(&label21);
      ca_.Goto(&block28, phi_bb17_9, phi_bb17_7);
    }
  }

  TNode<IntPtrT> phi_bb28_9;
  TNode<Smi> phi_bb28_11;
  TNode<BoolT> tmp22;
  if (block28.is_used()) {
    ca_.Bind(&block28, &phi_bb28_9, &phi_bb28_11);
    tmp22 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block24, phi_bb28_9, phi_bb28_11, tmp22);
  }

  TNode<IntPtrT> phi_bb27_9;
  TNode<Smi> phi_bb27_11;
  TNode<BoolT> tmp23;
  if (block27.is_used()) {
    ca_.Bind(&block27, &phi_bb27_9, &phi_bb27_11);
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 809);
    tmp23 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block24, phi_bb27_9, phi_bb27_11, tmp23);
  }

  TNode<IntPtrT> phi_bb24_9;
  TNode<Smi> phi_bb24_11;
  TNode<BoolT> phi_bb24_17;
  if (block24.is_used()) {
    ca_.Bind(&block24, &phi_bb24_9, &phi_bb24_11, &phi_bb24_17);
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 814);
    ca_.Branch(phi_bb24_17, &block22, std::vector<compiler::Node*>{phi_bb24_9, phi_bb24_11}, &block23, std::vector<compiler::Node*>{phi_bb24_9, phi_bb24_11});
  }

  TNode<IntPtrT> phi_bb23_9;
  TNode<Smi> phi_bb23_11;
  if (block23.is_used()) {
    ca_.Bind(&block23, &phi_bb23_9, &phi_bb23_11);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/cast.tq", 814});
      CodeStubAssembler(state_).FailAssert("Torque assert 'Is<A>(o)' failed", pos_stack);
    }
  }

  TNode<IntPtrT> phi_bb22_9;
  TNode<Smi> phi_bb22_11;
  TNode<Number> tmp24;
  TNode<IntPtrT> tmp25;
  TNode<IntPtrT> tmp26;
  if (block22.is_used()) {
    ca_.Bind(&block22, &phi_bb22_9, &phi_bb22_11);
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 815);
    tmp24 = TORQUE_CAST(TNode<Object>{tmp17});
    ca_.SetSourcePosition("../../../src/builtins/array-splice.tq", 76);
    StoreFixedDoubleArrayDirect_0(state_, TNode<FixedDoubleArray>{tmp14}, TNode<Smi>{phi_bb22_11}, TNode<Number>{tmp24});
    ca_.SetSourcePosition("../../../src/builtins/array-splice.tq", 72);
    tmp25 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp26 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb22_9}, TNode<IntPtrT>{tmp25});
    ca_.SetSourcePosition("../../../src/builtins/array-splice.tq", 71);
    ca_.Goto(&block19, tmp19, tmp26);
  }

  TNode<Smi> phi_bb18_7;
  TNode<IntPtrT> phi_bb18_9;
  if (block18.is_used()) {
    ca_.Bind(&block18, &phi_bb18_7, &phi_bb18_9);
    ca_.SetSourcePosition("../../../src/builtins/array-splice.tq", 67);
    ca_.Goto(&block3, phi_bb18_7);
  }

  TNode<Smi> phi_bb3_7;
  if (block3.is_used()) {
    ca_.Bind(&block3, &phi_bb3_7);
    ca_.SetSourcePosition("../../../src/builtins/array-to-spliced.tq", 103);
    ca_.Goto(&block29);
  }

    ca_.Bind(&block29);
}

} // namespace internal
} // namespace v8
