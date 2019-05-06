// Copyright Low Entry. All Rights Reserved.

#pragma once


#include "CoreMinimal.h"
#include "CoreUObject.h"

#include "Engine/Engine.h"

#include "Http.h"
#include "DelayAction.h"

#include "ELowEntryHttpRequestType.h"

#include "LowEntryHttpRequest.generated.h"


class ULowEntryHttpRequestResponse;
class FLowEntryHttpRequestExecutionAction;


DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegateULowEntryHttpRequestOnComplete, ULowEntryHttpRequestResponse*, Response);


UCLASS(BlueprintType)
class LOWENTRYHTTPREQUEST_API ULowEntryHttpRequest : public UObject
{
	GENERATED_UCLASS_BODY()


public:
	static ULowEntryHttpRequest* Create();


public:
	FHttpRequestPtr HttpRequest = FHttpModule::Get().CreateRequest();
	UPROPERTY()
	TMap<FString, FString> UrlParameters;
	UPROPERTY()
	TMap<FString, FString> ContentStringParameters;
	UPROPERTY()
	bool JsonData = false;

	UPROPERTY()
	int32 KeepAliveCount = 0;

	FLowEntryHttpRequestExecutionAction* Execution = NULL;
	UPROPERTY()
	FDelegateULowEntryHttpRequestOnComplete ExecutionEvent;
	UPROPERTY()
	ULowEntryHttpRequestResponse* ExecutionResponse = NULL;

	UPROPERTY()
	int32 BytesToSend = 0;
	UPROPERTY()
	int32 BytesSent = 0;
	UPROPERTY()
	int32 BytesToReceive = 0;
	UPROPERTY()
	int32 BytesReceived = 0;
	

