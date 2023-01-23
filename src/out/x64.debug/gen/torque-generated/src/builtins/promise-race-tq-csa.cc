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
#include "torque-generated/src/builtins/promise-race-tq-csa.h"
#include "torque-generated/src/builtins/array-every-tq-csa.h"
#include "torque-generated/src/builtins/array-join-tq-csa.h"
#include "torque-generated/src/builtins/base-tq-csa.h"
#include "torque-generated/src/builtins/convert-tq-csa.h"
#include "torque-generated/src/builtins/iterator-tq-csa.h"
#include "torque-generated/src/builtins/promise-abstract-operations-tq-csa.h"
#include "torque-generated/src/builtins/promise-any-tq-csa.h"
#include "torque-generated/src/builtins/promise-constructor-tq-csa.h"
#include "torque-generated/src/builtins/promise-race-tq-csa.h"
#include "torque-generated/src/builtins/promise-resolve-tq-csa.h"
#include "torque-generated/src/builtins/torque-internal-tq-csa.h"
#include "torque-generated/src/objects/contexts-tq-csa.h"
#include "torque-generated/src/objects/js-promise-tq-csa.h"

namespace v8 {
namespace internal {

TF_BUILTIN(PromiseRace, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kReceiver);
  USE(parameter1);
  TNode<Object> parameter2 = UncheckedParameter<Object>(Descriptor::kIterable);
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object, HeapObject> block14(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block19(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block23(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block30(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block29(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block28(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block31(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, HeapObject> block25(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block32(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block33(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block34(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block35(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block36(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block39(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block40(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block43(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block44(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block41(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block45(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block42(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block37(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block46(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block38(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, HeapObject> block18(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block12(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    ca_.Goto(&block0);

  TNode<JSReceiver> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/promise-race.tq", 13);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = Cast_JSReceiver_1(state_, TNode<Context>{parameter0}, TNode<Object>{parameter1}, &label1);
    ca_.Goto(&block3);
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block4);
    }
  }

  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.SetSourcePosition("../../../src/builtins/promise-race.tq", 14);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{parameter0}, MessageTemplate::kCalledOnNonObject, "Promise.race");
  }

  TNode<BoolT> tmp2;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    ca_.SetSourcePosition("../../../src/builtins/promise-race.tq", 18);
    tmp2 = Is_NativeContext_Context_0(state_, TNode<Context>{parameter0}, TNode<Context>{parameter0});
    ca_.Branch(tmp2, &block5, std::vector<compiler::Node*>{}, &block6, std::vector<compiler::Node*>{});
  }

  if (block6.is_used()) {
    ca_.Bind(&block6);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/promise-race.tq", 18});
      CodeStubAssembler(state_).FailAssert("Torque assert 'Is<NativeContext>(context)' failed", pos_stack);
    }
  }

  TNode<NativeContext> tmp3;
  TNode<Oddball> tmp4;
  TNode<PromiseCapability> tmp5;
  TNode<IntPtrT> tmp6;
  TNode<Object> tmp7;
  TNode<IntPtrT> tmp8;
  TNode<Object> tmp9;
  TNode<IntPtrT> tmp10;
  TNode<HeapObject> tmp11;
  TNode<BoolT> tmp12;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    ca_.SetSourcePosition("../../../src/builtins/promise-race.tq", 19);
    tmp3 = UnsafeCast_NativeContext_0(state_, TNode<Context>{parameter0}, TNode<Object>{parameter0});
    ca_.SetSourcePosition("../../../src/builtins/promise-race.tq", 24);
    tmp4 = False_0(state_);
    tmp5 = ca_.CallStub<PromiseCapability>(Builtins::CallableFor(ca_.isolate(), Builtin::kNewPromiseCapability), parameter0, tmp0, tmp4);
    ca_.SetSourcePosition("../../../src/builtins/promise-race.tq", 25);
    tmp6 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp7 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp5, tmp6});
    ca_.SetSourcePosition("../../../src/builtins/promise-race.tq", 26);
    tmp8 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp9 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp5, tmp8});
    ca_.SetSourcePosition("../../../src/builtins/promise-race.tq", 27);
    tmp10 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp11 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{tmp5, tmp10});
    ca_.SetSourcePosition("../../../src/builtins/promise-race.tq", 30);
    tmp12 = Is_Constructor_JSReceiver_0(state_, TNode<Context>{parameter0}, TNode<JSReceiver>{tmp0});
    ca_.Branch(tmp12, &block7, std::vector<compiler::Node*>{}, &block8, std::vector<compiler::Node*>{});
  }

  if (block8.is_used()) {
    ca_.Bind(&block8);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/promise-race.tq", 30});
      CodeStubAssembler(state_).FailAssert("Torque assert 'Is<Constructor>(receiver)' failed", pos_stack);
    }
  }

  TNode<JSReceiver> tmp13;
  TNode<BoolT> tmp14;
  if (block7.is_used()) {
    ca_.Bind(&block7);
    ca_.SetSourcePosition("../../../src/builtins/promise-race.tq", 31);
    tmp13 = UnsafeCast_Constructor_0(state_, TNode<Context>{parameter0}, TNode<Object>{tmp0});
    ca_.SetSourcePosition("../../../src/builtins/promise-race.tq", 35);
    tmp14 = CodeStubAssembler(state_).IsDebugActive();
    ca_.Branch(tmp14, &block9, std::vector<compiler::Node*>{}, &block10, std::vector<compiler::Node*>{});
  }

  TNode<Symbol> tmp15;
  TNode<Oddball> tmp16;
  TNode<Object> tmp17;
  if (block9.is_used()) {
    ca_.Bind(&block9);
    ca_.SetSourcePosition("../../../src/builtins/promise-race.tq", 36);
    tmp15 = kPromiseForwardingHandlerSymbol_0(state_);
    tmp16 = True_0(state_);
    tmp17 = CodeStubAssembler(state_).SetPropertyStrict(TNode<Context>{parameter0}, TNode<Object>{tmp9}, TNode<Object>{tmp15}, TNode<Object>{tmp16});
    ca_.SetSourcePosition("../../../src/builtins/promise-race.tq", 35);
    ca_.Goto(&block10);
  }

  TNode<Object> tmp18;
      TNode<Object> tmp20;
  TNode<JSReceiver> tmp21;
  TNode<Object> tmp22;
      TNode<Object> tmp24;
  TNode<IntPtrT> tmp25;
  TNode<Object> tmp26;
  TNode<IntPtrT> tmp27;
      TNode<Object> tmp29;
  TNode<Map> tmp30;
  if (block10.is_used()) {
    ca_.Bind(&block10);
    ca_.SetSourcePosition("../../../src/builtins/promise-race.tq", 45);
    compiler::CodeAssemblerExceptionHandlerLabel catch19__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch19__label);
    tmp18 = GetPromiseResolve_0(state_, TNode<Context>{parameter0}, TNode<NativeContext>{tmp3}, TNode<JSReceiver>{tmp13});
    }
    if (catch19__label.is_used()) {
      compiler::CodeAssemblerLabel catch19_skip(&ca_);
      ca_.Goto(&catch19_skip);
      ca_.Bind(&catch19__label, &tmp20);
      ca_.Goto(&block15);
      ca_.Bind(&catch19_skip);
    }
    ca_.SetSourcePosition("../../../src/builtins/promise-race.tq", 49);
    compiler::CodeAssemblerExceptionHandlerLabel catch23__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch23__label);
    std::tie(tmp21, tmp22) = IteratorBuiltinsAssembler(state_).GetIterator(TNode<Context>{parameter0}, TNode<Object>{parameter2}).Flatten();
    }
    if (catch23__label.is_used()) {
      compiler::CodeAssemblerLabel catch23_skip(&ca_);
      ca_.Goto(&catch23_skip);
      ca_.Bind(&catch23__label, &tmp24);
      ca_.Goto(&block16);
      ca_.Bind(&catch23_skip);
    }
    ca_.SetSourcePosition("../../../src/builtins/promise-race.tq", 57);
    tmp25 = ITERATOR_RESULT_MAP_INDEX_0(state_);
    ca_.SetSourcePosition("../../../src/builtins/promise-race.tq", 56);
    compiler::CodeAssemblerExceptionHandlerLabel catch28__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch28__label);
    std::tie(tmp26, tmp27) = NativeContextSlot_Map_1(state_, TNode<NativeContext>{tmp3}, TNode<IntPtrT>{tmp25}).Flatten();
    }
    if (catch28__label.is_used()) {
      compiler::CodeAssemblerLabel catch28_skip(&ca_);
      ca_.Goto(&catch28_skip);
      ca_.Bind(&catch28__label, &tmp29);
      ca_.Goto(&block19);
      ca_.Bind(&catch28_skip);
    }
    tmp30 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference{tmp26, tmp27});
    ca_.SetSourcePosition("../../../src/builtins/promise-race.tq", 58);
    ca_.Goto(&block22);
  }

  TNode<HeapObject> tmp31;
  if (block15.is_used()) {
    ca_.Bind(&block15);
    ca_.SetSourcePosition("../../../src/builtins/promise-race.tq", 45);
    tmp31 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block14, ca_.Uninitialized<Object>(), tmp20, tmp31);
  }

  TNode<HeapObject> tmp32;
  if (block16.is_used()) {
    ca_.Bind(&block16);
    ca_.SetSourcePosition("../../../src/builtins/promise-race.tq", 49);
    tmp32 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block14, tmp18, tmp24, tmp32);
  }

  TNode<Object> phi_bb14_10;
  TNode<Object> phi_bb14_13;
  TNode<HeapObject> phi_bb14_14;
  if (block14.is_used()) {
    ca_.Bind(&block14, &phi_bb14_10, &phi_bb14_13, &phi_bb14_14);
    ca_.SetSourcePosition("../../../src/builtins/promise-race.tq", 51);
    ca_.Goto(&block12, phi_bb14_13);
  }

  TNode<HeapObject> tmp33;
  if (block19.is_used()) {
    ca_.Bind(&block19);
    ca_.SetSourcePosition("../../../src/builtins/promise-race.tq", 56);
    tmp33 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block18, tmp29, tmp33);
  }

  TNode<BoolT> tmp34;
      TNode<Object> tmp36;
  if (block22.is_used()) {
    ca_.Bind(&block22);
    ca_.SetSourcePosition("../../../src/builtins/promise-race.tq", 58);
    compiler::CodeAssemblerExceptionHandlerLabel catch35__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch35__label);
    tmp34 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    }
    if (catch35__label.is_used()) {
      compiler::CodeAssemblerLabel catch35_skip(&ca_);
      ca_.Goto(&catch35_skip);
      ca_.Bind(&catch35__label, &tmp36);
      ca_.Goto(&block23);
      ca_.Bind(&catch35_skip);
    }
    ca_.Branch(tmp34, &block20, std::vector<compiler::Node*>{}, &block21, std::vector<compiler::Node*>{});
  }

