// Copyright Low Entry. All Rights Reserved.

#pragma once


#include "CoreMinimal.h"

#include "LatentActions.h"

#include "LowEntryHttpRequest.h"


class FLowEntryHttpRequestExecutionAction : public FPendingLatentAction
{
public:
	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;

	FString Url = TEXT("");
	bool Done = false;
	ULowEntryHttpRequest* HttpRequest;
	ULowEntryHttpRequestResponse*& HttpResponse;

	FLowEntryHttpRequestExecutionAction(const FLatentActionInfo& LatentInfo, const FString& RequestingUrl, ULowEntryHttpRequest* HttpRequest0, ULowEntryHttpRequestResponse*& HttpResponse0)
		: ExecutionFunction(LatentInfo.ExecutionFunction)
		, OutputLink(LatentInfo.Linkage)
		, CallbackTarget(LatentInfo.CallbackTarget)
		, HttpResponse(HttpResponse0)
	{
		Url = RequestingUrl;
		HttpRequest = HttpRequest0;
	}

	virtual ~FLowEntryHttpRequestExecutionAction() override
	{
		if(!Done)
		{
			if((HttpRequest != nullptr) && HttpRequest->IsValidLowLevel() && !HttpRequest->IsPendingKill())
			{
				Done = true;
				HttpRequest->ExecutionActionIsDone();
			}
		}
	}

	void UpdateOperation(FLatentResponse& Response)
	{
		if((HttpRequest == nullptr) || !HttpRequest->IsValidLowLevel() || HttpRequest->IsPendingKill())
		{
			Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
			return;
		}
		if(Done)
		{
			HttpRequest->ExecutionActionIsDone();
			Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
		}
	}

	void Finish()
	{
		Done = true;
	}

#if WITH_EDITOR
	// Returns a human readable description of the latent operation's current state
	virtual FString GetDescription() const override
	{
		if(Url.Len() > 0)
		{
			return TEXT("Waiting for server response from \"") + Url + TEXT("\"");
		}
		return TEXT("Waiting for server response");
	}
#endif
};
