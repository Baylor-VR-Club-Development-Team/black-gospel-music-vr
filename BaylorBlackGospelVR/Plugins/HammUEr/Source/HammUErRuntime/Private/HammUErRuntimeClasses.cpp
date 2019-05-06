#include "HammUErRuntimePrivatePCH.h"
#include "../Public/HammUErRuntime.h"
#include "../Public/HammUErRuntimeClasses.h"

AHammuerLogicActorBase::AHammuerLogicActorBase()
{
	PrimaryActorTick.bCanEverTick = true;
	
}

AHammuerLogicAuto::AHammuerLogicAuto()
{
	PrimaryActorTick.bCanEverTick = true;
}

AHammuerLogicRelay::AHammuerLogicRelay()
{
	PrimaryActorTick.bCanEverTick = true;
}

AHammuerFuncBrushActor::AHammuerFuncBrushActor()
{
	PrimaryActorTick.bCanEverTick = true;
	myStaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Func Brush"));
	RootComponent = myStaticMeshComponent;
}

bool AHammuerLogicActorBase::FindTargetEntities(FHammuerOutput inputOutput)
{
	targets.Empty();
	for (TObjectIterator<AHammuerLogicActorBase> Itr; Itr; ++Itr) // does this work?
	{
		FString toCheck = Itr->GetFriendlyName();//Itr->GetActorLabel();
		if (toCheck == inputOutput.targetEntity)
			targets.Add(*Itr);
	}
	return (targets.Num() != 0);
}

void AHammuerLogicActorBase::ExecuteAll()
{
	for (int i = 0; i < myOutputs.Num(); i++)
		ExecuteOutput(i);
}

FString AHammuerLogicActorBase::GetFriendlyName()
{
	return friendlyName;
}

void AHammuerLogicActorBase::SetFriendlyName(FString inName)
{
	friendlyName = inName;
}

void AHammuerLogicActorBase::ExecuteOutput(int index)
{
	if (FindTargetEntities(myOutputs[index]))
	{
		for (int i = 0; i < targets.Num(); i++)
		{
			if (doVerbose)
				UE_LOG(LogTemp, Log, TEXT("%s executing output %i for %s"), *(this->GetFriendlyName()), index, *(targets[i]->GetFriendlyName()));// *(this->GetActorLabel()), index, *(targets[i]->GetActorLabel()));
			DoExecute(targets[i], index);
		}
		targets.Empty();
	}
}

void AHammuerLogicActorBase::DoExecute_Implementation(AHammuerLogicActorBase* myTarget, int index)
{
	UE_LOG(LogTemp, Error, TEXT("Implement me in BP since C++ timers are hell"));
}

void AHammuerLogicRelay::Trigger_Implementation()	
{
	if (doVerbose)
	UE_LOG(LogTemp, Log, TEXT("TRIGGER signal received, %s"), *this->GetFriendlyName());

	if (!isDisabled)
		ExecuteAll();
}
