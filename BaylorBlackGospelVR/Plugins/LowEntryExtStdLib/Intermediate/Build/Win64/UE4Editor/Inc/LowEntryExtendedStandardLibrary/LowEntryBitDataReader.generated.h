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
class ULowEntryBitDataReader;
#ifdef LOWENTRYEXTENDEDSTANDARDLIBRARY_LowEntryBitDataReader_generated_h
#error "LowEntryBitDataReader.generated.h already included, missing '#pragma once' in LowEntryBitDataReader.h"
#endif
#define LOWENTRYEXTENDEDSTANDARDLIBRARY_LowEntryBitDataReader_generated_h

#define Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_Classes_LowEntryBitDataReader_h_18_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetStringUtf8Array) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<FString>*)Z_Param__Result=P_THIS->GetStringUtf8Array(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetBooleanArray) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<bool>*)Z_Param__Result=P_THIS->GetBooleanArray(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetDoubleBytesArray) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<ULowEntryDouble*>*)Z_Param__Result=P_THIS->GetDoubleBytesArray(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetFloatArray) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<float>*)Z_Param__Result=P_THIS->GetFloatArray(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetLongBytesArray) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<ULowEntryLong*>*)Z_Param__Result=P_THIS->GetLongBytesArray(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetPositiveInteger3Array) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<int32>*)Z_Param__Result=P_THIS->GetPositiveInteger3Array(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetPositiveInteger2Array) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<int32>*)Z_Param__Result=P_THIS->GetPositiveInteger2Array(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetPositiveInteger1Array) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<int32>*)Z_Param__Result=P_THIS->GetPositiveInteger1Array(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetIntegerArray) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<int32>*)Z_Param__Result=P_THIS->GetIntegerArray(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetByteArray) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<uint8>*)Z_Param__Result=P_THIS->GetByteArray(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetIntegerArrayMostSignificantBits) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_BitCount); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<int32>*)Z_Param__Result=P_THIS->GetIntegerArrayMostSignificantBits(Z_Param_BitCount); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetIntegerArrayLeastSignificantBits) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_BitCount); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<int32>*)Z_Param__Result=P_THIS->GetIntegerArrayLeastSignificantBits(Z_Param_BitCount); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetByteArrayMostSignificantBits) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_BitCount); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<uint8>*)Z_Param__Result=P_THIS->GetByteArrayMostSignificantBits(Z_Param_BitCount); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetByteArrayLeastSignificantBits) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_BitCount); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<uint8>*)Z_Param__Result=P_THIS->GetByteArrayLeastSignificantBits(Z_Param_BitCount); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetBitArray) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<bool>*)Z_Param__Result=P_THIS->GetBitArray(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetStringUtf8) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=P_THIS->GetStringUtf8(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetBoolean) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->GetBoolean(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetDoubleBytes) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryDouble**)Z_Param__Result=P_THIS->GetDoubleBytes(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetFloat) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=P_THIS->GetFloat(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetLongBytes) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryLong**)Z_Param__Result=P_THIS->GetLongBytes(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetPositiveInteger3) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetPositiveInteger3(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetPositiveInteger2) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetPositiveInteger2(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetPositiveInteger1) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetPositiveInteger1(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetInteger) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetInteger(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetByte) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(uint8*)Z_Param__Result=P_THIS->GetByte(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetIntegerMostSignificantBits) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_BitCount); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetIntegerMostSignificantBits(Z_Param_BitCount); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetIntegerLeastSignificantBits) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_BitCount); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetIntegerLeastSignificantBits(Z_Param_BitCount); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetByteMostSignificantBits) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_BitCount); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(uint8*)Z_Param__Result=P_THIS->GetByteMostSignificantBits(Z_Param_BitCount); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetByteLeastSignificantBits) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_BitCount); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(uint8*)Z_Param__Result=P_THIS->GetByteLeastSignificantBits(Z_Param_BitCount); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetBit) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->GetBit(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRemaining) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->Remaining(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execEmpty) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Empty(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execReset) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Reset(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetPosition) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Position_); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetPosition(Z_Param_Position_); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetPosition) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetPosition(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetClone) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryBitDataReader**)Z_Param__Result=P_THIS->GetClone(); \
		P_NATIVE_END; \
	}


