// HammUEr
// Copyright 2015-2016 Turfster / NT Entertainment
// All Rights Reserved.


// This code is held together with kitten whiskers and toothpicks.
// There's nothing to see or learn here.
// Seriously.
// Turn back.

#include "HammUErPrivatePCH.h"
#include "MapFileLoader.h"

#include "RawMesh.h"
#include "AssetRegistryModule.h"

#include "MapShared/MAPConverters.h"
#include "MapShared/MAPLight.h"
#include "MapShared/MAPSpotLight.h"
#include "MapShared/MAPEnvironmentLight.h"
#include "MapShared/MAPOverlay.h"
#include "MapShared/MAPFuncBrush.h"
#include "MapShared/MAPPropStatic.h"
#include "MapShared/MAPPropDynamic.h"
#include "MapShared/VMFLogicAuto.h"
#include "MapShared/VMFLogicRelay.h"
#include "MapShared/VMFFuncInstance.h"
#include "MapShared/MAPFuncPhysBox.h"
#include "MapShared/MAPPath.h"
#include "HammUErObjects.h"
#include "../../HammUErRuntime/Public/HammUErRuntimeClasses.h"

#include "Materials/MaterialExpressionVertexColor.h"

#include "Runtime/Launch/Resources/Version.h" 

#include "ObjectTools.h"

#include "InstanceDataHandler.h"

MapLoaderBase* MapFileLoader::myLoader;
FString MapFileLoader::importDirectory;
FString MapFileLoader::cacheFilename;
float MapFileLoader::local_conversionFactor;
bool MapFileLoader::textureCheat;
bool MapFileLoader::createInstanceData;
InstanceDataHandler* MapFileLoader::instanceData;
FString MapFileLoader::instanceFileName;
UMaterialInterface* MapFileLoader::debugPropMaterial;

/*TArray<UStaticMesh*> MapFileLoader::listofStaticMeshes;
UPackage* MapFileLoader::Package;*/

void RecenterMesh(FRawMesh& rawMesh, FVector& newPosition, bool shiftOverride = false) // can't pass a default as a reference, of course, so
{
	if (!shiftOverride)
	{
		newPosition = FVector::ZeroVector;
		for (int i = 0; i < rawMesh.VertexPositions.Num(); i++)
			newPosition += rawMesh.VertexPositions[i];
		newPosition /= rawMesh.VertexPositions.Num();
	}

	for (int i = 0; i < rawMesh.VertexPositions.Num(); i++)
		rawMesh.VertexPositions[i] -= newPosition;
}

void BuildRawMesh(std::vector<VMFTri*> triangles, FRawMesh& rawMesh, TArray<int32>& materialReindex)
{
	// prep stuff
	int32 numFaces = triangles.size();
	if (numFaces == 0)
		return;

	TArray<bool> loadTris;
	for (int i = 0; i < numFaces; i++)
		loadTris.Add(true);

	if (HammUErSettings::checkDegenerates) // UE faceplants hard when it runs into degenerate triangles when building a staticmesh
	{
		for (int tri = 0; tri < triangles.size(); tri++)
		{
			if (FVector::PointsAreSame(MAPConverters::MAPtoF(triangles[tri]->v1), MAPConverters::MAPtoF(triangles[tri]->v2)) ||
				FVector::PointsAreSame(MAPConverters::MAPtoF(triangles[tri]->v1), MAPConverters::MAPtoF(triangles[tri]->v3)) ||
				FVector::PointsAreSame(MAPConverters::MAPtoF(triangles[tri]->v2), MAPConverters::MAPtoF(triangles[tri]->v3)))
			{
				UE_LOG(LogTemp, Warning, TEXT("Degenerate triangle found. Skipping."));
				loadTris[tri] = false;
				numFaces--;
			}
		}
	}
	
	if (numFaces == 0)
		return;


	int32 numVertices = numFaces * 3;
	int32 verticesOffset = rawMesh.VertexPositions.Num(); // might as well add this for later combining // do I... actually still use this?
	int32 faceIndexOffset = rawMesh.FaceMaterialIndices.Num();

	rawMesh.FaceMaterialIndices.AddZeroed(numFaces);
	rawMesh.FaceSmoothingMasks.AddZeroed(numFaces);

	TArray<FVector> keptVertices;
	TArray<uint32> triVertexIndex;

	for (int i = 0; i < triangles.size(); i++) // okay, we need to rebuild the entire thing to have shared vertex pos + UVs... and normals I guess. God this is such a pain
	{											// actually, we don't, I just ran into a shitty bug
		if (loadTris[i])
		{
			triVertexIndex.Add(keptVertices.AddUnique(MAPConverters::MAPtoF(triangles[i]->v1)));//VertexInformation(MAPConverters::MAPtoF(triangles[i]->v1), MAPConverters::MAPtoF(triangles[i]->n1), MAPConverters::MAPtoF(triangles[i]->uv1), MAPConverters::MAPtoF(triangles[i]->c1))));
			triVertexIndex.Add(keptVertices.AddUnique(MAPConverters::MAPtoF(triangles[i]->v2)));//VertexInformation(MAPConverters::MAPtoF(triangles[i]->v2), MAPConverters::MAPtoF(triangles[i]->n2), MAPConverters::MAPtoF(triangles[i]->uv2), MAPConverters::MAPtoF(triangles[i]->c2))));
			triVertexIndex.Add(keptVertices.AddUnique(MAPConverters::MAPtoF(triangles[i]->v3)));//VertexInformation(MAPConverters::MAPtoF(triangles[i]->v3), MAPConverters::MAPtoF(triangles[i]->n3), MAPConverters::MAPtoF(triangles[i]->uv3), MAPConverters::MAPtoF(triangles[i]->c3))));
		}
	}
	if (triVertexIndex.Num() != numVertices)
	{
		UE_LOG(LogTemp, Error, TEXT("Something went wrong reducing vertices!"));
		return;
	}

	UE_LOG(LogTemp, Log, TEXT("Reduced vertices from %i to %i"), triangles.size() * 3, keptVertices.Num());

	rawMesh.VertexPositions.AddZeroed(keptVertices.Num());

	for (int i = 0; i < keptVertices.Num(); i++)
	{
		rawMesh.VertexPositions[i] = keptVertices[i];
	}

	int currentIndex = 0;

	for (int tri = 0; tri < triangles.size(); tri++)
	{
		if (!loadTris[tri])
			continue;

		rawMesh.WedgeTexCoords[0].Add(MAPConverters::MAPtoF(triangles[tri]->uv1));
		rawMesh.WedgeTangentX.Add(FVector::ZeroVector);
		rawMesh.WedgeTangentY.Add(FVector::ZeroVector);
		rawMesh.WedgeTangentZ.Add(MAPConverters::MAPtoF(triangles[tri]->n1));
		rawMesh.WedgeColors.Add(MAPConverters::MAPtoF(triangles[tri]->c1));
		rawMesh.WedgeIndices.Add(verticesOffset + triVertexIndex[currentIndex]);

		rawMesh.WedgeTexCoords[0].Add(MAPConverters::MAPtoF(triangles[tri]->uv3));
		rawMesh.WedgeTangentX.Add(FVector::ZeroVector);
		rawMesh.WedgeTangentY.Add(FVector::ZeroVector);
		rawMesh.WedgeTangentZ.Add(MAPConverters::MAPtoF(triangles[tri]->n3));
		rawMesh.WedgeColors.Add(MAPConverters::MAPtoF(triangles[tri]->c3));
		rawMesh.WedgeIndices.Add(verticesOffset + triVertexIndex[currentIndex+2]);

		rawMesh.WedgeTexCoords[0].Add(MAPConverters::MAPtoF(triangles[tri]->uv2));
		rawMesh.WedgeTangentX.Add(FVector::ZeroVector);
		rawMesh.WedgeTangentY.Add(FVector::ZeroVector);
		rawMesh.WedgeTangentZ.Add(MAPConverters::MAPtoF(triangles[tri]->n2));
		rawMesh.WedgeColors.Add(MAPConverters::MAPtoF(triangles[tri]->c2));
		rawMesh.WedgeIndices.Add(verticesOffset + triVertexIndex[currentIndex+1]);
		currentIndex += 3;

		int matIndex = 0;
		if (materialReindex.Contains(triangles[tri]->matId))
			matIndex = materialReindex.Find(triangles[tri]->matId);
		else
			matIndex = materialReindex.Add(triangles[tri]->matId);

		rawMesh.FaceMaterialIndices[faceIndexOffset++] = matIndex;
	}

}

bool MapFileLoader::IsIgnoreActor(FString name)
{
	if (!HammUErSettings::checkIgnore)
		return false;		// early out, we're not doing anything

	FName tagToCheck = FName(*FString("HammUErIgnoreOnImport"));
	for (TObjectIterator<AActor> Itr; Itr; ++Itr)
	{
		FString toCheck = Itr->GetActorLabel();
		if (toCheck == name)
		{
			if (Itr->Tags.Contains(tagToCheck))
			{
				if (HammUErSettings::toDeleteList.Num() > 0)
				{
					if (HammUErSettings::toDeleteList.Contains(name))
						HammUErSettings::toDeleteList.Remove(name);
				}
				return true;
			}
		}
	}
	return false;
}

bool MapFileLoader::PreviousActorExists(FString name, bool doDestroy, FString tag, bool ignoreTag)
{
	for (TObjectIterator<AActor> Itr; Itr; ++Itr)
	{
		FString toCheck = Itr->GetActorLabel();
		if (toCheck == name)
		{
			if (Itr->Tags.Contains(*tag))
			{
				if (doDestroy)
				{
					GWorld->DestroyActor(*Itr);
					UE_LOG(LogTemp, Warning, TEXT("Removed old same name collision for %s."), *toCheck);
				}
				return true;
			}
			if (ignoreTag)
				return true;
		}
	}
	return false;
}

AActor* MapFileLoader::GetPreviousActor(FString name, FString tag, bool ignoreTag)
{
	for (TObjectIterator<AActor> Itr; Itr; ++Itr)
	{
		FString toCheck = Itr->GetActorLabel();
		if (toCheck == name)
		{
			if (ignoreTag)
				return (*Itr);
			if (Itr->Tags.Contains(*tag))
				return (*Itr);
		}
	}
	return NULL;
}

// yes, these have a lot of repeat code. Shut up.
void MapFileLoader::DoDummy(int32 entityIndex)
{
	BaseEntity* data = GetEntity(entityIndex);
	FRotator rotatorToUse = FRotator(HammUErSettings::importRotationValue.Y, HammUErSettings::importRotationValue.Z, HammUErSettings::importRotationValue.X);
	UWorld* editorWorld = GEditor->GetEditorWorldContext().World();

	FActorSpawnParameters FAS;
	FString tempName = data->name.c_str();
	if (tempName == "")
	{
		tempName = data->classname.c_str(); 
		tempName += "_" + FString::FromInt(data->id);
	}

	if (HammUErSettings::alwaysPrependFilename) 
		if (!tempName.StartsWith(FPaths::GetBaseFilename(cacheFilename))) // this should never happen, but you never know
		tempName = FPaths::GetBaseFilename(cacheFilename) + "_" + tempName;

	FString tag = "Entity_" + FString::FromInt(data->id);

	if (IsIgnoreActor(tempName))
	{
		UE_LOG(LogTemp, Log, TEXT("Skipping %s, contains ignore tag."), *tempName);
		return;
	}
	PreviousActorExists(tempName/*data->name*/, true, tag, false);

	FAS.Name = FName(*tag);

	FVector propPosition = FQuat(FVector(0.0f, 0.0f, 1.0f), 3 * PI / 2.f)*MAPConverters::MAPtoF(data->origin);
	ANote* tempActor = editorWorld->SpawnActor<ANote>(FAS);
	tempActor->SetActorLabel(tempName);
	
	if (HammUErSettings::importNonZero)
		propPosition += HammUErSettings::importOffset;

	if ((HammUErSettings::importRotation) && (HammUErSettings::CenterCheckboxEnabled))
		propPosition = rotatorToUse.RotateVector(propPosition);

	if (HammUErSettings::importRotation)
		tempActor->SetActorRotation(rotatorToUse);

	tempActor->SetActorLocation(propPosition);
	tempActor->Tags.Empty();
	tempActor->Tags.Add(FName(*tag));
	tempActor->Tags.Add(FName(data->classname.c_str()));

	tempActor->PostEditChange();
}

void MapFileLoader::DoFuncBrush(int32 entityIndex, TArray<UMaterialInterface*> newMaterials)
{
	MAPFuncBrush* data = (MAPFuncBrush*)GetEntity(entityIndex);
	if ((!data->myBrush) && (data->modelname ==""))
	{
		UE_LOG(LogTemp, Error, TEXT("No data for func_brush. Skipping..."));
		return;
	}
	FRotator rotatorToUse = FRotator(HammUErSettings::importRotationValue.Y, HammUErSettings::importRotationValue.Z, HammUErSettings::importRotationValue.X);
	UWorld* editorWorld = GEditor->GetEditorWorldContext().World();

	FActorSpawnParameters FAS;
	FString tempName = data->name.c_str();
	FString tag = "Entity_" + FString::FromInt(data->id);

	if (HammUErSettings::alwaysPrependFilename) 
		if (!tempName.StartsWith(FPaths::GetBaseFilename(cacheFilename))) // this should never happen, but you never know
		tempName = FPaths::GetBaseFilename(cacheFilename) + "_" + tempName;

	if (IsIgnoreActor(tempName))
	{
		UE_LOG(LogTemp, Log, TEXT("Skipping %s, contains ignore tag."), *tempName);
		return;
	}

	PreviousActorExists(tempName, true, tag, false);

	if (createInstanceData)
	{
		instanceData->instanceAdd(data->id);
		instanceData->instanceAddString(data->name.c_str());
	}

	FAS.Name = FName(*tag);

	FVector propPosition = FQuat(FVector(0.0f, 0.0f, 1.0f), 3 * PI / 2.f)*MAPConverters::MAPtoF(data->origin);

	FVector meshPosition = propPosition;//FVector::ZeroVector;

	UBlueprint* BPtoUse = NULL;
	BPtoUse = HammUErSettings::FindInBPDatabase("FuncBrushBP");
	if (BPtoUse)  // we want to use the blueprint version
	{
		TSubclassOf<AActor> BPClass = (UClass*)BPtoUse->GeneratedClass;
		AHammuerFuncBrushActor* tempActor = editorWorld->SpawnActor<AHammuerFuncBrushActor>(BPClass, FAS);
		UStaticMeshComponent* USMC = (UStaticMeshComponent*)tempActor->GetComponentByClass(UStaticMeshComponent::StaticClass());

		UStaticMesh* myMesh = NULL;
		if (data->modelname != "")
		{
			myMesh = HammUErSettings::FindInStaticMeshDatabase(data->modelname.c_str());
			if (HammUErSettings::propScaleType == 2)
				tempActor->SetActorScale3D(FVector(local_conversionFactor, local_conversionFactor, local_conversionFactor));

			if (HammUErSettings::ignorePitch)
				data->angles.X = 0;
			if (HammUErSettings::ignoreRoll)
				data->angles.Z = 0;
			if (HammUErSettings::ignoreYaw)
				data->angles.Y = 0;
		}
		else
		{
			myMesh = ImportBrush(data->myBrush, newMaterials, meshPosition, true, false);
			float offsetCheck = FMath::Abs((meshPosition - propPosition).Size());
			if (offsetCheck > 200.f) // objective vector offset thing to make sure we don't shift stuff too far away
				propPosition += meshPosition;
			else
				propPosition = meshPosition;
		}
		if (myMesh == NULL)
			myMesh = GenerateTemporaryModel(data->modelname.c_str());

		tempActor->SetActorLabel(tempName);
		tempActor->SetFriendlyName(data->name.c_str());

		if (HammUErSettings::toDeleteList.Num() > 0)
		{
			if (HammUErSettings::toDeleteList.Contains(tempName))
				HammUErSettings::toDeleteList.Remove(tempName);
		}

		if (HammUErSettings::importNonZero)
			propPosition += HammUErSettings::importOffset;

		if ((HammUErSettings::importRotation) && (HammUErSettings::CenterCheckboxEnabled))
			propPosition = rotatorToUse.RotateVector(propPosition);

		if (HammUErSettings::importRotation)
			tempActor->SetActorRotation(rotatorToUse);


		if (data->modelname != "")

		{
			FMatrix OGMatrix(FVector::ForwardVector, -FVector::RightVector, FVector::UpVector, FVector::ZeroVector);
			FMatrix rotationMatrix = HammUErSettings::CreateRotationMatrix(-data->angles.X, data->angles.Z, data->angles.Y);

			FMatrix finalMatrix = OGMatrix.Inverse()*rotationMatrix*OGMatrix;

			if (HammUErSettings::importRotation)
				tempActor->AddActorWorldRotation(finalMatrix.Rotator() + FRotator(0, 90, 0));
			else
				tempActor->SetActorRotation(finalMatrix.Rotator() + FRotator(0, 90, 0));
		}

		tempActor->SetActorLocation(propPosition);
		USMC->SetStaticMesh(myMesh);
		if ((HammUErSettings::twoSidedCull) && (data->myBrush->containsNoDraw || data->myBrush->containsDisplacements))
			USMC->bCastShadowAsTwoSided = true;
		USMC->PostEditChange();

		USMC->SetMobility(EComponentMobility::Static);

		for (int i = 0; i < data->myOutputs.size(); i++)
		{
			FHammuerOutput newOutput;
			newOutput.delay = data->myOutputs[i]->timeDelay;
			newOutput.onlyOnce = data->myOutputs[i]->fireOnce;
			newOutput.outputName = data->myOutputs[i]->outputName.c_str();
			newOutput.parameter = data->myOutputs[i]->parameters.c_str();
			newOutput.targetEntity = data->myOutputs[i]->targetEntity.c_str();
			newOutput.targetInput = data->myOutputs[i]->targetInput.c_str();
			tempActor->myOutputs.Add(newOutput);
		}

		tempActor->SetSolidity(data->solidity);
		tempActor->SetShadows(data->shadows);
		tempActor->StartDisabled(data->startsDisabled);

		tempActor->Tags.Empty();
		tempActor->Tags.Add(FName(*tag));
		tempActor->Tags.Add(FName(data->classname.c_str()));

		tempActor->PostEditChange();
	}
	else
	{
		AStaticMeshActor* tempActor = editorWorld->SpawnActor<AStaticMeshActor>(FAS);

		UStaticMesh* myMesh = NULL;
		if (data->modelname != "")
		{

			myMesh = HammUErSettings::FindInStaticMeshDatabase(data->modelname.c_str());
			if (HammUErSettings::propScaleType == 2)
				tempActor->SetActorScale3D(FVector(local_conversionFactor, local_conversionFactor, local_conversionFactor));

			if (createInstanceData)
			{
				int funcType = 01;
				instanceData->instanceAdd(funcType);
				instanceData->instanceAddString(data->modelname.c_str());
			}

			if (HammUErSettings::ignorePitch)
				data->angles.X = 0;
			if (HammUErSettings::ignoreRoll)
				data->angles.Z = 0;
			if (HammUErSettings::ignoreYaw)
				data->angles.Y = 0;

			if (HammUErSettings::generateOverlaps)
				tempActor->GetStaticMeshComponent()->SetGenerateOverlapEvents(true);
		}
		else
		{
			if (createInstanceData)
			{
				int funcType = 02;
				instanceData->instanceAdd(funcType);
			}

			myMesh = ImportBrush(data->myBrush, newMaterials, meshPosition, true, false);
			float offsetCheck = FMath::Abs((meshPosition - propPosition).Size());
			if (offsetCheck > 200.f) // objective vector offset thing to make sure we don't shift stuff too far away
				propPosition += meshPosition;
			else
				propPosition = meshPosition;
		}
		if (myMesh == NULL)
			myMesh = GenerateTemporaryModel(data->modelname.c_str());

		if (createInstanceData)
		{
			instanceData->instanceAdd(data->origin);
			instanceData->instanceAdd(data->angles);
			instanceData->instanceAdd(data->solidity);
			instanceData->instanceAdd(data->shadows);
			instanceData->instanceAdd(data->startsDisabled);
		}


		tempActor->SetActorLabel(tempName);
		if (HammUErSettings::toDeleteList.Num() > 0)
		{
			if (HammUErSettings::toDeleteList.Contains(tempName))
				HammUErSettings::toDeleteList.Remove(tempName);
		}

		if (HammUErSettings::importNonZero)
			propPosition += HammUErSettings::importOffset;

		if ((HammUErSettings::importRotation) && (HammUErSettings::CenterCheckboxEnabled))
			propPosition = rotatorToUse.RotateVector(propPosition);

		if (HammUErSettings::importRotation)
			tempActor->SetActorRotation(rotatorToUse);

		if (data->modelname != "")
		{
			FMatrix OGMatrix(FVector::ForwardVector, -FVector::RightVector, FVector::UpVector, FVector::ZeroVector);
			FMatrix rotationMatrix = HammUErSettings::CreateRotationMatrix(-data->angles.X, data->angles.Z, data->angles.Y);

			FMatrix finalMatrix = OGMatrix.Inverse()*rotationMatrix*OGMatrix;

			if (HammUErSettings::importRotation)
				tempActor->AddActorWorldRotation(finalMatrix.Rotator() + FRotator(0, 90, 0));
			else
				tempActor->SetActorRotation(finalMatrix.Rotator() + FRotator(0, 90, 0));
		}

		tempActor->SetActorLocation(propPosition);
#if ENGINE_MINOR_VERSION < 14
		tempActor->GetStaticMeshComponent()->StaticMesh = myMesh;
#else
		tempActor->GetStaticMeshComponent()->SetStaticMesh(myMesh);
#endif
		tempActor->GetStaticMeshComponent()->SetMobility(EComponentMobility::Static);
		if ((HammUErSettings::twoSidedCull) && (data->myBrush->containsNoDraw || data->myBrush->containsDisplacements))
			((UPrimitiveComponent*)tempActor->GetRootComponent())->bCastShadowAsTwoSided = true;


		tempActor->Tags.Empty();
		tempActor->Tags.Add(FName(*tag));
		tempActor->Tags.Add(FName(data->classname.c_str()));

		tempActor->PostEditChange();
	}
}

