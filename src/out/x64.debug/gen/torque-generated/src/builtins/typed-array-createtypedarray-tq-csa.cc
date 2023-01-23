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
#include "torque-generated/src/builtins/typed-array-createtypedarray-tq-csa.h"
#include "torque-generated/src/builtins/array-join-tq-csa.h"
#include "torque-generated/src/builtins/arraybuffer-tq-csa.h"
#include "torque-generated/src/builtins/base-tq-csa.h"
#include "torque-generated/src/builtins/cast-tq-csa.h"
#include "torque-generated/src/builtins/convert-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-createtypedarray-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-tq-csa.h"
#include "torque-generated/src/objects/js-array-buffer-tq-csa.h"
#include "torque-generated/src/objects/js-objects-tq-csa.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/typed-array-createtypedarray.tq?l=25&c=1
TNode<JSTypedArray> AllocateTypedArray_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, bool p_isOnHeap, TNode<Map> p_map, TNode<JSArrayBuffer> p_buffer, TNode<UintPtrT> p_byteOffset, TNode<UintPtrT> p_byteLength, TNode<UintPtrT> p_length, TNode<BoolT> p_isLengthTracking) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<ByteArray> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<ByteArray> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<ByteArray> block18(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<ByteArray> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<ByteArray> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<ByteArray> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<ByteArray> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<ByteArray> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<ByteArray, BoolT> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<ByteArray> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<ByteArray> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<ByteArray> block26(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<ByteArray> block25(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<ByteArray> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block27(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 30);
    if ((p_isOnHeap)) {
      ca_.Goto(&block2);
    } else {
      ca_.Goto(&block3);
    }
  }

  TNode<BoolT> tmp0;
  TNode<BoolT> tmp1;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 31);
    tmp0 = IsResizableArrayBuffer_0(state_, TNode<JSArrayBuffer>{p_buffer});
    tmp1 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp0});
    ca_.Branch(tmp1, &block5, std::vector<compiler::Node*>{}, &block6, std::vector<compiler::Node*>{});
  }

  if (block6.is_used()) {
    ca_.Bind(&block6);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/typed-array-createtypedarray.tq", 31});
      CodeStubAssembler(state_).FailAssert("Torque assert '!IsResizableArrayBuffer(buffer)' failed", pos_stack);
    }
  }

  TNode<BoolT> tmp2;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 32);
    tmp2 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{p_isLengthTracking});
    ca_.Branch(tmp2, &block7, std::vector<compiler::Node*>{}, &block8, std::vector<compiler::Node*>{});
  }

  if (block8.is_used()) {
    ca_.Bind(&block8);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/typed-array-createtypedarray.tq", 32});
      CodeStubAssembler(state_).FailAssert("Torque assert '!isLengthTracking' failed", pos_stack);
    }
  }

  TNode<ByteArray> tmp3;
  if (block7.is_used()) {
    ca_.Bind(&block7);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 33);
    tmp3 = CodeStubAssembler(state_).AllocateByteArray(TNode<UintPtrT>{p_byteLength});
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 30);
    ca_.Goto(&block4, tmp3);
  }

  TNode<ByteArray> tmp4;
  TNode<RawPtrT> tmp5;
  TNode<UintPtrT> tmp6;
  TNode<BoolT> tmp7;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 35);
    tmp4 = kEmptyByteArray_0(state_);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 41);
    tmp5 = CodeStubAssembler(state_).LoadJSArrayBufferBackingStorePtr(TNode<JSArrayBuffer>{p_buffer});
    tmp6 = Convert_uintptr_RawPtr_0(state_, TNode<RawPtrT>{tmp5});
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 48);
    tmp7 = CodeStubAssembler(state_).IsMockArrayBufferAllocatorFlag();
    ca_.Branch(tmp7, &block11, std::vector<compiler::Node*>{}, &block12, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp8;
  if (block11.is_used()) {
    ca_.Bind(&block11);
    tmp8 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block13, tmp8);
  }

  TNode<UintPtrT> tmp9;
  TNode<BoolT> tmp10;
  if (block12.is_used()) {
    ca_.Bind(&block12);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 49);
    tmp9 = CodeStubAssembler(state_).UintPtrAdd(TNode<UintPtrT>{tmp6}, TNode<UintPtrT>{p_byteOffset});
    tmp10 = CodeStubAssembler(state_).UintPtrGreaterThanOrEqual(TNode<UintPtrT>{tmp9}, TNode<UintPtrT>{tmp6});
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 48);
    ca_.Goto(&block13, tmp10);
  }

  TNode<BoolT> phi_bb13_10;
  if (block13.is_used()) {
    ca_.Bind(&block13, &phi_bb13_10);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 47);
    ca_.Branch(phi_bb13_10, &block9, std::vector<compiler::Node*>{}, &block10, std::vector<compiler::Node*>{});
  }

  if (block10.is_used()) {
    ca_.Bind(&block10);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/typed-array-createtypedarray.tq", 47});
      CodeStubAssembler(state_).FailAssert("Torque assert 'IsMockArrayBufferAllocatorFlag() || (backingStore + byteOffset) >= backingStore' failed", pos_stack);
    }
  }

  if (block9.is_used()) {
    ca_.Bind(&block9);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 30);
    ca_.Goto(&block4, tmp4);
  }

  TNode<ByteArray> phi_bb4_7;
  TNode<JSObject> tmp11;
  TNode<JSTypedArray> tmp12;
  TNode<IntPtrT> tmp13;
  TNode<IntPtrT> tmp14;
  if (block4.is_used()) {
    ca_.Bind(&block4, &phi_bb4_7);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 56);
    tmp11 = AllocateFastOrSlowJSObjectFromMap_0(state_, TNode<Context>{p_context}, TNode<Map>{p_map});
    tmp12 = UnsafeCast_JSTypedArray_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp11});
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 57);
    tmp13 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    CodeStubAssembler(state_).StoreReference<FixedArrayBase>(CodeStubAssembler::Reference{tmp12, tmp13}, phi_bb4_7);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 58);
    tmp14 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    CodeStubAssembler(state_).StoreReference<JSArrayBuffer>(CodeStubAssembler::Reference{tmp12, tmp14}, p_buffer);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 59);
    CodeStubAssembler(state_).StoreJSArrayBufferViewByteOffset(TNode<JSArrayBufferView>{tmp12}, TNode<UintPtrT>{p_byteOffset});
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 60);
    ca_.Branch(p_isLengthTracking, &block14, std::vector<compiler::Node*>{phi_bb4_7}, &block15, std::vector<compiler::Node*>{phi_bb4_7});
  }

  TNode<ByteArray> phi_bb14_7;
  TNode<BoolT> tmp15;
  if (block14.is_used()) {
    ca_.Bind(&block14, &phi_bb14_7);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 61);
    tmp15 = IsResizableArrayBuffer_0(state_, TNode<JSArrayBuffer>{p_buffer});
    ca_.Branch(tmp15, &block17, std::vector<compiler::Node*>{phi_bb14_7}, &block18, std::vector<compiler::Node*>{phi_bb14_7});
  }

  TNode<ByteArray> phi_bb18_7;
  if (block18.is_used()) {
    ca_.Bind(&block18, &phi_bb18_7);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/typed-array-createtypedarray.tq", 61});
      CodeStubAssembler(state_).FailAssert("Torque assert 'IsResizableArrayBuffer(buffer)' failed", pos_stack);
    }
  }

  TNode<ByteArray> phi_bb17_7;
  TNode<UintPtrT> tmp16;
  TNode<UintPtrT> tmp17;
  if (block17.is_used()) {
    ca_.Bind(&block17, &phi_bb17_7);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 64);
    tmp16 = FromConstexpr_uintptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    CodeStubAssembler(state_).StoreJSArrayBufferViewByteLength(TNode<JSArrayBufferView>{tmp12}, TNode<UintPtrT>{tmp16});
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 65);
    tmp17 = FromConstexpr_uintptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    CodeStubAssembler(state_).StoreJSTypedArrayLength(TNode<JSTypedArray>{tmp12}, TNode<UintPtrT>{tmp17});
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 60);
    ca_.Goto(&block16, phi_bb17_7);
  }

  TNode<ByteArray> phi_bb15_7;
  if (block15.is_used()) {
    ca_.Bind(&block15, &phi_bb15_7);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 67);
    CodeStubAssembler(state_).StoreJSArrayBufferViewByteLength(TNode<JSArrayBufferView>{tmp12}, TNode<UintPtrT>{p_byteLength});
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 68);
    CodeStubAssembler(state_).StoreJSTypedArrayLength(TNode<JSTypedArray>{tmp12}, TNode<UintPtrT>{p_length});
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 60);
    ca_.Goto(&block16, phi_bb15_7);
  }

  TNode<ByteArray> phi_bb16_7;
  TNode<IntPtrT> tmp18;
  TNode<Uint32T> tmp19;
  TNode<Uint32T> tmp20;
  TNode<IntPtrT> tmp21;
  TNode<BoolT> tmp22;
  if (block16.is_used()) {
    ca_.Bind(&block16, &phi_bb16_7);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 70);
    tmp18 = FromConstexpr_intptr_constexpr_int31_0(state_, 32);
    tmp19 = CodeStubAssembler(state_).LoadReference<Uint32T>(CodeStubAssembler::Reference{tmp12, tmp18});
    tmp20 = ca_.UncheckedCast<Uint32T>(CodeStubAssembler(state_).UpdateWord32<base::BitField<bool, 0, 1, uint32_t>>(ca_.UncheckedCast<Word32T>(tmp19), ca_.UncheckedCast<Uint32T>(p_isLengthTracking)));
    CodeStubAssembler(state_).StoreReference<Uint32T>(CodeStubAssembler::Reference{tmp12, tmp18}, tmp20);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 71);
    tmp21 = FromConstexpr_intptr_constexpr_int31_0(state_, 32);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 72);
    tmp22 = IsResizableArrayBuffer_0(state_, TNode<JSArrayBuffer>{p_buffer});
    ca_.Branch(tmp22, &block19, std::vector<compiler::Node*>{phi_bb16_7}, &block20, std::vector<compiler::Node*>{phi_bb16_7});
  }

  TNode<ByteArray> phi_bb19_7;
  TNode<BoolT> tmp23;
  TNode<BoolT> tmp24;
  if (block19.is_used()) {
    ca_.Bind(&block19, &phi_bb19_7);
    tmp23 = IsSharedArrayBuffer_0(state_, TNode<JSArrayBuffer>{p_buffer});
    tmp24 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp23});
    ca_.Goto(&block21, phi_bb19_7, tmp24);
  }

  TNode<ByteArray> phi_bb20_7;
  TNode<BoolT> tmp25;
  if (block20.is_used()) {
    ca_.Bind(&block20, &phi_bb20_7);
    tmp25 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block21, phi_bb20_7, tmp25);
  }

  TNode<ByteArray> phi_bb21_7;
  TNode<BoolT> phi_bb21_13;
  TNode<Uint32T> tmp26;
  TNode<Uint32T> tmp27;
  if (block21.is_used()) {
    ca_.Bind(&block21, &phi_bb21_7, &phi_bb21_13);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 71);
    tmp26 = CodeStubAssembler(state_).LoadReference<Uint32T>(CodeStubAssembler::Reference{tmp12, tmp21});
    tmp27 = ca_.UncheckedCast<Uint32T>(CodeStubAssembler(state_).UpdateWord32<base::BitField<bool, 1, 1, uint32_t>>(ca_.UncheckedCast<Word32T>(tmp26), ca_.UncheckedCast<Uint32T>(phi_bb21_13)));
    CodeStubAssembler(state_).StoreReference<Uint32T>(CodeStubAssembler::Reference{tmp12, tmp21}, tmp27);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 73);
    if ((p_isOnHeap)) {
      ca_.Goto(&block22, phi_bb21_7);
    } else {
      ca_.Goto(&block23, phi_bb21_7);
    }
  }

  TNode<ByteArray> phi_bb22_7;
  if (block22.is_used()) {
    ca_.Bind(&block22, &phi_bb22_7);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 74);
    TypedArrayBuiltinsAssembler(state_).SetJSTypedArrayOnHeapDataPtr(TNode<JSTypedArray>{tmp12}, TNode<ByteArray>{phi_bb22_7}, TNode<UintPtrT>{p_byteOffset});
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 73);
    ca_.Goto(&block24, phi_bb22_7);
  }

  TNode<ByteArray> phi_bb23_7;
  TNode<RawPtrT> tmp28;
  TNode<RawPtrT> tmp29;
  TNode<RawPtrT> tmp30;
  TNode<IntPtrT> tmp31;
  TNode<RawPtrT> tmp32;
  TNode<BoolT> tmp33;
  if (block23.is_used()) {
    ca_.Bind(&block23, &phi_bb23_7);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 77);
    tmp28 = CodeStubAssembler(state_).LoadJSArrayBufferBackingStorePtr(TNode<JSArrayBuffer>{p_buffer});
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 76);
    TypedArrayBuiltinsAssembler(state_).SetJSTypedArrayOffHeapDataPtr(TNode<JSTypedArray>{tmp12}, TNode<RawPtrT>{tmp28}, TNode<UintPtrT>{p_byteOffset});
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 79);
    tmp29 = CodeStubAssembler(state_).LoadJSTypedArrayDataPtr(TNode<JSTypedArray>{tmp12});
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 80);
    tmp30 = CodeStubAssembler(state_).LoadJSArrayBufferBackingStorePtr(TNode<JSArrayBuffer>{p_buffer});
    tmp31 = Convert_intptr_uintptr_0(state_, TNode<UintPtrT>{p_byteOffset});
    tmp32 = CodeStubAssembler(state_).RawPtrAdd(TNode<RawPtrT>{tmp30}, TNode<IntPtrT>{tmp31});
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 79);
    tmp33 = CodeStubAssembler(state_).WordEqual(TNode<RawPtrT>{tmp29}, TNode<RawPtrT>{tmp32});
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 78);
    ca_.Branch(tmp33, &block25, std::vector<compiler::Node*>{phi_bb23_7}, &block26, std::vector<compiler::Node*>{phi_bb23_7});
  }

  TNode<ByteArray> phi_bb26_7;
  if (block26.is_used()) {
    ca_.Bind(&block26, &phi_bb26_7);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/typed-array-createtypedarray.tq", 78});
      CodeStubAssembler(state_).FailAssert("Torque assert 'typedArray.data_ptr == (buffer.backing_store_ptr + Convert<intptr>(byteOffset))' failed", pos_stack);
    }
  }

  TNode<ByteArray> phi_bb25_7;
  if (block25.is_used()) {
    ca_.Bind(&block25, &phi_bb25_7);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 73);
    ca_.Goto(&block24, phi_bb25_7);
  }

  TNode<ByteArray> phi_bb24_7;
  if (block24.is_used()) {
    ca_.Bind(&block24, &phi_bb24_7);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 82);
    TypedArrayBuiltinsAssembler(state_).SetupTypedArrayEmbedderFields(TNode<JSTypedArray>{tmp12});
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 25);
    ca_.Goto(&block27);
  }

    ca_.Bind(&block27);
  return TNode<JSTypedArray>{tmp12};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/typed-array-createtypedarray.tq?l=86&c=1
