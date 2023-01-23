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
#include "torque-generated/src/builtins/array-lastindexof-tq-csa.h"
#include "torque-generated/src/builtins/array-join-tq-csa.h"
#include "torque-generated/src/builtins/array-lastindexof-tq-csa.h"
#include "torque-generated/src/builtins/base-tq-csa.h"
#include "torque-generated/src/builtins/cast-tq-csa.h"
#include "torque-generated/src/builtins/convert-tq-csa.h"
#include "torque-generated/src/builtins/frame-arguments-tq-csa.h"
#include "torque-generated/src/builtins/torque-internal-tq-csa.h"
#include "torque-generated/src/objects/fixed-array-tq-csa.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-lastindexof.tq?l=10&c=1
TNode<Object> LoadWithHoleCheck_FixedArray_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<FixedArrayBase> p_elements, TNode<Smi> p_index, compiler::CodeAssemblerLabel* label_IfHole) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<FixedArray> tmp0;
  TNode<Object> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<IntPtrT> tmp3;
  TNode<IntPtrT> tmp4;
  TNode<UintPtrT> tmp5;
  TNode<UintPtrT> tmp6;
  TNode<BoolT> tmp7;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/array-lastindexof.tq", 13);
    tmp0 = UnsafeCast_FixedArray_0(state_, TNode<Context>{p_context}, TNode<Object>{p_elements});
    ca_.SetSourcePosition("../../../src/builtins/array-lastindexof.tq", 14);
    std::tie(tmp1, tmp2, tmp3) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray>{tmp0}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 118);
    tmp4 = Convert_intptr_Smi_0(state_, TNode<Smi>{p_index});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 89);
    tmp5 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp4});
    tmp6 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp3});
    tmp7 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp5}, TNode<UintPtrT>{tmp6});
    ca_.Branch(tmp7, &block7, std::vector<compiler::Node*>{}, &block8, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<Object> tmp10;
  TNode<IntPtrT> tmp11;
  TNode<Object> tmp12;
  TNode<Oddball> tmp13;
  TNode<BoolT> tmp14;
  if (block7.is_used()) {
    ca_.Bind(&block7);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 97);
    tmp8 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{tmp4});
    tmp9 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp2}, TNode<IntPtrT>{tmp8});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 96);
    std::tie(tmp10, tmp11) = NewReference_Object_0(state_, TNode<Object>{tmp1}, TNode<IntPtrT>{tmp9}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/array-lastindexof.tq", 14);
    tmp12 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp10, tmp11});
    ca_.SetSourcePosition("../../../src/builtins/array-lastindexof.tq", 15);
    tmp13 = TheHole_0(state_);
    tmp14 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp12}, TNode<HeapObject>{tmp13});
    ca_.Branch(tmp14, &block11, std::vector<compiler::Node*>{}, &block12, std::vector<compiler::Node*>{});
  }

  if (block8.is_used()) {
    ca_.Bind(&block8);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 119);
    CodeStubAssembler(state_).PrintErr("halting because of unreachable code at src/builtins/torque-internal.tq:119:41");
    CodeStubAssembler(state_).Unreachable();
  }

  if (block11.is_used()) {
    ca_.Bind(&block11);
    ca_.SetSourcePosition("../../../src/builtins/array-lastindexof.tq", 10);
    ca_.Goto(label_IfHole);
  }

  TNode<Object> tmp15;
  if (block12.is_used()) {
    ca_.Bind(&block12);
    ca_.SetSourcePosition("../../../src/builtins/array-lastindexof.tq", 16);
    tmp15 = UnsafeCast_JSAny_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp12});
    ca_.SetSourcePosition("../../../src/builtins/array-lastindexof.tq", 10);
    ca_.Goto(&block13);
  }

    ca_.Bind(&block13);
  return TNode<Object>{tmp15};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-lastindexof.tq?l=19&c=1
