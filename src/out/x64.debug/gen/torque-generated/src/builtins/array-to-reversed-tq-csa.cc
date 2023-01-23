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
#include "torque-generated/src/builtins/array-to-reversed-tq-csa.h"
#include "torque-generated/src/builtins/array-join-tq-csa.h"
#include "torque-generated/src/builtins/array-reverse-tq-csa.h"
#include "torque-generated/src/builtins/array-to-reversed-tq-csa.h"
#include "torque-generated/src/builtins/array-tq-csa.h"
#include "torque-generated/src/builtins/base-tq-csa.h"
#include "torque-generated/src/builtins/convert-tq-csa.h"
#include "torque-generated/src/builtins/torque-internal-tq-csa.h"
#include "torque-generated/src/objects/fixed-array-tq-csa.h"
#include "torque-generated/src/objects/js-array-tq-csa.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-to-reversed.tq?l=7&c=1
TNode<JSArray> FastPackedDoubleArrayToReversed_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<FixedDoubleArray> p_elements, TNode<Smi> p_length) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<FixedArrayBase> tmp1;
  TNode<FixedDoubleArray> tmp2;
  TNode<Smi> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/array-to-reversed.tq", 12);
    tmp0 = CodeStubAssembler(state_).SmiUntag(TNode<Smi>{p_length});
    ca_.SetSourcePosition("../../../src/builtins/array-to-reversed.tq", 11);
    tmp1 = CodeStubAssembler(state_).AllocateFixedArray(ElementsKind::PACKED_DOUBLE_ELEMENTS, TNode<IntPtrT>{tmp0}, CodeStubAssembler::AllocationFlag::kAllowLargeObjectAllocation);
    tmp2 = UnsafeCast_FixedDoubleArray_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp1});
    ca_.SetSourcePosition("../../../src/builtins/array-to-reversed.tq", 16);
    tmp3 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    ca_.SetSourcePosition("../../../src/builtins/array-to-reversed.tq", 19);
    ca_.Goto(&block4, tmp3);
  }

  TNode<Smi> phi_bb4_4;
  TNode<BoolT> tmp4;
  if (block4.is_used()) {
    ca_.Bind(&block4, &phi_bb4_4);
    tmp4 = CodeStubAssembler(state_).SmiLessThan(TNode<Smi>{phi_bb4_4}, TNode<Smi>{p_length});
    ca_.Branch(tmp4, &block2, std::vector<compiler::Node*>{phi_bb4_4}, &block3, std::vector<compiler::Node*>{phi_bb4_4});
  }

  TNode<Smi> phi_bb2_4;
  TNode<Smi> tmp5;
  TNode<Smi> tmp6;
  TNode<Smi> tmp7;
  TNode<Object> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<IntPtrT> tmp10;
  TNode<IntPtrT> tmp11;
  TNode<UintPtrT> tmp12;
  TNode<UintPtrT> tmp13;
  TNode<BoolT> tmp14;
  if (block2.is_used()) {
    ca_.Bind(&block2, &phi_bb2_4);
    ca_.SetSourcePosition("../../../src/builtins/array-to-reversed.tq", 22);
    tmp5 = CodeStubAssembler(state_).SmiSub(TNode<Smi>{p_length}, TNode<Smi>{phi_bb2_4});
    tmp6 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp7 = CodeStubAssembler(state_).SmiSub(TNode<Smi>{tmp5}, TNode<Smi>{tmp6});
    ca_.SetSourcePosition("../../../src/builtins/array-to-reversed.tq", 26);
    std::tie(tmp8, tmp9, tmp10) = FieldSliceFixedDoubleArrayFloats_0(state_, TNode<FixedDoubleArray>{p_elements}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 118);
    tmp11 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp7});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 89);
    tmp12 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp11});
    tmp13 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp10});
    tmp14 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp12}, TNode<UintPtrT>{tmp13});
    ca_.Branch(tmp14, &block11, std::vector<compiler::Node*>{phi_bb2_4}, &block12, std::vector<compiler::Node*>{phi_bb2_4});
  }

  TNode<Smi> phi_bb11_4;
  TNode<IntPtrT> tmp15;
  TNode<IntPtrT> tmp16;
  TNode<Object> tmp17;
  TNode<IntPtrT> tmp18;
  TNode<BoolT> tmp19;
  TNode<Float64T> tmp20;
  if (block11.is_used()) {
    ca_.Bind(&block11, &phi_bb11_4);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 97);
    tmp15 = TimesSizeOf_float64_or_hole_0(state_, TNode<IntPtrT>{tmp11});
    tmp16 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp9}, TNode<IntPtrT>{tmp15});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 96);
    std::tie(tmp17, tmp18) = NewReference_float64_or_hole_0(state_, TNode<Object>{tmp8}, TNode<IntPtrT>{tmp16}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/array-to-reversed.tq", 26);
    std::tie(tmp19, tmp20) = LoadFloat64OrHole_0(state_, TorqueStructReference_float64_or_hole_0{TNode<Object>{tmp17}, TNode<IntPtrT>{tmp18}, TorqueStructUnsafe_0{}}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/base.tq", 161);
    ca_.Branch(tmp19, &block16, std::vector<compiler::Node*>{phi_bb11_4}, &block17, std::vector<compiler::Node*>{phi_bb11_4});
  }

  TNode<Smi> phi_bb12_4;
  if (block12.is_used()) {
    ca_.Bind(&block12, &phi_bb12_4);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 119);
    CodeStubAssembler(state_).PrintErr("halting because of unreachable code at src/builtins/torque-internal.tq:119:41");
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<Smi> phi_bb16_4;
  if (block16.is_used()) {
    ca_.Bind(&block16, &phi_bb16_4);
    ca_.SetSourcePosition("../../../src/builtins/array-to-reversed.tq", 26);
    CodeStubAssembler(state_).PrintErr("halting because of unreachable code at src/builtins/array-to-reversed.tq:26:49");
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<Smi> phi_bb17_4;
  TNode<Smi> tmp21;
  TNode<Smi> tmp22;
  if (block17.is_used()) {
    ca_.Bind(&block17, &phi_bb17_4);
    ca_.SetSourcePosition("../../../src/builtins/array-to-reversed.tq", 29);
    CodeStubAssembler(state_).StoreFixedDoubleArrayElement(TNode<FixedDoubleArray>{tmp2}, TNode<Smi>{phi_bb17_4}, TNode<Float64T>{tmp20});
    ca_.SetSourcePosition("../../../src/builtins/array-to-reversed.tq", 32);
    tmp21 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    tmp22 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{phi_bb17_4}, TNode<Smi>{tmp21});
    ca_.SetSourcePosition("../../../src/builtins/array-to-reversed.tq", 19);
    ca_.Goto(&block4, tmp22);
  }

  TNode<Smi> phi_bb3_4;
  TNode<NativeContext> tmp23;
  TNode<Map> tmp24;
  TNode<JSArray> tmp25;
  if (block3.is_used()) {
    ca_.Bind(&block3, &phi_bb3_4);
    ca_.SetSourcePosition("../../../src/builtins/array-to-reversed.tq", 37);
    tmp23 = CodeStubAssembler(state_).LoadNativeContext(TNode<Context>{p_context});
    ca_.SetSourcePosition("../../../src/builtins/array-to-reversed.tq", 36);
    tmp24 = CodeStubAssembler(state_).LoadJSArrayElementsMap(ElementsKind::PACKED_DOUBLE_ELEMENTS, TNode<NativeContext>{tmp23});
    ca_.SetSourcePosition("../../../src/builtins/array-to-reversed.tq", 38);
    tmp25 = NewJSArray_0(state_, TNode<Context>{p_context}, TNode<Map>{tmp24}, TNode<FixedArrayBase>{tmp2});
    ca_.SetSourcePosition("../../../src/builtins/array-to-reversed.tq", 7);
    ca_.Goto(&block18);
  }

    ca_.Bind(&block18);
  return TNode<JSArray>{tmp25};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-to-reversed.tq?l=81&c=1
TNode<JSArray> TryFastArrayToReversed_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_receiver, compiler::CodeAssemblerLabel* label_Slow) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block26(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block27(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSArray> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSArray> block28(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<JSArray> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/array-to-reversed.tq", 83);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = Cast_FastJSArray_1(state_, TNode<Context>{p_context}, TNode<Object>{p_receiver}, &label1);
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
  TNode<Smi> tmp3;
  TNode<BoolT> tmp4;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    ca_.SetSourcePosition("../../../src/builtins/array-to-reversed.tq", 85);
    tmp2 = CodeStubAssembler(state_).LoadFastJSArrayLength(TNode<JSArray>{tmp0});
    tmp3 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp4 = CodeStubAssembler(state_).SmiLessThan(TNode<Smi>{tmp2}, TNode<Smi>{tmp3});
    ca_.Branch(tmp4, &block5, std::vector<compiler::Node*>{}, &block6, std::vector<compiler::Node*>{});
  }

  TNode<Number> tmp5;
  TNode<JSArray> tmp6;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    tmp5 = FromConstexpr_Number_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp6 = CodeStubAssembler(state_).ArrayCreate(TNode<Context>{p_context}, TNode<Number>{tmp5});
    ca_.Goto(&block2, tmp6);
  }

  TNode<IntPtrT> tmp7;
  TNode<Map> tmp8;
  TNode<Int32T> tmp9;
  TNode<Int32T> tmp10;
  TNode<BoolT> tmp11;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.SetSourcePosition("../../../src/builtins/array-to-reversed.tq", 87);
    tmp7 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp8 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference{tmp0, tmp7});
    tmp9 = CodeStubAssembler(state_).LoadMapElementsKind(TNode<Map>{tmp8});
    ca_.SetSourcePosition("../../../src/builtins/array-to-reversed.tq", 88);
    tmp10 = FromConstexpr_ElementsKind_constexpr_PACKED_SMI_ELEMENTS_0(state_, ElementsKind::PACKED_SMI_ELEMENTS);
    tmp11 = CodeStubAssembler(state_).ElementsKindEqual(TNode<Int32T>{tmp9}, TNode<Int32T>{tmp10});
    ca_.Branch(tmp11, &block7, std::vector<compiler::Node*>{}, &block8, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp12;
  TNode<FixedArrayBase> tmp13;
  TNode<FixedArray> tmp14;
  TNode<Smi> tmp15;
  TNode<JSArray> tmp16;
  if (block7.is_used()) {
    ca_.Bind(&block7);
    ca_.SetSourcePosition("../../../src/builtins/array-to-reversed.tq", 91);
    tmp12 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp13 = CodeStubAssembler(state_).LoadReference<FixedArrayBase>(CodeStubAssembler::Reference{tmp0, tmp12});
    tmp14 = UnsafeCast_FixedArray_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp13});
    tmp15 = CodeStubAssembler(state_).LoadFastJSArrayLength(TNode<JSArray>{tmp0});
    ca_.SetSourcePosition("../../../src/builtins/array-to-reversed.tq", 89);
    tmp16 = FastArrayToReversed_FixedArray_0(state_, TNode<Context>{p_context}, ElementsKind::PACKED_SMI_ELEMENTS, TNode<FixedArray>{tmp14}, TNode<Smi>{tmp15}, false);
    ca_.Goto(&block2, tmp16);
  }

  TNode<Int32T> tmp17;
  TNode<BoolT> tmp18;
  if (block8.is_used()) {
    ca_.Bind(&block8);
    ca_.SetSourcePosition("../../../src/builtins/array-to-reversed.tq", 92);
    tmp17 = FromConstexpr_ElementsKind_constexpr_PACKED_ELEMENTS_0(state_, ElementsKind::PACKED_ELEMENTS);
    tmp18 = CodeStubAssembler(state_).ElementsKindEqual(TNode<Int32T>{tmp9}, TNode<Int32T>{tmp17});
    ca_.Branch(tmp18, &block10, std::vector<compiler::Node*>{}, &block11, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp19;
  TNode<FixedArrayBase> tmp20;
  TNode<FixedArray> tmp21;
  TNode<Smi> tmp22;
  TNode<JSArray> tmp23;
  if (block10.is_used()) {
    ca_.Bind(&block10);
    ca_.SetSourcePosition("../../../src/builtins/array-to-reversed.tq", 94);
    tmp19 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp20 = CodeStubAssembler(state_).LoadReference<FixedArrayBase>(CodeStubAssembler::Reference{tmp0, tmp19});
    tmp21 = UnsafeCast_FixedArray_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp20});
    ca_.SetSourcePosition("../../../src/builtins/array-to-reversed.tq", 95);
    tmp22 = CodeStubAssembler(state_).LoadFastJSArrayLength(TNode<JSArray>{tmp0});
    ca_.SetSourcePosition("../../../src/builtins/array-to-reversed.tq", 93);
    tmp23 = FastArrayToReversed_FixedArray_0(state_, TNode<Context>{p_context}, ElementsKind::PACKED_ELEMENTS, TNode<FixedArray>{tmp21}, TNode<Smi>{tmp22}, false);
    ca_.Goto(&block2, tmp23);
  }

  TNode<Int32T> tmp24;
  TNode<BoolT> tmp25;
  if (block11.is_used()) {
    ca_.Bind(&block11);
    ca_.SetSourcePosition("../../../src/builtins/array-to-reversed.tq", 96);
    tmp24 = FromConstexpr_ElementsKind_constexpr_PACKED_DOUBLE_ELEMENTS_0(state_, ElementsKind::PACKED_DOUBLE_ELEMENTS);
    tmp25 = CodeStubAssembler(state_).ElementsKindEqual(TNode<Int32T>{tmp9}, TNode<Int32T>{tmp24});
    ca_.Branch(tmp25, &block13, std::vector<compiler::Node*>{}, &block14, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp26;
  TNode<FixedArrayBase> tmp27;
  TNode<FixedDoubleArray> tmp28;
  TNode<Smi> tmp29;
  TNode<JSArray> tmp30;
  if (block13.is_used()) {
    ca_.Bind(&block13);
    ca_.SetSourcePosition("../../../src/builtins/array-to-reversed.tq", 98);
    tmp26 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp27 = CodeStubAssembler(state_).LoadReference<FixedArrayBase>(CodeStubAssembler::Reference{tmp0, tmp26});
    tmp28 = UnsafeCast_FixedDoubleArray_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp27});
    tmp29 = CodeStubAssembler(state_).LoadFastJSArrayLength(TNode<JSArray>{tmp0});
    ca_.SetSourcePosition("../../../src/builtins/array-to-reversed.tq", 97);
    tmp30 = FastPackedDoubleArrayToReversed_0(state_, TNode<Context>{p_context}, TNode<FixedDoubleArray>{tmp28}, TNode<Smi>{tmp29});
    ca_.Goto(&block2, tmp30);
  }

  TNode<IntPtrT> tmp31;
  TNode<Map> tmp32;
  TNode<BoolT> tmp33;
  TNode<BoolT> tmp34;
  if (block14.is_used()) {
    ca_.Bind(&block14);
    ca_.SetSourcePosition("../../../src/builtins/array-to-reversed.tq", 100);
    tmp31 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp32 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference{tmp0, tmp31});
    tmp33 = CodeStubAssembler(state_).IsPrototypeInitialArrayPrototype(TNode<Context>{p_context}, TNode<Map>{tmp32});
    tmp34 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp33});
    ca_.Branch(tmp34, &block16, std::vector<compiler::Node*>{}, &block17, std::vector<compiler::Node*>{});
  }

  if (block16.is_used()) {
    ca_.Bind(&block16);
    ca_.Goto(&block1);
  }

  TNode<BoolT> tmp35;
  if (block17.is_used()) {
    ca_.Bind(&block17);
    ca_.SetSourcePosition("../../../src/builtins/array-to-reversed.tq", 101);
    tmp35 = CodeStubAssembler(state_).IsNoElementsProtectorCellInvalid();
    ca_.Branch(tmp35, &block18, std::vector<compiler::Node*>{}, &block19, std::vector<compiler::Node*>{});
  }

  if (block18.is_used()) {
    ca_.Bind(&block18);
    ca_.Goto(&block1);
  }

  TNode<Int32T> tmp36;
  TNode<BoolT> tmp37;
  if (block19.is_used()) {
    ca_.Bind(&block19);
    ca_.SetSourcePosition("../../../src/builtins/array-to-reversed.tq", 103);
    tmp36 = FromConstexpr_ElementsKind_constexpr_HOLEY_SMI_ELEMENTS_0(state_, ElementsKind::HOLEY_SMI_ELEMENTS);
    tmp37 = CodeStubAssembler(state_).ElementsKindEqual(TNode<Int32T>{tmp9}, TNode<Int32T>{tmp36});
    ca_.Branch(tmp37, &block22, std::vector<compiler::Node*>{}, &block23, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp38;
  if (block22.is_used()) {
    ca_.Bind(&block22);
    tmp38 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block24, tmp38);
  }

  TNode<Int32T> tmp39;
  TNode<BoolT> tmp40;
  if (block23.is_used()) {
    ca_.Bind(&block23);
    ca_.SetSourcePosition("../../../src/builtins/array-to-reversed.tq", 104);
    tmp39 = FromConstexpr_ElementsKind_constexpr_HOLEY_ELEMENTS_0(state_, ElementsKind::HOLEY_ELEMENTS);
    tmp40 = CodeStubAssembler(state_).ElementsKindEqual(TNode<Int32T>{tmp9}, TNode<Int32T>{tmp39});
    ca_.SetSourcePosition("../../../src/builtins/array-to-reversed.tq", 103);
    ca_.Goto(&block24, tmp40);
  }

  TNode<BoolT> phi_bb24_5;
  if (block24.is_used()) {
    ca_.Bind(&block24, &phi_bb24_5);
    ca_.Branch(phi_bb24_5, &block20, std::vector<compiler::Node*>{}, &block21, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp41;
  TNode<FixedArrayBase> tmp42;
  TNode<FixedArray> tmp43;
  TNode<Smi> tmp44;
  TNode<JSArray> tmp45;
  if (block20.is_used()) {
    ca_.Bind(&block20);
    ca_.SetSourcePosition("../../../src/builtins/array-to-reversed.tq", 106);
    tmp41 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp42 = CodeStubAssembler(state_).LoadReference<FixedArrayBase>(CodeStubAssembler::Reference{tmp0, tmp41});
    tmp43 = UnsafeCast_FixedArray_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp42});
    ca_.SetSourcePosition("../../../src/builtins/array-to-reversed.tq", 107);
    tmp44 = CodeStubAssembler(state_).LoadFastJSArrayLength(TNode<JSArray>{tmp0});
    ca_.SetSourcePosition("../../../src/builtins/array-to-reversed.tq", 105);
    tmp45 = FastArrayToReversed_FixedArray_0(state_, TNode<Context>{p_context}, ElementsKind::PACKED_ELEMENTS, TNode<FixedArray>{tmp43}, TNode<Smi>{tmp44}, false);
    ca_.Goto(&block2, tmp45);
  }

  TNode<Int32T> tmp46;
  TNode<BoolT> tmp47;
  if (block21.is_used()) {
    ca_.Bind(&block21);
    ca_.SetSourcePosition("../../../src/builtins/array-to-reversed.tq", 108);
    tmp46 = FromConstexpr_ElementsKind_constexpr_HOLEY_DOUBLE_ELEMENTS_0(state_, ElementsKind::HOLEY_DOUBLE_ELEMENTS);
    tmp47 = CodeStubAssembler(state_).ElementsKindEqual(TNode<Int32T>{tmp9}, TNode<Int32T>{tmp46});
    ca_.Branch(tmp47, &block26, std::vector<compiler::Node*>{}, &block27, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp48;
  TNode<FixedArrayBase> tmp49;
  TNode<FixedDoubleArray> tmp50;
  TNode<Smi> tmp51;
  TNode<JSArray> tmp52;
  if (block26.is_used()) {
    ca_.Bind(&block26);
    ca_.SetSourcePosition("../../../src/builtins/array-to-reversed.tq", 111);
    tmp48 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp49 = CodeStubAssembler(state_).LoadReference<FixedArrayBase>(CodeStubAssembler::Reference{tmp0, tmp48});
    tmp50 = UnsafeCast_FixedDoubleArray_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp49});
    tmp51 = CodeStubAssembler(state_).LoadFastJSArrayLength(TNode<JSArray>{tmp0});
    ca_.SetSourcePosition("../../../src/builtins/array-to-reversed.tq", 109);
    tmp52 = FastArrayToReversed_FixedDoubleArray_0(state_, TNode<Context>{p_context}, ElementsKind::PACKED_ELEMENTS, TNode<FixedDoubleArray>{tmp50}, TNode<Smi>{tmp51}, true);
    ca_.Goto(&block2, tmp52);
  }

  if (block27.is_used()) {
    ca_.Bind(&block27);
    ca_.SetSourcePosition("../../../src/builtins/array-to-reversed.tq", 114);
    ca_.Goto(&block1);
  }

  TNode<JSArray> phi_bb2_2;
  if (block2.is_used()) {
    ca_.Bind(&block2, &phi_bb2_2);
    ca_.SetSourcePosition("../../../src/builtins/array-to-reversed.tq", 81);
    ca_.Goto(&block28, phi_bb2_2);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_Slow);
  }

  TNode<JSArray> phi_bb28_2;
    ca_.Bind(&block28, &phi_bb28_2);
  return TNode<JSArray>{phi_bb28_2};
}

