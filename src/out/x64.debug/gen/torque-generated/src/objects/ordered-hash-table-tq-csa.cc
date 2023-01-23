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
#include "torque-generated/src/objects/ordered-hash-table-tq-csa.h"
#include "torque-generated/src/builtins/base-tq-csa.h"
#include "torque-generated/src/builtins/builtins-string-tq-csa.h"
#include "torque-generated/src/builtins/convert-tq-csa.h"
#include "torque-generated/src/builtins/torque-internal-tq-csa.h"
#include "torque-generated/src/objects/fixed-array-tq-csa.h"
#include "torque-generated/src/objects/ordered-hash-table-tq-csa.h"
#include "torque-generated/src/objects/string-tq-csa.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/ordered-hash-table.tq?l=17&c=1
TNode<HeapObject> Cast_SmallOrderedHashTable_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError) {
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
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 17);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = DownCastForTorqueClass_SmallOrderedHashTable_0(state_, TNode<HeapObject>{p_obj}, &label1);
    ca_.Goto(&block3);
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block4);
    }
  }

  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.Goto(label_CastError);
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    ca_.Goto(&block5);
  }

    ca_.Bind(&block5);
  return TNode<HeapObject>{tmp0};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/ordered-hash-table.tq?l=24&c=1
TNode<Map> kSmallOrderedHashSetMap_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 24);
  TNode<Map> tmp0;
    tmp0 = CodeStubAssembler(state_).SmallOrderedHashSetMapConstant();
  return TNode<Map>{tmp0};}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/ordered-hash-table.tq?l=26&c=1
TNode<SmallOrderedHashSet> Cast_SmallOrderedHashSet_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<SmallOrderedHashSet> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 26);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = DownCastForTorqueClass_SmallOrderedHashSet_0(state_, TNode<HeapObject>{p_obj}, &label1);
    ca_.Goto(&block3);
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block4);
    }
  }

  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.Goto(label_CastError);
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    ca_.Goto(&block5);
  }

    ca_.Bind(&block5);
  return TNode<SmallOrderedHashSet>{tmp0};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/ordered-hash-table.tq?l=40&c=1
TNode<SmallOrderedHashSet> AllocateSmallOrderedHashSet_0(compiler::CodeAssemblerState* state_, TNode<IntPtrT> p_capacity) {
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

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<BoolT> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 42);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, SmallOrderedHashTable<int>::kLoadFactor);
    tmp1 = CodeStubAssembler(state_).IntPtrDiv(TNode<IntPtrT>{p_capacity}, TNode<IntPtrT>{tmp0});
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 44);
    tmp2 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp3 = CodeStubAssembler(state_).IntPtrLessThanOrEqual(TNode<IntPtrT>{tmp2}, TNode<IntPtrT>{tmp1});
    ca_.Branch(tmp3, &block4, std::vector<compiler::Node*>{}, &block5, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp4;
  TNode<BoolT> tmp5;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, SmallOrderedHashTable<int>::kMaxCapacity);
    tmp5 = CodeStubAssembler(state_).IntPtrLessThanOrEqual(TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp4});
    ca_.Goto(&block6, tmp5);
  }

  TNode<BoolT> tmp6;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    tmp6 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block6, tmp6);
  }

  TNode<BoolT> phi_bb6_3;
  if (block6.is_used()) {
    ca_.Bind(&block6, &phi_bb6_3);
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 43);
    ca_.Branch(phi_bb6_3, &block2, std::vector<compiler::Node*>{}, &block3, std::vector<compiler::Node*>{});
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/objects/ordered-hash-table.tq", 43});
      CodeStubAssembler(state_).FailAssert("Torque assert '0 <= hashTableSize && hashTableSize <= kSmallOrderedHashTableMaxCapacity' failed", pos_stack);
    }
  }

  TNode<Map> tmp7;
  TNode<Uint8T> tmp8;
  TNode<Uint8T> tmp9;
  TNode<Uint8T> tmp10;
  TNode<Oddball> tmp11;
  TNode<Oddball> tmp12;
  TNode<Uint8T> tmp13;
  TNode<Uint8T> tmp14;
  TNode<Uint8T> tmp15;
  TNode<Uint8T> tmp16;
  TNode<IntPtrT> tmp17;
  TNode<IntPtrT> tmp18;
  TNode<IntPtrT> tmp19;
  TNode<IntPtrT> tmp20;
  TNode<IntPtrT> tmp21;
  TNode<IntPtrT> tmp22;
  TNode<IntPtrT> tmp23;
  TNode<IntPtrT> tmp24;
  TNode<IntPtrT> tmp25;
  TNode<IntPtrT> tmp26;
  TNode<IntPtrT> tmp27;
  TNode<IntPtrT> tmp28;
  TNode<IntPtrT> tmp29;
  TNode<IntPtrT> tmp30;
  TNode<IntPtrT> tmp31;
  TNode<IntPtrT> tmp32;
  TNode<IntPtrT> tmp33;
  TNode<BoolT> tmp34;
  TNode<BoolT> tmp35;
  TNode<HeapObject> tmp36;
  TNode<IntPtrT> tmp37;
  TNode<IntPtrT> tmp38;
  TNode<Uint8T> tmp39;
  TNode<IntPtrT> tmp40;
  TNode<Uint8T> tmp41;
  TNode<IntPtrT> tmp42;
  TNode<IntPtrT> tmp43;
  TNode<IntPtrT> tmp44;
  TNode<SmallOrderedHashSet> tmp45;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 46);
    tmp7 = kSmallOrderedHashSetMap_0(state_);
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 49);
    tmp8 = Convert_uint8_intptr_0(state_, TNode<IntPtrT>{tmp1});
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 50);
    tmp9 = FromConstexpr_uint8_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    std::tie(tmp10) = ConstantIterator_uint8_0(state_, TNode<Uint8T>{tmp9}).Flatten();
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 51);
    tmp11 = TheHole_0(state_);
    std::tie(tmp12) = ConstantIterator_TheHole_0(state_, TNode<Oddball>{tmp11}).Flatten();
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 52);
    tmp13 = FromConstexpr_uint8_constexpr_int31_0(state_, SmallOrderedHashTable<int>::kNotFound);
    std::tie(tmp14) = ConstantIterator_uint8_0(state_, TNode<Uint8T>{tmp13}).Flatten();
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 53);
    tmp15 = FromConstexpr_uint8_constexpr_int31_0(state_, SmallOrderedHashTable<int>::kNotFound);
    std::tie(tmp16) = ConstantIterator_uint8_0(state_, TNode<Uint8T>{tmp15}).Flatten();
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 32);
    tmp17 = Convert_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 45);
    tmp18 = FromConstexpr_intptr_constexpr_int31_0(state_, 7);
    tmp19 = AddIndexedFieldSizeToObjectSize_0(state_, TNode<IntPtrT>{tmp18}, TNode<IntPtrT>{tmp17}, kUInt8Size);
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 33);
    tmp20 = Convert_intptr_uint8_0(state_, TNode<Uint8T>{tmp8});
    tmp21 = FromConstexpr_intptr_constexpr_int31_0(state_, SmallOrderedHashTable<int>::kLoadFactor);
    tmp22 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp20}, TNode<IntPtrT>{tmp21});
    tmp23 = Convert_intptr_intptr_0(state_, TNode<IntPtrT>{tmp22});
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 45);
    tmp24 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp25 = AddIndexedFieldSizeToObjectSize_0(state_, TNode<IntPtrT>{tmp24}, TNode<IntPtrT>{tmp23}, kTaggedSize);
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 35);
    tmp26 = Convert_intptr_uint8_0(state_, TNode<Uint8T>{tmp8});
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 45);
    tmp27 = AddIndexedFieldSizeToObjectSize_0(state_, TNode<IntPtrT>{tmp25}, TNode<IntPtrT>{tmp26}, kUInt8Size);
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 36);
    tmp28 = Convert_intptr_uint8_0(state_, TNode<Uint8T>{tmp8});
    tmp29 = FromConstexpr_intptr_constexpr_int31_0(state_, SmallOrderedHashTable<int>::kLoadFactor);
    tmp30 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp28}, TNode<IntPtrT>{tmp29});
    tmp31 = Convert_intptr_intptr_0(state_, TNode<IntPtrT>{tmp30});
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 45);
    tmp32 = AddIndexedFieldSizeToObjectSize_0(state_, TNode<IntPtrT>{tmp27}, TNode<IntPtrT>{tmp31}, kUInt8Size);
    tmp33 = AlignTagged_0(state_, TNode<IntPtrT>{tmp32});
    tmp34 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    tmp35 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    tmp36 = AllocateFromNew_0(state_, TNode<IntPtrT>{tmp33}, TNode<Map>{tmp7}, TNode<BoolT>{tmp34}, TNode<BoolT>{tmp35});
    tmp37 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    CodeStubAssembler(state_).StoreReference<Map>(CodeStubAssembler::Reference{tmp36, tmp37}, tmp7);
    tmp38 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp39 = FromConstexpr_uint8_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    CodeStubAssembler(state_).StoreReference<Uint8T>(CodeStubAssembler::Reference{tmp36, tmp38}, tmp39);
    tmp40 = FromConstexpr_intptr_constexpr_int31_0(state_, 5);
    tmp41 = FromConstexpr_uint8_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    CodeStubAssembler(state_).StoreReference<Uint8T>(CodeStubAssembler::Reference{tmp36, tmp40}, tmp41);
    tmp42 = FromConstexpr_intptr_constexpr_int31_0(state_, 6);
    CodeStubAssembler(state_).StoreReference<Uint8T>(CodeStubAssembler::Reference{tmp36, tmp42}, tmp8);
    tmp43 = FromConstexpr_intptr_constexpr_int31_0(state_, 7);
    InitializeFieldsFromIterator_uint8_ConstantIterator_uint8_0(state_, TorqueStructSlice_uint8_MutableReference_uint8_0{TNode<Object>{tmp36}, TNode<IntPtrT>{tmp43}, TNode<IntPtrT>{tmp17}, TorqueStructUnsafe_0{}}, TorqueStructConstantIterator_uint8_0{TNode<Uint8T>{tmp10}});
    tmp44 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    InitializeFieldsFromIterator_JSReceiver_OR_Smi_OR_HeapNumber_OR_BigInt_OR_String_OR_Symbol_OR_True_OR_False_OR_Null_OR_Undefined_OR_TheHole_ConstantIterator_TheHole_0(state_, TorqueStructSlice_JSReceiver_OR_Smi_OR_HeapNumber_OR_BigInt_OR_String_OR_Symbol_OR_True_OR_False_OR_Null_OR_Undefined_OR_TheHole_MutableReference_JSReceiver_OR_Smi_OR_HeapNumber_OR_BigInt_OR_String_OR_Symbol_OR_True_OR_False_OR_Null_OR_Undefined_OR_TheHole_0{TNode<Object>{tmp36}, TNode<IntPtrT>{tmp44}, TNode<IntPtrT>{tmp23}, TorqueStructUnsafe_0{}}, TorqueStructConstantIterator_TheHole_0{TNode<Oddball>{tmp12}});
    InitializeFieldsFromIterator_uint8_ConstantIterator_uint8_0(state_, TorqueStructSlice_uint8_MutableReference_uint8_0{TNode<Object>{tmp36}, TNode<IntPtrT>{tmp25}, TNode<IntPtrT>{tmp26}, TorqueStructUnsafe_0{}}, TorqueStructConstantIterator_uint8_0{TNode<Uint8T>{tmp14}});
    InitializeFieldsFromIterator_uint8_ConstantIterator_uint8_0(state_, TorqueStructSlice_uint8_MutableReference_uint8_0{TNode<Object>{tmp36}, TNode<IntPtrT>{tmp27}, TNode<IntPtrT>{tmp31}, TorqueStructUnsafe_0{}}, TorqueStructConstantIterator_uint8_0{TNode<Uint8T>{tmp16}});
    tmp45 = TORQUE_CAST(TNode<HeapObject>{tmp36});
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 40);
    ca_.Goto(&block7);
  }

    ca_.Bind(&block7);
  return TNode<SmallOrderedHashSet>{tmp45};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/ordered-hash-table.tq?l=63&c=1
TNode<Map> kSmallOrderedHashMapMap_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 63);
  TNode<Map> tmp0;
    tmp0 = CodeStubAssembler(state_).SmallOrderedHashMapMapConstant();
  return TNode<Map>{tmp0};}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/ordered-hash-table.tq?l=65&c=1
TNode<SmallOrderedHashMap> Cast_SmallOrderedHashMap_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<SmallOrderedHashMap> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 65);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = DownCastForTorqueClass_SmallOrderedHashMap_0(state_, TNode<HeapObject>{p_obj}, &label1);
    ca_.Goto(&block3);
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block4);
    }
  }

  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.Goto(label_CastError);
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    ca_.Goto(&block5);
  }

    ca_.Bind(&block5);
  return TNode<SmallOrderedHashMap>{tmp0};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/ordered-hash-table.tq?l=79&c=1
