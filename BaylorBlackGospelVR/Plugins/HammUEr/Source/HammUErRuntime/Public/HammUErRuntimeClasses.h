#pragma once
#include "HammUErInterfaces.h"
#include "Runtime/Launch/Resources/Version.h" 
#include "HammUErRuntimeClasses.generated.h"

USTRUCT(BlueprintType)
struct HAMMUERRUNTIME_API FHammuerOutput
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HammUEr")
		FString outputName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HammUEr")
		FString targetEntity;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HammUEr")
		FString targetInput;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HammUEr")
		FString parameter;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HammUEr")
		float delay;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HammUEr")
		bool onlyOnce;

	bool isActive = false;
	float startTime;

};

UCLASS(Blueprintable, BlueprintType)
class HAMMUERRUNTIME_API AHammuerLogicActorBase : public AActor, public IHammuerLogicInterface
{
	GENERATED_BODY()

public:

	AHammuerLogicActorBase();

	UFUNCTION(BlueprintCallable, Category = "HammUEr Logic")
	bool FindTargetEntities(FHammuerOutput inputOutput);

	UFUNCTION(BlueprintCallable, Category = "HammUEr Logic")
	void ExecuteAll();

	UFUNCTION(BlueprintCallable, Category = "HammUEr Logic")
	void ExecuteOutput(int index);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "HammUEr Logic")
	void DoExecute(AHammuerLogicActorBase* myTarget, int index);

	UFUNCTION(BlueprintCallable, Category = "HammUEr Logic")
	FString GetFriendlyName() override;
	void SetFriendlyName(FString inName);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HammUEr")
	TArray<FHammuerOutput> myOutputs;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HammUEr")
	bool doVerbose = false;

	UPROPERTY(BlueprintReadOnly, Category = "HammUEr")// moved this here because if I kept it just in the private part, UE would reset everything to unnamed?
	FString friendlyName = "unnamed";

private:
	TArray<AHammuerLogicActorBase*> targets;
	
};

UCLASS(Blueprintable, BlueprintType)
class HAMMUERRUNTIME_API AHammuerLogicAuto : public AHammuerLogicActorBase
{
	GENERATED_BODY()

public:
	AHammuerLogicAuto();

};

UCLASS(Blueprintable, BlueprintType)
class HAMMUERRUNTIME_API AHammuerLogicRelay : public AHammuerLogicActorBase
{
	GENERATED_BODY()
public:
	AHammuerLogicRelay();

	UFUNCTION(BlueprintCallable, Category = "HammUEr Logic")
	void Enable()
	{
		isDisabled = false;
	}

	UFUNCTION(BlueprintCallable, Category = "HammUEr Logic")
	void Disable()
	{
		isDisabled = true;
	}

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "HammUEr Logic")
	void Trigger();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HammUEr")
	bool isDisabled = false;
};

UCLASS(Blueprintable, BlueprintType)
class HAMMUERRUNTIME_API AHammuerFuncBrushActor : public AHammuerLogicActorBase
{
	GENERATED_BODY()
public:

	AHammuerFuncBrushActor();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* myStaticMeshComponent;

	void SetMesh(UStaticMesh* newMesh)
	{
		if (myStaticMeshComponent)
		{
#if ENGINE_MINOR_VERSION<14
			myStaticMeshComponent->StaticMesh = newMesh;
#else
			myStaticMeshComponent->SetStaticMesh(newMesh);
#endif
		}
	}

	void SetSolidity(int solidity)
	{
		if (myStaticMeshComponent)
		{
			switch (solidity)
			{
			case 0:myStaticMeshComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
				break;
			case 1:myStaticMeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
				break;
			case 2:myStaticMeshComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
				break;
			}
		}
	}

	void StartDisabled(bool startDisabled)
	{
		this->SetActorHiddenInGame(startDisabled);
	}

	void SetShadows(bool shadows)
	{
		if (myStaticMeshComponent)
			myStaticMeshComponent->SetCastShadow(shadows);
	}

};