// Copyright Low Entry. All Rights Reserved.

#include "LowEntryXmlParserNode.h"


// init >>
	ULowEntryXmlParserNode::ULowEntryXmlParserNode(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
	{
	}

	ULowEntryXmlParserNode* ULowEntryXmlParserNode::Create(TSharedPtr<FXmlFile> XmlFile, FXmlNode* Node)
	{
		ULowEntryXmlParserNode* Instance = NewObject<ULowEntryXmlParserNode>();
		Instance->XmlFile = XmlFile;
		Instance->Node = Node;
		return Instance;
	}
	ULowEntryXmlParserNode* ULowEntryXmlParserNode::Create(TSharedPtr<FXmlFile> XmlFile, const FXmlNode* Node)
	{
		ULowEntryXmlParserNode* Instance = NewObject<ULowEntryXmlParserNode>();
		Instance->XmlFile = XmlFile;
		Instance->Node = Node;
		return Instance;
	}
// init <<


bool ULowEntryXmlParserNode::IsValid()
{
	return (XmlFile.IsValid() && (Node != nullptr));
}


ULowEntryXmlParserNode* ULowEntryXmlParserNode::GetNextNode()
{
	if(!IsValid())
	{
		return NULL;
	}
	const FXmlNode* NextNode = Node->GetNextNode();
	if(NextNode == nullptr)
	{
		return NULL;
	}
	return ULowEntryXmlParserNode::Create(XmlFile, NextNode);
}

TArray<ULowEntryXmlParserNode*> ULowEntryXmlParserNode::GetChildrenNodes()
{
	TArray<ULowEntryXmlParserNode*> Array;
	if(!IsValid())
	{
		return Array;
	}
	const TArray<FXmlNode*> Nodes = Node->GetChildrenNodes();
	for(FXmlNode* NextNode : Nodes)
	{
		if(NextNode != nullptr)
		{
			Array.Add(ULowEntryXmlParserNode::Create(XmlFile, NextNode));
		}
	}
	return Array;
}

ULowEntryXmlParserNode* ULowEntryXmlParserNode::GetFirstChildNode()
{
	if(!IsValid())
	{
		return NULL;
	}
	const FXmlNode* NextNode = Node->GetFirstChildNode();
	if(NextNode == nullptr)
	{
		return NULL;
	}
	return ULowEntryXmlParserNode::Create(XmlFile, NextNode);
}

ULowEntryXmlParserNode* ULowEntryXmlParserNode::FindChildNode(const FString& Tag)
{
	if(!IsValid())
	{
		return NULL;
	}
	const FXmlNode* NextNode = Node->FindChildNode(Tag);
	if(NextNode == nullptr)
	{
		return NULL;
	}
	return ULowEntryXmlParserNode::Create(XmlFile, NextNode);
}

FString ULowEntryXmlParserNode::GetTag()
{
	if(!IsValid())
	{
		return TEXT("");
	}
	return Node->GetTag();
}

FString ULowEntryXmlParserNode::GetValue()
{
	if(!IsValid())
	{
		return TEXT("");
	}
	return Node->GetContent();
}

TArray<FLowEntryXmlParserNodeAttribute> ULowEntryXmlParserNode::GetAttributes()
{
	TArray<FLowEntryXmlParserNodeAttribute> Attributes;
	if(!IsValid())
	{
		return Attributes;
	}
	TArray<FXmlAttribute> NodeAttributes = Node->GetAttributes();
	for(FXmlAttribute NodeAttribute : NodeAttributes)
	{
		FLowEntryXmlParserNodeAttribute Attribute;
		Attribute.Tag = NodeAttribute.GetTag();
		Attribute.Value = NodeAttribute.GetValue();
		Attributes.Add(Attribute);
	}
	return Attributes;
}

FString ULowEntryXmlParserNode::GetAttribute(const FString& Tag)
{
	if(!IsValid())
	{
		return TEXT("");
	}
	return Node->GetAttribute(Tag);
}
