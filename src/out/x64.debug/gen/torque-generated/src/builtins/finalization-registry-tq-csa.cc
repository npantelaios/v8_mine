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
#include "torque-generated/src/builtins/finalization-registry-tq-csa.h"
#include "torque-generated/src/builtins/array-every-tq-csa.h"
#include "torque-generated/src/builtins/base-tq-csa.h"
#include "torque-generated/src/builtins/boolean-tq-csa.h"
#include "torque-generated/src/builtins/cast-tq-csa.h"
#include "torque-generated/src/builtins/convert-tq-csa.h"
#include "torque-generated/src/builtins/finalization-registry-tq-csa.h"
#include "torque-generated/src/builtins/frame-arguments-tq-csa.h"
#include "torque-generated/src/builtins/torque-internal-tq-csa.h"
#include "torque-generated/src/objects/js-objects-tq-csa.h"
#include "torque-generated/src/objects/js-weak-refs-tq-csa.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/finalization-registry.tq?l=22&c=1
TNode<HeapObject> SplitOffTail_0(compiler::CodeAssemblerState* state_, TNode<WeakCell> p_weakCell) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<HeapObject> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<Oddball> tmp3;
  TNode<Oddball> tmp4;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/finalization-registry.tq", 23);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 24);
    tmp1 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{p_weakCell, tmp0});
    ca_.SetSourcePosition("../../../src/builtins/finalization-registry.tq", 24);
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 24);
    tmp3 = Undefined_0(state_);
    CodeStubAssembler(state_).StoreReference<HeapObject>(CodeStubAssembler::Reference{p_weakCell, tmp2}, tmp3);
    ca_.SetSourcePosition("../../../src/builtins/finalization-registry.tq", 26);
    compiler::CodeAssemblerLabel label5(&ca_);
    tmp4 = Cast_Undefined_2(state_, TNode<HeapObject>{tmp1}, &label5);
    ca_.Goto(&block4);
    if (label5.is_used()) {
      ca_.Bind(&label5);
      ca_.Goto(&block5);
    }
  }

  TNode<IntPtrT> tmp6;
  TNode<HeapObject> tmp7;
  TNode<BoolT> tmp8;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    ca_.SetSourcePosition("../../../src/builtins/finalization-registry.tq", 29);
    tmp6 = FromConstexpr_intptr_constexpr_int31_0(state_, 20);
    tmp7 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{ca_.UncheckedCast<WeakCell>(tmp1), tmp6});
    tmp8 = CodeStubAssembler(state_).TaggedEqual(TNode<HeapObject>{tmp7}, TNode<HeapObject>{p_weakCell});
    ca_.Branch(tmp8, &block6, std::vector<compiler::Node*>{}, &block7, std::vector<compiler::Node*>{});
  }

  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.SetSourcePosition("../../../src/builtins/finalization-registry.tq", 26);
    ca_.Goto(&block2);
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    ca_.SetSourcePosition("../../../src/builtins/finalization-registry.tq", 29);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/finalization-registry.tq", 29});
      CodeStubAssembler(state_).FailAssert("Torque assert 'tailIsNowAHead.prev == weakCell' failed", pos_stack);
    }
  }

  TNode<IntPtrT> tmp9;
  TNode<Oddball> tmp10;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.SetSourcePosition("../../../src/builtins/finalization-registry.tq", 30);
    tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 20);
    tmp10 = Undefined_0(state_);
    CodeStubAssembler(state_).StoreReference<HeapObject>(CodeStubAssembler::Reference{ca_.UncheckedCast<WeakCell>(tmp1), tmp9}, tmp10);
    ca_.SetSourcePosition("../../../src/builtins/finalization-registry.tq", 26);
    ca_.Goto(&block2);
  }

  if (block2.is_used()) {
    ca_.Bind(&block2);
    ca_.SetSourcePosition("../../../src/builtins/finalization-registry.tq", 22);
    ca_.Goto(&block8);
  }

    ca_.Bind(&block8);
  return TNode<HeapObject>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/finalization-registry.tq?l=36&c=1
