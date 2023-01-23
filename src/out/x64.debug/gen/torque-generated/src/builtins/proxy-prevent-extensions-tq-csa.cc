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
#include "torque-generated/src/builtins/proxy-prevent-extensions-tq-csa.h"
#include "torque-generated/src/builtins/base-tq-csa.h"
#include "torque-generated/src/builtins/convert-tq-csa.h"
#include "torque-generated/src/builtins/object-tq-csa.h"
#include "torque-generated/src/builtins/proxy-delete-property-tq-csa.h"
#include "torque-generated/src/objects/js-objects-tq-csa.h"

namespace v8 {
namespace internal {

TF_BUILTIN(ProxyPreventExtensions, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedParameter<Context>(Descriptor::kContext);
  USE(parameter0);
  TNode<JSProxy> parameter1 = UncheckedParameter<JSProxy>(Descriptor::kProxy);
  USE(parameter1);
  TNode<Oddball> parameter2 = UncheckedParameter<Oddball>(Descriptor::kDoThrow);
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block20(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block25(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block26(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block27(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block28(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block29(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<HeapObject> tmp1;
  TNode<Oddball> tmp2;
  TNode<BoolT> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/proxy-prevent-extensions.tq", 14);
    CodeStubAssembler(state_).PerformStackCheck(TNode<Context>{parameter0});
    ca_.SetSourcePosition("../../../src/builtins/proxy-prevent-extensions.tq", 20);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp1 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{parameter1, tmp0});
    tmp2 = Null_0(state_);
    tmp3 = CodeStubAssembler(state_).TaggedEqual(TNode<HeapObject>{tmp1}, TNode<HeapObject>{tmp2});
    ca_.Branch(tmp3, &block7, std::vector<compiler::Node*>{}, &block8, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp4;
  if (block7.is_used()) {
    ca_.Bind(&block7);
    tmp4 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block9, tmp4);
  }

  TNode<IntPtrT> tmp5;
  TNode<HeapObject> tmp6;
  TNode<BoolT> tmp7;
  if (block8.is_used()) {
    ca_.Bind(&block8);
    tmp5 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp6 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{parameter1, tmp5});
    tmp7 = Is_JSReceiver_JSReceiver_OR_Null_0(state_, TNode<Context>{parameter0}, TNode<HeapObject>{tmp6});
    ca_.Goto(&block9, tmp7);
  }

  TNode<BoolT> phi_bb9_4;
  if (block9.is_used()) {
    ca_.Bind(&block9, &phi_bb9_4);
    ca_.Branch(phi_bb9_4, &block5, std::vector<compiler::Node*>{}, &block6, std::vector<compiler::Node*>{});
  }

  if (block6.is_used()) {
    ca_.Bind(&block6);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/proxy-prevent-extensions.tq", 20});
      CodeStubAssembler(state_).FailAssert("Torque assert 'proxy.handler == Null || Is<JSReceiver>(proxy.handler)' failed", pos_stack);
    }
  }

  TNode<IntPtrT> tmp8;
  TNode<HeapObject> tmp9;
  TNode<JSReceiver> tmp10;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    ca_.SetSourcePosition("../../../src/builtins/proxy-prevent-extensions.tq", 22);
    tmp8 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp9 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{parameter1, tmp8});
    compiler::CodeAssemblerLabel label11(&ca_);
    tmp10 = Cast_JSReceiver_0(state_, TNode<HeapObject>{tmp9}, &label11);
    ca_.Goto(&block10);
    if (label11.is_used()) {
      ca_.Bind(&label11);
      ca_.Goto(&block11);
    }
  }

  if (block11.is_used()) {
    ca_.Bind(&block11);
    ca_.SetSourcePosition("../../../src/builtins/proxy-prevent-extensions.tq", 61);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{parameter0}, MessageTemplate::kProxyRevoked, "preventExtensions");
  }

  TNode<IntPtrT> tmp12;
  TNode<HeapObject> tmp13;
  TNode<JSReceiver> tmp14;
  if (block10.is_used()) {
    ca_.Bind(&block10);
    ca_.SetSourcePosition("../../../src/builtins/proxy-prevent-extensions.tq", 25);
    tmp12 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp13 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{parameter1, tmp12});
    ca_.SetSourcePosition("../../../src/builtins/proxy-prevent-extensions.tq", 29);
    compiler::CodeAssemblerLabel label15(&ca_);
    tmp14 = GetMethod_2(state_, TNode<Context>{parameter0}, TNode<Object>{tmp10}, "preventExtensions", &label15);
    ca_.Goto(&block14);
    if (label15.is_used()) {
      ca_.Bind(&label15);
      ca_.Goto(&block15);
    }
  }

  TNode<Oddball> tmp16;
  TNode<BoolT> tmp17;
  if (block15.is_used()) {
    ca_.Bind(&block15);
    ca_.SetSourcePosition("../../../src/builtins/proxy-prevent-extensions.tq", 56);
    tmp16 = True_0(state_);
    tmp17 = CodeStubAssembler(state_).TaggedEqual(TNode<HeapObject>{parameter2}, TNode<HeapObject>{tmp16});
    ca_.Branch(tmp17, &block28, std::vector<compiler::Node*>{}, &block29, std::vector<compiler::Node*>{});
  }