  TNode<HeapObject> tmp37;
  if (block23.is_used()) {
    ca_.Bind(&block23);
    tmp37 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block18, tmp36, tmp37);
  }

  TNode<JSReceiver> tmp38;
      TNode<Object> tmp41;
  if (block20.is_used()) {
    ca_.Bind(&block20);
    ca_.SetSourcePosition("../../../src/builtins/promise-race.tq", 64);
    compiler::CodeAssemblerLabel label39(&ca_);
    compiler::CodeAssemblerExceptionHandlerLabel catch40__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch40__label);
    tmp38 = IteratorBuiltinsAssembler(state_).IteratorStep(TNode<Context>{parameter0}, TorqueStructIteratorRecord{TNode<JSReceiver>{tmp21}, TNode<Object>{tmp22}}, TNode<Map>{tmp30}, &label39);
    }
    if (catch40__label.is_used()) {
      compiler::CodeAssemblerLabel catch40_skip(&ca_);
      ca_.Goto(&catch40_skip);
      ca_.Bind(&catch40__label, &tmp41);
      ca_.Goto(&block30);
      ca_.Bind(&catch40_skip);
    }
    ca_.Goto(&block28);
    if (label39.is_used()) {
      ca_.Bind(&label39);
      ca_.Goto(&block29);
    }
  }

  TNode<HeapObject> tmp42;
  if (block30.is_used()) {
    ca_.Bind(&block30);
    tmp42 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block25, tmp41, tmp42);
  }

  if (block29.is_used()) {
    ca_.Bind(&block29);
    ca_.SetSourcePosition("../../../src/builtins/promise-race.tq", 65);
    CodeStubAssembler(state_).Return(tmp11);
  }

  TNode<Object> tmp43;
      TNode<Object> tmp45;
  TNode<Object> tmp46;
      TNode<Object> tmp48;
  TNode<String> tmp49;
  TNode<Object> tmp50;
      TNode<Object> tmp52;
  TNode<Object> tmp53;
      TNode<Object> tmp55;
  TNode<Object> tmp56;
      TNode<Object> tmp58;
  TNode<Object> tmp59;
      TNode<Object> tmp61;
  TNode<BoolT> tmp62;
      TNode<Object> tmp64;
  if (block28.is_used()) {
    ca_.Bind(&block28);
    ca_.SetSourcePosition("../../../src/builtins/promise-race.tq", 71);
    compiler::CodeAssemblerExceptionHandlerLabel catch44__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch44__label);
    tmp43 = IteratorBuiltinsAssembler(state_).IteratorValue(TNode<Context>{parameter0}, TNode<JSReceiver>{tmp38}, TNode<Map>{tmp30});
    }
    if (catch44__label.is_used()) {
      compiler::CodeAssemblerLabel catch44_skip(&ca_);
      ca_.Goto(&catch44_skip);
      ca_.Bind(&catch44__label, &tmp45);
      ca_.Goto(&block31);
      ca_.Bind(&catch44_skip);
    }
    ca_.SetSourcePosition("../../../src/builtins/promise-race.tq", 78);
    compiler::CodeAssemblerExceptionHandlerLabel catch47__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch47__label);
    tmp46 = CallResolve_0(state_, TNode<Context>{parameter0}, TNode<JSReceiver>{tmp13}, TNode<Object>{tmp18}, TNode<Object>{tmp43});
    }
    if (catch47__label.is_used()) {
      compiler::CodeAssemblerLabel catch47_skip(&ca_);
      ca_.Goto(&catch47_skip);
      ca_.Bind(&catch47__label, &tmp48);
      ca_.Goto(&block32);
      ca_.Bind(&catch47_skip);
    }
    ca_.SetSourcePosition("../../../src/builtins/promise-race.tq", 82);
    tmp49 = kThenString_0(state_);
    compiler::CodeAssemblerExceptionHandlerLabel catch51__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch51__label);
    tmp50 = CodeStubAssembler(state_).GetProperty(TNode<Context>{parameter0}, TNode<Object>{tmp46}, TNode<Object>{tmp49});
    }
    if (catch51__label.is_used()) {
      compiler::CodeAssemblerLabel catch51_skip(&ca_);
      ca_.Goto(&catch51_skip);
      ca_.Bind(&catch51__label, &tmp52);
      ca_.Goto(&block33);
      ca_.Bind(&catch51_skip);
    }
    ca_.SetSourcePosition("../../../src/builtins/promise-race.tq", 84);
    compiler::CodeAssemblerExceptionHandlerLabel catch54__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch54__label);
    tmp53 = UnsafeCast_JSAny_0(state_, TNode<Context>{parameter0}, TNode<Object>{tmp7});
    }
    if (catch54__label.is_used()) {
      compiler::CodeAssemblerLabel catch54_skip(&ca_);
      ca_.Goto(&catch54_skip);
      ca_.Bind(&catch54__label, &tmp55);
      ca_.Goto(&block34);
      ca_.Bind(&catch54_skip);
    }
    ca_.SetSourcePosition("../../../src/builtins/promise-race.tq", 85);
    compiler::CodeAssemblerExceptionHandlerLabel catch57__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch57__label);
    tmp56 = UnsafeCast_JSAny_0(state_, TNode<Context>{parameter0}, TNode<Object>{tmp9});
    }
    if (catch57__label.is_used()) {
      compiler::CodeAssemblerLabel catch57_skip(&ca_);
      ca_.Goto(&catch57_skip);
      ca_.Bind(&catch57__label, &tmp58);
      ca_.Goto(&block35);
      ca_.Bind(&catch57_skip);
    }
    ca_.SetSourcePosition("../../../src/builtins/promise-race.tq", 83);
    compiler::CodeAssemblerExceptionHandlerLabel catch60__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch60__label);
    tmp59 = CodeStubAssembler(state_).Call(TNode<Context>{parameter0}, TNode<Object>{tmp50}, TNode<Object>{tmp46}, TNode<Object>{tmp53}, TNode<Object>{tmp56});
    }
    if (catch60__label.is_used()) {
      compiler::CodeAssemblerLabel catch60_skip(&ca_);
      ca_.Goto(&catch60_skip);
      ca_.Bind(&catch60__label, &tmp61);
      ca_.Goto(&block36);
      ca_.Bind(&catch60_skip);
    }
    ca_.SetSourcePosition("../../../src/builtins/promise-race.tq", 89);
    compiler::CodeAssemblerExceptionHandlerLabel catch63__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch63__label);
    tmp62 = CodeStubAssembler(state_).IsDebugActive();
    }
    if (catch63__label.is_used()) {
      compiler::CodeAssemblerLabel catch63_skip(&ca_);
      ca_.Goto(&catch63_skip);
      ca_.Bind(&catch63__label, &tmp64);
      ca_.Goto(&block39);
      ca_.Bind(&catch63_skip);
    }
    ca_.Branch(tmp62, &block40, std::vector<compiler::Node*>{}, &block41, std::vector<compiler::Node*>{});
  }

  TNode<HeapObject> tmp65;
  if (block31.is_used()) {
    ca_.Bind(&block31);
    ca_.SetSourcePosition("../../../src/builtins/promise-race.tq", 71);
    tmp65 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block25, tmp45, tmp65);
  }

  TNode<Object> phi_bb25_15;
  TNode<HeapObject> phi_bb25_16;
  if (block25.is_used()) {
    ca_.Bind(&block25, &phi_bb25_15, &phi_bb25_16);
    ca_.SetSourcePosition("../../../src/builtins/promise-race.tq", 73);
    ca_.Goto(&block12, phi_bb25_15);
  }

  TNode<HeapObject> tmp66;
  if (block32.is_used()) {
    ca_.Bind(&block32);
    ca_.SetSourcePosition("../../../src/builtins/promise-race.tq", 78);
    tmp66 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block18, tmp48, tmp66);
  }

  TNode<HeapObject> tmp67;
  if (block33.is_used()) {
    ca_.Bind(&block33);
    ca_.SetSourcePosition("../../../src/builtins/promise-race.tq", 82);
    tmp67 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block18, tmp52, tmp67);
  }

  TNode<HeapObject> tmp68;
  if (block34.is_used()) {
    ca_.Bind(&block34);
    ca_.SetSourcePosition("../../../src/builtins/promise-race.tq", 84);
    tmp68 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block18, tmp55, tmp68);
  }

  TNode<HeapObject> tmp69;
  if (block35.is_used()) {
    ca_.Bind(&block35);
    ca_.SetSourcePosition("../../../src/builtins/promise-race.tq", 85);
    tmp69 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block18, tmp58, tmp69);
  }

  TNode<HeapObject> tmp70;
  if (block36.is_used()) {
    ca_.Bind(&block36);
    ca_.SetSourcePosition("../../../src/builtins/promise-race.tq", 83);
    tmp70 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block18, tmp61, tmp70);
  }

  TNode<HeapObject> tmp71;
  if (block39.is_used()) {
    ca_.Bind(&block39);
    ca_.SetSourcePosition("../../../src/builtins/promise-race.tq", 89);
    tmp71 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block18, tmp64, tmp71);
  }

  TNode<BoolT> tmp72;
      TNode<Object> tmp74;
  TNode<BoolT> tmp75;
      TNode<Object> tmp77;
  if (block40.is_used()) {
    ca_.Bind(&block40);
    compiler::CodeAssemblerExceptionHandlerLabel catch73__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch73__label);
    tmp72 = Is_JSPromise_JSReceiver_OR_Undefined_0(state_, TNode<Context>{parameter0}, TNode<HeapObject>{tmp11});
    }
    if (catch73__label.is_used()) {
      compiler::CodeAssemblerLabel catch73_skip(&ca_);
      ca_.Goto(&catch73_skip);
      ca_.Bind(&catch73__label, &tmp74);
      ca_.Goto(&block43);
      ca_.Bind(&catch73_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch76__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch76__label);
    tmp75 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp72});
    }
    if (catch76__label.is_used()) {
      compiler::CodeAssemblerLabel catch76_skip(&ca_);
      ca_.Goto(&catch76_skip);
      ca_.Bind(&catch76__label, &tmp77);
      ca_.Goto(&block44);
      ca_.Bind(&catch76_skip);
    }
    ca_.Goto(&block42, tmp75);
  }

  TNode<HeapObject> tmp78;
  if (block43.is_used()) {
    ca_.Bind(&block43);
    tmp78 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block18, tmp74, tmp78);
  }

  TNode<HeapObject> tmp79;
  if (block44.is_used()) {
    ca_.Bind(&block44);
    tmp79 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block18, tmp77, tmp79);
  }

  TNode<BoolT> tmp80;
      TNode<Object> tmp82;
  if (block41.is_used()) {
    ca_.Bind(&block41);
    compiler::CodeAssemblerExceptionHandlerLabel catch81__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch81__label);
    tmp80 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    }
    if (catch81__label.is_used()) {
      compiler::CodeAssemblerLabel catch81_skip(&ca_);
      ca_.Goto(&catch81_skip);
      ca_.Bind(&catch81__label, &tmp82);
      ca_.Goto(&block45);
      ca_.Bind(&catch81_skip);
    }
    ca_.Goto(&block42, tmp80);
  }

  TNode<HeapObject> tmp83;
  if (block45.is_used()) {
    ca_.Bind(&block45);
    tmp83 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block18, tmp82, tmp83);
  }

  TNode<BoolT> phi_bb42_19;
  if (block42.is_used()) {
    ca_.Bind(&block42, &phi_bb42_19);
    ca_.Branch(phi_bb42_19, &block37, std::vector<compiler::Node*>{}, &block38, std::vector<compiler::Node*>{});
  }

  TNode<Symbol> tmp84;
  TNode<Object> tmp85;
      TNode<Object> tmp87;
  if (block37.is_used()) {
    ca_.Bind(&block37);
    ca_.SetSourcePosition("../../../src/builtins/promise-race.tq", 91);
    tmp84 = kPromiseHandledBySymbol_0(state_);
    ca_.SetSourcePosition("../../../src/builtins/promise-race.tq", 90);
    compiler::CodeAssemblerExceptionHandlerLabel catch86__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch86__label);
    tmp85 = CodeStubAssembler(state_).SetPropertyStrict(TNode<Context>{parameter0}, TNode<Object>{tmp59}, TNode<Object>{tmp84}, TNode<Object>{tmp11});
    }
    if (catch86__label.is_used()) {
      compiler::CodeAssemblerLabel catch86_skip(&ca_);
      ca_.Goto(&catch86_skip);
      ca_.Bind(&catch86__label, &tmp87);
      ca_.Goto(&block46);
      ca_.Bind(&catch86_skip);
    }
    ca_.SetSourcePosition("../../../src/builtins/promise-race.tq", 89);
    ca_.Goto(&block38);
  }

  TNode<HeapObject> tmp88;
  if (block46.is_used()) {
    ca_.Bind(&block46);
    ca_.SetSourcePosition("../../../src/builtins/promise-race.tq", 90);
    tmp88 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block18, tmp87, tmp88);
  }

  if (block38.is_used()) {
    ca_.Bind(&block38);
    ca_.SetSourcePosition("../../../src/builtins/promise-race.tq", 58);
    ca_.Goto(&block22);
  }

  if (block21.is_used()) {
    ca_.Bind(&block21);
    ca_.SetSourcePosition("../../../src/builtins/promise-race.tq", 102);
    CodeStubAssembler(state_).PrintErr("halting because of unreachable code at src/builtins/promise-race.tq:102:3");
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<Object> phi_bb18_13;
  TNode<HeapObject> phi_bb18_14;
  if (block18.is_used()) {
    ca_.Bind(&block18, &phi_bb18_13, &phi_bb18_14);
    ca_.SetSourcePosition("../../../src/builtins/promise-race.tq", 95);
    IteratorCloseOnException_0(state_, TNode<Context>{parameter0}, TorqueStructIteratorRecord{TNode<JSReceiver>{tmp21}, TNode<Object>{tmp22}});
    ca_.SetSourcePosition("../../../src/builtins/promise-race.tq", 96);
    ca_.Goto(&block12, phi_bb18_13);
  }

  TNode<Object> phi_bb12_10;
  TNode<Object> tmp89;
  TNode<Oddball> tmp90;
  TNode<Object> tmp91;
  if (block12.is_used()) {
    ca_.Bind(&block12, &phi_bb12_10);
    ca_.SetSourcePosition("../../../src/builtins/promise-race.tq", 99);
    tmp89 = UnsafeCast_JSAny_0(state_, TNode<Context>{parameter0}, TNode<Object>{tmp9});
    tmp90 = Undefined_0(state_);
    tmp91 = CodeStubAssembler(state_).Call(TNode<Context>{parameter0}, TNode<Object>{tmp89}, TNode<Object>{tmp90}, TNode<Object>{phi_bb12_10});
    ca_.SetSourcePosition("../../../src/builtins/promise-race.tq", 100);
    CodeStubAssembler(state_).Return(tmp11);
  }
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-race.tq?l=89&c=33
TNode<BoolT> Is_JSPromise_JSReceiver_OR_Undefined_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<HeapObject> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<JSPromise> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 808);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = Cast_JSPromise_0(state_, TNode<HeapObject>{p_o}, &label1);
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
    ca_.SetSourcePosition("../../../src/builtins/promise-race.tq", 89);
    ca_.Goto(&block6);
  }

    ca_.Bind(&block6);
  return TNode<BoolT>{phi_bb1_2};
}

} // namespace internal
} // namespace v8
