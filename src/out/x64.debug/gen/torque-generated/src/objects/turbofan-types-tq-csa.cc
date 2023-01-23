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
#include "torque-generated/src/objects/turbofan-types-tq-csa.h"
#include "torque-generated/src/builtins/base-tq-csa.h"
#include "torque-generated/src/builtins/builtins-bigint-tq-csa.h"
#include "torque-generated/src/builtins/cast-tq-csa.h"
#include "torque-generated/src/builtins/convert-tq-csa.h"
#include "torque-generated/src/builtins/torque-internal-tq-csa.h"
#include "torque-generated/src/objects/js-array-tq-csa.h"
#include "torque-generated/src/objects/js-function-tq-csa.h"
#include "torque-generated/src/objects/js-objects-tq-csa.h"
#include "torque-generated/src/objects/js-proxy-tq-csa.h"
#include "torque-generated/src/objects/map-tq-csa.h"
#include "torque-generated/src/objects/name-tq-csa.h"
#include "torque-generated/src/objects/string-tq-csa.h"
#include "torque-generated/src/objects/turbofan-types-tq-csa.h"
#include "torque-generated/src/wasm/wasm-objects-tq-csa.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turbofan-types.tq?l=12&c=1
TNode<TurbofanType> Cast_TurbofanType_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<TurbofanType> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 12);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = DownCastForTorqueClass_TurbofanType_0(state_, TNode<HeapObject>{p_obj}, &label1);
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
  return TNode<TurbofanType>{tmp0};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turbofan-types.tq?l=60&c=1
TNode<TurbofanBitsetType> Cast_TurbofanBitsetType_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<TurbofanBitsetType> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 60);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = DownCastForTorqueClass_TurbofanBitsetType_0(state_, TNode<HeapObject>{p_obj}, &label1);
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
  return TNode<TurbofanBitsetType>{tmp0};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turbofan-types.tq?l=66&c=1
TNode<TurbofanUnionType> Cast_TurbofanUnionType_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<TurbofanUnionType> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 66);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = DownCastForTorqueClass_TurbofanUnionType_0(state_, TNode<HeapObject>{p_obj}, &label1);
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
  return TNode<TurbofanUnionType>{tmp0};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turbofan-types.tq?l=72&c=1
TNode<TurbofanRangeType> Cast_TurbofanRangeType_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<TurbofanRangeType> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 72);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = DownCastForTorqueClass_TurbofanRangeType_0(state_, TNode<HeapObject>{p_obj}, &label1);
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
  return TNode<TurbofanRangeType>{tmp0};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turbofan-types.tq?l=78&c=1
TNode<TurbofanHeapConstantType> Cast_TurbofanHeapConstantType_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<TurbofanHeapConstantType> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 78);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = DownCastForTorqueClass_TurbofanHeapConstantType_0(state_, TNode<HeapObject>{p_obj}, &label1);
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
  return TNode<TurbofanHeapConstantType>{tmp0};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turbofan-types.tq?l=83&c=1
TNode<TurbofanOtherNumberConstantType> Cast_TurbofanOtherNumberConstantType_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<TurbofanOtherNumberConstantType> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 83);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = DownCastForTorqueClass_TurbofanOtherNumberConstantType_0(state_, TNode<HeapObject>{p_obj}, &label1);
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
  return TNode<TurbofanOtherNumberConstantType>{tmp0};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turbofan-types.tq?l=88&c=1
TNode<BoolT> IsMinusZero_0(compiler::CodeAssemblerState* state_, TNode<Float64T> p_x) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Float64T> tmp0;
  TNode<BoolT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 89);
    tmp0 = FromConstexpr_float64_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp1 = CodeStubAssembler(state_).Float64Equal(TNode<Float64T>{p_x}, TNode<Float64T>{tmp0});
    ca_.Branch(tmp1, &block2, std::vector<compiler::Node*>{}, &block3, std::vector<compiler::Node*>{});
  }

  TNode<Float64T> tmp2;
  TNode<Float64T> tmp3;
  TNode<Float64T> tmp4;
  TNode<BoolT> tmp5;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    tmp2 = FromConstexpr_float64_constexpr_float64_0(state_, 1);
    tmp3 = CodeStubAssembler(state_).Float64Div(TNode<Float64T>{tmp2}, TNode<Float64T>{p_x});
    tmp4 = FromConstexpr_float64_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp5 = CodeStubAssembler(state_).Float64LessThan(TNode<Float64T>{tmp3}, TNode<Float64T>{tmp4});
    ca_.Goto(&block4, tmp5);
  }

  TNode<BoolT> tmp6;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    tmp6 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block4, tmp6);
  }

  TNode<BoolT> phi_bb4_2;
  if (block4.is_used()) {
    ca_.Bind(&block4, &phi_bb4_2);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 88);
    ca_.Goto(&block5);
  }

    ca_.Bind(&block5);
  return TNode<BoolT>{phi_bb4_2};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turbofan-types.tq?l=92&c=1