TNode<Object> LoadWithHoleCheck_FixedDoubleArray_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<FixedArrayBase> p_elements, TNode<Smi> p_index, compiler::CodeAssemblerLabel* label_IfHole) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<FixedDoubleArray> tmp0;
  TNode<Object> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<IntPtrT> tmp3;
  TNode<IntPtrT> tmp4;
  TNode<UintPtrT> tmp5;
  TNode<UintPtrT> tmp6;
  TNode<BoolT> tmp7;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/array-lastindexof.tq", 22);
    tmp0 = UnsafeCast_FixedDoubleArray_0(state_, TNode<Context>{p_context}, TNode<Object>{p_elements});
    ca_.SetSourcePosition("../../../src/builtins/array-lastindexof.tq", 23);
    std::tie(tmp1, tmp2, tmp3) = FieldSliceFixedDoubleArrayFloats_0(state_, TNode<FixedDoubleArray>{tmp0}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 118);
    tmp4 = Convert_intptr_Smi_0(state_, TNode<Smi>{p_index});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 89);
    tmp5 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp4});
    tmp6 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp3});
    tmp7 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp5}, TNode<UintPtrT>{tmp6});
    ca_.Branch(tmp7, &block7, std::vector<compiler::Node*>{}, &block8, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<Object> tmp10;
  TNode<IntPtrT> tmp11;
  TNode<BoolT> tmp12;
  TNode<Float64T> tmp13;
  if (block7.is_used()) {
    ca_.Bind(&block7);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 97);
    tmp8 = TimesSizeOf_float64_or_hole_0(state_, TNode<IntPtrT>{tmp4});
    tmp9 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp2}, TNode<IntPtrT>{tmp8});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 96);
    std::tie(tmp10, tmp11) = NewReference_float64_or_hole_0(state_, TNode<Object>{tmp1}, TNode<IntPtrT>{tmp9}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/array-lastindexof.tq", 23);
    std::tie(tmp12, tmp13) = LoadFloat64OrHole_0(state_, TorqueStructReference_float64_or_hole_0{TNode<Object>{tmp10}, TNode<IntPtrT>{tmp11}, TorqueStructUnsafe_0{}}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/base.tq", 161);
    ca_.Branch(tmp12, &block12, std::vector<compiler::Node*>{}, &block13, std::vector<compiler::Node*>{});
  }

  if (block8.is_used()) {
    ca_.Bind(&block8);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 119);
    CodeStubAssembler(state_).PrintErr("halting because of unreachable code at src/builtins/torque-internal.tq:119:41");
    CodeStubAssembler(state_).Unreachable();
  }

  if (block12.is_used()) {
    ca_.Bind(&block12);
    ca_.SetSourcePosition("../../../src/builtins/array-lastindexof.tq", 19);
    ca_.Goto(label_IfHole);
  }

  TNode<HeapNumber> tmp14;
  if (block13.is_used()) {
    ca_.Bind(&block13);
    ca_.SetSourcePosition("../../../src/builtins/array-lastindexof.tq", 24);
    tmp14 = CodeStubAssembler(state_).AllocateHeapNumberWithValue(TNode<Float64T>{tmp13});
    ca_.SetSourcePosition("../../../src/builtins/array-lastindexof.tq", 19);
    ca_.Goto(&block14);
  }

    ca_.Bind(&block14);
  return TNode<Object>{tmp14};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-lastindexof.tq?l=59&c=1
TNode<Number> GetFromIndex_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Number> p_length, TorqueStructArguments p_arguments) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<BoolT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/array-lastindexof.tq", 64);
    tmp0 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x2ull));
    tmp1 = CodeStubAssembler(state_).IntPtrLessThan(TNode<IntPtrT>{p_arguments.length}, TNode<IntPtrT>{tmp0});
    ca_.Branch(tmp1, &block2, std::vector<compiler::Node*>{}, &block3, std::vector<compiler::Node*>{});
  }

  TNode<Number> tmp2;
  TNode<Number> tmp3;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    tmp2 = FromConstexpr_Number_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp3 = CodeStubAssembler(state_).NumberSub(TNode<Number>{p_length}, TNode<Number>{tmp2});
    ca_.Goto(&block4, tmp3);
  }

  TNode<IntPtrT> tmp4;
  TNode<Object> tmp5;
  TNode<Number> tmp6;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    tmp4 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp5 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{p_arguments.frame}, TNode<RawPtrT>{p_arguments.base}, TNode<IntPtrT>{p_arguments.length}, TNode<IntPtrT>{p_arguments.actual_count}}, TNode<IntPtrT>{tmp4});
    tmp6 = ToInteger_Inline_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp5});
    ca_.Goto(&block4, tmp6);
  }

  TNode<Number> phi_bb4_6;
  TNode<Smi> tmp7;
  TNode<Number> tmp8;
  TNode<BoolT> tmp9;
  if (block4.is_used()) {
    ca_.Bind(&block4, &phi_bb4_6);
    ca_.SetSourcePosition("../../../src/builtins/array-lastindexof.tq", 67);
    tmp7 = SmiConstant_0(state_, IntegerLiteral(false, 0x0ull));
    ca_.SetSourcePosition("../../../src/builtins/array-lastindexof.tq", 68);
    tmp8 = FromConstexpr_Number_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp9 = NumberIsGreaterThanOrEqual_0(state_, TNode<Number>{phi_bb4_6}, TNode<Number>{tmp8});
    ca_.Branch(tmp9, &block6, std::vector<compiler::Node*>{}, &block7, std::vector<compiler::Node*>{});
  }

  TNode<Number> tmp10;
  TNode<Number> tmp11;
  TNode<Number> tmp12;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.SetSourcePosition("../../../src/builtins/array-lastindexof.tq", 71);
    tmp10 = FromConstexpr_Number_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp11 = CodeStubAssembler(state_).NumberSub(TNode<Number>{p_length}, TNode<Number>{tmp10});
    tmp12 = Min_0(state_, TNode<Number>{phi_bb4_6}, TNode<Number>{tmp11});
    ca_.SetSourcePosition("../../../src/builtins/array-lastindexof.tq", 68);
    ca_.Goto(&block8, tmp12);
  }

  TNode<Number> tmp13;
  if (block7.is_used()) {
    ca_.Bind(&block7);
    ca_.SetSourcePosition("../../../src/builtins/array-lastindexof.tq", 74);
    tmp13 = CodeStubAssembler(state_).NumberAdd(TNode<Number>{p_length}, TNode<Number>{phi_bb4_6});
    ca_.SetSourcePosition("../../../src/builtins/array-lastindexof.tq", 68);
    ca_.Goto(&block8, tmp13);
  }

  TNode<Number> phi_bb8_7;
  if (block8.is_used()) {
    ca_.Bind(&block8, &phi_bb8_7);
    ca_.SetSourcePosition("../../../src/builtins/array-lastindexof.tq", 59);
    ca_.Goto(&block9);
  }

    ca_.Bind(&block9);
  return TNode<Number>{phi_bb8_7};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-lastindexof.tq?l=79&c=1