TF_BUILTIN(GenericArrayToReversed, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedParameter<Context>(Descriptor::kContext);
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kReceiver);
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<JSReceiver> tmp0;
  TNode<Number> tmp1;
  TNode<JSArray> tmp2;
  TNode<Number> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/array-to-reversed.tq", 121);
    tmp0 = CodeStubAssembler(state_).ToObject_Inline(TNode<Context>{parameter0}, TNode<Object>{parameter1});
    ca_.SetSourcePosition("../../../src/builtins/array-to-reversed.tq", 124);
    tmp1 = GetLengthProperty_0(state_, TNode<Context>{parameter0}, TNode<Object>{tmp0});
    ca_.SetSourcePosition("../../../src/builtins/array-to-reversed.tq", 127);
    tmp2 = CodeStubAssembler(state_).ArrayCreate(TNode<Context>{parameter0}, TNode<Number>{tmp1});
    ca_.SetSourcePosition("../../../src/builtins/array-to-reversed.tq", 130);
    tmp3 = FromConstexpr_Number_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    ca_.SetSourcePosition("../../../src/builtins/array-to-reversed.tq", 133);
    ca_.Goto(&block3, tmp3);
  }

  TNode<Number> phi_bb3_5;
  TNode<BoolT> tmp4;
  if (block3.is_used()) {
    ca_.Bind(&block3, &phi_bb3_5);
    tmp4 = NumberIsLessThan_0(state_, TNode<Number>{phi_bb3_5}, TNode<Number>{tmp1});
    ca_.Branch(tmp4, &block1, std::vector<compiler::Node*>{phi_bb3_5}, &block2, std::vector<compiler::Node*>{phi_bb3_5});
  }

  TNode<Number> phi_bb1_5;
  TNode<Number> tmp5;
  TNode<Number> tmp6;
  TNode<Number> tmp7;
  TNode<Object> tmp8;
  TNode<Object> tmp9;
  TNode<Number> tmp10;
  TNode<Number> tmp11;
  if (block1.is_used()) {
    ca_.Bind(&block1, &phi_bb1_5);
    ca_.SetSourcePosition("../../../src/builtins/array-to-reversed.tq", 136);
    tmp5 = CodeStubAssembler(state_).NumberSub(TNode<Number>{tmp1}, TNode<Number>{phi_bb1_5});
    tmp6 = FromConstexpr_Number_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp7 = CodeStubAssembler(state_).NumberSub(TNode<Number>{tmp5}, TNode<Number>{tmp6});
    ca_.SetSourcePosition("../../../src/builtins/array-to-reversed.tq", 139);
    tmp8 = CodeStubAssembler(state_).GetProperty(TNode<Context>{parameter0}, TNode<Object>{tmp0}, TNode<Object>{tmp7});
    ca_.SetSourcePosition("../../../src/builtins/array-to-reversed.tq", 142);
    tmp9 = ca_.CallStub<Object>(Builtins::CallableFor(ca_.isolate(), Builtin::kFastCreateDataProperty), parameter0, tmp2, phi_bb1_5, tmp8);
    ca_.SetSourcePosition("../../../src/builtins/array-to-reversed.tq", 145);
    tmp10 = FromConstexpr_Number_constexpr_int31_0(state_, 1);
    tmp11 = CodeStubAssembler(state_).NumberAdd(TNode<Number>{phi_bb1_5}, TNode<Number>{tmp10});
    ca_.SetSourcePosition("../../../src/builtins/array-to-reversed.tq", 133);
    ca_.Goto(&block3, tmp11);
  }

  TNode<Number> phi_bb2_5;
  if (block2.is_used()) {
    ca_.Bind(&block2, &phi_bb2_5);
    ca_.SetSourcePosition("../../../src/builtins/array-to-reversed.tq", 149);
    CodeStubAssembler(state_).Return(tmp2);
  }
}

