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
#include "torque-generated/src/builtins/object-tq-csa.h"
#include "torque-generated/src/builtins/array-every-tq-csa.h"
#include "torque-generated/src/builtins/array-join-tq-csa.h"
#include "torque-generated/src/builtins/base-tq-csa.h"
#include "torque-generated/src/builtins/cast-tq-csa.h"
#include "torque-generated/src/builtins/conversion-tq-csa.h"
#include "torque-generated/src/builtins/convert-tq-csa.h"
#include "torque-generated/src/builtins/object-tq-csa.h"
#include "torque-generated/src/builtins/promise-all-tq-csa.h"
#include "torque-generated/src/builtins/proxy-get-prototype-of-tq-csa.h"
#include "torque-generated/src/builtins/proxy-is-extensible-tq-csa.h"
#include "torque-generated/src/builtins/proxy-prevent-extensions-tq-csa.h"
#include "torque-generated/src/builtins/proxy-set-prototype-of-tq-csa.h"
#include "torque-generated/src/objects/contexts-tq-csa.h"
#include "torque-generated/src/objects/js-objects-tq-csa.h"
#include "torque-generated/src/objects/js-proxy-tq-csa.h"
#include "torque-generated/src/objects/map-tq-csa.h"
#include "torque-generated/src/objects/property-descriptor-object-tq-csa.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/object.tq?l=34&c=1
TNode<Object> ObjectIsExtensibleImpl_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_object) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<JSReceiver> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 36);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = Cast_JSReceiver_1(state_, TNode<Context>{p_context}, TNode<Object>{p_object}, &label1);
    ca_.Goto(&block4);
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block5);
    }
  }

  TNode<Oddball> tmp2;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    tmp2 = False_0(state_);
    ca_.Goto(&block1, tmp2);
  }

  TNode<JSProxy> tmp3;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 37);
    compiler::CodeAssemblerLabel label4(&ca_);
    tmp3 = Cast_JSProxy_0(state_, TNode<HeapObject>{tmp0}, &label4);
    ca_.Goto(&block8);
    if (label4.is_used()) {
      ca_.Bind(&label4);
      ca_.Goto(&block9);
    }
  }

  TNode<Object> tmp5;
  if (block9.is_used()) {
    ca_.Bind(&block9);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 38);
    tmp5 = CodeStubAssembler(state_).CallRuntime(Runtime::kObjectIsExtensible, p_context, tmp0); 
    ca_.Goto(&block1, tmp5);
  }

  TNode<Object> tmp6;
  if (block8.is_used()) {
    ca_.Bind(&block8);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 39);
    tmp6 = ca_.CallStub<Object>(Builtins::CallableFor(ca_.isolate(), Builtin::kProxyIsExtensible), p_context, tmp3);
    ca_.Goto(&block1, tmp6);
  }

  TNode<Object> phi_bb1_2;
  if (block1.is_used()) {
    ca_.Bind(&block1, &phi_bb1_2);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 34);
    ca_.Goto(&block10, phi_bb1_2);
  }

  TNode<Object> phi_bb10_2;
    ca_.Bind(&block10, &phi_bb10_2);
  return TNode<Object>{phi_bb10_2};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/object.tq?l=42&c=1
TNode<Object> ObjectPreventExtensionsThrow_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_object) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<JSReceiver> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 44);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = Cast_JSReceiver_1(state_, TNode<Context>{p_context}, TNode<Object>{p_object}, &label1);
    ca_.Goto(&block4);
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block5);
    }
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    ca_.Goto(&block1, p_object);
  }

  TNode<JSProxy> tmp2;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 45);
    compiler::CodeAssemblerLabel label3(&ca_);
    tmp2 = Cast_JSProxy_0(state_, TNode<HeapObject>{tmp0}, &label3);
    ca_.Goto(&block8);
    if (label3.is_used()) {
      ca_.Bind(&label3);
      ca_.Goto(&block9);
    }
  }

  TNode<Object> tmp4;
  if (block9.is_used()) {
    ca_.Bind(&block9);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 46);
    tmp4 = CodeStubAssembler(state_).CallRuntime(Runtime::kJSReceiverPreventExtensionsThrow, p_context, tmp0); 
    ca_.Goto(&block1, tmp4);
  }

  TNode<Oddball> tmp5;
  TNode<Object> tmp6;
  if (block8.is_used()) {
    ca_.Bind(&block8);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 47);
    tmp5 = True_0(state_);
    tmp6 = ca_.CallStub<Object>(Builtins::CallableFor(ca_.isolate(), Builtin::kProxyPreventExtensions), p_context, tmp2, tmp5);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 48);
    ca_.Goto(&block1, tmp0);
  }

  TNode<Object> phi_bb1_2;
  if (block1.is_used()) {
    ca_.Bind(&block1, &phi_bb1_2);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 42);
    ca_.Goto(&block10, phi_bb1_2);
  }

  TNode<Object> phi_bb10_2;
    ca_.Bind(&block10, &phi_bb10_2);
  return TNode<Object>{phi_bb10_2};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/object.tq?l=51&c=1
TNode<Object> ObjectPreventExtensionsDontThrow_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_object) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<JSReceiver> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 54);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = Cast_JSReceiver_1(state_, TNode<Context>{p_context}, TNode<Object>{p_object}, &label1);
    ca_.Goto(&block4);
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block5);
    }
  }

  TNode<Oddball> tmp2;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    tmp2 = False_0(state_);
    ca_.Goto(&block1, tmp2);
  }

  TNode<JSProxy> tmp3;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 55);
    compiler::CodeAssemblerLabel label4(&ca_);
    tmp3 = Cast_JSProxy_0(state_, TNode<HeapObject>{tmp0}, &label4);
    ca_.Goto(&block8);
    if (label4.is_used()) {
      ca_.Bind(&label4);
      ca_.Goto(&block9);
    }
  }

  TNode<Object> tmp5;
  if (block9.is_used()) {
    ca_.Bind(&block9);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 56);
    tmp5 = CodeStubAssembler(state_).CallRuntime(Runtime::kJSReceiverPreventExtensionsDontThrow, p_context, tmp0); 
    ca_.Goto(&block1, tmp5);
  }

  TNode<Oddball> tmp6;
  TNode<Object> tmp7;
  if (block8.is_used()) {
    ca_.Bind(&block8);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 58);
    tmp6 = False_0(state_);
    tmp7 = ca_.CallStub<Object>(Builtins::CallableFor(ca_.isolate(), Builtin::kProxyPreventExtensions), p_context, tmp3, tmp6);
    ca_.Goto(&block1, tmp7);
  }

  TNode<Object> phi_bb1_2;
  if (block1.is_used()) {
    ca_.Bind(&block1, &phi_bb1_2);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 51);
    ca_.Goto(&block10, phi_bb1_2);
  }

  TNode<Object> phi_bb10_2;
    ca_.Bind(&block10, &phi_bb10_2);
  return TNode<Object>{phi_bb10_2};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/object.tq?l=61&c=1
TNode<Object> ObjectGetPrototypeOfImpl_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_object) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<JSReceiver> tmp0;
  TNode<Object> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 63);
    tmp0 = CodeStubAssembler(state_).ToObject_Inline(TNode<Context>{p_context}, TNode<Object>{p_object});
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 64);
    tmp1 = JSReceiverGetPrototypeOf_0(state_, TNode<Context>{p_context}, TNode<JSReceiver>{tmp0});
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 61);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Object>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/object.tq?l=67&c=1
TNode<Object> JSReceiverGetPrototypeOf_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSReceiver> p_object) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<JSProxy> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 69);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = Cast_JSProxy_0(state_, TNode<HeapObject>{p_object}, &label1);
    ca_.Goto(&block4);
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block5);
    }
  }

  TNode<Object> tmp2;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 70);
    tmp2 = CodeStubAssembler(state_).CallRuntime(Runtime::kJSReceiverGetPrototypeOf, p_context, p_object); 
    ca_.Goto(&block1, tmp2);
  }

  TNode<Object> tmp3;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 71);
    tmp3 = ca_.CallStub<Object>(Builtins::CallableFor(ca_.isolate(), Builtin::kProxyGetPrototypeOf), p_context, tmp0);
    ca_.Goto(&block1, tmp3);
  }

  TNode<Object> phi_bb1_2;
  if (block1.is_used()) {
    ca_.Bind(&block1, &phi_bb1_2);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 67);
    ca_.Goto(&block6);
  }

    ca_.Bind(&block6);
  return TNode<Object>{phi_bb1_2};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/object.tq?l=74&c=1