void MapFileLoader::DoFuncBox(int32 entityIndex, TArray<UMaterialInterface*> newMaterials)
{
	MAPFuncPhysBox* data = (MAPFuncPhysBox*)GetEntity(entityIndex);
	if (!data->myBrush)
	{
		UE_LOG(LogTemp, Error, TEXT("No data for func_phys_box. Skipping..."));
		return;
	}
	FRotator rotatorToUse = FRotator(HammUErSettings::importRotationValue.Y, HammUErSettings::importRotationValue.Z, HammUErSettings::importRotationValue.X);
	UWorld* editorWorld = GEditor->GetEditorWorldContext().World();

	FActorSpawnParameters FAS;
	FString tempName = data->name.c_str();
	FString tag = "Entity_" + FString::FromInt(data->id);

	if (HammUErSettings::alwaysPrependFilename) 
		if (!tempName.StartsWith(FPaths::GetBaseFilename(cacheFilename))) // this should never happen, but you never know
		tempName = FPaths::GetBaseFilename(cacheFilename) + "_" + tempName;

	if (IsIgnoreActor(tempName))
	{
		UE_LOG(LogTemp, Log, TEXT("Skipping %s, contains ignore tag."), *tempName);
		return;
	}
	PreviousActorExists(tempName, true, tag, false);

	FAS.Name = FName(*tag);

	if (createInstanceData)
	{
		instanceData->instanceAdd(data->id);
		instanceData->instanceAddString(data->name.c_str());
	}

	FVector propPosition = FQuat(FVector(0.0f, 0.0f, 1.0f), 3 * PI / 2.f)*MAPConverters::MAPtoF(data->origin);

	FVector meshPosition = propPosition;//FVector::ZeroVector;
	UStaticMesh* myMesh = ImportBrush(data->myBrush, newMaterials, meshPosition, true, false,true);
	if (createInstanceData)
	{
		instanceData->instanceAdd(data->angles);
		instanceData->instanceAdd(data->solidity);
		instanceData->instanceAdd(data->shadows);
		instanceData->instanceAdd(data->startsDisabled);
	}

	float offsetCheck = FMath::Abs((meshPosition - propPosition).Size());
	if (offsetCheck>200.f) // objective vector offset thing to make sure we don't shift stuff too far away
		propPosition += meshPosition;
	else
		propPosition = meshPosition;

	AStaticMeshActor* tempActor = editorWorld->SpawnActor<AStaticMeshActor>(FAS);
	tempActor->SetActorLabel(tempName);
	
	if (HammUErSettings::toDeleteList.Num() > 0)
	{
		if (HammUErSettings::toDeleteList.Contains(tempName))
			HammUErSettings::toDeleteList.Remove(tempName);
	}
	
	if (HammUErSettings::importNonZero)
		propPosition += HammUErSettings::importOffset;

	if ((HammUErSettings::importRotation) && (HammUErSettings::CenterCheckboxEnabled))
		propPosition = rotatorToUse.RotateVector(propPosition);

	if (HammUErSettings::importRotation)
		tempActor->SetActorRotation(rotatorToUse);
	
	tempActor->SetActorLocation(propPosition);
#if ENGINE_MINOR_VERSION <14
	tempActor->GetStaticMeshComponent()->StaticMesh = myMesh;
#else
	tempActor->GetStaticMeshComponent()->SetStaticMesh(myMesh);
#endif
	tempActor->GetStaticMeshComponent()->SetMobility(EComponentMobility::Movable);
	tempActor->GetStaticMeshComponent()->SetSimulatePhysics(true);
	if ((HammUErSettings::twoSidedCull) && (data->myBrush->containsNoDraw || data->myBrush->containsDisplacements))
		((UPrimitiveComponent*)tempActor->GetRootComponent())->bCastShadowAsTwoSided = true;

	tempActor->Tags.Empty();
	tempActor->Tags.Add(FName(*tag));
	tempActor->Tags.Add(FName(data->classname.c_str()));

	tempActor->PostEditChange();
}

void MapFileLoader::DoFuncStatic(int32 entityIndex, TArray<UMaterialInterface*> newMaterials)
{
	MAPFuncBrush* data = (MAPFuncBrush*)GetEntity(entityIndex);
	if ((!data->myBrush) && (data->modelname == ""))
	{
		UE_LOG(LogTemp, Error, TEXT("No data for func_static. Skipping..."));
		return;
	}
	FVector propPosition = FVector(data->origin.X, data->origin.Y, data->origin.Z);
	FRotator rotatorToUse = FRotator(HammUErSettings::importRotationValue.Y, HammUErSettings::importRotationValue.Z, HammUErSettings::importRotationValue.X);
	UWorld* editorWorld = GEditor->GetEditorWorldContext().World();

	FActorSpawnParameters FAS;
	FString tempName = data->name.c_str();
	FString tag = "Entity_" + FString::FromInt(data->id);

	if (HammUErSettings::alwaysPrependFilename) 
		if (!tempName.StartsWith(FPaths::GetBaseFilename(cacheFilename))) // this should never happen, but you never know
		tempName = FPaths::GetBaseFilename(cacheFilename) + "_" + tempName;

	if (IsIgnoreActor(tempName))
	{
		UE_LOG(LogTemp, Log, TEXT("Skipping %s, contains ignore tag."), *tempName);
		return;
	}
	PreviousActorExists(tempName, true, tag, false);

	FAS.Name = FName(*tag);

	propPosition = FQuat(FVector(0.0f, 0.0f, 1.0f), 3 * PI / 2.f)* propPosition;

	FVector meshPosition = FVector::ZeroVector;

	AStaticMeshActor* tempActor = editorWorld->SpawnActor<AStaticMeshActor>(FAS);

	if (createInstanceData)
	{
		instanceData->instanceAdd(data->id);
		instanceData->instanceAddString(data->name.c_str());
	}

	UStaticMesh* myMesh = NULL;
	if (data->modelname != "")
	{
		if (createInstanceData)
		{
			int funcType = 01;
			instanceData->instanceAdd(funcType);
			instanceData->instanceAddString(data->modelname.c_str());
		}

		myMesh = HammUErSettings::FindInStaticMeshDatabase(data->modelname.c_str());
		if (HammUErSettings::propScaleType == 2)
			tempActor->SetActorScale3D(FVector(local_conversionFactor, local_conversionFactor, local_conversionFactor));
		if (HammUErSettings::ignorePitch)
			data->angles.X = 0;
		if (HammUErSettings::ignoreRoll)
			data->angles.Z = 0;
		if (HammUErSettings::ignoreYaw)
			data->angles.Y = 0;

		if (HammUErSettings::generateOverlaps)
			tempActor->GetStaticMeshComponent()->SetGenerateOverlapEvents(true);

	}
	else
	{
		if (createInstanceData)
		{
			int funcType = 02;
			instanceData->instanceAdd(funcType);
		}
		myMesh = ImportBrush(data->myBrush, newMaterials, meshPosition, true, false);
		float offsetCheck = FMath::Abs((meshPosition - propPosition).Size());
		if (offsetCheck > 200.f) // objective vector offset thing to make sure we don't shift stuff too far away
			propPosition += meshPosition;
		else
			propPosition = meshPosition;
	}
	if (myMesh == NULL)
		myMesh = GenerateTemporaryModel(data->modelname.c_str());
	
	if (createInstanceData)
	{
		instanceData->instanceAdd(data->origin);
		instanceData->instanceAdd(data->angles);
		instanceData->instanceAdd(data->solidity);
		instanceData->instanceAdd(data->shadows);
		instanceData->instanceAdd(data->startsDisabled);
	}

	if (HammUErSettings::toDeleteList.Num() > 0)
	{
		if (HammUErSettings::toDeleteList.Contains(tempName))
			HammUErSettings::toDeleteList.Remove(tempName);
	}
	
	tempActor->SetActorLabel(tempName);
	
	if (HammUErSettings::importNonZero)
		propPosition += HammUErSettings::importOffset;

	if ((HammUErSettings::importRotation) && (HammUErSettings::CenterCheckboxEnabled))
		propPosition = rotatorToUse.RotateVector(propPosition);

	if (HammUErSettings::importRotation)
		tempActor->SetActorRotation(rotatorToUse);

	if (data->modelname != "")
	{
		FMatrix OGMatrix(FVector::ForwardVector, -FVector::RightVector, FVector::UpVector, FVector::ZeroVector);
		FMatrix rotationMatrix = HammUErSettings::CreateRotationMatrix(-data->angles.X, data->angles.Z, data->angles.Y);

		FMatrix finalMatrix = OGMatrix.Inverse()*rotationMatrix*OGMatrix;

		if (HammUErSettings::importRotation)
			tempActor->AddActorWorldRotation(finalMatrix.Rotator()+FRotator(0, 90, 0));
		else
			tempActor->SetActorRotation(finalMatrix.Rotator() +FRotator(0, 90, 0));
	}
	tempActor->SetActorLocation(propPosition);
#if ENGINE_MINOR_VERSION<14
	tempActor->GetStaticMeshComponent()->StaticMesh = myMesh;
#else
	tempActor->GetStaticMeshComponent()->SetStaticMesh(myMesh);
#endif

	if ((HammUErSettings::twoSidedCull) && (data->myBrush->containsNoDraw || data->myBrush->containsDisplacements))
		((UPrimitiveComponent*)tempActor->GetRootComponent())->bCastShadowAsTwoSided = true;

	tempActor->Tags.Empty();
	tempActor->Tags.Add(FName(*tag));
	tempActor->Tags.Add(FName(data->classname.c_str()));

	tempActor->PostEditChange();

}

void MapFileLoader::DoLogicRelay(int32 entityIndex)
{
	VMFLogicRelay* data = (VMFLogicRelay*)GetEntity(entityIndex);

	FRotator rotatorToUse = FRotator(HammUErSettings::importRotationValue.Y, HammUErSettings::importRotationValue.Z, HammUErSettings::importRotationValue.X);
	UWorld* editorWorld = GEditor->GetEditorWorldContext().World();

	FActorSpawnParameters FAS;
	FString tempName = data->name.c_str();
	FString tag = "Entity_" + FString::FromInt(data->id);

	if (HammUErSettings::alwaysPrependFilename)
		if (!tempName.StartsWith(FPaths::GetBaseFilename(cacheFilename))) // this should never happen, but you never know
		tempName = FPaths::GetBaseFilename(cacheFilename) + "_" + tempName;

	if (IsIgnoreActor(tempName))
	{
		UE_LOG(LogTemp, Log, TEXT("Skipping %s, contains ignore tag."), *tempName);
		return;
	}
	PreviousActorExists(tempName, true, tag, false);

	FAS.Name = FName(*tag);

	UBlueprint* BPtoUse = NULL;
	BPtoUse = HammUErSettings::FindInBPDatabase("LogicRelayBP");
	if (BPtoUse)
	{
		TSubclassOf<AHammuerLogicActorBase> BPClass = (UClass*)BPtoUse->GeneratedClass;
		AHammuerLogicActorBase* tempActor = editorWorld->SpawnActor<AHammuerLogicActorBase>(BPClass, FAS);
		FVector propPosition = FQuat(FVector(0.0f, 0.0f, 1.0f), 3 * PI / 2.f)*MAPConverters::MAPtoF(data->origin);

		tempActor->SetActorLabel(tempName);
		tempActor->SetFriendlyName(data->name.c_str());

		if (HammUErSettings::importNonZero)
			propPosition += HammUErSettings::importOffset;

		if ((HammUErSettings::importRotation) && (HammUErSettings::CenterCheckboxEnabled))
			propPosition = rotatorToUse.RotateVector(propPosition);


		if (HammUErSettings::importRotation)
			tempActor->SetActorRotation(rotatorToUse);



		tempActor->SetActorLocation(propPosition);

		for (int i = 0; i < data->myOutputs.size(); i++)
		{
			FHammuerOutput newOutput;
			newOutput.delay = data->myOutputs[i]->timeDelay;
			newOutput.onlyOnce = data->myOutputs[i]->fireOnce;
			newOutput.outputName = data->myOutputs[i]->outputName.c_str();
			newOutput.parameter = data->myOutputs[i]->parameters.c_str();
			newOutput.targetEntity = data->myOutputs[i]->targetEntity.c_str();
			newOutput.targetInput = data->myOutputs[i]->targetInput.c_str();

			tempActor->myOutputs.Add(newOutput);
		}

		tempActor->Tags.Empty();
		tempActor->Tags.Add(FName(*tag));
		tempActor->Tags.Add(FName(data->classname.c_str()));


		tempActor->PostEditChange();
	}
	else
	{
		AHammuerLogicRelay* tempActor = editorWorld->SpawnActor<AHammuerLogicRelay>(FAS);
		FVector propPosition = FQuat(FVector(0.0f, 0.0f, 1.0f), 3 * PI / 2.f)*MAPConverters::MAPtoF(data->origin);

		tempActor->SetActorLabel(tempName);

		if (HammUErSettings::importNonZero)
			propPosition += HammUErSettings::importOffset;

		if ((HammUErSettings::importRotation) && (HammUErSettings::CenterCheckboxEnabled))
			propPosition = rotatorToUse.RotateVector(propPosition);

		if (HammUErSettings::importRotation)
			tempActor->SetActorRotation(rotatorToUse);

		tempActor->SetActorLocation(propPosition);

		for (int i = 0; i < data->myOutputs.size(); i++)
		{
			FHammuerOutput newOutput;
			newOutput.delay = data->myOutputs[i]->timeDelay;
			newOutput.onlyOnce = data->myOutputs[i]->fireOnce;
			newOutput.outputName = data->myOutputs[i]->outputName.c_str();
			newOutput.parameter = data->myOutputs[i]->parameters.c_str();
			newOutput.targetEntity = data->myOutputs[i]->targetEntity.c_str();
			newOutput.targetInput = data->myOutputs[i]->targetInput.c_str();
			tempActor->myOutputs.Add(newOutput);
		}

		tempActor->Tags.Empty();
		tempActor->Tags.Add(FName(*tag));
		tempActor->Tags.Add(FName(data->classname.c_str()));

		tempActor->PostEditChange();
	}
}

