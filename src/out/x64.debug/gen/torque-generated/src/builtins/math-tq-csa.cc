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
#include "torque-generated/src/builtins/math-tq-csa.h"
#include "torque-generated/src/builtins/base-tq-csa.h"
#include "torque-generated/src/builtins/cast-tq-csa.h"
#include "torque-generated/src/builtins/conversion-tq-csa.h"
#include "torque-generated/src/builtins/convert-tq-csa.h"
#include "torque-generated/src/builtins/frame-arguments-tq-csa.h"
#include "torque-generated/src/builtins/math-tq-csa.h"
#include "torque-generated/src/builtins/torque-internal-tq-csa.h"
#include "torque-generated/src/objects/contexts-tq-csa.h"
#include "torque-generated/src/objects/fixed-array-tq-csa.h"
#include "torque-generated/src/objects/heap-number-tq-csa.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/math.tq?l=7&c=1
void ReduceToSmiOrFloat64_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_x, compiler::CodeAssemblerLabel* label_SmiResult, compiler::TypedCodeAssemblerVariable<Smi>* label_SmiResult_parameter_0, compiler::CodeAssemblerLabel* label_Float64Result, compiler::TypedCodeAssemblerVariable<Float64T>* label_Float64Result_parameter_0) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object, Object> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object, Object> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 11);
    ca_.Goto(&block5, p_x);
  }

  TNode<Object> phi_bb5_2;
  TNode<BoolT> tmp0;
  if (block5.is_used()) {
    ca_.Bind(&block5, &phi_bb5_2);
    tmp0 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Branch(tmp0, &block3, std::vector<compiler::Node*>{phi_bb5_2}, &block4, std::vector<compiler::Node*>{phi_bb5_2});
  }

  TNode<Object> phi_bb3_2;
  TNode<Smi> tmp1;
  if (block3.is_used()) {
    ca_.Bind(&block3, &phi_bb3_2);
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 13);
    compiler::CodeAssemblerLabel label2(&ca_);
    tmp1 = Cast_Smi_0(state_, TNode<Object>{phi_bb3_2}, &label2);
    ca_.Goto(&block8, phi_bb3_2, phi_bb3_2, phi_bb3_2);
    if (label2.is_used()) {
      ca_.Bind(&label2);
      ca_.Goto(&block9, phi_bb3_2, phi_bb3_2, phi_bb3_2);
    }
  }

  TNode<Object> phi_bb9_2;
  TNode<Object> phi_bb9_3;
  TNode<Object> phi_bb9_4;
  TNode<HeapNumber> tmp3;
  if (block9.is_used()) {
    ca_.Bind(&block9, &phi_bb9_2, &phi_bb9_3, &phi_bb9_4);
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 16);
    compiler::CodeAssemblerLabel label4(&ca_);
    tmp3 = Cast_HeapNumber_0(state_, TNode<HeapObject>{ca_.UncheckedCast<HeapObject>(phi_bb9_3)}, &label4);
    ca_.Goto(&block12, phi_bb9_2, phi_bb9_3);
    if (label4.is_used()) {
      ca_.Bind(&label4);
      ca_.Goto(&block13, phi_bb9_2, phi_bb9_3);
    }
  }

  TNode<Object> phi_bb8_2;
  TNode<Object> phi_bb8_3;
  TNode<Object> phi_bb8_4;
  if (block8.is_used()) {
    ca_.Bind(&block8, &phi_bb8_2, &phi_bb8_3, &phi_bb8_4);
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 7);
    *label_SmiResult_parameter_0 = tmp1;
    ca_.Goto(label_SmiResult);
  }

  TNode<Object> phi_bb13_2;
  TNode<Object> phi_bb13_3;
  TNode<Number> tmp5;
  if (block13.is_used()) {
    ca_.Bind(&block13, &phi_bb13_2, &phi_bb13_3);
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 20);
    tmp5 = ca_.CallStub<Number>(Builtins::CallableFor(ca_.isolate(), Builtin::kNonNumberToNumber), p_context, ca_.UncheckedCast<HeapObject>(phi_bb13_3));
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 11);
    ca_.Goto(&block5, tmp5);
  }

  TNode<Object> phi_bb12_2;
  TNode<Object> phi_bb12_3;
  TNode<Float64T> tmp6;
  if (block12.is_used()) {
    ca_.Bind(&block12, &phi_bb12_2, &phi_bb12_3);
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 17);
    tmp6 = Convert_float64_HeapNumber_0(state_, TNode<HeapNumber>{tmp3});
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 7);
    *label_Float64Result_parameter_0 = tmp6;
    ca_.Goto(label_Float64Result);
  }

  TNode<Object> phi_bb4_2;
  if (block4.is_used()) {
    ca_.Bind(&block4, &phi_bb4_2);
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 24);
    VerifiedUnreachable_0(state_);
  }
}

TF_BUILTIN(MathAbs, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kX);
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    compiler::TypedCodeAssemblerVariable<Smi> tmp1(&ca_);
    compiler::TypedCodeAssemblerVariable<Float64T> tmp3(&ca_);
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 39);
    compiler::CodeAssemblerLabel label0(&ca_);
    compiler::CodeAssemblerLabel label2(&ca_);
    ReduceToSmiOrFloat64_0(state_, TNode<Context>{parameter0}, TNode<Object>{parameter1}, &label0, &tmp1, &label2, &tmp3);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5);
    }
    if (label2.is_used()) {
      ca_.Bind(&label2);
      ca_.Goto(&block6);
    }
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 42);
    if (((CodeStubAssembler(state_).IsIntPtrAbsWithOverflowSupported()))) {
      ca_.Goto(&block9);
    } else {
      ca_.Goto(&block10);
    }
  }

  TNode<Float64T> tmp4;
  TNode<Number> tmp5;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 58);
    tmp4 = CodeStubAssembler(state_).Float64Abs(TNode<Float64T>{tmp3.value()});
    tmp5 = Convert_Number_float64_0(state_, TNode<Float64T>{tmp4});
    CodeStubAssembler(state_).Return(tmp5);
  }

  TNode<Smi> tmp6;
  if (block9.is_used()) {
    ca_.Bind(&block9);
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 43);
    compiler::CodeAssemblerLabel label7(&ca_);
    tmp6 = CodeStubAssembler(state_).TrySmiAbs(TNode<Smi>{tmp1.value()}, &label7);
    ca_.Goto(&block12);
    if (label7.is_used()) {
      ca_.Bind(&label7);
      ca_.Goto(&block13);
    }
  }

  if (block13.is_used()) {
    ca_.Bind(&block13);
    ca_.Goto(&block8);
  }

  if (block12.is_used()) {
    ca_.Bind(&block12);
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 45);
    CodeStubAssembler(state_).Return(tmp6);
  }

  TNode<Smi> tmp8;
  TNode<BoolT> tmp9;
  if (block10.is_used()) {
    ca_.Bind(&block10);
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 47);
    tmp8 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp9 = CodeStubAssembler(state_).SmiLessThanOrEqual(TNode<Smi>{tmp8}, TNode<Smi>{tmp1.value()});
    ca_.Branch(tmp9, &block14, std::vector<compiler::Node*>{}, &block15, std::vector<compiler::Node*>{});
  }

  if (block14.is_used()) {
    ca_.Bind(&block14);
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 48);
    CodeStubAssembler(state_).Return(tmp1.value());
  }

  TNode<Smi> tmp10;
  TNode<Smi> tmp11;
  if (block15.is_used()) {
    ca_.Bind(&block15);
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 50);
    tmp10 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    compiler::CodeAssemblerLabel label12(&ca_);
    tmp11 = CodeStubAssembler(state_).TrySmiSub(TNode<Smi>{tmp10}, TNode<Smi>{tmp1.value()}, &label12);
    ca_.Goto(&block17);
    if (label12.is_used()) {
      ca_.Bind(&label12);
      ca_.Goto(&block18);
    }
  }

  if (block18.is_used()) {
    ca_.Bind(&block18);
    ca_.Goto(&block8);
  }

  if (block17.is_used()) {
    ca_.Bind(&block17);
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 51);
    CodeStubAssembler(state_).Return(tmp11);
  }

  TNode<Number> tmp13;
  if (block8.is_used()) {
    ca_.Bind(&block8);
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 55);
    tmp13 = CodeStubAssembler(state_).NumberConstant(0.0 - kSmiMinValue);
    CodeStubAssembler(state_).Return(tmp13);
  }
}

