// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UObject;
struct FLatentActionInfo;
#ifdef LOWENTRYEXTENDEDSTANDARDLIBRARY_LowEntryLatentActionString_generated_h
#error "LowEntryLatentActionString.generated.h already included, missing '#pragma once' in LowEntryLatentActionString.h"
#endif
#define LOWENTRYEXTENDEDSTANDARDLIBRARY_LowEntryLatentActionString_generated_h

#define BaylorBlackGospelVR_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_ClassesLatentAction_LowEntryLatentActionString_h_17_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetResult) \
	{ \
		P_GET_PROPERTY_REF(UStrProperty,Z_Param_Out_Result_); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->GetResult(Z_Param_Out_Result_); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsDone) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->IsDone(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDone) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Result_); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Done(Z_Param_Result_); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execWaitTillDone) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_STRUCT(FLatentActionInfo,Z_Param_LatentInfo); \
		P_GET_PROPERTY_REF(UStrProperty,Z_Param_Out_Result_); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->WaitTillDone(Z_Param_WorldContextObject,Z_Param_LatentInfo,Z_Param_Out_Result_); \
		P_NATIVE_END; \
	}


#define BaylorBlackGospelVR_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_ClassesLatentAction_LowEntryLatentActionString_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetResult) \
	{ \
		P_GET_PROPERTY_REF(UStrProperty,Z_Param_Out_Result_); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->GetResult(Z_Param_Out_Result_); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsDone) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->IsDone(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDone) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Result_); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Done(Z_Param_Result_); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execWaitTillDone) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_STRUCT(FLatentActionInfo,Z_Param_LatentInfo); \
		P_GET_PROPERTY_REF(UStrProperty,Z_Param_Out_Result_); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->WaitTillDone(Z_Param_WorldContextObject,Z_Param_LatentInfo,Z_Param_Out_Result_); \
		P_NATIVE_END; \
	}


#define BaylorBlackGospelVR_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_ClassesLatentAction_LowEntryLatentActionString_h_17_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesULowEntryLatentActionString(); \
	friend struct Z_Construct_UClass_ULowEntryLatentActionString_Statics; \
public: \
	DECLARE_CLASS(ULowEntryLatentActionString, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/LowEntryExtendedStandardLibrary"), NO_API) \
	DECLARE_SERIALIZER(ULowEntryLatentActionString)


#define BaylorBlackGospelVR_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_ClassesLatentAction_LowEntryLatentActionString_h_17_INCLASS \
private: \
	static void StaticRegisterNativesULowEntryLatentActionString(); \
	friend struct Z_Construct_UClass_ULowEntryLatentActionString_Statics; \
public: \
	DECLARE_CLASS(ULowEntryLatentActionString, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/LowEntryExtendedStandardLibrary"), NO_API) \
	DECLARE_SERIALIZER(ULowEntryLatentActionString)


#define BaylorBlackGospelVR_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_ClassesLatentAction_LowEntryLatentActionString_h_17_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ULowEntryLatentActionString(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ULowEntryLatentActionString) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ULowEntryLatentActionString); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ULowEntryLatentActionString); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ULowEntryLatentActionString(ULowEntryLatentActionString&&); \
	NO_API ULowEntryLatentActionString(const ULowEntryLatentActionString&); \
public:


#define BaylorBlackGospelVR_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_ClassesLatentAction_LowEntryLatentActionString_h_17_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ULowEntryLatentActionString(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ULowEntryLatentActionString(ULowEntryLatentActionString&&); \
	NO_API ULowEntryLatentActionString(const ULowEntryLatentActionString&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ULowEntryLatentActionString); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ULowEntryLatentActionString); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ULowEntryLatentActionString)


#define BaylorBlackGospelVR_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_ClassesLatentAction_LowEntryLatentActionString_h_17_PRIVATE_PROPERTY_OFFSET
#define BaylorBlackGospelVR_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_ClassesLatentAction_LowEntryLatentActionString_h_14_PROLOG
#define BaylorBlackGospelVR_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_ClassesLatentAction_LowEntryLatentActionString_h_17_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	BaylorBlackGospelVR_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_ClassesLatentAction_LowEntryLatentActionString_h_17_PRIVATE_PROPERTY_OFFSET \
	BaylorBlackGospelVR_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_ClassesLatentAction_LowEntryLatentActionString_h_17_RPC_WRAPPERS \
	BaylorBlackGospelVR_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_ClassesLatentAction_LowEntryLatentActionString_h_17_INCLASS \
	BaylorBlackGospelVR_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_ClassesLatentAction_LowEntryLatentActionString_h_17_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define BaylorBlackGospelVR_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_ClassesLatentAction_LowEntryLatentActionString_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	BaylorBlackGospelVR_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_ClassesLatentAction_LowEntryLatentActionString_h_17_PRIVATE_PROPERTY_OFFSET \
	BaylorBlackGospelVR_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_ClassesLatentAction_LowEntryLatentActionString_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	BaylorBlackGospelVR_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_ClassesLatentAction_LowEntryLatentActionString_h_17_INCLASS_NO_PURE_DECLS \
	BaylorBlackGospelVR_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_ClassesLatentAction_LowEntryLatentActionString_h_17_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class LowEntryLatentActionString."); \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID BaylorBlackGospelVR_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_ClassesLatentAction_LowEntryLatentActionString_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