TNode<JSTypedArray> TypedArrayInitialize_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, bool p_initialize, TNode<Map> p_map, TNode<UintPtrT> p_length, TorqueStructTypedArrayElementsInfo p_elementsInfo, compiler::CodeAssemblerLabel* label_IfRangeError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSTypedArray> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<UintPtrT> tmp0;
  TNode<BoolT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/typed-array.tq", 28);
    tmp0 = FromConstexpr_uintptr_constexpr_uintptr_0(state_, JSTypedArray::kMaxLength);
    tmp1 = CodeStubAssembler(state_).UintPtrGreaterThan(TNode<UintPtrT>{p_length}, TNode<UintPtrT>{tmp0});
    ca_.Branch(tmp1, &block4, std::vector<compiler::Node*>{}, &block5, std::vector<compiler::Node*>{});
  }

  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.Goto(&block1);
  }

  TNode<UintPtrT> tmp2;
  TNode<UintPtrT> tmp3;
  TNode<BoolT> tmp4;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    ca_.SetSourcePosition("../../../src/builtins/typed-array.tq", 29);
    tmp2 = FromConstexpr_uintptr_constexpr_uintptr_0(state_, JSArrayBuffer::kMaxByteLength);
    tmp3 = CodeStubAssembler(state_).WordShr(TNode<UintPtrT>{tmp2}, TNode<UintPtrT>{p_elementsInfo.sizeLog2});
    ca_.SetSourcePosition("../../../src/builtins/typed-array.tq", 30);
    tmp4 = CodeStubAssembler(state_).UintPtrGreaterThan(TNode<UintPtrT>{p_length}, TNode<UintPtrT>{tmp3});
    ca_.Branch(tmp4, &block6, std::vector<compiler::Node*>{}, &block7, std::vector<compiler::Node*>{});
  }

  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.Goto(&block1);
  }

  TNode<UintPtrT> tmp5;
  TNode<Number> tmp6;
  TNode<JSReceiver> tmp7;
  TNode<UintPtrT> tmp8;
  TNode<UintPtrT> tmp9;
  TNode<BoolT> tmp10;
  if (block7.is_used()) {
    ca_.Bind(&block7);
    ca_.SetSourcePosition("../../../src/builtins/typed-array.tq", 31);
    tmp5 = CodeStubAssembler(state_).WordShl(TNode<UintPtrT>{p_length}, TNode<UintPtrT>{p_elementsInfo.sizeLog2});
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 92);
    tmp6 = Convert_Number_uintptr_0(state_, TNode<UintPtrT>{tmp5});
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 93);
    tmp7 = GetArrayBufferFunction_0(state_, TNode<Context>{p_context});
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 94);
    tmp8 = FromConstexpr_uintptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 97);
    tmp9 = FromConstexpr_uintptr_constexpr_int31_0(state_, JSTypedArray::kMaxSizeInHeap);
    tmp10 = CodeStubAssembler(state_).UintPtrGreaterThan(TNode<UintPtrT>{tmp5}, TNode<UintPtrT>{tmp9});
    ca_.Branch(tmp10, &block12, std::vector<compiler::Node*>{}, &block13, std::vector<compiler::Node*>{});
  }

  if (block12.is_used()) {
    ca_.Bind(&block12);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 114);
    if ((p_initialize)) {
      ca_.Goto(&block17);
    } else {
      ca_.Goto(&block18);
    }
  }

  TNode<JSArrayBuffer> tmp11;
  TNode<BoolT> tmp12;
  TNode<JSTypedArray> tmp13;
  if (block13.is_used()) {
    ca_.Bind(&block13);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 99);
    tmp11 = TypedArrayBuiltinsAssembler(state_).AllocateEmptyOnHeapBuffer(TNode<Context>{p_context});
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 103);
    tmp12 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    tmp13 = AllocateTypedArray_0(state_, TNode<Context>{p_context}, true, TNode<Map>{p_map}, TNode<JSArrayBuffer>{tmp11}, TNode<UintPtrT>{tmp8}, TNode<UintPtrT>{tmp5}, TNode<UintPtrT>{p_length}, TNode<BoolT>{tmp12});
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 107);
    if ((p_initialize)) {
      ca_.Goto(&block14);
    } else {
      ca_.Goto(&block15);
    }
  }

  TNode<RawPtrT> tmp14;
  TNode<IntPtrT> tmp15;
  if (block14.is_used()) {
    ca_.Bind(&block14);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 108);
    tmp14 = CodeStubAssembler(state_).LoadJSTypedArrayDataPtr(TNode<JSTypedArray>{tmp13});
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 109);
    tmp15 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    TypedArrayBuiltinsAssembler(state_).CallCMemset(TNode<RawPtrT>{tmp14}, TNode<IntPtrT>{tmp15}, TNode<UintPtrT>{tmp5});
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 107);
    ca_.Goto(&block16);
  }

  if (block15.is_used()) {
    ca_.Bind(&block15);
    ca_.Goto(&block16);
  }

  if (block16.is_used()) {
    ca_.Bind(&block16);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 112);
    ca_.Goto(&block2, tmp13);
  }

  TNode<JSReceiver> tmp16;
  if (block17.is_used()) {
    ca_.Bind(&block17);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 115);
    tmp16 = CodeStubAssembler(state_).Construct(TNode<Context>{p_context}, TNode<JSReceiver>{tmp7}, TNode<Object>{tmp6});
    ca_.Goto(&block9, tmp16);
  }

  TNode<JSFunction> tmp17;
  TNode<Oddball> tmp18;
  TNode<Object> tmp19;
  if (block18.is_used()) {
    ca_.Bind(&block18);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 118);
    tmp17 = GetArrayBufferNoInitFunction_0(state_, TNode<Context>{p_context});
    tmp18 = Undefined_0(state_);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 117);
    tmp19 = CodeStubAssembler(state_).Call(TNode<Context>{p_context}, TNode<Object>{tmp17}, TNode<Object>{tmp18}, TNode<Object>{tmp6});
    ca_.Goto(&block9, tmp19);
  }

  TNode<Object> phi_bb9_9;
  TNode<JSArrayBuffer> tmp20;
  if (block9.is_used()) {
    ca_.Bind(&block9, &phi_bb9_9);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 121);
    compiler::CodeAssemblerLabel label21(&ca_);
    tmp20 = Cast_JSArrayBuffer_1(state_, TNode<Context>{p_context}, TNode<Object>{phi_bb9_9}, &label21);
    ca_.Goto(&block22);
    if (label21.is_used()) {
      ca_.Bind(&label21);
      ca_.Goto(&block23);
    }
  }

  if (block23.is_used()) {
    ca_.Bind(&block23);
    CodeStubAssembler(state_).PrintErr("halting because of unreachable code at src/builtins/typed-array-createtypedarray.tq:121:61");
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<BoolT> tmp22;
  TNode<JSTypedArray> tmp23;
  if (block22.is_used()) {
    ca_.Bind(&block22);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 124);
    tmp22 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    tmp23 = AllocateTypedArray_0(state_, TNode<Context>{p_context}, false, TNode<Map>{p_map}, TNode<JSArrayBuffer>{tmp20}, TNode<UintPtrT>{tmp8}, TNode<UintPtrT>{tmp5}, TNode<UintPtrT>{p_length}, TNode<BoolT>{tmp22});
    ca_.Goto(&block2, tmp23);
  }

  TNode<JSTypedArray> phi_bb2_5;
  if (block2.is_used()) {
    ca_.Bind(&block2, &phi_bb2_5);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 86);
    ca_.Goto(&block24);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_IfRangeError);
  }

    ca_.Bind(&block24);
  return TNode<JSTypedArray>{phi_bb2_5};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/typed-array-createtypedarray.tq?l=132&c=1
