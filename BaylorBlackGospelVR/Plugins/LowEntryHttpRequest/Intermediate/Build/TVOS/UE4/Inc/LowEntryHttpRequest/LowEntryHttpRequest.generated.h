// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class ULowEntryHttpRequestResponse;
class UObject;
struct FLatentActionInfo;
enum class ELowEntryHttpRequestType : uint8;
#ifdef LOWENTRYHTTPREQUEST_LowEntryHttpRequest_generated_h
#error "LowEntryHttpRequest.generated.h already included, missing '#pragma once' in LowEntryHttpRequest.h"
#endif
#define LOWENTRYHTTPREQUEST_LowEntryHttpRequest_generated_h

#define Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryHttpRequest_Source_LowEntryHttpRequest_Public_Classes_LowEntryHttpRequest_h_23_DELEGATE \
struct _Script_LowEntryHttpRequest_eventDelegateULowEntryHttpRequestOnComplete_Parms \
{ \
	ULowEntryHttpRequestResponse* Response; \
}; \
static inline void FDelegateULowEntryHttpRequestOnComplete_DelegateWrapper(const FScriptDelegate& DelegateULowEntryHttpRequestOnComplete, ULowEntryHttpRequestResponse* Response) \
{ \
	_Script_LowEntryHttpRequest_eventDelegateULowEntryHttpRequestOnComplete_Parms Parms; \
	Parms.Response=Response; \
	DelegateULowEntryHttpRequestOnComplete.ProcessDelegate<UObject>(&Parms); \
}


#define Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryHttpRequest_Source_LowEntryHttpRequest_Public_Classes_LowEntryHttpRequest_h_29_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetReceivedPercentage) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=P_THIS->GetReceivedPercentage(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetSentPercentage) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=P_THIS->GetSentPercentage(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetBytesReceived) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetBytesReceived(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetBytesToReceive) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetBytesToReceive(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetBytesSent) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetBytesSent(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetBytesToSend) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetBytesToSend(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetContentAsStringParameters) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=P_THIS->GetContentAsStringParameters(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetUrlWithUrlParameters) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=P_THIS->GetUrlWithUrlParameters(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsExecutingRequest) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->IsExecutingRequest(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCancelRequest) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->CancelRequest(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execExecuteRequestEvent) \
	{ \
		P_GET_PROPERTY(UDelegateProperty,Z_Param_OnComplete); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->ExecuteRequestEvent(FDelegateULowEntryHttpRequestOnComplete(Z_Param_OnComplete)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execExecuteRequest) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_STRUCT(FLatentActionInfo,Z_Param_LatentInfo); \
		P_GET_OBJECT_REF(ULowEntryHttpRequestResponse,Z_Param_Out_Response); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->ExecuteRequest(Z_Param_WorldContextObject,Z_Param_LatentInfo,Z_Param_Out_Response); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetContentAsStringParameters) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Key); \
		P_GET_PROPERTY(UStrProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetContentAsStringParameters(Z_Param_Key,Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetContentAsJsonString) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Data); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetContentAsJsonString(Z_Param_Data); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetContentAsString) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Data); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetContentAsString(Z_Param_Data); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetContent) \
	{ \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_Data); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetContent(Z_Param_Out_Data); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetHeader) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Key); \
		P_GET_PROPERTY(UStrProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetHeader(Z_Param_Key,Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetUrlParameter) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Key); \
		P_GET_PROPERTY(UStrProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetUrlParameter(Z_Param_Key,Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetUrlCustomType) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Type); \
		P_GET_PROPERTY(UStrProperty,Z_Param_Url); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetUrlCustomType(Z_Param_Type,Z_Param_Url); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetUrl) \
	{ \
		P_GET_ENUM(ELowEntryHttpRequestType,Z_Param_Type); \
		P_GET_PROPERTY(UStrProperty,Z_Param_Url); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetUrl(ELowEntryHttpRequestType(Z_Param_Type),Z_Param_Url); \
		P_NATIVE_END; \
	}


