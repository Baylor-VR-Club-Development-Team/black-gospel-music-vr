// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "HammUErRuntime/Public/HammUErRuntimeClasses.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeHammUErRuntimeClasses() {}
// Cross Module References
	HAMMUERRUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FHammuerOutput();
	UPackage* Z_Construct_UPackage__Script_HammUErRuntime();
	HAMMUERRUNTIME_API UClass* Z_Construct_UClass_AHammuerLogicActorBase_NoRegister();
	HAMMUERRUNTIME_API UClass* Z_Construct_UClass_AHammuerLogicActorBase();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	HAMMUERRUNTIME_API UFunction* Z_Construct_UFunction_AHammuerLogicActorBase_DoExecute();
	HAMMUERRUNTIME_API UFunction* Z_Construct_UFunction_AHammuerLogicActorBase_ExecuteAll();
	HAMMUERRUNTIME_API UFunction* Z_Construct_UFunction_AHammuerLogicActorBase_ExecuteOutput();
	HAMMUERRUNTIME_API UFunction* Z_Construct_UFunction_AHammuerLogicActorBase_FindTargetEntities();
	HAMMUERRUNTIME_API UFunction* Z_Construct_UFunction_AHammuerLogicActorBase_GetFriendlyName();
	HAMMUERRUNTIME_API UClass* Z_Construct_UClass_UHammuerLogicInterface_NoRegister();
	HAMMUERRUNTIME_API UClass* Z_Construct_UClass_AHammuerLogicAuto_NoRegister();
	HAMMUERRUNTIME_API UClass* Z_Construct_UClass_AHammuerLogicAuto();
	HAMMUERRUNTIME_API UClass* Z_Construct_UClass_AHammuerLogicRelay_NoRegister();
	HAMMUERRUNTIME_API UClass* Z_Construct_UClass_AHammuerLogicRelay();
	HAMMUERRUNTIME_API UFunction* Z_Construct_UFunction_AHammuerLogicRelay_Disable();
	HAMMUERRUNTIME_API UFunction* Z_Construct_UFunction_AHammuerLogicRelay_Enable();
	HAMMUERRUNTIME_API UFunction* Z_Construct_UFunction_AHammuerLogicRelay_Trigger();
	HAMMUERRUNTIME_API UClass* Z_Construct_UClass_AHammuerFuncBrushActor_NoRegister();
	HAMMUERRUNTIME_API UClass* Z_Construct_UClass_AHammuerFuncBrushActor();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
// End Cross Module References
class UScriptStruct* FHammuerOutput::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern HAMMUERRUNTIME_API uint32 Get_Z_Construct_UScriptStruct_FHammuerOutput_CRC();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FHammuerOutput, Z_Construct_UPackage__Script_HammUErRuntime(), TEXT("HammuerOutput"), sizeof(FHammuerOutput), Get_Z_Construct_UScriptStruct_FHammuerOutput_CRC());
	}
	return Singleton;
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FHammuerOutput(FHammuerOutput::StaticStruct, TEXT("/Script/HammUErRuntime"), TEXT("HammuerOutput"), false, nullptr, nullptr);
static struct FScriptStruct_HammUErRuntime_StaticRegisterNativesFHammuerOutput
{
	FScriptStruct_HammUErRuntime_StaticRegisterNativesFHammuerOutput()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("HammuerOutput")),new UScriptStruct::TCppStructOps<FHammuerOutput>);
	}
} ScriptStruct_HammUErRuntime_StaticRegisterNativesFHammuerOutput;
	struct Z_Construct_UScriptStruct_FHammuerOutput_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_onlyOnce_MetaData[];
#endif
		static void NewProp_onlyOnce_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_onlyOnce;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_delay_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_delay;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_parameter_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_parameter;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_targetInput_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_targetInput;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_targetEntity_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_targetEntity;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_outputName_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_outputName;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FHammuerOutput_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/HammUErRuntimeClasses.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FHammuerOutput_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FHammuerOutput>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FHammuerOutput_Statics::NewProp_onlyOnce_MetaData[] = {
		{ "Category", "HammUEr" },
		{ "ModuleRelativePath", "Public/HammUErRuntimeClasses.h" },
	};
