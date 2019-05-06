// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LowEntryExtendedStandardLibrary/Public/ClassesTypes/LowEntryDouble.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeLowEntryDouble() {}
// Cross Module References
	LOWENTRYEXTENDEDSTANDARDLIBRARY_API UClass* Z_Construct_UClass_ULowEntryDouble_NoRegister();
	LOWENTRYEXTENDEDSTANDARDLIBRARY_API UClass* Z_Construct_UClass_ULowEntryDouble();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_LowEntryExtendedStandardLibrary();
	LOWENTRYEXTENDEDSTANDARDLIBRARY_API UFunction* Z_Construct_UFunction_ULowEntryDouble_CastToLongBytes();
	LOWENTRYEXTENDEDSTANDARDLIBRARY_API UClass* Z_Construct_UClass_ULowEntryLong_NoRegister();
	LOWENTRYEXTENDEDSTANDARDLIBRARY_API UFunction* Z_Construct_UFunction_ULowEntryDouble_CastToString();
	LOWENTRYEXTENDEDSTANDARDLIBRARY_API UFunction* Z_Construct_UFunction_ULowEntryDouble_CreateClone();
	LOWENTRYEXTENDEDSTANDARDLIBRARY_API UFunction* Z_Construct_UFunction_ULowEntryDouble_DoubleBytes_Add();
	LOWENTRYEXTENDEDSTANDARDLIBRARY_API UFunction* Z_Construct_UFunction_ULowEntryDouble_DoubleBytes_Equals();
	LOWENTRYEXTENDEDSTANDARDLIBRARY_API UFunction* Z_Construct_UFunction_ULowEntryDouble_DoubleBytes_GreaterThan();
	LOWENTRYEXTENDEDSTANDARDLIBRARY_API UFunction* Z_Construct_UFunction_ULowEntryDouble_DoubleBytes_LessThan();
	LOWENTRYEXTENDEDSTANDARDLIBRARY_API UFunction* Z_Construct_UFunction_ULowEntryDouble_DoubleBytes_Subtract();
	LOWENTRYEXTENDEDSTANDARDLIBRARY_API UFunction* Z_Construct_UFunction_ULowEntryDouble_Float_Add();
	LOWENTRYEXTENDEDSTANDARDLIBRARY_API UFunction* Z_Construct_UFunction_ULowEntryDouble_Float_Equals();
	LOWENTRYEXTENDEDSTANDARDLIBRARY_API UFunction* Z_Construct_UFunction_ULowEntryDouble_Float_GreaterThan();
	LOWENTRYEXTENDEDSTANDARDLIBRARY_API UFunction* Z_Construct_UFunction_ULowEntryDouble_Float_LessThan();
	LOWENTRYEXTENDEDSTANDARDLIBRARY_API UFunction* Z_Construct_UFunction_ULowEntryDouble_Float_Subtract();
	LOWENTRYEXTENDEDSTANDARDLIBRARY_API UFunction* Z_Construct_UFunction_ULowEntryDouble_GetBytes();
	LOWENTRYEXTENDEDSTANDARDLIBRARY_API UFunction* Z_Construct_UFunction_ULowEntryDouble_Integer_GreaterThan();
	LOWENTRYEXTENDEDSTANDARDLIBRARY_API UFunction* Z_Construct_UFunction_ULowEntryDouble_Integer_LessThan();
	LOWENTRYEXTENDEDSTANDARDLIBRARY_API UFunction* Z_Construct_UFunction_ULowEntryDouble_LongBytes_GreaterThan();
	LOWENTRYEXTENDEDSTANDARDLIBRARY_API UFunction* Z_Construct_UFunction_ULowEntryDouble_LongBytes_LessThan();
	LOWENTRYEXTENDEDSTANDARDLIBRARY_API UFunction* Z_Construct_UFunction_ULowEntryDouble_SetBytes();