  TNode<Object> tmp18;
  TNode<BoolT> tmp19;
  if (block14.is_used()) {
    ca_.Bind(&block14);
    ca_.SetSourcePosition("../../../src/builtins/proxy-prevent-extensions.tq", 34);
    tmp18 = CodeStubAssembler(state_).Call(TNode<Context>{parameter0}, TNode<Object>{tmp14}, TNode<Object>{tmp10}, TNode<Object>{tmp13});
    ca_.SetSourcePosition("../../../src/builtins/proxy-prevent-extensions.tq", 39);
    tmp19 = ToBoolean_0(state_, TNode<Object>{tmp18});
    ca_.Branch(tmp19, &block16, std::vector<compiler::Node*>{}, &block17, std::vector<compiler::Node*>{});
  }

  TNode<Object> tmp20;
  TNode<Oddball> tmp21;
  TNode<BoolT> tmp22;
  if (block16.is_used()) {
    ca_.Bind(&block16);
    ca_.SetSourcePosition("../../../src/builtins/proxy-prevent-extensions.tq", 40);
    tmp20 = ObjectIsExtensibleImpl_0(state_, TNode<Context>{parameter0}, TNode<Object>{tmp13});
    ca_.SetSourcePosition("../../../src/builtins/proxy-prevent-extensions.tq", 41);
    tmp21 = True_0(state_);
    tmp22 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp20}, TNode<HeapObject>{tmp21});
    ca_.Branch(tmp22, &block21, std::vector<compiler::Node*>{}, &block22, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp23;
  if (block21.is_used()) {
    ca_.Bind(&block21);
    tmp23 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block23, tmp23);
  }

  TNode<Oddball> tmp24;
  TNode<BoolT> tmp25;
  if (block22.is_used()) {
    ca_.Bind(&block22);
    tmp24 = False_0(state_);
    tmp25 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp20}, TNode<HeapObject>{tmp24});
    ca_.Goto(&block23, tmp25);
  }

  TNode<BoolT> phi_bb23_9;
  if (block23.is_used()) {
    ca_.Bind(&block23, &phi_bb23_9);
    ca_.Branch(phi_bb23_9, &block19, std::vector<compiler::Node*>{}, &block20, std::vector<compiler::Node*>{});
  }

  if (block20.is_used()) {
    ca_.Bind(&block20);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/proxy-prevent-extensions.tq", 41});
      CodeStubAssembler(state_).FailAssert("Torque assert 'extensibleTarget == True || extensibleTarget == False' failed", pos_stack);
    }
  }

  TNode<Oddball> tmp26;
  TNode<BoolT> tmp27;
  if (block19.is_used()) {
    ca_.Bind(&block19);
    ca_.SetSourcePosition("../../../src/builtins/proxy-prevent-extensions.tq", 42);
    tmp26 = True_0(state_);
    tmp27 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp20}, TNode<HeapObject>{tmp26});
    ca_.Branch(tmp27, &block24, std::vector<compiler::Node*>{}, &block25, std::vector<compiler::Node*>{});
  }

  if (block24.is_used()) {
    ca_.Bind(&block24);
    ca_.SetSourcePosition("../../../src/builtins/proxy-prevent-extensions.tq", 43);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{parameter0}, MessageTemplate::kProxyPreventExtensionsExtensible);
  }

  TNode<Oddball> tmp28;
  if (block25.is_used()) {
    ca_.Bind(&block25);
    ca_.SetSourcePosition("../../../src/builtins/proxy-prevent-extensions.tq", 53);
    tmp28 = True_0(state_);
    CodeStubAssembler(state_).Return(tmp28);
  }

  TNode<Oddball> tmp29;
  TNode<BoolT> tmp30;
  if (block17.is_used()) {
    ca_.Bind(&block17);
    ca_.SetSourcePosition("../../../src/builtins/proxy-prevent-extensions.tq", 46);
    tmp29 = True_0(state_);
    tmp30 = CodeStubAssembler(state_).TaggedEqual(TNode<HeapObject>{parameter2}, TNode<HeapObject>{tmp29});
    ca_.Branch(tmp30, &block26, std::vector<compiler::Node*>{}, &block27, std::vector<compiler::Node*>{});
  }

  if (block26.is_used()) {
    ca_.Bind(&block26);
    ca_.SetSourcePosition("../../../src/builtins/proxy-prevent-extensions.tq", 47);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{parameter0}, MessageTemplate::kProxyTrapReturnedFalsish, "preventExtensions");
  }

  TNode<Oddball> tmp31;
  if (block27.is_used()) {
    ca_.Bind(&block27);
    ca_.SetSourcePosition("../../../src/builtins/proxy-prevent-extensions.tq", 49);
    tmp31 = False_0(state_);
    CodeStubAssembler(state_).Return(tmp31);
  }

  TNode<Object> tmp32;
  if (block28.is_used()) {
    ca_.Bind(&block28);
    ca_.SetSourcePosition("../../../src/builtins/proxy-prevent-extensions.tq", 57);
    tmp32 = ObjectPreventExtensionsThrow_0(state_, TNode<Context>{parameter0}, TNode<Object>{tmp13});
    CodeStubAssembler(state_).Return(tmp32);
  }

  TNode<Object> tmp33;
  if (block29.is_used()) {
    ca_.Bind(&block29);
    ca_.SetSourcePosition("../../../src/builtins/proxy-prevent-extensions.tq", 59);
    tmp33 = ObjectPreventExtensionsDontThrow_0(state_, TNode<Context>{parameter0}, TNode<Object>{tmp13});
    CodeStubAssembler(state_).Return(tmp33);
  }
}

} // namespace internal
} // namespace v8
