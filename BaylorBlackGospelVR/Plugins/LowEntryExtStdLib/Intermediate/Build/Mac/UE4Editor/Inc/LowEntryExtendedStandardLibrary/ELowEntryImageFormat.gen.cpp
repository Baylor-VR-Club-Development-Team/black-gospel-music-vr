// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LowEntryExtendedStandardLibrary/Public/Classes/ELowEntryImageFormat.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeELowEntryImageFormat() {}
// Cross Module References
	LOWENTRYEXTENDEDSTANDARDLIBRARY_API UEnum* Z_Construct_UEnum_LowEntryExtendedStandardLibrary_ELowEntryImageFormat();
	UPackage* Z_Construct_UPackage__Script_LowEntryExtendedStandardLibrary();
// End Cross Module References
	static UEnum* ELowEntryImageFormat_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_LowEntryExtendedStandardLibrary_ELowEntryImageFormat, Z_Construct_UPackage__Script_LowEntryExtendedStandardLibrary(), TEXT("ELowEntryImageFormat"));
		}
		return Singleton;
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_ELowEntryImageFormat(ELowEntryImageFormat_StaticEnum, TEXT("/Script/LowEntryExtendedStandardLibrary"), TEXT("ELowEntryImageFormat"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_LowEntryExtendedStandardLibrary_ELowEntryImageFormat_CRC() { return 3008454619U; }
	UEnum* Z_Construct_UEnum_LowEntryExtendedStandardLibrary_ELowEntryImageFormat()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_LowEntryExtendedStandardLibrary();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("ELowEntryImageFormat"), 0, Get_Z_Construct_UEnum_LowEntryExtendedStandardLibrary_ELowEntryImageFormat_CRC(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "ELowEntryImageFormat::Invalid", (int64)ELowEntryImageFormat::Invalid },
				{ "ELowEntryImageFormat::PNG", (int64)ELowEntryImageFormat::PNG },
				{ "ELowEntryImageFormat::JPEG", (int64)ELowEntryImageFormat::JPEG },
				{ "ELowEntryImageFormat::GrayscaleJPEG", (int64)ELowEntryImageFormat::GrayscaleJPEG },
				{ "ELowEntryImageFormat::BMP", (int64)ELowEntryImageFormat::BMP },
				{ "ELowEntryImageFormat::ICO", (int64)ELowEntryImageFormat::ICO },
				{ "ELowEntryImageFormat::EXR", (int64)ELowEntryImageFormat::EXR },
				{ "ELowEntryImageFormat::ICNS", (int64)ELowEntryImageFormat::ICNS },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BMP.ToolTip", "Windows Bitmap" },
				{ "EXR.ToolTip", "OpenEXR (HDR) image file format" },
				{ "GrayscaleJPEG.ToolTip", "Single channel jpeg" },
				{ "ICNS.ToolTip", "Mac icon" },
				{ "ICO.ToolTip", "Windows Icon resource" },
				{ "Invalid.ToolTip", "Invalid or unrecognized format" },
				{ "JPEG.ToolTip", "Joint Photographic Experts Group" },
				{ "ModuleRelativePath", "Public/Classes/ELowEntryImageFormat.h" },
				{ "PNG.ToolTip", "Portable Network Graphics" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_LowEntryExtendedStandardLibrary,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				"ELowEntryImageFormat",
				RF_Public|RF_Transient|RF_MarkAsNative,
				nullptr,
				(uint8)UEnum::ECppForm::EnumClass,
				"ELowEntryImageFormat",
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
