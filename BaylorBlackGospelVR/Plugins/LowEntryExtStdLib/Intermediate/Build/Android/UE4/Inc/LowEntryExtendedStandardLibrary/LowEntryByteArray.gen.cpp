// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LowEntryExtendedStandardLibrary/Public/Classes/LowEntryByteArray.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeLowEntryByteArray() {}
// Cross Module References
	LOWENTRYEXTENDEDSTANDARDLIBRARY_API UClass* Z_Construct_UClass_ULowEntryByteArray_NoRegister();
	LOWENTRYEXTENDEDSTANDARDLIBRARY_API UClass* Z_Construct_UClass_ULowEntryByteArray();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_LowEntryExtendedStandardLibrary();
// End Cross Module References
	void ULowEntryByteArray::StaticRegisterNativesULowEntryByteArray()
	{
	}
	UClass* Z_Construct_UClass_ULowEntryByteArray_NoRegister()
	{
		return ULowEntryByteArray::StaticClass();
	}
	struct Z_Construct_UClass_ULowEntryByteArray_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ByteArray_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_ByteArray;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_ByteArray_Inner;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ULowEntryByteArray_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_LowEntryExtendedStandardLibrary,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULowEntryByteArray_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "Classes/LowEntryByteArray.h" },
		{ "ModuleRelativePath", "Public/Classes/LowEntryByteArray.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULowEntryByteArray_Statics::NewProp_ByteArray_MetaData[] = {
		{ "ModuleRelativePath", "Public/Classes/LowEntryByteArray.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ULowEntryByteArray_Statics::NewProp_ByteArray = { UE4CodeGen_Private::EPropertyClass::Array, "ByteArray", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000000, 1, nullptr, STRUCT_OFFSET(ULowEntryByteArray, ByteArray), METADATA_PARAMS(Z_Construct_UClass_ULowEntryByteArray_Statics::NewProp_ByteArray_MetaData, ARRAY_COUNT(Z_Construct_UClass_ULowEntryByteArray_Statics::NewProp_ByteArray_MetaData)) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UClass_ULowEntryByteArray_Statics::NewProp_ByteArray_Inner = { UE4CodeGen_Private::EPropertyClass::Byte, "ByteArray", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ULowEntryByteArray_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULowEntryByteArray_Statics::NewProp_ByteArray,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULowEntryByteArray_Statics::NewProp_ByteArray_Inner,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ULowEntryByteArray_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ULowEntryByteArray>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ULowEntryByteArray_Statics::ClassParams = {
		&ULowEntryByteArray::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x001000A0u,
		nullptr, 0,
		Z_Construct_UClass_ULowEntryByteArray_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_ULowEntryByteArray_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_ULowEntryByteArray_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_ULowEntryByteArray_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ULowEntryByteArray()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ULowEntryByteArray_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ULowEntryByteArray, 1921256092);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ULowEntryByteArray(Z_Construct_UClass_ULowEntryByteArray, &ULowEntryByteArray::StaticClass, TEXT("/Script/LowEntryExtendedStandardLibrary"), TEXT("ULowEntryByteArray"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ULowEntryByteArray);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