TNode<JSTypedArray> ConstructByLength_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Map> p_map, TNode<Object> p_lengthObj, TorqueStructTypedArrayElementsInfo p_elementsInfo) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<UintPtrT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 136);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = ToIndex_0(state_, TNode<Context>{p_context}, TNode<Object>{p_lengthObj}, &label1);
    ca_.Goto(&block4);
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block5);
    }
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    ca_.Goto(&block3);
  }

  TNode<JSTypedArray> tmp2;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 138);
    compiler::CodeAssemblerLabel label3(&ca_);
    tmp2 = TypedArrayInitialize_0(state_, TNode<Context>{p_context}, true, TNode<Map>{p_map}, TNode<UintPtrT>{tmp0}, TorqueStructTypedArrayElementsInfo{TNode<UintPtrT>{p_elementsInfo.sizeLog2}, TNode<Int32T>{p_elementsInfo.kind}}, &label3);
    ca_.Goto(&block6);
    if (label3.is_used()) {
      ca_.Bind(&label3);
      ca_.Goto(&block7);
    }
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    ca_.Goto(&block3);
  }

  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 132);
    ca_.Goto(&block8);
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 141);
    CodeStubAssembler(state_).ThrowRangeError(TNode<Context>{p_context}, MessageTemplate::kInvalidTypedArrayLength, TNode<Object>{p_lengthObj});
  }

    ca_.Bind(&block8);
  return TNode<JSTypedArray>{tmp2};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/typed-array-createtypedarray.tq?l=147&c=1
TNode<JSTypedArray> ConstructByArrayLike_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Map> p_map, TNode<HeapObject> p_arrayLike, TNode<UintPtrT> p_length, TorqueStructTypedArrayElementsInfo p_elementsInfo) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block22(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block25(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block26(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block27(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block28(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block29(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block30(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<JSTypedArray> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 153);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = TypedArrayInitialize_0(state_, TNode<Context>{p_context}, false, TNode<Map>{p_map}, TNode<UintPtrT>{p_length}, TorqueStructTypedArrayElementsInfo{TNode<UintPtrT>{p_elementsInfo.sizeLog2}, TNode<Int32T>{p_elementsInfo.kind}}, &label1);
    ca_.Goto(&block4);
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block5);
    }
  }

  TNode<Number> tmp2;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 193);
    tmp2 = Convert_Number_uintptr_0(state_, TNode<UintPtrT>{p_length});
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 192);
    CodeStubAssembler(state_).ThrowRangeError(TNode<Context>{p_context}, MessageTemplate::kInvalidTypedArrayLength, TNode<Object>{tmp2});
  }

  TNode<JSTypedArray> tmp3;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 157);
    compiler::CodeAssemblerLabel label4(&ca_);
    tmp3 = Cast_JSTypedArray_0(state_, TNode<HeapObject>{p_arrayLike}, &label4);
    ca_.Goto(&block10);
    if (label4.is_used()) {
      ca_.Bind(&label4);
      ca_.Goto(&block11);
    }
  }

  if (block11.is_used()) {
    ca_.Bind(&block11);
    ca_.Goto(&block7);
  }

  TNode<IntPtrT> tmp5;
  TNode<JSArrayBuffer> tmp6;
  TNode<UintPtrT> tmp7;
  if (block10.is_used()) {
    ca_.Bind(&block10);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 160);
    tmp5 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp6 = CodeStubAssembler(state_).LoadReference<JSArrayBuffer>(CodeStubAssembler::Reference{tmp3, tmp5});
    compiler::CodeAssemblerLabel label8(&ca_);
    tmp7 = LoadJSArrayBufferViewByteLength_0(state_, TNode<JSArrayBufferView>{tmp3}, TNode<JSArrayBuffer>{tmp6}, &label8);
    ca_.Goto(&block14);
    if (label8.is_used()) {
      ca_.Bind(&label8);
      ca_.Goto(&block15);
    }
  }

  if (block15.is_used()) {
    ca_.Bind(&block15);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 163);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{p_context}, MessageTemplate::kDetachedOperation, "Construct");
  }

  TNode<Int32T> tmp9;
  TNode<BoolT> tmp10;
  if (block14.is_used()) {
    ca_.Bind(&block14);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 165);
    tmp9 = CodeStubAssembler(state_).LoadElementsKind(TNode<JSTypedArray>{tmp3});
    tmp10 = ElementsKindNotEqual_0(state_, TNode<Int32T>{tmp9}, TNode<Int32T>{p_elementsInfo.kind});
    ca_.Branch(tmp10, &block16, std::vector<compiler::Node*>{}, &block17, std::vector<compiler::Node*>{});
  }

  TNode<Int32T> tmp11;
  TNode<BoolT> tmp12;
  TNode<BoolT> tmp13;
  TNode<BoolT> tmp14;
  if (block16.is_used()) {
    ca_.Bind(&block16);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 166);
    tmp11 = CodeStubAssembler(state_).LoadElementsKind(TNode<JSTypedArray>{tmp3});
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 179);
    tmp12 = TypedArrayBuiltinsAssembler(state_).IsBigInt64ElementsKind(TNode<Int32T>{tmp11});
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 180);
    tmp13 = TypedArrayBuiltinsAssembler(state_).IsBigInt64ElementsKind(TNode<Int32T>{p_elementsInfo.kind});
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 179);
    tmp14 = CodeStubAssembler(state_).Word32NotEqual(TNode<BoolT>{tmp12}, TNode<BoolT>{tmp13});
    ca_.Branch(tmp14, &block26, std::vector<compiler::Node*>{}, &block27, std::vector<compiler::Node*>{});
  }

  TNode<UintPtrT> tmp15;
  TNode<BoolT> tmp16;
  if (block17.is_used()) {
    ca_.Bind(&block17);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 168);
    tmp15 = FromConstexpr_uintptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp16 = CodeStubAssembler(state_).UintPtrGreaterThan(TNode<UintPtrT>{p_length}, TNode<UintPtrT>{tmp15});
    ca_.Branch(tmp16, &block19, std::vector<compiler::Node*>{}, &block20, std::vector<compiler::Node*>{});
  }

  TNode<UintPtrT> tmp17;
  TNode<BoolT> tmp18;
  if (block19.is_used()) {
    ca_.Bind(&block19);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 169);
    tmp17 = FromConstexpr_uintptr_constexpr_uintptr_0(state_, JSArrayBuffer::kMaxByteLength);
    tmp18 = CodeStubAssembler(state_).UintPtrLessThanOrEqual(TNode<UintPtrT>{tmp7}, TNode<UintPtrT>{tmp17});
    ca_.Branch(tmp18, &block21, std::vector<compiler::Node*>{}, &block22, std::vector<compiler::Node*>{});
  }

  if (block22.is_used()) {
    ca_.Bind(&block22);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/typed-array-createtypedarray.tq", 169});
      CodeStubAssembler(state_).FailAssert("Torque assert 'byteLength <= kArrayBufferMaxByteLength' failed", pos_stack);
    }
  }

  TNode<IntPtrT> tmp19;
  TNode<JSArrayBuffer> tmp20;
  TNode<BoolT> tmp21;
  if (block21.is_used()) {
    ca_.Bind(&block21);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 170);
    tmp19 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp20 = CodeStubAssembler(state_).LoadReference<JSArrayBuffer>(CodeStubAssembler::Reference{tmp3, tmp19});
    tmp21 = IsSharedArrayBuffer_0(state_, TNode<JSArrayBuffer>{tmp20});
    ca_.Branch(tmp21, &block23, std::vector<compiler::Node*>{}, &block24, std::vector<compiler::Node*>{});
  }

  TNode<RawPtrT> tmp22;
  TNode<RawPtrT> tmp23;
  if (block23.is_used()) {
    ca_.Bind(&block23);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 172);
    tmp22 = CodeStubAssembler(state_).LoadJSTypedArrayDataPtr(TNode<JSTypedArray>{tmp0});
    tmp23 = CodeStubAssembler(state_).LoadJSTypedArrayDataPtr(TNode<JSTypedArray>{tmp3});
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 171);
    TypedArrayBuiltinsAssembler(state_).CallCRelaxedMemcpy(TNode<RawPtrT>{tmp22}, TNode<RawPtrT>{tmp23}, TNode<UintPtrT>{tmp7});
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 170);
    ca_.Goto(&block25);
  }

  TNode<RawPtrT> tmp24;
  TNode<RawPtrT> tmp25;
  if (block24.is_used()) {
    ca_.Bind(&block24);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 175);
    tmp24 = CodeStubAssembler(state_).LoadJSTypedArrayDataPtr(TNode<JSTypedArray>{tmp0});
    tmp25 = CodeStubAssembler(state_).LoadJSTypedArrayDataPtr(TNode<JSTypedArray>{tmp3});
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 174);
    TypedArrayBuiltinsAssembler(state_).CallCMemcpy(TNode<RawPtrT>{tmp24}, TNode<RawPtrT>{tmp25}, TNode<UintPtrT>{tmp7});
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 170);
    ca_.Goto(&block25);
  }

  if (block25.is_used()) {
    ca_.Bind(&block25);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 168);
    ca_.Goto(&block20);
  }

  if (block20.is_used()) {
    ca_.Bind(&block20);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 184);
    ca_.Goto(&block6);
  }

  if (block26.is_used()) {
    ca_.Bind(&block26);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 181);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{p_context}, MessageTemplate::kBigIntMixedTypes);
  }

  if (block27.is_used()) {
    ca_.Bind(&block27);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 183);
    ca_.Goto(&block7);
  }

  TNode<UintPtrT> tmp26;
  TNode<BoolT> tmp27;
  if (block7.is_used()) {
    ca_.Bind(&block7);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 185);
    tmp26 = FromConstexpr_uintptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp27 = CodeStubAssembler(state_).UintPtrGreaterThan(TNode<UintPtrT>{p_length}, TNode<UintPtrT>{tmp26});
    ca_.Branch(tmp27, &block28, std::vector<compiler::Node*>{}, &block29, std::vector<compiler::Node*>{});
  }

  TNode<Number> tmp28;
  if (block28.is_used()) {
    ca_.Bind(&block28);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 187);
    tmp28 = Convert_Number_uintptr_0(state_, TNode<UintPtrT>{p_length});
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 186);
    CodeStubAssembler(state_).CallRuntime(Runtime::kTypedArrayCopyElements, p_context, tmp0, p_arrayLike, tmp28);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 185);
    ca_.Goto(&block29);
  }

  if (block29.is_used()) {
    ca_.Bind(&block29);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 156);
    ca_.Goto(&block6);
  }

  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 147);
    ca_.Goto(&block30);
  }

    ca_.Bind(&block30);
  return TNode<JSTypedArray>{tmp0};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/typed-array-createtypedarray.tq?l=199&c=1