TNode<BoolT> TestTurbofanBitsetType_0(compiler::CodeAssemblerState* state_, TNode<Object> p_value, TNode<Uint32T> p_bitsetLow, TNode<Uint32T> p_bitsetHigh) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block25(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block27(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block28(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block30(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block31(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block36(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block35(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block40(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block39(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block44(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block43(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block48(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block47(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block52(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block51(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block53(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block54(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block59(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block58(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block68(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block67(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block64(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block60(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block61(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block62(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block72(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block71(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block73(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block74(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block79(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block78(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block83(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block82(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block87(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block86(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block91(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block90(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block94(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block95(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block96(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block93(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block92(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block99(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block100(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block101(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block98(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block97(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block104(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block105(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block106(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block103(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block102(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block109(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block110(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block111(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block108(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block107(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block112(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block113(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block114(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block115(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block117(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block118(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block120(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block119(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block121(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block124(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block125(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block127(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block128(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block129(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block126(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block122(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block130(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block131(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block133(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block134(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block135(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block132(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block139(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block138(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block140(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block141(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block149(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block148(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block145(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block143(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block144(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block154(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block153(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block155(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Number> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 98);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = Cast_Number_0(state_, TNode<Object>{p_value}, &label1);
    ca_.Goto(&block4);
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block5);
    }
  }

  TNode<Oddball> tmp2;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 124);
    compiler::CodeAssemblerLabel label3(&ca_);
    tmp2 = Cast_Null_0(state_, TNode<HeapObject>{ca_.UncheckedCast<HeapObject>(p_value)}, &label3);
    ca_.Goto(&block35);
    if (label3.is_used()) {
      ca_.Bind(&label3);
      ca_.Goto(&block36);
    }
  }

  TNode<Float64T> tmp4;
  TNode<BoolT> tmp5;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 99);
    tmp4 = Convert_float64_Number_0(state_, TNode<Number>{tmp0});
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 100);
    tmp5 = CodeStubAssembler(state_).IsInteger(TNode<Object>{tmp0});
    ca_.Branch(tmp5, &block6, std::vector<compiler::Node*>{}, &block7, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp6;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 101);
    tmp6 = IsMinusZero_0(state_, TNode<Float64T>{tmp4});
    ca_.Branch(tmp6, &block9, std::vector<compiler::Node*>{}, &block10, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp7;
  if (block9.is_used()) {
    ca_.Bind(&block9);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 102);
    tmp7 = ca_.UncheckedCast<BoolT>(CodeStubAssembler(state_).DecodeWord32<base::BitField<bool, 11, 1, uint32_t>>(ca_.UncheckedCast<Word32T>(p_bitsetLow)));
    ca_.Goto(&block1, tmp7);
  }

  TNode<Float64T> tmp8;
  TNode<BoolT> tmp9;
  if (block10.is_used()) {
    ca_.Bind(&block10);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 103);
    tmp8 = FromConstexpr_float64_constexpr_IntegerLiteral_0(state_, IntegerLiteral(true, 0x80000000ull));
    tmp9 = CodeStubAssembler(state_).Float64LessThan(TNode<Float64T>{tmp4}, TNode<Float64T>{tmp8});
    ca_.Branch(tmp9, &block12, std::vector<compiler::Node*>{}, &block13, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp10;
  if (block12.is_used()) {
    ca_.Bind(&block12);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 104);
    tmp10 = ca_.UncheckedCast<BoolT>(CodeStubAssembler(state_).DecodeWord32<base::BitField<bool, 4, 1, uint32_t>>(ca_.UncheckedCast<Word32T>(p_bitsetLow)));
    ca_.Goto(&block1, tmp10);
  }

  TNode<Float64T> tmp11;
  TNode<BoolT> tmp12;
  if (block13.is_used()) {
    ca_.Bind(&block13);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 105);
    tmp11 = FromConstexpr_float64_constexpr_IntegerLiteral_0(state_, IntegerLiteral(true, 0x40000000ull));
    tmp12 = CodeStubAssembler(state_).Float64LessThan(TNode<Float64T>{tmp4}, TNode<Float64T>{tmp11});
    ca_.Branch(tmp12, &block15, std::vector<compiler::Node*>{}, &block16, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp13;
  if (block15.is_used()) {
    ca_.Bind(&block15);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 106);
    tmp13 = ca_.UncheckedCast<BoolT>(CodeStubAssembler(state_).DecodeWord32<base::BitField<bool, 3, 1, uint32_t>>(ca_.UncheckedCast<Word32T>(p_bitsetLow)));
    ca_.Goto(&block1, tmp13);
  }

  TNode<Float64T> tmp14;
  TNode<BoolT> tmp15;
  if (block16.is_used()) {
    ca_.Bind(&block16);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 107);
    tmp14 = FromConstexpr_float64_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp15 = CodeStubAssembler(state_).Float64LessThan(TNode<Float64T>{tmp4}, TNode<Float64T>{tmp14});
    ca_.Branch(tmp15, &block18, std::vector<compiler::Node*>{}, &block19, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp16;
  if (block18.is_used()) {
    ca_.Bind(&block18);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 108);
    tmp16 = ca_.UncheckedCast<BoolT>(CodeStubAssembler(state_).DecodeWord32<base::BitField<bool, 6, 1, uint32_t>>(ca_.UncheckedCast<Word32T>(p_bitsetLow)));
    ca_.Goto(&block1, tmp16);
  }

  TNode<Float64T> tmp17;
  TNode<BoolT> tmp18;
  if (block19.is_used()) {
    ca_.Bind(&block19);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 109);
    tmp17 = FromConstexpr_float64_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x40000000ull));
    tmp18 = CodeStubAssembler(state_).Float64LessThan(TNode<Float64T>{tmp4}, TNode<Float64T>{tmp17});
    ca_.Branch(tmp18, &block21, std::vector<compiler::Node*>{}, &block22, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp19;
  if (block21.is_used()) {
    ca_.Bind(&block21);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 110);
    tmp19 = ca_.UncheckedCast<BoolT>(CodeStubAssembler(state_).DecodeWord32<base::BitField<bool, 10, 1, uint32_t>>(ca_.UncheckedCast<Word32T>(p_bitsetLow)));
    ca_.Goto(&block1, tmp19);
  }

  TNode<Float64T> tmp20;
  TNode<BoolT> tmp21;
  if (block22.is_used()) {
    ca_.Bind(&block22);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 111);
    tmp20 = FromConstexpr_float64_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x80000000ull));
    tmp21 = CodeStubAssembler(state_).Float64LessThan(TNode<Float64T>{tmp4}, TNode<Float64T>{tmp20});
    ca_.Branch(tmp21, &block24, std::vector<compiler::Node*>{}, &block25, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp22;
  if (block24.is_used()) {
    ca_.Bind(&block24);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 112);
    tmp22 = ca_.UncheckedCast<BoolT>(CodeStubAssembler(state_).DecodeWord32<base::BitField<bool, 1, 1, uint32_t>>(ca_.UncheckedCast<Word32T>(p_bitsetLow)));
    ca_.Goto(&block1, tmp22);
  }

  TNode<Float64T> tmp23;
  TNode<BoolT> tmp24;
  if (block25.is_used()) {
    ca_.Bind(&block25);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 113);
    tmp23 = FromConstexpr_float64_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0xffffffffull));
    tmp24 = CodeStubAssembler(state_).Float64LessThanOrEqual(TNode<Float64T>{tmp4}, TNode<Float64T>{tmp23});
    ca_.Branch(tmp24, &block27, std::vector<compiler::Node*>{}, &block28, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp25;
  if (block27.is_used()) {
    ca_.Bind(&block27);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 114);
    tmp25 = ca_.UncheckedCast<BoolT>(CodeStubAssembler(state_).DecodeWord32<base::BitField<bool, 2, 1, uint32_t>>(ca_.UncheckedCast<Word32T>(p_bitsetLow)));
    ca_.Goto(&block1, tmp25);
  }

  TNode<BoolT> tmp26;
  if (block28.is_used()) {
    ca_.Bind(&block28);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 116);
    tmp26 = ca_.UncheckedCast<BoolT>(CodeStubAssembler(state_).DecodeWord32<base::BitField<bool, 4, 1, uint32_t>>(ca_.UncheckedCast<Word32T>(p_bitsetLow)));
    ca_.Goto(&block1, tmp26);
  }

  TNode<BoolT> tmp27;
  if (block7.is_used()) {
    ca_.Bind(&block7);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 118);
    tmp27 = Float64IsNaN_0(state_, TNode<Float64T>{tmp4});
    ca_.Branch(tmp27, &block30, std::vector<compiler::Node*>{}, &block31, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp28;
  if (block30.is_used()) {
    ca_.Bind(&block30);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 119);
    tmp28 = ca_.UncheckedCast<BoolT>(CodeStubAssembler(state_).DecodeWord32<base::BitField<bool, 12, 1, uint32_t>>(ca_.UncheckedCast<Word32T>(p_bitsetLow)));
    ca_.Goto(&block1, tmp28);
  }

  TNode<BoolT> tmp29;
  if (block31.is_used()) {
    ca_.Bind(&block31);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 121);
    tmp29 = ca_.UncheckedCast<BoolT>(CodeStubAssembler(state_).DecodeWord32<base::BitField<bool, 4, 1, uint32_t>>(ca_.UncheckedCast<Word32T>(p_bitsetLow)));
    ca_.Goto(&block1, tmp29);
  }

  TNode<Oddball> tmp30;
  if (block36.is_used()) {
    ca_.Bind(&block36);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 127);
    compiler::CodeAssemblerLabel label31(&ca_);
    tmp30 = Cast_Undefined_2(state_, TNode<HeapObject>{ca_.UncheckedCast<HeapObject>(p_value)}, &label31);
    ca_.Goto(&block39);
    if (label31.is_used()) {
      ca_.Bind(&label31);
      ca_.Goto(&block40);
    }
  }

  TNode<BoolT> tmp32;
  if (block35.is_used()) {
    ca_.Bind(&block35);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 125);
    tmp32 = ca_.UncheckedCast<BoolT>(CodeStubAssembler(state_).DecodeWord32<base::BitField<bool, 7, 1, uint32_t>>(ca_.UncheckedCast<Word32T>(p_bitsetLow)));
    ca_.Goto(&block1, tmp32);
  }

  TNode<Oddball> tmp33;
  if (block40.is_used()) {
    ca_.Bind(&block40);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 130);
    compiler::CodeAssemblerLabel label34(&ca_);
    tmp33 = Cast_Boolean_1(state_, TNode<HeapObject>{ca_.UncheckedCast<HeapObject>(p_value)}, &label34);
    ca_.Goto(&block43);
    if (label34.is_used()) {
      ca_.Bind(&label34);
      ca_.Goto(&block44);
    }
  }

  TNode<BoolT> tmp35;
  if (block39.is_used()) {
    ca_.Bind(&block39);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 128);
    tmp35 = ca_.UncheckedCast<BoolT>(CodeStubAssembler(state_).DecodeWord32<base::BitField<bool, 8, 1, uint32_t>>(ca_.UncheckedCast<Word32T>(p_bitsetLow)));
    ca_.Goto(&block1, tmp35);
  }

  TNode<Symbol> tmp36;
  if (block44.is_used()) {
    ca_.Bind(&block44);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 133);
    compiler::CodeAssemblerLabel label37(&ca_);
    tmp36 = Cast_Symbol_0(state_, TNode<HeapObject>{ca_.UncheckedCast<HeapObject>(p_value)}, &label37);
    ca_.Goto(&block47);
    if (label37.is_used()) {
      ca_.Bind(&label37);
      ca_.Goto(&block48);
    }
  }

  TNode<BoolT> tmp38;
  if (block43.is_used()) {
    ca_.Bind(&block43);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 131);
    tmp38 = ca_.UncheckedCast<BoolT>(CodeStubAssembler(state_).DecodeWord32<base::BitField<bool, 9, 1, uint32_t>>(ca_.UncheckedCast<Word32T>(p_bitsetLow)));
    ca_.Goto(&block1, tmp38);
  }

  TNode<String> tmp39;
  if (block48.is_used()) {
    ca_.Bind(&block48);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 136);
    compiler::CodeAssemblerLabel label40(&ca_);
    tmp39 = Cast_String_0(state_, TNode<HeapObject>{ca_.UncheckedCast<HeapObject>(p_value)}, &label40);
    ca_.Goto(&block51);
    if (label40.is_used()) {
      ca_.Bind(&label40);
      ca_.Goto(&block52);
    }
  }

  TNode<BoolT> tmp41;
  if (block47.is_used()) {
    ca_.Bind(&block47);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 134);
    tmp41 = ca_.UncheckedCast<BoolT>(CodeStubAssembler(state_).DecodeWord32<base::BitField<bool, 13, 1, uint32_t>>(ca_.UncheckedCast<Word32T>(p_bitsetLow)));
    ca_.Goto(&block1, tmp41);
  }

  TNode<JSProxy> tmp42;
  if (block52.is_used()) {
    ca_.Bind(&block52);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 143);
    compiler::CodeAssemblerLabel label43(&ca_);
    tmp42 = Cast_JSProxy_0(state_, TNode<HeapObject>{ca_.UncheckedCast<HeapObject>(p_value)}, &label43);
    ca_.Goto(&block58);
    if (label43.is_used()) {
      ca_.Bind(&label43);
      ca_.Goto(&block59);
    }
  }

  TNode<BoolT> tmp44;
  if (block51.is_used()) {
    ca_.Bind(&block51);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 137);
    tmp44 = Method_String_IsNotInternalized_0(state_, TNode<String>{tmp39});
    ca_.Branch(tmp44, &block53, std::vector<compiler::Node*>{}, &block54, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp45;
  if (block53.is_used()) {
    ca_.Bind(&block53);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 138);
    tmp45 = ca_.UncheckedCast<BoolT>(CodeStubAssembler(state_).DecodeWord32<base::BitField<bool, 5, 1, uint32_t>>(ca_.UncheckedCast<Word32T>(p_bitsetLow)));
    ca_.Goto(&block1, tmp45);
  }

  TNode<BoolT> tmp46;
  if (block54.is_used()) {
    ca_.Bind(&block54);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 140);
    tmp46 = ca_.UncheckedCast<BoolT>(CodeStubAssembler(state_).DecodeWord32<base::BitField<bool, 14, 1, uint32_t>>(ca_.UncheckedCast<Word32T>(p_bitsetLow)));
    ca_.Goto(&block1, tmp46);
  }

  TNode<JSFunction> tmp47;
  if (block59.is_used()) {
    ca_.Bind(&block59);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 147);
    compiler::CodeAssemblerLabel label48(&ca_);
    tmp47 = Cast_JSFunction_0(state_, TNode<HeapObject>{ca_.UncheckedCast<HeapObject>(p_value)}, &label48);
    ca_.Goto(&block71);
    if (label48.is_used()) {
      ca_.Bind(&label48);
      ca_.Goto(&block72);
    }
  }

  TNode<JSReceiver> tmp49;
  if (block58.is_used()) {
    ca_.Bind(&block58);
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 808);
    compiler::CodeAssemblerLabel label50(&ca_);
    tmp49 = Cast_Callable_0(state_, TNode<HeapObject>{tmp42}, &label50);
    ca_.Goto(&block67);
    if (label50.is_used()) {
      ca_.Bind(&label50);
      ca_.Goto(&block68);
    }
  }

  TNode<BoolT> tmp51;
  if (block68.is_used()) {
    ca_.Bind(&block68);
    tmp51 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block64, tmp51);
  }

  TNode<BoolT> tmp52;
  if (block67.is_used()) {
    ca_.Bind(&block67);
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 809);
    tmp52 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block64, tmp52);
  }

  TNode<BoolT> phi_bb64_8;
  if (block64.is_used()) {
    ca_.Bind(&block64, &phi_bb64_8);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 144);
    ca_.Branch(phi_bb64_8, &block60, std::vector<compiler::Node*>{}, &block61, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp53;
  if (block60.is_used()) {
    ca_.Bind(&block60);
    tmp53 = ca_.UncheckedCast<BoolT>(CodeStubAssembler(state_).DecodeWord32<base::BitField<bool, 18, 1, uint32_t>>(ca_.UncheckedCast<Word32T>(p_bitsetLow)));
    ca_.Goto(&block62, tmp53);
  }

  TNode<BoolT> tmp54;
  if (block61.is_used()) {
    ca_.Bind(&block61);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 145);
    tmp54 = ca_.UncheckedCast<BoolT>(CodeStubAssembler(state_).DecodeWord32<base::BitField<bool, 19, 1, uint32_t>>(ca_.UncheckedCast<Word32T>(p_bitsetLow)));
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 144);
    ca_.Goto(&block62, tmp54);
  }

  TNode<BoolT> phi_bb62_6;
  if (block62.is_used()) {
    ca_.Bind(&block62, &phi_bb62_6);
    ca_.Goto(&block1, phi_bb62_6);
  }

  TNode<JSBoundFunction> tmp55;
  if (block72.is_used()) {
    ca_.Bind(&block72);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 154);
    compiler::CodeAssemblerLabel label56(&ca_);
    tmp55 = Cast_JSBoundFunction_0(state_, TNode<HeapObject>{ca_.UncheckedCast<HeapObject>(p_value)}, &label56);
    ca_.Goto(&block78);
    if (label56.is_used()) {
      ca_.Bind(&label56);
      ca_.Goto(&block79);
    }
  }

  TNode<IntPtrT> tmp57;
  TNode<SharedFunctionInfo> tmp58;
  TNode<IntPtrT> tmp59;
  TNode<Uint32T> tmp60;
  TNode<BoolT> tmp61;
  if (block71.is_used()) {
    ca_.Bind(&block71);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 148);
    tmp57 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp58 = CodeStubAssembler(state_).LoadReference<SharedFunctionInfo>(CodeStubAssembler::Reference{tmp47, tmp57});
    tmp59 = FromConstexpr_intptr_constexpr_int31_0(state_, 28);
    tmp60 = CodeStubAssembler(state_).LoadReference<Uint32T>(CodeStubAssembler::Reference{tmp58, tmp59});
    tmp61 = ca_.UncheckedCast<BoolT>(CodeStubAssembler(state_).DecodeWord32<base::BitField<bool, 10, 1, uint32_t>>(ca_.UncheckedCast<Word32T>(tmp60)));
    ca_.Branch(tmp61, &block73, std::vector<compiler::Node*>{}, &block74, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp62;
  if (block73.is_used()) {
    ca_.Bind(&block73);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 149);
    tmp62 = ca_.UncheckedCast<BoolT>(CodeStubAssembler(state_).DecodeWord32<base::BitField<bool, 21, 1, uint32_t>>(ca_.UncheckedCast<Word32T>(p_bitsetLow)));
    ca_.Goto(&block1, tmp62);
  }

  TNode<BoolT> tmp63;
  if (block74.is_used()) {
    ca_.Bind(&block74);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 151);
    tmp63 = ca_.UncheckedCast<BoolT>(CodeStubAssembler(state_).DecodeWord32<base::BitField<bool, 20, 1, uint32_t>>(ca_.UncheckedCast<Word32T>(p_bitsetLow)));
    ca_.Goto(&block1, tmp63);
  }

  TNode<Oddball> tmp64;
  if (block79.is_used()) {
    ca_.Bind(&block79);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 157);
    compiler::CodeAssemblerLabel label65(&ca_);
    tmp64 = Cast_TheHole_1(state_, TNode<HeapObject>{ca_.UncheckedCast<HeapObject>(p_value)}, &label65);
    ca_.Goto(&block82);
    if (label65.is_used()) {
      ca_.Bind(&label65);
      ca_.Goto(&block83);
    }
  }

  TNode<BoolT> tmp66;
  if (block78.is_used()) {
    ca_.Bind(&block78);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 155);
    tmp66 = ca_.UncheckedCast<BoolT>(CodeStubAssembler(state_).DecodeWord32<base::BitField<bool, 22, 1, uint32_t>>(ca_.UncheckedCast<Word32T>(p_bitsetLow)));
    ca_.Goto(&block1, tmp66);
  }

  TNode<JSArray> tmp67;
  if (block83.is_used()) {
    ca_.Bind(&block83);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 160);
    compiler::CodeAssemblerLabel label68(&ca_);
    tmp67 = Cast_JSArray_0(state_, TNode<HeapObject>{ca_.UncheckedCast<HeapObject>(p_value)}, &label68);
    ca_.Goto(&block86);
    if (label68.is_used()) {
      ca_.Bind(&label68);
      ca_.Goto(&block87);
    }
  }

  TNode<BoolT> tmp69;
  if (block82.is_used()) {
    ca_.Bind(&block82);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 158);
    tmp69 = ca_.UncheckedCast<BoolT>(CodeStubAssembler(state_).DecodeWord32<base::BitField<bool, 23, 1, uint32_t>>(ca_.UncheckedCast<Word32T>(p_bitsetLow)));
    ca_.Goto(&block1, tmp69);
  }

  TNode<BigInt> tmp70;
  if (block87.is_used()) {
    ca_.Bind(&block87);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 163);
    compiler::CodeAssemblerLabel label71(&ca_);
    tmp70 = Cast_BigInt_0(state_, TNode<HeapObject>{ca_.UncheckedCast<HeapObject>(p_value)}, &label71);
    ca_.Goto(&block90);
    if (label71.is_used()) {
      ca_.Bind(&label71);
      ca_.Goto(&block91);
    }
  }

  TNode<BoolT> tmp72;
  if (block86.is_used()) {
    ca_.Bind(&block86);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 161);
    tmp72 = ca_.UncheckedCast<BoolT>(CodeStubAssembler(state_).DecodeWord32<base::BitField<bool, 26, 1, uint32_t>>(ca_.UncheckedCast<Word32T>(p_bitsetLow)));
    ca_.Goto(&block1, tmp72);
  }

  TNode<JSObject> tmp73;
  if (block91.is_used()) {
    ca_.Bind(&block91);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 195);
    compiler::CodeAssemblerLabel label74(&ca_);
    tmp73 = Cast_JSObject_0(state_, TNode<HeapObject>{ca_.UncheckedCast<HeapObject>(p_value)}, &label74);
    ca_.Goto(&block138);
    if (label74.is_used()) {
      ca_.Bind(&label74);
      ca_.Goto(&block139);
    }
  }

  TNode<BoolT> tmp75;
  TNode<BoolT> tmp76;
  if (block90.is_used()) {
    ca_.Bind(&block90);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 164);
    tmp75 = ca_.UncheckedCast<BoolT>(CodeStubAssembler(state_).DecodeWord32<base::BitField<bool, 30, 1, uint32_t>>(ca_.UncheckedCast<Word32T>(p_bitsetLow)));
    tmp76 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp75});
    ca_.Branch(tmp76, &block94, std::vector<compiler::Node*>{}, &block95, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp77;
  if (block94.is_used()) {
    ca_.Bind(&block94);
    tmp77 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block96, tmp77);
  }

  TNode<BoolT> tmp78;
  if (block95.is_used()) {
    ca_.Bind(&block95);
    tmp78 = ca_.UncheckedCast<BoolT>(CodeStubAssembler(state_).DecodeWord32<base::BitField<bool, 28, 1, uint32_t>>(ca_.UncheckedCast<Word32T>(p_bitsetLow)));
    ca_.Goto(&block96, tmp78);
  }

  TNode<BoolT> phi_bb96_7;
  if (block96.is_used()) {
    ca_.Bind(&block96, &phi_bb96_7);
    ca_.Branch(phi_bb96_7, &block92, std::vector<compiler::Node*>{}, &block93, std::vector<compiler::Node*>{});
  }

  if (block93.is_used()) {
    ca_.Bind(&block93);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/objects/turbofan-types.tq", 164});
      CodeStubAssembler(state_).FailAssert("Torque assert '!bitsetLow.other_big_int || bitsetLow.other_unsigned_big_int_64' failed", pos_stack);
    }
  }

  TNode<BoolT> tmp79;
  TNode<BoolT> tmp80;
  if (block92.is_used()) {
    ca_.Bind(&block92);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 165);
    tmp79 = ca_.UncheckedCast<BoolT>(CodeStubAssembler(state_).DecodeWord32<base::BitField<bool, 30, 1, uint32_t>>(ca_.UncheckedCast<Word32T>(p_bitsetLow)));
    tmp80 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp79});
    ca_.Branch(tmp80, &block99, std::vector<compiler::Node*>{}, &block100, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp81;
  if (block99.is_used()) {
    ca_.Bind(&block99);
    tmp81 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block101, tmp81);
  }

  TNode<BoolT> tmp82;
  if (block100.is_used()) {
    ca_.Bind(&block100);
    tmp82 = ca_.UncheckedCast<BoolT>(CodeStubAssembler(state_).DecodeWord32<base::BitField<bool, 29, 1, uint32_t>>(ca_.UncheckedCast<Word32T>(p_bitsetLow)));
    ca_.Goto(&block101, tmp82);
  }

  TNode<BoolT> phi_bb101_7;
  if (block101.is_used()) {
    ca_.Bind(&block101, &phi_bb101_7);
    ca_.Branch(phi_bb101_7, &block97, std::vector<compiler::Node*>{}, &block98, std::vector<compiler::Node*>{});
  }

  if (block98.is_used()) {
    ca_.Bind(&block98);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/objects/turbofan-types.tq", 165});
      CodeStubAssembler(state_).FailAssert("Torque assert '!bitsetLow.other_big_int || bitsetLow.negative_big_int_63' failed", pos_stack);
    }
  }

  TNode<BoolT> tmp83;
  TNode<BoolT> tmp84;
  if (block97.is_used()) {
    ca_.Bind(&block97);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 167);
    tmp83 = ca_.UncheckedCast<BoolT>(CodeStubAssembler(state_).DecodeWord32<base::BitField<bool, 28, 1, uint32_t>>(ca_.UncheckedCast<Word32T>(p_bitsetLow)));
    tmp84 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp83});
    ca_.Branch(tmp84, &block104, std::vector<compiler::Node*>{}, &block105, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp85;
  if (block104.is_used()) {
    ca_.Bind(&block104);
    tmp85 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block106, tmp85);
  }

  TNode<BoolT> tmp86;
  if (block105.is_used()) {
    ca_.Bind(&block105);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 168);
    tmp86 = ca_.UncheckedCast<BoolT>(CodeStubAssembler(state_).DecodeWord32<base::BitField<bool, 27, 1, uint32_t>>(ca_.UncheckedCast<Word32T>(p_bitsetLow)));
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 167);
    ca_.Goto(&block106, tmp86);
  }

  TNode<BoolT> phi_bb106_7;
  if (block106.is_used()) {
    ca_.Bind(&block106, &phi_bb106_7);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 166);
    ca_.Branch(phi_bb106_7, &block102, std::vector<compiler::Node*>{}, &block103, std::vector<compiler::Node*>{});
  }

  if (block103.is_used()) {
    ca_.Bind(&block103);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/objects/turbofan-types.tq", 166});
      CodeStubAssembler(state_).FailAssert("Torque assert '!bitsetLow.other_unsigned_big_int_64 || bitsetLow.unsigned_big_int_63' failed", pos_stack);
    }
  }

  TNode<BoolT> tmp87;
  TNode<BoolT> tmp88;
  if (block102.is_used()) {
    ca_.Bind(&block102);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 169);
    tmp87 = ca_.UncheckedCast<BoolT>(CodeStubAssembler(state_).DecodeWord32<base::BitField<bool, 29, 1, uint32_t>>(ca_.UncheckedCast<Word32T>(p_bitsetLow)));
    tmp88 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp87});
    ca_.Branch(tmp88, &block109, std::vector<compiler::Node*>{}, &block110, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp89;
  if (block109.is_used()) {
    ca_.Bind(&block109);
    tmp89 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block111, tmp89);
  }

  TNode<BoolT> tmp90;
  if (block110.is_used()) {
    ca_.Bind(&block110);
    tmp90 = ca_.UncheckedCast<BoolT>(CodeStubAssembler(state_).DecodeWord32<base::BitField<bool, 27, 1, uint32_t>>(ca_.UncheckedCast<Word32T>(p_bitsetLow)));
    ca_.Goto(&block111, tmp90);
  }

  TNode<BoolT> phi_bb111_7;
  if (block111.is_used()) {
    ca_.Bind(&block111, &phi_bb111_7);
    ca_.Branch(phi_bb111_7, &block107, std::vector<compiler::Node*>{}, &block108, std::vector<compiler::Node*>{});
  }

  if (block108.is_used()) {
    ca_.Bind(&block108);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/objects/turbofan-types.tq", 169});
      CodeStubAssembler(state_).FailAssert("Torque assert '!bitsetLow.negative_big_int_63 || bitsetLow.unsigned_big_int_63' failed", pos_stack);
    }
  }

  TNode<BoolT> tmp91;
  if (block107.is_used()) {
    ca_.Bind(&block107);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 172);
    tmp91 = FromConstexpr_bool_constexpr_bool_0(state_, (CodeStubAssembler(state_).ConstexprBoolNot((CodeStubAssembler(state_).Is64()))));
    ca_.Branch(tmp91, &block112, std::vector<compiler::Node*>{}, &block113, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp92;
  if (block112.is_used()) {
    ca_.Bind(&block112);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 173);
    tmp92 = ca_.UncheckedCast<BoolT>(CodeStubAssembler(state_).DecodeWord32<base::BitField<bool, 30, 1, uint32_t>>(ca_.UncheckedCast<Word32T>(p_bitsetLow)));
    ca_.Goto(&block1, tmp92);
  }

  TNode<IntPtrT> tmp93;
  TNode<IntPtrT> tmp94;
  TNode<BoolT> tmp95;
  if (block113.is_used()) {
    ca_.Bind(&block113);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 176);
    tmp93 = BigIntBuiltinsAssembler(state_).ReadBigIntLength(TNode<BigInt>{tmp70});
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 177);
    tmp94 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp95 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{tmp93}, TNode<IntPtrT>{tmp94});
    ca_.Branch(tmp95, &block114, std::vector<compiler::Node*>{}, &block115, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp96;
  if (block114.is_used()) {
    ca_.Bind(&block114);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 178);
    tmp96 = ca_.UncheckedCast<BoolT>(CodeStubAssembler(state_).DecodeWord32<base::BitField<bool, 30, 1, uint32_t>>(ca_.UncheckedCast<Word32T>(p_bitsetLow)));
    ca_.Goto(&block1, tmp96);
  }

  TNode<IntPtrT> tmp97;
  TNode<BoolT> tmp98;
  if (block115.is_used()) {
    ca_.Bind(&block115);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 179);
    tmp97 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp98 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{tmp93}, TNode<IntPtrT>{tmp97});
    ca_.Branch(tmp98, &block117, std::vector<compiler::Node*>{}, &block118, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp99;
  if (block117.is_used()) {
    ca_.Bind(&block117);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 180);
    tmp99 = ca_.UncheckedCast<BoolT>(CodeStubAssembler(state_).DecodeWord32<base::BitField<bool, 27, 1, uint32_t>>(ca_.UncheckedCast<Word32T>(p_bitsetLow)));
    ca_.Goto(&block1, tmp99);
  }

  TNode<IntPtrT> tmp100;
  TNode<BoolT> tmp101;
  if (block118.is_used()) {
    ca_.Bind(&block118);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 182);
    tmp100 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp101 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{tmp93}, TNode<IntPtrT>{tmp100});
    ca_.Branch(tmp101, &block119, std::vector<compiler::Node*>{}, &block120, std::vector<compiler::Node*>{});
  }

  if (block120.is_used()) {
    ca_.Bind(&block120);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/objects/turbofan-types.tq", 182});
      CodeStubAssembler(state_).FailAssert("Torque assert 'length == 1' failed", pos_stack);
    }
  }

  TNode<Uint32T> tmp102;
  TNode<IntPtrT> tmp103;
  TNode<UintPtrT> tmp104;
  TNode<Uint32T> tmp105;
  TNode<BoolT> tmp106;
  if (block119.is_used()) {
    ca_.Bind(&block119);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 183);
    tmp102 = BigIntBuiltinsAssembler(state_).ReadBigIntSign(TNode<BigInt>{tmp70});
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 184);
    tmp103 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp104 = CodeStubAssembler(state_).LoadBigIntDigit(TNode<BigInt>{tmp70}, TNode<IntPtrT>{tmp103});
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 185);
    tmp105 = kPositiveSign_0(state_);
    tmp106 = CodeStubAssembler(state_).Word32Equal(TNode<Uint32T>{tmp102}, TNode<Uint32T>{tmp105});
    ca_.Branch(tmp106, &block121, std::vector<compiler::Node*>{}, &block122, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp107;
  if (block121.is_used()) {
    ca_.Bind(&block121);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 186);
    tmp107 = ca_.UncheckedCast<BoolT>(CodeStubAssembler(state_).DecodeWord32<base::BitField<bool, 28, 1, uint32_t>>(ca_.UncheckedCast<Word32T>(p_bitsetLow)));
    ca_.Branch(tmp107, &block124, std::vector<compiler::Node*>{}, &block125, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp108;
  if (block124.is_used()) {
    ca_.Bind(&block124);
    tmp108 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block126, tmp108);
  }

  TNode<UintPtrT> tmp109;
  TNode<BoolT> tmp110;
  if (block125.is_used()) {
    ca_.Bind(&block125);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 187);
    tmp109 = Convert_uintptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(ca_.Is64() ? 0x7FFFFFFFFFFFFFFF : 0x7FFFFFFF));
    tmp110 = CodeStubAssembler(state_).UintPtrLessThanOrEqual(TNode<UintPtrT>{tmp104}, TNode<UintPtrT>{tmp109});
    ca_.Branch(tmp110, &block127, std::vector<compiler::Node*>{}, &block128, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp111;
  if (block127.is_used()) {
    ca_.Bind(&block127);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 188);
    tmp111 = ca_.UncheckedCast<BoolT>(CodeStubAssembler(state_).DecodeWord32<base::BitField<bool, 27, 1, uint32_t>>(ca_.UncheckedCast<Word32T>(p_bitsetLow)));
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 187);
    ca_.Goto(&block129, tmp111);
  }

  TNode<BoolT> tmp112;
  if (block128.is_used()) {
    ca_.Bind(&block128);
    tmp112 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block129, tmp112);
  }

  TNode<BoolT> phi_bb129_11;
  if (block129.is_used()) {
    ca_.Bind(&block129, &phi_bb129_11);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 186);
    ca_.Goto(&block126, phi_bb129_11);
  }

  TNode<BoolT> phi_bb126_10;
  if (block126.is_used()) {
    ca_.Bind(&block126, &phi_bb126_10);
    ca_.Goto(&block1, phi_bb126_10);
  }

  TNode<BoolT> tmp113;
  if (block122.is_used()) {
    ca_.Bind(&block122);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 190);
    tmp113 = ca_.UncheckedCast<BoolT>(CodeStubAssembler(state_).DecodeWord32<base::BitField<bool, 30, 1, uint32_t>>(ca_.UncheckedCast<Word32T>(p_bitsetLow)));
    ca_.Branch(tmp113, &block130, std::vector<compiler::Node*>{}, &block131, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp114;
  if (block130.is_used()) {
    ca_.Bind(&block130);
    tmp114 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block132, tmp114);
  }

  TNode<UintPtrT> tmp115;
  TNode<BoolT> tmp116;
  if (block131.is_used()) {
    ca_.Bind(&block131);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 191);
    tmp115 = Convert_uintptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(ca_.Is64() ? 0x8000000000000000 : 0x80000000));
    tmp116 = CodeStubAssembler(state_).UintPtrLessThanOrEqual(TNode<UintPtrT>{tmp104}, TNode<UintPtrT>{tmp115});
    ca_.Branch(tmp116, &block133, std::vector<compiler::Node*>{}, &block134, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp117;
  if (block133.is_used()) {
    ca_.Bind(&block133);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 192);
    tmp117 = ca_.UncheckedCast<BoolT>(CodeStubAssembler(state_).DecodeWord32<base::BitField<bool, 29, 1, uint32_t>>(ca_.UncheckedCast<Word32T>(p_bitsetLow)));
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 191);
    ca_.Goto(&block135, tmp117);
  }

  TNode<BoolT> tmp118;
  if (block134.is_used()) {
    ca_.Bind(&block134);
    tmp118 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block135, tmp118);
  }

  TNode<BoolT> phi_bb135_11;
  if (block135.is_used()) {
    ca_.Bind(&block135, &phi_bb135_11);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 190);
    ca_.Goto(&block132, phi_bb135_11);
  }

  TNode<BoolT> phi_bb132_10;
  if (block132.is_used()) {
    ca_.Bind(&block132, &phi_bb132_10);
    ca_.Goto(&block1, phi_bb132_10);
  }

  TNode<WasmObject> tmp119;
  if (block139.is_used()) {
    ca_.Bind(&block139);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 205);
    compiler::CodeAssemblerLabel label120(&ca_);
    tmp119 = Cast_WasmObject_0(state_, TNode<HeapObject>{ca_.UncheckedCast<HeapObject>(p_value)}, &label120);
    ca_.Goto(&block153);
    if (label120.is_used()) {
      ca_.Bind(&label120);
      ca_.Goto(&block154);
    }
  }

  TNode<IntPtrT> tmp121;
  TNode<Map> tmp122;
  TNode<BoolT> tmp123;
  if (block138.is_used()) {
    ca_.Bind(&block138);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 196);
    tmp121 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp122 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference{tmp73, tmp121});
    tmp123 = Method_Map_IsUndetectable_0(state_, TNode<Map>{tmp122});
    ca_.Branch(tmp123, &block140, std::vector<compiler::Node*>{}, &block141, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp124;
  if (block140.is_used()) {
    ca_.Bind(&block140);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 197);
    tmp124 = ca_.UncheckedCast<BoolT>(CodeStubAssembler(state_).DecodeWord32<base::BitField<bool, 17, 1, uint32_t>>(ca_.UncheckedCast<Word32T>(p_bitsetLow)));
    ca_.Goto(&block1, tmp124);
  }

  TNode<JSReceiver> tmp125;
  if (block141.is_used()) {
    ca_.Bind(&block141);
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 808);
    compiler::CodeAssemblerLabel label126(&ca_);
    tmp125 = Cast_Callable_0(state_, TNode<HeapObject>{tmp73}, &label126);
    ca_.Goto(&block148);
    if (label126.is_used()) {
      ca_.Bind(&label126);
      ca_.Goto(&block149);
    }
  }

  TNode<BoolT> tmp127;
  if (block149.is_used()) {
    ca_.Bind(&block149);
    tmp127 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block145, tmp127);
  }

  TNode<BoolT> tmp128;
  if (block148.is_used()) {
    ca_.Bind(&block148);
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 809);
    tmp128 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block145, tmp128);
  }

  TNode<BoolT> phi_bb145_8;
  if (block145.is_used()) {
    ca_.Bind(&block145, &phi_bb145_8);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 198);
    ca_.Branch(phi_bb145_8, &block143, std::vector<compiler::Node*>{}, &block144, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp129;
  if (block143.is_used()) {
    ca_.Bind(&block143);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 199);
    tmp129 = ca_.UncheckedCast<BoolT>(CodeStubAssembler(state_).DecodeWord32<base::BitField<bool, 15, 1, uint32_t>>(ca_.UncheckedCast<Word32T>(p_bitsetLow)));
    ca_.Goto(&block1, tmp129);
  }

  TNode<BoolT> tmp130;
  if (block144.is_used()) {
    ca_.Bind(&block144);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 201);
    tmp130 = ca_.UncheckedCast<BoolT>(CodeStubAssembler(state_).DecodeWord32<base::BitField<bool, 16, 1, uint32_t>>(ca_.UncheckedCast<Word32T>(p_bitsetLow)));
    ca_.Goto(&block1, tmp130);
  }

  TNode<BoolT> tmp131;
  if (block154.is_used()) {
    ca_.Bind(&block154);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 209);
    tmp131 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp131);
  }

  TNode<BoolT> tmp132;
  if (block153.is_used()) {
    ca_.Bind(&block153);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 206);
    tmp132 = ca_.UncheckedCast<BoolT>(CodeStubAssembler(state_).DecodeWord32<base::BitField<bool, 31, 1, uint32_t>>(ca_.UncheckedCast<Word32T>(p_bitsetLow)));
    ca_.Goto(&block1, tmp132);
  }

  TNode<BoolT> phi_bb1_3;
  if (block1.is_used()) {
    ca_.Bind(&block1, &phi_bb1_3);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 92);
    ca_.Goto(&block155);
  }

    ca_.Bind(&block155);
  return TNode<BoolT>{phi_bb1_3};
}

TF_BUILTIN(TestTurbofanType, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedParameter<Context>(Descriptor::kContext);
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kValue);
  USE(parameter1);
  TNode<TurbofanType> parameter2 = UncheckedParameter<TurbofanType>(Descriptor::kExpectedType);
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block25(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block26(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block27(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block31(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block30(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block35(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block34(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block39(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block38(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<TurbofanBitsetType> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 217);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = Cast_TurbofanBitsetType_0(state_, TNode<HeapObject>{parameter2}, &label1);
    ca_.Goto(&block3);
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block4);
    }
  }

  TNode<TurbofanUnionType> tmp2;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 221);
    compiler::CodeAssemblerLabel label3(&ca_);
    tmp2 = Cast_TurbofanUnionType_0(state_, TNode<HeapObject>{ca_.UncheckedCast<TurbofanType>(parameter2)}, &label3);
    ca_.Goto(&block7);
    if (label3.is_used()) {
      ca_.Bind(&label3);
      ca_.Goto(&block8);
    }
  }

  TNode<IntPtrT> tmp4;
  TNode<Uint32T> tmp5;
  TNode<IntPtrT> tmp6;
  TNode<Uint32T> tmp7;
  TNode<BoolT> tmp8;
  TNode<Oddball> tmp9;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 219);
    tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp5 = CodeStubAssembler(state_).LoadReference<Uint32T>(CodeStubAssembler::Reference{tmp0, tmp4});
    tmp6 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp7 = CodeStubAssembler(state_).LoadReference<Uint32T>(CodeStubAssembler::Reference{tmp0, tmp6});
    tmp8 = TestTurbofanBitsetType_0(state_, TNode<Object>{parameter1}, TNode<Uint32T>{tmp5}, TNode<Uint32T>{tmp7});
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 218);
    tmp9 = Convert_Boolean_bool_0(state_, TNode<BoolT>{tmp8});
    CodeStubAssembler(state_).Return(tmp9);
  }

  TNode<TurbofanRangeType> tmp10;
  if (block8.is_used()) {
    ca_.Bind(&block8);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 226);
    compiler::CodeAssemblerLabel label11(&ca_);
    tmp10 = Cast_TurbofanRangeType_0(state_, TNode<HeapObject>{ca_.UncheckedCast<TurbofanType>(parameter2)}, &label11);
    ca_.Goto(&block14);
    if (label11.is_used()) {
      ca_.Bind(&label11);
      ca_.Goto(&block15);
    }
  }

  TNode<IntPtrT> tmp12;
  TNode<TurbofanType> tmp13;
  TNode<Oddball> tmp14;
  TNode<Oddball> tmp15;
  TNode<BoolT> tmp16;
  if (block7.is_used()) {
    ca_.Bind(&block7);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 223);
    tmp12 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp13 = CodeStubAssembler(state_).LoadReference<TurbofanType>(CodeStubAssembler::Reference{tmp2, tmp12});
    tmp14 = ca_.CallStub<Oddball>(Builtins::CallableFor(ca_.isolate(), Builtin::kTestTurbofanType), parameter0, parameter1, tmp13);
    tmp15 = True_0(state_);
    tmp16 = CodeStubAssembler(state_).TaggedEqual(TNode<HeapObject>{tmp14}, TNode<HeapObject>{tmp15});
    ca_.Branch(tmp16, &block9, std::vector<compiler::Node*>{}, &block10, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp17;
  if (block9.is_used()) {
    ca_.Bind(&block9);
    tmp17 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block11, tmp17);
  }

  TNode<IntPtrT> tmp18;
  TNode<TurbofanType> tmp19;
  TNode<Oddball> tmp20;
  TNode<Oddball> tmp21;
  TNode<BoolT> tmp22;
  if (block10.is_used()) {
    ca_.Bind(&block10);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 224);
    tmp18 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp19 = CodeStubAssembler(state_).LoadReference<TurbofanType>(CodeStubAssembler::Reference{tmp2, tmp18});
    tmp20 = ca_.CallStub<Oddball>(Builtins::CallableFor(ca_.isolate(), Builtin::kTestTurbofanType), parameter0, parameter1, tmp19);
    tmp21 = True_0(state_);
    tmp22 = CodeStubAssembler(state_).TaggedEqual(TNode<HeapObject>{tmp20}, TNode<HeapObject>{tmp21});
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 223);
    ca_.Goto(&block11, tmp22);
  }

  TNode<BoolT> phi_bb11_6;
  TNode<Oddball> tmp23;
  if (block11.is_used()) {
    ca_.Bind(&block11, &phi_bb11_6);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 222);
    tmp23 = Convert_Boolean_bool_0(state_, TNode<BoolT>{phi_bb11_6});
    CodeStubAssembler(state_).Return(tmp23);
  }

  TNode<TurbofanHeapConstantType> tmp24;
  if (block15.is_used()) {
    ca_.Bind(&block15);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 233);
    compiler::CodeAssemblerLabel label25(&ca_);
    tmp24 = Cast_TurbofanHeapConstantType_0(state_, TNode<HeapObject>{ca_.UncheckedCast<TurbofanType>(parameter2)}, &label25);
    ca_.Goto(&block30);
    if (label25.is_used()) {
      ca_.Bind(&label25);
      ca_.Goto(&block31);
    }
  }

  TNode<Number> tmp26;
  if (block14.is_used()) {
    ca_.Bind(&block14);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 227);
    compiler::CodeAssemblerLabel label27(&ca_);
    tmp26 = Cast_Number_0(state_, TNode<Object>{parameter1}, &label27);
    ca_.Goto(&block18);
    if (label27.is_used()) {
      ca_.Bind(&label27);
      ca_.Goto(&block19);
    }
  }

  TNode<Oddball> tmp28;
  if (block19.is_used()) {
    ca_.Bind(&block19);
    tmp28 = False_0(state_);
    CodeStubAssembler(state_).Return(tmp28);
  }

  TNode<BoolT> tmp29;
  TNode<BoolT> tmp30;
  if (block18.is_used()) {
    ca_.Bind(&block18);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 228);
    tmp29 = IsIntegerOrSomeInfinity_0(state_, TNode<Object>{tmp26});
    tmp30 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp29});
    ca_.Branch(tmp30, &block20, std::vector<compiler::Node*>{}, &block21, std::vector<compiler::Node*>{});
  }

  TNode<Oddball> tmp31;
  if (block20.is_used()) {
    ca_.Bind(&block20);
    tmp31 = False_0(state_);
    CodeStubAssembler(state_).Return(tmp31);
  }

  TNode<Float64T> tmp32;
  TNode<BoolT> tmp33;
  TNode<BoolT> tmp34;
  if (block21.is_used()) {
    ca_.Bind(&block21);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 229);
    tmp32 = Convert_float64_Number_0(state_, TNode<Number>{tmp26});
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 231);
    tmp33 = IsMinusZero_0(state_, TNode<Float64T>{tmp32});
    tmp34 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp33});
    ca_.Branch(tmp34, &block22, std::vector<compiler::Node*>{}, &block23, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp35;
  TNode<Float64T> tmp36;
  TNode<BoolT> tmp37;
  if (block22.is_used()) {
    ca_.Bind(&block22);
    tmp35 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp36 = CodeStubAssembler(state_).LoadReference<Float64T>(CodeStubAssembler::Reference{tmp10, tmp35});
    tmp37 = CodeStubAssembler(state_).Float64LessThanOrEqual(TNode<Float64T>{tmp36}, TNode<Float64T>{tmp32});
    ca_.Goto(&block24, tmp37);
  }

  TNode<BoolT> tmp38;
  if (block23.is_used()) {
    ca_.Bind(&block23);
    tmp38 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block24, tmp38);
  }

  TNode<BoolT> phi_bb24_8;
  if (block24.is_used()) {
    ca_.Bind(&block24, &phi_bb24_8);
    ca_.Branch(phi_bb24_8, &block25, std::vector<compiler::Node*>{}, &block26, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp39;
  TNode<Float64T> tmp40;
  TNode<BoolT> tmp41;
  if (block25.is_used()) {
    ca_.Bind(&block25);
    tmp39 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp40 = CodeStubAssembler(state_).LoadReference<Float64T>(CodeStubAssembler::Reference{tmp10, tmp39});
    tmp41 = CodeStubAssembler(state_).Float64LessThanOrEqual(TNode<Float64T>{tmp32}, TNode<Float64T>{tmp40});
    ca_.Goto(&block27, tmp41);
  }

  TNode<BoolT> tmp42;
  if (block26.is_used()) {
    ca_.Bind(&block26);
    tmp42 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block27, tmp42);
  }

  TNode<BoolT> phi_bb27_8;
  TNode<Oddball> tmp43;
  if (block27.is_used()) {
    ca_.Bind(&block27, &phi_bb27_8);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 230);
    tmp43 = Convert_Boolean_bool_0(state_, TNode<BoolT>{phi_bb27_8});
    CodeStubAssembler(state_).Return(tmp43);
  }

  TNode<TurbofanOtherNumberConstantType> tmp44;
  if (block31.is_used()) {
    ca_.Bind(&block31);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 236);
    compiler::CodeAssemblerLabel label45(&ca_);
    tmp44 = Cast_TurbofanOtherNumberConstantType_0(state_, TNode<HeapObject>{ca_.UncheckedCast<TurbofanType>(parameter2)}, &label45);
    ca_.Goto(&block34);
    if (label45.is_used()) {
      ca_.Bind(&label45);
      ca_.Goto(&block35);
    }
  }

  TNode<IntPtrT> tmp46;
  TNode<HeapObject> tmp47;
  TNode<BoolT> tmp48;
  TNode<Oddball> tmp49;
  if (block30.is_used()) {
    ca_.Bind(&block30);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 234);
    tmp46 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp47 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{tmp24, tmp46});
    tmp48 = CodeStubAssembler(state_).TaggedEqual(TNode<MaybeObject>{parameter1}, TNode<MaybeObject>{tmp47});
    tmp49 = Convert_Boolean_bool_0(state_, TNode<BoolT>{tmp48});
    CodeStubAssembler(state_).Return(tmp49);
  }

  if (block35.is_used()) {
    ca_.Bind(&block35);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 242);
    CodeStubAssembler(state_).PrintErr("halting because of unreachable code at src/objects/turbofan-types.tq:242:7");
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<Number> tmp50;
  if (block34.is_used()) {
    ca_.Bind(&block34);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 238);
    compiler::CodeAssemblerLabel label51(&ca_);
    tmp50 = Cast_Number_0(state_, TNode<Object>{parameter1}, &label51);
    ca_.Goto(&block38);
    if (label51.is_used()) {
      ca_.Bind(&label51);
      ca_.Goto(&block39);
    }
  }

  TNode<Oddball> tmp52;
  if (block39.is_used()) {
    ca_.Bind(&block39);
    tmp52 = False_0(state_);
    CodeStubAssembler(state_).Return(tmp52);
  }

  TNode<Float64T> tmp53;
  TNode<IntPtrT> tmp54;
  TNode<Float64T> tmp55;
  TNode<BoolT> tmp56;
  TNode<Oddball> tmp57;
  if (block38.is_used()) {
    ca_.Bind(&block38);
    tmp53 = Convert_float64_Number_0(state_, TNode<Number>{tmp50});
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 239);
    tmp54 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp55 = CodeStubAssembler(state_).LoadReference<Float64T>(CodeStubAssembler::Reference{tmp44, tmp54});
    tmp56 = CodeStubAssembler(state_).Float64Equal(TNode<Float64T>{tmp53}, TNode<Float64T>{tmp55});
    tmp57 = Convert_Boolean_bool_0(state_, TNode<BoolT>{tmp56});
    CodeStubAssembler(state_).Return(tmp57);
  }
}

