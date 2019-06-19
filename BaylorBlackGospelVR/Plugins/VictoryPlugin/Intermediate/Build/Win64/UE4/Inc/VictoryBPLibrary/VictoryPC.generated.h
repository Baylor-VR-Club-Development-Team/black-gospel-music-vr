// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FSubtitleCue;
class USoundBase;
class UAudioComponent;
struct FVictorySubtitleCue;
#ifdef VICTORYBPLIBRARY_VictoryPC_generated_h
#error "VictoryPC.generated.h already included, missing '#pragma once' in VictoryPC.h"
#endif
#define VICTORYBPLIBRARY_VictoryPC_generated_h

#define Unreal_Projects_Sun_PluginStaging_Output21_HostProject_Plugins_VictoryBPLibrary_Source_VictoryBPLibrary_Public_VictoryPC_h_22_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FVictorySubtitleCue_Statics; \
	VICTORYBPLIBRARY_API static class UScriptStruct* StaticStruct();


#define Unreal_Projects_Sun_PluginStaging_Output21_HostProject_Plugins_VictoryBPLibrary_Source_VictoryBPLibrary_Public_VictoryPC_h_44_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execVictoryPC_GetMyIP_SendRequest) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->VictoryPC_GetMyIP_SendRequest(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSubtitles_CPPDelegate) \
	{ \
		P_GET_TARRAY_REF(FSubtitleCue,Z_Param_Out_VictorySubtitles); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_CueDuration); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Subtitles_CPPDelegate(Z_Param_Out_VictorySubtitles,Z_Param_CueDuration); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execVictoryPlaySpeechSound) \
	{ \
		P_GET_OBJECT(USoundBase,Z_Param_Sound); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_VolumeMultiplier); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_PitchMultiplier); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_StartTime); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UAudioComponent**)Z_Param__Result=P_THIS->VictoryPlaySpeechSound(Z_Param_Sound,Z_Param_VolumeMultiplier,Z_Param_PitchMultiplier,Z_Param_StartTime); \
		P_NATIVE_END; \
	}


#define Unreal_Projects_Sun_PluginStaging_Output21_HostProject_Plugins_VictoryBPLibrary_Source_VictoryBPLibrary_Public_VictoryPC_h_44_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execVictoryPC_GetMyIP_SendRequest) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->VictoryPC_GetMyIP_SendRequest(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSubtitles_CPPDelegate) \
	{ \
		P_GET_TARRAY_REF(FSubtitleCue,Z_Param_Out_VictorySubtitles); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_CueDuration); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Subtitles_CPPDelegate(Z_Param_Out_VictorySubtitles,Z_Param_CueDuration); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execVictoryPlaySpeechSound) \
	{ \
		P_GET_OBJECT(USoundBase,Z_Param_Sound); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_VolumeMultiplier); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_PitchMultiplier); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_StartTime); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UAudioComponent**)Z_Param__Result=P_THIS->VictoryPlaySpeechSound(Z_Param_Sound,Z_Param_VolumeMultiplier,Z_Param_PitchMultiplier,Z_Param_StartTime); \
		P_NATIVE_END; \
	}


#define Unreal_Projects_Sun_PluginStaging_Output21_HostProject_Plugins_VictoryBPLibrary_Source_VictoryBPLibrary_Public_VictoryPC_h_44_EVENT_PARMS \
	struct VictoryPC_eventOnVictorySubtitlesQueued_Parms \
	{ \
		TArray<FVictorySubtitleCue> VictorySubtitles; \
		float CueDuration; \
	}; \
	struct VictoryPC_eventVictoryPC_GetMyIP_DataReceived_Parms \
	{ \
		FString YourIP; \
	};


#define Unreal_Projects_Sun_PluginStaging_Output21_HostProject_Plugins_VictoryBPLibrary_Source_VictoryBPLibrary_Public_VictoryPC_h_44_CALLBACK_WRAPPERS
#define Unreal_Projects_Sun_PluginStaging_Output21_HostProject_Plugins_VictoryBPLibrary_Source_VictoryBPLibrary_Public_VictoryPC_h_44_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAVictoryPC(); \
	friend struct Z_Construct_UClass_AVictoryPC_Statics; \
