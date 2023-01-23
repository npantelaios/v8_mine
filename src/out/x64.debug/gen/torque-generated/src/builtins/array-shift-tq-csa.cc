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
#include "torque-generated/src/builtins/array-shift-tq-csa.h"
#include "torque-generated/src/builtins/array-findindex-tq-csa.h"
#include "torque-generated/src/builtins/array-reverse-tq-csa.h"
#include "torque-generated/src/builtins/array-shift-tq-csa.h"
#include "torque-generated/src/builtins/array-tq-csa.h"
#include "torque-generated/src/builtins/base-tq-csa.h"
#include "torque-generated/src/builtins/convert-tq-csa.h"
#include "torque-generated/src/builtins/frames-tq-csa.h"
#include "torque-generated/src/builtins/torque-internal-tq-csa.h"
#include "torque-generated/src/objects/fixed-array-tq-csa.h"
#include "torque-generated/src/objects/js-array-tq-csa.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-shift.tq?l=8&c=1
TNode<Object> TryFastArrayShift_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_receiver, compiler::CodeAssemblerLabel* label_Slow, compiler::CodeAssemblerLabel* label_Runtime) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block25(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block28(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block27(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block31(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block30(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block32(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block38(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block37(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block33(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block42(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block41(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block43(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block44(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block45(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block34(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block47(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block53(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block52(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block58(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block59(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block48(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block65(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block64(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block70(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block71(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block49(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block74(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<JSArray> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/array-shift.tq", 10);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = Cast_FastJSArray_1(state_, TNode<Context>{p_context}, TNode<Object>{p_receiver}, &label1);
    ca_.Goto(&block4);
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block5);
    }
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    ca_.Goto(&block1);
  }

  TNode<JSArray> tmp2;
  TNode<JSArray> tmp3;
  TNode<Map> tmp4;
  TNode<BoolT> tmp5;
  TNode<BoolT> tmp6;
  TNode<BoolT> tmp7;
  TNode<Int32T> tmp8;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.SetSourcePosition("../../../src/builtins/array-shift.tq", 11);
    std::tie(tmp2, tmp3, tmp4, tmp5, tmp6, tmp7) = NewFastJSArrayWitness_0(state_, TNode<JSArray>{tmp0}).Flatten();
    ca_.SetSourcePosition("../../../src/objects/js-array.tq", 257);
    compiler::CodeAssemblerLabel label9(&ca_);
    tmp8 = CodeStubAssembler(state_).EnsureArrayPushable(TNode<Context>{p_context}, TNode<Map>{tmp4}, &label9);
    ca_.Goto(&block7);
    if (label9.is_used()) {
      ca_.Bind(&label9);
      ca_.Goto(&block8);
    }
  }

  if (block8.is_used()) {
    ca_.Bind(&block8);
    ca_.Goto(&block1);
  }

  TNode<BoolT> tmp10;
  TNode<Smi> tmp11;
  TNode<Smi> tmp12;
  TNode<BoolT> tmp13;
  if (block7.is_used()) {
    ca_.Bind(&block7);
    ca_.SetSourcePosition("../../../src/objects/js-array.tq", 258);
    EnsureWriteableFastElements_0(state_, TNode<Context>{p_context}, TNode<JSArray>{tmp3});
    ca_.SetSourcePosition("../../../src/objects/js-array.tq", 259);
    tmp10 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.SetSourcePosition("../../../src/builtins/array-shift.tq", 15);
    tmp11 = CodeStubAssembler(state_).LoadFastJSArrayLength(TNode<JSArray>{tmp0});
    tmp12 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp13 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp11}, TNode<Smi>{tmp12});
    ca_.Branch(tmp13, &block9, std::vector<compiler::Node*>{}, &block10, std::vector<compiler::Node*>{});
  }

  TNode<Oddball> tmp14;
  if (block9.is_used()) {
    ca_.Bind(&block9);
    ca_.SetSourcePosition("../../../src/builtins/array-shift.tq", 16);
    tmp14 = Undefined_0(state_);
    ca_.Goto(&block3, tmp14);
  }

  TNode<Smi> tmp15;
  TNode<Smi> tmp16;
  TNode<Smi> tmp17;
  TNode<Smi> tmp18;
  TNode<Smi> tmp19;
  TNode<Smi> tmp20;
  TNode<IntPtrT> tmp21;
  TNode<FixedArrayBase> tmp22;
  TNode<IntPtrT> tmp23;
  TNode<Smi> tmp24;
  TNode<BoolT> tmp25;
  if (block10.is_used()) {
    ca_.Bind(&block10);
    ca_.SetSourcePosition("../../../src/builtins/array-shift.tq", 19);
    tmp15 = CodeStubAssembler(state_).LoadFastJSArrayLength(TNode<JSArray>{tmp0});
    tmp16 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp17 = CodeStubAssembler(state_).SmiSub(TNode<Smi>{tmp15}, TNode<Smi>{tmp16});
    ca_.SetSourcePosition("../../../src/builtins/array-shift.tq", 23);
    tmp18 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp17}, TNode<Smi>{tmp17});
    tmp19 = FromConstexpr_Smi_constexpr_int31_0(state_, JSObject::kMinAddedElementsCapacity);
    tmp20 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp18}, TNode<Smi>{tmp19});
    ca_.SetSourcePosition("../../../src/builtins/array-shift.tq", 24);
    tmp21 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp22 = CodeStubAssembler(state_).LoadReference<FixedArrayBase>(CodeStubAssembler::Reference{tmp0, tmp21});
    tmp23 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp24 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp22, tmp23});
    ca_.SetSourcePosition("../../../src/builtins/array-shift.tq", 23);
    tmp25 = CodeStubAssembler(state_).SmiLessThan(TNode<Smi>{tmp20}, TNode<Smi>{tmp24});
    ca_.Branch(tmp25, &block11, std::vector<compiler::Node*>{}, &block12, std::vector<compiler::Node*>{});
  }

  if (block11.is_used()) {
    ca_.Bind(&block11);
    ca_.SetSourcePosition("../../../src/builtins/array-shift.tq", 25);
    ca_.Goto(&block2);
  }

  TNode<Smi> tmp26;
  TNode<BoolT> tmp27;
  if (block12.is_used()) {
    ca_.Bind(&block12);
    ca_.SetSourcePosition("../../../src/builtins/array-shift.tq", 30);
    tmp26 = FromConstexpr_Smi_constexpr_int31_0(state_, JSArray::kMaxCopyElements);
    tmp27 = CodeStubAssembler(state_).SmiGreaterThan(TNode<Smi>{tmp17}, TNode<Smi>{tmp26});
    ca_.Branch(tmp27, &block13, std::vector<compiler::Node*>{}, &block14, std::vector<compiler::Node*>{});
  }

  if (block13.is_used()) {
    ca_.Bind(&block13);
    ca_.Goto(&block2);
  }

  TNode<Smi> tmp28;
  if (block14.is_used()) {
    ca_.Bind(&block14);
    ca_.SetSourcePosition("../../../src/builtins/array-shift.tq", 32);
    tmp28 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    ca_.SetSourcePosition("../../../src/objects/js-array.tq", 227);
    ca_.Branch(tmp5, &block19, std::vector<compiler::Node*>{}, &block20, std::vector<compiler::Node*>{});
  }

  TNode<Object> tmp29;
  if (block19.is_used()) {
    ca_.Bind(&block19);
    ca_.SetSourcePosition("../../../src/objects/js-array.tq", 228);
    compiler::CodeAssemblerLabel label30(&ca_);
    tmp29 = LoadElementNoHole_FixedDoubleArray_0(state_, TNode<Context>{p_context}, TNode<JSArray>{tmp3}, TNode<Smi>{tmp28}, &label30);
    ca_.Goto(&block22);
    if (label30.is_used()) {
      ca_.Bind(&label30);
      ca_.Goto(&block23);
    }
  }

  if (block23.is_used()) {
    ca_.Bind(&block23);
    ca_.Goto(&block17);
  }

  if (block22.is_used()) {
    ca_.Bind(&block22);
    ca_.Goto(&block18, tmp29);
  }

  TNode<Object> tmp31;
  if (block20.is_used()) {
    ca_.Bind(&block20);
    ca_.SetSourcePosition("../../../src/objects/js-array.tq", 231);
    compiler::CodeAssemblerLabel label32(&ca_);
    tmp31 = LoadElementNoHole_FixedArray_0(state_, TNode<Context>{p_context}, TNode<JSArray>{tmp3}, TNode<Smi>{tmp28}, &label32);
    ca_.Goto(&block24);
    if (label32.is_used()) {
      ca_.Bind(&label32);
      ca_.Goto(&block25);
    }
  }

  if (block25.is_used()) {
    ca_.Bind(&block25);
    ca_.Goto(&block17);
  }

  if (block24.is_used()) {
    ca_.Bind(&block24);
    ca_.Goto(&block18, tmp31);
  }

  TNode<Object> phi_bb18_17;
  if (block18.is_used()) {
    ca_.Bind(&block18, &phi_bb18_17);
    ca_.SetSourcePosition("../../../src/objects/js-array.tq", 250);
    ca_.Goto(&block15, phi_bb18_17);
  }

  TNode<Oddball> tmp33;
  if (block17.is_used()) {
    ca_.Bind(&block17);
    ca_.SetSourcePosition("../../../src/objects/js-array.tq", 252);
    tmp33 = Undefined_0(state_);
    ca_.Goto(&block15, tmp33);
  }

  TNode<Object> phi_bb15_13;
  if (block15.is_used()) {
    ca_.Bind(&block15, &phi_bb15_13);
    ca_.SetSourcePosition("../../../src/objects/js-array.tq", 263);
    ca_.Branch(tmp10, &block27, std::vector<compiler::Node*>{}, &block28, std::vector<compiler::Node*>{});
  }

  if (block28.is_used()) {
    ca_.Bind(&block28);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/objects/js-array.tq", 263});
      CodeStubAssembler(state_).FailAssert("Torque assert 'this.arrayIsPushable' failed", pos_stack);
    }
  }

  TNode<IntPtrT> tmp34;
  TNode<IntPtrT> tmp35;
  TNode<IntPtrT> tmp36;
  if (block27.is_used()) {
    ca_.Bind(&block27);
    ca_.SetSourcePosition("../../../src/objects/js-array.tq", 264);
    StoreFastJSArrayLength_0(state_, TNode<JSArray>{tmp3}, TNode<Smi>{tmp17});
    ca_.SetSourcePosition("../../../src/builtins/array-shift.tq", 34);
    tmp34 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp17});
    tmp35 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp36 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    ca_.SetSourcePosition("../../../src/objects/js-array.tq", 286);
    ca_.Branch(tmp10, &block30, std::vector<compiler::Node*>{}, &block31, std::vector<compiler::Node*>{});
  }

  if (block31.is_used()) {
    ca_.Bind(&block31);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/objects/js-array.tq", 286});
      CodeStubAssembler(state_).FailAssert("Torque assert 'this.arrayIsPushable' failed", pos_stack);
    }
  }

  if (block30.is_used()) {
    ca_.Bind(&block30);
    ca_.SetSourcePosition("../../../src/objects/js-array.tq", 287);
    ca_.Branch(tmp5, &block32, std::vector<compiler::Node*>{}, &block33, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp37;
  TNode<FixedArrayBase> tmp38;
  TNode<FixedDoubleArray> tmp39;
  if (block32.is_used()) {
    ca_.Bind(&block32);
    ca_.SetSourcePosition("../../../src/objects/js-array.tq", 289);
    tmp37 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp38 = CodeStubAssembler(state_).LoadReference<FixedArrayBase>(CodeStubAssembler::Reference{tmp3, tmp37});
    compiler::CodeAssemblerLabel label40(&ca_);
    tmp39 = Cast_FixedDoubleArray_0(state_, TNode<HeapObject>{tmp38}, &label40);
    ca_.Goto(&block37);
    if (label40.is_used()) {
      ca_.Bind(&label40);
      ca_.Goto(&block38);
    }
  }

  if (block38.is_used()) {
    ca_.Bind(&block38);
    ca_.SetSourcePosition("../../../src/objects/js-array.tq", 290);
    CodeStubAssembler(state_).PrintErr("halting because of unreachable code at src/objects/js-array.tq:290:21");
    CodeStubAssembler(state_).Unreachable();
  }

  if (block37.is_used()) {
    ca_.Bind(&block37);
    ca_.SetSourcePosition("../../../src/objects/js-array.tq", 291);
    TorqueMoveElements_1(state_, TNode<FixedDoubleArray>{tmp39}, TNode<IntPtrT>{tmp35}, TNode<IntPtrT>{tmp36}, TNode<IntPtrT>{tmp34});
    ca_.SetSourcePosition("../../../src/objects/js-array.tq", 287);
    ca_.Goto(&block34);
  }

  TNode<IntPtrT> tmp41;
  TNode<FixedArrayBase> tmp42;
  TNode<FixedArray> tmp43;
  if (block33.is_used()) {
    ca_.Bind(&block33);
    ca_.SetSourcePosition("../../../src/objects/js-array.tq", 293);
    tmp41 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp42 = CodeStubAssembler(state_).LoadReference<FixedArrayBase>(CodeStubAssembler::Reference{tmp3, tmp41});
    compiler::CodeAssemblerLabel label44(&ca_);
    tmp43 = Cast_FixedArray_0(state_, TNode<HeapObject>{tmp42}, &label44);
    ca_.Goto(&block41);
    if (label44.is_used()) {
      ca_.Bind(&label44);
      ca_.Goto(&block42);
    }
  }

  if (block42.is_used()) {
    ca_.Bind(&block42);
    ca_.SetSourcePosition("../../../src/objects/js-array.tq", 294);
    CodeStubAssembler(state_).PrintErr("halting because of unreachable code at src/objects/js-array.tq:294:21");
    CodeStubAssembler(state_).Unreachable();
  }

  if (block41.is_used()) {
    ca_.Bind(&block41);
    ca_.SetSourcePosition("../../../src/objects/js-array.tq", 295);
    ca_.Branch(tmp6, &block43, std::vector<compiler::Node*>{}, &block44, std::vector<compiler::Node*>{});
  }

  if (block43.is_used()) {
    ca_.Bind(&block43);
    ca_.SetSourcePosition("../../../src/objects/js-array.tq", 296);
    TorqueMoveElementsSmi_0(state_, TNode<FixedArray>{tmp43}, TNode<IntPtrT>{tmp35}, TNode<IntPtrT>{tmp36}, TNode<IntPtrT>{tmp34});
    ca_.SetSourcePosition("../../../src/objects/js-array.tq", 295);
    ca_.Goto(&block45);
  }

  if (block44.is_used()) {
    ca_.Bind(&block44);
    ca_.SetSourcePosition("../../../src/objects/js-array.tq", 298);
    TorqueMoveElements_0(state_, TNode<FixedArray>{tmp43}, TNode<IntPtrT>{tmp35}, TNode<IntPtrT>{tmp36}, TNode<IntPtrT>{tmp34});
    ca_.SetSourcePosition("../../../src/objects/js-array.tq", 295);
    ca_.Goto(&block45);
  }

  if (block45.is_used()) {
    ca_.Bind(&block45);
    ca_.SetSourcePosition("../../../src/objects/js-array.tq", 287);
    ca_.Goto(&block34);
  }

  if (block34.is_used()) {
    ca_.Bind(&block34);
    ca_.SetSourcePosition("../../../src/objects/js-array.tq", 237);
    ca_.Branch(tmp5, &block47, std::vector<compiler::Node*>{}, &block48, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp45;
  TNode<FixedArrayBase> tmp46;
  TNode<FixedDoubleArray> tmp47;
  if (block47.is_used()) {
    ca_.Bind(&block47);
    ca_.SetSourcePosition("../../../src/objects/js-array.tq", 238);
    tmp45 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp46 = CodeStubAssembler(state_).LoadReference<FixedArrayBase>(CodeStubAssembler::Reference{tmp3, tmp45});
    compiler::CodeAssemblerLabel label48(&ca_);
    tmp47 = Cast_FixedDoubleArray_0(state_, TNode<HeapObject>{tmp46}, &label48);
    ca_.Goto(&block52);
    if (label48.is_used()) {
      ca_.Bind(&label48);
      ca_.Goto(&block53);
    }
  }

  if (block53.is_used()) {
    ca_.Bind(&block53);
    ca_.SetSourcePosition("../../../src/objects/js-array.tq", 239);
    CodeStubAssembler(state_).PrintErr("halting because of unreachable code at src/objects/js-array.tq:239:21");
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<Object> tmp49;
  TNode<IntPtrT> tmp50;
  TNode<IntPtrT> tmp51;
  TNode<IntPtrT> tmp52;
  TNode<UintPtrT> tmp53;
  TNode<UintPtrT> tmp54;
  TNode<BoolT> tmp55;
  if (block52.is_used()) {
    ca_.Bind(&block52);
    ca_.SetSourcePosition("../../../src/objects/js-array.tq", 240);
    std::tie(tmp49, tmp50, tmp51) = FieldSliceFixedDoubleArrayFloats_0(state_, TNode<FixedDoubleArray>{tmp47}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 118);
    tmp52 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp17});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 89);
    tmp53 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp52});
    tmp54 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp51});
    tmp55 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp53}, TNode<UintPtrT>{tmp54});
    ca_.Branch(tmp55, &block58, std::vector<compiler::Node*>{}, &block59, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp56;
  TNode<IntPtrT> tmp57;
  TNode<Object> tmp58;
  TNode<IntPtrT> tmp59;
  TNode<BoolT> tmp60;
  TNode<Float64T> tmp61;
  if (block58.is_used()) {
    ca_.Bind(&block58);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 97);
    tmp56 = TimesSizeOf_float64_or_hole_0(state_, TNode<IntPtrT>{tmp52});
    tmp57 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp50}, TNode<IntPtrT>{tmp56});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 96);
    std::tie(tmp58, tmp59) = NewReference_float64_or_hole_0(state_, TNode<Object>{tmp49}, TNode<IntPtrT>{tmp57}).Flatten();
    ca_.SetSourcePosition("../../../src/objects/js-array.tq", 240);
    std::tie(tmp60, tmp61) = kDoubleHole_0(state_).Flatten();
    StoreFloat64OrHole_0(state_, TorqueStructReference_float64_or_hole_0{TNode<Object>{tmp58}, TNode<IntPtrT>{tmp59}, TorqueStructUnsafe_0{}}, TorqueStructfloat64_or_hole_0{TNode<BoolT>{tmp60}, TNode<Float64T>{tmp61}});
    ca_.SetSourcePosition("../../../src/objects/js-array.tq", 237);
    ca_.Goto(&block49);
  }

  if (block59.is_used()) {
    ca_.Bind(&block59);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 119);
    CodeStubAssembler(state_).PrintErr("halting because of unreachable code at src/builtins/torque-internal.tq:119:41");
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<IntPtrT> tmp62;
  TNode<FixedArrayBase> tmp63;
  TNode<FixedArray> tmp64;
  if (block48.is_used()) {
    ca_.Bind(&block48);
    ca_.SetSourcePosition("../../../src/objects/js-array.tq", 242);
    tmp62 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp63 = CodeStubAssembler(state_).LoadReference<FixedArrayBase>(CodeStubAssembler::Reference{tmp3, tmp62});
    compiler::CodeAssemblerLabel label65(&ca_);
    tmp64 = Cast_FixedArray_0(state_, TNode<HeapObject>{tmp63}, &label65);
    ca_.Goto(&block64);
    if (label65.is_used()) {
      ca_.Bind(&label65);
      ca_.Goto(&block65);
    }
  }

  if (block65.is_used()) {
    ca_.Bind(&block65);
    ca_.SetSourcePosition("../../../src/objects/js-array.tq", 243);
    CodeStubAssembler(state_).PrintErr("halting because of unreachable code at src/objects/js-array.tq:243:21");
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<Object> tmp66;
  TNode<IntPtrT> tmp67;
  TNode<IntPtrT> tmp68;
  TNode<IntPtrT> tmp69;
  TNode<UintPtrT> tmp70;
  TNode<UintPtrT> tmp71;
  TNode<BoolT> tmp72;
  if (block64.is_used()) {
    ca_.Bind(&block64);
    ca_.SetSourcePosition("../../../src/objects/js-array.tq", 244);
    std::tie(tmp66, tmp67, tmp68) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray>{tmp64}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 118);
    tmp69 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp17});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 89);
    tmp70 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp69});
    tmp71 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp68});
    tmp72 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp70}, TNode<UintPtrT>{tmp71});
    ca_.Branch(tmp72, &block70, std::vector<compiler::Node*>{}, &block71, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp73;
  TNode<IntPtrT> tmp74;
  TNode<Object> tmp75;
  TNode<IntPtrT> tmp76;
  TNode<Oddball> tmp77;
  if (block70.is_used()) {
    ca_.Bind(&block70);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 97);
    tmp73 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{tmp69});
    tmp74 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp67}, TNode<IntPtrT>{tmp73});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 96);
    std::tie(tmp75, tmp76) = NewReference_Object_0(state_, TNode<Object>{tmp66}, TNode<IntPtrT>{tmp74}).Flatten();
    ca_.SetSourcePosition("../../../src/objects/js-array.tq", 244);
    tmp77 = TheHole_0(state_);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp75, tmp76}, tmp77);
    ca_.SetSourcePosition("../../../src/objects/js-array.tq", 237);
    ca_.Goto(&block49);
  }

  if (block71.is_used()) {
    ca_.Bind(&block71);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 119);
    CodeStubAssembler(state_).PrintErr("halting because of unreachable code at src/builtins/torque-internal.tq:119:41");
    CodeStubAssembler(state_).Unreachable();
  }

  if (block49.is_used()) {
    ca_.Bind(&block49);
    ca_.SetSourcePosition("../../../src/builtins/array-shift.tq", 36);
    ca_.Goto(&block3, phi_bb15_13);
  }

  TNode<Object> phi_bb3_2;
  if (block3.is_used()) {
    ca_.Bind(&block3, &phi_bb3_2);
    ca_.SetSourcePosition("../../../src/builtins/array-shift.tq", 8);
    ca_.Goto(&block74, phi_bb3_2);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_Slow);
  }

  if (block2.is_used()) {
    ca_.Bind(&block2);
    ca_.Goto(label_Runtime);
  }

  TNode<Object> phi_bb74_2;
    ca_.Bind(&block74, &phi_bb74_2);
  return TNode<Object>{phi_bb74_2};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-shift.tq?l=39&c=1