TF_BUILTIN(CheckTurbofanType, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedParameter<Context>(Descriptor::kContext);
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kValue);
  USE(parameter1);
  TNode<TurbofanType> parameter2 = UncheckedParameter<TurbofanType>(Descriptor::kExpectedType);
  USE(parameter2);
  TNode<Smi> parameter3 = UncheckedParameter<Smi>(Descriptor::kNodeId);
  USE(parameter3);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Oddball> tmp0;
  TNode<Oddball> tmp1;
  TNode<BoolT> tmp2;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 249);
    tmp0 = ca_.CallStub<Oddball>(Builtins::CallableFor(ca_.isolate(), Builtin::kTestTurbofanType), parameter0, parameter1, parameter2);
    tmp1 = True_0(state_);
    tmp2 = CodeStubAssembler(state_).TaggedEqual(TNode<HeapObject>{tmp0}, TNode<HeapObject>{tmp1});
    ca_.Branch(tmp2, &block1, std::vector<compiler::Node*>{}, &block2, std::vector<compiler::Node*>{});
  }

  TNode<Oddball> tmp3;
  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 250);
    tmp3 = Undefined_0(state_);
    CodeStubAssembler(state_).Return(tmp3);
  }

  if (block2.is_used()) {
    ca_.Bind(&block2);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 253);
    CodeStubAssembler(state_).PrintErr("Type assertion failed! (value/expectedType/nodeId)");
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 254);
    CodeStubAssembler(state_).PrintErr(TNode<Object>{parameter1});
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 255);
    CodeStubAssembler(state_).PrintErr(TNode<Object>{parameter2});
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 256);
    CodeStubAssembler(state_).PrintErr(TNode<Object>{parameter3});
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 257);
    CodeStubAssembler(state_).PrintErr("halting because of unreachable code at src/objects/turbofan-types.tq:257:3");
    CodeStubAssembler(state_).Unreachable();
  }
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turbofan-types.tq?l=62&c=3
TNode<Uint32T> LoadTurbofanBitsetTypeBitsetLow_0(compiler::CodeAssemblerState* state_, TNode<TurbofanBitsetType> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Uint32T> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 62);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp1 = CodeStubAssembler(state_).LoadReference<Uint32T>(CodeStubAssembler::Reference{p_o, tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Uint32T>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turbofan-types.tq?l=62&c=3
void StoreTurbofanBitsetTypeBitsetLow_0(compiler::CodeAssemblerState* state_, TNode<TurbofanBitsetType> p_o, TNode<Uint32T> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 62);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    CodeStubAssembler(state_).StoreReference<Uint32T>(CodeStubAssembler::Reference{p_o, tmp0}, p_v);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turbofan-types.tq?l=63&c=3
TNode<Uint32T> LoadTurbofanBitsetTypeBitsetHigh_0(compiler::CodeAssemblerState* state_, TNode<TurbofanBitsetType> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Uint32T> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 63);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp1 = CodeStubAssembler(state_).LoadReference<Uint32T>(CodeStubAssembler::Reference{p_o, tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Uint32T>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turbofan-types.tq?l=63&c=3
void StoreTurbofanBitsetTypeBitsetHigh_0(compiler::CodeAssemblerState* state_, TNode<TurbofanBitsetType> p_o, TNode<Uint32T> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 63);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    CodeStubAssembler(state_).StoreReference<Uint32T>(CodeStubAssembler::Reference{p_o, tmp0}, p_v);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turbofan-types.tq?l=68&c=3
TNode<TurbofanType> LoadTurbofanUnionTypeType1_0(compiler::CodeAssemblerState* state_, TNode<TurbofanUnionType> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<TurbofanType> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 68);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp1 = CodeStubAssembler(state_).LoadReference<TurbofanType>(CodeStubAssembler::Reference{p_o, tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<TurbofanType>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turbofan-types.tq?l=68&c=3
void StoreTurbofanUnionTypeType1_0(compiler::CodeAssemblerState* state_, TNode<TurbofanUnionType> p_o, TNode<TurbofanType> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 68);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    CodeStubAssembler(state_).StoreReference<TurbofanType>(CodeStubAssembler::Reference{p_o, tmp0}, p_v);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turbofan-types.tq?l=69&c=3
TNode<TurbofanType> LoadTurbofanUnionTypeType2_0(compiler::CodeAssemblerState* state_, TNode<TurbofanUnionType> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<TurbofanType> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 69);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp1 = CodeStubAssembler(state_).LoadReference<TurbofanType>(CodeStubAssembler::Reference{p_o, tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<TurbofanType>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turbofan-types.tq?l=69&c=3
void StoreTurbofanUnionTypeType2_0(compiler::CodeAssemblerState* state_, TNode<TurbofanUnionType> p_o, TNode<TurbofanType> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 69);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    CodeStubAssembler(state_).StoreReference<TurbofanType>(CodeStubAssembler::Reference{p_o, tmp0}, p_v);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turbofan-types.tq?l=74&c=3
TNode<Float64T> LoadTurbofanRangeTypeMin_0(compiler::CodeAssemblerState* state_, TNode<TurbofanRangeType> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Float64T> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 74);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp1 = CodeStubAssembler(state_).LoadReference<Float64T>(CodeStubAssembler::Reference{p_o, tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Float64T>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turbofan-types.tq?l=74&c=3
void StoreTurbofanRangeTypeMin_0(compiler::CodeAssemblerState* state_, TNode<TurbofanRangeType> p_o, TNode<Float64T> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Float64T> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 74);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp1 = CodeStubAssembler(state_).Float64SilenceNaN(TNode<Float64T>{p_v});
    CodeStubAssembler(state_).StoreReference<Float64T>(CodeStubAssembler::Reference{p_o, tmp0}, tmp1);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turbofan-types.tq?l=75&c=3
TNode<Float64T> LoadTurbofanRangeTypeMax_0(compiler::CodeAssemblerState* state_, TNode<TurbofanRangeType> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Float64T> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 75);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp1 = CodeStubAssembler(state_).LoadReference<Float64T>(CodeStubAssembler::Reference{p_o, tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Float64T>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turbofan-types.tq?l=75&c=3
void StoreTurbofanRangeTypeMax_0(compiler::CodeAssemblerState* state_, TNode<TurbofanRangeType> p_o, TNode<Float64T> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Float64T> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 75);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp1 = CodeStubAssembler(state_).Float64SilenceNaN(TNode<Float64T>{p_v});
    CodeStubAssembler(state_).StoreReference<Float64T>(CodeStubAssembler::Reference{p_o, tmp0}, tmp1);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turbofan-types.tq?l=80&c=3
TNode<HeapObject> LoadTurbofanHeapConstantTypeConstant_0(compiler::CodeAssemblerState* state_, TNode<TurbofanHeapConstantType> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<HeapObject> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 80);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp1 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{p_o, tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<HeapObject>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turbofan-types.tq?l=80&c=3
void StoreTurbofanHeapConstantTypeConstant_0(compiler::CodeAssemblerState* state_, TNode<TurbofanHeapConstantType> p_o, TNode<HeapObject> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 80);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    CodeStubAssembler(state_).StoreReference<HeapObject>(CodeStubAssembler::Reference{p_o, tmp0}, p_v);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turbofan-types.tq?l=85&c=3
TNode<Float64T> LoadTurbofanOtherNumberConstantTypeConstant_0(compiler::CodeAssemblerState* state_, TNode<TurbofanOtherNumberConstantType> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Float64T> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 85);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp1 = CodeStubAssembler(state_).LoadReference<Float64T>(CodeStubAssembler::Reference{p_o, tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Float64T>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turbofan-types.tq?l=85&c=3
void StoreTurbofanOtherNumberConstantTypeConstant_0(compiler::CodeAssemblerState* state_, TNode<TurbofanOtherNumberConstantType> p_o, TNode<Float64T> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Float64T> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 85);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp1 = CodeStubAssembler(state_).Float64SilenceNaN(TNode<Float64T>{p_v});
    CodeStubAssembler(state_).StoreReference<Float64T>(CodeStubAssembler::Reference{p_o, tmp0}, tmp1);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turbofan-types.tq?l=12&c=1
TNode<TurbofanType> DownCastForTorqueClass_TurbofanType_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError) {
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
    if (((CodeStubAssembler(state_).ConstexprInt31Equal(static_cast<InstanceType>(215), static_cast<InstanceType>(219))))) {
      ca_.Goto(&block3);
    } else {
      ca_.Goto(&block4);
    }
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 331);
    if ((CodeStubAssembler(state_).ClassHasMapConstant<TurbofanType>())) {
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
    tmp2 = CodeStubAssembler(state_).GetClassMapConstant<TurbofanType>();
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
    tmp6 = FromConstexpr_uint32_constexpr_uint32_0(state_, static_cast<InstanceType>(215));
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
    tmp8 = FromConstexpr_int32_constexpr_int32_0(state_, (CodeStubAssembler(state_).ConstexprUint32Sub(static_cast<InstanceType>(219), static_cast<InstanceType>(215))));
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 338);
    tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp10 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference{tmp1, tmp9});
    tmp11 = Convert_uint16_InstanceType_0(state_, TNode<Uint16T>{tmp10});
    tmp12 = Convert_int32_uint16_0(state_, TNode<Uint16T>{tmp11});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 340);
    tmp13 = FromConstexpr_InstanceType_constexpr_InstanceType_0(state_, static_cast<InstanceType>(215));
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

  TNode<TurbofanType> tmp20;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 343);
    tmp20 = TORQUE_CAST(TNode<HeapObject>{p_o});
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 12);
    ca_.Goto(&block15);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_CastError);
  }

    ca_.Bind(&block15);
  return TNode<TurbofanType>{tmp20};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turbofan-types.tq?l=60&c=1
TNode<TurbofanBitsetType> DownCastForTorqueClass_TurbofanBitsetType_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError) {
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
    if (((CodeStubAssembler(state_).ConstexprInt31Equal(static_cast<InstanceType>(215), static_cast<InstanceType>(215))))) {
      ca_.Goto(&block3);
    } else {
      ca_.Goto(&block4);
    }
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 331);
    if ((CodeStubAssembler(state_).ClassHasMapConstant<TurbofanBitsetType>())) {
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
    tmp2 = CodeStubAssembler(state_).GetClassMapConstant<TurbofanBitsetType>();
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
    tmp6 = FromConstexpr_uint32_constexpr_uint32_0(state_, static_cast<InstanceType>(215));
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
    tmp8 = FromConstexpr_int32_constexpr_int32_0(state_, (CodeStubAssembler(state_).ConstexprUint32Sub(static_cast<InstanceType>(215), static_cast<InstanceType>(215))));
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 338);
    tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp10 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference{tmp1, tmp9});
    tmp11 = Convert_uint16_InstanceType_0(state_, TNode<Uint16T>{tmp10});
    tmp12 = Convert_int32_uint16_0(state_, TNode<Uint16T>{tmp11});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 340);
    tmp13 = FromConstexpr_InstanceType_constexpr_InstanceType_0(state_, static_cast<InstanceType>(215));
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

  TNode<TurbofanBitsetType> tmp20;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 343);
    tmp20 = TORQUE_CAST(TNode<HeapObject>{p_o});
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 60);
    ca_.Goto(&block15);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_CastError);
  }

    ca_.Bind(&block15);
  return TNode<TurbofanBitsetType>{tmp20};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turbofan-types.tq?l=66&c=1
TNode<TurbofanUnionType> DownCastForTorqueClass_TurbofanUnionType_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError) {
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
    if (((CodeStubAssembler(state_).ConstexprInt31Equal(static_cast<InstanceType>(219), static_cast<InstanceType>(219))))) {
      ca_.Goto(&block3);
    } else {
      ca_.Goto(&block4);
    }
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 331);
    if ((CodeStubAssembler(state_).ClassHasMapConstant<TurbofanUnionType>())) {
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
    tmp2 = CodeStubAssembler(state_).GetClassMapConstant<TurbofanUnionType>();
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
    tmp6 = FromConstexpr_uint32_constexpr_uint32_0(state_, static_cast<InstanceType>(219));
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
    tmp8 = FromConstexpr_int32_constexpr_int32_0(state_, (CodeStubAssembler(state_).ConstexprUint32Sub(static_cast<InstanceType>(219), static_cast<InstanceType>(219))));
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 338);
    tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp10 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference{tmp1, tmp9});
    tmp11 = Convert_uint16_InstanceType_0(state_, TNode<Uint16T>{tmp10});
    tmp12 = Convert_int32_uint16_0(state_, TNode<Uint16T>{tmp11});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 340);
    tmp13 = FromConstexpr_InstanceType_constexpr_InstanceType_0(state_, static_cast<InstanceType>(219));
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

  TNode<TurbofanUnionType> tmp20;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 343);
    tmp20 = TORQUE_CAST(TNode<HeapObject>{p_o});
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 66);
    ca_.Goto(&block15);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_CastError);
  }

    ca_.Bind(&block15);
  return TNode<TurbofanUnionType>{tmp20};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turbofan-types.tq?l=72&c=1
