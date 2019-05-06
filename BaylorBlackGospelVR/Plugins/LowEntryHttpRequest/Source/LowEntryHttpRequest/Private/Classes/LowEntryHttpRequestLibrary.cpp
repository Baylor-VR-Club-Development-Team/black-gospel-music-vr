// Copyright Low Entry. All Rights Reserved.

#include "LowEntryHttpRequestLibrary.h"
#include "LowEntryHttpRequest.h"


// init >>
	ULowEntryHttpRequestLibrary::ULowEntryHttpRequestLibrary(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
	{
	}
// init <<


// request >>
	ULowEntryHttpRequest* ULowEntryHttpRequestLibrary::Request_Create()
	{
		return ULowEntryHttpRequest::Create();
	}
// init <<