TNode<Object> ObjectSetPrototypeOfThrow_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_object, TNode<HeapObject> p_proto) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<JSReceiver> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 77);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = Cast_JSReceiver_1(state_, TNode<Context>{p_context}, TNode<Object>{p_object}, &label1);
    ca_.Goto(&block4);
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block5);
    }
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    ca_.Goto(&block1, p_object);
  }

  TNode<JSProxy> tmp2;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 78);
    compiler::CodeAssemblerLabel label3(&ca_);
    tmp2 = Cast_JSProxy_0(state_, TNode<HeapObject>{tmp0}, &label3);
    ca_.Goto(&block8);
    if (label3.is_used()) {
      ca_.Bind(&label3);
      ca_.Goto(&block9);
    }
  }

  TNode<Object> tmp4;
  if (block9.is_used()) {
    ca_.Bind(&block9);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 79);
    tmp4 = CodeStubAssembler(state_).CallRuntime(Runtime::kJSReceiverSetPrototypeOfThrow, p_context, tmp0, p_proto); 
    ca_.Goto(&block1, tmp4);
  }

  TNode<Oddball> tmp5;
  TNode<Object> tmp6;
  if (block8.is_used()) {
    ca_.Bind(&block8);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 81);
    tmp5 = True_0(state_);
    tmp6 = ca_.CallStub<Object>(Builtins::CallableFor(ca_.isolate(), Builtin::kProxySetPrototypeOf), p_context, tmp2, p_proto, tmp5);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 82);
    ca_.Goto(&block1, tmp0);
  }

  TNode<Object> phi_bb1_3;
  if (block1.is_used()) {
    ca_.Bind(&block1, &phi_bb1_3);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 74);
    ca_.Goto(&block10, phi_bb1_3);
  }

  TNode<Object> phi_bb10_3;
    ca_.Bind(&block10, &phi_bb10_3);
  return TNode<Object>{phi_bb10_3};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/object.tq?l=85&c=1
TNode<Object> ObjectSetPrototypeOfDontThrow_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_object, TNode<HeapObject> p_proto) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<JSReceiver> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 88);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = Cast_JSReceiver_1(state_, TNode<Context>{p_context}, TNode<Object>{p_object}, &label1);
    ca_.Goto(&block4);
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block5);
    }
  }

  TNode<Oddball> tmp2;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    tmp2 = False_0(state_);
    ca_.Goto(&block1, tmp2);
  }

  TNode<JSProxy> tmp3;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 89);
    compiler::CodeAssemblerLabel label4(&ca_);
    tmp3 = Cast_JSProxy_0(state_, TNode<HeapObject>{tmp0}, &label4);
    ca_.Goto(&block8);
    if (label4.is_used()) {
      ca_.Bind(&label4);
      ca_.Goto(&block9);
    }
  }

  TNode<Object> tmp5;
  if (block9.is_used()) {
    ca_.Bind(&block9);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 90);
    tmp5 = CodeStubAssembler(state_).CallRuntime(Runtime::kJSReceiverSetPrototypeOfDontThrow, p_context, tmp0, p_proto); 
    ca_.Goto(&block1, tmp5);
  }

  TNode<Oddball> tmp6;
  TNode<Object> tmp7;
  if (block8.is_used()) {
    ca_.Bind(&block8);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 92);
    tmp6 = False_0(state_);
    tmp7 = ca_.CallStub<Object>(Builtins::CallableFor(ca_.isolate(), Builtin::kProxySetPrototypeOf), p_context, tmp3, p_proto, tmp6);
    ca_.Goto(&block1, tmp7);
  }

  TNode<Object> phi_bb1_3;
  if (block1.is_used()) {
    ca_.Bind(&block1, &phi_bb1_3);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 85);
    ca_.Goto(&block10, phi_bb1_3);
  }

  TNode<Object> phi_bb10_3;
    ca_.Bind(&block10, &phi_bb10_3);
  return TNode<Object>{phi_bb10_3};
}

