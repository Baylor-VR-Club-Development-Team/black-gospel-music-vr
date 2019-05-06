// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LowEntryExtendedStandardLibrary/Public/Classes/ELowEntryBatteryState.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeELowEntryBatteryState() {}
// Cross Module References
	LOWENTRYEXTENDEDSTANDARDLIBRARY_API UEnum* Z_Construct_UEnum_LowEntryExtendedStandardLibrary_ELowEntryBatteryState();
	UPackage* Z_Construct_UPackage__Script_LowEntryExtendedStandardLibrary();
// End Cross Module References
	static UEnum* ELowEntryBatteryState_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_LowEntryExtendedStandardLibrary_ELowEntryBatteryState, Z_Construct_UPackage__Script_LowEntryExtendedStandardLibrary(), TEXT("ELowEntryBatteryState"));
		}
		return Singleton;
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_ELowEntryBatteryState(ELowEntryBatteryState_StaticEnum, TEXT("/Script/LowEntryExtendedStandardLibrary"), TEXT("ELowEntryBatteryState"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_LowEntryExtendedStandardLibrary_ELowEntryBatteryState_CRC() { return 1344920099U; }
	UEnum* Z_Construct_UEnum_LowEntryExtendedStandardLibrary_ELowEntryBatteryState()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_LowEntryExtendedStandardLibrary();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("ELowEntryBatteryState"), 0, Get_Z_Construct_UEnum_LowEntryExtendedStandardLibrary_ELowEntryBatteryState_CRC(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "ELowEntryBatteryState::Charging", (int64)ELowEntryBatteryState::Charging },
				{ "ELowEntryBatteryState::Discharging", (int64)ELowEntryBatteryState::Discharging },
				{ "ELowEntryBatteryState::Full", (int64)ELowEntryBatteryState::Full },
				{ "ELowEntryBatteryState::NotCharging", (int64)ELowEntryBatteryState::NotCharging },
				{ "ELowEntryBatteryState::Unknown", (int64)ELowEntryBatteryState::Unknown },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "ModuleRelativePath", "Public/Classes/ELowEntryBatteryState.h" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_LowEntryExtendedStandardLibrary,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				"ELowEntryBatteryState",
				RF_Public|RF_Transient|RF_MarkAsNative,
				nullptr,
				(uint8)UEnum::ECppForm::EnumClass,
				"ELowEntryBatteryState",
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
