// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LowEntryXmlParser/Public/Classes/LowEntryXmlParserNode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeLowEntryXmlParserNode() {}
// Cross Module References
	LOWENTRYXMLPARSER_API UClass* Z_Construct_UClass_ULowEntryXmlParserNode_NoRegister();
	LOWENTRYXMLPARSER_API UClass* Z_Construct_UClass_ULowEntryXmlParserNode();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_LowEntryXmlParser();
	LOWENTRYXMLPARSER_API UFunction* Z_Construct_UFunction_ULowEntryXmlParserNode_FindChildNode();
	LOWENTRYXMLPARSER_API UFunction* Z_Construct_UFunction_ULowEntryXmlParserNode_GetAttribute();
	LOWENTRYXMLPARSER_API UFunction* Z_Construct_UFunction_ULowEntryXmlParserNode_GetAttributes();
	LOWENTRYXMLPARSER_API UScriptStruct* Z_Construct_UScriptStruct_FLowEntryXmlParserNodeAttribute();
	LOWENTRYXMLPARSER_API UFunction* Z_Construct_UFunction_ULowEntryXmlParserNode_GetChildrenNodes();
	LOWENTRYXMLPARSER_API UFunction* Z_Construct_UFunction_ULowEntryXmlParserNode_GetFirstChildNode();
	LOWENTRYXMLPARSER_API UFunction* Z_Construct_UFunction_ULowEntryXmlParserNode_GetNextNode();
	LOWENTRYXMLPARSER_API UFunction* Z_Construct_UFunction_ULowEntryXmlParserNode_GetTag();
	LOWENTRYXMLPARSER_API UFunction* Z_Construct_UFunction_ULowEntryXmlParserNode_GetValue();