TF_BUILTIN(CreateObjectWithoutProperties, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedParameter<Context>(Descriptor::kContext);
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kPrototype);
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Map> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Map, HeapObject> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    ca_.Goto(&block0);

  TNode<Oddball> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 101);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = Cast_Null_1(state_, TNode<Context>{parameter0}, TNode<Object>{parameter1}, &label1);
    ca_.Goto(&block5);
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block6);
    }
  }

  TNode<JSReceiver> tmp2;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 112);
    compiler::CodeAssemblerLabel label3(&ca_);
    tmp2 = Cast_JSReceiver_1(state_, TNode<Context>{parameter0}, TNode<Object>{ca_.UncheckedCast<Object>(parameter1)}, &label3);
    ca_.Goto(&block9);
    if (label3.is_used()) {
      ca_.Bind(&label3);
      ca_.Goto(&block10);
    }
  }

  TNode<IntPtrT> tmp4;
  TNode<Object> tmp5;
  TNode<IntPtrT> tmp6;
  TNode<Map> tmp7;
  TNode<NameDictionary> tmp8;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 103);
    tmp4 = SLOW_OBJECT_WITH_NULL_PROTOTYPE_MAP_0(state_);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 102);
    std::tie(tmp5, tmp6) = NativeContextSlot_Context_Map_0(state_, TNode<Context>{parameter0}, TNode<IntPtrT>{tmp4}).Flatten();
    tmp7 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference{tmp5, tmp6});
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 109);
    tmp8 = CodeStubAssembler(state_).AllocateNameDictionary(NameDictionary::kInitialCapacity);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 101);
    ca_.Goto(&block3, tmp7, tmp8);
  }

  if (block10.is_used()) {
    ca_.Bind(&block10);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 130);
    ca_.Goto(&block2);
  }

  TNode<FixedArray> tmp9;
  TNode<IntPtrT> tmp10;
  TNode<Object> tmp11;
  TNode<IntPtrT> tmp12;
  TNode<JSFunction> tmp13;
  TNode<IntPtrT> tmp14;
  TNode<HeapObject> tmp15;
  TNode<Map> tmp16;
  TNode<IntPtrT> tmp17;
  TNode<HeapObject> tmp18;
  TNode<BoolT> tmp19;
  if (block9.is_used()) {
    ca_.Bind(&block9);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 113);
    tmp9 = kEmptyFixedArray_0(state_);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 115);
    tmp10 = OBJECT_FUNCTION_INDEX_0(state_);
    std::tie(tmp11, tmp12) = NativeContextSlot_Context_JSFunction_0(state_, TNode<Context>{parameter0}, TNode<IntPtrT>{tmp10}).Flatten();
    tmp13 = CodeStubAssembler(state_).LoadReference<JSFunction>(CodeStubAssembler::Reference{tmp11, tmp12});
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 116);
    tmp14 = FromConstexpr_intptr_constexpr_int31_0(state_, 28);
    tmp15 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{tmp13, tmp14});
    tmp16 = UnsafeCast_Map_0(state_, TNode<Context>{parameter0}, TNode<Object>{tmp15});
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 117);
    tmp17 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    tmp18 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{tmp16, tmp17});
    tmp19 = CodeStubAssembler(state_).TaggedNotEqual(TNode<HeapObject>{tmp2}, TNode<HeapObject>{tmp18});
    ca_.Branch(tmp19, &block11, std::vector<compiler::Node*>{}, &block12, std::vector<compiler::Node*>{tmp16});
  }

  TNode<IntPtrT> tmp20;
  TNode<Map> tmp21;
  TNode<PrototypeInfo> tmp22;
  if (block11.is_used()) {
    ca_.Bind(&block11);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 118);
    tmp20 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp21 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference{tmp2, tmp20});
    compiler::CodeAssemblerLabel label23(&ca_);
    tmp22 = Method_Map_PrototypeInfo_0(state_, TNode<Map>{tmp21}, &label23);
    ca_.Goto(&block13);
    if (label23.is_used()) {
      ca_.Bind(&label23);
      ca_.Goto(&block14);
    }
  }

  if (block14.is_used()) {
    ca_.Bind(&block14);
    ca_.Goto(&block2);
  }

  TNode<IntPtrT> tmp24;
  TNode<MaybeObject> tmp25;
  TNode<Oddball> tmp26;
  if (block13.is_used()) {
    ca_.Bind(&block13);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 119);
    tmp24 = FromConstexpr_intptr_constexpr_int31_0(state_, 24);
    tmp25 = CodeStubAssembler(state_).LoadReference<MaybeObject>(CodeStubAssembler::Reference{tmp22, tmp24});
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 120);
    compiler::CodeAssemblerLabel label27(&ca_);
    tmp26 = Cast_Undefined_0(state_, TNode<MaybeObject>{tmp25}, &label27);
    ca_.Goto(&block17);
    if (label27.is_used()) {
      ca_.Bind(&label27);
      ca_.Goto(&block18);
    }
  }

  TNode<Map> tmp28;
  if (block18.is_used()) {
    ca_.Bind(&block18);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 124);
    compiler::CodeAssemblerLabel label29(&ca_);
    tmp28 = WeakToStrong_Map_0(state_, TNode<MaybeObject>{ca_.UncheckedCast<MaybeObject>(tmp25)}, &label29);
    ca_.Goto(&block19);
    if (label29.is_used()) {
      ca_.Bind(&label29);
      ca_.Goto(&block20);
    }
  }

  if (block17.is_used()) {
    ca_.Bind(&block17);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 121);
    ca_.Goto(&block2);
  }

  if (block20.is_used()) {
    ca_.Bind(&block20);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 124);
    ca_.Goto(&block2);
  }

  if (block19.is_used()) {
    ca_.Bind(&block19);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 117);
    ca_.Goto(&block12, tmp28);
  }

  TNode<Map> phi_bb12_2;
  if (block12.is_used()) {
    ca_.Bind(&block12, &phi_bb12_2);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 101);
    ca_.Goto(&block3, phi_bb12_2, tmp9);
  }

  TNode<Map> phi_bb3_2;
  TNode<HeapObject> phi_bb3_3;
  TNode<JSObject> tmp30;
  if (block3.is_used()) {
    ca_.Bind(&block3, &phi_bb3_2, &phi_bb3_3);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 133);
    tmp30 = CodeStubAssembler(state_).AllocateJSObjectFromMap(TNode<Map>{phi_bb3_2}, TNode<HeapObject>{phi_bb3_3});
    CodeStubAssembler(state_).Return(tmp30);
  }

  TNode<Oddball> tmp31;
  TNode<Object> tmp32;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 135);
    tmp31 = Undefined_0(state_);
    tmp32 = CodeStubAssembler(state_).CallRuntime(Runtime::kObjectCreate, parameter0, parameter1, tmp31); 
    CodeStubAssembler(state_).Return(tmp32);
  }
}

TF_BUILTIN(ObjectIsExtensible, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kObject);
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Object> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 142);
    tmp0 = ObjectIsExtensibleImpl_0(state_, TNode<Context>{parameter0}, TNode<Object>{parameter1});
    CodeStubAssembler(state_).Return(tmp0);
  }
}

TF_BUILTIN(ObjectPreventExtensions, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kObject);
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Object> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 149);
    tmp0 = ObjectPreventExtensionsThrow_0(state_, TNode<Context>{parameter0}, TNode<Object>{parameter1});
    CodeStubAssembler(state_).Return(tmp0);
  }
}

TF_BUILTIN(ObjectGetPrototypeOf, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kObject);
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Object> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 155);
    tmp0 = ObjectGetPrototypeOfImpl_0(state_, TNode<Context>{parameter0}, TNode<Object>{parameter1});
    CodeStubAssembler(state_).Return(tmp0);
  }
}

TF_BUILTIN(ObjectSetPrototypeOf, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kObject);
  USE(parameter1);
  TNode<Object> parameter2 = UncheckedParameter<Object>(Descriptor::kProto);
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Object> tmp0;
  TNode<HeapObject> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 162);
    tmp0 = RequireObjectCoercible_0(state_, TNode<Context>{parameter0}, TNode<Object>{parameter1}, "Object.setPrototypeOf");
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 171);
    compiler::CodeAssemblerLabel label2(&ca_);
    tmp1 = Cast_JSReceiver_OR_Null_1(state_, TNode<Context>{parameter0}, TNode<Object>{parameter2}, &label2);
    ca_.Goto(&block3);
    if (label2.is_used()) {
      ca_.Bind(&label2);
      ca_.Goto(&block4);
    }
  }

  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 175);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{parameter0}, MessageTemplate::kProtoObjectOrNull, TNode<Object>{parameter2});
  }

  TNode<Object> tmp3;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 172);
    tmp3 = ObjectSetPrototypeOfThrow_0(state_, TNode<Context>{parameter0}, TNode<Object>{parameter1}, TNode<HeapObject>{tmp1});
    CodeStubAssembler(state_).Return(tmp3);
  }
}

TF_BUILTIN(ObjectPrototypeToString, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kReceiver);
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<String> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 183);
    tmp0 = ca_.CallStub<String>(Builtins::CallableFor(ca_.isolate(), Builtin::kObjectToString), parameter0, parameter1);
    CodeStubAssembler(state_).Return(tmp0);
  }
}

TF_BUILTIN(ObjectPrototypeValueOf, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kReceiver);
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<JSReceiver> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 190);
    tmp0 = CodeStubAssembler(state_).ToObject_Inline(TNode<Context>{parameter0}, TNode<Object>{parameter1});
    CodeStubAssembler(state_).Return(tmp0);
  }
}

