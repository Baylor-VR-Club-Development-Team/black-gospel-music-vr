// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LowEntryHttpRequest/Public/Enums/ELowEntryHttpRequestType.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeELowEntryHttpRequestType() {}
// Cross Module References
	LOWENTRYHTTPREQUEST_API UEnum* Z_Construct_UEnum_LowEntryHttpRequest_ELowEntryHttpRequestType();
	UPackage* Z_Construct_UPackage__Script_LowEntryHttpRequest();
// End Cross Module References
	static UEnum* ELowEntryHttpRequestType_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_LowEntryHttpRequest_ELowEntryHttpRequestType, Z_Construct_UPackage__Script_LowEntryHttpRequest(), TEXT("ELowEntryHttpRequestType"));
		}
		return Singleton;
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_ELowEntryHttpRequestType(ELowEntryHttpRequestType_StaticEnum, TEXT("/Script/LowEntryHttpRequest"), TEXT("ELowEntryHttpRequestType"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_LowEntryHttpRequest_ELowEntryHttpRequestType_CRC() { return 1922465231U; }
	UEnum* Z_Construct_UEnum_LowEntryHttpRequest_ELowEntryHttpRequestType()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_LowEntryHttpRequest();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("ELowEntryHttpRequestType"), 0, Get_Z_Construct_UEnum_LowEntryHttpRequest_ELowEntryHttpRequestType_CRC(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "ELowEntryHttpRequestType::GET", (int64)ELowEntryHttpRequestType::GET },
				{ "ELowEntryHttpRequestType::POST", (int64)ELowEntryHttpRequestType::POST },
				{ "ELowEntryHttpRequestType::PUT", (int64)ELowEntryHttpRequestType::PUT },
				{ "ELowEntryHttpRequestType::_PATCH", (int64)ELowEntryHttpRequestType::_PATCH },
				{ "ELowEntryHttpRequestType::_DELETE", (int64)ELowEntryHttpRequestType::_DELETE },
				{ "ELowEntryHttpRequestType::_CONNECT", (int64)ELowEntryHttpRequestType::_CONNECT },
				{ "ELowEntryHttpRequestType::_OPTIONS", (int64)ELowEntryHttpRequestType::_OPTIONS },
				{ "ELowEntryHttpRequestType::_HEAD", (int64)ELowEntryHttpRequestType::_HEAD },
				{ "ELowEntryHttpRequestType::_TRACE", (int64)ELowEntryHttpRequestType::_TRACE },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "ModuleRelativePath", "Public/Enums/ELowEntryHttpRequestType.h" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_LowEntryHttpRequest,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				"ELowEntryHttpRequestType",
				RF_Public|RF_Transient|RF_MarkAsNative,
				nullptr,
				(uint8)UEnum::ECppForm::EnumClass,
				"ELowEntryHttpRequestType",
				Enumerators,
				ARRAY_COUNT(Enumerators),
				METADATA_PARAMS(Enum_MetaDataParams, ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
