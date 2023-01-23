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
#include "torque-generated/src/builtins/typed-array-filter-tq-csa.h"
#include "torque-generated/src/builtins/array-every-tq-csa.h"
#include "torque-generated/src/builtins/base-tq-csa.h"
#include "torque-generated/src/builtins/convert-tq-csa.h"
#include "torque-generated/src/builtins/frame-arguments-tq-csa.h"
#include "torque-generated/src/builtins/growable-fixed-array-tq-csa.h"
#include "torque-generated/src/builtins/torque-internal-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-createtypedarray-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-every-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-filter-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-tq-csa.h"
#include "torque-generated/src/objects/fixed-array-tq-csa.h"
#include "torque-generated/src/objects/js-array-tq-csa.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/typed-array-filter.tq?l=6&c=1
const char* kBuiltinNameFilter_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
  return "%TypedArray%.prototype.filter";}

TF_BUILTIN(TypedArrayPrototypeFilter, CodeStubAssembler) {
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
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT, JSTypedArray, UintPtrT> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT, JSTypedArray, UintPtrT> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT, JSTypedArray, UintPtrT, UintPtrT, UintPtrT> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT, JSTypedArray, UintPtrT, UintPtrT, UintPtrT> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT, JSTypedArray, UintPtrT, UintPtrT, UintPtrT> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT, JSTypedArray, UintPtrT, UintPtrT, UintPtrT> block25(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT, JSTypedArray, UintPtrT> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT, JSTypedArray, UintPtrT, Object> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT, UintPtrT> block28(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT, UintPtrT> block33(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT, UintPtrT> block32(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT, UintPtrT> block34(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, UintPtrT> block38(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, UintPtrT> block37(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, UintPtrT> block40(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, UintPtrT> block39(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, UintPtrT> block42(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, UintPtrT> block41(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT, UintPtrT> block35(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, UintPtrT, FixedArray, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block47(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, UintPtrT, FixedArray, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block48(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT, UintPtrT> block29(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT, JSTypedArray, UintPtrT> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT, JSTypedArray, IntPtrT, IntPtrT> block54(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT, JSTypedArray, IntPtrT, IntPtrT> block53(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT, JSTypedArray, IntPtrT, IntPtrT> block56(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT, JSTypedArray, IntPtrT, IntPtrT> block55(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT, JSTypedArray, IntPtrT, IntPtrT> block58(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT, JSTypedArray, IntPtrT, IntPtrT> block57(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<JSTypedArray> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-filter.tq", 17);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = Cast_JSTypedArray_1(state_, TNode<Context>{parameter0}, TNode<Object>{parameter1}, &label1);
    ca_.Goto(&block5);
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block6);
    }
  }

  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-filter.tq", 18);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{parameter0}, MessageTemplate::kNotTypedArray, kBuiltinNameFilter_0(state_));
  }

  TNode<JSTypedArray> tmp2;
  TNode<UintPtrT> tmp3;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-filter.tq", 21);
    compiler::CodeAssemblerLabel label4(&ca_);
    std::tie(tmp2, tmp3) = EnsureAttachedAndReadLength_0(state_, TNode<JSTypedArray>{tmp0}, &label4).Flatten();
    ca_.Goto(&block7);
    if (label4.is_used()) {
      ca_.Bind(&label4);
      ca_.Goto(&block8);
    }
  }

  if (block8.is_used()) {
    ca_.Bind(&block8);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-filter.tq", 84);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{parameter0}, MessageTemplate::kDetachedOperation, kBuiltinNameFilter_0(state_));
  }

  TNode<IntPtrT> tmp5;
  TNode<Object> tmp6;
  TNode<JSReceiver> tmp7;
  if (block7.is_used()) {
    ca_.Bind(&block7);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-filter.tq", 24);
    tmp5 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp6 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{torque_arguments.frame}, TNode<RawPtrT>{torque_arguments.base}, TNode<IntPtrT>{torque_arguments.length}, TNode<IntPtrT>{torque_arguments.actual_count}}, TNode<IntPtrT>{tmp5});
    compiler::CodeAssemblerLabel label8(&ca_);
    tmp7 = Cast_Callable_1(state_, TNode<Context>{parameter0}, TNode<Object>{tmp6}, &label8);
    ca_.Goto(&block11);
    if (label8.is_used()) {
      ca_.Bind(&label8);
      ca_.Goto(&block12);
    }
  }

  TNode<IntPtrT> tmp9;
  TNode<Object> tmp10;
  if (block12.is_used()) {
    ca_.Bind(&block12);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-filter.tq", 25);
    tmp9 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp10 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{torque_arguments.frame}, TNode<RawPtrT>{torque_arguments.base}, TNode<IntPtrT>{torque_arguments.length}, TNode<IntPtrT>{torque_arguments.actual_count}}, TNode<IntPtrT>{tmp9});
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{parameter0}, MessageTemplate::kCalledNonCallable, TNode<Object>{tmp10});
  }

  TNode<IntPtrT> tmp11;
  TNode<Object> tmp12;
  TNode<FixedArray> tmp13;
  TNode<IntPtrT> tmp14;
  TNode<IntPtrT> tmp15;
  TNode<JSTypedArray> tmp16;
  TNode<JSTypedArray> tmp17;
  TNode<BuiltinPtr> tmp18;
  TNode<UintPtrT> tmp19;
  if (block11.is_used()) {
    ca_.Bind(&block11);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-filter.tq", 28);
    tmp11 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp12 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{torque_arguments.frame}, TNode<RawPtrT>{torque_arguments.base}, TNode<IntPtrT>{torque_arguments.length}, TNode<IntPtrT>{torque_arguments.actual_count}}, TNode<IntPtrT>{tmp11});
    ca_.SetSourcePosition("../../../src/builtins/typed-array-filter.tq", 33);
    std::tie(tmp13, tmp14, tmp15) = NewGrowableFixedArray_0(state_).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/typed-array-filter.tq", 34);
    std::tie(tmp16, tmp17, tmp18) = NewAttachedJSTypedArrayWitness_0(state_, TNode<JSTypedArray>{tmp2}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/typed-array-filter.tq", 40);
    tmp19 = FromConstexpr_uintptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    ca_.Goto(&block15, tmp13, tmp14, tmp15, tmp17, tmp19);
  }

  TNode<FixedArray> phi_bb15_11;
  TNode<IntPtrT> phi_bb15_12;
  TNode<IntPtrT> phi_bb15_13;
  TNode<JSTypedArray> phi_bb15_15;
  TNode<UintPtrT> phi_bb15_17;
  TNode<BoolT> tmp20;
  if (block15.is_used()) {
    ca_.Bind(&block15, &phi_bb15_11, &phi_bb15_12, &phi_bb15_13, &phi_bb15_15, &phi_bb15_17);
    tmp20 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{phi_bb15_17}, TNode<UintPtrT>{tmp3});
    ca_.Branch(tmp20, &block13, std::vector<compiler::Node*>{phi_bb15_11, phi_bb15_12, phi_bb15_13, phi_bb15_15, phi_bb15_17}, &block14, std::vector<compiler::Node*>{phi_bb15_11, phi_bb15_12, phi_bb15_13, phi_bb15_15, phi_bb15_17});
  }

  TNode<FixedArray> phi_bb13_11;
  TNode<IntPtrT> phi_bb13_12;
  TNode<IntPtrT> phi_bb13_13;
  TNode<JSTypedArray> phi_bb13_15;
  TNode<UintPtrT> phi_bb13_17;
  TNode<UintPtrT> tmp21;
  if (block13.is_used()) {
    ca_.Bind(&block13, &phi_bb13_11, &phi_bb13_12, &phi_bb13_13, &phi_bb13_15, &phi_bb13_17);
    ca_.SetSourcePosition("../../../src/builtins/typed-array.tq", 223);
    compiler::CodeAssemblerLabel label22(&ca_);
    tmp21 = CodeStubAssembler(state_).LoadJSTypedArrayLengthAndCheckDetached(TNode<JSTypedArray>{tmp16}, &label22);
    ca_.Goto(&block22, phi_bb13_11, phi_bb13_12, phi_bb13_13, phi_bb13_15, phi_bb13_17, phi_bb13_17, phi_bb13_17);
    if (label22.is_used()) {
      ca_.Bind(&label22);
      ca_.Goto(&block23, phi_bb13_11, phi_bb13_12, phi_bb13_13, phi_bb13_15, phi_bb13_17, phi_bb13_17, phi_bb13_17);
    }
  }

  TNode<FixedArray> phi_bb23_11;
  TNode<IntPtrT> phi_bb23_12;
  TNode<IntPtrT> phi_bb23_13;
  TNode<JSTypedArray> phi_bb23_15;
  TNode<UintPtrT> phi_bb23_17;
  TNode<UintPtrT> phi_bb23_19;
  TNode<UintPtrT> phi_bb23_20;
  if (block23.is_used()) {
    ca_.Bind(&block23, &phi_bb23_11, &phi_bb23_12, &phi_bb23_13, &phi_bb23_15, &phi_bb23_17, &phi_bb23_19, &phi_bb23_20);
    ca_.Goto(&block20, phi_bb23_11, phi_bb23_12, phi_bb23_13, phi_bb23_15, phi_bb23_17);
  }

  TNode<FixedArray> phi_bb22_11;
  TNode<IntPtrT> phi_bb22_12;
  TNode<IntPtrT> phi_bb22_13;
  TNode<JSTypedArray> phi_bb22_15;
  TNode<UintPtrT> phi_bb22_17;
  TNode<UintPtrT> phi_bb22_19;
  TNode<UintPtrT> phi_bb22_20;
  TNode<BoolT> tmp23;
  if (block22.is_used()) {
    ca_.Bind(&block22, &phi_bb22_11, &phi_bb22_12, &phi_bb22_13, &phi_bb22_15, &phi_bb22_17, &phi_bb22_19, &phi_bb22_20);
    ca_.SetSourcePosition("../../../src/builtins/typed-array.tq", 225);
    tmp23 = CodeStubAssembler(state_).UintPtrGreaterThanOrEqual(TNode<UintPtrT>{phi_bb22_20}, TNode<UintPtrT>{tmp21});
    ca_.Branch(tmp23, &block24, std::vector<compiler::Node*>{phi_bb22_11, phi_bb22_12, phi_bb22_13, phi_bb22_15, phi_bb22_17, phi_bb22_19, phi_bb22_20}, &block25, std::vector<compiler::Node*>{phi_bb22_11, phi_bb22_12, phi_bb22_13, phi_bb22_15, phi_bb22_17, phi_bb22_19, phi_bb22_20});
  }

  TNode<FixedArray> phi_bb24_11;
  TNode<IntPtrT> phi_bb24_12;
  TNode<IntPtrT> phi_bb24_13;
  TNode<JSTypedArray> phi_bb24_15;
  TNode<UintPtrT> phi_bb24_17;
  TNode<UintPtrT> phi_bb24_19;
  TNode<UintPtrT> phi_bb24_20;
  if (block24.is_used()) {
    ca_.Bind(&block24, &phi_bb24_11, &phi_bb24_12, &phi_bb24_13, &phi_bb24_15, &phi_bb24_17, &phi_bb24_19, &phi_bb24_20);
    ca_.SetSourcePosition("../../../src/builtins/typed-array.tq", 226);
    ca_.Goto(&block20, phi_bb24_11, phi_bb24_12, phi_bb24_13, phi_bb24_15, phi_bb24_17);
  }

  TNode<FixedArray> phi_bb25_11;
  TNode<IntPtrT> phi_bb25_12;
  TNode<IntPtrT> phi_bb25_13;
  TNode<JSTypedArray> phi_bb25_15;
  TNode<UintPtrT> phi_bb25_17;
  TNode<UintPtrT> phi_bb25_19;
  TNode<UintPtrT> phi_bb25_20;
  TNode<JSTypedArray> tmp24;
  TNode<Numeric> tmp25;
  if (block25.is_used()) {
    ca_.Bind(&block25, &phi_bb25_11, &phi_bb25_12, &phi_bb25_13, &phi_bb25_15, &phi_bb25_17, &phi_bb25_19, &phi_bb25_20);
    ca_.SetSourcePosition("../../../src/builtins/typed-array.tq", 228);
    tmp24 = (TNode<JSTypedArray>{tmp16});
    ca_.SetSourcePosition("../../../src/builtins/typed-array.tq", 233);
tmp25 = TORQUE_CAST(CodeStubAssembler(state_).CallBuiltinPointer(Builtins::CallableFor(ca_.isolate(),ExampleBuiltinForTorqueFunctionPointerType(1)).descriptor(), tmp18, TNode<Object>(), tmp24, phi_bb25_17));
    ca_.SetSourcePosition("../../../src/builtins/typed-array-filter.tq", 47);
    ca_.Goto(&block17, phi_bb25_11, phi_bb25_12, phi_bb25_13, tmp24, phi_bb25_17, tmp25);
  }

  TNode<FixedArray> phi_bb20_11;
  TNode<IntPtrT> phi_bb20_12;
  TNode<IntPtrT> phi_bb20_13;
  TNode<JSTypedArray> phi_bb20_15;
  TNode<UintPtrT> phi_bb20_17;
  TNode<Oddball> tmp26;
  if (block20.is_used()) {
    ca_.Bind(&block20, &phi_bb20_11, &phi_bb20_12, &phi_bb20_13, &phi_bb20_15, &phi_bb20_17);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-filter.tq", 48);
    tmp26 = Undefined_0(state_);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-filter.tq", 44);
    ca_.Goto(&block17, phi_bb20_11, phi_bb20_12, phi_bb20_13, phi_bb20_15, phi_bb20_17, tmp26);
  }

  TNode<FixedArray> phi_bb17_11;
  TNode<IntPtrT> phi_bb17_12;
  TNode<IntPtrT> phi_bb17_13;
  TNode<JSTypedArray> phi_bb17_15;
  TNode<UintPtrT> phi_bb17_17;
  TNode<Object> phi_bb17_18;
  TNode<Number> tmp27;
  TNode<Object> tmp28;
  TNode<BoolT> tmp29;
  if (block17.is_used()) {
    ca_.Bind(&block17, &phi_bb17_11, &phi_bb17_12, &phi_bb17_13, &phi_bb17_15, &phi_bb17_17, &phi_bb17_18);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-filter.tq", 56);
    tmp27 = Convert_Number_uintptr_0(state_, TNode<UintPtrT>{phi_bb17_17});
    ca_.SetSourcePosition("../../../src/builtins/typed-array-filter.tq", 55);
    tmp28 = CodeStubAssembler(state_).Call(TNode<Context>{parameter0}, TNode<Object>{tmp7}, TNode<Object>{tmp12}, TNode<Object>{phi_bb17_18}, TNode<Object>{tmp27}, TNode<Object>{tmp16});
    ca_.SetSourcePosition("../../../src/builtins/typed-array-filter.tq", 62);
    tmp29 = ToBoolean_0(state_, TNode<Object>{tmp28});
    ca_.Branch(tmp29, &block28, std::vector<compiler::Node*>{phi_bb17_11, phi_bb17_12, phi_bb17_13, phi_bb17_17}, &block29, std::vector<compiler::Node*>{phi_bb17_11, phi_bb17_12, phi_bb17_13, phi_bb17_17});
  }

  TNode<FixedArray> phi_bb28_11;
  TNode<IntPtrT> phi_bb28_12;
  TNode<IntPtrT> phi_bb28_13;
  TNode<UintPtrT> phi_bb28_17;
  TNode<BoolT> tmp30;
  if (block28.is_used()) {
    ca_.Bind(&block28, &phi_bb28_11, &phi_bb28_12, &phi_bb28_13, &phi_bb28_17);
    ca_.SetSourcePosition("../../../src/builtins/growable-fixed-array.tq", 20);
    tmp30 = CodeStubAssembler(state_).IntPtrLessThanOrEqual(TNode<IntPtrT>{phi_bb28_13}, TNode<IntPtrT>{phi_bb28_12});
    ca_.Branch(tmp30, &block32, std::vector<compiler::Node*>{phi_bb28_11, phi_bb28_12, phi_bb28_13, phi_bb28_17}, &block33, std::vector<compiler::Node*>{phi_bb28_11, phi_bb28_12, phi_bb28_13, phi_bb28_17});
  }

  TNode<FixedArray> phi_bb33_11;
  TNode<IntPtrT> phi_bb33_12;
  TNode<IntPtrT> phi_bb33_13;
  TNode<UintPtrT> phi_bb33_17;
  if (block33.is_used()) {
    ca_.Bind(&block33, &phi_bb33_11, &phi_bb33_12, &phi_bb33_13, &phi_bb33_17);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/growable-fixed-array.tq", 20});
      CodeStubAssembler(state_).FailAssert("Torque assert 'this.length <= this.capacity' failed", pos_stack);
    }
  }

  TNode<FixedArray> phi_bb32_11;
  TNode<IntPtrT> phi_bb32_12;
  TNode<IntPtrT> phi_bb32_13;
  TNode<UintPtrT> phi_bb32_17;
  TNode<BoolT> tmp31;
  if (block32.is_used()) {
    ca_.Bind(&block32, &phi_bb32_11, &phi_bb32_12, &phi_bb32_13, &phi_bb32_17);
    ca_.SetSourcePosition("../../../src/builtins/growable-fixed-array.tq", 21);
    tmp31 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{phi_bb32_12}, TNode<IntPtrT>{phi_bb32_13});
    ca_.Branch(tmp31, &block34, std::vector<compiler::Node*>{phi_bb32_11, phi_bb32_12, phi_bb32_13, phi_bb32_17}, &block35, std::vector<compiler::Node*>{phi_bb32_11, phi_bb32_12, phi_bb32_13, phi_bb32_17});
  }

  TNode<FixedArray> phi_bb34_11;
  TNode<IntPtrT> phi_bb34_12;
  TNode<IntPtrT> phi_bb34_13;
  TNode<UintPtrT> phi_bb34_17;
  TNode<IntPtrT> tmp32;
  TNode<IntPtrT> tmp33;
  TNode<IntPtrT> tmp34;
  TNode<IntPtrT> tmp35;
  TNode<IntPtrT> tmp36;
  TNode<IntPtrT> tmp37;
  TNode<BoolT> tmp38;
  if (block34.is_used()) {
    ca_.Bind(&block34, &phi_bb34_11, &phi_bb34_12, &phi_bb34_13, &phi_bb34_17);
    ca_.SetSourcePosition("../../../src/builtins/growable-fixed-array.tq", 24);
    tmp32 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp33 = CodeStubAssembler(state_).WordSar(TNode<IntPtrT>{phi_bb34_12}, TNode<IntPtrT>{tmp32});
    tmp34 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb34_12}, TNode<IntPtrT>{tmp33});
    tmp35 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x10ull));
    tmp36 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp34}, TNode<IntPtrT>{tmp35});
    ca_.SetSourcePosition("../../../src/builtins/growable-fixed-array.tq", 13);
    tmp37 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp38 = CodeStubAssembler(state_).IntPtrGreaterThanOrEqual(TNode<IntPtrT>{phi_bb34_13}, TNode<IntPtrT>{tmp37});
    ca_.Branch(tmp38, &block37, std::vector<compiler::Node*>{phi_bb34_11, phi_bb34_13, phi_bb34_17}, &block38, std::vector<compiler::Node*>{phi_bb34_11, phi_bb34_13, phi_bb34_17});
  }

  TNode<FixedArray> phi_bb38_11;
  TNode<IntPtrT> phi_bb38_13;
  TNode<UintPtrT> phi_bb38_17;
  if (block38.is_used()) {
    ca_.Bind(&block38, &phi_bb38_11, &phi_bb38_13, &phi_bb38_17);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/growable-fixed-array.tq", 13});
      CodeStubAssembler(state_).FailAssert("Torque assert 'this.length >= 0' failed", pos_stack);
    }
  }

  TNode<FixedArray> phi_bb37_11;
  TNode<IntPtrT> phi_bb37_13;
  TNode<UintPtrT> phi_bb37_17;
  TNode<IntPtrT> tmp39;
  TNode<BoolT> tmp40;
  if (block37.is_used()) {
    ca_.Bind(&block37, &phi_bb37_11, &phi_bb37_13, &phi_bb37_17);
    ca_.SetSourcePosition("../../../src/builtins/growable-fixed-array.tq", 14);
    tmp39 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp40 = CodeStubAssembler(state_).IntPtrGreaterThanOrEqual(TNode<IntPtrT>{tmp36}, TNode<IntPtrT>{tmp39});
    ca_.Branch(tmp40, &block39, std::vector<compiler::Node*>{phi_bb37_11, phi_bb37_13, phi_bb37_17}, &block40, std::vector<compiler::Node*>{phi_bb37_11, phi_bb37_13, phi_bb37_17});
  }

  TNode<FixedArray> phi_bb40_11;
  TNode<IntPtrT> phi_bb40_13;
  TNode<UintPtrT> phi_bb40_17;
  if (block40.is_used()) {
    ca_.Bind(&block40, &phi_bb40_11, &phi_bb40_13, &phi_bb40_17);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/growable-fixed-array.tq", 14});
      CodeStubAssembler(state_).FailAssert("Torque assert 'newCapacity >= 0' failed", pos_stack);
    }
  }

  TNode<FixedArray> phi_bb39_11;
  TNode<IntPtrT> phi_bb39_13;
  TNode<UintPtrT> phi_bb39_17;
  TNode<BoolT> tmp41;
  if (block39.is_used()) {
    ca_.Bind(&block39, &phi_bb39_11, &phi_bb39_13, &phi_bb39_17);
    ca_.SetSourcePosition("../../../src/builtins/growable-fixed-array.tq", 15);
    tmp41 = CodeStubAssembler(state_).IntPtrGreaterThanOrEqual(TNode<IntPtrT>{tmp36}, TNode<IntPtrT>{phi_bb39_13});
    ca_.Branch(tmp41, &block41, std::vector<compiler::Node*>{phi_bb39_11, phi_bb39_13, phi_bb39_17}, &block42, std::vector<compiler::Node*>{phi_bb39_11, phi_bb39_13, phi_bb39_17});
  }

  TNode<FixedArray> phi_bb42_11;
  TNode<IntPtrT> phi_bb42_13;
  TNode<UintPtrT> phi_bb42_17;
  if (block42.is_used()) {
    ca_.Bind(&block42, &phi_bb42_11, &phi_bb42_13, &phi_bb42_17);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/growable-fixed-array.tq", 15});
      CodeStubAssembler(state_).FailAssert("Torque assert 'newCapacity >= this.length' failed", pos_stack);
    }
  }

  TNode<FixedArray> phi_bb41_11;
  TNode<IntPtrT> phi_bb41_13;
  TNode<UintPtrT> phi_bb41_17;
  TNode<IntPtrT> tmp42;
  TNode<FixedArray> tmp43;
  if (block41.is_used()) {
    ca_.Bind(&block41, &phi_bb41_11, &phi_bb41_13, &phi_bb41_17);
    ca_.SetSourcePosition("../../../src/builtins/growable-fixed-array.tq", 16);
    tmp42 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    ca_.SetSourcePosition("../../../src/builtins/growable-fixed-array.tq", 17);
    tmp43 = ExtractFixedArray_0(state_, TNode<FixedArray>{phi_bb41_11}, TNode<IntPtrT>{tmp42}, TNode<IntPtrT>{phi_bb41_13}, TNode<IntPtrT>{tmp36});
    ca_.SetSourcePosition("../../../src/builtins/growable-fixed-array.tq", 21);
    ca_.Goto(&block35, tmp43, tmp36, phi_bb41_13, phi_bb41_17);
  }

  TNode<FixedArray> phi_bb35_11;
  TNode<IntPtrT> phi_bb35_12;
  TNode<IntPtrT> phi_bb35_13;
  TNode<UintPtrT> phi_bb35_17;
  TNode<Object> tmp44;
  TNode<IntPtrT> tmp45;
  TNode<IntPtrT> tmp46;
  TNode<IntPtrT> tmp47;
  TNode<IntPtrT> tmp48;
  TNode<UintPtrT> tmp49;
  TNode<UintPtrT> tmp50;
  TNode<BoolT> tmp51;
  if (block35.is_used()) {
    ca_.Bind(&block35, &phi_bb35_11, &phi_bb35_12, &phi_bb35_13, &phi_bb35_17);
    ca_.SetSourcePosition("../../../src/builtins/growable-fixed-array.tq", 10);
    std::tie(tmp44, tmp45, tmp46) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray>{phi_bb35_11}).Flatten();
    tmp47 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp48 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb35_13}, TNode<IntPtrT>{tmp47});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 89);
    tmp49 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{phi_bb35_13});
    tmp50 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp46});
    tmp51 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp49}, TNode<UintPtrT>{tmp50});
    ca_.Branch(tmp51, &block47, std::vector<compiler::Node*>{phi_bb35_11, phi_bb35_12, phi_bb35_17, phi_bb35_11, phi_bb35_13, phi_bb35_13, phi_bb35_13, phi_bb35_13}, &block48, std::vector<compiler::Node*>{phi_bb35_11, phi_bb35_12, phi_bb35_17, phi_bb35_11, phi_bb35_13, phi_bb35_13, phi_bb35_13, phi_bb35_13});
  }

  TNode<FixedArray> phi_bb47_11;
  TNode<IntPtrT> phi_bb47_12;
  TNode<UintPtrT> phi_bb47_17;
  TNode<FixedArray> phi_bb47_22;
  TNode<IntPtrT> phi_bb47_26;
  TNode<IntPtrT> phi_bb47_27;
  TNode<IntPtrT> phi_bb47_31;
  TNode<IntPtrT> phi_bb47_32;
  TNode<IntPtrT> tmp52;
  TNode<IntPtrT> tmp53;
  TNode<Object> tmp54;
  TNode<IntPtrT> tmp55;
  if (block47.is_used()) {
    ca_.Bind(&block47, &phi_bb47_11, &phi_bb47_12, &phi_bb47_17, &phi_bb47_22, &phi_bb47_26, &phi_bb47_27, &phi_bb47_31, &phi_bb47_32);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 97);
    tmp52 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{phi_bb47_32});
    tmp53 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp45}, TNode<IntPtrT>{tmp52});
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 96);
    std::tie(tmp54, tmp55) = NewReference_Object_0(state_, TNode<Object>{tmp44}, TNode<IntPtrT>{tmp53}).Flatten();
    ca_.SetSourcePosition("../../../src/builtins/growable-fixed-array.tq", 10);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp54, tmp55}, phi_bb17_18);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-filter.tq", 62);
    ca_.Goto(&block29, phi_bb47_11, phi_bb47_12, tmp48, phi_bb47_17);
  }

  TNode<FixedArray> phi_bb48_11;
  TNode<IntPtrT> phi_bb48_12;
  TNode<UintPtrT> phi_bb48_17;
  TNode<FixedArray> phi_bb48_22;
  TNode<IntPtrT> phi_bb48_26;
  TNode<IntPtrT> phi_bb48_27;
  TNode<IntPtrT> phi_bb48_31;
  TNode<IntPtrT> phi_bb48_32;
  if (block48.is_used()) {
    ca_.Bind(&block48, &phi_bb48_11, &phi_bb48_12, &phi_bb48_17, &phi_bb48_22, &phi_bb48_26, &phi_bb48_27, &phi_bb48_31, &phi_bb48_32);
    ca_.SetSourcePosition("../../../src/builtins/torque-internal.tq", 101);
    CodeStubAssembler(state_).PrintErr("halting because of unreachable code at src/builtins/torque-internal.tq:101:45");
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<FixedArray> phi_bb29_11;
  TNode<IntPtrT> phi_bb29_12;
  TNode<IntPtrT> phi_bb29_13;
  TNode<UintPtrT> phi_bb29_17;
  TNode<UintPtrT> tmp56;
  TNode<UintPtrT> tmp57;
  if (block29.is_used()) {
    ca_.Bind(&block29, &phi_bb29_11, &phi_bb29_12, &phi_bb29_13, &phi_bb29_17);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-filter.tq", 40);
    tmp56 = FromConstexpr_uintptr_constexpr_int31_0(state_, 1);
    tmp57 = CodeStubAssembler(state_).UintPtrAdd(TNode<UintPtrT>{phi_bb29_17}, TNode<UintPtrT>{tmp56});
    ca_.Goto(&block15, phi_bb29_11, phi_bb29_12, phi_bb29_13, phi_bb17_15, tmp57);
  }

  TNode<FixedArray> phi_bb14_11;
  TNode<IntPtrT> phi_bb14_12;
  TNode<IntPtrT> phi_bb14_13;
  TNode<JSTypedArray> phi_bb14_15;
  TNode<UintPtrT> phi_bb14_17;
  TNode<UintPtrT> tmp58;
  TNode<JSTypedArray> tmp59;
  TNode<UintPtrT> tmp60;
  TNode<Number> tmp61;
  TNode<NativeContext> tmp62;
  TNode<Map> tmp63;
  TNode<IntPtrT> tmp64;
  TNode<BoolT> tmp65;
  if (block14.is_used()) {
    ca_.Bind(&block14, &phi_bb14_11, &phi_bb14_12, &phi_bb14_13, &phi_bb14_15, &phi_bb14_17);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-filter.tq", 69);
    tmp58 = CodeStubAssembler(state_).Unsigned(TNode<IntPtrT>{phi_bb14_13});
    ca_.SetSourcePosition("../../../src/builtins/typed-array-filter.tq", 68);
    tmp59 = TypedArraySpeciesCreateByLength_0(state_, TNode<Context>{parameter0}, kBuiltinNameFilter_0(state_), TNode<JSTypedArray>{tmp0}, TNode<UintPtrT>{tmp58});
    ca_.SetSourcePosition("../../../src/builtins/typed-array-filter.tq", 78);
    tmp60 = CodeStubAssembler(state_).Unsigned(TNode<IntPtrT>{phi_bb14_13});
    tmp61 = Convert_Number_uintptr_0(state_, TNode<UintPtrT>{tmp60});
    ca_.SetSourcePosition("../../../src/builtins/growable-fixed-array.tq", 30);
    tmp62 = CodeStubAssembler(state_).LoadNativeContext(TNode<Context>{parameter0});
    ca_.SetSourcePosition("../../../src/builtins/growable-fixed-array.tq", 32);
    tmp63 = CodeStubAssembler(state_).LoadJSArrayElementsMap(ElementsKind::PACKED_ELEMENTS, TNode<NativeContext>{tmp62});
    ca_.SetSourcePosition("../../../src/builtins/growable-fixed-array.tq", 13);
    tmp64 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp65 = CodeStubAssembler(state_).IntPtrGreaterThanOrEqual(TNode<IntPtrT>{phi_bb14_13}, TNode<IntPtrT>{tmp64});
    ca_.Branch(tmp65, &block53, std::vector<compiler::Node*>{phi_bb14_11, phi_bb14_12, phi_bb14_13, phi_bb14_15, phi_bb14_13, phi_bb14_13}, &block54, std::vector<compiler::Node*>{phi_bb14_11, phi_bb14_12, phi_bb14_13, phi_bb14_15, phi_bb14_13, phi_bb14_13});
  }

  TNode<FixedArray> phi_bb54_11;
  TNode<IntPtrT> phi_bb54_12;
  TNode<IntPtrT> phi_bb54_13;
  TNode<JSTypedArray> phi_bb54_15;
  TNode<IntPtrT> phi_bb54_25;
  TNode<IntPtrT> phi_bb54_26;
  if (block54.is_used()) {
    ca_.Bind(&block54, &phi_bb54_11, &phi_bb54_12, &phi_bb54_13, &phi_bb54_15, &phi_bb54_25, &phi_bb54_26);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/growable-fixed-array.tq", 13});
      CodeStubAssembler(state_).FailAssert("Torque assert 'this.length >= 0' failed", pos_stack);
    }
  }

  TNode<FixedArray> phi_bb53_11;
  TNode<IntPtrT> phi_bb53_12;
  TNode<IntPtrT> phi_bb53_13;
  TNode<JSTypedArray> phi_bb53_15;
  TNode<IntPtrT> phi_bb53_25;
  TNode<IntPtrT> phi_bb53_26;
  TNode<IntPtrT> tmp66;
  TNode<BoolT> tmp67;
  if (block53.is_used()) {
    ca_.Bind(&block53, &phi_bb53_11, &phi_bb53_12, &phi_bb53_13, &phi_bb53_15, &phi_bb53_25, &phi_bb53_26);
    ca_.SetSourcePosition("../../../src/builtins/growable-fixed-array.tq", 14);
    tmp66 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp67 = CodeStubAssembler(state_).IntPtrGreaterThanOrEqual(TNode<IntPtrT>{phi_bb53_26}, TNode<IntPtrT>{tmp66});
    ca_.Branch(tmp67, &block55, std::vector<compiler::Node*>{phi_bb53_11, phi_bb53_12, phi_bb53_13, phi_bb53_15, phi_bb53_25, phi_bb53_26}, &block56, std::vector<compiler::Node*>{phi_bb53_11, phi_bb53_12, phi_bb53_13, phi_bb53_15, phi_bb53_25, phi_bb53_26});
  }

  TNode<FixedArray> phi_bb56_11;
  TNode<IntPtrT> phi_bb56_12;
  TNode<IntPtrT> phi_bb56_13;
  TNode<JSTypedArray> phi_bb56_15;
  TNode<IntPtrT> phi_bb56_25;
  TNode<IntPtrT> phi_bb56_26;
  if (block56.is_used()) {
    ca_.Bind(&block56, &phi_bb56_11, &phi_bb56_12, &phi_bb56_13, &phi_bb56_15, &phi_bb56_25, &phi_bb56_26);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/growable-fixed-array.tq", 14});
      CodeStubAssembler(state_).FailAssert("Torque assert 'newCapacity >= 0' failed", pos_stack);
    }
  }

  TNode<FixedArray> phi_bb55_11;
  TNode<IntPtrT> phi_bb55_12;
  TNode<IntPtrT> phi_bb55_13;
  TNode<JSTypedArray> phi_bb55_15;
  TNode<IntPtrT> phi_bb55_25;
  TNode<IntPtrT> phi_bb55_26;
  TNode<BoolT> tmp68;
  if (block55.is_used()) {
    ca_.Bind(&block55, &phi_bb55_11, &phi_bb55_12, &phi_bb55_13, &phi_bb55_15, &phi_bb55_25, &phi_bb55_26);
    ca_.SetSourcePosition("../../../src/builtins/growable-fixed-array.tq", 15);
    tmp68 = CodeStubAssembler(state_).IntPtrGreaterThanOrEqual(TNode<IntPtrT>{phi_bb55_26}, TNode<IntPtrT>{phi_bb55_13});
    ca_.Branch(tmp68, &block57, std::vector<compiler::Node*>{phi_bb55_11, phi_bb55_12, phi_bb55_13, phi_bb55_15, phi_bb55_25, phi_bb55_26}, &block58, std::vector<compiler::Node*>{phi_bb55_11, phi_bb55_12, phi_bb55_13, phi_bb55_15, phi_bb55_25, phi_bb55_26});
  }

  TNode<FixedArray> phi_bb58_11;
  TNode<IntPtrT> phi_bb58_12;
  TNode<IntPtrT> phi_bb58_13;
  TNode<JSTypedArray> phi_bb58_15;
  TNode<IntPtrT> phi_bb58_25;
  TNode<IntPtrT> phi_bb58_26;
  if (block58.is_used()) {
    ca_.Bind(&block58, &phi_bb58_11, &phi_bb58_12, &phi_bb58_13, &phi_bb58_15, &phi_bb58_25, &phi_bb58_26);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/growable-fixed-array.tq", 15});
      CodeStubAssembler(state_).FailAssert("Torque assert 'newCapacity >= this.length' failed", pos_stack);
    }
  }

  TNode<FixedArray> phi_bb57_11;
  TNode<IntPtrT> phi_bb57_12;
  TNode<IntPtrT> phi_bb57_13;
  TNode<JSTypedArray> phi_bb57_15;
  TNode<IntPtrT> phi_bb57_25;
  TNode<IntPtrT> phi_bb57_26;
  TNode<IntPtrT> tmp69;
  TNode<FixedArray> tmp70;
  TNode<Smi> tmp71;
  TNode<JSArray> tmp72;
  if (block57.is_used()) {
    ca_.Bind(&block57, &phi_bb57_11, &phi_bb57_12, &phi_bb57_13, &phi_bb57_15, &phi_bb57_25, &phi_bb57_26);
    ca_.SetSourcePosition("../../../src/builtins/growable-fixed-array.tq", 16);
    tmp69 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    ca_.SetSourcePosition("../../../src/builtins/growable-fixed-array.tq", 17);
    tmp70 = ExtractFixedArray_0(state_, TNode<FixedArray>{phi_bb57_11}, TNode<IntPtrT>{tmp69}, TNode<IntPtrT>{phi_bb57_13}, TNode<IntPtrT>{phi_bb57_26});
    ca_.SetSourcePosition("../../../src/builtins/growable-fixed-array.tq", 34);
    tmp71 = Convert_Smi_intptr_0(state_, TNode<IntPtrT>{phi_bb57_13});
    ca_.SetSourcePosition("../../../src/builtins/growable-fixed-array.tq", 35);
    tmp72 = CodeStubAssembler(state_).AllocateJSArray(TNode<Map>{tmp63}, TNode<FixedArrayBase>{tmp70}, TNode<Smi>{tmp71});
    ca_.SetSourcePosition("../../../src/builtins/typed-array-filter.tq", 79);
    CodeStubAssembler(state_).CallRuntime(Runtime::kTypedArrayCopyElements, parameter0, tmp59, tmp72, tmp61);
    ca_.SetSourcePosition("../../../src/builtins/typed-array-filter.tq", 82);
    arguments.PopAndReturn(tmp59);
  }
}

} // namespace internal
} // namespace v8
