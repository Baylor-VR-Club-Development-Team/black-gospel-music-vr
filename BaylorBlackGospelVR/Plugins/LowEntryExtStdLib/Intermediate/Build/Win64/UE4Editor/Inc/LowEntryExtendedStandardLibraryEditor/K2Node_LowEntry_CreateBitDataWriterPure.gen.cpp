// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LowEntryExtendedStandardLibraryEditor/Public/Classes/K2Node_LowEntry_CreateBitDataWriterPure.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeK2Node_LowEntry_CreateBitDataWriterPure() {}
// Cross Module References
	LOWENTRYEXTENDEDSTANDARDLIBRARYEDITOR_API UClass* Z_Construct_UClass_UK2Node_LowEntry_CreateBitDataWriterPure_NoRegister();
	LOWENTRYEXTENDEDSTANDARDLIBRARYEDITOR_API UClass* Z_Construct_UClass_UK2Node_LowEntry_CreateBitDataWriterPure();
	BLUEPRINTGRAPH_API UClass* Z_Construct_UClass_UK2Node();
	UPackage* Z_Construct_UPackage__Script_LowEntryExtendedStandardLibraryEditor();
// End Cross Module References
	void UK2Node_LowEntry_CreateBitDataWriterPure::StaticRegisterNativesUK2Node_LowEntry_CreateBitDataWriterPure()
	{
	}
	UClass* Z_Construct_UClass_UK2Node_LowEntry_CreateBitDataWriterPure_NoRegister()
	{
		return UK2Node_LowEntry_CreateBitDataWriterPure::StaticClass();
	}
	struct Z_Construct_UClass_UK2Node_LowEntry_CreateBitDataWriterPure_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_NumInputs_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_NumInputs;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UK2Node_LowEntry_CreateBitDataWriterPure_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UK2Node,
		(UObject* (*)())Z_Construct_UPackage__Script_LowEntryExtendedStandardLibraryEditor,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UK2Node_LowEntry_CreateBitDataWriterPure_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Classes/K2Node_LowEntry_CreateBitDataWriterPure.h" },
		{ "ModuleRelativePath", "Public/Classes/K2Node_LowEntry_CreateBitDataWriterPure.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UK2Node_LowEntry_CreateBitDataWriterPure_Statics::NewProp_NumInputs_MetaData[] = {
		{ "ModuleRelativePath", "Public/Classes/K2Node_LowEntry_CreateBitDataWriterPure.h" },
		{ "ToolTip", "The number of input pins to generate for this node" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_UK2Node_LowEntry_CreateBitDataWriterPure_Statics::NewProp_NumInputs = { UE4CodeGen_Private::EPropertyClass::Int, "NumInputs", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000000, 1, nullptr, STRUCT_OFFSET(UK2Node_LowEntry_CreateBitDataWriterPure, NumInputs), METADATA_PARAMS(Z_Construct_UClass_UK2Node_LowEntry_CreateBitDataWriterPure_Statics::NewProp_NumInputs_MetaData, ARRAY_COUNT(Z_Construct_UClass_UK2Node_LowEntry_CreateBitDataWriterPure_Statics::NewProp_NumInputs_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UK2Node_LowEntry_CreateBitDataWriterPure_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UK2Node_LowEntry_CreateBitDataWriterPure_Statics::NewProp_NumInputs,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UK2Node_LowEntry_CreateBitDataWriterPure_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UK2Node_LowEntry_CreateBitDataWriterPure>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UK2Node_LowEntry_CreateBitDataWriterPure_Statics::ClassParams = {
		&UK2Node_LowEntry_CreateBitDataWriterPure::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x000800A0u,
		nullptr, 0,
		Z_Construct_UClass_UK2Node_LowEntry_CreateBitDataWriterPure_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_UK2Node_LowEntry_CreateBitDataWriterPure_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UK2Node_LowEntry_CreateBitDataWriterPure_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UK2Node_LowEntry_CreateBitDataWriterPure_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UK2Node_LowEntry_CreateBitDataWriterPure()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UK2Node_LowEntry_CreateBitDataWriterPure_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UK2Node_LowEntry_CreateBitDataWriterPure, 3115105126);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UK2Node_LowEntry_CreateBitDataWriterPure(Z_Construct_UClass_UK2Node_LowEntry_CreateBitDataWriterPure, &UK2Node_LowEntry_CreateBitDataWriterPure::StaticClass, TEXT("/Script/LowEntryExtendedStandardLibraryEditor"), TEXT("UK2Node_LowEntry_CreateBitDataWriterPure"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UK2Node_LowEntry_CreateBitDataWriterPure);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
