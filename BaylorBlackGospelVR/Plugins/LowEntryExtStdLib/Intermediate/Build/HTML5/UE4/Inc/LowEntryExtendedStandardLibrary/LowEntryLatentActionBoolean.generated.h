// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UObject;
struct FLatentActionInfo;
#ifdef LOWENTRYEXTENDEDSTANDARDLIBRARY_LowEntryLatentActionBoolean_generated_h
#error "LowEntryLatentActionBoolean.generated.h already included, missing '#pragma once' in LowEntryLatentActionBoolean.h"
#endif
#define LOWENTRYEXTENDEDSTANDARDLIBRARY_LowEntryLatentActionBoolean_generated_h

#define Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_ClassesLatentAction_LowEntryLatentActionBoolean_h_17_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetResult) \
	{ \
		P_GET_UBOOL_REF(Z_Param_Out_Result_); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->GetResult(Z_Param_Out_Result_); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsDone) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->IsDone(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDone) \
	{ \
		P_GET_UBOOL(Z_Param_Result_); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Done(Z_Param_Result_); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execWaitTillDone) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_STRUCT(FLatentActionInfo,Z_Param_LatentInfo); \
		P_GET_UBOOL_REF(Z_Param_Out_Result_); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->WaitTillDone(Z_Param_WorldContextObject,Z_Param_LatentInfo,Z_Param_Out_Result_); \
		P_NATIVE_END; \
	}


#define Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_ClassesLatentAction_LowEntryLatentActionBoolean_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetResult) \
	{ \
		P_GET_UBOOL_REF(Z_Param_Out_Result_); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->GetResult(Z_Param_Out_Result_); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsDone) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->IsDone(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDone) \
	{ \
		P_GET_UBOOL(Z_Param_Result_); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Done(Z_Param_Result_); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execWaitTillDone) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_STRUCT(FLatentActionInfo,Z_Param_LatentInfo); \
		P_GET_UBOOL_REF(Z_Param_Out_Result_); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->WaitTillDone(Z_Param_WorldContextObject,Z_Param_LatentInfo,Z_Param_Out_Result_); \
		P_NATIVE_END; \
	}


#define Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_ClassesLatentAction_LowEntryLatentActionBoolean_h_17_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesULowEntryLatentActionBoolean(); \
	friend struct Z_Construct_UClass_ULowEntryLatentActionBoolean_Statics; \
public: \
	DECLARE_CLASS(ULowEntryLatentActionBoolean, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/LowEntryExtendedStandardLibrary"), NO_API) \
	DECLARE_SERIALIZER(ULowEntryLatentActionBoolean)


#define Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_ClassesLatentAction_LowEntryLatentActionBoolean_h_17_INCLASS \
private: \
	static void StaticRegisterNativesULowEntryLatentActionBoolean(); \
	friend struct Z_Construct_UClass_ULowEntryLatentActionBoolean_Statics; \
public: \
	DECLARE_CLASS(ULowEntryLatentActionBoolean, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/LowEntryExtendedStandardLibrary"), NO_API) \
	DECLARE_SERIALIZER(ULowEntryLatentActionBoolean)


#define Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_ClassesLatentAction_LowEntryLatentActionBoolean_h_17_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ULowEntryLatentActionBoolean(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ULowEntryLatentActionBoolean) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ULowEntryLatentActionBoolean); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ULowEntryLatentActionBoolean); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ULowEntryLatentActionBoolean(ULowEntryLatentActionBoolean&&); \
	NO_API ULowEntryLatentActionBoolean(const ULowEntryLatentActionBoolean&); \
public:


#define Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_ClassesLatentAction_LowEntryLatentActionBoolean_h_17_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ULowEntryLatentActionBoolean(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ULowEntryLatentActionBoolean(ULowEntryLatentActionBoolean&&); \
	NO_API ULowEntryLatentActionBoolean(const ULowEntryLatentActionBoolean&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ULowEntryLatentActionBoolean); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ULowEntryLatentActionBoolean); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ULowEntryLatentActionBoolean)


#define Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_ClassesLatentAction_LowEntryLatentActionBoolean_h_17_PRIVATE_PROPERTY_OFFSET
#define Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_ClassesLatentAction_LowEntryLatentActionBoolean_h_14_PROLOG
#define Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_ClassesLatentAction_LowEntryLatentActionBoolean_h_17_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_ClassesLatentAction_LowEntryLatentActionBoolean_h_17_PRIVATE_PROPERTY_OFFSET \
	Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_ClassesLatentAction_LowEntryLatentActionBoolean_h_17_RPC_WRAPPERS \
	Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_ClassesLatentAction_LowEntryLatentActionBoolean_h_17_INCLASS \
	Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_ClassesLatentAction_LowEntryLatentActionBoolean_h_17_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_ClassesLatentAction_LowEntryLatentActionBoolean_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_ClassesLatentAction_LowEntryLatentActionBoolean_h_17_PRIVATE_PROPERTY_OFFSET \
	Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_ClassesLatentAction_LowEntryLatentActionBoolean_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_ClassesLatentAction_LowEntryLatentActionBoolean_h_17_INCLASS_NO_PURE_DECLS \
	Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_ClassesLatentAction_LowEntryLatentActionBoolean_h_17_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class LowEntryLatentActionBoolean."); \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_ClassesLatentAction_LowEntryLatentActionBoolean_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