TF_BUILTIN(MathCeil, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kX);
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    compiler::TypedCodeAssemblerVariable<Smi> tmp1(&ca_);
    compiler::TypedCodeAssemblerVariable<Float64T> tmp3(&ca_);
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 67);
    compiler::CodeAssemblerLabel label0(&ca_);
    compiler::CodeAssemblerLabel label2(&ca_);
    ReduceToSmiOrFloat64_0(state_, TNode<Context>{parameter0}, TNode<Object>{parameter1}, &label0, &tmp1, &label2, &tmp3);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5);
    }
    if (label2.is_used()) {
      ca_.Bind(&label2);
      ca_.Goto(&block6);
    }
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 69);
    CodeStubAssembler(state_).Return(tmp1.value());
  }

  TNode<Float64T> tmp4;
  TNode<Number> tmp5;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 71);
    tmp4 = CodeStubAssembler(state_).Float64Ceil(TNode<Float64T>{tmp3.value()});
    tmp5 = Convert_Number_float64_0(state_, TNode<Float64T>{tmp4});
    CodeStubAssembler(state_).Return(tmp5);
  }
}

TF_BUILTIN(MathFloor, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kX);
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    compiler::TypedCodeAssemblerVariable<Smi> tmp1(&ca_);
    compiler::TypedCodeAssemblerVariable<Float64T> tmp3(&ca_);
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 80);
    compiler::CodeAssemblerLabel label0(&ca_);
    compiler::CodeAssemblerLabel label2(&ca_);
    ReduceToSmiOrFloat64_0(state_, TNode<Context>{parameter0}, TNode<Object>{parameter1}, &label0, &tmp1, &label2, &tmp3);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5);
    }
    if (label2.is_used()) {
      ca_.Bind(&label2);
      ca_.Goto(&block6);
    }
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 82);
    CodeStubAssembler(state_).Return(tmp1.value());
  }

  TNode<Float64T> tmp4;
  TNode<Number> tmp5;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 84);
    tmp4 = CodeStubAssembler(state_).Float64Floor(TNode<Float64T>{tmp3.value()});
    tmp5 = Convert_Number_float64_0(state_, TNode<Float64T>{tmp4});
    CodeStubAssembler(state_).Return(tmp5);
  }
}

TF_BUILTIN(MathRound, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kX);
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    compiler::TypedCodeAssemblerVariable<Smi> tmp1(&ca_);
    compiler::TypedCodeAssemblerVariable<Float64T> tmp3(&ca_);
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 93);
    compiler::CodeAssemblerLabel label0(&ca_);
    compiler::CodeAssemblerLabel label2(&ca_);
    ReduceToSmiOrFloat64_0(state_, TNode<Context>{parameter0}, TNode<Object>{parameter1}, &label0, &tmp1, &label2, &tmp3);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5);
    }
    if (label2.is_used()) {
      ca_.Bind(&label2);
      ca_.Goto(&block6);
    }
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 95);
    CodeStubAssembler(state_).Return(tmp1.value());
  }

  TNode<Float64T> tmp4;
  TNode<Number> tmp5;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 97);
    tmp4 = CodeStubAssembler(state_).Float64Round(TNode<Float64T>{tmp3.value()});
    tmp5 = Convert_Number_float64_0(state_, TNode<Float64T>{tmp4});
    CodeStubAssembler(state_).Return(tmp5);
  }
}

TF_BUILTIN(MathTrunc, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kX);
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    compiler::TypedCodeAssemblerVariable<Smi> tmp1(&ca_);
    compiler::TypedCodeAssemblerVariable<Float64T> tmp3(&ca_);
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 106);
    compiler::CodeAssemblerLabel label0(&ca_);
    compiler::CodeAssemblerLabel label2(&ca_);
    ReduceToSmiOrFloat64_0(state_, TNode<Context>{parameter0}, TNode<Object>{parameter1}, &label0, &tmp1, &label2, &tmp3);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5);
    }
    if (label2.is_used()) {
      ca_.Bind(&label2);
      ca_.Goto(&block6);
    }
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 108);
    CodeStubAssembler(state_).Return(tmp1.value());
  }

  TNode<Float64T> tmp4;
  TNode<Number> tmp5;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 110);
    tmp4 = CodeStubAssembler(state_).Float64Trunc(TNode<Float64T>{tmp3.value()});
    tmp5 = Convert_Number_float64_0(state_, TNode<Float64T>{tmp4});
    CodeStubAssembler(state_).Return(tmp5);
  }
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/math.tq?l=118&c=1
TNode<Number> MathPowImpl_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_base, TNode<Object> p_exponent) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Float64T> tmp0;
  TNode<Float64T> tmp1;
  TNode<Float64T> tmp2;
  TNode<Number> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 121);
    tmp0 = CodeStubAssembler(state_).TruncateTaggedToFloat64(TNode<Context>{p_context}, TNode<Object>{p_base});
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 122);
    tmp1 = CodeStubAssembler(state_).TruncateTaggedToFloat64(TNode<Context>{p_context}, TNode<Object>{p_exponent});
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 123);
    tmp2 = CodeStubAssembler(state_).Float64Pow(TNode<Float64T>{tmp0}, TNode<Float64T>{tmp1});
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 124);
    tmp3 = Convert_Number_float64_0(state_, TNode<Float64T>{tmp2});
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 118);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Number>{tmp3};
}

TF_BUILTIN(MathPow, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kBase);
  USE(parameter1);
  TNode<Object> parameter2 = UncheckedParameter<Object>(Descriptor::kExponent);
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Number> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 130);
    tmp0 = MathPowImpl_0(state_, TNode<Context>{parameter0}, TNode<Object>{parameter1}, TNode<Object>{parameter2});
    CodeStubAssembler(state_).Return(tmp0);
  }
}

TF_BUILTIN(MathMax, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Word32T> argc = UncheckedParameter<Word32T>(Descriptor::kJSActualArgumentsCount);
  TNode<IntPtrT> arguments_length(ChangeInt32ToIntPtr(UncheckedCast<Int32T>(argc)));
  TNode<RawPtrT> arguments_frame = UncheckedCast<RawPtrT>(LoadFramePointer());
  TorqueStructArguments torque_arguments(GetFrameArguments(arguments_frame, arguments_length, FrameArgumentsArgcType::kCountIncludesReceiver));
  CodeStubArguments arguments(this, torque_arguments);
  TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
  USE(parameter0);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Float64T, IntPtrT> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Float64T, IntPtrT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Float64T, IntPtrT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Float64T> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 137);
    tmp0 = FromConstexpr_float64_constexpr_float64_0(state_, -V8_INFINITY);
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 139);
    tmp1 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    ca_.Goto(&block3, tmp0, tmp1);
  }

  TNode<Float64T> phi_bb3_5;
  TNode<IntPtrT> phi_bb3_7;
  TNode<BoolT> tmp2;
  if (block3.is_used()) {
    ca_.Bind(&block3, &phi_bb3_5, &phi_bb3_7);
    tmp2 = CodeStubAssembler(state_).IntPtrLessThan(TNode<IntPtrT>{phi_bb3_7}, TNode<IntPtrT>{torque_arguments.length});
    ca_.Branch(tmp2, &block1, std::vector<compiler::Node*>{phi_bb3_5, phi_bb3_7}, &block2, std::vector<compiler::Node*>{phi_bb3_5, phi_bb3_7});
  }

  TNode<Float64T> phi_bb1_5;
  TNode<IntPtrT> phi_bb1_7;
  TNode<Object> tmp3;
  TNode<Float64T> tmp4;
  TNode<Float64T> tmp5;
  TNode<IntPtrT> tmp6;
  TNode<IntPtrT> tmp7;
  if (block1.is_used()) {
    ca_.Bind(&block1, &phi_bb1_5, &phi_bb1_7);
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 140);
    tmp3 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{torque_arguments.frame}, TNode<RawPtrT>{torque_arguments.base}, TNode<IntPtrT>{torque_arguments.length}, TNode<IntPtrT>{torque_arguments.actual_count}}, TNode<IntPtrT>{phi_bb1_7});
    tmp4 = CodeStubAssembler(state_).TruncateTaggedToFloat64(TNode<Context>{parameter0}, TNode<Object>{tmp3});
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 141);
    tmp5 = CodeStubAssembler(state_).Float64Max(TNode<Float64T>{phi_bb1_5}, TNode<Float64T>{tmp4});
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 139);
    tmp6 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp7 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb1_7}, TNode<IntPtrT>{tmp6});
    ca_.Goto(&block3, tmp5, tmp7);
  }

  TNode<Float64T> phi_bb2_5;
  TNode<IntPtrT> phi_bb2_7;
  TNode<Number> tmp8;
  if (block2.is_used()) {
    ca_.Bind(&block2, &phi_bb2_5, &phi_bb2_7);
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 143);
    tmp8 = Convert_Number_float64_0(state_, TNode<Float64T>{phi_bb2_5});
    arguments.PopAndReturn(tmp8);
  }
}

