// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UObject;
class ULowEntryByteArray;
class APlayerController;
class ULocalPlayer;
enum class ELowEntryExtendedStandardLibrary1to10other : uint8;
enum class ELowEntryExtendedStandardLibrary0to9 : uint8;
enum class ELowEntryExtendedStandardLibraryTrueOrFalse : uint8;
struct FGeometry;
struct FVector2D;
enum class ELowEntrySplitScreenTypeThreePlayers : uint8;
enum class ELowEntrySplitScreenTypeTwoPlayers : uint8;
enum class ELowEntrySplitScreenType : uint8;
class ULowEntryDouble;
class ULowEntryLong;
class ULowEntryBitDataEntry;
class ULowEntryBitDataWriter;
class ULowEntryBitDataReader;
class ULowEntryByteDataEntry;
class ULowEntryByteDataWriter;
class ULowEntryByteDataReader;
struct FLatentActionInfo;
struct FLowEntryRegexMatch;
class ULowEntryExecutionQueue;
struct FTimespan;
struct FDateTime;
class ULowEntryParsedHashcash;
enum class ELowEntryHmacAlgorithm : uint8;
class USceneCaptureComponent2D;
class ASceneCapture2D;
class UTexture;
class UMediaSoundComponent;
class UMediaPlayer;
class UMediaTexture;
class UTextureRenderTarget2D;
struct FColor;
enum class ELowEntryImageFormat : uint8;
class UTexture2D;
class ULowEntryLatentActionString;
class ULowEntryLatentActionObject;
class ULowEntryLatentActionNone;
class ULowEntryLatentActionInteger;
class ULowEntryLatentActionFloat;
class ULowEntryLatentActionBoolean;
class USoundClass;
class AActor;
enum class ELowEntryBatteryState : uint8;
#ifdef LOWENTRYEXTENDEDSTANDARDLIBRARY_LowEntryExtendedStandardLibrary_generated_h
#error "LowEntryExtendedStandardLibrary.generated.h already included, missing '#pragma once' in LowEntryExtendedStandardLibrary.h"
#endif
#define LOWENTRYEXTENDEDSTANDARDLIBRARY_LowEntryExtendedStandardLibrary_generated_h

#define BaylorBlackGospelVR_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_Classes_LowEntryExtendedStandardLibrary_h_82_DELEGATE \
struct _Script_LowEntryExtendedStandardLibrary_eventDelegateULowEntryExtendedStandardLibraryCompareObjects_Parms \
{ \
	UObject* ObjectA; \
	UObject* ObjectB; \
	bool Result; \
}; \
static inline void FDelegateULowEntryExtendedStandardLibraryCompareObjects_DelegateWrapper(const FScriptDelegate& DelegateULowEntryExtendedStandardLibraryCompareObjects, UObject* ObjectA, UObject* ObjectB, bool& Result) \
{ \
	_Script_LowEntryExtendedStandardLibrary_eventDelegateULowEntryExtendedStandardLibraryCompareObjects_Parms Parms; \
	Parms.ObjectA=ObjectA; \
	Parms.ObjectB=ObjectB; \
	Parms.Result=Result ? true : false; \
	DelegateULowEntryExtendedStandardLibraryCompareObjects.ProcessDelegate<UObject>(&Parms); \
	Result=Parms.Result; \
}