TNode<Object> GenericArrayShift_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_receiver) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, Number> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, Number> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, Number> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<JSReceiver> tmp0;
  TNode<Number> tmp1;
  TNode<Number> tmp2;
  TNode<BoolT> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/array-shift.tq", 42);
    tmp0 = CodeStubAssembler(state_).ToObject_Inline(TNode<Context>{p_context}, TNode<Object>{p_receiver});
    ca_.SetSourcePosition("../../../src/builtins/array-shift.tq", 45);
    tmp1 = GetLengthProperty_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp0});
    ca_.SetSourcePosition("../../../src/builtins/array-shift.tq", 48);
    tmp2 = FromConstexpr_Number_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp3 = IsNumberEqual_0(state_, TNode<Number>{tmp1}, TNode<Number>{tmp2});
    ca_.Branch(tmp3, &block2, std::vector<compiler::Node*>{}, &block3, std::vector<compiler::Node*>{});
  }

  TNode<String> tmp4;
  TNode<Smi> tmp5;
  TNode<Object> tmp6;
  TNode<Oddball> tmp7;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    ca_.SetSourcePosition("../../../src/builtins/array-shift.tq", 50);
    tmp4 = kLengthString_0(state_);
    tmp5 = Convert_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp6 = ca_.CallStub<Object>(Builtins::CallableFor(ca_.isolate(), Builtin::kSetProperty), p_context, tmp0, tmp4, tmp5);
    ca_.SetSourcePosition("../../../src/builtins/array-shift.tq", 52);
    tmp7 = Undefined_0(state_);
    ca_.Goto(&block1, tmp7);
  }

  TNode<Smi> tmp8;
  TNode<Object> tmp9;
  TNode<Number> tmp10;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    ca_.SetSourcePosition("../../../src/builtins/array-shift.tq", 56);
    tmp8 = Convert_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp9 = CodeStubAssembler(state_).GetProperty(TNode<Context>{p_context}, TNode<Object>{tmp0}, TNode<Object>{tmp8});
    ca_.SetSourcePosition("../../../src/builtins/array-shift.tq", 58);
    tmp10 = FromConstexpr_Number_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    ca_.SetSourcePosition("../../../src/builtins/array-shift.tq", 60);
    ca_.Goto(&block6, tmp10);
  }

  TNode<Number> phi_bb6_5;
  TNode<BoolT> tmp11;
  if (block6.is_used()) {
    ca_.Bind(&block6, &phi_bb6_5);
    tmp11 = NumberIsLessThan_0(state_, TNode<Number>{phi_bb6_5}, TNode<Number>{tmp1});
    ca_.Branch(tmp11, &block4, std::vector<compiler::Node*>{phi_bb6_5}, &block5, std::vector<compiler::Node*>{phi_bb6_5});
  }

  TNode<Number> phi_bb4_5;
  TNode<Number> tmp12;
  TNode<Number> tmp13;
  TNode<Oddball> tmp14;
  TNode<Oddball> tmp15;
  TNode<BoolT> tmp16;
  if (block4.is_used()) {
    ca_.Bind(&block4, &phi_bb4_5);
    ca_.SetSourcePosition("../../../src/builtins/array-shift.tq", 65);
    tmp12 = FromConstexpr_Number_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp13 = CodeStubAssembler(state_).NumberSub(TNode<Number>{phi_bb4_5}, TNode<Number>{tmp12});
    ca_.SetSourcePosition("../../../src/builtins/array-shift.tq", 68);
    tmp14 = ca_.CallStub<Oddball>(Builtins::CallableFor(ca_.isolate(), Builtin::kHasProperty), p_context, tmp0, phi_bb4_5);
    ca_.SetSourcePosition("../../../src/builtins/array-shift.tq", 71);
    tmp15 = True_0(state_);
    tmp16 = CodeStubAssembler(state_).TaggedEqual(TNode<HeapObject>{tmp14}, TNode<HeapObject>{tmp15});
    ca_.Branch(tmp16, &block7, std::vector<compiler::Node*>{phi_bb4_5, phi_bb4_5}, &block8, std::vector<compiler::Node*>{phi_bb4_5, phi_bb4_5});
  }

  TNode<Number> phi_bb7_5;
  TNode<Number> phi_bb7_6;
  TNode<Object> tmp17;
  TNode<Object> tmp18;
  if (block7.is_used()) {
    ca_.Bind(&block7, &phi_bb7_5, &phi_bb7_6);
    ca_.SetSourcePosition("../../../src/builtins/array-shift.tq", 73);
    tmp17 = CodeStubAssembler(state_).GetProperty(TNode<Context>{p_context}, TNode<Object>{tmp0}, TNode<Object>{phi_bb7_6});
    ca_.SetSourcePosition("../../../src/builtins/array-shift.tq", 76);
    tmp18 = ca_.CallStub<Object>(Builtins::CallableFor(ca_.isolate(), Builtin::kSetProperty), p_context, tmp0, tmp13, tmp17);
    ca_.SetSourcePosition("../../../src/builtins/array-shift.tq", 71);
    ca_.Goto(&block9, phi_bb7_5, phi_bb7_6);
  }

  TNode<Number> phi_bb8_5;
  TNode<Number> phi_bb8_6;
  TNode<Smi> tmp19;
  TNode<Oddball> tmp20;
  if (block8.is_used()) {
    ca_.Bind(&block8, &phi_bb8_5, &phi_bb8_6);
    ca_.SetSourcePosition("../../../src/builtins/array-shift.tq", 79);
    tmp19 = FromConstexpr_LanguageModeSmi_constexpr_LanguageMode_0(state_, LanguageMode::kStrict);
    tmp20 = ca_.CallStub<Oddball>(Builtins::CallableFor(ca_.isolate(), Builtin::kDeleteProperty), p_context, tmp0, tmp13, tmp19);
    ca_.SetSourcePosition("../../../src/builtins/array-shift.tq", 71);
    ca_.Goto(&block9, phi_bb8_5, phi_bb8_6);
  }

  TNode<Number> phi_bb9_5;
  TNode<Number> phi_bb9_6;
  TNode<Number> tmp21;
  TNode<Number> tmp22;
  if (block9.is_used()) {
    ca_.Bind(&block9, &phi_bb9_5, &phi_bb9_6);
    ca_.SetSourcePosition("../../../src/builtins/array-shift.tq", 83);
    tmp21 = FromConstexpr_Number_constexpr_int31_0(state_, 1);
    tmp22 = CodeStubAssembler(state_).NumberAdd(TNode<Number>{phi_bb9_5}, TNode<Number>{tmp21});
    ca_.SetSourcePosition("../../../src/builtins/array-shift.tq", 60);
    ca_.Goto(&block6, tmp22);
  }

  TNode<Number> phi_bb5_5;
  TNode<Number> tmp23;
  TNode<Number> tmp24;
  TNode<Smi> tmp25;
  TNode<Oddball> tmp26;
  TNode<String> tmp27;
  TNode<Number> tmp28;
  TNode<Number> tmp29;
  TNode<Object> tmp30;
  if (block5.is_used()) {
    ca_.Bind(&block5, &phi_bb5_5);
    ca_.SetSourcePosition("../../../src/builtins/array-shift.tq", 87);
    tmp23 = FromConstexpr_Number_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp24 = CodeStubAssembler(state_).NumberSub(TNode<Number>{tmp1}, TNode<Number>{tmp23});
    tmp25 = FromConstexpr_LanguageModeSmi_constexpr_LanguageMode_0(state_, LanguageMode::kStrict);
    tmp26 = ca_.CallStub<Oddball>(Builtins::CallableFor(ca_.isolate(), Builtin::kDeleteProperty), p_context, tmp0, tmp24, tmp25);
    ca_.SetSourcePosition("../../../src/builtins/array-shift.tq", 90);
    tmp27 = kLengthString_0(state_);
    tmp28 = FromConstexpr_Number_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp29 = CodeStubAssembler(state_).NumberSub(TNode<Number>{tmp1}, TNode<Number>{tmp28});
    tmp30 = ca_.CallStub<Object>(Builtins::CallableFor(ca_.isolate(), Builtin::kSetProperty), p_context, tmp0, tmp27, tmp29);
    ca_.SetSourcePosition("../../../src/builtins/array-shift.tq", 93);
    ca_.Goto(&block1, tmp9);
  }

  TNode<Object> phi_bb1_2;
  if (block1.is_used()) {
    ca_.Bind(&block1, &phi_bb1_2);
    ca_.SetSourcePosition("../../../src/builtins/array-shift.tq", 39);
    ca_.Goto(&block10, phi_bb1_2);
  }

  TNode<Object> phi_bb10_2;
    ca_.Bind(&block10, &phi_bb10_2);
  return TNode<Object>{phi_bb10_2};
}