void ConstructByIterable_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSReceiver> p_iterable, TNode<JSReceiver> p_iteratorFn, compiler::CodeAssemblerLabel* label_IfConstructByArrayLike, compiler::TypedCodeAssemblerVariable<JSArray>* label_IfConstructByArrayLike_parameter_0, compiler::TypedCodeAssemblerVariable<UintPtrT>* label_IfConstructByArrayLike_parameter_1) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<JSArray> tmp0;
  TNode<UintPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 203);
    tmp0 = ca_.CallStub<JSArray>(Builtins::CallableFor(ca_.isolate(), Builtin::kIterableToListMayPreserveHoles), p_context, p_iterable, p_iteratorFn);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 205);
    tmp1 = LoadJSArrayLengthAsUintPtr_0(state_, TNode<JSArray>{tmp0});
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 199);
    *label_IfConstructByArrayLike_parameter_1 = tmp1;
    *label_IfConstructByArrayLike_parameter_0 = tmp0;
    ca_.Goto(label_IfConstructByArrayLike);
  }
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/typed-array-createtypedarray.tq?l=210&c=1
void ConstructByTypedArray_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSTypedArray> p_srcTypedArray, compiler::CodeAssemblerLabel* label_IfConstructByArrayLike, compiler::TypedCodeAssemblerVariable<JSTypedArray>* label_IfConstructByArrayLike_parameter_0, compiler::TypedCodeAssemblerVariable<UintPtrT>* label_IfConstructByArrayLike_parameter_1) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<UintPtrT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<UintPtrT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 216);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = CodeStubAssembler(state_).LoadJSTypedArrayLengthAndCheckDetached(TNode<JSTypedArray>{p_srcTypedArray}, &label1);
    ca_.Goto(&block4);
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block5);
    }
  }

  TNode<UintPtrT> tmp2;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 219);
    tmp2 = FromConstexpr_uintptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 214);
    ca_.Goto(&block2, tmp2);
  }

  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 218);
    ca_.Goto(&block2, tmp0);
  }

  TNode<UintPtrT> phi_bb2_2;
  if (block2.is_used()) {
    ca_.Bind(&block2, &phi_bb2_2);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 210);
    *label_IfConstructByArrayLike_parameter_1 = phi_bb2_2;
    *label_IfConstructByArrayLike_parameter_0 = p_srcTypedArray;
    ca_.Goto(label_IfConstructByArrayLike);
  }
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/typed-array-createtypedarray.tq?l=227&c=1
TNode<JSTypedArray> ConstructByArrayBuffer_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSFunction> p_target, TNode<JSReceiver> p_newTarget, TNode<JSArrayBuffer> p_buffer, TNode<Object> p_byteOffset, TNode<Object> p_length) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Map, BoolT> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block26(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block25(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block27(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block28(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block31(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block32(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, BoolT> block33(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block29(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block38(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block37(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block30(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, UintPtrT> block34(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block39(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block42(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block43(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block45(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block46(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block48(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block49(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block40(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block51(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block52(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block53(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block54(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block57(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block58(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, BoolT> block59(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block55(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block56(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, UintPtrT, UintPtrT> block41(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, String> block19(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block17(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block15(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block60(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<BoolT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 232);
    tmp0 = IsResizableArrayBuffer_0(state_, TNode<JSArrayBuffer>{p_buffer});
    ca_.Branch(tmp0, &block2, std::vector<compiler::Node*>{}, &block3, std::vector<compiler::Node*>{});
  }

  TNode<Oddball> tmp1;
  TNode<BoolT> tmp2;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    tmp1 = Undefined_0(state_);
    tmp2 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{p_length}, TNode<HeapObject>{tmp1});
    ca_.Goto(&block4, tmp2);
  }

  TNode<BoolT> tmp3;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    tmp3 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block4, tmp3);
  }

  TNode<BoolT> phi_bb4_8;
  TNode<BoolT> tmp4;
  if (block4.is_used()) {
    ca_.Bind(&block4, &phi_bb4_8);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 236);
    tmp4 = IsResizableArrayBuffer_0(state_, TNode<JSArrayBuffer>{p_buffer});
    ca_.Branch(tmp4, &block5, std::vector<compiler::Node*>{}, &block6, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp5;
  TNode<BoolT> tmp6;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 237);
    tmp5 = IsSharedArrayBuffer_0(state_, TNode<JSArrayBuffer>{p_buffer});
    tmp6 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp5});
    ca_.Branch(tmp6, &block8, std::vector<compiler::Node*>{}, &block9, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp7;
  if (block8.is_used()) {
    ca_.Bind(&block8);
    tmp7 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block10, tmp7);
  }

  if (block9.is_used()) {
    ca_.Bind(&block9);
    ca_.Goto(&block10, phi_bb4_8);
  }

  TNode<BoolT> phi_bb10_10;
  if (block10.is_used()) {
    ca_.Bind(&block10, &phi_bb10_10);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 236);
    ca_.Goto(&block7, phi_bb10_10);
  }

  TNode<BoolT> tmp8;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp8 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block7, tmp8);
  }

  TNode<BoolT> phi_bb7_9;
  if (block7.is_used()) {
    ca_.Bind(&block7, &phi_bb7_9);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 238);
    ca_.Branch(phi_bb7_9, &block11, std::vector<compiler::Node*>{phi_bb7_9}, &block12, std::vector<compiler::Node*>{phi_bb7_9});
  }

  TNode<BoolT> phi_bb11_8;
  TNode<Map> tmp9;
  if (block11.is_used()) {
    ca_.Bind(&block11, &phi_bb11_8);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 239);
    tmp9 = GetDerivedRabGsabMap_0(state_, TNode<Context>{p_context}, TNode<JSFunction>{p_target}, TNode<JSReceiver>{p_newTarget});
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 238);
    ca_.Goto(&block13, tmp9, phi_bb11_8);
  }

  TNode<BoolT> phi_bb12_8;
  TNode<Map> tmp10;
  if (block12.is_used()) {
    ca_.Bind(&block12, &phi_bb12_8);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 241);
    tmp10 = GetDerivedMap_0(state_, TNode<Context>{p_context}, TNode<JSFunction>{p_target}, TNode<JSReceiver>{p_newTarget});
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 238);
    ca_.Goto(&block13, tmp10, phi_bb12_8);
  }

  TNode<Map> phi_bb13_6;
  TNode<BoolT> phi_bb13_8;
  TNode<UintPtrT> tmp11;
  TNode<Int32T> tmp12;
  TNode<UintPtrT> tmp13;
  if (block13.is_used()) {
    ca_.Bind(&block13, &phi_bb13_6, &phi_bb13_8);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 246);
    std::tie(tmp11, tmp12) = TypedArrayBuiltinsAssembler(state_).GetTypedArrayElementsInfo(TNode<Map>{phi_bb13_6}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 250);
    compiler::CodeAssemblerLabel label14(&ca_);
    tmp13 = ToIndex_0(state_, TNode<Context>{p_context}, TNode<Object>{p_byteOffset}, &label14);
    ca_.Goto(&block20, phi_bb13_8);
    if (label14.is_used()) {
      ca_.Bind(&label14);
      ca_.Goto(&block21, phi_bb13_8);
    }
  }

  TNode<BoolT> phi_bb21_8;
  if (block21.is_used()) {
    ca_.Bind(&block21, &phi_bb21_8);
    ca_.Goto(&block15, phi_bb21_8);
  }

  TNode<BoolT> phi_bb20_8;
  TNode<UintPtrT> tmp15;
  TNode<UintPtrT> tmp16;
  TNode<UintPtrT> tmp17;
  TNode<UintPtrT> tmp18;
  TNode<UintPtrT> tmp19;
  TNode<UintPtrT> tmp20;
  TNode<BoolT> tmp21;
  if (block20.is_used()) {
    ca_.Bind(&block20, &phi_bb20_8);
    ca_.SetSourcePosition("../../../src/builtins/typed-array.tq", 50);
    tmp15 = FromConstexpr_uintptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp16 = CodeStubAssembler(state_).WordShl(TNode<UintPtrT>{tmp15}, TNode<UintPtrT>{tmp11});
    tmp17 = FromConstexpr_uintptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp18 = CodeStubAssembler(state_).UintPtrSub(TNode<UintPtrT>{tmp16}, TNode<UintPtrT>{tmp17});
    tmp19 = CodeStubAssembler(state_).WordAnd(TNode<UintPtrT>{tmp13}, TNode<UintPtrT>{tmp18});
    tmp20 = FromConstexpr_uintptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp21 = CodeStubAssembler(state_).WordNotEqual(TNode<UintPtrT>{tmp19}, TNode<UintPtrT>{tmp20});
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 253);
    ca_.Branch(tmp21, &block22, std::vector<compiler::Node*>{phi_bb20_8}, &block23, std::vector<compiler::Node*>{phi_bb20_8});
  }

  TNode<BoolT> phi_bb22_8;
  TNode<String> tmp22;
  if (block22.is_used()) {
    ca_.Bind(&block22, &phi_bb22_8);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 254);
    tmp22 = FromConstexpr_String_constexpr_string_0(state_, "start offset");
    ca_.Goto(&block19, phi_bb22_8, tmp22);
  }

  TNode<BoolT> phi_bb23_8;
  TNode<UintPtrT> tmp23;
  if (block23.is_used()) {
    ca_.Bind(&block23, &phi_bb23_8);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 259);
    compiler::CodeAssemblerLabel label24(&ca_);
    tmp23 = ToIndex_0(state_, TNode<Context>{p_context}, TNode<Object>{p_length}, &label24);
    ca_.Goto(&block25, phi_bb23_8);
    if (label24.is_used()) {
      ca_.Bind(&label24);
      ca_.Goto(&block26, phi_bb23_8);
    }
  }

  TNode<BoolT> phi_bb26_8;
  if (block26.is_used()) {
    ca_.Bind(&block26, &phi_bb26_8);
    ca_.Goto(&block17, phi_bb26_8);
  }

  TNode<BoolT> phi_bb25_8;
  TNode<BoolT> tmp25;
  if (block25.is_used()) {
    ca_.Bind(&block25, &phi_bb25_8);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 263);
    tmp25 = IsDetachedBuffer_0(state_, TNode<JSArrayBuffer>{p_buffer});
    ca_.Branch(tmp25, &block27, std::vector<compiler::Node*>{phi_bb25_8}, &block28, std::vector<compiler::Node*>{phi_bb25_8});
  }

  TNode<BoolT> phi_bb27_8;
  if (block27.is_used()) {
    ca_.Bind(&block27, &phi_bb27_8);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 264);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{p_context}, MessageTemplate::kDetachedOperation, "Construct");
  }

  TNode<BoolT> phi_bb28_8;
  TNode<BoolT> tmp26;
  if (block28.is_used()) {
    ca_.Bind(&block28, &phi_bb28_8);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 269);
    tmp26 = IsResizableArrayBuffer_0(state_, TNode<JSArrayBuffer>{p_buffer});
    ca_.Branch(tmp26, &block31, std::vector<compiler::Node*>{phi_bb28_8}, &block32, std::vector<compiler::Node*>{phi_bb28_8});
  }

  TNode<BoolT> phi_bb31_8;
  TNode<BoolT> tmp27;
  if (block31.is_used()) {
    ca_.Bind(&block31, &phi_bb31_8);
    tmp27 = IsSharedArrayBuffer_0(state_, TNode<JSArrayBuffer>{p_buffer});
    ca_.Goto(&block33, phi_bb31_8, tmp27);
  }

  TNode<BoolT> phi_bb32_8;
  TNode<BoolT> tmp28;
  if (block32.is_used()) {
    ca_.Bind(&block32, &phi_bb32_8);
    tmp28 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block33, phi_bb32_8, tmp28);
  }

  TNode<BoolT> phi_bb33_8;
  TNode<BoolT> phi_bb33_16;
  if (block33.is_used()) {
    ca_.Bind(&block33, &phi_bb33_8, &phi_bb33_16);
    ca_.Branch(phi_bb33_16, &block29, std::vector<compiler::Node*>{phi_bb33_8}, &block30, std::vector<compiler::Node*>{phi_bb33_8});
  }

  TNode<BoolT> phi_bb29_8;
  TNode<Object> tmp29;
  TNode<UintPtrT> tmp30;
  if (block29.is_used()) {
    ca_.Bind(&block29, &phi_bb29_8);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 270);
    tmp29 = CodeStubAssembler(state_).CallRuntime(Runtime::kGrowableSharedArrayBufferByteLength, p_context, p_buffer); 
    compiler::CodeAssemblerLabel label31(&ca_);
    tmp30 = ToIndex_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp29}, &label31);
    ca_.Goto(&block37, phi_bb29_8);
    if (label31.is_used()) {
      ca_.Bind(&label31);
      ca_.Goto(&block38, phi_bb29_8);
    }
  }

  TNode<BoolT> phi_bb38_8;
  if (block38.is_used()) {
    ca_.Bind(&block38, &phi_bb38_8);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 271);
    CodeStubAssembler(state_).PrintErr("halting because of unreachable code at src/builtins/typed-array-createtypedarray.tq:271:21");
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<BoolT> phi_bb37_8;
  if (block37.is_used()) {
    ca_.Bind(&block37, &phi_bb37_8);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 269);
    ca_.Goto(&block34, phi_bb37_8, tmp30);
  }

  TNode<BoolT> phi_bb30_8;
  TNode<UintPtrT> tmp32;
  if (block30.is_used()) {
    ca_.Bind(&block30, &phi_bb30_8);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 273);
    tmp32 = CodeStubAssembler(state_).LoadJSArrayBufferByteLength(TNode<JSArrayBuffer>{p_buffer});
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 269);
    ca_.Goto(&block34, phi_bb30_8, tmp32);
  }

  TNode<BoolT> phi_bb34_8;
  TNode<UintPtrT> phi_bb34_14;
  TNode<Oddball> tmp33;
  TNode<BoolT> tmp34;
  if (block34.is_used()) {
    ca_.Bind(&block34, &phi_bb34_8, &phi_bb34_14);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 277);
    tmp33 = Undefined_0(state_);
    tmp34 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{p_length}, TNode<HeapObject>{tmp33});
    ca_.Branch(tmp34, &block39, std::vector<compiler::Node*>{phi_bb34_8}, &block40, std::vector<compiler::Node*>{phi_bb34_8});
  }

  TNode<BoolT> phi_bb39_8;
  TNode<UintPtrT> tmp35;
  TNode<UintPtrT> tmp36;
  TNode<UintPtrT> tmp37;
  TNode<UintPtrT> tmp38;
  TNode<UintPtrT> tmp39;
  TNode<UintPtrT> tmp40;
  TNode<BoolT> tmp41;
  if (block39.is_used()) {
    ca_.Bind(&block39, &phi_bb39_8);
    ca_.SetSourcePosition("../../../src/builtins/typed-array.tq", 50);
    tmp35 = FromConstexpr_uintptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp36 = CodeStubAssembler(state_).WordShl(TNode<UintPtrT>{tmp35}, TNode<UintPtrT>{tmp11});
    tmp37 = FromConstexpr_uintptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp38 = CodeStubAssembler(state_).UintPtrSub(TNode<UintPtrT>{tmp36}, TNode<UintPtrT>{tmp37});
    tmp39 = CodeStubAssembler(state_).WordAnd(TNode<UintPtrT>{phi_bb34_14}, TNode<UintPtrT>{tmp38});
    tmp40 = FromConstexpr_uintptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp41 = CodeStubAssembler(state_).WordNotEqual(TNode<UintPtrT>{tmp39}, TNode<UintPtrT>{tmp40});
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 280);
    ca_.Branch(tmp41, &block42, std::vector<compiler::Node*>{phi_bb39_8}, &block43, std::vector<compiler::Node*>{phi_bb39_8});
  }

  TNode<BoolT> phi_bb42_8;
  TNode<String> tmp42;
  if (block42.is_used()) {
    ca_.Bind(&block42, &phi_bb42_8);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 281);
    tmp42 = FromConstexpr_String_constexpr_string_0(state_, "byte length");
    ca_.Goto(&block19, phi_bb42_8, tmp42);
  }

  TNode<BoolT> phi_bb43_8;
  TNode<BoolT> tmp43;
  if (block43.is_used()) {
    ca_.Bind(&block43, &phi_bb43_8);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 286);
    tmp43 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{phi_bb34_14}, TNode<UintPtrT>{tmp13});
    ca_.Branch(tmp43, &block45, std::vector<compiler::Node*>{phi_bb43_8}, &block46, std::vector<compiler::Node*>{phi_bb43_8});
  }

  TNode<BoolT> phi_bb45_8;
  if (block45.is_used()) {
    ca_.Bind(&block45, &phi_bb45_8);
    ca_.Goto(&block15, phi_bb45_8);
  }

  TNode<BoolT> phi_bb46_8;
  TNode<UintPtrT> tmp44;
  TNode<UintPtrT> tmp45;
  TNode<UintPtrT> tmp46;
  TNode<BoolT> tmp47;
  if (block46.is_used()) {
    ca_.Bind(&block46, &phi_bb46_8);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 290);
    tmp44 = CodeStubAssembler(state_).UintPtrSub(TNode<UintPtrT>{phi_bb34_14}, TNode<UintPtrT>{tmp13});
    ca_.SetSourcePosition("../../../src/builtins/typed-array.tq", 38);
    tmp45 = CodeStubAssembler(state_).WordShr(TNode<UintPtrT>{tmp44}, TNode<UintPtrT>{tmp11});
    ca_.SetSourcePosition("../../../src/builtins/typed-array.tq", 39);
    tmp46 = FromConstexpr_uintptr_constexpr_uintptr_0(state_, JSTypedArray::kMaxLength);
    tmp47 = CodeStubAssembler(state_).UintPtrGreaterThan(TNode<UintPtrT>{tmp45}, TNode<UintPtrT>{tmp46});
    ca_.Branch(tmp47, &block48, std::vector<compiler::Node*>{phi_bb46_8}, &block49, std::vector<compiler::Node*>{phi_bb46_8});
  }

  TNode<BoolT> phi_bb48_8;
  if (block48.is_used()) {
    ca_.Bind(&block48, &phi_bb48_8);
    ca_.Goto(&block17, phi_bb48_8);
  }

  TNode<BoolT> phi_bb49_8;
  if (block49.is_used()) {
    ca_.Bind(&block49, &phi_bb49_8);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 277);
    ca_.Goto(&block41, phi_bb49_8, tmp45, tmp44);
  }

  TNode<BoolT> phi_bb40_8;
  TNode<UintPtrT> tmp48;
  TNode<BoolT> tmp49;
  if (block40.is_used()) {
    ca_.Bind(&block40, &phi_bb40_8);
    ca_.SetSourcePosition("../../../src/builtins/typed-array.tq", 28);
    tmp48 = FromConstexpr_uintptr_constexpr_uintptr_0(state_, JSTypedArray::kMaxLength);
    tmp49 = CodeStubAssembler(state_).UintPtrGreaterThan(TNode<UintPtrT>{tmp23}, TNode<UintPtrT>{tmp48});
    ca_.Branch(tmp49, &block51, std::vector<compiler::Node*>{phi_bb40_8}, &block52, std::vector<compiler::Node*>{phi_bb40_8});
  }

  TNode<BoolT> phi_bb51_8;
  if (block51.is_used()) {
    ca_.Bind(&block51, &phi_bb51_8);
    ca_.Goto(&block17, phi_bb51_8);
  }

  TNode<BoolT> phi_bb52_8;
  TNode<UintPtrT> tmp50;
  TNode<UintPtrT> tmp51;
  TNode<BoolT> tmp52;
  if (block52.is_used()) {
    ca_.Bind(&block52, &phi_bb52_8);
    ca_.SetSourcePosition("../../../src/builtins/typed-array.tq", 29);
    tmp50 = FromConstexpr_uintptr_constexpr_uintptr_0(state_, JSArrayBuffer::kMaxByteLength);
    tmp51 = CodeStubAssembler(state_).WordShr(TNode<UintPtrT>{tmp50}, TNode<UintPtrT>{tmp11});
    ca_.SetSourcePosition("../../../src/builtins/typed-array.tq", 30);
    tmp52 = CodeStubAssembler(state_).UintPtrGreaterThan(TNode<UintPtrT>{tmp23}, TNode<UintPtrT>{tmp51});
    ca_.Branch(tmp52, &block53, std::vector<compiler::Node*>{phi_bb52_8}, &block54, std::vector<compiler::Node*>{phi_bb52_8});
  }

  TNode<BoolT> phi_bb53_8;
  if (block53.is_used()) {
    ca_.Bind(&block53, &phi_bb53_8);
    ca_.Goto(&block17, phi_bb53_8);
  }

  TNode<BoolT> phi_bb54_8;
  TNode<UintPtrT> tmp53;
  TNode<BoolT> tmp54;
  if (block54.is_used()) {
    ca_.Bind(&block54, &phi_bb54_8);
    ca_.SetSourcePosition("../../../src/builtins/typed-array.tq", 31);
    tmp53 = CodeStubAssembler(state_).WordShl(TNode<UintPtrT>{tmp23}, TNode<UintPtrT>{tmp11});
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 302);
    tmp54 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{phi_bb34_14}, TNode<UintPtrT>{tmp53});
    ca_.Branch(tmp54, &block57, std::vector<compiler::Node*>{phi_bb54_8}, &block58, std::vector<compiler::Node*>{phi_bb54_8});
  }

  TNode<BoolT> phi_bb57_8;
  TNode<BoolT> tmp55;
  if (block57.is_used()) {
    ca_.Bind(&block57, &phi_bb57_8);
    tmp55 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block59, phi_bb57_8, tmp55);
  }

  TNode<BoolT> phi_bb58_8;
  TNode<UintPtrT> tmp56;
  TNode<BoolT> tmp57;
  if (block58.is_used()) {
    ca_.Bind(&block58, &phi_bb58_8);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 303);
    tmp56 = CodeStubAssembler(state_).UintPtrSub(TNode<UintPtrT>{phi_bb34_14}, TNode<UintPtrT>{tmp53});
    tmp57 = CodeStubAssembler(state_).UintPtrGreaterThan(TNode<UintPtrT>{tmp13}, TNode<UintPtrT>{tmp56});
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 302);
    ca_.Goto(&block59, phi_bb58_8, tmp57);
  }

  TNode<BoolT> phi_bb59_8;
  TNode<BoolT> phi_bb59_16;
  if (block59.is_used()) {
    ca_.Bind(&block59, &phi_bb59_8, &phi_bb59_16);
    ca_.Branch(phi_bb59_16, &block55, std::vector<compiler::Node*>{phi_bb59_8}, &block56, std::vector<compiler::Node*>{phi_bb59_8});
  }

  TNode<BoolT> phi_bb55_8;
  if (block55.is_used()) {
    ca_.Bind(&block55, &phi_bb55_8);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 304);
    ca_.Goto(&block17, phi_bb55_8);
  }

  TNode<BoolT> phi_bb56_8;
  if (block56.is_used()) {
    ca_.Bind(&block56, &phi_bb56_8);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 277);
    ca_.Goto(&block41, phi_bb56_8, tmp23, tmp53);
  }

  TNode<BoolT> phi_bb41_8;
  TNode<UintPtrT> phi_bb41_12;
  TNode<UintPtrT> phi_bb41_13;
  TNode<JSTypedArray> tmp58;
  if (block41.is_used()) {
    ca_.Bind(&block41, &phi_bb41_8, &phi_bb41_12, &phi_bb41_13);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 308);
    tmp58 = AllocateTypedArray_0(state_, TNode<Context>{p_context}, false, TNode<Map>{phi_bb13_6}, TNode<JSArrayBuffer>{p_buffer}, TNode<UintPtrT>{tmp13}, TNode<UintPtrT>{phi_bb41_13}, TNode<UintPtrT>{phi_bb41_12}, TNode<BoolT>{phi_bb4_8});
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 227);
    ca_.Goto(&block60);
  }

  TNode<BoolT> phi_bb19_8;
  TNode<String> phi_bb19_11;
  if (block19.is_used()) {
    ca_.Bind(&block19, &phi_bb19_8, &phi_bb19_11);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 312);
    CodeStubAssembler(state_).CallRuntime(Runtime::kThrowInvalidTypedArrayAlignment, p_context, phi_bb13_6, phi_bb19_11);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<BoolT> phi_bb17_8;
  if (block17.is_used()) {
    ca_.Bind(&block17, &phi_bb17_8);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 314);
    CodeStubAssembler(state_).ThrowRangeError(TNode<Context>{p_context}, MessageTemplate::kInvalidTypedArrayLength, TNode<Object>{p_length});
  }

  TNode<BoolT> phi_bb15_8;
  if (block15.is_used()) {
    ca_.Bind(&block15, &phi_bb15_8);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 316);
    CodeStubAssembler(state_).ThrowRangeError(TNode<Context>{p_context}, MessageTemplate::kInvalidOffset, TNode<Object>{p_byteOffset});
  }

    ca_.Bind(&block60);
  return TNode<JSTypedArray>{tmp58};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/typed-array-createtypedarray.tq?l=322&c=1
