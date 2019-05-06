// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LowEntryExtendedStandardLibrary/Public/Classes/ELowEntrySplitScreenType.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeELowEntrySplitScreenType() {}
// Cross Module References
	LOWENTRYEXTENDEDSTANDARDLIBRARY_API UEnum* Z_Construct_UEnum_LowEntryExtendedStandardLibrary_ELowEntrySplitScreenType();
	UPackage* Z_Construct_UPackage__Script_LowEntryExtendedStandardLibrary();
// End Cross Module References
	static UEnum* ELowEntrySplitScreenType_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_LowEntryExtendedStandardLibrary_ELowEntrySplitScreenType, Z_Construct_UPackage__Script_LowEntryExtendedStandardLibrary(), TEXT("ELowEntrySplitScreenType"));
		}
		return Singleton;
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_ELowEntrySplitScreenType(ELowEntrySplitScreenType_StaticEnum, TEXT("/Script/LowEntryExtendedStandardLibrary"), TEXT("ELowEntrySplitScreenType"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_LowEntryExtendedStandardLibrary_ELowEntrySplitScreenType_CRC() { return 3824538751U; }
	UEnum* Z_Construct_UEnum_LowEntryExtendedStandardLibrary_ELowEntrySplitScreenType()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_LowEntryExtendedStandardLibrary();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("ELowEntrySplitScreenType"), 0, Get_Z_Construct_UEnum_LowEntryExtendedStandardLibrary_ELowEntrySplitScreenType_CRC(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "ELowEntrySplitScreenType::None", (int64)ELowEntrySplitScreenType::None },
				{ "ELowEntrySplitScreenType::TwoPlayer_Horizontal", (int64)ELowEntrySplitScreenType::TwoPlayer_Horizontal },
				{ "ELowEntrySplitScreenType::TwoPlayer_Vertical", (int64)ELowEntrySplitScreenType::TwoPlayer_Vertical },
				{ "ELowEntrySplitScreenType::ThreePlayer_FavorTop", (int64)ELowEntrySplitScreenType::ThreePlayer_FavorTop },
				{ "ELowEntrySplitScreenType::ThreePlayer_FavorBottom", (int64)ELowEntrySplitScreenType::ThreePlayer_FavorBottom },
				{ "ELowEntrySplitScreenType::ThreePlayer_Vertical", (int64)ELowEntrySplitScreenType::ThreePlayer_Vertical },
				{ "ELowEntrySplitScreenType::FourPlayer_Grid", (int64)ELowEntrySplitScreenType::FourPlayer_Grid },
				{ "ELowEntrySplitScreenType::FourPlayer_Vertical", (int64)ELowEntrySplitScreenType::FourPlayer_Vertical },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "ModuleRelativePath", "Public/Classes/ELowEntrySplitScreenType.h" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_LowEntryExtendedStandardLibrary,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				"ELowEntrySplitScreenType",
				RF_Public|RF_Transient|RF_MarkAsNative,
				nullptr,
				(uint8)UEnum::ECppForm::EnumClass,
				"ELowEntrySplitScreenType",
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