TNode<SmallOrderedHashMap> AllocateSmallOrderedHashMap_0(compiler::CodeAssemblerState* state_, TNode<IntPtrT> p_capacity) {
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

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<BoolT> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 81);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, SmallOrderedHashTable<int>::kLoadFactor);
    tmp1 = CodeStubAssembler(state_).IntPtrDiv(TNode<IntPtrT>{p_capacity}, TNode<IntPtrT>{tmp0});
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 83);
    tmp2 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp3 = CodeStubAssembler(state_).IntPtrLessThanOrEqual(TNode<IntPtrT>{tmp2}, TNode<IntPtrT>{tmp1});
    ca_.Branch(tmp3, &block4, std::vector<compiler::Node*>{}, &block5, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp4;
  TNode<BoolT> tmp5;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, SmallOrderedHashTable<int>::kMaxCapacity);
    tmp5 = CodeStubAssembler(state_).IntPtrLessThanOrEqual(TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp4});
    ca_.Goto(&block6, tmp5);
  }

  TNode<BoolT> tmp6;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    tmp6 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block6, tmp6);
  }

  TNode<BoolT> phi_bb6_3;
  if (block6.is_used()) {
    ca_.Bind(&block6, &phi_bb6_3);
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 82);
    ca_.Branch(phi_bb6_3, &block2, std::vector<compiler::Node*>{}, &block3, std::vector<compiler::Node*>{});
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/objects/ordered-hash-table.tq", 82});
      CodeStubAssembler(state_).FailAssert("Torque assert '0 <= hashTableSize && hashTableSize <= kSmallOrderedHashTableMaxCapacity' failed", pos_stack);
    }
  }

  TNode<Map> tmp7;
  TNode<Uint8T> tmp8;
  TNode<Uint8T> tmp9;
  TNode<Uint8T> tmp10;
  TNode<Oddball> tmp11;
  TNode<Oddball> tmp12;
  TNode<Object> tmp13;
  TNode<Object> tmp14;
  TNode<Uint8T> tmp15;
  TNode<Uint8T> tmp16;
  TNode<Uint8T> tmp17;
  TNode<Uint8T> tmp18;
  TNode<IntPtrT> tmp19;
  TNode<IntPtrT> tmp20;
  TNode<IntPtrT> tmp21;
  TNode<IntPtrT> tmp22;
  TNode<IntPtrT> tmp23;
  TNode<IntPtrT> tmp24;
  TNode<IntPtrT> tmp25;
  TNode<IntPtrT> tmp26;
  TNode<IntPtrT> tmp27;
  TNode<IntPtrT> tmp28;
  TNode<IntPtrT> tmp29;
  TNode<IntPtrT> tmp30;
  TNode<IntPtrT> tmp31;
  TNode<IntPtrT> tmp32;
  TNode<IntPtrT> tmp33;
  TNode<IntPtrT> tmp34;
  TNode<IntPtrT> tmp35;
  TNode<BoolT> tmp36;
  TNode<BoolT> tmp37;
  TNode<HeapObject> tmp38;
  TNode<IntPtrT> tmp39;
  TNode<IntPtrT> tmp40;
  TNode<Uint8T> tmp41;
  TNode<IntPtrT> tmp42;
  TNode<Uint8T> tmp43;
  TNode<IntPtrT> tmp44;
  TNode<IntPtrT> tmp45;
  TNode<IntPtrT> tmp46;
  TNode<SmallOrderedHashMap> tmp47;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 85);
    tmp7 = kSmallOrderedHashMapMap_0(state_);
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 88);
    tmp8 = Convert_uint8_intptr_0(state_, TNode<IntPtrT>{tmp1});
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 89);
    tmp9 = FromConstexpr_uint8_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    std::tie(tmp10) = ConstantIterator_uint8_0(state_, TNode<Uint8T>{tmp9}).Flatten();
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 90);
    tmp11 = TheHole_0(state_);
    tmp12 = TheHole_0(state_);
    std::tie(tmp13, tmp14) = ConstantIterator_HashMapEntry_0(state_, TorqueStructHashMapEntry_0{TNode<Object>{tmp11}, TNode<Object>{tmp12}}).Flatten();
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 91);
    tmp15 = FromConstexpr_uint8_constexpr_int31_0(state_, SmallOrderedHashTable<int>::kNotFound);
    std::tie(tmp16) = ConstantIterator_uint8_0(state_, TNode<Uint8T>{tmp15}).Flatten();
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 92);
    tmp17 = FromConstexpr_uint8_constexpr_int31_0(state_, SmallOrderedHashTable<int>::kNotFound);
    std::tie(tmp18) = ConstantIterator_uint8_0(state_, TNode<Uint8T>{tmp17}).Flatten();
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 71);
    tmp19 = Convert_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 84);
    tmp20 = FromConstexpr_intptr_constexpr_int31_0(state_, 7);
    tmp21 = AddIndexedFieldSizeToObjectSize_0(state_, TNode<IntPtrT>{tmp20}, TNode<IntPtrT>{tmp19}, kUInt8Size);
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 72);
    tmp22 = Convert_intptr_uint8_0(state_, TNode<Uint8T>{tmp8});
    tmp23 = FromConstexpr_intptr_constexpr_int31_0(state_, SmallOrderedHashTable<int>::kLoadFactor);
    tmp24 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp22}, TNode<IntPtrT>{tmp23});
    tmp25 = Convert_intptr_intptr_0(state_, TNode<IntPtrT>{tmp24});
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 84);
    tmp26 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp27 = AddIndexedFieldSizeToObjectSize_0(state_, TNode<IntPtrT>{tmp26}, TNode<IntPtrT>{tmp25}, 8);
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 74);
    tmp28 = Convert_intptr_uint8_0(state_, TNode<Uint8T>{tmp8});
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 84);
    tmp29 = AddIndexedFieldSizeToObjectSize_0(state_, TNode<IntPtrT>{tmp27}, TNode<IntPtrT>{tmp28}, kUInt8Size);
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 75);
    tmp30 = Convert_intptr_uint8_0(state_, TNode<Uint8T>{tmp8});
    tmp31 = FromConstexpr_intptr_constexpr_int31_0(state_, SmallOrderedHashTable<int>::kLoadFactor);
    tmp32 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp30}, TNode<IntPtrT>{tmp31});
    tmp33 = Convert_intptr_intptr_0(state_, TNode<IntPtrT>{tmp32});
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 84);
    tmp34 = AddIndexedFieldSizeToObjectSize_0(state_, TNode<IntPtrT>{tmp29}, TNode<IntPtrT>{tmp33}, kUInt8Size);
    tmp35 = AlignTagged_0(state_, TNode<IntPtrT>{tmp34});
    tmp36 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    tmp37 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    tmp38 = AllocateFromNew_0(state_, TNode<IntPtrT>{tmp35}, TNode<Map>{tmp7}, TNode<BoolT>{tmp36}, TNode<BoolT>{tmp37});
    tmp39 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    CodeStubAssembler(state_).StoreReference<Map>(CodeStubAssembler::Reference{tmp38, tmp39}, tmp7);
    tmp40 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp41 = FromConstexpr_uint8_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    CodeStubAssembler(state_).StoreReference<Uint8T>(CodeStubAssembler::Reference{tmp38, tmp40}, tmp41);
    tmp42 = FromConstexpr_intptr_constexpr_int31_0(state_, 5);
    tmp43 = FromConstexpr_uint8_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    CodeStubAssembler(state_).StoreReference<Uint8T>(CodeStubAssembler::Reference{tmp38, tmp42}, tmp43);
    tmp44 = FromConstexpr_intptr_constexpr_int31_0(state_, 6);
    CodeStubAssembler(state_).StoreReference<Uint8T>(CodeStubAssembler::Reference{tmp38, tmp44}, tmp8);
    tmp45 = FromConstexpr_intptr_constexpr_int31_0(state_, 7);
    InitializeFieldsFromIterator_uint8_ConstantIterator_uint8_0(state_, TorqueStructSlice_uint8_MutableReference_uint8_0{TNode<Object>{tmp38}, TNode<IntPtrT>{tmp45}, TNode<IntPtrT>{tmp19}, TorqueStructUnsafe_0{}}, TorqueStructConstantIterator_uint8_0{TNode<Uint8T>{tmp10}});
    tmp46 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    InitializeFieldsFromIterator_HashMapEntry_ConstantIterator_HashMapEntry_0(state_, TorqueStructSlice_HashMapEntry_MutableReference_HashMapEntry_0{TNode<Object>{tmp38}, TNode<IntPtrT>{tmp46}, TNode<IntPtrT>{tmp25}, TorqueStructUnsafe_0{}}, TorqueStructConstantIterator_HashMapEntry_0{TorqueStructHashMapEntry_0{TNode<Object>{tmp13}, TNode<Object>{tmp14}}});
    InitializeFieldsFromIterator_uint8_ConstantIterator_uint8_0(state_, TorqueStructSlice_uint8_MutableReference_uint8_0{TNode<Object>{tmp38}, TNode<IntPtrT>{tmp27}, TNode<IntPtrT>{tmp28}, TorqueStructUnsafe_0{}}, TorqueStructConstantIterator_uint8_0{TNode<Uint8T>{tmp16}});
    InitializeFieldsFromIterator_uint8_ConstantIterator_uint8_0(state_, TorqueStructSlice_uint8_MutableReference_uint8_0{TNode<Object>{tmp38}, TNode<IntPtrT>{tmp29}, TNode<IntPtrT>{tmp33}, TorqueStructUnsafe_0{}}, TorqueStructConstantIterator_uint8_0{TNode<Uint8T>{tmp18}});
    tmp47 = TORQUE_CAST(TNode<HeapObject>{tmp38});
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 79);
    ca_.Goto(&block7);
  }

    ca_.Bind(&block7);
  return TNode<SmallOrderedHashMap>{tmp47};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/ordered-hash-table.tq?l=102&c=1
TNode<SmallOrderedNameDictionary> Cast_SmallOrderedNameDictionary_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<SmallOrderedNameDictionary> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 102);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = DownCastForTorqueClass_SmallOrderedNameDictionary_0(state_, TNode<HeapObject>{p_obj}, &label1);
    ca_.Goto(&block3);
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block4);
    }
  }

  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.Goto(label_CastError);
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    ca_.Goto(&block5);
  }

    ca_.Bind(&block5);
  return TNode<SmallOrderedNameDictionary>{tmp0};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/ordered-hash-table.tq?l=28&c=3
TNode<Uint8T> LoadSmallOrderedHashSetNumberOfElements_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedHashSet> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Uint8T> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 28);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp1 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference{p_o, tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Uint8T>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/ordered-hash-table.tq?l=28&c=3
void StoreSmallOrderedHashSetNumberOfElements_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedHashSet> p_o, TNode<Uint8T> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 28);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    CodeStubAssembler(state_).StoreReference<Uint8T>(CodeStubAssembler::Reference{p_o, tmp0}, p_v);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/ordered-hash-table.tq?l=29&c=3
TNode<Uint8T> LoadSmallOrderedHashSetNumberOfDeletedElements_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedHashSet> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Uint8T> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 29);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 5);
    tmp1 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference{p_o, tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Uint8T>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/ordered-hash-table.tq?l=29&c=3
void StoreSmallOrderedHashSetNumberOfDeletedElements_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedHashSet> p_o, TNode<Uint8T> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 29);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 5);
    CodeStubAssembler(state_).StoreReference<Uint8T>(CodeStubAssembler::Reference{p_o, tmp0}, p_v);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/ordered-hash-table.tq?l=30&c=9
TNode<Uint8T> LoadSmallOrderedHashSetNumberOfBuckets_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedHashSet> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Uint8T> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 30);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 6);
    tmp1 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference{p_o, tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Uint8T>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/ordered-hash-table.tq?l=32&c=31
TorqueStructSlice_uint8_MutableReference_uint8_0 FieldSliceSmallOrderedHashSetPadding_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedHashSet> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<Object> tmp2;
  TNode<IntPtrT> tmp3;
  TNode<IntPtrT> tmp4;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 32);
    tmp0 = Convert_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp1 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x7ull));
    std::tie(tmp2, tmp3, tmp4) = NewMutableSlice_uint8_0(state_, TNode<Object>{p_o}, TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp0}).Flatten();
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TorqueStructSlice_uint8_MutableReference_uint8_0{TNode<Object>{tmp2}, TNode<IntPtrT>{tmp3}, TNode<IntPtrT>{tmp4}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/ordered-hash-table.tq?l=32&c=31
TNode<Uint8T> LoadSmallOrderedHashSetPadding_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedHashSet> p_o, TNode<IntPtrT> p_i) {
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
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 32);
    std::tie(tmp0, tmp1, tmp2) = FieldSliceSmallOrderedHashSetPadding_0(state_, TNode<SmallOrderedHashSet>{p_o}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 89);
    tmp3 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{p_i});
    tmp4 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp2});
    tmp5 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp3}, TNode<UintPtrT>{tmp4});
    ca_.Branch(tmp5, &block6, std::vector<compiler::Node*>{}, &block7, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<Object> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<Uint8T> tmp10;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 97);
    tmp6 = TimesSizeOf_uint8_0(state_, TNode<IntPtrT>{p_i});
    tmp7 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp6});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 96);
    std::tie(tmp8, tmp9) = NewReference_uint8_0(state_, TNode<Object>{tmp0}, TNode<IntPtrT>{tmp7}).Flatten();
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 32);
    tmp10 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference{tmp8, tmp9});
    ca_.Goto(&block10);
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 101);
    CodeStubAssembler(state_).PrintErr("halting because of unreachable code at src/builtins/torque-internal.tq:101:45");
    CodeStubAssembler(state_).Unreachable();
  }

    ca_.Bind(&block10);
  return TNode<Uint8T>{tmp10};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/ordered-hash-table.tq?l=32&c=31
