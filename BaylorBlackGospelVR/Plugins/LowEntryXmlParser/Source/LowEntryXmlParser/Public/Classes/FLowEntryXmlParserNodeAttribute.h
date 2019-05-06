// Copyright Low Entry. All Rights Reserved.

#pragma once


#include "CoreMinimal.h"

#include "FLowEntryXmlParserNodeAttribute.generated.h"


USTRUCT(BlueprintType)
struct LOWENTRYXMLPARSER_API FLowEntryXmlParserNodeAttribute
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Low Entry|Xml Parser|Node Attribute")
		FString Tag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Low Entry|Xml Parser|Node Attribute")
		FString Value;
};