TF_BUILTIN(ArrayPrototypeToReversed, CodeStubAssembler) {
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
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<JSArray> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/array-to-reversed.tq", 156);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = TryFastArrayToReversed_0(state_, TNode<Context>{parameter0}, TNode<Object>{parameter1}, &label1);
    ca_.Goto(&block3);
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block4);
    }
  }

  TNode<Object> tmp2;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.SetSourcePosition("../../../src/builtins/array-to-reversed.tq", 158);
    tmp2 = ca_.CallStub<Object>(Builtins::CallableFor(ca_.isolate(), Builtin::kGenericArrayToReversed), parameter0, parameter1);
    arguments.PopAndReturn(tmp2);
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    ca_.SetSourcePosition("../../../src/builtins/array-to-reversed.tq", 156);
    arguments.PopAndReturn(tmp0);
  }
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-to-reversed.tq?l=89&c=12
TNode<JSArray> FastArrayToReversed_FixedArray_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, ElementsKind p_kind, TNode<FixedArray> p_elements, TNode<Smi> p_length, bool p_initializeArray) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<FixedArrayBase> tmp1;
  TNode<BoolT> tmp2;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/array-to-reversed.tq", 47);
    tmp0 = CodeStubAssembler(state_).SmiUntag(TNode<Smi>{p_length});
    ca_.SetSourcePosition("../../../src/builtins/array-to-reversed.tq", 46);
    tmp1 = CodeStubAssembler(state_).AllocateFixedArray(p_kind, TNode<IntPtrT>{tmp0}, CodeStubAssembler::AllocationFlag::kAllowLargeObjectAllocation);
    ca_.SetSourcePosition("../../../src/builtins/array-to-reversed.tq", 51);
    tmp2 = FromConstexpr_bool_constexpr_bool_0(state_, p_initializeArray);
    ca_.Branch(tmp2, &block2, std::vector<compiler::Node*>{}, &block3, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp3;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    ca_.SetSourcePosition("../../../src/builtins/array-to-reversed.tq", 52);
    tmp3 = Is_FixedArray_FixedArrayBase_0(state_, TNode<Context>{p_context}, TNode<FixedArrayBase>{tmp1});
    ca_.Branch(tmp3, &block4, std::vector<compiler::Node*>{}, &block5, std::vector<compiler::Node*>{});
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/array-to-reversed.tq", 52});
      CodeStubAssembler(state_).FailAssert("Torque assert 'Is<FixedArray>(copy)' failed", pos_stack);
    }
  }

  TNode<FixedArray> tmp4;
  TNode<IntPtrT> tmp5;
  TNode<IntPtrT> tmp6;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.SetSourcePosition("../../../src/builtins/array-to-reversed.tq", 54);
    tmp4 = UnsafeCast_FixedArray_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp1});
    tmp5 = CodeStubAssembler(state_).SmiUntag(TNode<Smi>{p_length});
    ca_.SetSourcePosition("../../../src/builtins/array-to-reversed.tq", 53);
    tmp6 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    CodeStubAssembler(state_).FillFixedArrayWithSmiZero(p_kind, TNode<FixedArray>{tmp4}, TNode<IntPtrT>{tmp6}, TNode<IntPtrT>{tmp5});
    ca_.SetSourcePosition("../../../src/builtins/array-to-reversed.tq", 51);
    ca_.Goto(&block3);
  }

  TNode<Smi> tmp7;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    ca_.SetSourcePosition("../../../src/builtins/array-to-reversed.tq", 58);
    tmp7 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    ca_.SetSourcePosition("../../../src/builtins/array-to-reversed.tq", 61);
    ca_.Goto(&block8, tmp7);
  }

  TNode<Smi> phi_bb8_4;
  TNode<BoolT> tmp8;
  if (block8.is_used()) {
    ca_.Bind(&block8, &phi_bb8_4);
    tmp8 = CodeStubAssembler(state_).SmiLessThan(TNode<Smi>{phi_bb8_4}, TNode<Smi>{p_length});
    ca_.Branch(tmp8, &block6, std::vector<compiler::Node*>{phi_bb8_4}, &block7, std::vector<compiler::Node*>{phi_bb8_4});
  }

  TNode<Smi> phi_bb6_4;
  TNode<Smi> tmp9;
  TNode<Smi> tmp10;
  TNode<Smi> tmp11;
  TNode<Object> tmp12;
  TNode<Smi> tmp13;
  TNode<Smi> tmp14;
  if (block6.is_used()) {
    ca_.Bind(&block6, &phi_bb6_4);
    ca_.SetSourcePosition("../../../src/builtins/array-to-reversed.tq", 64);
    tmp9 = CodeStubAssembler(state_).SmiSub(TNode<Smi>{p_length}, TNode<Smi>{phi_bb6_4});
    tmp10 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp11 = CodeStubAssembler(state_).SmiSub(TNode<Smi>{tmp9}, TNode<Smi>{tmp10});
    ca_.SetSourcePosition("../../../src/builtins/array-to-reversed.tq", 67);
    tmp12 = LoadElementOrUndefined_0(state_, TNode<Context>{p_context}, TNode<FixedArray>{p_elements}, TNode<Smi>{tmp11});
    ca_.SetSourcePosition("../../../src/builtins/array-to-reversed.tq", 70);
    StoreElement_FixedArray_Object_0(state_, TNode<Context>{p_context}, TNode<FixedArrayBase>{tmp1}, TNode<Smi>{phi_bb6_4}, TNode<Object>{tmp12});
    ca_.SetSourcePosition("../../../src/builtins/array-to-reversed.tq", 73);
    tmp13 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    tmp14 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{phi_bb6_4}, TNode<Smi>{tmp13});
    ca_.SetSourcePosition("../../../src/builtins/array-to-reversed.tq", 61);
    ca_.Goto(&block8, tmp14);
  }

  TNode<Smi> phi_bb7_4;
  TNode<NativeContext> tmp15;
  TNode<Map> tmp16;
  TNode<JSArray> tmp17;
  if (block7.is_used()) {
    ca_.Bind(&block7, &phi_bb7_4);
    ca_.SetSourcePosition("../../../src/builtins/array-to-reversed.tq", 77);
    tmp15 = CodeStubAssembler(state_).LoadNativeContext(TNode<Context>{p_context});
    tmp16 = CodeStubAssembler(state_).LoadJSArrayElementsMap(p_kind, TNode<NativeContext>{tmp15});
    ca_.SetSourcePosition("../../../src/builtins/array-to-reversed.tq", 78);
    tmp17 = NewJSArray_0(state_, TNode<Context>{p_context}, TNode<Map>{tmp16}, TNode<FixedArrayBase>{tmp1});
    ca_.SetSourcePosition("../../../src/builtins/array-to-reversed.tq", 89);
    ca_.Goto(&block9);
  }

    ca_.Bind(&block9);
  return TNode<JSArray>{tmp17};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-to-reversed.tq?l=109&c=14