void StoreSmallOrderedHashSetPadding_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedHashSet> p_o, TNode<IntPtrT> p_i, TNode<Uint8T> p_v) {
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
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 32);
    std::tie(tmp0, tmp1, tmp2) = FieldSliceSmallOrderedHashSetPadding_0(state_, TNode<SmallOrderedHashSet>{p_o}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 89);
    tmp3 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{p_i});
    tmp4 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp2});
    tmp5 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp3}, TNode<UintPtrT>{tmp4});
    ca_.Branch(tmp5, &block6, std::vector<compiler::Node*>{}, &block7, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<Object> tmp8;
  TNode<IntPtrT> tmp9;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 97);
    tmp6 = TimesSizeOf_uint8_0(state_, TNode<IntPtrT>{p_i});
    tmp7 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp6});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 96);
    std::tie(tmp8, tmp9) = NewReference_uint8_0(state_, TNode<Object>{tmp0}, TNode<IntPtrT>{tmp7}).Flatten();
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 32);
    CodeStubAssembler(state_).StoreReference<Uint8T>(CodeStubAssembler::Reference{tmp8, tmp9}, p_v);
    ca_.Goto(&block10);
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 101);
    CodeStubAssembler(state_).PrintErr("halting because of unreachable code at src/builtins/torque-internal.tq:101:45");
    CodeStubAssembler(state_).Unreachable();
  }

    ca_.Bind(&block10);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/ordered-hash-table.tq?l=33&c=3
TorqueStructSlice_JSReceiver_OR_Smi_OR_HeapNumber_OR_BigInt_OR_String_OR_Symbol_OR_True_OR_False_OR_Null_OR_Undefined_OR_TheHole_MutableReference_JSReceiver_OR_Smi_OR_HeapNumber_OR_BigInt_OR_String_OR_Symbol_OR_True_OR_False_OR_Null_OR_Undefined_OR_TheHole_0 FieldSliceSmallOrderedHashSetDataTable_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedHashSet> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Uint8T> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<IntPtrT> tmp3;
  TNode<IntPtrT> tmp4;
  TNode<IntPtrT> tmp5;
  TNode<IntPtrT> tmp6;
  TNode<Object> tmp7;
  TNode<IntPtrT> tmp8;
  TNode<IntPtrT> tmp9;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 33);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 6);
    tmp1 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference{p_o, tmp0});
    tmp2 = Convert_intptr_uint8_0(state_, TNode<Uint8T>{tmp1});
    tmp3 = FromConstexpr_intptr_constexpr_int31_0(state_, SmallOrderedHashTable<int>::kLoadFactor);
    tmp4 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp2}, TNode<IntPtrT>{tmp3});
    tmp5 = Convert_intptr_intptr_0(state_, TNode<IntPtrT>{tmp4});
    tmp6 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x8ull));
    std::tie(tmp7, tmp8, tmp9) = NewMutableSlice_JSReceiver_OR_Smi_OR_HeapNumber_OR_BigInt_OR_String_OR_Symbol_OR_True_OR_False_OR_Null_OR_Undefined_OR_TheHole_0(state_, TNode<Object>{p_o}, TNode<IntPtrT>{tmp6}, TNode<IntPtrT>{tmp5}).Flatten();
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TorqueStructSlice_JSReceiver_OR_Smi_OR_HeapNumber_OR_BigInt_OR_String_OR_Symbol_OR_True_OR_False_OR_Null_OR_Undefined_OR_TheHole_MutableReference_JSReceiver_OR_Smi_OR_HeapNumber_OR_BigInt_OR_String_OR_Symbol_OR_True_OR_False_OR_Null_OR_Undefined_OR_TheHole_0{TNode<Object>{tmp7}, TNode<IntPtrT>{tmp8}, TNode<IntPtrT>{tmp9}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/ordered-hash-table.tq?l=33&c=3
TNode<Object> LoadSmallOrderedHashSetDataTable_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedHashSet> p_o, TNode<IntPtrT> p_i) {
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
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 33);
    std::tie(tmp0, tmp1, tmp2) = FieldSliceSmallOrderedHashSetDataTable_0(state_, TNode<SmallOrderedHashSet>{p_o}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 89);
    tmp3 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{p_i});
    tmp4 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp2});
    tmp5 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp3}, TNode<UintPtrT>{tmp4});
    ca_.Branch(tmp5, &block6, std::vector<compiler::Node*>{}, &block7, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<Object> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<Object> tmp10;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 97);
    tmp6 = TimesSizeOf_JSReceiver_OR_Smi_OR_HeapNumber_OR_BigInt_OR_String_OR_Symbol_OR_True_OR_False_OR_Null_OR_Undefined_OR_TheHole_0(state_, TNode<IntPtrT>{p_i});
    tmp7 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp6});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 96);
    std::tie(tmp8, tmp9) = NewReference_JSReceiver_OR_Smi_OR_HeapNumber_OR_BigInt_OR_String_OR_Symbol_OR_True_OR_False_OR_Null_OR_Undefined_OR_TheHole_0(state_, TNode<Object>{tmp0}, TNode<IntPtrT>{tmp7}).Flatten();
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 33);
    tmp10 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp8, tmp9});
    ca_.Goto(&block10);
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 101);
    CodeStubAssembler(state_).PrintErr("halting because of unreachable code at src/builtins/torque-internal.tq:101:45");
    CodeStubAssembler(state_).Unreachable();
  }

    ca_.Bind(&block10);
  return TNode<Object>{tmp10};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/ordered-hash-table.tq?l=33&c=3
void StoreSmallOrderedHashSetDataTable_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedHashSet> p_o, TNode<IntPtrT> p_i, TNode<Object> p_v) {
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
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 33);
    std::tie(tmp0, tmp1, tmp2) = FieldSliceSmallOrderedHashSetDataTable_0(state_, TNode<SmallOrderedHashSet>{p_o}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 89);
    tmp3 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{p_i});
    tmp4 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp2});
    tmp5 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp3}, TNode<UintPtrT>{tmp4});
    ca_.Branch(tmp5, &block6, std::vector<compiler::Node*>{}, &block7, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<Object> tmp8;
  TNode<IntPtrT> tmp9;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 97);
    tmp6 = TimesSizeOf_JSReceiver_OR_Smi_OR_HeapNumber_OR_BigInt_OR_String_OR_Symbol_OR_True_OR_False_OR_Null_OR_Undefined_OR_TheHole_0(state_, TNode<IntPtrT>{p_i});
    tmp7 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp6});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 96);
    std::tie(tmp8, tmp9) = NewReference_JSReceiver_OR_Smi_OR_HeapNumber_OR_BigInt_OR_String_OR_Symbol_OR_True_OR_False_OR_Null_OR_Undefined_OR_TheHole_0(state_, TNode<Object>{tmp0}, TNode<IntPtrT>{tmp7}).Flatten();
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 33);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp8, tmp9}, p_v);
    ca_.Goto(&block10);
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 101);
    CodeStubAssembler(state_).PrintErr("halting because of unreachable code at src/builtins/torque-internal.tq:101:45");
    CodeStubAssembler(state_).Unreachable();
  }

    ca_.Bind(&block10);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/ordered-hash-table.tq?l=35&c=3
TorqueStructSlice_uint8_MutableReference_uint8_0 FieldSliceSmallOrderedHashSetHashTable_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedHashSet> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Object> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<IntPtrT> tmp3;
  TNode<IntPtrT> tmp4;
  TNode<IntPtrT> tmp5;
  TNode<IntPtrT> tmp6;
  TNode<Uint8T> tmp7;
  TNode<IntPtrT> tmp8;
  TNode<Object> tmp9;
  TNode<IntPtrT> tmp10;
  TNode<IntPtrT> tmp11;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 35);
    std::tie(tmp0, tmp1, tmp2) = FieldSliceSmallOrderedHashSetDataTable_0(state_, TNode<SmallOrderedHashSet>{p_o}).Flatten();
    tmp3 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x4ull));
    tmp4 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp3}, TNode<IntPtrT>{tmp2});
    tmp5 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp4});
    tmp6 = FromConstexpr_intptr_constexpr_int31_0(state_, 6);
    tmp7 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference{p_o, tmp6});
    tmp8 = Convert_intptr_uint8_0(state_, TNode<Uint8T>{tmp7});
    std::tie(tmp9, tmp10, tmp11) = NewMutableSlice_uint8_0(state_, TNode<Object>{p_o}, TNode<IntPtrT>{tmp5}, TNode<IntPtrT>{tmp8}).Flatten();
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TorqueStructSlice_uint8_MutableReference_uint8_0{TNode<Object>{tmp9}, TNode<IntPtrT>{tmp10}, TNode<IntPtrT>{tmp11}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/ordered-hash-table.tq?l=35&c=3
TNode<Uint8T> LoadSmallOrderedHashSetHashTable_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedHashSet> p_o, TNode<IntPtrT> p_i) {
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
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 35);
    std::tie(tmp0, tmp1, tmp2) = FieldSliceSmallOrderedHashSetHashTable_0(state_, TNode<SmallOrderedHashSet>{p_o}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 89);
    tmp3 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{p_i});
    tmp4 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp2});
    tmp5 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp3}, TNode<UintPtrT>{tmp4});
    ca_.Branch(tmp5, &block6, std::vector<compiler::Node*>{}, &block7, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<Object> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<Uint8T> tmp10;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 97);
    tmp6 = TimesSizeOf_uint8_0(state_, TNode<IntPtrT>{p_i});
    tmp7 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp6});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 96);
    std::tie(tmp8, tmp9) = NewReference_uint8_0(state_, TNode<Object>{tmp0}, TNode<IntPtrT>{tmp7}).Flatten();
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 35);
    tmp10 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference{tmp8, tmp9});
    ca_.Goto(&block10);
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 101);
    CodeStubAssembler(state_).PrintErr("halting because of unreachable code at src/builtins/torque-internal.tq:101:45");
    CodeStubAssembler(state_).Unreachable();
  }

    ca_.Bind(&block10);
  return TNode<Uint8T>{tmp10};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/ordered-hash-table.tq?l=35&c=3
void StoreSmallOrderedHashSetHashTable_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedHashSet> p_o, TNode<IntPtrT> p_i, TNode<Uint8T> p_v) {
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
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 35);
    std::tie(tmp0, tmp1, tmp2) = FieldSliceSmallOrderedHashSetHashTable_0(state_, TNode<SmallOrderedHashSet>{p_o}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 89);
    tmp3 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{p_i});
    tmp4 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp2});
    tmp5 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp3}, TNode<UintPtrT>{tmp4});
    ca_.Branch(tmp5, &block6, std::vector<compiler::Node*>{}, &block7, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<Object> tmp8;
  TNode<IntPtrT> tmp9;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 97);
    tmp6 = TimesSizeOf_uint8_0(state_, TNode<IntPtrT>{p_i});
    tmp7 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp6});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 96);
    std::tie(tmp8, tmp9) = NewReference_uint8_0(state_, TNode<Object>{tmp0}, TNode<IntPtrT>{tmp7}).Flatten();
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 35);
    CodeStubAssembler(state_).StoreReference<Uint8T>(CodeStubAssembler::Reference{tmp8, tmp9}, p_v);
    ca_.Goto(&block10);
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 101);
    CodeStubAssembler(state_).PrintErr("halting because of unreachable code at src/builtins/torque-internal.tq:101:45");
    CodeStubAssembler(state_).Unreachable();
  }

    ca_.Bind(&block10);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/ordered-hash-table.tq?l=36&c=3
TorqueStructSlice_uint8_MutableReference_uint8_0 FieldSliceSmallOrderedHashSetChainTable_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedHashSet> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Object> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<IntPtrT> tmp3;
  TNode<IntPtrT> tmp4;
  TNode<IntPtrT> tmp5;
  TNode<IntPtrT> tmp6;
  TNode<Uint8T> tmp7;
  TNode<IntPtrT> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<IntPtrT> tmp10;
  TNode<IntPtrT> tmp11;
  TNode<Object> tmp12;
  TNode<IntPtrT> tmp13;
  TNode<IntPtrT> tmp14;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 36);
    std::tie(tmp0, tmp1, tmp2) = FieldSliceSmallOrderedHashSetHashTable_0(state_, TNode<SmallOrderedHashSet>{p_o}).Flatten();
    tmp3 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp4 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp3}, TNode<IntPtrT>{tmp2});
    tmp5 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp4});
    tmp6 = FromConstexpr_intptr_constexpr_int31_0(state_, 6);
    tmp7 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference{p_o, tmp6});
    tmp8 = Convert_intptr_uint8_0(state_, TNode<Uint8T>{tmp7});
    tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, SmallOrderedHashTable<int>::kLoadFactor);
    tmp10 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp8}, TNode<IntPtrT>{tmp9});
    tmp11 = Convert_intptr_intptr_0(state_, TNode<IntPtrT>{tmp10});
    std::tie(tmp12, tmp13, tmp14) = NewMutableSlice_uint8_0(state_, TNode<Object>{p_o}, TNode<IntPtrT>{tmp5}, TNode<IntPtrT>{tmp11}).Flatten();
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TorqueStructSlice_uint8_MutableReference_uint8_0{TNode<Object>{tmp12}, TNode<IntPtrT>{tmp13}, TNode<IntPtrT>{tmp14}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/ordered-hash-table.tq?l=36&c=3
TNode<Uint8T> LoadSmallOrderedHashSetChainTable_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedHashSet> p_o, TNode<IntPtrT> p_i) {
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
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 36);
    std::tie(tmp0, tmp1, tmp2) = FieldSliceSmallOrderedHashSetChainTable_0(state_, TNode<SmallOrderedHashSet>{p_o}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 89);
    tmp3 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{p_i});
    tmp4 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp2});
    tmp5 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp3}, TNode<UintPtrT>{tmp4});
    ca_.Branch(tmp5, &block6, std::vector<compiler::Node*>{}, &block7, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<Object> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<Uint8T> tmp10;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 97);
    tmp6 = TimesSizeOf_uint8_0(state_, TNode<IntPtrT>{p_i});
    tmp7 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp6});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 96);
    std::tie(tmp8, tmp9) = NewReference_uint8_0(state_, TNode<Object>{tmp0}, TNode<IntPtrT>{tmp7}).Flatten();
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 36);
    tmp10 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference{tmp8, tmp9});
    ca_.Goto(&block10);
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 101);
    CodeStubAssembler(state_).PrintErr("halting because of unreachable code at src/builtins/torque-internal.tq:101:45");
    CodeStubAssembler(state_).Unreachable();
  }

    ca_.Bind(&block10);
  return TNode<Uint8T>{tmp10};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/ordered-hash-table.tq?l=36&c=3