TNode<TurbofanRangeType> DownCastForTorqueClass_TurbofanRangeType_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError) {
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
    if (((CodeStubAssembler(state_).ConstexprInt31Equal(static_cast<InstanceType>(218), static_cast<InstanceType>(218))))) {
      ca_.Goto(&block3);
    } else {
      ca_.Goto(&block4);
    }
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 331);
    if ((CodeStubAssembler(state_).ClassHasMapConstant<TurbofanRangeType>())) {
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
    tmp2 = CodeStubAssembler(state_).GetClassMapConstant<TurbofanRangeType>();
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
    tmp6 = FromConstexpr_uint32_constexpr_uint32_0(state_, static_cast<InstanceType>(218));
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
    tmp8 = FromConstexpr_int32_constexpr_int32_0(state_, (CodeStubAssembler(state_).ConstexprUint32Sub(static_cast<InstanceType>(218), static_cast<InstanceType>(218))));
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 338);
    tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp10 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference{tmp1, tmp9});
    tmp11 = Convert_uint16_InstanceType_0(state_, TNode<Uint16T>{tmp10});
    tmp12 = Convert_int32_uint16_0(state_, TNode<Uint16T>{tmp11});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 340);
    tmp13 = FromConstexpr_InstanceType_constexpr_InstanceType_0(state_, static_cast<InstanceType>(218));
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

  TNode<TurbofanRangeType> tmp20;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 343);
    tmp20 = TORQUE_CAST(TNode<HeapObject>{p_o});
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 72);
    ca_.Goto(&block15);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_CastError);
  }

    ca_.Bind(&block15);
  return TNode<TurbofanRangeType>{tmp20};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turbofan-types.tq?l=78&c=1