TNode<Object> TryFastArrayLastIndexOf_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSReceiver> p_receiver, TNode<Object> p_searchElement, TNode<Number> p_from, compiler::CodeAssemblerLabel* label_Slow) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<JSArray> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/array-lastindexof.tq", 83);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = Cast_FastJSArray_0(state_, TNode<Context>{p_context}, TNode<HeapObject>{p_receiver}, &label1);
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
    ca_.SetSourcePosition("../../../src/builtins/array-lastindexof.tq", 84);
    tmp2 = CodeStubAssembler(state_).LoadFastJSArrayLength(TNode<JSArray>{tmp0});
    ca_.SetSourcePosition("../../../src/builtins/array-lastindexof.tq", 85);
    tmp3 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp4 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp2}, TNode<Smi>{tmp3});
    ca_.Branch(tmp4, &block5, std::vector<compiler::Node*>{}, &block6, std::vector<compiler::Node*>{});
  }

  TNode<Smi> tmp5;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    tmp5 = SmiConstant_0(state_, IntegerLiteral(true, 0x1ull));
    ca_.Goto(&block2, tmp5);
  }

  TNode<Smi> tmp6;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.SetSourcePosition("../../../src/builtins/array-lastindexof.tq", 87);
    compiler::CodeAssemblerLabel label7(&ca_);
    tmp6 = Cast_Smi_0(state_, TNode<Object>{p_from}, &label7);
    ca_.Goto(&block7);
    if (label7.is_used()) {
      ca_.Bind(&label7);
      ca_.Goto(&block8);
    }
  }

  if (block8.is_used()) {
    ca_.Bind(&block8);
    ca_.Goto(&block1);
  }

  TNode<IntPtrT> tmp8;
  TNode<Map> tmp9;
  TNode<Int32T> tmp10;
  TNode<BoolT> tmp11;
  if (block7.is_used()) {
    ca_.Bind(&block7);
    ca_.SetSourcePosition("../../../src/builtins/array-lastindexof.tq", 88);
    tmp8 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp9 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference{tmp0, tmp8});
    tmp10 = CodeStubAssembler(state_).LoadMapElementsKind(TNode<Map>{tmp9});
    ca_.SetSourcePosition("../../../src/builtins/array-lastindexof.tq", 89);
    tmp11 = CodeStubAssembler(state_).IsFastSmiOrTaggedElementsKind(TNode<Int32T>{tmp10});
    ca_.Branch(tmp11, &block9, std::vector<compiler::Node*>{}, &block10, std::vector<compiler::Node*>{});
  }

  TNode<Smi> tmp12;
  if (block9.is_used()) {
    ca_.Bind(&block9);
    ca_.SetSourcePosition("../../../src/builtins/array-lastindexof.tq", 90);
    tmp12 = FastArrayLastIndexOf_FixedArray_0(state_, TNode<Context>{p_context}, TNode<JSArray>{tmp0}, TNode<Smi>{tmp6}, TNode<Object>{p_searchElement});
    ca_.Goto(&block2, tmp12);
  }

  TNode<BoolT> tmp13;
  if (block10.is_used()) {
    ca_.Bind(&block10);
    ca_.SetSourcePosition("../../../src/builtins/array-lastindexof.tq", 93);
    tmp13 = CodeStubAssembler(state_).IsDoubleElementsKind(TNode<Int32T>{tmp10});
    ca_.Branch(tmp13, &block11, std::vector<compiler::Node*>{}, &block12, std::vector<compiler::Node*>{});
  }

  if (block12.is_used()) {
    ca_.Bind(&block12);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/array-lastindexof.tq", 93});
      CodeStubAssembler(state_).FailAssert("Torque assert 'IsDoubleElementsKind(kind)' failed", pos_stack);
    }
  }

  TNode<Smi> tmp14;
  if (block11.is_used()) {
    ca_.Bind(&block11);
    ca_.SetSourcePosition("../../../src/builtins/array-lastindexof.tq", 94);
    tmp14 = FastArrayLastIndexOf_FixedDoubleArray_0(state_, TNode<Context>{p_context}, TNode<JSArray>{tmp0}, TNode<Smi>{tmp6}, TNode<Object>{p_searchElement});
    ca_.Goto(&block2, tmp14);
  }

  TNode<Object> phi_bb2_4;
  if (block2.is_used()) {
    ca_.Bind(&block2, &phi_bb2_4);
    ca_.SetSourcePosition("../../../src/builtins/array-lastindexof.tq", 79);
    ca_.Goto(&block13, phi_bb2_4);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_Slow);
  }

  TNode<Object> phi_bb13_4;
    ca_.Bind(&block13, &phi_bb13_4);
  return TNode<Object>{phi_bb13_4};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-lastindexof.tq?l=98&c=1