void StoreSmallOrderedHashSetChainTable_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedHashSet> p_o, TNode<IntPtrT> p_i, TNode<Uint8T> p_v) {
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
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 36);
    std::tie(tmp0, tmp1, tmp2) = FieldSliceSmallOrderedHashSetChainTable_0(state_, TNode<SmallOrderedHashSet>{p_o}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 89);
    tmp3 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{p_i});
    tmp4 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp2});
    tmp5 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp3}, TNode<UintPtrT>{tmp4});
    ca_.Branch(tmp5, &block6, std::vector<compiler::Node*>{}, &block7, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<Object> tmp8;
  TNode<IntPtrT> tmp9;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 97);
    tmp6 = TimesSizeOf_uint8_0(state_, TNode<IntPtrT>{p_i});
    tmp7 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp6});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 96);
    std::tie(tmp8, tmp9) = NewReference_uint8_0(state_, TNode<Object>{tmp0}, TNode<IntPtrT>{tmp7}).Flatten();
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 36);
    CodeStubAssembler(state_).StoreReference<Uint8T>(CodeStubAssembler::Reference{tmp8, tmp9}, p_v);
    ca_.Goto(&block10);
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 101);
    CodeStubAssembler(state_).PrintErr("halting because of unreachable code at src/builtins/torque-internal.tq:101:45");
    CodeStubAssembler(state_).Unreachable();
  }

    ca_.Bind(&block10);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/ordered-hash-table.tq?l=67&c=3
TNode<Uint8T> LoadSmallOrderedHashMapNumberOfElements_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedHashMap> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Uint8T> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 67);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp1 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference{p_o, tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Uint8T>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/ordered-hash-table.tq?l=67&c=3
void StoreSmallOrderedHashMapNumberOfElements_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedHashMap> p_o, TNode<Uint8T> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 67);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    CodeStubAssembler(state_).StoreReference<Uint8T>(CodeStubAssembler::Reference{p_o, tmp0}, p_v);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/ordered-hash-table.tq?l=68&c=3
TNode<Uint8T> LoadSmallOrderedHashMapNumberOfDeletedElements_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedHashMap> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Uint8T> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 68);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 5);
    tmp1 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference{p_o, tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Uint8T>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/ordered-hash-table.tq?l=68&c=3
void StoreSmallOrderedHashMapNumberOfDeletedElements_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedHashMap> p_o, TNode<Uint8T> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 68);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 5);
    CodeStubAssembler(state_).StoreReference<Uint8T>(CodeStubAssembler::Reference{p_o, tmp0}, p_v);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/ordered-hash-table.tq?l=69&c=9
TNode<Uint8T> LoadSmallOrderedHashMapNumberOfBuckets_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedHashMap> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Uint8T> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 69);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 6);
    tmp1 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference{p_o, tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Uint8T>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/ordered-hash-table.tq?l=71&c=31
TorqueStructSlice_uint8_MutableReference_uint8_0 FieldSliceSmallOrderedHashMapPadding_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedHashMap> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<Object> tmp2;
  TNode<IntPtrT> tmp3;
  TNode<IntPtrT> tmp4;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 71);
    tmp0 = Convert_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp1 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x7ull));
    std::tie(tmp2, tmp3, tmp4) = NewMutableSlice_uint8_0(state_, TNode<Object>{p_o}, TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp0}).Flatten();
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TorqueStructSlice_uint8_MutableReference_uint8_0{TNode<Object>{tmp2}, TNode<IntPtrT>{tmp3}, TNode<IntPtrT>{tmp4}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/ordered-hash-table.tq?l=71&c=31
TNode<Uint8T> LoadSmallOrderedHashMapPadding_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedHashMap> p_o, TNode<IntPtrT> p_i) {
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
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 71);
    std::tie(tmp0, tmp1, tmp2) = FieldSliceSmallOrderedHashMapPadding_0(state_, TNode<SmallOrderedHashMap>{p_o}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 89);
    tmp3 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{p_i});
    tmp4 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp2});
    tmp5 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp3}, TNode<UintPtrT>{tmp4});
    ca_.Branch(tmp5, &block6, std::vector<compiler::Node*>{}, &block7, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<Object> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<Uint8T> tmp10;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 97);
    tmp6 = TimesSizeOf_uint8_0(state_, TNode<IntPtrT>{p_i});
    tmp7 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp6});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 96);
    std::tie(tmp8, tmp9) = NewReference_uint8_0(state_, TNode<Object>{tmp0}, TNode<IntPtrT>{tmp7}).Flatten();
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 71);
    tmp10 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference{tmp8, tmp9});
    ca_.Goto(&block10);
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 101);
    CodeStubAssembler(state_).PrintErr("halting because of unreachable code at src/builtins/torque-internal.tq:101:45");
    CodeStubAssembler(state_).Unreachable();
  }

    ca_.Bind(&block10);
  return TNode<Uint8T>{tmp10};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/ordered-hash-table.tq?l=71&c=31
void StoreSmallOrderedHashMapPadding_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedHashMap> p_o, TNode<IntPtrT> p_i, TNode<Uint8T> p_v) {
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
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 71);
    std::tie(tmp0, tmp1, tmp2) = FieldSliceSmallOrderedHashMapPadding_0(state_, TNode<SmallOrderedHashMap>{p_o}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 89);
    tmp3 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{p_i});
    tmp4 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp2});
    tmp5 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp3}, TNode<UintPtrT>{tmp4});
    ca_.Branch(tmp5, &block6, std::vector<compiler::Node*>{}, &block7, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<Object> tmp8;
  TNode<IntPtrT> tmp9;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 97);
    tmp6 = TimesSizeOf_uint8_0(state_, TNode<IntPtrT>{p_i});
    tmp7 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp6});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 96);
    std::tie(tmp8, tmp9) = NewReference_uint8_0(state_, TNode<Object>{tmp0}, TNode<IntPtrT>{tmp7}).Flatten();
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 71);
    CodeStubAssembler(state_).StoreReference<Uint8T>(CodeStubAssembler::Reference{tmp8, tmp9}, p_v);
    ca_.Goto(&block10);
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 101);
    CodeStubAssembler(state_).PrintErr("halting because of unreachable code at src/builtins/torque-internal.tq:101:45");
    CodeStubAssembler(state_).Unreachable();
  }

    ca_.Bind(&block10);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/ordered-hash-table.tq?l=72&c=3
TorqueStructSlice_HashMapEntry_MutableReference_HashMapEntry_0 FieldSliceSmallOrderedHashMapDataTable_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedHashMap> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Uint8T> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<IntPtrT> tmp3;
  TNode<IntPtrT> tmp4;
  TNode<IntPtrT> tmp5;
  TNode<IntPtrT> tmp6;
  TNode<Object> tmp7;
  TNode<IntPtrT> tmp8;
  TNode<IntPtrT> tmp9;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 72);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 6);
    tmp1 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference{p_o, tmp0});
    tmp2 = Convert_intptr_uint8_0(state_, TNode<Uint8T>{tmp1});
    tmp3 = FromConstexpr_intptr_constexpr_int31_0(state_, SmallOrderedHashTable<int>::kLoadFactor);
    tmp4 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp2}, TNode<IntPtrT>{tmp3});
    tmp5 = Convert_intptr_intptr_0(state_, TNode<IntPtrT>{tmp4});
    tmp6 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x8ull));
    std::tie(tmp7, tmp8, tmp9) = NewMutableSlice_HashMapEntry_0(state_, TNode<Object>{p_o}, TNode<IntPtrT>{tmp6}, TNode<IntPtrT>{tmp5}).Flatten();
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TorqueStructSlice_HashMapEntry_MutableReference_HashMapEntry_0{TNode<Object>{tmp7}, TNode<IntPtrT>{tmp8}, TNode<IntPtrT>{tmp9}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/ordered-hash-table.tq?l=74&c=3
TorqueStructSlice_uint8_MutableReference_uint8_0 FieldSliceSmallOrderedHashMapHashTable_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedHashMap> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Object> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<IntPtrT> tmp3;
  TNode<IntPtrT> tmp4;
  TNode<IntPtrT> tmp5;
  TNode<IntPtrT> tmp6;
  TNode<Uint8T> tmp7;
  TNode<IntPtrT> tmp8;
  TNode<Object> tmp9;
  TNode<IntPtrT> tmp10;
  TNode<IntPtrT> tmp11;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 74);
    std::tie(tmp0, tmp1, tmp2) = FieldSliceSmallOrderedHashMapDataTable_0(state_, TNode<SmallOrderedHashMap>{p_o}).Flatten();
    tmp3 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x8ull));
    tmp4 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp3}, TNode<IntPtrT>{tmp2});
    tmp5 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp4});
    tmp6 = FromConstexpr_intptr_constexpr_int31_0(state_, 6);
    tmp7 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference{p_o, tmp6});
    tmp8 = Convert_intptr_uint8_0(state_, TNode<Uint8T>{tmp7});
    std::tie(tmp9, tmp10, tmp11) = NewMutableSlice_uint8_0(state_, TNode<Object>{p_o}, TNode<IntPtrT>{tmp5}, TNode<IntPtrT>{tmp8}).Flatten();
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TorqueStructSlice_uint8_MutableReference_uint8_0{TNode<Object>{tmp9}, TNode<IntPtrT>{tmp10}, TNode<IntPtrT>{tmp11}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/ordered-hash-table.tq?l=74&c=3
TNode<Uint8T> LoadSmallOrderedHashMapHashTable_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedHashMap> p_o, TNode<IntPtrT> p_i) {
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
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 74);
    std::tie(tmp0, tmp1, tmp2) = FieldSliceSmallOrderedHashMapHashTable_0(state_, TNode<SmallOrderedHashMap>{p_o}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 89);
    tmp3 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{p_i});
    tmp4 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp2});
    tmp5 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp3}, TNode<UintPtrT>{tmp4});
    ca_.Branch(tmp5, &block6, std::vector<compiler::Node*>{}, &block7, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<Object> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<Uint8T> tmp10;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 97);
    tmp6 = TimesSizeOf_uint8_0(state_, TNode<IntPtrT>{p_i});
    tmp7 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp6});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 96);
    std::tie(tmp8, tmp9) = NewReference_uint8_0(state_, TNode<Object>{tmp0}, TNode<IntPtrT>{tmp7}).Flatten();
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 74);
    tmp10 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference{tmp8, tmp9});
    ca_.Goto(&block10);
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 101);
    CodeStubAssembler(state_).PrintErr("halting because of unreachable code at src/builtins/torque-internal.tq:101:45");
    CodeStubAssembler(state_).Unreachable();
  }

    ca_.Bind(&block10);
  return TNode<Uint8T>{tmp10};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/ordered-hash-table.tq?l=74&c=3
void StoreSmallOrderedHashMapHashTable_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedHashMap> p_o, TNode<IntPtrT> p_i, TNode<Uint8T> p_v) {
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
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 74);
    std::tie(tmp0, tmp1, tmp2) = FieldSliceSmallOrderedHashMapHashTable_0(state_, TNode<SmallOrderedHashMap>{p_o}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 89);
    tmp3 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{p_i});
    tmp4 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp2});
    tmp5 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp3}, TNode<UintPtrT>{tmp4});
    ca_.Branch(tmp5, &block6, std::vector<compiler::Node*>{}, &block7, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<Object> tmp8;
  TNode<IntPtrT> tmp9;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 97);
    tmp6 = TimesSizeOf_uint8_0(state_, TNode<IntPtrT>{p_i});
    tmp7 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp6});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 96);
    std::tie(tmp8, tmp9) = NewReference_uint8_0(state_, TNode<Object>{tmp0}, TNode<IntPtrT>{tmp7}).Flatten();
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 74);
    CodeStubAssembler(state_).StoreReference<Uint8T>(CodeStubAssembler::Reference{tmp8, tmp9}, p_v);
    ca_.Goto(&block10);
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 101);
    CodeStubAssembler(state_).PrintErr("halting because of unreachable code at src/builtins/torque-internal.tq:101:45");
    CodeStubAssembler(state_).Unreachable();
  }

    ca_.Bind(&block10);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/ordered-hash-table.tq?l=75&c=3