TNode<TurbofanHeapConstantType> DownCastForTorqueClass_TurbofanHeapConstantType_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError) {
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
    if (((CodeStubAssembler(state_).ConstexprInt31Equal(static_cast<InstanceType>(216), static_cast<InstanceType>(216))))) {
      ca_.Goto(&block3);
    } else {
      ca_.Goto(&block4);
    }
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 331);
    if ((CodeStubAssembler(state_).ClassHasMapConstant<TurbofanHeapConstantType>())) {
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
    tmp2 = CodeStubAssembler(state_).GetClassMapConstant<TurbofanHeapConstantType>();
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
    tmp6 = FromConstexpr_uint32_constexpr_uint32_0(state_, static_cast<InstanceType>(216));
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
    tmp8 = FromConstexpr_int32_constexpr_int32_0(state_, (CodeStubAssembler(state_).ConstexprUint32Sub(static_cast<InstanceType>(216), static_cast<InstanceType>(216))));
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 338);
    tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp10 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference{tmp1, tmp9});
    tmp11 = Convert_uint16_InstanceType_0(state_, TNode<Uint16T>{tmp10});
    tmp12 = Convert_int32_uint16_0(state_, TNode<Uint16T>{tmp11});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 340);
    tmp13 = FromConstexpr_InstanceType_constexpr_InstanceType_0(state_, static_cast<InstanceType>(216));
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

  TNode<TurbofanHeapConstantType> tmp20;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 343);
    tmp20 = TORQUE_CAST(TNode<HeapObject>{p_o});
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 78);
    ca_.Goto(&block15);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_CastError);
  }

    ca_.Bind(&block15);
  return TNode<TurbofanHeapConstantType>{tmp20};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turbofan-types.tq?l=83&c=1