TF_BUILTIN(MathMin, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Word32T> argc = UncheckedParameter<Word32T>(Descriptor::kJSActualArgumentsCount);
  TNode<IntPtrT> arguments_length(ChangeInt32ToIntPtr(UncheckedCast<Int32T>(argc)));
  TNode<RawPtrT> arguments_frame = UncheckedCast<RawPtrT>(LoadFramePointer());
  TorqueStructArguments torque_arguments(GetFrameArguments(arguments_frame, arguments_length, FrameArgumentsArgcType::kCountIncludesReceiver));
  CodeStubArguments arguments(this, torque_arguments);
  TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
  USE(parameter0);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Float64T, IntPtrT> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Float64T, IntPtrT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Float64T, IntPtrT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Float64T> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 150);
    tmp0 = FromConstexpr_float64_constexpr_float64_0(state_, V8_INFINITY);
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 152);
    tmp1 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    ca_.Goto(&block3, tmp0, tmp1);
  }

  TNode<Float64T> phi_bb3_5;
  TNode<IntPtrT> phi_bb3_7;
  TNode<BoolT> tmp2;
  if (block3.is_used()) {
    ca_.Bind(&block3, &phi_bb3_5, &phi_bb3_7);
    tmp2 = CodeStubAssembler(state_).IntPtrLessThan(TNode<IntPtrT>{phi_bb3_7}, TNode<IntPtrT>{torque_arguments.length});
    ca_.Branch(tmp2, &block1, std::vector<compiler::Node*>{phi_bb3_5, phi_bb3_7}, &block2, std::vector<compiler::Node*>{phi_bb3_5, phi_bb3_7});
  }

  TNode<Float64T> phi_bb1_5;
  TNode<IntPtrT> phi_bb1_7;
  TNode<Object> tmp3;
  TNode<Float64T> tmp4;
  TNode<Float64T> tmp5;
  TNode<IntPtrT> tmp6;
  TNode<IntPtrT> tmp7;
  if (block1.is_used()) {
    ca_.Bind(&block1, &phi_bb1_5, &phi_bb1_7);
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 153);
    tmp3 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{torque_arguments.frame}, TNode<RawPtrT>{torque_arguments.base}, TNode<IntPtrT>{torque_arguments.length}, TNode<IntPtrT>{torque_arguments.actual_count}}, TNode<IntPtrT>{phi_bb1_7});
    tmp4 = CodeStubAssembler(state_).TruncateTaggedToFloat64(TNode<Context>{parameter0}, TNode<Object>{tmp3});
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 154);
    tmp5 = CodeStubAssembler(state_).Float64Min(TNode<Float64T>{phi_bb1_5}, TNode<Float64T>{tmp4});
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 152);
    tmp6 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp7 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb1_7}, TNode<IntPtrT>{tmp6});
    ca_.Goto(&block3, tmp5, tmp7);
  }

  TNode<Float64T> phi_bb2_5;
  TNode<IntPtrT> phi_bb2_7;
  TNode<Number> tmp8;
  if (block2.is_used()) {
    ca_.Bind(&block2, &phi_bb2_5, &phi_bb2_7);
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 156);
    tmp8 = Convert_Number_float64_0(state_, TNode<Float64T>{phi_bb2_5});
    arguments.PopAndReturn(tmp8);
  }
}

TF_BUILTIN(MathAcos, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kX);
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Number> tmp0;
  TNode<Float64T> tmp1;
  TNode<Float64T> tmp2;
  TNode<Number> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 164);
    tmp0 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context>{parameter0}, TNode<Object>{parameter1});
    tmp1 = Convert_float64_Number_0(state_, TNode<Number>{tmp0});
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 165);
    tmp2 = CodeStubAssembler(state_).Float64Acos(TNode<Float64T>{tmp1});
    tmp3 = Convert_Number_float64_0(state_, TNode<Float64T>{tmp2});
    CodeStubAssembler(state_).Return(tmp3);
  }
}

TF_BUILTIN(MathAcosh, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kX);
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Number> tmp0;
  TNode<Float64T> tmp1;
  TNode<Float64T> tmp2;
  TNode<Number> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 173);
    tmp0 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context>{parameter0}, TNode<Object>{parameter1});
    tmp1 = Convert_float64_Number_0(state_, TNode<Number>{tmp0});
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 174);
    tmp2 = CodeStubAssembler(state_).Float64Acosh(TNode<Float64T>{tmp1});
    tmp3 = Convert_Number_float64_0(state_, TNode<Float64T>{tmp2});
    CodeStubAssembler(state_).Return(tmp3);
  }
}

TF_BUILTIN(MathAsin, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kX);
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Number> tmp0;
  TNode<Float64T> tmp1;
  TNode<Float64T> tmp2;
  TNode<Number> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 182);
    tmp0 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context>{parameter0}, TNode<Object>{parameter1});
    tmp1 = Convert_float64_Number_0(state_, TNode<Number>{tmp0});
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 183);
    tmp2 = CodeStubAssembler(state_).Float64Asin(TNode<Float64T>{tmp1});
    tmp3 = Convert_Number_float64_0(state_, TNode<Float64T>{tmp2});
    CodeStubAssembler(state_).Return(tmp3);
  }
}

TF_BUILTIN(MathAsinh, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kX);
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Number> tmp0;
  TNode<Float64T> tmp1;
  TNode<Float64T> tmp2;
  TNode<Number> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 191);
    tmp0 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context>{parameter0}, TNode<Object>{parameter1});
    tmp1 = Convert_float64_Number_0(state_, TNode<Number>{tmp0});
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 192);
    tmp2 = CodeStubAssembler(state_).Float64Asinh(TNode<Float64T>{tmp1});
    tmp3 = Convert_Number_float64_0(state_, TNode<Float64T>{tmp2});
    CodeStubAssembler(state_).Return(tmp3);
  }
}

TF_BUILTIN(MathAtan, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kX);
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Number> tmp0;
  TNode<Float64T> tmp1;
  TNode<Float64T> tmp2;
  TNode<Number> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 200);
    tmp0 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context>{parameter0}, TNode<Object>{parameter1});
    tmp1 = Convert_float64_Number_0(state_, TNode<Number>{tmp0});
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 201);
    tmp2 = CodeStubAssembler(state_).Float64Atan(TNode<Float64T>{tmp1});
    tmp3 = Convert_Number_float64_0(state_, TNode<Float64T>{tmp2});
    CodeStubAssembler(state_).Return(tmp3);
  }
}

TF_BUILTIN(MathAtan2, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kY);
  USE(parameter1);
  TNode<Object> parameter2 = UncheckedParameter<Object>(Descriptor::kX);
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Number> tmp0;
  TNode<Float64T> tmp1;
  TNode<Number> tmp2;
  TNode<Float64T> tmp3;
  TNode<Float64T> tmp4;
  TNode<Number> tmp5;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 209);
    tmp0 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context>{parameter0}, TNode<Object>{parameter1});
    tmp1 = Convert_float64_Number_0(state_, TNode<Number>{tmp0});
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 210);
    tmp2 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context>{parameter0}, TNode<Object>{parameter2});
    tmp3 = Convert_float64_Number_0(state_, TNode<Number>{tmp2});
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 211);
    tmp4 = CodeStubAssembler(state_).Float64Atan2(TNode<Float64T>{tmp1}, TNode<Float64T>{tmp3});
    tmp5 = Convert_Number_float64_0(state_, TNode<Float64T>{tmp4});
    CodeStubAssembler(state_).Return(tmp5);
  }
}

TF_BUILTIN(MathAtanh, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kX);
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Number> tmp0;
  TNode<Float64T> tmp1;
  TNode<Float64T> tmp2;
  TNode<Number> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 219);
    tmp0 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context>{parameter0}, TNode<Object>{parameter1});
    tmp1 = Convert_float64_Number_0(state_, TNode<Number>{tmp0});
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 220);
    tmp2 = CodeStubAssembler(state_).Float64Atanh(TNode<Float64T>{tmp1});
    tmp3 = Convert_Number_float64_0(state_, TNode<Float64T>{tmp2});
    CodeStubAssembler(state_).Return(tmp3);
  }
}

TF_BUILTIN(MathCbrt, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kX);
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Number> tmp0;
  TNode<Float64T> tmp1;
  TNode<Float64T> tmp2;
  TNode<Number> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 228);
    tmp0 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context>{parameter0}, TNode<Object>{parameter1});
    tmp1 = Convert_float64_Number_0(state_, TNode<Number>{tmp0});
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 229);
    tmp2 = CodeStubAssembler(state_).Float64Cbrt(TNode<Float64T>{tmp1});
    tmp3 = Convert_Number_float64_0(state_, TNode<Float64T>{tmp2});
    CodeStubAssembler(state_).Return(tmp3);
  }
}

