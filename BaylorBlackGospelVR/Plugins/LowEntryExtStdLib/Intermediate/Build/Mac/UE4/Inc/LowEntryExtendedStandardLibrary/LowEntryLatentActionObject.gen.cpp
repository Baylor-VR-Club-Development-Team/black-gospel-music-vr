// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LowEntryExtendedStandardLibrary/Public/ClassesLatentAction/LowEntryLatentActionObject.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeLowEntryLatentActionObject() {}
// Cross Module References
	LOWENTRYEXTENDEDSTANDARDLIBRARY_API UClass* Z_Construct_UClass_ULowEntryLatentActionObject_NoRegister();
	LOWENTRYEXTENDEDSTANDARDLIBRARY_API UClass* Z_Construct_UClass_ULowEntryLatentActionObject();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_LowEntryExtendedStandardLibrary();
	LOWENTRYEXTENDEDSTANDARDLIBRARY_API UFunction* Z_Construct_UFunction_ULowEntryLatentActionObject_Done();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	LOWENTRYEXTENDEDSTANDARDLIBRARY_API UFunction* Z_Construct_UFunction_ULowEntryLatentActionObject_GetResult();
	LOWENTRYEXTENDEDSTANDARDLIBRARY_API UFunction* Z_Construct_UFunction_ULowEntryLatentActionObject_IsDone();
	LOWENTRYEXTENDEDSTANDARDLIBRARY_API UFunction* Z_Construct_UFunction_ULowEntryLatentActionObject_WaitTillDone();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FLatentActionInfo();