TNode<JSArray> FastArrayToReversed_FixedDoubleArray_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, ElementsKind p_kind, TNode<FixedDoubleArray> p_elements, TNode<Smi> p_length, bool p_initializeArray) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<FixedArrayBase> tmp1;
  TNode<BoolT> tmp2;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/array-to-reversed.tq", 47);
    tmp0 = CodeStubAssembler(state_).SmiUntag(TNode<Smi>{p_length});
    ca_.SetSourcePosition("../../../src/builtins/array-to-reversed.tq", 46);
    tmp1 = CodeStubAssembler(state_).AllocateFixedArray(p_kind, TNode<IntPtrT>{tmp0}, CodeStubAssembler::AllocationFlag::kAllowLargeObjectAllocation);
    ca_.SetSourcePosition("../../../src/builtins/array-to-reversed.tq", 51);
    tmp2 = FromConstexpr_bool_constexpr_bool_0(state_, p_initializeArray);
    ca_.Branch(tmp2, &block2, std::vector<compiler::Node*>{}, &block3, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp3;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    ca_.SetSourcePosition("../../../src/builtins/array-to-reversed.tq", 52);
    tmp3 = Is_FixedArray_FixedArrayBase_0(state_, TNode<Context>{p_context}, TNode<FixedArrayBase>{tmp1});
    ca_.Branch(tmp3, &block4, std::vector<compiler::Node*>{}, &block5, std::vector<compiler::Node*>{});
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/array-to-reversed.tq", 52});
      CodeStubAssembler(state_).FailAssert("Torque assert 'Is<FixedArray>(copy)' failed", pos_stack);
    }
  }

  TNode<FixedArray> tmp4;
  TNode<IntPtrT> tmp5;
  TNode<IntPtrT> tmp6;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.SetSourcePosition("../../../src/builtins/array-to-reversed.tq", 54);
    tmp4 = UnsafeCast_FixedArray_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp1});
    tmp5 = CodeStubAssembler(state_).SmiUntag(TNode<Smi>{p_length});
    ca_.SetSourcePosition("../../../src/builtins/array-to-reversed.tq", 53);
    tmp6 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    CodeStubAssembler(state_).FillFixedArrayWithSmiZero(p_kind, TNode<FixedArray>{tmp4}, TNode<IntPtrT>{tmp6}, TNode<IntPtrT>{tmp5});
    ca_.SetSourcePosition("../../../src/builtins/array-to-reversed.tq", 51);
    ca_.Goto(&block3);
  }

  TNode<Smi> tmp7;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    ca_.SetSourcePosition("../../../src/builtins/array-to-reversed.tq", 58);
    tmp7 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    ca_.SetSourcePosition("../../../src/builtins/array-to-reversed.tq", 61);
    ca_.Goto(&block8, tmp7);
  }

  TNode<Smi> phi_bb8_4;
  TNode<BoolT> tmp8;
  if (block8.is_used()) {
    ca_.Bind(&block8, &phi_bb8_4);
    tmp8 = CodeStubAssembler(state_).SmiLessThan(TNode<Smi>{phi_bb8_4}, TNode<Smi>{p_length});
    ca_.Branch(tmp8, &block6, std::vector<compiler::Node*>{phi_bb8_4}, &block7, std::vector<compiler::Node*>{phi_bb8_4});
  }

  TNode<Smi> phi_bb6_4;
  TNode<Smi> tmp9;
  TNode<Smi> tmp10;
  TNode<Smi> tmp11;
  TNode<Object> tmp12;
  TNode<Smi> tmp13;
  TNode<Smi> tmp14;
  if (block6.is_used()) {
    ca_.Bind(&block6, &phi_bb6_4);
    ca_.SetSourcePosition("../../../src/builtins/array-to-reversed.tq", 64);
    tmp9 = CodeStubAssembler(state_).SmiSub(TNode<Smi>{p_length}, TNode<Smi>{phi_bb6_4});
    tmp10 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp11 = CodeStubAssembler(state_).SmiSub(TNode<Smi>{tmp9}, TNode<Smi>{tmp10});
    ca_.SetSourcePosition("../../../src/builtins/array-to-reversed.tq", 67);
    tmp12 = LoadElementOrUndefined_1(state_, TNode<FixedDoubleArray>{p_elements}, TNode<Smi>{tmp11});
    ca_.SetSourcePosition("../../../src/builtins/array-to-reversed.tq", 70);
    StoreElement_FixedArray_Object_0(state_, TNode<Context>{p_context}, TNode<FixedArrayBase>{tmp1}, TNode<Smi>{phi_bb6_4}, TNode<Object>{tmp12});
    ca_.SetSourcePosition("../../../src/builtins/array-to-reversed.tq", 73);
    tmp13 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    tmp14 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{phi_bb6_4}, TNode<Smi>{tmp13});
    ca_.SetSourcePosition("../../../src/builtins/array-to-reversed.tq", 61);
    ca_.Goto(&block8, tmp14);
  }

  TNode<Smi> phi_bb7_4;
  TNode<NativeContext> tmp15;
  TNode<Map> tmp16;
  TNode<JSArray> tmp17;
  if (block7.is_used()) {
    ca_.Bind(&block7, &phi_bb7_4);
    ca_.SetSourcePosition("../../../src/builtins/array-to-reversed.tq", 77);
    tmp15 = CodeStubAssembler(state_).LoadNativeContext(TNode<Context>{p_context});
    tmp16 = CodeStubAssembler(state_).LoadJSArrayElementsMap(p_kind, TNode<NativeContext>{tmp15});
    ca_.SetSourcePosition("../../../src/builtins/array-to-reversed.tq", 78);
    tmp17 = NewJSArray_0(state_, TNode<Context>{p_context}, TNode<Map>{tmp16}, TNode<FixedArrayBase>{tmp1});
    ca_.SetSourcePosition("../../../src/builtins/array-to-reversed.tq", 109);
    ca_.Goto(&block9);
  }

    ca_.Bind(&block9);
  return TNode<JSArray>{tmp17};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-to-reversed.tq?l=52&c=12
TNode<BoolT> Is_FixedArray_FixedArrayBase_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<FixedArrayBase> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<FixedArray> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 808);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = Cast_FixedArray_0(state_, TNode<HeapObject>{p_o}, &label1);
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
    ca_.SetSourcePosition("../../../src/builtins/array-to-reversed.tq", 52);
    ca_.Goto(&block6);
  }

    ca_.Bind(&block6);
  return TNode<BoolT>{phi_bb1_2};
}

} // namespace internal
} // namespace v8