TNode<HeapObject> PopClearedCell_0(compiler::CodeAssemblerState* state_, TNode<JSFinalizationRegistry> p_finalizationRegistry) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<HeapObject> tmp1;
  TNode<Oddball> tmp2;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/finalization-registry.tq", 39);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 24);
    tmp1 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{p_finalizationRegistry, tmp0});
    ca_.SetSourcePosition("../../../src/builtins/finalization-registry.tq", 40);
    compiler::CodeAssemblerLabel label3(&ca_);
    tmp2 = Cast_Undefined_2(state_, TNode<HeapObject>{tmp1}, &label3);
    ca_.Goto(&block4);
    if (label3.is_used()) {
      ca_.Bind(&label3);
      ca_.Goto(&block5);
    }
  }

  TNode<IntPtrT> tmp4;
  TNode<HeapObject> tmp5;
  TNode<Oddball> tmp6;
  TNode<BoolT> tmp7;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    ca_.SetSourcePosition("../../../src/builtins/finalization-registry.tq", 44);
    tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 20);
    tmp5 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{ca_.UncheckedCast<WeakCell>(tmp1), tmp4});
    tmp6 = Undefined_0(state_);
    tmp7 = CodeStubAssembler(state_).TaggedEqual(TNode<HeapObject>{tmp5}, TNode<HeapObject>{tmp6});
    ca_.Branch(tmp7, &block6, std::vector<compiler::Node*>{}, &block7, std::vector<compiler::Node*>{});
  }

  TNode<Oddball> tmp8;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.SetSourcePosition("../../../src/builtins/finalization-registry.tq", 41);
    tmp8 = Undefined_0(state_);
    ca_.Goto(&block1, tmp8);
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    ca_.SetSourcePosition("../../../src/builtins/finalization-registry.tq", 44);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/finalization-registry.tq", 44});
      CodeStubAssembler(state_).FailAssert("Torque assert 'weakCell.prev == Undefined' failed", pos_stack);
    }
  }

  TNode<IntPtrT> tmp9;
  TNode<HeapObject> tmp10;
  TNode<IntPtrT> tmp11;
  TNode<HeapObject> tmp12;
  TNode<Oddball> tmp13;
  TNode<BoolT> tmp14;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.SetSourcePosition("../../../src/builtins/finalization-registry.tq", 45);
    tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 24);
    tmp10 = SplitOffTail_0(state_, TNode<WeakCell>{ca_.UncheckedCast<WeakCell>(tmp1)});
    CodeStubAssembler(state_).StoreReference<HeapObject>(CodeStubAssembler::Reference{p_finalizationRegistry, tmp9}, tmp10);
    ca_.SetSourcePosition("../../../src/builtins/finalization-registry.tq", 51);
    tmp11 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp12 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{ca_.UncheckedCast<WeakCell>(tmp1), tmp11});
    tmp13 = Undefined_0(state_);
    tmp14 = CodeStubAssembler(state_).TaggedNotEqual(TNode<HeapObject>{tmp12}, TNode<HeapObject>{tmp13});
    ca_.Branch(tmp14, &block8, std::vector<compiler::Node*>{}, &block9, std::vector<compiler::Node*>{});
  }

  if (block8.is_used()) {
    ca_.Bind(&block8);
    ca_.SetSourcePosition("../../../src/builtins/finalization-registry.tq", 52);
    CodeStubAssembler(state_).RemoveFinalizationRegistryCellFromUnregisterTokenMap(TNode<JSFinalizationRegistry>{p_finalizationRegistry}, TNode<WeakCell>{ca_.UncheckedCast<WeakCell>(tmp1)});
    ca_.SetSourcePosition("../../../src/builtins/finalization-registry.tq", 51);
    ca_.Goto(&block9);
  }

  if (block9.is_used()) {
    ca_.Bind(&block9);
    ca_.SetSourcePosition("../../../src/builtins/finalization-registry.tq", 56);
    ca_.Goto(&block1, ca_.UncheckedCast<WeakCell>(tmp1));
  }

  TNode<HeapObject> phi_bb1_1;
  if (block1.is_used()) {
    ca_.Bind(&block1, &phi_bb1_1);
    ca_.SetSourcePosition("../../../src/builtins/finalization-registry.tq", 36);
    ca_.Goto(&block10, phi_bb1_1);
  }

  TNode<HeapObject> phi_bb10_1;
    ca_.Bind(&block10, &phi_bb10_1);
  return TNode<HeapObject>{phi_bb10_1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/finalization-registry.tq?l=61&c=1
void PushCell_0(compiler::CodeAssemblerState* state_, TNode<JSFinalizationRegistry> p_finalizationRegistry, TNode<WeakCell> p_cell) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<HeapObject> tmp2;
  TNode<IntPtrT> tmp3;
  TNode<HeapObject> tmp4;
  TNode<Oddball> tmp5;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/finalization-registry.tq", 63);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 24);
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 20);
    tmp2 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{p_finalizationRegistry, tmp1});
    CodeStubAssembler(state_).StoreReference<HeapObject>(CodeStubAssembler::Reference{p_cell, tmp0}, tmp2);
    ca_.SetSourcePosition("../../../src/builtins/finalization-registry.tq", 64);
    tmp3 = FromConstexpr_intptr_constexpr_int31_0(state_, 20);
    tmp4 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{p_finalizationRegistry, tmp3});
    ca_.SetSourcePosition("../../../src/builtins/finalization-registry.tq", 65);
    compiler::CodeAssemblerLabel label6(&ca_);
    tmp5 = Cast_Undefined_2(state_, TNode<HeapObject>{tmp4}, &label6);
    ca_.Goto(&block4);
    if (label6.is_used()) {
      ca_.Bind(&label6);
      ca_.Goto(&block5);
    }
  }

  TNode<IntPtrT> tmp7;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    ca_.SetSourcePosition("../../../src/builtins/finalization-registry.tq", 68);
    tmp7 = FromConstexpr_intptr_constexpr_int31_0(state_, 20);
    CodeStubAssembler(state_).StoreReference<HeapObject>(CodeStubAssembler::Reference{ca_.UncheckedCast<WeakCell>(tmp4), tmp7}, p_cell);
    ca_.SetSourcePosition("../../../src/builtins/finalization-registry.tq", 65);
    ca_.Goto(&block2);
  }

  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.Goto(&block2);
  }

  TNode<IntPtrT> tmp8;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    ca_.SetSourcePosition("../../../src/builtins/finalization-registry.tq", 71);
    tmp8 = FromConstexpr_intptr_constexpr_int31_0(state_, 20);
    CodeStubAssembler(state_).StoreReference<HeapObject>(CodeStubAssembler::Reference{p_finalizationRegistry, tmp8}, p_cell);
    ca_.SetSourcePosition("../../../src/builtins/finalization-registry.tq", 61);
    ca_.Goto(&block6);
  }

    ca_.Bind(&block6);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/finalization-registry.tq?l=74&c=1