TF_BUILTIN(ObjectPrototypeToLocaleString, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kReceiver);
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Oddball> tmp0;
  TNode<BoolT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 198);
    tmp0 = Null_0(state_);
    tmp1 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{parameter1}, TNode<HeapObject>{tmp0});
    ca_.Branch(tmp1, &block3, std::vector<compiler::Node*>{}, &block4, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp2;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    tmp2 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block5, tmp2);
  }

  TNode<Oddball> tmp3;
  TNode<BoolT> tmp4;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    tmp3 = Undefined_0(state_);
    tmp4 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{parameter1}, TNode<HeapObject>{tmp3});
    ca_.Goto(&block5, tmp4);
  }

  TNode<BoolT> phi_bb5_3;
  if (block5.is_used()) {
    ca_.Bind(&block5, &phi_bb5_3);
    ca_.Branch(phi_bb5_3, &block1, std::vector<compiler::Node*>{}, &block2, std::vector<compiler::Node*>{});
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 199);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{parameter0}, MessageTemplate::kCalledOnNullOrUndefined, "Object.prototype.toLocaleString");
  }

  TNode<Object> tmp5;
  TNode<Object> tmp6;
  TNode<Object> tmp7;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 203);
    tmp5 = FromConstexpr_JSAny_constexpr_string_0(state_, "toString");
    tmp6 = CodeStubAssembler(state_).GetProperty(TNode<Context>{parameter0}, TNode<Object>{parameter1}, TNode<Object>{tmp5});
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 204);
    tmp7 = CodeStubAssembler(state_).Call(TNode<Context>{parameter0}, TNode<Object>{tmp6}, TNode<Object>{parameter1});
    CodeStubAssembler(state_).Return(tmp7);
  }
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/object.tq?l=228&c=1
TNode<PropertyDescriptorObject> ToPropertyDescriptor_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSReceiver> p_object) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block26(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block25(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block27(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block31(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block32(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block33(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block29(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block37(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block36(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block30(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block28(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block38(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<PropertyDescriptorObject> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<Map> tmp2;
  TNode<IntPtrT> tmp3;
  TNode<Object> tmp4;
  TNode<IntPtrT> tmp5;
  TNode<Map> tmp6;
  TNode<BoolT> tmp7;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 230);
    tmp0 = CodeStubAssembler(state_).AllocatePropertyDescriptorObject(TNode<Context>{p_context});
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 232);
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp2 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference{p_object, tmp1});
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 233);
    tmp3 = DATA_PROPERTY_DESCRIPTOR_MAP_INDEX_0(state_);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 232);
    std::tie(tmp4, tmp5) = NativeContextSlot_Map_0(state_, TNode<Context>{p_context}, TNode<IntPtrT>{tmp3}).Flatten();
    tmp6 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference{tmp4, tmp5});
    tmp7 = CodeStubAssembler(state_).TaggedEqual(TNode<HeapObject>{tmp2}, TNode<HeapObject>{tmp6});
    ca_.Branch(tmp7, &block2, std::vector<compiler::Node*>{}, &block3, std::vector<compiler::Node*>{});
  }

  TNode<Object> tmp8;
  TNode<Object> tmp9;
  TNode<IntPtrT> tmp10;
  TNode<Smi> tmp11;
  TNode<BoolT> tmp12;
  TNode<Smi> tmp13;
  TNode<IntPtrT> tmp14;
  TNode<BoolT> tmp15;
  TNode<Smi> tmp16;
  TNode<Smi> tmp17;
  TNode<Object> tmp18;
  TNode<Object> tmp19;
  TNode<IntPtrT> tmp20;
  TNode<Smi> tmp21;
  TNode<BoolT> tmp22;
  TNode<Smi> tmp23;
  TNode<IntPtrT> tmp24;
  TNode<BoolT> tmp25;
  TNode<Smi> tmp26;
  TNode<Smi> tmp27;
  TNode<Object> tmp28;
  TNode<Object> tmp29;
  TNode<IntPtrT> tmp30;
  TNode<Smi> tmp31;
  TNode<BoolT> tmp32;
  TNode<Smi> tmp33;
  TNode<IntPtrT> tmp34;
  TNode<BoolT> tmp35;
  TNode<Smi> tmp36;
  TNode<Smi> tmp37;
  TNode<IntPtrT> tmp38;
  TNode<Smi> tmp39;
  TNode<BoolT> tmp40;
  TNode<Smi> tmp41;
  TNode<IntPtrT> tmp42;
  TNode<Object> tmp43;
  TNode<Object> tmp44;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 235);
    tmp8 = CodeStubAssembler(state_).LoadObjectField(TNode<HeapObject>{p_object}, JSDataPropertyDescriptor::kWritableOffset);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 234);
    tmp9 = UnsafeCast_JSAny_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp8});
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 236);
    tmp10 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp11 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp0, tmp10});
    tmp12 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    tmp13 = ca_.UncheckedCast<Smi>(ca_.BitcastWordToTaggedSigned(CodeStubAssembler(state_).UpdateWord32InWord<base::BitField<bool, 6, 1, uintptr_t>>(ca_.UncheckedCast<WordT>(ca_.BitcastTaggedToWordForTagAndSmiBits(tmp11)), ca_.UncheckedCast<Uint32T>(tmp12))));
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{tmp0, tmp10}, tmp13);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 237);
    tmp14 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp15 = ToBoolean_0(state_, TNode<Object>{tmp9});
    tmp16 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp0, tmp14});
    tmp17 = ca_.UncheckedCast<Smi>(ca_.BitcastWordToTaggedSigned(CodeStubAssembler(state_).UpdateWord32InWord<base::BitField<bool, 5, 1, uintptr_t>>(ca_.UncheckedCast<WordT>(ca_.BitcastTaggedToWordForTagAndSmiBits(tmp16)), ca_.UncheckedCast<Uint32T>(tmp15))));
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{tmp0, tmp14}, tmp17);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 240);
    tmp18 = CodeStubAssembler(state_).LoadObjectField(TNode<HeapObject>{p_object}, JSDataPropertyDescriptor::kEnumerableOffset);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 239);
    tmp19 = UnsafeCast_JSAny_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp18});
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 241);
    tmp20 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp21 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp0, tmp20});
    tmp22 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    tmp23 = ca_.UncheckedCast<Smi>(ca_.BitcastWordToTaggedSigned(CodeStubAssembler(state_).UpdateWord32InWord<base::BitField<bool, 2, 1, uintptr_t>>(ca_.UncheckedCast<WordT>(ca_.BitcastTaggedToWordForTagAndSmiBits(tmp21)), ca_.UncheckedCast<Uint32T>(tmp22))));
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{tmp0, tmp20}, tmp23);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 242);
    tmp24 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp25 = ToBoolean_0(state_, TNode<Object>{tmp19});
    tmp26 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp0, tmp24});
    tmp27 = ca_.UncheckedCast<Smi>(ca_.BitcastWordToTaggedSigned(CodeStubAssembler(state_).UpdateWord32InWord<base::BitField<bool, 1, 1, uintptr_t>>(ca_.UncheckedCast<WordT>(ca_.BitcastTaggedToWordForTagAndSmiBits(tmp26)), ca_.UncheckedCast<Uint32T>(tmp25))));
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{tmp0, tmp24}, tmp27);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 245);
    tmp28 = CodeStubAssembler(state_).LoadObjectField(TNode<HeapObject>{p_object}, JSDataPropertyDescriptor::kConfigurableOffset);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 244);
    tmp29 = UnsafeCast_JSAny_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp28});
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 246);
    tmp30 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp31 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp0, tmp30});
    tmp32 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    tmp33 = ca_.UncheckedCast<Smi>(ca_.BitcastWordToTaggedSigned(CodeStubAssembler(state_).UpdateWord32InWord<base::BitField<bool, 4, 1, uintptr_t>>(ca_.UncheckedCast<WordT>(ca_.BitcastTaggedToWordForTagAndSmiBits(tmp31)), ca_.UncheckedCast<Uint32T>(tmp32))));
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{tmp0, tmp30}, tmp33);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 247);
    tmp34 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp35 = ToBoolean_0(state_, TNode<Object>{tmp29});
    tmp36 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp0, tmp34});
    tmp37 = ca_.UncheckedCast<Smi>(ca_.BitcastWordToTaggedSigned(CodeStubAssembler(state_).UpdateWord32InWord<base::BitField<bool, 3, 1, uintptr_t>>(ca_.UncheckedCast<WordT>(ca_.BitcastTaggedToWordForTagAndSmiBits(tmp36)), ca_.UncheckedCast<Uint32T>(tmp35))));
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{tmp0, tmp34}, tmp37);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 249);
    tmp38 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp39 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp0, tmp38});
    tmp40 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    tmp41 = ca_.UncheckedCast<Smi>(ca_.BitcastWordToTaggedSigned(CodeStubAssembler(state_).UpdateWord32InWord<base::BitField<bool, 7, 1, uintptr_t>>(ca_.UncheckedCast<WordT>(ca_.BitcastTaggedToWordForTagAndSmiBits(tmp39)), ca_.UncheckedCast<Uint32T>(tmp40))));
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{tmp0, tmp38}, tmp41);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 250);
    tmp42 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 251);
    tmp43 = CodeStubAssembler(state_).LoadObjectField(TNode<HeapObject>{p_object}, JSDataPropertyDescriptor::kValueOffset);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 250);
    tmp44 = UnsafeCast_JSAny_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp43});
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp0, tmp42}, tmp44);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 232);
    ca_.Goto(&block4);
  }

  TNode<IntPtrT> tmp45;
  TNode<Map> tmp46;
  TNode<IntPtrT> tmp47;
  TNode<Object> tmp48;
  TNode<IntPtrT> tmp49;
  TNode<Map> tmp50;
  TNode<BoolT> tmp51;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 253);
    tmp45 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp46 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference{p_object, tmp45});
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 254);
    tmp47 = ACCESSOR_PROPERTY_DESCRIPTOR_MAP_INDEX_0(state_);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 253);
    std::tie(tmp48, tmp49) = NativeContextSlot_Map_0(state_, TNode<Context>{p_context}, TNode<IntPtrT>{tmp47}).Flatten();
    tmp50 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference{tmp48, tmp49});
    tmp51 = CodeStubAssembler(state_).TaggedEqual(TNode<HeapObject>{tmp46}, TNode<HeapObject>{tmp50});
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 252);
    ca_.Branch(tmp51, &block5, std::vector<compiler::Node*>{}, &block6, std::vector<compiler::Node*>{});
  }

  TNode<Object> tmp52;
  TNode<Object> tmp53;
  TNode<IntPtrT> tmp54;
  TNode<Smi> tmp55;
  TNode<BoolT> tmp56;
  TNode<Smi> tmp57;
  TNode<IntPtrT> tmp58;
  TNode<BoolT> tmp59;
  TNode<Smi> tmp60;
  TNode<Smi> tmp61;
  TNode<Object> tmp62;
  TNode<Object> tmp63;
  TNode<IntPtrT> tmp64;
  TNode<Smi> tmp65;
  TNode<BoolT> tmp66;
  TNode<Smi> tmp67;
  TNode<IntPtrT> tmp68;
  TNode<BoolT> tmp69;
  TNode<Smi> tmp70;
  TNode<Smi> tmp71;
  TNode<IntPtrT> tmp72;
  TNode<Smi> tmp73;
  TNode<BoolT> tmp74;
  TNode<Smi> tmp75;
  TNode<IntPtrT> tmp76;
  TNode<Object> tmp77;
  TNode<Object> tmp78;
  TNode<IntPtrT> tmp79;
  TNode<Smi> tmp80;
  TNode<BoolT> tmp81;
  TNode<Smi> tmp82;
  TNode<IntPtrT> tmp83;
  TNode<Object> tmp84;
  TNode<Object> tmp85;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 256);
    tmp52 = CodeStubAssembler(state_).LoadObjectField(TNode<HeapObject>{p_object}, JSAccessorPropertyDescriptor::kEnumerableOffset);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 255);
    tmp53 = UnsafeCast_JSAny_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp52});
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 257);
    tmp54 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp55 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp0, tmp54});
    tmp56 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    tmp57 = ca_.UncheckedCast<Smi>(ca_.BitcastWordToTaggedSigned(CodeStubAssembler(state_).UpdateWord32InWord<base::BitField<bool, 2, 1, uintptr_t>>(ca_.UncheckedCast<WordT>(ca_.BitcastTaggedToWordForTagAndSmiBits(tmp55)), ca_.UncheckedCast<Uint32T>(tmp56))));
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{tmp0, tmp54}, tmp57);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 258);
    tmp58 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp59 = ToBoolean_0(state_, TNode<Object>{tmp53});
    tmp60 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp0, tmp58});
    tmp61 = ca_.UncheckedCast<Smi>(ca_.BitcastWordToTaggedSigned(CodeStubAssembler(state_).UpdateWord32InWord<base::BitField<bool, 1, 1, uintptr_t>>(ca_.UncheckedCast<WordT>(ca_.BitcastTaggedToWordForTagAndSmiBits(tmp60)), ca_.UncheckedCast<Uint32T>(tmp59))));
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{tmp0, tmp58}, tmp61);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 260);
    tmp62 = CodeStubAssembler(state_).LoadObjectField(TNode<HeapObject>{p_object}, JSAccessorPropertyDescriptor::kConfigurableOffset);
    tmp63 = UnsafeCast_JSAny_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp62});
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 262);
    tmp64 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp65 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp0, tmp64});
    tmp66 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    tmp67 = ca_.UncheckedCast<Smi>(ca_.BitcastWordToTaggedSigned(CodeStubAssembler(state_).UpdateWord32InWord<base::BitField<bool, 4, 1, uintptr_t>>(ca_.UncheckedCast<WordT>(ca_.BitcastTaggedToWordForTagAndSmiBits(tmp65)), ca_.UncheckedCast<Uint32T>(tmp66))));
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{tmp0, tmp64}, tmp67);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 263);
    tmp68 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp69 = ToBoolean_0(state_, TNode<Object>{tmp63});
    tmp70 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp0, tmp68});
    tmp71 = ca_.UncheckedCast<Smi>(ca_.BitcastWordToTaggedSigned(CodeStubAssembler(state_).UpdateWord32InWord<base::BitField<bool, 3, 1, uintptr_t>>(ca_.UncheckedCast<WordT>(ca_.BitcastTaggedToWordForTagAndSmiBits(tmp70)), ca_.UncheckedCast<Uint32T>(tmp69))));
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{tmp0, tmp68}, tmp71);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 265);
    tmp72 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp73 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp0, tmp72});
    tmp74 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    tmp75 = ca_.UncheckedCast<Smi>(ca_.BitcastWordToTaggedSigned(CodeStubAssembler(state_).UpdateWord32InWord<base::BitField<bool, 8, 1, uintptr_t>>(ca_.UncheckedCast<WordT>(ca_.BitcastTaggedToWordForTagAndSmiBits(tmp73)), ca_.UncheckedCast<Uint32T>(tmp74))));
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{tmp0, tmp72}, tmp75);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 266);
    tmp76 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 267);
    tmp77 = CodeStubAssembler(state_).LoadObjectField(TNode<HeapObject>{p_object}, JSAccessorPropertyDescriptor::kGetOffset);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 266);
    tmp78 = UnsafeCast_JSAny_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp77});
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp0, tmp76}, tmp78);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 269);
    tmp79 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp80 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp0, tmp79});
    tmp81 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    tmp82 = ca_.UncheckedCast<Smi>(ca_.BitcastWordToTaggedSigned(CodeStubAssembler(state_).UpdateWord32InWord<base::BitField<bool, 9, 1, uintptr_t>>(ca_.UncheckedCast<WordT>(ca_.BitcastTaggedToWordForTagAndSmiBits(tmp80)), ca_.UncheckedCast<Uint32T>(tmp81))));
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{tmp0, tmp79}, tmp82);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 270);
    tmp83 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 271);
    tmp84 = CodeStubAssembler(state_).LoadObjectField(TNode<HeapObject>{p_object}, JSAccessorPropertyDescriptor::kSetOffset);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 270);
    tmp85 = UnsafeCast_JSAny_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp84});
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp0, tmp83}, tmp85);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 252);
    ca_.Goto(&block7);
  }

  TNode<Object> tmp86;
  TNode<Oddball> tmp87;
  TNode<Oddball> tmp88;
  TNode<BoolT> tmp89;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 273);
    tmp86 = FromConstexpr_JSAny_constexpr_string_0(state_, "enumerable");
    tmp87 = ca_.CallStub<Oddball>(Builtins::CallableFor(ca_.isolate(), Builtin::kHasProperty), p_context, p_object, tmp86);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 274);
    tmp88 = True_0(state_);
    tmp89 = CodeStubAssembler(state_).TaggedEqual(TNode<HeapObject>{tmp87}, TNode<HeapObject>{tmp88});
    ca_.Branch(tmp89, &block8, std::vector<compiler::Node*>{}, &block9, std::vector<compiler::Node*>{});
  }

  TNode<Object> tmp90;
  TNode<Object> tmp91;
  TNode<BoolT> tmp92;
  TNode<IntPtrT> tmp93;
  TNode<Smi> tmp94;
  TNode<BoolT> tmp95;
  TNode<Smi> tmp96;
  TNode<IntPtrT> tmp97;
  TNode<Smi> tmp98;
  TNode<Smi> tmp99;
  if (block8.is_used()) {
    ca_.Bind(&block8);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 275);
    tmp90 = FromConstexpr_JSAny_constexpr_string_0(state_, "enumerable");
    tmp91 = CodeStubAssembler(state_).GetProperty(TNode<Context>{p_context}, TNode<Object>{p_object}, TNode<Object>{tmp90});
    tmp92 = ToBoolean_0(state_, TNode<Object>{tmp91});
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 276);
    tmp93 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp94 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp0, tmp93});
    tmp95 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    tmp96 = ca_.UncheckedCast<Smi>(ca_.BitcastWordToTaggedSigned(CodeStubAssembler(state_).UpdateWord32InWord<base::BitField<bool, 2, 1, uintptr_t>>(ca_.UncheckedCast<WordT>(ca_.BitcastTaggedToWordForTagAndSmiBits(tmp94)), ca_.UncheckedCast<Uint32T>(tmp95))));
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{tmp0, tmp93}, tmp96);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 277);
    tmp97 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp98 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp0, tmp97});
    tmp99 = ca_.UncheckedCast<Smi>(ca_.BitcastWordToTaggedSigned(CodeStubAssembler(state_).UpdateWord32InWord<base::BitField<bool, 1, 1, uintptr_t>>(ca_.UncheckedCast<WordT>(ca_.BitcastTaggedToWordForTagAndSmiBits(tmp98)), ca_.UncheckedCast<Uint32T>(tmp92))));
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{tmp0, tmp97}, tmp99);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 274);
    ca_.Goto(&block9);
  }

  TNode<Object> tmp100;
  TNode<Oddball> tmp101;
  TNode<Oddball> tmp102;
  TNode<BoolT> tmp103;
  if (block9.is_used()) {
    ca_.Bind(&block9);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 280);
    tmp100 = FromConstexpr_JSAny_constexpr_string_0(state_, "configurable");
    tmp101 = ca_.CallStub<Oddball>(Builtins::CallableFor(ca_.isolate(), Builtin::kHasProperty), p_context, p_object, tmp100);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 281);
    tmp102 = True_0(state_);
    tmp103 = CodeStubAssembler(state_).TaggedEqual(TNode<HeapObject>{tmp101}, TNode<HeapObject>{tmp102});
    ca_.Branch(tmp103, &block10, std::vector<compiler::Node*>{}, &block11, std::vector<compiler::Node*>{});
  }

  TNode<Object> tmp104;
  TNode<Object> tmp105;
  TNode<BoolT> tmp106;
  TNode<IntPtrT> tmp107;
  TNode<Smi> tmp108;
  TNode<BoolT> tmp109;
  TNode<Smi> tmp110;
  TNode<IntPtrT> tmp111;
  TNode<Smi> tmp112;
  TNode<Smi> tmp113;
  if (block10.is_used()) {
    ca_.Bind(&block10);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 282);
    tmp104 = FromConstexpr_JSAny_constexpr_string_0(state_, "configurable");
    tmp105 = CodeStubAssembler(state_).GetProperty(TNode<Context>{p_context}, TNode<Object>{p_object}, TNode<Object>{tmp104});
    tmp106 = ToBoolean_0(state_, TNode<Object>{tmp105});
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 283);
    tmp107 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp108 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp0, tmp107});
    tmp109 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    tmp110 = ca_.UncheckedCast<Smi>(ca_.BitcastWordToTaggedSigned(CodeStubAssembler(state_).UpdateWord32InWord<base::BitField<bool, 4, 1, uintptr_t>>(ca_.UncheckedCast<WordT>(ca_.BitcastTaggedToWordForTagAndSmiBits(tmp108)), ca_.UncheckedCast<Uint32T>(tmp109))));
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{tmp0, tmp107}, tmp110);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 284);
    tmp111 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp112 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp0, tmp111});
    tmp113 = ca_.UncheckedCast<Smi>(ca_.BitcastWordToTaggedSigned(CodeStubAssembler(state_).UpdateWord32InWord<base::BitField<bool, 3, 1, uintptr_t>>(ca_.UncheckedCast<WordT>(ca_.BitcastTaggedToWordForTagAndSmiBits(tmp112)), ca_.UncheckedCast<Uint32T>(tmp106))));
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{tmp0, tmp111}, tmp113);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 281);
    ca_.Goto(&block11);
  }

  TNode<Object> tmp114;
  TNode<Oddball> tmp115;
  TNode<Oddball> tmp116;
  TNode<BoolT> tmp117;
  if (block11.is_used()) {
    ca_.Bind(&block11);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 287);
    tmp114 = FromConstexpr_JSAny_constexpr_string_0(state_, "value");
    tmp115 = ca_.CallStub<Oddball>(Builtins::CallableFor(ca_.isolate(), Builtin::kHasProperty), p_context, p_object, tmp114);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 288);
    tmp116 = True_0(state_);
    tmp117 = CodeStubAssembler(state_).TaggedEqual(TNode<HeapObject>{tmp115}, TNode<HeapObject>{tmp116});
    ca_.Branch(tmp117, &block12, std::vector<compiler::Node*>{}, &block13, std::vector<compiler::Node*>{});
  }

  TNode<Object> tmp118;
  TNode<Object> tmp119;
  TNode<IntPtrT> tmp120;
  TNode<Smi> tmp121;
  TNode<BoolT> tmp122;
  TNode<Smi> tmp123;
  TNode<IntPtrT> tmp124;
  if (block12.is_used()) {
    ca_.Bind(&block12);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 289);
    tmp118 = FromConstexpr_JSAny_constexpr_string_0(state_, "value");
    tmp119 = CodeStubAssembler(state_).GetProperty(TNode<Context>{p_context}, TNode<Object>{p_object}, TNode<Object>{tmp118});
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 290);
    tmp120 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp121 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp0, tmp120});
    tmp122 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    tmp123 = ca_.UncheckedCast<Smi>(ca_.BitcastWordToTaggedSigned(CodeStubAssembler(state_).UpdateWord32InWord<base::BitField<bool, 7, 1, uintptr_t>>(ca_.UncheckedCast<WordT>(ca_.BitcastTaggedToWordForTagAndSmiBits(tmp121)), ca_.UncheckedCast<Uint32T>(tmp122))));
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{tmp0, tmp120}, tmp123);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 291);
    tmp124 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp0, tmp124}, tmp119);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 288);
    ca_.Goto(&block13);
  }

  TNode<Object> tmp125;
  TNode<Oddball> tmp126;
  TNode<Oddball> tmp127;
  TNode<BoolT> tmp128;
  if (block13.is_used()) {
    ca_.Bind(&block13);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 294);
    tmp125 = FromConstexpr_JSAny_constexpr_string_0(state_, "writable");
    tmp126 = ca_.CallStub<Oddball>(Builtins::CallableFor(ca_.isolate(), Builtin::kHasProperty), p_context, p_object, tmp125);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 295);
    tmp127 = True_0(state_);
    tmp128 = CodeStubAssembler(state_).TaggedEqual(TNode<HeapObject>{tmp126}, TNode<HeapObject>{tmp127});
    ca_.Branch(tmp128, &block14, std::vector<compiler::Node*>{}, &block15, std::vector<compiler::Node*>{});
  }

  TNode<Object> tmp129;
  TNode<Object> tmp130;
  TNode<BoolT> tmp131;
  TNode<IntPtrT> tmp132;
  TNode<Smi> tmp133;
  TNode<BoolT> tmp134;
  TNode<Smi> tmp135;
  TNode<IntPtrT> tmp136;
  TNode<Smi> tmp137;
  TNode<Smi> tmp138;
  if (block14.is_used()) {
    ca_.Bind(&block14);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 296);
    tmp129 = FromConstexpr_JSAny_constexpr_string_0(state_, "writable");
    tmp130 = CodeStubAssembler(state_).GetProperty(TNode<Context>{p_context}, TNode<Object>{p_object}, TNode<Object>{tmp129});
    tmp131 = ToBoolean_0(state_, TNode<Object>{tmp130});
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 297);
    tmp132 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp133 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp0, tmp132});
    tmp134 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    tmp135 = ca_.UncheckedCast<Smi>(ca_.BitcastWordToTaggedSigned(CodeStubAssembler(state_).UpdateWord32InWord<base::BitField<bool, 6, 1, uintptr_t>>(ca_.UncheckedCast<WordT>(ca_.BitcastTaggedToWordForTagAndSmiBits(tmp133)), ca_.UncheckedCast<Uint32T>(tmp134))));
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{tmp0, tmp132}, tmp135);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 298);
    tmp136 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp137 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp0, tmp136});
    tmp138 = ca_.UncheckedCast<Smi>(ca_.BitcastWordToTaggedSigned(CodeStubAssembler(state_).UpdateWord32InWord<base::BitField<bool, 5, 1, uintptr_t>>(ca_.UncheckedCast<WordT>(ca_.BitcastTaggedToWordForTagAndSmiBits(tmp137)), ca_.UncheckedCast<Uint32T>(tmp131))));
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{tmp0, tmp136}, tmp138);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 295);
    ca_.Goto(&block15);
  }

  TNode<Object> tmp139;
  TNode<Oddball> tmp140;
  TNode<Oddball> tmp141;
  TNode<BoolT> tmp142;
  if (block15.is_used()) {
    ca_.Bind(&block15);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 301);
    tmp139 = FromConstexpr_JSAny_constexpr_string_0(state_, "get");
    tmp140 = ca_.CallStub<Oddball>(Builtins::CallableFor(ca_.isolate(), Builtin::kHasProperty), p_context, p_object, tmp139);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 302);
    tmp141 = True_0(state_);
    tmp142 = CodeStubAssembler(state_).TaggedEqual(TNode<HeapObject>{tmp140}, TNode<HeapObject>{tmp141});
    ca_.Branch(tmp142, &block16, std::vector<compiler::Node*>{}, &block17, std::vector<compiler::Node*>{});
  }

  TNode<Object> tmp143;
  TNode<Object> tmp144;
  TNode<BoolT> tmp145;
  TNode<BoolT> tmp146;
  if (block16.is_used()) {
    ca_.Bind(&block16);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 303);
    tmp143 = FromConstexpr_JSAny_constexpr_string_0(state_, "get");
    tmp144 = CodeStubAssembler(state_).GetProperty(TNode<Context>{p_context}, TNode<Object>{p_object}, TNode<Object>{tmp143});
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 304);
    tmp145 = Is_Undefined_JSAny_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp144});
    tmp146 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp145});
    ca_.Branch(tmp146, &block20, std::vector<compiler::Node*>{}, &block21, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp147;
  TNode<BoolT> tmp148;
  if (block20.is_used()) {
    ca_.Bind(&block20);
    tmp147 = Is_FunctionTemplateInfo_JSAny_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp144});
    tmp148 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp147});
    ca_.Goto(&block22, tmp148);
  }

  TNode<BoolT> tmp149;
  if (block21.is_used()) {
    ca_.Bind(&block21);
    tmp149 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block22, tmp149);
  }

  TNode<BoolT> phi_bb22_10;
  if (block22.is_used()) {
    ca_.Bind(&block22, &phi_bb22_10);
    ca_.Branch(phi_bb22_10, &block18, std::vector<compiler::Node*>{}, &block19, std::vector<compiler::Node*>{tmp144});
  }

  TNode<JSReceiver> tmp150;
  if (block18.is_used()) {
    ca_.Bind(&block18);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 305);
    compiler::CodeAssemblerLabel label151(&ca_);
    tmp150 = Cast_Callable_1(state_, TNode<Context>{p_context}, TNode<Object>{tmp144}, &label151);
    ca_.Goto(&block25);
    if (label151.is_used()) {
      ca_.Bind(&label151);
      ca_.Goto(&block26);
    }
  }

  if (block26.is_used()) {
    ca_.Bind(&block26);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{p_context}, MessageTemplate::kObjectGetterCallable, TNode<Object>{tmp144});
  }

  if (block25.is_used()) {
    ca_.Bind(&block25);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 304);
    ca_.Goto(&block19, tmp150);
  }

  TNode<Object> phi_bb19_8;
  TNode<IntPtrT> tmp152;
  TNode<Smi> tmp153;
  TNode<BoolT> tmp154;
  TNode<Smi> tmp155;
  TNode<IntPtrT> tmp156;
  if (block19.is_used()) {
    ca_.Bind(&block19, &phi_bb19_8);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 308);
    tmp152 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp153 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp0, tmp152});
    tmp154 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    tmp155 = ca_.UncheckedCast<Smi>(ca_.BitcastWordToTaggedSigned(CodeStubAssembler(state_).UpdateWord32InWord<base::BitField<bool, 8, 1, uintptr_t>>(ca_.UncheckedCast<WordT>(ca_.BitcastTaggedToWordForTagAndSmiBits(tmp153)), ca_.UncheckedCast<Uint32T>(tmp154))));
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{tmp0, tmp152}, tmp155);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 309);
    tmp156 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp0, tmp156}, phi_bb19_8);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 302);
    ca_.Goto(&block17);
  }

  TNode<Object> tmp157;
  TNode<Oddball> tmp158;
  TNode<Oddball> tmp159;
  TNode<BoolT> tmp160;
  if (block17.is_used()) {
    ca_.Bind(&block17);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 312);
    tmp157 = FromConstexpr_JSAny_constexpr_string_0(state_, "set");
    tmp158 = ca_.CallStub<Oddball>(Builtins::CallableFor(ca_.isolate(), Builtin::kHasProperty), p_context, p_object, tmp157);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 313);
    tmp159 = True_0(state_);
    tmp160 = CodeStubAssembler(state_).TaggedEqual(TNode<HeapObject>{tmp158}, TNode<HeapObject>{tmp159});
    ca_.Branch(tmp160, &block27, std::vector<compiler::Node*>{}, &block28, std::vector<compiler::Node*>{});
  }

  TNode<Object> tmp161;
  TNode<Object> tmp162;
  TNode<BoolT> tmp163;
  TNode<BoolT> tmp164;
  if (block27.is_used()) {
    ca_.Bind(&block27);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 314);
    tmp161 = FromConstexpr_JSAny_constexpr_string_0(state_, "set");
    tmp162 = CodeStubAssembler(state_).GetProperty(TNode<Context>{p_context}, TNode<Object>{p_object}, TNode<Object>{tmp161});
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 315);
    tmp163 = Is_Undefined_JSAny_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp162});
    tmp164 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp163});
    ca_.Branch(tmp164, &block31, std::vector<compiler::Node*>{}, &block32, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp165;
  TNode<BoolT> tmp166;
  if (block31.is_used()) {
    ca_.Bind(&block31);
    tmp165 = Is_FunctionTemplateInfo_JSAny_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp162});
    tmp166 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp165});
    ca_.Goto(&block33, tmp166);
  }

  TNode<BoolT> tmp167;
  if (block32.is_used()) {
    ca_.Bind(&block32);
    tmp167 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block33, tmp167);
  }

  TNode<BoolT> phi_bb33_11;
  if (block33.is_used()) {
    ca_.Bind(&block33, &phi_bb33_11);
    ca_.Branch(phi_bb33_11, &block29, std::vector<compiler::Node*>{}, &block30, std::vector<compiler::Node*>{tmp162});
  }

  TNode<JSReceiver> tmp168;
  if (block29.is_used()) {
    ca_.Bind(&block29);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 316);
    compiler::CodeAssemblerLabel label169(&ca_);
    tmp168 = Cast_Callable_1(state_, TNode<Context>{p_context}, TNode<Object>{tmp162}, &label169);
    ca_.Goto(&block36);
    if (label169.is_used()) {
      ca_.Bind(&label169);
      ca_.Goto(&block37);
    }
  }

  if (block37.is_used()) {
    ca_.Bind(&block37);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{p_context}, MessageTemplate::kObjectSetterCallable, TNode<Object>{tmp162});
  }

  if (block36.is_used()) {
    ca_.Bind(&block36);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 315);
    ca_.Goto(&block30, tmp168);
  }

  TNode<Object> phi_bb30_9;
  TNode<IntPtrT> tmp170;
  TNode<Smi> tmp171;
  TNode<BoolT> tmp172;
  TNode<Smi> tmp173;
  TNode<IntPtrT> tmp174;
  if (block30.is_used()) {
    ca_.Bind(&block30, &phi_bb30_9);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 319);
    tmp170 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp171 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp0, tmp170});
    tmp172 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    tmp173 = ca_.UncheckedCast<Smi>(ca_.BitcastWordToTaggedSigned(CodeStubAssembler(state_).UpdateWord32InWord<base::BitField<bool, 9, 1, uintptr_t>>(ca_.UncheckedCast<WordT>(ca_.BitcastTaggedToWordForTagAndSmiBits(tmp171)), ca_.UncheckedCast<Uint32T>(tmp172))));
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{tmp0, tmp170}, tmp173);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 320);
    tmp174 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp0, tmp174}, phi_bb30_9);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 313);
    ca_.Goto(&block28);
  }

  if (block28.is_used()) {
    ca_.Bind(&block28);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 252);
    ca_.Goto(&block7);
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 232);
    ca_.Goto(&block4);
  }

  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 228);
    ca_.Goto(&block38);
  }

    ca_.Bind(&block38);
  return TNode<PropertyDescriptorObject>{tmp0};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/object.tq?l=326&c=1