public: \
	DECLARE_CLASS(AVictoryPC, APlayerController, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/VictoryBPLibrary"), NO_API) \
	DECLARE_SERIALIZER(AVictoryPC)


#define Unreal_Projects_Sun_PluginStaging_Output21_HostProject_Plugins_VictoryBPLibrary_Source_VictoryBPLibrary_Public_VictoryPC_h_44_INCLASS \
private: \
	static void StaticRegisterNativesAVictoryPC(); \
	friend struct Z_Construct_UClass_AVictoryPC_Statics; \
public: \
	DECLARE_CLASS(AVictoryPC, APlayerController, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/VictoryBPLibrary"), NO_API) \
	DECLARE_SERIALIZER(AVictoryPC)


#define Unreal_Projects_Sun_PluginStaging_Output21_HostProject_Plugins_VictoryBPLibrary_Source_VictoryBPLibrary_Public_VictoryPC_h_44_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AVictoryPC(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AVictoryPC) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AVictoryPC); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AVictoryPC); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AVictoryPC(AVictoryPC&&); \
	NO_API AVictoryPC(const AVictoryPC&); \
public:


#define Unreal_Projects_Sun_PluginStaging_Output21_HostProject_Plugins_VictoryBPLibrary_Source_VictoryBPLibrary_Public_VictoryPC_h_44_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AVictoryPC(AVictoryPC&&); \
	NO_API AVictoryPC(const AVictoryPC&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AVictoryPC); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AVictoryPC); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AVictoryPC)


#define Unreal_Projects_Sun_PluginStaging_Output21_HostProject_Plugins_VictoryBPLibrary_Source_VictoryBPLibrary_Public_VictoryPC_h_44_PRIVATE_PROPERTY_OFFSET
#define Unreal_Projects_Sun_PluginStaging_Output21_HostProject_Plugins_VictoryBPLibrary_Source_VictoryBPLibrary_Public_VictoryPC_h_41_PROLOG \
	Unreal_Projects_Sun_PluginStaging_Output21_HostProject_Plugins_VictoryBPLibrary_Source_VictoryBPLibrary_Public_VictoryPC_h_44_EVENT_PARMS


#define Unreal_Projects_Sun_PluginStaging_Output21_HostProject_Plugins_VictoryBPLibrary_Source_VictoryBPLibrary_Public_VictoryPC_h_44_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Unreal_Projects_Sun_PluginStaging_Output21_HostProject_Plugins_VictoryBPLibrary_Source_VictoryBPLibrary_Public_VictoryPC_h_44_PRIVATE_PROPERTY_OFFSET \
	Unreal_Projects_Sun_PluginStaging_Output21_HostProject_Plugins_VictoryBPLibrary_Source_VictoryBPLibrary_Public_VictoryPC_h_44_RPC_WRAPPERS \
	Unreal_Projects_Sun_PluginStaging_Output21_HostProject_Plugins_VictoryBPLibrary_Source_VictoryBPLibrary_Public_VictoryPC_h_44_CALLBACK_WRAPPERS \
	Unreal_Projects_Sun_PluginStaging_Output21_HostProject_Plugins_VictoryBPLibrary_Source_VictoryBPLibrary_Public_VictoryPC_h_44_INCLASS \
	Unreal_Projects_Sun_PluginStaging_Output21_HostProject_Plugins_VictoryBPLibrary_Source_VictoryBPLibrary_Public_VictoryPC_h_44_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Unreal_Projects_Sun_PluginStaging_Output21_HostProject_Plugins_VictoryBPLibrary_Source_VictoryBPLibrary_Public_VictoryPC_h_44_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Unreal_Projects_Sun_PluginStaging_Output21_HostProject_Plugins_VictoryBPLibrary_Source_VictoryBPLibrary_Public_VictoryPC_h_44_PRIVATE_PROPERTY_OFFSET \
	Unreal_Projects_Sun_PluginStaging_Output21_HostProject_Plugins_VictoryBPLibrary_Source_VictoryBPLibrary_Public_VictoryPC_h_44_RPC_WRAPPERS_NO_PURE_DECLS \
	Unreal_Projects_Sun_PluginStaging_Output21_HostProject_Plugins_VictoryBPLibrary_Source_VictoryBPLibrary_Public_VictoryPC_h_44_CALLBACK_WRAPPERS \
	Unreal_Projects_Sun_PluginStaging_Output21_HostProject_Plugins_VictoryBPLibrary_Source_VictoryBPLibrary_Public_VictoryPC_h_44_INCLASS_NO_PURE_DECLS \
	Unreal_Projects_Sun_PluginStaging_Output21_HostProject_Plugins_VictoryBPLibrary_Source_VictoryBPLibrary_Public_VictoryPC_h_44_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Unreal_Projects_Sun_PluginStaging_Output21_HostProject_Plugins_VictoryBPLibrary_Source_VictoryBPLibrary_Public_VictoryPC_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