TNode<TurbofanOtherNumberConstantType> DownCastForTorqueClass_TurbofanOtherNumberConstantType_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError) {
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
    if (((CodeStubAssembler(state_).ConstexprInt31Equal(static_cast<InstanceType>(217), static_cast<InstanceType>(217))))) {
      ca_.Goto(&block3);
    } else {
      ca_.Goto(&block4);
    }
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 331);
    if ((CodeStubAssembler(state_).ClassHasMapConstant<TurbofanOtherNumberConstantType>())) {
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
    tmp2 = CodeStubAssembler(state_).GetClassMapConstant<TurbofanOtherNumberConstantType>();
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
    tmp6 = FromConstexpr_uint32_constexpr_uint32_0(state_, static_cast<InstanceType>(217));
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
    tmp8 = FromConstexpr_int32_constexpr_int32_0(state_, (CodeStubAssembler(state_).ConstexprUint32Sub(static_cast<InstanceType>(217), static_cast<InstanceType>(217))));
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 338);
    tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp10 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference{tmp1, tmp9});
    tmp11 = Convert_uint16_InstanceType_0(state_, TNode<Uint16T>{tmp10});
    tmp12 = Convert_int32_uint16_0(state_, TNode<Uint16T>{tmp11});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 340);
    tmp13 = FromConstexpr_InstanceType_constexpr_InstanceType_0(state_, static_cast<InstanceType>(217));
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

  TNode<TurbofanOtherNumberConstantType> tmp20;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 343);
    tmp20 = TORQUE_CAST(TNode<HeapObject>{p_o});
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 83);
    ca_.Goto(&block15);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_CastError);
  }

    ca_.Bind(&block15);
  return TNode<TurbofanOtherNumberConstantType>{tmp20};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turbofan-types.tq?l=144&c=14