TNode<HeapObject> ToPropertyDescriptor_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_object) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Oddball> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 330);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = Cast_Undefined_1(state_, TNode<Object>{p_object}, &label1);
    ca_.Goto(&block4);
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block5);
    }
  }

  TNode<JSReceiver> tmp2;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 333);
    compiler::CodeAssemblerLabel label3(&ca_);
    tmp2 = Cast_JSReceiver_1(state_, TNode<Context>{p_context}, TNode<Object>{ca_.UncheckedCast<Object>(p_object)}, &label3);
    ca_.Goto(&block8);
    if (label3.is_used()) {
      ca_.Bind(&label3);
      ca_.Goto(&block9);
    }
  }

  TNode<Oddball> tmp4;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 331);
    tmp4 = Undefined_0(state_);
    ca_.Goto(&block1, tmp4);
  }

  if (block9.is_used()) {
    ca_.Bind(&block9);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 337);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{p_context}, MessageTemplate::kPropertyDescObject, TNode<Object>{p_object});
  }

  TNode<PropertyDescriptorObject> tmp5;
  if (block8.is_used()) {
    ca_.Bind(&block8);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 334);
    tmp5 = ToPropertyDescriptor_0(state_, TNode<Context>{p_context}, TNode<JSReceiver>{tmp2});
    ca_.Goto(&block1, tmp5);
  }

  TNode<HeapObject> phi_bb1_2;
  if (block1.is_used()) {
    ca_.Bind(&block1, &phi_bb1_2);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 326);
    ca_.Goto(&block10);
  }

    ca_.Bind(&block10);
  return TNode<HeapObject>{phi_bb1_2};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/object.tq?l=345&c=1
