// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LowEntryExtendedStandardLibrary/Public/Classes/LowEntryByteDataReader.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeLowEntryByteDataReader() {}
// Cross Module References
	LOWENTRYEXTENDEDSTANDARDLIBRARY_API UClass* Z_Construct_UClass_ULowEntryByteDataReader_NoRegister();
	LOWENTRYEXTENDEDSTANDARDLIBRARY_API UClass* Z_Construct_UClass_ULowEntryByteDataReader();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_LowEntryExtendedStandardLibrary();
	LOWENTRYEXTENDEDSTANDARDLIBRARY_API UFunction* Z_Construct_UFunction_ULowEntryByteDataReader_Empty();
	LOWENTRYEXTENDEDSTANDARDLIBRARY_API UFunction* Z_Construct_UFunction_ULowEntryByteDataReader_GetBoolean();
	LOWENTRYEXTENDEDSTANDARDLIBRARY_API UFunction* Z_Construct_UFunction_ULowEntryByteDataReader_GetBooleanArray();
	LOWENTRYEXTENDEDSTANDARDLIBRARY_API UFunction* Z_Construct_UFunction_ULowEntryByteDataReader_GetByte();
	LOWENTRYEXTENDEDSTANDARDLIBRARY_API UFunction* Z_Construct_UFunction_ULowEntryByteDataReader_GetByteArray();
	LOWENTRYEXTENDEDSTANDARDLIBRARY_API UFunction* Z_Construct_UFunction_ULowEntryByteDataReader_GetClone();
	LOWENTRYEXTENDEDSTANDARDLIBRARY_API UFunction* Z_Construct_UFunction_ULowEntryByteDataReader_GetDoubleBytes();
	LOWENTRYEXTENDEDSTANDARDLIBRARY_API UClass* Z_Construct_UClass_ULowEntryDouble_NoRegister();
	LOWENTRYEXTENDEDSTANDARDLIBRARY_API UFunction* Z_Construct_UFunction_ULowEntryByteDataReader_GetDoubleBytesArray();
	LOWENTRYEXTENDEDSTANDARDLIBRARY_API UFunction* Z_Construct_UFunction_ULowEntryByteDataReader_GetFloat();
	LOWENTRYEXTENDEDSTANDARDLIBRARY_API UFunction* Z_Construct_UFunction_ULowEntryByteDataReader_GetFloatArray();
	LOWENTRYEXTENDEDSTANDARDLIBRARY_API UFunction* Z_Construct_UFunction_ULowEntryByteDataReader_GetInteger();
	LOWENTRYEXTENDEDSTANDARDLIBRARY_API UFunction* Z_Construct_UFunction_ULowEntryByteDataReader_GetIntegerArray();
	LOWENTRYEXTENDEDSTANDARDLIBRARY_API UFunction* Z_Construct_UFunction_ULowEntryByteDataReader_GetLongBytes();
	LOWENTRYEXTENDEDSTANDARDLIBRARY_API UClass* Z_Construct_UClass_ULowEntryLong_NoRegister();
	LOWENTRYEXTENDEDSTANDARDLIBRARY_API UFunction* Z_Construct_UFunction_ULowEntryByteDataReader_GetLongBytesArray();
	LOWENTRYEXTENDEDSTANDARDLIBRARY_API UFunction* Z_Construct_UFunction_ULowEntryByteDataReader_GetPosition();
	LOWENTRYEXTENDEDSTANDARDLIBRARY_API UFunction* Z_Construct_UFunction_ULowEntryByteDataReader_GetPositiveInteger1();
	LOWENTRYEXTENDEDSTANDARDLIBRARY_API UFunction* Z_Construct_UFunction_ULowEntryByteDataReader_GetPositiveInteger1Array();
	LOWENTRYEXTENDEDSTANDARDLIBRARY_API UFunction* Z_Construct_UFunction_ULowEntryByteDataReader_GetPositiveInteger2();
	LOWENTRYEXTENDEDSTANDARDLIBRARY_API UFunction* Z_Construct_UFunction_ULowEntryByteDataReader_GetPositiveInteger2Array();
	LOWENTRYEXTENDEDSTANDARDLIBRARY_API UFunction* Z_Construct_UFunction_ULowEntryByteDataReader_GetPositiveInteger3();
	LOWENTRYEXTENDEDSTANDARDLIBRARY_API UFunction* Z_Construct_UFunction_ULowEntryByteDataReader_GetPositiveInteger3Array();
	LOWENTRYEXTENDEDSTANDARDLIBRARY_API UFunction* Z_Construct_UFunction_ULowEntryByteDataReader_GetStringUtf8();
	LOWENTRYEXTENDEDSTANDARDLIBRARY_API UFunction* Z_Construct_UFunction_ULowEntryByteDataReader_GetStringUtf8Array();
	LOWENTRYEXTENDEDSTANDARDLIBRARY_API UFunction* Z_Construct_UFunction_ULowEntryByteDataReader_Remaining();
	LOWENTRYEXTENDEDSTANDARDLIBRARY_API UFunction* Z_Construct_UFunction_ULowEntryByteDataReader_Reset();
	LOWENTRYEXTENDEDSTANDARDLIBRARY_API UFunction* Z_Construct_UFunction_ULowEntryByteDataReader_SetPosition();