// End Cross Module References
	void ULowEntryDouble::StaticRegisterNativesULowEntryDouble()
	{
		UClass* Class = ULowEntryDouble::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "CastToLongBytes", &ULowEntryDouble::execCastToLongBytes },
			{ "CastToString", &ULowEntryDouble::execCastToString },
			{ "CreateClone", &ULowEntryDouble::execCreateClone },
			{ "DoubleBytes_Add", &ULowEntryDouble::execDoubleBytes_Add },
			{ "DoubleBytes_Equals", &ULowEntryDouble::execDoubleBytes_Equals },
			{ "DoubleBytes_GreaterThan", &ULowEntryDouble::execDoubleBytes_GreaterThan },
			{ "DoubleBytes_LessThan", &ULowEntryDouble::execDoubleBytes_LessThan },
			{ "DoubleBytes_Subtract", &ULowEntryDouble::execDoubleBytes_Subtract },
			{ "Float_Add", &ULowEntryDouble::execFloat_Add },
			{ "Float_Equals", &ULowEntryDouble::execFloat_Equals },
			{ "Float_GreaterThan", &ULowEntryDouble::execFloat_GreaterThan },
			{ "Float_LessThan", &ULowEntryDouble::execFloat_LessThan },
			{ "Float_Subtract", &ULowEntryDouble::execFloat_Subtract },
			{ "GetBytes", &ULowEntryDouble::execGetBytes },
			{ "Integer_GreaterThan", &ULowEntryDouble::execInteger_GreaterThan },
			{ "Integer_LessThan", &ULowEntryDouble::execInteger_LessThan },
			{ "LongBytes_GreaterThan", &ULowEntryDouble::execLongBytes_GreaterThan },
			{ "LongBytes_LessThan", &ULowEntryDouble::execLongBytes_LessThan },
			{ "SetBytes", &ULowEntryDouble::execSetBytes },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ULowEntryDouble_CastToLongBytes_Statics
	{
		struct LowEntryDouble_eventCastToLongBytes_Parms
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
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ULowEntryDouble_CastToLongBytes_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Object, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(LowEntryDouble_eventCastToLongBytes_Parms, ReturnValue), Z_Construct_UClass_ULowEntryLong_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULowEntryDouble_CastToLongBytes_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryDouble_CastToLongBytes_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryDouble_CastToLongBytes_Statics::Function_MetaDataParams[] = {
		{ "Category", "Low Entry|Extended Standard Library|Types|Double (bytes)" },
		{ "DisplayName", "Cast To Long (bytes)" },
		{ "ModuleRelativePath", "Public/ClassesTypes/LowEntryDouble.h" },
		{ "ToolTip", "Casts the double to a long." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULowEntryDouble_CastToLongBytes_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULowEntryDouble, "CastToLongBytes", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14020401, sizeof(LowEntryDouble_eventCastToLongBytes_Parms), Z_Construct_UFunction_ULowEntryDouble_CastToLongBytes_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryDouble_CastToLongBytes_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULowEntryDouble_CastToLongBytes_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryDouble_CastToLongBytes_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULowEntryDouble_CastToLongBytes()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULowEntryDouble_CastToLongBytes_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULowEntryDouble_CastToString_Statics
	{
		struct LowEntryDouble_eventCastToString_Parms
		{
			int32 MinFractionalDigits;
			FString ReturnValue;
		};
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MinFractionalDigits_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_MinFractionalDigits;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ULowEntryDouble_CastToString_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Str, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(LowEntryDouble_eventCastToString_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryDouble_CastToString_Statics::NewProp_MinFractionalDigits_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ULowEntryDouble_CastToString_Statics::NewProp_MinFractionalDigits = { UE4CodeGen_Private::EPropertyClass::Int, "MinFractionalDigits", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000082, 1, nullptr, STRUCT_OFFSET(LowEntryDouble_eventCastToString_Parms, MinFractionalDigits), METADATA_PARAMS(Z_Construct_UFunction_ULowEntryDouble_CastToString_Statics::NewProp_MinFractionalDigits_MetaData, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryDouble_CastToString_Statics::NewProp_MinFractionalDigits_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULowEntryDouble_CastToString_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryDouble_CastToString_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryDouble_CastToString_Statics::NewProp_MinFractionalDigits,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryDouble_CastToString_Statics::Function_MetaDataParams[] = {
		{ "Category", "Low Entry|Extended Standard Library|Types|Double (bytes)" },
		{ "CPP_Default_MinFractionalDigits", "1" },
		{ "DisplayName", "To String" },
		{ "ModuleRelativePath", "Public/ClassesTypes/LowEntryDouble.h" },
		{ "ToolTip", "Casts the double to a string." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULowEntryDouble_CastToString_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULowEntryDouble, "CastToString", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14020401, sizeof(LowEntryDouble_eventCastToString_Parms), Z_Construct_UFunction_ULowEntryDouble_CastToString_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryDouble_CastToString_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULowEntryDouble_CastToString_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryDouble_CastToString_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULowEntryDouble_CastToString()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULowEntryDouble_CastToString_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULowEntryDouble_CreateClone_Statics
	{
		struct LowEntryDouble_eventCreateClone_Parms
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
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ULowEntryDouble_CreateClone_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Object, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(LowEntryDouble_eventCreateClone_Parms, ReturnValue), Z_Construct_UClass_ULowEntryDouble_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULowEntryDouble_CreateClone_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryDouble_CreateClone_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryDouble_CreateClone_Statics::Function_MetaDataParams[] = {
		{ "Category", "Low Entry|Extended Standard Library|Types|Double (bytes)" },
		{ "DisplayName", "Create Clone" },
		{ "ModuleRelativePath", "Public/ClassesTypes/LowEntryDouble.h" },
		{ "ToolTip", "Casts the long to a double." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULowEntryDouble_CreateClone_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULowEntryDouble, "CreateClone", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14020401, sizeof(LowEntryDouble_eventCreateClone_Parms), Z_Construct_UFunction_ULowEntryDouble_CreateClone_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryDouble_CreateClone_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULowEntryDouble_CreateClone_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryDouble_CreateClone_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULowEntryDouble_CreateClone()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULowEntryDouble_CreateClone_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULowEntryDouble_DoubleBytes_Add_Statics
	{
		struct LowEntryDouble_eventDoubleBytes_Add_Parms
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
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ULowEntryDouble_DoubleBytes_Add_Statics::NewProp_Value = { UE4CodeGen_Private::EPropertyClass::Object, "Value", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(LowEntryDouble_eventDoubleBytes_Add_Parms, Value), Z_Construct_UClass_ULowEntryDouble_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULowEntryDouble_DoubleBytes_Add_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryDouble_DoubleBytes_Add_Statics::NewProp_Value,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryDouble_DoubleBytes_Add_Statics::Function_MetaDataParams[] = {
		{ "Category", "Low Entry|Extended Standard Library|Types|Double (bytes)" },
		{ "DisplayName", "Add (Double Bytes)" },
		{ "ModuleRelativePath", "Public/ClassesTypes/LowEntryDouble.h" },
		{ "ToolTip", "Add a float to this double." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULowEntryDouble_DoubleBytes_Add_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULowEntryDouble, "DoubleBytes_Add", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(LowEntryDouble_eventDoubleBytes_Add_Parms), Z_Construct_UFunction_ULowEntryDouble_DoubleBytes_Add_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryDouble_DoubleBytes_Add_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULowEntryDouble_DoubleBytes_Add_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryDouble_DoubleBytes_Add_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULowEntryDouble_DoubleBytes_Add()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULowEntryDouble_DoubleBytes_Add_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULowEntryDouble_DoubleBytes_Equals_Statics
	{
		struct LowEntryDouble_eventDoubleBytes_Equals_Parms
		{
			ULowEntryDouble* Value;
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Value;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ULowEntryDouble_DoubleBytes_Equals_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((LowEntryDouble_eventDoubleBytes_Equals_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ULowEntryDouble_DoubleBytes_Equals_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Bool, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(LowEntryDouble_eventDoubleBytes_Equals_Parms), &Z_Construct_UFunction_ULowEntryDouble_DoubleBytes_Equals_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ULowEntryDouble_DoubleBytes_Equals_Statics::NewProp_Value = { UE4CodeGen_Private::EPropertyClass::Object, "Value", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(LowEntryDouble_eventDoubleBytes_Equals_Parms, Value), Z_Construct_UClass_ULowEntryDouble_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULowEntryDouble_DoubleBytes_Equals_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryDouble_DoubleBytes_Equals_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryDouble_DoubleBytes_Equals_Statics::NewProp_Value,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryDouble_DoubleBytes_Equals_Statics::Function_MetaDataParams[] = {
		{ "Category", "Low Entry|Extended Standard Library|Types|Double (bytes)" },
		{ "DisplayName", "Equals (Double Bytes)" },
		{ "ModuleRelativePath", "Public/ClassesTypes/LowEntryDouble.h" },
		{ "ToolTip", "Returns true if the double is equal to the given integer." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULowEntryDouble_DoubleBytes_Equals_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULowEntryDouble, "DoubleBytes_Equals", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14020401, sizeof(LowEntryDouble_eventDoubleBytes_Equals_Parms), Z_Construct_UFunction_ULowEntryDouble_DoubleBytes_Equals_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryDouble_DoubleBytes_Equals_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULowEntryDouble_DoubleBytes_Equals_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryDouble_DoubleBytes_Equals_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULowEntryDouble_DoubleBytes_Equals()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULowEntryDouble_DoubleBytes_Equals_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULowEntryDouble_DoubleBytes_GreaterThan_Statics
	{
		struct LowEntryDouble_eventDoubleBytes_GreaterThan_Parms
		{
			ULowEntryDouble* Value;
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Value;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ULowEntryDouble_DoubleBytes_GreaterThan_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((LowEntryDouble_eventDoubleBytes_GreaterThan_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ULowEntryDouble_DoubleBytes_GreaterThan_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Bool, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(LowEntryDouble_eventDoubleBytes_GreaterThan_Parms), &Z_Construct_UFunction_ULowEntryDouble_DoubleBytes_GreaterThan_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ULowEntryDouble_DoubleBytes_GreaterThan_Statics::NewProp_Value = { UE4CodeGen_Private::EPropertyClass::Object, "Value", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(LowEntryDouble_eventDoubleBytes_GreaterThan_Parms, Value), Z_Construct_UClass_ULowEntryDouble_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULowEntryDouble_DoubleBytes_GreaterThan_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryDouble_DoubleBytes_GreaterThan_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryDouble_DoubleBytes_GreaterThan_Statics::NewProp_Value,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryDouble_DoubleBytes_GreaterThan_Statics::Function_MetaDataParams[] = {
		{ "Category", "Low Entry|Extended Standard Library|Types|Double (bytes)" },
		{ "DisplayName", "Greater Than (Double Bytes)" },
		{ "ModuleRelativePath", "Public/ClassesTypes/LowEntryDouble.h" },
		{ "ToolTip", "Returns true if the double is greater than the given float." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULowEntryDouble_DoubleBytes_GreaterThan_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULowEntryDouble, "DoubleBytes_GreaterThan", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14020401, sizeof(LowEntryDouble_eventDoubleBytes_GreaterThan_Parms), Z_Construct_UFunction_ULowEntryDouble_DoubleBytes_GreaterThan_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryDouble_DoubleBytes_GreaterThan_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULowEntryDouble_DoubleBytes_GreaterThan_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryDouble_DoubleBytes_GreaterThan_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULowEntryDouble_DoubleBytes_GreaterThan()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULowEntryDouble_DoubleBytes_GreaterThan_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULowEntryDouble_DoubleBytes_LessThan_Statics
	{
		struct LowEntryDouble_eventDoubleBytes_LessThan_Parms
		{
			ULowEntryDouble* Value;
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Value;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ULowEntryDouble_DoubleBytes_LessThan_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((LowEntryDouble_eventDoubleBytes_LessThan_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ULowEntryDouble_DoubleBytes_LessThan_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Bool, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(LowEntryDouble_eventDoubleBytes_LessThan_Parms), &Z_Construct_UFunction_ULowEntryDouble_DoubleBytes_LessThan_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ULowEntryDouble_DoubleBytes_LessThan_Statics::NewProp_Value = { UE4CodeGen_Private::EPropertyClass::Object, "Value", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(LowEntryDouble_eventDoubleBytes_LessThan_Parms, Value), Z_Construct_UClass_ULowEntryDouble_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULowEntryDouble_DoubleBytes_LessThan_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryDouble_DoubleBytes_LessThan_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryDouble_DoubleBytes_LessThan_Statics::NewProp_Value,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryDouble_DoubleBytes_LessThan_Statics::Function_MetaDataParams[] = {
		{ "Category", "Low Entry|Extended Standard Library|Types|Double (bytes)" },
		{ "DisplayName", "Less Than (Double Bytes)" },
		{ "ModuleRelativePath", "Public/ClassesTypes/LowEntryDouble.h" },
		{ "ToolTip", "Returns true if the double is less than the given float." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULowEntryDouble_DoubleBytes_LessThan_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULowEntryDouble, "DoubleBytes_LessThan", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14020401, sizeof(LowEntryDouble_eventDoubleBytes_LessThan_Parms), Z_Construct_UFunction_ULowEntryDouble_DoubleBytes_LessThan_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryDouble_DoubleBytes_LessThan_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULowEntryDouble_DoubleBytes_LessThan_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryDouble_DoubleBytes_LessThan_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULowEntryDouble_DoubleBytes_LessThan()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULowEntryDouble_DoubleBytes_LessThan_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULowEntryDouble_DoubleBytes_Subtract_Statics
	{
		struct LowEntryDouble_eventDoubleBytes_Subtract_Parms
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
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ULowEntryDouble_DoubleBytes_Subtract_Statics::NewProp_Value = { UE4CodeGen_Private::EPropertyClass::Object, "Value", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(LowEntryDouble_eventDoubleBytes_Subtract_Parms, Value), Z_Construct_UClass_ULowEntryDouble_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULowEntryDouble_DoubleBytes_Subtract_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryDouble_DoubleBytes_Subtract_Statics::NewProp_Value,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryDouble_DoubleBytes_Subtract_Statics::Function_MetaDataParams[] = {
		{ "Category", "Low Entry|Extended Standard Library|Types|Double (bytes)" },
		{ "DisplayName", "Subtract (Double Bytes)" },
		{ "ModuleRelativePath", "Public/ClassesTypes/LowEntryDouble.h" },
		{ "ToolTip", "Subtracts a float from this double." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULowEntryDouble_DoubleBytes_Subtract_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULowEntryDouble, "DoubleBytes_Subtract", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(LowEntryDouble_eventDoubleBytes_Subtract_Parms), Z_Construct_UFunction_ULowEntryDouble_DoubleBytes_Subtract_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryDouble_DoubleBytes_Subtract_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULowEntryDouble_DoubleBytes_Subtract_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryDouble_DoubleBytes_Subtract_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULowEntryDouble_DoubleBytes_Subtract()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULowEntryDouble_DoubleBytes_Subtract_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULowEntryDouble_Float_Add_Statics
	{
		struct LowEntryDouble_eventFloat_Add_Parms
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
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryDouble_Float_Add_Statics::NewProp_Value_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ULowEntryDouble_Float_Add_Statics::NewProp_Value = { UE4CodeGen_Private::EPropertyClass::Float, "Value", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000082, 1, nullptr, STRUCT_OFFSET(LowEntryDouble_eventFloat_Add_Parms, Value), METADATA_PARAMS(Z_Construct_UFunction_ULowEntryDouble_Float_Add_Statics::NewProp_Value_MetaData, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryDouble_Float_Add_Statics::NewProp_Value_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULowEntryDouble_Float_Add_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryDouble_Float_Add_Statics::NewProp_Value,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryDouble_Float_Add_Statics::Function_MetaDataParams[] = {
		{ "Category", "Low Entry|Extended Standard Library|Types|Double (bytes)" },
		{ "DisplayName", "Add (Float)" },
		{ "ModuleRelativePath", "Public/ClassesTypes/LowEntryDouble.h" },
		{ "ToolTip", "Add a float to this double." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULowEntryDouble_Float_Add_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULowEntryDouble, "Float_Add", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(LowEntryDouble_eventFloat_Add_Parms), Z_Construct_UFunction_ULowEntryDouble_Float_Add_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryDouble_Float_Add_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULowEntryDouble_Float_Add_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryDouble_Float_Add_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULowEntryDouble_Float_Add()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULowEntryDouble_Float_Add_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULowEntryDouble_Float_Equals_Statics
	{
		struct LowEntryDouble_eventFloat_Equals_Parms
		{
			float Value;
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
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
	void Z_Construct_UFunction_ULowEntryDouble_Float_Equals_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((LowEntryDouble_eventFloat_Equals_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ULowEntryDouble_Float_Equals_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Bool, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(LowEntryDouble_eventFloat_Equals_Parms), &Z_Construct_UFunction_ULowEntryDouble_Float_Equals_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryDouble_Float_Equals_Statics::NewProp_Value_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ULowEntryDouble_Float_Equals_Statics::NewProp_Value = { UE4CodeGen_Private::EPropertyClass::Float, "Value", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000082, 1, nullptr, STRUCT_OFFSET(LowEntryDouble_eventFloat_Equals_Parms, Value), METADATA_PARAMS(Z_Construct_UFunction_ULowEntryDouble_Float_Equals_Statics::NewProp_Value_MetaData, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryDouble_Float_Equals_Statics::NewProp_Value_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULowEntryDouble_Float_Equals_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryDouble_Float_Equals_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryDouble_Float_Equals_Statics::NewProp_Value,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryDouble_Float_Equals_Statics::Function_MetaDataParams[] = {
		{ "Category", "Low Entry|Extended Standard Library|Types|Double (bytes)" },
		{ "DisplayName", "Equals (Float)" },
		{ "ModuleRelativePath", "Public/ClassesTypes/LowEntryDouble.h" },
		{ "ToolTip", "Returns true if the double is equal to the given integer." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULowEntryDouble_Float_Equals_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULowEntryDouble, "Float_Equals", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14020401, sizeof(LowEntryDouble_eventFloat_Equals_Parms), Z_Construct_UFunction_ULowEntryDouble_Float_Equals_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryDouble_Float_Equals_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULowEntryDouble_Float_Equals_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryDouble_Float_Equals_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULowEntryDouble_Float_Equals()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULowEntryDouble_Float_Equals_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULowEntryDouble_Float_GreaterThan_Statics
	{
		struct LowEntryDouble_eventFloat_GreaterThan_Parms
		{
			float Value;
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
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
	void Z_Construct_UFunction_ULowEntryDouble_Float_GreaterThan_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((LowEntryDouble_eventFloat_GreaterThan_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ULowEntryDouble_Float_GreaterThan_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Bool, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(LowEntryDouble_eventFloat_GreaterThan_Parms), &Z_Construct_UFunction_ULowEntryDouble_Float_GreaterThan_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryDouble_Float_GreaterThan_Statics::NewProp_Value_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ULowEntryDouble_Float_GreaterThan_Statics::NewProp_Value = { UE4CodeGen_Private::EPropertyClass::Float, "Value", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000082, 1, nullptr, STRUCT_OFFSET(LowEntryDouble_eventFloat_GreaterThan_Parms, Value), METADATA_PARAMS(Z_Construct_UFunction_ULowEntryDouble_Float_GreaterThan_Statics::NewProp_Value_MetaData, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryDouble_Float_GreaterThan_Statics::NewProp_Value_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULowEntryDouble_Float_GreaterThan_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryDouble_Float_GreaterThan_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryDouble_Float_GreaterThan_Statics::NewProp_Value,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryDouble_Float_GreaterThan_Statics::Function_MetaDataParams[] = {
		{ "Category", "Low Entry|Extended Standard Library|Types|Double (bytes)" },
		{ "DisplayName", "Greater Than (Float)" },
		{ "ModuleRelativePath", "Public/ClassesTypes/LowEntryDouble.h" },
		{ "ToolTip", "Returns true if the double is greater than the given float." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULowEntryDouble_Float_GreaterThan_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULowEntryDouble, "Float_GreaterThan", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14020401, sizeof(LowEntryDouble_eventFloat_GreaterThan_Parms), Z_Construct_UFunction_ULowEntryDouble_Float_GreaterThan_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryDouble_Float_GreaterThan_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULowEntryDouble_Float_GreaterThan_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryDouble_Float_GreaterThan_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULowEntryDouble_Float_GreaterThan()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULowEntryDouble_Float_GreaterThan_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULowEntryDouble_Float_LessThan_Statics
	{
		struct LowEntryDouble_eventFloat_LessThan_Parms
		{
			float Value;
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
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
	void Z_Construct_UFunction_ULowEntryDouble_Float_LessThan_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((LowEntryDouble_eventFloat_LessThan_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ULowEntryDouble_Float_LessThan_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Bool, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(LowEntryDouble_eventFloat_LessThan_Parms), &Z_Construct_UFunction_ULowEntryDouble_Float_LessThan_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryDouble_Float_LessThan_Statics::NewProp_Value_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ULowEntryDouble_Float_LessThan_Statics::NewProp_Value = { UE4CodeGen_Private::EPropertyClass::Float, "Value", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000082, 1, nullptr, STRUCT_OFFSET(LowEntryDouble_eventFloat_LessThan_Parms, Value), METADATA_PARAMS(Z_Construct_UFunction_ULowEntryDouble_Float_LessThan_Statics::NewProp_Value_MetaData, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryDouble_Float_LessThan_Statics::NewProp_Value_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULowEntryDouble_Float_LessThan_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryDouble_Float_LessThan_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryDouble_Float_LessThan_Statics::NewProp_Value,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryDouble_Float_LessThan_Statics::Function_MetaDataParams[] = {
		{ "Category", "Low Entry|Extended Standard Library|Types|Double (bytes)" },
		{ "DisplayName", "Less Than (Float)" },
		{ "ModuleRelativePath", "Public/ClassesTypes/LowEntryDouble.h" },
		{ "ToolTip", "Returns true if the double is less than the given float." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULowEntryDouble_Float_LessThan_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULowEntryDouble, "Float_LessThan", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14020401, sizeof(LowEntryDouble_eventFloat_LessThan_Parms), Z_Construct_UFunction_ULowEntryDouble_Float_LessThan_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryDouble_Float_LessThan_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULowEntryDouble_Float_LessThan_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryDouble_Float_LessThan_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULowEntryDouble_Float_LessThan()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULowEntryDouble_Float_LessThan_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULowEntryDouble_Float_Subtract_Statics
	{
		struct LowEntryDouble_eventFloat_Subtract_Parms
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
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryDouble_Float_Subtract_Statics::NewProp_Value_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ULowEntryDouble_Float_Subtract_Statics::NewProp_Value = { UE4CodeGen_Private::EPropertyClass::Float, "Value", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000082, 1, nullptr, STRUCT_OFFSET(LowEntryDouble_eventFloat_Subtract_Parms, Value), METADATA_PARAMS(Z_Construct_UFunction_ULowEntryDouble_Float_Subtract_Statics::NewProp_Value_MetaData, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryDouble_Float_Subtract_Statics::NewProp_Value_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULowEntryDouble_Float_Subtract_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryDouble_Float_Subtract_Statics::NewProp_Value,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryDouble_Float_Subtract_Statics::Function_MetaDataParams[] = {
		{ "Category", "Low Entry|Extended Standard Library|Types|Double (bytes)" },
		{ "DisplayName", "Subtract (Float)" },
		{ "ModuleRelativePath", "Public/ClassesTypes/LowEntryDouble.h" },
		{ "ToolTip", "Subtracts a float from this double." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULowEntryDouble_Float_Subtract_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULowEntryDouble, "Float_Subtract", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(LowEntryDouble_eventFloat_Subtract_Parms), Z_Construct_UFunction_ULowEntryDouble_Float_Subtract_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryDouble_Float_Subtract_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULowEntryDouble_Float_Subtract_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryDouble_Float_Subtract_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULowEntryDouble_Float_Subtract()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULowEntryDouble_Float_Subtract_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULowEntryDouble_GetBytes_Statics
	{
		struct LowEntryDouble_eventGetBytes_Parms
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
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_ULowEntryDouble_GetBytes_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Array, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(LowEntryDouble_eventGetBytes_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_ULowEntryDouble_GetBytes_Statics::NewProp_ReturnValue_Inner = { UE4CodeGen_Private::EPropertyClass::Byte, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULowEntryDouble_GetBytes_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryDouble_GetBytes_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryDouble_GetBytes_Statics::NewProp_ReturnValue_Inner,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryDouble_GetBytes_Statics::Function_MetaDataParams[] = {
		{ "Category", "Low Entry|Extended Standard Library|Types|Double (bytes)" },
		{ "DisplayName", "Get Bytes" },
		{ "ModuleRelativePath", "Public/ClassesTypes/LowEntryDouble.h" },
		{ "ToolTip", "Returns the bytes (always 8 bytes)." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULowEntryDouble_GetBytes_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULowEntryDouble, "GetBytes", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14020401, sizeof(LowEntryDouble_eventGetBytes_Parms), Z_Construct_UFunction_ULowEntryDouble_GetBytes_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryDouble_GetBytes_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULowEntryDouble_GetBytes_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryDouble_GetBytes_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULowEntryDouble_GetBytes()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULowEntryDouble_GetBytes_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULowEntryDouble_Integer_GreaterThan_Statics
	{
		struct LowEntryDouble_eventInteger_GreaterThan_Parms
		{
			int32 Value;
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
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
	void Z_Construct_UFunction_ULowEntryDouble_Integer_GreaterThan_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((LowEntryDouble_eventInteger_GreaterThan_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ULowEntryDouble_Integer_GreaterThan_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Bool, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(LowEntryDouble_eventInteger_GreaterThan_Parms), &Z_Construct_UFunction_ULowEntryDouble_Integer_GreaterThan_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryDouble_Integer_GreaterThan_Statics::NewProp_Value_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ULowEntryDouble_Integer_GreaterThan_Statics::NewProp_Value = { UE4CodeGen_Private::EPropertyClass::Int, "Value", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000082, 1, nullptr, STRUCT_OFFSET(LowEntryDouble_eventInteger_GreaterThan_Parms, Value), METADATA_PARAMS(Z_Construct_UFunction_ULowEntryDouble_Integer_GreaterThan_Statics::NewProp_Value_MetaData, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryDouble_Integer_GreaterThan_Statics::NewProp_Value_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULowEntryDouble_Integer_GreaterThan_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryDouble_Integer_GreaterThan_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryDouble_Integer_GreaterThan_Statics::NewProp_Value,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryDouble_Integer_GreaterThan_Statics::Function_MetaDataParams[] = {
		{ "Category", "Low Entry|Extended Standard Library|Types|Double (bytes)" },
		{ "DisplayName", "Greater Than (Integer)" },
		{ "ModuleRelativePath", "Public/ClassesTypes/LowEntryDouble.h" },
		{ "ToolTip", "Returns true if the double is greater than the given integer." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULowEntryDouble_Integer_GreaterThan_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULowEntryDouble, "Integer_GreaterThan", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14020401, sizeof(LowEntryDouble_eventInteger_GreaterThan_Parms), Z_Construct_UFunction_ULowEntryDouble_Integer_GreaterThan_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryDouble_Integer_GreaterThan_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULowEntryDouble_Integer_GreaterThan_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryDouble_Integer_GreaterThan_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULowEntryDouble_Integer_GreaterThan()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULowEntryDouble_Integer_GreaterThan_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULowEntryDouble_Integer_LessThan_Statics
	{
		struct LowEntryDouble_eventInteger_LessThan_Parms
		{
			int32 Value;
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
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
	void Z_Construct_UFunction_ULowEntryDouble_Integer_LessThan_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((LowEntryDouble_eventInteger_LessThan_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ULowEntryDouble_Integer_LessThan_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Bool, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(LowEntryDouble_eventInteger_LessThan_Parms), &Z_Construct_UFunction_ULowEntryDouble_Integer_LessThan_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryDouble_Integer_LessThan_Statics::NewProp_Value_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ULowEntryDouble_Integer_LessThan_Statics::NewProp_Value = { UE4CodeGen_Private::EPropertyClass::Int, "Value", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000082, 1, nullptr, STRUCT_OFFSET(LowEntryDouble_eventInteger_LessThan_Parms, Value), METADATA_PARAMS(Z_Construct_UFunction_ULowEntryDouble_Integer_LessThan_Statics::NewProp_Value_MetaData, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryDouble_Integer_LessThan_Statics::NewProp_Value_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULowEntryDouble_Integer_LessThan_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryDouble_Integer_LessThan_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryDouble_Integer_LessThan_Statics::NewProp_Value,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryDouble_Integer_LessThan_Statics::Function_MetaDataParams[] = {
		{ "Category", "Low Entry|Extended Standard Library|Types|Double (bytes)" },
		{ "DisplayName", "Less Than (Integer)" },
		{ "ModuleRelativePath", "Public/ClassesTypes/LowEntryDouble.h" },
		{ "ToolTip", "Returns true if the double is less than the given integer." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULowEntryDouble_Integer_LessThan_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULowEntryDouble, "Integer_LessThan", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14020401, sizeof(LowEntryDouble_eventInteger_LessThan_Parms), Z_Construct_UFunction_ULowEntryDouble_Integer_LessThan_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryDouble_Integer_LessThan_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULowEntryDouble_Integer_LessThan_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryDouble_Integer_LessThan_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULowEntryDouble_Integer_LessThan()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULowEntryDouble_Integer_LessThan_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULowEntryDouble_LongBytes_GreaterThan_Statics
	{
		struct LowEntryDouble_eventLongBytes_GreaterThan_Parms
		{
			ULowEntryLong* Value;
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Value;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ULowEntryDouble_LongBytes_GreaterThan_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((LowEntryDouble_eventLongBytes_GreaterThan_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ULowEntryDouble_LongBytes_GreaterThan_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Bool, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(LowEntryDouble_eventLongBytes_GreaterThan_Parms), &Z_Construct_UFunction_ULowEntryDouble_LongBytes_GreaterThan_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ULowEntryDouble_LongBytes_GreaterThan_Statics::NewProp_Value = { UE4CodeGen_Private::EPropertyClass::Object, "Value", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(LowEntryDouble_eventLongBytes_GreaterThan_Parms, Value), Z_Construct_UClass_ULowEntryLong_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULowEntryDouble_LongBytes_GreaterThan_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryDouble_LongBytes_GreaterThan_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryDouble_LongBytes_GreaterThan_Statics::NewProp_Value,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryDouble_LongBytes_GreaterThan_Statics::Function_MetaDataParams[] = {
		{ "Category", "Low Entry|Extended Standard Library|Types|Double (bytes)" },
		{ "DisplayName", "Greater Than (Long Bytes)" },
		{ "ModuleRelativePath", "Public/ClassesTypes/LowEntryDouble.h" },
		{ "ToolTip", "Returns true if the double is greater than the given integer." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULowEntryDouble_LongBytes_GreaterThan_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULowEntryDouble, "LongBytes_GreaterThan", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14020401, sizeof(LowEntryDouble_eventLongBytes_GreaterThan_Parms), Z_Construct_UFunction_ULowEntryDouble_LongBytes_GreaterThan_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryDouble_LongBytes_GreaterThan_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULowEntryDouble_LongBytes_GreaterThan_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryDouble_LongBytes_GreaterThan_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULowEntryDouble_LongBytes_GreaterThan()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULowEntryDouble_LongBytes_GreaterThan_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULowEntryDouble_LongBytes_LessThan_Statics
	{
		struct LowEntryDouble_eventLongBytes_LessThan_Parms
		{
			ULowEntryLong* Value;
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Value;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ULowEntryDouble_LongBytes_LessThan_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((LowEntryDouble_eventLongBytes_LessThan_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ULowEntryDouble_LongBytes_LessThan_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Bool, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(LowEntryDouble_eventLongBytes_LessThan_Parms), &Z_Construct_UFunction_ULowEntryDouble_LongBytes_LessThan_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ULowEntryDouble_LongBytes_LessThan_Statics::NewProp_Value = { UE4CodeGen_Private::EPropertyClass::Object, "Value", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(LowEntryDouble_eventLongBytes_LessThan_Parms, Value), Z_Construct_UClass_ULowEntryLong_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULowEntryDouble_LongBytes_LessThan_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryDouble_LongBytes_LessThan_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryDouble_LongBytes_LessThan_Statics::NewProp_Value,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryDouble_LongBytes_LessThan_Statics::Function_MetaDataParams[] = {
		{ "Category", "Low Entry|Extended Standard Library|Types|Double (bytes)" },
		{ "DisplayName", "Less Than (Long Bytes)" },
		{ "ModuleRelativePath", "Public/ClassesTypes/LowEntryDouble.h" },
		{ "ToolTip", "Returns true if the double is less than the given integer." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULowEntryDouble_LongBytes_LessThan_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULowEntryDouble, "LongBytes_LessThan", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14020401, sizeof(LowEntryDouble_eventLongBytes_LessThan_Parms), Z_Construct_UFunction_ULowEntryDouble_LongBytes_LessThan_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryDouble_LongBytes_LessThan_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULowEntryDouble_LongBytes_LessThan_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryDouble_LongBytes_LessThan_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULowEntryDouble_LongBytes_LessThan()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULowEntryDouble_LongBytes_LessThan_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULowEntryDouble_SetBytes_Statics
	{
		struct LowEntryDouble_eventSetBytes_Parms
		{
			TArray<uint8> ByteArray;
			int32 Index;
			int32 Length;
		};
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_Length;
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_Index;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ByteArray_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_ByteArray;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_ByteArray_Inner;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ULowEntryDouble_SetBytes_Statics::NewProp_Length = { UE4CodeGen_Private::EPropertyClass::Int, "Length", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010040000000080, 1, nullptr, STRUCT_OFFSET(LowEntryDouble_eventSetBytes_Parms, Length), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ULowEntryDouble_SetBytes_Statics::NewProp_Index = { UE4CodeGen_Private::EPropertyClass::Int, "Index", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010040000000080, 1, nullptr, STRUCT_OFFSET(LowEntryDouble_eventSetBytes_Parms, Index), METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryDouble_SetBytes_Statics::NewProp_ByteArray_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_ULowEntryDouble_SetBytes_Statics::NewProp_ByteArray = { UE4CodeGen_Private::EPropertyClass::Array, "ByteArray", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000008000182, 1, nullptr, STRUCT_OFFSET(LowEntryDouble_eventSetBytes_Parms, ByteArray), METADATA_PARAMS(Z_Construct_UFunction_ULowEntryDouble_SetBytes_Statics::NewProp_ByteArray_MetaData, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryDouble_SetBytes_Statics::NewProp_ByteArray_MetaData)) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_ULowEntryDouble_SetBytes_Statics::NewProp_ByteArray_Inner = { UE4CodeGen_Private::EPropertyClass::Byte, "ByteArray", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULowEntryDouble_SetBytes_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryDouble_SetBytes_Statics::NewProp_Length,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryDouble_SetBytes_Statics::NewProp_Index,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryDouble_SetBytes_Statics::NewProp_ByteArray,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryDouble_SetBytes_Statics::NewProp_ByteArray_Inner,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryDouble_SetBytes_Statics::Function_MetaDataParams[] = {
		{ "AdvancedDisplay", "1" },
		{ "Category", "Low Entry|Extended Standard Library|Types|Double (bytes)" },
		{ "CPP_Default_Index", "0" },
		{ "CPP_Default_Length", "2147483647" },
		{ "DisplayName", "Set Bytes" },
		{ "ModuleRelativePath", "Public/ClassesTypes/LowEntryDouble.h" },
		{ "ToolTip", "Sets the bytes (will only add the first 8 bytes, will add 0 bytes if the given byte array was less than 8 bytes)." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULowEntryDouble_SetBytes_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULowEntryDouble, "SetBytes", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04420401, sizeof(LowEntryDouble_eventSetBytes_Parms), Z_Construct_UFunction_ULowEntryDouble_SetBytes_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryDouble_SetBytes_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULowEntryDouble_SetBytes_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryDouble_SetBytes_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULowEntryDouble_SetBytes()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULowEntryDouble_SetBytes_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ULowEntryDouble_NoRegister()
	{
		return ULowEntryDouble::StaticClass();
	}
	struct Z_Construct_UClass_ULowEntryDouble_Statics
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
	UObject* (*const Z_Construct_UClass_ULowEntryDouble_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_LowEntryExtendedStandardLibrary,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ULowEntryDouble_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ULowEntryDouble_CastToLongBytes, "CastToLongBytes" }, // 233560042
		{ &Z_Construct_UFunction_ULowEntryDouble_CastToString, "CastToString" }, // 797031836
		{ &Z_Construct_UFunction_ULowEntryDouble_CreateClone, "CreateClone" }, // 53762375
		{ &Z_Construct_UFunction_ULowEntryDouble_DoubleBytes_Add, "DoubleBytes_Add" }, // 3309361864
		{ &Z_Construct_UFunction_ULowEntryDouble_DoubleBytes_Equals, "DoubleBytes_Equals" }, // 315943558
		{ &Z_Construct_UFunction_ULowEntryDouble_DoubleBytes_GreaterThan, "DoubleBytes_GreaterThan" }, // 4117402312
		{ &Z_Construct_UFunction_ULowEntryDouble_DoubleBytes_LessThan, "DoubleBytes_LessThan" }, // 1064280722
		{ &Z_Construct_UFunction_ULowEntryDouble_DoubleBytes_Subtract, "DoubleBytes_Subtract" }, // 2030058137
		{ &Z_Construct_UFunction_ULowEntryDouble_Float_Add, "Float_Add" }, // 2364599388
		{ &Z_Construct_UFunction_ULowEntryDouble_Float_Equals, "Float_Equals" }, // 1398414479
		{ &Z_Construct_UFunction_ULowEntryDouble_Float_GreaterThan, "Float_GreaterThan" }, // 724914163
		{ &Z_Construct_UFunction_ULowEntryDouble_Float_LessThan, "Float_LessThan" }, // 2853690216
		{ &Z_Construct_UFunction_ULowEntryDouble_Float_Subtract, "Float_Subtract" }, // 580456463
		{ &Z_Construct_UFunction_ULowEntryDouble_GetBytes, "GetBytes" }, // 2909017814
		{ &Z_Construct_UFunction_ULowEntryDouble_Integer_GreaterThan, "Integer_GreaterThan" }, // 2832610152
		{ &Z_Construct_UFunction_ULowEntryDouble_Integer_LessThan, "Integer_LessThan" }, // 2819878617
		{ &Z_Construct_UFunction_ULowEntryDouble_LongBytes_GreaterThan, "LongBytes_GreaterThan" }, // 1397981799
		{ &Z_Construct_UFunction_ULowEntryDouble_LongBytes_LessThan, "LongBytes_LessThan" }, // 2524144190
		{ &Z_Construct_UFunction_ULowEntryDouble_SetBytes, "SetBytes" }, // 2866633767
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULowEntryDouble_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "ClassesTypes/LowEntryDouble.h" },
		{ "ModuleRelativePath", "Public/ClassesTypes/LowEntryDouble.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULowEntryDouble_Statics::NewProp_Bytes_MetaData[] = {
		{ "ModuleRelativePath", "Public/ClassesTypes/LowEntryDouble.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ULowEntryDouble_Statics::NewProp_Bytes = { UE4CodeGen_Private::EPropertyClass::Array, "Bytes", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000000, 1, nullptr, STRUCT_OFFSET(ULowEntryDouble, Bytes), METADATA_PARAMS(Z_Construct_UClass_ULowEntryDouble_Statics::NewProp_Bytes_MetaData, ARRAY_COUNT(Z_Construct_UClass_ULowEntryDouble_Statics::NewProp_Bytes_MetaData)) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UClass_ULowEntryDouble_Statics::NewProp_Bytes_Inner = { UE4CodeGen_Private::EPropertyClass::Byte, "Bytes", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ULowEntryDouble_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULowEntryDouble_Statics::NewProp_Bytes,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULowEntryDouble_Statics::NewProp_Bytes_Inner,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ULowEntryDouble_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ULowEntryDouble>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ULowEntryDouble_Statics::ClassParams = {
		&ULowEntryDouble::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x001000A0u,
		FuncInfo, ARRAY_COUNT(FuncInfo),
		Z_Construct_UClass_ULowEntryDouble_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_ULowEntryDouble_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_ULowEntryDouble_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_ULowEntryDouble_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ULowEntryDouble()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ULowEntryDouble_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ULowEntryDouble, 2582107957);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ULowEntryDouble(Z_Construct_UClass_ULowEntryDouble, &ULowEntryDouble::StaticClass, TEXT("/Script/LowEntryExtendedStandardLibrary"), TEXT("ULowEntryDouble"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ULowEntryDouble);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