TNode<JSTypedArray> TypedArrayCreateByLength_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSReceiver> p_constructor, TNode<Number> p_length, const char* p_methodName) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<BoolT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 326);
    tmp0 = CodeStubAssembler(state_).IsSafeInteger(TNode<Object>{p_length});
    ca_.Branch(tmp0, &block2, std::vector<compiler::Node*>{}, &block3, std::vector<compiler::Node*>{});
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/typed-array-createtypedarray.tq", 326});
      CodeStubAssembler(state_).FailAssert("Torque assert 'IsSafeInteger(length)' failed", pos_stack);
    }
  }

  TNode<JSReceiver> tmp1;
  TNode<UintPtrT> tmp2;
  TNode<JSTypedArray> tmp3;
  TNode<IntPtrT> tmp4;
  TNode<Uint32T> tmp5;
  TNode<BoolT> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<JSArrayBuffer> tmp8;
  TNode<BoolT> tmp9;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 329);
    tmp1 = CodeStubAssembler(state_).Construct(TNode<Context>{p_context}, TNode<JSReceiver>{p_constructor}, TNode<Object>{p_length});
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 334);
    tmp2 = TypedArrayBuiltinsAssembler(state_).ValidateTypedArrayAndGetLength(TNode<Context>{p_context}, TNode<Object>{tmp1}, p_methodName);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 336);
    tmp3 = UnsafeCast_JSTypedArray_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp1});
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 339);
    tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 32);
    tmp5 = CodeStubAssembler(state_).LoadReference<Uint32T>(CodeStubAssembler::Reference{tmp3, tmp4});
    tmp6 = ca_.UncheckedCast<BoolT>(CodeStubAssembler(state_).DecodeWord32<base::BitField<bool, 1, 1, uint32_t>>(ca_.UncheckedCast<Word32T>(tmp5)));
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 340);
    tmp7 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp8 = CodeStubAssembler(state_).LoadReference<JSArrayBuffer>(CodeStubAssembler::Reference{tmp3, tmp7});
    tmp9 = IsResizableArrayBuffer_0(state_, TNode<JSArrayBuffer>{tmp8});
    ca_.Branch(tmp9, &block6, std::vector<compiler::Node*>{}, &block7, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp10;
  TNode<JSArrayBuffer> tmp11;
  TNode<BoolT> tmp12;
  TNode<BoolT> tmp13;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 341);
    tmp10 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp11 = CodeStubAssembler(state_).LoadReference<JSArrayBuffer>(CodeStubAssembler::Reference{tmp3, tmp10});
    tmp12 = IsSharedArrayBuffer_0(state_, TNode<JSArrayBuffer>{tmp11});
    tmp13 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp12});
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 340);
    ca_.Goto(&block8, tmp13);
  }

  TNode<BoolT> tmp14;
  if (block7.is_used()) {
    ca_.Bind(&block7);
    tmp14 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block8, tmp14);
  }

  TNode<BoolT> phi_bb8_8;
  TNode<BoolT> tmp15;
  if (block8.is_used()) {
    ca_.Bind(&block8, &phi_bb8_8);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 339);
    tmp15 = CodeStubAssembler(state_).Word32Equal(TNode<BoolT>{tmp6}, TNode<BoolT>{phi_bb8_8});
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 338);
    ca_.Branch(tmp15, &block4, std::vector<compiler::Node*>{}, &block5, std::vector<compiler::Node*>{});
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/typed-array-createtypedarray.tq", 338});
      CodeStubAssembler(state_).FailAssert("Torque assert 'newTypedArray.bit_field.is_backed_by_rab == (IsResizableArrayBuffer(newTypedArray.buffer) && !IsSharedArrayBuffer(newTypedArray.buffer))' failed", pos_stack);
    }
  }

  TNode<IntPtrT> tmp16;
  TNode<Uint32T> tmp17;
  TNode<BoolT> tmp18;
  TNode<BoolT> tmp19;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 343);
    tmp16 = FromConstexpr_intptr_constexpr_int31_0(state_, 32);
    tmp17 = CodeStubAssembler(state_).LoadReference<Uint32T>(CodeStubAssembler::Reference{tmp3, tmp16});
    tmp18 = ca_.UncheckedCast<BoolT>(CodeStubAssembler(state_).DecodeWord32<base::BitField<bool, 0, 1, uint32_t>>(ca_.UncheckedCast<Word32T>(tmp17)));
    tmp19 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp18});
    ca_.Branch(tmp19, &block11, std::vector<compiler::Node*>{}, &block12, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp20;
  if (block11.is_used()) {
    ca_.Bind(&block11);
    tmp20 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block13, tmp20);
  }

  TNode<IntPtrT> tmp21;
  TNode<JSArrayBuffer> tmp22;
  TNode<BoolT> tmp23;
  if (block12.is_used()) {
    ca_.Bind(&block12);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 344);
    tmp21 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp22 = CodeStubAssembler(state_).LoadReference<JSArrayBuffer>(CodeStubAssembler::Reference{tmp3, tmp21});
    tmp23 = IsResizableArrayBuffer_0(state_, TNode<JSArrayBuffer>{tmp22});
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 343);
    ca_.Goto(&block13, tmp23);
  }

  TNode<BoolT> phi_bb13_7;
  if (block13.is_used()) {
    ca_.Bind(&block13, &phi_bb13_7);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 342);
    ca_.Branch(phi_bb13_7, &block9, std::vector<compiler::Node*>{}, &block10, std::vector<compiler::Node*>{});
  }

  if (block10.is_used()) {
    ca_.Bind(&block10);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/typed-array-createtypedarray.tq", 342});
      CodeStubAssembler(state_).FailAssert("Torque assert '!newTypedArray.bit_field.is_length_tracking || IsResizableArrayBuffer(newTypedArray.buffer)' failed", pos_stack);
    }
  }

  TNode<IntPtrT> tmp24;
  TNode<JSArrayBuffer> tmp25;
  TNode<BoolT> tmp26;
  if (block9.is_used()) {
    ca_.Bind(&block9);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 346);
    tmp24 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp25 = CodeStubAssembler(state_).LoadReference<JSArrayBuffer>(CodeStubAssembler::Reference{tmp3, tmp24});
    tmp26 = IsDetachedBuffer_0(state_, TNode<JSArrayBuffer>{tmp25});
    ca_.Branch(tmp26, &block14, std::vector<compiler::Node*>{}, &block15, std::vector<compiler::Node*>{});
  }

  if (block14.is_used()) {
    ca_.Bind(&block14);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 347);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{p_context}, MessageTemplate::kDetachedOperation, p_methodName);
  }

  TNode<UintPtrT> tmp27;
  TNode<BoolT> tmp28;
  if (block15.is_used()) {
    ca_.Bind(&block15);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 353);
    tmp27 = Convert_uintptr_Number_0(state_, TNode<Number>{p_length});
    tmp28 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp2}, TNode<UintPtrT>{tmp27});
    ca_.Branch(tmp28, &block16, std::vector<compiler::Node*>{}, &block17, std::vector<compiler::Node*>{});
  }

  if (block16.is_used()) {
    ca_.Bind(&block16);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 354);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{p_context}, MessageTemplate::kTypedArrayTooShort);
  }

  if (block17.is_used()) {
    ca_.Bind(&block17);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 322);
    ca_.Goto(&block18);
  }

    ca_.Bind(&block18);
  return TNode<JSTypedArray>{tmp3};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/typed-array-createtypedarray.tq?l=361&c=1
