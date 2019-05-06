// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class ULowEntryXmlParserNode;
#ifdef LOWENTRYXMLPARSER_LowEntryXmlParserLibrary_generated_h
#error "LowEntryXmlParserLibrary.generated.h already included, missing '#pragma once' in LowEntryXmlParserLibrary.h"
#endif
#define LOWENTRYXMLPARSER_LowEntryXmlParserLibrary_generated_h

#define BaylorBlackGospelVR_Plugins_LowEntryXmlParser_Source_LowEntryXmlParser_Public_Classes_LowEntryXmlParserLibrary_h_24_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execXmlToString) \
	{ \
		P_GET_OBJECT(ULowEntryXmlParserNode,Z_Param_Node); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=ULowEntryXmlParserLibrary::XmlToString(Z_Param_Node); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStringToXml) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Xml); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryXmlParserNode**)Z_Param__Result=ULowEntryXmlParserLibrary::StringToXml(Z_Param_Xml); \
		P_NATIVE_END; \
	}


#define BaylorBlackGospelVR_Plugins_LowEntryXmlParser_Source_LowEntryXmlParser_Public_Classes_LowEntryXmlParserLibrary_h_24_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execXmlToString) \
	{ \
		P_GET_OBJECT(ULowEntryXmlParserNode,Z_Param_Node); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=ULowEntryXmlParserLibrary::XmlToString(Z_Param_Node); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStringToXml) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Xml); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryXmlParserNode**)Z_Param__Result=ULowEntryXmlParserLibrary::StringToXml(Z_Param_Xml); \
		P_NATIVE_END; \
	}


#define BaylorBlackGospelVR_Plugins_LowEntryXmlParser_Source_LowEntryXmlParser_Public_Classes_LowEntryXmlParserLibrary_h_24_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesULowEntryXmlParserLibrary(); \
	friend struct Z_Construct_UClass_ULowEntryXmlParserLibrary_Statics; \
public: \
	DECLARE_CLASS(ULowEntryXmlParserLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/LowEntryXmlParser"), NO_API) \
	DECLARE_SERIALIZER(ULowEntryXmlParserLibrary)


#define BaylorBlackGospelVR_Plugins_LowEntryXmlParser_Source_LowEntryXmlParser_Public_Classes_LowEntryXmlParserLibrary_h_24_INCLASS \
private: \
	static void StaticRegisterNativesULowEntryXmlParserLibrary(); \
	friend struct Z_Construct_UClass_ULowEntryXmlParserLibrary_Statics; \
public: \
	DECLARE_CLASS(ULowEntryXmlParserLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/LowEntryXmlParser"), NO_API) \
	DECLARE_SERIALIZER(ULowEntryXmlParserLibrary)


#define BaylorBlackGospelVR_Plugins_LowEntryXmlParser_Source_LowEntryXmlParser_Public_Classes_LowEntryXmlParserLibrary_h_24_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ULowEntryXmlParserLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ULowEntryXmlParserLibrary) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ULowEntryXmlParserLibrary); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ULowEntryXmlParserLibrary); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ULowEntryXmlParserLibrary(ULowEntryXmlParserLibrary&&); \
	NO_API ULowEntryXmlParserLibrary(const ULowEntryXmlParserLibrary&); \
public:


#define BaylorBlackGospelVR_Plugins_LowEntryXmlParser_Source_LowEntryXmlParser_Public_Classes_LowEntryXmlParserLibrary_h_24_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ULowEntryXmlParserLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ULowEntryXmlParserLibrary(ULowEntryXmlParserLibrary&&); \
	NO_API ULowEntryXmlParserLibrary(const ULowEntryXmlParserLibrary&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ULowEntryXmlParserLibrary); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ULowEntryXmlParserLibrary); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ULowEntryXmlParserLibrary)


#define BaylorBlackGospelVR_Plugins_LowEntryXmlParser_Source_LowEntryXmlParser_Public_Classes_LowEntryXmlParserLibrary_h_24_PRIVATE_PROPERTY_OFFSET
#define BaylorBlackGospelVR_Plugins_LowEntryXmlParser_Source_LowEntryXmlParser_Public_Classes_LowEntryXmlParserLibrary_h_21_PROLOG
#define BaylorBlackGospelVR_Plugins_LowEntryXmlParser_Source_LowEntryXmlParser_Public_Classes_LowEntryXmlParserLibrary_h_24_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	BaylorBlackGospelVR_Plugins_LowEntryXmlParser_Source_LowEntryXmlParser_Public_Classes_LowEntryXmlParserLibrary_h_24_PRIVATE_PROPERTY_OFFSET \
	BaylorBlackGospelVR_Plugins_LowEntryXmlParser_Source_LowEntryXmlParser_Public_Classes_LowEntryXmlParserLibrary_h_24_RPC_WRAPPERS \
	BaylorBlackGospelVR_Plugins_LowEntryXmlParser_Source_LowEntryXmlParser_Public_Classes_LowEntryXmlParserLibrary_h_24_INCLASS \
	BaylorBlackGospelVR_Plugins_LowEntryXmlParser_Source_LowEntryXmlParser_Public_Classes_LowEntryXmlParserLibrary_h_24_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define BaylorBlackGospelVR_Plugins_LowEntryXmlParser_Source_LowEntryXmlParser_Public_Classes_LowEntryXmlParserLibrary_h_24_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	BaylorBlackGospelVR_Plugins_LowEntryXmlParser_Source_LowEntryXmlParser_Public_Classes_LowEntryXmlParserLibrary_h_24_PRIVATE_PROPERTY_OFFSET \
	BaylorBlackGospelVR_Plugins_LowEntryXmlParser_Source_LowEntryXmlParser_Public_Classes_LowEntryXmlParserLibrary_h_24_RPC_WRAPPERS_NO_PURE_DECLS \
	BaylorBlackGospelVR_Plugins_LowEntryXmlParser_Source_LowEntryXmlParser_Public_Classes_LowEntryXmlParserLibrary_h_24_INCLASS_NO_PURE_DECLS \
	BaylorBlackGospelVR_Plugins_LowEntryXmlParser_Source_LowEntryXmlParser_Public_Classes_LowEntryXmlParserLibrary_h_24_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class LowEntryXmlParserLibrary."); \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID BaylorBlackGospelVR_Plugins_LowEntryXmlParser_Source_LowEntryXmlParser_Public_Classes_LowEntryXmlParserLibrary_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
