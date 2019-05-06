// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LowEntryXmlParser/Public/Classes/FLowEntryXmlParserNodeAttribute.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFLowEntryXmlParserNodeAttribute() {}
// Cross Module References
	LOWENTRYXMLPARSER_API UScriptStruct* Z_Construct_UScriptStruct_FLowEntryXmlParserNodeAttribute();
	UPackage* Z_Construct_UPackage__Script_LowEntryXmlParser();
// End Cross Module References
class UScriptStruct* FLowEntryXmlParserNodeAttribute::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern LOWENTRYXMLPARSER_API uint32 Get_Z_Construct_UScriptStruct_FLowEntryXmlParserNodeAttribute_CRC();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FLowEntryXmlParserNodeAttribute, Z_Construct_UPackage__Script_LowEntryXmlParser(), TEXT("LowEntryXmlParserNodeAttribute"), sizeof(FLowEntryXmlParserNodeAttribute), Get_Z_Construct_UScriptStruct_FLowEntryXmlParserNodeAttribute_CRC());
	}
	return Singleton;
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FLowEntryXmlParserNodeAttribute(FLowEntryXmlParserNodeAttribute::StaticStruct, TEXT("/Script/LowEntryXmlParser"), TEXT("LowEntryXmlParserNodeAttribute"), false, nullptr, nullptr);
static struct FScriptStruct_LowEntryXmlParser_StaticRegisterNativesFLowEntryXmlParserNodeAttribute
{
	FScriptStruct_LowEntryXmlParser_StaticRegisterNativesFLowEntryXmlParserNodeAttribute()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("LowEntryXmlParserNodeAttribute")),new UScriptStruct::TCppStructOps<FLowEntryXmlParserNodeAttribute>);
	}
} ScriptStruct_LowEntryXmlParser_StaticRegisterNativesFLowEntryXmlParserNodeAttribute;
	struct Z_Construct_UScriptStruct_FLowEntryXmlParserNodeAttribute_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Value_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_Value;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Tag_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_Tag;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FLowEntryXmlParserNodeAttribute_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Classes/FLowEntryXmlParserNodeAttribute.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FLowEntryXmlParserNodeAttribute_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FLowEntryXmlParserNodeAttribute>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FLowEntryXmlParserNodeAttribute_Statics::NewProp_Value_MetaData[] = {
		{ "Category", "Low Entry|Xml Parser|Node Attribute" },
		{ "ModuleRelativePath", "Public/Classes/FLowEntryXmlParserNodeAttribute.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FLowEntryXmlParserNodeAttribute_Statics::NewProp_Value = { UE4CodeGen_Private::EPropertyClass::Str, "Value", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FLowEntryXmlParserNodeAttribute, Value), METADATA_PARAMS(Z_Construct_UScriptStruct_FLowEntryXmlParserNodeAttribute_Statics::NewProp_Value_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FLowEntryXmlParserNodeAttribute_Statics::NewProp_Value_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FLowEntryXmlParserNodeAttribute_Statics::NewProp_Tag_MetaData[] = {
		{ "Category", "Low Entry|Xml Parser|Node Attribute" },
		{ "ModuleRelativePath", "Public/Classes/FLowEntryXmlParserNodeAttribute.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FLowEntryXmlParserNodeAttribute_Statics::NewProp_Tag = { UE4CodeGen_Private::EPropertyClass::Str, "Tag", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FLowEntryXmlParserNodeAttribute, Tag), METADATA_PARAMS(Z_Construct_UScriptStruct_FLowEntryXmlParserNodeAttribute_Statics::NewProp_Tag_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FLowEntryXmlParserNodeAttribute_Statics::NewProp_Tag_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FLowEntryXmlParserNodeAttribute_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FLowEntryXmlParserNodeAttribute_Statics::NewProp_Value,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FLowEntryXmlParserNodeAttribute_Statics::NewProp_Tag,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FLowEntryXmlParserNodeAttribute_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_LowEntryXmlParser,
		nullptr,
		&NewStructOps,
		"LowEntryXmlParserNodeAttribute",
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		sizeof(FLowEntryXmlParserNodeAttribute),
		alignof(FLowEntryXmlParserNodeAttribute),
		Z_Construct_UScriptStruct_FLowEntryXmlParserNodeAttribute_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UScriptStruct_FLowEntryXmlParserNodeAttribute_Statics::PropPointers),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FLowEntryXmlParserNodeAttribute_Statics::Struct_MetaDataParams, ARRAY_COUNT(Z_Construct_UScriptStruct_FLowEntryXmlParserNodeAttribute_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FLowEntryXmlParserNodeAttribute()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FLowEntryXmlParserNodeAttribute_CRC();
		UPackage* Outer = Z_Construct_UPackage__Script_LowEntryXmlParser();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("LowEntryXmlParserNodeAttribute"), sizeof(FLowEntryXmlParserNodeAttribute), Get_Z_Construct_UScriptStruct_FLowEntryXmlParserNodeAttribute_CRC(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FLowEntryXmlParserNodeAttribute_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FLowEntryXmlParserNodeAttribute_CRC() { return 3012568164U; }
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