TNode<Object> FromPropertyDescriptor_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_object) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Object> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 348);
    tmp0 = ObjectBuiltinsAssembler(state_).FromPropertyDescriptor(TNode<Context>{p_context}, TNode<Object>{p_object});
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 345);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Object>{tmp0};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/object.tq?l=101&c=7
TNode<Oddball> Cast_Null_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError) {
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

  TNode<Oddball> tmp2;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    compiler::CodeAssemblerLabel label3(&ca_);
    tmp2 = Cast_Null_0(state_, TNode<HeapObject>{tmp0}, &label3);
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
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 101);
    ca_.Goto(&block7);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_CastError);
  }

    ca_.Bind(&block7);
  return TNode<Oddball>{tmp2};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/object.tq?l=124&c=21
TNode<Map> WeakToStrong_Map_0(compiler::CodeAssemblerState* state_, TNode<MaybeObject> p_x, compiler::CodeAssemblerLabel* label_ClearedWeakPointer) {
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
    ca_.SetSourcePosition("../../../src/builtins/base.tq", 71);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = CodeStubAssembler(state_).GetHeapObjectAssumeWeak(TNode<MaybeObject>{p_x}, &label1);
    ca_.Goto(&block3);
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block4);
    }
  }

  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 124);
    ca_.Goto(label_ClearedWeakPointer);
  }

  TNode<Map> tmp2;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    ca_.SetSourcePosition("../../../src/builtins/base.tq", 72);
    tmp2 = TORQUE_CAST(TNode<HeapObject>{tmp0});
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 124);
    ca_.Goto(&block5);
  }

    ca_.Bind(&block5);
  return TNode<Map>{tmp2};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/object.tq?l=171&c=5