#define BaylorBlackGospelVR_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_Classes_LowEntryExtendedStandardLibrary_h_88_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execMergeEncapsulatedByteArrays) \
	{ \
		P_GET_TARRAY_REF(ULowEntryByteArray*,Z_Param_Out_ByteArrays); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<uint8>*)Z_Param__Result=ULowEntryExtendedStandardLibrary::MergeEncapsulatedByteArrays(Z_Param_Out_ByteArrays); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execEncapsulateByteArray) \
	{ \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_ByteArray); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryByteArray**)Z_Param__Result=ULowEntryExtendedStandardLibrary::EncapsulateByteArray(Z_Param_Out_ByteArray); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSimpleKismetSystemLibraryPrintString) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_InString); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::SimpleKismetSystemLibraryPrintString(Z_Param_InString); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execPlayerControllerGetLocalPlayer) \
	{ \
		P_GET_OBJECT(APlayerController,Z_Param_PlayerController); \
		P_GET_UBOOL_REF(Z_Param_Out_Success); \
		P_GET_OBJECT_REF(ULocalPlayer,Z_Param_Out_LocalPlayer); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::PlayerControllerGetLocalPlayer(Z_Param_PlayerController,Z_Param_Out_Success,Z_Param_Out_LocalPlayer); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCaseSwitchObject) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_OnlyCheckFirstX); \
		P_GET_OBJECT(UObject,Z_Param_Value); \
		P_GET_OBJECT(UObject,Z_Param__1__); \
		P_GET_OBJECT(UObject,Z_Param__2__); \
		P_GET_OBJECT(UObject,Z_Param__3__); \
		P_GET_OBJECT(UObject,Z_Param__4__); \
		P_GET_OBJECT(UObject,Z_Param__5__); \
		P_GET_OBJECT(UObject,Z_Param__6__); \
		P_GET_OBJECT(UObject,Z_Param__7__); \
		P_GET_OBJECT(UObject,Z_Param__8__); \
		P_GET_OBJECT(UObject,Z_Param__9__); \
		P_GET_OBJECT(UObject,Z_Param__10__); \
		P_GET_ENUM_REF(ELowEntryExtendedStandardLibrary1to10other,Z_Param_Out_Branch); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::CaseSwitchObject(Z_Param_OnlyCheckFirstX,Z_Param_Value,Z_Param__1__,Z_Param__2__,Z_Param__3__,Z_Param__4__,Z_Param__5__,Z_Param__6__,Z_Param__7__,Z_Param__8__,Z_Param__9__,Z_Param__10__,(ELowEntryExtendedStandardLibrary1to10other&)(Z_Param_Out_Branch)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCaseSwitchByte) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_OnlyCheckFirstX); \
		P_GET_PROPERTY(UByteProperty,Z_Param_Value); \
		P_GET_PROPERTY(UByteProperty,Z_Param__1__); \
		P_GET_PROPERTY(UByteProperty,Z_Param__2__); \
		P_GET_PROPERTY(UByteProperty,Z_Param__3__); \
		P_GET_PROPERTY(UByteProperty,Z_Param__4__); \
		P_GET_PROPERTY(UByteProperty,Z_Param__5__); \
		P_GET_PROPERTY(UByteProperty,Z_Param__6__); \
		P_GET_PROPERTY(UByteProperty,Z_Param__7__); \
		P_GET_PROPERTY(UByteProperty,Z_Param__8__); \
		P_GET_PROPERTY(UByteProperty,Z_Param__9__); \
		P_GET_PROPERTY(UByteProperty,Z_Param__10__); \
		P_GET_ENUM_REF(ELowEntryExtendedStandardLibrary1to10other,Z_Param_Out_Branch); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::CaseSwitchByte(Z_Param_OnlyCheckFirstX,Z_Param_Value,Z_Param__1__,Z_Param__2__,Z_Param__3__,Z_Param__4__,Z_Param__5__,Z_Param__6__,Z_Param__7__,Z_Param__8__,Z_Param__9__,Z_Param__10__,(ELowEntryExtendedStandardLibrary1to10other&)(Z_Param_Out_Branch)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCaseSwitchInteger) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_OnlyCheckFirstX); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Value); \
		P_GET_PROPERTY(UIntProperty,Z_Param__1__); \
		P_GET_PROPERTY(UIntProperty,Z_Param__2__); \
		P_GET_PROPERTY(UIntProperty,Z_Param__3__); \
		P_GET_PROPERTY(UIntProperty,Z_Param__4__); \
		P_GET_PROPERTY(UIntProperty,Z_Param__5__); \
		P_GET_PROPERTY(UIntProperty,Z_Param__6__); \
		P_GET_PROPERTY(UIntProperty,Z_Param__7__); \
		P_GET_PROPERTY(UIntProperty,Z_Param__8__); \
		P_GET_PROPERTY(UIntProperty,Z_Param__9__); \
		P_GET_PROPERTY(UIntProperty,Z_Param__10__); \
		P_GET_ENUM_REF(ELowEntryExtendedStandardLibrary1to10other,Z_Param_Out_Branch); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::CaseSwitchInteger(Z_Param_OnlyCheckFirstX,Z_Param_Value,Z_Param__1__,Z_Param__2__,Z_Param__3__,Z_Param__4__,Z_Param__5__,Z_Param__6__,Z_Param__7__,Z_Param__8__,Z_Param__9__,Z_Param__10__,(ELowEntryExtendedStandardLibrary1to10other&)(Z_Param_Out_Branch)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execExecToByte) \
	{ \
		P_GET_ENUM(ELowEntryExtendedStandardLibrary0to9,Z_Param_Branch); \
		P_GET_PROPERTY_REF(UByteProperty,Z_Param_Out_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::ExecToByte(ELowEntryExtendedStandardLibrary0to9(Z_Param_Branch),Z_Param_Out_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execExecToInteger) \
	{ \
		P_GET_ENUM(ELowEntryExtendedStandardLibrary0to9,Z_Param_Branch); \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::ExecToInteger(ELowEntryExtendedStandardLibrary0to9(Z_Param_Branch),Z_Param_Out_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execExecToBoolean) \
	{ \
		P_GET_ENUM(ELowEntryExtendedStandardLibraryTrueOrFalse,Z_Param_Branch); \
		P_GET_UBOOL_REF(Z_Param_Out_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::ExecToBoolean(ELowEntryExtendedStandardLibraryTrueOrFalse(Z_Param_Branch),Z_Param_Out_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetKeyboardFocusedWidgetType) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FName*)Z_Param__Result=ULowEntryExtendedStandardLibrary::GetKeyboardFocusedWidgetType(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetUserFocusedWidgetType) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_UserIndex); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FName*)Z_Param__Result=ULowEntryExtendedStandardLibrary::GetUserFocusedWidgetType(Z_Param_UserIndex); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execClearKeyboardFocus) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::ClearKeyboardFocus(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execClearUserFocus) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_UserIndex); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::ClearUserFocus(Z_Param_UserIndex); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execClearAllUserFocus) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::ClearAllUserFocus(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetAbsoluteToLocalScale) \
	{ \
		P_GET_STRUCT_REF(FGeometry,Z_Param_Out_Geometry); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FVector2D*)Z_Param__Result=ULowEntryExtendedStandardLibrary::GetAbsoluteToLocalScale(Z_Param_Out_Geometry); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetLocalToAbsoluteScale) \
	{ \
		P_GET_STRUCT_REF(FGeometry,Z_Param_Out_Geometry); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FVector2D*)Z_Param__Result=ULowEntryExtendedStandardLibrary::GetLocalToAbsoluteScale(Z_Param_Out_Geometry); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetAbsoluteSize) \
	{ \
		P_GET_STRUCT_REF(FGeometry,Z_Param_Out_Geometry); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FVector2D*)Z_Param__Result=ULowEntryExtendedStandardLibrary::GetAbsoluteSize(Z_Param_Out_Geometry); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDivide_Vector2dVector2d) \
	{ \
		P_GET_STRUCT_REF(FVector2D,Z_Param_Out_A); \
		P_GET_STRUCT_REF(FVector2D,Z_Param_Out_B); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FVector2D*)Z_Param__Result=ULowEntryExtendedStandardLibrary::Divide_Vector2dVector2d(Z_Param_Out_A,Z_Param_Out_B); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetClassWithName) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_ClassName); \
		P_GET_OBJECT_REF(UClass,Z_Param_Out_Class_); \
		P_GET_UBOOL_REF(Z_Param_Out_Success); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::GetClassWithName(Z_Param_ClassName,Z_Param_Out_Class_,Z_Param_Out_Success); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetWorldRenderingEnabled) \
	{ \
		P_GET_UBOOL(Z_Param_Enabled); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::SetWorldRenderingEnabled(Z_Param_Enabled); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsWorldRenderingEnabled) \
	{ \
		P_GET_UBOOL_REF(Z_Param_Out_Success); \
		P_GET_UBOOL_REF(Z_Param_Out_Enabled); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::IsWorldRenderingEnabled(Z_Param_Out_Success,Z_Param_Out_Enabled); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetSplitScreenType_ThreePlayers) \
	{ \
		P_GET_ENUM(ELowEntrySplitScreenTypeThreePlayers,Z_Param_Type); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::SetSplitScreenType_ThreePlayers(ELowEntrySplitScreenTypeThreePlayers(Z_Param_Type)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetSplitScreenType_TwoPlayers) \
	{ \
		P_GET_ENUM(ELowEntrySplitScreenTypeTwoPlayers,Z_Param_Type); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::SetSplitScreenType_TwoPlayers(ELowEntrySplitScreenTypeTwoPlayers(Z_Param_Type)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetSplitScreenType) \
	{ \
		P_GET_ENUM_REF(ELowEntrySplitScreenType,Z_Param_Out_Type); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::GetSplitScreenType((ELowEntrySplitScreenType&)(Z_Param_Out_Type)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetSplitScreenEnabled) \
	{ \
		P_GET_UBOOL(Z_Param_Enabled); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::SetSplitScreenEnabled(Z_Param_Enabled); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetWindowMode) \
	{ \
		P_GET_UBOOL(Z_Param_Fullscreen); \
		P_GET_UBOOL(Z_Param_IsFullscreenWindowed); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::SetWindowMode(Z_Param_Fullscreen,Z_Param_IsFullscreenWindowed); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetWindowMode) \
	{ \
		P_GET_UBOOL_REF(Z_Param_Out_Success); \
		P_GET_UBOOL_REF(Z_Param_Out_Fullscreen); \
		P_GET_UBOOL_REF(Z_Param_Out_IsFullscreenWindowed); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::GetWindowMode(Z_Param_Out_Success,Z_Param_Out_Fullscreen,Z_Param_Out_IsFullscreenWindowed); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetWindowPositiomInPercentagesCentered) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_X); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Y); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::SetWindowPositiomInPercentagesCentered(Z_Param_X,Z_Param_Y); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetWindowSize) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Width); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Height); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::SetWindowSize(Z_Param_Width,Z_Param_Height); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetWindowPosition) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_X); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Y); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::SetWindowPosition(Z_Param_X,Z_Param_Y); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetWindowPositiomInPercentagesCentered) \
	{ \
		P_GET_UBOOL_REF(Z_Param_Out_Success); \
		P_GET_PROPERTY_REF(UFloatProperty,Z_Param_Out_X); \
		P_GET_PROPERTY_REF(UFloatProperty,Z_Param_Out_Y); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::GetWindowPositiomInPercentagesCentered(Z_Param_Out_Success,Z_Param_Out_X,Z_Param_Out_Y); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetWindowSize) \
	{ \
		P_GET_UBOOL_REF(Z_Param_Out_Success); \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_Width); \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_Height); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::GetWindowSize(Z_Param_Out_Success,Z_Param_Out_Width,Z_Param_Out_Height); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetWindowPosition) \
	{ \
		P_GET_UBOOL_REF(Z_Param_Out_Success); \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_X); \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_Y); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::GetWindowPosition(Z_Param_Out_Success,Z_Param_Out_X,Z_Param_Out_Y); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetWindowBounds) \
	{ \
		P_GET_UBOOL_REF(Z_Param_Out_Success); \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_X); \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_Y); \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_Width); \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_Height); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::GetWindowBounds(Z_Param_Out_Success,Z_Param_Out_X,Z_Param_Out_Y,Z_Param_Out_Width,Z_Param_Out_Height); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetPrimaryMonitorWorkArea) \
	{ \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_X); \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_Y); \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_Width); \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_Height); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::GetPrimaryMonitorWorkArea(Z_Param_Out_X,Z_Param_Out_Y,Z_Param_Out_Width,Z_Param_Out_Height); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetPrimaryMonitorResolution) \
	{ \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_Width); \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_Height); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::GetPrimaryMonitorResolution(Z_Param_Out_Width,Z_Param_Out_Height); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetMouseLockedToViewport) \
	{ \
		P_GET_UBOOL(Z_Param_Locked); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::SetMouseLockedToViewport(Z_Param_Locked); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetMousePositionInPercentages) \
	{ \
		P_GET_UBOOL_REF(Z_Param_Out_Success); \
		P_GET_PROPERTY_REF(UFloatProperty,Z_Param_Out_X); \
		P_GET_PROPERTY_REF(UFloatProperty,Z_Param_Out_Y); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::GetMousePositionInPercentages(Z_Param_Out_Success,Z_Param_Out_X,Z_Param_Out_Y); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetMousePositionInPercentages) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_X); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Y); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::SetMousePositionInPercentages(Z_Param_X,Z_Param_Y); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetMousePosition) \
	{ \
		P_GET_UBOOL_REF(Z_Param_Out_Success); \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_X); \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_Y); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::GetMousePosition(Z_Param_Out_Success,Z_Param_Out_X,Z_Param_Out_Y); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetMousePosition) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_X); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Y); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::SetMousePosition(Z_Param_X,Z_Param_Y); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDouble_Create) \
	{ \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_ByteArray); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Index); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Length); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryDouble**)Z_Param__Result=ULowEntryExtendedStandardLibrary::Double_Create(Z_Param_Out_ByteArray,Z_Param_Index,Z_Param_Length); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDouble_CreateZero) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryDouble**)Z_Param__Result=ULowEntryExtendedStandardLibrary::Double_CreateZero(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLong_Create) \
	{ \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_ByteArray); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Index); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Length); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryLong**)Z_Param__Result=ULowEntryExtendedStandardLibrary::Long_Create(Z_Param_Out_ByteArray,Z_Param_Index,Z_Param_Length); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLong_CreateZero) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryLong**)Z_Param__Result=ULowEntryExtendedStandardLibrary::Long_CreateZero(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBitDataEntry_CreateFromStringUtf8Array) \
	{ \
		P_GET_TARRAY_REF(FString,Z_Param_Out_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryBitDataEntry**)Z_Param__Result=ULowEntryExtendedStandardLibrary::BitDataEntry_CreateFromStringUtf8Array(Z_Param_Out_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBitDataEntry_CreateFromBooleanArray) \
	{ \
		P_GET_TARRAY_REF(bool,Z_Param_Out_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryBitDataEntry**)Z_Param__Result=ULowEntryExtendedStandardLibrary::BitDataEntry_CreateFromBooleanArray(Z_Param_Out_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBitDataEntry_CreateFromDoubleBytesArray) \
	{ \
		P_GET_TARRAY_REF(ULowEntryDouble*,Z_Param_Out_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryBitDataEntry**)Z_Param__Result=ULowEntryExtendedStandardLibrary::BitDataEntry_CreateFromDoubleBytesArray(Z_Param_Out_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBitDataEntry_CreateFromFloatArray) \
	{ \
		P_GET_TARRAY_REF(float,Z_Param_Out_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryBitDataEntry**)Z_Param__Result=ULowEntryExtendedStandardLibrary::BitDataEntry_CreateFromFloatArray(Z_Param_Out_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBitDataEntry_CreateFromLongBytesArray) \
	{ \
		P_GET_TARRAY_REF(ULowEntryLong*,Z_Param_Out_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryBitDataEntry**)Z_Param__Result=ULowEntryExtendedStandardLibrary::BitDataEntry_CreateFromLongBytesArray(Z_Param_Out_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBitDataEntry_CreateFromPositiveInteger3Array) \
	{ \
		P_GET_TARRAY_REF(int32,Z_Param_Out_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryBitDataEntry**)Z_Param__Result=ULowEntryExtendedStandardLibrary::BitDataEntry_CreateFromPositiveInteger3Array(Z_Param_Out_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBitDataEntry_CreateFromPositiveInteger2Array) \
	{ \
		P_GET_TARRAY_REF(int32,Z_Param_Out_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryBitDataEntry**)Z_Param__Result=ULowEntryExtendedStandardLibrary::BitDataEntry_CreateFromPositiveInteger2Array(Z_Param_Out_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBitDataEntry_CreateFromPositiveInteger1Array) \
	{ \
		P_GET_TARRAY_REF(int32,Z_Param_Out_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryBitDataEntry**)Z_Param__Result=ULowEntryExtendedStandardLibrary::BitDataEntry_CreateFromPositiveInteger1Array(Z_Param_Out_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBitDataEntry_CreateFromIntegerArray) \
	{ \
		P_GET_TARRAY_REF(int32,Z_Param_Out_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryBitDataEntry**)Z_Param__Result=ULowEntryExtendedStandardLibrary::BitDataEntry_CreateFromIntegerArray(Z_Param_Out_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBitDataEntry_CreateFromByteArray) \
	{ \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryBitDataEntry**)Z_Param__Result=ULowEntryExtendedStandardLibrary::BitDataEntry_CreateFromByteArray(Z_Param_Out_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBitDataEntry_CreateFromIntegerArrayMostSignificantBits) \
	{ \
		P_GET_TARRAY_REF(int32,Z_Param_Out_Value); \
		P_GET_PROPERTY(UIntProperty,Z_Param_BitCount); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryBitDataEntry**)Z_Param__Result=ULowEntryExtendedStandardLibrary::BitDataEntry_CreateFromIntegerArrayMostSignificantBits(Z_Param_Out_Value,Z_Param_BitCount); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBitDataEntry_CreateFromIntegerArrayLeastSignificantBits) \
	{ \
		P_GET_TARRAY_REF(int32,Z_Param_Out_Value); \
		P_GET_PROPERTY(UIntProperty,Z_Param_BitCount); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryBitDataEntry**)Z_Param__Result=ULowEntryExtendedStandardLibrary::BitDataEntry_CreateFromIntegerArrayLeastSignificantBits(Z_Param_Out_Value,Z_Param_BitCount); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBitDataEntry_CreateFromByteArrayMostSignificantBits) \
	{ \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_Value); \
		P_GET_PROPERTY(UIntProperty,Z_Param_BitCount); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryBitDataEntry**)Z_Param__Result=ULowEntryExtendedStandardLibrary::BitDataEntry_CreateFromByteArrayMostSignificantBits(Z_Param_Out_Value,Z_Param_BitCount); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBitDataEntry_CreateFromByteArrayLeastSignificantBits) \
	{ \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_Value); \
		P_GET_PROPERTY(UIntProperty,Z_Param_BitCount); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryBitDataEntry**)Z_Param__Result=ULowEntryExtendedStandardLibrary::BitDataEntry_CreateFromByteArrayLeastSignificantBits(Z_Param_Out_Value,Z_Param_BitCount); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBitDataEntry_CreateFromBitArray) \
	{ \
		P_GET_TARRAY_REF(bool,Z_Param_Out_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryBitDataEntry**)Z_Param__Result=ULowEntryExtendedStandardLibrary::BitDataEntry_CreateFromBitArray(Z_Param_Out_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBitDataEntry_CreateFromStringUtf8) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryBitDataEntry**)Z_Param__Result=ULowEntryExtendedStandardLibrary::BitDataEntry_CreateFromStringUtf8(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBitDataEntry_CreateFromBoolean) \
	{ \
		P_GET_UBOOL(Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryBitDataEntry**)Z_Param__Result=ULowEntryExtendedStandardLibrary::BitDataEntry_CreateFromBoolean(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBitDataEntry_CreateFromDoubleBytes) \
	{ \
		P_GET_OBJECT(ULowEntryDouble,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryBitDataEntry**)Z_Param__Result=ULowEntryExtendedStandardLibrary::BitDataEntry_CreateFromDoubleBytes(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBitDataEntry_CreateFromFloat) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryBitDataEntry**)Z_Param__Result=ULowEntryExtendedStandardLibrary::BitDataEntry_CreateFromFloat(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBitDataEntry_CreateFromLongBytes) \
	{ \
		P_GET_OBJECT(ULowEntryLong,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryBitDataEntry**)Z_Param__Result=ULowEntryExtendedStandardLibrary::BitDataEntry_CreateFromLongBytes(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBitDataEntry_CreateFromPositiveInteger3) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryBitDataEntry**)Z_Param__Result=ULowEntryExtendedStandardLibrary::BitDataEntry_CreateFromPositiveInteger3(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBitDataEntry_CreateFromPositiveInteger2) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryBitDataEntry**)Z_Param__Result=ULowEntryExtendedStandardLibrary::BitDataEntry_CreateFromPositiveInteger2(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBitDataEntry_CreateFromPositiveInteger1) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryBitDataEntry**)Z_Param__Result=ULowEntryExtendedStandardLibrary::BitDataEntry_CreateFromPositiveInteger1(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBitDataEntry_CreateFromInteger) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryBitDataEntry**)Z_Param__Result=ULowEntryExtendedStandardLibrary::BitDataEntry_CreateFromInteger(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBitDataEntry_CreateFromByte) \
	{ \
		P_GET_PROPERTY(UByteProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryBitDataEntry**)Z_Param__Result=ULowEntryExtendedStandardLibrary::BitDataEntry_CreateFromByte(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBitDataEntry_CreateFromIntegerMostSignificantBits) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Value); \
		P_GET_PROPERTY(UIntProperty,Z_Param_BitCount); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryBitDataEntry**)Z_Param__Result=ULowEntryExtendedStandardLibrary::BitDataEntry_CreateFromIntegerMostSignificantBits(Z_Param_Value,Z_Param_BitCount); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBitDataEntry_CreateFromIntegerLeastSignificantBits) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Value); \
		P_GET_PROPERTY(UIntProperty,Z_Param_BitCount); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryBitDataEntry**)Z_Param__Result=ULowEntryExtendedStandardLibrary::BitDataEntry_CreateFromIntegerLeastSignificantBits(Z_Param_Value,Z_Param_BitCount); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBitDataEntry_CreateFromByteMostSignificantBits) \
	{ \
		P_GET_PROPERTY(UByteProperty,Z_Param_Value); \
		P_GET_PROPERTY(UIntProperty,Z_Param_BitCount); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryBitDataEntry**)Z_Param__Result=ULowEntryExtendedStandardLibrary::BitDataEntry_CreateFromByteMostSignificantBits(Z_Param_Value,Z_Param_BitCount); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBitDataEntry_CreateFromByteLeastSignificantBits) \
	{ \
		P_GET_PROPERTY(UByteProperty,Z_Param_Value); \
		P_GET_PROPERTY(UIntProperty,Z_Param_BitCount); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryBitDataEntry**)Z_Param__Result=ULowEntryExtendedStandardLibrary::BitDataEntry_CreateFromByteLeastSignificantBits(Z_Param_Value,Z_Param_BitCount); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBitDataEntry_CreateFromBit) \
	{ \
		P_GET_UBOOL(Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryBitDataEntry**)Z_Param__Result=ULowEntryExtendedStandardLibrary::BitDataEntry_CreateFromBit(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBitDataWriter_GetBytes) \
	{ \
		P_GET_OBJECT(ULowEntryBitDataWriter,Z_Param_BitDataWriter); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<uint8>*)Z_Param__Result=ULowEntryExtendedStandardLibrary::BitDataWriter_GetBytes(Z_Param_BitDataWriter); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBitDataWriter_CreateFromEntryArrayPure) \
	{ \
		P_GET_TARRAY_REF(ULowEntryBitDataEntry*,Z_Param_Out_Array); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryBitDataWriter**)Z_Param__Result=ULowEntryExtendedStandardLibrary::BitDataWriter_CreateFromEntryArrayPure(Z_Param_Out_Array); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBitDataWriter_CreateFromEntryArray) \
	{ \
		P_GET_TARRAY_REF(ULowEntryBitDataEntry*,Z_Param_Out_Array); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryBitDataWriter**)Z_Param__Result=ULowEntryExtendedStandardLibrary::BitDataWriter_CreateFromEntryArray(Z_Param_Out_Array); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBitDataReader_Create) \
	{ \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_Bytes); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Index); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Length); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryBitDataReader**)Z_Param__Result=ULowEntryExtendedStandardLibrary::BitDataReader_Create(Z_Param_Out_Bytes,Z_Param_Index,Z_Param_Length); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execByteDataEntry_CreateFromStringUtf8Array) \
	{ \
		P_GET_TARRAY_REF(FString,Z_Param_Out_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryByteDataEntry**)Z_Param__Result=ULowEntryExtendedStandardLibrary::ByteDataEntry_CreateFromStringUtf8Array(Z_Param_Out_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execByteDataEntry_CreateFromBooleanArray) \
	{ \
		P_GET_TARRAY_REF(bool,Z_Param_Out_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryByteDataEntry**)Z_Param__Result=ULowEntryExtendedStandardLibrary::ByteDataEntry_CreateFromBooleanArray(Z_Param_Out_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execByteDataEntry_CreateFromDoubleBytesArray) \
	{ \
		P_GET_TARRAY_REF(ULowEntryDouble*,Z_Param_Out_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryByteDataEntry**)Z_Param__Result=ULowEntryExtendedStandardLibrary::ByteDataEntry_CreateFromDoubleBytesArray(Z_Param_Out_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execByteDataEntry_CreateFromFloatArray) \
	{ \
		P_GET_TARRAY_REF(float,Z_Param_Out_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryByteDataEntry**)Z_Param__Result=ULowEntryExtendedStandardLibrary::ByteDataEntry_CreateFromFloatArray(Z_Param_Out_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execByteDataEntry_CreateFromLongBytesArray) \
	{ \
		P_GET_TARRAY_REF(ULowEntryLong*,Z_Param_Out_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryByteDataEntry**)Z_Param__Result=ULowEntryExtendedStandardLibrary::ByteDataEntry_CreateFromLongBytesArray(Z_Param_Out_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execByteDataEntry_CreateFromPositiveInteger3Array) \
	{ \
		P_GET_TARRAY_REF(int32,Z_Param_Out_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryByteDataEntry**)Z_Param__Result=ULowEntryExtendedStandardLibrary::ByteDataEntry_CreateFromPositiveInteger3Array(Z_Param_Out_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execByteDataEntry_CreateFromPositiveInteger2Array) \
	{ \
		P_GET_TARRAY_REF(int32,Z_Param_Out_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryByteDataEntry**)Z_Param__Result=ULowEntryExtendedStandardLibrary::ByteDataEntry_CreateFromPositiveInteger2Array(Z_Param_Out_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execByteDataEntry_CreateFromPositiveInteger1Array) \
	{ \
		P_GET_TARRAY_REF(int32,Z_Param_Out_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryByteDataEntry**)Z_Param__Result=ULowEntryExtendedStandardLibrary::ByteDataEntry_CreateFromPositiveInteger1Array(Z_Param_Out_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execByteDataEntry_CreateFromIntegerArray) \
	{ \
		P_GET_TARRAY_REF(int32,Z_Param_Out_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryByteDataEntry**)Z_Param__Result=ULowEntryExtendedStandardLibrary::ByteDataEntry_CreateFromIntegerArray(Z_Param_Out_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execByteDataEntry_CreateFromByteArray) \
	{ \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryByteDataEntry**)Z_Param__Result=ULowEntryExtendedStandardLibrary::ByteDataEntry_CreateFromByteArray(Z_Param_Out_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execByteDataEntry_CreateFromStringUtf8) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryByteDataEntry**)Z_Param__Result=ULowEntryExtendedStandardLibrary::ByteDataEntry_CreateFromStringUtf8(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execByteDataEntry_CreateFromBoolean) \
	{ \
		P_GET_UBOOL(Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryByteDataEntry**)Z_Param__Result=ULowEntryExtendedStandardLibrary::ByteDataEntry_CreateFromBoolean(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execByteDataEntry_CreateFromDoubleBytes) \
	{ \
		P_GET_OBJECT(ULowEntryDouble,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryByteDataEntry**)Z_Param__Result=ULowEntryExtendedStandardLibrary::ByteDataEntry_CreateFromDoubleBytes(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execByteDataEntry_CreateFromFloat) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryByteDataEntry**)Z_Param__Result=ULowEntryExtendedStandardLibrary::ByteDataEntry_CreateFromFloat(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execByteDataEntry_CreateFromLongBytes) \
	{ \
		P_GET_OBJECT(ULowEntryLong,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryByteDataEntry**)Z_Param__Result=ULowEntryExtendedStandardLibrary::ByteDataEntry_CreateFromLongBytes(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execByteDataEntry_CreateFromPositiveInteger3) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryByteDataEntry**)Z_Param__Result=ULowEntryExtendedStandardLibrary::ByteDataEntry_CreateFromPositiveInteger3(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execByteDataEntry_CreateFromPositiveInteger2) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryByteDataEntry**)Z_Param__Result=ULowEntryExtendedStandardLibrary::ByteDataEntry_CreateFromPositiveInteger2(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execByteDataEntry_CreateFromPositiveInteger1) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryByteDataEntry**)Z_Param__Result=ULowEntryExtendedStandardLibrary::ByteDataEntry_CreateFromPositiveInteger1(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execByteDataEntry_CreateFromInteger) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryByteDataEntry**)Z_Param__Result=ULowEntryExtendedStandardLibrary::ByteDataEntry_CreateFromInteger(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execByteDataEntry_CreateFromByte) \
	{ \
		P_GET_PROPERTY(UByteProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryByteDataEntry**)Z_Param__Result=ULowEntryExtendedStandardLibrary::ByteDataEntry_CreateFromByte(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execByteDataWriter_GetBytes) \
	{ \
		P_GET_OBJECT(ULowEntryByteDataWriter,Z_Param_ByteDataWriter); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<uint8>*)Z_Param__Result=ULowEntryExtendedStandardLibrary::ByteDataWriter_GetBytes(Z_Param_ByteDataWriter); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execByteDataWriter_CreateFromEntryArrayPure) \
	{ \
		P_GET_TARRAY_REF(ULowEntryByteDataEntry*,Z_Param_Out_Array); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryByteDataWriter**)Z_Param__Result=ULowEntryExtendedStandardLibrary::ByteDataWriter_CreateFromEntryArrayPure(Z_Param_Out_Array); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execByteDataWriter_CreateFromEntryArray) \
	{ \
		P_GET_TARRAY_REF(ULowEntryByteDataEntry*,Z_Param_Out_Array); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryByteDataWriter**)Z_Param__Result=ULowEntryExtendedStandardLibrary::ByteDataWriter_CreateFromEntryArray(Z_Param_Out_Array); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execByteDataReader_Create) \
	{ \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_Bytes); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Index); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Length); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryByteDataReader**)Z_Param__Result=ULowEntryExtendedStandardLibrary::ByteDataReader_Create(Z_Param_Out_Bytes,Z_Param_Index,Z_Param_Length); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execTickSeconds) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_STRUCT(FLatentActionInfo,Z_Param_LatentInfo); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Ticks); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_SecondsInterval); \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_Tick); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::TickSeconds(Z_Param_WorldContextObject,Z_Param_LatentInfo,Z_Param_Ticks,Z_Param_SecondsInterval,Z_Param_Out_Tick); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execTickFrames) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_STRUCT(FLatentActionInfo,Z_Param_LatentInfo); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Ticks); \
		P_GET_PROPERTY(UIntProperty,Z_Param_FramesInterval); \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_Tick); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::TickFrames(Z_Param_WorldContextObject,Z_Param_LatentInfo,Z_Param_Ticks,Z_Param_FramesInterval,Z_Param_Out_Tick); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execChangeMap) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_PROPERTY(UStrProperty,Z_Param_Map); \
		P_GET_PROPERTY(UStrProperty,Z_Param_Args); \
		P_GET_OBJECT(APlayerController,Z_Param_SpecificPlayer); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::ChangeMap(Z_Param_WorldContextObject,Z_Param_Map,Z_Param_Args,Z_Param_SpecificPlayer); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execServerChangeMap) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_PROPERTY(UStrProperty,Z_Param_Map); \
		P_GET_PROPERTY(UStrProperty,Z_Param_Args); \
		P_GET_OBJECT(APlayerController,Z_Param_SpecificPlayer); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::ServerChangeMap(Z_Param_WorldContextObject,Z_Param_Map,Z_Param_Args,Z_Param_SpecificPlayer); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execJoinGame) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_PROPERTY(UStrProperty,Z_Param_ServerAddress); \
		P_GET_PROPERTY(UStrProperty,Z_Param_Args); \
		P_GET_OBJECT(APlayerController,Z_Param_SpecificPlayer); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::JoinGame(Z_Param_WorldContextObject,Z_Param_ServerAddress,Z_Param_Args,Z_Param_SpecificPlayer); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execHostGame) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_PROPERTY(UStrProperty,Z_Param_Map); \
		P_GET_PROPERTY(UStrProperty,Z_Param_Args); \
		P_GET_OBJECT(APlayerController,Z_Param_SpecificPlayer); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::HostGame(Z_Param_WorldContextObject,Z_Param_Map,Z_Param_Args,Z_Param_SpecificPlayer); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCrash) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::Crash(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRegexReplace) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_String); \
		P_GET_PROPERTY(UStrProperty,Z_Param_Pattern); \
		P_GET_PROPERTY(UStrProperty,Z_Param_Replacement); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=ULowEntryExtendedStandardLibrary::RegexReplace(Z_Param_String,Z_Param_Pattern,Z_Param_Replacement); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRegexGetMatches) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_String); \
		P_GET_PROPERTY(UStrProperty,Z_Param_Pattern); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<FLowEntryRegexMatch>*)Z_Param__Result=ULowEntryExtendedStandardLibrary::RegexGetMatches(Z_Param_String,Z_Param_Pattern); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRegexCount) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_String); \
		P_GET_PROPERTY(UStrProperty,Z_Param_Pattern); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=ULowEntryExtendedStandardLibrary::RegexCount(Z_Param_String,Z_Param_Pattern); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRegexMatch) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_String); \
		P_GET_PROPERTY(UStrProperty,Z_Param_Pattern); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::RegexMatch(Z_Param_String,Z_Param_Pattern); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execReplaceCharactersExcept) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_String); \
		P_GET_PROPERTY(UStrProperty,Z_Param_ReplacementCharacter); \
		P_GET_UBOOL(Z_Param_KeepLowercaseAZ); \
		P_GET_UBOOL(Z_Param_KeepUppercaseAZ); \
		P_GET_UBOOL(Z_Param_KeepNumbers); \
		P_GET_PROPERTY(UStrProperty,Z_Param_OtherCharactersToKeep); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=ULowEntryExtendedStandardLibrary::ReplaceCharactersExcept(Z_Param_String,Z_Param_ReplacementCharacter,Z_Param_KeepLowercaseAZ,Z_Param_KeepUppercaseAZ,Z_Param_KeepNumbers,Z_Param_OtherCharactersToKeep); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRemoveCharactersExcept) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_String); \
		P_GET_UBOOL(Z_Param_KeepLowercaseAZ); \
		P_GET_UBOOL(Z_Param_KeepUppercaseAZ); \
		P_GET_UBOOL(Z_Param_KeepNumbers); \
		P_GET_PROPERTY(UStrProperty,Z_Param_OtherCharactersToKeep); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=ULowEntryExtendedStandardLibrary::RemoveCharactersExcept(Z_Param_String,Z_Param_KeepLowercaseAZ,Z_Param_KeepUppercaseAZ,Z_Param_KeepNumbers,Z_Param_OtherCharactersToKeep); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCreateString) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Length); \
		P_GET_PROPERTY(UStrProperty,Z_Param_Filler); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=ULowEntryExtendedStandardLibrary::CreateString(Z_Param_Length,Z_Param_Filler); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execNextQueueExecution) \
	{ \
		P_GET_OBJECT(ULowEntryExecutionQueue,Z_Param_Queue); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::NextQueueExecution(Z_Param_Queue); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execQueueExecutions) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_OBJECT_REF(ULowEntryExecutionQueue,Z_Param_Out_Queue); \
		P_GET_STRUCT(FLatentActionInfo,Z_Param_LatentInfo); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::QueueExecutions(Z_Param_WorldContextObject,Z_Param_Out_Queue,Z_Param_LatentInfo); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRetriggerableRandomDelayFrames) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_PROPERTY(UIntProperty,Z_Param_MinFrames); \
		P_GET_PROPERTY(UIntProperty,Z_Param_MaxFrames); \
		P_GET_STRUCT(FLatentActionInfo,Z_Param_LatentInfo); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::RetriggerableRandomDelayFrames(Z_Param_WorldContextObject,Z_Param_MinFrames,Z_Param_MaxFrames,Z_Param_LatentInfo); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRandomDelayFrames) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_PROPERTY(UIntProperty,Z_Param_MinFrames); \
		P_GET_PROPERTY(UIntProperty,Z_Param_MaxFrames); \
		P_GET_STRUCT(FLatentActionInfo,Z_Param_LatentInfo); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::RandomDelayFrames(Z_Param_WorldContextObject,Z_Param_MinFrames,Z_Param_MaxFrames,Z_Param_LatentInfo); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRetriggerableDelayFrames) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Frames); \
		P_GET_STRUCT(FLatentActionInfo,Z_Param_LatentInfo); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::RetriggerableDelayFrames(Z_Param_WorldContextObject,Z_Param_Frames,Z_Param_LatentInfo); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDelayFrames) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Frames); \
		P_GET_STRUCT(FLatentActionInfo,Z_Param_LatentInfo); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::DelayFrames(Z_Param_WorldContextObject,Z_Param_Frames,Z_Param_LatentInfo); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRetriggerableRandomDelay) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_MinDuration); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_MaxDuration); \
		P_GET_STRUCT(FLatentActionInfo,Z_Param_LatentInfo); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::RetriggerableRandomDelay(Z_Param_WorldContextObject,Z_Param_MinDuration,Z_Param_MaxDuration,Z_Param_LatentInfo); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRandomDelay) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_MinDuration); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_MaxDuration); \
		P_GET_STRUCT(FLatentActionInfo,Z_Param_LatentInfo); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::RandomDelay(Z_Param_WorldContextObject,Z_Param_MinDuration,Z_Param_MaxDuration,Z_Param_LatentInfo); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSortObjectArrayDirectly) \
	{ \
		P_GET_TARRAY_REF(UObject*,Z_Param_Out_ObjectArray); \
		P_GET_PROPERTY(UDelegateProperty,Z_Param_Comparator); \
		P_GET_UBOOL(Z_Param_Reversed); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::SortObjectArrayDirectly(Z_Param_Out_ObjectArray,FDelegateULowEntryExtendedStandardLibraryCompareObjects(Z_Param_Comparator),Z_Param_Reversed); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSortObjectArray) \
	{ \
		P_GET_TARRAY_REF(UObject*,Z_Param_Out_ObjectArray); \
		P_GET_PROPERTY(UDelegateProperty,Z_Param_Comparator); \
		P_GET_UBOOL(Z_Param_Reversed); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<UObject*>*)Z_Param__Result=ULowEntryExtendedStandardLibrary::SortObjectArray(Z_Param_Out_ObjectArray,FDelegateULowEntryExtendedStandardLibraryCompareObjects(Z_Param_Comparator),Z_Param_Reversed); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSortTimespanArrayDirectly) \
	{ \
		P_GET_TARRAY_REF(FTimespan,Z_Param_Out_TimespanArray); \
		P_GET_UBOOL(Z_Param_Reversed); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::SortTimespanArrayDirectly(Z_Param_Out_TimespanArray,Z_Param_Reversed); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSortTimespanArray) \
	{ \
		P_GET_TARRAY_REF(FTimespan,Z_Param_Out_TimespanArray); \
		P_GET_UBOOL(Z_Param_Reversed); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<FTimespan>*)Z_Param__Result=ULowEntryExtendedStandardLibrary::SortTimespanArray(Z_Param_Out_TimespanArray,Z_Param_Reversed); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSortDateTimeArrayDirectly) \
	{ \
		P_GET_TARRAY_REF(FDateTime,Z_Param_Out_DateTimeArray); \
		P_GET_UBOOL(Z_Param_Reversed); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::SortDateTimeArrayDirectly(Z_Param_Out_DateTimeArray,Z_Param_Reversed); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSortDateTimeArray) \
	{ \
		P_GET_TARRAY_REF(FDateTime,Z_Param_Out_DateTimeArray); \
		P_GET_UBOOL(Z_Param_Reversed); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<FDateTime>*)Z_Param__Result=ULowEntryExtendedStandardLibrary::SortDateTimeArray(Z_Param_Out_DateTimeArray,Z_Param_Reversed); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSortByteArrayDirectly) \
	{ \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_ByteArray); \
		P_GET_UBOOL(Z_Param_Reversed); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::SortByteArrayDirectly(Z_Param_Out_ByteArray,Z_Param_Reversed); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSortByteArray) \
	{ \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_ByteArray); \
		P_GET_UBOOL(Z_Param_Reversed); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<uint8>*)Z_Param__Result=ULowEntryExtendedStandardLibrary::SortByteArray(Z_Param_Out_ByteArray,Z_Param_Reversed); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSortFloatArrayDirectly) \
	{ \
		P_GET_TARRAY_REF(float,Z_Param_Out_FloatArray); \
		P_GET_UBOOL(Z_Param_Reversed); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::SortFloatArrayDirectly(Z_Param_Out_FloatArray,Z_Param_Reversed); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSortFloatArray) \
	{ \
		P_GET_TARRAY_REF(float,Z_Param_Out_FloatArray); \
		P_GET_UBOOL(Z_Param_Reversed); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<float>*)Z_Param__Result=ULowEntryExtendedStandardLibrary::SortFloatArray(Z_Param_Out_FloatArray,Z_Param_Reversed); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSortIntegerArrayDirectly) \
	{ \
		P_GET_TARRAY_REF(int32,Z_Param_Out_IntegerArray); \
		P_GET_UBOOL(Z_Param_Reversed); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::SortIntegerArrayDirectly(Z_Param_Out_IntegerArray,Z_Param_Reversed); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSortIntegerArray) \
	{ \
		P_GET_TARRAY_REF(int32,Z_Param_Out_IntegerArray); \
		P_GET_UBOOL(Z_Param_Reversed); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<int32>*)Z_Param__Result=ULowEntryExtendedStandardLibrary::SortIntegerArray(Z_Param_Out_IntegerArray,Z_Param_Reversed); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSortStringArrayDirectly) \
	{ \
		P_GET_TARRAY_REF(FString,Z_Param_Out_StringArray); \
		P_GET_UBOOL(Z_Param_Reversed); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::SortStringArrayDirectly(Z_Param_Out_StringArray,Z_Param_Reversed); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSortStringArray) \
	{ \
		P_GET_TARRAY_REF(FString,Z_Param_Out_StringArray); \
		P_GET_UBOOL(Z_Param_Reversed); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<FString>*)Z_Param__Result=ULowEntryExtendedStandardLibrary::SortStringArray(Z_Param_Out_StringArray,Z_Param_Reversed); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConvertUtcDateToLocalDate) \
	{ \
		P_GET_STRUCT_REF(FDateTime,Z_Param_Out_Utc); \
		P_GET_STRUCT_REF(FDateTime,Z_Param_Out_Local); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::ConvertUtcDateToLocalDate(Z_Param_Out_Utc,Z_Param_Out_Local); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConvertLocalDateToUtcDate) \
	{ \
		P_GET_STRUCT_REF(FDateTime,Z_Param_Out_Local); \
		P_GET_STRUCT_REF(FDateTime,Z_Param_Out_Utc); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::ConvertLocalDateToUtcDate(Z_Param_Out_Local,Z_Param_Out_Utc); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDateTime_FromUnixTimestamp) \
	{ \
		P_GET_OBJECT(ULowEntryLong,Z_Param_Timestamp); \
		P_GET_STRUCT_REF(FDateTime,Z_Param_Out_DateTime); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::DateTime_FromUnixTimestamp(Z_Param_Timestamp,Z_Param_Out_DateTime); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDateTime_ToUnixTimestamp) \
	{ \
		P_GET_STRUCT_REF(FDateTime,Z_Param_Out_DateTime); \
		P_GET_OBJECT_REF(ULowEntryLong,Z_Param_Out_Timestamp); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::DateTime_ToUnixTimestamp(Z_Param_Out_DateTime,Z_Param_Out_Timestamp); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDateTime_ToString) \
	{ \
		P_GET_STRUCT_REF(FDateTime,Z_Param_Out_DateTime); \
		P_GET_PROPERTY_REF(UStrProperty,Z_Param_Out_String); \
		P_GET_PROPERTY(UStrProperty,Z_Param_Format); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::DateTime_ToString(Z_Param_Out_DateTime,Z_Param_Out_String,Z_Param_Format); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDateTime_ToIso8601) \
	{ \
		P_GET_STRUCT_REF(FDateTime,Z_Param_Out_DateTime); \
		P_GET_PROPERTY_REF(UStrProperty,Z_Param_Out_String); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::DateTime_ToIso8601(Z_Param_Out_DateTime,Z_Param_Out_String); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execMinOfTimespanArray) \
	{ \
		P_GET_TARRAY_REF(FTimespan,Z_Param_Out_TimespanArray); \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_IndexOfMinValue); \
		P_GET_STRUCT_REF(FTimespan,Z_Param_Out_MinValue); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::MinOfTimespanArray(Z_Param_Out_TimespanArray,Z_Param_Out_IndexOfMinValue,Z_Param_Out_MinValue); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execMaxOfTimespanArray) \
	{ \
		P_GET_TARRAY_REF(FTimespan,Z_Param_Out_TimespanArray); \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_IndexOfMaxValue); \
		P_GET_STRUCT_REF(FTimespan,Z_Param_Out_MaxValue); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::MaxOfTimespanArray(Z_Param_Out_TimespanArray,Z_Param_Out_IndexOfMaxValue,Z_Param_Out_MaxValue); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execMinOfDateTimeArray) \
	{ \
		P_GET_TARRAY_REF(FDateTime,Z_Param_Out_DateTimeArray); \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_IndexOfMinValue); \
		P_GET_STRUCT_REF(FDateTime,Z_Param_Out_MinValue); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::MinOfDateTimeArray(Z_Param_Out_DateTimeArray,Z_Param_Out_IndexOfMinValue,Z_Param_Out_MinValue); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execMaxOfDateTimeArray) \
	{ \
		P_GET_TARRAY_REF(FDateTime,Z_Param_Out_DateTimeArray); \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_IndexOfMaxValue); \
		P_GET_STRUCT_REF(FDateTime,Z_Param_Out_MaxValue); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::MaxOfDateTimeArray(Z_Param_Out_DateTimeArray,Z_Param_Out_IndexOfMaxValue,Z_Param_Out_MaxValue); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execMinOfStringArray) \
	{ \
		P_GET_TARRAY_REF(FString,Z_Param_Out_StringArray); \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_IndexOfMinValue); \
		P_GET_PROPERTY_REF(UStrProperty,Z_Param_Out_MinValue); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::MinOfStringArray(Z_Param_Out_StringArray,Z_Param_Out_IndexOfMinValue,Z_Param_Out_MinValue); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execMaxOfStringArray) \
	{ \
		P_GET_TARRAY_REF(FString,Z_Param_Out_StringArray); \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_IndexOfMaxValue); \
		P_GET_PROPERTY_REF(UStrProperty,Z_Param_Out_MaxValue); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::MaxOfStringArray(Z_Param_Out_StringArray,Z_Param_Out_IndexOfMaxValue,Z_Param_Out_MaxValue); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execFloorDecimals) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Number); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Decimals); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=ULowEntryExtendedStandardLibrary::FloorDecimals(Z_Param_Number,Z_Param_Decimals); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCeilDecimals) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Number); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Decimals); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=ULowEntryExtendedStandardLibrary::CeilDecimals(Z_Param_Number,Z_Param_Decimals); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRoundDecimals) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Number); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Decimals); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=ULowEntryExtendedStandardLibrary::RoundDecimals(Z_Param_Number,Z_Param_Decimals); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGreaterEqualByteFloat) \
	{ \
		P_GET_PROPERTY(UByteProperty,Z_Param_A); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_B); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::GreaterEqualByteFloat(Z_Param_A,Z_Param_B); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLessEqualByteFloat) \
	{ \
		P_GET_PROPERTY(UByteProperty,Z_Param_A); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_B); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::LessEqualByteFloat(Z_Param_A,Z_Param_B); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGreaterByteFloat) \
	{ \
		P_GET_PROPERTY(UByteProperty,Z_Param_A); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_B); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::GreaterByteFloat(Z_Param_A,Z_Param_B); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLessByteFloat) \
	{ \
		P_GET_PROPERTY(UByteProperty,Z_Param_A); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_B); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::LessByteFloat(Z_Param_A,Z_Param_B); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGreaterEqualByteInteger) \
	{ \
		P_GET_PROPERTY(UByteProperty,Z_Param_A); \
		P_GET_PROPERTY(UIntProperty,Z_Param_B); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::GreaterEqualByteInteger(Z_Param_A,Z_Param_B); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLessEqualByteInteger) \
	{ \
		P_GET_PROPERTY(UByteProperty,Z_Param_A); \
		P_GET_PROPERTY(UIntProperty,Z_Param_B); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::LessEqualByteInteger(Z_Param_A,Z_Param_B); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGreaterByteInteger) \
	{ \
		P_GET_PROPERTY(UByteProperty,Z_Param_A); \
		P_GET_PROPERTY(UIntProperty,Z_Param_B); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::GreaterByteInteger(Z_Param_A,Z_Param_B); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLessByteInteger) \
	{ \
		P_GET_PROPERTY(UByteProperty,Z_Param_A); \
		P_GET_PROPERTY(UIntProperty,Z_Param_B); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::LessByteInteger(Z_Param_A,Z_Param_B); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGreaterEqualFloatByte) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_A); \
		P_GET_PROPERTY(UByteProperty,Z_Param_B); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::GreaterEqualFloatByte(Z_Param_A,Z_Param_B); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLessEqualFloatByte) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_A); \
		P_GET_PROPERTY(UByteProperty,Z_Param_B); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::LessEqualFloatByte(Z_Param_A,Z_Param_B); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGreaterFloatByte) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_A); \
		P_GET_PROPERTY(UByteProperty,Z_Param_B); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::GreaterFloatByte(Z_Param_A,Z_Param_B); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLessFloatByte) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_A); \
		P_GET_PROPERTY(UByteProperty,Z_Param_B); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::LessFloatByte(Z_Param_A,Z_Param_B); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGreaterEqualFloatInteger) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_A); \
		P_GET_PROPERTY(UIntProperty,Z_Param_B); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::GreaterEqualFloatInteger(Z_Param_A,Z_Param_B); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLessEqualFloatInteger) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_A); \
		P_GET_PROPERTY(UIntProperty,Z_Param_B); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::LessEqualFloatInteger(Z_Param_A,Z_Param_B); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGreaterFloatInteger) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_A); \
		P_GET_PROPERTY(UIntProperty,Z_Param_B); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::GreaterFloatInteger(Z_Param_A,Z_Param_B); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLessFloatInteger) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_A); \
		P_GET_PROPERTY(UIntProperty,Z_Param_B); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::LessFloatInteger(Z_Param_A,Z_Param_B); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGreaterEqualIntegerByte) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_A); \
		P_GET_PROPERTY(UByteProperty,Z_Param_B); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::GreaterEqualIntegerByte(Z_Param_A,Z_Param_B); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLessEqualIntegerByte) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_A); \
		P_GET_PROPERTY(UByteProperty,Z_Param_B); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::LessEqualIntegerByte(Z_Param_A,Z_Param_B); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGreaterIntegerByte) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_A); \
		P_GET_PROPERTY(UByteProperty,Z_Param_B); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::GreaterIntegerByte(Z_Param_A,Z_Param_B); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLessIntegerByte) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_A); \
		P_GET_PROPERTY(UByteProperty,Z_Param_B); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::LessIntegerByte(Z_Param_A,Z_Param_B); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGreaterEqualIntegerFloat) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_A); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_B); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::GreaterEqualIntegerFloat(Z_Param_A,Z_Param_B); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLessEqualIntegerFloat) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_A); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_B); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::LessEqualIntegerFloat(Z_Param_A,Z_Param_B); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGreaterIntegerFloat) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_A); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_B); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::GreaterIntegerFloat(Z_Param_A,Z_Param_B); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLessIntegerFloat) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_A); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_B); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::LessIntegerFloat(Z_Param_A,Z_Param_B); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGreaterEqualStringString) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_A); \
		P_GET_PROPERTY(UStrProperty,Z_Param_B); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::GreaterEqualStringString(Z_Param_A,Z_Param_B); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLessEqualStringString) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_A); \
		P_GET_PROPERTY(UStrProperty,Z_Param_B); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::LessEqualStringString(Z_Param_A,Z_Param_B); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGreaterStringString) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_A); \
		P_GET_PROPERTY(UStrProperty,Z_Param_B); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::GreaterStringString(Z_Param_A,Z_Param_B); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLessStringString) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_A); \
		P_GET_PROPERTY(UStrProperty,Z_Param_B); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::LessStringString(Z_Param_A,Z_Param_B); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execMaxString) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_A); \
		P_GET_PROPERTY(UStrProperty,Z_Param_B); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=ULowEntryExtendedStandardLibrary::MaxString(Z_Param_A,Z_Param_B); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execMinString) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_A); \
		P_GET_PROPERTY(UStrProperty,Z_Param_B); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=ULowEntryExtendedStandardLibrary::MinString(Z_Param_A,Z_Param_B); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execTabCharacter) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=ULowEntryExtendedStandardLibrary::TabCharacter(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCarriageReturnCharacter) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=ULowEntryExtendedStandardLibrary::CarriageReturnCharacter(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execWindowsNewlineCharacter) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=ULowEntryExtendedStandardLibrary::WindowsNewlineCharacter(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execNewlineCharacter) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=ULowEntryExtendedStandardLibrary::NewlineCharacter(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execParsedHashcashIsValid) \
	{ \
		P_GET_OBJECT(ULowEntryParsedHashcash,Z_Param_Target); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::ParsedHashcashIsValid(Z_Param_Target); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execHashcashParse) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Hash); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryParsedHashcash**)Z_Param__Result=ULowEntryExtendedStandardLibrary::HashcashParse(Z_Param_Hash); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execHashcashParseArray) \
	{ \
		P_GET_TARRAY_REF(FString,Z_Param_Out_Hashes); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<ULowEntryParsedHashcash*>*)Z_Param__Result=ULowEntryExtendedStandardLibrary::HashcashParseArray(Z_Param_Out_Hashes); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execHashcashCustomCreationDate) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Resource); \
		P_GET_STRUCT_REF(FDateTime,Z_Param_Out_UtcDate); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Bits); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=ULowEntryExtendedStandardLibrary::HashcashCustomCreationDate(Z_Param_Resource,Z_Param_Out_UtcDate,Z_Param_Bits); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execHashcash) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Resource); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Bits); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=ULowEntryExtendedStandardLibrary::Hashcash(Z_Param_Resource,Z_Param_Bits); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execHashcashArrayCustomCreationDate) \
	{ \
		P_GET_TARRAY_REF(FString,Z_Param_Out_Resources); \
		P_GET_STRUCT_REF(FDateTime,Z_Param_Out_UtcDate); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Bits); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<FString>*)Z_Param__Result=ULowEntryExtendedStandardLibrary::HashcashArrayCustomCreationDate(Z_Param_Out_Resources,Z_Param_Out_UtcDate,Z_Param_Bits); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execHashcashArray) \
	{ \
		P_GET_TARRAY_REF(FString,Z_Param_Out_Resources); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Bits); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<FString>*)Z_Param__Result=ULowEntryExtendedStandardLibrary::HashcashArray(Z_Param_Out_Resources,Z_Param_Bits); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execHMAC) \
	{ \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_ByteArray); \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_Key); \
		P_GET_ENUM(ELowEntryHmacAlgorithm,Z_Param_Algorithm); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Index); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Length); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<uint8>*)Z_Param__Result=ULowEntryExtendedStandardLibrary::HMAC(Z_Param_Out_ByteArray,Z_Param_Out_Key,ELowEntryHmacAlgorithm(Z_Param_Algorithm),Z_Param_Index,Z_Param_Length); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBCrypt) \
	{ \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_ByteArray); \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_Salt); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Strength); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Index); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Length); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<uint8>*)Z_Param__Result=ULowEntryExtendedStandardLibrary::BCrypt(Z_Param_Out_ByteArray,Z_Param_Out_Salt,Z_Param_Strength,Z_Param_Index,Z_Param_Length); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSha512) \
	{ \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_ByteArray); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Index); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Length); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<uint8>*)Z_Param__Result=ULowEntryExtendedStandardLibrary::Sha512(Z_Param_Out_ByteArray,Z_Param_Index,Z_Param_Length); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSha256) \
	{ \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_ByteArray); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Index); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Length); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<uint8>*)Z_Param__Result=ULowEntryExtendedStandardLibrary::Sha256(Z_Param_Out_ByteArray,Z_Param_Index,Z_Param_Length); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSha1) \
	{ \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_ByteArray); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Index); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Length); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<uint8>*)Z_Param__Result=ULowEntryExtendedStandardLibrary::Sha1(Z_Param_Out_ByteArray,Z_Param_Index,Z_Param_Length); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execMd5) \
	{ \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_ByteArray); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Index); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Length); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<uint8>*)Z_Param__Result=ULowEntryExtendedStandardLibrary::Md5(Z_Param_Out_ByteArray,Z_Param_Index,Z_Param_Length); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execPearson) \
	{ \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_ByteArray); \
		P_GET_PROPERTY(UIntProperty,Z_Param_HashLength); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Index); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Length); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<uint8>*)Z_Param__Result=ULowEntryExtendedStandardLibrary::Pearson(Z_Param_Out_ByteArray,Z_Param_HashLength,Z_Param_Index,Z_Param_Length); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSceneCaptureComponent2D_SetFov) \
	{ \
		P_GET_OBJECT(USceneCaptureComponent2D,Z_Param_SceneCaptureComponent2D); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Fov); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::SceneCaptureComponent2D_SetFov(Z_Param_SceneCaptureComponent2D,Z_Param_Fov); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSceneCaptureComponent2D_GetFov) \
	{ \
		P_GET_OBJECT(USceneCaptureComponent2D,Z_Param_SceneCaptureComponent2D); \
		P_GET_PROPERTY_REF(UFloatProperty,Z_Param_Out_Fov); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::SceneCaptureComponent2D_GetFov(Z_Param_SceneCaptureComponent2D,Z_Param_Out_Fov); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSceneCapture2D_SetFov) \
	{ \
		P_GET_OBJECT(ASceneCapture2D,Z_Param_SceneCapture2D); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Fov); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::SceneCapture2D_SetFov(Z_Param_SceneCapture2D,Z_Param_Fov); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSceneCapture2D_GetFov) \
	{ \
		P_GET_OBJECT(ASceneCapture2D,Z_Param_SceneCapture2D); \
		P_GET_PROPERTY_REF(UFloatProperty,Z_Param_Out_Fov); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::SceneCapture2D_GetFov(Z_Param_SceneCapture2D,Z_Param_Out_Fov); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execTextureUpdateResource) \
	{ \
		P_GET_OBJECT(UTexture,Z_Param_Texture); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::TextureUpdateResource(Z_Param_Texture); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLoadVideo) \
	{ \
		P_GET_OBJECT(UMediaSoundComponent,Z_Param_MediaSoundComponent); \
		P_GET_PROPERTY(UStrProperty,Z_Param_Url); \
		P_GET_UBOOL_REF(Z_Param_Out_Success); \
		P_GET_OBJECT_REF(UMediaPlayer,Z_Param_Out_MediaPlayer); \
		P_GET_OBJECT_REF(UMediaTexture,Z_Param_Out_MediaTexture); \
		P_GET_UBOOL(Z_Param_PlayOnOpen); \
		P_GET_UBOOL(Z_Param_Loop); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::LoadVideo(Z_Param_MediaSoundComponent,Z_Param_Url,Z_Param_Out_Success,Z_Param_Out_MediaPlayer,Z_Param_Out_MediaTexture,Z_Param_PlayOnOpen,Z_Param_Loop); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execTextureRenderTarget2DToPixels) \
	{ \
		P_GET_OBJECT(UTextureRenderTarget2D,Z_Param_TextureRenderTarget2D); \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_Width); \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_Height); \
		P_GET_TARRAY_REF(FColor,Z_Param_Out_Pixels); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::TextureRenderTarget2DToPixels(Z_Param_TextureRenderTarget2D,Z_Param_Out_Width,Z_Param_Out_Height,Z_Param_Out_Pixels); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSceneCaptureComponent2DToPixels) \
	{ \
		P_GET_OBJECT(USceneCaptureComponent2D,Z_Param_SceneCaptureComponent2D); \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_Width); \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_Height); \
		P_GET_TARRAY_REF(FColor,Z_Param_Out_Pixels); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::SceneCaptureComponent2DToPixels(Z_Param_SceneCaptureComponent2D,Z_Param_Out_Width,Z_Param_Out_Height,Z_Param_Out_Pixels); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSceneCapture2DToPixels) \
	{ \
		P_GET_OBJECT(ASceneCapture2D,Z_Param_SceneCapture2D); \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_Width); \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_Height); \
		P_GET_TARRAY_REF(FColor,Z_Param_Out_Pixels); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::SceneCapture2DToPixels(Z_Param_SceneCapture2D,Z_Param_Out_Width,Z_Param_Out_Height,Z_Param_Out_Pixels); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execTextureRenderTarget2DToBytes) \
	{ \
		P_GET_OBJECT(UTextureRenderTarget2D,Z_Param_TextureRenderTarget2D); \
		P_GET_ENUM(ELowEntryImageFormat,Z_Param_ImageFormat); \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_ByteArray); \
		P_GET_PROPERTY(UIntProperty,Z_Param_CompressionQuality); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::TextureRenderTarget2DToBytes(Z_Param_TextureRenderTarget2D,ELowEntryImageFormat(Z_Param_ImageFormat),Z_Param_Out_ByteArray,Z_Param_CompressionQuality); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSceneCaptureComponent2DToBytes) \
	{ \
		P_GET_OBJECT(USceneCaptureComponent2D,Z_Param_SceneCaptureComponent2D); \
		P_GET_ENUM(ELowEntryImageFormat,Z_Param_ImageFormat); \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_ByteArray); \
		P_GET_PROPERTY(UIntProperty,Z_Param_CompressionQuality); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::SceneCaptureComponent2DToBytes(Z_Param_SceneCaptureComponent2D,ELowEntryImageFormat(Z_Param_ImageFormat),Z_Param_Out_ByteArray,Z_Param_CompressionQuality); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSceneCapture2DToBytes) \
	{ \
		P_GET_OBJECT(ASceneCapture2D,Z_Param_SceneCapture2D); \
		P_GET_ENUM(ELowEntryImageFormat,Z_Param_ImageFormat); \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_ByteArray); \
		P_GET_PROPERTY(UIntProperty,Z_Param_CompressionQuality); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::SceneCapture2DToBytes(Z_Param_SceneCapture2D,ELowEntryImageFormat(Z_Param_ImageFormat),Z_Param_Out_ByteArray,Z_Param_CompressionQuality); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execPixelsToExistingTexture2D) \
	{ \
		P_GET_UBOOL_REF(Z_Param_Out_ReusedGivenTexture2D); \
		P_GET_OBJECT(UTexture2D,Z_Param_Texture2D); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Width); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Height); \
		P_GET_TARRAY_REF(FColor,Z_Param_Out_Pixels); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UTexture2D**)Z_Param__Result=ULowEntryExtendedStandardLibrary::PixelsToExistingTexture2D(Z_Param_Out_ReusedGivenTexture2D,Z_Param_Texture2D,Z_Param_Width,Z_Param_Height,Z_Param_Out_Pixels); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execPixelsToTexture2D) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Width); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Height); \
		P_GET_TARRAY_REF(FColor,Z_Param_Out_Pixels); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UTexture2D**)Z_Param__Result=ULowEntryExtendedStandardLibrary::PixelsToTexture2D(Z_Param_Width,Z_Param_Height,Z_Param_Out_Pixels); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execTexture2DToPixels) \
	{ \
		P_GET_OBJECT(UTexture2D,Z_Param_Texture2D); \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_Width); \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_Height); \
		P_GET_TARRAY_REF(FColor,Z_Param_Out_Pixels); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::Texture2DToPixels(Z_Param_Texture2D,Z_Param_Out_Width,Z_Param_Out_Height,Z_Param_Out_Pixels); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execPixelsToBytes) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Width); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Height); \
		P_GET_TARRAY_REF(FColor,Z_Param_Out_Pixels); \
		P_GET_ENUM(ELowEntryImageFormat,Z_Param_ImageFormat); \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_ByteArray); \
		P_GET_PROPERTY(UIntProperty,Z_Param_CompressionQuality); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::PixelsToBytes(Z_Param_Width,Z_Param_Height,Z_Param_Out_Pixels,ELowEntryImageFormat(Z_Param_ImageFormat),Z_Param_Out_ByteArray,Z_Param_CompressionQuality); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBytesToPixels) \
	{ \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_ByteArray); \
		P_GET_ENUM(ELowEntryImageFormat,Z_Param_ImageFormat); \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_Width); \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_Height); \
		P_GET_TARRAY_REF(FColor,Z_Param_Out_Pixels); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Index); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Length); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::BytesToPixels(Z_Param_Out_ByteArray,ELowEntryImageFormat(Z_Param_ImageFormat),Z_Param_Out_Width,Z_Param_Out_Height,Z_Param_Out_Pixels,Z_Param_Index,Z_Param_Length); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execTexture2DToBytes) \
	{ \
		P_GET_OBJECT(UTexture2D,Z_Param_Texture2D); \
		P_GET_ENUM(ELowEntryImageFormat,Z_Param_ImageFormat); \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_ByteArray); \
		P_GET_PROPERTY(UIntProperty,Z_Param_CompressionQuality); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::Texture2DToBytes(Z_Param_Texture2D,ELowEntryImageFormat(Z_Param_ImageFormat),Z_Param_Out_ByteArray,Z_Param_CompressionQuality); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBytesToExistingImage) \
	{ \
		P_GET_UBOOL_REF(Z_Param_Out_ReusedGivenTexture2D); \
		P_GET_OBJECT(UTexture2D,Z_Param_Texture2D); \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_ByteArray); \
		P_GET_ENUM(ELowEntryImageFormat,Z_Param_ImageFormat); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Index); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Length); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UTexture2D**)Z_Param__Result=ULowEntryExtendedStandardLibrary::BytesToExistingImage(Z_Param_Out_ReusedGivenTexture2D,Z_Param_Texture2D,Z_Param_Out_ByteArray,ELowEntryImageFormat(Z_Param_ImageFormat),Z_Param_Index,Z_Param_Length); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBytesToImage) \
	{ \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_ByteArray); \
		P_GET_ENUM(ELowEntryImageFormat,Z_Param_ImageFormat); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Index); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Length); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UTexture2D**)Z_Param__Result=ULowEntryExtendedStandardLibrary::BytesToImage(Z_Param_Out_ByteArray,ELowEntryImageFormat(Z_Param_ImageFormat),Z_Param_Index,Z_Param_Length); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetByteWithBitSet) \
	{ \
		P_GET_PROPERTY(UByteProperty,Z_Param_Byte); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Bit); \
		P_GET_UBOOL(Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(uint8*)Z_Param__Result=ULowEntryExtendedStandardLibrary::GetByteWithBitSet(Z_Param_Byte,Z_Param_Bit,Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsBitSet) \
	{ \
		P_GET_PROPERTY(UByteProperty,Z_Param_B); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Bit); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::IsBitSet(Z_Param_B,Z_Param_Bit); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execByteToBits) \
	{ \
		P_GET_PROPERTY(UByteProperty,Z_Param_Byte); \
		P_GET_UBOOL_REF(Z_Param_Out_Bit1); \
		P_GET_UBOOL_REF(Z_Param_Out_Bit2); \
		P_GET_UBOOL_REF(Z_Param_Out_Bit3); \
		P_GET_UBOOL_REF(Z_Param_Out_Bit4); \
		P_GET_UBOOL_REF(Z_Param_Out_Bit5); \
		P_GET_UBOOL_REF(Z_Param_Out_Bit6); \
		P_GET_UBOOL_REF(Z_Param_Out_Bit7); \
		P_GET_UBOOL_REF(Z_Param_Out_Bit8); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::ByteToBits(Z_Param_Byte,Z_Param_Out_Bit1,Z_Param_Out_Bit2,Z_Param_Out_Bit3,Z_Param_Out_Bit4,Z_Param_Out_Bit5,Z_Param_Out_Bit6,Z_Param_Out_Bit7,Z_Param_Out_Bit8); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBitsToByte) \
	{ \
		P_GET_UBOOL(Z_Param_Bit1); \
		P_GET_UBOOL(Z_Param_Bit2); \
		P_GET_UBOOL(Z_Param_Bit3); \
		P_GET_UBOOL(Z_Param_Bit4); \
		P_GET_UBOOL(Z_Param_Bit5); \
		P_GET_UBOOL(Z_Param_Bit6); \
		P_GET_UBOOL(Z_Param_Bit7); \
		P_GET_UBOOL(Z_Param_Bit8); \
		P_GET_PROPERTY_REF(UByteProperty,Z_Param_Out_Byte); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::BitsToByte(Z_Param_Bit1,Z_Param_Bit2,Z_Param_Bit3,Z_Param_Bit4,Z_Param_Bit5,Z_Param_Bit6,Z_Param_Bit7,Z_Param_Bit8,Z_Param_Out_Byte); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBytesToByte) \
	{ \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_ByteArray); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Index); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Length); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(uint8*)Z_Param__Result=ULowEntryExtendedStandardLibrary::BytesToByte(Z_Param_Out_ByteArray,Z_Param_Index,Z_Param_Length); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execByteToBytes) \
	{ \
		P_GET_PROPERTY(UByteProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<uint8>*)Z_Param__Result=ULowEntryExtendedStandardLibrary::ByteToBytes(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execParseStringIntoDoubleBytes) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_String); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryDouble**)Z_Param__Result=ULowEntryExtendedStandardLibrary::ParseStringIntoDoubleBytes(Z_Param_String); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBytesToDoubleBytes) \
	{ \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_ByteArray); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Index); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Length); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryDouble**)Z_Param__Result=ULowEntryExtendedStandardLibrary::BytesToDoubleBytes(Z_Param_Out_ByteArray,Z_Param_Index,Z_Param_Length); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBytesToFloat) \
	{ \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_ByteArray); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Index); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Length); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=ULowEntryExtendedStandardLibrary::BytesToFloat(Z_Param_Out_ByteArray,Z_Param_Index,Z_Param_Length); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execFloatToBytes) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<uint8>*)Z_Param__Result=ULowEntryExtendedStandardLibrary::FloatToBytes(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execParseStringIntoLongBytes) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_String); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryLong**)Z_Param__Result=ULowEntryExtendedStandardLibrary::ParseStringIntoLongBytes(Z_Param_String); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBytesToLongBytes) \
	{ \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_ByteArray); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Index); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Length); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryLong**)Z_Param__Result=ULowEntryExtendedStandardLibrary::BytesToLongBytes(Z_Param_Out_ByteArray,Z_Param_Index,Z_Param_Length); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBytesToInteger) \
	{ \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_ByteArray); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Index); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Length); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=ULowEntryExtendedStandardLibrary::BytesToInteger(Z_Param_Out_ByteArray,Z_Param_Index,Z_Param_Length); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIntegerToBytes) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<uint8>*)Z_Param__Result=ULowEntryExtendedStandardLibrary::IntegerToBytes(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execByteToBoolean) \
	{ \
		P_GET_PROPERTY(UByteProperty,Z_Param_Byte); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::ByteToBoolean(Z_Param_Byte); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBooleanToByte) \
	{ \
		P_GET_UBOOL(Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(uint8*)Z_Param__Result=ULowEntryExtendedStandardLibrary::BooleanToByte(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBytesToBoolean) \
	{ \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_ByteArray); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Index); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Length); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::BytesToBoolean(Z_Param_Out_ByteArray,Z_Param_Index,Z_Param_Length); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBooleanToBytes) \
	{ \
		P_GET_UBOOL(Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<uint8>*)Z_Param__Result=ULowEntryExtendedStandardLibrary::BooleanToBytes(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBytesToBitString) \
	{ \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_ByteArray); \
		P_GET_UBOOL(Z_Param_AddSpaces); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Index); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Length); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=ULowEntryExtendedStandardLibrary::BytesToBitString(Z_Param_Out_ByteArray,Z_Param_AddSpaces,Z_Param_Index,Z_Param_Length); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBitStringToBytes) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Bits); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<uint8>*)Z_Param__Result=ULowEntryExtendedStandardLibrary::BitStringToBytes(Z_Param_Bits); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBytesToBinary) \
	{ \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_ByteArray); \
		P_GET_UBOOL(Z_Param_AddSpaces); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Index); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Length); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=ULowEntryExtendedStandardLibrary::BytesToBinary(Z_Param_Out_ByteArray,Z_Param_AddSpaces,Z_Param_Index,Z_Param_Length); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBinaryToBytes) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Binary); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<uint8>*)Z_Param__Result=ULowEntryExtendedStandardLibrary::BinaryToBytes(Z_Param_Binary); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBytesToHex) \
	{ \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_ByteArray); \
		P_GET_UBOOL(Z_Param_AddSpaces); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Index); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Length); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=ULowEntryExtendedStandardLibrary::BytesToHex(Z_Param_Out_ByteArray,Z_Param_AddSpaces,Z_Param_Index,Z_Param_Length); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execHexToBytes) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Hex); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<uint8>*)Z_Param__Result=ULowEntryExtendedStandardLibrary::HexToBytes(Z_Param_Hex); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBytesToBase64Url) \
	{ \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_ByteArray); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Index); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Length); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=ULowEntryExtendedStandardLibrary::BytesToBase64Url(Z_Param_Out_ByteArray,Z_Param_Index,Z_Param_Length); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBase64UrlToBytes) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Base64Url); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<uint8>*)Z_Param__Result=ULowEntryExtendedStandardLibrary::Base64UrlToBytes(Z_Param_Base64Url); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBase64UrlToBase64) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Base64Url); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=ULowEntryExtendedStandardLibrary::Base64UrlToBase64(Z_Param_Base64Url); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBase64ToBase64Url) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Base64); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=ULowEntryExtendedStandardLibrary::Base64ToBase64Url(Z_Param_Base64); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBytesToBase64) \
	{ \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_ByteArray); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Index); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Length); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=ULowEntryExtendedStandardLibrary::BytesToBase64(Z_Param_Out_ByteArray,Z_Param_Index,Z_Param_Length); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBase64ToBytes) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Base64); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<uint8>*)Z_Param__Result=ULowEntryExtendedStandardLibrary::Base64ToBytes(Z_Param_Base64); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBytesToStringUtf8) \
	{ \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_ByteArray); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Index); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Length); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=ULowEntryExtendedStandardLibrary::BytesToStringUtf8(Z_Param_Out_ByteArray,Z_Param_Index,Z_Param_Length); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStringToBytesUtf8) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_String); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<uint8>*)Z_Param__Result=ULowEntryExtendedStandardLibrary::StringToBytesUtf8(Z_Param_String); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGenerateRandomBytesRandomLength) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_MinLength); \
		P_GET_PROPERTY(UIntProperty,Z_Param_MaxLength); \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_ByteArray); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::GenerateRandomBytesRandomLength(Z_Param_MinLength,Z_Param_MaxLength,Z_Param_Out_ByteArray); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGenerateRandomBytes) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Length); \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_ByteArray); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::GenerateRandomBytes(Z_Param_Length,Z_Param_Out_ByteArray); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBytesSubArray) \
	{ \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_ByteArray); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Index); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Length); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<uint8>*)Z_Param__Result=ULowEntryExtendedStandardLibrary::BytesSubArray(Z_Param_Out_ByteArray,Z_Param_Index,Z_Param_Length); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execMergeBytes) \
	{ \
		P_GET_TARRAY(uint8,Z_Param_A); \
		P_GET_TARRAY(uint8,Z_Param_B); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<uint8>*)Z_Param__Result=ULowEntryExtendedStandardLibrary::MergeBytes(Z_Param_A,Z_Param_B); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSplitBytes) \
	{ \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_ByteArray); \
		P_GET_PROPERTY(UIntProperty,Z_Param_LengthA); \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_A); \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_B); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::SplitBytes(Z_Param_Out_ByteArray,Z_Param_LengthA,Z_Param_Out_A,Z_Param_Out_B); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAreBytesEqual) \
	{ \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_A); \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_B); \
		P_GET_PROPERTY(UIntProperty,Z_Param_IndexA); \
		P_GET_PROPERTY(UIntProperty,Z_Param_LengthA); \
		P_GET_PROPERTY(UIntProperty,Z_Param_IndexB); \
		P_GET_PROPERTY(UIntProperty,Z_Param_LengthB); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::AreBytesEqual(Z_Param_Out_A,Z_Param_Out_B,Z_Param_IndexA,Z_Param_LengthA,Z_Param_IndexB,Z_Param_LengthB); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLatentAction_Create_String) \
	{ \
		P_GET_OBJECT_REF(ULowEntryLatentActionString,Z_Param_Out_LatentAction); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::LatentAction_Create_String(Z_Param_Out_LatentAction); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLatentAction_Create_Object) \
	{ \
		P_GET_OBJECT_REF(ULowEntryLatentActionObject,Z_Param_Out_LatentAction); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::LatentAction_Create_Object(Z_Param_Out_LatentAction); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLatentAction_Create_None) \
	{ \
		P_GET_OBJECT_REF(ULowEntryLatentActionNone,Z_Param_Out_LatentAction); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::LatentAction_Create_None(Z_Param_Out_LatentAction); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLatentAction_Create_Integer) \
	{ \
		P_GET_OBJECT_REF(ULowEntryLatentActionInteger,Z_Param_Out_LatentAction); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::LatentAction_Create_Integer(Z_Param_Out_LatentAction); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLatentAction_Create_Float) \
	{ \
		P_GET_OBJECT_REF(ULowEntryLatentActionFloat,Z_Param_Out_LatentAction); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::LatentAction_Create_Float(Z_Param_Out_LatentAction); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLatentAction_Create_Boolean) \
	{ \
		P_GET_OBJECT_REF(ULowEntryLatentActionBoolean,Z_Param_Out_LatentAction); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::LatentAction_Create_Boolean(Z_Param_Out_LatentAction); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSoundClass_GetPitch) \
	{ \
		P_GET_OBJECT(USoundClass,Z_Param_SoundClass); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=ULowEntryExtendedStandardLibrary::SoundClass_GetPitch(Z_Param_SoundClass); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSoundClass_SetPitch) \
	{ \
		P_GET_OBJECT(USoundClass,Z_Param_SoundClass); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Pitch); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::SoundClass_SetPitch(Z_Param_SoundClass,Z_Param_Pitch); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSoundClass_GetVolume) \
	{ \
		P_GET_OBJECT(USoundClass,Z_Param_SoundClass); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=ULowEntryExtendedStandardLibrary::SoundClass_GetVolume(Z_Param_SoundClass); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSoundClass_SetVolume) \
	{ \
		P_GET_OBJECT(USoundClass,Z_Param_SoundClass); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Volume); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::SoundClass_SetVolume(Z_Param_SoundClass,Z_Param_Volume); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetGenericTeamId) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_Target); \
		P_GET_PROPERTY(UByteProperty,Z_Param_TeamID); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::SetGenericTeamId(Z_Param_Target,Z_Param_TeamID); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetGenericTeamId) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_Target); \
		P_GET_PROPERTY_REF(UByteProperty,Z_Param_Out_TeamID); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::GetGenericTeamId(Z_Param_Target,Z_Param_Out_TeamID); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCreateObject) \
	{ \
		P_GET_OBJECT(UClass,Z_Param_Class); \
		P_GET_OBJECT_REF(UObject,Z_Param_Out_Object); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::CreateObject(Z_Param_Class,Z_Param_Out_Object); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetMaximumVolume) \
	{ \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_Volume); \
		P_GET_UBOOL_REF(Z_Param_Out_Success); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::GetMaximumVolume(Z_Param_Out_Volume,Z_Param_Out_Success); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetCurrentVolume) \
	{ \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_Volume); \
		P_GET_UBOOL_REF(Z_Param_Out_Success); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::GetCurrentVolume(Z_Param_Out_Volume,Z_Param_Out_Success); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAreAndroidHeadphonesPluggedIn) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::AreAndroidHeadphonesPluggedIn(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetAndroidNumberOfCores) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=ULowEntryExtendedStandardLibrary::GetAndroidNumberOfCores(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsAndroidDaydreamApplication) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::IsAndroidDaydreamApplication(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetAndroidBuildVersion) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=ULowEntryExtendedStandardLibrary::GetAndroidBuildVersion(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetAndroidGlVersion) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=ULowEntryExtendedStandardLibrary::GetAndroidGlVersion(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetAndroidGpuFamily) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=ULowEntryExtendedStandardLibrary::GetAndroidGpuFamily(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetAndroidDefaultLocale) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=ULowEntryExtendedStandardLibrary::GetAndroidDefaultLocale(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetAndroidOsLanguage) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=ULowEntryExtendedStandardLibrary::GetAndroidOsLanguage(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetAndroidVersion) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=ULowEntryExtendedStandardLibrary::GetAndroidVersion(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetAndroidDeviceModel) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=ULowEntryExtendedStandardLibrary::GetAndroidDeviceModel(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetAndroidDeviceMake) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=ULowEntryExtendedStandardLibrary::GetAndroidDeviceMake(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetAndroidVolume) \
	{ \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_Volume); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::GetAndroidVolume(Z_Param_Out_Volume); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetCurrentVolumePercentage) \
	{ \
		P_GET_PROPERTY_REF(UFloatProperty,Z_Param_Out_Percentage); \
		P_GET_UBOOL_REF(Z_Param_Out_Success); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::GetCurrentVolumePercentage(Z_Param_Out_Percentage,Z_Param_Out_Success); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetBatteryTemperature) \
	{ \
		P_GET_PROPERTY_REF(UFloatProperty,Z_Param_Out_Celsius); \
		P_GET_UBOOL_REF(Z_Param_Out_Success); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::GetBatteryTemperature(Z_Param_Out_Celsius,Z_Param_Out_Success); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetBatteryCharge) \
	{ \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_Percentage); \
		P_GET_UBOOL_REF(Z_Param_Out_Success); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::GetBatteryCharge(Z_Param_Out_Percentage,Z_Param_Out_Success); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetBatteryState) \
	{ \
		P_GET_ENUM_REF(ELowEntryBatteryState,Z_Param_Out_State); \
		P_GET_UBOOL_REF(Z_Param_Out_Success); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::GetBatteryState((ELowEntryBatteryState&)(Z_Param_Out_State),Z_Param_Out_Success); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDesktopPlatform) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::DesktopPlatform(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIosPlatform) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::IosPlatform(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAndroidPlatform) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::AndroidPlatform(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSwitchPlatform) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::SwitchPlatform(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execXboxOnePlatform) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::XboxOnePlatform(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execPs4Platform) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::Ps4Platform(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execMacPlatform) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::MacPlatform(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLinuxPlatform) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::LinuxPlatform(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execWindowsRtArmPlatform) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::WindowsRtArmPlatform(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execWindowsRtPlatform) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::WindowsRtPlatform(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execWindows64Platform) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::Windows64Platform(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execWindows32Platform) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::Windows32Platform(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execWindowsPlatform) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::WindowsPlatform(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execHtml5Platform) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::Html5Platform(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execWithEditor) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::WithEditor(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execShippingBuild) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::ShippingBuild(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execTestBuild) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::TestBuild(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDevelopmentBuild) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::DevelopmentBuild(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDebugBuild) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::DebugBuild(); \
		P_NATIVE_END; \
	}