void FinalizationRegistryCleanupLoop_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSFinalizationRegistry> p_finalizationRegistry, TNode<JSReceiver> p_callback) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, HeapObject> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/finalization-registry.tq", 77);
    ca_.Goto(&block4);
  }

  TNode<BoolT> tmp0;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    tmp0 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Branch(tmp0, &block2, std::vector<compiler::Node*>{}, &block3, std::vector<compiler::Node*>{});
  }

  TNode<HeapObject> tmp1;
  TNode<Oddball> tmp2;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    ca_.SetSourcePosition("../../../src/builtins/finalization-registry.tq", 78);
    tmp1 = PopClearedCell_0(state_, TNode<JSFinalizationRegistry>{p_finalizationRegistry});
    ca_.SetSourcePosition("../../../src/builtins/finalization-registry.tq", 80);
    compiler::CodeAssemblerLabel label3(&ca_);
    tmp2 = Cast_Undefined_2(state_, TNode<HeapObject>{tmp1}, &label3);
    ca_.Goto(&block7);
    if (label3.is_used()) {
      ca_.Bind(&label3);
      ca_.Goto(&block8);
    }
  }

  TNode<Oddball> tmp4;
  TNode<IntPtrT> tmp5;
      TNode<Object> tmp7;
  TNode<Object> tmp8;
  TNode<Object> tmp9;
      TNode<Object> tmp11;
  if (block8.is_used()) {
    ca_.Bind(&block8);
    ca_.SetSourcePosition("../../../src/builtins/finalization-registry.tq", 85);
    tmp4 = Undefined_0(state_);
    compiler::CodeAssemblerExceptionHandlerLabel catch6__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch6__label);
    tmp5 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    }
    if (catch6__label.is_used()) {
      compiler::CodeAssemblerLabel catch6_skip(&ca_);
      ca_.Goto(&catch6_skip);
      ca_.Bind(&catch6__label, &tmp7);
      ca_.Goto(&block11);
      ca_.Bind(&catch6_skip);
    }
    tmp8 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{ca_.UncheckedCast<WeakCell>(tmp1), tmp5});
    compiler::CodeAssemblerExceptionHandlerLabel catch10__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch10__label);
    tmp9 = CodeStubAssembler(state_).Call(TNode<Context>{p_context}, TNode<Object>{p_callback}, TNode<Object>{tmp4}, TNode<Object>{tmp8});
    }
    if (catch10__label.is_used()) {
      compiler::CodeAssemblerLabel catch10_skip(&ca_);
      ca_.Goto(&catch10_skip);
      ca_.Bind(&catch10__label, &tmp11);
      ca_.Goto(&block12);
      ca_.Bind(&catch10_skip);
    }
    ca_.SetSourcePosition("../../../src/builtins/finalization-registry.tq", 77);
    ca_.Goto(&block4);
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    ca_.SetSourcePosition("../../../src/builtins/finalization-registry.tq", 81);
    ca_.Goto(&block3);
  }

  TNode<HeapObject> tmp12;
  if (block11.is_used()) {
    ca_.Bind(&block11);
    ca_.SetSourcePosition("../../../src/builtins/finalization-registry.tq", 85);
    tmp12 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block10, tmp7, tmp12);
  }

  TNode<HeapObject> tmp13;
  if (block12.is_used()) {
    ca_.Bind(&block12);
    tmp13 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block10, tmp11, tmp13);
  }

  TNode<Object> phi_bb10_6;
  TNode<HeapObject> phi_bb10_7;
  if (block10.is_used()) {
    ca_.Bind(&block10, &phi_bb10_6, &phi_bb10_7);
    ca_.SetSourcePosition("../../../src/builtins/finalization-registry.tq", 87);
    CodeStubAssembler(state_).CallRuntime(Runtime::kShrinkFinalizationRegistryUnregisterTokenMap, p_context, p_finalizationRegistry);
    ca_.SetSourcePosition("../../../src/builtins/finalization-registry.tq", 89);
    CodeStubAssembler(state_).CallRuntime(Runtime::kReThrowWithMessage, p_context, phi_bb10_6, phi_bb10_7);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    ca_.SetSourcePosition("../../../src/builtins/finalization-registry.tq", 95);
    CodeStubAssembler(state_).CallRuntime(Runtime::kShrinkFinalizationRegistryUnregisterTokenMap, p_context, p_finalizationRegistry);
    ca_.SetSourcePosition("../../../src/builtins/finalization-registry.tq", 74);
    ca_.Goto(&block13);
  }

    ca_.Bind(&block13);
}

TF_BUILTIN(FinalizationRegistryConstructor, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kReceiver);
  USE(parameter1);
  TNode<Object> parameter2 = UncheckedParameter<Object>(Descriptor::kJSNewTarget);
USE(parameter2);
  TNode<JSFunction> parameter3 = UncheckedParameter<JSFunction>(Descriptor::kJSTarget);
