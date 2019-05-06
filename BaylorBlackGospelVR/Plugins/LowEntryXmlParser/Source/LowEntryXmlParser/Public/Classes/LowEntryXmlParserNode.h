// Copyright Low Entry. All Rights Reserved.

#pragma once


#include "CoreMinimal.h"
#include "CoreUObject.h"

#include "XmlNode.h"
#include "XmlFile.h"

#include "FLowEntryXmlParserNodeAttribute.h"

#include "LowEntryXmlParserNode.generated.h"


UCLASS(BlueprintType)
class LOWENTRYXMLPARSER_API ULowEntryXmlParserNode : public UObject
{
	GENERATED_UCLASS_BODY()


public:
	static ULowEntryXmlParserNode* Create(TSharedPtr<FXmlFile> XmlFile, FXmlNode* Node);
	static ULowEntryXmlParserNode* Create(TSharedPtr<FXmlFile> XmlFile, const FXmlNode* Node);


public:
	bool IsValid();


	/**
	* Gets the next node in a list of nodes, can return NULL.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Xml Parser|Node", Meta = (DisplayName = "Get Next Node"))
		ULowEntryXmlParserNode* GetNextNode();

	/**
	* Gets a list of children nodes.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Xml Parser|Node", Meta = (DisplayName = "Get Children Nodes"))
		TArray<ULowEntryXmlParserNode*> GetChildrenNodes();
	
	/**
	* Gets the first child of this node which can be iterated into with GetNextNode, can return NULL.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Xml Parser|Node", Meta = (DisplayName = "Get First Child Node"))
		ULowEntryXmlParserNode* GetFirstChildNode();
	
	/**
	* Finds the first child node that contains the specified tag, can return NULL.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Xml Parser|Node", Meta = (DisplayName = "Find Child Node"))
		ULowEntryXmlParserNode* FindChildNode(const FString& Tag);

	/**
	* Gets the tag of the node.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Xml Parser|Node", Meta = (DisplayName = "Get Tag"))
		FString GetTag();

	/**
	* Gets the value of the node.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Xml Parser|Node", Meta = (DisplayName = "Get Value"))
		FString GetValue();

	/**
	* Gets all of the attributes in this node.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Xml Parser|Node", Meta = (DisplayName = "Get Attributes"))
		TArray<FLowEntryXmlParserNodeAttribute> GetAttributes();

	/**
	* Gets an attribute that corresponds with the given tag.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Xml Parser|Node", Meta = (DisplayName = "Get Attribute"))
		FString GetAttribute(const FString& Tag);


public:
	TSharedPtr<FXmlFile> XmlFile; // keeps everything in memory
	const FXmlNode* Node = NULL;
};