// End Cross Module References
	void ULowEntryXmlParserNode::StaticRegisterNativesULowEntryXmlParserNode()
	{
		UClass* Class = ULowEntryXmlParserNode::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "FindChildNode", &ULowEntryXmlParserNode::execFindChildNode },
			{ "GetAttribute", &ULowEntryXmlParserNode::execGetAttribute },
			{ "GetAttributes", &ULowEntryXmlParserNode::execGetAttributes },
			{ "GetChildrenNodes", &ULowEntryXmlParserNode::execGetChildrenNodes },
			{ "GetFirstChildNode", &ULowEntryXmlParserNode::execGetFirstChildNode },
			{ "GetNextNode", &ULowEntryXmlParserNode::execGetNextNode },
			{ "GetTag", &ULowEntryXmlParserNode::execGetTag },
			{ "GetValue", &ULowEntryXmlParserNode::execGetValue },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ULowEntryXmlParserNode_FindChildNode_Statics
	{
		struct LowEntryXmlParserNode_eventFindChildNode_Parms
		{
			FString Tag;
			ULowEntryXmlParserNode* ReturnValue;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Tag_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_Tag;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ULowEntryXmlParserNode_FindChildNode_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Object, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(LowEntryXmlParserNode_eventFindChildNode_Parms, ReturnValue), Z_Construct_UClass_ULowEntryXmlParserNode_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryXmlParserNode_FindChildNode_Statics::NewProp_Tag_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ULowEntryXmlParserNode_FindChildNode_Statics::NewProp_Tag = { UE4CodeGen_Private::EPropertyClass::Str, "Tag", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(LowEntryXmlParserNode_eventFindChildNode_Parms, Tag), METADATA_PARAMS(Z_Construct_UFunction_ULowEntryXmlParserNode_FindChildNode_Statics::NewProp_Tag_MetaData, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryXmlParserNode_FindChildNode_Statics::NewProp_Tag_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULowEntryXmlParserNode_FindChildNode_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryXmlParserNode_FindChildNode_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryXmlParserNode_FindChildNode_Statics::NewProp_Tag,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryXmlParserNode_FindChildNode_Statics::Function_MetaDataParams[] = {
		{ "Category", "Low Entry|Xml Parser|Node" },
		{ "DisplayName", "Find Child Node" },
		{ "ModuleRelativePath", "Public/Classes/LowEntryXmlParserNode.h" },
		{ "ToolTip", "Finds the first child node that contains the specified tag, can return NULL." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULowEntryXmlParserNode_FindChildNode_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULowEntryXmlParserNode, "FindChildNode", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(LowEntryXmlParserNode_eventFindChildNode_Parms), Z_Construct_UFunction_ULowEntryXmlParserNode_FindChildNode_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryXmlParserNode_FindChildNode_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULowEntryXmlParserNode_FindChildNode_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryXmlParserNode_FindChildNode_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULowEntryXmlParserNode_FindChildNode()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULowEntryXmlParserNode_FindChildNode_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULowEntryXmlParserNode_GetAttribute_Statics
	{
		struct LowEntryXmlParserNode_eventGetAttribute_Parms
		{
			FString Tag;
			FString ReturnValue;
		};
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Tag_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_Tag;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ULowEntryXmlParserNode_GetAttribute_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Str, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(LowEntryXmlParserNode_eventGetAttribute_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryXmlParserNode_GetAttribute_Statics::NewProp_Tag_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ULowEntryXmlParserNode_GetAttribute_Statics::NewProp_Tag = { UE4CodeGen_Private::EPropertyClass::Str, "Tag", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(LowEntryXmlParserNode_eventGetAttribute_Parms, Tag), METADATA_PARAMS(Z_Construct_UFunction_ULowEntryXmlParserNode_GetAttribute_Statics::NewProp_Tag_MetaData, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryXmlParserNode_GetAttribute_Statics::NewProp_Tag_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULowEntryXmlParserNode_GetAttribute_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryXmlParserNode_GetAttribute_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryXmlParserNode_GetAttribute_Statics::NewProp_Tag,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryXmlParserNode_GetAttribute_Statics::Function_MetaDataParams[] = {
		{ "Category", "Low Entry|Xml Parser|Node" },
		{ "DisplayName", "Get Attribute" },
		{ "ModuleRelativePath", "Public/Classes/LowEntryXmlParserNode.h" },
		{ "ToolTip", "Gets an attribute that corresponds with the given tag." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULowEntryXmlParserNode_GetAttribute_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULowEntryXmlParserNode, "GetAttribute", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14020401, sizeof(LowEntryXmlParserNode_eventGetAttribute_Parms), Z_Construct_UFunction_ULowEntryXmlParserNode_GetAttribute_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryXmlParserNode_GetAttribute_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULowEntryXmlParserNode_GetAttribute_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryXmlParserNode_GetAttribute_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULowEntryXmlParserNode_GetAttribute()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULowEntryXmlParserNode_GetAttribute_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULowEntryXmlParserNode_GetAttributes_Statics
	{
		struct LowEntryXmlParserNode_eventGetAttributes_Parms
		{
			TArray<FLowEntryXmlParserNodeAttribute> ReturnValue;
		};
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue_Inner;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_ULowEntryXmlParserNode_GetAttributes_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Array, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(LowEntryXmlParserNode_eventGetAttributes_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ULowEntryXmlParserNode_GetAttributes_Statics::NewProp_ReturnValue_Inner = { UE4CodeGen_Private::EPropertyClass::Struct, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, Z_Construct_UScriptStruct_FLowEntryXmlParserNodeAttribute, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULowEntryXmlParserNode_GetAttributes_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryXmlParserNode_GetAttributes_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryXmlParserNode_GetAttributes_Statics::NewProp_ReturnValue_Inner,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryXmlParserNode_GetAttributes_Statics::Function_MetaDataParams[] = {
		{ "Category", "Low Entry|Xml Parser|Node" },
		{ "DisplayName", "Get Attributes" },
		{ "ModuleRelativePath", "Public/Classes/LowEntryXmlParserNode.h" },
		{ "ToolTip", "Gets all of the attributes in this node." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULowEntryXmlParserNode_GetAttributes_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULowEntryXmlParserNode, "GetAttributes", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(LowEntryXmlParserNode_eventGetAttributes_Parms), Z_Construct_UFunction_ULowEntryXmlParserNode_GetAttributes_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryXmlParserNode_GetAttributes_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULowEntryXmlParserNode_GetAttributes_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryXmlParserNode_GetAttributes_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULowEntryXmlParserNode_GetAttributes()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULowEntryXmlParserNode_GetAttributes_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULowEntryXmlParserNode_GetChildrenNodes_Statics
	{
		struct LowEntryXmlParserNode_eventGetChildrenNodes_Parms
		{
			TArray<ULowEntryXmlParserNode*> ReturnValue;
		};
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue_Inner;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_ULowEntryXmlParserNode_GetChildrenNodes_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Array, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(LowEntryXmlParserNode_eventGetChildrenNodes_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ULowEntryXmlParserNode_GetChildrenNodes_Statics::NewProp_ReturnValue_Inner = { UE4CodeGen_Private::EPropertyClass::Object, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, Z_Construct_UClass_ULowEntryXmlParserNode_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULowEntryXmlParserNode_GetChildrenNodes_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryXmlParserNode_GetChildrenNodes_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryXmlParserNode_GetChildrenNodes_Statics::NewProp_ReturnValue_Inner,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryXmlParserNode_GetChildrenNodes_Statics::Function_MetaDataParams[] = {
		{ "Category", "Low Entry|Xml Parser|Node" },
		{ "DisplayName", "Get Children Nodes" },
		{ "ModuleRelativePath", "Public/Classes/LowEntryXmlParserNode.h" },
		{ "ToolTip", "Gets a list of children nodes." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULowEntryXmlParserNode_GetChildrenNodes_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULowEntryXmlParserNode, "GetChildrenNodes", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(LowEntryXmlParserNode_eventGetChildrenNodes_Parms), Z_Construct_UFunction_ULowEntryXmlParserNode_GetChildrenNodes_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryXmlParserNode_GetChildrenNodes_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULowEntryXmlParserNode_GetChildrenNodes_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryXmlParserNode_GetChildrenNodes_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULowEntryXmlParserNode_GetChildrenNodes()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULowEntryXmlParserNode_GetChildrenNodes_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULowEntryXmlParserNode_GetFirstChildNode_Statics
	{
		struct LowEntryXmlParserNode_eventGetFirstChildNode_Parms
		{
			ULowEntryXmlParserNode* ReturnValue;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ULowEntryXmlParserNode_GetFirstChildNode_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Object, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(LowEntryXmlParserNode_eventGetFirstChildNode_Parms, ReturnValue), Z_Construct_UClass_ULowEntryXmlParserNode_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULowEntryXmlParserNode_GetFirstChildNode_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryXmlParserNode_GetFirstChildNode_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryXmlParserNode_GetFirstChildNode_Statics::Function_MetaDataParams[] = {
		{ "Category", "Low Entry|Xml Parser|Node" },
		{ "DisplayName", "Get First Child Node" },
		{ "ModuleRelativePath", "Public/Classes/LowEntryXmlParserNode.h" },
		{ "ToolTip", "Gets the first child of this node which can be iterated into with GetNextNode, can return NULL." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULowEntryXmlParserNode_GetFirstChildNode_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULowEntryXmlParserNode, "GetFirstChildNode", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(LowEntryXmlParserNode_eventGetFirstChildNode_Parms), Z_Construct_UFunction_ULowEntryXmlParserNode_GetFirstChildNode_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryXmlParserNode_GetFirstChildNode_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULowEntryXmlParserNode_GetFirstChildNode_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryXmlParserNode_GetFirstChildNode_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULowEntryXmlParserNode_GetFirstChildNode()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULowEntryXmlParserNode_GetFirstChildNode_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULowEntryXmlParserNode_GetNextNode_Statics
	{
		struct LowEntryXmlParserNode_eventGetNextNode_Parms
		{
			ULowEntryXmlParserNode* ReturnValue;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ULowEntryXmlParserNode_GetNextNode_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Object, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(LowEntryXmlParserNode_eventGetNextNode_Parms, ReturnValue), Z_Construct_UClass_ULowEntryXmlParserNode_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULowEntryXmlParserNode_GetNextNode_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryXmlParserNode_GetNextNode_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryXmlParserNode_GetNextNode_Statics::Function_MetaDataParams[] = {
		{ "Category", "Low Entry|Xml Parser|Node" },
		{ "DisplayName", "Get Next Node" },
		{ "ModuleRelativePath", "Public/Classes/LowEntryXmlParserNode.h" },
		{ "ToolTip", "Gets the next node in a list of nodes, can return NULL." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULowEntryXmlParserNode_GetNextNode_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULowEntryXmlParserNode, "GetNextNode", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(LowEntryXmlParserNode_eventGetNextNode_Parms), Z_Construct_UFunction_ULowEntryXmlParserNode_GetNextNode_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryXmlParserNode_GetNextNode_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULowEntryXmlParserNode_GetNextNode_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryXmlParserNode_GetNextNode_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULowEntryXmlParserNode_GetNextNode()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULowEntryXmlParserNode_GetNextNode_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULowEntryXmlParserNode_GetTag_Statics
	{
		struct LowEntryXmlParserNode_eventGetTag_Parms
		{
			FString ReturnValue;
		};
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ULowEntryXmlParserNode_GetTag_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Str, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(LowEntryXmlParserNode_eventGetTag_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULowEntryXmlParserNode_GetTag_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryXmlParserNode_GetTag_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryXmlParserNode_GetTag_Statics::Function_MetaDataParams[] = {
		{ "Category", "Low Entry|Xml Parser|Node" },
		{ "DisplayName", "Get Tag" },
		{ "ModuleRelativePath", "Public/Classes/LowEntryXmlParserNode.h" },
		{ "ToolTip", "Gets the tag of the node." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULowEntryXmlParserNode_GetTag_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULowEntryXmlParserNode, "GetTag", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14020401, sizeof(LowEntryXmlParserNode_eventGetTag_Parms), Z_Construct_UFunction_ULowEntryXmlParserNode_GetTag_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryXmlParserNode_GetTag_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULowEntryXmlParserNode_GetTag_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryXmlParserNode_GetTag_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULowEntryXmlParserNode_GetTag()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULowEntryXmlParserNode_GetTag_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULowEntryXmlParserNode_GetValue_Statics
	{
		struct LowEntryXmlParserNode_eventGetValue_Parms
		{
			FString ReturnValue;
		};
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ULowEntryXmlParserNode_GetValue_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Str, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(LowEntryXmlParserNode_eventGetValue_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULowEntryXmlParserNode_GetValue_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryXmlParserNode_GetValue_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryXmlParserNode_GetValue_Statics::Function_MetaDataParams[] = {
		{ "Category", "Low Entry|Xml Parser|Node" },
		{ "DisplayName", "Get Value" },
		{ "ModuleRelativePath", "Public/Classes/LowEntryXmlParserNode.h" },
		{ "ToolTip", "Gets the value of the node." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULowEntryXmlParserNode_GetValue_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULowEntryXmlParserNode, "GetValue", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14020401, sizeof(LowEntryXmlParserNode_eventGetValue_Parms), Z_Construct_UFunction_ULowEntryXmlParserNode_GetValue_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryXmlParserNode_GetValue_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULowEntryXmlParserNode_GetValue_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryXmlParserNode_GetValue_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULowEntryXmlParserNode_GetValue()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULowEntryXmlParserNode_GetValue_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ULowEntryXmlParserNode_NoRegister()
	{
		return ULowEntryXmlParserNode::StaticClass();
	}
	struct Z_Construct_UClass_ULowEntryXmlParserNode_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ULowEntryXmlParserNode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_LowEntryXmlParser,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ULowEntryXmlParserNode_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ULowEntryXmlParserNode_FindChildNode, "FindChildNode" }, // 2148972056
		{ &Z_Construct_UFunction_ULowEntryXmlParserNode_GetAttribute, "GetAttribute" }, // 3965100421
		{ &Z_Construct_UFunction_ULowEntryXmlParserNode_GetAttributes, "GetAttributes" }, // 2520211129
		{ &Z_Construct_UFunction_ULowEntryXmlParserNode_GetChildrenNodes, "GetChildrenNodes" }, // 68475544
		{ &Z_Construct_UFunction_ULowEntryXmlParserNode_GetFirstChildNode, "GetFirstChildNode" }, // 3554474985
		{ &Z_Construct_UFunction_ULowEntryXmlParserNode_GetNextNode, "GetNextNode" }, // 1122554395
		{ &Z_Construct_UFunction_ULowEntryXmlParserNode_GetTag, "GetTag" }, // 3457610258
		{ &Z_Construct_UFunction_ULowEntryXmlParserNode_GetValue, "GetValue" }, // 96685357
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULowEntryXmlParserNode_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "Classes/LowEntryXmlParserNode.h" },
		{ "ModuleRelativePath", "Public/Classes/LowEntryXmlParserNode.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ULowEntryXmlParserNode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ULowEntryXmlParserNode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ULowEntryXmlParserNode_Statics::ClassParams = {
		&ULowEntryXmlParserNode::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x001000A0u,
		FuncInfo, ARRAY_COUNT(FuncInfo),
		nullptr, 0,
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_ULowEntryXmlParserNode_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_ULowEntryXmlParserNode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ULowEntryXmlParserNode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ULowEntryXmlParserNode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ULowEntryXmlParserNode, 2797976052);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ULowEntryXmlParserNode(Z_Construct_UClass_ULowEntryXmlParserNode, &ULowEntryXmlParserNode::StaticClass, TEXT("/Script/LowEntryXmlParser"), TEXT("ULowEntryXmlParserNode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ULowEntryXmlParserNode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