void MapFileLoader::DoLogicAuto(int32 entityIndex)
{
	VMFLogicAuto* data = (VMFLogicAuto*)GetEntity(entityIndex);

	FRotator rotatorToUse = FRotator(HammUErSettings::importRotationValue.Y, HammUErSettings::importRotationValue.Z, HammUErSettings::importRotationValue.X);
	UWorld* editorWorld = GEditor->GetEditorWorldContext().World();

	FActorSpawnParameters FAS;
	FString tempName = data->name.c_str();
	FString tag = "Entity_" + FString::FromInt(data->id);

	if (HammUErSettings::alwaysPrependFilename) 
		if (!tempName.StartsWith(FPaths::GetBaseFilename(cacheFilename))) // this should never happen, but you never know
		tempName = FPaths::GetBaseFilename(cacheFilename) + "_" + tempName;

	if (IsIgnoreActor(tempName))
	{
		UE_LOG(LogTemp, Log, TEXT("Skipping %s, contains ignore tag."), *tempName);
		return;
	}
	PreviousActorExists(tempName, true, tag, false);

	FAS.Name = FName(*tag);

	UBlueprint* BPtoUse = NULL;
	BPtoUse = HammUErSettings::FindInBPDatabase("LogicAutoBP");
	if (BPtoUse)
	{
		TSubclassOf<AHammuerLogicActorBase> BPClass = (UClass*)BPtoUse->GeneratedClass;
		AHammuerLogicActorBase* tempActor = editorWorld->SpawnActor<AHammuerLogicActorBase>(BPClass, FAS);
		FVector propPosition = FQuat(FVector(0.0f, 0.0f, 1.0f), 3 * PI / 2.f)*MAPConverters::MAPtoF(data->origin);

		tempActor->SetActorLabel(tempName);
		tempActor->SetFriendlyName(data->name.c_str());

		if (HammUErSettings::importNonZero)
			propPosition += HammUErSettings::importOffset;

		if ((HammUErSettings::importRotation) && (HammUErSettings::CenterCheckboxEnabled))
			propPosition = rotatorToUse.RotateVector(propPosition);

		if (HammUErSettings::importRotation)
			tempActor->SetActorRotation(rotatorToUse);

		tempActor->SetActorLocation(propPosition);

		for (int i = 0; i < data->myOutputs.size(); i++)
		{
			FHammuerOutput newOutput;
			newOutput.delay = data->myOutputs[i]->timeDelay;
			newOutput.onlyOnce = data->myOutputs[i]->fireOnce;
			newOutput.outputName = data->myOutputs[i]->outputName.c_str();
			newOutput.parameter = data->myOutputs[i]->parameters.c_str();
			newOutput.targetEntity = data->myOutputs[i]->targetEntity.c_str();
			newOutput.targetInput = data->myOutputs[i]->targetInput.c_str();

			tempActor->myOutputs.Add(newOutput);
		}

		tempActor->Tags.Empty();
		tempActor->Tags.Add(FName(*tag));
		tempActor->Tags.Add(FName(data->classname.c_str()));

		tempActor->PostEditChange();
	}
	else
	{
		AHammuerLogicAuto* tempActor = editorWorld->SpawnActor<AHammuerLogicAuto>(FAS);
		FVector propPosition = FQuat(FVector(0.0f, 0.0f, 1.0f), 3 * PI / 2.f)*MAPConverters::MAPtoF(data->origin);

		tempActor->SetActorLabel(tempName);

		if (HammUErSettings::importNonZero)
			propPosition += HammUErSettings::importOffset;

		if ((HammUErSettings::importRotation) && (HammUErSettings::CenterCheckboxEnabled))
			propPosition = rotatorToUse.RotateVector(propPosition);

		if (HammUErSettings::importRotation)
			tempActor->SetActorRotation(rotatorToUse);

		tempActor->SetActorLocation(propPosition);

		for (int i = 0; i < data->myOutputs.size(); i++)
		{
			FHammuerOutput newOutput;
			newOutput.delay = data->myOutputs[i]->timeDelay;
			newOutput.onlyOnce = data->myOutputs[i]->fireOnce;
			newOutput.outputName = data->myOutputs[i]->outputName.c_str();
			newOutput.parameter = data->myOutputs[i]->parameters.c_str();
			newOutput.targetEntity = data->myOutputs[i]->targetEntity.c_str();
			newOutput.targetInput = data->myOutputs[i]->targetInput.c_str();
			tempActor->myOutputs.Add(newOutput);
		}

		tempActor->Tags.Empty();
		tempActor->Tags.Add(FName(*tag));
		tempActor->Tags.Add(FName(data->classname.c_str()));

		tempActor->PostEditChange();
	}
}

void MapFileLoader::DoPropStatic(int32 entityIndex, MAPPropStatic* instancedProp)
{
	MAPPropStatic* data;
	if (entityIndex == -1)
		data = instancedProp;
	else
		data = (MAPPropStatic*)GetEntity(entityIndex);

	FRotator rotatorToUse = FRotator(HammUErSettings::importRotationValue.Y, HammUErSettings::importRotationValue.Z, HammUErSettings::importRotationValue.X);
	UWorld* editorWorld = GEditor->GetEditorWorldContext().World();

	if (data->modelname != "error")
	{
		if (createInstanceData)
		{
			instanceData->instanceAdd(data->id);
			instanceData->instanceAddString(data->name.c_str());
			instanceData->instanceAddString(data->modelname.c_str());
			instanceData->instanceAdd(data->origin);
			instanceData->instanceAdd(data->angles);
		}

		if (HammUErSettings::ignorePitch)
			data->angles.X = 0;
		if (HammUErSettings::ignoreRoll)
			data->angles.Z = 0;
		if (HammUErSettings::ignoreYaw)
			data->angles.Y = 0;

		UStaticMesh* toSpawn = HammUErSettings::FindInStaticMeshDatabase(data->modelname.c_str());
		if (HammUErSettings::placeUnknownModels || (toSpawn != NULL))
		{
			if (toSpawn == NULL)
				toSpawn = GenerateTemporaryModel(data->modelname.c_str());
			FActorSpawnParameters FAS;
			FString tempName = data->name.c_str();
			FString tag = "Entity_" + FString::FromInt(data->id);

			if (HammUErSettings::alwaysPrependFilename) 
				if (!tempName.StartsWith(FPaths::GetBaseFilename(cacheFilename))) // this should never happen, but you never know
				tempName = FPaths::GetBaseFilename(cacheFilename) + "_" + tempName;

			if (IsIgnoreActor(tempName))
			{
				UE_LOG(LogTemp, Log, TEXT("Skipping %s, contains ignore tag."), *tempName);
				return;
			}
			PreviousActorExists(tempName, true, tag, false);

			FAS.Name = FName(*tag);
			
			FVector propPosition = FQuat(FVector(0.0f, 0.0f, 1.0f), 3 * PI / 2.f)*MAPConverters::MAPtoF(data->origin);

			AStaticMeshActor* tempActor = editorWorld->SpawnActor<AStaticMeshActor>(FAS);
			tempActor->SetActorLabel(tempName);
		
			if (HammUErSettings::toDeleteList.Num() > 0)
			{
				if (HammUErSettings::toDeleteList.Contains(tempName))
					HammUErSettings::toDeleteList.Remove(tempName);
			}

			if (HammUErSettings::importNonZero)
				propPosition += HammUErSettings::importOffset;

			if ((HammUErSettings::importRotation) && (HammUErSettings::CenterCheckboxEnabled))
				propPosition = rotatorToUse.RotateVector(propPosition);

			if (HammUErSettings::importRotation)
				tempActor->SetActorRotation(rotatorToUse);

			
			tempActor->SetActorLocation(propPosition);

			// Y left to Y right
			//FMatrix OGMatrix(FVector::ForwardVector, -FVector::RightVector, FVector::UpVector, FVector::ZeroVector);
			int rotationType = HammUErSettings::FindInModelDatabase(data->modelname.c_str());
			float changeYaw = 0;
			float changeRoll = 0;
			float changePitch = 0;

			GetRotationValues(rotationType, MAPConverters::MAPtoF(data->angles), changePitch, changeRoll, changeYaw);
			FRotator rotationChange = FRotator(changePitch, changeYaw, changeRoll);

			if (HammUErSettings::importRotation)
			{
				tempActor->SetActorRotation(rotatorToUse);
				tempActor->AddActorLocalRotation(rotationChange); 
			}
			else
				tempActor->AddActorLocalRotation(rotationChange);

			if (HammUErSettings::propScaleType == 2)
				tempActor->SetActorScale3D(FVector(local_conversionFactor, local_conversionFactor, local_conversionFactor));
#if ENGINE_MINOR_VERSION <14
			tempActor->GetStaticMeshComponent()->StaticMesh = toSpawn;
#else
			tempActor->GetStaticMeshComponent()->SetStaticMesh(toSpawn);
#endif
			FVector checkPos = tempActor->GetActorLocation();
			if (checkPos != propPosition)
				tempActor->SetActorLocation(propPosition);

			tempActor->Tags.Empty();
			tempActor->Tags.Add(FName(*tag));
			tempActor->Tags.Add(FName(data->classname.c_str()));

			tempActor->PostEditChange();
		}
	}
}

void MapFileLoader::DoPropDynamic(int32 entityIndex, MAPPropDynamic* instancedProp)
{
	MAPPropDynamic* data;
	if (entityIndex == -1)
		data = instancedProp;
	else
		data = (MAPPropDynamic*)GetEntity(entityIndex);

	FRotator rotatorToUse = FRotator(HammUErSettings::importRotationValue.Y, HammUErSettings::importRotationValue.Z, HammUErSettings::importRotationValue.X);
	UWorld* editorWorld = GEditor->GetEditorWorldContext().World();
	
	if (data->modelname != "error")
	{

		if (createInstanceData)
		{
			instanceData->instanceAdd(data->id);
			instanceData->instanceAddString(data->name.c_str());
			instanceData->instanceAddString(data->modelname.c_str());
			instanceData->instanceAdd(data->origin);
			instanceData->instanceAdd(data->angles);
		}
		if (HammUErSettings::ignorePitch)
			data->angles.X = 0;
		if (HammUErSettings::ignoreRoll)
			data->angles.Z = 0;
		if (HammUErSettings::ignoreYaw)
			data->angles.Y = 0;

		UStaticMesh* toSpawn = HammUErSettings::FindInStaticMeshDatabase(data->modelname.c_str());
		if (HammUErSettings::placeUnknownModels || (toSpawn != NULL))
		{
			if (toSpawn == NULL)
				toSpawn = GenerateTemporaryModel(data->modelname.c_str());
			FActorSpawnParameters FAS;
			FString tempName = data->name.c_str();
			FString tag = "Entity_" + FString::FromInt(data->id);

			if (HammUErSettings::alwaysPrependFilename) 
				if (!tempName.StartsWith(FPaths::GetBaseFilename(cacheFilename))) // this should never happen, but you never know
				tempName = FPaths::GetBaseFilename(cacheFilename) + "_" + tempName;

			if (IsIgnoreActor(tempName))
			{
				UE_LOG(LogTemp, Log, TEXT("Skipping %s, contains ignore tag."), *tempName);
				return;
			}
			PreviousActorExists(tempName, true, tag, false);

			FAS.Name = FName(*tag);

			AStaticMeshActor* tempActor = editorWorld->SpawnActor<AStaticMeshActor>(FAS);
			tempActor->SetActorLabel(tempName);
			FVector propPosition = FQuat(FVector(0.0f, 0.0f, 1.0f), 3 * PI / 2.f)*MAPConverters::MAPtoF(data->origin);

			if (HammUErSettings::toDeleteList.Num() > 0)
			{
				if (HammUErSettings::toDeleteList.Contains(tempName))
					HammUErSettings::toDeleteList.Remove(tempName);
			}

			if (HammUErSettings::importNonZero)
				propPosition += HammUErSettings::importOffset;

			if ((HammUErSettings::importRotation) && (HammUErSettings::CenterCheckboxEnabled))
				propPosition = rotatorToUse.RotateVector(propPosition);

			if (HammUErSettings::importRotation)
				tempActor->SetActorRotation(rotatorToUse);

			tempActor->SetActorLocation(propPosition);

			int rotationType = HammUErSettings::FindInModelDatabase(data->modelname.c_str());
			float changeYaw = 0;
			float changeRoll = 0;
			float changePitch = 0;
			GetRotationValues(rotationType, MAPConverters::MAPtoF(data->angles), changePitch, changeRoll, changeYaw);
			FRotator rotationChange = FRotator(changePitch, changeYaw, changeRoll);

			if (HammUErSettings::importRotation)
			{
				tempActor->SetActorRotation(rotatorToUse);
				if (rotationType > 0)
					tempActor->SetActorRotation(rotationChange);  // look you worked out all the calculations for VtmB beforehand, so just keep using the same system // this is probably broken on importrotation
				else
					tempActor->AddActorLocalRotation(rotationChange);
			}
			else
				if (rotationType > 0)
					tempActor->SetActorRotation(rotationChange);
				else
					tempActor->AddActorLocalRotation(rotationChange);

			if (HammUErSettings::propScaleType == 2)
				tempActor->SetActorScale3D(FVector(local_conversionFactor, local_conversionFactor, local_conversionFactor));
#if ENGINE_MINOR_VERSION <14
			tempActor->GetStaticMeshComponent()->StaticMesh = toSpawn;
#else
			tempActor->GetStaticMeshComponent()->SetStaticMesh(toSpawn);
#endif
			FVector checkPos = tempActor->GetActorLocation();
			if (checkPos != propPosition)
				tempActor->SetActorLocation(propPosition);
			
			tempActor->Tags.Empty();
			tempActor->Tags.Add(FName(*tag));
			tempActor->Tags.Add(FName(data->classname.c_str()));

			tempActor->PostEditChange();
		}
	}
}

void MapFileLoader::DoLight(int32 entityIndex, MAPLight* instancedLight)
{

	MAPLight* data;

	if (entityIndex == -1)
		data = instancedLight;
	else
		data = (MAPLight*)GetEntity(entityIndex);
	
	if (createInstanceData)
	{
		instanceData->instanceAdd(data->id);
		instanceData->instanceAddString(data->name.c_str());
		instanceData->instanceAdd(data->origin);
		instanceData->instanceAdd(data->angles);
		instanceData->instanceAdd(data->pitch);
		instanceData->instanceAdd(data->lightColor);
		instanceData->instanceAdd(data->intensity);
		instanceData->instanceAdd(data->useIntensity);
		instanceData->instanceAdd(data->isMobile);
	}

	FRotator rotatorToUse = FRotator(HammUErSettings::importRotationValue.Y, HammUErSettings::importRotationValue.Z, HammUErSettings::importRotationValue.X);
	UWorld* editorWorld = GEditor->GetEditorWorldContext().World();

	FActorSpawnParameters FAS;
	FString tempName = data->name.c_str();
	FString tag = "Entity_" + FString::FromInt(data->id);

	if (HammUErSettings::alwaysPrependFilename) 
		if (!tempName.StartsWith(FPaths::GetBaseFilename(cacheFilename))) // this should never happen, but you never know
		tempName = FPaths::GetBaseFilename(cacheFilename) + "_" + tempName;

	if (IsIgnoreActor(tempName))
	{
		UE_LOG(LogTemp, Log, TEXT("Skipping %s, contains ignore tag."), *tempName);
		return;
	}
	PreviousActorExists(tempName, true, tag, false);

	FAS.Name = FName(*tag);
	FVector lightLocation = FQuat(FVector(0.0f, 0.0f, 1.0f), 3 * PI / 2.f)*MAPConverters::MAPtoF(data->origin);
	APointLight* newPointLight =
		 Cast<APointLight>(GEditor->AddActor(GEditor->GetEditorWorldContext().World()->GetCurrentLevel(), APointLight::StaticClass(), FTransform(lightLocation)));
	newPointLight->SetActorLabel(tempName);
	newPointLight->SetLightColor(MAPConverters::MAPtoF(data->lightColor));
	newPointLight->SetBrightness(data->intensity * (data->useIntensity ? HammUErSettings::lightFactor : 2));

	if (HammUErSettings::importNonZero)
		lightLocation += HammUErSettings::importOffset;

	if ((HammUErSettings::importRotation) && (HammUErSettings::CenterCheckboxEnabled))
		lightLocation = rotatorToUse.RotateVector(lightLocation);

	if (HammUErSettings::importRotation)
		newPointLight->SetActorRotation(rotatorToUse);

	if (data->isMobile)
		newPointLight->SetMobility(EComponentMobility::Movable);
	else
		newPointLight->SetMobility(EComponentMobility::Static);

	newPointLight->SetActorLocation(lightLocation);


	newPointLight->Tags.Empty();
	newPointLight->Tags.Add(FName(*tag));
	newPointLight->Tags.Add(FName(data->classname.c_str()));
	
	newPointLight->PostEditChange();
	newPointLight->PostEditMove(true);
}

AHammuerPathNode* MapFileLoader::DoPath(int32 entityIndex)
{
	MAPPath* data = (MAPPath*)GetEntity(entityIndex);
	UWorld* editorWorld = GEditor->GetEditorWorldContext().World();
	FActorSpawnParameters FAS;
	FString tempName = data->name.c_str();
	FString tag = "Entity_" + FString::FromInt(data->id);

	if (HammUErSettings::alwaysPrependFilename) 
		if (!tempName.StartsWith(FPaths::GetBaseFilename(cacheFilename))) // this should never happen, but you never know
		tempName = FPaths::GetBaseFilename(cacheFilename) + "_" + tempName;

	if (IsIgnoreActor(tempName))
	{
		UE_LOG(LogTemp, Log, TEXT("Skipping %s, contains ignore tag."), *tempName);
		return NULL;
	}
	PreviousActorExists(tempName, true, tag, false);

	FAS.Name = FName(*tag);

	AHammuerPathNode* tempActor = editorWorld->SpawnActor<AHammuerPathNode>(FAS);
	tempActor->SetActorLabel(tempName);
	tempActor->myTargetName = data->targetName.c_str();

	FVector pathNodeLocation = FQuat(FVector(0.0f, 0.0f, 1.0f), 3 * PI / 2.f)*MAPConverters::MAPtoF(data->origin);
	FRotator rotatorToUse = FRotator(HammUErSettings::importRotationValue.Y, HammUErSettings::importRotationValue.Z, HammUErSettings::importRotationValue.X);

	if (HammUErSettings::importNonZero)
		pathNodeLocation += HammUErSettings::importOffset;

	if ((HammUErSettings::importRotation) && (HammUErSettings::CenterCheckboxEnabled))
		pathNodeLocation = rotatorToUse.RotateVector(pathNodeLocation);

	if (HammUErSettings::importRotation)
		tempActor->SetActorRotation(rotatorToUse);

	tempActor->SetActorLocation(pathNodeLocation);

	tempActor->Tags.Empty();
	tempActor->Tags.Add(FName(*tag));
	tempActor->Tags.Add(FName(data->classname.c_str()));

	tempActor->PostEditChange();
	return tempActor;
}

