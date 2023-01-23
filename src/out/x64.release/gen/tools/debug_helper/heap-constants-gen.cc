
#include <cstdint>
#include <string>

// Don't bother initializing global cage base value, compute it from any
// on heap address instead.
#define V8_COMPRESS_POINTERS_DONT_USE_GLOBAL_BASE
#include "src/common/ptr-compr-inl.h"
#include "tools/debug_helper/debug-helper-internal.h"

namespace v8 {
namespace internal {
namespace debug_helper_internal {

std::string FindKnownObjectInMapSpace(uintptr_t offset) {
  switch (offset) {
    default: return "";
  }
}

std::string FindKnownObjectInOldSpace(uintptr_t offset) {
  switch (offset) {
    case 17341: return "ExternalMap";
    case 17381: return "JSMessageObjectMap";
    case 17005: return "ArgumentsIteratorAccessor";
    case 17029: return "ArrayLengthAccessor";
    case 17053: return "BoundFunctionLengthAccessor";
    case 17077: return "BoundFunctionNameAccessor";
    case 17101: return "ErrorStackAccessor";
    case 17125: return "FunctionArgumentsAccessor";
    case 17149: return "FunctionCallerAccessor";
    case 17173: return "FunctionNameAccessor";
    case 17197: return "FunctionLengthAccessor";
    case 17221: return "FunctionPrototypeAccessor";
    case 17245: return "StringLengthAccessor";
    case 17269: return "ValueUnavailableAccessor";
    case 17293: return "WrappedFunctionLengthAccessor";
    case 17317: return "WrappedFunctionNameAccessor";
    case 17421: return "EmptyScript";
    case 17489: return "ManyClosuresCell";
    case 17501: return "ArrayConstructorProtector";
    case 17521: return "NoElementsProtector";
    case 17541: return "MegaDOMProtector";
    case 17561: return "IsConcatSpreadableProtector";
    case 17581: return "ArraySpeciesProtector";
    case 17601: return "TypedArraySpeciesProtector";
    case 17621: return "PromiseSpeciesProtector";
    case 17641: return "RegExpSpeciesProtector";
    case 17661: return "StringLengthProtector";
    case 17681: return "ArrayIteratorProtector";
    case 17701: return "ArrayBufferDetachingProtector";
    case 17721: return "PromiseHookProtector";
    case 17741: return "PromiseResolveProtector";
    case 17761: return "MapIteratorProtector";
    case 17781: return "PromiseThenProtector";
    case 17801: return "SetIteratorProtector";
    case 17821: return "StringIteratorProtector";
    case 17841: return "StringSplitCache";
    case 18873: return "RegExpMultipleCache";
    case 19905: return "BuiltinsConstantsTable";
    case 21393: return "AsyncFunctionAwaitRejectSharedFun";
    case 21429: return "AsyncFunctionAwaitResolveSharedFun";
    case 21465: return "AsyncGeneratorAwaitRejectSharedFun";
    case 21501: return "AsyncGeneratorAwaitResolveSharedFun";
    case 21537: return "AsyncGeneratorYieldWithAwaitResolveSharedFun";
    case 21573: return "AsyncGeneratorReturnResolveSharedFun";
    case 21609: return "AsyncGeneratorReturnClosedRejectSharedFun";
    case 21645: return "AsyncGeneratorReturnClosedResolveSharedFun";
    case 21681: return "AsyncIteratorValueUnwrapSharedFun";
    case 21717: return "PromiseAllResolveElementSharedFun";
    case 21753: return "PromiseAllSettledResolveElementSharedFun";
    case 21789: return "PromiseAllSettledRejectElementSharedFun";
    case 21825: return "PromiseAnyRejectElementSharedFun";
    case 21861: return "PromiseCapabilityDefaultRejectSharedFun";
    case 21897: return "PromiseCapabilityDefaultResolveSharedFun";
    case 21933: return "PromiseCatchFinallySharedFun";
    case 21969: return "PromiseGetCapabilitiesExecutorSharedFun";
    case 22005: return "PromiseThenFinallySharedFun";
    case 22041: return "PromiseThrowerFinallySharedFun";
    case 22077: return "PromiseValueThunkFinallySharedFun";
    case 22113: return "ProxyRevokeSharedFun";
    case 22149: return "ShadowRealmImportValueFulfilledSFI";
    case 22185: return "SourceTextModuleExecuteAsyncModuleFulfilledSFI";
    case 22221: return "SourceTextModuleExecuteAsyncModuleRejectedSFI";
    default: return "";
  }
}

std::string FindKnownObjectInReadOnlySpace(uintptr_t offset) {
  switch (offset) {
    case 8513: return "MetaMap";
    case 8553: return "FixedArrayMap";
    case 8593: return "WeakFixedArrayMap";
    case 8633: return "WeakArrayListMap";
    case 8673: return "FixedCOWArrayMap";
    case 8713: return "DescriptorArrayMap";
    case 8753: return "UndefinedMap";
    case 8793: return "NullMap";
    case 8833: return "TheHoleMap";
    case 8985: return "PromiseFulfillReactionJobTaskMap";
    case 9025: return "PromiseRejectReactionJobTaskMap";
    case 9065: return "CallableTaskMap";
    case 9105: return "CallbackTaskMap";
    case 9145: return "PromiseResolveThenableJobTaskMap";
    case 9185: return "FunctionTemplateInfoMap";
    case 9225: return "ObjectTemplateInfoMap";
    case 9265: return "AccessCheckInfoMap";
    case 9305: return "AccessorPairMap";
    case 9345: return "AliasedArgumentsEntryMap";
    case 9385: return "AllocationMementoMap";
    case 9425: return "ArrayBoilerplateDescriptionMap";
    case 9465: return "AsmWasmDataMap";
    case 9505: return "AsyncGeneratorRequestMap";
    case 9545: return "BreakPointMap";
    case 9585: return "BreakPointInfoMap";
    case 9625: return "CallSiteInfoMap";
    case 9665: return "ClassPositionsMap";
    case 9705: return "DebugInfoMap";
    case 9745: return "EnumCacheMap";
    case 9785: return "ErrorStackDataMap";
    case 9825: return "FunctionTemplateRareDataMap";
    case 9865: return "InterceptorInfoMap";
    case 9905: return "InterpreterDataMap";
    case 9945: return "ModuleRequestMap";
    case 9985: return "PromiseCapabilityMap";
    case 10025: return "PromiseOnStackMap";
    case 10065: return "PromiseReactionMap";
    case 10105: return "PropertyDescriptorObjectMap";
    case 10145: return "PrototypeInfoMap";
    case 10185: return "RegExpBoilerplateDescriptionMap";
    case 10225: return "ScriptMap";
    case 10265: return "ScriptOrModuleMap";
    case 10305: return "SourceTextModuleInfoEntryMap";
    case 10345: return "StackFrameInfoMap";
    case 10385: return "TemplateObjectDescriptionMap";
    case 10425: return "Tuple2Map";
    case 10465: return "WasmExceptionTagMap";
    case 10505: return "WasmIndirectFunctionTableMap";
    case 10545: return "AllocationSiteWithWeakNextMap";
    case 10585: return "AllocationSiteWithoutWeakNextMap";
    case 10625: return "LoadHandler1Map";
    case 10665: return "LoadHandler2Map";
    case 10705: return "LoadHandler3Map";
    case 10745: return "StoreHandler0Map";
    case 10785: return "StoreHandler1Map";
    case 10825: return "StoreHandler2Map";
    case 10865: return "StoreHandler3Map";
    case 10933: return "ScopeInfoMap";
    case 10973: return "ModuleInfoMap";
    case 11013: return "ClosureFeedbackCellArrayMap";
    case 11053: return "FeedbackVectorMap";
    case 11093: return "HeapNumberMap";
    case 11133: return "SymbolMap";
    case 11173: return "ForeignMap";
    case 11213: return "MegaDomHandlerMap";
    case 11253: return "BooleanMap";
    case 11293: return "UninitializedMap";
    case 11333: return "ArgumentsMarkerMap";
    case 11373: return "ExceptionMap";
    case 11413: return "TerminationExceptionMap";
    case 11453: return "OptimizedOutMap";
    case 11493: return "StaleRegisterMap";
    case 11533: return "SelfReferenceMarkerMap";
    case 11573: return "BasicBlockCountersMarkerMap";
    case 11613: return "BigIntMap";
    case 11653: return "StringMap";
    case 11693: return "OneByteStringMap";
    case 11733: return "ConsStringMap";
    case 11773: return "ConsOneByteStringMap";
    case 11813: return "SlicedStringMap";
    case 11853: return "SlicedOneByteStringMap";
    case 11893: return "ExternalStringMap";
    case 11933: return "ExternalOneByteStringMap";
    case 11973: return "UncachedExternalStringMap";
    case 12013: return "UncachedExternalOneByteStringMap";
    case 12053: return "InternalizedStringMap";
    case 12093: return "OneByteInternalizedStringMap";
    case 12133: return "ExternalInternalizedStringMap";
    case 12173: return "ExternalOneByteInternalizedStringMap";
    case 12213: return "UncachedExternalInternalizedStringMap";
    case 12253: return "UncachedExternalOneByteInternalizedStringMap";
    case 12293: return "ThinStringMap";
    case 12333: return "ThinOneByteStringMap";
    case 12373: return "SharedStringMap";
    case 12413: return "SharedOneByteStringMap";
    case 12453: return "SharedExternalStringMap";
    case 12493: return "SharedExternalOneByteStringMap";
    case 12533: return "SharedUncachedExternalStringMap";
    case 12573: return "SharedUncachedExternalOneByteStringMap";
    case 12613: return "SharedThinStringMap";
    case 12653: return "SharedThinOneByteStringMap";
    case 12693: return "FixedDoubleArrayMap";
    case 12733: return "FeedbackMetadataArrayMap";
    case 12773: return "ByteArrayMap";
    case 12813: return "BytecodeArrayMap";
    case 12853: return "FreeSpaceMap";
    case 12893: return "PropertyArrayMap";
    case 12933: return "SmallOrderedHashMapMap";
    case 12973: return "SmallOrderedHashSetMap";
    case 13013: return "SmallOrderedNameDictionaryMap";
    case 13053: return "UncompiledDataWithoutPreparseDataMap";
    case 13093: return "UncompiledDataWithPreparseDataMap";
    case 13133: return "UncompiledDataWithoutPreparseDataWithJobMap";
    case 13173: return "UncompiledDataWithPreparseDataAndJobMap";
    case 13213: return "OnHeapBasicBlockProfilerDataMap";
    case 13253: return "TurbofanBitsetTypeMap";
    case 13293: return "TurbofanUnionTypeMap";
    case 13333: return "TurbofanRangeTypeMap";
    case 13373: return "TurbofanHeapConstantTypeMap";
    case 13413: return "TurbofanOtherNumberConstantTypeMap";
    case 13453: return "TurboshaftWord32TypeMap";
    case 13493: return "TurboshaftWord32RangeTypeMap";
    case 13533: return "TurboshaftWord64TypeMap";
    case 13573: return "TurboshaftWord64RangeTypeMap";
    case 13613: return "TurboshaftFloat64TypeMap";
    case 13653: return "TurboshaftFloat64RangeTypeMap";
    case 13693: return "InternalClassMap";
    case 13733: return "SmiPairMap";
    case 13773: return "SmiBoxMap";
    case 13813: return "ExportedSubClassBaseMap";
    case 13853: return "ExportedSubClassMap";
    case 13893: return "AbstractInternalClassSubclass1Map";
    case 13933: return "AbstractInternalClassSubclass2Map";
    case 13973: return "ExportedSubClass2Map";
    case 14013: return "SortStateMap";
    case 14053: return "WasmStringViewIterMap";
    case 14093: return "SloppyArgumentsElementsMap";
    case 14133: return "StrongDescriptorArrayMap";
    case 14173: return "TurboshaftWord32SetTypeMap";
    case 14213: return "TurboshaftWord64SetTypeMap";
    case 14253: return "TurboshaftFloat64SetTypeMap";
    case 14293: return "InternalClassWithSmiElementsMap";
    case 14333: return "InternalClassWithStructElementsMap";
    case 14373: return "InstructionStreamMap";
    case 14413: return "CellMap";
    case 14461: return "GlobalPropertyCellMap";
    case 14501: return "OnePointerFillerMap";
    case 14541: return "TwoPointerFillerMap";
    case 14581: return "NoClosuresCellMap";
    case 14621: return "OneClosureCellMap";
    case 14661: return "ManyClosuresCellMap";
    case 14701: return "TransitionArrayMap";
    case 14741: return "HashTableMap";
    case 14781: return "OrderedHashMapMap";
    case 14821: return "OrderedHashSetMap";
    case 14861: return "OrderedNameDictionaryMap";
    case 14901: return "NameDictionaryMap";
    case 14941: return "SwissNameDictionaryMap";
    case 14981: return "GlobalDictionaryMap";
    case 15021: return "NumberDictionaryMap";
    case 15061: return "SimpleNumberDictionaryMap";
    case 15101: return "NameToIndexHashTableMap";
    case 15141: return "RegisteredSymbolTableMap";
    case 15181: return "EmbedderDataArrayMap";
    case 15221: return "EphemeronHashTableMap";
    case 15261: return "ArrayListMap";
    case 15301: return "ScriptContextTableMap";
    case 15341: return "ObjectBoilerplateDescriptionMap";
    case 15381: return "CoverageInfoMap";
    case 15421: return "AccessorInfoMap";
    case 15461: return "SideEffectCallHandlerInfoMap";
    case 15501: return "SideEffectFreeCallHandlerInfoMap";
    case 15541: return "NextCallSideEffectFreeCallHandlerInfoMap";
    case 15581: return "PreparseDataMap";
    case 15621: return "SharedFunctionInfoMap";
    case 15661: return "SourceTextModuleMap";
    case 15701: return "SyntheticModuleMap";
    case 15741: return "CodeMap";
    case 15781: return "WasmApiFunctionRefMap";
    case 15821: return "WasmCapiFunctionDataMap";
    case 15861: return "WasmExportedFunctionDataMap";
    case 15901: return "WasmInternalFunctionMap";
    case 15941: return "WasmJSFunctionDataMap";
    case 15981: return "WasmResumeDataMap";
    case 16021: return "WasmTypeInfoMap";
    case 16061: return "WasmContinuationObjectMap";
    case 16101: return "WeakCellMap";
    case 8873: return "EmptyFixedArray";
    case 8881: return "EmptyWeakFixedArray";
    case 8889: return "EmptyWeakArrayList";
    case 8901: return "NullValue";
    case 8929: return "UndefinedValue";
    case 8957: return "TheHoleValue";
    case 10905: return "EmptyEnumCache";
    case 10917: return "EmptyDescriptorArray";
    case 14453: return "InvalidPrototypeValidityCell";
    case 16141: return "EmptyArrayList";
    case 16153: return "EmptyScopeInfo";
    case 16169: return "EmptyObjectBoilerplateDescription";
    case 16181: return "EmptyArrayBoilerplateDescription";
    case 16193: return "TrueValue";
    case 16221: return "FalseValue";
    case 16249: return "EmptyByteArray";
    case 16257: return "EmptyPropertyArray";
    case 16265: return "EmptyClosureFeedbackCellArray";
    case 16273: return "NoOpInterceptorInfo";
    case 16313: return "MinusZeroValue";
    case 16325: return "NanValue";
    case 16337: return "HoleNanValue";
    case 16349: return "InfinityValue";
    case 16361: return "MinusInfinityValue";
    case 16373: return "MaxSafeInteger";
    case 16385: return "MaxUInt32";
    case 16397: return "SmiMinValue";
    case 16409: return "SmiMaxValuePlusOne";
    case 16421: return "HashSeed";
    case 16437: return "SingleCharacterStringTable";
    case 21565: return "empty_string";
    case 31513: return "UninitializedValue";
    case 31569: return "ArgumentsMarker";
    case 31625: return "TerminationException";
    case 31689: return "Exception";
    case 31717: return "OptimizedOut";
    case 31773: return "StaleRegister";
    case 31829: return "SelfReferenceMarker";
    case 31893: return "BasicBlockCountersMarker";
    case 33225: return "EmptyPropertyDictionary";
    case 33265: return "EmptySymbolTable";
    case 33293: return "EmptySlowElementDictionary";
    case 33329: return "EmptyOrderedHashMap";
    case 33349: return "EmptyOrderedHashSet";
    case 33369: return "EmptyOrderedPropertyDictionary";
    case 33405: return "EmptySwissPropertyDictionary";
    case 33437: return "EmptyFeedbackMetadata";
    case 33449: return "GlobalThisBindingScopeInfo";
    case 33481: return "EmptyFunctionScopeInfo";
    case 33517: return "NativeScopeInfo";
    case 33541: return "ShadowRealmScopeInfo";
    case 33565: return "OffHeapTrampolineRelocationInfo";
    default: return "";
  }
}

int FindKnownMapInstanceTypeInMapSpace(uintptr_t offset) {
  switch (offset) {
    default: return -1;
  }
}

int FindKnownMapInstanceTypeInOldSpace(uintptr_t offset) {
  switch (offset) {
    case 17341: return 2114;
    case 17381: return 2118;
    default: return -1;
  }
}

int FindKnownMapInstanceTypeInReadOnlySpace(uintptr_t offset) {
  switch (offset) {
    case 8513: return 255;
    case 8553: return 175;
    case 8593: return 240;
    case 8633: return 273;
    case 8673: return 175;
    case 8713: return 236;
    case 8753: return 131;
    case 8793: return 131;
    case 8833: return 131;
    case 8985: return 132;
    case 9025: return 133;
    case 9065: return 134;
    case 9105: return 135;
    case 9145: return 136;
    case 9185: return 139;
    case 9225: return 140;
    case 9265: return 141;
    case 9305: return 142;
    case 9345: return 143;
    case 9385: return 144;
    case 9425: return 146;
    case 9465: return 147;
    case 9505: return 148;
    case 9545: return 149;
    case 9585: return 150;
    case 9625: return 151;
    case 9665: return 152;
    case 9705: return 153;
    case 9745: return 154;
    case 9785: return 155;
    case 9825: return 157;
    case 9865: return 158;
    case 9905: return 159;
    case 9945: return 160;
    case 9985: return 161;
    case 10025: return 162;
    case 10065: return 163;
    case 10105: return 164;
    case 10145: return 165;
    case 10185: return 166;
    case 10225: return 167;
    case 10265: return 168;
    case 10305: return 169;
    case 10345: return 170;
    case 10385: return 171;
    case 10425: return 172;
    case 10465: return 173;
    case 10505: return 174;
    case 10545: return 145;
    case 10585: return 145;
    case 10625: return 137;
    case 10665: return 137;
    case 10705: return 137;
    case 10745: return 138;
    case 10785: return 138;
    case 10825: return 138;
    case 10865: return 138;
    case 10933: return 261;
    case 10973: return 175;
    case 11013: return 187;
    case 11053: return 249;
    case 11093: return 130;
    case 11133: return 128;
    case 11173: return 204;
    case 11213: return 256;
    case 11253: return 131;
    case 11293: return 131;
    case 11333: return 131;
    case 11373: return 131;
    case 11413: return 131;
    case 11453: return 131;
    case 11493: return 131;
    case 11533: return 131;
    case 11573: return 131;
    case 11613: return 129;
    case 11653: return 32;
    case 11693: return 40;
    case 11733: return 33;
    case 11773: return 41;
    case 11813: return 35;
    case 11853: return 43;
    case 11893: return 34;
    case 11933: return 42;
    case 11973: return 50;
    case 12013: return 58;
    case 12053: return 0;
    case 12093: return 8;
    case 12133: return 2;
    case 12173: return 10;
    case 12213: return 18;
    case 12253: return 26;
    case 12293: return 37;
    case 12333: return 45;
    case 12373: return 96;
    case 12413: return 104;
    case 12453: return 98;
    case 12493: return 106;
    case 12533: return 114;
    case 12573: return 122;
    case 12613: return 101;
    case 12653: return 109;
    case 12693: return 192;
    case 12733: return 248;
    case 12773: return 190;
    case 12813: return 191;
    case 12853: return 251;
    case 12893: return 259;
    case 12933: return 231;
    case 12973: return 232;
    case 13013: return 233;
    case 13053: return 222;
    case 13093: return 220;
    case 13133: return 223;
    case 13173: return 221;
    case 13213: return 257;
    case 13253: return 215;
    case 13293: return 219;
    case 13333: return 218;
    case 13373: return 216;
    case 13413: return 217;
    case 13453: return 198;
    case 13493: return 199;
    case 13533: return 201;
    case 13573: return 202;
    case 13613: return 195;
    case 13653: return 196;
    case 13693: return 253;
    case 13733: return 264;
    case 13773: return 263;
    case 13813: return 228;
    case 13853: return 229;
    case 13893: return 234;
    case 13933: return 235;
    case 13973: return 230;
    case 14013: return 265;
    case 14053: return 271;
    case 14093: return 194;
    case 14133: return 237;
    case 14173: return 200;
    case 14213: return 203;
    case 14253: return 197;
    case 14293: return 193;
    case 14333: return 254;
    case 14373: return 252;
    case 14413: return 244;
    case 14461: return 260;
    case 14501: return 250;
    case 14541: return 250;
    case 14581: return 156;
    case 14621: return 156;
    case 14661: return 156;
    case 14701: return 241;
    case 14741: return 176;
    case 14781: return 182;
    case 14821: return 183;
    case 14861: return 184;
    case 14901: return 179;
    case 14941: return 266;
    case 14981: return 178;
    case 15021: return 181;
    case 15061: return 186;
    case 15101: return 180;
    case 15141: return 185;
    case 15181: return 247;
    case 15221: return 177;
    case 15261: return 175;
    case 15301: return 189;
    case 15341: return 188;
    case 15381: return 246;
    case 15421: return 242;
    case 15461: return 243;
    case 15501: return 243;
    case 15541: return 243;
    case 15581: return 258;
    case 15621: return 262;
    case 15661: return 238;
    case 15701: return 239;
    case 15741: return 245;
    case 15781: return 267;
    case 15821: return 225;
    case 15861: return 226;
    case 15901: return 269;
    case 15941: return 227;
    case 15981: return 270;
    case 16021: return 272;
    case 16061: return 268;
    case 16101: return 274;
    default: return -1;
  }
}

void FillInUnknownHeapAddresses(d::HeapAddresses* heap_addresses, uintptr_t any_uncompressed_ptr) {
  if (heap_addresses->any_heap_pointer == 0) {
    heap_addresses->any_heap_pointer = any_uncompressed_ptr;
  }
  if (heap_addresses->old_space_first_page == 0) {
    heap_addresses->old_space_first_page = i::V8HeapCompressionScheme::DecompressTaggedPointer(any_uncompressed_ptr, 786432);
  }
  if (heap_addresses->read_only_space_first_page == 0) {
    heap_addresses->read_only_space_first_page = i::V8HeapCompressionScheme::DecompressTaggedPointer(any_uncompressed_ptr, 0);
  }
}

}
}
}