#endif
	void Z_Construct_UScriptStruct_FHammuerOutput_Statics::NewProp_onlyOnce_SetBit(void* Obj)
	{
		((FHammuerOutput*)Obj)->onlyOnce = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FHammuerOutput_Statics::NewProp_onlyOnce = { UE4CodeGen_Private::EPropertyClass::Bool, "onlyOnce", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(FHammuerOutput), &Z_Construct_UScriptStruct_FHammuerOutput_Statics::NewProp_onlyOnce_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FHammuerOutput_Statics::NewProp_onlyOnce_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FHammuerOutput_Statics::NewProp_onlyOnce_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FHammuerOutput_Statics::NewProp_delay_MetaData[] = {
		{ "Category", "HammUEr" },
		{ "ModuleRelativePath", "Public/HammUErRuntimeClasses.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FHammuerOutput_Statics::NewProp_delay = { UE4CodeGen_Private::EPropertyClass::Float, "delay", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FHammuerOutput, delay), METADATA_PARAMS(Z_Construct_UScriptStruct_FHammuerOutput_Statics::NewProp_delay_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FHammuerOutput_Statics::NewProp_delay_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FHammuerOutput_Statics::NewProp_parameter_MetaData[] = {
		{ "Category", "HammUEr" },
		{ "ModuleRelativePath", "Public/HammUErRuntimeClasses.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FHammuerOutput_Statics::NewProp_parameter = { UE4CodeGen_Private::EPropertyClass::Str, "parameter", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FHammuerOutput, parameter), METADATA_PARAMS(Z_Construct_UScriptStruct_FHammuerOutput_Statics::NewProp_parameter_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FHammuerOutput_Statics::NewProp_parameter_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FHammuerOutput_Statics::NewProp_targetInput_MetaData[] = {
		{ "Category", "HammUEr" },
		{ "ModuleRelativePath", "Public/HammUErRuntimeClasses.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FHammuerOutput_Statics::NewProp_targetInput = { UE4CodeGen_Private::EPropertyClass::Str, "targetInput", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FHammuerOutput, targetInput), METADATA_PARAMS(Z_Construct_UScriptStruct_FHammuerOutput_Statics::NewProp_targetInput_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FHammuerOutput_Statics::NewProp_targetInput_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FHammuerOutput_Statics::NewProp_targetEntity_MetaData[] = {
		{ "Category", "HammUEr" },
		{ "ModuleRelativePath", "Public/HammUErRuntimeClasses.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FHammuerOutput_Statics::NewProp_targetEntity = { UE4CodeGen_Private::EPropertyClass::Str, "targetEntity", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FHammuerOutput, targetEntity), METADATA_PARAMS(Z_Construct_UScriptStruct_FHammuerOutput_Statics::NewProp_targetEntity_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FHammuerOutput_Statics::NewProp_targetEntity_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FHammuerOutput_Statics::NewProp_outputName_MetaData[] = {
		{ "Category", "HammUEr" },
		{ "ModuleRelativePath", "Public/HammUErRuntimeClasses.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FHammuerOutput_Statics::NewProp_outputName = { UE4CodeGen_Private::EPropertyClass::Str, "outputName", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FHammuerOutput, outputName), METADATA_PARAMS(Z_Construct_UScriptStruct_FHammuerOutput_Statics::NewProp_outputName_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FHammuerOutput_Statics::NewProp_outputName_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FHammuerOutput_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHammuerOutput_Statics::NewProp_onlyOnce,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHammuerOutput_Statics::NewProp_delay,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHammuerOutput_Statics::NewProp_parameter,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHammuerOutput_Statics::NewProp_targetInput,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHammuerOutput_Statics::NewProp_targetEntity,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHammuerOutput_Statics::NewProp_outputName,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FHammuerOutput_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_HammUErRuntime,
		nullptr,
		&NewStructOps,
		"HammuerOutput",
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		sizeof(FHammuerOutput),
		alignof(FHammuerOutput),
		Z_Construct_UScriptStruct_FHammuerOutput_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UScriptStruct_FHammuerOutput_Statics::PropPointers),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FHammuerOutput_Statics::Struct_MetaDataParams, ARRAY_COUNT(Z_Construct_UScriptStruct_FHammuerOutput_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FHammuerOutput()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FHammuerOutput_CRC();
		UPackage* Outer = Z_Construct_UPackage__Script_HammUErRuntime();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("HammuerOutput"), sizeof(FHammuerOutput), Get_Z_Construct_UScriptStruct_FHammuerOutput_CRC(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FHammuerOutput_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FHammuerOutput_CRC() { return 1013353341U; }
	static FName NAME_AHammuerLogicActorBase_DoExecute = FName(TEXT("DoExecute"));
	void AHammuerLogicActorBase::DoExecute(AHammuerLogicActorBase* myTarget, int32 index)
	{
		HammuerLogicActorBase_eventDoExecute_Parms Parms;
		Parms.myTarget=myTarget;
		Parms.index=index;
		ProcessEvent(FindFunctionChecked(NAME_AHammuerLogicActorBase_DoExecute),&Parms);
	}
	void AHammuerLogicActorBase::StaticRegisterNativesAHammuerLogicActorBase()
	{
		UClass* Class = AHammuerLogicActorBase::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "DoExecute", &AHammuerLogicActorBase::execDoExecute },
			{ "ExecuteAll", &AHammuerLogicActorBase::execExecuteAll },
			{ "ExecuteOutput", &AHammuerLogicActorBase::execExecuteOutput },
			{ "FindTargetEntities", &AHammuerLogicActorBase::execFindTargetEntities },
			{ "GetFriendlyName", &AHammuerLogicActorBase::execGetFriendlyName },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AHammuerLogicActorBase_DoExecute_Statics
	{
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_index;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_myTarget;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_AHammuerLogicActorBase_DoExecute_Statics::NewProp_index = { UE4CodeGen_Private::EPropertyClass::Int, "index", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(HammuerLogicActorBase_eventDoExecute_Parms, index), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AHammuerLogicActorBase_DoExecute_Statics::NewProp_myTarget = { UE4CodeGen_Private::EPropertyClass::Object, "myTarget", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(HammuerLogicActorBase_eventDoExecute_Parms, myTarget), Z_Construct_UClass_AHammuerLogicActorBase_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AHammuerLogicActorBase_DoExecute_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AHammuerLogicActorBase_DoExecute_Statics::NewProp_index,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AHammuerLogicActorBase_DoExecute_Statics::NewProp_myTarget,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AHammuerLogicActorBase_DoExecute_Statics::Function_MetaDataParams[] = {
		{ "Category", "HammUEr Logic" },
		{ "ModuleRelativePath", "Public/HammUErRuntimeClasses.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AHammuerLogicActorBase_DoExecute_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AHammuerLogicActorBase, "DoExecute", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x0C020C00, sizeof(HammuerLogicActorBase_eventDoExecute_Parms), Z_Construct_UFunction_AHammuerLogicActorBase_DoExecute_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AHammuerLogicActorBase_DoExecute_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AHammuerLogicActorBase_DoExecute_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AHammuerLogicActorBase_DoExecute_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AHammuerLogicActorBase_DoExecute()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AHammuerLogicActorBase_DoExecute_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AHammuerLogicActorBase_ExecuteAll_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AHammuerLogicActorBase_ExecuteAll_Statics::Function_MetaDataParams[] = {
		{ "Category", "HammUEr Logic" },
		{ "ModuleRelativePath", "Public/HammUErRuntimeClasses.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AHammuerLogicActorBase_ExecuteAll_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AHammuerLogicActorBase, "ExecuteAll", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AHammuerLogicActorBase_ExecuteAll_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AHammuerLogicActorBase_ExecuteAll_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AHammuerLogicActorBase_ExecuteAll()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AHammuerLogicActorBase_ExecuteAll_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AHammuerLogicActorBase_ExecuteOutput_Statics
	{
		struct HammuerLogicActorBase_eventExecuteOutput_Parms
		{
			int32 index;
		};
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_index;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_AHammuerLogicActorBase_ExecuteOutput_Statics::NewProp_index = { UE4CodeGen_Private::EPropertyClass::Int, "index", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(HammuerLogicActorBase_eventExecuteOutput_Parms, index), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AHammuerLogicActorBase_ExecuteOutput_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AHammuerLogicActorBase_ExecuteOutput_Statics::NewProp_index,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AHammuerLogicActorBase_ExecuteOutput_Statics::Function_MetaDataParams[] = {
		{ "Category", "HammUEr Logic" },
		{ "ModuleRelativePath", "Public/HammUErRuntimeClasses.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AHammuerLogicActorBase_ExecuteOutput_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AHammuerLogicActorBase, "ExecuteOutput", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(HammuerLogicActorBase_eventExecuteOutput_Parms), Z_Construct_UFunction_AHammuerLogicActorBase_ExecuteOutput_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AHammuerLogicActorBase_ExecuteOutput_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AHammuerLogicActorBase_ExecuteOutput_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AHammuerLogicActorBase_ExecuteOutput_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AHammuerLogicActorBase_ExecuteOutput()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AHammuerLogicActorBase_ExecuteOutput_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AHammuerLogicActorBase_FindTargetEntities_Statics
	{
		struct HammuerLogicActorBase_eventFindTargetEntities_Parms
		{
			FHammuerOutput inputOutput;
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_inputOutput;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_AHammuerLogicActorBase_FindTargetEntities_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((HammuerLogicActorBase_eventFindTargetEntities_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AHammuerLogicActorBase_FindTargetEntities_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Bool, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(HammuerLogicActorBase_eventFindTargetEntities_Parms), &Z_Construct_UFunction_AHammuerLogicActorBase_FindTargetEntities_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AHammuerLogicActorBase_FindTargetEntities_Statics::NewProp_inputOutput = { UE4CodeGen_Private::EPropertyClass::Struct, "inputOutput", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(HammuerLogicActorBase_eventFindTargetEntities_Parms, inputOutput), Z_Construct_UScriptStruct_FHammuerOutput, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AHammuerLogicActorBase_FindTargetEntities_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AHammuerLogicActorBase_FindTargetEntities_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AHammuerLogicActorBase_FindTargetEntities_Statics::NewProp_inputOutput,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AHammuerLogicActorBase_FindTargetEntities_Statics::Function_MetaDataParams[] = {
		{ "Category", "HammUEr Logic" },
		{ "ModuleRelativePath", "Public/HammUErRuntimeClasses.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AHammuerLogicActorBase_FindTargetEntities_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AHammuerLogicActorBase, "FindTargetEntities", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(HammuerLogicActorBase_eventFindTargetEntities_Parms), Z_Construct_UFunction_AHammuerLogicActorBase_FindTargetEntities_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AHammuerLogicActorBase_FindTargetEntities_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AHammuerLogicActorBase_FindTargetEntities_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AHammuerLogicActorBase_FindTargetEntities_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AHammuerLogicActorBase_FindTargetEntities()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AHammuerLogicActorBase_FindTargetEntities_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AHammuerLogicActorBase_GetFriendlyName_Statics
	{
		struct HammuerLogicActorBase_eventGetFriendlyName_Parms
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
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AHammuerLogicActorBase_GetFriendlyName_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Str, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(HammuerLogicActorBase_eventGetFriendlyName_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AHammuerLogicActorBase_GetFriendlyName_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AHammuerLogicActorBase_GetFriendlyName_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AHammuerLogicActorBase_GetFriendlyName_Statics::Function_MetaDataParams[] = {
		{ "Category", "HammUEr Logic" },
		{ "ModuleRelativePath", "Public/HammUErRuntimeClasses.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AHammuerLogicActorBase_GetFriendlyName_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AHammuerLogicActorBase, "GetFriendlyName", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(HammuerLogicActorBase_eventGetFriendlyName_Parms), Z_Construct_UFunction_AHammuerLogicActorBase_GetFriendlyName_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AHammuerLogicActorBase_GetFriendlyName_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AHammuerLogicActorBase_GetFriendlyName_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AHammuerLogicActorBase_GetFriendlyName_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AHammuerLogicActorBase_GetFriendlyName()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AHammuerLogicActorBase_GetFriendlyName_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AHammuerLogicActorBase_NoRegister()
	{
		return AHammuerLogicActorBase::StaticClass();
	}
	struct Z_Construct_UClass_AHammuerLogicActorBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_friendlyName_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_friendlyName;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_doVerbose_MetaData[];
#endif
		static void NewProp_doVerbose_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_doVerbose;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_myOutputs_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_myOutputs;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_myOutputs_Inner;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AHammuerLogicActorBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_HammUErRuntime,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AHammuerLogicActorBase_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AHammuerLogicActorBase_DoExecute, "DoExecute" }, // 3065087870
		{ &Z_Construct_UFunction_AHammuerLogicActorBase_ExecuteAll, "ExecuteAll" }, // 2453163096
		{ &Z_Construct_UFunction_AHammuerLogicActorBase_ExecuteOutput, "ExecuteOutput" }, // 1115402950
		{ &Z_Construct_UFunction_AHammuerLogicActorBase_FindTargetEntities, "FindTargetEntities" }, // 1147626268
		{ &Z_Construct_UFunction_AHammuerLogicActorBase_GetFriendlyName, "GetFriendlyName" }, // 3504171197
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHammuerLogicActorBase_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "HammUErRuntimeClasses.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/HammUErRuntimeClasses.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHammuerLogicActorBase_Statics::NewProp_friendlyName_MetaData[] = {
		{ "Category", "HammUEr" },
		{ "ModuleRelativePath", "Public/HammUErRuntimeClasses.h" },
		{ "ToolTip", "moved this here because if I kept it just in the private part, UE would reset everything to unnamed?" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_AHammuerLogicActorBase_Statics::NewProp_friendlyName = { UE4CodeGen_Private::EPropertyClass::Str, "friendlyName", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000014, 1, nullptr, STRUCT_OFFSET(AHammuerLogicActorBase, friendlyName), METADATA_PARAMS(Z_Construct_UClass_AHammuerLogicActorBase_Statics::NewProp_friendlyName_MetaData, ARRAY_COUNT(Z_Construct_UClass_AHammuerLogicActorBase_Statics::NewProp_friendlyName_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHammuerLogicActorBase_Statics::NewProp_doVerbose_MetaData[] = {
		{ "Category", "HammUEr" },
		{ "ModuleRelativePath", "Public/HammUErRuntimeClasses.h" },
	};
#endif
	void Z_Construct_UClass_AHammuerLogicActorBase_Statics::NewProp_doVerbose_SetBit(void* Obj)
	{
		((AHammuerLogicActorBase*)Obj)->doVerbose = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AHammuerLogicActorBase_Statics::NewProp_doVerbose = { UE4CodeGen_Private::EPropertyClass::Bool, "doVerbose", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(AHammuerLogicActorBase), &Z_Construct_UClass_AHammuerLogicActorBase_Statics::NewProp_doVerbose_SetBit, METADATA_PARAMS(Z_Construct_UClass_AHammuerLogicActorBase_Statics::NewProp_doVerbose_MetaData, ARRAY_COUNT(Z_Construct_UClass_AHammuerLogicActorBase_Statics::NewProp_doVerbose_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHammuerLogicActorBase_Statics::NewProp_myOutputs_MetaData[] = {
		{ "Category", "HammUEr" },
		{ "ModuleRelativePath", "Public/HammUErRuntimeClasses.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AHammuerLogicActorBase_Statics::NewProp_myOutputs = { UE4CodeGen_Private::EPropertyClass::Array, "myOutputs", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AHammuerLogicActorBase, myOutputs), METADATA_PARAMS(Z_Construct_UClass_AHammuerLogicActorBase_Statics::NewProp_myOutputs_MetaData, ARRAY_COUNT(Z_Construct_UClass_AHammuerLogicActorBase_Statics::NewProp_myOutputs_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_AHammuerLogicActorBase_Statics::NewProp_myOutputs_Inner = { UE4CodeGen_Private::EPropertyClass::Struct, "myOutputs", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, Z_Construct_UScriptStruct_FHammuerOutput, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AHammuerLogicActorBase_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHammuerLogicActorBase_Statics::NewProp_friendlyName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHammuerLogicActorBase_Statics::NewProp_doVerbose,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHammuerLogicActorBase_Statics::NewProp_myOutputs,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHammuerLogicActorBase_Statics::NewProp_myOutputs_Inner,
	};
		const UE4CodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_AHammuerLogicActorBase_Statics::InterfaceParams[] = {
			{ Z_Construct_UClass_UHammuerLogicInterface_NoRegister, (int32)VTABLE_OFFSET(AHammuerLogicActorBase, IHammuerLogicInterface), false },
		};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AHammuerLogicActorBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AHammuerLogicActorBase>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AHammuerLogicActorBase_Statics::ClassParams = {
		&AHammuerLogicActorBase::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x009000A0u,
		FuncInfo, ARRAY_COUNT(FuncInfo),
		Z_Construct_UClass_AHammuerLogicActorBase_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_AHammuerLogicActorBase_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		InterfaceParams, ARRAY_COUNT(InterfaceParams),
		METADATA_PARAMS(Z_Construct_UClass_AHammuerLogicActorBase_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AHammuerLogicActorBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AHammuerLogicActorBase()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AHammuerLogicActorBase_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AHammuerLogicActorBase, 1909829540);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AHammuerLogicActorBase(Z_Construct_UClass_AHammuerLogicActorBase, &AHammuerLogicActorBase::StaticClass, TEXT("/Script/HammUErRuntime"), TEXT("AHammuerLogicActorBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AHammuerLogicActorBase);
	void AHammuerLogicAuto::StaticRegisterNativesAHammuerLogicAuto()
	{
	}
	UClass* Z_Construct_UClass_AHammuerLogicAuto_NoRegister()
	{
		return AHammuerLogicAuto::StaticClass();
	}
	struct Z_Construct_UClass_AHammuerLogicAuto_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AHammuerLogicAuto_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AHammuerLogicActorBase,
		(UObject* (*)())Z_Construct_UPackage__Script_HammUErRuntime,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHammuerLogicAuto_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "HammUErRuntimeClasses.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/HammUErRuntimeClasses.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AHammuerLogicAuto_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AHammuerLogicAuto>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AHammuerLogicAuto_Statics::ClassParams = {
		&AHammuerLogicAuto::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x009000A0u,
		nullptr, 0,
		nullptr, 0,
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_AHammuerLogicAuto_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AHammuerLogicAuto_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AHammuerLogicAuto()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AHammuerLogicAuto_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AHammuerLogicAuto, 3125157616);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AHammuerLogicAuto(Z_Construct_UClass_AHammuerLogicAuto, &AHammuerLogicAuto::StaticClass, TEXT("/Script/HammUErRuntime"), TEXT("AHammuerLogicAuto"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AHammuerLogicAuto);
	static FName NAME_AHammuerLogicRelay_Trigger = FName(TEXT("Trigger"));
	void AHammuerLogicRelay::Trigger()
	{
		ProcessEvent(FindFunctionChecked(NAME_AHammuerLogicRelay_Trigger),NULL);
	}
	void AHammuerLogicRelay::StaticRegisterNativesAHammuerLogicRelay()
	{
		UClass* Class = AHammuerLogicRelay::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "Disable", &AHammuerLogicRelay::execDisable },
			{ "Enable", &AHammuerLogicRelay::execEnable },
			{ "Trigger", &AHammuerLogicRelay::execTrigger },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AHammuerLogicRelay_Disable_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AHammuerLogicRelay_Disable_Statics::Function_MetaDataParams[] = {
		{ "Category", "HammUEr Logic" },
		{ "ModuleRelativePath", "Public/HammUErRuntimeClasses.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AHammuerLogicRelay_Disable_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AHammuerLogicRelay, "Disable", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AHammuerLogicRelay_Disable_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AHammuerLogicRelay_Disable_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AHammuerLogicRelay_Disable()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AHammuerLogicRelay_Disable_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AHammuerLogicRelay_Enable_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AHammuerLogicRelay_Enable_Statics::Function_MetaDataParams[] = {
		{ "Category", "HammUEr Logic" },
		{ "ModuleRelativePath", "Public/HammUErRuntimeClasses.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AHammuerLogicRelay_Enable_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AHammuerLogicRelay, "Enable", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AHammuerLogicRelay_Enable_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AHammuerLogicRelay_Enable_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AHammuerLogicRelay_Enable()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AHammuerLogicRelay_Enable_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AHammuerLogicRelay_Trigger_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AHammuerLogicRelay_Trigger_Statics::Function_MetaDataParams[] = {
		{ "Category", "HammUEr Logic" },
		{ "ModuleRelativePath", "Public/HammUErRuntimeClasses.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AHammuerLogicRelay_Trigger_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AHammuerLogicRelay, "Trigger", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x0C020C00, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AHammuerLogicRelay_Trigger_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AHammuerLogicRelay_Trigger_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AHammuerLogicRelay_Trigger()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AHammuerLogicRelay_Trigger_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AHammuerLogicRelay_NoRegister()
	{
		return AHammuerLogicRelay::StaticClass();
	}
	struct Z_Construct_UClass_AHammuerLogicRelay_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_isDisabled_MetaData[];
#endif
		static void NewProp_isDisabled_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_isDisabled;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AHammuerLogicRelay_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AHammuerLogicActorBase,
		(UObject* (*)())Z_Construct_UPackage__Script_HammUErRuntime,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AHammuerLogicRelay_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AHammuerLogicRelay_Disable, "Disable" }, // 2259951299
		{ &Z_Construct_UFunction_AHammuerLogicRelay_Enable, "Enable" }, // 952246230
		{ &Z_Construct_UFunction_AHammuerLogicRelay_Trigger, "Trigger" }, // 485746086
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHammuerLogicRelay_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "HammUErRuntimeClasses.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/HammUErRuntimeClasses.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHammuerLogicRelay_Statics::NewProp_isDisabled_MetaData[] = {
		{ "Category", "HammUEr" },
		{ "ModuleRelativePath", "Public/HammUErRuntimeClasses.h" },
	};
#endif
	void Z_Construct_UClass_AHammuerLogicRelay_Statics::NewProp_isDisabled_SetBit(void* Obj)
	{
		((AHammuerLogicRelay*)Obj)->isDisabled = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AHammuerLogicRelay_Statics::NewProp_isDisabled = { UE4CodeGen_Private::EPropertyClass::Bool, "isDisabled", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(AHammuerLogicRelay), &Z_Construct_UClass_AHammuerLogicRelay_Statics::NewProp_isDisabled_SetBit, METADATA_PARAMS(Z_Construct_UClass_AHammuerLogicRelay_Statics::NewProp_isDisabled_MetaData, ARRAY_COUNT(Z_Construct_UClass_AHammuerLogicRelay_Statics::NewProp_isDisabled_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AHammuerLogicRelay_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHammuerLogicRelay_Statics::NewProp_isDisabled,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AHammuerLogicRelay_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AHammuerLogicRelay>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AHammuerLogicRelay_Statics::ClassParams = {
		&AHammuerLogicRelay::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x009000A0u,
		FuncInfo, ARRAY_COUNT(FuncInfo),
		Z_Construct_UClass_AHammuerLogicRelay_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_AHammuerLogicRelay_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_AHammuerLogicRelay_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AHammuerLogicRelay_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AHammuerLogicRelay()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AHammuerLogicRelay_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AHammuerLogicRelay, 725099901);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AHammuerLogicRelay(Z_Construct_UClass_AHammuerLogicRelay, &AHammuerLogicRelay::StaticClass, TEXT("/Script/HammUErRuntime"), TEXT("AHammuerLogicRelay"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AHammuerLogicRelay);
	void AHammuerFuncBrushActor::StaticRegisterNativesAHammuerFuncBrushActor()
	{
	}
	UClass* Z_Construct_UClass_AHammuerFuncBrushActor_NoRegister()
	{
		return AHammuerFuncBrushActor::StaticClass();
	}
	struct Z_Construct_UClass_AHammuerFuncBrushActor_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_myStaticMeshComponent_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_myStaticMeshComponent;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AHammuerFuncBrushActor_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AHammuerLogicActorBase,
		(UObject* (*)())Z_Construct_UPackage__Script_HammUErRuntime,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHammuerFuncBrushActor_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "HammUErRuntimeClasses.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/HammUErRuntimeClasses.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHammuerFuncBrushActor_Statics::NewProp_myStaticMeshComponent_MetaData[] = {
		{ "Category", "HammuerFuncBrushActor" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/HammUErRuntimeClasses.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AHammuerFuncBrushActor_Statics::NewProp_myStaticMeshComponent = { UE4CodeGen_Private::EPropertyClass::Object, "myStaticMeshComponent", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x00100000000a000d, 1, nullptr, STRUCT_OFFSET(AHammuerFuncBrushActor, myStaticMeshComponent), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AHammuerFuncBrushActor_Statics::NewProp_myStaticMeshComponent_MetaData, ARRAY_COUNT(Z_Construct_UClass_AHammuerFuncBrushActor_Statics::NewProp_myStaticMeshComponent_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AHammuerFuncBrushActor_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHammuerFuncBrushActor_Statics::NewProp_myStaticMeshComponent,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AHammuerFuncBrushActor_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AHammuerFuncBrushActor>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AHammuerFuncBrushActor_Statics::ClassParams = {
		&AHammuerFuncBrushActor::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x009000A0u,
		nullptr, 0,
		Z_Construct_UClass_AHammuerFuncBrushActor_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_AHammuerFuncBrushActor_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_AHammuerFuncBrushActor_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AHammuerFuncBrushActor_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AHammuerFuncBrushActor()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AHammuerFuncBrushActor_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AHammuerFuncBrushActor, 1383213124);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AHammuerFuncBrushActor(Z_Construct_UClass_AHammuerFuncBrushActor, &AHammuerFuncBrushActor::StaticClass, TEXT("/Script/HammUErRuntime"), TEXT("AHammuerFuncBrushActor"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AHammuerFuncBrushActor);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