void MapFileLoader::DoSpotLight(int32 entityIndex, MAPSpotLight* instancedSpotLight)
{

	MAPSpotLight* data;
	if (entityIndex == -1)
		data = instancedSpotLight;
	else
		data = (MAPSpotLight*)GetEntity(entityIndex);

	if (createInstanceData)
	{
		instanceData->instanceAdd(data->id);
		instanceData->instanceAddString(data->name.c_str());
		instanceData->instanceAdd(data->origin);
		instanceData->instanceAdd(data->angles);
		instanceData->instanceAdd(data->pitch);
		instanceData->instanceAdd(data->lightColor);
		instanceData->instanceAdd(data->intensity);
		instanceData->instanceAdd(data->useIntensity);
		instanceData->instanceAdd(data->isMobile);
		instanceData->instanceAdd(data->innerCone);
		instanceData->instanceAdd(data->outerCone);
	}

	FRotator rotatorToUse = FRotator(HammUErSettings::importRotationValue.Y, HammUErSettings::importRotationValue.Z, HammUErSettings::importRotationValue.X);
	UWorld* editorWorld = GEditor->GetEditorWorldContext().World();

	FActorSpawnParameters FAS;
	FString tempName = data->name.c_str();
	FString tag = "Entity_" + FString::FromInt(data->id);

	if (HammUErSettings::alwaysPrependFilename)
		if (!tempName.StartsWith(FPaths::GetBaseFilename(cacheFilename))) // this should never happen, but you never know
			tempName = FPaths::GetBaseFilename(cacheFilename) + "_" + tempName;

	if (IsIgnoreActor(tempName))
	{
		UE_LOG(LogTemp, Log, TEXT("Skipping %s, contains ignore tag."), *tempName);
		return;
	}
	PreviousActorExists(tempName, true, tag, false);

	FAS.Name = FName(*tag);
	FVector lightLocation = FQuat(FVector(0.0f, 0.0f, 1.0f), 3 * PI / 2.f)*MAPConverters::MAPtoF(data->origin);
	ASpotLight* newSpotLight =
		Cast<ASpotLight>(GEditor->AddActor(GEditor->GetEditorWorldContext().World()->GetCurrentLevel(), ASpotLight::StaticClass(), FTransform(lightLocation)));
	//editorWorld->SpawnActor<ASpotLight>(FAS);
	newSpotLight->SetActorLabel(tempName);
	newSpotLight->SetLightColor(MAPConverters::MAPtoF(data->lightColor));
	newSpotLight->SetBrightness(data->intensity * (data->useIntensity ? HammUErSettings::lightFactor : 2));

	USpotLightComponent* ULC = (USpotLightComponent*)newSpotLight->GetComponentByClass(USpotLightComponent::StaticClass());
	if (ULC)
	{
		ULC->InnerConeAngle = data->innerCone;
		ULC->OuterConeAngle = data->outerCone;
	}

	if (HammUErSettings::importNonZero)
		lightLocation += HammUErSettings::importOffset;

	if ((HammUErSettings::importRotation) && (HammUErSettings::CenterCheckboxEnabled))
		lightLocation = rotatorToUse.RotateVector(lightLocation);

	if (HammUErSettings::importRotation)
		newSpotLight->SetActorRotation(rotatorToUse);

	if (data->isMobile)
		newSpotLight->SetMobility(EComponentMobility::Movable);
	else
		newSpotLight->SetMobility(EComponentMobility::Static);

	newSpotLight->SetActorLocation(lightLocation);

	FMatrix OGMatrix(FVector::ForwardVector, -FVector::RightVector, FVector::UpVector, FVector::ZeroVector);
	FMatrix rotationMatrix = HammUErSettings::CreateRotationMatrix(-data->pitch, data->angles.Z, data->angles.Y);

	FMatrix finalMatrix = OGMatrix.Inverse()*rotationMatrix*OGMatrix;

	if (HammUErSettings::importRotation)
		newSpotLight->AddActorWorldRotation(finalMatrix.Rotator() + FRotator(0, 90, 0));
	else
		newSpotLight->SetActorRotation(finalMatrix.Rotator() + FRotator(0, 90, 0));

	
	newSpotLight->Tags.Empty();
	newSpotLight->Tags.Add(FName(*tag));
	newSpotLight->Tags.Add(FName(data->classname.c_str()));

//	lightWorkaroundTest.Add((ALight*)newSpotLight);
	newSpotLight->PostEditChange();
	newSpotLight->PostEditMove(true);
}

void MapFileLoader::DoEnvironmentLight(int32 entityIndex, MAPEnvironmentLight* instancedEnvironmentLight)
{

	MAPEnvironmentLight* data;
	if (entityIndex == -1)
		data = instancedEnvironmentLight;
	else
		data = (MAPEnvironmentLight*)GetEntity(entityIndex);

	if (createInstanceData)
	{
		instanceData->instanceAdd(data->id);
		instanceData->instanceAddString(data->name.c_str());
		instanceData->instanceAdd(data->origin);
		instanceData->instanceAdd(data->angles);
		instanceData->instanceAdd(data->pitch);
		instanceData->instanceAdd(data->lightColor);
		instanceData->instanceAdd(data->intensity);
		instanceData->instanceAdd(data->useIntensity);
		instanceData->instanceAdd(data->isMobile);
		instanceData->instanceAdd(data->Ambient);
		instanceData->instanceAdd(data->ambientIntensity);
	}

	FRotator rotatorToUse = FRotator(HammUErSettings::importRotationValue.Y, HammUErSettings::importRotationValue.Z, HammUErSettings::importRotationValue.X);
	UWorld* editorWorld = GEditor->GetEditorWorldContext().World();
	
	FActorSpawnParameters FAS;
	FString tempName = data->name.c_str();
	FString tag = "Entity_" + FString::FromInt(data->id);

	if (HammUErSettings::alwaysPrependFilename) 
		if (!tempName.StartsWith(FPaths::GetBaseFilename(cacheFilename))) // this should never happen, but you never know
		tempName = FPaths::GetBaseFilename(cacheFilename) + "_" + tempName;

	if (IsIgnoreActor(tempName))
	{
		UE_LOG(LogTemp, Log, TEXT("Skipping %s, contains ignore tag."), *tempName);
		return;
	}
	PreviousActorExists(tempName, true, tag, false);

	FAS.Name = FName(*tag);

	FVector lightLocation = FQuat(FVector(0.0f, 0.0f, 1.0f), 3 * PI / 2.f)*MAPConverters::MAPtoF(data->origin);

	ADirectionalLight* newEnviroLight = 
		Cast<ADirectionalLight>(GEditor->AddActor(GEditor->GetEditorWorldContext().World()->GetCurrentLevel(), ADirectionalLight::StaticClass(), FTransform(lightLocation)));

		//editorWorld->SpawnActor<ADirectionalLight>(FAS);
	newEnviroLight->SetActorLabel(data->name.c_str());
	float r = data->Ambient.R;
	float r2 = data->lightColor.R;
	r = (r / 255.f)*r2;
	float g = data->Ambient.G;
	float g2 = data->lightColor.G;
	g = (g / 255.f)*g2;
	float b = data->Ambient.B;
	float b2 = data->lightColor.B;
	b = (b / 255.f)*b2;
	FColor newColor = FColor((uint8)r, (uint8)g, (uint8)b);
	newEnviroLight->SetLightColor(newColor);
	newEnviroLight->SetBrightness(data->ambientIntensity);

	if (data->isMobile)
		newEnviroLight->SetMobility(EComponentMobility::Movable);
	else
		newEnviroLight->SetMobility(EComponentMobility::Static);

	if (HammUErSettings::importNonZero)
		lightLocation += HammUErSettings::importOffset;

	if ((HammUErSettings::importRotation) && (HammUErSettings::CenterCheckboxEnabled))
		lightLocation = rotatorToUse.RotateVector(lightLocation);

	if (HammUErSettings::importRotation)
		newEnviroLight->SetActorRotation(rotatorToUse);

	newEnviroLight->SetActorLocation(lightLocation);

	// Y left to Y right
	FMatrix OGMatrix(FVector::ForwardVector, -FVector::RightVector, FVector::UpVector, FVector::ZeroVector);
	FMatrix rotationMatrix = HammUErSettings::CreateRotationMatrix(-data->pitch, data->angles.Z, data->angles.Y);

	FMatrix finalMatrix = OGMatrix.Inverse()*rotationMatrix*OGMatrix;

	if (HammUErSettings::importRotation)
		newEnviroLight->AddActorWorldRotation(finalMatrix.Rotator() + FRotator(0, 90, 0));
	else
		newEnviroLight->SetActorRotation(finalMatrix.Rotator() + FRotator(0, 90, 0));
	
	newEnviroLight->Tags.Empty();
	newEnviroLight->Tags.Add(FName(*tag));
	newEnviroLight->Tags.Add(FName(data->classname.c_str()));

	//lightWorkaroundTest.Add((ALight*)newEnviroLight);
	newEnviroLight->PostEditChange();
	newEnviroLight->PostEditMove(true);

}

