// Copyright Low Entry. All Rights Reserved.

#pragma once


#include "CoreMinimal.h"

#include "ELowEntryHttpRequestType.generated.h"


UENUM()
enum class ELowEntryHttpRequestType : uint8
{
	GET = 0,
	POST = 1,
	PUT = 2,
	_PATCH = 3,
	_DELETE = 4,
	_CONNECT = 5,
	_OPTIONS = 6,
	_HEAD = 7,
	_TRACE = 8
};

static const FString ELowEntryHttpRequestTypes[9] = {"GET", "POST", "PUT", "PATCH", "DELETE", "CONNECT", "OPTIONS", "HEAD", "TRACE"};