TF_BUILTIN(MathClz32, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kX);
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Number> tmp0;
  TNode<Int32T> tmp1;
  TNode<Int32T> tmp2;
  TNode<Number> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 237);
    tmp0 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context>{parameter0}, TNode<Object>{parameter1});
    tmp1 = Convert_int32_Number_0(state_, TNode<Number>{tmp0});
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 238);
    tmp2 = CodeStubAssembler(state_).Word32Clz(TNode<Int32T>{tmp1});
    tmp3 = Convert_Number_int32_0(state_, TNode<Int32T>{tmp2});
    CodeStubAssembler(state_).Return(tmp3);
  }
}

TF_BUILTIN(MathCos, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kX);
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Number> tmp0;
  TNode<Float64T> tmp1;
  TNode<Float64T> tmp2;
  TNode<Number> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 246);
    tmp0 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context>{parameter0}, TNode<Object>{parameter1});
    tmp1 = Convert_float64_Number_0(state_, TNode<Number>{tmp0});
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 247);
    tmp2 = CodeStubAssembler(state_).Float64Cos(TNode<Float64T>{tmp1});
    tmp3 = Convert_Number_float64_0(state_, TNode<Float64T>{tmp2});
    CodeStubAssembler(state_).Return(tmp3);
  }
}

TF_BUILTIN(MathCosh, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kX);
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Number> tmp0;
  TNode<Float64T> tmp1;
  TNode<Float64T> tmp2;
  TNode<Number> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 255);
    tmp0 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context>{parameter0}, TNode<Object>{parameter1});
    tmp1 = Convert_float64_Number_0(state_, TNode<Number>{tmp0});
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 256);
    tmp2 = CodeStubAssembler(state_).Float64Cosh(TNode<Float64T>{tmp1});
    tmp3 = Convert_Number_float64_0(state_, TNode<Float64T>{tmp2});
    CodeStubAssembler(state_).Return(tmp3);
  }
}

TF_BUILTIN(MathExp, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kX);
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Number> tmp0;
  TNode<Float64T> tmp1;
  TNode<Float64T> tmp2;
  TNode<Number> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 264);
    tmp0 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context>{parameter0}, TNode<Object>{parameter1});
    tmp1 = Convert_float64_Number_0(state_, TNode<Number>{tmp0});
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 265);
    tmp2 = CodeStubAssembler(state_).Float64Exp(TNode<Float64T>{tmp1});
    tmp3 = Convert_Number_float64_0(state_, TNode<Float64T>{tmp2});
    CodeStubAssembler(state_).Return(tmp3);
  }
}

TF_BUILTIN(MathExpm1, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kX);
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Number> tmp0;
  TNode<Float64T> tmp1;
  TNode<Float64T> tmp2;
  TNode<Number> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 273);
    tmp0 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context>{parameter0}, TNode<Object>{parameter1});
    tmp1 = Convert_float64_Number_0(state_, TNode<Number>{tmp0});
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 274);
    tmp2 = CodeStubAssembler(state_).Float64Expm1(TNode<Float64T>{tmp1});
    tmp3 = Convert_Number_float64_0(state_, TNode<Float64T>{tmp2});
    CodeStubAssembler(state_).Return(tmp3);
  }
}

TF_BUILTIN(MathFround, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kX);
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Number> tmp0;
  TNode<Float32T> tmp1;
  TNode<Float64T> tmp2;
  TNode<Number> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 280);
    tmp0 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context>{parameter0}, TNode<Object>{parameter1});
    tmp1 = Convert_float32_Number_0(state_, TNode<Number>{tmp0});
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 281);
    tmp2 = Convert_float64_float32_0(state_, TNode<Float32T>{tmp1});
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 282);
    tmp3 = Convert_Number_float64_0(state_, TNode<Float64T>{tmp2});
    CodeStubAssembler(state_).Return(tmp3);
  }
}

TF_BUILTIN(MathImul, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kX);
  USE(parameter1);
  TNode<Object> parameter2 = UncheckedParameter<Object>(Descriptor::kY);
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Number> tmp0;
  TNode<Int32T> tmp1;
  TNode<Number> tmp2;
  TNode<Int32T> tmp3;
  TNode<Int32T> tmp4;
  TNode<Number> tmp5;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 288);
    tmp0 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context>{parameter0}, TNode<Object>{parameter1});
    tmp1 = Convert_int32_Number_0(state_, TNode<Number>{tmp0});
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 289);
    tmp2 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context>{parameter0}, TNode<Object>{parameter2});
    tmp3 = Convert_int32_Number_0(state_, TNode<Number>{tmp2});
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 290);
    tmp4 = CodeStubAssembler(state_).Int32Mul(TNode<Int32T>{tmp1}, TNode<Int32T>{tmp3});
    tmp5 = Convert_Number_int32_0(state_, TNode<Int32T>{tmp4});
    CodeStubAssembler(state_).Return(tmp5);
  }
}

TF_BUILTIN(MathLog, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kX);
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Number> tmp0;
  TNode<Float64T> tmp1;
  TNode<Float64T> tmp2;
  TNode<Number> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 298);
    tmp0 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context>{parameter0}, TNode<Object>{parameter1});
    tmp1 = Convert_float64_Number_0(state_, TNode<Number>{tmp0});
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 299);
    tmp2 = CodeStubAssembler(state_).Float64Log(TNode<Float64T>{tmp1});
    tmp3 = Convert_Number_float64_0(state_, TNode<Float64T>{tmp2});
    CodeStubAssembler(state_).Return(tmp3);
  }
}

TF_BUILTIN(MathLog1p, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kX);
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Number> tmp0;
  TNode<Float64T> tmp1;
  TNode<Float64T> tmp2;
  TNode<Number> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 307);
    tmp0 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context>{parameter0}, TNode<Object>{parameter1});
    tmp1 = Convert_float64_Number_0(state_, TNode<Number>{tmp0});
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 308);
    tmp2 = CodeStubAssembler(state_).Float64Log1p(TNode<Float64T>{tmp1});
    tmp3 = Convert_Number_float64_0(state_, TNode<Float64T>{tmp2});
    CodeStubAssembler(state_).Return(tmp3);
  }
}

TF_BUILTIN(MathLog10, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kX);
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Number> tmp0;
  TNode<Float64T> tmp1;
  TNode<Float64T> tmp2;
  TNode<Number> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 316);
    tmp0 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context>{parameter0}, TNode<Object>{parameter1});
    tmp1 = Convert_float64_Number_0(state_, TNode<Number>{tmp0});
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 317);
    tmp2 = CodeStubAssembler(state_).Float64Log10(TNode<Float64T>{tmp1});
    tmp3 = Convert_Number_float64_0(state_, TNode<Float64T>{tmp2});
    CodeStubAssembler(state_).Return(tmp3);
  }
}

TF_BUILTIN(MathLog2, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kX);
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Number> tmp0;
  TNode<Float64T> tmp1;
  TNode<Float64T> tmp2;
  TNode<Number> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 325);
    tmp0 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context>{parameter0}, TNode<Object>{parameter1});
    tmp1 = Convert_float64_Number_0(state_, TNode<Number>{tmp0});
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 326);
    tmp2 = CodeStubAssembler(state_).Float64Log2(TNode<Float64T>{tmp1});
    tmp3 = Convert_Number_float64_0(state_, TNode<Float64T>{tmp2});
    CodeStubAssembler(state_).Return(tmp3);
  }
}

TF_BUILTIN(MathSin, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kX);
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Number> tmp0;
  TNode<Float64T> tmp1;
  TNode<Float64T> tmp2;
  TNode<Number> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 334);
    tmp0 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context>{parameter0}, TNode<Object>{parameter1});
    tmp1 = Convert_float64_Number_0(state_, TNode<Number>{tmp0});
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 335);
    tmp2 = CodeStubAssembler(state_).Float64Sin(TNode<Float64T>{tmp1});
    tmp3 = Convert_Number_float64_0(state_, TNode<Float64T>{tmp2});
    CodeStubAssembler(state_).Return(tmp3);
  }
}