TNode<HeapObject> Cast_JSReceiver_OR_Null_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError) {
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

  TNode<HeapObject> tmp2;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    compiler::CodeAssemblerLabel label3(&ca_);
    tmp2 = Cast_JSReceiver_OR_Null_0(state_, TNode<HeapObject>{tmp0}, &label3);
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
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 171);
    ca_.Goto(&block7);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_CastError);
  }

    ca_.Bind(&block7);
  return TNode<HeapObject>{tmp2};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/object.tq?l=232&c=22
TorqueStructReference_Map_0 NativeContextSlot_Map_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<IntPtrT> p_index) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<NativeContext> tmp0;
  TNode<Object> tmp1;
  TNode<IntPtrT> tmp2;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/objects/contexts.tq", 83);
    tmp0 = CodeStubAssembler(state_).LoadNativeContext(TNode<Context>{p_context});
    std::tie(tmp1, tmp2) = ContextSlot_NativeContext_NativeContext_Map_0(state_, TNode<NativeContext>{tmp0}, TNode<IntPtrT>{p_index}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 232);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TorqueStructReference_Map_0{TNode<Object>{tmp1}, TNode<IntPtrT>{tmp2}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/object.tq?l=304&c=12
TNode<BoolT> Is_Undefined_JSAny_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Oddball> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 808);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = Cast_Undefined_1(state_, TNode<Object>{p_o}, &label1);
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
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 304);
    ca_.Goto(&block6);
  }

    ca_.Bind(&block6);
  return TNode<BoolT>{phi_bb1_2};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/object.tq?l=304&c=38
TNode<BoolT> Is_FunctionTemplateInfo_JSAny_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<FunctionTemplateInfo> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 808);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = Cast_FunctionTemplateInfo_1(state_, TNode<Context>{p_context}, TNode<Object>{p_o}, &label1);
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
    ca_.SetSourcePosition("../../../src/builtins/object.tq", 304);
    ca_.Goto(&block6);
  }

    ca_.Bind(&block6);
  return TNode<BoolT>{phi_bb1_2};
}

} // namespace internal
} // namespace v8
