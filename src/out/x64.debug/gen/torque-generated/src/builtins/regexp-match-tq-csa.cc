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
#include "torque-generated/src/builtins/regexp-match-tq-csa.h"
#include "torque-generated/src/builtins/array-join-tq-csa.h"
#include "torque-generated/src/builtins/array-slice-tq-csa.h"
#include "torque-generated/src/builtins/base-tq-csa.h"
#include "torque-generated/src/builtins/boolean-tq-csa.h"
#include "torque-generated/src/builtins/cast-tq-csa.h"
#include "torque-generated/src/builtins/convert-tq-csa.h"
#include "torque-generated/src/builtins/growable-fixed-array-tq-csa.h"
#include "torque-generated/src/builtins/number-tq-csa.h"
#include "torque-generated/src/builtins/regexp-exec-tq-csa.h"
#include "torque-generated/src/builtins/regexp-match-all-tq-csa.h"
#include "torque-generated/src/builtins/regexp-match-tq-csa.h"
#include "torque-generated/src/builtins/regexp-replace-tq-csa.h"
#include "torque-generated/src/builtins/regexp-tq-csa.h"
#include "torque-generated/src/builtins/torque-internal-tq-csa.h"
#include "torque-generated/src/objects/fixed-array-tq-csa.h"
#include "torque-generated/src/objects/js-array-tq-csa.h"
#include "torque-generated/src/objects/regexp-match-info-tq-csa.h"
#include "torque-generated/src/objects/string-tq-csa.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/regexp-match.tq?l=22&c=1
TNode<Object> RegExpPrototypeMatchBody_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSReceiver> p_regexp, TNode<String> p_string, bool p_isFastPath) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block27(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block28(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block35(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block36(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, String> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, String> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT, BoolT, String> block41(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT, BoolT, String> block39(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT, BoolT, String> block46(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT, BoolT, String> block50(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT, BoolT, String> block49(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT, BoolT, String> block51(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT, BoolT, String> block52(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT, BoolT, String, String> block53(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT, BoolT, String> block47(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT, BoolT, String> block55(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT, BoolT, String> block54(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT, BoolT, String> block56(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT, BoolT, String> block57(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT, BoolT, String, String> block48(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT, BoolT, String> block45(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT, BoolT, String> block58(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT, BoolT, String> block59(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT, BoolT, String, IntPtrT, IntPtrT> block65(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT, BoolT, String, IntPtrT, IntPtrT> block64(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT, BoolT, String, IntPtrT, IntPtrT> block67(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT, BoolT, String, IntPtrT, IntPtrT> block66(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT, BoolT, String, IntPtrT, IntPtrT> block69(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT, BoolT, String, IntPtrT, IntPtrT> block68(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT, BoolT, String, HeapObject> block60(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT, BoolT, String> block73(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT, BoolT, String> block72(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT, BoolT, String> block74(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, BoolT, String> block78(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, BoolT, String> block77(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, BoolT, String> block80(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, BoolT, String> block79(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, BoolT, String> block82(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, BoolT, String> block81(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT, BoolT, String> block75(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, BoolT, String, FixedArray, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block87(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, BoolT, String, FixedArray, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block88(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, BoolT, String> block91(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, BoolT, String> block92(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, BoolT, String> block93(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, BoolT, String> block97(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, BoolT, String> block96(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, BoolT, String> block94(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, BoolT, String, Object> block95(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, BoolT, String> block98(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, BoolT, String> block102(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, BoolT, String> block101(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, BoolT, String> block99(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, BoolT, String> block100(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT, BoolT, String> block40(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block103(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/regexp-match.tq", 24);
    if ((p_isFastPath)) {
      ca_.Goto(&block2);
    } else {
      ca_.Goto(&block3);
    }
  }

  TNode<BoolT> tmp0;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    ca_.SetSourcePosition("../../../src/builtins/regexp-match.tq", 25);
    tmp0 = Is_FastJSRegExp_JSReceiver_0(state_, TNode<Context>{p_context}, TNode<JSReceiver>{p_regexp});
    ca_.Branch(tmp0, &block5, std::vector<compiler::Node*>{}, &block6, std::vector<compiler::Node*>{});
  }

  if (block6.is_used()) {
    ca_.Bind(&block6);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/regexp-match.tq", 25});
      CodeStubAssembler(state_).FailAssert("Torque assert 'Is<FastJSRegExp>(regexp)' failed", pos_stack);
    }
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    ca_.SetSourcePosition("../../../src/builtins/regexp-match.tq", 24);
    ca_.Goto(&block4);
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    ca_.Goto(&block4);
  }

  TNode<BoolT> tmp1;
  TNode<BoolT> tmp2;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.SetSourcePosition("../../../src/builtins/regexp-match.tq", 28);
    tmp1 = RegExpBuiltinsAssembler(state_).FlagGetter(TNode<Context>{p_context}, TNode<Object>{p_regexp}, JSRegExp::Flag::kGlobal, p_isFastPath);
    ca_.SetSourcePosition("../../../src/builtins/regexp-match.tq", 30);
    tmp2 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp1});
    ca_.Branch(tmp2, &block7, std::vector<compiler::Node*>{}, &block8, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp3;
  if (block7.is_used()) {
    ca_.Bind(&block7);
    ca_.SetSourcePosition("../../../src/builtins/regexp-match.tq", 31);
    tmp3 = FromConstexpr_bool_constexpr_bool_0(state_, p_isFastPath);
    ca_.Branch(tmp3, &block9, std::vector<compiler::Node*>{}, &block10, std::vector<compiler::Node*>{});
  }

  TNode<Object> tmp4;
  if (block9.is_used()) {
    ca_.Bind(&block9);
    tmp4 = RegExpPrototypeExecBodyFast_0(state_, TNode<Context>{p_context}, TNode<JSReceiver>{p_regexp}, TNode<String>{p_string});
    ca_.Goto(&block11, tmp4);
  }

  TNode<Object> tmp5;
  if (block10.is_used()) {
    ca_.Bind(&block10);
    ca_.SetSourcePosition("../../../src/builtins/regexp-match.tq", 32);
    tmp5 = RegExpExec_0(state_, TNode<Context>{p_context}, TNode<JSReceiver>{p_regexp}, TNode<String>{p_string});
    ca_.SetSourcePosition("../../../src/builtins/regexp-match.tq", 31);
    ca_.Goto(&block11, tmp5);
  }

  TNode<Object> phi_bb11_4;
  if (block11.is_used()) {
    ca_.Bind(&block11, &phi_bb11_4);
    ca_.Goto(&block1, phi_bb11_4);
  }

  if (block8.is_used()) {
    ca_.Bind(&block8);
    ca_.SetSourcePosition("../../../src/builtins/regexp-match.tq", 35);
    ca_.Branch(tmp1, &block13, std::vector<compiler::Node*>{}, &block14, std::vector<compiler::Node*>{});
  }

  if (block14.is_used()) {
    ca_.Bind(&block14);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/regexp-match.tq", 35});
      CodeStubAssembler(state_).FailAssert("Torque assert 'isGlobal' failed", pos_stack);
    }
  }

  TNode<BoolT> tmp6;
  if (block13.is_used()) {
    ca_.Bind(&block13);
    ca_.SetSourcePosition("../../../src/builtins/regexp-match.tq", 36);
    tmp6 = RegExpBuiltinsAssembler(state_).FlagGetter(TNode<Context>{p_context}, TNode<Object>{p_regexp}, JSRegExp::Flag::kUnicode, p_isFastPath);
    ca_.Branch(tmp6, &block15, std::vector<compiler::Node*>{}, &block16, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp7;
  if (block15.is_used()) {
    ca_.Bind(&block15);
    tmp7 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block17, tmp7);
  }

  TNode<BoolT> tmp8;
  if (block16.is_used()) {
    ca_.Bind(&block16);
    ca_.SetSourcePosition("../../../src/builtins/regexp-match.tq", 37);
    tmp8 = RegExpBuiltinsAssembler(state_).FlagGetter(TNode<Context>{p_context}, TNode<Object>{p_regexp}, JSRegExp::Flag::kUnicodeSets, p_isFastPath);
    ca_.SetSourcePosition("../../../src/builtins/regexp-match.tq", 36);
    ca_.Goto(&block17, tmp8);
  }

  TNode<BoolT> phi_bb17_5;
  TNode<Number> tmp9;
  TNode<FixedArray> tmp10;
  TNode<IntPtrT> tmp11;
  TNode<IntPtrT> tmp12;
  TNode<BoolT> tmp13;
  TNode<String> tmp14;
  if (block17.is_used()) {
    ca_.Bind(&block17, &phi_bb17_5);
    ca_.SetSourcePosition("../../../src/builtins/regexp-match.tq", 39);
    tmp9 = FromConstexpr_Number_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    StoreLastIndex_0(state_, TNode<Context>{p_context}, TNode<Object>{p_regexp}, TNode<Number>{tmp9}, p_isFastPath);
    ca_.SetSourcePosition("../../../src/builtins/regexp-match.tq", 43);
    std::tie(tmp10, tmp11, tmp12) = NewGrowableFixedArray_0(state_).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/regexp-match.tq", 47);
    tmp13 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.SetSourcePosition("../../../src/builtins/regexp-match.tq", 48);
    tmp14 = CodeStubAssembler(state_).EmptyStringConstant();
    ca_.SetSourcePosition("../../../src/builtins/regexp-match.tq", 49);
    if ((p_isFastPath)) {
      ca_.Goto(&block18);
    } else {
      ca_.Goto(&block19);
    }
  }

  TNode<JSRegExp> tmp15;
  TNode<IntPtrT> tmp16;
  TNode<HeapObject> tmp17;
  TNode<FixedArray> tmp18;
  TNode<Object> tmp19;
  TNode<IntPtrT> tmp20;
  TNode<IntPtrT> tmp21;
  TNode<IntPtrT> tmp22;
  TNode<UintPtrT> tmp23;
  TNode<UintPtrT> tmp24;
  TNode<BoolT> tmp25;
  if (block18.is_used()) {
    ca_.Bind(&block18);
    ca_.SetSourcePosition("../../../src/builtins/regexp-match.tq", 50);
    tmp15 = UnsafeCast_JSRegExp_0(state_, TNode<Context>{p_context}, TNode<Object>{p_regexp});
    ca_.SetSourcePosition("../../../src/builtins/regexp-match.tq", 51);
    tmp16 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp17 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{tmp15, tmp16});
    tmp18 = UnsafeCast_FixedArray_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp17});
    ca_.SetSourcePosition("../../../src/builtins/regexp-match.tq", 52);
    std::tie(tmp19, tmp20, tmp21) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray>{tmp18}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 113);
    tmp22 = Convert_intptr_constexpr_int31_0(state_, JSRegExp::kTagIndex);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 89);
    tmp23 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp22});
    tmp24 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp21});
    tmp25 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp23}, TNode<UintPtrT>{tmp24});
    ca_.Branch(tmp25, &block27, std::vector<compiler::Node*>{}, &block28, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp26;
  TNode<IntPtrT> tmp27;
  TNode<Object> tmp28;
  TNode<IntPtrT> tmp29;
  TNode<Object> tmp30;
  TNode<Smi> tmp31;
  TNode<Smi> tmp32;
  TNode<BoolT> tmp33;
  if (block27.is_used()) {
    ca_.Bind(&block27);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 97);
    tmp26 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{tmp22});
    tmp27 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp20}, TNode<IntPtrT>{tmp26});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 96);
    std::tie(tmp28, tmp29) = NewReference_Object_0(state_, TNode<Object>{tmp19}, TNode<IntPtrT>{tmp27}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/regexp-match.tq", 52);
    tmp30 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp28, tmp29});
    tmp31 = UnsafeCast_Smi_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp30});
    tmp32 = FromConstexpr_Smi_constexpr_int31_0(state_, JSRegExp::ATOM);
    tmp33 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp31}, TNode<Smi>{tmp32});
    ca_.Branch(tmp33, &block21, std::vector<compiler::Node*>{}, &block22, std::vector<compiler::Node*>{tmp13, tmp14});
  }

  if (block28.is_used()) {
    ca_.Bind(&block28);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 114);
    CodeStubAssembler(state_).PrintErr("halting because of unreachable code at src/builtins/torque-internal.tq:114:41");
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<Object> tmp34;
  TNode<IntPtrT> tmp35;
  TNode<IntPtrT> tmp36;
  TNode<IntPtrT> tmp37;
  TNode<UintPtrT> tmp38;
  TNode<UintPtrT> tmp39;
  TNode<BoolT> tmp40;
  if (block21.is_used()) {
    ca_.Bind(&block21);
    ca_.SetSourcePosition("../../../src/builtins/regexp-match.tq", 53);
    std::tie(tmp34, tmp35, tmp36) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray>{tmp18}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 113);
    tmp37 = Convert_intptr_constexpr_int31_0(state_, JSRegExp::kAtomPatternIndex);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 89);
    tmp38 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp37});
    tmp39 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp36});
    tmp40 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp38}, TNode<UintPtrT>{tmp39});
    ca_.Branch(tmp40, &block35, std::vector<compiler::Node*>{}, &block36, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp41;
  TNode<IntPtrT> tmp42;
  TNode<Object> tmp43;
  TNode<IntPtrT> tmp44;
  TNode<Object> tmp45;
  TNode<String> tmp46;
  TNode<BoolT> tmp47;
  if (block35.is_used()) {
    ca_.Bind(&block35);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 97);
    tmp41 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{tmp37});
    tmp42 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp35}, TNode<IntPtrT>{tmp41});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 96);
    std::tie(tmp43, tmp44) = NewReference_Object_0(state_, TNode<Object>{tmp34}, TNode<IntPtrT>{tmp42}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/regexp-match.tq", 53);
    tmp45 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp43, tmp44});
    tmp46 = UnsafeCast_String_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp45});
    ca_.SetSourcePosition("../../../src/builtins/regexp-match.tq", 54);
    tmp47 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.SetSourcePosition("../../../src/builtins/regexp-match.tq", 52);
    ca_.Goto(&block22, tmp47, tmp46);
  }

  if (block36.is_used()) {
    ca_.Bind(&block36);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 114);
    CodeStubAssembler(state_).PrintErr("halting because of unreachable code at src/builtins/torque-internal.tq:114:41");
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<BoolT> phi_bb22_8;
  TNode<String> phi_bb22_9;
  if (block22.is_used()) {
    ca_.Bind(&block22, &phi_bb22_8, &phi_bb22_9);
    ca_.SetSourcePosition("../../../src/builtins/regexp-match.tq", 49);
    ca_.Goto(&block20, phi_bb22_8, phi_bb22_9);
  }

  if (block19.is_used()) {
    ca_.Bind(&block19);
    ca_.Goto(&block20, tmp13, tmp14);
  }

  TNode<BoolT> phi_bb20_8;
  TNode<String> phi_bb20_9;
  if (block20.is_used()) {
    ca_.Bind(&block20, &phi_bb20_8, &phi_bb20_9);
    ca_.SetSourcePosition("../../../src/builtins/regexp-match.tq", 58);
    ca_.Goto(&block41, tmp10, tmp11, tmp12, phi_bb20_8, phi_bb20_9);
  }

  TNode<FixedArray> phi_bb41_5;
  TNode<IntPtrT> phi_bb41_6;
  TNode<IntPtrT> phi_bb41_7;
  TNode<BoolT> phi_bb41_8;
  TNode<String> phi_bb41_9;
  TNode<BoolT> tmp48;
  if (block41.is_used()) {
    ca_.Bind(&block41, &phi_bb41_5, &phi_bb41_6, &phi_bb41_7, &phi_bb41_8, &phi_bb41_9);
    tmp48 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Branch(tmp48, &block39, std::vector<compiler::Node*>{phi_bb41_5, phi_bb41_6, phi_bb41_7, phi_bb41_8, phi_bb41_9}, &block40, std::vector<compiler::Node*>{phi_bb41_5, phi_bb41_6, phi_bb41_7, phi_bb41_8, phi_bb41_9});
  }

  TNode<FixedArray> phi_bb39_5;
  TNode<IntPtrT> phi_bb39_6;
  TNode<IntPtrT> phi_bb39_7;
  TNode<BoolT> phi_bb39_8;
  TNode<String> phi_bb39_9;
  TNode<String> tmp49;
  if (block39.is_used()) {
    ca_.Bind(&block39, &phi_bb39_5, &phi_bb39_6, &phi_bb39_7, &phi_bb39_8, &phi_bb39_9);
    ca_.SetSourcePosition("../../../src/builtins/regexp-match.tq", 59);
    tmp49 = CodeStubAssembler(state_).EmptyStringConstant();
    ca_.SetSourcePosition("../../../src/builtins/regexp-match.tq", 61);
    if ((p_isFastPath)) {
      ca_.Goto(&block46, phi_bb39_5, phi_bb39_6, phi_bb39_7, phi_bb39_8, phi_bb39_9);
    } else {
      ca_.Goto(&block47, phi_bb39_5, phi_bb39_6, phi_bb39_7, phi_bb39_8, phi_bb39_9);
    }
  }

  TNode<FixedArray> phi_bb46_5;
  TNode<IntPtrT> phi_bb46_6;
  TNode<IntPtrT> phi_bb46_7;
  TNode<BoolT> phi_bb46_8;
  TNode<String> phi_bb46_9;
  TNode<JSRegExp> tmp50;
  TNode<RegExpMatchInfo> tmp51;
  if (block46.is_used()) {
    ca_.Bind(&block46, &phi_bb46_5, &phi_bb46_6, &phi_bb46_7, &phi_bb46_8, &phi_bb46_9);
    ca_.SetSourcePosition("../../../src/builtins/regexp-match.tq", 66);
    tmp50 = UnsafeCast_JSRegExp_0(state_, TNode<Context>{p_context}, TNode<Object>{p_regexp});
    ca_.SetSourcePosition("../../../src/builtins/regexp-match.tq", 65);
    compiler::CodeAssemblerLabel label52(&ca_);
    tmp51 = RegExpPrototypeExecBodyWithoutResultFast_0(state_, TNode<Context>{p_context}, TNode<JSRegExp>{tmp50}, TNode<String>{p_string}, &label52);
    ca_.Goto(&block49, phi_bb46_5, phi_bb46_6, phi_bb46_7, phi_bb46_8, phi_bb46_9);
    if (label52.is_used()) {
      ca_.Bind(&label52);
      ca_.Goto(&block50, phi_bb46_5, phi_bb46_6, phi_bb46_7, phi_bb46_8, phi_bb46_9);
    }
  }

  TNode<FixedArray> phi_bb50_5;
  TNode<IntPtrT> phi_bb50_6;
  TNode<IntPtrT> phi_bb50_7;
  TNode<BoolT> phi_bb50_8;
  TNode<String> phi_bb50_9;
  if (block50.is_used()) {
    ca_.Bind(&block50, &phi_bb50_5, &phi_bb50_6, &phi_bb50_7, &phi_bb50_8, &phi_bb50_9);
    ca_.Goto(&block45, phi_bb50_5, phi_bb50_6, phi_bb50_7, phi_bb50_8, phi_bb50_9);
  }

  TNode<FixedArray> phi_bb49_5;
  TNode<IntPtrT> phi_bb49_6;
  TNode<IntPtrT> phi_bb49_7;
  TNode<BoolT> phi_bb49_8;
  TNode<String> phi_bb49_9;
  if (block49.is_used()) {
    ca_.Bind(&block49, &phi_bb49_5, &phi_bb49_6, &phi_bb49_7, &phi_bb49_8, &phi_bb49_9);
    ca_.SetSourcePosition("../../../src/builtins/regexp-match.tq", 67);
    ca_.Branch(phi_bb49_8, &block51, std::vector<compiler::Node*>{phi_bb49_5, phi_bb49_6, phi_bb49_7, phi_bb49_8, phi_bb49_9}, &block52, std::vector<compiler::Node*>{phi_bb49_5, phi_bb49_6, phi_bb49_7, phi_bb49_8, phi_bb49_9});
  }

  TNode<FixedArray> phi_bb51_5;
  TNode<IntPtrT> phi_bb51_6;
  TNode<IntPtrT> phi_bb51_7;
  TNode<BoolT> phi_bb51_8;
  TNode<String> phi_bb51_9;
  if (block51.is_used()) {
    ca_.Bind(&block51, &phi_bb51_5, &phi_bb51_6, &phi_bb51_7, &phi_bb51_8, &phi_bb51_9);
    ca_.Goto(&block53, phi_bb51_5, phi_bb51_6, phi_bb51_7, phi_bb51_8, phi_bb51_9, phi_bb51_9);
  }

  TNode<FixedArray> phi_bb52_5;
  TNode<IntPtrT> phi_bb52_6;
  TNode<IntPtrT> phi_bb52_7;
  TNode<BoolT> phi_bb52_8;
  TNode<String> phi_bb52_9;
  TNode<Object> tmp53;
  TNode<Object> tmp54;
  TNode<Smi> tmp55;
  TNode<Smi> tmp56;
  TNode<String> tmp57;
  if (block52.is_used()) {
    ca_.Bind(&block52, &phi_bb52_5, &phi_bb52_6, &phi_bb52_7, &phi_bb52_8, &phi_bb52_9);
    ca_.SetSourcePosition("../../../src/builtins/regexp-match.tq", 70);
    tmp53 = CodeStubAssembler(state_).UnsafeLoadFixedArrayElement(TNode<RegExpMatchInfo>{tmp51}, RegExpMatchInfo::kFirstCaptureIndex);
    ca_.SetSourcePosition("../../../src/builtins/regexp-match.tq", 72);
    tmp54 = CodeStubAssembler(state_).UnsafeLoadFixedArrayElement(TNode<RegExpMatchInfo>{tmp51}, (CodeStubAssembler(state_).ConstexprInt31Add(RegExpMatchInfo::kFirstCaptureIndex, (FromConstexpr_constexpr_int31_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull))))));
    ca_.SetSourcePosition("../../../src/builtins/regexp-match.tq", 75);
    tmp55 = UnsafeCast_Smi_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp53});
    tmp56 = UnsafeCast_Smi_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp54});
    ca_.SetSourcePosition("../../../src/builtins/regexp-match.tq", 74);
    tmp57 = ca_.CallStub<String>(Builtins::CallableFor(ca_.isolate(), Builtin::kSubString), p_context, p_string, tmp55, tmp56);
    ca_.SetSourcePosition("../../../src/builtins/regexp-match.tq", 67);
    ca_.Goto(&block53, phi_bb52_5, phi_bb52_6, phi_bb52_7, phi_bb52_8, phi_bb52_9, tmp57);
  }

  TNode<FixedArray> phi_bb53_5;
  TNode<IntPtrT> phi_bb53_6;
  TNode<IntPtrT> phi_bb53_7;
  TNode<BoolT> phi_bb53_8;
  TNode<String> phi_bb53_9;
  TNode<String> phi_bb53_10;
  if (block53.is_used()) {
    ca_.Bind(&block53, &phi_bb53_5, &phi_bb53_6, &phi_bb53_7, &phi_bb53_8, &phi_bb53_9, &phi_bb53_10);
    ca_.SetSourcePosition("../../../src/builtins/regexp-match.tq", 61);
    ca_.Goto(&block48, phi_bb53_5, phi_bb53_6, phi_bb53_7, phi_bb53_8, phi_bb53_9, phi_bb53_10);
  }

  TNode<FixedArray> phi_bb47_5;
  TNode<IntPtrT> phi_bb47_6;
  TNode<IntPtrT> phi_bb47_7;
  TNode<BoolT> phi_bb47_8;
  TNode<String> phi_bb47_9;
  TNode<BoolT> tmp58;
  if (block47.is_used()) {
    ca_.Bind(&block47, &phi_bb47_5, &phi_bb47_6, &phi_bb47_7, &phi_bb47_8, &phi_bb47_9);
    ca_.SetSourcePosition("../../../src/builtins/regexp-match.tq", 78);
    tmp58 = FromConstexpr_bool_constexpr_bool_0(state_, (CodeStubAssembler(state_).ConstexprBoolNot(p_isFastPath)));
    ca_.Branch(tmp58, &block54, std::vector<compiler::Node*>{phi_bb47_5, phi_bb47_6, phi_bb47_7, phi_bb47_8, phi_bb47_9}, &block55, std::vector<compiler::Node*>{phi_bb47_5, phi_bb47_6, phi_bb47_7, phi_bb47_8, phi_bb47_9});
  }

  TNode<FixedArray> phi_bb55_5;
  TNode<IntPtrT> phi_bb55_6;
  TNode<IntPtrT> phi_bb55_7;
  TNode<BoolT> phi_bb55_8;
  TNode<String> phi_bb55_9;
  if (block55.is_used()) {
    ca_.Bind(&block55, &phi_bb55_5, &phi_bb55_6, &phi_bb55_7, &phi_bb55_8, &phi_bb55_9);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/regexp-match.tq", 78});
      CodeStubAssembler(state_).FailAssert("Torque assert '!isFastPath' failed", pos_stack);
    }
  }

  TNode<FixedArray> phi_bb54_5;
  TNode<IntPtrT> phi_bb54_6;
  TNode<IntPtrT> phi_bb54_7;
  TNode<BoolT> phi_bb54_8;
  TNode<String> phi_bb54_9;
  TNode<Object> tmp59;
  TNode<Oddball> tmp60;
  TNode<BoolT> tmp61;
  if (block54.is_used()) {
    ca_.Bind(&block54, &phi_bb54_5, &phi_bb54_6, &phi_bb54_7, &phi_bb54_8, &phi_bb54_9);
    ca_.SetSourcePosition("../../../src/builtins/regexp-match.tq", 79);
    tmp59 = RegExpExec_0(state_, TNode<Context>{p_context}, TNode<JSReceiver>{p_regexp}, TNode<String>{p_string});
    ca_.SetSourcePosition("../../../src/builtins/regexp-match.tq", 80);
    tmp60 = Null_0(state_);
    tmp61 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp59}, TNode<HeapObject>{tmp60});
    ca_.Branch(tmp61, &block56, std::vector<compiler::Node*>{phi_bb54_5, phi_bb54_6, phi_bb54_7, phi_bb54_8, phi_bb54_9}, &block57, std::vector<compiler::Node*>{phi_bb54_5, phi_bb54_6, phi_bb54_7, phi_bb54_8, phi_bb54_9});
  }

  TNode<FixedArray> phi_bb56_5;
  TNode<IntPtrT> phi_bb56_6;
  TNode<IntPtrT> phi_bb56_7;
  TNode<BoolT> phi_bb56_8;
  TNode<String> phi_bb56_9;
  if (block56.is_used()) {
    ca_.Bind(&block56, &phi_bb56_5, &phi_bb56_6, &phi_bb56_7, &phi_bb56_8, &phi_bb56_9);
    ca_.SetSourcePosition("../../../src/builtins/regexp-match.tq", 81);
    ca_.Goto(&block45, phi_bb56_5, phi_bb56_6, phi_bb56_7, phi_bb56_8, phi_bb56_9);
  }

  TNode<FixedArray> phi_bb57_5;
  TNode<IntPtrT> phi_bb57_6;
  TNode<IntPtrT> phi_bb57_7;
  TNode<BoolT> phi_bb57_8;
  TNode<String> phi_bb57_9;
  TNode<Smi> tmp62;
  TNode<Object> tmp63;
  TNode<String> tmp64;
  if (block57.is_used()) {
    ca_.Bind(&block57, &phi_bb57_5, &phi_bb57_6, &phi_bb57_7, &phi_bb57_8, &phi_bb57_9);
    ca_.SetSourcePosition("../../../src/builtins/regexp-match.tq", 83);
    tmp62 = SmiConstant_0(state_, IntegerLiteral(false, 0x0ull));
    tmp63 = CodeStubAssembler(state_).GetProperty(TNode<Context>{p_context}, TNode<Object>{tmp59}, TNode<Object>{tmp62});
    tmp64 = CodeStubAssembler(state_).ToString_Inline(TNode<Context>{p_context}, TNode<Object>{tmp63});
    ca_.SetSourcePosition("../../../src/builtins/regexp-match.tq", 61);
    ca_.Goto(&block48, phi_bb57_5, phi_bb57_6, phi_bb57_7, phi_bb57_8, phi_bb57_9, tmp64);
  }

  TNode<FixedArray> phi_bb48_5;
  TNode<IntPtrT> phi_bb48_6;
  TNode<IntPtrT> phi_bb48_7;
  TNode<BoolT> phi_bb48_8;
  TNode<String> phi_bb48_9;
  TNode<String> phi_bb48_10;
  TNode<BoolT> tmp65;
  if (block48.is_used()) {
    ca_.Bind(&block48, &phi_bb48_5, &phi_bb48_6, &phi_bb48_7, &phi_bb48_8, &phi_bb48_9, &phi_bb48_10);
    ca_.SetSourcePosition("../../../src/builtins/growable-fixed-array.tq", 20);
    tmp65 = CodeStubAssembler(state_).IntPtrLessThanOrEqual(TNode<IntPtrT>{phi_bb48_7}, TNode<IntPtrT>{phi_bb48_6});
    ca_.Branch(tmp65, &block72, std::vector<compiler::Node*>{phi_bb48_5, phi_bb48_6, phi_bb48_7, phi_bb48_8, phi_bb48_9}, &block73, std::vector<compiler::Node*>{phi_bb48_5, phi_bb48_6, phi_bb48_7, phi_bb48_8, phi_bb48_9});
  }

  TNode<FixedArray> phi_bb45_5;
  TNode<IntPtrT> phi_bb45_6;
  TNode<IntPtrT> phi_bb45_7;
  TNode<BoolT> phi_bb45_8;
  TNode<String> phi_bb45_9;
  TNode<IntPtrT> tmp66;
  TNode<BoolT> tmp67;
  if (block45.is_used()) {
    ca_.Bind(&block45, &phi_bb45_5, &phi_bb45_6, &phi_bb45_7, &phi_bb45_8, &phi_bb45_9);
    ca_.SetSourcePosition("../../../src/builtins/regexp-match.tq", 87);
    tmp66 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp67 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{phi_bb45_7}, TNode<IntPtrT>{tmp66});
    ca_.Branch(tmp67, &block58, std::vector<compiler::Node*>{phi_bb45_5, phi_bb45_6, phi_bb45_7, phi_bb45_8, phi_bb45_9}, &block59, std::vector<compiler::Node*>{phi_bb45_5, phi_bb45_6, phi_bb45_7, phi_bb45_8, phi_bb45_9});
  }

  TNode<FixedArray> phi_bb58_5;
  TNode<IntPtrT> phi_bb58_6;
  TNode<IntPtrT> phi_bb58_7;
  TNode<BoolT> phi_bb58_8;
  TNode<String> phi_bb58_9;
  TNode<Oddball> tmp68;
  if (block58.is_used()) {
    ca_.Bind(&block58, &phi_bb58_5, &phi_bb58_6, &phi_bb58_7, &phi_bb58_8, &phi_bb58_9);
    tmp68 = Null_0(state_);
    ca_.Goto(&block60, phi_bb58_5, phi_bb58_6, phi_bb58_7, phi_bb58_8, phi_bb58_9, tmp68);
  }

  TNode<FixedArray> phi_bb59_5;
  TNode<IntPtrT> phi_bb59_6;
  TNode<IntPtrT> phi_bb59_7;
  TNode<BoolT> phi_bb59_8;
  TNode<String> phi_bb59_9;
  TNode<NativeContext> tmp69;
  TNode<Map> tmp70;
  TNode<IntPtrT> tmp71;
  TNode<BoolT> tmp72;
  if (block59.is_used()) {
    ca_.Bind(&block59, &phi_bb59_5, &phi_bb59_6, &phi_bb59_7, &phi_bb59_8, &phi_bb59_9);
    ca_.SetSourcePosition("../../../src/builtins/growable-fixed-array.tq", 30);
    tmp69 = CodeStubAssembler(state_).LoadNativeContext(TNode<Context>{p_context});
    ca_.SetSourcePosition("../../../src/builtins/growable-fixed-array.tq", 32);
    tmp70 = CodeStubAssembler(state_).LoadJSArrayElementsMap(ElementsKind::PACKED_ELEMENTS, TNode<NativeContext>{tmp69});
    ca_.SetSourcePosition("../../../src/builtins/growable-fixed-array.tq", 13);
    tmp71 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp72 = CodeStubAssembler(state_).IntPtrGreaterThanOrEqual(TNode<IntPtrT>{phi_bb59_7}, TNode<IntPtrT>{tmp71});
    ca_.Branch(tmp72, &block64, std::vector<compiler::Node*>{phi_bb59_5, phi_bb59_6, phi_bb59_7, phi_bb59_8, phi_bb59_9, phi_bb59_7, phi_bb59_7}, &block65, std::vector<compiler::Node*>{phi_bb59_5, phi_bb59_6, phi_bb59_7, phi_bb59_8, phi_bb59_9, phi_bb59_7, phi_bb59_7});
  }

  TNode<FixedArray> phi_bb65_5;
  TNode<IntPtrT> phi_bb65_6;
  TNode<IntPtrT> phi_bb65_7;
  TNode<BoolT> phi_bb65_8;
  TNode<String> phi_bb65_9;
  TNode<IntPtrT> phi_bb65_15;
  TNode<IntPtrT> phi_bb65_16;
  if (block65.is_used()) {
    ca_.Bind(&block65, &phi_bb65_5, &phi_bb65_6, &phi_bb65_7, &phi_bb65_8, &phi_bb65_9, &phi_bb65_15, &phi_bb65_16);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/growable-fixed-array.tq", 13});
      CodeStubAssembler(state_).FailAssert("Torque assert 'this.length >= 0' failed", pos_stack);
    }
  }

  TNode<FixedArray> phi_bb64_5;
  TNode<IntPtrT> phi_bb64_6;
  TNode<IntPtrT> phi_bb64_7;
  TNode<BoolT> phi_bb64_8;
  TNode<String> phi_bb64_9;
  TNode<IntPtrT> phi_bb64_15;
  TNode<IntPtrT> phi_bb64_16;
  TNode<IntPtrT> tmp73;
  TNode<BoolT> tmp74;
  if (block64.is_used()) {
    ca_.Bind(&block64, &phi_bb64_5, &phi_bb64_6, &phi_bb64_7, &phi_bb64_8, &phi_bb64_9, &phi_bb64_15, &phi_bb64_16);
    ca_.SetSourcePosition("../../../src/builtins/growable-fixed-array.tq", 14);
    tmp73 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp74 = CodeStubAssembler(state_).IntPtrGreaterThanOrEqual(TNode<IntPtrT>{phi_bb64_16}, TNode<IntPtrT>{tmp73});
    ca_.Branch(tmp74, &block66, std::vector<compiler::Node*>{phi_bb64_5, phi_bb64_6, phi_bb64_7, phi_bb64_8, phi_bb64_9, phi_bb64_15, phi_bb64_16}, &block67, std::vector<compiler::Node*>{phi_bb64_5, phi_bb64_6, phi_bb64_7, phi_bb64_8, phi_bb64_9, phi_bb64_15, phi_bb64_16});
  }

  TNode<FixedArray> phi_bb67_5;
  TNode<IntPtrT> phi_bb67_6;
  TNode<IntPtrT> phi_bb67_7;
  TNode<BoolT> phi_bb67_8;
  TNode<String> phi_bb67_9;
  TNode<IntPtrT> phi_bb67_15;
  TNode<IntPtrT> phi_bb67_16;
  if (block67.is_used()) {
    ca_.Bind(&block67, &phi_bb67_5, &phi_bb67_6, &phi_bb67_7, &phi_bb67_8, &phi_bb67_9, &phi_bb67_15, &phi_bb67_16);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/growable-fixed-array.tq", 14});
      CodeStubAssembler(state_).FailAssert("Torque assert 'newCapacity >= 0' failed", pos_stack);
    }
  }

  TNode<FixedArray> phi_bb66_5;
  TNode<IntPtrT> phi_bb66_6;
  TNode<IntPtrT> phi_bb66_7;
  TNode<BoolT> phi_bb66_8;
  TNode<String> phi_bb66_9;
  TNode<IntPtrT> phi_bb66_15;
  TNode<IntPtrT> phi_bb66_16;
  TNode<BoolT> tmp75;
  if (block66.is_used()) {
    ca_.Bind(&block66, &phi_bb66_5, &phi_bb66_6, &phi_bb66_7, &phi_bb66_8, &phi_bb66_9, &phi_bb66_15, &phi_bb66_16);
    ca_.SetSourcePosition("../../../src/builtins/growable-fixed-array.tq", 15);
    tmp75 = CodeStubAssembler(state_).IntPtrGreaterThanOrEqual(TNode<IntPtrT>{phi_bb66_16}, TNode<IntPtrT>{phi_bb66_7});
    ca_.Branch(tmp75, &block68, std::vector<compiler::Node*>{phi_bb66_5, phi_bb66_6, phi_bb66_7, phi_bb66_8, phi_bb66_9, phi_bb66_15, phi_bb66_16}, &block69, std::vector<compiler::Node*>{phi_bb66_5, phi_bb66_6, phi_bb66_7, phi_bb66_8, phi_bb66_9, phi_bb66_15, phi_bb66_16});
  }

  TNode<FixedArray> phi_bb69_5;
  TNode<IntPtrT> phi_bb69_6;
  TNode<IntPtrT> phi_bb69_7;
  TNode<BoolT> phi_bb69_8;
  TNode<String> phi_bb69_9;
  TNode<IntPtrT> phi_bb69_15;
  TNode<IntPtrT> phi_bb69_16;
  if (block69.is_used()) {
    ca_.Bind(&block69, &phi_bb69_5, &phi_bb69_6, &phi_bb69_7, &phi_bb69_8, &phi_bb69_9, &phi_bb69_15, &phi_bb69_16);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/growable-fixed-array.tq", 15});
      CodeStubAssembler(state_).FailAssert("Torque assert 'newCapacity >= this.length' failed", pos_stack);
    }
  }

  TNode<FixedArray> phi_bb68_5;
  TNode<IntPtrT> phi_bb68_6;
  TNode<IntPtrT> phi_bb68_7;
  TNode<BoolT> phi_bb68_8;
  TNode<String> phi_bb68_9;
  TNode<IntPtrT> phi_bb68_15;
  TNode<IntPtrT> phi_bb68_16;
  TNode<IntPtrT> tmp76;
  TNode<FixedArray> tmp77;
  TNode<Smi> tmp78;
  TNode<JSArray> tmp79;
  if (block68.is_used()) {
    ca_.Bind(&block68, &phi_bb68_5, &phi_bb68_6, &phi_bb68_7, &phi_bb68_8, &phi_bb68_9, &phi_bb68_15, &phi_bb68_16);
    ca_.SetSourcePosition("../../../src/builtins/growable-fixed-array.tq", 16);
    tmp76 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    ca_.SetSourcePosition("../../../src/builtins/growable-fixed-array.tq", 17);
    tmp77 = ExtractFixedArray_0(state_, TNode<FixedArray>{phi_bb68_5}, TNode<IntPtrT>{tmp76}, TNode<IntPtrT>{phi_bb68_7}, TNode<IntPtrT>{phi_bb68_16});
    ca_.SetSourcePosition("../../../src/builtins/growable-fixed-array.tq", 34);
    tmp78 = Convert_Smi_intptr_0(state_, TNode<IntPtrT>{phi_bb68_7});
    ca_.SetSourcePosition("../../../src/builtins/growable-fixed-array.tq", 35);
    tmp79 = CodeStubAssembler(state_).AllocateJSArray(TNode<Map>{tmp70}, TNode<FixedArrayBase>{tmp77}, TNode<Smi>{tmp78});
    ca_.SetSourcePosition("../../../src/builtins/regexp-match.tq", 87);
    ca_.Goto(&block60, phi_bb68_5, phi_bb68_6, phi_bb68_7, phi_bb68_8, phi_bb68_9, tmp79);
  }

  TNode<FixedArray> phi_bb60_5;
  TNode<IntPtrT> phi_bb60_6;
  TNode<IntPtrT> phi_bb60_7;
  TNode<BoolT> phi_bb60_8;
  TNode<String> phi_bb60_9;
  TNode<HeapObject> phi_bb60_11;
  if (block60.is_used()) {
    ca_.Bind(&block60, &phi_bb60_5, &phi_bb60_6, &phi_bb60_7, &phi_bb60_8, &phi_bb60_9, &phi_bb60_11);
    ca_.Goto(&block1, phi_bb60_11);
  }

  TNode<FixedArray> phi_bb73_5;
  TNode<IntPtrT> phi_bb73_6;
  TNode<IntPtrT> phi_bb73_7;
  TNode<BoolT> phi_bb73_8;
  TNode<String> phi_bb73_9;
  if (block73.is_used()) {
    ca_.Bind(&block73, &phi_bb73_5, &phi_bb73_6, &phi_bb73_7, &phi_bb73_8, &phi_bb73_9);
    ca_.SetSourcePosition("../../../src/builtins/growable-fixed-array.tq", 20);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/growable-fixed-array.tq", 20});
      CodeStubAssembler(state_).FailAssert("Torque assert 'this.length <= this.capacity' failed", pos_stack);
    }
  }

  TNode<FixedArray> phi_bb72_5;
  TNode<IntPtrT> phi_bb72_6;
  TNode<IntPtrT> phi_bb72_7;
  TNode<BoolT> phi_bb72_8;
  TNode<String> phi_bb72_9;
  TNode<BoolT> tmp80;
  if (block72.is_used()) {
    ca_.Bind(&block72, &phi_bb72_5, &phi_bb72_6, &phi_bb72_7, &phi_bb72_8, &phi_bb72_9);
    ca_.SetSourcePosition("../../../src/builtins/growable-fixed-array.tq", 21);
    tmp80 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{phi_bb72_6}, TNode<IntPtrT>{phi_bb72_7});
    ca_.Branch(tmp80, &block74, std::vector<compiler::Node*>{phi_bb72_5, phi_bb72_6, phi_bb72_7, phi_bb72_8, phi_bb72_9}, &block75, std::vector<compiler::Node*>{phi_bb72_5, phi_bb72_6, phi_bb72_7, phi_bb72_8, phi_bb72_9});
  }

  TNode<FixedArray> phi_bb74_5;
  TNode<IntPtrT> phi_bb74_6;
  TNode<IntPtrT> phi_bb74_7;
  TNode<BoolT> phi_bb74_8;
  TNode<String> phi_bb74_9;
  TNode<IntPtrT> tmp81;
  TNode<IntPtrT> tmp82;
  TNode<IntPtrT> tmp83;
  TNode<IntPtrT> tmp84;
  TNode<IntPtrT> tmp85;
  TNode<IntPtrT> tmp86;
  TNode<BoolT> tmp87;
  if (block74.is_used()) {
    ca_.Bind(&block74, &phi_bb74_5, &phi_bb74_6, &phi_bb74_7, &phi_bb74_8, &phi_bb74_9);
    ca_.SetSourcePosition("../../../src/builtins/growable-fixed-array.tq", 24);
    tmp81 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp82 = CodeStubAssembler(state_).WordSar(TNode<IntPtrT>{phi_bb74_6}, TNode<IntPtrT>{tmp81});
    tmp83 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb74_6}, TNode<IntPtrT>{tmp82});
    tmp84 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x10ull));
    tmp85 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp83}, TNode<IntPtrT>{tmp84});
    ca_.SetSourcePosition("../../../src/builtins/growable-fixed-array.tq", 13);
    tmp86 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp87 = CodeStubAssembler(state_).IntPtrGreaterThanOrEqual(TNode<IntPtrT>{phi_bb74_7}, TNode<IntPtrT>{tmp86});
    ca_.Branch(tmp87, &block77, std::vector<compiler::Node*>{phi_bb74_5, phi_bb74_7, phi_bb74_8, phi_bb74_9}, &block78, std::vector<compiler::Node*>{phi_bb74_5, phi_bb74_7, phi_bb74_8, phi_bb74_9});
  }

  TNode<FixedArray> phi_bb78_5;
  TNode<IntPtrT> phi_bb78_7;
  TNode<BoolT> phi_bb78_8;
  TNode<String> phi_bb78_9;
  if (block78.is_used()) {
    ca_.Bind(&block78, &phi_bb78_5, &phi_bb78_7, &phi_bb78_8, &phi_bb78_9);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/growable-fixed-array.tq", 13});
      CodeStubAssembler(state_).FailAssert("Torque assert 'this.length >= 0' failed", pos_stack);
    }
  }

  TNode<FixedArray> phi_bb77_5;
  TNode<IntPtrT> phi_bb77_7;
  TNode<BoolT> phi_bb77_8;
  TNode<String> phi_bb77_9;
  TNode<IntPtrT> tmp88;
  TNode<BoolT> tmp89;
  if (block77.is_used()) {
    ca_.Bind(&block77, &phi_bb77_5, &phi_bb77_7, &phi_bb77_8, &phi_bb77_9);
    ca_.SetSourcePosition("../../../src/builtins/growable-fixed-array.tq", 14);
    tmp88 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp89 = CodeStubAssembler(state_).IntPtrGreaterThanOrEqual(TNode<IntPtrT>{tmp85}, TNode<IntPtrT>{tmp88});
    ca_.Branch(tmp89, &block79, std::vector<compiler::Node*>{phi_bb77_5, phi_bb77_7, phi_bb77_8, phi_bb77_9}, &block80, std::vector<compiler::Node*>{phi_bb77_5, phi_bb77_7, phi_bb77_8, phi_bb77_9});
  }

  TNode<FixedArray> phi_bb80_5;
  TNode<IntPtrT> phi_bb80_7;
  TNode<BoolT> phi_bb80_8;
  TNode<String> phi_bb80_9;
  if (block80.is_used()) {
    ca_.Bind(&block80, &phi_bb80_5, &phi_bb80_7, &phi_bb80_8, &phi_bb80_9);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/growable-fixed-array.tq", 14});
      CodeStubAssembler(state_).FailAssert("Torque assert 'newCapacity >= 0' failed", pos_stack);
    }
  }

  TNode<FixedArray> phi_bb79_5;
  TNode<IntPtrT> phi_bb79_7;
  TNode<BoolT> phi_bb79_8;
  TNode<String> phi_bb79_9;
  TNode<BoolT> tmp90;
  if (block79.is_used()) {
    ca_.Bind(&block79, &phi_bb79_5, &phi_bb79_7, &phi_bb79_8, &phi_bb79_9);
    ca_.SetSourcePosition("../../../src/builtins/growable-fixed-array.tq", 15);
    tmp90 = CodeStubAssembler(state_).IntPtrGreaterThanOrEqual(TNode<IntPtrT>{tmp85}, TNode<IntPtrT>{phi_bb79_7});
    ca_.Branch(tmp90, &block81, std::vector<compiler::Node*>{phi_bb79_5, phi_bb79_7, phi_bb79_8, phi_bb79_9}, &block82, std::vector<compiler::Node*>{phi_bb79_5, phi_bb79_7, phi_bb79_8, phi_bb79_9});
  }

  TNode<FixedArray> phi_bb82_5;
  TNode<IntPtrT> phi_bb82_7;
  TNode<BoolT> phi_bb82_8;
  TNode<String> phi_bb82_9;
  if (block82.is_used()) {
    ca_.Bind(&block82, &phi_bb82_5, &phi_bb82_7, &phi_bb82_8, &phi_bb82_9);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/growable-fixed-array.tq", 15});
      CodeStubAssembler(state_).FailAssert("Torque assert 'newCapacity >= this.length' failed", pos_stack);
    }
  }

  TNode<FixedArray> phi_bb81_5;
  TNode<IntPtrT> phi_bb81_7;
  TNode<BoolT> phi_bb81_8;
  TNode<String> phi_bb81_9;
  TNode<IntPtrT> tmp91;
  TNode<FixedArray> tmp92;
  if (block81.is_used()) {
    ca_.Bind(&block81, &phi_bb81_5, &phi_bb81_7, &phi_bb81_8, &phi_bb81_9);
    ca_.SetSourcePosition("../../../src/builtins/growable-fixed-array.tq", 16);
    tmp91 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    ca_.SetSourcePosition("../../../src/builtins/growable-fixed-array.tq", 17);
    tmp92 = ExtractFixedArray_0(state_, TNode<FixedArray>{phi_bb81_5}, TNode<IntPtrT>{tmp91}, TNode<IntPtrT>{phi_bb81_7}, TNode<IntPtrT>{tmp85});
    ca_.SetSourcePosition("../../../src/builtins/growable-fixed-array.tq", 21);
    ca_.Goto(&block75, tmp92, tmp85, phi_bb81_7, phi_bb81_8, phi_bb81_9);
  }

  TNode<FixedArray> phi_bb75_5;
  TNode<IntPtrT> phi_bb75_6;
  TNode<IntPtrT> phi_bb75_7;
  TNode<BoolT> phi_bb75_8;
  TNode<String> phi_bb75_9;
  TNode<Object> tmp93;
  TNode<IntPtrT> tmp94;
  TNode<IntPtrT> tmp95;
  TNode<IntPtrT> tmp96;
  TNode<IntPtrT> tmp97;
  TNode<UintPtrT> tmp98;
  TNode<UintPtrT> tmp99;
  TNode<BoolT> tmp100;
  if (block75.is_used()) {
    ca_.Bind(&block75, &phi_bb75_5, &phi_bb75_6, &phi_bb75_7, &phi_bb75_8, &phi_bb75_9);
    ca_.SetSourcePosition("../../../src/builtins/growable-fixed-array.tq", 10);
    std::tie(tmp93, tmp94, tmp95) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray>{phi_bb75_5}).Flatten();
    tmp96 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp97 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb75_7}, TNode<IntPtrT>{tmp96});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 89);
    tmp98 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{phi_bb75_7});
    tmp99 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp95});
    tmp100 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp98}, TNode<UintPtrT>{tmp99});
    ca_.Branch(tmp100, &block87, std::vector<compiler::Node*>{phi_bb75_5, phi_bb75_6, phi_bb75_8, phi_bb75_9, phi_bb75_5, phi_bb75_7, phi_bb75_7, phi_bb75_7, phi_bb75_7}, &block88, std::vector<compiler::Node*>{phi_bb75_5, phi_bb75_6, phi_bb75_8, phi_bb75_9, phi_bb75_5, phi_bb75_7, phi_bb75_7, phi_bb75_7, phi_bb75_7});
  }

  TNode<FixedArray> phi_bb87_5;
  TNode<IntPtrT> phi_bb87_6;
  TNode<BoolT> phi_bb87_8;
  TNode<String> phi_bb87_9;
  TNode<FixedArray> phi_bb87_13;
  TNode<IntPtrT> phi_bb87_17;
  TNode<IntPtrT> phi_bb87_18;
  TNode<IntPtrT> phi_bb87_22;
  TNode<IntPtrT> phi_bb87_23;
  TNode<IntPtrT> tmp101;
  TNode<IntPtrT> tmp102;
  TNode<Object> tmp103;
  TNode<IntPtrT> tmp104;
  TNode<Smi> tmp105;
  TNode<Smi> tmp106;
  TNode<BoolT> tmp107;
  if (block87.is_used()) {
    ca_.Bind(&block87, &phi_bb87_5, &phi_bb87_6, &phi_bb87_8, &phi_bb87_9, &phi_bb87_13, &phi_bb87_17, &phi_bb87_18, &phi_bb87_22, &phi_bb87_23);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 97);
    tmp101 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{phi_bb87_23});
    tmp102 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp94}, TNode<IntPtrT>{tmp101});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 96);
    std::tie(tmp103, tmp104) = NewReference_Object_0(state_, TNode<Object>{tmp93}, TNode<IntPtrT>{tmp102}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/growable-fixed-array.tq", 10);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp103, tmp104}, phi_bb48_10);
    ca_.SetSourcePosition("../../../src/builtins/regexp-match.tq", 94);
    tmp105 = CodeStubAssembler(state_).LoadStringLengthAsSmi(TNode<String>{phi_bb48_10});
    ca_.SetSourcePosition("../../../src/builtins/regexp-match.tq", 95);
    tmp106 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp107 = CodeStubAssembler(state_).SmiNotEqual(TNode<Smi>{tmp105}, TNode<Smi>{tmp106});
    ca_.Branch(tmp107, &block91, std::vector<compiler::Node*>{phi_bb87_5, phi_bb87_6, phi_bb87_8, phi_bb87_9}, &block92, std::vector<compiler::Node*>{phi_bb87_5, phi_bb87_6, phi_bb87_8, phi_bb87_9});
  }

  TNode<FixedArray> phi_bb88_5;
  TNode<IntPtrT> phi_bb88_6;
  TNode<BoolT> phi_bb88_8;
  TNode<String> phi_bb88_9;
  TNode<FixedArray> phi_bb88_13;
  TNode<IntPtrT> phi_bb88_17;
  TNode<IntPtrT> phi_bb88_18;
  TNode<IntPtrT> phi_bb88_22;
  TNode<IntPtrT> phi_bb88_23;
  if (block88.is_used()) {
    ca_.Bind(&block88, &phi_bb88_5, &phi_bb88_6, &phi_bb88_8, &phi_bb88_9, &phi_bb88_13, &phi_bb88_17, &phi_bb88_18, &phi_bb88_22, &phi_bb88_23);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 101);
    CodeStubAssembler(state_).PrintErr("halting because of unreachable code at src/builtins/torque-internal.tq:101:45");
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<FixedArray> phi_bb91_5;
  TNode<IntPtrT> phi_bb91_6;
  TNode<BoolT> phi_bb91_8;
  TNode<String> phi_bb91_9;
  if (block91.is_used()) {
    ca_.Bind(&block91, &phi_bb91_5, &phi_bb91_6, &phi_bb91_8, &phi_bb91_9);
    ca_.SetSourcePosition("../../../src/builtins/regexp-match.tq", 96);
    ca_.Goto(&block41, phi_bb91_5, phi_bb91_6, tmp97, phi_bb91_8, phi_bb91_9);
  }

  TNode<FixedArray> phi_bb92_5;
  TNode<IntPtrT> phi_bb92_6;
  TNode<BoolT> phi_bb92_8;
  TNode<String> phi_bb92_9;
  TNode<Object> tmp108;
  if (block92.is_used()) {
    ca_.Bind(&block92, &phi_bb92_5, &phi_bb92_6, &phi_bb92_8, &phi_bb92_9);
    ca_.SetSourcePosition("../../../src/builtins/regexp-match.tq", 98);
    tmp108 = LoadLastIndex_0(state_, TNode<Context>{p_context}, TNode<Object>{p_regexp}, p_isFastPath);
    ca_.SetSourcePosition("../../../src/builtins/regexp-match.tq", 99);
    if ((p_isFastPath)) {
      ca_.Goto(&block93, phi_bb92_5, phi_bb92_6, phi_bb92_8, phi_bb92_9);
    } else {
      ca_.Goto(&block94, phi_bb92_5, phi_bb92_6, phi_bb92_8, phi_bb92_9);
    }
  }

  TNode<FixedArray> phi_bb93_5;
  TNode<IntPtrT> phi_bb93_6;
  TNode<BoolT> phi_bb93_8;
  TNode<String> phi_bb93_9;
  TNode<BoolT> tmp109;
  if (block93.is_used()) {
    ca_.Bind(&block93, &phi_bb93_5, &phi_bb93_6, &phi_bb93_8, &phi_bb93_9);
    ca_.SetSourcePosition("../../../src/builtins/regexp-match.tq", 100);
    tmp109 = CodeStubAssembler(state_).TaggedIsPositiveSmi(TNode<Object>{tmp108});
    ca_.Branch(tmp109, &block96, std::vector<compiler::Node*>{phi_bb93_5, phi_bb93_6, phi_bb93_8, phi_bb93_9}, &block97, std::vector<compiler::Node*>{phi_bb93_5, phi_bb93_6, phi_bb93_8, phi_bb93_9});
  }

  TNode<FixedArray> phi_bb97_5;
  TNode<IntPtrT> phi_bb97_6;
  TNode<BoolT> phi_bb97_8;
  TNode<String> phi_bb97_9;
  if (block97.is_used()) {
    ca_.Bind(&block97, &phi_bb97_5, &phi_bb97_6, &phi_bb97_8, &phi_bb97_9);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/regexp-match.tq", 100});
      CodeStubAssembler(state_).FailAssert("Torque assert 'TaggedIsPositiveSmi(lastIndex)' failed", pos_stack);
    }
  }

  TNode<FixedArray> phi_bb96_5;
  TNode<IntPtrT> phi_bb96_6;
  TNode<BoolT> phi_bb96_8;
  TNode<String> phi_bb96_9;
  if (block96.is_used()) {
    ca_.Bind(&block96, &phi_bb96_5, &phi_bb96_6, &phi_bb96_8, &phi_bb96_9);
    ca_.SetSourcePosition("../../../src/builtins/regexp-match.tq", 99);
    ca_.Goto(&block95, phi_bb96_5, phi_bb96_6, phi_bb96_8, phi_bb96_9, tmp108);
  }

  TNode<FixedArray> phi_bb94_5;
  TNode<IntPtrT> phi_bb94_6;
  TNode<BoolT> phi_bb94_8;
  TNode<String> phi_bb94_9;
  TNode<Number> tmp110;
  if (block94.is_used()) {
    ca_.Bind(&block94, &phi_bb94_5, &phi_bb94_6, &phi_bb94_8, &phi_bb94_9);
    ca_.SetSourcePosition("../../../src/builtins/regexp-match.tq", 102);
    tmp110 = CodeStubAssembler(state_).ToLength_Inline(TNode<Context>{p_context}, TNode<Object>{tmp108});
    ca_.SetSourcePosition("../../../src/builtins/regexp-match.tq", 99);
    ca_.Goto(&block95, phi_bb94_5, phi_bb94_6, phi_bb94_8, phi_bb94_9, tmp110);
  }

  TNode<FixedArray> phi_bb95_5;
  TNode<IntPtrT> phi_bb95_6;
  TNode<BoolT> phi_bb95_8;
  TNode<String> phi_bb95_9;
  TNode<Object> phi_bb95_12;
  TNode<Number> tmp111;
  TNode<Number> tmp112;
  if (block95.is_used()) {
    ca_.Bind(&block95, &phi_bb95_5, &phi_bb95_6, &phi_bb95_8, &phi_bb95_9, &phi_bb95_12);
    ca_.SetSourcePosition("../../../src/builtins/regexp-match.tq", 106);
    tmp111 = UnsafeCast_Number_0(state_, TNode<Context>{p_context}, TNode<Object>{phi_bb95_12});
    ca_.SetSourcePosition("../../../src/builtins/regexp-match.tq", 105);
    tmp112 = RegExpBuiltinsAssembler(state_).AdvanceStringIndex(TNode<String>{p_string}, TNode<Number>{tmp111}, TNode<BoolT>{phi_bb17_5}, p_isFastPath);
    ca_.SetSourcePosition("../../../src/builtins/regexp-match.tq", 108);
    if ((p_isFastPath)) {
      ca_.Goto(&block98, phi_bb95_5, phi_bb95_6, phi_bb95_8, phi_bb95_9);
    } else {
      ca_.Goto(&block99, phi_bb95_5, phi_bb95_6, phi_bb95_8, phi_bb95_9);
    }
  }

  TNode<FixedArray> phi_bb98_5;
  TNode<IntPtrT> phi_bb98_6;
  TNode<BoolT> phi_bb98_8;
  TNode<String> phi_bb98_9;
  TNode<BoolT> tmp113;
  if (block98.is_used()) {
    ca_.Bind(&block98, &phi_bb98_5, &phi_bb98_6, &phi_bb98_8, &phi_bb98_9);
    ca_.SetSourcePosition("../../../src/builtins/regexp-match.tq", 112);
    StaticAssertStringLengthFitsSmi_0(state_);
    ca_.SetSourcePosition("../../../src/builtins/regexp-match.tq", 113);
    tmp113 = CodeStubAssembler(state_).TaggedIsPositiveSmi(TNode<Object>{tmp112});
    ca_.Branch(tmp113, &block101, std::vector<compiler::Node*>{phi_bb98_5, phi_bb98_6, phi_bb98_8, phi_bb98_9}, &block102, std::vector<compiler::Node*>{phi_bb98_5, phi_bb98_6, phi_bb98_8, phi_bb98_9});
  }

  TNode<FixedArray> phi_bb102_5;
  TNode<IntPtrT> phi_bb102_6;
  TNode<BoolT> phi_bb102_8;
  TNode<String> phi_bb102_9;
  if (block102.is_used()) {
    ca_.Bind(&block102, &phi_bb102_5, &phi_bb102_6, &phi_bb102_8, &phi_bb102_9);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/regexp-match.tq", 113});
      CodeStubAssembler(state_).FailAssert("Torque assert 'TaggedIsPositiveSmi(newLastIndex)' failed", pos_stack);
    }
  }

  TNode<FixedArray> phi_bb101_5;
  TNode<IntPtrT> phi_bb101_6;
  TNode<BoolT> phi_bb101_8;
  TNode<String> phi_bb101_9;
  if (block101.is_used()) {
    ca_.Bind(&block101, &phi_bb101_5, &phi_bb101_6, &phi_bb101_8, &phi_bb101_9);
    ca_.SetSourcePosition("../../../src/builtins/regexp-match.tq", 108);
    ca_.Goto(&block100, phi_bb101_5, phi_bb101_6, phi_bb101_8, phi_bb101_9);
  }

  TNode<FixedArray> phi_bb99_5;
  TNode<IntPtrT> phi_bb99_6;
  TNode<BoolT> phi_bb99_8;
  TNode<String> phi_bb99_9;
  if (block99.is_used()) {
    ca_.Bind(&block99, &phi_bb99_5, &phi_bb99_6, &phi_bb99_8, &phi_bb99_9);
    ca_.Goto(&block100, phi_bb99_5, phi_bb99_6, phi_bb99_8, phi_bb99_9);
  }

  TNode<FixedArray> phi_bb100_5;
  TNode<IntPtrT> phi_bb100_6;
  TNode<BoolT> phi_bb100_8;
  TNode<String> phi_bb100_9;
  if (block100.is_used()) {
    ca_.Bind(&block100, &phi_bb100_5, &phi_bb100_6, &phi_bb100_8, &phi_bb100_9);
    ca_.SetSourcePosition("../../../src/builtins/regexp-match.tq", 116);
    StoreLastIndex_0(state_, TNode<Context>{p_context}, TNode<Object>{p_regexp}, TNode<Number>{tmp112}, p_isFastPath);
    ca_.SetSourcePosition("../../../src/builtins/regexp-match.tq", 58);
    ca_.Goto(&block41, phi_bb100_5, phi_bb100_6, tmp97, phi_bb100_8, phi_bb100_9);
  }

  TNode<FixedArray> phi_bb40_5;
  TNode<IntPtrT> phi_bb40_6;
  TNode<IntPtrT> phi_bb40_7;
  TNode<BoolT> phi_bb40_8;
  TNode<String> phi_bb40_9;
  if (block40.is_used()) {
    ca_.Bind(&block40, &phi_bb40_5, &phi_bb40_6, &phi_bb40_7, &phi_bb40_8, &phi_bb40_9);
    ca_.SetSourcePosition("../../../src/builtins/regexp-match.tq", 120);
    VerifiedUnreachable_0(state_);
  }

  TNode<Object> phi_bb1_3;
  if (block1.is_used()) {
    ca_.Bind(&block1, &phi_bb1_3);
    ca_.SetSourcePosition("../../../src/builtins/regexp-match.tq", 22);
    ca_.Goto(&block103, phi_bb1_3);
  }

  TNode<Object> phi_bb103_3;
    ca_.Bind(&block103, &phi_bb103_3);
  return TNode<Object>{phi_bb103_3};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/regexp-match.tq?l=123&c=1
