// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
enum class ELowEntryHttpRequestSuccess : uint8;
#ifdef LOWENTRYHTTPREQUEST_LowEntryHttpRequestResponse_generated_h
#error "LowEntryHttpRequestResponse.generated.h already included, missing '#pragma once' in LowEntryHttpRequestResponse.h"
#endif
#define LOWENTRYHTTPREQUEST_LowEntryHttpRequestResponse_generated_h

#define Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryHttpRequest_Source_LowEntryHttpRequest_Public_Classes_LowEntryHttpRequestResponse_h_19_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetAllHeaders) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<FString>*)Z_Param__Result=P_THIS->GetAllHeaders(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetHeader) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Key); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=P_THIS->GetHeader(Z_Param_Key); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetContentType) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=P_THIS->GetContentType(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetContentLength) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetContentLength(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetContentAsString) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=P_THIS->GetContentAsString(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetContent) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<uint8>*)Z_Param__Result=P_THIS->GetContent(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetUrl) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=P_THIS->GetUrl(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetResponseCode) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetResponseCode(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetWasSuccessful) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->GetWasSuccessful(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execWasSuccessful) \
	{ \
		P_GET_ENUM_REF(ELowEntryHttpRequestSuccess,Z_Param_Out_Branch); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->WasSuccessful((ELowEntryHttpRequestSuccess&)(Z_Param_Out_Branch)); \
		P_NATIVE_END; \
	}


#define Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryHttpRequest_Source_LowEntryHttpRequest_Public_Classes_LowEntryHttpRequestResponse_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetAllHeaders) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<FString>*)Z_Param__Result=P_THIS->GetAllHeaders(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetHeader) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Key); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=P_THIS->GetHeader(Z_Param_Key); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetContentType) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=P_THIS->GetContentType(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetContentLength) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetContentLength(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetContentAsString) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=P_THIS->GetContentAsString(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetContent) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<uint8>*)Z_Param__Result=P_THIS->GetContent(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetUrl) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=P_THIS->GetUrl(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetResponseCode) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetResponseCode(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetWasSuccessful) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->GetWasSuccessful(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execWasSuccessful) \
	{ \
		P_GET_ENUM_REF(ELowEntryHttpRequestSuccess,Z_Param_Out_Branch); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->WasSuccessful((ELowEntryHttpRequestSuccess&)(Z_Param_Out_Branch)); \
		P_NATIVE_END; \
	}


#define Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryHttpRequest_Source_LowEntryHttpRequest_Public_Classes_LowEntryHttpRequestResponse_h_19_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesULowEntryHttpRequestResponse(); \
	friend struct Z_Construct_UClass_ULowEntryHttpRequestResponse_Statics; \
public: \
	DECLARE_CLASS(ULowEntryHttpRequestResponse, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/LowEntryHttpRequest"), NO_API) \
	DECLARE_SERIALIZER(ULowEntryHttpRequestResponse)


#define Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryHttpRequest_Source_LowEntryHttpRequest_Public_Classes_LowEntryHttpRequestResponse_h_19_INCLASS \
private: \
	static void StaticRegisterNativesULowEntryHttpRequestResponse(); \
	friend struct Z_Construct_UClass_ULowEntryHttpRequestResponse_Statics; \
public: \
	DECLARE_CLASS(ULowEntryHttpRequestResponse, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/LowEntryHttpRequest"), NO_API) \
	DECLARE_SERIALIZER(ULowEntryHttpRequestResponse)


#define Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryHttpRequest_Source_LowEntryHttpRequest_Public_Classes_LowEntryHttpRequestResponse_h_19_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ULowEntryHttpRequestResponse(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ULowEntryHttpRequestResponse) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ULowEntryHttpRequestResponse); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ULowEntryHttpRequestResponse); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ULowEntryHttpRequestResponse(ULowEntryHttpRequestResponse&&); \
	NO_API ULowEntryHttpRequestResponse(const ULowEntryHttpRequestResponse&); \
public:


#define Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryHttpRequest_Source_LowEntryHttpRequest_Public_Classes_LowEntryHttpRequestResponse_h_19_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ULowEntryHttpRequestResponse(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ULowEntryHttpRequestResponse(ULowEntryHttpRequestResponse&&); \
	NO_API ULowEntryHttpRequestResponse(const ULowEntryHttpRequestResponse&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ULowEntryHttpRequestResponse); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ULowEntryHttpRequestResponse); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ULowEntryHttpRequestResponse)


#define Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryHttpRequest_Source_LowEntryHttpRequest_Public_Classes_LowEntryHttpRequestResponse_h_19_PRIVATE_PROPERTY_OFFSET
#define Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryHttpRequest_Source_LowEntryHttpRequest_Public_Classes_LowEntryHttpRequestResponse_h_16_PROLOG
#define Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryHttpRequest_Source_LowEntryHttpRequest_Public_Classes_LowEntryHttpRequestResponse_h_19_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryHttpRequest_Source_LowEntryHttpRequest_Public_Classes_LowEntryHttpRequestResponse_h_19_PRIVATE_PROPERTY_OFFSET \
	Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryHttpRequest_Source_LowEntryHttpRequest_Public_Classes_LowEntryHttpRequestResponse_h_19_RPC_WRAPPERS \
	Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryHttpRequest_Source_LowEntryHttpRequest_Public_Classes_LowEntryHttpRequestResponse_h_19_INCLASS \
	Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryHttpRequest_Source_LowEntryHttpRequest_Public_Classes_LowEntryHttpRequestResponse_h_19_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryHttpRequest_Source_LowEntryHttpRequest_Public_Classes_LowEntryHttpRequestResponse_h_19_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryHttpRequest_Source_LowEntryHttpRequest_Public_Classes_LowEntryHttpRequestResponse_h_19_PRIVATE_PROPERTY_OFFSET \
	Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryHttpRequest_Source_LowEntryHttpRequest_Public_Classes_LowEntryHttpRequestResponse_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
	Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryHttpRequest_Source_LowEntryHttpRequest_Public_Classes_LowEntryHttpRequestResponse_h_19_INCLASS_NO_PURE_DECLS \
	Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryHttpRequest_Source_LowEntryHttpRequest_Public_Classes_LowEntryHttpRequestResponse_h_19_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class LowEntryHttpRequestResponse."); \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryHttpRequest_Source_LowEntryHttpRequest_Public_Classes_LowEntryHttpRequestResponse_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