TNode<Object> GenericArrayLastIndexOf_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSReceiver> p_object, TNode<Object> p_searchElement, TNode<Number> p_from) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/array-lastindexof.tq", 104);
    ca_.Goto(&block4, p_from);
  }

  TNode<Number> phi_bb4_4;
  TNode<Number> tmp0;
  TNode<BoolT> tmp1;
  if (block4.is_used()) {
    ca_.Bind(&block4, &phi_bb4_4);
    tmp0 = FromConstexpr_Number_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp1 = NumberIsGreaterThanOrEqual_0(state_, TNode<Number>{phi_bb4_4}, TNode<Number>{tmp0});
    ca_.Branch(tmp1, &block2, std::vector<compiler::Node*>{phi_bb4_4}, &block3, std::vector<compiler::Node*>{phi_bb4_4});
  }

  TNode<Number> phi_bb2_4;
  TNode<Oddball> tmp2;
  TNode<Oddball> tmp3;
  TNode<BoolT> tmp4;
  if (block2.is_used()) {
    ca_.Bind(&block2, &phi_bb2_4);
    ca_.SetSourcePosition("../../../src/builtins/array-lastindexof.tq", 106);
    tmp2 = ca_.CallStub<Oddball>(Builtins::CallableFor(ca_.isolate(), Builtin::kHasProperty), p_context, p_object, phi_bb2_4);
    ca_.SetSourcePosition("../../../src/builtins/array-lastindexof.tq", 109);
    tmp3 = True_0(state_);
    tmp4 = CodeStubAssembler(state_).TaggedEqual(TNode<HeapObject>{tmp2}, TNode<HeapObject>{tmp3});
    ca_.Branch(tmp4, &block5, std::vector<compiler::Node*>{phi_bb2_4}, &block6, std::vector<compiler::Node*>{phi_bb2_4});
  }

  TNode<Number> phi_bb5_4;
  TNode<Object> tmp5;
  TNode<Oddball> tmp6;
  TNode<Oddball> tmp7;
  TNode<BoolT> tmp8;
  if (block5.is_used()) {
    ca_.Bind(&block5, &phi_bb5_4);
    ca_.SetSourcePosition("../../../src/builtins/array-lastindexof.tq", 111);
    tmp5 = CodeStubAssembler(state_).GetProperty(TNode<Context>{p_context}, TNode<Object>{p_object}, TNode<Object>{phi_bb5_4});
    ca_.SetSourcePosition("../../../src/builtins/array-lastindexof.tq", 115);
    tmp6 = CodeStubAssembler(state_).StrictEqual(TNode<Object>{p_searchElement}, TNode<Object>{tmp5});
    ca_.SetSourcePosition("../../../src/builtins/array-lastindexof.tq", 118);
    tmp7 = True_0(state_);
    tmp8 = CodeStubAssembler(state_).TaggedEqual(TNode<HeapObject>{tmp6}, TNode<HeapObject>{tmp7});
    ca_.Branch(tmp8, &block7, std::vector<compiler::Node*>{phi_bb5_4}, &block8, std::vector<compiler::Node*>{phi_bb5_4});
  }

  TNode<Number> phi_bb7_4;
  if (block7.is_used()) {
    ca_.Bind(&block7, &phi_bb7_4);
    ca_.Goto(&block1, phi_bb7_4);
  }

  TNode<Number> phi_bb8_4;
  if (block8.is_used()) {
    ca_.Bind(&block8, &phi_bb8_4);
    ca_.SetSourcePosition("../../../src/builtins/array-lastindexof.tq", 109);
    ca_.Goto(&block6, phi_bb8_4);
  }

  TNode<Number> phi_bb6_4;
  TNode<Number> tmp9;
  TNode<Number> tmp10;
  if (block6.is_used()) {
    ca_.Bind(&block6, &phi_bb6_4);
    ca_.SetSourcePosition("../../../src/builtins/array-lastindexof.tq", 122);
    tmp9 = FromConstexpr_Number_constexpr_int31_0(state_, 1);
    tmp10 = CodeStubAssembler(state_).NumberSub(TNode<Number>{phi_bb6_4}, TNode<Number>{tmp9});
    ca_.SetSourcePosition("../../../src/builtins/array-lastindexof.tq", 104);
    ca_.Goto(&block4, tmp10);
  }

  TNode<Number> phi_bb3_4;
  TNode<Smi> tmp11;
  if (block3.is_used()) {
    ca_.Bind(&block3, &phi_bb3_4);
    ca_.SetSourcePosition("../../../src/builtins/array-lastindexof.tq", 126);
    tmp11 = SmiConstant_0(state_, IntegerLiteral(true, 0x1ull));
    ca_.Goto(&block1, tmp11);
  }

  TNode<Object> phi_bb1_4;
  if (block1.is_used()) {
    ca_.Bind(&block1, &phi_bb1_4);
    ca_.SetSourcePosition("../../../src/builtins/array-lastindexof.tq", 98);
    ca_.Goto(&block9, phi_bb1_4);
  }

  TNode<Object> phi_bb9_4;
    ca_.Bind(&block9, &phi_bb9_4);
  return TNode<Object>{phi_bb9_4};
}