void ConstructByJSReceiver_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSReceiver> p_obj, compiler::CodeAssemblerLabel* label_IfConstructByArrayLike, compiler::TypedCodeAssemblerVariable<JSReceiver>* label_IfConstructByArrayLike_parameter_0, compiler::TypedCodeAssemblerVariable<UintPtrT>* label_IfConstructByArrayLike_parameter_1, compiler::CodeAssemblerLabel* label_IfIteratorNotCallable, compiler::TypedCodeAssemblerVariable<Object>* label_IfIteratorNotCallable_parameter_0) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSReceiver, UintPtrT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Symbol> tmp0;
  TNode<JSReceiver> tmp1;
    compiler::TypedCodeAssemblerVariable<Object> tmp4(&ca_);
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 368);
    tmp0 = CodeStubAssembler(state_).IteratorSymbolConstant();
    compiler::CodeAssemblerLabel label2(&ca_);
    compiler::CodeAssemblerLabel label3(&ca_);
    tmp1 = GetMethod_0(state_, TNode<Context>{p_context}, TNode<Object>{p_obj}, TNode<Name>{tmp0}, &label2, &label3, &tmp4);
    ca_.Goto(&block7);
    if (label2.is_used()) {
      ca_.Bind(&label2);
      ca_.Goto(&block8);
    }
    if (label3.is_used()) {
      ca_.Bind(&label3);
      ca_.Goto(&block9);
    }
  }

  TNode<String> tmp5;
  TNode<Object> tmp6;
  TNode<Number> tmp7;
  TNode<UintPtrT> tmp8;
  if (block8.is_used()) {
    ca_.Bind(&block8);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 373);
    tmp5 = kLengthString_0(state_);
    tmp6 = CodeStubAssembler(state_).GetProperty(TNode<Context>{p_context}, TNode<Object>{p_obj}, TNode<Object>{tmp5});
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 374);
    tmp7 = CodeStubAssembler(state_).ToLength_Inline(TNode<Context>{p_context}, TNode<Object>{tmp6});
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 378);
    compiler::CodeAssemblerLabel label9(&ca_);
    tmp8 = ChangeSafeIntegerNumberToUintPtr_0(state_, TNode<Number>{tmp7}, &label9);
    ca_.Goto(&block13);
    if (label9.is_used()) {
      ca_.Bind(&label9);
      ca_.Goto(&block14);
    }
  }

  if (block9.is_used()) {
    ca_.Bind(&block9);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 361);
    *label_IfIteratorNotCallable_parameter_0 = tmp4.value();
    ca_.Goto(label_IfIteratorNotCallable);
  }

    compiler::TypedCodeAssemblerVariable<JSArray> tmp11(&ca_);
    compiler::TypedCodeAssemblerVariable<UintPtrT> tmp12(&ca_);
  if (block7.is_used()) {
    ca_.Bind(&block7);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 370);
    compiler::CodeAssemblerLabel label10(&ca_);
    ConstructByIterable_0(state_, TNode<Context>{p_context}, TNode<JSReceiver>{p_obj}, TNode<JSReceiver>{tmp1}, &label10, &tmp11, &tmp12);
    if (label10.is_used()) {
      ca_.Bind(&label10);
      ca_.Goto(&block10);
    }
  }

  if (block10.is_used()) {
    ca_.Bind(&block10);
    ca_.Goto(&block1, tmp11.value(), tmp12.value());
  }

  if (block14.is_used()) {
    ca_.Bind(&block14);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 382);
    CodeStubAssembler(state_).ThrowRangeError(TNode<Context>{p_context}, MessageTemplate::kInvalidTypedArrayLength, TNode<Object>{tmp7});
  }

  if (block13.is_used()) {
    ca_.Bind(&block13);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 380);
    ca_.Goto(&block1, p_obj, tmp8);
  }

  TNode<JSReceiver> phi_bb1_0;
  TNode<UintPtrT> phi_bb1_1;
  if (block1.is_used()) {
    ca_.Bind(&block1, &phi_bb1_0, &phi_bb1_1);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 361);
    *label_IfConstructByArrayLike_parameter_1 = phi_bb1_1;
    *label_IfConstructByArrayLike_parameter_0 = phi_bb1_0;
    ca_.Goto(label_IfConstructByArrayLike);
  }
}

