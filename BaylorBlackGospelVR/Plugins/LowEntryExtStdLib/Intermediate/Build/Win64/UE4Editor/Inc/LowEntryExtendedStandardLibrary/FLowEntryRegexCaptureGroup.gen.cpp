// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LowEntryExtendedStandardLibrary/Public/Classes/FLowEntryRegexCaptureGroup.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFLowEntryRegexCaptureGroup() {}
// Cross Module References
	LOWENTRYEXTENDEDSTANDARDLIBRARY_API UScriptStruct* Z_Construct_UScriptStruct_FLowEntryRegexCaptureGroup();
	UPackage* Z_Construct_UPackage__Script_LowEntryExtendedStandardLibrary();
// End Cross Module References
class UScriptStruct* FLowEntryRegexCaptureGroup::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern LOWENTRYEXTENDEDSTANDARDLIBRARY_API uint32 Get_Z_Construct_UScriptStruct_FLowEntryRegexCaptureGroup_CRC();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FLowEntryRegexCaptureGroup, Z_Construct_UPackage__Script_LowEntryExtendedStandardLibrary(), TEXT("LowEntryRegexCaptureGroup"), sizeof(FLowEntryRegexCaptureGroup), Get_Z_Construct_UScriptStruct_FLowEntryRegexCaptureGroup_CRC());
	}
	return Singleton;
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FLowEntryRegexCaptureGroup(FLowEntryRegexCaptureGroup::StaticStruct, TEXT("/Script/LowEntryExtendedStandardLibrary"), TEXT("LowEntryRegexCaptureGroup"), false, nullptr, nullptr);
static struct FScriptStruct_LowEntryExtendedStandardLibrary_StaticRegisterNativesFLowEntryRegexCaptureGroup
{
	FScriptStruct_LowEntryExtendedStandardLibrary_StaticRegisterNativesFLowEntryRegexCaptureGroup()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("LowEntryRegexCaptureGroup")),new UScriptStruct::TCppStructOps<FLowEntryRegexCaptureGroup>);
	}
} ScriptStruct_LowEntryExtendedStandardLibrary_StaticRegisterNativesFLowEntryRegexCaptureGroup;
	struct Z_Construct_UScriptStruct_FLowEntryRegexCaptureGroup_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Match_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_Match;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_EndIndex_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_EndIndex;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BeginIndex_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_BeginIndex;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CaptureGroupNumber_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_CaptureGroupNumber;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FLowEntryRegexCaptureGroup_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Classes/FLowEntryRegexCaptureGroup.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FLowEntryRegexCaptureGroup_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FLowEntryRegexCaptureGroup>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FLowEntryRegexCaptureGroup_Statics::NewProp_Match_MetaData[] = {
		{ "Category", "Low Entry|Extended Standard Library|Utilities|String" },
		{ "ModuleRelativePath", "Public/Classes/FLowEntryRegexCaptureGroup.h" },
		{ "ToolTip", "This is the text of the capture group match." },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FLowEntryRegexCaptureGroup_Statics::NewProp_Match = { UE4CodeGen_Private::EPropertyClass::Str, "Match", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FLowEntryRegexCaptureGroup, Match), METADATA_PARAMS(Z_Construct_UScriptStruct_FLowEntryRegexCaptureGroup_Statics::NewProp_Match_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FLowEntryRegexCaptureGroup_Statics::NewProp_Match_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FLowEntryRegexCaptureGroup_Statics::NewProp_EndIndex_MetaData[] = {
		{ "Category", "Low Entry|Extended Standard Library|Utilities|String" },
		{ "ModuleRelativePath", "Public/Classes/FLowEntryRegexCaptureGroup.h" },
		{ "ToolTip", "This is the end index of the capture group match." },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FLowEntryRegexCaptureGroup_Statics::NewProp_EndIndex = { UE4CodeGen_Private::EPropertyClass::Int, "EndIndex", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FLowEntryRegexCaptureGroup, EndIndex), METADATA_PARAMS(Z_Construct_UScriptStruct_FLowEntryRegexCaptureGroup_Statics::NewProp_EndIndex_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FLowEntryRegexCaptureGroup_Statics::NewProp_EndIndex_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FLowEntryRegexCaptureGroup_Statics::NewProp_BeginIndex_MetaData[] = {
		{ "Category", "Low Entry|Extended Standard Library|Utilities|String" },
		{ "ModuleRelativePath", "Public/Classes/FLowEntryRegexCaptureGroup.h" },
		{ "ToolTip", "This is the start index of the capture group match." },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FLowEntryRegexCaptureGroup_Statics::NewProp_BeginIndex = { UE4CodeGen_Private::EPropertyClass::Int, "BeginIndex", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FLowEntryRegexCaptureGroup, BeginIndex), METADATA_PARAMS(Z_Construct_UScriptStruct_FLowEntryRegexCaptureGroup_Statics::NewProp_BeginIndex_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FLowEntryRegexCaptureGroup_Statics::NewProp_BeginIndex_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FLowEntryRegexCaptureGroup_Statics::NewProp_CaptureGroupNumber_MetaData[] = {
		{ "Category", "Low Entry|Extended Standard Library|Utilities|String" },
		{ "ModuleRelativePath", "Public/Classes/FLowEntryRegexCaptureGroup.h" },
		{ "ToolTip", "This is the number of the capture group, starting with 1." },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FLowEntryRegexCaptureGroup_Statics::NewProp_CaptureGroupNumber = { UE4CodeGen_Private::EPropertyClass::Int, "CaptureGroupNumber", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FLowEntryRegexCaptureGroup, CaptureGroupNumber), METADATA_PARAMS(Z_Construct_UScriptStruct_FLowEntryRegexCaptureGroup_Statics::NewProp_CaptureGroupNumber_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FLowEntryRegexCaptureGroup_Statics::NewProp_CaptureGroupNumber_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FLowEntryRegexCaptureGroup_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FLowEntryRegexCaptureGroup_Statics::NewProp_Match,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FLowEntryRegexCaptureGroup_Statics::NewProp_EndIndex,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FLowEntryRegexCaptureGroup_Statics::NewProp_BeginIndex,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FLowEntryRegexCaptureGroup_Statics::NewProp_CaptureGroupNumber,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FLowEntryRegexCaptureGroup_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_LowEntryExtendedStandardLibrary,
		nullptr,
		&NewStructOps,
		"LowEntryRegexCaptureGroup",
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		sizeof(FLowEntryRegexCaptureGroup),
		alignof(FLowEntryRegexCaptureGroup),
		Z_Construct_UScriptStruct_FLowEntryRegexCaptureGroup_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UScriptStruct_FLowEntryRegexCaptureGroup_Statics::PropPointers),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FLowEntryRegexCaptureGroup_Statics::Struct_MetaDataParams, ARRAY_COUNT(Z_Construct_UScriptStruct_FLowEntryRegexCaptureGroup_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FLowEntryRegexCaptureGroup()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FLowEntryRegexCaptureGroup_CRC();
		UPackage* Outer = Z_Construct_UPackage__Script_LowEntryExtendedStandardLibrary();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("LowEntryRegexCaptureGroup"), sizeof(FLowEntryRegexCaptureGroup), Get_Z_Construct_UScriptStruct_FLowEntryRegexCaptureGroup_CRC(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FLowEntryRegexCaptureGroup_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FLowEntryRegexCaptureGroup_CRC() { return 2777092360U; }
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