USE(parameter3);
  TNode<Object> parameter4 = UncheckedParameter<Object>(Descriptor::kCleanupCallback);
  USE(parameter4);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Oddball> tmp0;
  TNode<BoolT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/finalization-registry.tq", 104);
    tmp0 = Undefined_0(state_);
    tmp1 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{parameter2}, TNode<HeapObject>{tmp0});
    ca_.Branch(tmp1, &block1, std::vector<compiler::Node*>{}, &block2, std::vector<compiler::Node*>{});
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.SetSourcePosition("../../../src/builtins/finalization-registry.tq", 105);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{parameter0}, MessageTemplate::kConstructorNotFunction, "FinalizationRegistry");
  }

  TNode<JSReceiver> tmp2;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    ca_.SetSourcePosition("../../../src/builtins/finalization-registry.tq", 109);
    compiler::CodeAssemblerLabel label3(&ca_);
    tmp2 = Cast_Callable_1(state_, TNode<Context>{parameter0}, TNode<Object>{parameter4}, &label3);
    ca_.Goto(&block5);
    if (label3.is_used()) {
      ca_.Bind(&label3);
      ca_.Goto(&block6);
    }
  }

  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.SetSourcePosition("../../../src/builtins/finalization-registry.tq", 110);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{parameter0}, MessageTemplate::kWeakRefsCleanupMustBeCallable);
  }

  TNode<JSReceiver> tmp4;
  TNode<Map> tmp5;
  TNode<JSObject> tmp6;
  TNode<JSFinalizationRegistry> tmp7;
  TNode<IntPtrT> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<IntPtrT> tmp10;
  TNode<Int32T> tmp11;
  TNode<Uint32T> tmp12;
  TNode<Uint32T> tmp13;
  TNode<BoolT> tmp14;
  TNode<Uint32T> tmp15;
  TNode<Smi> tmp16;
  TNode<IntPtrT> tmp17;
  TNode<HeapObject> tmp18;
  TNode<Oddball> tmp19;
  TNode<BoolT> tmp20;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    ca_.SetSourcePosition("../../../src/builtins/finalization-registry.tq", 114);
    tmp4 = UnsafeCast_JSReceiver_0(state_, TNode<Context>{parameter0}, TNode<Object>{parameter2});
    tmp5 = GetDerivedMap_0(state_, TNode<Context>{parameter0}, TNode<JSFunction>{parameter3}, TNode<JSReceiver>{tmp4});
    ca_.SetSourcePosition("../../../src/builtins/finalization-registry.tq", 116);
    tmp6 = AllocateFastOrSlowJSObjectFromMap_0(state_, TNode<Context>{parameter0}, TNode<Map>{tmp5});
    ca_.SetSourcePosition("../../../src/builtins/finalization-registry.tq", 115);
    tmp7 = UnsafeCast_JSFinalizationRegistry_0(state_, TNode<Context>{parameter0}, TNode<Object>{tmp6});
    ca_.SetSourcePosition("../../../src/builtins/finalization-registry.tq", 119);
    tmp8 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    CodeStubAssembler(state_).StoreReference<NativeContext>(CodeStubAssembler::Reference{tmp7, tmp8}, parameter0);
    ca_.SetSourcePosition("../../../src/builtins/finalization-registry.tq", 121);
    tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    CodeStubAssembler(state_).StoreReference<JSReceiver>(CodeStubAssembler::Reference{tmp7, tmp9}, tmp2);
    ca_.SetSourcePosition("../../../src/builtins/finalization-registry.tq", 122);
    tmp10 = FromConstexpr_intptr_constexpr_int31_0(state_, 36);
    ca_.SetSourcePosition("../../../src/builtins/finalization-registry.tq", 123);
    tmp11 = FromConstexpr_int32_constexpr_int32_0(state_, 0);
    tmp12 = CodeStubAssembler(state_).Unsigned(TNode<Int32T>{tmp11});
    tmp13 = (TNode<Uint32T>{tmp12});
    tmp14 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    tmp15 = ca_.UncheckedCast<Uint32T>(CodeStubAssembler(state_).UpdateWord32<base::BitField<bool, 0, 1, uint32_t>>(ca_.UncheckedCast<Word32T>(tmp13), ca_.UncheckedCast<Uint32T>(tmp14), true));
    tmp16 = SmiTag_FinalizationRegistryFlags_0(state_, TNode<Uint32T>{tmp15});
    ca_.SetSourcePosition("../../../src/builtins/finalization-registry.tq", 122);
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{tmp7, tmp10}, tmp16);
    ca_.SetSourcePosition("../../../src/builtins/finalization-registry.tq", 125);
    tmp17 = FromConstexpr_intptr_constexpr_int31_0(state_, 20);
    tmp18 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{tmp7, tmp17});
    tmp19 = Undefined_0(state_);
    tmp20 = CodeStubAssembler(state_).TaggedEqual(TNode<HeapObject>{tmp18}, TNode<HeapObject>{tmp19});
    ca_.Branch(tmp20, &block7, std::vector<compiler::Node*>{}, &block8, std::vector<compiler::Node*>{});
  }

  if (block8.is_used()) {
    ca_.Bind(&block8);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/finalization-registry.tq", 125});
      CodeStubAssembler(state_).FailAssert("Torque assert 'finalizationRegistry.active_cells == Undefined' failed", pos_stack);
    }
  }

  TNode<IntPtrT> tmp21;
  TNode<HeapObject> tmp22;
  TNode<Oddball> tmp23;
  TNode<BoolT> tmp24;
  if (block7.is_used()) {
    ca_.Bind(&block7);
    ca_.SetSourcePosition("../../../src/builtins/finalization-registry.tq", 126);
    tmp21 = FromConstexpr_intptr_constexpr_int31_0(state_, 24);
    tmp22 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{tmp7, tmp21});
    tmp23 = Undefined_0(state_);
    tmp24 = CodeStubAssembler(state_).TaggedEqual(TNode<HeapObject>{tmp22}, TNode<HeapObject>{tmp23});
    ca_.Branch(tmp24, &block9, std::vector<compiler::Node*>{}, &block10, std::vector<compiler::Node*>{});
  }

  if (block10.is_used()) {
    ca_.Bind(&block10);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/finalization-registry.tq", 126});
      CodeStubAssembler(state_).FailAssert("Torque assert 'finalizationRegistry.cleared_cells == Undefined' failed", pos_stack);
    }
  }

  TNode<IntPtrT> tmp25;
  TNode<Object> tmp26;
  TNode<Oddball> tmp27;
  TNode<BoolT> tmp28;
  if (block9.is_used()) {
    ca_.Bind(&block9);
    ca_.SetSourcePosition("../../../src/builtins/finalization-registry.tq", 127);
    tmp25 = FromConstexpr_intptr_constexpr_int31_0(state_, 28);
    tmp26 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp7, tmp25});
    tmp27 = Undefined_0(state_);
    tmp28 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp26}, TNode<HeapObject>{tmp27});
    ca_.Branch(tmp28, &block11, std::vector<compiler::Node*>{}, &block12, std::vector<compiler::Node*>{});
  }

  if (block12.is_used()) {
    ca_.Bind(&block12);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/finalization-registry.tq", 127});
      CodeStubAssembler(state_).FailAssert("Torque assert 'finalizationRegistry.key_map == Undefined' failed", pos_stack);
    }
  }

  if (block11.is_used()) {
    ca_.Bind(&block11);
    ca_.SetSourcePosition("../../../src/builtins/finalization-registry.tq", 129);
    CodeStubAssembler(state_).Return(tmp7);
  }
}