// End Cross Module References
	void ULowEntryLatentActionObject::StaticRegisterNativesULowEntryLatentActionObject()
	{
		UClass* Class = ULowEntryLatentActionObject::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "Done", &ULowEntryLatentActionObject::execDone },
			{ "GetResult", &ULowEntryLatentActionObject::execGetResult },
			{ "IsDone", &ULowEntryLatentActionObject::execIsDone },
			{ "WaitTillDone", &ULowEntryLatentActionObject::execWaitTillDone },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ULowEntryLatentActionObject_Done_Statics
	{
		struct LowEntryLatentActionObject_eventDone_Parms
		{
			UObject* Result_;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Result_;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ULowEntryLatentActionObject_Done_Statics::NewProp_Result_ = { UE4CodeGen_Private::EPropertyClass::Object, "Result_", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(LowEntryLatentActionObject_eventDone_Parms, Result_), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULowEntryLatentActionObject_Done_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryLatentActionObject_Done_Statics::NewProp_Result_,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryLatentActionObject_Done_Statics::Function_MetaDataParams[] = {
		{ "Category", "Low Entry|Extended Standard Library|Latent Action|Object" },
		{ "DisplayName", "Done" },
		{ "Keywords", "end finished complete completion" },
		{ "ModuleRelativePath", "Public/ClassesLatentAction/LowEntryLatentActionObject.h" },
		{ "ToolTip", "Causes the latent action to be done." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULowEntryLatentActionObject_Done_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULowEntryLatentActionObject, "Done", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(LowEntryLatentActionObject_eventDone_Parms), Z_Construct_UFunction_ULowEntryLatentActionObject_Done_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryLatentActionObject_Done_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULowEntryLatentActionObject_Done_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryLatentActionObject_Done_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULowEntryLatentActionObject_Done()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULowEntryLatentActionObject_Done_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULowEntryLatentActionObject_GetResult_Statics
	{
		struct LowEntryLatentActionObject_eventGetResult_Parms
		{
			UObject* Result_;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Result_;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ULowEntryLatentActionObject_GetResult_Statics::NewProp_Result_ = { UE4CodeGen_Private::EPropertyClass::Object, "Result_", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000180, 1, nullptr, STRUCT_OFFSET(LowEntryLatentActionObject_eventGetResult_Parms, Result_), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULowEntryLatentActionObject_GetResult_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryLatentActionObject_GetResult_Statics::NewProp_Result_,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryLatentActionObject_GetResult_Statics::Function_MetaDataParams[] = {
		{ "Category", "Low Entry|Extended Standard Library|Latent Action|Object" },
		{ "DisplayName", "Get Result" },
		{ "Keywords", "result return value" },
		{ "ModuleRelativePath", "Public/ClassesLatentAction/LowEntryLatentActionObject.h" },
		{ "ToolTip", "Returns the result." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULowEntryLatentActionObject_GetResult_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULowEntryLatentActionObject, "GetResult", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14420401, sizeof(LowEntryLatentActionObject_eventGetResult_Parms), Z_Construct_UFunction_ULowEntryLatentActionObject_GetResult_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryLatentActionObject_GetResult_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULowEntryLatentActionObject_GetResult_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryLatentActionObject_GetResult_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULowEntryLatentActionObject_GetResult()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULowEntryLatentActionObject_GetResult_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULowEntryLatentActionObject_IsDone_Statics
	{
		struct LowEntryLatentActionObject_eventIsDone_Parms
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
	void Z_Construct_UFunction_ULowEntryLatentActionObject_IsDone_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((LowEntryLatentActionObject_eventIsDone_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ULowEntryLatentActionObject_IsDone_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Bool, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(LowEntryLatentActionObject_eventIsDone_Parms), &Z_Construct_UFunction_ULowEntryLatentActionObject_IsDone_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULowEntryLatentActionObject_IsDone_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryLatentActionObject_IsDone_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryLatentActionObject_IsDone_Statics::Function_MetaDataParams[] = {
		{ "Category", "Low Entry|Extended Standard Library|Latent Action|Object" },
		{ "DisplayName", "Is Done" },
		{ "Keywords", "end finished complete completion" },
		{ "ModuleRelativePath", "Public/ClassesLatentAction/LowEntryLatentActionObject.h" },
		{ "ToolTip", "Returns true if the latent action is done." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULowEntryLatentActionObject_IsDone_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULowEntryLatentActionObject, "IsDone", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14020401, sizeof(LowEntryLatentActionObject_eventIsDone_Parms), Z_Construct_UFunction_ULowEntryLatentActionObject_IsDone_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryLatentActionObject_IsDone_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULowEntryLatentActionObject_IsDone_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryLatentActionObject_IsDone_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULowEntryLatentActionObject_IsDone()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULowEntryLatentActionObject_IsDone_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULowEntryLatentActionObject_WaitTillDone_Statics
	{
		struct LowEntryLatentActionObject_eventWaitTillDone_Parms
		{
			UObject* WorldContextObject;
			FLatentActionInfo LatentInfo;
			UObject* Result_;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Result_;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_LatentInfo;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ULowEntryLatentActionObject_WaitTillDone_Statics::NewProp_Result_ = { UE4CodeGen_Private::EPropertyClass::Object, "Result_", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000180, 1, nullptr, STRUCT_OFFSET(LowEntryLatentActionObject_eventWaitTillDone_Parms, Result_), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ULowEntryLatentActionObject_WaitTillDone_Statics::NewProp_LatentInfo = { UE4CodeGen_Private::EPropertyClass::Struct, "LatentInfo", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(LowEntryLatentActionObject_eventWaitTillDone_Parms, LatentInfo), Z_Construct_UScriptStruct_FLatentActionInfo, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ULowEntryLatentActionObject_WaitTillDone_Statics::NewProp_WorldContextObject = { UE4CodeGen_Private::EPropertyClass::Object, "WorldContextObject", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(LowEntryLatentActionObject_eventWaitTillDone_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULowEntryLatentActionObject_WaitTillDone_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryLatentActionObject_WaitTillDone_Statics::NewProp_Result_,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryLatentActionObject_WaitTillDone_Statics::NewProp_LatentInfo,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryLatentActionObject_WaitTillDone_Statics::NewProp_WorldContextObject,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryLatentActionObject_WaitTillDone_Statics::Function_MetaDataParams[] = {
		{ "Category", "Low Entry|Extended Standard Library|Latent Action|Object" },
		{ "DisplayName", "Wait Till Done" },
		{ "Keywords", "untill for end finished complete completion" },
		{ "Latent", "" },
		{ "LatentInfo", "LatentInfo" },
		{ "ModuleRelativePath", "Public/ClassesLatentAction/LowEntryLatentActionObject.h" },
		{ "ToolTip", "Waits till the latent action is done." },
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULowEntryLatentActionObject_WaitTillDone_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULowEntryLatentActionObject, "WaitTillDone", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04420401, sizeof(LowEntryLatentActionObject_eventWaitTillDone_Parms), Z_Construct_UFunction_ULowEntryLatentActionObject_WaitTillDone_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryLatentActionObject_WaitTillDone_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULowEntryLatentActionObject_WaitTillDone_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryLatentActionObject_WaitTillDone_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULowEntryLatentActionObject_WaitTillDone()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULowEntryLatentActionObject_WaitTillDone_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ULowEntryLatentActionObject_NoRegister()
	{
		return ULowEntryLatentActionObject::StaticClass();
	}
	struct Z_Construct_UClass_ULowEntryLatentActionObject_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_KeepAliveCount_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_KeepAliveCount;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Result_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Result;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Finished_MetaData[];
#endif
		static void NewProp_Finished_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_Finished;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ULowEntryLatentActionObject_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_LowEntryExtendedStandardLibrary,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ULowEntryLatentActionObject_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ULowEntryLatentActionObject_Done, "Done" }, // 1732314305
		{ &Z_Construct_UFunction_ULowEntryLatentActionObject_GetResult, "GetResult" }, // 3538448562
		{ &Z_Construct_UFunction_ULowEntryLatentActionObject_IsDone, "IsDone" }, // 202406248
		{ &Z_Construct_UFunction_ULowEntryLatentActionObject_WaitTillDone, "WaitTillDone" }, // 3018568167
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULowEntryLatentActionObject_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "ClassesLatentAction/LowEntryLatentActionObject.h" },
		{ "ModuleRelativePath", "Public/ClassesLatentAction/LowEntryLatentActionObject.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULowEntryLatentActionObject_Statics::NewProp_KeepAliveCount_MetaData[] = {
		{ "ModuleRelativePath", "Public/ClassesLatentAction/LowEntryLatentActionObject.h" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_ULowEntryLatentActionObject_Statics::NewProp_KeepAliveCount = { UE4CodeGen_Private::EPropertyClass::Int, "KeepAliveCount", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000000, 1, nullptr, STRUCT_OFFSET(ULowEntryLatentActionObject, KeepAliveCount), METADATA_PARAMS(Z_Construct_UClass_ULowEntryLatentActionObject_Statics::NewProp_KeepAliveCount_MetaData, ARRAY_COUNT(Z_Construct_UClass_ULowEntryLatentActionObject_Statics::NewProp_KeepAliveCount_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULowEntryLatentActionObject_Statics::NewProp_Result_MetaData[] = {
		{ "ModuleRelativePath", "Public/ClassesLatentAction/LowEntryLatentActionObject.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ULowEntryLatentActionObject_Statics::NewProp_Result = { UE4CodeGen_Private::EPropertyClass::Object, "Result", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000000, 1, nullptr, STRUCT_OFFSET(ULowEntryLatentActionObject, Result), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ULowEntryLatentActionObject_Statics::NewProp_Result_MetaData, ARRAY_COUNT(Z_Construct_UClass_ULowEntryLatentActionObject_Statics::NewProp_Result_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULowEntryLatentActionObject_Statics::NewProp_Finished_MetaData[] = {
		{ "ModuleRelativePath", "Public/ClassesLatentAction/LowEntryLatentActionObject.h" },
	};
#endif
	void Z_Construct_UClass_ULowEntryLatentActionObject_Statics::NewProp_Finished_SetBit(void* Obj)
	{
		((ULowEntryLatentActionObject*)Obj)->Finished = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ULowEntryLatentActionObject_Statics::NewProp_Finished = { UE4CodeGen_Private::EPropertyClass::Bool, "Finished", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000000, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(ULowEntryLatentActionObject), &Z_Construct_UClass_ULowEntryLatentActionObject_Statics::NewProp_Finished_SetBit, METADATA_PARAMS(Z_Construct_UClass_ULowEntryLatentActionObject_Statics::NewProp_Finished_MetaData, ARRAY_COUNT(Z_Construct_UClass_ULowEntryLatentActionObject_Statics::NewProp_Finished_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ULowEntryLatentActionObject_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULowEntryLatentActionObject_Statics::NewProp_KeepAliveCount,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULowEntryLatentActionObject_Statics::NewProp_Result,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULowEntryLatentActionObject_Statics::NewProp_Finished,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ULowEntryLatentActionObject_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ULowEntryLatentActionObject>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ULowEntryLatentActionObject_Statics::ClassParams = {
		&ULowEntryLatentActionObject::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x001000A0u,
		FuncInfo, ARRAY_COUNT(FuncInfo),
		Z_Construct_UClass_ULowEntryLatentActionObject_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_ULowEntryLatentActionObject_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_ULowEntryLatentActionObject_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_ULowEntryLatentActionObject_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ULowEntryLatentActionObject()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ULowEntryLatentActionObject_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ULowEntryLatentActionObject, 1789827619);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ULowEntryLatentActionObject(Z_Construct_UClass_ULowEntryLatentActionObject, &ULowEntryLatentActionObject::StaticClass, TEXT("/Script/LowEntryExtendedStandardLibrary"), TEXT("ULowEntryLatentActionObject"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ULowEntryLatentActionObject);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