TorqueStructSlice_uint8_MutableReference_uint8_0 FieldSliceSmallOrderedHashMapChainTable_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedHashMap> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Object> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<IntPtrT> tmp3;
  TNode<IntPtrT> tmp4;
  TNode<IntPtrT> tmp5;
  TNode<IntPtrT> tmp6;
  TNode<Uint8T> tmp7;
  TNode<IntPtrT> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<IntPtrT> tmp10;
  TNode<IntPtrT> tmp11;
  TNode<Object> tmp12;
  TNode<IntPtrT> tmp13;
  TNode<IntPtrT> tmp14;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 75);
    std::tie(tmp0, tmp1, tmp2) = FieldSliceSmallOrderedHashMapHashTable_0(state_, TNode<SmallOrderedHashMap>{p_o}).Flatten();
    tmp3 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp4 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp3}, TNode<IntPtrT>{tmp2});
    tmp5 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp4});
    tmp6 = FromConstexpr_intptr_constexpr_int31_0(state_, 6);
    tmp7 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference{p_o, tmp6});
    tmp8 = Convert_intptr_uint8_0(state_, TNode<Uint8T>{tmp7});
    tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, SmallOrderedHashTable<int>::kLoadFactor);
    tmp10 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp8}, TNode<IntPtrT>{tmp9});
    tmp11 = Convert_intptr_intptr_0(state_, TNode<IntPtrT>{tmp10});
    std::tie(tmp12, tmp13, tmp14) = NewMutableSlice_uint8_0(state_, TNode<Object>{p_o}, TNode<IntPtrT>{tmp5}, TNode<IntPtrT>{tmp11}).Flatten();
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TorqueStructSlice_uint8_MutableReference_uint8_0{TNode<Object>{tmp12}, TNode<IntPtrT>{tmp13}, TNode<IntPtrT>{tmp14}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/ordered-hash-table.tq?l=75&c=3
TNode<Uint8T> LoadSmallOrderedHashMapChainTable_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedHashMap> p_o, TNode<IntPtrT> p_i) {
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
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 75);
    std::tie(tmp0, tmp1, tmp2) = FieldSliceSmallOrderedHashMapChainTable_0(state_, TNode<SmallOrderedHashMap>{p_o}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 89);
    tmp3 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{p_i});
    tmp4 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp2});
    tmp5 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp3}, TNode<UintPtrT>{tmp4});
    ca_.Branch(tmp5, &block6, std::vector<compiler::Node*>{}, &block7, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<Object> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<Uint8T> tmp10;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 97);
    tmp6 = TimesSizeOf_uint8_0(state_, TNode<IntPtrT>{p_i});
    tmp7 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp6});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 96);
    std::tie(tmp8, tmp9) = NewReference_uint8_0(state_, TNode<Object>{tmp0}, TNode<IntPtrT>{tmp7}).Flatten();
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 75);
    tmp10 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference{tmp8, tmp9});
    ca_.Goto(&block10);
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 101);
    CodeStubAssembler(state_).PrintErr("halting because of unreachable code at src/builtins/torque-internal.tq:101:45");
    CodeStubAssembler(state_).Unreachable();
  }

    ca_.Bind(&block10);
  return TNode<Uint8T>{tmp10};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/ordered-hash-table.tq?l=75&c=3
void StoreSmallOrderedHashMapChainTable_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedHashMap> p_o, TNode<IntPtrT> p_i, TNode<Uint8T> p_v) {
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
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 75);
    std::tie(tmp0, tmp1, tmp2) = FieldSliceSmallOrderedHashMapChainTable_0(state_, TNode<SmallOrderedHashMap>{p_o}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 89);
    tmp3 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{p_i});
    tmp4 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp2});
    tmp5 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp3}, TNode<UintPtrT>{tmp4});
    ca_.Branch(tmp5, &block6, std::vector<compiler::Node*>{}, &block7, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<Object> tmp8;
  TNode<IntPtrT> tmp9;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 97);
    tmp6 = TimesSizeOf_uint8_0(state_, TNode<IntPtrT>{p_i});
    tmp7 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp6});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 96);
    std::tie(tmp8, tmp9) = NewReference_uint8_0(state_, TNode<Object>{tmp0}, TNode<IntPtrT>{tmp7}).Flatten();
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 75);
    CodeStubAssembler(state_).StoreReference<Uint8T>(CodeStubAssembler::Reference{tmp8, tmp9}, p_v);
    ca_.Goto(&block10);
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 101);
    CodeStubAssembler(state_).PrintErr("halting because of unreachable code at src/builtins/torque-internal.tq:101:45");
    CodeStubAssembler(state_).Unreachable();
  }

    ca_.Bind(&block10);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/ordered-hash-table.tq?l=104&c=3
TNode<Int32T> LoadSmallOrderedNameDictionaryHash_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedNameDictionary> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Int32T> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 104);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp1 = CodeStubAssembler(state_).LoadReference<Int32T>(CodeStubAssembler::Reference{p_o, tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Int32T>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/ordered-hash-table.tq?l=104&c=3
void StoreSmallOrderedNameDictionaryHash_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedNameDictionary> p_o, TNode<Int32T> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 104);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    CodeStubAssembler(state_).StoreReference<Int32T>(CodeStubAssembler::Reference{p_o, tmp0}, p_v);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/ordered-hash-table.tq?l=107&c=3
TNode<Uint8T> LoadSmallOrderedNameDictionaryNumberOfElements_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedNameDictionary> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Uint8T> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 107);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp1 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference{p_o, tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Uint8T>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/ordered-hash-table.tq?l=107&c=3
void StoreSmallOrderedNameDictionaryNumberOfElements_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedNameDictionary> p_o, TNode<Uint8T> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 107);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    CodeStubAssembler(state_).StoreReference<Uint8T>(CodeStubAssembler::Reference{p_o, tmp0}, p_v);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/ordered-hash-table.tq?l=108&c=3
TNode<Uint8T> LoadSmallOrderedNameDictionaryNumberOfDeletedElements_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedNameDictionary> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Uint8T> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 108);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 9);
    tmp1 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference{p_o, tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Uint8T>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/ordered-hash-table.tq?l=108&c=3
void StoreSmallOrderedNameDictionaryNumberOfDeletedElements_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedNameDictionary> p_o, TNode<Uint8T> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 108);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 9);
    CodeStubAssembler(state_).StoreReference<Uint8T>(CodeStubAssembler::Reference{p_o, tmp0}, p_v);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/ordered-hash-table.tq?l=109&c=9
TNode<Uint8T> LoadSmallOrderedNameDictionaryNumberOfBuckets_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedNameDictionary> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Uint8T> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 109);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 10);
    tmp1 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference{p_o, tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Uint8T>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/ordered-hash-table.tq?l=111&c=31
TorqueStructSlice_uint8_MutableReference_uint8_0 FieldSliceSmallOrderedNameDictionaryPadding1_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedNameDictionary> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<Object> tmp2;
  TNode<IntPtrT> tmp3;
  TNode<IntPtrT> tmp4;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 111);
    tmp0 = Convert_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp1 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0xbull));
    std::tie(tmp2, tmp3, tmp4) = NewMutableSlice_uint8_0(state_, TNode<Object>{p_o}, TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp0}).Flatten();
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TorqueStructSlice_uint8_MutableReference_uint8_0{TNode<Object>{tmp2}, TNode<IntPtrT>{tmp3}, TNode<IntPtrT>{tmp4}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/ordered-hash-table.tq?l=111&c=31
TNode<Uint8T> LoadSmallOrderedNameDictionaryPadding1_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedNameDictionary> p_o, TNode<IntPtrT> p_i) {
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
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 111);
    std::tie(tmp0, tmp1, tmp2) = FieldSliceSmallOrderedNameDictionaryPadding1_0(state_, TNode<SmallOrderedNameDictionary>{p_o}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 89);
    tmp3 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{p_i});
    tmp4 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp2});
    tmp5 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp3}, TNode<UintPtrT>{tmp4});
    ca_.Branch(tmp5, &block6, std::vector<compiler::Node*>{}, &block7, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<Object> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<Uint8T> tmp10;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 97);
    tmp6 = TimesSizeOf_uint8_0(state_, TNode<IntPtrT>{p_i});
    tmp7 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp6});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 96);
    std::tie(tmp8, tmp9) = NewReference_uint8_0(state_, TNode<Object>{tmp0}, TNode<IntPtrT>{tmp7}).Flatten();
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 111);
    tmp10 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference{tmp8, tmp9});
    ca_.Goto(&block10);
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 101);
    CodeStubAssembler(state_).PrintErr("halting because of unreachable code at src/builtins/torque-internal.tq:101:45");
    CodeStubAssembler(state_).Unreachable();
  }

    ca_.Bind(&block10);
  return TNode<Uint8T>{tmp10};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/ordered-hash-table.tq?l=111&c=31
void StoreSmallOrderedNameDictionaryPadding1_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedNameDictionary> p_o, TNode<IntPtrT> p_i, TNode<Uint8T> p_v) {
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
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 111);
    std::tie(tmp0, tmp1, tmp2) = FieldSliceSmallOrderedNameDictionaryPadding1_0(state_, TNode<SmallOrderedNameDictionary>{p_o}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 89);
    tmp3 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{p_i});
    tmp4 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp2});
    tmp5 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp3}, TNode<UintPtrT>{tmp4});
    ca_.Branch(tmp5, &block6, std::vector<compiler::Node*>{}, &block7, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<Object> tmp8;
  TNode<IntPtrT> tmp9;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 97);
    tmp6 = TimesSizeOf_uint8_0(state_, TNode<IntPtrT>{p_i});
    tmp7 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp6});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 96);
    std::tie(tmp8, tmp9) = NewReference_uint8_0(state_, TNode<Object>{tmp0}, TNode<IntPtrT>{tmp7}).Flatten();
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 111);
    CodeStubAssembler(state_).StoreReference<Uint8T>(CodeStubAssembler::Reference{tmp8, tmp9}, p_v);
    ca_.Goto(&block10);
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 101);
    CodeStubAssembler(state_).PrintErr("halting because of unreachable code at src/builtins/torque-internal.tq:101:45");
    CodeStubAssembler(state_).Unreachable();
  }

    ca_.Bind(&block10);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/ordered-hash-table.tq?l=112&c=3
TorqueStructSlice_NameDictionaryEntry_MutableReference_NameDictionaryEntry_0 FieldSliceSmallOrderedNameDictionaryDataTable_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedNameDictionary> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Uint8T> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<IntPtrT> tmp3;
  TNode<IntPtrT> tmp4;
  TNode<IntPtrT> tmp5;
  TNode<IntPtrT> tmp6;
  TNode<Object> tmp7;
  TNode<IntPtrT> tmp8;
  TNode<IntPtrT> tmp9;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 112);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 10);
    tmp1 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference{p_o, tmp0});
    tmp2 = Convert_intptr_uint8_0(state_, TNode<Uint8T>{tmp1});
    tmp3 = FromConstexpr_intptr_constexpr_int31_0(state_, SmallOrderedHashTable<int>::kLoadFactor);
    tmp4 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp2}, TNode<IntPtrT>{tmp3});
    tmp5 = Convert_intptr_intptr_0(state_, TNode<IntPtrT>{tmp4});
    tmp6 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0xcull));
    std::tie(tmp7, tmp8, tmp9) = NewMutableSlice_NameDictionaryEntry_0(state_, TNode<Object>{p_o}, TNode<IntPtrT>{tmp6}, TNode<IntPtrT>{tmp5}).Flatten();
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TorqueStructSlice_NameDictionaryEntry_MutableReference_NameDictionaryEntry_0{TNode<Object>{tmp7}, TNode<IntPtrT>{tmp8}, TNode<IntPtrT>{tmp9}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/ordered-hash-table.tq?l=114&c=3
TorqueStructSlice_uint8_MutableReference_uint8_0 FieldSliceSmallOrderedNameDictionaryHashTable_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedNameDictionary> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Object> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<IntPtrT> tmp3;
  TNode<IntPtrT> tmp4;
  TNode<IntPtrT> tmp5;
  TNode<IntPtrT> tmp6;
  TNode<Uint8T> tmp7;
  TNode<IntPtrT> tmp8;
  TNode<Object> tmp9;
  TNode<IntPtrT> tmp10;
  TNode<IntPtrT> tmp11;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 114);
    std::tie(tmp0, tmp1, tmp2) = FieldSliceSmallOrderedNameDictionaryDataTable_0(state_, TNode<SmallOrderedNameDictionary>{p_o}).Flatten();
    tmp3 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0xcull));
    tmp4 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp3}, TNode<IntPtrT>{tmp2});
    tmp5 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp4});
    tmp6 = FromConstexpr_intptr_constexpr_int31_0(state_, 10);
    tmp7 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference{p_o, tmp6});
    tmp8 = Convert_intptr_uint8_0(state_, TNode<Uint8T>{tmp7});
    std::tie(tmp9, tmp10, tmp11) = NewMutableSlice_uint8_0(state_, TNode<Object>{p_o}, TNode<IntPtrT>{tmp5}, TNode<IntPtrT>{tmp8}).Flatten();
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TorqueStructSlice_uint8_MutableReference_uint8_0{TNode<Object>{tmp9}, TNode<IntPtrT>{tmp10}, TNode<IntPtrT>{tmp11}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/ordered-hash-table.tq?l=114&c=3
TNode<Uint8T> LoadSmallOrderedNameDictionaryHashTable_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedNameDictionary> p_o, TNode<IntPtrT> p_i) {
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
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 114);
    std::tie(tmp0, tmp1, tmp2) = FieldSliceSmallOrderedNameDictionaryHashTable_0(state_, TNode<SmallOrderedNameDictionary>{p_o}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 89);
    tmp3 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{p_i});
    tmp4 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp2});
    tmp5 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp3}, TNode<UintPtrT>{tmp4});
    ca_.Branch(tmp5, &block6, std::vector<compiler::Node*>{}, &block7, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<Object> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<Uint8T> tmp10;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 97);
    tmp6 = TimesSizeOf_uint8_0(state_, TNode<IntPtrT>{p_i});
    tmp7 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp6});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 96);
    std::tie(tmp8, tmp9) = NewReference_uint8_0(state_, TNode<Object>{tmp0}, TNode<IntPtrT>{tmp7}).Flatten();
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 114);
    tmp10 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference{tmp8, tmp9});
    ca_.Goto(&block10);
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 101);
    CodeStubAssembler(state_).PrintErr("halting because of unreachable code at src/builtins/torque-internal.tq:101:45");
    CodeStubAssembler(state_).Unreachable();
  }

    ca_.Bind(&block10);
  return TNode<Uint8T>{tmp10};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/ordered-hash-table.tq?l=114&c=3
