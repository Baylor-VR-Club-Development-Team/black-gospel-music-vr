// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BackendManagerFunctionLibrary.generated.h"
#include "../backendManager.h"

/**
 * 
 */
UCLASS()
class BAYLORBLACKGOSPELVR_API UBackendManagerFunctionLibrary : public UBlueprintFunctionLibrary
{
    public:
	    GENERATED_BODY()
	    UFUNCTION(BlueprintCallable, Category="Backend")
        static void getRecord(int id);
};
