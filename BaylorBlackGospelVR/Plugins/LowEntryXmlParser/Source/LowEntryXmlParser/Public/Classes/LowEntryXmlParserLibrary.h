// Copyright Low Entry. All Rights Reserved.

#pragma once


#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "XmlNode.h"
#include "XmlFile.h"

#include "LowEntryXmlParserLibrary.generated.h"


DECLARE_LOG_CATEGORY_EXTERN(LogLowEntryXmlParser, Log, All);


class ULowEntryXmlParserNode;


UCLASS()
class LOWENTRYXMLPARSER_API ULowEntryXmlParserLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()


public:
	/**
	* Parses XML data and returns the root node, returns NULL if it can't be parsed.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Xml Parser|Library", Meta = (DisplayName = "Parse Xml"))
		static ULowEntryXmlParserNode* StringToXml(const FString& Xml);

	/**
	* Converts the given node and all childs to XML data.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Xml Parser|Library", Meta = (DisplayName = "Get Xml"))
		static FString XmlToString(ULowEntryXmlParserNode* Node);


public:
	static FString ReplaceCDATA(const FString& Xml);
	static FString XmlEncode(const FString& String);
	static void WriteNodeHierarchy(const FXmlNode& Node, const FString& Indent, FString& Output);
};