void StoreSmallOrderedNameDictionaryHashTable_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedNameDictionary> p_o, TNode<IntPtrT> p_i, TNode<Uint8T> p_v) {
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
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 114);
    std::tie(tmp0, tmp1, tmp2) = FieldSliceSmallOrderedNameDictionaryHashTable_0(state_, TNode<SmallOrderedNameDictionary>{p_o}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 89);
    tmp3 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{p_i});
    tmp4 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp2});
    tmp5 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp3}, TNode<UintPtrT>{tmp4});
    ca_.Branch(tmp5, &block6, std::vector<compiler::Node*>{}, &block7, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<Object> tmp8;
  TNode<IntPtrT> tmp9;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 97);
    tmp6 = TimesSizeOf_uint8_0(state_, TNode<IntPtrT>{p_i});
    tmp7 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp6});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 96);
    std::tie(tmp8, tmp9) = NewReference_uint8_0(state_, TNode<Object>{tmp0}, TNode<IntPtrT>{tmp7}).Flatten();
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 114);
    CodeStubAssembler(state_).StoreReference<Uint8T>(CodeStubAssembler::Reference{tmp8, tmp9}, p_v);
    ca_.Goto(&block10);
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 101);
    CodeStubAssembler(state_).PrintErr("halting because of unreachable code at src/builtins/torque-internal.tq:101:45");
    CodeStubAssembler(state_).Unreachable();
  }

    ca_.Bind(&block10);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/ordered-hash-table.tq?l=115&c=3
TorqueStructSlice_uint8_MutableReference_uint8_0 FieldSliceSmallOrderedNameDictionaryChainTable_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedNameDictionary> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Object> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<IntPtrT> tmp3;
  TNode<IntPtrT> tmp4;
  TNode<IntPtrT> tmp5;
  TNode<IntPtrT> tmp6;
  TNode<Uint8T> tmp7;
  TNode<IntPtrT> tmp8;
  TNode<Object> tmp9;
  TNode<IntPtrT> tmp10;
  TNode<IntPtrT> tmp11;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 115);
    std::tie(tmp0, tmp1, tmp2) = FieldSliceSmallOrderedNameDictionaryHashTable_0(state_, TNode<SmallOrderedNameDictionary>{p_o}).Flatten();
    tmp3 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp4 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp3}, TNode<IntPtrT>{tmp2});
    tmp5 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp4});
    tmp6 = FromConstexpr_intptr_constexpr_int31_0(state_, 10);
    tmp7 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference{p_o, tmp6});
    tmp8 = Convert_intptr_uint8_0(state_, TNode<Uint8T>{tmp7});
    std::tie(tmp9, tmp10, tmp11) = NewMutableSlice_uint8_0(state_, TNode<Object>{p_o}, TNode<IntPtrT>{tmp5}, TNode<IntPtrT>{tmp8}).Flatten();
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TorqueStructSlice_uint8_MutableReference_uint8_0{TNode<Object>{tmp9}, TNode<IntPtrT>{tmp10}, TNode<IntPtrT>{tmp11}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/ordered-hash-table.tq?l=115&c=3
TNode<Uint8T> LoadSmallOrderedNameDictionaryChainTable_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedNameDictionary> p_o, TNode<IntPtrT> p_i) {
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
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 115);
    std::tie(tmp0, tmp1, tmp2) = FieldSliceSmallOrderedNameDictionaryChainTable_0(state_, TNode<SmallOrderedNameDictionary>{p_o}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 89);
    tmp3 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{p_i});
    tmp4 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp2});
    tmp5 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp3}, TNode<UintPtrT>{tmp4});
    ca_.Branch(tmp5, &block6, std::vector<compiler::Node*>{}, &block7, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<Object> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<Uint8T> tmp10;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 97);
    tmp6 = TimesSizeOf_uint8_0(state_, TNode<IntPtrT>{p_i});
    tmp7 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp6});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 96);
    std::tie(tmp8, tmp9) = NewReference_uint8_0(state_, TNode<Object>{tmp0}, TNode<IntPtrT>{tmp7}).Flatten();
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 115);
    tmp10 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference{tmp8, tmp9});
    ca_.Goto(&block10);
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 101);
    CodeStubAssembler(state_).PrintErr("halting because of unreachable code at src/builtins/torque-internal.tq:101:45");
    CodeStubAssembler(state_).Unreachable();
  }

    ca_.Bind(&block10);
  return TNode<Uint8T>{tmp10};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/ordered-hash-table.tq?l=115&c=3
void StoreSmallOrderedNameDictionaryChainTable_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedNameDictionary> p_o, TNode<IntPtrT> p_i, TNode<Uint8T> p_v) {
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
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 115);
    std::tie(tmp0, tmp1, tmp2) = FieldSliceSmallOrderedNameDictionaryChainTable_0(state_, TNode<SmallOrderedNameDictionary>{p_o}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 89);
    tmp3 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{p_i});
    tmp4 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp2});
    tmp5 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp3}, TNode<UintPtrT>{tmp4});
    ca_.Branch(tmp5, &block6, std::vector<compiler::Node*>{}, &block7, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<Object> tmp8;
  TNode<IntPtrT> tmp9;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 97);
    tmp6 = TimesSizeOf_uint8_0(state_, TNode<IntPtrT>{p_i});
    tmp7 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp6});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 96);
    std::tie(tmp8, tmp9) = NewReference_uint8_0(state_, TNode<Object>{tmp0}, TNode<IntPtrT>{tmp7}).Flatten();
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 115);
    CodeStubAssembler(state_).StoreReference<Uint8T>(CodeStubAssembler::Reference{tmp8, tmp9}, p_v);
    ca_.Goto(&block10);
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 101);
    CodeStubAssembler(state_).PrintErr("halting because of unreachable code at src/builtins/torque-internal.tq:101:45");
    CodeStubAssembler(state_).Unreachable();
  }

    ca_.Bind(&block10);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/ordered-hash-table.tq?l=17&c=1
TNode<HeapObject> DownCastForTorqueClass_SmallOrderedHashTable_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Map> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 327);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp1 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference{p_o, tmp0});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 330);
    if (((CodeStubAssembler(state_).ConstexprInt31Equal(static_cast<InstanceType>(231), static_cast<InstanceType>(233))))) {
      ca_.Goto(&block3);
    } else {
      ca_.Goto(&block4);
    }
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 331);
    if ((false)) {
      ca_.Goto(&block6);
    } else {
      ca_.Goto(&block7);
    }
  }

  TNode<Map> tmp2;
  TNode<BoolT> tmp3;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 332);
    tmp2 = CodeStubAssembler(state_).GetClassMapConstant<void>();
    tmp3 = CodeStubAssembler(state_).TaggedNotEqual(TNode<HeapObject>{tmp1}, TNode<HeapObject>{tmp2});
    ca_.Branch(tmp3, &block9, std::vector<compiler::Node*>{}, &block10, std::vector<compiler::Node*>{});
  }

  if (block9.is_used()) {
    ca_.Bind(&block9);
    ca_.Goto(&block1);
  }

  if (block10.is_used()) {
    ca_.Bind(&block10);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 331);
    ca_.Goto(&block8);
  }

  TNode<IntPtrT> tmp4;
  TNode<Uint16T> tmp5;
  TNode<Uint32T> tmp6;
  TNode<BoolT> tmp7;
  if (block7.is_used()) {
    ca_.Bind(&block7);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 334);
    tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp5 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference{tmp1, tmp4});
    tmp6 = FromConstexpr_uint32_constexpr_uint32_0(state_, static_cast<InstanceType>(231));
    tmp7 = CodeStubAssembler(state_).Word32NotEqual(TNode<Uint32T>{tmp5}, TNode<Uint32T>{tmp6});
    ca_.Branch(tmp7, &block11, std::vector<compiler::Node*>{}, &block12, std::vector<compiler::Node*>{});
  }

  if (block11.is_used()) {
    ca_.Bind(&block11);
    ca_.Goto(&block1);
  }

  if (block12.is_used()) {
    ca_.Bind(&block12);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 331);
    ca_.Goto(&block8);
  }

  if (block8.is_used()) {
    ca_.Bind(&block8);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 330);
    ca_.Goto(&block5);
  }

  TNode<Int32T> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<Uint16T> tmp10;
  TNode<Uint16T> tmp11;
  TNode<Int32T> tmp12;
  TNode<Uint16T> tmp13;
  TNode<Uint16T> tmp14;
  TNode<Int32T> tmp15;
  TNode<Int32T> tmp16;
  TNode<Uint32T> tmp17;
  TNode<Uint32T> tmp18;
  TNode<BoolT> tmp19;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 337);
    tmp8 = FromConstexpr_int32_constexpr_int32_0(state_, (CodeStubAssembler(state_).ConstexprUint32Sub(static_cast<InstanceType>(233), static_cast<InstanceType>(231))));
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 338);
    tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp10 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference{tmp1, tmp9});
    tmp11 = Convert_uint16_InstanceType_0(state_, TNode<Uint16T>{tmp10});
    tmp12 = Convert_int32_uint16_0(state_, TNode<Uint16T>{tmp11});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 340);
    tmp13 = FromConstexpr_InstanceType_constexpr_InstanceType_0(state_, static_cast<InstanceType>(231));
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 339);
    tmp14 = Convert_uint16_InstanceType_0(state_, TNode<Uint16T>{tmp13});
    tmp15 = Convert_int32_uint16_0(state_, TNode<Uint16T>{tmp14});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 338);
    tmp16 = CodeStubAssembler(state_).Int32Sub(TNode<Int32T>{tmp12}, TNode<Int32T>{tmp15});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 341);
    tmp17 = CodeStubAssembler(state_).Unsigned(TNode<Int32T>{tmp16});
    tmp18 = CodeStubAssembler(state_).Unsigned(TNode<Int32T>{tmp8});
    tmp19 = CodeStubAssembler(state_).Uint32GreaterThan(TNode<Uint32T>{tmp17}, TNode<Uint32T>{tmp18});
    ca_.Branch(tmp19, &block13, std::vector<compiler::Node*>{}, &block14, std::vector<compiler::Node*>{});
  }

  if (block13.is_used()) {
    ca_.Bind(&block13);
    ca_.Goto(&block1);
  }

  if (block14.is_used()) {
    ca_.Bind(&block14);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 330);
    ca_.Goto(&block5);
  }

  TNode<HeapObject> tmp20;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 343);
    tmp20 = (TNode<HeapObject>{p_o});
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 17);
    ca_.Goto(&block15);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_CastError);
  }

    ca_.Bind(&block15);
  return TNode<HeapObject>{tmp20};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/ordered-hash-table.tq?l=26&c=1