// End Cross Module References
	void ULowEntryByteDataReader::StaticRegisterNativesULowEntryByteDataReader()
	{
		UClass* Class = ULowEntryByteDataReader::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "Empty", &ULowEntryByteDataReader::execEmpty },
			{ "GetBoolean", &ULowEntryByteDataReader::execGetBoolean },
			{ "GetBooleanArray", &ULowEntryByteDataReader::execGetBooleanArray },
			{ "GetByte", &ULowEntryByteDataReader::execGetByte },
			{ "GetByteArray", &ULowEntryByteDataReader::execGetByteArray },
			{ "GetClone", &ULowEntryByteDataReader::execGetClone },
			{ "GetDoubleBytes", &ULowEntryByteDataReader::execGetDoubleBytes },
			{ "GetDoubleBytesArray", &ULowEntryByteDataReader::execGetDoubleBytesArray },
			{ "GetFloat", &ULowEntryByteDataReader::execGetFloat },
			{ "GetFloatArray", &ULowEntryByteDataReader::execGetFloatArray },
			{ "GetInteger", &ULowEntryByteDataReader::execGetInteger },
			{ "GetIntegerArray", &ULowEntryByteDataReader::execGetIntegerArray },
			{ "GetLongBytes", &ULowEntryByteDataReader::execGetLongBytes },
			{ "GetLongBytesArray", &ULowEntryByteDataReader::execGetLongBytesArray },
			{ "GetPosition", &ULowEntryByteDataReader::execGetPosition },
			{ "GetPositiveInteger1", &ULowEntryByteDataReader::execGetPositiveInteger1 },
			{ "GetPositiveInteger1Array", &ULowEntryByteDataReader::execGetPositiveInteger1Array },
			{ "GetPositiveInteger2", &ULowEntryByteDataReader::execGetPositiveInteger2 },
			{ "GetPositiveInteger2Array", &ULowEntryByteDataReader::execGetPositiveInteger2Array },
			{ "GetPositiveInteger3", &ULowEntryByteDataReader::execGetPositiveInteger3 },
			{ "GetPositiveInteger3Array", &ULowEntryByteDataReader::execGetPositiveInteger3Array },
			{ "GetStringUtf8", &ULowEntryByteDataReader::execGetStringUtf8 },
			{ "GetStringUtf8Array", &ULowEntryByteDataReader::execGetStringUtf8Array },
			{ "Remaining", &ULowEntryByteDataReader::execRemaining },
			{ "Reset", &ULowEntryByteDataReader::execReset },
			{ "SetPosition", &ULowEntryByteDataReader::execSetPosition },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ULowEntryByteDataReader_Empty_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryByteDataReader_Empty_Statics::Function_MetaDataParams[] = {
		{ "Category", "Low Entry|Extended Standard Library|Byte Data|Reader (Meta)" },
		{ "DisplayName", "Empty" },
		{ "ModuleRelativePath", "Public/Classes/LowEntryByteDataReader.h" },
		{ "ToolTip", "Causes Remaining to return 0." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULowEntryByteDataReader_Empty_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULowEntryByteDataReader, "Empty", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULowEntryByteDataReader_Empty_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataReader_Empty_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULowEntryByteDataReader_Empty()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULowEntryByteDataReader_Empty_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULowEntryByteDataReader_GetBoolean_Statics
	{
		struct LowEntryByteDataReader_eventGetBoolean_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ULowEntryByteDataReader_GetBoolean_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((LowEntryByteDataReader_eventGetBoolean_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ULowEntryByteDataReader_GetBoolean_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Bool, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(LowEntryByteDataReader_eventGetBoolean_Parms), &Z_Construct_UFunction_ULowEntryByteDataReader_GetBoolean_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULowEntryByteDataReader_GetBoolean_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryByteDataReader_GetBoolean_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryByteDataReader_GetBoolean_Statics::Function_MetaDataParams[] = {
		{ "Category", "Low Entry|Extended Standard Library|Byte Data|Reader" },
		{ "DisplayName", "Get Boolean" },
		{ "ModuleRelativePath", "Public/Classes/LowEntryByteDataReader.h" },
		{ "ToolTip", "Gets a boolean." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULowEntryByteDataReader_GetBoolean_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULowEntryByteDataReader, "GetBoolean", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(LowEntryByteDataReader_eventGetBoolean_Parms), Z_Construct_UFunction_ULowEntryByteDataReader_GetBoolean_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataReader_GetBoolean_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULowEntryByteDataReader_GetBoolean_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataReader_GetBoolean_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULowEntryByteDataReader_GetBoolean()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULowEntryByteDataReader_GetBoolean_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULowEntryByteDataReader_GetBooleanArray_Statics
	{
		struct LowEntryByteDataReader_eventGetBooleanArray_Parms
		{
			TArray<bool> ReturnValue;
		};
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue_Inner;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_ULowEntryByteDataReader_GetBooleanArray_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Array, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(LowEntryByteDataReader_eventGetBooleanArray_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ULowEntryByteDataReader_GetBooleanArray_Statics::NewProp_ReturnValue_Inner = { UE4CodeGen_Private::EPropertyClass::Bool, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULowEntryByteDataReader_GetBooleanArray_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryByteDataReader_GetBooleanArray_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryByteDataReader_GetBooleanArray_Statics::NewProp_ReturnValue_Inner,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryByteDataReader_GetBooleanArray_Statics::Function_MetaDataParams[] = {
		{ "Category", "Low Entry|Extended Standard Library|Byte Data|Reader" },
		{ "DisplayName", "Get Boolean Array" },
		{ "ModuleRelativePath", "Public/Classes/LowEntryByteDataReader.h" },
		{ "ToolTip", "Gets a boolean array." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULowEntryByteDataReader_GetBooleanArray_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULowEntryByteDataReader, "GetBooleanArray", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(LowEntryByteDataReader_eventGetBooleanArray_Parms), Z_Construct_UFunction_ULowEntryByteDataReader_GetBooleanArray_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataReader_GetBooleanArray_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULowEntryByteDataReader_GetBooleanArray_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataReader_GetBooleanArray_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULowEntryByteDataReader_GetBooleanArray()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULowEntryByteDataReader_GetBooleanArray_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULowEntryByteDataReader_GetByte_Statics
	{
		struct LowEntryByteDataReader_eventGetByte_Parms
		{
			uint8 ReturnValue;
		};
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_ULowEntryByteDataReader_GetByte_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Byte, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(LowEntryByteDataReader_eventGetByte_Parms, ReturnValue), nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULowEntryByteDataReader_GetByte_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryByteDataReader_GetByte_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryByteDataReader_GetByte_Statics::Function_MetaDataParams[] = {
		{ "Category", "Low Entry|Extended Standard Library|Byte Data|Reader" },
		{ "DisplayName", "Get Byte" },
		{ "ModuleRelativePath", "Public/Classes/LowEntryByteDataReader.h" },
		{ "ToolTip", "Gets a byte." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULowEntryByteDataReader_GetByte_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULowEntryByteDataReader, "GetByte", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(LowEntryByteDataReader_eventGetByte_Parms), Z_Construct_UFunction_ULowEntryByteDataReader_GetByte_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataReader_GetByte_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULowEntryByteDataReader_GetByte_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataReader_GetByte_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULowEntryByteDataReader_GetByte()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULowEntryByteDataReader_GetByte_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULowEntryByteDataReader_GetByteArray_Statics
	{
		struct LowEntryByteDataReader_eventGetByteArray_Parms
		{
			TArray<uint8> ReturnValue;
		};
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Inner;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_ULowEntryByteDataReader_GetByteArray_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Array, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(LowEntryByteDataReader_eventGetByteArray_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_ULowEntryByteDataReader_GetByteArray_Statics::NewProp_ReturnValue_Inner = { UE4CodeGen_Private::EPropertyClass::Byte, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULowEntryByteDataReader_GetByteArray_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryByteDataReader_GetByteArray_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryByteDataReader_GetByteArray_Statics::NewProp_ReturnValue_Inner,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryByteDataReader_GetByteArray_Statics::Function_MetaDataParams[] = {
		{ "Category", "Low Entry|Extended Standard Library|Byte Data|Reader" },
		{ "DisplayName", "Get Byte Array" },
		{ "ModuleRelativePath", "Public/Classes/LowEntryByteDataReader.h" },
		{ "ToolTip", "Gets a byte array." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULowEntryByteDataReader_GetByteArray_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULowEntryByteDataReader, "GetByteArray", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(LowEntryByteDataReader_eventGetByteArray_Parms), Z_Construct_UFunction_ULowEntryByteDataReader_GetByteArray_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataReader_GetByteArray_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULowEntryByteDataReader_GetByteArray_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataReader_GetByteArray_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULowEntryByteDataReader_GetByteArray()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULowEntryByteDataReader_GetByteArray_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULowEntryByteDataReader_GetClone_Statics
	{
		struct LowEntryByteDataReader_eventGetClone_Parms
		{
			ULowEntryByteDataReader* ReturnValue;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ULowEntryByteDataReader_GetClone_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Object, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(LowEntryByteDataReader_eventGetClone_Parms, ReturnValue), Z_Construct_UClass_ULowEntryByteDataReader_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULowEntryByteDataReader_GetClone_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryByteDataReader_GetClone_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryByteDataReader_GetClone_Statics::Function_MetaDataParams[] = {
		{ "Category", "Low Entry|Extended Standard Library|Byte Data|Reader (Meta)" },
		{ "DisplayName", "Get Clone" },
		{ "ModuleRelativePath", "Public/Classes/LowEntryByteDataReader.h" },
		{ "ToolTip", "Clones the clone of this ByteDataReader.\n\nAllows you to easily read and revert the position (by cloning, reading data with the clone, and then throwing the clone away)." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULowEntryByteDataReader_GetClone_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULowEntryByteDataReader, "GetClone", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(LowEntryByteDataReader_eventGetClone_Parms), Z_Construct_UFunction_ULowEntryByteDataReader_GetClone_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataReader_GetClone_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULowEntryByteDataReader_GetClone_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataReader_GetClone_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULowEntryByteDataReader_GetClone()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULowEntryByteDataReader_GetClone_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULowEntryByteDataReader_GetDoubleBytes_Statics
	{
		struct LowEntryByteDataReader_eventGetDoubleBytes_Parms
		{
			ULowEntryDouble* ReturnValue;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ULowEntryByteDataReader_GetDoubleBytes_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Object, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(LowEntryByteDataReader_eventGetDoubleBytes_Parms, ReturnValue), Z_Construct_UClass_ULowEntryDouble_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULowEntryByteDataReader_GetDoubleBytes_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryByteDataReader_GetDoubleBytes_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryByteDataReader_GetDoubleBytes_Statics::Function_MetaDataParams[] = {
		{ "Category", "Low Entry|Extended Standard Library|Byte Data|Reader" },
		{ "DisplayName", "Get Double (bytes)" },
		{ "ModuleRelativePath", "Public/Classes/LowEntryByteDataReader.h" },
		{ "ToolTip", "Gets a double (bytes)." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULowEntryByteDataReader_GetDoubleBytes_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULowEntryByteDataReader, "GetDoubleBytes", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(LowEntryByteDataReader_eventGetDoubleBytes_Parms), Z_Construct_UFunction_ULowEntryByteDataReader_GetDoubleBytes_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataReader_GetDoubleBytes_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULowEntryByteDataReader_GetDoubleBytes_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataReader_GetDoubleBytes_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULowEntryByteDataReader_GetDoubleBytes()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULowEntryByteDataReader_GetDoubleBytes_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULowEntryByteDataReader_GetDoubleBytesArray_Statics
	{
		struct LowEntryByteDataReader_eventGetDoubleBytesArray_Parms
		{
			TArray<ULowEntryDouble*> ReturnValue;
		};
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue_Inner;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_ULowEntryByteDataReader_GetDoubleBytesArray_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Array, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(LowEntryByteDataReader_eventGetDoubleBytesArray_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ULowEntryByteDataReader_GetDoubleBytesArray_Statics::NewProp_ReturnValue_Inner = { UE4CodeGen_Private::EPropertyClass::Object, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, Z_Construct_UClass_ULowEntryDouble_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULowEntryByteDataReader_GetDoubleBytesArray_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryByteDataReader_GetDoubleBytesArray_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryByteDataReader_GetDoubleBytesArray_Statics::NewProp_ReturnValue_Inner,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryByteDataReader_GetDoubleBytesArray_Statics::Function_MetaDataParams[] = {
		{ "Category", "Low Entry|Extended Standard Library|Byte Data|Reader" },
		{ "DisplayName", "Get Double (bytes) Array" },
		{ "ModuleRelativePath", "Public/Classes/LowEntryByteDataReader.h" },
		{ "ToolTip", "Gets a double (byte) array." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULowEntryByteDataReader_GetDoubleBytesArray_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULowEntryByteDataReader, "GetDoubleBytesArray", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(LowEntryByteDataReader_eventGetDoubleBytesArray_Parms), Z_Construct_UFunction_ULowEntryByteDataReader_GetDoubleBytesArray_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataReader_GetDoubleBytesArray_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULowEntryByteDataReader_GetDoubleBytesArray_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataReader_GetDoubleBytesArray_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULowEntryByteDataReader_GetDoubleBytesArray()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULowEntryByteDataReader_GetDoubleBytesArray_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULowEntryByteDataReader_GetFloat_Statics
	{
		struct LowEntryByteDataReader_eventGetFloat_Parms
		{
			float ReturnValue;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ULowEntryByteDataReader_GetFloat_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Float, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(LowEntryByteDataReader_eventGetFloat_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULowEntryByteDataReader_GetFloat_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryByteDataReader_GetFloat_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryByteDataReader_GetFloat_Statics::Function_MetaDataParams[] = {
		{ "Category", "Low Entry|Extended Standard Library|Byte Data|Reader" },
		{ "DisplayName", "Get Float" },
		{ "ModuleRelativePath", "Public/Classes/LowEntryByteDataReader.h" },
		{ "ToolTip", "Gets a float." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULowEntryByteDataReader_GetFloat_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULowEntryByteDataReader, "GetFloat", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(LowEntryByteDataReader_eventGetFloat_Parms), Z_Construct_UFunction_ULowEntryByteDataReader_GetFloat_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataReader_GetFloat_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULowEntryByteDataReader_GetFloat_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataReader_GetFloat_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULowEntryByteDataReader_GetFloat()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULowEntryByteDataReader_GetFloat_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULowEntryByteDataReader_GetFloatArray_Statics
	{
		struct LowEntryByteDataReader_eventGetFloatArray_Parms
		{
			TArray<float> ReturnValue;
		};
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ReturnValue_Inner;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_ULowEntryByteDataReader_GetFloatArray_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Array, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(LowEntryByteDataReader_eventGetFloatArray_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ULowEntryByteDataReader_GetFloatArray_Statics::NewProp_ReturnValue_Inner = { UE4CodeGen_Private::EPropertyClass::Float, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULowEntryByteDataReader_GetFloatArray_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryByteDataReader_GetFloatArray_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryByteDataReader_GetFloatArray_Statics::NewProp_ReturnValue_Inner,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryByteDataReader_GetFloatArray_Statics::Function_MetaDataParams[] = {
		{ "Category", "Low Entry|Extended Standard Library|Byte Data|Reader" },
		{ "DisplayName", "Get Float Array" },
		{ "ModuleRelativePath", "Public/Classes/LowEntryByteDataReader.h" },
		{ "ToolTip", "Gets a float array." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULowEntryByteDataReader_GetFloatArray_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULowEntryByteDataReader, "GetFloatArray", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(LowEntryByteDataReader_eventGetFloatArray_Parms), Z_Construct_UFunction_ULowEntryByteDataReader_GetFloatArray_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataReader_GetFloatArray_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULowEntryByteDataReader_GetFloatArray_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataReader_GetFloatArray_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULowEntryByteDataReader_GetFloatArray()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULowEntryByteDataReader_GetFloatArray_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULowEntryByteDataReader_GetInteger_Statics
	{
		struct LowEntryByteDataReader_eventGetInteger_Parms
		{
			int32 ReturnValue;
		};
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ULowEntryByteDataReader_GetInteger_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Int, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(LowEntryByteDataReader_eventGetInteger_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULowEntryByteDataReader_GetInteger_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryByteDataReader_GetInteger_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryByteDataReader_GetInteger_Statics::Function_MetaDataParams[] = {
		{ "Category", "Low Entry|Extended Standard Library|Byte Data|Reader" },
		{ "DisplayName", "Get Integer" },
		{ "ModuleRelativePath", "Public/Classes/LowEntryByteDataReader.h" },
		{ "ToolTip", "Gets an integer." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULowEntryByteDataReader_GetInteger_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULowEntryByteDataReader, "GetInteger", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(LowEntryByteDataReader_eventGetInteger_Parms), Z_Construct_UFunction_ULowEntryByteDataReader_GetInteger_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataReader_GetInteger_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULowEntryByteDataReader_GetInteger_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataReader_GetInteger_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULowEntryByteDataReader_GetInteger()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULowEntryByteDataReader_GetInteger_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULowEntryByteDataReader_GetIntegerArray_Statics
	{
		struct LowEntryByteDataReader_eventGetIntegerArray_Parms
		{
			TArray<int32> ReturnValue;
		};
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_ReturnValue_Inner;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_ULowEntryByteDataReader_GetIntegerArray_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Array, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(LowEntryByteDataReader_eventGetIntegerArray_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ULowEntryByteDataReader_GetIntegerArray_Statics::NewProp_ReturnValue_Inner = { UE4CodeGen_Private::EPropertyClass::Int, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULowEntryByteDataReader_GetIntegerArray_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryByteDataReader_GetIntegerArray_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryByteDataReader_GetIntegerArray_Statics::NewProp_ReturnValue_Inner,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryByteDataReader_GetIntegerArray_Statics::Function_MetaDataParams[] = {
		{ "Category", "Low Entry|Extended Standard Library|Byte Data|Reader" },
		{ "DisplayName", "Get Integer Array" },
		{ "ModuleRelativePath", "Public/Classes/LowEntryByteDataReader.h" },
		{ "ToolTip", "Gets an integer array." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULowEntryByteDataReader_GetIntegerArray_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULowEntryByteDataReader, "GetIntegerArray", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(LowEntryByteDataReader_eventGetIntegerArray_Parms), Z_Construct_UFunction_ULowEntryByteDataReader_GetIntegerArray_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataReader_GetIntegerArray_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULowEntryByteDataReader_GetIntegerArray_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataReader_GetIntegerArray_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULowEntryByteDataReader_GetIntegerArray()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULowEntryByteDataReader_GetIntegerArray_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULowEntryByteDataReader_GetLongBytes_Statics
	{
		struct LowEntryByteDataReader_eventGetLongBytes_Parms
		{
			ULowEntryLong* ReturnValue;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ULowEntryByteDataReader_GetLongBytes_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Object, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(LowEntryByteDataReader_eventGetLongBytes_Parms, ReturnValue), Z_Construct_UClass_ULowEntryLong_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULowEntryByteDataReader_GetLongBytes_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryByteDataReader_GetLongBytes_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryByteDataReader_GetLongBytes_Statics::Function_MetaDataParams[] = {
		{ "Category", "Low Entry|Extended Standard Library|Byte Data|Reader" },
		{ "DisplayName", "Get Long (bytes)" },
		{ "ModuleRelativePath", "Public/Classes/LowEntryByteDataReader.h" },
		{ "ToolTip", "Gets a long (bytes)." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULowEntryByteDataReader_GetLongBytes_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULowEntryByteDataReader, "GetLongBytes", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(LowEntryByteDataReader_eventGetLongBytes_Parms), Z_Construct_UFunction_ULowEntryByteDataReader_GetLongBytes_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataReader_GetLongBytes_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULowEntryByteDataReader_GetLongBytes_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataReader_GetLongBytes_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULowEntryByteDataReader_GetLongBytes()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULowEntryByteDataReader_GetLongBytes_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULowEntryByteDataReader_GetLongBytesArray_Statics
	{
		struct LowEntryByteDataReader_eventGetLongBytesArray_Parms
		{
			TArray<ULowEntryLong*> ReturnValue;
		};
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue_Inner;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_ULowEntryByteDataReader_GetLongBytesArray_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Array, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(LowEntryByteDataReader_eventGetLongBytesArray_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ULowEntryByteDataReader_GetLongBytesArray_Statics::NewProp_ReturnValue_Inner = { UE4CodeGen_Private::EPropertyClass::Object, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, Z_Construct_UClass_ULowEntryLong_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULowEntryByteDataReader_GetLongBytesArray_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryByteDataReader_GetLongBytesArray_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryByteDataReader_GetLongBytesArray_Statics::NewProp_ReturnValue_Inner,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryByteDataReader_GetLongBytesArray_Statics::Function_MetaDataParams[] = {
		{ "Category", "Low Entry|Extended Standard Library|Byte Data|Reader" },
		{ "DisplayName", "Get Long (bytes) Array" },
		{ "ModuleRelativePath", "Public/Classes/LowEntryByteDataReader.h" },
		{ "ToolTip", "Gets a long (bytes) array." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULowEntryByteDataReader_GetLongBytesArray_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULowEntryByteDataReader, "GetLongBytesArray", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(LowEntryByteDataReader_eventGetLongBytesArray_Parms), Z_Construct_UFunction_ULowEntryByteDataReader_GetLongBytesArray_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataReader_GetLongBytesArray_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULowEntryByteDataReader_GetLongBytesArray_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataReader_GetLongBytesArray_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULowEntryByteDataReader_GetLongBytesArray()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULowEntryByteDataReader_GetLongBytesArray_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULowEntryByteDataReader_GetPosition_Statics
	{
		struct LowEntryByteDataReader_eventGetPosition_Parms
		{
			int32 ReturnValue;
		};
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ULowEntryByteDataReader_GetPosition_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Int, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(LowEntryByteDataReader_eventGetPosition_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULowEntryByteDataReader_GetPosition_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryByteDataReader_GetPosition_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryByteDataReader_GetPosition_Statics::Function_MetaDataParams[] = {
		{ "Category", "Low Entry|Extended Standard Library|Byte Data|Reader (Meta)" },
		{ "DisplayName", "Get Position" },
		{ "ModuleRelativePath", "Public/Classes/LowEntryByteDataReader.h" },
		{ "ToolTip", "Returns the current position." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULowEntryByteDataReader_GetPosition_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULowEntryByteDataReader, "GetPosition", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14020401, sizeof(LowEntryByteDataReader_eventGetPosition_Parms), Z_Construct_UFunction_ULowEntryByteDataReader_GetPosition_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataReader_GetPosition_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULowEntryByteDataReader_GetPosition_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataReader_GetPosition_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULowEntryByteDataReader_GetPosition()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULowEntryByteDataReader_GetPosition_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULowEntryByteDataReader_GetPositiveInteger1_Statics
	{
		struct LowEntryByteDataReader_eventGetPositiveInteger1_Parms
		{
			int32 ReturnValue;
		};
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ULowEntryByteDataReader_GetPositiveInteger1_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Int, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(LowEntryByteDataReader_eventGetPositiveInteger1_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULowEntryByteDataReader_GetPositiveInteger1_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryByteDataReader_GetPositiveInteger1_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryByteDataReader_GetPositiveInteger1_Statics::Function_MetaDataParams[] = {
		{ "Category", "Low Entry|Extended Standard Library|Byte Data|Reader" },
		{ "DisplayName", "Get Positive Integer 1" },
		{ "ModuleRelativePath", "Public/Classes/LowEntryByteDataReader.h" },
		{ "ToolTip", "Gets a positive integer." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULowEntryByteDataReader_GetPositiveInteger1_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULowEntryByteDataReader, "GetPositiveInteger1", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(LowEntryByteDataReader_eventGetPositiveInteger1_Parms), Z_Construct_UFunction_ULowEntryByteDataReader_GetPositiveInteger1_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataReader_GetPositiveInteger1_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULowEntryByteDataReader_GetPositiveInteger1_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataReader_GetPositiveInteger1_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULowEntryByteDataReader_GetPositiveInteger1()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULowEntryByteDataReader_GetPositiveInteger1_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULowEntryByteDataReader_GetPositiveInteger1Array_Statics
	{
		struct LowEntryByteDataReader_eventGetPositiveInteger1Array_Parms
		{
			TArray<int32> ReturnValue;
		};
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_ReturnValue_Inner;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_ULowEntryByteDataReader_GetPositiveInteger1Array_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Array, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(LowEntryByteDataReader_eventGetPositiveInteger1Array_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ULowEntryByteDataReader_GetPositiveInteger1Array_Statics::NewProp_ReturnValue_Inner = { UE4CodeGen_Private::EPropertyClass::Int, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULowEntryByteDataReader_GetPositiveInteger1Array_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryByteDataReader_GetPositiveInteger1Array_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryByteDataReader_GetPositiveInteger1Array_Statics::NewProp_ReturnValue_Inner,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryByteDataReader_GetPositiveInteger1Array_Statics::Function_MetaDataParams[] = {
		{ "Category", "Low Entry|Extended Standard Library|Byte Data|Reader" },
		{ "DisplayName", "Get Positive Integer 1 Array" },
		{ "ModuleRelativePath", "Public/Classes/LowEntryByteDataReader.h" },
		{ "ToolTip", "Gets a positive integer array." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULowEntryByteDataReader_GetPositiveInteger1Array_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULowEntryByteDataReader, "GetPositiveInteger1Array", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(LowEntryByteDataReader_eventGetPositiveInteger1Array_Parms), Z_Construct_UFunction_ULowEntryByteDataReader_GetPositiveInteger1Array_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataReader_GetPositiveInteger1Array_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULowEntryByteDataReader_GetPositiveInteger1Array_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataReader_GetPositiveInteger1Array_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULowEntryByteDataReader_GetPositiveInteger1Array()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULowEntryByteDataReader_GetPositiveInteger1Array_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULowEntryByteDataReader_GetPositiveInteger2_Statics
	{
		struct LowEntryByteDataReader_eventGetPositiveInteger2_Parms
		{
			int32 ReturnValue;
		};
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ULowEntryByteDataReader_GetPositiveInteger2_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Int, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(LowEntryByteDataReader_eventGetPositiveInteger2_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULowEntryByteDataReader_GetPositiveInteger2_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryByteDataReader_GetPositiveInteger2_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryByteDataReader_GetPositiveInteger2_Statics::Function_MetaDataParams[] = {
		{ "Category", "Low Entry|Extended Standard Library|Byte Data|Reader" },
		{ "DisplayName", "Get Positive Integer 2" },
		{ "ModuleRelativePath", "Public/Classes/LowEntryByteDataReader.h" },
		{ "ToolTip", "Gets a positive integer." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULowEntryByteDataReader_GetPositiveInteger2_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULowEntryByteDataReader, "GetPositiveInteger2", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(LowEntryByteDataReader_eventGetPositiveInteger2_Parms), Z_Construct_UFunction_ULowEntryByteDataReader_GetPositiveInteger2_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataReader_GetPositiveInteger2_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULowEntryByteDataReader_GetPositiveInteger2_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataReader_GetPositiveInteger2_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULowEntryByteDataReader_GetPositiveInteger2()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULowEntryByteDataReader_GetPositiveInteger2_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULowEntryByteDataReader_GetPositiveInteger2Array_Statics
	{
		struct LowEntryByteDataReader_eventGetPositiveInteger2Array_Parms
		{
			TArray<int32> ReturnValue;
		};
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_ReturnValue_Inner;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_ULowEntryByteDataReader_GetPositiveInteger2Array_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Array, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(LowEntryByteDataReader_eventGetPositiveInteger2Array_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ULowEntryByteDataReader_GetPositiveInteger2Array_Statics::NewProp_ReturnValue_Inner = { UE4CodeGen_Private::EPropertyClass::Int, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULowEntryByteDataReader_GetPositiveInteger2Array_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryByteDataReader_GetPositiveInteger2Array_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryByteDataReader_GetPositiveInteger2Array_Statics::NewProp_ReturnValue_Inner,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryByteDataReader_GetPositiveInteger2Array_Statics::Function_MetaDataParams[] = {
		{ "Category", "Low Entry|Extended Standard Library|Byte Data|Reader" },
		{ "DisplayName", "Get Positive Integer 2 Array" },
		{ "ModuleRelativePath", "Public/Classes/LowEntryByteDataReader.h" },
		{ "ToolTip", "Gets a positive integer array." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULowEntryByteDataReader_GetPositiveInteger2Array_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULowEntryByteDataReader, "GetPositiveInteger2Array", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(LowEntryByteDataReader_eventGetPositiveInteger2Array_Parms), Z_Construct_UFunction_ULowEntryByteDataReader_GetPositiveInteger2Array_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataReader_GetPositiveInteger2Array_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULowEntryByteDataReader_GetPositiveInteger2Array_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataReader_GetPositiveInteger2Array_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULowEntryByteDataReader_GetPositiveInteger2Array()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULowEntryByteDataReader_GetPositiveInteger2Array_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULowEntryByteDataReader_GetPositiveInteger3_Statics
	{
		struct LowEntryByteDataReader_eventGetPositiveInteger3_Parms
		{
			int32 ReturnValue;
		};
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ULowEntryByteDataReader_GetPositiveInteger3_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Int, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(LowEntryByteDataReader_eventGetPositiveInteger3_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULowEntryByteDataReader_GetPositiveInteger3_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryByteDataReader_GetPositiveInteger3_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryByteDataReader_GetPositiveInteger3_Statics::Function_MetaDataParams[] = {
		{ "Category", "Low Entry|Extended Standard Library|Byte Data|Reader" },
		{ "DisplayName", "Get Positive Integer 3" },
		{ "ModuleRelativePath", "Public/Classes/LowEntryByteDataReader.h" },
		{ "ToolTip", "Gets a positive integer." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULowEntryByteDataReader_GetPositiveInteger3_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULowEntryByteDataReader, "GetPositiveInteger3", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(LowEntryByteDataReader_eventGetPositiveInteger3_Parms), Z_Construct_UFunction_ULowEntryByteDataReader_GetPositiveInteger3_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataReader_GetPositiveInteger3_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULowEntryByteDataReader_GetPositiveInteger3_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataReader_GetPositiveInteger3_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULowEntryByteDataReader_GetPositiveInteger3()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULowEntryByteDataReader_GetPositiveInteger3_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULowEntryByteDataReader_GetPositiveInteger3Array_Statics
	{
		struct LowEntryByteDataReader_eventGetPositiveInteger3Array_Parms
		{
			TArray<int32> ReturnValue;
		};
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_ReturnValue_Inner;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_ULowEntryByteDataReader_GetPositiveInteger3Array_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Array, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(LowEntryByteDataReader_eventGetPositiveInteger3Array_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ULowEntryByteDataReader_GetPositiveInteger3Array_Statics::NewProp_ReturnValue_Inner = { UE4CodeGen_Private::EPropertyClass::Int, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULowEntryByteDataReader_GetPositiveInteger3Array_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryByteDataReader_GetPositiveInteger3Array_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryByteDataReader_GetPositiveInteger3Array_Statics::NewProp_ReturnValue_Inner,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryByteDataReader_GetPositiveInteger3Array_Statics::Function_MetaDataParams[] = {
		{ "Category", "Low Entry|Extended Standard Library|Byte Data|Reader" },
		{ "DisplayName", "Get Positive Integer 3 Array" },
		{ "ModuleRelativePath", "Public/Classes/LowEntryByteDataReader.h" },
		{ "ToolTip", "Gets a positive integer array." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULowEntryByteDataReader_GetPositiveInteger3Array_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULowEntryByteDataReader, "GetPositiveInteger3Array", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(LowEntryByteDataReader_eventGetPositiveInteger3Array_Parms), Z_Construct_UFunction_ULowEntryByteDataReader_GetPositiveInteger3Array_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataReader_GetPositiveInteger3Array_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULowEntryByteDataReader_GetPositiveInteger3Array_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataReader_GetPositiveInteger3Array_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULowEntryByteDataReader_GetPositiveInteger3Array()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULowEntryByteDataReader_GetPositiveInteger3Array_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULowEntryByteDataReader_GetStringUtf8_Statics
	{
		struct LowEntryByteDataReader_eventGetStringUtf8_Parms
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
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ULowEntryByteDataReader_GetStringUtf8_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Str, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(LowEntryByteDataReader_eventGetStringUtf8_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULowEntryByteDataReader_GetStringUtf8_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryByteDataReader_GetStringUtf8_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryByteDataReader_GetStringUtf8_Statics::Function_MetaDataParams[] = {
		{ "Category", "Low Entry|Extended Standard Library|Byte Data|Reader" },
		{ "DisplayName", "Get String (Utf 8)" },
		{ "ModuleRelativePath", "Public/Classes/LowEntryByteDataReader.h" },
		{ "ToolTip", "Gets a String (UTF-8)." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULowEntryByteDataReader_GetStringUtf8_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULowEntryByteDataReader, "GetStringUtf8", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(LowEntryByteDataReader_eventGetStringUtf8_Parms), Z_Construct_UFunction_ULowEntryByteDataReader_GetStringUtf8_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataReader_GetStringUtf8_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULowEntryByteDataReader_GetStringUtf8_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataReader_GetStringUtf8_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULowEntryByteDataReader_GetStringUtf8()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULowEntryByteDataReader_GetStringUtf8_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULowEntryByteDataReader_GetStringUtf8Array_Statics
	{
		struct LowEntryByteDataReader_eventGetStringUtf8Array_Parms
		{
			TArray<FString> ReturnValue;
		};
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_ReturnValue_Inner;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_ULowEntryByteDataReader_GetStringUtf8Array_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Array, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(LowEntryByteDataReader_eventGetStringUtf8Array_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ULowEntryByteDataReader_GetStringUtf8Array_Statics::NewProp_ReturnValue_Inner = { UE4CodeGen_Private::EPropertyClass::Str, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULowEntryByteDataReader_GetStringUtf8Array_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryByteDataReader_GetStringUtf8Array_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryByteDataReader_GetStringUtf8Array_Statics::NewProp_ReturnValue_Inner,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryByteDataReader_GetStringUtf8Array_Statics::Function_MetaDataParams[] = {
		{ "Category", "Low Entry|Extended Standard Library|Byte Data|Reader" },
		{ "DisplayName", "Get String (Utf 8) Array" },
		{ "ModuleRelativePath", "Public/Classes/LowEntryByteDataReader.h" },
		{ "ToolTip", "Gets a String (UTF-8) array." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULowEntryByteDataReader_GetStringUtf8Array_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULowEntryByteDataReader, "GetStringUtf8Array", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(LowEntryByteDataReader_eventGetStringUtf8Array_Parms), Z_Construct_UFunction_ULowEntryByteDataReader_GetStringUtf8Array_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataReader_GetStringUtf8Array_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULowEntryByteDataReader_GetStringUtf8Array_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataReader_GetStringUtf8Array_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULowEntryByteDataReader_GetStringUtf8Array()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULowEntryByteDataReader_GetStringUtf8Array_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULowEntryByteDataReader_Remaining_Statics
	{
		struct LowEntryByteDataReader_eventRemaining_Parms
		{
			int32 ReturnValue;
		};
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ULowEntryByteDataReader_Remaining_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Int, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(LowEntryByteDataReader_eventRemaining_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULowEntryByteDataReader_Remaining_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryByteDataReader_Remaining_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryByteDataReader_Remaining_Statics::Function_MetaDataParams[] = {
		{ "Category", "Low Entry|Extended Standard Library|Byte Data|Reader (Meta)" },
		{ "DisplayName", "Get Remaining" },
		{ "ModuleRelativePath", "Public/Classes/LowEntryByteDataReader.h" },
		{ "ToolTip", "Returns the amount of bytes left." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULowEntryByteDataReader_Remaining_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULowEntryByteDataReader, "Remaining", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14020401, sizeof(LowEntryByteDataReader_eventRemaining_Parms), Z_Construct_UFunction_ULowEntryByteDataReader_Remaining_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataReader_Remaining_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULowEntryByteDataReader_Remaining_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataReader_Remaining_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULowEntryByteDataReader_Remaining()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULowEntryByteDataReader_Remaining_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULowEntryByteDataReader_Reset_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryByteDataReader_Reset_Statics::Function_MetaDataParams[] = {
		{ "Category", "Low Entry|Extended Standard Library|Byte Data|Reader (Meta)" },
		{ "DisplayName", "Reset" },
		{ "ModuleRelativePath", "Public/Classes/LowEntryByteDataReader.h" },
		{ "ToolTip", "Sets the current position to 0." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULowEntryByteDataReader_Reset_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULowEntryByteDataReader, "Reset", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULowEntryByteDataReader_Reset_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataReader_Reset_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULowEntryByteDataReader_Reset()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULowEntryByteDataReader_Reset_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULowEntryByteDataReader_SetPosition_Statics
	{
		struct LowEntryByteDataReader_eventSetPosition_Parms
		{
			int32 Position_;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Position__MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_Position_;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryByteDataReader_SetPosition_Statics::NewProp_Position__MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ULowEntryByteDataReader_SetPosition_Statics::NewProp_Position_ = { UE4CodeGen_Private::EPropertyClass::Int, "Position_", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000082, 1, nullptr, STRUCT_OFFSET(LowEntryByteDataReader_eventSetPosition_Parms, Position_), METADATA_PARAMS(Z_Construct_UFunction_ULowEntryByteDataReader_SetPosition_Statics::NewProp_Position__MetaData, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataReader_SetPosition_Statics::NewProp_Position__MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULowEntryByteDataReader_SetPosition_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryByteDataReader_SetPosition_Statics::NewProp_Position_,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryByteDataReader_SetPosition_Statics::Function_MetaDataParams[] = {
		{ "Category", "Low Entry|Extended Standard Library|Byte Data|Reader (Meta)" },
		{ "DisplayName", "Set Position" },
		{ "ModuleRelativePath", "Public/Classes/LowEntryByteDataReader.h" },
		{ "ToolTip", "Sets the current position." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULowEntryByteDataReader_SetPosition_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULowEntryByteDataReader, "SetPosition", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(LowEntryByteDataReader_eventSetPosition_Parms), Z_Construct_UFunction_ULowEntryByteDataReader_SetPosition_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataReader_SetPosition_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULowEntryByteDataReader_SetPosition_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataReader_SetPosition_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULowEntryByteDataReader_SetPosition()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULowEntryByteDataReader_SetPosition_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ULowEntryByteDataReader_NoRegister()
	{
		return ULowEntryByteDataReader::StaticClass();
	}
	struct Z_Construct_UClass_ULowEntryByteDataReader_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Position_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_Position;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Bytes_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Bytes;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_Bytes_Inner;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ULowEntryByteDataReader_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_LowEntryExtendedStandardLibrary,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ULowEntryByteDataReader_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ULowEntryByteDataReader_Empty, "Empty" }, // 3231467295
		{ &Z_Construct_UFunction_ULowEntryByteDataReader_GetBoolean, "GetBoolean" }, // 2756186319
		{ &Z_Construct_UFunction_ULowEntryByteDataReader_GetBooleanArray, "GetBooleanArray" }, // 962125178
		{ &Z_Construct_UFunction_ULowEntryByteDataReader_GetByte, "GetByte" }, // 1770325756
		{ &Z_Construct_UFunction_ULowEntryByteDataReader_GetByteArray, "GetByteArray" }, // 2520308237
		{ &Z_Construct_UFunction_ULowEntryByteDataReader_GetClone, "GetClone" }, // 332163865
		{ &Z_Construct_UFunction_ULowEntryByteDataReader_GetDoubleBytes, "GetDoubleBytes" }, // 1269188136
		{ &Z_Construct_UFunction_ULowEntryByteDataReader_GetDoubleBytesArray, "GetDoubleBytesArray" }, // 2404228641
		{ &Z_Construct_UFunction_ULowEntryByteDataReader_GetFloat, "GetFloat" }, // 3923637678
		{ &Z_Construct_UFunction_ULowEntryByteDataReader_GetFloatArray, "GetFloatArray" }, // 2596429125
		{ &Z_Construct_UFunction_ULowEntryByteDataReader_GetInteger, "GetInteger" }, // 2567257362
		{ &Z_Construct_UFunction_ULowEntryByteDataReader_GetIntegerArray, "GetIntegerArray" }, // 2568239788
		{ &Z_Construct_UFunction_ULowEntryByteDataReader_GetLongBytes, "GetLongBytes" }, // 1946853787
		{ &Z_Construct_UFunction_ULowEntryByteDataReader_GetLongBytesArray, "GetLongBytesArray" }, // 3158383124
		{ &Z_Construct_UFunction_ULowEntryByteDataReader_GetPosition, "GetPosition" }, // 2338590270
		{ &Z_Construct_UFunction_ULowEntryByteDataReader_GetPositiveInteger1, "GetPositiveInteger1" }, // 3761751276
		{ &Z_Construct_UFunction_ULowEntryByteDataReader_GetPositiveInteger1Array, "GetPositiveInteger1Array" }, // 4020273661
		{ &Z_Construct_UFunction_ULowEntryByteDataReader_GetPositiveInteger2, "GetPositiveInteger2" }, // 33157483
		{ &Z_Construct_UFunction_ULowEntryByteDataReader_GetPositiveInteger2Array, "GetPositiveInteger2Array" }, // 3478793700
		{ &Z_Construct_UFunction_ULowEntryByteDataReader_GetPositiveInteger3, "GetPositiveInteger3" }, // 2734483835
		{ &Z_Construct_UFunction_ULowEntryByteDataReader_GetPositiveInteger3Array, "GetPositiveInteger3Array" }, // 3505632787
		{ &Z_Construct_UFunction_ULowEntryByteDataReader_GetStringUtf8, "GetStringUtf8" }, // 2489017464
		{ &Z_Construct_UFunction_ULowEntryByteDataReader_GetStringUtf8Array, "GetStringUtf8Array" }, // 962410490
		{ &Z_Construct_UFunction_ULowEntryByteDataReader_Remaining, "Remaining" }, // 2504120129
		{ &Z_Construct_UFunction_ULowEntryByteDataReader_Reset, "Reset" }, // 4157030984
		{ &Z_Construct_UFunction_ULowEntryByteDataReader_SetPosition, "SetPosition" }, // 696030770
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULowEntryByteDataReader_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "Classes/LowEntryByteDataReader.h" },
		{ "ModuleRelativePath", "Public/Classes/LowEntryByteDataReader.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULowEntryByteDataReader_Statics::NewProp_Position_MetaData[] = {
		{ "ModuleRelativePath", "Public/Classes/LowEntryByteDataReader.h" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_ULowEntryByteDataReader_Statics::NewProp_Position = { UE4CodeGen_Private::EPropertyClass::Int, "Position", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000000, 1, nullptr, STRUCT_OFFSET(ULowEntryByteDataReader, Position), METADATA_PARAMS(Z_Construct_UClass_ULowEntryByteDataReader_Statics::NewProp_Position_MetaData, ARRAY_COUNT(Z_Construct_UClass_ULowEntryByteDataReader_Statics::NewProp_Position_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULowEntryByteDataReader_Statics::NewProp_Bytes_MetaData[] = {
		{ "ModuleRelativePath", "Public/Classes/LowEntryByteDataReader.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ULowEntryByteDataReader_Statics::NewProp_Bytes = { UE4CodeGen_Private::EPropertyClass::Array, "Bytes", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000000, 1, nullptr, STRUCT_OFFSET(ULowEntryByteDataReader, Bytes), METADATA_PARAMS(Z_Construct_UClass_ULowEntryByteDataReader_Statics::NewProp_Bytes_MetaData, ARRAY_COUNT(Z_Construct_UClass_ULowEntryByteDataReader_Statics::NewProp_Bytes_MetaData)) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UClass_ULowEntryByteDataReader_Statics::NewProp_Bytes_Inner = { UE4CodeGen_Private::EPropertyClass::Byte, "Bytes", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ULowEntryByteDataReader_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULowEntryByteDataReader_Statics::NewProp_Position,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULowEntryByteDataReader_Statics::NewProp_Bytes,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULowEntryByteDataReader_Statics::NewProp_Bytes_Inner,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ULowEntryByteDataReader_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ULowEntryByteDataReader>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ULowEntryByteDataReader_Statics::ClassParams = {
		&ULowEntryByteDataReader::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x001000A0u,
		FuncInfo, ARRAY_COUNT(FuncInfo),
		Z_Construct_UClass_ULowEntryByteDataReader_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_ULowEntryByteDataReader_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_ULowEntryByteDataReader_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_ULowEntryByteDataReader_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ULowEntryByteDataReader()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ULowEntryByteDataReader_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ULowEntryByteDataReader, 2366007587);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ULowEntryByteDataReader(Z_Construct_UClass_ULowEntryByteDataReader, &ULowEntryByteDataReader::StaticClass, TEXT("/Script/LowEntryExtendedStandardLibrary"), TEXT("ULowEntryByteDataReader"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ULowEntryByteDataReader);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