#define Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_Classes_LowEntryBitDataReader_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetStringUtf8Array) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<FString>*)Z_Param__Result=P_THIS->GetStringUtf8Array(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetBooleanArray) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<bool>*)Z_Param__Result=P_THIS->GetBooleanArray(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetDoubleBytesArray) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<ULowEntryDouble*>*)Z_Param__Result=P_THIS->GetDoubleBytesArray(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetFloatArray) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<float>*)Z_Param__Result=P_THIS->GetFloatArray(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetLongBytesArray) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<ULowEntryLong*>*)Z_Param__Result=P_THIS->GetLongBytesArray(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetPositiveInteger3Array) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<int32>*)Z_Param__Result=P_THIS->GetPositiveInteger3Array(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetPositiveInteger2Array) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<int32>*)Z_Param__Result=P_THIS->GetPositiveInteger2Array(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetPositiveInteger1Array) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<int32>*)Z_Param__Result=P_THIS->GetPositiveInteger1Array(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetIntegerArray) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<int32>*)Z_Param__Result=P_THIS->GetIntegerArray(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetByteArray) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<uint8>*)Z_Param__Result=P_THIS->GetByteArray(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetIntegerArrayMostSignificantBits) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_BitCount); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<int32>*)Z_Param__Result=P_THIS->GetIntegerArrayMostSignificantBits(Z_Param_BitCount); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetIntegerArrayLeastSignificantBits) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_BitCount); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<int32>*)Z_Param__Result=P_THIS->GetIntegerArrayLeastSignificantBits(Z_Param_BitCount); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetByteArrayMostSignificantBits) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_BitCount); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<uint8>*)Z_Param__Result=P_THIS->GetByteArrayMostSignificantBits(Z_Param_BitCount); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetByteArrayLeastSignificantBits) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_BitCount); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<uint8>*)Z_Param__Result=P_THIS->GetByteArrayLeastSignificantBits(Z_Param_BitCount); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetBitArray) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<bool>*)Z_Param__Result=P_THIS->GetBitArray(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetStringUtf8) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=P_THIS->GetStringUtf8(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetBoolean) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->GetBoolean(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetDoubleBytes) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryDouble**)Z_Param__Result=P_THIS->GetDoubleBytes(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetFloat) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=P_THIS->GetFloat(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetLongBytes) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryLong**)Z_Param__Result=P_THIS->GetLongBytes(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetPositiveInteger3) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetPositiveInteger3(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetPositiveInteger2) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetPositiveInteger2(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetPositiveInteger1) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetPositiveInteger1(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetInteger) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetInteger(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetByte) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(uint8*)Z_Param__Result=P_THIS->GetByte(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetIntegerMostSignificantBits) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_BitCount); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetIntegerMostSignificantBits(Z_Param_BitCount); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetIntegerLeastSignificantBits) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_BitCount); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetIntegerLeastSignificantBits(Z_Param_BitCount); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetByteMostSignificantBits) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_BitCount); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(uint8*)Z_Param__Result=P_THIS->GetByteMostSignificantBits(Z_Param_BitCount); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetByteLeastSignificantBits) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_BitCount); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(uint8*)Z_Param__Result=P_THIS->GetByteLeastSignificantBits(Z_Param_BitCount); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetBit) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->GetBit(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRemaining) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->Remaining(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execEmpty) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Empty(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execReset) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Reset(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetPosition) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Position_); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetPosition(Z_Param_Position_); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetPosition) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetPosition(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetClone) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryBitDataReader**)Z_Param__Result=P_THIS->GetClone(); \
		P_NATIVE_END; \
	}


#define Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_Classes_LowEntryBitDataReader_h_18_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesULowEntryBitDataReader(); \
	friend struct Z_Construct_UClass_ULowEntryBitDataReader_Statics; \
public: \
	DECLARE_CLASS(ULowEntryBitDataReader, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/LowEntryExtendedStandardLibrary"), NO_API) \
	DECLARE_SERIALIZER(ULowEntryBitDataReader)


#define Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_Classes_LowEntryBitDataReader_h_18_INCLASS \
private: \
	static void StaticRegisterNativesULowEntryBitDataReader(); \
	friend struct Z_Construct_UClass_ULowEntryBitDataReader_Statics; \
public: \
	DECLARE_CLASS(ULowEntryBitDataReader, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/LowEntryExtendedStandardLibrary"), NO_API) \
	DECLARE_SERIALIZER(ULowEntryBitDataReader)


#define Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_Classes_LowEntryBitDataReader_h_18_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ULowEntryBitDataReader(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ULowEntryBitDataReader) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ULowEntryBitDataReader); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ULowEntryBitDataReader); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ULowEntryBitDataReader(ULowEntryBitDataReader&&); \
	NO_API ULowEntryBitDataReader(const ULowEntryBitDataReader&); \
public:


#define Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_Classes_LowEntryBitDataReader_h_18_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ULowEntryBitDataReader(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ULowEntryBitDataReader(ULowEntryBitDataReader&&); \
	NO_API ULowEntryBitDataReader(const ULowEntryBitDataReader&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ULowEntryBitDataReader); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ULowEntryBitDataReader); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ULowEntryBitDataReader)


#define Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_Classes_LowEntryBitDataReader_h_18_PRIVATE_PROPERTY_OFFSET
#define Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_Classes_LowEntryBitDataReader_h_15_PROLOG
#define Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_Classes_LowEntryBitDataReader_h_18_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_Classes_LowEntryBitDataReader_h_18_PRIVATE_PROPERTY_OFFSET \
	Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_Classes_LowEntryBitDataReader_h_18_RPC_WRAPPERS \
	Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_Classes_LowEntryBitDataReader_h_18_INCLASS \
	Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_Classes_LowEntryBitDataReader_h_18_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_Classes_LowEntryBitDataReader_h_18_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_Classes_LowEntryBitDataReader_h_18_PRIVATE_PROPERTY_OFFSET \
	Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_Classes_LowEntryBitDataReader_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
	Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_Classes_LowEntryBitDataReader_h_18_INCLASS_NO_PURE_DECLS \
	Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_Classes_LowEntryBitDataReader_h_18_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class LowEntryBitDataReader."); \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_Classes_LowEntryBitDataReader_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