TF_BUILTIN(FinalizationRegistryRegister, CodeStubAssembler) {
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
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<JSFinalizationRegistry> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/finalization-registry.tq", 138);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = Cast_JSFinalizationRegistry_1(state_, TNode<Context>{parameter0}, TNode<Object>{parameter1}, &label1);
    ca_.Goto(&block3);
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block4);
    }
  }

  TNode<Object> tmp2;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.SetSourcePosition("../../../src/builtins/finalization-registry.tq", 139);
    tmp2 = FromConstexpr_Object_constexpr_string_0(state_, "FinalizationRegistry.prototype.register");
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{parameter0}, MessageTemplate::kIncompatibleMethodReceiver, TNode<Object>{tmp2}, TNode<Object>{parameter1});
  }

  TNode<IntPtrT> tmp3;
  TNode<Object> tmp4;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    ca_.SetSourcePosition("../../../src/builtins/finalization-registry.tq", 143);
    tmp3 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp4 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{torque_arguments.frame}, TNode<RawPtrT>{torque_arguments.base}, TNode<IntPtrT>{torque_arguments.length}, TNode<IntPtrT>{torque_arguments.actual_count}}, TNode<IntPtrT>{tmp3});
    compiler::CodeAssemblerLabel label5(&ca_);
    WeakCollectionsBuiltinsAssembler(state_).GotoIfCannotBeHeldWeakly(TNode<Object>{tmp4}, &label5);
    ca_.Goto(&block7);
    if (label5.is_used()) {
      ca_.Bind(&label5);
      ca_.Goto(&block8);
    }
  }

  if (block8.is_used()) {
    ca_.Bind(&block8);
    ca_.SetSourcePosition("../../../src/builtins/finalization-registry.tq", 144);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{parameter0}, MessageTemplate::kInvalidWeakRefsRegisterTarget);
  }

  TNode<IntPtrT> tmp6;
  TNode<Object> tmp7;
  TNode<HeapObject> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<Object> tmp10;
  TNode<BoolT> tmp11;
  if (block7.is_used()) {
    ca_.Bind(&block7);
    ca_.SetSourcePosition("../../../src/builtins/finalization-registry.tq", 146);
    tmp6 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp7 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{torque_arguments.frame}, TNode<RawPtrT>{torque_arguments.base}, TNode<IntPtrT>{torque_arguments.length}, TNode<IntPtrT>{torque_arguments.actual_count}}, TNode<IntPtrT>{tmp6});
    tmp8 = UnsafeCast_JSReceiver_OR_Symbol_0(state_, TNode<Context>{parameter0}, TNode<Object>{tmp7});
    ca_.SetSourcePosition("../../../src/builtins/finalization-registry.tq", 147);
    tmp9 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp10 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{torque_arguments.frame}, TNode<RawPtrT>{torque_arguments.base}, TNode<IntPtrT>{torque_arguments.length}, TNode<IntPtrT>{torque_arguments.actual_count}}, TNode<IntPtrT>{tmp9});
    ca_.SetSourcePosition("../../../src/builtins/finalization-registry.tq", 149);
    tmp11 = CodeStubAssembler(state_).TaggedEqual(TNode<HeapObject>{tmp8}, TNode<Object>{tmp10});
    ca_.Branch(tmp11, &block9, std::vector<compiler::Node*>{}, &block10, std::vector<compiler::Node*>{});
  }

  if (block9.is_used()) {
    ca_.Bind(&block9);
    ca_.SetSourcePosition("../../../src/builtins/finalization-registry.tq", 150);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{parameter0}, MessageTemplate::kWeakRefsRegisterTargetAndHoldingsMustNotBeSame);
  }

  TNode<IntPtrT> tmp12;
  TNode<Object> tmp13;
  TNode<BoolT> tmp14;
  if (block10.is_used()) {
    ca_.Bind(&block10);
    ca_.SetSourcePosition("../../../src/builtins/finalization-registry.tq", 156);
    tmp12 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x2ull));
    tmp13 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{torque_arguments.frame}, TNode<RawPtrT>{torque_arguments.base}, TNode<IntPtrT>{torque_arguments.length}, TNode<IntPtrT>{torque_arguments.actual_count}}, TNode<IntPtrT>{tmp12});
    ca_.SetSourcePosition("../../../src/builtins/finalization-registry.tq", 159);
    tmp14 = CodeStubAssembler(state_).IsUndefined(TNode<Object>{tmp13});
    ca_.Branch(tmp14, &block11, std::vector<compiler::Node*>{}, &block12, std::vector<compiler::Node*>{});
  }

  TNode<Oddball> tmp15;
  if (block11.is_used()) {
    ca_.Bind(&block11);
    ca_.SetSourcePosition("../../../src/builtins/finalization-registry.tq", 160);
    tmp15 = Undefined_0(state_);
    ca_.SetSourcePosition("../../../src/builtins/finalization-registry.tq", 159);
    ca_.Goto(&block13, tmp15);
  }

  if (block12.is_used()) {
    ca_.Bind(&block12);
    ca_.SetSourcePosition("../../../src/builtins/finalization-registry.tq", 162);
    compiler::CodeAssemblerLabel label16(&ca_);
    WeakCollectionsBuiltinsAssembler(state_).GotoIfCannotBeHeldWeakly(TNode<Object>{tmp13}, &label16);
    ca_.Goto(&block16);
    if (label16.is_used()) {
      ca_.Bind(&label16);
      ca_.Goto(&block17);
    }
  }

  if (block17.is_used()) {
    ca_.Bind(&block17);
    ca_.SetSourcePosition("../../../src/builtins/finalization-registry.tq", 163);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{parameter0}, MessageTemplate::kInvalidWeakRefsUnregisterToken, TNode<Object>{tmp13});
  }

  TNode<HeapObject> tmp17;
  if (block16.is_used()) {
    ca_.Bind(&block16);
    ca_.SetSourcePosition("../../../src/builtins/finalization-registry.tq", 165);
    tmp17 = UnsafeCast_JSReceiver_OR_Symbol_0(state_, TNode<Context>{parameter0}, TNode<Object>{tmp13});
    ca_.SetSourcePosition("../../../src/builtins/finalization-registry.tq", 159);
    ca_.Goto(&block13, tmp17);
  }

  TNode<HeapObject> phi_bb13_10;
  TNode<Map> tmp18;
  TNode<Oddball> tmp19;
  TNode<Oddball> tmp20;
  TNode<Oddball> tmp21;
  TNode<Oddball> tmp22;
  TNode<BoolT> tmp23;
  TNode<BoolT> tmp24;
  TNode<IntPtrT> tmp25;
  TNode<HeapObject> tmp26;
  TNode<IntPtrT> tmp27;
  TNode<IntPtrT> tmp28;
  TNode<IntPtrT> tmp29;
  TNode<IntPtrT> tmp30;
  TNode<IntPtrT> tmp31;
  TNode<IntPtrT> tmp32;
  TNode<IntPtrT> tmp33;
  TNode<IntPtrT> tmp34;
  TNode<IntPtrT> tmp35;
  TNode<WeakCell> tmp36;
  TNode<Oddball> tmp37;
  TNode<BoolT> tmp38;
  if (block13.is_used()) {
    ca_.Bind(&block13, &phi_bb13_10);
    ca_.SetSourcePosition("../../../src/builtins/finalization-registry.tq", 174);
    tmp18 = GetWeakCellMap_0(state_, TNode<Context>{parameter0});
    ca_.SetSourcePosition("../../../src/builtins/finalization-registry.tq", 179);
    tmp19 = Undefined_0(state_);
    ca_.SetSourcePosition("../../../src/builtins/finalization-registry.tq", 180);
    tmp20 = Undefined_0(state_);
    ca_.SetSourcePosition("../../../src/builtins/finalization-registry.tq", 181);
    tmp21 = Undefined_0(state_);
    ca_.SetSourcePosition("../../../src/builtins/finalization-registry.tq", 182);
    tmp22 = Undefined_0(state_);
    ca_.SetSourcePosition("../../../src/builtins/finalization-registry.tq", 173);
    tmp23 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    tmp24 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    tmp25 = FromConstexpr_intptr_constexpr_int31_0(state_, 36);
    tmp26 = AllocateFromNew_0(state_, TNode<IntPtrT>{tmp25}, TNode<Map>{tmp18}, TNode<BoolT>{tmp23}, TNode<BoolT>{tmp24});
    tmp27 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    CodeStubAssembler(state_).StoreReference<Map>(CodeStubAssembler::Reference{tmp26, tmp27}, tmp18);
    tmp28 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    CodeStubAssembler(state_).StoreReference<HeapObject>(CodeStubAssembler::Reference{tmp26, tmp28}, tmp0);
    tmp29 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    CodeStubAssembler(state_).StoreReference<HeapObject>(CodeStubAssembler::Reference{tmp26, tmp29}, tmp8);
    tmp30 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    CodeStubAssembler(state_).StoreReference<HeapObject>(CodeStubAssembler::Reference{tmp26, tmp30}, phi_bb13_10);
    tmp31 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp26, tmp31}, tmp10);
    tmp32 = FromConstexpr_intptr_constexpr_int31_0(state_, 20);
    CodeStubAssembler(state_).StoreReference<HeapObject>(CodeStubAssembler::Reference{tmp26, tmp32}, tmp19);
    tmp33 = FromConstexpr_intptr_constexpr_int31_0(state_, 24);
    CodeStubAssembler(state_).StoreReference<HeapObject>(CodeStubAssembler::Reference{tmp26, tmp33}, tmp20);
    tmp34 = FromConstexpr_intptr_constexpr_int31_0(state_, 28);
    CodeStubAssembler(state_).StoreReference<HeapObject>(CodeStubAssembler::Reference{tmp26, tmp34}, tmp21);
    tmp35 = FromConstexpr_intptr_constexpr_int31_0(state_, 32);
    CodeStubAssembler(state_).StoreReference<HeapObject>(CodeStubAssembler::Reference{tmp26, tmp35}, tmp22);
    tmp36 = TORQUE_CAST(TNode<HeapObject>{tmp26});
    ca_.SetSourcePosition("../../../src/builtins/finalization-registry.tq", 185);
    PushCell_0(state_, TNode<JSFinalizationRegistry>{tmp0}, TNode<WeakCell>{tmp36});
    ca_.SetSourcePosition("../../../src/builtins/finalization-registry.tq", 186);
    tmp37 = Undefined_0(state_);
    tmp38 = CodeStubAssembler(state_).TaggedNotEqual(TNode<HeapObject>{phi_bb13_10}, TNode<HeapObject>{tmp37});
    ca_.Branch(tmp38, &block18, std::vector<compiler::Node*>{phi_bb13_10}, &block19, std::vector<compiler::Node*>{phi_bb13_10});
  }

  TNode<HeapObject> phi_bb18_10;
  if (block18.is_used()) {
    ca_.Bind(&block18, &phi_bb18_10);
    ca_.SetSourcePosition("../../../src/builtins/finalization-registry.tq", 190);
    CodeStubAssembler(state_).CallRuntime(Runtime::kJSFinalizationRegistryRegisterWeakCellWithUnregisterToken, parameter0, tmp0, tmp36);
    ca_.SetSourcePosition("../../../src/builtins/finalization-registry.tq", 186);
    ca_.Goto(&block19, phi_bb18_10);
  }

  TNode<HeapObject> phi_bb19_10;
  TNode<Oddball> tmp39;
  if (block19.is_used()) {
    ca_.Bind(&block19, &phi_bb19_10);
    ca_.SetSourcePosition("../../../src/builtins/finalization-registry.tq", 194);
    tmp39 = Undefined_0(state_);
    arguments.PopAndReturn(tmp39);
  }
}