#define BaylorBlackGospelVR_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_Classes_LowEntryExtendedStandardLibrary_h_88_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execMergeEncapsulatedByteArrays) \
	{ \
		P_GET_TARRAY_REF(ULowEntryByteArray*,Z_Param_Out_ByteArrays); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<uint8>*)Z_Param__Result=ULowEntryExtendedStandardLibrary::MergeEncapsulatedByteArrays(Z_Param_Out_ByteArrays); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execEncapsulateByteArray) \
	{ \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_ByteArray); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryByteArray**)Z_Param__Result=ULowEntryExtendedStandardLibrary::EncapsulateByteArray(Z_Param_Out_ByteArray); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSimpleKismetSystemLibraryPrintString) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_InString); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::SimpleKismetSystemLibraryPrintString(Z_Param_InString); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execPlayerControllerGetLocalPlayer) \
	{ \
		P_GET_OBJECT(APlayerController,Z_Param_PlayerController); \
		P_GET_UBOOL_REF(Z_Param_Out_Success); \
		P_GET_OBJECT_REF(ULocalPlayer,Z_Param_Out_LocalPlayer); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::PlayerControllerGetLocalPlayer(Z_Param_PlayerController,Z_Param_Out_Success,Z_Param_Out_LocalPlayer); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCaseSwitchObject) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_OnlyCheckFirstX); \
		P_GET_OBJECT(UObject,Z_Param_Value); \
		P_GET_OBJECT(UObject,Z_Param__1__); \
		P_GET_OBJECT(UObject,Z_Param__2__); \
		P_GET_OBJECT(UObject,Z_Param__3__); \
		P_GET_OBJECT(UObject,Z_Param__4__); \
		P_GET_OBJECT(UObject,Z_Param__5__); \
		P_GET_OBJECT(UObject,Z_Param__6__); \
		P_GET_OBJECT(UObject,Z_Param__7__); \
		P_GET_OBJECT(UObject,Z_Param__8__); \
		P_GET_OBJECT(UObject,Z_Param__9__); \
		P_GET_OBJECT(UObject,Z_Param__10__); \
		P_GET_ENUM_REF(ELowEntryExtendedStandardLibrary1to10other,Z_Param_Out_Branch); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::CaseSwitchObject(Z_Param_OnlyCheckFirstX,Z_Param_Value,Z_Param__1__,Z_Param__2__,Z_Param__3__,Z_Param__4__,Z_Param__5__,Z_Param__6__,Z_Param__7__,Z_Param__8__,Z_Param__9__,Z_Param__10__,(ELowEntryExtendedStandardLibrary1to10other&)(Z_Param_Out_Branch)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCaseSwitchByte) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_OnlyCheckFirstX); \
		P_GET_PROPERTY(UByteProperty,Z_Param_Value); \
		P_GET_PROPERTY(UByteProperty,Z_Param__1__); \
		P_GET_PROPERTY(UByteProperty,Z_Param__2__); \
		P_GET_PROPERTY(UByteProperty,Z_Param__3__); \
		P_GET_PROPERTY(UByteProperty,Z_Param__4__); \
		P_GET_PROPERTY(UByteProperty,Z_Param__5__); \
		P_GET_PROPERTY(UByteProperty,Z_Param__6__); \
		P_GET_PROPERTY(UByteProperty,Z_Param__7__); \
		P_GET_PROPERTY(UByteProperty,Z_Param__8__); \
		P_GET_PROPERTY(UByteProperty,Z_Param__9__); \
		P_GET_PROPERTY(UByteProperty,Z_Param__10__); \
		P_GET_ENUM_REF(ELowEntryExtendedStandardLibrary1to10other,Z_Param_Out_Branch); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::CaseSwitchByte(Z_Param_OnlyCheckFirstX,Z_Param_Value,Z_Param__1__,Z_Param__2__,Z_Param__3__,Z_Param__4__,Z_Param__5__,Z_Param__6__,Z_Param__7__,Z_Param__8__,Z_Param__9__,Z_Param__10__,(ELowEntryExtendedStandardLibrary1to10other&)(Z_Param_Out_Branch)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCaseSwitchInteger) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_OnlyCheckFirstX); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Value); \
		P_GET_PROPERTY(UIntProperty,Z_Param__1__); \
		P_GET_PROPERTY(UIntProperty,Z_Param__2__); \
		P_GET_PROPERTY(UIntProperty,Z_Param__3__); \
		P_GET_PROPERTY(UIntProperty,Z_Param__4__); \
		P_GET_PROPERTY(UIntProperty,Z_Param__5__); \
		P_GET_PROPERTY(UIntProperty,Z_Param__6__); \
		P_GET_PROPERTY(UIntProperty,Z_Param__7__); \
		P_GET_PROPERTY(UIntProperty,Z_Param__8__); \
		P_GET_PROPERTY(UIntProperty,Z_Param__9__); \
		P_GET_PROPERTY(UIntProperty,Z_Param__10__); \
		P_GET_ENUM_REF(ELowEntryExtendedStandardLibrary1to10other,Z_Param_Out_Branch); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::CaseSwitchInteger(Z_Param_OnlyCheckFirstX,Z_Param_Value,Z_Param__1__,Z_Param__2__,Z_Param__3__,Z_Param__4__,Z_Param__5__,Z_Param__6__,Z_Param__7__,Z_Param__8__,Z_Param__9__,Z_Param__10__,(ELowEntryExtendedStandardLibrary1to10other&)(Z_Param_Out_Branch)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execExecToByte) \
	{ \
		P_GET_ENUM(ELowEntryExtendedStandardLibrary0to9,Z_Param_Branch); \
		P_GET_PROPERTY_REF(UByteProperty,Z_Param_Out_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::ExecToByte(ELowEntryExtendedStandardLibrary0to9(Z_Param_Branch),Z_Param_Out_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execExecToInteger) \
	{ \
		P_GET_ENUM(ELowEntryExtendedStandardLibrary0to9,Z_Param_Branch); \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::ExecToInteger(ELowEntryExtendedStandardLibrary0to9(Z_Param_Branch),Z_Param_Out_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execExecToBoolean) \
	{ \
		P_GET_ENUM(ELowEntryExtendedStandardLibraryTrueOrFalse,Z_Param_Branch); \
		P_GET_UBOOL_REF(Z_Param_Out_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::ExecToBoolean(ELowEntryExtendedStandardLibraryTrueOrFalse(Z_Param_Branch),Z_Param_Out_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetKeyboardFocusedWidgetType) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FName*)Z_Param__Result=ULowEntryExtendedStandardLibrary::GetKeyboardFocusedWidgetType(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetUserFocusedWidgetType) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_UserIndex); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FName*)Z_Param__Result=ULowEntryExtendedStandardLibrary::GetUserFocusedWidgetType(Z_Param_UserIndex); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execClearKeyboardFocus) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::ClearKeyboardFocus(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execClearUserFocus) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_UserIndex); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::ClearUserFocus(Z_Param_UserIndex); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execClearAllUserFocus) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::ClearAllUserFocus(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetAbsoluteToLocalScale) \
	{ \
		P_GET_STRUCT_REF(FGeometry,Z_Param_Out_Geometry); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FVector2D*)Z_Param__Result=ULowEntryExtendedStandardLibrary::GetAbsoluteToLocalScale(Z_Param_Out_Geometry); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetLocalToAbsoluteScale) \
	{ \
		P_GET_STRUCT_REF(FGeometry,Z_Param_Out_Geometry); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FVector2D*)Z_Param__Result=ULowEntryExtendedStandardLibrary::GetLocalToAbsoluteScale(Z_Param_Out_Geometry); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetAbsoluteSize) \
	{ \
		P_GET_STRUCT_REF(FGeometry,Z_Param_Out_Geometry); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FVector2D*)Z_Param__Result=ULowEntryExtendedStandardLibrary::GetAbsoluteSize(Z_Param_Out_Geometry); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDivide_Vector2dVector2d) \
	{ \
		P_GET_STRUCT_REF(FVector2D,Z_Param_Out_A); \
		P_GET_STRUCT_REF(FVector2D,Z_Param_Out_B); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FVector2D*)Z_Param__Result=ULowEntryExtendedStandardLibrary::Divide_Vector2dVector2d(Z_Param_Out_A,Z_Param_Out_B); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetClassWithName) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_ClassName); \
		P_GET_OBJECT_REF(UClass,Z_Param_Out_Class_); \
		P_GET_UBOOL_REF(Z_Param_Out_Success); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::GetClassWithName(Z_Param_ClassName,Z_Param_Out_Class_,Z_Param_Out_Success); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetWorldRenderingEnabled) \
	{ \
		P_GET_UBOOL(Z_Param_Enabled); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::SetWorldRenderingEnabled(Z_Param_Enabled); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsWorldRenderingEnabled) \
	{ \
		P_GET_UBOOL_REF(Z_Param_Out_Success); \
		P_GET_UBOOL_REF(Z_Param_Out_Enabled); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::IsWorldRenderingEnabled(Z_Param_Out_Success,Z_Param_Out_Enabled); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetSplitScreenType_ThreePlayers) \
	{ \
		P_GET_ENUM(ELowEntrySplitScreenTypeThreePlayers,Z_Param_Type); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::SetSplitScreenType_ThreePlayers(ELowEntrySplitScreenTypeThreePlayers(Z_Param_Type)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetSplitScreenType_TwoPlayers) \
	{ \
		P_GET_ENUM(ELowEntrySplitScreenTypeTwoPlayers,Z_Param_Type); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::SetSplitScreenType_TwoPlayers(ELowEntrySplitScreenTypeTwoPlayers(Z_Param_Type)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetSplitScreenType) \
	{ \
		P_GET_ENUM_REF(ELowEntrySplitScreenType,Z_Param_Out_Type); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::GetSplitScreenType((ELowEntrySplitScreenType&)(Z_Param_Out_Type)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetSplitScreenEnabled) \
	{ \
		P_GET_UBOOL(Z_Param_Enabled); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::SetSplitScreenEnabled(Z_Param_Enabled); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetWindowMode) \
	{ \
		P_GET_UBOOL(Z_Param_Fullscreen); \
		P_GET_UBOOL(Z_Param_IsFullscreenWindowed); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::SetWindowMode(Z_Param_Fullscreen,Z_Param_IsFullscreenWindowed); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetWindowMode) \
	{ \
		P_GET_UBOOL_REF(Z_Param_Out_Success); \
		P_GET_UBOOL_REF(Z_Param_Out_Fullscreen); \
		P_GET_UBOOL_REF(Z_Param_Out_IsFullscreenWindowed); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::GetWindowMode(Z_Param_Out_Success,Z_Param_Out_Fullscreen,Z_Param_Out_IsFullscreenWindowed); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetWindowPositiomInPercentagesCentered) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_X); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Y); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::SetWindowPositiomInPercentagesCentered(Z_Param_X,Z_Param_Y); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetWindowSize) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Width); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Height); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::SetWindowSize(Z_Param_Width,Z_Param_Height); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetWindowPosition) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_X); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Y); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::SetWindowPosition(Z_Param_X,Z_Param_Y); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetWindowPositiomInPercentagesCentered) \
	{ \
		P_GET_UBOOL_REF(Z_Param_Out_Success); \
		P_GET_PROPERTY_REF(UFloatProperty,Z_Param_Out_X); \
		P_GET_PROPERTY_REF(UFloatProperty,Z_Param_Out_Y); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::GetWindowPositiomInPercentagesCentered(Z_Param_Out_Success,Z_Param_Out_X,Z_Param_Out_Y); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetWindowSize) \
	{ \
		P_GET_UBOOL_REF(Z_Param_Out_Success); \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_Width); \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_Height); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::GetWindowSize(Z_Param_Out_Success,Z_Param_Out_Width,Z_Param_Out_Height); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetWindowPosition) \
	{ \
		P_GET_UBOOL_REF(Z_Param_Out_Success); \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_X); \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_Y); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::GetWindowPosition(Z_Param_Out_Success,Z_Param_Out_X,Z_Param_Out_Y); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetWindowBounds) \
	{ \
		P_GET_UBOOL_REF(Z_Param_Out_Success); \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_X); \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_Y); \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_Width); \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_Height); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::GetWindowBounds(Z_Param_Out_Success,Z_Param_Out_X,Z_Param_Out_Y,Z_Param_Out_Width,Z_Param_Out_Height); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetPrimaryMonitorWorkArea) \
	{ \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_X); \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_Y); \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_Width); \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_Height); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::GetPrimaryMonitorWorkArea(Z_Param_Out_X,Z_Param_Out_Y,Z_Param_Out_Width,Z_Param_Out_Height); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetPrimaryMonitorResolution) \
	{ \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_Width); \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_Height); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::GetPrimaryMonitorResolution(Z_Param_Out_Width,Z_Param_Out_Height); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetMouseLockedToViewport) \
	{ \
		P_GET_UBOOL(Z_Param_Locked); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::SetMouseLockedToViewport(Z_Param_Locked); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetMousePositionInPercentages) \
	{ \
		P_GET_UBOOL_REF(Z_Param_Out_Success); \
		P_GET_PROPERTY_REF(UFloatProperty,Z_Param_Out_X); \
		P_GET_PROPERTY_REF(UFloatProperty,Z_Param_Out_Y); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::GetMousePositionInPercentages(Z_Param_Out_Success,Z_Param_Out_X,Z_Param_Out_Y); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetMousePositionInPercentages) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_X); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Y); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::SetMousePositionInPercentages(Z_Param_X,Z_Param_Y); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetMousePosition) \
	{ \
		P_GET_UBOOL_REF(Z_Param_Out_Success); \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_X); \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_Y); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::GetMousePosition(Z_Param_Out_Success,Z_Param_Out_X,Z_Param_Out_Y); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetMousePosition) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_X); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Y); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::SetMousePosition(Z_Param_X,Z_Param_Y); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDouble_Create) \
	{ \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_ByteArray); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Index); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Length); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryDouble**)Z_Param__Result=ULowEntryExtendedStandardLibrary::Double_Create(Z_Param_Out_ByteArray,Z_Param_Index,Z_Param_Length); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDouble_CreateZero) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryDouble**)Z_Param__Result=ULowEntryExtendedStandardLibrary::Double_CreateZero(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLong_Create) \
	{ \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_ByteArray); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Index); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Length); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryLong**)Z_Param__Result=ULowEntryExtendedStandardLibrary::Long_Create(Z_Param_Out_ByteArray,Z_Param_Index,Z_Param_Length); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLong_CreateZero) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryLong**)Z_Param__Result=ULowEntryExtendedStandardLibrary::Long_CreateZero(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBitDataEntry_CreateFromStringUtf8Array) \
	{ \
		P_GET_TARRAY_REF(FString,Z_Param_Out_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryBitDataEntry**)Z_Param__Result=ULowEntryExtendedStandardLibrary::BitDataEntry_CreateFromStringUtf8Array(Z_Param_Out_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBitDataEntry_CreateFromBooleanArray) \
	{ \
		P_GET_TARRAY_REF(bool,Z_Param_Out_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryBitDataEntry**)Z_Param__Result=ULowEntryExtendedStandardLibrary::BitDataEntry_CreateFromBooleanArray(Z_Param_Out_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBitDataEntry_CreateFromDoubleBytesArray) \
	{ \
		P_GET_TARRAY_REF(ULowEntryDouble*,Z_Param_Out_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryBitDataEntry**)Z_Param__Result=ULowEntryExtendedStandardLibrary::BitDataEntry_CreateFromDoubleBytesArray(Z_Param_Out_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBitDataEntry_CreateFromFloatArray) \
	{ \
		P_GET_TARRAY_REF(float,Z_Param_Out_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryBitDataEntry**)Z_Param__Result=ULowEntryExtendedStandardLibrary::BitDataEntry_CreateFromFloatArray(Z_Param_Out_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBitDataEntry_CreateFromLongBytesArray) \
	{ \
		P_GET_TARRAY_REF(ULowEntryLong*,Z_Param_Out_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryBitDataEntry**)Z_Param__Result=ULowEntryExtendedStandardLibrary::BitDataEntry_CreateFromLongBytesArray(Z_Param_Out_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBitDataEntry_CreateFromPositiveInteger3Array) \
	{ \
		P_GET_TARRAY_REF(int32,Z_Param_Out_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryBitDataEntry**)Z_Param__Result=ULowEntryExtendedStandardLibrary::BitDataEntry_CreateFromPositiveInteger3Array(Z_Param_Out_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBitDataEntry_CreateFromPositiveInteger2Array) \
	{ \
		P_GET_TARRAY_REF(int32,Z_Param_Out_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryBitDataEntry**)Z_Param__Result=ULowEntryExtendedStandardLibrary::BitDataEntry_CreateFromPositiveInteger2Array(Z_Param_Out_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBitDataEntry_CreateFromPositiveInteger1Array) \
	{ \
		P_GET_TARRAY_REF(int32,Z_Param_Out_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryBitDataEntry**)Z_Param__Result=ULowEntryExtendedStandardLibrary::BitDataEntry_CreateFromPositiveInteger1Array(Z_Param_Out_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBitDataEntry_CreateFromIntegerArray) \
	{ \
		P_GET_TARRAY_REF(int32,Z_Param_Out_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryBitDataEntry**)Z_Param__Result=ULowEntryExtendedStandardLibrary::BitDataEntry_CreateFromIntegerArray(Z_Param_Out_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBitDataEntry_CreateFromByteArray) \
	{ \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryBitDataEntry**)Z_Param__Result=ULowEntryExtendedStandardLibrary::BitDataEntry_CreateFromByteArray(Z_Param_Out_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBitDataEntry_CreateFromIntegerArrayMostSignificantBits) \
	{ \
		P_GET_TARRAY_REF(int32,Z_Param_Out_Value); \
		P_GET_PROPERTY(UIntProperty,Z_Param_BitCount); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryBitDataEntry**)Z_Param__Result=ULowEntryExtendedStandardLibrary::BitDataEntry_CreateFromIntegerArrayMostSignificantBits(Z_Param_Out_Value,Z_Param_BitCount); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBitDataEntry_CreateFromIntegerArrayLeastSignificantBits) \
	{ \
		P_GET_TARRAY_REF(int32,Z_Param_Out_Value); \
		P_GET_PROPERTY(UIntProperty,Z_Param_BitCount); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryBitDataEntry**)Z_Param__Result=ULowEntryExtendedStandardLibrary::BitDataEntry_CreateFromIntegerArrayLeastSignificantBits(Z_Param_Out_Value,Z_Param_BitCount); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBitDataEntry_CreateFromByteArrayMostSignificantBits) \
	{ \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_Value); \
		P_GET_PROPERTY(UIntProperty,Z_Param_BitCount); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryBitDataEntry**)Z_Param__Result=ULowEntryExtendedStandardLibrary::BitDataEntry_CreateFromByteArrayMostSignificantBits(Z_Param_Out_Value,Z_Param_BitCount); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBitDataEntry_CreateFromByteArrayLeastSignificantBits) \
	{ \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_Value); \
		P_GET_PROPERTY(UIntProperty,Z_Param_BitCount); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryBitDataEntry**)Z_Param__Result=ULowEntryExtendedStandardLibrary::BitDataEntry_CreateFromByteArrayLeastSignificantBits(Z_Param_Out_Value,Z_Param_BitCount); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBitDataEntry_CreateFromBitArray) \
	{ \
		P_GET_TARRAY_REF(bool,Z_Param_Out_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryBitDataEntry**)Z_Param__Result=ULowEntryExtendedStandardLibrary::BitDataEntry_CreateFromBitArray(Z_Param_Out_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBitDataEntry_CreateFromStringUtf8) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryBitDataEntry**)Z_Param__Result=ULowEntryExtendedStandardLibrary::BitDataEntry_CreateFromStringUtf8(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBitDataEntry_CreateFromBoolean) \
	{ \
		P_GET_UBOOL(Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryBitDataEntry**)Z_Param__Result=ULowEntryExtendedStandardLibrary::BitDataEntry_CreateFromBoolean(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBitDataEntry_CreateFromDoubleBytes) \
	{ \
		P_GET_OBJECT(ULowEntryDouble,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryBitDataEntry**)Z_Param__Result=ULowEntryExtendedStandardLibrary::BitDataEntry_CreateFromDoubleBytes(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBitDataEntry_CreateFromFloat) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryBitDataEntry**)Z_Param__Result=ULowEntryExtendedStandardLibrary::BitDataEntry_CreateFromFloat(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBitDataEntry_CreateFromLongBytes) \
	{ \
		P_GET_OBJECT(ULowEntryLong,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryBitDataEntry**)Z_Param__Result=ULowEntryExtendedStandardLibrary::BitDataEntry_CreateFromLongBytes(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBitDataEntry_CreateFromPositiveInteger3) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryBitDataEntry**)Z_Param__Result=ULowEntryExtendedStandardLibrary::BitDataEntry_CreateFromPositiveInteger3(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBitDataEntry_CreateFromPositiveInteger2) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryBitDataEntry**)Z_Param__Result=ULowEntryExtendedStandardLibrary::BitDataEntry_CreateFromPositiveInteger2(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBitDataEntry_CreateFromPositiveInteger1) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryBitDataEntry**)Z_Param__Result=ULowEntryExtendedStandardLibrary::BitDataEntry_CreateFromPositiveInteger1(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBitDataEntry_CreateFromInteger) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryBitDataEntry**)Z_Param__Result=ULowEntryExtendedStandardLibrary::BitDataEntry_CreateFromInteger(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBitDataEntry_CreateFromByte) \
	{ \
		P_GET_PROPERTY(UByteProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryBitDataEntry**)Z_Param__Result=ULowEntryExtendedStandardLibrary::BitDataEntry_CreateFromByte(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBitDataEntry_CreateFromIntegerMostSignificantBits) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Value); \
		P_GET_PROPERTY(UIntProperty,Z_Param_BitCount); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryBitDataEntry**)Z_Param__Result=ULowEntryExtendedStandardLibrary::BitDataEntry_CreateFromIntegerMostSignificantBits(Z_Param_Value,Z_Param_BitCount); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBitDataEntry_CreateFromIntegerLeastSignificantBits) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Value); \
		P_GET_PROPERTY(UIntProperty,Z_Param_BitCount); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryBitDataEntry**)Z_Param__Result=ULowEntryExtendedStandardLibrary::BitDataEntry_CreateFromIntegerLeastSignificantBits(Z_Param_Value,Z_Param_BitCount); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBitDataEntry_CreateFromByteMostSignificantBits) \
	{ \
		P_GET_PROPERTY(UByteProperty,Z_Param_Value); \
		P_GET_PROPERTY(UIntProperty,Z_Param_BitCount); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryBitDataEntry**)Z_Param__Result=ULowEntryExtendedStandardLibrary::BitDataEntry_CreateFromByteMostSignificantBits(Z_Param_Value,Z_Param_BitCount); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBitDataEntry_CreateFromByteLeastSignificantBits) \
	{ \
		P_GET_PROPERTY(UByteProperty,Z_Param_Value); \
		P_GET_PROPERTY(UIntProperty,Z_Param_BitCount); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryBitDataEntry**)Z_Param__Result=ULowEntryExtendedStandardLibrary::BitDataEntry_CreateFromByteLeastSignificantBits(Z_Param_Value,Z_Param_BitCount); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBitDataEntry_CreateFromBit) \
	{ \
		P_GET_UBOOL(Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryBitDataEntry**)Z_Param__Result=ULowEntryExtendedStandardLibrary::BitDataEntry_CreateFromBit(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBitDataWriter_GetBytes) \
	{ \
		P_GET_OBJECT(ULowEntryBitDataWriter,Z_Param_BitDataWriter); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<uint8>*)Z_Param__Result=ULowEntryExtendedStandardLibrary::BitDataWriter_GetBytes(Z_Param_BitDataWriter); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBitDataWriter_CreateFromEntryArrayPure) \
	{ \
		P_GET_TARRAY_REF(ULowEntryBitDataEntry*,Z_Param_Out_Array); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryBitDataWriter**)Z_Param__Result=ULowEntryExtendedStandardLibrary::BitDataWriter_CreateFromEntryArrayPure(Z_Param_Out_Array); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBitDataWriter_CreateFromEntryArray) \
	{ \
		P_GET_TARRAY_REF(ULowEntryBitDataEntry*,Z_Param_Out_Array); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryBitDataWriter**)Z_Param__Result=ULowEntryExtendedStandardLibrary::BitDataWriter_CreateFromEntryArray(Z_Param_Out_Array); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBitDataReader_Create) \
	{ \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_Bytes); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Index); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Length); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryBitDataReader**)Z_Param__Result=ULowEntryExtendedStandardLibrary::BitDataReader_Create(Z_Param_Out_Bytes,Z_Param_Index,Z_Param_Length); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execByteDataEntry_CreateFromStringUtf8Array) \
	{ \
		P_GET_TARRAY_REF(FString,Z_Param_Out_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryByteDataEntry**)Z_Param__Result=ULowEntryExtendedStandardLibrary::ByteDataEntry_CreateFromStringUtf8Array(Z_Param_Out_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execByteDataEntry_CreateFromBooleanArray) \
	{ \
		P_GET_TARRAY_REF(bool,Z_Param_Out_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryByteDataEntry**)Z_Param__Result=ULowEntryExtendedStandardLibrary::ByteDataEntry_CreateFromBooleanArray(Z_Param_Out_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execByteDataEntry_CreateFromDoubleBytesArray) \
	{ \
		P_GET_TARRAY_REF(ULowEntryDouble*,Z_Param_Out_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryByteDataEntry**)Z_Param__Result=ULowEntryExtendedStandardLibrary::ByteDataEntry_CreateFromDoubleBytesArray(Z_Param_Out_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execByteDataEntry_CreateFromFloatArray) \
	{ \
		P_GET_TARRAY_REF(float,Z_Param_Out_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryByteDataEntry**)Z_Param__Result=ULowEntryExtendedStandardLibrary::ByteDataEntry_CreateFromFloatArray(Z_Param_Out_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execByteDataEntry_CreateFromLongBytesArray) \
	{ \
		P_GET_TARRAY_REF(ULowEntryLong*,Z_Param_Out_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryByteDataEntry**)Z_Param__Result=ULowEntryExtendedStandardLibrary::ByteDataEntry_CreateFromLongBytesArray(Z_Param_Out_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execByteDataEntry_CreateFromPositiveInteger3Array) \
	{ \
		P_GET_TARRAY_REF(int32,Z_Param_Out_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryByteDataEntry**)Z_Param__Result=ULowEntryExtendedStandardLibrary::ByteDataEntry_CreateFromPositiveInteger3Array(Z_Param_Out_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execByteDataEntry_CreateFromPositiveInteger2Array) \
	{ \
		P_GET_TARRAY_REF(int32,Z_Param_Out_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryByteDataEntry**)Z_Param__Result=ULowEntryExtendedStandardLibrary::ByteDataEntry_CreateFromPositiveInteger2Array(Z_Param_Out_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execByteDataEntry_CreateFromPositiveInteger1Array) \
	{ \
		P_GET_TARRAY_REF(int32,Z_Param_Out_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryByteDataEntry**)Z_Param__Result=ULowEntryExtendedStandardLibrary::ByteDataEntry_CreateFromPositiveInteger1Array(Z_Param_Out_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execByteDataEntry_CreateFromIntegerArray) \
	{ \
		P_GET_TARRAY_REF(int32,Z_Param_Out_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryByteDataEntry**)Z_Param__Result=ULowEntryExtendedStandardLibrary::ByteDataEntry_CreateFromIntegerArray(Z_Param_Out_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execByteDataEntry_CreateFromByteArray) \
	{ \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryByteDataEntry**)Z_Param__Result=ULowEntryExtendedStandardLibrary::ByteDataEntry_CreateFromByteArray(Z_Param_Out_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execByteDataEntry_CreateFromStringUtf8) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryByteDataEntry**)Z_Param__Result=ULowEntryExtendedStandardLibrary::ByteDataEntry_CreateFromStringUtf8(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execByteDataEntry_CreateFromBoolean) \
	{ \
		P_GET_UBOOL(Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryByteDataEntry**)Z_Param__Result=ULowEntryExtendedStandardLibrary::ByteDataEntry_CreateFromBoolean(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execByteDataEntry_CreateFromDoubleBytes) \
	{ \
		P_GET_OBJECT(ULowEntryDouble,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryByteDataEntry**)Z_Param__Result=ULowEntryExtendedStandardLibrary::ByteDataEntry_CreateFromDoubleBytes(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execByteDataEntry_CreateFromFloat) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryByteDataEntry**)Z_Param__Result=ULowEntryExtendedStandardLibrary::ByteDataEntry_CreateFromFloat(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execByteDataEntry_CreateFromLongBytes) \
	{ \
		P_GET_OBJECT(ULowEntryLong,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryByteDataEntry**)Z_Param__Result=ULowEntryExtendedStandardLibrary::ByteDataEntry_CreateFromLongBytes(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execByteDataEntry_CreateFromPositiveInteger3) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryByteDataEntry**)Z_Param__Result=ULowEntryExtendedStandardLibrary::ByteDataEntry_CreateFromPositiveInteger3(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execByteDataEntry_CreateFromPositiveInteger2) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryByteDataEntry**)Z_Param__Result=ULowEntryExtendedStandardLibrary::ByteDataEntry_CreateFromPositiveInteger2(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execByteDataEntry_CreateFromPositiveInteger1) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryByteDataEntry**)Z_Param__Result=ULowEntryExtendedStandardLibrary::ByteDataEntry_CreateFromPositiveInteger1(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execByteDataEntry_CreateFromInteger) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryByteDataEntry**)Z_Param__Result=ULowEntryExtendedStandardLibrary::ByteDataEntry_CreateFromInteger(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execByteDataEntry_CreateFromByte) \
	{ \
		P_GET_PROPERTY(UByteProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryByteDataEntry**)Z_Param__Result=ULowEntryExtendedStandardLibrary::ByteDataEntry_CreateFromByte(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execByteDataWriter_GetBytes) \
	{ \
		P_GET_OBJECT(ULowEntryByteDataWriter,Z_Param_ByteDataWriter); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<uint8>*)Z_Param__Result=ULowEntryExtendedStandardLibrary::ByteDataWriter_GetBytes(Z_Param_ByteDataWriter); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execByteDataWriter_CreateFromEntryArrayPure) \
	{ \
		P_GET_TARRAY_REF(ULowEntryByteDataEntry*,Z_Param_Out_Array); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryByteDataWriter**)Z_Param__Result=ULowEntryExtendedStandardLibrary::ByteDataWriter_CreateFromEntryArrayPure(Z_Param_Out_Array); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execByteDataWriter_CreateFromEntryArray) \
	{ \
		P_GET_TARRAY_REF(ULowEntryByteDataEntry*,Z_Param_Out_Array); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryByteDataWriter**)Z_Param__Result=ULowEntryExtendedStandardLibrary::ByteDataWriter_CreateFromEntryArray(Z_Param_Out_Array); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execByteDataReader_Create) \
	{ \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_Bytes); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Index); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Length); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryByteDataReader**)Z_Param__Result=ULowEntryExtendedStandardLibrary::ByteDataReader_Create(Z_Param_Out_Bytes,Z_Param_Index,Z_Param_Length); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execTickSeconds) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_STRUCT(FLatentActionInfo,Z_Param_LatentInfo); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Ticks); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_SecondsInterval); \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_Tick); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::TickSeconds(Z_Param_WorldContextObject,Z_Param_LatentInfo,Z_Param_Ticks,Z_Param_SecondsInterval,Z_Param_Out_Tick); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execTickFrames) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_STRUCT(FLatentActionInfo,Z_Param_LatentInfo); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Ticks); \
		P_GET_PROPERTY(UIntProperty,Z_Param_FramesInterval); \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_Tick); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::TickFrames(Z_Param_WorldContextObject,Z_Param_LatentInfo,Z_Param_Ticks,Z_Param_FramesInterval,Z_Param_Out_Tick); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execChangeMap) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_PROPERTY(UStrProperty,Z_Param_Map); \
		P_GET_PROPERTY(UStrProperty,Z_Param_Args); \
		P_GET_OBJECT(APlayerController,Z_Param_SpecificPlayer); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::ChangeMap(Z_Param_WorldContextObject,Z_Param_Map,Z_Param_Args,Z_Param_SpecificPlayer); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execServerChangeMap) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_PROPERTY(UStrProperty,Z_Param_Map); \
		P_GET_PROPERTY(UStrProperty,Z_Param_Args); \
		P_GET_OBJECT(APlayerController,Z_Param_SpecificPlayer); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::ServerChangeMap(Z_Param_WorldContextObject,Z_Param_Map,Z_Param_Args,Z_Param_SpecificPlayer); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execJoinGame) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_PROPERTY(UStrProperty,Z_Param_ServerAddress); \
		P_GET_PROPERTY(UStrProperty,Z_Param_Args); \
		P_GET_OBJECT(APlayerController,Z_Param_SpecificPlayer); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::JoinGame(Z_Param_WorldContextObject,Z_Param_ServerAddress,Z_Param_Args,Z_Param_SpecificPlayer); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execHostGame) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_PROPERTY(UStrProperty,Z_Param_Map); \
		P_GET_PROPERTY(UStrProperty,Z_Param_Args); \
		P_GET_OBJECT(APlayerController,Z_Param_SpecificPlayer); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::HostGame(Z_Param_WorldContextObject,Z_Param_Map,Z_Param_Args,Z_Param_SpecificPlayer); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCrash) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::Crash(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRegexReplace) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_String); \
		P_GET_PROPERTY(UStrProperty,Z_Param_Pattern); \
		P_GET_PROPERTY(UStrProperty,Z_Param_Replacement); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=ULowEntryExtendedStandardLibrary::RegexReplace(Z_Param_String,Z_Param_Pattern,Z_Param_Replacement); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRegexGetMatches) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_String); \
		P_GET_PROPERTY(UStrProperty,Z_Param_Pattern); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<FLowEntryRegexMatch>*)Z_Param__Result=ULowEntryExtendedStandardLibrary::RegexGetMatches(Z_Param_String,Z_Param_Pattern); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRegexCount) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_String); \
		P_GET_PROPERTY(UStrProperty,Z_Param_Pattern); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=ULowEntryExtendedStandardLibrary::RegexCount(Z_Param_String,Z_Param_Pattern); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRegexMatch) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_String); \
		P_GET_PROPERTY(UStrProperty,Z_Param_Pattern); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::RegexMatch(Z_Param_String,Z_Param_Pattern); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execReplaceCharactersExcept) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_String); \
		P_GET_PROPERTY(UStrProperty,Z_Param_ReplacementCharacter); \
		P_GET_UBOOL(Z_Param_KeepLowercaseAZ); \
		P_GET_UBOOL(Z_Param_KeepUppercaseAZ); \
		P_GET_UBOOL(Z_Param_KeepNumbers); \
		P_GET_PROPERTY(UStrProperty,Z_Param_OtherCharactersToKeep); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=ULowEntryExtendedStandardLibrary::ReplaceCharactersExcept(Z_Param_String,Z_Param_ReplacementCharacter,Z_Param_KeepLowercaseAZ,Z_Param_KeepUppercaseAZ,Z_Param_KeepNumbers,Z_Param_OtherCharactersToKeep); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRemoveCharactersExcept) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_String); \
		P_GET_UBOOL(Z_Param_KeepLowercaseAZ); \
		P_GET_UBOOL(Z_Param_KeepUppercaseAZ); \
		P_GET_UBOOL(Z_Param_KeepNumbers); \
		P_GET_PROPERTY(UStrProperty,Z_Param_OtherCharactersToKeep); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=ULowEntryExtendedStandardLibrary::RemoveCharactersExcept(Z_Param_String,Z_Param_KeepLowercaseAZ,Z_Param_KeepUppercaseAZ,Z_Param_KeepNumbers,Z_Param_OtherCharactersToKeep); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCreateString) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Length); \
		P_GET_PROPERTY(UStrProperty,Z_Param_Filler); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=ULowEntryExtendedStandardLibrary::CreateString(Z_Param_Length,Z_Param_Filler); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execNextQueueExecution) \
	{ \
		P_GET_OBJECT(ULowEntryExecutionQueue,Z_Param_Queue); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::NextQueueExecution(Z_Param_Queue); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execQueueExecutions) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_OBJECT_REF(ULowEntryExecutionQueue,Z_Param_Out_Queue); \
		P_GET_STRUCT(FLatentActionInfo,Z_Param_LatentInfo); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::QueueExecutions(Z_Param_WorldContextObject,Z_Param_Out_Queue,Z_Param_LatentInfo); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRetriggerableRandomDelayFrames) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_PROPERTY(UIntProperty,Z_Param_MinFrames); \
		P_GET_PROPERTY(UIntProperty,Z_Param_MaxFrames); \
		P_GET_STRUCT(FLatentActionInfo,Z_Param_LatentInfo); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::RetriggerableRandomDelayFrames(Z_Param_WorldContextObject,Z_Param_MinFrames,Z_Param_MaxFrames,Z_Param_LatentInfo); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRandomDelayFrames) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_PROPERTY(UIntProperty,Z_Param_MinFrames); \
		P_GET_PROPERTY(UIntProperty,Z_Param_MaxFrames); \
		P_GET_STRUCT(FLatentActionInfo,Z_Param_LatentInfo); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::RandomDelayFrames(Z_Param_WorldContextObject,Z_Param_MinFrames,Z_Param_MaxFrames,Z_Param_LatentInfo); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRetriggerableDelayFrames) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Frames); \
		P_GET_STRUCT(FLatentActionInfo,Z_Param_LatentInfo); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::RetriggerableDelayFrames(Z_Param_WorldContextObject,Z_Param_Frames,Z_Param_LatentInfo); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDelayFrames) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Frames); \
		P_GET_STRUCT(FLatentActionInfo,Z_Param_LatentInfo); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::DelayFrames(Z_Param_WorldContextObject,Z_Param_Frames,Z_Param_LatentInfo); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRetriggerableRandomDelay) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_MinDuration); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_MaxDuration); \
		P_GET_STRUCT(FLatentActionInfo,Z_Param_LatentInfo); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::RetriggerableRandomDelay(Z_Param_WorldContextObject,Z_Param_MinDuration,Z_Param_MaxDuration,Z_Param_LatentInfo); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRandomDelay) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_MinDuration); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_MaxDuration); \
		P_GET_STRUCT(FLatentActionInfo,Z_Param_LatentInfo); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::RandomDelay(Z_Param_WorldContextObject,Z_Param_MinDuration,Z_Param_MaxDuration,Z_Param_LatentInfo); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSortObjectArrayDirectly) \
	{ \
		P_GET_TARRAY_REF(UObject*,Z_Param_Out_ObjectArray); \
		P_GET_PROPERTY(UDelegateProperty,Z_Param_Comparator); \
		P_GET_UBOOL(Z_Param_Reversed); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::SortObjectArrayDirectly(Z_Param_Out_ObjectArray,FDelegateULowEntryExtendedStandardLibraryCompareObjects(Z_Param_Comparator),Z_Param_Reversed); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSortObjectArray) \
	{ \
		P_GET_TARRAY_REF(UObject*,Z_Param_Out_ObjectArray); \
		P_GET_PROPERTY(UDelegateProperty,Z_Param_Comparator); \
		P_GET_UBOOL(Z_Param_Reversed); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<UObject*>*)Z_Param__Result=ULowEntryExtendedStandardLibrary::SortObjectArray(Z_Param_Out_ObjectArray,FDelegateULowEntryExtendedStandardLibraryCompareObjects(Z_Param_Comparator),Z_Param_Reversed); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSortTimespanArrayDirectly) \
	{ \
		P_GET_TARRAY_REF(FTimespan,Z_Param_Out_TimespanArray); \
		P_GET_UBOOL(Z_Param_Reversed); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::SortTimespanArrayDirectly(Z_Param_Out_TimespanArray,Z_Param_Reversed); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSortTimespanArray) \
	{ \
		P_GET_TARRAY_REF(FTimespan,Z_Param_Out_TimespanArray); \
		P_GET_UBOOL(Z_Param_Reversed); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<FTimespan>*)Z_Param__Result=ULowEntryExtendedStandardLibrary::SortTimespanArray(Z_Param_Out_TimespanArray,Z_Param_Reversed); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSortDateTimeArrayDirectly) \
	{ \
		P_GET_TARRAY_REF(FDateTime,Z_Param_Out_DateTimeArray); \
		P_GET_UBOOL(Z_Param_Reversed); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::SortDateTimeArrayDirectly(Z_Param_Out_DateTimeArray,Z_Param_Reversed); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSortDateTimeArray) \
	{ \
		P_GET_TARRAY_REF(FDateTime,Z_Param_Out_DateTimeArray); \
		P_GET_UBOOL(Z_Param_Reversed); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<FDateTime>*)Z_Param__Result=ULowEntryExtendedStandardLibrary::SortDateTimeArray(Z_Param_Out_DateTimeArray,Z_Param_Reversed); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSortByteArrayDirectly) \
	{ \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_ByteArray); \
		P_GET_UBOOL(Z_Param_Reversed); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::SortByteArrayDirectly(Z_Param_Out_ByteArray,Z_Param_Reversed); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSortByteArray) \
	{ \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_ByteArray); \
		P_GET_UBOOL(Z_Param_Reversed); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<uint8>*)Z_Param__Result=ULowEntryExtendedStandardLibrary::SortByteArray(Z_Param_Out_ByteArray,Z_Param_Reversed); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSortFloatArrayDirectly) \
	{ \
		P_GET_TARRAY_REF(float,Z_Param_Out_FloatArray); \
		P_GET_UBOOL(Z_Param_Reversed); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::SortFloatArrayDirectly(Z_Param_Out_FloatArray,Z_Param_Reversed); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSortFloatArray) \
	{ \
		P_GET_TARRAY_REF(float,Z_Param_Out_FloatArray); \
		P_GET_UBOOL(Z_Param_Reversed); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<float>*)Z_Param__Result=ULowEntryExtendedStandardLibrary::SortFloatArray(Z_Param_Out_FloatArray,Z_Param_Reversed); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSortIntegerArrayDirectly) \
	{ \
		P_GET_TARRAY_REF(int32,Z_Param_Out_IntegerArray); \
		P_GET_UBOOL(Z_Param_Reversed); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::SortIntegerArrayDirectly(Z_Param_Out_IntegerArray,Z_Param_Reversed); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSortIntegerArray) \
	{ \
		P_GET_TARRAY_REF(int32,Z_Param_Out_IntegerArray); \
		P_GET_UBOOL(Z_Param_Reversed); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<int32>*)Z_Param__Result=ULowEntryExtendedStandardLibrary::SortIntegerArray(Z_Param_Out_IntegerArray,Z_Param_Reversed); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSortStringArrayDirectly) \
	{ \
		P_GET_TARRAY_REF(FString,Z_Param_Out_StringArray); \
		P_GET_UBOOL(Z_Param_Reversed); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::SortStringArrayDirectly(Z_Param_Out_StringArray,Z_Param_Reversed); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSortStringArray) \
	{ \
		P_GET_TARRAY_REF(FString,Z_Param_Out_StringArray); \
		P_GET_UBOOL(Z_Param_Reversed); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<FString>*)Z_Param__Result=ULowEntryExtendedStandardLibrary::SortStringArray(Z_Param_Out_StringArray,Z_Param_Reversed); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConvertUtcDateToLocalDate) \
	{ \
		P_GET_STRUCT_REF(FDateTime,Z_Param_Out_Utc); \
		P_GET_STRUCT_REF(FDateTime,Z_Param_Out_Local); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::ConvertUtcDateToLocalDate(Z_Param_Out_Utc,Z_Param_Out_Local); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConvertLocalDateToUtcDate) \
	{ \
		P_GET_STRUCT_REF(FDateTime,Z_Param_Out_Local); \
		P_GET_STRUCT_REF(FDateTime,Z_Param_Out_Utc); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::ConvertLocalDateToUtcDate(Z_Param_Out_Local,Z_Param_Out_Utc); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDateTime_FromUnixTimestamp) \
	{ \
		P_GET_OBJECT(ULowEntryLong,Z_Param_Timestamp); \
		P_GET_STRUCT_REF(FDateTime,Z_Param_Out_DateTime); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::DateTime_FromUnixTimestamp(Z_Param_Timestamp,Z_Param_Out_DateTime); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDateTime_ToUnixTimestamp) \
	{ \
		P_GET_STRUCT_REF(FDateTime,Z_Param_Out_DateTime); \
		P_GET_OBJECT_REF(ULowEntryLong,Z_Param_Out_Timestamp); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::DateTime_ToUnixTimestamp(Z_Param_Out_DateTime,Z_Param_Out_Timestamp); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDateTime_ToString) \
	{ \
		P_GET_STRUCT_REF(FDateTime,Z_Param_Out_DateTime); \
		P_GET_PROPERTY_REF(UStrProperty,Z_Param_Out_String); \
		P_GET_PROPERTY(UStrProperty,Z_Param_Format); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::DateTime_ToString(Z_Param_Out_DateTime,Z_Param_Out_String,Z_Param_Format); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDateTime_ToIso8601) \
	{ \
		P_GET_STRUCT_REF(FDateTime,Z_Param_Out_DateTime); \
		P_GET_PROPERTY_REF(UStrProperty,Z_Param_Out_String); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::DateTime_ToIso8601(Z_Param_Out_DateTime,Z_Param_Out_String); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execMinOfTimespanArray) \
	{ \
		P_GET_TARRAY_REF(FTimespan,Z_Param_Out_TimespanArray); \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_IndexOfMinValue); \
		P_GET_STRUCT_REF(FTimespan,Z_Param_Out_MinValue); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::MinOfTimespanArray(Z_Param_Out_TimespanArray,Z_Param_Out_IndexOfMinValue,Z_Param_Out_MinValue); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execMaxOfTimespanArray) \
	{ \
		P_GET_TARRAY_REF(FTimespan,Z_Param_Out_TimespanArray); \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_IndexOfMaxValue); \
		P_GET_STRUCT_REF(FTimespan,Z_Param_Out_MaxValue); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::MaxOfTimespanArray(Z_Param_Out_TimespanArray,Z_Param_Out_IndexOfMaxValue,Z_Param_Out_MaxValue); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execMinOfDateTimeArray) \
	{ \
		P_GET_TARRAY_REF(FDateTime,Z_Param_Out_DateTimeArray); \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_IndexOfMinValue); \
		P_GET_STRUCT_REF(FDateTime,Z_Param_Out_MinValue); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::MinOfDateTimeArray(Z_Param_Out_DateTimeArray,Z_Param_Out_IndexOfMinValue,Z_Param_Out_MinValue); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execMaxOfDateTimeArray) \
	{ \
		P_GET_TARRAY_REF(FDateTime,Z_Param_Out_DateTimeArray); \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_IndexOfMaxValue); \
		P_GET_STRUCT_REF(FDateTime,Z_Param_Out_MaxValue); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::MaxOfDateTimeArray(Z_Param_Out_DateTimeArray,Z_Param_Out_IndexOfMaxValue,Z_Param_Out_MaxValue); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execMinOfStringArray) \
	{ \
		P_GET_TARRAY_REF(FString,Z_Param_Out_StringArray); \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_IndexOfMinValue); \
		P_GET_PROPERTY_REF(UStrProperty,Z_Param_Out_MinValue); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::MinOfStringArray(Z_Param_Out_StringArray,Z_Param_Out_IndexOfMinValue,Z_Param_Out_MinValue); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execMaxOfStringArray) \
	{ \
		P_GET_TARRAY_REF(FString,Z_Param_Out_StringArray); \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_IndexOfMaxValue); \
		P_GET_PROPERTY_REF(UStrProperty,Z_Param_Out_MaxValue); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::MaxOfStringArray(Z_Param_Out_StringArray,Z_Param_Out_IndexOfMaxValue,Z_Param_Out_MaxValue); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execFloorDecimals) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Number); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Decimals); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=ULowEntryExtendedStandardLibrary::FloorDecimals(Z_Param_Number,Z_Param_Decimals); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCeilDecimals) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Number); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Decimals); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=ULowEntryExtendedStandardLibrary::CeilDecimals(Z_Param_Number,Z_Param_Decimals); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRoundDecimals) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Number); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Decimals); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=ULowEntryExtendedStandardLibrary::RoundDecimals(Z_Param_Number,Z_Param_Decimals); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGreaterEqualByteFloat) \
	{ \
		P_GET_PROPERTY(UByteProperty,Z_Param_A); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_B); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::GreaterEqualByteFloat(Z_Param_A,Z_Param_B); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLessEqualByteFloat) \
	{ \
		P_GET_PROPERTY(UByteProperty,Z_Param_A); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_B); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::LessEqualByteFloat(Z_Param_A,Z_Param_B); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGreaterByteFloat) \
	{ \
		P_GET_PROPERTY(UByteProperty,Z_Param_A); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_B); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::GreaterByteFloat(Z_Param_A,Z_Param_B); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLessByteFloat) \
	{ \
		P_GET_PROPERTY(UByteProperty,Z_Param_A); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_B); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::LessByteFloat(Z_Param_A,Z_Param_B); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGreaterEqualByteInteger) \
	{ \
		P_GET_PROPERTY(UByteProperty,Z_Param_A); \
		P_GET_PROPERTY(UIntProperty,Z_Param_B); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::GreaterEqualByteInteger(Z_Param_A,Z_Param_B); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLessEqualByteInteger) \
	{ \
		P_GET_PROPERTY(UByteProperty,Z_Param_A); \
		P_GET_PROPERTY(UIntProperty,Z_Param_B); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::LessEqualByteInteger(Z_Param_A,Z_Param_B); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGreaterByteInteger) \
	{ \
		P_GET_PROPERTY(UByteProperty,Z_Param_A); \
		P_GET_PROPERTY(UIntProperty,Z_Param_B); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::GreaterByteInteger(Z_Param_A,Z_Param_B); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLessByteInteger) \
	{ \
		P_GET_PROPERTY(UByteProperty,Z_Param_A); \
		P_GET_PROPERTY(UIntProperty,Z_Param_B); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::LessByteInteger(Z_Param_A,Z_Param_B); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGreaterEqualFloatByte) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_A); \
		P_GET_PROPERTY(UByteProperty,Z_Param_B); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::GreaterEqualFloatByte(Z_Param_A,Z_Param_B); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLessEqualFloatByte) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_A); \
		P_GET_PROPERTY(UByteProperty,Z_Param_B); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::LessEqualFloatByte(Z_Param_A,Z_Param_B); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGreaterFloatByte) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_A); \
		P_GET_PROPERTY(UByteProperty,Z_Param_B); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::GreaterFloatByte(Z_Param_A,Z_Param_B); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLessFloatByte) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_A); \
		P_GET_PROPERTY(UByteProperty,Z_Param_B); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::LessFloatByte(Z_Param_A,Z_Param_B); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGreaterEqualFloatInteger) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_A); \
		P_GET_PROPERTY(UIntProperty,Z_Param_B); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::GreaterEqualFloatInteger(Z_Param_A,Z_Param_B); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLessEqualFloatInteger) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_A); \
		P_GET_PROPERTY(UIntProperty,Z_Param_B); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::LessEqualFloatInteger(Z_Param_A,Z_Param_B); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGreaterFloatInteger) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_A); \
		P_GET_PROPERTY(UIntProperty,Z_Param_B); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::GreaterFloatInteger(Z_Param_A,Z_Param_B); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLessFloatInteger) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_A); \
		P_GET_PROPERTY(UIntProperty,Z_Param_B); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::LessFloatInteger(Z_Param_A,Z_Param_B); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGreaterEqualIntegerByte) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_A); \
		P_GET_PROPERTY(UByteProperty,Z_Param_B); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::GreaterEqualIntegerByte(Z_Param_A,Z_Param_B); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLessEqualIntegerByte) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_A); \
		P_GET_PROPERTY(UByteProperty,Z_Param_B); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::LessEqualIntegerByte(Z_Param_A,Z_Param_B); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGreaterIntegerByte) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_A); \
		P_GET_PROPERTY(UByteProperty,Z_Param_B); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::GreaterIntegerByte(Z_Param_A,Z_Param_B); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLessIntegerByte) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_A); \
		P_GET_PROPERTY(UByteProperty,Z_Param_B); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::LessIntegerByte(Z_Param_A,Z_Param_B); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGreaterEqualIntegerFloat) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_A); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_B); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::GreaterEqualIntegerFloat(Z_Param_A,Z_Param_B); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLessEqualIntegerFloat) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_A); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_B); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::LessEqualIntegerFloat(Z_Param_A,Z_Param_B); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGreaterIntegerFloat) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_A); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_B); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::GreaterIntegerFloat(Z_Param_A,Z_Param_B); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLessIntegerFloat) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_A); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_B); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::LessIntegerFloat(Z_Param_A,Z_Param_B); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGreaterEqualStringString) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_A); \
		P_GET_PROPERTY(UStrProperty,Z_Param_B); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::GreaterEqualStringString(Z_Param_A,Z_Param_B); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLessEqualStringString) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_A); \
		P_GET_PROPERTY(UStrProperty,Z_Param_B); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::LessEqualStringString(Z_Param_A,Z_Param_B); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGreaterStringString) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_A); \
		P_GET_PROPERTY(UStrProperty,Z_Param_B); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::GreaterStringString(Z_Param_A,Z_Param_B); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLessStringString) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_A); \
		P_GET_PROPERTY(UStrProperty,Z_Param_B); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::LessStringString(Z_Param_A,Z_Param_B); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execMaxString) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_A); \
		P_GET_PROPERTY(UStrProperty,Z_Param_B); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=ULowEntryExtendedStandardLibrary::MaxString(Z_Param_A,Z_Param_B); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execMinString) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_A); \
		P_GET_PROPERTY(UStrProperty,Z_Param_B); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=ULowEntryExtendedStandardLibrary::MinString(Z_Param_A,Z_Param_B); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execTabCharacter) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=ULowEntryExtendedStandardLibrary::TabCharacter(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCarriageReturnCharacter) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=ULowEntryExtendedStandardLibrary::CarriageReturnCharacter(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execWindowsNewlineCharacter) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=ULowEntryExtendedStandardLibrary::WindowsNewlineCharacter(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execNewlineCharacter) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=ULowEntryExtendedStandardLibrary::NewlineCharacter(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execParsedHashcashIsValid) \
	{ \
		P_GET_OBJECT(ULowEntryParsedHashcash,Z_Param_Target); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::ParsedHashcashIsValid(Z_Param_Target); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execHashcashParse) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Hash); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryParsedHashcash**)Z_Param__Result=ULowEntryExtendedStandardLibrary::HashcashParse(Z_Param_Hash); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execHashcashParseArray) \
	{ \
		P_GET_TARRAY_REF(FString,Z_Param_Out_Hashes); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<ULowEntryParsedHashcash*>*)Z_Param__Result=ULowEntryExtendedStandardLibrary::HashcashParseArray(Z_Param_Out_Hashes); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execHashcashCustomCreationDate) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Resource); \
		P_GET_STRUCT_REF(FDateTime,Z_Param_Out_UtcDate); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Bits); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=ULowEntryExtendedStandardLibrary::HashcashCustomCreationDate(Z_Param_Resource,Z_Param_Out_UtcDate,Z_Param_Bits); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execHashcash) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Resource); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Bits); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=ULowEntryExtendedStandardLibrary::Hashcash(Z_Param_Resource,Z_Param_Bits); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execHashcashArrayCustomCreationDate) \
	{ \
		P_GET_TARRAY_REF(FString,Z_Param_Out_Resources); \
		P_GET_STRUCT_REF(FDateTime,Z_Param_Out_UtcDate); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Bits); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<FString>*)Z_Param__Result=ULowEntryExtendedStandardLibrary::HashcashArrayCustomCreationDate(Z_Param_Out_Resources,Z_Param_Out_UtcDate,Z_Param_Bits); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execHashcashArray) \
	{ \
		P_GET_TARRAY_REF(FString,Z_Param_Out_Resources); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Bits); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<FString>*)Z_Param__Result=ULowEntryExtendedStandardLibrary::HashcashArray(Z_Param_Out_Resources,Z_Param_Bits); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execHMAC) \
	{ \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_ByteArray); \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_Key); \
		P_GET_ENUM(ELowEntryHmacAlgorithm,Z_Param_Algorithm); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Index); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Length); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<uint8>*)Z_Param__Result=ULowEntryExtendedStandardLibrary::HMAC(Z_Param_Out_ByteArray,Z_Param_Out_Key,ELowEntryHmacAlgorithm(Z_Param_Algorithm),Z_Param_Index,Z_Param_Length); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBCrypt) \
	{ \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_ByteArray); \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_Salt); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Strength); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Index); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Length); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<uint8>*)Z_Param__Result=ULowEntryExtendedStandardLibrary::BCrypt(Z_Param_Out_ByteArray,Z_Param_Out_Salt,Z_Param_Strength,Z_Param_Index,Z_Param_Length); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSha512) \
	{ \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_ByteArray); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Index); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Length); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<uint8>*)Z_Param__Result=ULowEntryExtendedStandardLibrary::Sha512(Z_Param_Out_ByteArray,Z_Param_Index,Z_Param_Length); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSha256) \
	{ \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_ByteArray); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Index); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Length); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<uint8>*)Z_Param__Result=ULowEntryExtendedStandardLibrary::Sha256(Z_Param_Out_ByteArray,Z_Param_Index,Z_Param_Length); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSha1) \
	{ \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_ByteArray); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Index); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Length); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<uint8>*)Z_Param__Result=ULowEntryExtendedStandardLibrary::Sha1(Z_Param_Out_ByteArray,Z_Param_Index,Z_Param_Length); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execMd5) \
	{ \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_ByteArray); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Index); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Length); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<uint8>*)Z_Param__Result=ULowEntryExtendedStandardLibrary::Md5(Z_Param_Out_ByteArray,Z_Param_Index,Z_Param_Length); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execPearson) \
	{ \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_ByteArray); \
		P_GET_PROPERTY(UIntProperty,Z_Param_HashLength); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Index); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Length); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<uint8>*)Z_Param__Result=ULowEntryExtendedStandardLibrary::Pearson(Z_Param_Out_ByteArray,Z_Param_HashLength,Z_Param_Index,Z_Param_Length); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSceneCaptureComponent2D_SetFov) \
	{ \
		P_GET_OBJECT(USceneCaptureComponent2D,Z_Param_SceneCaptureComponent2D); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Fov); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::SceneCaptureComponent2D_SetFov(Z_Param_SceneCaptureComponent2D,Z_Param_Fov); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSceneCaptureComponent2D_GetFov) \
	{ \
		P_GET_OBJECT(USceneCaptureComponent2D,Z_Param_SceneCaptureComponent2D); \
		P_GET_PROPERTY_REF(UFloatProperty,Z_Param_Out_Fov); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::SceneCaptureComponent2D_GetFov(Z_Param_SceneCaptureComponent2D,Z_Param_Out_Fov); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSceneCapture2D_SetFov) \
	{ \
		P_GET_OBJECT(ASceneCapture2D,Z_Param_SceneCapture2D); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Fov); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::SceneCapture2D_SetFov(Z_Param_SceneCapture2D,Z_Param_Fov); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSceneCapture2D_GetFov) \
	{ \
		P_GET_OBJECT(ASceneCapture2D,Z_Param_SceneCapture2D); \
		P_GET_PROPERTY_REF(UFloatProperty,Z_Param_Out_Fov); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::SceneCapture2D_GetFov(Z_Param_SceneCapture2D,Z_Param_Out_Fov); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execTextureUpdateResource) \
	{ \
		P_GET_OBJECT(UTexture,Z_Param_Texture); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::TextureUpdateResource(Z_Param_Texture); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLoadVideo) \
	{ \
		P_GET_OBJECT(UMediaSoundComponent,Z_Param_MediaSoundComponent); \
		P_GET_PROPERTY(UStrProperty,Z_Param_Url); \
		P_GET_UBOOL_REF(Z_Param_Out_Success); \
		P_GET_OBJECT_REF(UMediaPlayer,Z_Param_Out_MediaPlayer); \
		P_GET_OBJECT_REF(UMediaTexture,Z_Param_Out_MediaTexture); \
		P_GET_UBOOL(Z_Param_PlayOnOpen); \
		P_GET_UBOOL(Z_Param_Loop); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::LoadVideo(Z_Param_MediaSoundComponent,Z_Param_Url,Z_Param_Out_Success,Z_Param_Out_MediaPlayer,Z_Param_Out_MediaTexture,Z_Param_PlayOnOpen,Z_Param_Loop); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execTextureRenderTarget2DToPixels) \
	{ \
		P_GET_OBJECT(UTextureRenderTarget2D,Z_Param_TextureRenderTarget2D); \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_Width); \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_Height); \
		P_GET_TARRAY_REF(FColor,Z_Param_Out_Pixels); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::TextureRenderTarget2DToPixels(Z_Param_TextureRenderTarget2D,Z_Param_Out_Width,Z_Param_Out_Height,Z_Param_Out_Pixels); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSceneCaptureComponent2DToPixels) \
	{ \
		P_GET_OBJECT(USceneCaptureComponent2D,Z_Param_SceneCaptureComponent2D); \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_Width); \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_Height); \
		P_GET_TARRAY_REF(FColor,Z_Param_Out_Pixels); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::SceneCaptureComponent2DToPixels(Z_Param_SceneCaptureComponent2D,Z_Param_Out_Width,Z_Param_Out_Height,Z_Param_Out_Pixels); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSceneCapture2DToPixels) \
	{ \
		P_GET_OBJECT(ASceneCapture2D,Z_Param_SceneCapture2D); \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_Width); \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_Height); \
		P_GET_TARRAY_REF(FColor,Z_Param_Out_Pixels); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::SceneCapture2DToPixels(Z_Param_SceneCapture2D,Z_Param_Out_Width,Z_Param_Out_Height,Z_Param_Out_Pixels); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execTextureRenderTarget2DToBytes) \
	{ \
		P_GET_OBJECT(UTextureRenderTarget2D,Z_Param_TextureRenderTarget2D); \
		P_GET_ENUM(ELowEntryImageFormat,Z_Param_ImageFormat); \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_ByteArray); \
		P_GET_PROPERTY(UIntProperty,Z_Param_CompressionQuality); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::TextureRenderTarget2DToBytes(Z_Param_TextureRenderTarget2D,ELowEntryImageFormat(Z_Param_ImageFormat),Z_Param_Out_ByteArray,Z_Param_CompressionQuality); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSceneCaptureComponent2DToBytes) \
	{ \
		P_GET_OBJECT(USceneCaptureComponent2D,Z_Param_SceneCaptureComponent2D); \
		P_GET_ENUM(ELowEntryImageFormat,Z_Param_ImageFormat); \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_ByteArray); \
		P_GET_PROPERTY(UIntProperty,Z_Param_CompressionQuality); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::SceneCaptureComponent2DToBytes(Z_Param_SceneCaptureComponent2D,ELowEntryImageFormat(Z_Param_ImageFormat),Z_Param_Out_ByteArray,Z_Param_CompressionQuality); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSceneCapture2DToBytes) \
	{ \
		P_GET_OBJECT(ASceneCapture2D,Z_Param_SceneCapture2D); \
		P_GET_ENUM(ELowEntryImageFormat,Z_Param_ImageFormat); \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_ByteArray); \
		P_GET_PROPERTY(UIntProperty,Z_Param_CompressionQuality); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::SceneCapture2DToBytes(Z_Param_SceneCapture2D,ELowEntryImageFormat(Z_Param_ImageFormat),Z_Param_Out_ByteArray,Z_Param_CompressionQuality); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execPixelsToExistingTexture2D) \
	{ \
		P_GET_UBOOL_REF(Z_Param_Out_ReusedGivenTexture2D); \
		P_GET_OBJECT(UTexture2D,Z_Param_Texture2D); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Width); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Height); \
		P_GET_TARRAY_REF(FColor,Z_Param_Out_Pixels); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UTexture2D**)Z_Param__Result=ULowEntryExtendedStandardLibrary::PixelsToExistingTexture2D(Z_Param_Out_ReusedGivenTexture2D,Z_Param_Texture2D,Z_Param_Width,Z_Param_Height,Z_Param_Out_Pixels); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execPixelsToTexture2D) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Width); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Height); \
		P_GET_TARRAY_REF(FColor,Z_Param_Out_Pixels); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UTexture2D**)Z_Param__Result=ULowEntryExtendedStandardLibrary::PixelsToTexture2D(Z_Param_Width,Z_Param_Height,Z_Param_Out_Pixels); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execTexture2DToPixels) \
	{ \
		P_GET_OBJECT(UTexture2D,Z_Param_Texture2D); \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_Width); \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_Height); \
		P_GET_TARRAY_REF(FColor,Z_Param_Out_Pixels); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::Texture2DToPixels(Z_Param_Texture2D,Z_Param_Out_Width,Z_Param_Out_Height,Z_Param_Out_Pixels); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execPixelsToBytes) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Width); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Height); \
		P_GET_TARRAY_REF(FColor,Z_Param_Out_Pixels); \
		P_GET_ENUM(ELowEntryImageFormat,Z_Param_ImageFormat); \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_ByteArray); \
		P_GET_PROPERTY(UIntProperty,Z_Param_CompressionQuality); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::PixelsToBytes(Z_Param_Width,Z_Param_Height,Z_Param_Out_Pixels,ELowEntryImageFormat(Z_Param_ImageFormat),Z_Param_Out_ByteArray,Z_Param_CompressionQuality); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBytesToPixels) \
	{ \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_ByteArray); \
		P_GET_ENUM(ELowEntryImageFormat,Z_Param_ImageFormat); \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_Width); \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_Height); \
		P_GET_TARRAY_REF(FColor,Z_Param_Out_Pixels); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Index); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Length); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::BytesToPixels(Z_Param_Out_ByteArray,ELowEntryImageFormat(Z_Param_ImageFormat),Z_Param_Out_Width,Z_Param_Out_Height,Z_Param_Out_Pixels,Z_Param_Index,Z_Param_Length); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execTexture2DToBytes) \
	{ \
		P_GET_OBJECT(UTexture2D,Z_Param_Texture2D); \
		P_GET_ENUM(ELowEntryImageFormat,Z_Param_ImageFormat); \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_ByteArray); \
		P_GET_PROPERTY(UIntProperty,Z_Param_CompressionQuality); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::Texture2DToBytes(Z_Param_Texture2D,ELowEntryImageFormat(Z_Param_ImageFormat),Z_Param_Out_ByteArray,Z_Param_CompressionQuality); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBytesToExistingImage) \
	{ \
		P_GET_UBOOL_REF(Z_Param_Out_ReusedGivenTexture2D); \
		P_GET_OBJECT(UTexture2D,Z_Param_Texture2D); \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_ByteArray); \
		P_GET_ENUM(ELowEntryImageFormat,Z_Param_ImageFormat); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Index); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Length); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UTexture2D**)Z_Param__Result=ULowEntryExtendedStandardLibrary::BytesToExistingImage(Z_Param_Out_ReusedGivenTexture2D,Z_Param_Texture2D,Z_Param_Out_ByteArray,ELowEntryImageFormat(Z_Param_ImageFormat),Z_Param_Index,Z_Param_Length); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBytesToImage) \
	{ \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_ByteArray); \
		P_GET_ENUM(ELowEntryImageFormat,Z_Param_ImageFormat); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Index); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Length); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UTexture2D**)Z_Param__Result=ULowEntryExtendedStandardLibrary::BytesToImage(Z_Param_Out_ByteArray,ELowEntryImageFormat(Z_Param_ImageFormat),Z_Param_Index,Z_Param_Length); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetByteWithBitSet) \
	{ \
		P_GET_PROPERTY(UByteProperty,Z_Param_Byte); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Bit); \
		P_GET_UBOOL(Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(uint8*)Z_Param__Result=ULowEntryExtendedStandardLibrary::GetByteWithBitSet(Z_Param_Byte,Z_Param_Bit,Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsBitSet) \
	{ \
		P_GET_PROPERTY(UByteProperty,Z_Param_B); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Bit); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::IsBitSet(Z_Param_B,Z_Param_Bit); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execByteToBits) \
	{ \
		P_GET_PROPERTY(UByteProperty,Z_Param_Byte); \
		P_GET_UBOOL_REF(Z_Param_Out_Bit1); \
		P_GET_UBOOL_REF(Z_Param_Out_Bit2); \
		P_GET_UBOOL_REF(Z_Param_Out_Bit3); \
		P_GET_UBOOL_REF(Z_Param_Out_Bit4); \
		P_GET_UBOOL_REF(Z_Param_Out_Bit5); \
		P_GET_UBOOL_REF(Z_Param_Out_Bit6); \
		P_GET_UBOOL_REF(Z_Param_Out_Bit7); \
		P_GET_UBOOL_REF(Z_Param_Out_Bit8); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::ByteToBits(Z_Param_Byte,Z_Param_Out_Bit1,Z_Param_Out_Bit2,Z_Param_Out_Bit3,Z_Param_Out_Bit4,Z_Param_Out_Bit5,Z_Param_Out_Bit6,Z_Param_Out_Bit7,Z_Param_Out_Bit8); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBitsToByte) \
	{ \
		P_GET_UBOOL(Z_Param_Bit1); \
		P_GET_UBOOL(Z_Param_Bit2); \
		P_GET_UBOOL(Z_Param_Bit3); \
		P_GET_UBOOL(Z_Param_Bit4); \
		P_GET_UBOOL(Z_Param_Bit5); \
		P_GET_UBOOL(Z_Param_Bit6); \
		P_GET_UBOOL(Z_Param_Bit7); \
		P_GET_UBOOL(Z_Param_Bit8); \
		P_GET_PROPERTY_REF(UByteProperty,Z_Param_Out_Byte); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::BitsToByte(Z_Param_Bit1,Z_Param_Bit2,Z_Param_Bit3,Z_Param_Bit4,Z_Param_Bit5,Z_Param_Bit6,Z_Param_Bit7,Z_Param_Bit8,Z_Param_Out_Byte); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBytesToByte) \
	{ \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_ByteArray); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Index); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Length); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(uint8*)Z_Param__Result=ULowEntryExtendedStandardLibrary::BytesToByte(Z_Param_Out_ByteArray,Z_Param_Index,Z_Param_Length); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execByteToBytes) \
	{ \
		P_GET_PROPERTY(UByteProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<uint8>*)Z_Param__Result=ULowEntryExtendedStandardLibrary::ByteToBytes(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execParseStringIntoDoubleBytes) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_String); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryDouble**)Z_Param__Result=ULowEntryExtendedStandardLibrary::ParseStringIntoDoubleBytes(Z_Param_String); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBytesToDoubleBytes) \
	{ \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_ByteArray); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Index); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Length); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryDouble**)Z_Param__Result=ULowEntryExtendedStandardLibrary::BytesToDoubleBytes(Z_Param_Out_ByteArray,Z_Param_Index,Z_Param_Length); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBytesToFloat) \
	{ \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_ByteArray); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Index); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Length); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=ULowEntryExtendedStandardLibrary::BytesToFloat(Z_Param_Out_ByteArray,Z_Param_Index,Z_Param_Length); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execFloatToBytes) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<uint8>*)Z_Param__Result=ULowEntryExtendedStandardLibrary::FloatToBytes(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execParseStringIntoLongBytes) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_String); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryLong**)Z_Param__Result=ULowEntryExtendedStandardLibrary::ParseStringIntoLongBytes(Z_Param_String); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBytesToLongBytes) \
	{ \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_ByteArray); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Index); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Length); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryLong**)Z_Param__Result=ULowEntryExtendedStandardLibrary::BytesToLongBytes(Z_Param_Out_ByteArray,Z_Param_Index,Z_Param_Length); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBytesToInteger) \
	{ \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_ByteArray); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Index); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Length); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=ULowEntryExtendedStandardLibrary::BytesToInteger(Z_Param_Out_ByteArray,Z_Param_Index,Z_Param_Length); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIntegerToBytes) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<uint8>*)Z_Param__Result=ULowEntryExtendedStandardLibrary::IntegerToBytes(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execByteToBoolean) \
	{ \
		P_GET_PROPERTY(UByteProperty,Z_Param_Byte); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::ByteToBoolean(Z_Param_Byte); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBooleanToByte) \
	{ \
		P_GET_UBOOL(Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(uint8*)Z_Param__Result=ULowEntryExtendedStandardLibrary::BooleanToByte(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBytesToBoolean) \
	{ \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_ByteArray); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Index); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Length); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::BytesToBoolean(Z_Param_Out_ByteArray,Z_Param_Index,Z_Param_Length); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBooleanToBytes) \
	{ \
		P_GET_UBOOL(Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<uint8>*)Z_Param__Result=ULowEntryExtendedStandardLibrary::BooleanToBytes(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBytesToBitString) \
	{ \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_ByteArray); \
		P_GET_UBOOL(Z_Param_AddSpaces); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Index); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Length); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=ULowEntryExtendedStandardLibrary::BytesToBitString(Z_Param_Out_ByteArray,Z_Param_AddSpaces,Z_Param_Index,Z_Param_Length); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBitStringToBytes) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Bits); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<uint8>*)Z_Param__Result=ULowEntryExtendedStandardLibrary::BitStringToBytes(Z_Param_Bits); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBytesToBinary) \
	{ \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_ByteArray); \
		P_GET_UBOOL(Z_Param_AddSpaces); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Index); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Length); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=ULowEntryExtendedStandardLibrary::BytesToBinary(Z_Param_Out_ByteArray,Z_Param_AddSpaces,Z_Param_Index,Z_Param_Length); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBinaryToBytes) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Binary); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<uint8>*)Z_Param__Result=ULowEntryExtendedStandardLibrary::BinaryToBytes(Z_Param_Binary); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBytesToHex) \
	{ \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_ByteArray); \
		P_GET_UBOOL(Z_Param_AddSpaces); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Index); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Length); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=ULowEntryExtendedStandardLibrary::BytesToHex(Z_Param_Out_ByteArray,Z_Param_AddSpaces,Z_Param_Index,Z_Param_Length); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execHexToBytes) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Hex); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<uint8>*)Z_Param__Result=ULowEntryExtendedStandardLibrary::HexToBytes(Z_Param_Hex); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBytesToBase64Url) \
	{ \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_ByteArray); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Index); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Length); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=ULowEntryExtendedStandardLibrary::BytesToBase64Url(Z_Param_Out_ByteArray,Z_Param_Index,Z_Param_Length); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBase64UrlToBytes) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Base64Url); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<uint8>*)Z_Param__Result=ULowEntryExtendedStandardLibrary::Base64UrlToBytes(Z_Param_Base64Url); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBase64UrlToBase64) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Base64Url); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=ULowEntryExtendedStandardLibrary::Base64UrlToBase64(Z_Param_Base64Url); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBase64ToBase64Url) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Base64); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=ULowEntryExtendedStandardLibrary::Base64ToBase64Url(Z_Param_Base64); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBytesToBase64) \
	{ \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_ByteArray); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Index); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Length); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=ULowEntryExtendedStandardLibrary::BytesToBase64(Z_Param_Out_ByteArray,Z_Param_Index,Z_Param_Length); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBase64ToBytes) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Base64); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<uint8>*)Z_Param__Result=ULowEntryExtendedStandardLibrary::Base64ToBytes(Z_Param_Base64); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBytesToStringUtf8) \
	{ \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_ByteArray); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Index); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Length); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=ULowEntryExtendedStandardLibrary::BytesToStringUtf8(Z_Param_Out_ByteArray,Z_Param_Index,Z_Param_Length); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStringToBytesUtf8) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_String); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<uint8>*)Z_Param__Result=ULowEntryExtendedStandardLibrary::StringToBytesUtf8(Z_Param_String); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGenerateRandomBytesRandomLength) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_MinLength); \
		P_GET_PROPERTY(UIntProperty,Z_Param_MaxLength); \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_ByteArray); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::GenerateRandomBytesRandomLength(Z_Param_MinLength,Z_Param_MaxLength,Z_Param_Out_ByteArray); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGenerateRandomBytes) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Length); \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_ByteArray); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::GenerateRandomBytes(Z_Param_Length,Z_Param_Out_ByteArray); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBytesSubArray) \
	{ \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_ByteArray); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Index); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Length); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<uint8>*)Z_Param__Result=ULowEntryExtendedStandardLibrary::BytesSubArray(Z_Param_Out_ByteArray,Z_Param_Index,Z_Param_Length); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execMergeBytes) \
	{ \
		P_GET_TARRAY(uint8,Z_Param_A); \
		P_GET_TARRAY(uint8,Z_Param_B); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<uint8>*)Z_Param__Result=ULowEntryExtendedStandardLibrary::MergeBytes(Z_Param_A,Z_Param_B); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSplitBytes) \
	{ \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_ByteArray); \
		P_GET_PROPERTY(UIntProperty,Z_Param_LengthA); \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_A); \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_B); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::SplitBytes(Z_Param_Out_ByteArray,Z_Param_LengthA,Z_Param_Out_A,Z_Param_Out_B); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAreBytesEqual) \
	{ \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_A); \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_B); \
		P_GET_PROPERTY(UIntProperty,Z_Param_IndexA); \
		P_GET_PROPERTY(UIntProperty,Z_Param_LengthA); \
		P_GET_PROPERTY(UIntProperty,Z_Param_IndexB); \
		P_GET_PROPERTY(UIntProperty,Z_Param_LengthB); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::AreBytesEqual(Z_Param_Out_A,Z_Param_Out_B,Z_Param_IndexA,Z_Param_LengthA,Z_Param_IndexB,Z_Param_LengthB); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLatentAction_Create_String) \
	{ \
		P_GET_OBJECT_REF(ULowEntryLatentActionString,Z_Param_Out_LatentAction); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::LatentAction_Create_String(Z_Param_Out_LatentAction); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLatentAction_Create_Object) \
	{ \
		P_GET_OBJECT_REF(ULowEntryLatentActionObject,Z_Param_Out_LatentAction); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::LatentAction_Create_Object(Z_Param_Out_LatentAction); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLatentAction_Create_None) \
	{ \
		P_GET_OBJECT_REF(ULowEntryLatentActionNone,Z_Param_Out_LatentAction); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::LatentAction_Create_None(Z_Param_Out_LatentAction); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLatentAction_Create_Integer) \
	{ \
		P_GET_OBJECT_REF(ULowEntryLatentActionInteger,Z_Param_Out_LatentAction); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::LatentAction_Create_Integer(Z_Param_Out_LatentAction); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLatentAction_Create_Float) \
	{ \
		P_GET_OBJECT_REF(ULowEntryLatentActionFloat,Z_Param_Out_LatentAction); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::LatentAction_Create_Float(Z_Param_Out_LatentAction); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLatentAction_Create_Boolean) \
	{ \
		P_GET_OBJECT_REF(ULowEntryLatentActionBoolean,Z_Param_Out_LatentAction); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::LatentAction_Create_Boolean(Z_Param_Out_LatentAction); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSoundClass_GetPitch) \
	{ \
		P_GET_OBJECT(USoundClass,Z_Param_SoundClass); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=ULowEntryExtendedStandardLibrary::SoundClass_GetPitch(Z_Param_SoundClass); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSoundClass_SetPitch) \
	{ \
		P_GET_OBJECT(USoundClass,Z_Param_SoundClass); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Pitch); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::SoundClass_SetPitch(Z_Param_SoundClass,Z_Param_Pitch); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSoundClass_GetVolume) \
	{ \
		P_GET_OBJECT(USoundClass,Z_Param_SoundClass); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=ULowEntryExtendedStandardLibrary::SoundClass_GetVolume(Z_Param_SoundClass); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSoundClass_SetVolume) \
	{ \
		P_GET_OBJECT(USoundClass,Z_Param_SoundClass); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Volume); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::SoundClass_SetVolume(Z_Param_SoundClass,Z_Param_Volume); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetGenericTeamId) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_Target); \
		P_GET_PROPERTY(UByteProperty,Z_Param_TeamID); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::SetGenericTeamId(Z_Param_Target,Z_Param_TeamID); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetGenericTeamId) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_Target); \
		P_GET_PROPERTY_REF(UByteProperty,Z_Param_Out_TeamID); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::GetGenericTeamId(Z_Param_Target,Z_Param_Out_TeamID); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCreateObject) \
	{ \
		P_GET_OBJECT(UClass,Z_Param_Class); \
		P_GET_OBJECT_REF(UObject,Z_Param_Out_Object); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::CreateObject(Z_Param_Class,Z_Param_Out_Object); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetMaximumVolume) \
	{ \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_Volume); \
		P_GET_UBOOL_REF(Z_Param_Out_Success); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::GetMaximumVolume(Z_Param_Out_Volume,Z_Param_Out_Success); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetCurrentVolume) \
	{ \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_Volume); \
		P_GET_UBOOL_REF(Z_Param_Out_Success); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::GetCurrentVolume(Z_Param_Out_Volume,Z_Param_Out_Success); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAreAndroidHeadphonesPluggedIn) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::AreAndroidHeadphonesPluggedIn(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetAndroidNumberOfCores) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=ULowEntryExtendedStandardLibrary::GetAndroidNumberOfCores(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsAndroidDaydreamApplication) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::IsAndroidDaydreamApplication(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetAndroidBuildVersion) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=ULowEntryExtendedStandardLibrary::GetAndroidBuildVersion(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetAndroidGlVersion) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=ULowEntryExtendedStandardLibrary::GetAndroidGlVersion(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetAndroidGpuFamily) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=ULowEntryExtendedStandardLibrary::GetAndroidGpuFamily(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetAndroidDefaultLocale) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=ULowEntryExtendedStandardLibrary::GetAndroidDefaultLocale(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetAndroidOsLanguage) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=ULowEntryExtendedStandardLibrary::GetAndroidOsLanguage(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetAndroidVersion) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=ULowEntryExtendedStandardLibrary::GetAndroidVersion(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetAndroidDeviceModel) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=ULowEntryExtendedStandardLibrary::GetAndroidDeviceModel(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetAndroidDeviceMake) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=ULowEntryExtendedStandardLibrary::GetAndroidDeviceMake(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetAndroidVolume) \
	{ \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_Volume); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::GetAndroidVolume(Z_Param_Out_Volume); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetCurrentVolumePercentage) \
	{ \
		P_GET_PROPERTY_REF(UFloatProperty,Z_Param_Out_Percentage); \
		P_GET_UBOOL_REF(Z_Param_Out_Success); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::GetCurrentVolumePercentage(Z_Param_Out_Percentage,Z_Param_Out_Success); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetBatteryTemperature) \
	{ \
		P_GET_PROPERTY_REF(UFloatProperty,Z_Param_Out_Celsius); \
		P_GET_UBOOL_REF(Z_Param_Out_Success); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::GetBatteryTemperature(Z_Param_Out_Celsius,Z_Param_Out_Success); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetBatteryCharge) \
	{ \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_Percentage); \
		P_GET_UBOOL_REF(Z_Param_Out_Success); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::GetBatteryCharge(Z_Param_Out_Percentage,Z_Param_Out_Success); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetBatteryState) \
	{ \
		P_GET_ENUM_REF(ELowEntryBatteryState,Z_Param_Out_State); \
		P_GET_UBOOL_REF(Z_Param_Out_Success); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULowEntryExtendedStandardLibrary::GetBatteryState((ELowEntryBatteryState&)(Z_Param_Out_State),Z_Param_Out_Success); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDesktopPlatform) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::DesktopPlatform(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIosPlatform) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::IosPlatform(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAndroidPlatform) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::AndroidPlatform(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSwitchPlatform) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::SwitchPlatform(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execXboxOnePlatform) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::XboxOnePlatform(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execPs4Platform) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::Ps4Platform(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execMacPlatform) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::MacPlatform(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLinuxPlatform) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::LinuxPlatform(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execWindowsRtArmPlatform) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::WindowsRtArmPlatform(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execWindowsRtPlatform) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::WindowsRtPlatform(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execWindows64Platform) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::Windows64Platform(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execWindows32Platform) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::Windows32Platform(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execWindowsPlatform) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::WindowsPlatform(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execHtml5Platform) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::Html5Platform(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execWithEditor) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::WithEditor(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execShippingBuild) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::ShippingBuild(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execTestBuild) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::TestBuild(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDevelopmentBuild) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::DevelopmentBuild(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDebugBuild) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULowEntryExtendedStandardLibrary::DebugBuild(); \
		P_NATIVE_END; \
	}