TNode<SmallOrderedHashSet> DownCastForTorqueClass_SmallOrderedHashSet_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Map> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 327);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp1 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference{p_o, tmp0});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 330);
    if (((CodeStubAssembler(state_).ConstexprInt31Equal(static_cast<InstanceType>(232), static_cast<InstanceType>(232))))) {
      ca_.Goto(&block3);
    } else {
      ca_.Goto(&block4);
    }
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 331);
    if ((CodeStubAssembler(state_).ClassHasMapConstant<SmallOrderedHashSet>())) {
      ca_.Goto(&block6);
    } else {
      ca_.Goto(&block7);
    }
  }

  TNode<Map> tmp2;
  TNode<BoolT> tmp3;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 332);
    tmp2 = CodeStubAssembler(state_).GetClassMapConstant<SmallOrderedHashSet>();
    tmp3 = CodeStubAssembler(state_).TaggedNotEqual(TNode<HeapObject>{tmp1}, TNode<HeapObject>{tmp2});
    ca_.Branch(tmp3, &block9, std::vector<compiler::Node*>{}, &block10, std::vector<compiler::Node*>{});
  }

  if (block9.is_used()) {
    ca_.Bind(&block9);
    ca_.Goto(&block1);
  }

  if (block10.is_used()) {
    ca_.Bind(&block10);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 331);
    ca_.Goto(&block8);
  }

  TNode<IntPtrT> tmp4;
  TNode<Uint16T> tmp5;
  TNode<Uint32T> tmp6;
  TNode<BoolT> tmp7;
  if (block7.is_used()) {
    ca_.Bind(&block7);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 334);
    tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp5 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference{tmp1, tmp4});
    tmp6 = FromConstexpr_uint32_constexpr_uint32_0(state_, static_cast<InstanceType>(232));
    tmp7 = CodeStubAssembler(state_).Word32NotEqual(TNode<Uint32T>{tmp5}, TNode<Uint32T>{tmp6});
    ca_.Branch(tmp7, &block11, std::vector<compiler::Node*>{}, &block12, std::vector<compiler::Node*>{});
  }

  if (block11.is_used()) {
    ca_.Bind(&block11);
    ca_.Goto(&block1);
  }

  if (block12.is_used()) {
    ca_.Bind(&block12);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 331);
    ca_.Goto(&block8);
  }

  if (block8.is_used()) {
    ca_.Bind(&block8);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 330);
    ca_.Goto(&block5);
  }

  TNode<Int32T> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<Uint16T> tmp10;
  TNode<Uint16T> tmp11;
  TNode<Int32T> tmp12;
  TNode<Uint16T> tmp13;
  TNode<Uint16T> tmp14;
  TNode<Int32T> tmp15;
  TNode<Int32T> tmp16;
  TNode<Uint32T> tmp17;
  TNode<Uint32T> tmp18;
  TNode<BoolT> tmp19;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 337);
    tmp8 = FromConstexpr_int32_constexpr_int32_0(state_, (CodeStubAssembler(state_).ConstexprUint32Sub(static_cast<InstanceType>(232), static_cast<InstanceType>(232))));
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 338);
    tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp10 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference{tmp1, tmp9});
    tmp11 = Convert_uint16_InstanceType_0(state_, TNode<Uint16T>{tmp10});
    tmp12 = Convert_int32_uint16_0(state_, TNode<Uint16T>{tmp11});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 340);
    tmp13 = FromConstexpr_InstanceType_constexpr_InstanceType_0(state_, static_cast<InstanceType>(232));
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 339);
    tmp14 = Convert_uint16_InstanceType_0(state_, TNode<Uint16T>{tmp13});
    tmp15 = Convert_int32_uint16_0(state_, TNode<Uint16T>{tmp14});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 338);
    tmp16 = CodeStubAssembler(state_).Int32Sub(TNode<Int32T>{tmp12}, TNode<Int32T>{tmp15});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 341);
    tmp17 = CodeStubAssembler(state_).Unsigned(TNode<Int32T>{tmp16});
    tmp18 = CodeStubAssembler(state_).Unsigned(TNode<Int32T>{tmp8});
    tmp19 = CodeStubAssembler(state_).Uint32GreaterThan(TNode<Uint32T>{tmp17}, TNode<Uint32T>{tmp18});
    ca_.Branch(tmp19, &block13, std::vector<compiler::Node*>{}, &block14, std::vector<compiler::Node*>{});
  }

  if (block13.is_used()) {
    ca_.Bind(&block13);
    ca_.Goto(&block1);
  }

  if (block14.is_used()) {
    ca_.Bind(&block14);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 330);
    ca_.Goto(&block5);
  }

  TNode<SmallOrderedHashSet> tmp20;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 343);
    tmp20 = TORQUE_CAST(TNode<HeapObject>{p_o});
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 26);
    ca_.Goto(&block15);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_CastError);
  }

    ca_.Bind(&block15);
  return TNode<SmallOrderedHashSet>{tmp20};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/ordered-hash-table.tq?l=50&c=17
TorqueStructConstantIterator_uint8_0 ConstantIterator_uint8_0(compiler::CodeAssemblerState* state_, TNode<Uint8T> p_value) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 50);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TorqueStructConstantIterator_uint8_0{TNode<Uint8T>{p_value}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/ordered-hash-table.tq?l=45&c=10
void InitializeFieldsFromIterator_uint8_ConstantIterator_uint8_0(compiler::CodeAssemblerState* state_, TorqueStructSlice_uint8_MutableReference_uint8_0 p_target, TorqueStructConstantIterator_uint8_0 p_originIterator) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 128);
    tmp0 = TimesSizeOf_uint8_0(state_, TNode<IntPtrT>{p_target.length});
    tmp1 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{p_target.offset}, TNode<IntPtrT>{tmp0});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 293);
    ca_.Goto(&block5, p_target.offset);
  }

  TNode<IntPtrT> phi_bb5_5;
  TNode<BoolT> tmp2;
  if (block5.is_used()) {
    ca_.Bind(&block5, &phi_bb5_5);
    tmp2 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Branch(tmp2, &block3, std::vector<compiler::Node*>{phi_bb5_5}, &block4, std::vector<compiler::Node*>{phi_bb5_5});
  }

  TNode<IntPtrT> phi_bb3_5;
  TNode<BoolT> tmp3;
  if (block3.is_used()) {
    ca_.Bind(&block3, &phi_bb3_5);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 201);
    tmp3 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{phi_bb3_5}, TNode<IntPtrT>{tmp1});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 213);
    ca_.Branch(tmp3, &block9, std::vector<compiler::Node*>{phi_bb3_5}, &block10, std::vector<compiler::Node*>{phi_bb3_5});
  }

  TNode<IntPtrT> phi_bb9_5;
  if (block9.is_used()) {
    ca_.Bind(&block9, &phi_bb9_5);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 294);
    ca_.Goto(&block4, phi_bb9_5);
  }

  TNode<IntPtrT> phi_bb10_5;
  TNode<Object> tmp4;
  TNode<IntPtrT> tmp5;
  TNode<IntPtrT> tmp6;
  TNode<IntPtrT> tmp7;
  if (block10.is_used()) {
    ca_.Bind(&block10, &phi_bb10_5);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 216);
    std::tie(tmp4, tmp5) = NewReference_uint8_0(state_, TNode<Object>{p_target.object}, TNode<IntPtrT>{phi_bb10_5}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 217);
    tmp6 = FromConstexpr_intptr_constexpr_int31_0(state_, kUInt8Size);
    tmp7 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb10_5}, TNode<IntPtrT>{tmp6});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 295);
    CodeStubAssembler(state_).StoreReference<Uint8T>(CodeStubAssembler::Reference{tmp4, tmp5}, p_originIterator.value);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 293);
    ca_.Goto(&block5, tmp7);
  }

  TNode<IntPtrT> phi_bb4_5;
  if (block4.is_used()) {
    ca_.Bind(&block4, &phi_bb4_5);
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 45);
    ca_.Goto(&block16);
  }

    ca_.Bind(&block16);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/ordered-hash-table.tq?l=45&c=10
void InitializeFieldsFromIterator_JSReceiver_OR_Smi_OR_HeapNumber_OR_BigInt_OR_String_OR_Symbol_OR_True_OR_False_OR_Null_OR_Undefined_OR_TheHole_ConstantIterator_TheHole_0(compiler::CodeAssemblerState* state_, TorqueStructSlice_JSReceiver_OR_Smi_OR_HeapNumber_OR_BigInt_OR_String_OR_Symbol_OR_True_OR_False_OR_Null_OR_Undefined_OR_TheHole_MutableReference_JSReceiver_OR_Smi_OR_HeapNumber_OR_BigInt_OR_String_OR_Symbol_OR_True_OR_False_OR_Null_OR_Undefined_OR_TheHole_0 p_target, TorqueStructConstantIterator_TheHole_0 p_originIterator) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 128);
    tmp0 = TimesSizeOf_JSReceiver_OR_Smi_OR_HeapNumber_OR_BigInt_OR_String_OR_Symbol_OR_True_OR_False_OR_Null_OR_Undefined_OR_TheHole_0(state_, TNode<IntPtrT>{p_target.length});
    tmp1 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{p_target.offset}, TNode<IntPtrT>{tmp0});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 293);
    ca_.Goto(&block5, p_target.offset);
  }

  TNode<IntPtrT> phi_bb5_5;
  TNode<BoolT> tmp2;
  if (block5.is_used()) {
    ca_.Bind(&block5, &phi_bb5_5);
    tmp2 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Branch(tmp2, &block3, std::vector<compiler::Node*>{phi_bb5_5}, &block4, std::vector<compiler::Node*>{phi_bb5_5});
  }

  TNode<IntPtrT> phi_bb3_5;
  TNode<BoolT> tmp3;
  if (block3.is_used()) {
    ca_.Bind(&block3, &phi_bb3_5);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 201);
    tmp3 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{phi_bb3_5}, TNode<IntPtrT>{tmp1});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 213);
    ca_.Branch(tmp3, &block9, std::vector<compiler::Node*>{phi_bb3_5}, &block10, std::vector<compiler::Node*>{phi_bb3_5});
  }

  TNode<IntPtrT> phi_bb9_5;
  if (block9.is_used()) {
    ca_.Bind(&block9, &phi_bb9_5);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 294);
    ca_.Goto(&block4, phi_bb9_5);
  }

  TNode<IntPtrT> phi_bb10_5;
  TNode<Object> tmp4;
  TNode<IntPtrT> tmp5;
  TNode<IntPtrT> tmp6;
  TNode<IntPtrT> tmp7;
  if (block10.is_used()) {
    ca_.Bind(&block10, &phi_bb10_5);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 216);
    std::tie(tmp4, tmp5) = NewReference_JSReceiver_OR_Smi_OR_HeapNumber_OR_BigInt_OR_String_OR_Symbol_OR_True_OR_False_OR_Null_OR_Undefined_OR_TheHole_0(state_, TNode<Object>{p_target.object}, TNode<IntPtrT>{phi_bb10_5}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 217);
    tmp6 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    tmp7 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb10_5}, TNode<IntPtrT>{tmp6});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 295);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp4, tmp5}, p_originIterator.value);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 293);
    ca_.Goto(&block5, tmp7);
  }

  TNode<IntPtrT> phi_bb4_5;
  if (block4.is_used()) {
    ca_.Bind(&block4, &phi_bb4_5);
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 45);
    ca_.Goto(&block16);
  }

    ca_.Bind(&block16);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/ordered-hash-table.tq?l=65&c=1
TNode<SmallOrderedHashMap> DownCastForTorqueClass_SmallOrderedHashMap_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Map> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 327);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp1 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference{p_o, tmp0});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 330);
    if (((CodeStubAssembler(state_).ConstexprInt31Equal(static_cast<InstanceType>(231), static_cast<InstanceType>(231))))) {
      ca_.Goto(&block3);
    } else {
      ca_.Goto(&block4);
    }
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 331);
    if ((CodeStubAssembler(state_).ClassHasMapConstant<SmallOrderedHashMap>())) {
      ca_.Goto(&block6);
    } else {
      ca_.Goto(&block7);
    }
  }

  TNode<Map> tmp2;
  TNode<BoolT> tmp3;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 332);
    tmp2 = CodeStubAssembler(state_).GetClassMapConstant<SmallOrderedHashMap>();
    tmp3 = CodeStubAssembler(state_).TaggedNotEqual(TNode<HeapObject>{tmp1}, TNode<HeapObject>{tmp2});
    ca_.Branch(tmp3, &block9, std::vector<compiler::Node*>{}, &block10, std::vector<compiler::Node*>{});
  }

  if (block9.is_used()) {
    ca_.Bind(&block9);
    ca_.Goto(&block1);
  }

  if (block10.is_used()) {
    ca_.Bind(&block10);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 331);
    ca_.Goto(&block8);
  }

  TNode<IntPtrT> tmp4;
  TNode<Uint16T> tmp5;
  TNode<Uint32T> tmp6;
  TNode<BoolT> tmp7;
  if (block7.is_used()) {
    ca_.Bind(&block7);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 334);
    tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp5 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference{tmp1, tmp4});
    tmp6 = FromConstexpr_uint32_constexpr_uint32_0(state_, static_cast<InstanceType>(231));
    tmp7 = CodeStubAssembler(state_).Word32NotEqual(TNode<Uint32T>{tmp5}, TNode<Uint32T>{tmp6});
    ca_.Branch(tmp7, &block11, std::vector<compiler::Node*>{}, &block12, std::vector<compiler::Node*>{});
  }

  if (block11.is_used()) {
    ca_.Bind(&block11);
    ca_.Goto(&block1);
  }

  if (block12.is_used()) {
    ca_.Bind(&block12);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 331);
    ca_.Goto(&block8);
  }

  if (block8.is_used()) {
    ca_.Bind(&block8);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 330);
    ca_.Goto(&block5);
  }

  TNode<Int32T> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<Uint16T> tmp10;
  TNode<Uint16T> tmp11;
  TNode<Int32T> tmp12;
  TNode<Uint16T> tmp13;
  TNode<Uint16T> tmp14;
  TNode<Int32T> tmp15;
  TNode<Int32T> tmp16;
  TNode<Uint32T> tmp17;
  TNode<Uint32T> tmp18;
  TNode<BoolT> tmp19;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 337);
    tmp8 = FromConstexpr_int32_constexpr_int32_0(state_, (CodeStubAssembler(state_).ConstexprUint32Sub(static_cast<InstanceType>(231), static_cast<InstanceType>(231))));
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 338);
    tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp10 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference{tmp1, tmp9});
    tmp11 = Convert_uint16_InstanceType_0(state_, TNode<Uint16T>{tmp10});
    tmp12 = Convert_int32_uint16_0(state_, TNode<Uint16T>{tmp11});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 340);
    tmp13 = FromConstexpr_InstanceType_constexpr_InstanceType_0(state_, static_cast<InstanceType>(231));
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 339);
    tmp14 = Convert_uint16_InstanceType_0(state_, TNode<Uint16T>{tmp13});
    tmp15 = Convert_int32_uint16_0(state_, TNode<Uint16T>{tmp14});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 338);
    tmp16 = CodeStubAssembler(state_).Int32Sub(TNode<Int32T>{tmp12}, TNode<Int32T>{tmp15});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 341);
    tmp17 = CodeStubAssembler(state_).Unsigned(TNode<Int32T>{tmp16});
    tmp18 = CodeStubAssembler(state_).Unsigned(TNode<Int32T>{tmp8});
    tmp19 = CodeStubAssembler(state_).Uint32GreaterThan(TNode<Uint32T>{tmp17}, TNode<Uint32T>{tmp18});
    ca_.Branch(tmp19, &block13, std::vector<compiler::Node*>{}, &block14, std::vector<compiler::Node*>{});
  }

  if (block13.is_used()) {
    ca_.Bind(&block13);
    ca_.Goto(&block1);
  }

  if (block14.is_used()) {
    ca_.Bind(&block14);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 330);
    ca_.Goto(&block5);
  }

  TNode<SmallOrderedHashMap> tmp20;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 343);
    tmp20 = TORQUE_CAST(TNode<HeapObject>{p_o});
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 65);
    ca_.Goto(&block15);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_CastError);
  }

    ca_.Bind(&block15);
  return TNode<SmallOrderedHashMap>{tmp20};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/ordered-hash-table.tq?l=90&c=20