TF_BUILTIN(CreateTypedArray, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedParameter<Context>(Descriptor::kContext);
  USE(parameter0);
  TNode<JSFunction> parameter1 = UncheckedParameter<JSFunction>(Descriptor::kTarget);
  USE(parameter1);
  TNode<JSReceiver> parameter2 = UncheckedParameter<JSReceiver>(Descriptor::kNewTarget);
  USE(parameter2);
  TNode<Object> parameter3 = UncheckedParameter<Object>(Descriptor::kArg1);
  USE(parameter3);
  TNode<Object> parameter4 = UncheckedParameter<Object>(Descriptor::kArg2);
  USE(parameter4);
  TNode<Object> parameter5 = UncheckedParameter<Object>(Descriptor::kArg3);
  USE(parameter5);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block25(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block26(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block27(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSReceiver, UintPtrT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<BoolT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 391);
    tmp0 = CodeStubAssembler(state_).IsConstructor(TNode<HeapObject>{parameter1});
    ca_.Branch(tmp0, &block1, std::vector<compiler::Node*>{}, &block2, std::vector<compiler::Node*>{});
  }

  if (block2.is_used()) {
    ca_.Bind(&block2);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/typed-array-createtypedarray.tq", 391});
      CodeStubAssembler(state_).FailAssert("Torque assert 'IsConstructor(target)' failed", pos_stack);
    }
  }

  TNode<Smi> tmp1;
  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 396);
    compiler::CodeAssemblerLabel label2(&ca_);
    tmp1 = Cast_Smi_0(state_, TNode<Object>{parameter3}, &label2);
    ca_.Goto(&block11);
    if (label2.is_used()) {
      ca_.Bind(&label2);
      ca_.Goto(&block12);
    }
  }

  TNode<JSArrayBuffer> tmp3;
  if (block12.is_used()) {
    ca_.Bind(&block12);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 399);
    compiler::CodeAssemblerLabel label4(&ca_);
    tmp3 = Cast_JSArrayBuffer_0(state_, TNode<HeapObject>{ca_.UncheckedCast<HeapObject>(parameter3)}, &label4);
    ca_.Goto(&block15);
    if (label4.is_used()) {
      ca_.Bind(&label4);
      ca_.Goto(&block16);
    }
  }

  if (block11.is_used()) {
    ca_.Bind(&block11);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 397);
    ca_.Goto(&block8, tmp1);
  }

  TNode<JSTypedArray> tmp5;
  if (block16.is_used()) {
    ca_.Bind(&block16);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 402);
    compiler::CodeAssemblerLabel label6(&ca_);
    tmp5 = Cast_JSTypedArray_0(state_, TNode<HeapObject>{ca_.UncheckedCast<HeapObject>(parameter3)}, &label6);
    ca_.Goto(&block19);
    if (label6.is_used()) {
      ca_.Bind(&label6);
      ca_.Goto(&block20);
    }
  }

  TNode<JSTypedArray> tmp7;
  if (block15.is_used()) {
    ca_.Bind(&block15);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 400);
    tmp7 = ConstructByArrayBuffer_0(state_, TNode<Context>{parameter0}, TNode<JSFunction>{parameter1}, TNode<JSReceiver>{parameter2}, TNode<JSArrayBuffer>{tmp3}, TNode<Object>{parameter4}, TNode<Object>{parameter5});
    CodeStubAssembler(state_).Return(tmp7);
  }

  TNode<JSReceiver> tmp8;
  if (block20.is_used()) {
    ca_.Bind(&block20);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 405);
    compiler::CodeAssemblerLabel label9(&ca_);
    tmp8 = Cast_JSReceiver_0(state_, TNode<HeapObject>{ca_.UncheckedCast<HeapObject>(parameter3)}, &label9);
    ca_.Goto(&block24);
    if (label9.is_used()) {
      ca_.Bind(&label9);
      ca_.Goto(&block25);
    }
  }

    compiler::TypedCodeAssemblerVariable<JSTypedArray> tmp11(&ca_);
    compiler::TypedCodeAssemblerVariable<UintPtrT> tmp12(&ca_);
  if (block19.is_used()) {
    ca_.Bind(&block19);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 403);
    compiler::CodeAssemblerLabel label10(&ca_);
    ConstructByTypedArray_0(state_, TNode<Context>{parameter0}, TNode<JSTypedArray>{tmp5}, &label10, &tmp11, &tmp12);
    if (label10.is_used()) {
      ca_.Bind(&label10);
      ca_.Goto(&block21);
    }
  }

  if (block21.is_used()) {
    ca_.Bind(&block21);
    ca_.Goto(&block6, tmp11.value(), tmp12.value());
  }

  if (block25.is_used()) {
    ca_.Bind(&block25);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 412);
    ca_.Goto(&block8, ca_.UncheckedCast<PrimitiveHeapObject>(parameter3));
  }

    compiler::TypedCodeAssemblerVariable<JSReceiver> tmp14(&ca_);
    compiler::TypedCodeAssemblerVariable<UintPtrT> tmp15(&ca_);
    compiler::TypedCodeAssemblerVariable<Object> tmp17(&ca_);
  if (block24.is_used()) {
    ca_.Bind(&block24);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 406);
    compiler::CodeAssemblerLabel label13(&ca_);
    compiler::CodeAssemblerLabel label16(&ca_);
    ConstructByJSReceiver_0(state_, TNode<Context>{parameter0}, TNode<JSReceiver>{tmp8}, &label13, &tmp14, &tmp15, &label16, &tmp17);
    if (label13.is_used()) {
      ca_.Bind(&label13);
      ca_.Goto(&block26);
    }
    if (label16.is_used()) {
      ca_.Bind(&label16);
      ca_.Goto(&block27);
    }
  }

  if (block26.is_used()) {
    ca_.Bind(&block26);
    ca_.Goto(&block6, tmp14.value(), tmp15.value());
  }

  if (block27.is_used()) {
    ca_.Bind(&block27);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 429);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{parameter0}, MessageTemplate::kFirstArgumentIteratorSymbolNonCallable, "TypedArray\'s constructor");
  }

  TNode<Object> phi_bb8_6;
  TNode<Map> tmp18;
  TNode<UintPtrT> tmp19;
  TNode<Int32T> tmp20;
  TNode<JSTypedArray> tmp21;
  if (block8.is_used()) {
    ca_.Bind(&block8, &phi_bb8_6);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 416);
    tmp18 = GetDerivedMap_0(state_, TNode<Context>{parameter0}, TNode<JSFunction>{parameter1}, TNode<JSReceiver>{parameter2});
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 419);
    std::tie(tmp19, tmp20) = TypedArrayBuiltinsAssembler(state_).GetTypedArrayElementsInfo(TNode<Map>{tmp18}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 421);
    tmp21 = ConstructByLength_0(state_, TNode<Context>{parameter0}, TNode<Map>{tmp18}, TNode<Object>{phi_bb8_6}, TorqueStructTypedArrayElementsInfo{TNode<UintPtrT>{tmp19}, TNode<Int32T>{tmp20}});
    CodeStubAssembler(state_).Return(tmp21);
  }

  TNode<JSReceiver> phi_bb6_6;
  TNode<UintPtrT> phi_bb6_7;
  TNode<Map> tmp22;
  TNode<UintPtrT> tmp23;
  TNode<Int32T> tmp24;
  TNode<JSTypedArray> tmp25;
  if (block6.is_used()) {
    ca_.Bind(&block6, &phi_bb6_6, &phi_bb6_7);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 423);
    tmp22 = GetDerivedMap_0(state_, TNode<Context>{parameter0}, TNode<JSFunction>{parameter1}, TNode<JSReceiver>{parameter2});
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 426);
    std::tie(tmp23, tmp24) = TypedArrayBuiltinsAssembler(state_).GetTypedArrayElementsInfo(TNode<Map>{tmp22}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 427);
    tmp25 = ConstructByArrayLike_0(state_, TNode<Context>{parameter0}, TNode<Map>{tmp22}, TNode<HeapObject>{phi_bb6_6}, TNode<UintPtrT>{phi_bb6_7}, TorqueStructTypedArrayElementsInfo{TNode<UintPtrT>{tmp23}, TNode<Int32T>{tmp24}});
    CodeStubAssembler(state_).Return(tmp25);
  }
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/typed-array-createtypedarray.tq?l=435&c=1
TNode<JSTypedArray> TypedArraySpeciesCreate_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, const char* p_methodName, int31_t p_numArgs, TNode<JSTypedArray> p_exemplar, TNode<Object> p_arg0, TNode<Object> p_arg1, TNode<Object> p_arg2) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block18(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSTypedArray> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSTypedArray> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<JSFunction> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<Map> tmp2;
  TNode<BoolT> tmp3;
  TNode<BoolT> tmp4;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 439);
    tmp0 = TypedArrayBuiltinsAssembler(state_).GetDefaultConstructor(TNode<Context>{p_context}, TNode<JSTypedArray>{p_exemplar});
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 442);
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp2 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference{p_exemplar, tmp1});
    tmp3 = CodeStubAssembler(state_).IsPrototypeTypedArrayPrototype(TNode<Context>{p_context}, TNode<Map>{tmp2});
    tmp4 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp3});
    ca_.Branch(tmp4, &block4, std::vector<compiler::Node*>{}, &block5, std::vector<compiler::Node*>{});
  }

  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.Goto(&block3);
  }

  TNode<BoolT> tmp5;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 443);
    tmp5 = CodeStubAssembler(state_).IsTypedArraySpeciesProtectorCellInvalid();
    ca_.Branch(tmp5, &block6, std::vector<compiler::Node*>{}, &block7, std::vector<compiler::Node*>{});
  }

  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.Goto(&block3);
  }

  TNode<JSTypedArray> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<JSArrayBuffer> tmp8;
  TNode<BoolT> tmp9;
  TNode<BoolT> tmp10;
  if (block7.is_used()) {
    ca_.Bind(&block7);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 445);
    tmp6 = ca_.CallStub<JSTypedArray>(Builtins::CallableFor(ca_.isolate(), Builtin::kCreateTypedArray), p_context, tmp0, tmp0, p_arg0, p_arg1, p_arg2);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 450);
    tmp7 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp8 = CodeStubAssembler(state_).LoadReference<JSArrayBuffer>(CodeStubAssembler::Reference{tmp6, tmp7});
    tmp9 = IsDetachedBuffer_0(state_, TNode<JSArrayBuffer>{tmp8});
    tmp10 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp9});
    ca_.Branch(tmp10, &block8, std::vector<compiler::Node*>{}, &block9, std::vector<compiler::Node*>{});
  }

  if (block9.is_used()) {
    ca_.Bind(&block9);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/typed-array-createtypedarray.tq", 450});
      CodeStubAssembler(state_).FailAssert("Torque assert '!IsDetachedBuffer(typedArray.buffer)' failed", pos_stack);
    }
  }

  if (block8.is_used()) {
    ca_.Bind(&block8);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 452);
    ca_.Goto(&block1, tmp6);
  }

  TNode<JSReceiver> tmp11;
  TNode<JSReceiver> tmp12;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 455);
    tmp11 = CodeStubAssembler(state_).SpeciesConstructor(TNode<Context>{p_context}, TNode<Object>{p_exemplar}, TNode<JSReceiver>{tmp0});
    compiler::CodeAssemblerLabel label13(&ca_);
    tmp12 = Cast_Constructor_0(state_, TNode<HeapObject>{tmp11}, &label13);
    ca_.Goto(&block12);
    if (label13.is_used()) {
      ca_.Bind(&label13);
      ca_.Goto(&block13);
    }
  }

  if (block13.is_used()) {
    ca_.Bind(&block13);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 456);
    CodeStubAssembler(state_).PrintErr("halting because of unreachable code at src/builtins/typed-array-createtypedarray.tq:456:19");
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<Oddball> tmp14;
  if (block12.is_used()) {
    ca_.Bind(&block12);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 460);
    tmp14 = Undefined_0(state_);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 461);
    if (((CodeStubAssembler(state_).ConstexprInt31Equal(p_numArgs, (FromConstexpr_constexpr_int31_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull))))))) {
      ca_.Goto(&block14);
    } else {
      ca_.Goto(&block15);
    }
  }

  TNode<JSReceiver> tmp15;
  if (block14.is_used()) {
    ca_.Bind(&block14);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 462);
    tmp15 = CodeStubAssembler(state_).Construct(TNode<Context>{p_context}, TNode<JSReceiver>{tmp12}, TNode<Object>{p_arg0});
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 461);
    ca_.Goto(&block16, tmp15);
  }

  TNode<BoolT> tmp16;
  if (block15.is_used()) {
    ca_.Bind(&block15);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 464);
    tmp16 = FromConstexpr_bool_constexpr_bool_0(state_, (CodeStubAssembler(state_).ConstexprInt31Equal(p_numArgs, (FromConstexpr_constexpr_int31_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x3ull))))));
    ca_.Branch(tmp16, &block17, std::vector<compiler::Node*>{}, &block18, std::vector<compiler::Node*>{});
  }

  if (block18.is_used()) {
    ca_.Bind(&block18);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/typed-array-createtypedarray.tq", 464});
      CodeStubAssembler(state_).FailAssert("Torque assert 'numArgs == 3' failed", pos_stack);
    }
  }

  TNode<JSReceiver> tmp17;
  if (block17.is_used()) {
    ca_.Bind(&block17);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 465);
    tmp17 = CodeStubAssembler(state_).Construct(TNode<Context>{p_context}, TNode<JSReceiver>{tmp12}, TNode<Object>{p_arg0}, TNode<Object>{p_arg1}, TNode<Object>{p_arg2});
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 461);
    ca_.Goto(&block16, tmp17);
  }

  TNode<Object> phi_bb16_7;
  TNode<JSTypedArray> tmp18;
  if (block16.is_used()) {
    ca_.Bind(&block16, &phi_bb16_7);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 468);
    tmp18 = TypedArrayBuiltinsAssembler(state_).ValidateTypedArray(TNode<Context>{p_context}, TNode<Object>{phi_bb16_7}, p_methodName);
    ca_.Goto(&block1, tmp18);
  }

  TNode<JSTypedArray> phi_bb1_5;
  if (block1.is_used()) {
    ca_.Bind(&block1, &phi_bb1_5);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 435);
    ca_.Goto(&block19, phi_bb1_5);
  }

  TNode<JSTypedArray> phi_bb19_5;
    ca_.Bind(&block19, &phi_bb19_5);
  return TNode<JSTypedArray>{phi_bb19_5};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/typed-array-createtypedarray.tq?l=472&c=1
