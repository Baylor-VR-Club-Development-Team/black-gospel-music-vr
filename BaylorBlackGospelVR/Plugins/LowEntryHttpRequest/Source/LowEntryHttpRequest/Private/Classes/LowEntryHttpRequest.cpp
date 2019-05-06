// Copyright Low Entry. All Rights Reserved.

#include "LowEntryHttpRequest.h"
#include "LowEntryHttpRequestResponse.h"
#include "FLowEntryHttpRequestExecutionAction.h"


// init >>
	ULowEntryHttpRequest::ULowEntryHttpRequest(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
	{
		HttpRequest->SetHeader(TEXT("Content-Type"), TEXT("text/plain"));
	}

	ULowEntryHttpRequest* ULowEntryHttpRequest::Create()
	{
		return NewObject<ULowEntryHttpRequest>();
	}
// init <<


void ULowEntryHttpRequest::SetUrl(const ELowEntryHttpRequestType Type, const FString& Url)
{
	HttpRequest->SetVerb(ELowEntryHttpRequestTypes[(int32) Type]);
	HttpRequest->SetURL(Url);
}

void ULowEntryHttpRequest::SetUrlCustomType(const FString& Type, const FString& Url)
{
	HttpRequest->SetVerb(Type.ToUpper());
	HttpRequest->SetURL(Url);
}

void ULowEntryHttpRequest::SetUrlParameter(const FString& Key, const FString& Value)
{
	UrlParameters.Add(Key, Value);
}

void ULowEntryHttpRequest::SetHeader(const FString& Key, const FString& Value)
{
	HttpRequest->SetHeader(Key, Value);
}


void ULowEntryHttpRequest::SetContent(const TArray<uint8>& Data)
{
	HttpRequest->SetContent(Data);
	ContentStringParameters.Empty();
	JsonData = false;
}

void ULowEntryHttpRequest::SetContentAsString(const FString& Data)
{
	HttpRequest->SetContentAsString(Data);
	ContentStringParameters.Empty();
	JsonData = false;
}

void ULowEntryHttpRequest::SetContentAsJsonString(const FString& Data)
{
	HttpRequest->SetContentAsString(Data);
	ContentStringParameters.Empty();
	JsonData = true;
}

void ULowEntryHttpRequest::SetContentAsStringParameters(const FString& Key, const FString& Value)
{
	ContentStringParameters.Add(Key, Value);
	JsonData = false;
}


void ULowEntryHttpRequest::ExecuteRequest(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ULowEntryHttpRequestResponse*& Response)
{
	if(IsExecutingRequest())
	{
		Response = ExecutionResponse;
		return;
	}

	Response = ULowEntryHttpRequestResponse::Create();

	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
	if(World == nullptr)
	{
		return;
	}
	if(World->GetLatentActionManager().FindExistingAction<FLowEntryHttpRequestExecutionAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) != NULL)
	{
		return;
	}

	FString Url = GetUrlWithUrlParameters();
	HttpRequest->SetURL(Url);

	if(ContentStringParameters.Num() > 0)
	{
		HttpRequest->SetHeader(TEXT("Content-Type"), TEXT("application/x-www-form-urlencoded"));
		HttpRequest->SetContentAsString(GetContentAsStringParameters());
	}

	if(JsonData)
	{
		HttpRequest->SetHeader(TEXT("Content-Type"), TEXT("application/json;charset=utf-8"));
	}

	KeepAliveCount++;
	if(KeepAliveCount == 1)
	{
		AddToRoot();
	}

	BytesToSend = HttpRequest->GetContentLength();
	BytesSent = 0;
	BytesToReceive = 0;
	BytesReceived = 0;

	ExecutionResponse = Response;
	Execution = new FLowEntryHttpRequestExecutionAction(LatentInfo, Url, this, Response);
	World->GetLatentActionManager().AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, Execution);

	HttpRequest->OnProcessRequestComplete().BindUObject(this, &ULowEntryHttpRequest::OnExecuteRequestCompleted);
	HttpRequest->OnRequestProgress().BindUObject(this, &ULowEntryHttpRequest::OnExecuteRequestProgress);
	HttpRequest->ProcessRequest();
}

void ULowEntryHttpRequest::OnExecuteRequestCompleted(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
	BytesSent = BytesToSend;
	BytesReceived = BytesToReceive;

	if(ExecutionResponse != nullptr)
	{
		ExecutionResponse->SetResponse(Response);
		ExecutionResponse->SetWasSuccessful(bWasSuccessful);
		//ExecutionResponse = NULL;

		if(Execution != nullptr)
		{
			Execution->Finish();
		}
	}
	else
	{
		ExecutionActionIsDone();
	}
}

void ULowEntryHttpRequest::ExecutionActionIsDone()
{
	if(Execution != nullptr)
	{
		Execution->HttpResponse = ExecutionResponse;
		ExecutionResponse = NULL;

		Execution = NULL;

		KeepAliveCount--;
		if(KeepAliveCount == 0)
		{
			RemoveFromRoot();
		}
		if(KeepAliveCount < 0)
		{
			KeepAliveCount = 0;
		}
	}
}


