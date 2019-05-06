// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LowEntryXmlParser/Public/Classes/LowEntryXmlParserLibrary.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeLowEntryXmlParserLibrary() {}
// Cross Module References
	LOWENTRYXMLPARSER_API UClass* Z_Construct_UClass_ULowEntryXmlParserLibrary_NoRegister();
	LOWENTRYXMLPARSER_API UClass* Z_Construct_UClass_ULowEntryXmlParserLibrary();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	UPackage* Z_Construct_UPackage__Script_LowEntryXmlParser();
	LOWENTRYXMLPARSER_API UFunction* Z_Construct_UFunction_ULowEntryXmlParserLibrary_StringToXml();
	LOWENTRYXMLPARSER_API UClass* Z_Construct_UClass_ULowEntryXmlParserNode_NoRegister();
	LOWENTRYXMLPARSER_API UFunction* Z_Construct_UFunction_ULowEntryXmlParserLibrary_XmlToString();
// End Cross Module References
	void ULowEntryXmlParserLibrary::StaticRegisterNativesULowEntryXmlParserLibrary()
	{
		UClass* Class = ULowEntryXmlParserLibrary::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "StringToXml", &ULowEntryXmlParserLibrary::execStringToXml },
			{ "XmlToString", &ULowEntryXmlParserLibrary::execXmlToString },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ULowEntryXmlParserLibrary_StringToXml_Statics
	{
		struct LowEntryXmlParserLibrary_eventStringToXml_Parms
		{
			FString Xml;
			ULowEntryXmlParserNode* ReturnValue;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Xml_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_Xml;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ULowEntryXmlParserLibrary_StringToXml_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Object, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(LowEntryXmlParserLibrary_eventStringToXml_Parms, ReturnValue), Z_Construct_UClass_ULowEntryXmlParserNode_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryXmlParserLibrary_StringToXml_Statics::NewProp_Xml_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ULowEntryXmlParserLibrary_StringToXml_Statics::NewProp_Xml = { UE4CodeGen_Private::EPropertyClass::Str, "Xml", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(LowEntryXmlParserLibrary_eventStringToXml_Parms, Xml), METADATA_PARAMS(Z_Construct_UFunction_ULowEntryXmlParserLibrary_StringToXml_Statics::NewProp_Xml_MetaData, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryXmlParserLibrary_StringToXml_Statics::NewProp_Xml_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULowEntryXmlParserLibrary_StringToXml_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryXmlParserLibrary_StringToXml_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryXmlParserLibrary_StringToXml_Statics::NewProp_Xml,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryXmlParserLibrary_StringToXml_Statics::Function_MetaDataParams[] = {
		{ "Category", "Low Entry|Xml Parser|Library" },
		{ "DisplayName", "Parse Xml" },
		{ "ModuleRelativePath", "Public/Classes/LowEntryXmlParserLibrary.h" },
		{ "ToolTip", "Parses XML data and returns the root node, returns NULL if it can't be parsed." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULowEntryXmlParserLibrary_StringToXml_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULowEntryXmlParserLibrary, "StringToXml", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04022401, sizeof(LowEntryXmlParserLibrary_eventStringToXml_Parms), Z_Construct_UFunction_ULowEntryXmlParserLibrary_StringToXml_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryXmlParserLibrary_StringToXml_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULowEntryXmlParserLibrary_StringToXml_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryXmlParserLibrary_StringToXml_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULowEntryXmlParserLibrary_StringToXml()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULowEntryXmlParserLibrary_StringToXml_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULowEntryXmlParserLibrary_XmlToString_Statics
	{
		struct LowEntryXmlParserLibrary_eventXmlToString_Parms
		{
			ULowEntryXmlParserNode* Node;
			FString ReturnValue;
		};
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Node;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ULowEntryXmlParserLibrary_XmlToString_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Str, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(LowEntryXmlParserLibrary_eventXmlToString_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ULowEntryXmlParserLibrary_XmlToString_Statics::NewProp_Node = { UE4CodeGen_Private::EPropertyClass::Object, "Node", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(LowEntryXmlParserLibrary_eventXmlToString_Parms, Node), Z_Construct_UClass_ULowEntryXmlParserNode_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULowEntryXmlParserLibrary_XmlToString_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryXmlParserLibrary_XmlToString_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULowEntryXmlParserLibrary_XmlToString_Statics::NewProp_Node,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULowEntryXmlParserLibrary_XmlToString_Statics::Function_MetaDataParams[] = {
		{ "Category", "Low Entry|Xml Parser|Library" },
		{ "DisplayName", "Get Xml" },
		{ "ModuleRelativePath", "Public/Classes/LowEntryXmlParserLibrary.h" },
		{ "ToolTip", "Converts the given node and all childs to XML data." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULowEntryXmlParserLibrary_XmlToString_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULowEntryXmlParserLibrary, "XmlToString", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14022401, sizeof(LowEntryXmlParserLibrary_eventXmlToString_Parms), Z_Construct_UFunction_ULowEntryXmlParserLibrary_XmlToString_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryXmlParserLibrary_XmlToString_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULowEntryXmlParserLibrary_XmlToString_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ULowEntryXmlParserLibrary_XmlToString_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULowEntryXmlParserLibrary_XmlToString()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULowEntryXmlParserLibrary_XmlToString_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ULowEntryXmlParserLibrary_NoRegister()
	{
		return ULowEntryXmlParserLibrary::StaticClass();
	}
	struct Z_Construct_UClass_ULowEntryXmlParserLibrary_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ULowEntryXmlParserLibrary_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_LowEntryXmlParser,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ULowEntryXmlParserLibrary_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ULowEntryXmlParserLibrary_StringToXml, "StringToXml" }, // 1915883572
		{ &Z_Construct_UFunction_ULowEntryXmlParserLibrary_XmlToString, "XmlToString" }, // 2297114107
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULowEntryXmlParserLibrary_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Classes/LowEntryXmlParserLibrary.h" },
		{ "ModuleRelativePath", "Public/Classes/LowEntryXmlParserLibrary.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ULowEntryXmlParserLibrary_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ULowEntryXmlParserLibrary>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ULowEntryXmlParserLibrary_Statics::ClassParams = {
		&ULowEntryXmlParserLibrary::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x001000A0u,
		FuncInfo, ARRAY_COUNT(FuncInfo),
		nullptr, 0,
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_ULowEntryXmlParserLibrary_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_ULowEntryXmlParserLibrary_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ULowEntryXmlParserLibrary()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ULowEntryXmlParserLibrary_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ULowEntryXmlParserLibrary, 414153338);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ULowEntryXmlParserLibrary(Z_Construct_UClass_ULowEntryXmlParserLibrary, &ULowEntryXmlParserLibrary::StaticClass, TEXT("/Script/LowEntryXmlParser"), TEXT("ULowEntryXmlParserLibrary"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ULowEntryXmlParserLibrary);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