TF_BUILTIN(MathSign, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kX);
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Number> tmp0;
  TNode<Float64T> tmp1;
  TNode<Float64T> tmp2;
  TNode<BoolT> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 341);
    tmp0 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context>{parameter0}, TNode<Object>{parameter1});
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 342);
    tmp1 = Convert_float64_Number_0(state_, TNode<Number>{tmp0});
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 344);
    tmp2 = FromConstexpr_float64_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp3 = CodeStubAssembler(state_).Float64LessThan(TNode<Float64T>{tmp1}, TNode<Float64T>{tmp2});
    ca_.Branch(tmp3, &block1, std::vector<compiler::Node*>{}, &block2, std::vector<compiler::Node*>{});
  }

  TNode<Number> tmp4;
  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 345);
    tmp4 = FromConstexpr_Number_constexpr_IntegerLiteral_0(state_, IntegerLiteral(true, 0x1ull));
    CodeStubAssembler(state_).Return(tmp4);
  }

  TNode<Float64T> tmp5;
  TNode<BoolT> tmp6;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 346);
    tmp5 = FromConstexpr_float64_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp6 = CodeStubAssembler(state_).Float64GreaterThan(TNode<Float64T>{tmp1}, TNode<Float64T>{tmp5});
    ca_.Branch(tmp6, &block4, std::vector<compiler::Node*>{}, &block5, std::vector<compiler::Node*>{});
  }

  TNode<Number> tmp7;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 347);
    tmp7 = FromConstexpr_Number_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    CodeStubAssembler(state_).Return(tmp7);
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 349);
    CodeStubAssembler(state_).Return(tmp0);
  }
}

TF_BUILTIN(MathSinh, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kX);
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Number> tmp0;
  TNode<Float64T> tmp1;
  TNode<Float64T> tmp2;
  TNode<Number> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 358);
    tmp0 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context>{parameter0}, TNode<Object>{parameter1});
    tmp1 = Convert_float64_Number_0(state_, TNode<Number>{tmp0});
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 359);
    tmp2 = CodeStubAssembler(state_).Float64Sinh(TNode<Float64T>{tmp1});
    tmp3 = Convert_Number_float64_0(state_, TNode<Float64T>{tmp2});
    CodeStubAssembler(state_).Return(tmp3);
  }
}

TF_BUILTIN(MathSqrt, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kX);
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Number> tmp0;
  TNode<Float64T> tmp1;
  TNode<Float64T> tmp2;
  TNode<Number> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 367);
    tmp0 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context>{parameter0}, TNode<Object>{parameter1});
    tmp1 = Convert_float64_Number_0(state_, TNode<Number>{tmp0});
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 368);
    tmp2 = CodeStubAssembler(state_).Float64Sqrt(TNode<Float64T>{tmp1});
    tmp3 = Convert_Number_float64_0(state_, TNode<Float64T>{tmp2});
    CodeStubAssembler(state_).Return(tmp3);
  }
}

TF_BUILTIN(MathTan, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kX);
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Number> tmp0;
  TNode<Float64T> tmp1;
  TNode<Float64T> tmp2;
  TNode<Number> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 376);
    tmp0 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context>{parameter0}, TNode<Object>{parameter1});
    tmp1 = Convert_float64_Number_0(state_, TNode<Number>{tmp0});
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 377);
    tmp2 = CodeStubAssembler(state_).Float64Tan(TNode<Float64T>{tmp1});
    tmp3 = Convert_Number_float64_0(state_, TNode<Float64T>{tmp2});
    CodeStubAssembler(state_).Return(tmp3);
  }
}

TF_BUILTIN(MathTanh, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kX);
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Number> tmp0;
  TNode<Float64T> tmp1;
  TNode<Float64T> tmp2;
  TNode<Number> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 385);
    tmp0 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context>{parameter0}, TNode<Object>{parameter1});
    tmp1 = Convert_float64_Number_0(state_, TNode<Number>{tmp0});
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 386);
    tmp2 = CodeStubAssembler(state_).Float64Tanh(TNode<Float64T>{tmp1});
    tmp3 = Convert_Number_float64_0(state_, TNode<Float64T>{tmp2});
    CodeStubAssembler(state_).Return(tmp3);
  }
}

