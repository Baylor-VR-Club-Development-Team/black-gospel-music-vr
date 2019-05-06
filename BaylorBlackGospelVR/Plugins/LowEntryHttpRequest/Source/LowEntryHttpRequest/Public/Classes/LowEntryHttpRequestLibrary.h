// Copyright Low Entry. All Rights Reserved.

#pragma once


#include "CoreMinimal.h"

#include "Kismet/BlueprintFunctionLibrary.h"

#include "LowEntryHttpRequestLibrary.generated.h"


class ULowEntryHttpRequest;


UCLASS()
class LOWENTRYHTTPREQUEST_API ULowEntryHttpRequestLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()


public: // Request
	/**
	* Creates a new HTTP Request.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Http Request|Request", Meta = (DisplayName = "Create (Http Request)"))
		static ULowEntryHttpRequest* Request_Create();
};