TF_BUILTIN(FinalizationRegistryPrototypeCleanupSome, CodeStubAssembler) {
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
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSReceiver> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<JSFinalizationRegistry> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/finalization-registry.tq", 206);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = Cast_JSFinalizationRegistry_1(state_, TNode<Context>{parameter0}, TNode<Object>{parameter1}, &label1);
    ca_.Goto(&block3);
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block4);
    }
  }

  TNode<Object> tmp2;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    tmp2 = FromConstexpr_Object_constexpr_string_0(state_, "FinalizationRegistry.prototype.cleanupSome");
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{parameter0}, MessageTemplate::kIncompatibleMethodReceiver, TNode<Object>{tmp2}, TNode<Object>{parameter1});
  }

  TNode<IntPtrT> tmp3;
  TNode<Object> tmp4;
  TNode<Oddball> tmp5;
  TNode<BoolT> tmp6;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    ca_.SetSourcePosition("../../../src/builtins/finalization-registry.tq", 210);
    tmp3 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp4 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{torque_arguments.frame}, TNode<RawPtrT>{torque_arguments.base}, TNode<IntPtrT>{torque_arguments.length}, TNode<IntPtrT>{torque_arguments.actual_count}}, TNode<IntPtrT>{tmp3});
    tmp5 = Undefined_0(state_);
    tmp6 = CodeStubAssembler(state_).TaggedNotEqual(TNode<Object>{tmp4}, TNode<HeapObject>{tmp5});
    ca_.Branch(tmp6, &block5, std::vector<compiler::Node*>{}, &block6, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp7;
  TNode<Object> tmp8;
  TNode<JSReceiver> tmp9;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    ca_.SetSourcePosition("../../../src/builtins/finalization-registry.tq", 213);
    tmp7 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp8 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{torque_arguments.frame}, TNode<RawPtrT>{torque_arguments.base}, TNode<IntPtrT>{torque_arguments.length}, TNode<IntPtrT>{torque_arguments.actual_count}}, TNode<IntPtrT>{tmp7});
    compiler::CodeAssemblerLabel label10(&ca_);
    tmp9 = Cast_Callable_1(state_, TNode<Context>{parameter0}, TNode<Object>{tmp8}, &label10);
    ca_.Goto(&block10);
    if (label10.is_used()) {
      ca_.Bind(&label10);
      ca_.Goto(&block11);
    }
  }

  TNode<IntPtrT> tmp11;
  TNode<Object> tmp12;
  if (block11.is_used()) {
    ca_.Bind(&block11);
    ca_.SetSourcePosition("../../../src/builtins/finalization-registry.tq", 214);
    tmp11 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp12 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{torque_arguments.frame}, TNode<RawPtrT>{torque_arguments.base}, TNode<IntPtrT>{torque_arguments.length}, TNode<IntPtrT>{torque_arguments.actual_count}}, TNode<IntPtrT>{tmp11});
    ca_.SetSourcePosition("../../../src/builtins/finalization-registry.tq", 213);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{parameter0}, MessageTemplate::kWeakRefsCleanupMustBeCallable, TNode<Object>{tmp12});
  }

  if (block10.is_used()) {
    ca_.Bind(&block10);
    ca_.SetSourcePosition("../../../src/builtins/finalization-registry.tq", 210);
    ca_.Goto(&block7, tmp9);
  }

  TNode<IntPtrT> tmp13;
  TNode<JSReceiver> tmp14;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.SetSourcePosition("../../../src/builtins/finalization-registry.tq", 216);
    tmp13 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    tmp14 = CodeStubAssembler(state_).LoadReference<JSReceiver>(CodeStubAssembler::Reference{tmp0, tmp13});
    ca_.SetSourcePosition("../../../src/builtins/finalization-registry.tq", 210);
    ca_.Goto(&block7, tmp14);
  }

  TNode<JSReceiver> phi_bb7_7;
  TNode<Oddball> tmp15;
  if (block7.is_used()) {
    ca_.Bind(&block7, &phi_bb7_7);
    ca_.SetSourcePosition("../../../src/builtins/finalization-registry.tq", 219);
    FinalizationRegistryCleanupLoop_0(state_, TNode<Context>{parameter0}, TNode<JSFinalizationRegistry>{tmp0}, TNode<JSReceiver>{phi_bb7_7});
    ca_.SetSourcePosition("../../../src/builtins/finalization-registry.tq", 220);
    tmp15 = Undefined_0(state_);
    arguments.PopAndReturn(tmp15);
  }
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/finalization-registry.tq?l=115&c=32
TNode<JSFinalizationRegistry> UnsafeCast_JSFinalizationRegistry_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<BoolT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 814);
    tmp0 = Is_JSFinalizationRegistry_Object_0(state_, TNode<Context>{p_context}, TNode<Object>{p_o});
    ca_.Branch(tmp0, &block2, std::vector<compiler::Node*>{}, &block3, std::vector<compiler::Node*>{});
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/cast.tq", 814});
      CodeStubAssembler(state_).FailAssert("Torque assert 'Is<A>(o)' failed", pos_stack);
    }
  }

  TNode<JSFinalizationRegistry> tmp1;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 815);
    tmp1 = TORQUE_CAST(TNode<Object>{p_o});
    ca_.SetSourcePosition("../../../src/builtins/finalization-registry.tq", 115);
    ca_.Goto(&block4);
  }

    ca_.Bind(&block4);
  return TNode<JSFinalizationRegistry>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/finalization-registry.tq?l=123&c=7