TF_BUILTIN(ArrayPrototypeShift, CodeStubAssembler) {
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
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Object> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/array-shift.tq", 100);
    compiler::CodeAssemblerLabel label1(&ca_);
    compiler::CodeAssemblerLabel label2(&ca_);
    tmp0 = TryFastArrayShift_0(state_, TNode<Context>{parameter0}, TNode<Object>{parameter1}, &label1, &label2);
    ca_.Goto(&block5);
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block6);
    }
    if (label2.is_used()) {
      ca_.Bind(&label2);
      ca_.Goto(&block7);
    }
  }

  TNode<Object> tmp3;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.SetSourcePosition("../../../src/builtins/array-shift.tq", 102);
    tmp3 = GenericArrayShift_0(state_, TNode<Context>{parameter0}, TNode<Object>{parameter1});
    arguments.PopAndReturn(tmp3);
  }

  TNode<JSFunction> tmp4;
  TNode<Oddball> tmp5;
  TNode<Int32T> tmp6;
  if (block7.is_used()) {
    ca_.Bind(&block7);
    ca_.SetSourcePosition("../../../src/builtins/array-shift.tq", 105);
    tmp4 = LoadTargetFromFrame_0(state_);
    tmp5 = Undefined_0(state_);
    ca_.SetSourcePosition("../../../src/builtins/array-shift.tq", 106);
    tmp6 = Convert_int32_intptr_0(state_, TNode<IntPtrT>{torque_arguments.actual_count});
    ca_.SetSourcePosition("../../../src/builtins/array-shift.tq", 104);
   CodeStubAssembler(state_).TailCallBuiltin(Builtin::kArrayShift, parameter0, tmp4, tmp5, tmp6);
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    ca_.SetSourcePosition("../../../src/builtins/array-shift.tq", 100);
    arguments.PopAndReturn(tmp0);
  }
}

} // namespace internal
} // namespace v8