TF_BUILTIN(MathHypot, CodeStubAssembler) {
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
  compiler::CodeAssemblerParameterizedLabel<BoolT, Float64T, IntPtrT> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, Float64T, IntPtrT> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, Float64T, IntPtrT> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, Float64T, IntPtrT> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, Float64T, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, Float64T, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, Float64T, IntPtrT> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, Float64T, IntPtrT> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, Float64T, IntPtrT> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, Float64T, IntPtrT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, Float64T> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, Float64T> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, Float64T> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, Float64T> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, Float64T> block26(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, Float64T> block27(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, Float64T> block29(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, Float64T> block28(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, Float64T, Float64T, Float64T, IntPtrT> block32(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, Float64T, Float64T, Float64T, IntPtrT> block30(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, Float64T, Float64T, Float64T, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block38(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, Float64T, Float64T, Float64T, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block39(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, Float64T, Float64T, Float64T, IntPtrT, IntPtrT, IntPtrT> block44(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, Float64T, Float64T, Float64T, IntPtrT, IntPtrT, IntPtrT> block43(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, Float64T, Float64T, Float64T, IntPtrT> block31(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<BoolT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 394);
    tmp0 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp1 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{torque_arguments.length}, TNode<IntPtrT>{tmp0});
    ca_.Branch(tmp1, &block1, std::vector<compiler::Node*>{}, &block2, std::vector<compiler::Node*>{});
  }

  TNode<Number> tmp2;
  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 395);
    tmp2 = FromConstexpr_Number_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    arguments.PopAndReturn(tmp2);
  }

  TNode<FixedDoubleArray> tmp3;
  TNode<BoolT> tmp4;
  TNode<Float64T> tmp5;
  TNode<IntPtrT> tmp6;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 397);
    tmp3 = CodeStubAssembler(state_).AllocateZeroedFixedDoubleArray(TNode<IntPtrT>{torque_arguments.length});
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 398);
    tmp4 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 399);
    tmp5 = FromConstexpr_float64_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 400);
    tmp6 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    ca_.Goto(&block5, tmp4, tmp5, tmp6);
  }

  TNode<BoolT> phi_bb5_8;
  TNode<Float64T> phi_bb5_9;
  TNode<IntPtrT> phi_bb5_10;
  TNode<BoolT> tmp7;
  if (block5.is_used()) {
    ca_.Bind(&block5, &phi_bb5_8, &phi_bb5_9, &phi_bb5_10);
    tmp7 = CodeStubAssembler(state_).IntPtrLessThan(TNode<IntPtrT>{phi_bb5_10}, TNode<IntPtrT>{torque_arguments.length});
    ca_.Branch(tmp7, &block3, std::vector<compiler::Node*>{phi_bb5_8, phi_bb5_9, phi_bb5_10}, &block4, std::vector<compiler::Node*>{phi_bb5_8, phi_bb5_9, phi_bb5_10});
  }

  TNode<BoolT> phi_bb3_8;
  TNode<Float64T> phi_bb3_9;
  TNode<IntPtrT> phi_bb3_10;
  TNode<Object> tmp8;
  TNode<Number> tmp9;
  TNode<Float64T> tmp10;
  TNode<BoolT> tmp11;
  if (block3.is_used()) {
    ca_.Bind(&block3, &phi_bb3_8, &phi_bb3_9, &phi_bb3_10);
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 401);
    tmp8 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{torque_arguments.frame}, TNode<RawPtrT>{torque_arguments.base}, TNode<IntPtrT>{torque_arguments.length}, TNode<IntPtrT>{torque_arguments.actual_count}}, TNode<IntPtrT>{phi_bb3_10});
    tmp9 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context>{parameter0}, TNode<Object>{tmp8});
    tmp10 = Convert_float64_Number_0(state_, TNode<Number>{tmp9});
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 402);
    tmp11 = Float64IsNaN_0(state_, TNode<Float64T>{tmp10});
    ca_.Branch(tmp11, &block7, std::vector<compiler::Node*>{phi_bb3_8, phi_bb3_9, phi_bb3_10}, &block8, std::vector<compiler::Node*>{phi_bb3_8, phi_bb3_9, phi_bb3_10});
  }

  TNode<BoolT> phi_bb7_8;
  TNode<Float64T> phi_bb7_9;
  TNode<IntPtrT> phi_bb7_10;
  TNode<BoolT> tmp12;
  if (block7.is_used()) {
    ca_.Bind(&block7, &phi_bb7_8, &phi_bb7_9, &phi_bb7_10);
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 403);
    tmp12 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 402);
    ca_.Goto(&block9, tmp12, phi_bb7_9, phi_bb7_10);
  }

  TNode<BoolT> phi_bb8_8;
  TNode<Float64T> phi_bb8_9;
  TNode<IntPtrT> phi_bb8_10;
  TNode<Float64T> tmp13;
  TNode<Object> tmp14;
  TNode<IntPtrT> tmp15;
  TNode<IntPtrT> tmp16;
  TNode<UintPtrT> tmp17;
  TNode<UintPtrT> tmp18;
  TNode<BoolT> tmp19;
  if (block8.is_used()) {
    ca_.Bind(&block8, &phi_bb8_8, &phi_bb8_9, &phi_bb8_10);
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 405);
    tmp13 = CodeStubAssembler(state_).Float64Abs(TNode<Float64T>{tmp10});
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 406);
    std::tie(tmp14, tmp15, tmp16) = FieldSliceFixedDoubleArrayFloats_0(state_, TNode<FixedDoubleArray>{tmp3}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 89);
    tmp17 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{phi_bb8_10});
    tmp18 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp16});
    tmp19 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp17}, TNode<UintPtrT>{tmp18});
    ca_.Branch(tmp19, &block14, std::vector<compiler::Node*>{phi_bb8_8, phi_bb8_9, phi_bb8_10, phi_bb8_10, phi_bb8_10, phi_bb8_10, phi_bb8_10}, &block15, std::vector<compiler::Node*>{phi_bb8_8, phi_bb8_9, phi_bb8_10, phi_bb8_10, phi_bb8_10, phi_bb8_10, phi_bb8_10});
  }

  TNode<BoolT> phi_bb14_8;
  TNode<Float64T> phi_bb14_9;
  TNode<IntPtrT> phi_bb14_10;
  TNode<IntPtrT> phi_bb14_17;
  TNode<IntPtrT> phi_bb14_18;
  TNode<IntPtrT> phi_bb14_22;
  TNode<IntPtrT> phi_bb14_23;
  TNode<IntPtrT> tmp20;
  TNode<IntPtrT> tmp21;
  TNode<Object> tmp22;
  TNode<IntPtrT> tmp23;
  TNode<BoolT> tmp24;
  TNode<Float64T> tmp25;
  TNode<BoolT> tmp26;
  if (block14.is_used()) {
    ca_.Bind(&block14, &phi_bb14_8, &phi_bb14_9, &phi_bb14_10, &phi_bb14_17, &phi_bb14_18, &phi_bb14_22, &phi_bb14_23);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 97);
    tmp20 = TimesSizeOf_float64_or_hole_0(state_, TNode<IntPtrT>{phi_bb14_23});
    tmp21 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp15}, TNode<IntPtrT>{tmp20});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 96);
    std::tie(tmp22, tmp23) = NewReference_float64_or_hole_0(state_, TNode<Object>{tmp14}, TNode<IntPtrT>{tmp21}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 406);
    std::tie(tmp24, tmp25) = Convert_float64_or_hole_float64_0(state_, TNode<Float64T>{tmp13}).Flatten();
    StoreFloat64OrHole_0(state_, TorqueStructReference_float64_or_hole_0{TNode<Object>{tmp22}, TNode<IntPtrT>{tmp23}, TorqueStructUnsafe_0{}}, TorqueStructfloat64_or_hole_0{TNode<BoolT>{tmp24}, TNode<Float64T>{tmp25}});
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 407);
    tmp26 = CodeStubAssembler(state_).Float64GreaterThan(TNode<Float64T>{tmp13}, TNode<Float64T>{phi_bb14_9});
    ca_.Branch(tmp26, &block18, std::vector<compiler::Node*>{phi_bb14_8, phi_bb14_9, phi_bb14_10}, &block19, std::vector<compiler::Node*>{phi_bb14_8, phi_bb14_9, phi_bb14_10});
  }

  TNode<BoolT> phi_bb15_8;
  TNode<Float64T> phi_bb15_9;
  TNode<IntPtrT> phi_bb15_10;
  TNode<IntPtrT> phi_bb15_17;
  TNode<IntPtrT> phi_bb15_18;
  TNode<IntPtrT> phi_bb15_22;
  TNode<IntPtrT> phi_bb15_23;
  if (block15.is_used()) {
    ca_.Bind(&block15, &phi_bb15_8, &phi_bb15_9, &phi_bb15_10, &phi_bb15_17, &phi_bb15_18, &phi_bb15_22, &phi_bb15_23);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 101);
    CodeStubAssembler(state_).PrintErr("halting because of unreachable code at src/builtins/torque-internal.tq:101:45");
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<BoolT> phi_bb18_8;
  TNode<Float64T> phi_bb18_9;
  TNode<IntPtrT> phi_bb18_10;
  if (block18.is_used()) {
    ca_.Bind(&block18, &phi_bb18_8, &phi_bb18_9, &phi_bb18_10);
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 407);
    ca_.Goto(&block19, phi_bb18_8, tmp13, phi_bb18_10);
  }

  TNode<BoolT> phi_bb19_8;
  TNode<Float64T> phi_bb19_9;
  TNode<IntPtrT> phi_bb19_10;
  if (block19.is_used()) {
    ca_.Bind(&block19, &phi_bb19_8, &phi_bb19_9, &phi_bb19_10);
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 402);
    ca_.Goto(&block9, phi_bb19_8, phi_bb19_9, phi_bb19_10);
  }

  TNode<BoolT> phi_bb9_8;
  TNode<Float64T> phi_bb9_9;
  TNode<IntPtrT> phi_bb9_10;
  TNode<IntPtrT> tmp27;
  TNode<IntPtrT> tmp28;
  if (block9.is_used()) {
    ca_.Bind(&block9, &phi_bb9_8, &phi_bb9_9, &phi_bb9_10);
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 400);
    tmp27 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp28 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb9_10}, TNode<IntPtrT>{tmp27});
    ca_.Goto(&block5, phi_bb9_8, phi_bb9_9, tmp28);
  }

  TNode<BoolT> phi_bb4_8;
  TNode<Float64T> phi_bb4_9;
  TNode<IntPtrT> phi_bb4_10;
  TNode<Float64T> tmp29;
  TNode<BoolT> tmp30;
  if (block4.is_used()) {
    ca_.Bind(&block4, &phi_bb4_8, &phi_bb4_9, &phi_bb4_10);
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 412);
    tmp29 = FromConstexpr_float64_constexpr_float64_0(state_, V8_INFINITY);
    tmp30 = CodeStubAssembler(state_).Float64Equal(TNode<Float64T>{phi_bb4_9}, TNode<Float64T>{tmp29});
    ca_.Branch(tmp30, &block20, std::vector<compiler::Node*>{phi_bb4_8, phi_bb4_9}, &block21, std::vector<compiler::Node*>{phi_bb4_8, phi_bb4_9});
  }

  TNode<BoolT> phi_bb20_8;
  TNode<Float64T> phi_bb20_9;
  TNode<Number> tmp31;
  if (block20.is_used()) {
    ca_.Bind(&block20, &phi_bb20_8, &phi_bb20_9);
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 413);
    tmp31 = FromConstexpr_Number_constexpr_float64_0(state_, V8_INFINITY);
    arguments.PopAndReturn(tmp31);
  }

  TNode<BoolT> phi_bb21_8;
  TNode<Float64T> phi_bb21_9;
  if (block21.is_used()) {
    ca_.Bind(&block21, &phi_bb21_8, &phi_bb21_9);
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 414);
    ca_.Branch(phi_bb21_8, &block23, std::vector<compiler::Node*>{phi_bb21_8, phi_bb21_9}, &block24, std::vector<compiler::Node*>{phi_bb21_8, phi_bb21_9});
  }

  TNode<BoolT> phi_bb23_8;
  TNode<Float64T> phi_bb23_9;
  TNode<HeapNumber> tmp32;
  if (block23.is_used()) {
    ca_.Bind(&block23, &phi_bb23_8, &phi_bb23_9);
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 415);
    tmp32 = kNaN_0(state_);
    arguments.PopAndReturn(tmp32);
  }

  TNode<BoolT> phi_bb24_8;
  TNode<Float64T> phi_bb24_9;
  TNode<Float64T> tmp33;
  TNode<BoolT> tmp34;
  if (block24.is_used()) {
    ca_.Bind(&block24, &phi_bb24_8, &phi_bb24_9);
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 416);
    tmp33 = FromConstexpr_float64_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp34 = CodeStubAssembler(state_).Float64Equal(TNode<Float64T>{phi_bb24_9}, TNode<Float64T>{tmp33});
    ca_.Branch(tmp34, &block26, std::vector<compiler::Node*>{phi_bb24_8, phi_bb24_9}, &block27, std::vector<compiler::Node*>{phi_bb24_8, phi_bb24_9});
  }

  TNode<BoolT> phi_bb26_8;
  TNode<Float64T> phi_bb26_9;
  TNode<Number> tmp35;
  if (block26.is_used()) {
    ca_.Bind(&block26, &phi_bb26_8, &phi_bb26_9);
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 417);
    tmp35 = FromConstexpr_Number_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    arguments.PopAndReturn(tmp35);
  }

  TNode<BoolT> phi_bb27_8;
  TNode<Float64T> phi_bb27_9;
  TNode<Float64T> tmp36;
  TNode<BoolT> tmp37;
  if (block27.is_used()) {
    ca_.Bind(&block27, &phi_bb27_8, &phi_bb27_9);
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 419);
    tmp36 = FromConstexpr_float64_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp37 = CodeStubAssembler(state_).Float64GreaterThan(TNode<Float64T>{phi_bb27_9}, TNode<Float64T>{tmp36});
    ca_.Branch(tmp37, &block28, std::vector<compiler::Node*>{phi_bb27_8, phi_bb27_9}, &block29, std::vector<compiler::Node*>{phi_bb27_8, phi_bb27_9});
  }

  TNode<BoolT> phi_bb29_8;
  TNode<Float64T> phi_bb29_9;
  if (block29.is_used()) {
    ca_.Bind(&block29, &phi_bb29_8, &phi_bb29_9);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/math.tq", 419});
      CodeStubAssembler(state_).FailAssert("Torque assert 'max > 0' failed", pos_stack);
    }
  }

  TNode<BoolT> phi_bb28_8;
  TNode<Float64T> phi_bb28_9;
  TNode<Float64T> tmp38;
  TNode<Float64T> tmp39;
  TNode<IntPtrT> tmp40;
  if (block28.is_used()) {
    ca_.Bind(&block28, &phi_bb28_8, &phi_bb28_9);
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 423);
    tmp38 = FromConstexpr_float64_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 424);
    tmp39 = FromConstexpr_float64_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 425);
    tmp40 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    ca_.Goto(&block32, phi_bb28_8, phi_bb28_9, tmp38, tmp39, tmp40);
  }

  TNode<BoolT> phi_bb32_8;
  TNode<Float64T> phi_bb32_9;
  TNode<Float64T> phi_bb32_10;
  TNode<Float64T> phi_bb32_11;
  TNode<IntPtrT> phi_bb32_12;
  TNode<BoolT> tmp41;
  if (block32.is_used()) {
    ca_.Bind(&block32, &phi_bb32_8, &phi_bb32_9, &phi_bb32_10, &phi_bb32_11, &phi_bb32_12);
    tmp41 = CodeStubAssembler(state_).IntPtrLessThan(TNode<IntPtrT>{phi_bb32_12}, TNode<IntPtrT>{torque_arguments.length});
    ca_.Branch(tmp41, &block30, std::vector<compiler::Node*>{phi_bb32_8, phi_bb32_9, phi_bb32_10, phi_bb32_11, phi_bb32_12}, &block31, std::vector<compiler::Node*>{phi_bb32_8, phi_bb32_9, phi_bb32_10, phi_bb32_11, phi_bb32_12});
  }

  TNode<BoolT> phi_bb30_8;
  TNode<Float64T> phi_bb30_9;
  TNode<Float64T> phi_bb30_10;
  TNode<Float64T> phi_bb30_11;
  TNode<IntPtrT> phi_bb30_12;
  TNode<Object> tmp42;
  TNode<IntPtrT> tmp43;
  TNode<IntPtrT> tmp44;
  TNode<UintPtrT> tmp45;
  TNode<UintPtrT> tmp46;
  TNode<BoolT> tmp47;
  if (block30.is_used()) {
    ca_.Bind(&block30, &phi_bb30_8, &phi_bb30_9, &phi_bb30_10, &phi_bb30_11, &phi_bb30_12);
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 426);
    std::tie(tmp42, tmp43, tmp44) = FieldSliceFixedDoubleArrayFloats_0(state_, TNode<FixedDoubleArray>{tmp3}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 89);
    tmp45 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{phi_bb30_12});
    tmp46 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp44});
    tmp47 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp45}, TNode<UintPtrT>{tmp46});
    ca_.Branch(tmp47, &block38, std::vector<compiler::Node*>{phi_bb30_8, phi_bb30_9, phi_bb30_10, phi_bb30_11, phi_bb30_12, phi_bb30_12, phi_bb30_12, phi_bb30_12, phi_bb30_12}, &block39, std::vector<compiler::Node*>{phi_bb30_8, phi_bb30_9, phi_bb30_10, phi_bb30_11, phi_bb30_12, phi_bb30_12, phi_bb30_12, phi_bb30_12, phi_bb30_12});
  }

  TNode<BoolT> phi_bb38_8;
  TNode<Float64T> phi_bb38_9;
  TNode<Float64T> phi_bb38_10;
  TNode<Float64T> phi_bb38_11;
  TNode<IntPtrT> phi_bb38_12;
  TNode<IntPtrT> phi_bb38_17;
  TNode<IntPtrT> phi_bb38_18;
  TNode<IntPtrT> phi_bb38_22;
  TNode<IntPtrT> phi_bb38_23;
  TNode<IntPtrT> tmp48;
  TNode<IntPtrT> tmp49;
  TNode<Object> tmp50;
  TNode<IntPtrT> tmp51;
  TNode<BoolT> tmp52;
  TNode<Float64T> tmp53;
  TNode<BoolT> tmp54;
  if (block38.is_used()) {
    ca_.Bind(&block38, &phi_bb38_8, &phi_bb38_9, &phi_bb38_10, &phi_bb38_11, &phi_bb38_12, &phi_bb38_17, &phi_bb38_18, &phi_bb38_22, &phi_bb38_23);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 97);
    tmp48 = TimesSizeOf_float64_or_hole_0(state_, TNode<IntPtrT>{phi_bb38_23});
    tmp49 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp43}, TNode<IntPtrT>{tmp48});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 96);
    std::tie(tmp50, tmp51) = NewReference_float64_or_hole_0(state_, TNode<Object>{tmp42}, TNode<IntPtrT>{tmp49}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 426);
    std::tie(tmp52, tmp53) = LoadFloat64OrHole_0(state_, TorqueStructReference_float64_or_hole_0{TNode<Object>{tmp50}, TNode<IntPtrT>{tmp51}, TorqueStructUnsafe_0{}}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/base.tq", 167);
    tmp54 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp52});
    ca_.Branch(tmp54, &block43, std::vector<compiler::Node*>{phi_bb38_8, phi_bb38_9, phi_bb38_10, phi_bb38_11, phi_bb38_12, phi_bb38_17, phi_bb38_18}, &block44, std::vector<compiler::Node*>{phi_bb38_8, phi_bb38_9, phi_bb38_10, phi_bb38_11, phi_bb38_12, phi_bb38_17, phi_bb38_18});
  }

  TNode<BoolT> phi_bb39_8;
  TNode<Float64T> phi_bb39_9;
  TNode<Float64T> phi_bb39_10;
  TNode<Float64T> phi_bb39_11;
  TNode<IntPtrT> phi_bb39_12;
  TNode<IntPtrT> phi_bb39_17;
  TNode<IntPtrT> phi_bb39_18;
  TNode<IntPtrT> phi_bb39_22;
  TNode<IntPtrT> phi_bb39_23;
  if (block39.is_used()) {
    ca_.Bind(&block39, &phi_bb39_8, &phi_bb39_9, &phi_bb39_10, &phi_bb39_11, &phi_bb39_12, &phi_bb39_17, &phi_bb39_18, &phi_bb39_22, &phi_bb39_23);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 101);
    CodeStubAssembler(state_).PrintErr("halting because of unreachable code at src/builtins/torque-internal.tq:101:45");
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<BoolT> phi_bb44_8;
  TNode<Float64T> phi_bb44_9;
  TNode<Float64T> phi_bb44_10;
  TNode<Float64T> phi_bb44_11;
  TNode<IntPtrT> phi_bb44_12;
  TNode<IntPtrT> phi_bb44_17;
  TNode<IntPtrT> phi_bb44_18;
  if (block44.is_used()) {
    ca_.Bind(&block44, &phi_bb44_8, &phi_bb44_9, &phi_bb44_10, &phi_bb44_11, &phi_bb44_12, &phi_bb44_17, &phi_bb44_18);
    ca_.SetSourcePosition("../../../src/builtins/base.tq", 167);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/base.tq", 167});
      CodeStubAssembler(state_).FailAssert("Torque assert '!this.is_hole' failed", pos_stack);
    }
  }

  TNode<BoolT> phi_bb43_8;
  TNode<Float64T> phi_bb43_9;
  TNode<Float64T> phi_bb43_10;
  TNode<Float64T> phi_bb43_11;
  TNode<IntPtrT> phi_bb43_12;
  TNode<IntPtrT> phi_bb43_17;
  TNode<IntPtrT> phi_bb43_18;
  TNode<Float64T> tmp55;
  TNode<Float64T> tmp56;
  TNode<Float64T> tmp57;
  TNode<Float64T> tmp58;
  TNode<Float64T> tmp59;
  TNode<Float64T> tmp60;
  TNode<IntPtrT> tmp61;
  TNode<IntPtrT> tmp62;
  if (block43.is_used()) {
    ca_.Bind(&block43, &phi_bb43_8, &phi_bb43_9, &phi_bb43_10, &phi_bb43_11, &phi_bb43_12, &phi_bb43_17, &phi_bb43_18);
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 426);
    tmp55 = CodeStubAssembler(state_).Float64Div(TNode<Float64T>{tmp53}, TNode<Float64T>{phi_bb43_9});
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 427);
    tmp56 = CodeStubAssembler(state_).Float64Mul(TNode<Float64T>{tmp55}, TNode<Float64T>{tmp55});
    tmp57 = CodeStubAssembler(state_).Float64Sub(TNode<Float64T>{tmp56}, TNode<Float64T>{phi_bb43_11});
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 428);
    tmp58 = CodeStubAssembler(state_).Float64Add(TNode<Float64T>{phi_bb43_10}, TNode<Float64T>{tmp57});
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 429);
    tmp59 = CodeStubAssembler(state_).Float64Sub(TNode<Float64T>{tmp58}, TNode<Float64T>{phi_bb43_10});
    tmp60 = CodeStubAssembler(state_).Float64Sub(TNode<Float64T>{tmp59}, TNode<Float64T>{tmp57});
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 425);
    tmp61 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp62 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb43_12}, TNode<IntPtrT>{tmp61});
    ca_.Goto(&block32, phi_bb43_8, phi_bb43_9, tmp58, tmp60, tmp62);
  }

  TNode<BoolT> phi_bb31_8;
  TNode<Float64T> phi_bb31_9;
  TNode<Float64T> phi_bb31_10;
  TNode<Float64T> phi_bb31_11;
  TNode<IntPtrT> phi_bb31_12;
  TNode<Float64T> tmp63;
  TNode<Float64T> tmp64;
  TNode<Number> tmp65;
  if (block31.is_used()) {
    ca_.Bind(&block31, &phi_bb31_8, &phi_bb31_9, &phi_bb31_10, &phi_bb31_11, &phi_bb31_12);
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 432);
    tmp63 = CodeStubAssembler(state_).Float64Sqrt(TNode<Float64T>{phi_bb31_10});
    tmp64 = CodeStubAssembler(state_).Float64Mul(TNode<Float64T>{tmp63}, TNode<Float64T>{phi_bb31_9});
    tmp65 = Convert_Number_float64_0(state_, TNode<Float64T>{tmp64});
    arguments.PopAndReturn(tmp65);
  }
}