#define BaylorBlackGospelVR_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_Classes_LowEntryExtendedStandardLibrary_h_88_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesULowEntryExtendedStandardLibrary(); \
	friend struct Z_Construct_UClass_ULowEntryExtendedStandardLibrary_Statics; \
public: \
	DECLARE_CLASS(ULowEntryExtendedStandardLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/LowEntryExtendedStandardLibrary"), NO_API) \
	DECLARE_SERIALIZER(ULowEntryExtendedStandardLibrary)


#define BaylorBlackGospelVR_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_Classes_LowEntryExtendedStandardLibrary_h_88_INCLASS \
private: \
	static void StaticRegisterNativesULowEntryExtendedStandardLibrary(); \
	friend struct Z_Construct_UClass_ULowEntryExtendedStandardLibrary_Statics; \
public: \
	DECLARE_CLASS(ULowEntryExtendedStandardLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/LowEntryExtendedStandardLibrary"), NO_API) \
	DECLARE_SERIALIZER(ULowEntryExtendedStandardLibrary)


#define BaylorBlackGospelVR_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_Classes_LowEntryExtendedStandardLibrary_h_88_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ULowEntryExtendedStandardLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ULowEntryExtendedStandardLibrary) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ULowEntryExtendedStandardLibrary); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ULowEntryExtendedStandardLibrary); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ULowEntryExtendedStandardLibrary(ULowEntryExtendedStandardLibrary&&); \
	NO_API ULowEntryExtendedStandardLibrary(const ULowEntryExtendedStandardLibrary&); \
public:


#define BaylorBlackGospelVR_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_Classes_LowEntryExtendedStandardLibrary_h_88_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ULowEntryExtendedStandardLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ULowEntryExtendedStandardLibrary(ULowEntryExtendedStandardLibrary&&); \
	NO_API ULowEntryExtendedStandardLibrary(const ULowEntryExtendedStandardLibrary&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ULowEntryExtendedStandardLibrary); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ULowEntryExtendedStandardLibrary); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ULowEntryExtendedStandardLibrary)


