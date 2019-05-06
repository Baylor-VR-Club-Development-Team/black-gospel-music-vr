// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LowEntryExtendedStandardLibrary/Public/Classes/LowEntryExecutionQueue.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeLowEntryExecutionQueue() {}
// Cross Module References
	LOWENTRYEXTENDEDSTANDARDLIBRARY_API UClass* Z_Construct_UClass_ULowEntryExecutionQueue_NoRegister();
	LOWENTRYEXTENDEDSTANDARDLIBRARY_API UClass* Z_Construct_UClass_ULowEntryExecutionQueue();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_LowEntryExtendedStandardLibrary();
// End Cross Module References
	void ULowEntryExecutionQueue::StaticRegisterNativesULowEntryExecutionQueue()
	{
	}
	UClass* Z_Construct_UClass_ULowEntryExecutionQueue_NoRegister()
	{
		return ULowEntryExecutionQueue::StaticClass();
	}
	struct Z_Construct_UClass_ULowEntryExecutionQueue_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Next_MetaData[];
#endif
		static void NewProp_Next_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_Next;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Count_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_Count;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ULowEntryExecutionQueue_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_LowEntryExtendedStandardLibrary,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULowEntryExecutionQueue_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "Classes/LowEntryExecutionQueue.h" },
		{ "ModuleRelativePath", "Public/Classes/LowEntryExecutionQueue.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULowEntryExecutionQueue_Statics::NewProp_Next_MetaData[] = {
		{ "ModuleRelativePath", "Public/Classes/LowEntryExecutionQueue.h" },
	};
#endif
	void Z_Construct_UClass_ULowEntryExecutionQueue_Statics::NewProp_Next_SetBit(void* Obj)
	{
		((ULowEntryExecutionQueue*)Obj)->Next = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ULowEntryExecutionQueue_Statics::NewProp_Next = { UE4CodeGen_Private::EPropertyClass::Bool, "Next", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000000, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(ULowEntryExecutionQueue), &Z_Construct_UClass_ULowEntryExecutionQueue_Statics::NewProp_Next_SetBit, METADATA_PARAMS(Z_Construct_UClass_ULowEntryExecutionQueue_Statics::NewProp_Next_MetaData, ARRAY_COUNT(Z_Construct_UClass_ULowEntryExecutionQueue_Statics::NewProp_Next_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULowEntryExecutionQueue_Statics::NewProp_Count_MetaData[] = {
		{ "ModuleRelativePath", "Public/Classes/LowEntryExecutionQueue.h" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_ULowEntryExecutionQueue_Statics::NewProp_Count = { UE4CodeGen_Private::EPropertyClass::Int, "Count", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000000, 1, nullptr, STRUCT_OFFSET(ULowEntryExecutionQueue, Count), METADATA_PARAMS(Z_Construct_UClass_ULowEntryExecutionQueue_Statics::NewProp_Count_MetaData, ARRAY_COUNT(Z_Construct_UClass_ULowEntryExecutionQueue_Statics::NewProp_Count_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ULowEntryExecutionQueue_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULowEntryExecutionQueue_Statics::NewProp_Next,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULowEntryExecutionQueue_Statics::NewProp_Count,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ULowEntryExecutionQueue_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ULowEntryExecutionQueue>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ULowEntryExecutionQueue_Statics::ClassParams = {
		&ULowEntryExecutionQueue::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x001000A0u,
		nullptr, 0,
		Z_Construct_UClass_ULowEntryExecutionQueue_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_ULowEntryExecutionQueue_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_ULowEntryExecutionQueue_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_ULowEntryExecutionQueue_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ULowEntryExecutionQueue()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ULowEntryExecutionQueue_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ULowEntryExecutionQueue, 566819955);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ULowEntryExecutionQueue(Z_Construct_UClass_ULowEntryExecutionQueue, &ULowEntryExecutionQueue::StaticClass, TEXT("/Script/LowEntryExtendedStandardLibrary"), TEXT("ULowEntryExecutionQueue"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ULowEntryExecutionQueue);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