TF_BUILTIN(MathRandom, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kReceiver);
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Object> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<Smi> tmp3;
  TNode<Smi> tmp4;
  TNode<BoolT> tmp5;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 440);
    tmp0 = MATH_RANDOM_INDEX_INDEX_0(state_);
    std::tie(tmp1, tmp2) = NativeContextSlot_NativeContext_Smi_0(state_, TNode<NativeContext>{parameter0}, TNode<IntPtrT>{tmp0}).Flatten();
    tmp3 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp1, tmp2});
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 441);
    tmp4 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp5 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp3}, TNode<Smi>{tmp4});
    ca_.Branch(tmp5, &block1, std::vector<compiler::Node*>{}, &block2, std::vector<compiler::Node*>{tmp3});
  }

  TNode<Smi> tmp6;
  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 443);
    tmp6 = CodeStubAssembler(state_).RefillMathRandom(TNode<NativeContext>{parameter0});
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 441);
    ca_.Goto(&block2, tmp6);
  }

  TNode<Smi> phi_bb2_2;
  TNode<Smi> tmp7;
  TNode<Smi> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<Object> tmp10;
  TNode<IntPtrT> tmp11;
  TNode<IntPtrT> tmp12;
  TNode<Object> tmp13;
  TNode<IntPtrT> tmp14;
  TNode<FixedDoubleArray> tmp15;
  TNode<Object> tmp16;
  TNode<IntPtrT> tmp17;
  TNode<IntPtrT> tmp18;
  TNode<IntPtrT> tmp19;
  TNode<UintPtrT> tmp20;
  TNode<UintPtrT> tmp21;
  TNode<BoolT> tmp22;
  if (block2.is_used()) {
    ca_.Bind(&block2, &phi_bb2_2);
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 445);
    tmp7 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp8 = CodeStubAssembler(state_).SmiSub(TNode<Smi>{phi_bb2_2}, TNode<Smi>{tmp7});
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 446);
    tmp9 = MATH_RANDOM_INDEX_INDEX_0(state_);
    std::tie(tmp10, tmp11) = NativeContextSlot_NativeContext_Smi_0(state_, TNode<NativeContext>{parameter0}, TNode<IntPtrT>{tmp9}).Flatten();
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{tmp10, tmp11}, tmp8);
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 449);
    tmp12 = MATH_RANDOM_CACHE_INDEX_0(state_);
    std::tie(tmp13, tmp14) = NativeContextSlot_NativeContext_FixedDoubleArray_0(state_, TNode<NativeContext>{parameter0}, TNode<IntPtrT>{tmp12}).Flatten();
    tmp15 = CodeStubAssembler(state_).LoadReference<FixedDoubleArray>(CodeStubAssembler::Reference{tmp13, tmp14});
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 451);
    std::tie(tmp16, tmp17, tmp18) = FieldSliceFixedDoubleArrayFloats_0(state_, TNode<FixedDoubleArray>{tmp15}).Flatten();
    tmp19 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp8});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 89);
    tmp20 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp19});
    tmp21 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp18});
    tmp22 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp20}, TNode<UintPtrT>{tmp21});
    ca_.Branch(tmp22, &block7, std::vector<compiler::Node*>{}, &block8, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp23;
  TNode<IntPtrT> tmp24;
  TNode<Object> tmp25;
  TNode<IntPtrT> tmp26;
  TNode<BoolT> tmp27;
  TNode<Float64T> tmp28;
  TNode<BoolT> tmp29;
  if (block7.is_used()) {
    ca_.Bind(&block7);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 97);
    tmp23 = TimesSizeOf_float64_or_hole_0(state_, TNode<IntPtrT>{tmp19});
    tmp24 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp17}, TNode<IntPtrT>{tmp23});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 96);
    std::tie(tmp25, tmp26) = NewReference_float64_or_hole_0(state_, TNode<Object>{tmp16}, TNode<IntPtrT>{tmp24}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 451);
    std::tie(tmp27, tmp28) = LoadFloat64OrHole_0(state_, TorqueStructReference_float64_or_hole_0{TNode<Object>{tmp25}, TNode<IntPtrT>{tmp26}, TorqueStructUnsafe_0{}}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/base.tq", 167);
    tmp29 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp27});
    ca_.Branch(tmp29, &block12, std::vector<compiler::Node*>{}, &block13, std::vector<compiler::Node*>{});
  }

  if (block8.is_used()) {
    ca_.Bind(&block8);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 101);
    CodeStubAssembler(state_).PrintErr("halting because of unreachable code at src/builtins/torque-internal.tq:101:45");
    CodeStubAssembler(state_).Unreachable();
  }

  if (block13.is_used()) {
    ca_.Bind(&block13);
    ca_.SetSourcePosition("../../../src/builtins/base.tq", 167);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/base.tq", 167});
      CodeStubAssembler(state_).FailAssert("Torque assert '!this.is_hole' failed", pos_stack);
    }
  }

  TNode<HeapNumber> tmp30;
  if (block12.is_used()) {
    ca_.Bind(&block12);
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 452);
    tmp30 = CodeStubAssembler(state_).AllocateHeapNumberWithValue(TNode<Float64T>{tmp28});
    CodeStubAssembler(state_).Return(tmp30);
  }
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/math.tq?l=440&c=24
TorqueStructReference_Smi_0 NativeContextSlot_NativeContext_Smi_0(compiler::CodeAssemblerState* state_, TNode<NativeContext> p_context, TNode<IntPtrT> p_index) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Object> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/objects/contexts.tq", 87);
    std::tie(tmp0, tmp1) = NativeContextSlot_Smi_0(state_, TNode<NativeContext>{p_context}, TNode<IntPtrT>{p_index}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 440);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TorqueStructReference_Smi_0{TNode<Object>{tmp0}, TNode<IntPtrT>{tmp1}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/math.tq?l=449&c=8
TorqueStructReference_FixedDoubleArray_0 NativeContextSlot_NativeContext_FixedDoubleArray_0(compiler::CodeAssemblerState* state_, TNode<NativeContext> p_context, TNode<IntPtrT> p_index) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Object> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/objects/contexts.tq", 87);
    std::tie(tmp0, tmp1) = NativeContextSlot_FixedDoubleArray_0(state_, TNode<NativeContext>{p_context}, TNode<IntPtrT>{p_index}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/math.tq", 449);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TorqueStructReference_FixedDoubleArray_0{TNode<Object>{tmp0}, TNode<IntPtrT>{tmp1}, TorqueStructUnsafe_0{}};
}

} // namespace internal
} // namespace v8
