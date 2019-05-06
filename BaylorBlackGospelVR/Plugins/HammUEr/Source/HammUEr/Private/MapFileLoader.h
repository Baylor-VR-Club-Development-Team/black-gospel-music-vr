// HammUEr
// Copyright 2015-2016 Turfster / NT Entertainment
// All Rights Reserved.


// This code is held together with kitten whiskers and toothpicks.
// There's nothing to see or learn here.
// Seriously.
// Turn back.

#pragma once
#include "MapShared/BaseEntity.h"
#include "MapShared/MapLoaderBase.h"
#include "MAPLoader/MAPLoader.h"
#include "D3/Doom3ProcLoader.h"
#include "SourceVMF/VMFLoader.h"
#include "MapShared/MAPSettings.h"
#include "MapShared/MAPSpotlight.h"
#include "MapShared/MAPEnvironmentLight.h"
#include "MapShared/MAPLight.h"
#include "MapShared/MAPPropStatic.h"
#include "MapShared/MAPOverlay.h"
#include "MapShared/MAPPropDynamic.h"
#include "MapShared/VMFFuncInstance.h"
#include "InstanceDataHandler.h"
#include "HammUErObjects.h"

enum MapSettingType :int
{
	ConversionRate,
	RoundPoints,
	RoundMeshPoints,
	IntersectRange,
	DiscardErrorRange,
	Verbose,
	DontSmooth,
	SmoothingAngle,
	SmoothWeldRange,
	DispAlphaChannel,
	PatchDivV,
	PatchDivH,
	RoundDisplacementPoints
};

class MapFileLoader{
	
	private:
		static MapLoaderBase* myLoader;
		static MapLoaderBase* testLoader;  // this is for the planned watchdog thing
		static FString importDirectory;
		static FString cacheFilename;

		static bool createInstanceData;
		static InstanceDataHandler* instanceData;
		static FString instanceFileName;

	public:
		static void SetInstanceFilename(FString inFileName)
		{
			instanceFileName = inFileName;
		}

		static void ToggleInstance(bool inB)
		{
			createInstanceData = inB;
		}

		static void Open(FString fileName)
		{
			textureCheat = false;
			if (fileName.ToLower().EndsWith(".proc"))
			{
				myLoader = (MapLoaderBase*)new D3Proc();
				textureCheat = true;
			}
			else
				if (fileName.ToLower().EndsWith(".map"))
					myLoader = (MapLoaderBase*)new MAPLoader();
				else
					myLoader = (MapLoaderBase*)new VMFLoader();
			if (myLoader)
			{
				cacheFilename = fileName;
				myLoader->Open(TCHAR_TO_UTF8(*fileName));
			}
		}

		static void Set(MapSettingType inType, float value)
		{
			if (myLoader != NULL)
				switch (inType)
				{
				case MapSettingType::ConversionRate:
					myLoader->SetConversion(value);
					MAPSettings::localConversionRate = value;
					local_conversionFactor = 100.f / value;
					break;
				case MapSettingType::IntersectRange:
					MAPSettings::intersectRange = value;
					break;
				case MapSettingType::DiscardErrorRange:
					MAPSettings::discardErrorRange = value;
					break;
				case MapSettingType::SmoothingAngle:
					myLoader->SetSmoothingAngle(value);
					break;
				case MapSettingType::SmoothWeldRange:
					myLoader->SetSmoothingWeldRange(value);
					break;
				case MapSettingType::DispAlphaChannel:
					MAPSettings::defaultDisplacementAlphaChannel = value;
					break;
				case MapSettingType::PatchDivH:
					MAPSettings::defaultPatchSubdivisionH = value;
					break;
				case MapSettingType::PatchDivV:
					MAPSettings::defaultPatchSubdivisionV = value;
					break;
				}
		}

		static void Set(MapSettingType inType, bool value)
		{
			if (myLoader != NULL)
				switch (inType)
				{
				case MapSettingType::RoundPoints:
					MAPSettings::roundPoints = value;
					break;
				case MapSettingType::RoundMeshPoints:
					MAPSettings::roundMeshPoints = value;
					break;
				case MapSettingType::RoundDisplacementPoints:
					MAPSettings::roundDisplacementPoints = value;
					break;
				case MapSettingType::DontSmooth:
					myLoader->SetDontSmooth(value);
					break;
				case MapSettingType::Verbose:
					break;
				}
		}

		static bool PhaseOne()
		{
			if (myLoader != NULL)
				return myLoader->PhaseOne();
			UE_LOG(LogTemp, Error, TEXT("No map loaded!"));
			return false;
		}

		static void PhaseTwo(TArray<int32> tws, TArray<int32> ths, TArray<bool> tnd)
		{
			if (myLoader != NULL)
			{
				FScopedSlowTask SlowTask(6, FText::FromString("Calculating..."));
				SlowTask.MakeDialog();
				SlowTask.EnterProgressFrame(2);
				std::vector<int> tw2;
				for (int i = 0; i < tws.Num(); i++)
					tw2.push_back(tws[i]);
				std::vector<int> th2;
				for (int i = 0; i < ths.Num(); i++)
					th2.push_back(ths[i]);
				std::vector<bool> tn2;
				for (int i = 0; i < tnd.Num(); i++)
					tn2.push_back(tnd[i]);

				myLoader->PhaseTwo(tw2, th2, tn2);
				SlowTask.EnterProgressFrame(4);
				tw2.empty();
				th2.empty();
				tn2.empty();
			}
		}

