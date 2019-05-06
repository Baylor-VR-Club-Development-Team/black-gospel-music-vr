// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LowEntryExtendedStandardLibrary/Public/Classes/LowEntryByteDataWriter.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeLowEntryByteDataWriter() {}
// Cross Module References
	LOWENTRYEXTENDEDSTANDARDLIBRARY_API UClass* Z_Construct_UClass_ULowEntryByteDataWriter_NoRegister();
	LOWENTRYEXTENDEDSTANDARDLIBRARY_API UClass* Z_Construct_UClass_ULowEntryByteDataWriter();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_LowEntryExtendedStandardLibrary();
	LOWENTRYEXTENDEDSTANDARDLIBRARY_API UFunction* Z_Construct_UFunction_ULowEntryByteDataWriter_AddBoolean();
	LOWENTRYEXTENDEDSTANDARDLIBRARY_API UFunction* Z_Construct_UFunction_ULowEntryByteDataWriter_AddBooleanArray();
	LOWENTRYEXTENDEDSTANDARDLIBRARY_API UFunction* Z_Construct_UFunction_ULowEntryByteDataWriter_AddByte();
	LOWENTRYEXTENDEDSTANDARDLIBRARY_API UFunction* Z_Construct_UFunction_ULowEntryByteDataWriter_AddByteArray();
	LOWENTRYEXTENDEDSTANDARDLIBRARY_API UFunction* Z_Construct_UFunction_ULowEntryByteDataWriter_AddDoubleBytes();
	LOWENTRYEXTENDEDSTANDARDLIBRARY_API UClass* Z_Construct_UClass_ULowEntryDouble_NoRegister();
	LOWENTRYEXTENDEDSTANDARDLIBRARY_API UFunction* Z_Construct_UFunction_ULowEntryByteDataWriter_AddDoubleBytesArray();
	LOWENTRYEXTENDEDSTANDARDLIBRARY_API UFunction* Z_Construct_UFunction_ULowEntryByteDataWriter_AddFloat();
	LOWENTRYEXTENDEDSTANDARDLIBRARY_API UFunction* Z_Construct_UFunction_ULowEntryByteDataWriter_AddFloatArray();
	LOWENTRYEXTENDEDSTANDARDLIBRARY_API UFunction* Z_Construct_UFunction_ULowEntryByteDataWriter_AddInteger();
	LOWENTRYEXTENDEDSTANDARDLIBRARY_API UFunction* Z_Construct_UFunction_ULowEntryByteDataWriter_AddIntegerArray();
	LOWENTRYEXTENDEDSTANDARDLIBRARY_API UFunction* Z_Construct_UFunction_ULowEntryByteDataWriter_AddLongBytes();
	LOWENTRYEXTENDEDSTANDARDLIBRARY_API UClass* Z_Construct_UClass_ULowEntryLong_NoRegister();
	LOWENTRYEXTENDEDSTANDARDLIBRARY_API UFunction* Z_Construct_UFunction_ULowEntryByteDataWriter_AddLongBytesArray();
	LOWENTRYEXTENDEDSTANDARDLIBRARY_API UFunction* Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger1();
	LOWENTRYEXTENDEDSTANDARDLIBRARY_API UFunction* Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger1Array();
	LOWENTRYEXTENDEDSTANDARDLIBRARY_API UFunction* Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger2();
	LOWENTRYEXTENDEDSTANDARDLIBRARY_API UFunction* Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger2Array();
	LOWENTRYEXTENDEDSTANDARDLIBRARY_API UFunction* Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger3();
	LOWENTRYEXTENDEDSTANDARDLIBRARY_API UFunction* Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger3Array();
	LOWENTRYEXTENDEDSTANDARDLIBRARY_API UFunction* Z_Construct_UFunction_ULowEntryByteDataWriter_AddStringUtf8();
	LOWENTRYEXTENDEDSTANDARDLIBRARY_API UFunction* Z_Construct_UFunction_ULowEntryByteDataWriter_AddStringUtf8Array();
