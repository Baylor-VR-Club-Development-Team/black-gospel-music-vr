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
#ifdef LOWENTRYEXTENDEDSTANDARDLIBRARY_LowEntryByteDataWriter_generated_h
#error "LowEntryByteDataWriter.generated.h already included, missing '#pragma once' in LowEntryByteDataWriter.h"
#endif
#define LOWENTRYEXTENDEDSTANDARDLIBRARY_LowEntryByteDataWriter_generated_h

#define Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_Classes_LowEntryByteDataWriter_h_21_RPC_WRAPPERS \
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
	}


#define Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_Classes_LowEntryByteDataWriter_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
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
	}


#define Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_Classes_LowEntryByteDataWriter_h_21_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesULowEntryByteDataWriter(); \
	friend struct Z_Construct_UClass_ULowEntryByteDataWriter_Statics; \
public: \
	DECLARE_CLASS(ULowEntryByteDataWriter, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/LowEntryExtendedStandardLibrary"), NO_API) \
	DECLARE_SERIALIZER(ULowEntryByteDataWriter)


#define Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_Classes_LowEntryByteDataWriter_h_21_INCLASS \
private: \
	static void StaticRegisterNativesULowEntryByteDataWriter(); \
	friend struct Z_Construct_UClass_ULowEntryByteDataWriter_Statics; \
public: \
	DECLARE_CLASS(ULowEntryByteDataWriter, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/LowEntryExtendedStandardLibrary"), NO_API) \
	DECLARE_SERIALIZER(ULowEntryByteDataWriter)


#define Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_Classes_LowEntryByteDataWriter_h_21_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ULowEntryByteDataWriter(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ULowEntryByteDataWriter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ULowEntryByteDataWriter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ULowEntryByteDataWriter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ULowEntryByteDataWriter(ULowEntryByteDataWriter&&); \
	NO_API ULowEntryByteDataWriter(const ULowEntryByteDataWriter&); \
public:


#define Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_Classes_LowEntryByteDataWriter_h_21_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ULowEntryByteDataWriter(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ULowEntryByteDataWriter(ULowEntryByteDataWriter&&); \
	NO_API ULowEntryByteDataWriter(const ULowEntryByteDataWriter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ULowEntryByteDataWriter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ULowEntryByteDataWriter); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ULowEntryByteDataWriter)


#define Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_Classes_LowEntryByteDataWriter_h_21_PRIVATE_PROPERTY_OFFSET
#define Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_Classes_LowEntryByteDataWriter_h_18_PROLOG
#define Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_Classes_LowEntryByteDataWriter_h_21_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_Classes_LowEntryByteDataWriter_h_21_PRIVATE_PROPERTY_OFFSET \
	Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_Classes_LowEntryByteDataWriter_h_21_RPC_WRAPPERS \
	Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_Classes_LowEntryByteDataWriter_h_21_INCLASS \
	Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_Classes_LowEntryByteDataWriter_h_21_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_Classes_LowEntryByteDataWriter_h_21_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_Classes_LowEntryByteDataWriter_h_21_PRIVATE_PROPERTY_OFFSET \
	Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_Classes_LowEntryByteDataWriter_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
	Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_Classes_LowEntryByteDataWriter_h_21_INCLASS_NO_PURE_DECLS \
	Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_Classes_LowEntryByteDataWriter_h_21_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class LowEntryByteDataWriter."); \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_Classes_LowEntryByteDataWriter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
