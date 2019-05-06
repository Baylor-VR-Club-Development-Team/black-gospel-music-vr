// Copyright Low Entry. All Rights Reserved.

#pragma once


#include "CoreMinimal.h"
#include "CoreUObject.h"

#include "Http.h"

#include "ELowEntryHttpRequestSuccess.h"

#include "LowEntryHttpRequestResponse.generated.h"


UCLASS(BlueprintType)
class LOWENTRYHTTPREQUEST_API ULowEntryHttpRequestResponse : public UObject
{
	GENERATED_UCLASS_BODY()


public:
	static ULowEntryHttpRequestResponse* Create();
	static ULowEntryHttpRequestResponse* Create(const FHttpResponsePtr Response);


public:
	FHttpResponsePtr Response = NULL;
	UPROPERTY()
	bool Successful = false;


	void SetResponse(const FHttpResponsePtr NewResponse);


	/**
	* Returns true if the HTTP request was successful.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Http Request|Response", Meta = (DisplayName = "Was Request Successful", ExpandEnumAsExecs = "Branch"))
		void WasSuccessful(ELowEntryHttpRequestSuccess& Branch);

	/**
	* Returns true if the HTTP request was successful.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Http Request|Response", Meta = (DisplayName = "Get Was Request Successful"))
		bool GetWasSuccessful();

	void SetWasSuccessful(const bool WasSuccessful);


	/**
	* Returns the HTTP response code.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Http Request|Response", Meta = (DisplayName = "Get Response Code"))
		int32 GetResponseCode();


	/**
	* Returns the URL to which the HTTP request was made.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Http Request|Response", Meta = (DisplayName = "Get Url"))
		FString GetUrl();


	/**
	* Returns the content as bytes that the HTTP request returned.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Http Request|Response", Meta = (DisplayName = "Get Content As Bytes"))
		TArray<uint8> GetContent();

	/**
	* Returns the content as a string that the HTTP request returned.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Http Request|Response", Meta = (DisplayName = "Get Content As String"))
		FString GetContentAsString();

	/**
	* Returns the length of the content that the HTTP request returned.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Http Request|Response", Meta = (DisplayName = "Get Content Length"))
		int32 GetContentLength();

	/**
	* Returns the type of the content that the HTTP request returned.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Http Request|Response", Meta = (DisplayName = "Get Content Type"))
		FString GetContentType();


	/**
	* Returns a header that the HTTP request returned.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Http Request|Response", Meta = (DisplayName = "Get Header"))
		FString GetHeader(const FString& Key);

	/**
	* Returns all headers that the HTTP request returned.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Http Request|Response", Meta = (DisplayName = "Get All Headers"))
		TArray<FString> GetAllHeaders();
};