#define BaylorBlackGospelVR_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_Classes_LowEntryExtendedStandardLibrary_h_88_PRIVATE_PROPERTY_OFFSET
#define BaylorBlackGospelVR_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_Classes_LowEntryExtendedStandardLibrary_h_85_PROLOG
#define BaylorBlackGospelVR_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_Classes_LowEntryExtendedStandardLibrary_h_88_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	BaylorBlackGospelVR_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_Classes_LowEntryExtendedStandardLibrary_h_88_PRIVATE_PROPERTY_OFFSET \
	BaylorBlackGospelVR_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_Classes_LowEntryExtendedStandardLibrary_h_88_RPC_WRAPPERS \
	BaylorBlackGospelVR_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_Classes_LowEntryExtendedStandardLibrary_h_88_INCLASS \
	BaylorBlackGospelVR_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_Classes_LowEntryExtendedStandardLibrary_h_88_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define BaylorBlackGospelVR_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_Classes_LowEntryExtendedStandardLibrary_h_88_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	BaylorBlackGospelVR_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_Classes_LowEntryExtendedStandardLibrary_h_88_PRIVATE_PROPERTY_OFFSET \
	BaylorBlackGospelVR_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_Classes_LowEntryExtendedStandardLibrary_h_88_RPC_WRAPPERS_NO_PURE_DECLS \
	BaylorBlackGospelVR_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_Classes_LowEntryExtendedStandardLibrary_h_88_INCLASS_NO_PURE_DECLS \
	BaylorBlackGospelVR_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_Classes_LowEntryExtendedStandardLibrary_h_88_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class LowEntryExtendedStandardLibrary."); \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID BaylorBlackGospelVR_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_Classes_LowEntryExtendedStandardLibrary_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