	/**
	* Sets the URL to which the HTTP request will be made.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Http Request|Request", Meta = (DisplayName = "Set Url"))
		void SetUrl(const ELowEntryHttpRequestType Type, const FString& Url);

	/**
	* Sets the URL to which the HTTP request will be made.
	* 
	* This blueprint also allows you to typ your own HTTP header request type.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Http Request|Request", Meta = (DisplayName = "Set Url (Custom Type)"))
		void SetUrlCustomType(const FString& Type, const FString& Url);

	/**
	* Sets a URL parameter (this will automatically add GET parameters to the URL when the request is executed, this will for example turn a URL like "google.com" into "google.com?parameter1=value1&parameter2=value2" on request execution).
	* 
	* Call this blueprint multiple times to have multiple parameters.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Http Request|Request", Meta = (DisplayName = "Set Url Parameter", Keywords = "get parameters"))
		void SetUrlParameter(const FString& Key, const FString& Value);

	/**
	* Sets a HTTP header, like "Content-Type".
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Http Request|Request", Meta = (DisplayName = "Set Header"))
		void SetHeader(const FString& Key, const FString& Value);


	/**
	* Sets the content as bytes.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Http Request|Request", Meta = (DisplayName = "Set Content As Bytes"))
		void SetContent(const TArray<uint8>& Data);

	/**
	* Sets the content as a string.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Http Request|Request", Meta = (DisplayName = "Set Content As String"))
		void SetContentAsString(const FString& Data);

	/**
	* Sets the content as a JSON string (this will automatically add the required headers to send a JSON request).
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Http Request|Request", Meta = (DisplayName = "Set Content As Json String"))
		void SetContentAsJsonString(const FString& Data);
	
	/**
	* Sets the content as POST parameters (this will automatically add the required headers to send a POST request).
	* 
	* Call this blueprint multiple times to have multiple parameters.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Http Request|Request", Meta = (DisplayName = "Set Content As Parameters", Keywords = "post put parameters"))
		void SetContentAsStringParameters(const FString& Key, const FString& Value);


	/**
	* Executes the request.
	*
	* This blueprint can NOT execute several HTTP Requests at the same time, because this is a latent blueprint, similar to Delay or Retriggerable Delay.
	* 
	* Only after the execution of this blueprint has been completed, can this blueprint be used again.
	*
	* If you need to execute several HTTP Requests at the same time, you can use several instances of this blueprint, or you can use the "Execute Request (Event)" blueprint instead.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Http Request|Request", meta = (Latent, WorldContext = "WorldContextObject", LatentInfo = "LatentInfo", DisplayName = "Execute Request"))
		void ExecuteRequest(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ULowEntryHttpRequestResponse*& Response);

	void OnExecuteRequestCompleted(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);
	void ExecutionActionIsDone();


	/**
	* Executes the request.
	* 
	* When done, this blueprint will execute the given event.
	* 
	* This blueprint can execute several HTTP Requests at the same time.
	* 
	* This blueprint is slightly messier than the "Execute Request" blueprint, but only this blueprint can handle several executions at the same time.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Http Request|Request", meta = (DisplayName = "Execute Request (Event)"))
		void ExecuteRequestEvent(const FDelegateULowEntryHttpRequestOnComplete OnComplete);

	void OnExecuteRequestCompletedEvent(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);


	void OnExecuteRequestProgress(FHttpRequestPtr Request, int32 NewBytesSent, int32 NewBytesReceived);


	/**
	* Cancels any executing requests.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Http Request|Request", Meta = (DisplayName = "Cancel Request Execution"))
		void CancelRequest();

	/**
	* Returns true if any requests are still executing.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Http Request|Request", Meta = (DisplayName = "Is Request Executing", Keywords = "done finished pending ready stopped"))
		bool IsExecutingRequest();


	/**
	* Returns true if any requests are still executing.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Http Request|Request", Meta = (DisplayName = "Get Url With Set Url Parameters"))
		FString GetUrlWithUrlParameters();

	/**
	* Returns true if any requests are still executing.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Http Request|Request", Meta = (DisplayName = "Get Content As Set String Parameters"))
		FString GetContentAsStringParameters();


	/**
	* Returns the number of bytes that the Http Request will have to send.
	* This doesn't include the size of the headers, only the size of the content will be taken into account.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Http Request|Request", Meta = (DisplayName = "Get Bytes To Send", Keywords = "data sent upload"))
		int32 GetBytesToSend();

	/**
	* Returns the number of bytes that the Http Request has sent so far.
	* 
	* Sometimes this does not return the correct value, this is caused by internal engine code.
	* Don't rely on this function to always return the correct value.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Http Request|Request", Meta = (DisplayName = "Get Bytes Sent So Far", Keywords = "data send upload"))
		int32 GetBytesSent();

	/**
	* Returns the number of bytes that the Http Request will have to receive.
	* This doesn't include the size of the headers, only the size of the content will be taken into account.
	* 
	* Sometimes this does not return the correct value, this is caused by internal engine code.
	* Don't rely on this function to always return the correct value.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Http Request|Request", Meta = (DisplayName = "Get Bytes To Receive", Keywords = "data received download"))
		int32 GetBytesToReceive();

	/**
	* Returns the number of bytes that the Http Request has received so far.
	* 
	* Sometimes this does not return the correct value, this is caused by internal engine code.
	* Don't rely on this function to always return the correct value.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Http Request|Request", Meta = (DisplayName = "Get Bytes Received So Far", Keywords = "data receive download"))
		int32 GetBytesReceived();

	/**
	* Returns the percentage of howmuch data has been sent so far (from 0.0 to 1.0).
	* 
	* Sometimes this does not return the correct value, this is caused by internal engine code.
	* Don't rely on this function to always return the correct value.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Http Request|Request", Meta = (DisplayName = "Get Percentage Of Sending Complete", Keywords = "data send sent part progression upload"))
		float GetSentPercentage();
	
	/**
	* Returns the percentage of howmuch data has been received so far (from 0.0 to 1.0).
	* 
	* Sometimes this does not return the correct value, this is caused by internal engine code.
	* Don't rely on this function to always return the correct value.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Http Request|Request", Meta = (DisplayName = "Get Percentage Of Receiving Complete", Keywords = "data receive received part progression download"))
		float GetReceivedPercentage();
};