TNode<Object> FastRegExpPrototypeMatchBody_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSRegExp> p_receiver, TNode<String> p_string) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Object> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/regexp-match.tq", 125);
    tmp0 = RegExpPrototypeMatchBody_0(state_, TNode<Context>{p_context}, TNode<JSReceiver>{p_receiver}, TNode<String>{p_string}, true);
    ca_.SetSourcePosition("../../../src/builtins/regexp-match.tq", 123);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Object>{tmp0};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/regexp-match.tq?l=128&c=1
TNode<Object> SlowRegExpPrototypeMatchBody_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSReceiver> p_receiver, TNode<String> p_string) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Object> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/regexp-match.tq", 130);
    tmp0 = RegExpPrototypeMatchBody_0(state_, TNode<Context>{p_context}, TNode<JSReceiver>{p_receiver}, TNode<String>{p_string}, false);
    ca_.SetSourcePosition("../../../src/builtins/regexp-match.tq", 128);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Object>{tmp0};
}

TF_BUILTIN(RegExpMatchFast, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedParameter<Context>(Descriptor::kContext);
  USE(parameter0);
  TNode<JSRegExp> parameter1 = UncheckedParameter<JSRegExp>(Descriptor::kReceiver);
  USE(parameter1);
  TNode<String> parameter2 = UncheckedParameter<String>(Descriptor::kString);
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Object> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/regexp-match.tq", 138);
    tmp0 = FastRegExpPrototypeMatchBody_0(state_, TNode<Context>{parameter0}, TNode<JSRegExp>{parameter1}, TNode<String>{parameter2});
    CodeStubAssembler(state_).Return(tmp0);
  }
}

