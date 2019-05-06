// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class ULowEntryDouble;
class ULowEntryLong;
#ifdef LOWENTRYEXTENDEDSTANDARDLIBRARY_LowEntryBitDataWriter_generated_h
#error "LowEntryBitDataWriter.generated.h already included, missing '#pragma once' in LowEntryBitDataWriter.h"
#endif
#define LOWENTRYEXTENDEDSTANDARDLIBRARY_LowEntryBitDataWriter_generated_h

#define BaylorBlackGospelVR_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_Classes_LowEntryBitDataWriter_h_21_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execAddStringUtf8Array) \
	{ \
		P_GET_TARRAY_REF(FString,Z_Param_Out_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->AddStringUtf8Array(Z_Param_Out_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddBooleanArray) \
	{ \
		P_GET_TARRAY_REF(bool,Z_Param_Out_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->AddBooleanArray(Z_Param_Out_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddDoubleBytesArray) \
	{ \
		P_GET_TARRAY_REF(ULowEntryDouble*,Z_Param_Out_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->AddDoubleBytesArray(Z_Param_Out_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddFloatArray) \
	{ \
		P_GET_TARRAY_REF(float,Z_Param_Out_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->AddFloatArray(Z_Param_Out_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddLongBytesArray) \
	{ \
		P_GET_TARRAY_REF(ULowEntryLong*,Z_Param_Out_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->AddLongBytesArray(Z_Param_Out_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddPositiveInteger3Array) \
	{ \
		P_GET_TARRAY_REF(int32,Z_Param_Out_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->AddPositiveInteger3Array(Z_Param_Out_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddPositiveInteger2Array) \
	{ \
		P_GET_TARRAY_REF(int32,Z_Param_Out_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->AddPositiveInteger2Array(Z_Param_Out_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddPositiveInteger1Array) \
	{ \
		P_GET_TARRAY_REF(int32,Z_Param_Out_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->AddPositiveInteger1Array(Z_Param_Out_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddIntegerArray) \
	{ \
		P_GET_TARRAY_REF(int32,Z_Param_Out_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->AddIntegerArray(Z_Param_Out_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddByteArray) \
	{ \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->AddByteArray(Z_Param_Out_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddIntegerArrayMostSignificantBits) \
	{ \
		P_GET_TARRAY_REF(int32,Z_Param_Out_Value); \
		P_GET_PROPERTY(UIntProperty,Z_Param_BitCount); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->AddIntegerArrayMostSignificantBits(Z_Param_Out_Value,Z_Param_BitCount); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddIntegerArrayLeastSignificantBits) \
	{ \
		P_GET_TARRAY_REF(int32,Z_Param_Out_Value); \
		P_GET_PROPERTY(UIntProperty,Z_Param_BitCount); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->AddIntegerArrayLeastSignificantBits(Z_Param_Out_Value,Z_Param_BitCount); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddByteArrayMostSignificantBits) \
	{ \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_Value); \
		P_GET_PROPERTY(UIntProperty,Z_Param_BitCount); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->AddByteArrayMostSignificantBits(Z_Param_Out_Value,Z_Param_BitCount); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddByteArrayLeastSignificantBits) \
	{ \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_Value); \
		P_GET_PROPERTY(UIntProperty,Z_Param_BitCount); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->AddByteArrayLeastSignificantBits(Z_Param_Out_Value,Z_Param_BitCount); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddBitArray) \
	{ \
		P_GET_TARRAY_REF(bool,Z_Param_Out_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->AddBitArray(Z_Param_Out_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddStringUtf8) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->AddStringUtf8(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddBoolean) \
	{ \
		P_GET_UBOOL(Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->AddBoolean(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddDoubleBytes) \
	{ \
		P_GET_OBJECT(ULowEntryDouble,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->AddDoubleBytes(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddFloat) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->AddFloat(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddLongBytes) \
	{ \
		P_GET_OBJECT(ULowEntryLong,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->AddLongBytes(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddPositiveInteger3) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->AddPositiveInteger3(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddPositiveInteger2) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->AddPositiveInteger2(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddPositiveInteger1) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->AddPositiveInteger1(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddInteger) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->AddInteger(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddByte) \
	{ \
		P_GET_PROPERTY(UByteProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->AddByte(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddIntegerMostSignificantBits) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Value); \
		P_GET_PROPERTY(UIntProperty,Z_Param_BitCount); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->AddIntegerMostSignificantBits(Z_Param_Value,Z_Param_BitCount); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddIntegerLeastSignificantBits) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Value); \
		P_GET_PROPERTY(UIntProperty,Z_Param_BitCount); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->AddIntegerLeastSignificantBits(Z_Param_Value,Z_Param_BitCount); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddByteMostSignificantBits) \
	{ \
		P_GET_PROPERTY(UByteProperty,Z_Param_Value); \
		P_GET_PROPERTY(UIntProperty,Z_Param_BitCount); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->AddByteMostSignificantBits(Z_Param_Value,Z_Param_BitCount); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddByteLeastSignificantBits) \
	{ \
		P_GET_PROPERTY(UByteProperty,Z_Param_Value); \
		P_GET_PROPERTY(UIntProperty,Z_Param_BitCount); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->AddByteLeastSignificantBits(Z_Param_Value,Z_Param_BitCount); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddBit) \
	{ \
		P_GET_UBOOL(Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->AddBit(Z_Param_Value); \
		P_NATIVE_END; \
	}


#define BaylorBlackGospelVR_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_Classes_LowEntryBitDataWriter_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execAddStringUtf8Array) \
	{ \
		P_GET_TARRAY_REF(FString,Z_Param_Out_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->AddStringUtf8Array(Z_Param_Out_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddBooleanArray) \
	{ \
		P_GET_TARRAY_REF(bool,Z_Param_Out_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->AddBooleanArray(Z_Param_Out_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddDoubleBytesArray) \
	{ \
		P_GET_TARRAY_REF(ULowEntryDouble*,Z_Param_Out_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->AddDoubleBytesArray(Z_Param_Out_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddFloatArray) \
	{ \
		P_GET_TARRAY_REF(float,Z_Param_Out_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->AddFloatArray(Z_Param_Out_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddLongBytesArray) \
	{ \
		P_GET_TARRAY_REF(ULowEntryLong*,Z_Param_Out_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->AddLongBytesArray(Z_Param_Out_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddPositiveInteger3Array) \
	{ \
		P_GET_TARRAY_REF(int32,Z_Param_Out_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->AddPositiveInteger3Array(Z_Param_Out_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddPositiveInteger2Array) \
	{ \
		P_GET_TARRAY_REF(int32,Z_Param_Out_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->AddPositiveInteger2Array(Z_Param_Out_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddPositiveInteger1Array) \
	{ \
		P_GET_TARRAY_REF(int32,Z_Param_Out_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->AddPositiveInteger1Array(Z_Param_Out_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddIntegerArray) \
	{ \
		P_GET_TARRAY_REF(int32,Z_Param_Out_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->AddIntegerArray(Z_Param_Out_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddByteArray) \
	{ \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->AddByteArray(Z_Param_Out_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddIntegerArrayMostSignificantBits) \
	{ \
		P_GET_TARRAY_REF(int32,Z_Param_Out_Value); \
		P_GET_PROPERTY(UIntProperty,Z_Param_BitCount); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->AddIntegerArrayMostSignificantBits(Z_Param_Out_Value,Z_Param_BitCount); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddIntegerArrayLeastSignificantBits) \
	{ \
		P_GET_TARRAY_REF(int32,Z_Param_Out_Value); \
		P_GET_PROPERTY(UIntProperty,Z_Param_BitCount); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->AddIntegerArrayLeastSignificantBits(Z_Param_Out_Value,Z_Param_BitCount); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddByteArrayMostSignificantBits) \
	{ \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_Value); \
		P_GET_PROPERTY(UIntProperty,Z_Param_BitCount); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->AddByteArrayMostSignificantBits(Z_Param_Out_Value,Z_Param_BitCount); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddByteArrayLeastSignificantBits) \
	{ \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_Value); \
		P_GET_PROPERTY(UIntProperty,Z_Param_BitCount); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->AddByteArrayLeastSignificantBits(Z_Param_Out_Value,Z_Param_BitCount); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddBitArray) \
	{ \
		P_GET_TARRAY_REF(bool,Z_Param_Out_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->AddBitArray(Z_Param_Out_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddStringUtf8) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->AddStringUtf8(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddBoolean) \
	{ \
		P_GET_UBOOL(Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->AddBoolean(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddDoubleBytes) \
	{ \
		P_GET_OBJECT(ULowEntryDouble,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->AddDoubleBytes(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddFloat) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->AddFloat(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddLongBytes) \
	{ \
		P_GET_OBJECT(ULowEntryLong,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->AddLongBytes(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddPositiveInteger3) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->AddPositiveInteger3(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddPositiveInteger2) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->AddPositiveInteger2(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddPositiveInteger1) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->AddPositiveInteger1(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddInteger) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->AddInteger(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddByte) \
	{ \
		P_GET_PROPERTY(UByteProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->AddByte(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddIntegerMostSignificantBits) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Value); \
		P_GET_PROPERTY(UIntProperty,Z_Param_BitCount); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->AddIntegerMostSignificantBits(Z_Param_Value,Z_Param_BitCount); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddIntegerLeastSignificantBits) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Value); \
		P_GET_PROPERTY(UIntProperty,Z_Param_BitCount); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->AddIntegerLeastSignificantBits(Z_Param_Value,Z_Param_BitCount); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddByteMostSignificantBits) \
	{ \
		P_GET_PROPERTY(UByteProperty,Z_Param_Value); \
		P_GET_PROPERTY(UIntProperty,Z_Param_BitCount); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->AddByteMostSignificantBits(Z_Param_Value,Z_Param_BitCount); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddByteLeastSignificantBits) \
	{ \
		P_GET_PROPERTY(UByteProperty,Z_Param_Value); \
		P_GET_PROPERTY(UIntProperty,Z_Param_BitCount); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->AddByteLeastSignificantBits(Z_Param_Value,Z_Param_BitCount); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddBit) \
	{ \
		P_GET_UBOOL(Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->AddBit(Z_Param_Value); \
		P_NATIVE_END; \
	}


#define BaylorBlackGospelVR_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_Classes_LowEntryBitDataWriter_h_21_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesULowEntryBitDataWriter(); \
	friend struct Z_Construct_UClass_ULowEntryBitDataWriter_Statics; \
public: \
	DECLARE_CLASS(ULowEntryBitDataWriter, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/LowEntryExtendedStandardLibrary"), NO_API) \
	DECLARE_SERIALIZER(ULowEntryBitDataWriter)


#define BaylorBlackGospelVR_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_Classes_LowEntryBitDataWriter_h_21_INCLASS \
private: \
	static void StaticRegisterNativesULowEntryBitDataWriter(); \
	friend struct Z_Construct_UClass_ULowEntryBitDataWriter_Statics; \
public: \
	DECLARE_CLASS(ULowEntryBitDataWriter, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/LowEntryExtendedStandardLibrary"), NO_API) \
	DECLARE_SERIALIZER(ULowEntryBitDataWriter)


#define BaylorBlackGospelVR_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_Classes_LowEntryBitDataWriter_h_21_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ULowEntryBitDataWriter(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ULowEntryBitDataWriter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ULowEntryBitDataWriter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ULowEntryBitDataWriter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ULowEntryBitDataWriter(ULowEntryBitDataWriter&&); \
	NO_API ULowEntryBitDataWriter(const ULowEntryBitDataWriter&); \
public:


#define BaylorBlackGospelVR_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_Classes_LowEntryBitDataWriter_h_21_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ULowEntryBitDataWriter(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ULowEntryBitDataWriter(ULowEntryBitDataWriter&&); \
	NO_API ULowEntryBitDataWriter(const ULowEntryBitDataWriter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ULowEntryBitDataWriter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ULowEntryBitDataWriter); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ULowEntryBitDataWriter)


#define BaylorBlackGospelVR_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_Classes_LowEntryBitDataWriter_h_21_PRIVATE_PROPERTY_OFFSET
#define BaylorBlackGospelVR_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_Classes_LowEntryBitDataWriter_h_18_PROLOG
#define BaylorBlackGospelVR_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_Classes_LowEntryBitDataWriter_h_21_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	BaylorBlackGospelVR_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_Classes_LowEntryBitDataWriter_h_21_PRIVATE_PROPERTY_OFFSET \
	BaylorBlackGospelVR_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_Classes_LowEntryBitDataWriter_h_21_RPC_WRAPPERS \
	BaylorBlackGospelVR_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_Classes_LowEntryBitDataWriter_h_21_INCLASS \
	BaylorBlackGospelVR_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_Classes_LowEntryBitDataWriter_h_21_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define BaylorBlackGospelVR_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_Classes_LowEntryBitDataWriter_h_21_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	BaylorBlackGospelVR_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_Classes_LowEntryBitDataWriter_h_21_PRIVATE_PROPERTY_OFFSET \
	BaylorBlackGospelVR_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_Classes_LowEntryBitDataWriter_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
	BaylorBlackGospelVR_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_Classes_LowEntryBitDataWriter_h_21_INCLASS_NO_PURE_DECLS \
	BaylorBlackGospelVR_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_Classes_LowEntryBitDataWriter_h_21_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class LowEntryBitDataWriter."); \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID BaylorBlackGospelVR_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_Classes_LowEntryBitDataWriter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