#define Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryHttpRequest_Source_LowEntryHttpRequest_Public_Classes_LowEntryHttpRequest_h_29_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetReceivedPercentage) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=P_THIS->GetReceivedPercentage(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetSentPercentage) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=P_THIS->GetSentPercentage(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetBytesReceived) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetBytesReceived(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetBytesToReceive) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetBytesToReceive(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetBytesSent) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetBytesSent(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetBytesToSend) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetBytesToSend(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetContentAsStringParameters) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=P_THIS->GetContentAsStringParameters(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetUrlWithUrlParameters) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=P_THIS->GetUrlWithUrlParameters(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsExecutingRequest) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->IsExecutingRequest(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCancelRequest) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->CancelRequest(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execExecuteRequestEvent) \
	{ \
		P_GET_PROPERTY(UDelegateProperty,Z_Param_OnComplete); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->ExecuteRequestEvent(FDelegateULowEntryHttpRequestOnComplete(Z_Param_OnComplete)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execExecuteRequest) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_STRUCT(FLatentActionInfo,Z_Param_LatentInfo); \
		P_GET_OBJECT_REF(ULowEntryHttpRequestResponse,Z_Param_Out_Response); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->ExecuteRequest(Z_Param_WorldContextObject,Z_Param_LatentInfo,Z_Param_Out_Response); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetContentAsStringParameters) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Key); \
		P_GET_PROPERTY(UStrProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetContentAsStringParameters(Z_Param_Key,Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetContentAsJsonString) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Data); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetContentAsJsonString(Z_Param_Data); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetContentAsString) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Data); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetContentAsString(Z_Param_Data); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetContent) \
	{ \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_Data); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetContent(Z_Param_Out_Data); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetHeader) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Key); \
		P_GET_PROPERTY(UStrProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetHeader(Z_Param_Key,Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetUrlParameter) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Key); \
		P_GET_PROPERTY(UStrProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetUrlParameter(Z_Param_Key,Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetUrlCustomType) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Type); \
		P_GET_PROPERTY(UStrProperty,Z_Param_Url); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetUrlCustomType(Z_Param_Type,Z_Param_Url); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetUrl) \
	{ \
		P_GET_ENUM(ELowEntryHttpRequestType,Z_Param_Type); \
		P_GET_PROPERTY(UStrProperty,Z_Param_Url); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetUrl(ELowEntryHttpRequestType(Z_Param_Type),Z_Param_Url); \
		P_NATIVE_END; \
	}


#define Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryHttpRequest_Source_LowEntryHttpRequest_Public_Classes_LowEntryHttpRequest_h_29_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesULowEntryHttpRequest(); \
	friend struct Z_Construct_UClass_ULowEntryHttpRequest_Statics; \
public: \
	DECLARE_CLASS(ULowEntryHttpRequest, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/LowEntryHttpRequest"), NO_API) \
	DECLARE_SERIALIZER(ULowEntryHttpRequest)


#define Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryHttpRequest_Source_LowEntryHttpRequest_Public_Classes_LowEntryHttpRequest_h_29_INCLASS \
private: \
	static void StaticRegisterNativesULowEntryHttpRequest(); \
	friend struct Z_Construct_UClass_ULowEntryHttpRequest_Statics; \
public: \
	DECLARE_CLASS(ULowEntryHttpRequest, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/LowEntryHttpRequest"), NO_API) \
	DECLARE_SERIALIZER(ULowEntryHttpRequest)


#define Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryHttpRequest_Source_LowEntryHttpRequest_Public_Classes_LowEntryHttpRequest_h_29_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ULowEntryHttpRequest(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ULowEntryHttpRequest) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ULowEntryHttpRequest); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ULowEntryHttpRequest); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ULowEntryHttpRequest(ULowEntryHttpRequest&&); \
	NO_API ULowEntryHttpRequest(const ULowEntryHttpRequest&); \
public:


#define Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryHttpRequest_Source_LowEntryHttpRequest_Public_Classes_LowEntryHttpRequest_h_29_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ULowEntryHttpRequest(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ULowEntryHttpRequest(ULowEntryHttpRequest&&); \
	NO_API ULowEntryHttpRequest(const ULowEntryHttpRequest&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ULowEntryHttpRequest); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ULowEntryHttpRequest); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ULowEntryHttpRequest)


#define Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryHttpRequest_Source_LowEntryHttpRequest_Public_Classes_LowEntryHttpRequest_h_29_PRIVATE_PROPERTY_OFFSET
#define Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryHttpRequest_Source_LowEntryHttpRequest_Public_Classes_LowEntryHttpRequest_h_26_PROLOG
#define Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryHttpRequest_Source_LowEntryHttpRequest_Public_Classes_LowEntryHttpRequest_h_29_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryHttpRequest_Source_LowEntryHttpRequest_Public_Classes_LowEntryHttpRequest_h_29_PRIVATE_PROPERTY_OFFSET \
	Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryHttpRequest_Source_LowEntryHttpRequest_Public_Classes_LowEntryHttpRequest_h_29_RPC_WRAPPERS \
	Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryHttpRequest_Source_LowEntryHttpRequest_Public_Classes_LowEntryHttpRequest_h_29_INCLASS \
	Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryHttpRequest_Source_LowEntryHttpRequest_Public_Classes_LowEntryHttpRequest_h_29_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryHttpRequest_Source_LowEntryHttpRequest_Public_Classes_LowEntryHttpRequest_h_29_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryHttpRequest_Source_LowEntryHttpRequest_Public_Classes_LowEntryHttpRequest_h_29_PRIVATE_PROPERTY_OFFSET \
	Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryHttpRequest_Source_LowEntryHttpRequest_Public_Classes_LowEntryHttpRequest_h_29_RPC_WRAPPERS_NO_PURE_DECLS \
	Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryHttpRequest_Source_LowEntryHttpRequest_Public_Classes_LowEntryHttpRequest_h_29_INCLASS_NO_PURE_DECLS \
	Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryHttpRequest_Source_LowEntryHttpRequest_Public_Classes_LowEntryHttpRequest_h_29_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class LowEntryHttpRequest."); \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryHttpRequest_Source_LowEntryHttpRequest_Public_Classes_LowEntryHttpRequest_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