TF_BUILTIN(RegExpPrototypeMatch, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kReceiver);
  USE(parameter1);
  TNode<Object> parameter2 = UncheckedParameter<Object>(Descriptor::kString);
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<JSReceiver> tmp0;
  TNode<String> tmp1;
  TNode<JSRegExp> tmp2;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/regexp-match.tq", 145);
    CodeStubAssembler(state_).ThrowIfNotJSReceiver(TNode<Context>{parameter0}, TNode<Object>{parameter1}, MessageTemplate::kIncompatibleMethodReceiver, "RegExp.prototype.@@match");
    ca_.SetSourcePosition("../../../src/builtins/regexp-match.tq", 148);
    tmp0 = UnsafeCast_JSReceiver_0(state_, TNode<Context>{parameter0}, TNode<Object>{parameter1});
    ca_.SetSourcePosition("../../../src/builtins/regexp-match.tq", 149);
    tmp1 = CodeStubAssembler(state_).ToString_Inline(TNode<Context>{parameter0}, TNode<Object>{parameter2});
    ca_.SetSourcePosition("../../../src/builtins/regexp-match.tq", 154);
    compiler::CodeAssemblerLabel label3(&ca_);
    tmp2 = Cast_FastJSRegExp_0(state_, TNode<Context>{parameter0}, TNode<HeapObject>{tmp0}, &label3);
    ca_.Goto(&block3);
    if (label3.is_used()) {
      ca_.Bind(&label3);
      ca_.Goto(&block4);
    }
  }

  TNode<Object> tmp4;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.SetSourcePosition("../../../src/builtins/regexp-match.tq", 155);
    tmp4 = SlowRegExpPrototypeMatchBody_0(state_, TNode<Context>{parameter0}, TNode<JSReceiver>{tmp0}, TNode<String>{tmp1});
    CodeStubAssembler(state_).Return(tmp4);
  }

  TNode<Object> tmp5;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    ca_.SetSourcePosition("../../../src/builtins/regexp-match.tq", 159);
    tmp5 = ca_.CallStub<Object>(Builtins::CallableFor(ca_.isolate(), Builtin::kRegExpMatchFast), parameter0, tmp2, tmp1);
    CodeStubAssembler(state_).Return(tmp5);
  }
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/regexp-match.tq?l=25&c=12
TNode<BoolT> Is_FastJSRegExp_JSReceiver_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSReceiver> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<JSRegExp> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 808);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = Cast_FastJSRegExp_0(state_, TNode<Context>{p_context}, TNode<HeapObject>{p_o}, &label1);
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
    ca_.SetSourcePosition("../../../src/builtins/regexp-match.tq", 25);
    ca_.Goto(&block6);
  }

    ca_.Bind(&block6);
  return TNode<BoolT>{phi_bb1_2};
}

} // namespace internal
} // namespace v8