void MapFileLoader::DoFuncInstance(int32 entityIndex, VMFFuncInstance* inputData) // this is a horrifying clusterfuck
{
	VMFFuncInstance* data;
	if (entityIndex == -1)
		data = inputData;
	else
		data = (VMFFuncInstance*)GetEntity(entityIndex);

	if (createInstanceData)
	{
		instanceData->instanceAdd(data->id);
		instanceData->instanceAddString(data->name.c_str());
		instanceData->instanceAddString(data->instance_name.c_str());
		instanceData->instanceAdd(data->origin);
		instanceData->instanceAdd(data->angles);
	}

	if (HammUErSettings::InstanceInDatabase(data->instance_name.c_str()))
	{
		std::vector<uint8_t> fileData;
		FILE* fp;
		FString instanceName = HammUErSettings::GetInstance(data->instance_name.c_str());
		fopen_s(&fp, TCHAR_TO_ANSI(*instanceName), "rb");
		if (!fp)
			return; // could not find the file?
		fseek(fp, 0, SEEK_END);
		long int fileSize = ftell(fp);
		fclose(fp);
		if (fileSize < 12)
		{
			FString problemFile = data->instance_name.c_str();
			UE_LOG(LogTemp, Warning, TEXT("Instance data for %s corrupted?"), *problemFile);
			return;
		}
		fopen_s(&fp, TCHAR_TO_ANSI(*instanceName), "rb");
		fileData.reserve(fileSize);
		fread((uint8_t*)&fileData[0], sizeof(uint8_t), fileSize, fp);
		fclose(fp);

		UWorld* editorWorld = GEditor->GetEditorWorldContext().World();
		FRotator rotatorToUse = FRotator(HammUErSettings::importRotationValue.Y, HammUErSettings::importRotationValue.Z, HammUErSettings::importRotationValue.X);

		FVector propPosition = FQuat(FVector(0.0f, 0.0f, 1.0f), 3 * PI / 2.f)*(MAPConverters::MAPtoF(data->origin));
		FMatrix OGMatrix(FVector::ForwardVector, -FVector::RightVector, FVector::UpVector, FVector::ZeroVector);
		FMatrix rotationMatrix;

		uint8_t* dataPtr = fileData.data();
		int header = *(int*)dataPtr;
		if (header != 0x11554400)
			return;
		dataPtr += 4;
		int numBrushes = *(int*)dataPtr;
		dataPtr += 4;
		int numEntities = *(int*)dataPtr;
		dataPtr += 4;
		for (int i = 0; i < numBrushes; i++)
		{
			int brushId = *(int*)dataPtr;
			dataPtr+=4;
			int length = *(int*)dataPtr;
			dataPtr += 4;
			FString meshName = "";
			for (int str = 0; str < length; str++)
			{
				char* newChar = (char*)dataPtr;
				meshName += *newChar;
				dataPtr += 1;
			}
			FVector meshLocation = *(FVector*)dataPtr;
			dataPtr += sizeof(FVector);

			UStaticMesh* instancedMesh = (UStaticMesh*)StaticLoadObject(UStaticMesh::StaticClass(), NULL, *meshName);
			if (instancedMesh != NULL)
			{
				FActorSpawnParameters FAS;
				FVector propBase = FQuat(FVector(0.0f, 0.0f, 1.0f), 3 * PI / 2.f)*(MAPConverters::MAPtoF(data->origin));
				propPosition = (meshLocation);

				FString tempName = data->name.c_str();
				tempName = tempName + "_" + FString::FromInt(brushId);
				FString tag = "Entity_" + FString::FromInt(data->id);
				if (IsIgnoreActor(data->name.c_str()))
				{
					UE_LOG(LogTemp, Log, TEXT("Skipping contains ignore tag."));
					return;
				}

				bool foundOne = PreviousActorExists(data->name.c_str(), true, tag);

				if (HammUErSettings::alwaysPrependFilename)
					if (!tempName.StartsWith(FPaths::GetBaseFilename(cacheFilename))) // this should never happen, but you never know
						tempName = FPaths::GetBaseFilename(cacheFilename) + "_" + tempName;

				if (HammUErSettings::importNonZero)
					propBase += HammUErSettings::importOffset;

				AStaticMeshActor* tempActor = editorWorld->SpawnActor<AStaticMeshActor>(FAS);
#if ENGINE_MINOR_VERSION <14
				tempActor->GetStaticMeshComponent()->StaticMesh = instancedMesh;
#else
				tempActor->GetStaticMeshComponent()->SetStaticMesh(instancedMesh);
#endif

				if (HammUErSettings::generateOverlaps)
					tempActor->GetStaticMeshComponent()->SetGenerateOverlapEvents(true);

				tempActor->SetActorLabel(tempName);
				if (HammUErSettings::importRotation && HammUErSettings::CenterCheckboxEnabled)
					propBase = rotatorToUse.RotateVector(propBase);

				if (HammUErSettings::importRotation)
					tempActor->SetActorRotation(rotatorToUse);

				rotationMatrix = HammUErSettings::CreateRotationMatrix(-data->angles.X, data->angles.Z, data->angles.Y);

				FMatrix finalMatrix = OGMatrix.Inverse()*rotationMatrix*OGMatrix;

				propPosition = finalMatrix.Rotator().RotateVector(propPosition);

				tempActor->SetActorLocation(propBase + propPosition);

				tempActor->AddActorWorldRotation(finalMatrix.Rotator());
				tempActor->Tags.Empty();
				tempActor->Tags.Add(FName(*tag));
				tempActor->Tags.Add(FName(data->classname.c_str()));

				tempActor->PostEditChange();
			}
		}
		
		for (int i = 0; i < numEntities; i++)
		{
			int entityType = *(int*)dataPtr;
			dataPtr += 4;
	
			switch ((MapEntityType)entityType)
			{
				case MapEntityType::Overlay:
				{
					int brushId = *(int*)dataPtr;
					dataPtr += 4;
					int length = *(int*)dataPtr;
					dataPtr += 4;
					std::string origName = data->name + "_";
					for (int str = 0; str < length; str++)
					{
						origName += *(char*)dataPtr;
						dataPtr += 1;
					}
					length = *(int*)dataPtr;
					dataPtr += 4;
					std::string matName = "";
					for (int str = 0; str < length; str++)
					{
						matName += *(char*)dataPtr;
						dataPtr += 1;
					}
					FVector location = *(FVector*)dataPtr;
					dataPtr += sizeof(FVector);
					MAPVector angles = *(MAPVector*)dataPtr;
					dataPtr += sizeof(MAPVector);
					float minU = *(float*)dataPtr;
					dataPtr += sizeof(float);
					float minV = *(float*)dataPtr;
					dataPtr += sizeof(float);
					float maxU = *(float*)dataPtr;
					dataPtr += sizeof(float);
					float maxV = *(float*)dataPtr;
					dataPtr += sizeof(float);
					MAPVector basisNormal = *(MAPVector*)dataPtr;
					dataPtr += sizeof(MAPVector);
					float startU = *(float*)dataPtr;
					dataPtr += sizeof(float);
					float startV = *(float*)dataPtr;
					dataPtr += sizeof(float);
					float endU = *(float*)dataPtr;
					dataPtr += sizeof(float);
					float endV = *(float*)dataPtr;
					dataPtr += sizeof(float);

					MAPOverlay* newOverlay = new MAPOverlay();
					newOverlay->id = brushId;
					newOverlay->name = origName;
					newOverlay->materialName = matName;
					MAPVector rotated = MAPConverters::FtoMAP(FRotator(-data->angles.X, -data->angles.Y, data->angles.Z).RotateVector(location));
					newOverlay->origin = data->origin + rotated;
					newOverlay->angles = data->angles + angles;
					newOverlay->minU = minU;
					newOverlay->maxU = maxU;
					newOverlay->minV = minV;
					newOverlay->maxV = maxV;
					newOverlay->startU = startU;
					newOverlay->startV = startV;
					newOverlay->endU = endU;
					newOverlay->endV = endV;
					newOverlay->basisNormal = basisNormal;
					DoOverlay(-1, newOverlay);
					delete newOverlay;
				}
				break;
				case MapEntityType::Instance:
				{
					int brushId = *(int*)dataPtr;
					dataPtr += 4;
					int length = *(int*)dataPtr;
					dataPtr += 4;
					std::string funcName = data->name + "_";
					for (int str = 0; str < length; str++)
					{
						funcName += *(char*)dataPtr;
						dataPtr += 1;
					}
					std::string instanceNameToo = "";
					length = *(int*)dataPtr;
					dataPtr += 4;
					for (int str = 0; str < length; str++)
					{
						instanceNameToo += *(char*)dataPtr;
						dataPtr += 1;
					}
					FVector origin = *(FVector*)dataPtr;
					dataPtr += sizeof(FVector);
					MAPVector angles = *(MAPVector*)dataPtr;
					dataPtr += sizeof(MAPVector);
					
					MAPVector rotated = MAPConverters::FtoMAP(FRotator(-data->angles.X, -data->angles.Y, data->angles.Z).RotateVector(origin));

					VMFFuncInstance* newFunc = new VMFFuncInstance();
					newFunc->id = brushId;
					newFunc->name = funcName;
					newFunc->instance_name = instanceNameToo;
					newFunc->origin = data->origin + rotated;
					newFunc->angles = data->angles + angles;
					DoFuncInstance(-1, newFunc);
					delete newFunc;
				}
				break;
				case MapEntityType::FuncBrush:
				case MapEntityType::FuncStatic:
				{
					int brushId = *(int*)dataPtr;
					dataPtr += 4;
					int length = *(int*)dataPtr;
					dataPtr += 4;
					std::string propName = data->name + "_";
					for (int str = 0; str < length; str++)
					{
						propName += *(char*)dataPtr;
						dataPtr += 1;
					}
					int funcType = *(int*)dataPtr;
					dataPtr += 4;
					switch (funcType)
					{
					case 1:
						{
							length = *(int*)dataPtr;
							dataPtr += 4;
							std::string modelName = "";
							for (int str = 0; str < length; str++)
							{
								modelName += *(char*)dataPtr;
								dataPtr += 1;
							}
							FVector origin = *(FVector*)dataPtr;
							dataPtr += sizeof(FVector);
							MAPVector angles = *(MAPVector*)dataPtr;
							dataPtr += sizeof(MAPVector);
							int solidity = *(int*)dataPtr;
							dataPtr += sizeof(int);
							bool shadows = *(bool*)dataPtr;
							dataPtr += sizeof(bool);
							bool startsDisabled = *(bool*)dataPtr;
							dataPtr += sizeof(bool);

							MAPPropStatic* newProp = new MAPPropStatic();
							newProp->id = brushId;
							newProp->name = propName;
							newProp->modelname = modelName;

							MAPVector rotated = MAPConverters::FtoMAP(FRotator(-data->angles.X, -data->angles.Y, data->angles.Z).RotateVector(origin));

							newProp->origin = data->origin + rotated;//data->origin;
							newProp->angles = angles + data->angles;
							DoPropStatic(-1, newProp);
							delete newProp;
						}	
						break;
					case 2:
						{
							int tempidnotused = *(int*)dataPtr;
							dataPtr += 4;
							length = *(int*)dataPtr;
							dataPtr += 4;
							std::string brushName = "";
							for (int str = 0; str < length; str++)
							{
								brushName += *(char*)dataPtr;
								dataPtr += 1;
							}
							FVector meshLocation = *(FVector*)dataPtr;
							dataPtr += sizeof(FVector);
							FVector origin = *(FVector*)dataPtr; // not used?
							dataPtr += sizeof(FVector);
							/*if (origin != meshLocation)
								meshLocation = origin;*/
							MAPVector angles = *(MAPVector*)dataPtr;
							dataPtr += sizeof(MAPVector);
							int solidity = *(int*)dataPtr;
							dataPtr += sizeof(int);
							bool shadows = *(bool*)dataPtr;
							dataPtr += sizeof(bool);
							bool startsDisabled = *(bool*)dataPtr;
							dataPtr += sizeof(bool);

							FString meshName = brushName.c_str();
							UStaticMesh* instancedMesh = (UStaticMesh*)StaticLoadObject(UStaticMesh::StaticClass(), NULL, *meshName);
							if (instancedMesh != NULL)
							{
								FActorSpawnParameters FAS;

								FVector rotated = FRotator(-data->angles.X, -data->angles.Y, data->angles.Z).RotateVector(meshLocation);
								FVector propBase = FQuat(FVector(0.0f, 0.0f, 1.0f), 3 * PI / 2.f)*(MAPConverters::MAPtoF(data->origin));
								propPosition = meshLocation;

								FString tempName = data->name.c_str();
								tempName = tempName + "_" + FString::FromInt(brushId);
								FString tag = "Entity_" + FString::FromInt(data->id);
								if (IsIgnoreActor(data->name.c_str()))
								{
									UE_LOG(LogTemp, Log, TEXT("Skipping contains ignore tag."));
									return;
								}

								bool foundOne = PreviousActorExists(data->name.c_str(), true, tag);

								if (HammUErSettings::alwaysPrependFilename)
									if (!tempName.StartsWith(FPaths::GetBaseFilename(cacheFilename))) // this should never happen, but you never know
										tempName = FPaths::GetBaseFilename(cacheFilename) + "_" + tempName;

								if (HammUErSettings::importNonZero)
									propBase += HammUErSettings::importOffset;

								if (HammUErSettings::importRotation && HammUErSettings::CenterCheckboxEnabled)
									propBase = rotatorToUse.RotateVector(propBase);

								AStaticMeshActor* tempActor = editorWorld->SpawnActor<AStaticMeshActor>(FAS);
#if ENGINE_MINOR_VERSION<14
								tempActor->GetStaticMeshComponent()->StaticMesh = instancedMesh;
#else
								tempActor->GetStaticMeshComponent()->SetStaticMesh(instancedMesh);
#endif

								if (HammUErSettings::generateOverlaps)
									tempActor->GetStaticMeshComponent()->SetGenerateOverlapEvents(true);

								tempActor->SetActorLabel(tempName);
								
								if (HammUErSettings::importRotation)
									tempActor->SetActorRotation(rotatorToUse);

								//rotationMatrix = HammUErSettings::CreateRotationMatrix(-angles.X-data->angles.X, angles.Z+data->angles.Z, angles.Y+data->angles.Y);
								rotationMatrix = HammUErSettings::CreateRotationMatrix(data->angles.X, data->angles.Z, data->angles.Y);

								FMatrix finalMatrix = OGMatrix.Inverse()*rotationMatrix*OGMatrix;

								propPosition = finalMatrix.Rotator().RotateVector(propPosition);

								tempActor->SetActorLocation(propBase+propPosition);

								tempActor->AddActorWorldRotation(finalMatrix.Rotator());
								tempActor->Tags.Empty();
								tempActor->Tags.Add(FName(*tag));
								tempActor->Tags.Add(FName(data->classname.c_str()));

								tempActor->PostEditChange();
							}
					}
						break;
					}
				}
				break;
				case MapEntityType::PropStatic:
				{
					int brushId = *(int*)dataPtr;
					dataPtr += 4;
					int length = *(int*)dataPtr;
					dataPtr += 4;
					std::string propName = data->name + "_";
					for (int str = 0; str < length; str++)
					{
						propName += *(char*)dataPtr;
						dataPtr += 1;
					}
					length = *(int*)dataPtr;
					dataPtr += 4;
					std::string modelName = data->name + "_";
					for (int str = 0; str < length; str++)
					{
						modelName += *(char*)dataPtr;
						dataPtr += 1;
					}
					MAPVector propLocation = *(MAPVector*)dataPtr;
					dataPtr += sizeof(MAPVector);
					MAPVector propAngles = *(MAPVector*)dataPtr;
					dataPtr += sizeof(MAPVector);
					MAPPropStatic* newProp = new MAPPropStatic();
					newProp->id = brushId;
					newProp->name = propName;
					newProp->modelname = modelName;

					MAPVector rotated = MAPConverters::FtoMAP(FRotator(-data->angles.X, -data->angles.Y, data->angles.Z).RotateVector(MAPConverters::MAPtoF(propLocation)));

					newProp->origin = data->origin + rotated;//data->origin;
					newProp->angles = propAngles + data->angles;
					DoPropStatic(-1, newProp);
					delete newProp;
				}
				break;
				case MapEntityType::PropDynamic:
				{
					int brushId = *(int*)dataPtr;
					dataPtr += 4;
					int length = *(int*)dataPtr;
					dataPtr += 4;
					std::string propName = data->name + "_";
					for (int str = 0; str < length; str++)
					{
						propName += *(char*)dataPtr;
						dataPtr += 1;
					}
					length = *(int*)dataPtr;
					dataPtr += 4;
					std::string modelName = data->name + "_";
					for (int str = 0; str < length; str++)
					{
						modelName += *(char*)dataPtr;
						dataPtr += 1;
					}
					MAPVector propLocation = *(MAPVector*)dataPtr;
					dataPtr += sizeof(MAPVector);
					MAPVector propAngles = *(MAPVector*)dataPtr;
					dataPtr += sizeof(MAPVector);
					MAPPropDynamic* newProp = new MAPPropDynamic();
					newProp->id = brushId;
					newProp->name = propName;
					newProp->modelname = modelName;

					MAPVector rotated = MAPConverters::FtoMAP(FRotator(-data->angles.X, -data->angles.Y, data->angles.Z).RotateVector(MAPConverters::MAPtoF(propLocation)));

					newProp->origin = rotated +data->origin;
					newProp->angles = propAngles + data->angles;
					DoPropDynamic(-1, newProp);
					delete newProp;
				}
				break;
				case MapEntityType::FuncBox:
				{
					int brushId = *(int*)dataPtr;
					dataPtr += 4;
					int length = *(int*)dataPtr;
					dataPtr += 4;
					std::string propName = data->name + "_";
					for (int str = 0; str < length; str++)
					{
						propName += *(char*)dataPtr;
						dataPtr += 1;
					}
					int oldId = *(int*)dataPtr;
					dataPtr += 4;
					length = *(int*)dataPtr;
					dataPtr += 4;
					std::string brushName = data->name + "_";
					for (int str = 0; str < length; str++)
					{
						brushName += *(char*)dataPtr;
						dataPtr += 1;
					}
					FVector origin = *(FVector*)dataPtr;
					dataPtr += sizeof(FVector);
					MAPVector angles = *(MAPVector*)dataPtr;
					dataPtr += sizeof(MAPVector);
					int solidity = *(int*)dataPtr;
					dataPtr += sizeof(int);
					bool shadows = *(bool*)dataPtr;
					dataPtr += sizeof(bool);
					bool startsDisabled = *(bool*)dataPtr;
					dataPtr += sizeof(bool);
					UE_LOG(LogTemp, Warning, TEXT("Instanced func_box not implemented."))
				}
				break;
				case MapEntityType::EnvironmentLight:
				{
					int brushId = *(int*)dataPtr;
					dataPtr += 4;
					int length = *(int*)dataPtr;
					dataPtr += 4;
					std::string lightName = data->name + "_";
					for (int str = 0; str < length; str++)
					{
						lightName += *(char*)dataPtr;
						dataPtr += 1;
					}
					MAPVector lightLocation = *(MAPVector*)dataPtr;
					dataPtr += sizeof(MAPVector);
					MAPVector lightAngles = *(MAPVector*)dataPtr;
					dataPtr += sizeof(MAPVector);
					float pitch = *(float*)dataPtr;
					dataPtr += sizeof(float);
					MAPColor lightColor = *(MAPColor*)dataPtr;
					dataPtr += sizeof(MAPColor);
					int intensity = *(int*)dataPtr;
					dataPtr += sizeof(int);
					bool useIntensity = *(bool*)dataPtr;
					dataPtr += sizeof(bool);
					bool isMobile = *(bool*)dataPtr;
					dataPtr += sizeof(bool);
					MAPColor Ambient = *(MAPColor*)dataPtr;
					dataPtr += sizeof(MAPColor);
					int ambientIntensity = *(int*)dataPtr;
					dataPtr += sizeof(int);

					MAPEnvironmentLight* instancedLight = new MAPEnvironmentLight();
					instancedLight->id = brushId;
					instancedLight->name = lightName;

					MAPVector rotated = MAPConverters::FtoMAP(FRotator(-data->angles.X, -data->angles.Y, data->angles.Z).RotateVector(MAPConverters::MAPtoF(lightLocation)));

					instancedLight->origin = rotated+ data->origin;
					instancedLight->angles = lightAngles + data->angles;
					instancedLight->pitch = pitch + data->angles.X;
					instancedLight->lightColor = lightColor;
					instancedLight->intensity = intensity;
					instancedLight->useIntensity = useIntensity;
					instancedLight->isMobile = isMobile;
					instancedLight->Ambient = Ambient;
					instancedLight->ambientIntensity = ambientIntensity;
					DoLight(-1, instancedLight);
					delete instancedLight;
				}
				break;
				case MapEntityType::Spotlight:
				{
					int brushId = *(int*)dataPtr;
					dataPtr += 4;
					int length = *(int*)dataPtr;
					dataPtr += 4;
					std::string lightName = data->name+"_";
					for (int str = 0; str < length; str++)
					{
						lightName += * (char*)dataPtr;
						dataPtr += 1;
					}
					MAPVector lightLocation = *(MAPVector*)dataPtr;
					dataPtr += sizeof(MAPVector);
					MAPVector lightAngles = *(MAPVector*)dataPtr;
					dataPtr += sizeof(MAPVector);
					float pitch = *(float*)dataPtr;
					dataPtr += sizeof(float);
					MAPColor lightColor = *(MAPColor*)dataPtr;
					dataPtr += sizeof(MAPColor);
					int intensity = *(int*)dataPtr;
					dataPtr += sizeof(int);
					bool useIntensity = *(bool*)dataPtr;
					dataPtr += sizeof(bool);
					bool isMobile = *(bool*)dataPtr;
					dataPtr += sizeof(bool);
					float innerCone = *(float*)dataPtr;
					dataPtr += sizeof(float);
					float outerCone = *(float*)dataPtr;
					dataPtr += sizeof(float);

					MAPSpotLight* instancedSpotLight = new MAPSpotLight();
					instancedSpotLight->id = brushId;
					instancedSpotLight->name = lightName;

					MAPVector rotated = MAPConverters::FtoMAP(FRotator(-data->angles.X, -data->angles.Y, data->angles.Z).RotateVector(MAPConverters::MAPtoF(lightLocation)));

					instancedSpotLight->origin = rotated +data->origin;
					instancedSpotLight->angles = lightAngles + data->angles;
					instancedSpotLight->pitch = pitch+data->angles.X;
					instancedSpotLight->lightColor = lightColor;
					instancedSpotLight->intensity = intensity;
					instancedSpotLight->useIntensity = useIntensity;
					instancedSpotLight->isMobile = isMobile;
					instancedSpotLight->innerCone = innerCone;
					instancedSpotLight->outerCone = outerCone;
					DoSpotLight(-1, instancedSpotLight);
					delete instancedSpotLight;
				}
				break;
				case MapEntityType::Light:
				{
					int brushId = *(int*)dataPtr;
					dataPtr += 4;
					int length = *(int*)dataPtr;
					dataPtr += 4;
					std::string lightName = data->name + "_";
					for (int str = 0; str < length; str++)
					{
						lightName += *(char*)dataPtr;
						dataPtr += 1;
					}
					MAPVector lightLocation = *(MAPVector*)dataPtr;
					dataPtr += sizeof(MAPVector);
					MAPVector lightAngles = *(MAPVector*)dataPtr;
					dataPtr += sizeof(MAPVector);
					float pitch = *(float*)dataPtr;
					dataPtr += sizeof(float);
					MAPColor lightColor = *(MAPColor*)dataPtr;
					dataPtr += sizeof(MAPColor);
					int intensity = *(int*)dataPtr;
					dataPtr += sizeof(int);
					bool useIntensity = *(bool*)dataPtr;
					dataPtr += sizeof(bool);
					bool isMobile = *(bool*)dataPtr;
					dataPtr += sizeof(bool);

					MAPLight* instancedLight = new MAPLight();
					instancedLight->id = brushId;
					instancedLight->name = lightName;

					MAPVector rotated = MAPConverters::FtoMAP(FRotator(-data->angles.X, -data->angles.Y, data->angles.Z).RotateVector(MAPConverters::MAPtoF(lightLocation)));

					instancedLight->origin = rotated +data->origin;
					instancedLight->angles = lightAngles + data->angles;
					instancedLight->pitch = pitch + data->angles.X;
					instancedLight->lightColor = lightColor;
					instancedLight->intensity = intensity;
					instancedLight->useIntensity = useIntensity;
					instancedLight->isMobile = isMobile;
					DoLight(-1, instancedLight);
					delete instancedLight;
				}
				break;
			}
		}

		fileData.empty();
	}
	else
	{
		FString workaround = data->instance_name.c_str();
		UE_LOG(LogTemp, Error, TEXT("! Could not find instance information for %s"), *workaround);
	}
}

void MapFileLoader::DoOverlay(int32 entityIndex, MAPOverlay* inputData)
{
	MAPOverlay* data;
	if (entityIndex == -1)
		data = inputData;
	else
		data = (MAPOverlay*)GetEntity(entityIndex);

	if (createInstanceData)
	{
		instanceData->instanceAdd(data->id);
		instanceData->instanceAddString(data->name.c_str());
		instanceData->instanceAddString(data->materialName.c_str());
		instanceData->instanceAdd(data->origin);
		instanceData->instanceAdd(data->angles);
		instanceData->instanceAdd(data->minU);
		instanceData->instanceAdd(data->minV);
		instanceData->instanceAdd(data->maxU);
		instanceData->instanceAdd(data->maxV);
		instanceData->instanceAdd(data->basisNormal);
		instanceData->instanceAdd(data->startU);
		instanceData->instanceAdd(data->startV);
		instanceData->instanceAdd(data->endU);
		instanceData->instanceAdd(data->endV);
	}

	if (HammUErSettings::ignorePitch)
		data->angles.X = 0;
	if (HammUErSettings::ignoreRoll)
		data->angles.Z = 0;
	if (HammUErSettings::ignoreYaw)
		data->angles.Y = 0;

	FRotator rotatorToUse = FRotator(HammUErSettings::importRotationValue.Y, HammUErSettings::importRotationValue.Z, HammUErSettings::importRotationValue.X);
	UWorld* editorWorld = GEditor->GetEditorWorldContext().World();

	FActorSpawnParameters FAS;
	FString tempName = data->name.c_str();
	FString tag = "Entity_" + FString::FromInt(data->id);

	if (HammUErSettings::alwaysPrependFilename)
		if (!tempName.StartsWith(FPaths::GetBaseFilename(cacheFilename))) // this should never happen, but you never know
		tempName = FPaths::GetBaseFilename(cacheFilename) + "_" + tempName;

	if (IsIgnoreActor(tempName))
	{
		UE_LOG(LogTemp, Log, TEXT("Skipping %s, contains ignore tag."), *tempName);
		return;
	}
	PreviousActorExists(tempName, true, tag, false);

	FAS.Name = FName(*tag);

	FVector decalLocation = FQuat(FVector(0.0f, 0.0f, 1.0f), 3 * PI / 2.f)*MAPConverters::MAPtoF(data->origin);
	if (HammUErSettings::importNonZero)
		decalLocation += HammUErSettings::importOffset;

	if ((HammUErSettings::importRotation) && (HammUErSettings::CenterCheckboxEnabled))
		decalLocation = rotatorToUse.RotateVector(decalLocation);

	FHitResult Hit(ForceInit);
	FVector Start, End;

	FCollisionQueryParams FCQP;
	FCollisionObjectQueryParams FCOQP = FCollisionObjectQueryParams(ECC_TO_BITFIELD(ECC_WorldStatic));

	int multiplier = 0; // find the nearest surface, within reason
	while ((multiplier < 10) && (!Hit.Actor.IsValid()))
	{
		if (!Hit.Actor.IsValid())
		{
			Start = decalLocation + FVector(0, 0, 5 + 5 * multiplier);
			End = decalLocation - FVector(0, 0, 5 + 5 * multiplier);
			editorWorld->LineTraceSingleByObjectType(Hit, Start, End, FCOQP, FCQP);

			if (!Hit.Actor.IsValid())
			{
				Start = decalLocation + FVector(5 + 5 * multiplier, 0, 0);
				End = decalLocation - FVector(5 + 5 * multiplier, 0, 0);
				editorWorld->LineTraceSingleByObjectType(Hit, Start, End, FCOQP, FCQP);

				if (!Hit.Actor.IsValid())
				{
					Start = decalLocation - FVector(5 + 5 * multiplier, 0, 0);
					End = decalLocation + FVector(5 + 5 * multiplier, 0, 0);
					editorWorld->LineTraceSingleByObjectType(Hit, Start, End, FCOQP, FCQP);

					if (!Hit.Actor.IsValid())
					{
						Start = decalLocation - FVector(0, 5 + 5 * multiplier, 0);
						End = decalLocation + FVector(0, 5 + 5 * multiplier, 0);
						editorWorld->LineTraceSingleByObjectType(Hit, Start, End, FCOQP, FCQP);

						if (!Hit.Actor.IsValid())
						{
							Start = decalLocation + FVector(0, 5 + 5 * multiplier, 0);
							End = decalLocation - FVector(0, 5 + 5 * multiplier, 0);
							editorWorld->LineTraceSingleByObjectType(Hit, Start, End, FCOQP, FCQP);

							if (!Hit.Actor.IsValid())
							{
								Start = decalLocation - FVector(0, 0, 5 + 5 * multiplier);
								End = decalLocation + FVector(0, 0, 5 + 5 * multiplier);
								editorWorld->LineTraceSingleByObjectType(Hit, Start, End, FCOQP, FCQP);
							}
						}
					}
				}
			}
		}
		multiplier++;
	}
	if (Hit.Actor.IsValid())
		decalLocation = Hit.ImpactPoint;

	UMaterialInterface* matToUse = NULL;
	int index = HammUErSettings::FindInMaster(data->materialName.c_str());
	int adbi = -1;
	if (index > -1)
	{
		adbi = HammUErSettings::masterMaterialList[index]->AssetDatabaseIndex;
		if (adbi > -1)
			matToUse = ((UMaterialInterface*)HammUErSettings::AssetData[adbi].GetAsset());
		else
			UE_LOG(LogTemp, Error, TEXT("Could not find %s in asset database?"), data->materialName.c_str());

	}
	else
		UE_LOG(LogTemp, Warning, TEXT("Could not find %s in master database."), data->materialName.c_str());
	float scaleValue = 1.f;
	if ((data->maxU < 0) || (data->maxV < 0))
	{
		if (adbi > -1)
		{
			int tempU, tempV;
			HammUErSettings::GetMaterialSizes((UMaterial*)HammUErSettings::AssetData[adbi].GetAsset(), tempU, tempV);
			scaleValue = HammUErSettings::GetDecalScale(data->materialName.c_str());
			data->maxU = (tempU / 2) * scaleValue;
			data->maxV = (tempV / 2) * scaleValue;
		}
		else
		{
			data->maxU = 1;
			data->maxV = 1;
		}
	}

	ADecalActor* newDecal = editorWorld->SpawnActor<ADecalActor>(FAS);
	newDecal->SetActorLabel(tempName);

	newDecal->SetDecalMaterial(matToUse);

	newDecal->SetActorLocation(decalLocation);
	newDecal->SetActorRotation(FQuat::Identity); // reset the stupid default of -90 pitch

	FVector normalized = -Hit.Normal;
	normalized.Normalize();
	FVector baseRotation = FVector(1, 0, 0);

	FRotator newRotation = normalized.Rotation();
	newDecal->SetActorRotation(newRotation);

	float dot = FVector::DotProduct(normalized, FVector(0, 0, 1));
	if ((FMath::Abs(dot) < 0.3f))
	{ // should be vertical
		newDecal->AddActorLocalRotation(FRotator(0, 0, 90));
	}
	else
	{
		if (FMath::Abs(dot) > 0.7f)
		{
			newRotation.Yaw = 0;
			newRotation.Roll = data->angles.Y - 90;
			if (FMath::Abs(newRotation.Roll) > 165)
			{
				newRotation.Yaw = -180;
				newRotation.Roll = 180 - newRotation.Roll;
				UE_LOG(LogTemp, Warning, TEXT("Did some sneaky trickery for %s"), data->name.c_str());
			}
			newDecal->SetActorRotation(newRotation);
		}
	}

#if ENGINE_MINOR_VERSION>=11
	newDecal->SetActorRelativeScale3D(FVector(1.f, 1.f, 1.f));
	newDecal->GetDecal()->DecalSize = FVector(1.f, (data->maxV*local_conversionFactor), (data->maxU*local_conversionFactor));
#else
	newDecal->SetActorRelativeScale3D(FVector(1.f, data->maxV*local_conversionFactor, data->maxU*local_conversionFactor));
#endif

	newDecal->Tags.Empty();
	newDecal->Tags.Add(FName(*tag));
	newDecal->Tags.Add(FName(data->classname.c_str()));
	UActorComponent* stupidworkaround = newDecal->GetComponentByClass(UDecalComponent::StaticClass());
	FString workString = "U = " + FString::SanitizeFloat(data->startU) + "-" + FString::SanitizeFloat(data->endU);
	stupidworkaround->ComponentTags.Add(FName(*workString));
	workString = "V = " + FString::SanitizeFloat(data->startV) + "-" + FString::SanitizeFloat(data->endV);
	stupidworkaround->ComponentTags.Add(FName(*workString));
	workString = "decalScale = " + FString::SanitizeFloat(scaleValue);
	stupidworkaround->ComponentTags.Add(FName(*workString));
	newDecal->PostEditChange();
}

