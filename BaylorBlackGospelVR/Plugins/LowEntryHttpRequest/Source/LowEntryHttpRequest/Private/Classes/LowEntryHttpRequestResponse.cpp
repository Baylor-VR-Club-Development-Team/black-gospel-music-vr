// Copyright Low Entry. All Rights Reserved.

#include "LowEntryHttpRequestResponse.h"


// init >>
	ULowEntryHttpRequestResponse::ULowEntryHttpRequestResponse(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
	{
	}

	ULowEntryHttpRequestResponse* ULowEntryHttpRequestResponse::Create()
	{
		return NewObject<ULowEntryHttpRequestResponse>();
	}

	ULowEntryHttpRequestResponse* ULowEntryHttpRequestResponse::Create(const FHttpResponsePtr Response)
	{
		ULowEntryHttpRequestResponse* Instance = NewObject<ULowEntryHttpRequestResponse>();
		Instance->Response = Response;
		return Instance;
	}
// init <<


void ULowEntryHttpRequestResponse::SetResponse(const FHttpResponsePtr NewResponse)
{
	Response = NewResponse;
}


void ULowEntryHttpRequestResponse::WasSuccessful(ELowEntryHttpRequestSuccess& Branch)
{
	if(Successful)
	{
		Branch = ELowEntryHttpRequestSuccess::Success;
	}
	else
	{
		Branch = ELowEntryHttpRequestSuccess::Failed;
	}
}

bool ULowEntryHttpRequestResponse::GetWasSuccessful()
{
	return Successful;
}

void ULowEntryHttpRequestResponse::SetWasSuccessful(const bool WasSuccessful)
{
	Successful = WasSuccessful;
}


int32 ULowEntryHttpRequestResponse::GetResponseCode()
{
	if(!Response.IsValid())
	{
		return -1;
	}
	return Response->GetResponseCode();
}


FString ULowEntryHttpRequestResponse::GetUrl()
{
	if(!Response.IsValid())
	{
		return TEXT("");
	}
	return Response->GetURL();
}


TArray<uint8> ULowEntryHttpRequestResponse::GetContent()
{
	if(!Response.IsValid())
	{
		return TArray<uint8>();
	}
	return Response->GetContent();
}

FString ULowEntryHttpRequestResponse::GetContentAsString()
{
	if(!Response.IsValid())
	{
		return TEXT("");
	}
	return Response->GetContentAsString();
}

int32 ULowEntryHttpRequestResponse::GetContentLength()
{
	if(!Response.IsValid())
	{
		return -1;
	}
	return Response->GetContentLength();
}

FString ULowEntryHttpRequestResponse::GetContentType()
{
	if(!Response.IsValid())
	{
		return TEXT("");
	}
	return Response->GetContentType();
}


FString ULowEntryHttpRequestResponse::GetHeader(const FString& Key)
{
	if(!Response.IsValid())
	{
		return TEXT("");
	}
	return Response->GetHeader(Key);
}

TArray<FString> ULowEntryHttpRequestResponse::GetAllHeaders()
{
	if(!Response.IsValid())
	{
		return TArray<FString>();
	}
	return Response->GetAllHeaders();
}