		static TArray<FString> GetMaterials()
		{
			if (myLoader != NULL)
			{
				TArray<FString> result;
				std::vector<std::string> input = myLoader->GetMaterials();
				for (int i = 0; i < input.size(); i++)
					result.Add(input[i].c_str());
				return result;

			}
			else
			{
				UE_LOG(LogTemp, Error, TEXT("No map loaded!"));
				TArray<FString> empty;
				return empty;
			}
		}

		static int GetNumBrushes()
		{
			if (myLoader != NULL)
				return myLoader->GetNumBrushes();
			UE_LOG(LogTemp, Error, TEXT("No map loaded!"));
			return 0;
		}

		static MapBrush* GetBrush(int index)
		{
			if (myLoader != NULL)
				return myLoader->GetBrush(index);
			UE_LOG(LogTemp, Error, TEXT("No map loaded!"));
			return NULL;
		}

		static int GetNumEntities()
		{
			if (myLoader != NULL)
				return myLoader->GetNumEntities();
			UE_LOG(LogTemp, Error, TEXT("No map loaded!"));
			return 0;
		}

		static int GetEntityID(int index)
		{
			if (myLoader != NULL)
				return myLoader->GetEntityID(index);
			UE_LOG(LogTemp, Error, TEXT("No map loaded!"));
			return -1;
		}

		static FString GetEntityName(int index)
		{
			if (myLoader != NULL)
				return (myLoader->GetEntityName(index)).c_str();
			UE_LOG(LogTemp, Error, TEXT("No map loaded!"));
			return "What are you even trying to do?";
		}

		static MapEntityType GetEntityType(int index)
		{
			if (myLoader != NULL)
				return myLoader->GetEntityType(index);
			UE_LOG(LogTemp, Error, TEXT("No map loaded!"));
			return MapEntityType::Unknown;
		}

		static BaseEntity* GetEntity(int index)
		{
			if (myLoader != NULL)
				return myLoader->GetEntity(index);
			UE_LOG(LogTemp, Error, TEXT("No map loaded!"));
			return NULL;
		}

		static FString GetStageName()
		{
			if (myLoader != NULL)
				return myLoader->GetStageName().c_str();
			UE_LOG(LogTemp, Error, TEXT("No map loaded!"));
			return "idle";
		}

		static float GetStagePercentage()
		{
			if (myLoader != NULL)
				return myLoader->GetStagePercentage();
			UE_LOG(LogTemp, Error, TEXT("No map loaded!"));
			return 0.f;
		}

		static void SetImportDir(FString inDir)
		{
			if (myLoader != NULL)
			{
				inDir.Replace(TEXT("\\"), TEXT("/"));
				if (inDir.EndsWith("/"))
					inDir.RemoveAt(inDir.Len() - 1, 1);
				importDirectory = inDir;
			}
			else
				UE_LOG(LogTemp, Error, TEXT("No map loaded!"));
		}

		static void ImportIntoWorld(TArray<UMaterialInterface*> newMaterials, bool doAll);

	static bool textureCheat; // .proc cheat thingy

	private:
		static UStaticMesh* ImportBrush(MapBrush* workBrush, TArray<UMaterialInterface*> newMaterials, FVector &meshPosition, bool overrideDecouple = false,  bool buildActor = true, bool noComplex = false);
		static bool PreviousActorExists(FString name, bool doDestroy = false, FString tag = "", bool ignoreTag = true);
		static AActor* GetPreviousActor(FString name, FString tag = "", bool ignoreTag = true);

		static bool IsIgnoreActor(FString name);

		static void DoFuncBrush(int32 entityIndex, TArray<UMaterialInterface*> newMaterials);
		static void DoFuncStatic(int32 entityIndex, TArray<UMaterialInterface*> newMaterials);
		static void DoFuncBox(int32 entityIndex, TArray<UMaterialInterface*> newMaterials);
		static void DoLogicRelay(int32 entityIndex);
		static void DoLogicAuto(int32 entityIndex);
		static void DoPropStatic(int32 entityIndex, MAPPropStatic* instancedProp = NULL);
		static void DoPropDynamic(int32 entityIndex, MAPPropDynamic* instancedProp = NULL);
		static void DoLight(int32 entityIndex, MAPLight* instancedLight = NULL);
		static void DoSpotLight(int32 entityIndex, MAPSpotLight* instancedSpotLight=NULL);
		static void DoEnvironmentLight(int32 entityIndex, MAPEnvironmentLight* instancedEnvironmentLight=NULL);
		static AHammuerPathNode* DoPath(int32 entityIndex);
		static void DoOverlay(int32 entityIndex, MAPOverlay* inputData = NULL);
		static void DoDummy(int32 entityIndex);
		static void DoFuncInstance(int32 entityIndex, VMFFuncInstance* inputData = NULL);

		static void GetRotationValues(int rotationType, FVector angles, float& changePitch, float& changeRoll, float &changeYaw);

		static float local_conversionFactor;

		// for the missing prop notification stuff
		static UStaticMesh* GenerateTemporaryModel(std::string modelLocation, bool generateExclamation = false);
		static UMaterialInterface* debugPropMaterial;
/*		static TArray<UStaticMesh*> listofStaticMeshes;
		static UPackage* Package;*/
};