void MapFileLoader::GetRotationValues(int rotationType, FVector angles, float& changePitch, float& changeRoll, float &changeYaw)
{
	switch (rotationType)
	{
	case 0: // nothing;

		changeYaw = -angles.Y;
		/*changeRoll = angles.Z;
		changePitch = angles.X;*/
		// original kludge
		changeRoll = angles.X;
		changePitch = angles.Z;
		break;
	case 1:
		changeYaw = 90 + 360 - angles.Y;
		changeRoll = -angles.Z;
		changePitch = angles.X;
		break;
	case 2:
		changeYaw = -angles.Y + 270;
		changeRoll = -angles.Z;
		changePitch = angles.X;
		break;
	}
}

UStaticMesh* MapFileLoader::ImportBrush(MapBrush* workBrush, TArray<UMaterialInterface*> newMaterials, FVector &meshPosition, bool overrideDecouple, bool buildActor, bool noComplex)
{
	UWorld* editorWorld = GEditor->GetEditorWorldContext().World();
	FRotator rotatorToUse = FRotator(HammUErSettings::importRotationValue.Y, HammUErSettings::importRotationValue.Z, HammUErSettings::importRotationValue.X);

	if (!workBrush)
		return GenerateTemporaryModel("broken_brush", true);
	if (workBrush->triangles.size() == 0)  // empty brush
		return GenerateTemporaryModel("no_triangles_in_brush", true);

	
	FString MeshName = workBrush->brushName.c_str();
	MeshName = MeshName.Replace(TEXT(" "), TEXT("_"));
	MeshName = MeshName.Replace(TEXT("*"), TEXT("X"));
	MeshName = MeshName.Replace(TEXT("?"), TEXT("Q"));
	MeshName = MeshName.Replace(TEXT("!"), TEXT("I"));
	MeshName = MeshName.Replace(TEXT("."), TEXT("-"));
	MeshName = MeshName.Replace(TEXT("&"), TEXT("_"));

	//PreviousActorExists(MeshName, true); // trying to make sure we remove the old one first kinda messes with it and makes it become "invisible" to UE

	FRawMesh rawMesh;
	TArray<int32> reIndexedMaterials;

	BuildRawMesh(workBrush->triangles, rawMesh, reIndexedMaterials);
	if (rawMesh.VertexPositions.Num() == 0)
		return GenerateTemporaryModel("no_vertices_in_brush", true);


	if (HammUErSettings::CenterCheckboxEnabled || overrideDecouple)
		RecenterMesh(rawMesh, meshPosition, (meshPosition != FVector::ZeroVector));

	TArray<UMaterialInterface*> meshMaterials;
	for (int j = 0; j < reIndexedMaterials.Num(); j++)
		meshMaterials.Add(newMaterials[reIndexedMaterials[j]]);

	FString NewPackageName = TEXT("/Game/") + (importDirectory != "" ? importDirectory + "/Meshes/" : "Meshes/") + MeshName;
	UPackage* Package = CreatePackage(NULL, *NewPackageName);
	Package->FullyLoad();
	Package->Modify();
	
	if (createInstanceData)
	{
		instanceData->instanceAdd(workBrush->id);
		instanceData->instanceAddString(NewPackageName+"."+MeshName);
		instanceData->instanceAdd(meshPosition);
	}

	if (MeshName.Contains("/") || MeshName.Contains("\\"))
	{
		MeshName = MeshName.Replace(TEXT("\\"), TEXT("/"));
		int offset = MeshName.Find("/", ESearchCase::IgnoreCase, ESearchDir::FromEnd);
		MeshName = MeshName.Mid(offset+1);
	}

	UStaticMesh* NewAsset = HammUErSettings::CreateStaticMesh(rawMesh, meshMaterials, Package, FName(*MeshName),noComplex);

	FAssetRegistryModule::AssetCreated(NewAsset);
	NewAsset->PostEditChange();

	Package->SetDirtyFlag(true);

	FString PackageFileName = FPackageName::LongPackageNameToFilename(NewPackageName, FPackageName::GetAssetPackageExtension());
//	listofStaticMeshes.Add(NewAsset);
	if (HammUErSettings::generateThumbs)
		ThumbnailTools::GenerateThumbnailForObjectToSaveToDisk(NewAsset);
	if (UPackage::SavePackage(Package, NewAsset, RF_Public | RF_Standalone, *PackageFileName, GError, nullptr, false, true, SAVE_NoError))

	{
		if (HammUErSettings::verboseDebugEnabled)UE_LOG(LogTemp, Warning, TEXT("Saving %s to package successful"), *NewPackageName);
		if (buildActor)
		{
			FActorSpawnParameters FAS;

			if (HammUErSettings::alwaysPrependFilename)
			if (!MeshName.StartsWith(FPaths::GetBaseFilename(cacheFilename))) // this should never happen, but you never know
				MeshName = FPaths::GetBaseFilename(cacheFilename) + "_" + MeshName;

			FAS.Name = FName(*MeshName);
			
			if (HammUErSettings::toDeleteList.Num() > 0)
			{
				if (HammUErSettings::toDeleteList.Contains(MeshName))
					HammUErSettings::toDeleteList.Remove(MeshName);
			}

			AStaticMeshActor* tempActor = editorWorld->SpawnActor<AStaticMeshActor>(FAS);
			tempActor->SetActorLabel(MeshName);

			if (HammUErSettings::importNonZero)
				meshPosition += HammUErSettings::importOffset;

			if ((HammUErSettings::importRotation) && (HammUErSettings::CenterCheckboxEnabled))
				meshPosition = rotatorToUse.RotateVector(meshPosition);

			if (HammUErSettings::importRotation)
				tempActor->SetActorRotation(rotatorToUse);

			tempActor->SetActorLocation(meshPosition);
#if ENGINE_MINOR_VERSION <14
			tempActor->GetStaticMeshComponent()->StaticMesh = NewAsset;
#else
			tempActor->GetStaticMeshComponent()->SetStaticMesh(NewAsset);
#endif
			if (HammUErSettings::generateOverlaps)
				tempActor->GetStaticMeshComponent()->SetGenerateOverlapEvents(true);
			FVector checkPos = tempActor->GetActorLocation();
			if (checkPos != meshPosition)
				tempActor->SetActorLocation(meshPosition);
			if ((HammUErSettings::twoSidedCull) && (workBrush->containsNoDraw || workBrush->containsDisplacements))
				((UPrimitiveComponent*)tempActor->GetRootComponent())->bCastShadowAsTwoSided = true;
			tempActor->PostEditChange();
		}
		else
			return NewAsset;
	}
	else
		if (HammUErSettings::verboseDebugEnabled)UE_LOG(LogTemp, Error, TEXT("Saving %s to package failed"), *NewPackageName);
	return NULL;
}

void MapFileLoader::ImportIntoWorld(TArray<UMaterialInterface*> newMaterials, bool doAll)
{
	instanceData = new InstanceDataHandler();

	FString umapname;
	FString NMIDPackageFileName;
	UPackage* NMIDPackage = nullptr;
	UWorld* newWorld = nullptr;

	if (FPaths::GetBaseFilename(cacheFilename).StartsWith(TEXT("HI_"), ESearchCase::CaseSensitive))
	{
		umapname = FPaths::GetBaseFilename(cacheFilename);
		FString NMIDPackageName = TEXT("/Game/HammUErInstances/") + umapname;
		NMIDPackageFileName = FPackageName::LongPackageNameToFilename(NMIDPackageName, FPackageName::GetAssetPackageExtension());
		NMIDPackage = CreatePackage(NULL, *NMIDPackageName);
		NMIDPackage->FullyLoad();
		NMIDPackage->Modify();
		if (!NMIDPackage->ContainsMap())
			newWorld = UWorld::CreateWorld(EWorldType::Editor, true, *umapname, NMIDPackage);
		FEditorFileUtils::LoadMap(NMIDPackageName);
		newWorld = GEditor->GetEditorWorldContext().World();
		GEditor->SavePackage(NMIDPackage, newWorld, RF_Public | RF_Standalone, *NMIDPackageFileName, GError, nullptr, false, true, SAVE_None);
	}
	/*//FAILED single uasset file saving for meshes, it takes a billion times longer
	FString NewPackageName = TEXT("/Game/") + (importDirectory != "" ? importDirectory + "/Meshes/" : "Meshes/") + importDirectory;
	Package = CreatePackage(NULL, *NewPackageName);*/

	if (createInstanceData)
	{
		int numB = GetNumBrushes();
		if (HammUErSettings::doNotGenerateMeshes) // this is a bad, bad idea to combine these, but... gotta account for it
			numB = 0;
		int numE = GetNumEntities();
		if (HammUErSettings::doNotGenerateEntities)
			numE = 0;
		instanceData->instanceAdd(numB);
		instanceData->instanceAdd(numE);
	}

	// generate meshes
	int numBrushes = GetNumBrushes();
	FScopedSlowTask SlowTask(numBrushes, FText::FromString("Building meshes..."));
	SlowTask.MakeDialog();
	FVector meshPosition = FVector::ZeroVector;
	bool useReducedList = (HammUErSettings::reducedImportList.Num() > 0);

	FString tempName;

	for (int i = 0; i < numBrushes; i++)
	{
		SlowTask.EnterProgressFrame(1);
		MapBrush* workBrush = GetBrush(i);
		meshPosition = FVector::ZeroVector;
		if (workBrush)
		{
			tempName = workBrush->brushName.c_str();
			tempName = tempName.Replace(TEXT(" "), TEXT("_"));
			tempName = tempName.Replace(TEXT("*"), TEXT("X"));
			tempName = tempName.Replace(TEXT("?"), TEXT("Q"));
			tempName = tempName.Replace(TEXT("!"), TEXT("I"));
			tempName = tempName.Replace(TEXT("."), TEXT("-"));
			tempName = tempName.Replace(TEXT("&"), TEXT("_"));
			if (HammUErSettings::alwaysPrependFilename)
				if (!tempName.StartsWith(FPaths::GetBaseFilename(cacheFilename))) // this should never happen, but you never know
					tempName = FPaths::GetBaseFilename(cacheFilename) + "_" + tempName;

			if (useReducedList)
			{
				if (!HammUErSettings::reducedImportList.Contains(workBrush->id))
				{
					if (HammUErSettings::toDeleteList.Num() > 0)
					{
						if (HammUErSettings::toDeleteList.Contains(tempName))
							HammUErSettings::toDeleteList.Remove(tempName);
					}
					continue;
				}
			}

			if (IsIgnoreActor(tempName))
			{
				UE_LOG(LogTemp, Log, TEXT("Skipping %s, contains ignore tag."), *tempName);
				continue;
			}
			if (!HammUErSettings::doNotGenerateMeshes)
			{
				ImportBrush(workBrush, newMaterials, meshPosition);
			}
		}
	}


	// now do entities
	int numEntities = GetNumEntities();
	useReducedList = (HammUErSettings::reducedImportEntityList.Num() > 0);
	{
		FScopedSlowTask SlowTask(numEntities, FText::FromString("Importing entities..."));
		SlowTask.MakeDialog();

		TArray<AHammuerPathNode*> pathNodeList; // need this for later
		for (int i = 0; i < numEntities; i++)
		{
			SlowTask.EnterProgressFrame(1);
			int entityType = GetEntityType(i);
			if (createInstanceData)
				instanceData->instanceAdd(entityType);

			tempName = GetEntityName(i);
			tempName = tempName.Replace(TEXT(" "), TEXT("_"));
			tempName = tempName.Replace(TEXT("*"), TEXT("X"));
			tempName = tempName.Replace(TEXT("?"), TEXT("Q"));
			tempName = tempName.Replace(TEXT("!"), TEXT("I"));
			tempName = tempName.Replace(TEXT("."), TEXT("-"));
			tempName = tempName.Replace(TEXT("&"), TEXT("_"));
			if (HammUErSettings::alwaysPrependFilename)
				if (!tempName.StartsWith(FPaths::GetBaseFilename(cacheFilename))) // this should never happen, but you never know
					tempName = FPaths::GetBaseFilename(cacheFilename) + "_" + tempName;

			if (useReducedList)
			{
				if (!HammUErSettings::reducedImportList.Contains(GetEntityID(i)))
				{
					if (HammUErSettings::toDeleteList.Num() > 0)
					{
						if (HammUErSettings::toDeleteList.Contains(tempName))
							HammUErSettings::toDeleteList.Remove(tempName);
					}
					continue;
				}
			}

			if (IsIgnoreActor(tempName))
			{
				UE_LOG(LogTemp, Log, TEXT("Skipping %s, contains ignore tag."), *tempName);
				continue;
			}
			if (!HammUErSettings::doNotGenerateEntities)
			{
				switch (entityType)
				{
				case MapEntityType::Instance:
					DoFuncInstance(i);
					break;
				case MapEntityType::FuncBrush:
					DoFuncBrush(i, newMaterials);
					break;
				case MapEntityType::FuncStatic:
					DoFuncStatic(i, newMaterials);
					break;
				case MapEntityType::FuncBox:
					DoFuncBox(i, newMaterials);
					break;
				case MapEntityType::LogicRelay:
					DoLogicRelay(i);
					break;
				case MapEntityType::LogicAuto:
					DoLogicAuto(i);
					break;
				case MapEntityType::PropStatic:
					DoPropStatic(i);
					break;
				case MapEntityType::PropDynamic:
					DoPropDynamic(i);
					break;
				case MapEntityType::Light:
					DoLight(i);
					break;
				case MapEntityType::Path:
					pathNodeList.Add(DoPath(i));
					break;
				case MapEntityType::Spotlight:
					DoSpotLight(i);
					break;
				case MapEntityType::EnvironmentLight:
					DoEnvironmentLight(i);
					break;
				case MapEntityType::Overlay:
					DoOverlay(i);
					break;
				default:
					if (!HammUErSettings::doNotGenerateUnknownNotes)
						DoDummy(i);
					//UE_LOG(LogTemp, Warning, TEXT("Unimplemented entity type? If a brush type, check entity_mesh actors that match tag id"));
				}
			}
			/* //FAILED single uasset file saving for meshes, it takes a billion times longer
			FScopedSlowTask SlowTask2(listofStaticMeshes.Num(), FText::FromString("Saving meshes..."));
			SlowTask2.MakeDialog();
			FString PackageFileName = FPackageName::LongPackageNameToFilename(NewPackageName, FPackageName::GetAssetPackageExtension());
			for (int i = 0; i < listofStaticMeshes.Num(); i++)
			{
				SlowTask2.EnterProgressFrame(1);
				UPackage::SavePackage(Package, listofStaticMeshes[i], RF_Public | RF_Standalone, *PackageFileName, GError, nullptr, false, true, SAVE_NoError);
			}
		*/

		// okay now walk through the paths and hook them up
			for (int i = 0; i < pathNodeList.Num(); i++)
			{
				AHammuerPathNode* target = NULL;;
				for (TObjectIterator<AHammuerPathNode> Itr; Itr; ++Itr)
				{
					FString toCheck = Itr->GetActorLabel();
					if (toCheck == pathNodeList[i]->myTargetName)
					{
						target = (*Itr);
						break;
					}
				}
				if (target != NULL)
				{
					pathNodeList[i]->nextTarget = target;
				}
			}
		}
	}
	if (createInstanceData)
		instanceData->WriteTo(instanceFileName);

	if (FPaths::GetBaseFilename(cacheFilename).StartsWith(TEXT("HI_"), ESearchCase::CaseSensitive))
	{
		UE_LOG(LogTemp, Log, TEXT("Need to save this map, it's a HammUEr Instance."));

		if (newWorld)
			GEditor->SavePackage(NMIDPackage, newWorld, RF_Public | RF_Standalone, *NMIDPackageFileName, GError, nullptr, false, true, SAVE_None);
	}


	delete instanceData;
}


