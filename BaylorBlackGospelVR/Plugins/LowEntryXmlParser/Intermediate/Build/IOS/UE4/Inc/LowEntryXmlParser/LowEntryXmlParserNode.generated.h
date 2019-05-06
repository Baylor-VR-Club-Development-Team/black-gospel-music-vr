// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FLowEntryXmlParserNodeAttribute;
class ULowEntryXmlParserNode;
#ifdef LOWENTRYXMLPARSER_LowEntryXmlParserNode_generated_h
#error "LowEntryXmlParserNode.generated.h already included, missing '#pragma once' in LowEntryXmlParserNode.h"
#endif
#define LOWENTRYXMLPARSER_LowEntryXmlParserNode_generated_h

#define Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryXmlParser_Source_LowEntryXmlParser_Public_Classes_LowEntryXmlParserNode_h_20_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetAttribute) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Tag); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=P_THIS->GetAttribute(Z_Param_Tag); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetAttributes) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<FLowEntryXmlParserNodeAttribute>*)Z_Param__Result=P_THIS->GetAttributes(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetValue) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=P_THIS->GetValue(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetTag) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=P_THIS->GetTag(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execFindChildNode) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Tag); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryXmlParserNode**)Z_Param__Result=P_THIS->FindChildNode(Z_Param_Tag); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetFirstChildNode) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryXmlParserNode**)Z_Param__Result=P_THIS->GetFirstChildNode(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetChildrenNodes) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<ULowEntryXmlParserNode*>*)Z_Param__Result=P_THIS->GetChildrenNodes(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetNextNode) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryXmlParserNode**)Z_Param__Result=P_THIS->GetNextNode(); \
		P_NATIVE_END; \
	}


#define Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryXmlParser_Source_LowEntryXmlParser_Public_Classes_LowEntryXmlParserNode_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetAttribute) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Tag); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=P_THIS->GetAttribute(Z_Param_Tag); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetAttributes) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<FLowEntryXmlParserNodeAttribute>*)Z_Param__Result=P_THIS->GetAttributes(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetValue) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=P_THIS->GetValue(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetTag) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=P_THIS->GetTag(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execFindChildNode) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Tag); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryXmlParserNode**)Z_Param__Result=P_THIS->FindChildNode(Z_Param_Tag); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetFirstChildNode) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryXmlParserNode**)Z_Param__Result=P_THIS->GetFirstChildNode(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetChildrenNodes) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<ULowEntryXmlParserNode*>*)Z_Param__Result=P_THIS->GetChildrenNodes(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetNextNode) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryXmlParserNode**)Z_Param__Result=P_THIS->GetNextNode(); \
		P_NATIVE_END; \
	}


#define Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryXmlParser_Source_LowEntryXmlParser_Public_Classes_LowEntryXmlParserNode_h_20_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesULowEntryXmlParserNode(); \
	friend struct Z_Construct_UClass_ULowEntryXmlParserNode_Statics; \
public: \
	DECLARE_CLASS(ULowEntryXmlParserNode, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/LowEntryXmlParser"), NO_API) \
	DECLARE_SERIALIZER(ULowEntryXmlParserNode)


#define Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryXmlParser_Source_LowEntryXmlParser_Public_Classes_LowEntryXmlParserNode_h_20_INCLASS \
private: \
	static void StaticRegisterNativesULowEntryXmlParserNode(); \
	friend struct Z_Construct_UClass_ULowEntryXmlParserNode_Statics; \
public: \
	DECLARE_CLASS(ULowEntryXmlParserNode, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/LowEntryXmlParser"), NO_API) \
	DECLARE_SERIALIZER(ULowEntryXmlParserNode)


#define Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryXmlParser_Source_LowEntryXmlParser_Public_Classes_LowEntryXmlParserNode_h_20_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ULowEntryXmlParserNode(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ULowEntryXmlParserNode) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ULowEntryXmlParserNode); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ULowEntryXmlParserNode); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ULowEntryXmlParserNode(ULowEntryXmlParserNode&&); \
	NO_API ULowEntryXmlParserNode(const ULowEntryXmlParserNode&); \
public:


#define Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryXmlParser_Source_LowEntryXmlParser_Public_Classes_LowEntryXmlParserNode_h_20_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ULowEntryXmlParserNode(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ULowEntryXmlParserNode(ULowEntryXmlParserNode&&); \
	NO_API ULowEntryXmlParserNode(const ULowEntryXmlParserNode&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ULowEntryXmlParserNode); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ULowEntryXmlParserNode); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ULowEntryXmlParserNode)


#define Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryXmlParser_Source_LowEntryXmlParser_Public_Classes_LowEntryXmlParserNode_h_20_PRIVATE_PROPERTY_OFFSET
#define Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryXmlParser_Source_LowEntryXmlParser_Public_Classes_LowEntryXmlParserNode_h_17_PROLOG
#define Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryXmlParser_Source_LowEntryXmlParser_Public_Classes_LowEntryXmlParserNode_h_20_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryXmlParser_Source_LowEntryXmlParser_Public_Classes_LowEntryXmlParserNode_h_20_PRIVATE_PROPERTY_OFFSET \
	Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryXmlParser_Source_LowEntryXmlParser_Public_Classes_LowEntryXmlParserNode_h_20_RPC_WRAPPERS \
	Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryXmlParser_Source_LowEntryXmlParser_Public_Classes_LowEntryXmlParserNode_h_20_INCLASS \
	Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryXmlParser_Source_LowEntryXmlParser_Public_Classes_LowEntryXmlParserNode_h_20_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryXmlParser_Source_LowEntryXmlParser_Public_Classes_LowEntryXmlParserNode_h_20_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryXmlParser_Source_LowEntryXmlParser_Public_Classes_LowEntryXmlParserNode_h_20_PRIVATE_PROPERTY_OFFSET \
	Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryXmlParser_Source_LowEntryXmlParser_Public_Classes_LowEntryXmlParserNode_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
	Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryXmlParser_Source_LowEntryXmlParser_Public_Classes_LowEntryXmlParserNode_h_20_INCLASS_NO_PURE_DECLS \
	Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryXmlParser_Source_LowEntryXmlParser_Public_Classes_LowEntryXmlParserNode_h_20_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class LowEntryXmlParserNode."); \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_LowEntryXmlParser_Source_LowEntryXmlParser_Public_Classes_LowEntryXmlParserNode_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