TNode<BoolT> Is_Callable_JSProxy_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSProxy> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<JSReceiver> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 808);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = Cast_Callable_0(state_, TNode<HeapObject>{p_o}, &label1);
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
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 144);
    ca_.Goto(&block6);
  }

    ca_.Bind(&block6);
  return TNode<BoolT>{phi_bb1_2};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turbofan-types.tq?l=187&c=23
TNode<UintPtrT> Convert_uintptr_constexpr_IntegerLiteral_0(compiler::CodeAssemblerState* state_, IntegerLiteral p_i) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<UintPtrT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/convert.tq", 187);
    tmp0 = FromConstexpr_uintptr_constexpr_IntegerLiteral_0(state_, p_i);
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 187);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<UintPtrT>{tmp0};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turbofan-types.tq?l=198&c=18
TNode<BoolT> Is_Callable_JSObject_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSObject> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<JSReceiver> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/cast.tq", 808);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = Cast_Callable_0(state_, TNode<HeapObject>{p_o}, &label1);
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
    ca_.SetSourcePosition("../../../src/objects/turbofan-types.tq", 198);
    ca_.Goto(&block6);
  }

    ca_.Bind(&block6);
  return TNode<BoolT>{phi_bb1_2};
}

} // namespace internal
} // namespace v8
