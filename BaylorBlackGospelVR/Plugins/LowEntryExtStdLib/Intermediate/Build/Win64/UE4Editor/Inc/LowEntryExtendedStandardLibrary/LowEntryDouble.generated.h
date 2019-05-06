// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class ULowEntryLong;
class ULowEntryDouble;
#ifdef LOWENTRYEXTENDEDSTANDARDLIBRARY_LowEntryDouble_generated_h
#error "LowEntryDouble.generated.h already included, missing '#pragma once' in LowEntryDouble.h"
#endif
#define LOWENTRYEXTENDEDSTANDARDLIBRARY_LowEntryDouble_generated_h

#define BaylorBlackGospelVR_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_ClassesTypes_LowEntryDouble_h_18_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execLongBytes_LessThan) \
	{ \
		P_GET_OBJECT(ULowEntryLong,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->LongBytes_LessThan(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLongBytes_GreaterThan) \
	{ \
		P_GET_OBJECT(ULowEntryLong,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->LongBytes_GreaterThan(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDoubleBytes_LessThan) \
	{ \
		P_GET_OBJECT(ULowEntryDouble,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->DoubleBytes_LessThan(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDoubleBytes_GreaterThan) \
	{ \
		P_GET_OBJECT(ULowEntryDouble,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->DoubleBytes_GreaterThan(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDoubleBytes_Equals) \
	{ \
		P_GET_OBJECT(ULowEntryDouble,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->DoubleBytes_Equals(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDoubleBytes_Subtract) \
	{ \
		P_GET_OBJECT(ULowEntryDouble,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->DoubleBytes_Subtract(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDoubleBytes_Add) \
	{ \
		P_GET_OBJECT(ULowEntryDouble,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->DoubleBytes_Add(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execInteger_LessThan) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->Integer_LessThan(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execInteger_GreaterThan) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->Integer_GreaterThan(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execFloat_LessThan) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->Float_LessThan(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execFloat_GreaterThan) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->Float_GreaterThan(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execFloat_Equals) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->Float_Equals(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execFloat_Subtract) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Float_Subtract(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execFloat_Add) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Float_Add(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCastToString) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_MinFractionalDigits); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=P_THIS->CastToString(Z_Param_MinFractionalDigits); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCastToLongBytes) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryLong**)Z_Param__Result=P_THIS->CastToLongBytes(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCreateClone) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryDouble**)Z_Param__Result=P_THIS->CreateClone(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetBytes) \
	{ \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_ByteArray); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Index); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Length); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetBytes(Z_Param_Out_ByteArray,Z_Param_Index,Z_Param_Length); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetBytes) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<uint8>*)Z_Param__Result=P_THIS->GetBytes(); \
		P_NATIVE_END; \
	}


#define BaylorBlackGospelVR_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_ClassesTypes_LowEntryDouble_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execLongBytes_LessThan) \
	{ \
		P_GET_OBJECT(ULowEntryLong,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->LongBytes_LessThan(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLongBytes_GreaterThan) \
	{ \
		P_GET_OBJECT(ULowEntryLong,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->LongBytes_GreaterThan(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDoubleBytes_LessThan) \
	{ \
		P_GET_OBJECT(ULowEntryDouble,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->DoubleBytes_LessThan(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDoubleBytes_GreaterThan) \
	{ \
		P_GET_OBJECT(ULowEntryDouble,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->DoubleBytes_GreaterThan(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDoubleBytes_Equals) \
	{ \
		P_GET_OBJECT(ULowEntryDouble,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->DoubleBytes_Equals(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDoubleBytes_Subtract) \
	{ \
		P_GET_OBJECT(ULowEntryDouble,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->DoubleBytes_Subtract(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDoubleBytes_Add) \
	{ \
		P_GET_OBJECT(ULowEntryDouble,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->DoubleBytes_Add(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execInteger_LessThan) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->Integer_LessThan(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execInteger_GreaterThan) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->Integer_GreaterThan(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execFloat_LessThan) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->Float_LessThan(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execFloat_GreaterThan) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->Float_GreaterThan(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execFloat_Equals) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->Float_Equals(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execFloat_Subtract) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Float_Subtract(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execFloat_Add) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Float_Add(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCastToString) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_MinFractionalDigits); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=P_THIS->CastToString(Z_Param_MinFractionalDigits); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCastToLongBytes) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryLong**)Z_Param__Result=P_THIS->CastToLongBytes(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCreateClone) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ULowEntryDouble**)Z_Param__Result=P_THIS->CreateClone(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetBytes) \
	{ \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_ByteArray); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Index); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Length); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetBytes(Z_Param_Out_ByteArray,Z_Param_Index,Z_Param_Length); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetBytes) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<uint8>*)Z_Param__Result=P_THIS->GetBytes(); \
		P_NATIVE_END; \
	}


#define BaylorBlackGospelVR_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_ClassesTypes_LowEntryDouble_h_18_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesULowEntryDouble(); \
	friend struct Z_Construct_UClass_ULowEntryDouble_Statics; \
public: \
	DECLARE_CLASS(ULowEntryDouble, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/LowEntryExtendedStandardLibrary"), NO_API) \
	DECLARE_SERIALIZER(ULowEntryDouble)


#define BaylorBlackGospelVR_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_ClassesTypes_LowEntryDouble_h_18_INCLASS \
private: \
	static void StaticRegisterNativesULowEntryDouble(); \
	friend struct Z_Construct_UClass_ULowEntryDouble_Statics; \
public: \
	DECLARE_CLASS(ULowEntryDouble, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/LowEntryExtendedStandardLibrary"), NO_API) \
	DECLARE_SERIALIZER(ULowEntryDouble)


#define BaylorBlackGospelVR_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_ClassesTypes_LowEntryDouble_h_18_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ULowEntryDouble(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ULowEntryDouble) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ULowEntryDouble); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ULowEntryDouble); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ULowEntryDouble(ULowEntryDouble&&); \
	NO_API ULowEntryDouble(const ULowEntryDouble&); \
public:


#define BaylorBlackGospelVR_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_ClassesTypes_LowEntryDouble_h_18_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ULowEntryDouble(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ULowEntryDouble(ULowEntryDouble&&); \
	NO_API ULowEntryDouble(const ULowEntryDouble&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ULowEntryDouble); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ULowEntryDouble); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ULowEntryDouble)


#define BaylorBlackGospelVR_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_ClassesTypes_LowEntryDouble_h_18_PRIVATE_PROPERTY_OFFSET
#define BaylorBlackGospelVR_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_ClassesTypes_LowEntryDouble_h_15_PROLOG
#define BaylorBlackGospelVR_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_ClassesTypes_LowEntryDouble_h_18_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	BaylorBlackGospelVR_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_ClassesTypes_LowEntryDouble_h_18_PRIVATE_PROPERTY_OFFSET \
	BaylorBlackGospelVR_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_ClassesTypes_LowEntryDouble_h_18_RPC_WRAPPERS \
	BaylorBlackGospelVR_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_ClassesTypes_LowEntryDouble_h_18_INCLASS \
	BaylorBlackGospelVR_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_ClassesTypes_LowEntryDouble_h_18_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define BaylorBlackGospelVR_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_ClassesTypes_LowEntryDouble_h_18_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	BaylorBlackGospelVR_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_ClassesTypes_LowEntryDouble_h_18_PRIVATE_PROPERTY_OFFSET \
	BaylorBlackGospelVR_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_ClassesTypes_LowEntryDouble_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
	BaylorBlackGospelVR_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_ClassesTypes_LowEntryDouble_h_18_INCLASS_NO_PURE_DECLS \
	BaylorBlackGospelVR_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_ClassesTypes_LowEntryDouble_h_18_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class LowEntryDouble."); \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID BaylorBlackGospelVR_Plugins_LowEntryExtStdLib_Source_LowEntryExtendedStandardLibrary_Public_ClassesTypes_LowEntryDouble_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