void ULowEntryHttpRequest::ExecuteRequestEvent(const FDelegateULowEntryHttpRequestOnComplete OnComplete)
{
	ExecutionEvent = OnComplete;

	if(IsExecutingRequest())
	{
		return;
	}

	ExecutionResponse = ULowEntryHttpRequestResponse::Create();

	FString Url = GetUrlWithUrlParameters();
	HttpRequest->SetURL(Url);

	if(ContentStringParameters.Num() > 0)
	{
		HttpRequest->SetHeader(TEXT("Content-Type"), TEXT("application/x-www-form-urlencoded"));
		HttpRequest->SetContentAsString(GetContentAsStringParameters());
	}

	if(JsonData)
	{
		HttpRequest->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
	}

	KeepAliveCount++;
	if(KeepAliveCount == 1)
	{
		AddToRoot();
	}

	BytesToSend = HttpRequest->GetContentLength();
	BytesSent = 0;
	BytesToReceive = 0;
	BytesReceived = 0;

	HttpRequest->OnProcessRequestComplete().BindUObject(this, &ULowEntryHttpRequest::OnExecuteRequestCompletedEvent);
	HttpRequest->OnRequestProgress().BindUObject(this, &ULowEntryHttpRequest::OnExecuteRequestProgress);
	HttpRequest->ProcessRequest();
}

void ULowEntryHttpRequest::OnExecuteRequestCompletedEvent(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
	BytesSent = BytesToSend;
	BytesReceived = BytesToReceive;

	if(ExecutionResponse != nullptr)
	{
		ExecutionResponse->SetResponse(Response);
		ExecutionResponse->SetWasSuccessful(bWasSuccessful);
		//ExecutionResponse = NULL;
	}

	KeepAliveCount--;
	if(KeepAliveCount == 0)
	{
		RemoveFromRoot();
	}
	if(KeepAliveCount < 0)
	{
		KeepAliveCount = 0;
	}

	if(ExecutionResponse != nullptr)
	{
		ExecutionEvent.ExecuteIfBound(ExecutionResponse);
	}
}


void ULowEntryHttpRequest::OnExecuteRequestProgress(FHttpRequestPtr Request, int32 NewBytesSent, int32 NewBytesReceived)
{
	BytesSent = NewBytesSent;
	BytesReceived = NewBytesReceived;

	if(Request.IsValid() && Request->GetResponse().IsValid())
	{
		BytesToReceive = Request->GetResponse()->GetContentLength();
	}
}


void ULowEntryHttpRequest::CancelRequest()
{
	HttpRequest->CancelRequest();
}

bool ULowEntryHttpRequest::IsExecutingRequest()
{
	return (Execution != nullptr);
}


FString ULowEntryHttpRequest::GetUrlWithUrlParameters()
{
	FString Url = HttpRequest->GetURL();

	if(UrlParameters.Num() <= 0)
	{
		return Url;
	}

	int32 LastSlash;
	int32 LastQuestionMark;
	Url.FindLastChar('/', LastSlash);
	Url.FindLastChar('?', LastQuestionMark);

	if((LastQuestionMark <= -1) || (LastQuestionMark < LastSlash)) // ? is missing
	{
		if(UrlParameters.Num() > 0)
		{
			Url += '?';
		}
	}

	if(!Url.EndsWith(TEXT("?")) && !Url.EndsWith(TEXT("&"))) // last character is not a ? or &
	{
		Url += '&';
	}

	for(const auto& Entry : UrlParameters)
	{
		if(Entry.Key.Len() > 0)
		{
			Url += FGenericPlatformHttp::UrlEncode(Entry.Key);
			Url += '=';
			Url += FGenericPlatformHttp::UrlEncode(Entry.Value);
			Url += '&';
		}
	}

	if(Url.EndsWith(TEXT("&")))
	{
		Url.RemoveFromEnd(TEXT("&"));
	}

	return Url;
}

FString ULowEntryHttpRequest::GetContentAsStringParameters()
{
	FString Content;

	if(ContentStringParameters.Num() <= 0)
	{
		return Content;
	}

	for(const auto& Entry : ContentStringParameters)
	{
		if(Entry.Key.Len() > 0)
		{
			Content += FGenericPlatformHttp::UrlEncode(Entry.Key);
			Content += '=';
			Content += FGenericPlatformHttp::UrlEncode(Entry.Value);
			Content += '&';
		}
	}

	if(Content.EndsWith(TEXT("&")))
	{
		Content.RemoveFromEnd(TEXT("&"));
	}

	return Content;
}


int32 ULowEntryHttpRequest::GetBytesToSend()
{
	return BytesToSend;
}

int32 ULowEntryHttpRequest::GetBytesSent()
{
	if(BytesSent >= BytesToSend)
	{
		return BytesToSend;
	}
	return BytesSent;
}

int32 ULowEntryHttpRequest::GetBytesToReceive()
{
	return BytesToReceive;
}

int32 ULowEntryHttpRequest::GetBytesReceived()
{
	if(BytesReceived >= BytesToReceive)
	{
		return BytesToReceive;
	}
	return BytesReceived;
}

float ULowEntryHttpRequest::GetSentPercentage()
{
	if(BytesToSend <= 0)
	{
		return 1.0;
	}
	if(BytesSent >= BytesToSend)
	{
		return 1.0;
	}
	return (((float)BytesSent) / ((float)BytesToSend));
}

float ULowEntryHttpRequest::GetReceivedPercentage()
{
	if(BytesToReceive <= 0)
	{
		return 1.0;
	}
	if(BytesReceived >= BytesToReceive)
	{
		return 1.0;
	}
	return (((float) BytesReceived) / ((float) BytesToReceive));
}