// some oldskool code that should hopefully increase user feedback
UStaticMesh* MapFileLoader::GenerateTemporaryModel(std::string modelLocation, bool generateExclamation)
{
	MapBrush* newTempBrush = new MapBrush();
	if (modelLocation.find(".mdl") != std::string::npos)
	{
		std::size_t location = modelLocation.find(".mdl");
		modelLocation = modelLocation.erase(location);
	}
	newTempBrush->brushName = modelLocation;
	bool oldCenter = HammUErSettings::CenterCheckboxEnabled;
	HammUErSettings::CenterCheckboxEnabled = false;

	std::vector<VMFTri*> newTri;

	if (generateExclamation)
	{
		for (int i = 0; i < 52; i++)
			newTri.push_back(NULL);
		newTri[0] = new VMFTri(MAPVector(-1.f, 1.f, 1.f), MAPVector(-1.f, 1.f, -1.f), MAPVector(-1.f, -1.f, -1.f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[0]);
		newTri[1] = new VMFTri(MAPVector(-1.f, 1.f, 1.f), MAPVector(-1.f, -1.f, -1.f), MAPVector(-1.f, -1.f, 1.f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[1]);
		newTri[2] = new VMFTri(MAPVector(-1.f, 1.f, -1.f), MAPVector(1.f, 1.f, -1.f), MAPVector(1.f, -1.f, -1.f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[2]);
		newTri[3] = new VMFTri(MAPVector(-1.f, 1.f, -1.f), MAPVector(1.f, -1.f, -1.f), MAPVector(-1.f, -1.f, -1.f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[3]);
		newTri[4] = new VMFTri(MAPVector(1.f, 1.f, -1.f), MAPVector(1.f, 1.f, 1.f), MAPVector(1.f, -1.f, 1.f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[4]);
		newTri[5] = new VMFTri(MAPVector(1.f, 1.f, -1.f), MAPVector(1.f, -1.f, 1.f), MAPVector(1.f, -1.f, -1.f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[5]);
		newTri[6] = new VMFTri(MAPVector(1.f, 1.f, 1.f), MAPVector(-1.f, 1.f, 1.f), MAPVector(-1.f, 1.f, 6.f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[6]);
		newTri[7] = new VMFTri(MAPVector(1.f, 1.f, 1.f), MAPVector(-1.f, 1.f, 6.f), MAPVector(1.f, 1.f, 6.f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[7]);
		newTri[8] = new VMFTri(MAPVector(-1.f, -1.f, 1.f), MAPVector(-1.f, -1.f, -1.f), MAPVector(1.f, -1.f, -1.f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[8]);
		newTri[9] = new VMFTri(MAPVector(-1.f, -1.f, 1.f), MAPVector(1.f, -1.f, -1.f), MAPVector(1.f, -1.f, 1.f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[9]);
		newTri[10] = new VMFTri(MAPVector(1.f, 1.f, 1.f), MAPVector(1.f, 1.f, -1.f), MAPVector(1.f, 6.f, -1.f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[10]);
		newTri[11] = new VMFTri(MAPVector(1.f, 1.f, 1.f), MAPVector(1.f, 6.f, -1.f), MAPVector(1.f, 6.f, 1.f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[11]);
		newTri[12] = new VMFTri(MAPVector(1.f, 1.f, 6.f), MAPVector(-1.f, 1.f, 6.f), MAPVector(-1.f, -1.f, 6.f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[12]);
		newTri[13] = new VMFTri(MAPVector(1.f, 1.f, 6.f), MAPVector(-1.f, -1.f, 6.f), MAPVector(1.f, -1.f, 6.f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[13]);
		newTri[14] = new VMFTri(MAPVector(1.f, -1.f, 1.f), MAPVector(1.f, 1.f, 1.f), MAPVector(1.f, 1.f, 6.f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[14]);
		newTri[15] = new VMFTri(MAPVector(1.f, -1.f, 1.f), MAPVector(1.f, 1.f, 6.f), MAPVector(1.f, -1.f, 6.f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[15]);
		newTri[16] = new VMFTri(MAPVector(-1.f, 1.f, 1.f), MAPVector(-1.f, -1.f, 1.f), MAPVector(-1.f, -1.f, 6.f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[16]);
		newTri[17] = new VMFTri(MAPVector(-1.f, 1.f, 1.f), MAPVector(-1.f, -1.f, 6.f), MAPVector(-1.f, 1.f, 6.f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[17]);
		newTri[18] = new VMFTri(MAPVector(-1.f, -1.f, 1.f), MAPVector(1.f, -1.f, 1.f), MAPVector(1.f, -1.f, 6.f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[18]);
		newTri[19] = new VMFTri(MAPVector(-1.f, -1.f, 1.f), MAPVector(1.f, -1.f, 6.f), MAPVector(-1.f, -1.f, 6.f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[19]);
		newTri[20] = new VMFTri(MAPVector(-1.f, 1.f, -2.f), MAPVector(-1.f, 1.f, -4.f), MAPVector(-1.f, -1.f, -4.f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[20]);
		newTri[21] = new VMFTri(MAPVector(-1.f, 1.f, -2.f), MAPVector(-1.f, -1.f, -4.f), MAPVector(-1.f, -1.f, -2.f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[21]);
		newTri[22] = new VMFTri(MAPVector(-1.f, 1.f, -4.f), MAPVector(1.f, 1.f, -4.f), MAPVector(1.f, -1.f, -4.f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[22]);
		newTri[23] = new VMFTri(MAPVector(-1.f, 1.f, -4.f), MAPVector(1.f, -1.f, -4.f), MAPVector(-1.f, -1.f, -4.f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[23]);
		newTri[24] = new VMFTri(MAPVector(1.f, 1.f, -4.f), MAPVector(1.f, 1.f, -2.f), MAPVector(1.f, -1.f, -2.f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[24]);
		newTri[25] = new VMFTri(MAPVector(1.f, 1.f, -4.f), MAPVector(1.f, -1.f, -2.f), MAPVector(1.f, -1.f, -4.f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[25]);
		newTri[26] = new VMFTri(MAPVector(1.f, 1.f, -2.f), MAPVector(-1.f, 1.f, -2.f), MAPVector(-1.f, -1.f, -2.f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[26]);
		newTri[27] = new VMFTri(MAPVector(1.f, 1.f, -2.f), MAPVector(-1.f, -1.f, -2.f), MAPVector(1.f, -1.f, -2.f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[27]);
		newTri[28] = new VMFTri(MAPVector(-1.f, -1.f, -2.f), MAPVector(-1.f, -1.f, -4.f), MAPVector(1.f, -1.f, -4.f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[28]);
		newTri[29] = new VMFTri(MAPVector(-1.f, -1.f, -2.f), MAPVector(1.f, -1.f, -4.f), MAPVector(1.f, -1.f, -2.f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[29]);
		newTri[30] = new VMFTri(MAPVector(1.f, 1.f, -2.f), MAPVector(1.f, 1.f, -4.f), MAPVector(-1.f, 1.f, -4.f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[30]);
		newTri[31] = new VMFTri(MAPVector(1.f, 1.f, -2.f), MAPVector(-1.f, 1.f, -4.f), MAPVector(-1.f, 1.f, -2.f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[31]);
		newTri[32] = new VMFTri(MAPVector(1.f, 6.f, 1.f), MAPVector(1.f, 6.f, -1.f), MAPVector(-1.f, 6.f, -1.f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[32]);
		newTri[33] = new VMFTri(MAPVector(1.f, 6.f, 1.f), MAPVector(-1.f, 6.f, -1.f), MAPVector(-1.f, 6.f, 1.f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[33]);
		newTri[34] = new VMFTri(MAPVector(-1.f, 1.f, -1.f), MAPVector(-1.f, 1.f, 1.f), MAPVector(-1.f, 6.f, 1.f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[34]);
		newTri[35] = new VMFTri(MAPVector(-1.f, 1.f, -1.f), MAPVector(-1.f, 6.f, 1.f), MAPVector(-1.f, 6.f, -1.f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[35]);
		newTri[36] = new VMFTri(MAPVector(-1.f, 1.f, 1.f), MAPVector(1.f, 1.f, 1.f), MAPVector(1.f, 6.f, 1.f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[36]);
		newTri[37] = new VMFTri(MAPVector(-1.f, 1.f, 1.f), MAPVector(1.f, 6.f, 1.f), MAPVector(-1.f, 6.f, 1.f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[37]);
		newTri[38] = new VMFTri(MAPVector(1.f, 1.f, -1.f), MAPVector(-1.f, 1.f, -1.f), MAPVector(-1.f, 6.f, -1.f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[38]);
		newTri[39] = new VMFTri(MAPVector(1.f, 1.f, -1.f), MAPVector(-1.f, 6.f, -1.f), MAPVector(1.f, 6.f, -1.f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[39]);
		newTri[40] = new VMFTri(MAPVector(-1.f, -3.f, 1.f), MAPVector(-1.f, -3.f, -1.f), MAPVector(-1.f, -5.f, -1.f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[40]);
		newTri[41] = new VMFTri(MAPVector(-1.f, -3.f, 1.f), MAPVector(-1.f, -5.f, -1.f), MAPVector(-1.f, -5.f, 1.f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[41]);
		newTri[42] = new VMFTri(MAPVector(-1.f, -3.f, -1.f), MAPVector(1.f, -3.f, -1.f), MAPVector(1.f, -5.f, -1.f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[42]);
		newTri[43] = new VMFTri(MAPVector(-1.f, -3.f, -1.f), MAPVector(1.f, -5.f, -1.f), MAPVector(-1.f, -5.f, -1.f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[43]);
		newTri[44] = new VMFTri(MAPVector(1.f, -3.f, -1.f), MAPVector(1.f, -3.f, 1.f), MAPVector(1.f, -5.f, 1.f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[44]);
		newTri[45] = new VMFTri(MAPVector(1.f, -3.f, -1.f), MAPVector(1.f, -5.f, 1.f), MAPVector(1.f, -5.f, -1.f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[45]);
		newTri[46] = new VMFTri(MAPVector(1.f, -3.f, 1.f), MAPVector(-1.f, -3.f, 1.f), MAPVector(-1.f, -5.f, 1.f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[46]);
		newTri[47] = new VMFTri(MAPVector(1.f, -3.f, 1.f), MAPVector(-1.f, -5.f, 1.f), MAPVector(1.f, -5.f, 1.f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[47]);
		newTri[48] = new VMFTri(MAPVector(-1.f, -5.f, 1.f), MAPVector(-1.f, -5.f, -1.f), MAPVector(1.f, -5.f, -1.f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[48]);
		newTri[49] = new VMFTri(MAPVector(-1.f, -5.f, 1.f), MAPVector(1.f, -5.f, -1.f), MAPVector(1.f, -5.f, 1.f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[49]);
		newTri[50] = new VMFTri(MAPVector(1.f, -3.f, 1.f), MAPVector(1.f, -3.f, -1.f), MAPVector(-1.f, -3.f, -1.f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[50]);
		newTri[51] = new VMFTri(MAPVector(1.f, -3.f, 1.f), MAPVector(-1.f, -3.f, -1.f), MAPVector(-1.f, -3.f, 1.f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), MAPColor(0, 255, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[51]);
	}
	else
	{
		for (int i = 0; i < 88; i++)
			newTri.push_back(NULL);
		// kicking it oldskool in here! Yes, I just came here from 1985. Shut up.
		newTri[0] = new VMFTri(MAPVector(-0.375f, -0.375f, 2.917985f), MAPVector(-0.375f, 0.375001f, 2.827422f), MAPVector(-0.375f, 0.375001f, 1.774594f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[0]);
		newTri[1] = new VMFTri(MAPVector(-0.375f, -0.375f, 2.917985f), MAPVector(-0.375f, 0.375001f, 1.774594f), MAPVector(-0.375f, -0.375f, 1.774594f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[1]);
		newTri[2] = new VMFTri(MAPVector(-0.375f, 0.375001f, 2.827422f), MAPVector(0.375f, 0.375001f, 2.827422f), MAPVector(0.375f, 0.375001f, 1.774594f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[2]);
		newTri[3] = new VMFTri(MAPVector(-0.375f, 0.375001f, 2.827422f), MAPVector(0.375f, 0.375001f, 1.774594f), MAPVector(-0.375f, 0.375001f, 1.774594f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[3]);
		newTri[4] = new VMFTri(MAPVector(0.375f, 0.375001f, 2.827422f), MAPVector(0.375f, -0.375f, 2.917985f), MAPVector(0.375f, -0.375f, 1.774594f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[4]);
		newTri[5] = new VMFTri(MAPVector(0.375f, 0.375001f, 2.827422f), MAPVector(0.375f, -0.375f, 1.774594f), MAPVector(0.375f, 0.375001f, 1.774594f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[5]);
		newTri[6] = new VMFTri(MAPVector(0.375f, -0.375f, 2.917985f), MAPVector(-0.375f, -0.375f, 2.917985f), MAPVector(-0.375f, -0.375f, 1.774594f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[6]);
		newTri[7] = new VMFTri(MAPVector(0.375f, -0.375f, 2.917985f), MAPVector(-0.375f, -0.375f, 1.774594f), MAPVector(0.375f, -0.375f, 1.774594f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[7]);
		newTri[8] = new VMFTri(MAPVector(-0.375f, 0.375001f, 2.827422f), MAPVector(-0.375f, -0.375f, 2.917985f), MAPVector(-0.375f, 0.366772f, 3.586801f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[8]);
		newTri[9] = new VMFTri(MAPVector(-0.375f, 0.375001f, 2.827422f), MAPVector(-0.375f, 0.366772f, 3.586801f), MAPVector(-0.375f, 0.375001f, 3.586801f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[9]);
		newTri[10] = new VMFTri(MAPVector(0.375f, 0.366772f, 3.586801f), MAPVector(0.375f, 0.375001f, 3.586801f), MAPVector(-0.375f, 0.375001f, 3.586801f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[10]);
		newTri[11] = new VMFTri(MAPVector(0.375f, 0.366772f, 3.586801f), MAPVector(-0.375f, 0.375001f, 3.586801f), MAPVector(-0.375f, 0.366772f, 3.586801f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[11]);
		newTri[12] = new VMFTri(MAPVector(-0.375f, -0.375f, 2.917985f), MAPVector(0.375f, -0.375f, 2.917985f), MAPVector(0.375f, 0.366772f, 3.586801f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[12]);
		newTri[13] = new VMFTri(MAPVector(-0.375f, -0.375f, 2.917985f), MAPVector(0.375f, 0.366772f, 3.586801f), MAPVector(-0.375f, 0.366772f, 3.586801f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[13]);
		newTri[14] = new VMFTri(MAPVector(0.375f, 0.375001f, 3.586801f), MAPVector(0.375f, 0.375001f, 2.827422f), MAPVector(0.375f, 1.55557f, 3.511325f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[14]);
		newTri[15] = new VMFTri(MAPVector(0.375f, 0.375001f, 3.586801f), MAPVector(0.375f, 1.55557f, 3.511325f), MAPVector(0.375f, 1.55557f, 4.18014f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[15]);
		newTri[16] = new VMFTri(MAPVector(0.375f, -0.375f, 2.917985f), MAPVector(0.375f, 0.375001f, 2.827422f), MAPVector(0.375f, 0.375001f, 3.586801f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[16]);
		newTri[17] = new VMFTri(MAPVector(0.375f, -0.375f, 2.917985f), MAPVector(0.375f, 0.375001f, 3.586801f), MAPVector(0.375f, 0.366772f, 3.586801f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[17]);
		newTri[18] = new VMFTri(MAPVector(0.375f, 1.55557f, 4.18014f), MAPVector(0.375f, 1.55557f, 3.511325f), MAPVector(0.375f, 2.075434f, 4.083692f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[18]);
		newTri[19] = new VMFTri(MAPVector(0.375f, 1.55557f, 4.18014f), MAPVector(0.375f, 2.075434f, 4.083692f), MAPVector(0.375f, 2.075434f, 4.18014f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[19]);
		newTri[20] = new VMFTri(MAPVector(-0.375f, 0.375001f, 2.827422f), MAPVector(-0.375f, 0.375001f, 3.586801f), MAPVector(-0.375f, 1.55557f, 4.18014f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[20]);
		newTri[21] = new VMFTri(MAPVector(-0.375f, 0.375001f, 2.827422f), MAPVector(-0.375f, 1.55557f, 4.18014f), MAPVector(-0.375f, 1.55557f, 3.511325f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[21]);
		newTri[22] = new VMFTri(MAPVector(0.375f, 0.375001f, 2.827422f), MAPVector(-0.375f, 0.375001f, 2.827422f), MAPVector(-0.375f, 1.55557f, 3.511325f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[22]);
		newTri[23] = new VMFTri(MAPVector(0.375f, 0.375001f, 2.827422f), MAPVector(-0.375f, 1.55557f, 3.511325f), MAPVector(0.375f, 1.55557f, 3.511325f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[23]);
		newTri[24] = new VMFTri(MAPVector(-0.375f, 0.375001f, 3.586801f), MAPVector(0.375f, 0.375001f, 3.586801f), MAPVector(0.375f, 1.55557f, 4.18014f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[24]);
		newTri[25] = new VMFTri(MAPVector(-0.375f, 0.375001f, 3.586801f), MAPVector(0.375f, 1.55557f, 4.18014f), MAPVector(-0.375f, 1.55557f, 4.18014f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[25]);
		newTri[26] = new VMFTri(MAPVector(0.375f, 2.075434f, 4.083692f), MAPVector(-0.375f, 2.075434f, 4.083692f), MAPVector(-0.375f, 2.075434f, 4.18014f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[26]);
		newTri[27] = new VMFTri(MAPVector(0.375f, 2.075434f, 4.083692f), MAPVector(-0.375f, 2.075434f, 4.18014f), MAPVector(0.375f, 2.075434f, 4.18014f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[27]);
		newTri[28] = new VMFTri(MAPVector(-0.375f, 2.075434f, 4.18014f), MAPVector(-0.375f, 1.55557f, 4.18014f), MAPVector(-0.375f, 1.555571f, 5.28762f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[28]);
		newTri[29] = new VMFTri(MAPVector(-0.375f, 2.075434f, 4.18014f), MAPVector(-0.375f, 1.555571f, 5.28762f), MAPVector(-0.375f, 2.075434f, 5.28762f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[29]);
		newTri[30] = new VMFTri(MAPVector(-0.375f, 1.55557f, 3.511325f), MAPVector(-0.375f, 1.55557f, 4.18014f), MAPVector(-0.375f, 2.075434f, 4.18014f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[30]);
		newTri[31] = new VMFTri(MAPVector(-0.375f, 1.55557f, 3.511325f), MAPVector(-0.375f, 2.075434f, 4.18014f), MAPVector(-0.375f, 2.075434f, 4.083692f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[31]);
		newTri[32] = new VMFTri(MAPVector(0.375f, 1.55557f, 3.511325f), MAPVector(-0.375f, 1.55557f, 3.511325f), MAPVector(-0.375f, 2.075434f, 4.083692f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[32]);
		newTri[33] = new VMFTri(MAPVector(0.375f, 1.55557f, 3.511325f), MAPVector(-0.375f, 2.075434f, 4.083692f), MAPVector(0.375f, 2.075434f, 4.083692f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[33]);
		newTri[34] = new VMFTri(MAPVector(-0.375f, 1.555571f, 5.28762f), MAPVector(0.375f, 1.555571f, 5.28762f), MAPVector(0.375f, 0.435391f, 5.889502f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[34]);
		newTri[35] = new VMFTri(MAPVector(-0.375f, 1.555571f, 5.28762f), MAPVector(0.375f, 0.435391f, 5.889502f), MAPVector(-0.375f, 0.435391f, 5.889502f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[35]);
		newTri[36] = new VMFTri(MAPVector(-0.375f, 1.55557f, 4.18014f), MAPVector(0.375f, 1.55557f, 4.18014f), MAPVector(0.375f, 1.555571f, 5.28762f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[36]);
		newTri[37] = new VMFTri(MAPVector(-0.375f, 1.55557f, 4.18014f), MAPVector(0.375f, 1.555571f, 5.28762f), MAPVector(-0.375f, 1.555571f, 5.28762f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[37]);
		newTri[38] = new VMFTri(MAPVector(0.375f, 1.55557f, 4.18014f), MAPVector(0.375f, 2.075434f, 4.18014f), MAPVector(0.375f, 2.075434f, 5.28762f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[38]);
		newTri[39] = new VMFTri(MAPVector(0.375f, 1.55557f, 4.18014f), MAPVector(0.375f, 2.075434f, 5.28762f), MAPVector(0.375f, 1.555571f, 5.28762f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[39]);
		newTri[40] = new VMFTri(MAPVector(0.375f, 2.075434f, 4.18014f), MAPVector(-0.375f, 2.075434f, 4.18014f), MAPVector(-0.375f, 2.075434f, 5.28762f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[40]);
		newTri[41] = new VMFTri(MAPVector(0.375f, 2.075434f, 4.18014f), MAPVector(-0.375f, 2.075434f, 5.28762f), MAPVector(0.375f, 2.075434f, 5.28762f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[41]);
		newTri[42] = new VMFTri(MAPVector(-0.375f, 1.555571f, 5.77808f), MAPVector(0.375f, 1.555571f, 5.77808f), MAPVector(0.375f, 1.560331f, 5.77808f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[42]);
		newTri[43] = new VMFTri(MAPVector(-0.375f, 1.555571f, 5.77808f), MAPVector(0.375f, 1.560331f, 5.77808f), MAPVector(-0.375f, 1.560331f, 5.77808f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[43]);
		newTri[44] = new VMFTri(MAPVector(-0.375f, 2.075434f, 5.28762f), MAPVector(-0.375f, 1.555571f, 5.28762f), MAPVector(-0.375f, 1.555571f, 5.77808f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[44]);
		newTri[45] = new VMFTri(MAPVector(-0.375f, 2.075434f, 5.28762f), MAPVector(-0.375f, 1.555571f, 5.77808f), MAPVector(-0.375f, 1.560331f, 5.77808f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[45]);
		newTri[46] = new VMFTri(MAPVector(0.375f, 2.075434f, 5.28762f), MAPVector(-0.375f, 2.075434f, 5.28762f), MAPVector(-0.375f, 1.560331f, 5.77808f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[46]);
		newTri[47] = new VMFTri(MAPVector(0.375f, 2.075434f, 5.28762f), MAPVector(-0.375f, 1.560331f, 5.77808f), MAPVector(0.375f, 1.560331f, 5.77808f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[47]);
		newTri[48] = new VMFTri(MAPVector(0.375f, 1.555571f, 5.28762f), MAPVector(0.375f, 2.075434f, 5.28762f), MAPVector(0.375f, 1.560331f, 5.77808f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[48]);
		newTri[49] = new VMFTri(MAPVector(0.375f, 1.555571f, 5.28762f), MAPVector(0.375f, 1.560331f, 5.77808f), MAPVector(0.375f, 1.555571f, 5.77808f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[49]);
		newTri[50] = new VMFTri(MAPVector(0.375f, 0.435391f, 5.889502f), MAPVector(0.375f, 0.435391f, 6.379961f), MAPVector(0.375f, -0.197512f, 6.379961f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[50]);
		newTri[51] = new VMFTri(MAPVector(0.375f, 0.435391f, 5.889502f), MAPVector(0.375f, -0.197512f, 6.379961f), MAPVector(0.375f, -0.197512f, 5.889502f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[51]);
		newTri[52] = new VMFTri(MAPVector(0.375f, 1.555571f, 5.28762f), MAPVector(0.375f, 1.555571f, 5.77808f), MAPVector(0.375f, 0.435391f, 6.379961f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[52]);
		newTri[53] = new VMFTri(MAPVector(0.375f, 1.555571f, 5.28762f), MAPVector(0.375f, 0.435391f, 6.379961f), MAPVector(0.375f, 0.435391f, 5.889502f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[53]);
		newTri[54] = new VMFTri(MAPVector(0.375f, 1.555571f, 5.77808f), MAPVector(-0.375f, 1.555571f, 5.77808f), MAPVector(-0.375f, 0.435391f, 6.379961f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[54]);
		newTri[55] = new VMFTri(MAPVector(0.375f, 1.555571f, 5.77808f), MAPVector(-0.375f, 0.435391f, 6.379961f), MAPVector(0.375f, 0.435391f, 6.379961f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[55]);
		newTri[56] = new VMFTri(MAPVector(-0.375f, 1.555571f, 5.77808f), MAPVector(-0.375f, 1.555571f, 5.28762f), MAPVector(-0.375f, 0.435391f, 5.889502f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[56]);
		newTri[57] = new VMFTri(MAPVector(-0.375f, 1.555571f, 5.77808f), MAPVector(-0.375f, 0.435391f, 5.889502f), MAPVector(-0.375f, 0.435391f, 6.379961f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[57]);
		newTri[58] = new VMFTri(MAPVector(-0.375f, -0.197512f, 6.379961f), MAPVector(-0.375f, -0.197512f, 5.889502f), MAPVector(-0.375f, -0.831379f, 5.312123f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[58]);
		newTri[59] = new VMFTri(MAPVector(-0.375f, -0.197512f, 6.379961f), MAPVector(-0.375f, -0.831379f, 5.312123f), MAPVector(-0.497904f, -1.248534f, 5.767931f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[59]);
		newTri[60] = new VMFTri(MAPVector(-0.375f, 0.435391f, 5.889502f), MAPVector(0.375f, 0.435391f, 5.889502f), MAPVector(0.375f, -0.197512f, 5.889502f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[60]);
		newTri[61] = new VMFTri(MAPVector(-0.375f, 0.435391f, 5.889502f), MAPVector(0.375f, -0.197512f, 5.889502f), MAPVector(-0.375f, -0.197512f, 5.889502f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[61]);
		newTri[62] = new VMFTri(MAPVector(-0.375f, 0.435391f, 6.379961f), MAPVector(-0.375f, 0.435391f, 5.889502f), MAPVector(-0.375f, -0.197512f, 5.889502f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[62]);
		newTri[63] = new VMFTri(MAPVector(-0.375f, 0.435391f, 6.379961f), MAPVector(-0.375f, -0.197512f, 5.889502f), MAPVector(-0.375f, -0.197512f, 6.379961f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[63]);
		newTri[64] = new VMFTri(MAPVector(0.375f, 0.435391f, 6.379961f), MAPVector(-0.375f, 0.435391f, 6.379961f), MAPVector(-0.375f, -0.197512f, 6.379961f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), 0);
		newTempBrush->triangles.push_back(newTri[64]);
		newTri[65] = new VMFTri(MAPVector(0.375f, 0.435391f, 6.379961f), MAPVector(-0.375f, -0.197512f, 6.379961f), MAPVector(0.375f, -0.197512f, 6.379961f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), 0);
newTempBrush->triangles.push_back(newTri[65]);
newTri[66] = new VMFTri(MAPVector(-0.375f, -0.831379f, 5.312123f), MAPVector(0.375f, -0.831379f, 5.312123f), MAPVector(0.252097f, -1.248534f, 5.767931f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), 0);
newTempBrush->triangles.push_back(newTri[66]);
newTri[67] = new VMFTri(MAPVector(-0.375f, -0.831379f, 5.312123f), MAPVector(0.252097f, -1.248534f, 5.767931f), MAPVector(-0.497904f, -1.248534f, 5.767931f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), 0);
newTempBrush->triangles.push_back(newTri[67]);
newTri[68] = new VMFTri(MAPVector(0.375f, -0.197512f, 6.379961f), MAPVector(-0.375f, -0.197512f, 6.379961f), MAPVector(-0.497904f, -1.248534f, 5.767931f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), 0);
newTempBrush->triangles.push_back(newTri[68]);
newTri[69] = new VMFTri(MAPVector(0.375f, -0.197512f, 6.379961f), MAPVector(-0.497904f, -1.248534f, 5.767931f), MAPVector(0.252097f, -1.248534f, 5.767931f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), 0);
newTempBrush->triangles.push_back(newTri[69]);
newTri[70] = new VMFTri(MAPVector(0.375f, -0.197512f, 5.889502f), MAPVector(0.375f, -0.197512f, 6.379961f), MAPVector(0.252097f, -1.248534f, 5.767931f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), 0);
newTempBrush->triangles.push_back(newTri[70]);
newTri[71] = new VMFTri(MAPVector(0.375f, -0.197512f, 5.889502f), MAPVector(0.252097f, -1.248534f, 5.767931f), MAPVector(0.375f, -0.831379f, 5.312123f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), 0);
newTempBrush->triangles.push_back(newTri[71]);
newTri[72] = new VMFTri(MAPVector(-0.375f, -0.197512f, 5.889502f), MAPVector(0.375f, -0.197512f, 5.889502f), MAPVector(0.375f, -0.831379f, 5.312123f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), 0);
newTempBrush->triangles.push_back(newTri[72]);
newTri[73] = new VMFTri(MAPVector(-0.375f, -0.197512f, 5.889502f), MAPVector(0.375f, -0.831379f, 5.312123f), MAPVector(-0.375f, -0.831379f, 5.312123f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), 0);
newTempBrush->triangles.push_back(newTri[73]);
newTri[74] = new VMFTri(MAPVector(0.375f, 0.375f, 0.879993f), MAPVector(0.375f, -0.375f, 0.879993f), MAPVector(0.375f, -0.375f, -0.019767f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), 0);
newTempBrush->triangles.push_back(newTri[74]);
newTri[75] = new VMFTri(MAPVector(0.375f, 0.375f, 0.879993f), MAPVector(0.375f, -0.375f, -0.019767f), MAPVector(0.375f, 0.375f, -0.019767f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), 0);
newTempBrush->triangles.push_back(newTri[75]);
newTri[76] = new VMFTri(MAPVector(-0.375f, 0.375f, 0.879993f), MAPVector(-0.375f, -0.375f, 0.879993f), MAPVector(0.375f, -0.375f, 0.879993f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), 0);
newTempBrush->triangles.push_back(newTri[76]);
newTri[77] = new VMFTri(MAPVector(-0.375f, 0.375f, 0.879993f), MAPVector(0.375f, -0.375f, 0.879993f), MAPVector(0.375f, 0.375f, 0.879993f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), 0);
newTempBrush->triangles.push_back(newTri[77]);
newTri[78] = new VMFTri(MAPVector(-0.375f, 0.375001f, 1.774594f), MAPVector(0.375f, 0.375001f, 1.774594f), MAPVector(0.375f, -0.375f, 1.774594f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), 0);
newTempBrush->triangles.push_back(newTri[78]);
newTri[79] = new VMFTri(MAPVector(-0.375f, 0.375001f, 1.774594f), MAPVector(0.375f, -0.375f, 1.774594f), MAPVector(-0.375f, -0.375f, 1.774594f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), 0);
newTempBrush->triangles.push_back(newTri[79]);
newTri[80] = new VMFTri(MAPVector(-0.375f, -0.375f, -0.019767f), MAPVector(-0.375f, 0.375f, -0.019767f), MAPVector(0.375f, 0.375f, -0.019767f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), 0);
newTempBrush->triangles.push_back(newTri[80]);
newTri[81] = new VMFTri(MAPVector(-0.375f, -0.375f, -0.019767f), MAPVector(0.375f, 0.375f, -0.019767f), MAPVector(0.375f, -0.375f, -0.019767f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), 0);
newTempBrush->triangles.push_back(newTri[81]);
newTri[82] = new VMFTri(MAPVector(-0.375f, -0.375f, 0.879993f), MAPVector(-0.375f, 0.375f, 0.879993f), MAPVector(-0.375f, 0.375f, -0.019767f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), 0);
newTempBrush->triangles.push_back(newTri[82]);
newTri[83] = new VMFTri(MAPVector(-0.375f, -0.375f, 0.879993f), MAPVector(-0.375f, 0.375f, -0.019767f), MAPVector(-0.375f, -0.375f, -0.019767f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), 0);
newTempBrush->triangles.push_back(newTri[83]);
newTri[84] = new VMFTri(MAPVector(0.375f, -0.375f, 0.879993f), MAPVector(-0.375f, -0.375f, 0.879993f), MAPVector(-0.375f, -0.375f, -0.019767f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), 0);
newTempBrush->triangles.push_back(newTri[84]);
newTri[85] = new VMFTri(MAPVector(0.375f, -0.375f, 0.879993f), MAPVector(-0.375f, -0.375f, -0.019767f), MAPVector(0.375f, -0.375f, -0.019767f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), 0);
newTempBrush->triangles.push_back(newTri[85]);
newTri[86] = new VMFTri(MAPVector(-0.375f, 0.375f, 0.879993f), MAPVector(0.375f, 0.375f, 0.879993f), MAPVector(0.375f, 0.375f, -0.019767f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), 0);
newTempBrush->triangles.push_back(newTri[86]);
newTri[87] = new VMFTri(MAPVector(-0.375f, 0.375f, 0.879993f), MAPVector(0.375f, 0.375f, -0.019767f), MAPVector(-0.375f, 0.375f, -0.019767f), MAPVector2D(1, 0), MAPVector2D(1, 1), MAPVector2D(0, 1), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), MAPColor(255, 0, 0, 255), 0);
newTempBrush->triangles.push_back(newTri[87]);
	}

	for (int i = 0; i < newTri.size(); i++)
	{
		newTri[i]->v1 *= HammUErSettings::scaleUnknownModels;
		newTri[i]->v2 *= HammUErSettings::scaleUnknownModels;
		newTri[i]->v3 *= HammUErSettings::scaleUnknownModels;
	}

	FVector nowhere = FVector::ZeroVector;
	// did we generate this before? If not, generate one.
	// this reuses the first one ever generated this session, but it's not really that important, is it?
	if (debugPropMaterial == NULL)
	{
		// generate a debug material that grabs vertex color
		FString NewPackageName = TEXT("/Game/") + (importDirectory != "" ? importDirectory + "/Meshes/" : "Meshes/") + "Models/M_missingPropMaterial";
		UPackage* matPackage = CreatePackage(NULL, *NewPackageName);
		matPackage->FullyLoad();
		matPackage->Modify();

		auto MaterialFactory = NewObject<UMaterialFactoryNew>();

		UMaterial* newMaterial = (UMaterial*)MaterialFactory->FactoryCreateNew(UMaterial::StaticClass(), matPackage, FName("M_missingPropMaterial"), RF_Public | RF_Standalone, NULL, GWarn);
		FAssetRegistryModule::AssetCreated(newMaterial);
		UMaterialExpressionVertexColor* UVC = NewObject<UMaterialExpressionVertexColor>(newMaterial);
		newMaterial->Expressions.Add(UVC);
		newMaterial->BaseColor.Expression = UVC;
		TArray<FExpressionOutput> outputs = newMaterial->BaseColor.Expression->GetOutputs();
		FExpressionOutput* output = outputs.GetData();
		newMaterial->BaseColor.Mask = output->Mask;
		newMaterial->BaseColor.MaskR = output->MaskR;
		newMaterial->BaseColor.MaskG = output->MaskG;
		newMaterial->BaseColor.MaskB = output->MaskB;
		newMaterial->BaseColor.MaskA = output->MaskA;
		newMaterial->PostEditChange();
		FString PackageFileName = FPackageName::LongPackageNameToFilename(NewPackageName, FPackageName::GetAssetPackageExtension());
		if (HammUErSettings::generateThumbs)
			ThumbnailTools::GenerateThumbnailForObjectToSaveToDisk(newMaterial);
		UPackage::SavePackage(matPackage, newMaterial, RF_Public | RF_Standalone, *PackageFileName, GError, nullptr, false, true, SAVE_NoError);
		debugPropMaterial = (UMaterialInterface*)newMaterial;
	}
	TArray<UMaterialInterface*> nothing;
	nothing.Add(debugPropMaterial);
	UStaticMesh* myResult = ImportBrush(newTempBrush, nothing, nowhere, true, false);
	newTempBrush->triangles.clear();
	for (int i = 0; i < newTri.size(); i++)
	{
		delete newTri[i];
	}
	newTri.clear();
	HammUErSettings::CenterCheckboxEnabled = oldCenter;
	delete newTempBrush;
	return myResult;
}


