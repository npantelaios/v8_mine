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
#include "torque-generated/src/builtins/typed-array-slice-tq-csa.h"
#include "torque-generated/src/builtins/array-join-tq-csa.h"
#include "torque-generated/src/builtins/base-tq-csa.h"
#include "torque-generated/src/builtins/convert-tq-csa.h"
#include "torque-generated/src/builtins/frame-arguments-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-createtypedarray-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-slice-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-tq-csa.h"
#include "torque-generated/src/objects/js-array-buffer-tq-csa.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/typed-array-slice.tq?l=8&c=1
const char* kBuiltinNameSlice_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
  return "%TypedArray%.prototype.slice";}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/typed-array-slice.tq?l=13&c=1
void FastCopy_0(compiler::CodeAssemblerState* state_, TNode<JSTypedArray> p_src, TNode<JSTypedArray> p_dest, TNode<UintPtrT> p_k, TNode<UintPtrT> p_count, compiler::CodeAssemblerLabel* label_IfSlow) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block26(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block25(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block30(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block31(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block32(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block33(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block28(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block37(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block36(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block41(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block42(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block43(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block44(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block39(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block46(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block45(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block48(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block47(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block49(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block50(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block51(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block52(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<BoolT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-slice.tq", 16);
    tmp0 = IsForceSlowPath_0(state_);
    ca_.Branch(tmp0, &block3, std::vector<compiler::Node*>{}, &block4, std::vector<compiler::Node*>{});
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    ca_.Goto(&block1);
  }

  TNode<Int32T> tmp1;
  TNode<UintPtrT> tmp2;
  TNode<Int32T> tmp3;
  TNode<BoolT> tmp4;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-slice.tq", 18);
    tmp1 = CodeStubAssembler(state_).LoadElementsKind(TNode<JSTypedArray>{p_src});
    ca_.SetSourcePosition("../../../src/builtins/typed-array-slice.tq", 19);
    std::tie(tmp2, tmp3) = TypedArrayBuiltinsAssembler(state_).GetTypedArrayElementsInfo(TNode<JSTypedArray>{p_dest}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/typed-array-slice.tq", 25);
    tmp4 = ElementsKindNotEqual_0(state_, TNode<Int32T>{tmp1}, TNode<Int32T>{tmp3});
    ca_.Branch(tmp4, &block5, std::vector<compiler::Node*>{}, &block6, std::vector<compiler::Node*>{});
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-slice.tq", 27);
    ca_.Goto(&block1);
  }

  TNode<IntPtrT> tmp5;
  TNode<JSArrayBuffer> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<JSArrayBuffer> tmp8;
  TNode<BoolT> tmp9;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-slice.tq", 29);
    tmp5 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp6 = CodeStubAssembler(state_).LoadReference<JSArrayBuffer>(CodeStubAssembler::Reference{p_dest, tmp5});
    tmp7 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp8 = CodeStubAssembler(state_).LoadReference<JSArrayBuffer>(CodeStubAssembler::Reference{p_src, tmp7});
    tmp9 = CodeStubAssembler(state_).TaggedEqual(TNode<HeapObject>{tmp6}, TNode<HeapObject>{tmp8});
    ca_.Branch(tmp9, &block7, std::vector<compiler::Node*>{}, &block8, std::vector<compiler::Node*>{});
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-slice.tq", 30);
    ca_.Goto(&block1);
  }

  TNode<UintPtrT> tmp10;
  TNode<BoolT> tmp11;
  if (block8.is_used()) {
    ca_.Bind(&block8);
    ca_.SetSourcePosition("../../../src/builtins/typed-array.tq", 28);
    tmp10 = FromConstexpr_uintptr_constexpr_uintptr_0(state_, JSTypedArray::kMaxLength);
    tmp11 = CodeStubAssembler(state_).UintPtrGreaterThan(TNode<UintPtrT>{p_count}, TNode<UintPtrT>{tmp10});
    ca_.Branch(tmp11, &block12, std::vector<compiler::Node*>{}, &block13, std::vector<compiler::Node*>{});
  }

  if (block12.is_used()) {
    ca_.Bind(&block12);
    ca_.Goto(&block10);
  }

  TNode<UintPtrT> tmp12;
  TNode<UintPtrT> tmp13;
  TNode<BoolT> tmp14;
  if (block13.is_used()) {
    ca_.Bind(&block13);
    ca_.SetSourcePosition("../../../src/builtins/typed-array.tq", 29);
    tmp12 = FromConstexpr_uintptr_constexpr_uintptr_0(state_, JSArrayBuffer::kMaxByteLength);
    tmp13 = CodeStubAssembler(state_).WordShr(TNode<UintPtrT>{tmp12}, TNode<UintPtrT>{tmp2});
    ca_.SetSourcePosition("../../../src/builtins/typed-array.tq", 30);
    tmp14 = CodeStubAssembler(state_).UintPtrGreaterThan(TNode<UintPtrT>{p_count}, TNode<UintPtrT>{tmp13});
    ca_.Branch(tmp14, &block14, std::vector<compiler::Node*>{}, &block15, std::vector<compiler::Node*>{});
  }

  if (block14.is_used()) {
    ca_.Bind(&block14);
    ca_.Goto(&block10);
  }

  TNode<UintPtrT> tmp15;
  TNode<UintPtrT> tmp16;
  TNode<BoolT> tmp17;
  if (block15.is_used()) {
    ca_.Bind(&block15);
    ca_.SetSourcePosition("../../../src/builtins/typed-array.tq", 31);
    tmp15 = CodeStubAssembler(state_).WordShl(TNode<UintPtrT>{p_count}, TNode<UintPtrT>{tmp2});
    ca_.SetSourcePosition("../../../src/builtins/typed-array.tq", 28);
    tmp16 = FromConstexpr_uintptr_constexpr_uintptr_0(state_, JSTypedArray::kMaxLength);
    tmp17 = CodeStubAssembler(state_).UintPtrGreaterThan(TNode<UintPtrT>{p_k}, TNode<UintPtrT>{tmp16});
    ca_.Branch(tmp17, &block19, std::vector<compiler::Node*>{}, &block20, std::vector<compiler::Node*>{});
  }

  if (block10.is_used()) {
    ca_.Bind(&block10);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-slice.tq", 34);
    CodeStubAssembler(state_).PrintErr("halting because of unreachable code at src/builtins/typed-array-slice.tq:34:17");
    CodeStubAssembler(state_).Unreachable();
  }

  if (block19.is_used()) {
    ca_.Bind(&block19);
    ca_.SetSourcePosition("../../../src/builtins/typed-array.tq", 28);
    ca_.Goto(&block17);
  }

  TNode<UintPtrT> tmp18;
  TNode<UintPtrT> tmp19;
  TNode<BoolT> tmp20;
  if (block20.is_used()) {
    ca_.Bind(&block20);
    ca_.SetSourcePosition("../../../src/builtins/typed-array.tq", 29);
    tmp18 = FromConstexpr_uintptr_constexpr_uintptr_0(state_, JSArrayBuffer::kMaxByteLength);
    tmp19 = CodeStubAssembler(state_).WordShr(TNode<UintPtrT>{tmp18}, TNode<UintPtrT>{tmp2});
    ca_.SetSourcePosition("../../../src/builtins/typed-array.tq", 30);
    tmp20 = CodeStubAssembler(state_).UintPtrGreaterThan(TNode<UintPtrT>{p_k}, TNode<UintPtrT>{tmp19});
    ca_.Branch(tmp20, &block21, std::vector<compiler::Node*>{}, &block22, std::vector<compiler::Node*>{});
  }

  if (block21.is_used()) {
    ca_.Bind(&block21);
    ca_.Goto(&block17);
  }

  TNode<UintPtrT> tmp21;
  TNode<RawPtrT> tmp22;
  TNode<IntPtrT> tmp23;
  TNode<RawPtrT> tmp24;
  TNode<UintPtrT> tmp25;
  if (block22.is_used()) {
    ca_.Bind(&block22);
    ca_.SetSourcePosition("../../../src/builtins/typed-array.tq", 31);
    tmp21 = CodeStubAssembler(state_).WordShl(TNode<UintPtrT>{p_k}, TNode<UintPtrT>{tmp2});
    ca_.SetSourcePosition("../../../src/builtins/typed-array-slice.tq", 37);
    tmp22 = CodeStubAssembler(state_).LoadJSTypedArrayDataPtr(TNode<JSTypedArray>{p_src});
    tmp23 = Convert_intptr_uintptr_0(state_, TNode<UintPtrT>{tmp21});
    tmp24 = CodeStubAssembler(state_).RawPtrAdd(TNode<RawPtrT>{tmp22}, TNode<IntPtrT>{tmp23});
    ca_.SetSourcePosition("../../../src/builtins/typed-array-slice.tq", 41);
    compiler::CodeAssemblerLabel label26(&ca_);
    tmp25 = CodeStubAssembler(state_).LoadJSTypedArrayLengthAndCheckDetached(TNode<JSTypedArray>{p_src}, &label26);
    ca_.Goto(&block25);
    if (label26.is_used()) {
      ca_.Bind(&label26);
      ca_.Goto(&block26);
    }
  }

  if (block17.is_used()) {
    ca_.Bind(&block17);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-slice.tq", 36);
    CodeStubAssembler(state_).PrintErr("halting because of unreachable code at src/builtins/typed-array-slice.tq:36:17");
    CodeStubAssembler(state_).Unreachable();
  }

  if (block26.is_used()) {
    ca_.Bind(&block26);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-slice.tq", 41);
    CodeStubAssembler(state_).PrintErr("halting because of unreachable code at src/builtins/typed-array-slice.tq:41:63");
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<UintPtrT> tmp27;
  TNode<Int32T> tmp28;
  TNode<UintPtrT> tmp29;
  TNode<BoolT> tmp30;
  if (block25.is_used()) {
    ca_.Bind(&block25);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-slice.tq", 42);
    std::tie(tmp27, tmp28) = TypedArrayBuiltinsAssembler(state_).GetTypedArrayElementsInfo(TNode<JSTypedArray>{p_src}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/typed-array.tq", 28);
    tmp29 = FromConstexpr_uintptr_constexpr_uintptr_0(state_, JSTypedArray::kMaxLength);
    tmp30 = CodeStubAssembler(state_).UintPtrGreaterThan(TNode<UintPtrT>{tmp25}, TNode<UintPtrT>{tmp29});
    ca_.Branch(tmp30, &block30, std::vector<compiler::Node*>{}, &block31, std::vector<compiler::Node*>{});
  }

  if (block30.is_used()) {
    ca_.Bind(&block30);
    ca_.Goto(&block28);
  }

  TNode<UintPtrT> tmp31;
  TNode<UintPtrT> tmp32;
  TNode<BoolT> tmp33;
  if (block31.is_used()) {
    ca_.Bind(&block31);
    ca_.SetSourcePosition("../../../src/builtins/typed-array.tq", 29);
    tmp31 = FromConstexpr_uintptr_constexpr_uintptr_0(state_, JSArrayBuffer::kMaxByteLength);
    tmp32 = CodeStubAssembler(state_).WordShr(TNode<UintPtrT>{tmp31}, TNode<UintPtrT>{tmp27});
    ca_.SetSourcePosition("../../../src/builtins/typed-array.tq", 30);
    tmp33 = CodeStubAssembler(state_).UintPtrGreaterThan(TNode<UintPtrT>{tmp25}, TNode<UintPtrT>{tmp32});
    ca_.Branch(tmp33, &block32, std::vector<compiler::Node*>{}, &block33, std::vector<compiler::Node*>{});
  }

  if (block32.is_used()) {
    ca_.Bind(&block32);
    ca_.Goto(&block28);
  }

  TNode<UintPtrT> tmp34;
  TNode<UintPtrT> tmp35;
  if (block33.is_used()) {
    ca_.Bind(&block33);
    ca_.SetSourcePosition("../../../src/builtins/typed-array.tq", 31);
    tmp34 = CodeStubAssembler(state_).WordShl(TNode<UintPtrT>{tmp25}, TNode<UintPtrT>{tmp27});
    ca_.SetSourcePosition("../../../src/builtins/typed-array-slice.tq", 46);
    compiler::CodeAssemblerLabel label36(&ca_);
    tmp35 = CodeStubAssembler(state_).LoadJSTypedArrayLengthAndCheckDetached(TNode<JSTypedArray>{p_dest}, &label36);
    ca_.Goto(&block36);
    if (label36.is_used()) {
      ca_.Bind(&label36);
      ca_.Goto(&block37);
    }
  }

  if (block28.is_used()) {
    ca_.Bind(&block28);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-slice.tq", 43);
    CodeStubAssembler(state_).PrintErr("halting because of unreachable code at src/builtins/typed-array-slice.tq:43:30");
    CodeStubAssembler(state_).Unreachable();
  }

  if (block37.is_used()) {
    ca_.Bind(&block37);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-slice.tq", 46);
    CodeStubAssembler(state_).PrintErr("halting because of unreachable code at src/builtins/typed-array-slice.tq:46:64");
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<UintPtrT> tmp37;
  TNode<Int32T> tmp38;
  TNode<UintPtrT> tmp39;
  TNode<BoolT> tmp40;
  if (block36.is_used()) {
    ca_.Bind(&block36);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-slice.tq", 47);
    std::tie(tmp37, tmp38) = TypedArrayBuiltinsAssembler(state_).GetTypedArrayElementsInfo(TNode<JSTypedArray>{p_dest}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/typed-array.tq", 28);
    tmp39 = FromConstexpr_uintptr_constexpr_uintptr_0(state_, JSTypedArray::kMaxLength);
    tmp40 = CodeStubAssembler(state_).UintPtrGreaterThan(TNode<UintPtrT>{tmp35}, TNode<UintPtrT>{tmp39});
    ca_.Branch(tmp40, &block41, std::vector<compiler::Node*>{}, &block42, std::vector<compiler::Node*>{});
  }

  if (block41.is_used()) {
    ca_.Bind(&block41);
    ca_.Goto(&block39);
  }

  TNode<UintPtrT> tmp41;
  TNode<UintPtrT> tmp42;
  TNode<BoolT> tmp43;
  if (block42.is_used()) {
    ca_.Bind(&block42);
    ca_.SetSourcePosition("../../../src/builtins/typed-array.tq", 29);
    tmp41 = FromConstexpr_uintptr_constexpr_uintptr_0(state_, JSArrayBuffer::kMaxByteLength);
    tmp42 = CodeStubAssembler(state_).WordShr(TNode<UintPtrT>{tmp41}, TNode<UintPtrT>{tmp37});
    ca_.SetSourcePosition("../../../src/builtins/typed-array.tq", 30);
    tmp43 = CodeStubAssembler(state_).UintPtrGreaterThan(TNode<UintPtrT>{tmp35}, TNode<UintPtrT>{tmp42});
    ca_.Branch(tmp43, &block43, std::vector<compiler::Node*>{}, &block44, std::vector<compiler::Node*>{});
  }

  if (block43.is_used()) {
    ca_.Bind(&block43);
    ca_.Goto(&block39);
  }

  TNode<UintPtrT> tmp44;
  TNode<BoolT> tmp45;
  if (block44.is_used()) {
    ca_.Bind(&block44);
    ca_.SetSourcePosition("../../../src/builtins/typed-array.tq", 31);
    tmp44 = CodeStubAssembler(state_).WordShl(TNode<UintPtrT>{tmp35}, TNode<UintPtrT>{tmp37});
    ca_.SetSourcePosition("../../../src/builtins/typed-array-slice.tq", 50);
    tmp45 = CodeStubAssembler(state_).UintPtrLessThanOrEqual(TNode<UintPtrT>{tmp15}, TNode<UintPtrT>{tmp44});
    ca_.Branch(tmp45, &block45, std::vector<compiler::Node*>{}, &block46, std::vector<compiler::Node*>{});
  }

  if (block39.is_used()) {
    ca_.Bind(&block39);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-slice.tq", 48);
    CodeStubAssembler(state_).PrintErr("halting because of unreachable code at src/builtins/typed-array-slice.tq:48:31");
    CodeStubAssembler(state_).Unreachable();
  }

  if (block46.is_used()) {
    ca_.Bind(&block46);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-slice.tq", 50);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/typed-array-slice.tq", 50});
      CodeStubAssembler(state_).FailAssert("Torque assert 'countBytes <= destByteLength' failed", pos_stack);
    }
  }

  TNode<UintPtrT> tmp46;
  TNode<BoolT> tmp47;
  if (block45.is_used()) {
    ca_.Bind(&block45);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-slice.tq", 51);
    tmp46 = CodeStubAssembler(state_).UintPtrSub(TNode<UintPtrT>{tmp34}, TNode<UintPtrT>{tmp21});
    tmp47 = CodeStubAssembler(state_).UintPtrLessThanOrEqual(TNode<UintPtrT>{tmp15}, TNode<UintPtrT>{tmp46});
    ca_.Branch(tmp47, &block47, std::vector<compiler::Node*>{}, &block48, std::vector<compiler::Node*>{});
  }

  if (block48.is_used()) {
    ca_.Bind(&block48);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/typed-array-slice.tq", 51});
      CodeStubAssembler(state_).FailAssert("Torque assert 'countBytes <= srcByteLength - startOffset' failed", pos_stack);
    }
  }

  TNode<IntPtrT> tmp48;
  TNode<JSArrayBuffer> tmp49;
  TNode<BoolT> tmp50;
  if (block47.is_used()) {
    ca_.Bind(&block47);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-slice.tq", 54);
    tmp48 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp49 = CodeStubAssembler(state_).LoadReference<JSArrayBuffer>(CodeStubAssembler::Reference{p_src, tmp48});
    tmp50 = IsSharedArrayBuffer_0(state_, TNode<JSArrayBuffer>{tmp49});
    ca_.Branch(tmp50, &block49, std::vector<compiler::Node*>{}, &block50, std::vector<compiler::Node*>{});
  }

  TNode<RawPtrT> tmp51;
  if (block49.is_used()) {
    ca_.Bind(&block49);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-slice.tq", 56);
    tmp51 = CodeStubAssembler(state_).LoadJSTypedArrayDataPtr(TNode<JSTypedArray>{p_dest});
    TypedArrayBuiltinsAssembler(state_).CallCRelaxedMemmove(TNode<RawPtrT>{tmp51}, TNode<RawPtrT>{tmp24}, TNode<UintPtrT>{tmp15});
    ca_.SetSourcePosition("../../../src/builtins/typed-array-slice.tq", 54);
    ca_.Goto(&block51);
  }

  TNode<RawPtrT> tmp52;
  if (block50.is_used()) {
    ca_.Bind(&block50);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-slice.tq", 58);
    tmp52 = CodeStubAssembler(state_).LoadJSTypedArrayDataPtr(TNode<JSTypedArray>{p_dest});
    TypedArrayBuiltinsAssembler(state_).CallCMemmove(TNode<RawPtrT>{tmp52}, TNode<RawPtrT>{tmp24}, TNode<UintPtrT>{tmp15});
    ca_.SetSourcePosition("../../../src/builtins/typed-array-slice.tq", 54);
    ca_.Goto(&block51);
  }

  if (block51.is_used()) {
    ca_.Bind(&block51);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-slice.tq", 13);
    ca_.Goto(&block52);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_IfSlow);
  }

    ca_.Bind(&block52);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/typed-array-slice.tq?l=62&c=1
void SlowCopy_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSTypedArray> p_src, TNode<JSTypedArray> p_dest, TNode<UintPtrT> p_k, TNode<UintPtrT> p_final) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Int32T> tmp0;
  TNode<BoolT> tmp1;
  TNode<Int32T> tmp2;
  TNode<BoolT> tmp3;
  TNode<BoolT> tmp4;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-slice.tq", 64);
    tmp0 = CodeStubAssembler(state_).LoadElementsKind(TNode<JSTypedArray>{p_src});
    tmp1 = TypedArrayBuiltinsAssembler(state_).IsBigInt64ElementsKind(TNode<Int32T>{tmp0});
    ca_.SetSourcePosition("../../../src/builtins/typed-array-slice.tq", 65);
    tmp2 = CodeStubAssembler(state_).LoadElementsKind(TNode<JSTypedArray>{p_dest});
    tmp3 = TypedArrayBuiltinsAssembler(state_).IsBigInt64ElementsKind(TNode<Int32T>{tmp2});
    ca_.SetSourcePosition("../../../src/builtins/typed-array-slice.tq", 64);
    tmp4 = CodeStubAssembler(state_).Word32NotEqual(TNode<BoolT>{tmp1}, TNode<BoolT>{tmp3});
    ca_.Branch(tmp4, &block2, std::vector<compiler::Node*>{}, &block3, std::vector<compiler::Node*>{});
  }

  if (block2.is_used()) {
    ca_.Bind(&block2);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-slice.tq", 67);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{p_context}, MessageTemplate::kBigIntMixedTypes);
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-slice.tq", 70);
    TypedArrayBuiltinsAssembler(state_).CallCCopyTypedArrayElementsSlice(TNode<JSTypedArray>{p_src}, TNode<JSTypedArray>{p_dest}, TNode<UintPtrT>{p_k}, TNode<UintPtrT>{p_final});
    ca_.SetSourcePosition("../../../src/builtins/typed-array-slice.tq", 62);
    ca_.Goto(&block4);
  }

    ca_.Bind(&block4);
}

TF_BUILTIN(TypedArrayPrototypeSlice, CodeStubAssembler) {
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
  compiler::CodeAssemblerParameterizedLabel<UintPtrT> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<UintPtrT> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<UintPtrT, UintPtrT> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<UintPtrT, UintPtrT> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<UintPtrT> tmp0;
  TNode<JSTypedArray> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<Object> tmp3;
  TNode<Oddball> tmp4;
  TNode<BoolT> tmp5;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-slice.tq", 83);
    tmp0 = TypedArrayBuiltinsAssembler(state_).ValidateTypedArrayAndGetLength(TNode<Context>{parameter0}, TNode<Object>{parameter1}, kBuiltinNameSlice_0(state_));
    ca_.SetSourcePosition("../../../src/builtins/typed-array-slice.tq", 84);
    tmp1 = UnsafeCast_JSTypedArray_0(state_, TNode<Context>{parameter0}, TNode<Object>{parameter1});
    ca_.SetSourcePosition("../../../src/builtins/typed-array-slice.tq", 89);
    tmp2 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp3 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{torque_arguments.frame}, TNode<RawPtrT>{torque_arguments.base}, TNode<IntPtrT>{torque_arguments.length}, TNode<IntPtrT>{torque_arguments.actual_count}}, TNode<IntPtrT>{tmp2});
    ca_.SetSourcePosition("../../../src/builtins/typed-array-slice.tq", 91);
    tmp4 = Undefined_0(state_);
    tmp5 = CodeStubAssembler(state_).TaggedNotEqual(TNode<Object>{tmp3}, TNode<HeapObject>{tmp4});
    ca_.Branch(tmp5, &block1, std::vector<compiler::Node*>{}, &block2, std::vector<compiler::Node*>{});
  }

  TNode<UintPtrT> tmp6;
  if (block1.is_used()) {
    ca_.Bind(&block1);
    tmp6 = ConvertAndClampRelativeIndex_1(state_, TNode<Context>{parameter0}, TNode<Object>{tmp3}, TNode<UintPtrT>{tmp0});
    ca_.Goto(&block3, tmp6);
  }

  TNode<UintPtrT> tmp7;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    tmp7 = FromConstexpr_uintptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    ca_.Goto(&block3, tmp7);
  }

  TNode<UintPtrT> phi_bb3_9;
  TNode<IntPtrT> tmp8;
  TNode<Object> tmp9;
  TNode<Oddball> tmp10;
  TNode<BoolT> tmp11;
  if (block3.is_used()) {
    ca_.Bind(&block3, &phi_bb3_9);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-slice.tq", 97);
    tmp8 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp9 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{torque_arguments.frame}, TNode<RawPtrT>{torque_arguments.base}, TNode<IntPtrT>{torque_arguments.length}, TNode<IntPtrT>{torque_arguments.actual_count}}, TNode<IntPtrT>{tmp8});
    ca_.SetSourcePosition("../../../src/builtins/typed-array-slice.tq", 99);
    tmp10 = Undefined_0(state_);
    tmp11 = CodeStubAssembler(state_).TaggedNotEqual(TNode<Object>{tmp9}, TNode<HeapObject>{tmp10});
    ca_.Branch(tmp11, &block5, std::vector<compiler::Node*>{}, &block6, std::vector<compiler::Node*>{});
  }

  TNode<UintPtrT> tmp12;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    tmp12 = ConvertAndClampRelativeIndex_1(state_, TNode<Context>{parameter0}, TNode<Object>{tmp9}, TNode<UintPtrT>{tmp0});
    ca_.Goto(&block7, tmp12);
  }

  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.Goto(&block7, tmp0);
  }

  TNode<UintPtrT> phi_bb7_11;
  TNode<UintPtrT> tmp13;
  TNode<IntPtrT> tmp14;
  TNode<IntPtrT> tmp15;
  TNode<IntPtrT> tmp16;
  TNode<UintPtrT> tmp17;
  TNode<JSTypedArray> tmp18;
  TNode<UintPtrT> tmp19;
  TNode<BoolT> tmp20;
  if (block7.is_used()) {
    ca_.Bind(&block7, &phi_bb7_11);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-slice.tq", 102);
    tmp13 = CodeStubAssembler(state_).UintPtrSub(TNode<UintPtrT>{phi_bb7_11}, TNode<UintPtrT>{phi_bb3_9});
    tmp14 = CodeStubAssembler(state_).Signed(TNode<UintPtrT>{tmp13});
    tmp15 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp16 = CodeStubAssembler(state_).IntPtrMax(TNode<IntPtrT>{tmp14}, TNode<IntPtrT>{tmp15});
    tmp17 = CodeStubAssembler(state_).Unsigned(TNode<IntPtrT>{tmp16});
    ca_.SetSourcePosition("../../../src/builtins/typed-array-slice.tq", 106);
    tmp18 = TypedArraySpeciesCreateByLength_0(state_, TNode<Context>{parameter0}, kBuiltinNameSlice_0(state_), TNode<JSTypedArray>{tmp1}, TNode<UintPtrT>{tmp17});
    ca_.SetSourcePosition("../../../src/builtins/typed-array-slice.tq", 108);
    tmp19 = FromConstexpr_uintptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp20 = CodeStubAssembler(state_).UintPtrGreaterThan(TNode<UintPtrT>{tmp17}, TNode<UintPtrT>{tmp19});
    ca_.Branch(tmp20, &block9, std::vector<compiler::Node*>{}, &block10, std::vector<compiler::Node*>{phi_bb7_11, tmp17});
  }

  TNode<UintPtrT> tmp21;
  if (block9.is_used()) {
    ca_.Bind(&block9);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-slice.tq", 111);
    compiler::CodeAssemblerLabel label22(&ca_);
    tmp21 = CodeStubAssembler(state_).LoadJSTypedArrayLengthAndCheckDetached(TNode<JSTypedArray>{tmp1}, &label22);
    ca_.Goto(&block15);
    if (label22.is_used()) {
      ca_.Bind(&label22);
      ca_.Goto(&block16);
    }
  }

  if (block16.is_used()) {
    ca_.Bind(&block16);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-slice.tq", 124);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{parameter0}, MessageTemplate::kDetachedOperation, kBuiltinNameSlice_0(state_));
  }

  TNode<BoolT> tmp23;
  if (block15.is_used()) {
    ca_.Bind(&block15);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-slice.tq", 114);
    tmp23 = CodeStubAssembler(state_).UintPtrGreaterThanOrEqual(TNode<UintPtrT>{phi_bb3_9}, TNode<UintPtrT>{tmp21});
    ca_.Branch(tmp23, &block17, std::vector<compiler::Node*>{}, &block18, std::vector<compiler::Node*>{});
  }

  if (block17.is_used()) {
    ca_.Bind(&block17);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-slice.tq", 115);
    arguments.PopAndReturn(tmp18);
  }

  TNode<BoolT> tmp24;
  if (block18.is_used()) {
    ca_.Bind(&block18);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-slice.tq", 117);
    tmp24 = CodeStubAssembler(state_).UintPtrGreaterThan(TNode<UintPtrT>{phi_bb7_11}, TNode<UintPtrT>{tmp21});
    ca_.Branch(tmp24, &block19, std::vector<compiler::Node*>{}, &block20, std::vector<compiler::Node*>{phi_bb7_11, tmp17});
  }

  TNode<UintPtrT> tmp25;
  TNode<IntPtrT> tmp26;
  TNode<IntPtrT> tmp27;
  TNode<IntPtrT> tmp28;
  TNode<UintPtrT> tmp29;
  if (block19.is_used()) {
    ca_.Bind(&block19);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-slice.tq", 119);
    tmp25 = CodeStubAssembler(state_).UintPtrSub(TNode<UintPtrT>{tmp21}, TNode<UintPtrT>{phi_bb3_9});
    tmp26 = CodeStubAssembler(state_).Signed(TNode<UintPtrT>{tmp25});
    tmp27 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp28 = CodeStubAssembler(state_).IntPtrMax(TNode<IntPtrT>{tmp26}, TNode<IntPtrT>{tmp27});
    tmp29 = CodeStubAssembler(state_).Unsigned(TNode<IntPtrT>{tmp28});
    ca_.SetSourcePosition("../../../src/builtins/typed-array-slice.tq", 117);
    ca_.Goto(&block20, tmp21, tmp29);
  }

  TNode<UintPtrT> phi_bb20_11;
  TNode<UintPtrT> phi_bb20_12;
  TNode<JSTypedArray> tmp30;
  if (block20.is_used()) {
    ca_.Bind(&block20, &phi_bb20_11, &phi_bb20_12);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-slice.tq", 121);
    tmp30 = (TNode<JSTypedArray>{tmp1});
    compiler::CodeAssemblerLabel label31(&ca_);
    FastCopy_0(state_, TNode<JSTypedArray>{tmp30}, TNode<JSTypedArray>{tmp18}, TNode<UintPtrT>{phi_bb3_9}, TNode<UintPtrT>{phi_bb20_12}, &label31);
    ca_.Goto(&block21);
    if (label31.is_used()) {
      ca_.Bind(&label31);
      ca_.Goto(&block22);
    }
  }

  if (block22.is_used()) {
    ca_.Bind(&block22);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-slice.tq", 126);
    SlowCopy_0(state_, TNode<Context>{parameter0}, TNode<JSTypedArray>{tmp1}, TNode<JSTypedArray>{tmp18}, TNode<UintPtrT>{phi_bb3_9}, TNode<UintPtrT>{phi_bb20_11});
    ca_.SetSourcePosition("../../../src/builtins/typed-array-slice.tq", 109);
    ca_.Goto(&block11);
  }

  if (block21.is_used()) {
    ca_.Bind(&block21);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-slice.tq", 125);
    ca_.Goto(&block11);
  }

  if (block11.is_used()) {
    ca_.Bind(&block11);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-slice.tq", 108);
    ca_.Goto(&block10, phi_bb20_11, phi_bb20_12);
  }

  TNode<UintPtrT> phi_bb10_11;
  TNode<UintPtrT> phi_bb10_12;
  if (block10.is_used()) {
    ca_.Bind(&block10, &phi_bb10_11, &phi_bb10_12);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-slice.tq", 130);
    arguments.PopAndReturn(tmp18);
  }
}

} // namespace internal
} // namespace v8
