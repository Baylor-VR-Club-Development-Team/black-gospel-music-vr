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
#ifdef LOWENTRYEXTENDEDSTANDARDLIBRARY_LowEntryLatentActionNone_generated_h
#error "LowEntryLatentActionNone.generated.h already included, missing '#pragma once' in LowEntryLatentActionNone.h"
#endif
#define LOWENTRYEXTENDEDSTANDARDLIBRARY_LowEntryLatentActionNone_generated_h

#define BaylorBlackGospelVR_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_ClassesLatentAction_LowEntryLatentActionNone_h_17_RPC_WRAPPERS \
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
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Done(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execWaitTillDone) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_STRUCT(FLatentActionInfo,Z_Param_LatentInfo); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->WaitTillDone(Z_Param_WorldContextObject,Z_Param_LatentInfo); \
		P_NATIVE_END; \
	}


#define BaylorBlackGospelVR_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_ClassesLatentAction_LowEntryLatentActionNone_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
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
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Done(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execWaitTillDone) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_STRUCT(FLatentActionInfo,Z_Param_LatentInfo); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->WaitTillDone(Z_Param_WorldContextObject,Z_Param_LatentInfo); \
		P_NATIVE_END; \
	}


#define BaylorBlackGospelVR_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_ClassesLatentAction_LowEntryLatentActionNone_h_17_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesULowEntryLatentActionNone(); \
	friend struct Z_Construct_UClass_ULowEntryLatentActionNone_Statics; \
public: \
	DECLARE_CLASS(ULowEntryLatentActionNone, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/LowEntryExtendedStandardLibrary"), NO_API) \
	DECLARE_SERIALIZER(ULowEntryLatentActionNone)


#define BaylorBlackGospelVR_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_ClassesLatentAction_LowEntryLatentActionNone_h_17_INCLASS \
private: \
	static void StaticRegisterNativesULowEntryLatentActionNone(); \
	friend struct Z_Construct_UClass_ULowEntryLatentActionNone_Statics; \
public: \
	DECLARE_CLASS(ULowEntryLatentActionNone, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/LowEntryExtendedStandardLibrary"), NO_API) \
	DECLARE_SERIALIZER(ULowEntryLatentActionNone)


#define BaylorBlackGospelVR_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_ClassesLatentAction_LowEntryLatentActionNone_h_17_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ULowEntryLatentActionNone(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ULowEntryLatentActionNone) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ULowEntryLatentActionNone); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ULowEntryLatentActionNone); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ULowEntryLatentActionNone(ULowEntryLatentActionNone&&); \
	NO_API ULowEntryLatentActionNone(const ULowEntryLatentActionNone&); \
public:


#define BaylorBlackGospelVR_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_ClassesLatentAction_LowEntryLatentActionNone_h_17_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ULowEntryLatentActionNone(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ULowEntryLatentActionNone(ULowEntryLatentActionNone&&); \
	NO_API ULowEntryLatentActionNone(const ULowEntryLatentActionNone&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ULowEntryLatentActionNone); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ULowEntryLatentActionNone); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ULowEntryLatentActionNone)


#define BaylorBlackGospelVR_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_ClassesLatentAction_LowEntryLatentActionNone_h_17_PRIVATE_PROPERTY_OFFSET
#define BaylorBlackGospelVR_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_ClassesLatentAction_LowEntryLatentActionNone_h_14_PROLOG
#define BaylorBlackGospelVR_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_ClassesLatentAction_LowEntryLatentActionNone_h_17_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	BaylorBlackGospelVR_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_ClassesLatentAction_LowEntryLatentActionNone_h_17_PRIVATE_PROPERTY_OFFSET \
	BaylorBlackGospelVR_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_ClassesLatentAction_LowEntryLatentActionNone_h_17_RPC_WRAPPERS \
	BaylorBlackGospelVR_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_ClassesLatentAction_LowEntryLatentActionNone_h_17_INCLASS \
	BaylorBlackGospelVR_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_ClassesLatentAction_LowEntryLatentActionNone_h_17_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define BaylorBlackGospelVR_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_ClassesLatentAction_LowEntryLatentActionNone_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	BaylorBlackGospelVR_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_ClassesLatentAction_LowEntryLatentActionNone_h_17_PRIVATE_PROPERTY_OFFSET \
	BaylorBlackGospelVR_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_ClassesLatentAction_LowEntryLatentActionNone_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	BaylorBlackGospelVR_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_ClassesLatentAction_LowEntryLatentActionNone_h_17_INCLASS_NO_PURE_DECLS \
	BaylorBlackGospelVR_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_ClassesLatentAction_LowEntryLatentActionNone_h_17_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class LowEntryLatentActionNone."); \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID BaylorBlackGospelVR_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_ClassesLatentAction_LowEntryLatentActionNone_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