TF_BUILTIN(ArrayPrototypeLastIndexOf, CodeStubAssembler) {
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
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<JSReceiver> tmp0;
  TNode<Number> tmp1;
  TNode<Smi> tmp2;
  TNode<BoolT> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/array-lastindexof.tq", 133);
    tmp0 = CodeStubAssembler(state_).ToObject_Inline(TNode<Context>{parameter0}, TNode<Object>{parameter1});
    ca_.SetSourcePosition("../../../src/builtins/array-lastindexof.tq", 136);
    tmp1 = GetLengthProperty_0(state_, TNode<Context>{parameter0}, TNode<Object>{tmp0});
    ca_.SetSourcePosition("../../../src/builtins/array-lastindexof.tq", 139);
    tmp2 = SmiConstant_0(state_, IntegerLiteral(false, 0x0ull));
    tmp3 = IsNumberEqual_0(state_, TNode<Number>{tmp1}, TNode<Number>{tmp2});
    ca_.Branch(tmp3, &block1, std::vector<compiler::Node*>{}, &block2, std::vector<compiler::Node*>{});
  }

  TNode<Smi> tmp4;
  if (block1.is_used()) {
    ca_.Bind(&block1);
    tmp4 = SmiConstant_0(state_, IntegerLiteral(true, 0x1ull));
    arguments.PopAndReturn(tmp4);
  }

  TNode<Number> tmp5;
  TNode<IntPtrT> tmp6;
  TNode<Object> tmp7;
  TNode<Object> tmp8;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    ca_.SetSourcePosition("../../../src/builtins/array-lastindexof.tq", 142);
    tmp5 = GetFromIndex_0(state_, TNode<Context>{parameter0}, TNode<Number>{tmp1}, TorqueStructArguments{TNode<RawPtrT>{torque_arguments.frame}, TNode<RawPtrT>{torque_arguments.base}, TNode<IntPtrT>{torque_arguments.length}, TNode<IntPtrT>{torque_arguments.actual_count}});
    ca_.SetSourcePosition("../../../src/builtins/array-lastindexof.tq", 144);
    tmp6 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp7 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{torque_arguments.frame}, TNode<RawPtrT>{torque_arguments.base}, TNode<IntPtrT>{torque_arguments.length}, TNode<IntPtrT>{torque_arguments.actual_count}}, TNode<IntPtrT>{tmp6});
    ca_.SetSourcePosition("../../../src/builtins/array-lastindexof.tq", 147);
    compiler::CodeAssemblerLabel label9(&ca_);
    tmp8 = TryFastArrayLastIndexOf_0(state_, TNode<Context>{parameter0}, TNode<JSReceiver>{tmp0}, TNode<Object>{tmp7}, TNode<Number>{tmp5}, &label9);
    ca_.Goto(&block5);
    if (label9.is_used()) {
      ca_.Bind(&label9);
      ca_.Goto(&block6);
    }
  }

  TNode<Object> tmp10;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.SetSourcePosition("../../../src/builtins/array-lastindexof.tq", 150);
    tmp10 = GenericArrayLastIndexOf_0(state_, TNode<Context>{parameter0}, TNode<JSReceiver>{tmp0}, TNode<Object>{tmp7}, TNode<Number>{tmp5});
    arguments.PopAndReturn(tmp10);
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    ca_.SetSourcePosition("../../../src/builtins/array-lastindexof.tq", 147);
    arguments.PopAndReturn(tmp8);
  }
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-lastindexof.tq?l=90&c=12
TNode<Smi> FastArrayLastIndexOf_FixedArray_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSArray> p_array, TNode<Smi> p_from, TNode<Object> p_searchElement) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block14(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block16(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<FixedArrayBase> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<Smi> tmp3;
  TNode<BoolT> tmp4;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/array-lastindexof.tq", 29);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp1 = CodeStubAssembler(state_).LoadReference<FixedArrayBase>(CodeStubAssembler::Reference{p_array, tmp0});
    ca_.SetSourcePosition("../../../src/builtins/array-lastindexof.tq", 36);
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp3 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp1, tmp2});
    tmp4 = CodeStubAssembler(state_).SmiGreaterThanOrEqual(TNode<Smi>{p_from}, TNode<Smi>{tmp3});
    ca_.Branch(tmp4, &block2, std::vector<compiler::Node*>{}, &block3, std::vector<compiler::Node*>{p_from});
  }

  TNode<IntPtrT> tmp5;
  TNode<Smi> tmp6;
  TNode<Smi> tmp7;
  TNode<Smi> tmp8;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    ca_.SetSourcePosition("../../../src/builtins/array-lastindexof.tq", 37);
    tmp5 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp6 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp1, tmp5});
    tmp7 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp8 = CodeStubAssembler(state_).SmiSub(TNode<Smi>{tmp6}, TNode<Smi>{tmp7});
    ca_.SetSourcePosition("../../../src/builtins/array-lastindexof.tq", 36);
    ca_.Goto(&block3, tmp8);
  }

  TNode<Smi> phi_bb3_5;
  if (block3.is_used()) {
    ca_.Bind(&block3, &phi_bb3_5);
    ca_.SetSourcePosition("../../../src/builtins/array-lastindexof.tq", 40);
    ca_.Goto(&block6, phi_bb3_5);
  }

  TNode<Smi> phi_bb6_5;
  TNode<Smi> tmp9;
  TNode<BoolT> tmp10;
  if (block6.is_used()) {
    ca_.Bind(&block6, &phi_bb6_5);
    tmp9 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp10 = CodeStubAssembler(state_).SmiGreaterThanOrEqual(TNode<Smi>{phi_bb6_5}, TNode<Smi>{tmp9});
    ca_.Branch(tmp10, &block4, std::vector<compiler::Node*>{phi_bb6_5}, &block5, std::vector<compiler::Node*>{phi_bb6_5});
  }

  TNode<Smi> phi_bb4_5;
  TNode<Object> tmp11;
  if (block4.is_used()) {
    ca_.Bind(&block4, &phi_bb4_5);
    ca_.SetSourcePosition("../../../src/builtins/array-lastindexof.tq", 42);
    compiler::CodeAssemblerLabel label12(&ca_);
    tmp11 = LoadWithHoleCheck_FixedArray_0(state_, TNode<Context>{p_context}, TNode<FixedArrayBase>{tmp1}, TNode<Smi>{phi_bb4_5}, &label12);
    ca_.Goto(&block9, phi_bb4_5, phi_bb4_5);
    if (label12.is_used()) {
      ca_.Bind(&label12);
      ca_.Goto(&block10, phi_bb4_5, phi_bb4_5);
    }
  }

  TNode<Smi> phi_bb10_5;
  TNode<Smi> phi_bb10_7;
  if (block10.is_used()) {
    ca_.Bind(&block10, &phi_bb10_5, &phi_bb10_7);
    ca_.SetSourcePosition("../../../src/builtins/array-lastindexof.tq", 41);
    ca_.Goto(&block7, phi_bb10_5);
  }

  TNode<Smi> phi_bb9_5;
  TNode<Smi> phi_bb9_7;
  TNode<Oddball> tmp13;
  TNode<Oddball> tmp14;
  TNode<BoolT> tmp15;
  if (block9.is_used()) {
    ca_.Bind(&block9, &phi_bb9_5, &phi_bb9_7);
    ca_.SetSourcePosition("../../../src/builtins/array-lastindexof.tq", 45);
    tmp13 = CodeStubAssembler(state_).StrictEqual(TNode<Object>{p_searchElement}, TNode<Object>{tmp11});
    ca_.SetSourcePosition("../../../src/builtins/array-lastindexof.tq", 46);
    tmp14 = True_0(state_);
    tmp15 = CodeStubAssembler(state_).TaggedEqual(TNode<HeapObject>{tmp13}, TNode<HeapObject>{tmp14});
    ca_.Branch(tmp15, &block11, std::vector<compiler::Node*>{phi_bb9_5}, &block12, std::vector<compiler::Node*>{phi_bb9_5});
  }

  TNode<Smi> phi_bb11_5;
  TNode<BoolT> tmp16;
  if (block11.is_used()) {
    ca_.Bind(&block11, &phi_bb11_5);
    ca_.SetSourcePosition("../../../src/builtins/array-lastindexof.tq", 47);
    tmp16 = Is_FastJSArray_JSArray_0(state_, TNode<Context>{p_context}, TNode<JSArray>{p_array});
    ca_.Branch(tmp16, &block13, std::vector<compiler::Node*>{phi_bb11_5}, &block14, std::vector<compiler::Node*>{phi_bb11_5});
  }

  TNode<Smi> phi_bb14_5;
  if (block14.is_used()) {
    ca_.Bind(&block14, &phi_bb14_5);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/array-lastindexof.tq", 47});
      CodeStubAssembler(state_).FailAssert("Torque assert 'Is<FastJSArray>(array)' failed", pos_stack);
    }
  }

  TNode<Smi> phi_bb13_5;
  if (block13.is_used()) {
    ca_.Bind(&block13, &phi_bb13_5);
    ca_.SetSourcePosition("../../../src/builtins/array-lastindexof.tq", 48);
    ca_.Goto(&block1, phi_bb13_5);
  }

  TNode<Smi> phi_bb12_5;
  if (block12.is_used()) {
    ca_.Bind(&block12, &phi_bb12_5);
    ca_.SetSourcePosition("../../../src/builtins/array-lastindexof.tq", 50);
    ca_.Goto(&block7, phi_bb12_5);
  }

  TNode<Smi> phi_bb7_5;
  TNode<Smi> tmp17;
  TNode<Smi> tmp18;
  if (block7.is_used()) {
    ca_.Bind(&block7, &phi_bb7_5);
    ca_.SetSourcePosition("../../../src/builtins/array-lastindexof.tq", 52);
    tmp17 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    tmp18 = CodeStubAssembler(state_).SmiSub(TNode<Smi>{phi_bb7_5}, TNode<Smi>{tmp17});
    ca_.SetSourcePosition("../../../src/builtins/array-lastindexof.tq", 40);
    ca_.Goto(&block6, tmp18);
  }

  TNode<Smi> phi_bb5_5;
  TNode<BoolT> tmp19;
  if (block5.is_used()) {
    ca_.Bind(&block5, &phi_bb5_5);
    ca_.SetSourcePosition("../../../src/builtins/array-lastindexof.tq", 55);
    tmp19 = Is_FastJSArray_JSArray_0(state_, TNode<Context>{p_context}, TNode<JSArray>{p_array});
    ca_.Branch(tmp19, &block15, std::vector<compiler::Node*>{phi_bb5_5}, &block16, std::vector<compiler::Node*>{phi_bb5_5});
  }

  TNode<Smi> phi_bb16_5;
  if (block16.is_used()) {
    ca_.Bind(&block16, &phi_bb16_5);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/array-lastindexof.tq", 55});
      CodeStubAssembler(state_).FailAssert("Torque assert 'Is<FastJSArray>(array)' failed", pos_stack);
    }
  }

  TNode<Smi> phi_bb15_5;
  TNode<Smi> tmp20;
  if (block15.is_used()) {
    ca_.Bind(&block15, &phi_bb15_5);
    ca_.SetSourcePosition("../../../src/builtins/array-lastindexof.tq", 56);
    tmp20 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(true, 0x1ull));
    ca_.Goto(&block1, tmp20);
  }

  TNode<Smi> phi_bb1_4;
  if (block1.is_used()) {
    ca_.Bind(&block1, &phi_bb1_4);
    ca_.SetSourcePosition("../../../src/builtins/array-lastindexof.tq", 90);
    ca_.Goto(&block17, phi_bb1_4);
  }

  TNode<Smi> phi_bb17_4;
    ca_.Bind(&block17, &phi_bb17_4);
  return TNode<Smi>{phi_bb17_4};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-lastindexof.tq?l=94&c=10
