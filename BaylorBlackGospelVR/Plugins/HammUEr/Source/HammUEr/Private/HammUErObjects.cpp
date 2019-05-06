// HammUEr
// Copyright 2015-2016 Turfster / NT Entertainment
// All Rights Reserved.


// This code is held together with kitten whiskers and toothpicks.
// There's nothing to see or learn here.
// Seriously.
// Turn back.

#include "HammUErPrivatePCH.h"
#include "HammUErObjects.h"
#include "HammUErRuntimeClasses.h"
#include "Runtime/Launch/Resources/Version.h" 

class FHammuerPathProxy : public FPrimitiveSceneProxy
{
public:
	FHammuerPathProxy(UHammuerPathComponent* Component)
		:FPrimitiveSceneProxy(Component)
	{
		myOwner = Cast<AHammuerPathNode>(Component->GetOwner());
	}

	virtual void GetDynamicMeshElements(const TArray<const FSceneView*>& Views, const FSceneViewFamily& ViewFamily, uint32 VisibilityMap, FMeshElementCollector& Collector) const override
	{
		if (myOwner->CanDraw())
		{
			FVector startLocation = myOwner->GetActorLocation();
			FVector endLocation = myOwner->nextTarget->GetActorLocation();
			static const FLinearColor RadiusColor = FLinearColor(FColorList::Orange);
			for (int32 ViewIndex = 0; ViewIndex < Views.Num(); ViewIndex++)
			{
				if (VisibilityMap & (1 << ViewIndex))
				{
					FPrimitiveDrawInterface* PDI = Collector.GetPDI(ViewIndex);

					PDI->DrawLine(startLocation, endLocation, myOwner->pathColor, SDPG_World, myOwner->pathThickness);
					DrawArrowHead(PDI, startLocation, endLocation, 10.f, myOwner->pathColor, SDPG_World, myOwner->pathThickness);
				}
			}
		}
	}

#if ENGINE_MINOR_VERSION>=11
	virtual FPrimitiveViewRelevance GetViewRelevance(const FSceneView* View) const override
	{
		FPrimitiveViewRelevance Result;
		Result.bDrawRelevance = IsShown(View);
		Result.bDynamicRelevance = true;
		Result.bSeparateTranslucencyRelevance = Result.bNormalTranslucencyRelevance = IsShown(View);
		return Result;
	}
#else
	virtual FPrimitiveViewRelevance GetViewRelevance(const FSceneView* View) override
	{
		FPrimitiveViewRelevance Result;
		Result.bDrawRelevance = IsShown(View);
		Result.bDynamicRelevance = true;
		Result.bSeparateTranslucencyRelevance = Result.bNormalTranslucencyRelevance = IsShown(View);
		return Result;
	}

#endif

	virtual uint32 GetMemoryFootprint(void) const override { return(sizeof(*this) + GetAllocatedSize()); }
	uint32 GetAllocatedSize(void) const { return FPrimitiveSceneProxy::GetAllocatedSize(); }

	AHammuerPathNode* myOwner;
};

UHammuerPathComponent::UHammuerPathComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{

	SetCollisionProfileName(UCollisionProfile::NoCollision_ProfileName);
	bHiddenInGame = true;
	bUseEditorCompositing = true;
	SetGenerateOverlapEvents(false);
}

FPrimitiveSceneProxy* UHammuerPathComponent::CreateSceneProxy()
{
	FHammuerPathProxy* newPathProxy = nullptr;

	return newPathProxy;
	//return new FHammuerPathProxy(this);
}


FBoxSphereBounds UHammuerPathComponent::CalcBounds(const FTransform& LocalToWorld) const
{
	const AHammuerPathNode* Owner = Cast<AHammuerPathNode>(GetOwner());
	if (Owner)
	{
		FBox BoundingBox(Owner->GetActorLocation() - FVector(5, 5, 5),		// basically a small box around the point.
			Owner->GetActorLocation() + FVector(5, 5, 5));
		if (Owner->nextTarget)
		{
			FVector tempBB = Owner->nextTarget->GetActorLocation();
			if (!tempBB.ContainsNaN())
				BoundingBox += tempBB;
		}
		return FBoxSphereBounds(BoundingBox);
	}

	return FBoxSphereBounds(EForceInit::ForceInitToZero);
}


AHammuerPathNode::AHammuerPathNode(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
	if (WITH_EDITOR)
	{
		PrimaryActorTick.bCanEverTick = true;
		PrimaryActorTick.bStartWithTickEnabled = true;
	}
	pathColor = FColor(255, 0, 0, 255);
	pathThickness = 3.f;
	myPathComponent = CreateEditorOnlyDefaultSubobject<UHammuerPathComponent>(TEXT("MyPathComponent"));
}

void AHammuerPathNode::Tick(float DeltaTime)
{
	myPathComponent->MarkRenderStateDirty();// keep updating, otherwise nothing gets drawn
}

bool AHammuerPathNode::ShouldTickIfViewportsOnly() const
{
	return true;
}