TorqueStructConstantIterator_HashMapEntry_0 ConstantIterator_HashMapEntry_0(compiler::CodeAssemblerState* state_, TorqueStructHashMapEntry_0 p_value) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 90);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TorqueStructConstantIterator_HashMapEntry_0{TorqueStructHashMapEntry_0{TNode<Object>{p_value.key}, TNode<Object>{p_value.value}}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/ordered-hash-table.tq?l=84&c=10
void InitializeFieldsFromIterator_HashMapEntry_ConstantIterator_HashMapEntry_0(compiler::CodeAssemblerState* state_, TorqueStructSlice_HashMapEntry_MutableReference_HashMapEntry_0 p_target, TorqueStructConstantIterator_HashMapEntry_0 p_originIterator) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 128);
    tmp0 = TimesSizeOf_HashMapEntry_0(state_, TNode<IntPtrT>{p_target.length});
    tmp1 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{p_target.offset}, TNode<IntPtrT>{tmp0});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 293);
    ca_.Goto(&block5, p_target.offset);
  }

  TNode<IntPtrT> phi_bb5_6;
  TNode<BoolT> tmp2;
  if (block5.is_used()) {
    ca_.Bind(&block5, &phi_bb5_6);
    tmp2 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Branch(tmp2, &block3, std::vector<compiler::Node*>{phi_bb5_6}, &block4, std::vector<compiler::Node*>{phi_bb5_6});
  }

  TNode<IntPtrT> phi_bb3_6;
  TNode<BoolT> tmp3;
  if (block3.is_used()) {
    ca_.Bind(&block3, &phi_bb3_6);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 201);
    tmp3 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{phi_bb3_6}, TNode<IntPtrT>{tmp1});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 213);
    ca_.Branch(tmp3, &block9, std::vector<compiler::Node*>{phi_bb3_6}, &block10, std::vector<compiler::Node*>{phi_bb3_6});
  }

  TNode<IntPtrT> phi_bb9_6;
  if (block9.is_used()) {
    ca_.Bind(&block9, &phi_bb9_6);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 294);
    ca_.Goto(&block4, phi_bb9_6);
  }

  TNode<IntPtrT> phi_bb10_6;
  TNode<Object> tmp4;
  TNode<IntPtrT> tmp5;
  TNode<IntPtrT> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<IntPtrT> tmp8;
  TNode<IntPtrT> tmp9;
  if (block10.is_used()) {
    ca_.Bind(&block10, &phi_bb10_6);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 216);
    std::tie(tmp4, tmp5) = NewReference_HashMapEntry_0(state_, TNode<Object>{p_target.object}, TNode<IntPtrT>{phi_bb10_6}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 217);
    tmp6 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp7 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb10_6}, TNode<IntPtrT>{tmp6});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 295);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp4, tmp5}, p_originIterator.value.key);
    tmp8 = FromConstexpr_intptr_constexpr_intptr_0(state_, 4);
    tmp9 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp5}, TNode<IntPtrT>{tmp8});
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp4, tmp9}, p_originIterator.value.value);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 293);
    ca_.Goto(&block5, tmp7);
  }

  TNode<IntPtrT> phi_bb4_6;
  if (block4.is_used()) {
    ca_.Bind(&block4, &phi_bb4_6);
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 84);
    ca_.Goto(&block16);
  }

    ca_.Bind(&block16);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/ordered-hash-table.tq?l=102&c=1
TNode<SmallOrderedNameDictionary> DownCastForTorqueClass_SmallOrderedNameDictionary_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Map> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 327);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp1 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference{p_o, tmp0});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 330);
    if (((CodeStubAssembler(state_).ConstexprInt31Equal(static_cast<InstanceType>(233), static_cast<InstanceType>(233))))) {
      ca_.Goto(&block3);
    } else {
      ca_.Goto(&block4);
    }
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 331);
    if ((CodeStubAssembler(state_).ClassHasMapConstant<SmallOrderedNameDictionary>())) {
      ca_.Goto(&block6);
    } else {
      ca_.Goto(&block7);
    }
  }

  TNode<Map> tmp2;
  TNode<BoolT> tmp3;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 332);
    tmp2 = CodeStubAssembler(state_).GetClassMapConstant<SmallOrderedNameDictionary>();
    tmp3 = CodeStubAssembler(state_).TaggedNotEqual(TNode<HeapObject>{tmp1}, TNode<HeapObject>{tmp2});
    ca_.Branch(tmp3, &block9, std::vector<compiler::Node*>{}, &block10, std::vector<compiler::Node*>{});
  }

  if (block9.is_used()) {
    ca_.Bind(&block9);
    ca_.Goto(&block1);
  }

  if (block10.is_used()) {
    ca_.Bind(&block10);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 331);
    ca_.Goto(&block8);
  }

  TNode<IntPtrT> tmp4;
  TNode<Uint16T> tmp5;
  TNode<Uint32T> tmp6;
  TNode<BoolT> tmp7;
  if (block7.is_used()) {
    ca_.Bind(&block7);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 334);
    tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp5 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference{tmp1, tmp4});
    tmp6 = FromConstexpr_uint32_constexpr_uint32_0(state_, static_cast<InstanceType>(233));
    tmp7 = CodeStubAssembler(state_).Word32NotEqual(TNode<Uint32T>{tmp5}, TNode<Uint32T>{tmp6});
    ca_.Branch(tmp7, &block11, std::vector<compiler::Node*>{}, &block12, std::vector<compiler::Node*>{});
  }

  if (block11.is_used()) {
    ca_.Bind(&block11);
    ca_.Goto(&block1);
  }

  if (block12.is_used()) {
    ca_.Bind(&block12);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 331);
    ca_.Goto(&block8);
  }

  if (block8.is_used()) {
    ca_.Bind(&block8);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 330);
    ca_.Goto(&block5);
  }

  TNode<Int32T> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<Uint16T> tmp10;
  TNode<Uint16T> tmp11;
  TNode<Int32T> tmp12;
  TNode<Uint16T> tmp13;
  TNode<Uint16T> tmp14;
  TNode<Int32T> tmp15;
  TNode<Int32T> tmp16;
  TNode<Uint32T> tmp17;
  TNode<Uint32T> tmp18;
  TNode<BoolT> tmp19;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 337);
    tmp8 = FromConstexpr_int32_constexpr_int32_0(state_, (CodeStubAssembler(state_).ConstexprUint32Sub(static_cast<InstanceType>(233), static_cast<InstanceType>(233))));
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 338);
    tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp10 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference{tmp1, tmp9});
    tmp11 = Convert_uint16_InstanceType_0(state_, TNode<Uint16T>{tmp10});
    tmp12 = Convert_int32_uint16_0(state_, TNode<Uint16T>{tmp11});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 340);
    tmp13 = FromConstexpr_InstanceType_constexpr_InstanceType_0(state_, static_cast<InstanceType>(233));
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 339);
    tmp14 = Convert_uint16_InstanceType_0(state_, TNode<Uint16T>{tmp13});
    tmp15 = Convert_int32_uint16_0(state_, TNode<Uint16T>{tmp14});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 338);
    tmp16 = CodeStubAssembler(state_).Int32Sub(TNode<Int32T>{tmp12}, TNode<Int32T>{tmp15});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 341);
    tmp17 = CodeStubAssembler(state_).Unsigned(TNode<Int32T>{tmp16});
    tmp18 = CodeStubAssembler(state_).Unsigned(TNode<Int32T>{tmp8});
    tmp19 = CodeStubAssembler(state_).Uint32GreaterThan(TNode<Uint32T>{tmp17}, TNode<Uint32T>{tmp18});
    ca_.Branch(tmp19, &block13, std::vector<compiler::Node*>{}, &block14, std::vector<compiler::Node*>{});
  }

  if (block13.is_used()) {
    ca_.Bind(&block13);
    ca_.Goto(&block1);
  }

  if (block14.is_used()) {
    ca_.Bind(&block14);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 330);
    ca_.Goto(&block5);
  }

  TNode<SmallOrderedNameDictionary> tmp20;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 343);
    tmp20 = TORQUE_CAST(TNode<HeapObject>{p_o});
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 102);
    ca_.Goto(&block15);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_CastError);
  }

    ca_.Bind(&block15);
  return TNode<SmallOrderedNameDictionary>{tmp20};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/ordered-hash-table.tq?l=33&c=3
TorqueStructSlice_JSReceiver_OR_Smi_OR_HeapNumber_OR_BigInt_OR_String_OR_Symbol_OR_True_OR_False_OR_Null_OR_Undefined_OR_TheHole_MutableReference_JSReceiver_OR_Smi_OR_HeapNumber_OR_BigInt_OR_String_OR_Symbol_OR_True_OR_False_OR_Null_OR_Undefined_OR_TheHole_0 NewMutableSlice_JSReceiver_OR_Smi_OR_HeapNumber_OR_BigInt_OR_String_OR_Symbol_OR_True_OR_False_OR_Null_OR_Undefined_OR_TheHole_0(compiler::CodeAssemblerState* state_, TNode<Object> p_object, TNode<IntPtrT> p_offset, TNode<IntPtrT> p_length) {
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
    std::tie(tmp0, tmp1, tmp2) = (TorqueStructSlice_JSReceiver_OR_Smi_OR_HeapNumber_OR_BigInt_OR_String_OR_Symbol_OR_True_OR_False_OR_Null_OR_Undefined_OR_TheHole_MutableReference_JSReceiver_OR_Smi_OR_HeapNumber_OR_BigInt_OR_String_OR_Symbol_OR_True_OR_False_OR_Null_OR_Undefined_OR_TheHole_0{TNode<Object>{p_object}, TNode<IntPtrT>{p_offset}, TNode<IntPtrT>{p_length}, TorqueStructUnsafe_0{}}).Flatten();
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 33);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TorqueStructSlice_JSReceiver_OR_Smi_OR_HeapNumber_OR_BigInt_OR_String_OR_Symbol_OR_True_OR_False_OR_Null_OR_Undefined_OR_TheHole_MutableReference_JSReceiver_OR_Smi_OR_HeapNumber_OR_BigInt_OR_String_OR_Symbol_OR_True_OR_False_OR_Null_OR_Undefined_OR_TheHole_0{TNode<Object>{tmp0}, TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp2}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/ordered-hash-table.tq?l=72&c=3
TorqueStructSlice_HashMapEntry_MutableReference_HashMapEntry_0 NewMutableSlice_HashMapEntry_0(compiler::CodeAssemblerState* state_, TNode<Object> p_object, TNode<IntPtrT> p_offset, TNode<IntPtrT> p_length) {
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
    std::tie(tmp0, tmp1, tmp2) = (TorqueStructSlice_HashMapEntry_MutableReference_HashMapEntry_0{TNode<Object>{p_object}, TNode<IntPtrT>{p_offset}, TNode<IntPtrT>{p_length}, TorqueStructUnsafe_0{}}).Flatten();
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 72);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TorqueStructSlice_HashMapEntry_MutableReference_HashMapEntry_0{TNode<Object>{tmp0}, TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp2}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/ordered-hash-table.tq?l=112&c=3
TorqueStructSlice_NameDictionaryEntry_MutableReference_NameDictionaryEntry_0 NewMutableSlice_NameDictionaryEntry_0(compiler::CodeAssemblerState* state_, TNode<Object> p_object, TNode<IntPtrT> p_offset, TNode<IntPtrT> p_length) {
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
    std::tie(tmp0, tmp1, tmp2) = (TorqueStructSlice_NameDictionaryEntry_MutableReference_NameDictionaryEntry_0{TNode<Object>{p_object}, TNode<IntPtrT>{p_offset}, TNode<IntPtrT>{p_length}, TorqueStructUnsafe_0{}}).Flatten();
    ca_.SetSourcePosition("../../../src/objects/ordered-hash-table.tq", 112);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TorqueStructSlice_NameDictionaryEntry_MutableReference_NameDictionaryEntry_0{TNode<Object>{tmp0}, TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp2}, TorqueStructUnsafe_0{}};
}

} // namespace internal
} // namespace v8