// End Cross Module References
	void ULowEntryByteDataWriter::StaticRegisterNativesULowEntryByteDataWriter()
	{
		UClass* Class = ULowEntryByteDataWriter::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "AddBoolean", &ULowEntryByteDataWriter::execAddBoolean },
			{ "AddBooleanArray", &ULowEntryByteDataWriter::execAddBooleanArray },
			{ "AddByte", &ULowEntryByteDataWriter::execAddByte },
			{ "AddByteArray", &ULowEntryByteDataWriter::execAddByteArray },
			{ "AddDoubleBytes", &ULowEntryByteDataWriter::execAddDoubleBytes },
			{ "AddDoubleBytesArray", &ULowEntryByteDataWriter::execAddDoubleBytesArray },
			{ "AddFloat", &ULowEntryByteDataWriter::execAddFloat },
			{ "AddFloatArray", &ULowEntryByteDataWriter::execAddFloatArray },
			{ "AddInteger", &ULowEntryByteDataWriter::execAddInteger },
			{ "AddIntegerArray", &ULowEntryByteDataWriter::execAddIntegerArray },
			{ "AddLongBytes", &ULowEntryByteDataWriter::execAddLongBytes },
			{ "AddLongBytesArray", &ULowEntryByteDataWriter::execAddLongBytesArray },
			{ "AddPositiveInteger1", &ULowEntryByteDataWriter::execAddPositiveInteger1 },
			{ "AddPositiveInteger1Array", &ULowEntryByteDataWriter::execAddPositiveInteger1Array },
			{ "AddPositiveInteger2", &ULowEntryByteDataWriter::execAddPositiveInteger2 },
			{ "AddPositiveInteger2Array", &ULowEntryByteDataWriter::execAddPositiveInteger2Array },
			{ "AddPositiveInteger3", &ULowEntryByteDataWriter::execAddPositiveInteger3 },
			{ "AddPositiveInteger3Array", &ULowEntryByteDataWriter::execAddPositiveInteger3Array },
			{ "AddStringUtf8", &ULowEntryByteDataWriter::execAddStringUtf8 },
			{ "AddStringUtf8Array", &ULowEntryByteDataWriter::execAddStringUtf8Array },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ULowEntryByteDataWriter_AddBoolean_Statics
	{
		struct LowEntryByteDataWriter_eventAddBoolean_Parms
		{
			bool Value;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Value_MetaData[];
#endif
		static void NewProp_Value_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_Value;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryByteDataWriter_AddBoolean_Statics::NewProp_Value_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	void Z_Construct_UFunction_ULowEntryByteDataWriter_AddBoolean_Statics::NewProp_Value_SetBit(void* Obj)
	{
		((LowEntryByteDataWriter_eventAddBoolean_Parms*)Obj)->Value = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ULowEntryByteDataWriter_AddBoolean_Statics::NewProp_Value = { UE4CodeGen_Private::EPropertyClass::Bool, "Value", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000082, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(LowEntryByteDataWriter_eventAddBoolean_Parms), &Z_Construct_UFunction_ULowEntryByteDataWriter_AddBoolean_Statics::NewProp_Value_SetBit, METADATA_PARAMS(Z_Construct_UFunction_ULowEntryByteDataWriter_AddBoolean_Statics::NewProp_Value_MetaData, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataWriter_AddBoolean_Statics::NewProp_Value_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULowEntryByteDataWriter_AddBoolean_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryByteDataWriter_AddBoolean_Statics::NewProp_Value,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryByteDataWriter_AddBoolean_Statics::Function_MetaDataParams[] = {
		{ "Category", "Low Entry|Extended Standard Library|Byte Data|Writer" },
		{ "DisplayName", "Add Boolean" },
		{ "ModuleRelativePath", "Public/Classes/LowEntryByteDataWriter.h" },
		{ "ToolTip", "Adds a boolean." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULowEntryByteDataWriter_AddBoolean_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULowEntryByteDataWriter, "AddBoolean", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(LowEntryByteDataWriter_eventAddBoolean_Parms), Z_Construct_UFunction_ULowEntryByteDataWriter_AddBoolean_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataWriter_AddBoolean_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULowEntryByteDataWriter_AddBoolean_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataWriter_AddBoolean_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULowEntryByteDataWriter_AddBoolean()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULowEntryByteDataWriter_AddBoolean_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULowEntryByteDataWriter_AddBooleanArray_Statics
	{
		struct LowEntryByteDataWriter_eventAddBooleanArray_Parms
		{
			TArray<bool> Value;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Value_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Value;
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_Value_Inner;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryByteDataWriter_AddBooleanArray_Statics::NewProp_Value_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_ULowEntryByteDataWriter_AddBooleanArray_Statics::NewProp_Value = { UE4CodeGen_Private::EPropertyClass::Array, "Value", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000008000182, 1, nullptr, STRUCT_OFFSET(LowEntryByteDataWriter_eventAddBooleanArray_Parms, Value), METADATA_PARAMS(Z_Construct_UFunction_ULowEntryByteDataWriter_AddBooleanArray_Statics::NewProp_Value_MetaData, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataWriter_AddBooleanArray_Statics::NewProp_Value_MetaData)) };
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ULowEntryByteDataWriter_AddBooleanArray_Statics::NewProp_Value_Inner = { UE4CodeGen_Private::EPropertyClass::Bool, "Value", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULowEntryByteDataWriter_AddBooleanArray_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryByteDataWriter_AddBooleanArray_Statics::NewProp_Value,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryByteDataWriter_AddBooleanArray_Statics::NewProp_Value_Inner,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryByteDataWriter_AddBooleanArray_Statics::Function_MetaDataParams[] = {
		{ "Category", "Low Entry|Extended Standard Library|Byte Data|Writer" },
		{ "DisplayName", "Add Boolean Array" },
		{ "ModuleRelativePath", "Public/Classes/LowEntryByteDataWriter.h" },
		{ "ToolTip", "Adds a boolean array." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULowEntryByteDataWriter_AddBooleanArray_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULowEntryByteDataWriter, "AddBooleanArray", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04420401, sizeof(LowEntryByteDataWriter_eventAddBooleanArray_Parms), Z_Construct_UFunction_ULowEntryByteDataWriter_AddBooleanArray_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataWriter_AddBooleanArray_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULowEntryByteDataWriter_AddBooleanArray_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataWriter_AddBooleanArray_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULowEntryByteDataWriter_AddBooleanArray()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULowEntryByteDataWriter_AddBooleanArray_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULowEntryByteDataWriter_AddByte_Statics
	{
		struct LowEntryByteDataWriter_eventAddByte_Parms
		{
			uint8 Value;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Value_MetaData[];
#endif
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_Value;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryByteDataWriter_AddByte_Statics::NewProp_Value_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_ULowEntryByteDataWriter_AddByte_Statics::NewProp_Value = { UE4CodeGen_Private::EPropertyClass::Byte, "Value", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000082, 1, nullptr, STRUCT_OFFSET(LowEntryByteDataWriter_eventAddByte_Parms, Value), nullptr, METADATA_PARAMS(Z_Construct_UFunction_ULowEntryByteDataWriter_AddByte_Statics::NewProp_Value_MetaData, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataWriter_AddByte_Statics::NewProp_Value_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULowEntryByteDataWriter_AddByte_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryByteDataWriter_AddByte_Statics::NewProp_Value,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryByteDataWriter_AddByte_Statics::Function_MetaDataParams[] = {
		{ "Category", "Low Entry|Extended Standard Library|Byte Data|Writer" },
		{ "DisplayName", "Add Byte" },
		{ "ModuleRelativePath", "Public/Classes/LowEntryByteDataWriter.h" },
		{ "ToolTip", "Adds a byte." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULowEntryByteDataWriter_AddByte_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULowEntryByteDataWriter, "AddByte", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(LowEntryByteDataWriter_eventAddByte_Parms), Z_Construct_UFunction_ULowEntryByteDataWriter_AddByte_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataWriter_AddByte_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULowEntryByteDataWriter_AddByte_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataWriter_AddByte_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULowEntryByteDataWriter_AddByte()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULowEntryByteDataWriter_AddByte_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULowEntryByteDataWriter_AddByteArray_Statics
	{
		struct LowEntryByteDataWriter_eventAddByteArray_Parms
		{
			TArray<uint8> Value;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Value_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Value;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_Value_Inner;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryByteDataWriter_AddByteArray_Statics::NewProp_Value_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_ULowEntryByteDataWriter_AddByteArray_Statics::NewProp_Value = { UE4CodeGen_Private::EPropertyClass::Array, "Value", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000008000182, 1, nullptr, STRUCT_OFFSET(LowEntryByteDataWriter_eventAddByteArray_Parms, Value), METADATA_PARAMS(Z_Construct_UFunction_ULowEntryByteDataWriter_AddByteArray_Statics::NewProp_Value_MetaData, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataWriter_AddByteArray_Statics::NewProp_Value_MetaData)) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_ULowEntryByteDataWriter_AddByteArray_Statics::NewProp_Value_Inner = { UE4CodeGen_Private::EPropertyClass::Byte, "Value", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULowEntryByteDataWriter_AddByteArray_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryByteDataWriter_AddByteArray_Statics::NewProp_Value,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryByteDataWriter_AddByteArray_Statics::NewProp_Value_Inner,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryByteDataWriter_AddByteArray_Statics::Function_MetaDataParams[] = {
		{ "Category", "Low Entry|Extended Standard Library|Byte Data|Writer" },
		{ "DisplayName", "Add Byte Array" },
		{ "ModuleRelativePath", "Public/Classes/LowEntryByteDataWriter.h" },
		{ "ToolTip", "Adds a byte array." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULowEntryByteDataWriter_AddByteArray_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULowEntryByteDataWriter, "AddByteArray", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04420401, sizeof(LowEntryByteDataWriter_eventAddByteArray_Parms), Z_Construct_UFunction_ULowEntryByteDataWriter_AddByteArray_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataWriter_AddByteArray_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULowEntryByteDataWriter_AddByteArray_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataWriter_AddByteArray_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULowEntryByteDataWriter_AddByteArray()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULowEntryByteDataWriter_AddByteArray_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULowEntryByteDataWriter_AddDoubleBytes_Statics
	{
		struct LowEntryByteDataWriter_eventAddDoubleBytes_Parms
		{
			ULowEntryDouble* Value;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Value;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ULowEntryByteDataWriter_AddDoubleBytes_Statics::NewProp_Value = { UE4CodeGen_Private::EPropertyClass::Object, "Value", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(LowEntryByteDataWriter_eventAddDoubleBytes_Parms, Value), Z_Construct_UClass_ULowEntryDouble_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULowEntryByteDataWriter_AddDoubleBytes_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryByteDataWriter_AddDoubleBytes_Statics::NewProp_Value,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryByteDataWriter_AddDoubleBytes_Statics::Function_MetaDataParams[] = {
		{ "Category", "Low Entry|Extended Standard Library|Byte Data|Writer" },
		{ "DisplayName", "Add Double (Bytes)" },
		{ "ModuleRelativePath", "Public/Classes/LowEntryByteDataWriter.h" },
		{ "ToolTip", "Adds a double (bytes)." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULowEntryByteDataWriter_AddDoubleBytes_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULowEntryByteDataWriter, "AddDoubleBytes", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(LowEntryByteDataWriter_eventAddDoubleBytes_Parms), Z_Construct_UFunction_ULowEntryByteDataWriter_AddDoubleBytes_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataWriter_AddDoubleBytes_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULowEntryByteDataWriter_AddDoubleBytes_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataWriter_AddDoubleBytes_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULowEntryByteDataWriter_AddDoubleBytes()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULowEntryByteDataWriter_AddDoubleBytes_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULowEntryByteDataWriter_AddDoubleBytesArray_Statics
	{
		struct LowEntryByteDataWriter_eventAddDoubleBytesArray_Parms
		{
			TArray<ULowEntryDouble*> Value;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Value_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Value;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Value_Inner;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryByteDataWriter_AddDoubleBytesArray_Statics::NewProp_Value_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_ULowEntryByteDataWriter_AddDoubleBytesArray_Statics::NewProp_Value = { UE4CodeGen_Private::EPropertyClass::Array, "Value", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000008000182, 1, nullptr, STRUCT_OFFSET(LowEntryByteDataWriter_eventAddDoubleBytesArray_Parms, Value), METADATA_PARAMS(Z_Construct_UFunction_ULowEntryByteDataWriter_AddDoubleBytesArray_Statics::NewProp_Value_MetaData, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataWriter_AddDoubleBytesArray_Statics::NewProp_Value_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ULowEntryByteDataWriter_AddDoubleBytesArray_Statics::NewProp_Value_Inner = { UE4CodeGen_Private::EPropertyClass::Object, "Value", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, Z_Construct_UClass_ULowEntryDouble_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULowEntryByteDataWriter_AddDoubleBytesArray_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryByteDataWriter_AddDoubleBytesArray_Statics::NewProp_Value,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryByteDataWriter_AddDoubleBytesArray_Statics::NewProp_Value_Inner,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryByteDataWriter_AddDoubleBytesArray_Statics::Function_MetaDataParams[] = {
		{ "Category", "Low Entry|Extended Standard Library|Byte Data|Writer" },
		{ "DisplayName", "Add Double (bytes) Array" },
		{ "ModuleRelativePath", "Public/Classes/LowEntryByteDataWriter.h" },
		{ "ToolTip", "Adds a double (bytes) array." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULowEntryByteDataWriter_AddDoubleBytesArray_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULowEntryByteDataWriter, "AddDoubleBytesArray", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04420401, sizeof(LowEntryByteDataWriter_eventAddDoubleBytesArray_Parms), Z_Construct_UFunction_ULowEntryByteDataWriter_AddDoubleBytesArray_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataWriter_AddDoubleBytesArray_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULowEntryByteDataWriter_AddDoubleBytesArray_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataWriter_AddDoubleBytesArray_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULowEntryByteDataWriter_AddDoubleBytesArray()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULowEntryByteDataWriter_AddDoubleBytesArray_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULowEntryByteDataWriter_AddFloat_Statics
	{
		struct LowEntryByteDataWriter_eventAddFloat_Parms
		{
			float Value;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Value_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Value;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryByteDataWriter_AddFloat_Statics::NewProp_Value_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ULowEntryByteDataWriter_AddFloat_Statics::NewProp_Value = { UE4CodeGen_Private::EPropertyClass::Float, "Value", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000082, 1, nullptr, STRUCT_OFFSET(LowEntryByteDataWriter_eventAddFloat_Parms, Value), METADATA_PARAMS(Z_Construct_UFunction_ULowEntryByteDataWriter_AddFloat_Statics::NewProp_Value_MetaData, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataWriter_AddFloat_Statics::NewProp_Value_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULowEntryByteDataWriter_AddFloat_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryByteDataWriter_AddFloat_Statics::NewProp_Value,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryByteDataWriter_AddFloat_Statics::Function_MetaDataParams[] = {
		{ "Category", "Low Entry|Extended Standard Library|Byte Data|Writer" },
		{ "DisplayName", "Add Float" },
		{ "ModuleRelativePath", "Public/Classes/LowEntryByteDataWriter.h" },
		{ "ToolTip", "Adds a float." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULowEntryByteDataWriter_AddFloat_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULowEntryByteDataWriter, "AddFloat", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(LowEntryByteDataWriter_eventAddFloat_Parms), Z_Construct_UFunction_ULowEntryByteDataWriter_AddFloat_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataWriter_AddFloat_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULowEntryByteDataWriter_AddFloat_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataWriter_AddFloat_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULowEntryByteDataWriter_AddFloat()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULowEntryByteDataWriter_AddFloat_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULowEntryByteDataWriter_AddFloatArray_Statics
	{
		struct LowEntryByteDataWriter_eventAddFloatArray_Parms
		{
			TArray<float> Value;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Value_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Value;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Value_Inner;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryByteDataWriter_AddFloatArray_Statics::NewProp_Value_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_ULowEntryByteDataWriter_AddFloatArray_Statics::NewProp_Value = { UE4CodeGen_Private::EPropertyClass::Array, "Value", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000008000182, 1, nullptr, STRUCT_OFFSET(LowEntryByteDataWriter_eventAddFloatArray_Parms, Value), METADATA_PARAMS(Z_Construct_UFunction_ULowEntryByteDataWriter_AddFloatArray_Statics::NewProp_Value_MetaData, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataWriter_AddFloatArray_Statics::NewProp_Value_MetaData)) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ULowEntryByteDataWriter_AddFloatArray_Statics::NewProp_Value_Inner = { UE4CodeGen_Private::EPropertyClass::Float, "Value", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULowEntryByteDataWriter_AddFloatArray_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryByteDataWriter_AddFloatArray_Statics::NewProp_Value,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryByteDataWriter_AddFloatArray_Statics::NewProp_Value_Inner,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryByteDataWriter_AddFloatArray_Statics::Function_MetaDataParams[] = {
		{ "Category", "Low Entry|Extended Standard Library|Byte Data|Writer" },
		{ "DisplayName", "Add Float Array" },
		{ "ModuleRelativePath", "Public/Classes/LowEntryByteDataWriter.h" },
		{ "ToolTip", "Adds a float array." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULowEntryByteDataWriter_AddFloatArray_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULowEntryByteDataWriter, "AddFloatArray", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04420401, sizeof(LowEntryByteDataWriter_eventAddFloatArray_Parms), Z_Construct_UFunction_ULowEntryByteDataWriter_AddFloatArray_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataWriter_AddFloatArray_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULowEntryByteDataWriter_AddFloatArray_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataWriter_AddFloatArray_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULowEntryByteDataWriter_AddFloatArray()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULowEntryByteDataWriter_AddFloatArray_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULowEntryByteDataWriter_AddInteger_Statics
	{
		struct LowEntryByteDataWriter_eventAddInteger_Parms
		{
			int32 Value;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Value_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_Value;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryByteDataWriter_AddInteger_Statics::NewProp_Value_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ULowEntryByteDataWriter_AddInteger_Statics::NewProp_Value = { UE4CodeGen_Private::EPropertyClass::Int, "Value", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000082, 1, nullptr, STRUCT_OFFSET(LowEntryByteDataWriter_eventAddInteger_Parms, Value), METADATA_PARAMS(Z_Construct_UFunction_ULowEntryByteDataWriter_AddInteger_Statics::NewProp_Value_MetaData, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataWriter_AddInteger_Statics::NewProp_Value_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULowEntryByteDataWriter_AddInteger_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryByteDataWriter_AddInteger_Statics::NewProp_Value,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryByteDataWriter_AddInteger_Statics::Function_MetaDataParams[] = {
		{ "Category", "Low Entry|Extended Standard Library|Byte Data|Writer" },
		{ "DisplayName", "Add Integer" },
		{ "ModuleRelativePath", "Public/Classes/LowEntryByteDataWriter.h" },
		{ "ToolTip", "Adds an integer." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULowEntryByteDataWriter_AddInteger_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULowEntryByteDataWriter, "AddInteger", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(LowEntryByteDataWriter_eventAddInteger_Parms), Z_Construct_UFunction_ULowEntryByteDataWriter_AddInteger_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataWriter_AddInteger_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULowEntryByteDataWriter_AddInteger_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataWriter_AddInteger_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULowEntryByteDataWriter_AddInteger()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULowEntryByteDataWriter_AddInteger_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULowEntryByteDataWriter_AddIntegerArray_Statics
	{
		struct LowEntryByteDataWriter_eventAddIntegerArray_Parms
		{
			TArray<int32> Value;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Value_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Value;
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_Value_Inner;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryByteDataWriter_AddIntegerArray_Statics::NewProp_Value_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_ULowEntryByteDataWriter_AddIntegerArray_Statics::NewProp_Value = { UE4CodeGen_Private::EPropertyClass::Array, "Value", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000008000182, 1, nullptr, STRUCT_OFFSET(LowEntryByteDataWriter_eventAddIntegerArray_Parms, Value), METADATA_PARAMS(Z_Construct_UFunction_ULowEntryByteDataWriter_AddIntegerArray_Statics::NewProp_Value_MetaData, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataWriter_AddIntegerArray_Statics::NewProp_Value_MetaData)) };
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ULowEntryByteDataWriter_AddIntegerArray_Statics::NewProp_Value_Inner = { UE4CodeGen_Private::EPropertyClass::Int, "Value", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULowEntryByteDataWriter_AddIntegerArray_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryByteDataWriter_AddIntegerArray_Statics::NewProp_Value,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryByteDataWriter_AddIntegerArray_Statics::NewProp_Value_Inner,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryByteDataWriter_AddIntegerArray_Statics::Function_MetaDataParams[] = {
		{ "Category", "Low Entry|Extended Standard Library|Byte Data|Writer" },
		{ "DisplayName", "Add Integer Array" },
		{ "ModuleRelativePath", "Public/Classes/LowEntryByteDataWriter.h" },
		{ "ToolTip", "Adds an integer array." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULowEntryByteDataWriter_AddIntegerArray_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULowEntryByteDataWriter, "AddIntegerArray", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04420401, sizeof(LowEntryByteDataWriter_eventAddIntegerArray_Parms), Z_Construct_UFunction_ULowEntryByteDataWriter_AddIntegerArray_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataWriter_AddIntegerArray_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULowEntryByteDataWriter_AddIntegerArray_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataWriter_AddIntegerArray_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULowEntryByteDataWriter_AddIntegerArray()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULowEntryByteDataWriter_AddIntegerArray_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULowEntryByteDataWriter_AddLongBytes_Statics
	{
		struct LowEntryByteDataWriter_eventAddLongBytes_Parms
		{
			ULowEntryLong* Value;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Value;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ULowEntryByteDataWriter_AddLongBytes_Statics::NewProp_Value = { UE4CodeGen_Private::EPropertyClass::Object, "Value", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(LowEntryByteDataWriter_eventAddLongBytes_Parms, Value), Z_Construct_UClass_ULowEntryLong_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULowEntryByteDataWriter_AddLongBytes_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryByteDataWriter_AddLongBytes_Statics::NewProp_Value,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryByteDataWriter_AddLongBytes_Statics::Function_MetaDataParams[] = {
		{ "Category", "Low Entry|Extended Standard Library|Byte Data|Writer" },
		{ "DisplayName", "Add Long (Bytes)" },
		{ "ModuleRelativePath", "Public/Classes/LowEntryByteDataWriter.h" },
		{ "ToolTip", "Adds a long (bytes)." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULowEntryByteDataWriter_AddLongBytes_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULowEntryByteDataWriter, "AddLongBytes", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(LowEntryByteDataWriter_eventAddLongBytes_Parms), Z_Construct_UFunction_ULowEntryByteDataWriter_AddLongBytes_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataWriter_AddLongBytes_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULowEntryByteDataWriter_AddLongBytes_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataWriter_AddLongBytes_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULowEntryByteDataWriter_AddLongBytes()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULowEntryByteDataWriter_AddLongBytes_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULowEntryByteDataWriter_AddLongBytesArray_Statics
	{
		struct LowEntryByteDataWriter_eventAddLongBytesArray_Parms
		{
			TArray<ULowEntryLong*> Value;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Value_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Value;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Value_Inner;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryByteDataWriter_AddLongBytesArray_Statics::NewProp_Value_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_ULowEntryByteDataWriter_AddLongBytesArray_Statics::NewProp_Value = { UE4CodeGen_Private::EPropertyClass::Array, "Value", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000008000182, 1, nullptr, STRUCT_OFFSET(LowEntryByteDataWriter_eventAddLongBytesArray_Parms, Value), METADATA_PARAMS(Z_Construct_UFunction_ULowEntryByteDataWriter_AddLongBytesArray_Statics::NewProp_Value_MetaData, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataWriter_AddLongBytesArray_Statics::NewProp_Value_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ULowEntryByteDataWriter_AddLongBytesArray_Statics::NewProp_Value_Inner = { UE4CodeGen_Private::EPropertyClass::Object, "Value", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, Z_Construct_UClass_ULowEntryLong_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULowEntryByteDataWriter_AddLongBytesArray_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryByteDataWriter_AddLongBytesArray_Statics::NewProp_Value,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryByteDataWriter_AddLongBytesArray_Statics::NewProp_Value_Inner,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryByteDataWriter_AddLongBytesArray_Statics::Function_MetaDataParams[] = {
		{ "Category", "Low Entry|Extended Standard Library|Byte Data|Writer" },
		{ "DisplayName", "Add Long (bytes) Array" },
		{ "ModuleRelativePath", "Public/Classes/LowEntryByteDataWriter.h" },
		{ "ToolTip", "Adds a long (bytes) array." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULowEntryByteDataWriter_AddLongBytesArray_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULowEntryByteDataWriter, "AddLongBytesArray", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04420401, sizeof(LowEntryByteDataWriter_eventAddLongBytesArray_Parms), Z_Construct_UFunction_ULowEntryByteDataWriter_AddLongBytesArray_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataWriter_AddLongBytesArray_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULowEntryByteDataWriter_AddLongBytesArray_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataWriter_AddLongBytesArray_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULowEntryByteDataWriter_AddLongBytesArray()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULowEntryByteDataWriter_AddLongBytesArray_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger1_Statics
	{
		struct LowEntryByteDataWriter_eventAddPositiveInteger1_Parms
		{
			int32 Value;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Value_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_Value;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger1_Statics::NewProp_Value_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger1_Statics::NewProp_Value = { UE4CodeGen_Private::EPropertyClass::Int, "Value", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000082, 1, nullptr, STRUCT_OFFSET(LowEntryByteDataWriter_eventAddPositiveInteger1_Parms, Value), METADATA_PARAMS(Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger1_Statics::NewProp_Value_MetaData, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger1_Statics::NewProp_Value_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger1_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger1_Statics::NewProp_Value,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger1_Statics::Function_MetaDataParams[] = {
		{ "Category", "Low Entry|Extended Standard Library|Byte Data|Writer" },
		{ "DisplayName", "Add Positive Integer 1" },
		{ "ModuleRelativePath", "Public/Classes/LowEntryByteDataWriter.h" },
		{ "ToolTip", "Adds a positive integer.\n\nWill store values below 128 in 1 byte, higher values will be stored in 4 bytes.\n\nThe given integer has to be 0 or higher, values under 0 will be changed to 0." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger1_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULowEntryByteDataWriter, "AddPositiveInteger1", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(LowEntryByteDataWriter_eventAddPositiveInteger1_Parms), Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger1_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger1_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger1_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger1_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger1()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger1_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger1Array_Statics
	{
		struct LowEntryByteDataWriter_eventAddPositiveInteger1Array_Parms
		{
			TArray<int32> Value;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Value_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Value;
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_Value_Inner;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger1Array_Statics::NewProp_Value_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger1Array_Statics::NewProp_Value = { UE4CodeGen_Private::EPropertyClass::Array, "Value", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000008000182, 1, nullptr, STRUCT_OFFSET(LowEntryByteDataWriter_eventAddPositiveInteger1Array_Parms, Value), METADATA_PARAMS(Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger1Array_Statics::NewProp_Value_MetaData, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger1Array_Statics::NewProp_Value_MetaData)) };
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger1Array_Statics::NewProp_Value_Inner = { UE4CodeGen_Private::EPropertyClass::Int, "Value", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger1Array_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger1Array_Statics::NewProp_Value,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger1Array_Statics::NewProp_Value_Inner,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger1Array_Statics::Function_MetaDataParams[] = {
		{ "Category", "Low Entry|Extended Standard Library|Byte Data|Writer" },
		{ "DisplayName", "Add Positive Integer 1 Array" },
		{ "ModuleRelativePath", "Public/Classes/LowEntryByteDataWriter.h" },
		{ "ToolTip", "Adds a positive integer array.\n\nWill store values below 128 in 1 byte, higher values will be stored in 4 bytes.\n\nThe given integers have to be 0 or higher, values under 0 will be changed to 0." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger1Array_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULowEntryByteDataWriter, "AddPositiveInteger1Array", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04420401, sizeof(LowEntryByteDataWriter_eventAddPositiveInteger1Array_Parms), Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger1Array_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger1Array_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger1Array_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger1Array_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger1Array()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger1Array_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger2_Statics
	{
		struct LowEntryByteDataWriter_eventAddPositiveInteger2_Parms
		{
			int32 Value;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Value_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_Value;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger2_Statics::NewProp_Value_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger2_Statics::NewProp_Value = { UE4CodeGen_Private::EPropertyClass::Int, "Value", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000082, 1, nullptr, STRUCT_OFFSET(LowEntryByteDataWriter_eventAddPositiveInteger2_Parms, Value), METADATA_PARAMS(Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger2_Statics::NewProp_Value_MetaData, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger2_Statics::NewProp_Value_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger2_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger2_Statics::NewProp_Value,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger2_Statics::Function_MetaDataParams[] = {
		{ "Category", "Low Entry|Extended Standard Library|Byte Data|Writer" },
		{ "DisplayName", "Add Positive Integer 2" },
		{ "ModuleRelativePath", "Public/Classes/LowEntryByteDataWriter.h" },
		{ "ToolTip", "Adds a positive integer.\n\nWill store values below 32.768 in 2 bytes, higher values will be stored in 4 bytes.\n\nThe given integer has to be 0 or higher, values under 0 will be changed to 0." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger2_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULowEntryByteDataWriter, "AddPositiveInteger2", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(LowEntryByteDataWriter_eventAddPositiveInteger2_Parms), Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger2_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger2_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger2_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger2_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger2()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger2_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger2Array_Statics
	{
		struct LowEntryByteDataWriter_eventAddPositiveInteger2Array_Parms
		{
			TArray<int32> Value;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Value_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Value;
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_Value_Inner;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger2Array_Statics::NewProp_Value_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger2Array_Statics::NewProp_Value = { UE4CodeGen_Private::EPropertyClass::Array, "Value", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000008000182, 1, nullptr, STRUCT_OFFSET(LowEntryByteDataWriter_eventAddPositiveInteger2Array_Parms, Value), METADATA_PARAMS(Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger2Array_Statics::NewProp_Value_MetaData, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger2Array_Statics::NewProp_Value_MetaData)) };
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger2Array_Statics::NewProp_Value_Inner = { UE4CodeGen_Private::EPropertyClass::Int, "Value", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger2Array_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger2Array_Statics::NewProp_Value,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger2Array_Statics::NewProp_Value_Inner,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger2Array_Statics::Function_MetaDataParams[] = {
		{ "Category", "Low Entry|Extended Standard Library|Byte Data|Writer" },
		{ "DisplayName", "Add Positive Integer 2 Array" },
		{ "ModuleRelativePath", "Public/Classes/LowEntryByteDataWriter.h" },
		{ "ToolTip", "Adds a positive integer array.\n\nWill store values below 32.768 in 2 bytes, higher values will be stored in 4 bytes.\n\nThe given integers have to be 0 or higher, values under 0 will be changed to 0." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger2Array_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULowEntryByteDataWriter, "AddPositiveInteger2Array", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04420401, sizeof(LowEntryByteDataWriter_eventAddPositiveInteger2Array_Parms), Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger2Array_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger2Array_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger2Array_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger2Array_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger2Array()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger2Array_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger3_Statics
	{
		struct LowEntryByteDataWriter_eventAddPositiveInteger3_Parms
		{
			int32 Value;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Value_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_Value;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger3_Statics::NewProp_Value_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger3_Statics::NewProp_Value = { UE4CodeGen_Private::EPropertyClass::Int, "Value", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000082, 1, nullptr, STRUCT_OFFSET(LowEntryByteDataWriter_eventAddPositiveInteger3_Parms, Value), METADATA_PARAMS(Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger3_Statics::NewProp_Value_MetaData, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger3_Statics::NewProp_Value_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger3_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger3_Statics::NewProp_Value,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger3_Statics::Function_MetaDataParams[] = {
		{ "Category", "Low Entry|Extended Standard Library|Byte Data|Writer" },
		{ "DisplayName", "Add Positive Integer 3" },
		{ "ModuleRelativePath", "Public/Classes/LowEntryByteDataWriter.h" },
		{ "ToolTip", "Adds a positive integer.\n\nWill store values below 8.388.608 in 3 bytes, higher values will be stored in 4 bytes.\n\nThe given integer has to be 0 or higher, values under 0 will be changed to 0." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger3_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULowEntryByteDataWriter, "AddPositiveInteger3", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(LowEntryByteDataWriter_eventAddPositiveInteger3_Parms), Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger3_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger3_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger3_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger3_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger3()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger3_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger3Array_Statics
	{
		struct LowEntryByteDataWriter_eventAddPositiveInteger3Array_Parms
		{
			TArray<int32> Value;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Value_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Value;
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_Value_Inner;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger3Array_Statics::NewProp_Value_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger3Array_Statics::NewProp_Value = { UE4CodeGen_Private::EPropertyClass::Array, "Value", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000008000182, 1, nullptr, STRUCT_OFFSET(LowEntryByteDataWriter_eventAddPositiveInteger3Array_Parms, Value), METADATA_PARAMS(Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger3Array_Statics::NewProp_Value_MetaData, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger3Array_Statics::NewProp_Value_MetaData)) };
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger3Array_Statics::NewProp_Value_Inner = { UE4CodeGen_Private::EPropertyClass::Int, "Value", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger3Array_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger3Array_Statics::NewProp_Value,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger3Array_Statics::NewProp_Value_Inner,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger3Array_Statics::Function_MetaDataParams[] = {
		{ "Category", "Low Entry|Extended Standard Library|Byte Data|Writer" },
		{ "DisplayName", "Add Positive Integer 3 Array" },
		{ "ModuleRelativePath", "Public/Classes/LowEntryByteDataWriter.h" },
		{ "ToolTip", "Adds a positive integer array.\n\nWill store values below 8.388.608 in 3 bytes, higher values will be stored in 4 bytes.\n\nThe given integers have to be 0 or higher, values under 0 will be changed to 0." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger3Array_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULowEntryByteDataWriter, "AddPositiveInteger3Array", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04420401, sizeof(LowEntryByteDataWriter_eventAddPositiveInteger3Array_Parms), Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger3Array_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger3Array_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger3Array_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger3Array_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger3Array()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger3Array_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULowEntryByteDataWriter_AddStringUtf8_Statics
	{
		struct LowEntryByteDataWriter_eventAddStringUtf8_Parms
		{
			FString Value;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Value_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_Value;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryByteDataWriter_AddStringUtf8_Statics::NewProp_Value_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ULowEntryByteDataWriter_AddStringUtf8_Statics::NewProp_Value = { UE4CodeGen_Private::EPropertyClass::Str, "Value", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(LowEntryByteDataWriter_eventAddStringUtf8_Parms, Value), METADATA_PARAMS(Z_Construct_UFunction_ULowEntryByteDataWriter_AddStringUtf8_Statics::NewProp_Value_MetaData, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataWriter_AddStringUtf8_Statics::NewProp_Value_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULowEntryByteDataWriter_AddStringUtf8_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryByteDataWriter_AddStringUtf8_Statics::NewProp_Value,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryByteDataWriter_AddStringUtf8_Statics::Function_MetaDataParams[] = {
		{ "Category", "Low Entry|Extended Standard Library|Byte Data|Writer" },
		{ "DisplayName", "Add String (Utf 8)" },
		{ "ModuleRelativePath", "Public/Classes/LowEntryByteDataWriter.h" },
		{ "ToolTip", "Adds a String (UTF-8)." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULowEntryByteDataWriter_AddStringUtf8_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULowEntryByteDataWriter, "AddStringUtf8", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(LowEntryByteDataWriter_eventAddStringUtf8_Parms), Z_Construct_UFunction_ULowEntryByteDataWriter_AddStringUtf8_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataWriter_AddStringUtf8_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULowEntryByteDataWriter_AddStringUtf8_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataWriter_AddStringUtf8_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULowEntryByteDataWriter_AddStringUtf8()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULowEntryByteDataWriter_AddStringUtf8_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULowEntryByteDataWriter_AddStringUtf8Array_Statics
	{
		struct LowEntryByteDataWriter_eventAddStringUtf8Array_Parms
		{
			TArray<FString> Value;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Value_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Value;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_Value_Inner;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryByteDataWriter_AddStringUtf8Array_Statics::NewProp_Value_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_ULowEntryByteDataWriter_AddStringUtf8Array_Statics::NewProp_Value = { UE4CodeGen_Private::EPropertyClass::Array, "Value", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000008000182, 1, nullptr, STRUCT_OFFSET(LowEntryByteDataWriter_eventAddStringUtf8Array_Parms, Value), METADATA_PARAMS(Z_Construct_UFunction_ULowEntryByteDataWriter_AddStringUtf8Array_Statics::NewProp_Value_MetaData, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataWriter_AddStringUtf8Array_Statics::NewProp_Value_MetaData)) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ULowEntryByteDataWriter_AddStringUtf8Array_Statics::NewProp_Value_Inner = { UE4CodeGen_Private::EPropertyClass::Str, "Value", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULowEntryByteDataWriter_AddStringUtf8Array_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryByteDataWriter_AddStringUtf8Array_Statics::NewProp_Value,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryByteDataWriter_AddStringUtf8Array_Statics::NewProp_Value_Inner,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryByteDataWriter_AddStringUtf8Array_Statics::Function_MetaDataParams[] = {
		{ "Category", "Low Entry|Extended Standard Library|Byte Data|Writer" },
		{ "DisplayName", "Add String (Utf 8) Array" },
		{ "ModuleRelativePath", "Public/Classes/LowEntryByteDataWriter.h" },
		{ "ToolTip", "Adds a String (UTF-8) array." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULowEntryByteDataWriter_AddStringUtf8Array_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULowEntryByteDataWriter, "AddStringUtf8Array", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04420401, sizeof(LowEntryByteDataWriter_eventAddStringUtf8Array_Parms), Z_Construct_UFunction_ULowEntryByteDataWriter_AddStringUtf8Array_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataWriter_AddStringUtf8Array_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULowEntryByteDataWriter_AddStringUtf8Array_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryByteDataWriter_AddStringUtf8Array_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULowEntryByteDataWriter_AddStringUtf8Array()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULowEntryByteDataWriter_AddStringUtf8Array_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ULowEntryByteDataWriter_NoRegister()
	{
		return ULowEntryByteDataWriter::StaticClass();
	}
	struct Z_Construct_UClass_ULowEntryByteDataWriter_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Bytes_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Bytes;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_Bytes_Inner;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ULowEntryByteDataWriter_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_LowEntryExtendedStandardLibrary,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ULowEntryByteDataWriter_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ULowEntryByteDataWriter_AddBoolean, "AddBoolean" }, // 1100847349
		{ &Z_Construct_UFunction_ULowEntryByteDataWriter_AddBooleanArray, "AddBooleanArray" }, // 2404404042
		{ &Z_Construct_UFunction_ULowEntryByteDataWriter_AddByte, "AddByte" }, // 3767790333
		{ &Z_Construct_UFunction_ULowEntryByteDataWriter_AddByteArray, "AddByteArray" }, // 3753704779
		{ &Z_Construct_UFunction_ULowEntryByteDataWriter_AddDoubleBytes, "AddDoubleBytes" }, // 1368565139
		{ &Z_Construct_UFunction_ULowEntryByteDataWriter_AddDoubleBytesArray, "AddDoubleBytesArray" }, // 3994338414
		{ &Z_Construct_UFunction_ULowEntryByteDataWriter_AddFloat, "AddFloat" }, // 1631698682
		{ &Z_Construct_UFunction_ULowEntryByteDataWriter_AddFloatArray, "AddFloatArray" }, // 3357737049
		{ &Z_Construct_UFunction_ULowEntryByteDataWriter_AddInteger, "AddInteger" }, // 781743959
		{ &Z_Construct_UFunction_ULowEntryByteDataWriter_AddIntegerArray, "AddIntegerArray" }, // 2622704481
		{ &Z_Construct_UFunction_ULowEntryByteDataWriter_AddLongBytes, "AddLongBytes" }, // 2509757452
		{ &Z_Construct_UFunction_ULowEntryByteDataWriter_AddLongBytesArray, "AddLongBytesArray" }, // 1081366561
		{ &Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger1, "AddPositiveInteger1" }, // 3897298199
		{ &Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger1Array, "AddPositiveInteger1Array" }, // 202429751
		{ &Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger2, "AddPositiveInteger2" }, // 1419995589
		{ &Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger2Array, "AddPositiveInteger2Array" }, // 505757662
		{ &Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger3, "AddPositiveInteger3" }, // 2258697366
		{ &Z_Construct_UFunction_ULowEntryByteDataWriter_AddPositiveInteger3Array, "AddPositiveInteger3Array" }, // 2611363904
		{ &Z_Construct_UFunction_ULowEntryByteDataWriter_AddStringUtf8, "AddStringUtf8" }, // 1910386840
		{ &Z_Construct_UFunction_ULowEntryByteDataWriter_AddStringUtf8Array, "AddStringUtf8Array" }, // 629340428
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULowEntryByteDataWriter_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "Classes/LowEntryByteDataWriter.h" },
		{ "ModuleRelativePath", "Public/Classes/LowEntryByteDataWriter.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULowEntryByteDataWriter_Statics::NewProp_Bytes_MetaData[] = {
		{ "ModuleRelativePath", "Public/Classes/LowEntryByteDataWriter.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ULowEntryByteDataWriter_Statics::NewProp_Bytes = { UE4CodeGen_Private::EPropertyClass::Array, "Bytes", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000000, 1, nullptr, STRUCT_OFFSET(ULowEntryByteDataWriter, Bytes), METADATA_PARAMS(Z_Construct_UClass_ULowEntryByteDataWriter_Statics::NewProp_Bytes_MetaData, ARRAY_COUNT(Z_Construct_UClass_ULowEntryByteDataWriter_Statics::NewProp_Bytes_MetaData)) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UClass_ULowEntryByteDataWriter_Statics::NewProp_Bytes_Inner = { UE4CodeGen_Private::EPropertyClass::Byte, "Bytes", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ULowEntryByteDataWriter_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULowEntryByteDataWriter_Statics::NewProp_Bytes,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULowEntryByteDataWriter_Statics::NewProp_Bytes_Inner,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ULowEntryByteDataWriter_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ULowEntryByteDataWriter>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ULowEntryByteDataWriter_Statics::ClassParams = {
		&ULowEntryByteDataWriter::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x001000A0u,
		FuncInfo, ARRAY_COUNT(FuncInfo),
		Z_Construct_UClass_ULowEntryByteDataWriter_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_ULowEntryByteDataWriter_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_ULowEntryByteDataWriter_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_ULowEntryByteDataWriter_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ULowEntryByteDataWriter()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ULowEntryByteDataWriter_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ULowEntryByteDataWriter, 3921350244);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ULowEntryByteDataWriter(Z_Construct_UClass_ULowEntryByteDataWriter, &ULowEntryByteDataWriter::StaticClass, TEXT("/Script/LowEntryExtendedStandardLibrary"), TEXT("ULowEntryByteDataWriter"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ULowEntryByteDataWriter);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