TNode<Smi> SmiTag_FinalizationRegistryFlags_0(compiler::CodeAssemblerState* state_, TNode<Uint32T> p_value) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Smi> tmp0;
  TNode<Smi> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/base.tq", 1210);
    tmp0 = CodeStubAssembler(state_).SmiFromUint32(TNode<Uint32T>{p_value});
    tmp1 = (TNode<Smi>{tmp0});
    ca_.SetSourcePosition("../../../src/builtins/finalization-registry.tq", 123);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Smi>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/finalization-registry.tq?l=138&c=32
TNode<JSFinalizationRegistry> Cast_JSFinalizationRegistry_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<HeapObject> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 162);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = CodeStubAssembler(state_).TaggedToHeapObject(TNode<Object>{p_o}, &label1);
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

  TNode<JSFinalizationRegistry> tmp2;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    compiler::CodeAssemblerLabel label3(&ca_);
    tmp2 = Cast_JSFinalizationRegistry_0(state_, TNode<HeapObject>{tmp0}, &label3);
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

  if (block5.is_used()) {
    ca_.Bind(&block5);
    ca_.SetSourcePosition("../../../src/builtins/finalization-registry.tq", 138);
    ca_.Goto(&block7);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_CastError);
  }

    ca_.Bind(&block7);
  return TNode<JSFinalizationRegistry>{tmp2};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/finalization-registry.tq?l=146&c=18
TNode<HeapObject> UnsafeCast_JSReceiver_OR_Symbol_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<BoolT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 814);
    tmp0 = Is_JSReceiver_OR_Symbol_Object_0(state_, TNode<Context>{p_context}, TNode<Object>{p_o});
    ca_.Branch(tmp0, &block2, std::vector<compiler::Node*>{}, &block3, std::vector<compiler::Node*>{});
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/cast.tq", 814});
      CodeStubAssembler(state_).FailAssert("Torque assert 'Is<A>(o)' failed", pos_stack);
    }
  }

  TNode<HeapObject> tmp1;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 815);
    tmp1 = TORQUE_CAST(TNode<Object>{p_o});
    ca_.SetSourcePosition("../../../src/builtins/finalization-registry.tq", 146);
    ca_.Goto(&block4);
  }

    ca_.Bind(&block4);
  return TNode<HeapObject>{tmp1};
}

} // namespace internal
} // namespace v8