TNode<Smi> FastArrayLastIndexOf_FixedDoubleArray_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSArray> p_array, TNode<Smi> p_from, TNode<Object> p_searchElement) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block14(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block16(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<FixedArrayBase> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<Smi> tmp3;
  TNode<BoolT> tmp4;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/array-lastindexof.tq", 29);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp1 = CodeStubAssembler(state_).LoadReference<FixedArrayBase>(CodeStubAssembler::Reference{p_array, tmp0});
    ca_.SetSourcePosition("../../../src/builtins/array-lastindexof.tq", 36);
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp3 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp1, tmp2});
    tmp4 = CodeStubAssembler(state_).SmiGreaterThanOrEqual(TNode<Smi>{p_from}, TNode<Smi>{tmp3});
    ca_.Branch(tmp4, &block2, std::vector<compiler::Node*>{}, &block3, std::vector<compiler::Node*>{p_from});
  }

  TNode<IntPtrT> tmp5;
  TNode<Smi> tmp6;
  TNode<Smi> tmp7;
  TNode<Smi> tmp8;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    ca_.SetSourcePosition("../../../src/builtins/array-lastindexof.tq", 37);
    tmp5 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp6 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp1, tmp5});
    tmp7 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp8 = CodeStubAssembler(state_).SmiSub(TNode<Smi>{tmp6}, TNode<Smi>{tmp7});
    ca_.SetSourcePosition("../../../src/builtins/array-lastindexof.tq", 36);
    ca_.Goto(&block3, tmp8);
  }

  TNode<Smi> phi_bb3_5;
  if (block3.is_used()) {
    ca_.Bind(&block3, &phi_bb3_5);
    ca_.SetSourcePosition("../../../src/builtins/array-lastindexof.tq", 40);
    ca_.Goto(&block6, phi_bb3_5);
  }

  TNode<Smi> phi_bb6_5;
  TNode<Smi> tmp9;
  TNode<BoolT> tmp10;
  if (block6.is_used()) {
    ca_.Bind(&block6, &phi_bb6_5);
    tmp9 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp10 = CodeStubAssembler(state_).SmiGreaterThanOrEqual(TNode<Smi>{phi_bb6_5}, TNode<Smi>{tmp9});
    ca_.Branch(tmp10, &block4, std::vector<compiler::Node*>{phi_bb6_5}, &block5, std::vector<compiler::Node*>{phi_bb6_5});
  }

  TNode<Smi> phi_bb4_5;
  TNode<Object> tmp11;
  if (block4.is_used()) {
    ca_.Bind(&block4, &phi_bb4_5);
    ca_.SetSourcePosition("../../../src/builtins/array-lastindexof.tq", 42);
    compiler::CodeAssemblerLabel label12(&ca_);
    tmp11 = LoadWithHoleCheck_FixedDoubleArray_0(state_, TNode<Context>{p_context}, TNode<FixedArrayBase>{tmp1}, TNode<Smi>{phi_bb4_5}, &label12);
    ca_.Goto(&block9, phi_bb4_5, phi_bb4_5);
    if (label12.is_used()) {
      ca_.Bind(&label12);
      ca_.Goto(&block10, phi_bb4_5, phi_bb4_5);
    }
  }

  TNode<Smi> phi_bb10_5;
  TNode<Smi> phi_bb10_7;
  if (block10.is_used()) {
    ca_.Bind(&block10, &phi_bb10_5, &phi_bb10_7);
    ca_.SetSourcePosition("../../../src/builtins/array-lastindexof.tq", 41);
    ca_.Goto(&block7, phi_bb10_5);
  }

  TNode<Smi> phi_bb9_5;
  TNode<Smi> phi_bb9_7;
  TNode<Oddball> tmp13;
  TNode<Oddball> tmp14;
  TNode<BoolT> tmp15;
  if (block9.is_used()) {
    ca_.Bind(&block9, &phi_bb9_5, &phi_bb9_7);
    ca_.SetSourcePosition("../../../src/builtins/array-lastindexof.tq", 45);
    tmp13 = CodeStubAssembler(state_).StrictEqual(TNode<Object>{p_searchElement}, TNode<Object>{tmp11});
    ca_.SetSourcePosition("../../../src/builtins/array-lastindexof.tq", 46);
    tmp14 = True_0(state_);
    tmp15 = CodeStubAssembler(state_).TaggedEqual(TNode<HeapObject>{tmp13}, TNode<HeapObject>{tmp14});
    ca_.Branch(tmp15, &block11, std::vector<compiler::Node*>{phi_bb9_5}, &block12, std::vector<compiler::Node*>{phi_bb9_5});
  }

  TNode<Smi> phi_bb11_5;
  TNode<BoolT> tmp16;
  if (block11.is_used()) {
    ca_.Bind(&block11, &phi_bb11_5);
    ca_.SetSourcePosition("../../../src/builtins/array-lastindexof.tq", 47);
    tmp16 = Is_FastJSArray_JSArray_0(state_, TNode<Context>{p_context}, TNode<JSArray>{p_array});
    ca_.Branch(tmp16, &block13, std::vector<compiler::Node*>{phi_bb11_5}, &block14, std::vector<compiler::Node*>{phi_bb11_5});
  }

  TNode<Smi> phi_bb14_5;
  if (block14.is_used()) {
    ca_.Bind(&block14, &phi_bb14_5);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/array-lastindexof.tq", 47});
      CodeStubAssembler(state_).FailAssert("Torque assert 'Is<FastJSArray>(array)' failed", pos_stack);
    }
  }

  TNode<Smi> phi_bb13_5;
  if (block13.is_used()) {
    ca_.Bind(&block13, &phi_bb13_5);
    ca_.SetSourcePosition("../../../src/builtins/array-lastindexof.tq", 48);
    ca_.Goto(&block1, phi_bb13_5);
  }

  TNode<Smi> phi_bb12_5;
  if (block12.is_used()) {
    ca_.Bind(&block12, &phi_bb12_5);
    ca_.SetSourcePosition("../../../src/builtins/array-lastindexof.tq", 50);
    ca_.Goto(&block7, phi_bb12_5);
  }

  TNode<Smi> phi_bb7_5;
  TNode<Smi> tmp17;
  TNode<Smi> tmp18;
  if (block7.is_used()) {
    ca_.Bind(&block7, &phi_bb7_5);
    ca_.SetSourcePosition("../../../src/builtins/array-lastindexof.tq", 52);
    tmp17 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    tmp18 = CodeStubAssembler(state_).SmiSub(TNode<Smi>{phi_bb7_5}, TNode<Smi>{tmp17});
    ca_.SetSourcePosition("../../../src/builtins/array-lastindexof.tq", 40);
    ca_.Goto(&block6, tmp18);
  }

  TNode<Smi> phi_bb5_5;
  TNode<BoolT> tmp19;
  if (block5.is_used()) {
    ca_.Bind(&block5, &phi_bb5_5);
    ca_.SetSourcePosition("../../../src/builtins/array-lastindexof.tq", 55);
    tmp19 = Is_FastJSArray_JSArray_0(state_, TNode<Context>{p_context}, TNode<JSArray>{p_array});
    ca_.Branch(tmp19, &block15, std::vector<compiler::Node*>{phi_bb5_5}, &block16, std::vector<compiler::Node*>{phi_bb5_5});
  }

  TNode<Smi> phi_bb16_5;
  if (block16.is_used()) {
    ca_.Bind(&block16, &phi_bb16_5);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/array-lastindexof.tq", 55});
      CodeStubAssembler(state_).FailAssert("Torque assert 'Is<FastJSArray>(array)' failed", pos_stack);
    }
  }

  TNode<Smi> phi_bb15_5;
  TNode<Smi> tmp20;
  if (block15.is_used()) {
    ca_.Bind(&block15, &phi_bb15_5);
    ca_.SetSourcePosition("../../../src/builtins/array-lastindexof.tq", 56);
    tmp20 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(true, 0x1ull));
    ca_.Goto(&block1, tmp20);
  }

  TNode<Smi> phi_bb1_4;
  if (block1.is_used()) {
    ca_.Bind(&block1, &phi_bb1_4);
    ca_.SetSourcePosition("../../../src/builtins/array-lastindexof.tq", 94);
    ca_.Goto(&block17, phi_bb1_4);
  }

  TNode<Smi> phi_bb17_4;
    ca_.Bind(&block17, &phi_bb17_4);
  return TNode<Smi>{phi_bb17_4};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-lastindexof.tq?l=47&c=16
TNode<BoolT> Is_FastJSArray_JSArray_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSArray> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<JSArray> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 808);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = Cast_FastJSArray_0(state_, TNode<Context>{p_context}, TNode<HeapObject>{p_o}, &label1);
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
    ca_.SetSourcePosition("../../../src/builtins/array-lastindexof.tq", 47);
    ca_.Goto(&block6);
  }

    ca_.Bind(&block6);
  return TNode<BoolT>{phi_bb1_2};
}

} // namespace internal
} // namespace v8