TNode<JSTypedArray> TypedArraySpeciesCreateByLength_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, const char* p_methodName, TNode<JSTypedArray> p_exemplar, TNode<UintPtrT> p_length) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Number> tmp0;
  TNode<Oddball> tmp1;
  TNode<Oddball> tmp2;
  TNode<JSTypedArray> tmp3;
  TNode<UintPtrT> tmp4;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 479);
    tmp0 = Convert_Number_uintptr_0(state_, TNode<UintPtrT>{p_length});
    tmp1 = Undefined_0(state_);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 480);
    tmp2 = Undefined_0(state_);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 478);
    tmp3 = TypedArraySpeciesCreate_0(state_, TNode<Context>{p_context}, p_methodName, (FromConstexpr_constexpr_int31_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull))), TNode<JSTypedArray>{p_exemplar}, TNode<Object>{tmp0}, TNode<Object>{tmp1}, TNode<Object>{tmp2});
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 483);
    compiler::CodeAssemblerLabel label5(&ca_);
    tmp4 = CodeStubAssembler(state_).LoadJSTypedArrayLengthAndCheckDetached(TNode<JSTypedArray>{tmp3}, &label5);
    ca_.Goto(&block4);
    if (label5.is_used()) {
      ca_.Bind(&label5);
      ca_.Goto(&block5);
    }
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 489);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{p_context}, MessageTemplate::kTypedArrayTooShort);
  }

  TNode<BoolT> tmp6;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 485);
    tmp6 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp4}, TNode<UintPtrT>{p_length});
    ca_.Branch(tmp6, &block6, std::vector<compiler::Node*>{}, &block7, std::vector<compiler::Node*>{});
  }

  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 486);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{p_context}, MessageTemplate::kTypedArrayTooShort);
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 472);
    ca_.Goto(&block8);
  }

    ca_.Bind(&block8);
  return TNode<JSTypedArray>{tmp3};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/typed-array-createtypedarray.tq?l=494&c=1
TNode<JSTypedArray> TypedArraySpeciesCreateByBuffer_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, const char* p_methodName, TNode<JSTypedArray> p_exemplar, TNode<JSArrayBuffer> p_buffer, TNode<UintPtrT> p_beginByteOffset, TNode<Object> p_newLength) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Number> tmp0;
  TNode<JSTypedArray> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 500);
    tmp0 = Convert_Number_uintptr_0(state_, TNode<UintPtrT>{p_beginByteOffset});
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 499);
    tmp1 = TypedArraySpeciesCreate_0(state_, TNode<Context>{p_context}, p_methodName, (FromConstexpr_constexpr_int31_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x3ull))), TNode<JSTypedArray>{p_exemplar}, TNode<Object>{p_buffer}, TNode<Object>{tmp0}, TNode<Object>{p_newLength});
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 494);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<JSTypedArray>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/typed-array-createtypedarray.tq?l=505&c=1
TNode<JSTypedArray> TypedArrayCreateSameType_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSTypedArray> p_exemplar, TNode<UintPtrT> p_newLength) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<JSFunction> tmp0;
  TNode<Number> tmp1;
  TNode<Oddball> tmp2;
  TNode<Oddball> tmp3;
  TNode<JSTypedArray> tmp4;
  TNode<IntPtrT> tmp5;
  TNode<JSArrayBuffer> tmp6;
  TNode<BoolT> tmp7;
  TNode<BoolT> tmp8;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 507);
    tmp0 = TypedArrayBuiltinsAssembler(state_).GetDefaultConstructor(TNode<Context>{p_context}, TNode<JSTypedArray>{p_exemplar});
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 509);
    tmp1 = Convert_Number_uintptr_0(state_, TNode<UintPtrT>{p_newLength});
    tmp2 = Undefined_0(state_);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 510);
    tmp3 = Undefined_0(state_);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 508);
    tmp4 = ca_.CallStub<JSTypedArray>(Builtins::CallableFor(ca_.isolate(), Builtin::kCreateTypedArray), p_context, tmp0, tmp0, tmp1, tmp2, tmp3);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 511);
    tmp5 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp6 = CodeStubAssembler(state_).LoadReference<JSArrayBuffer>(CodeStubAssembler::Reference{tmp4, tmp5});
    tmp7 = IsDetachedBuffer_0(state_, TNode<JSArrayBuffer>{tmp6});
    tmp8 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp7});
    ca_.Branch(tmp8, &block2, std::vector<compiler::Node*>{}, &block3, std::vector<compiler::Node*>{});
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/typed-array-createtypedarray.tq", 511});
      CodeStubAssembler(state_).FailAssert("Torque assert '!IsDetachedBuffer(typedArray.buffer)' failed", pos_stack);
    }
  }

  TNode<Int32T> tmp9;
  TNode<Int32T> tmp10;
  TNode<Int32T> tmp11;
  TNode<BoolT> tmp12;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 515);
    tmp9 = CodeStubAssembler(state_).LoadElementsKind(TNode<JSTypedArray>{p_exemplar});
    tmp10 = CodeStubAssembler(state_).GetNonRabGsabElementsKind(TNode<Int32T>{tmp9});
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 516);
    tmp11 = CodeStubAssembler(state_).LoadElementsKind(TNode<JSTypedArray>{tmp4});
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 515);
    tmp12 = CodeStubAssembler(state_).ElementsKindEqual(TNode<Int32T>{tmp10}, TNode<Int32T>{tmp11});
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 514);
    ca_.Branch(tmp12, &block4, std::vector<compiler::Node*>{}, &block5, std::vector<compiler::Node*>{});
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/typed-array-createtypedarray.tq", 514});
      CodeStubAssembler(state_).FailAssert("Torque assert 'GetNonRabGsabElementsKind(exemplar.elements_kind) == typedArray.elements_kind' failed", pos_stack);
    }
  }

  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-createtypedarray.tq", 505);
    ca_.Goto(&block6);
  }

    ca_.Bind(&block6);
  return TNode<JSTypedArray>{tmp4};
}

} // namespace internal
} // namespace v8
