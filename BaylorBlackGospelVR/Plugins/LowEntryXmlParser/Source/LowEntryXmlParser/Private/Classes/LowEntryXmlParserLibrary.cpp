// Copyright Low Entry. All Rights Reserved.

#include "LowEntryXmlParserLibrary.h"
#include "LowEntryXmlParserNode.h"


DEFINE_LOG_CATEGORY(LogLowEntryXmlParser);


// init >>
	ULowEntryXmlParserLibrary::ULowEntryXmlParserLibrary(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
	{
	}
// init <<


ULowEntryXmlParserNode* ULowEntryXmlParserLibrary::StringToXml(const FString& Xml)
{
	FString PurgedXml;
	if(Xml.Contains(TEXT("<![CDATA["), ESearchCase::CaseSensitive, ESearchDir::FromStart))
	{
		PurgedXml = ReplaceCDATA(Xml);
	}
	else
	{
		PurgedXml = Xml;
	}

	FXmlFile* XmlFilePtr = new FXmlFile(PurgedXml, EConstructMethod::ConstructFromBuffer);
	FXmlNode* RootNode = XmlFilePtr->GetRootNode();
	if(RootNode == nullptr)
	{
		PurgedXml.ReplaceInline(TEXT("<"), TEXT("\r\n<"), ESearchCase::CaseSensitive);
		PurgedXml.TrimStartAndEndInline();

		XmlFilePtr = new FXmlFile(PurgedXml, EConstructMethod::ConstructFromBuffer);
		RootNode = XmlFilePtr->GetRootNode();
		if(RootNode == nullptr)
		{
			UE_LOG(LogLowEntryXmlParser, Error, TEXT("Couldn't parse the given XML, please validate the XML with http://www.w3schools.com/xml/xml_validator.asp"));
			return nullptr;
		}
	}
	TSharedPtr<FXmlFile> XmlFile = MakeShareable(XmlFilePtr);
	return ULowEntryXmlParserNode::Create(XmlFile, RootNode);
}

FString ULowEntryXmlParserLibrary::ReplaceCDATA(const FString& Xml)
{
	TArray<TCHAR> Characters = Xml.GetCharArray();
	int32 Length = Xml.Len();

	FString Result = TEXT("");
	int32 LastMatchEnding = 0;

	FString Start = TEXT("<![CDATA[");
	FString End = TEXT("]]>");

	while(true)
	{
		int32 b = Xml.Find(Start, ESearchCase::CaseSensitive, ESearchDir::FromStart, LastMatchEnding - 1);
		if(b < 0)
		{
			break;
		}

		int32 e = Xml.Find(End, ESearchCase::CaseSensitive, ESearchDir::FromStart, b + 9 - 1);
		if(e < 0)
		{
			break;
		}
		e += 3;

		for(int32 i = LastMatchEnding; i < b; i++)
		{
			Result += Characters[i];
		}
		Result += XmlEncode(Xml.Mid((b + 9), (e - 3) - (b + 9))); //  "<![CDATA["  is 9,   "]]>"  is 3

		LastMatchEnding = e;
	}
	for(int32 i = LastMatchEnding; i < Length; i++)
	{
		Result += Characters[i];
	}
	return Result;
}

FString ULowEntryXmlParserLibrary::XmlEncode(const FString& String)
{
	FString Result = String;
	Result.ReplaceInline(TEXT("&"), TEXT("&amp;"), ESearchCase::CaseSensitive);
	Result.ReplaceInline(TEXT("\""), TEXT("&quot;"), ESearchCase::CaseSensitive);
	Result.ReplaceInline(TEXT("'"), TEXT("&apos;"), ESearchCase::CaseSensitive);
	Result.ReplaceInline(TEXT("<"), TEXT("&lt;"), ESearchCase::CaseSensitive);
	Result.ReplaceInline(TEXT(">"), TEXT("&gt;"), ESearchCase::CaseSensitive);
	return Result;
}


FString ULowEntryXmlParserLibrary::XmlToString(ULowEntryXmlParserNode* Node)
{
	FString Xml = TEXT(""); // TEXT("<?xml version=\"1.0\" encoding=\"UTF-8\"?>") + LINE_TERMINATOR;
	if((Node != nullptr) && (Node->Node != nullptr))
	{
		WriteNodeHierarchy(*Node->Node, TEXT(""), Xml);
	}
	return Xml;
}

void ULowEntryXmlParserLibrary::WriteNodeHierarchy(const FXmlNode& Node, const FString& Indent, FString& Output)
{
	// Write the tag
	Output += Indent + FString::Printf(TEXT("<%s"), *Node.GetTag());
	for(const FXmlAttribute& Attribute : Node.GetAttributes())
	{
		FString EscapedValue = Attribute.GetValue();
		EscapedValue.ReplaceInline(TEXT("&"), TEXT("&amp;"), ESearchCase::CaseSensitive);
		EscapedValue.ReplaceInline(TEXT("\""), TEXT("&quot;"), ESearchCase::CaseSensitive);
		EscapedValue.ReplaceInline(TEXT("'"), TEXT("&apos;"), ESearchCase::CaseSensitive);
		EscapedValue.ReplaceInline(TEXT("<"), TEXT("&lt;"), ESearchCase::CaseSensitive);
		EscapedValue.ReplaceInline(TEXT(">"), TEXT("&gt;"), ESearchCase::CaseSensitive);
		Output += FString::Printf(TEXT(" %s=\"%s\""), *Attribute.GetTag(), *EscapedValue);
	}

	// Write the node contents
	const FXmlNode* FirstChildNode = Node.GetFirstChildNode();
	if(FirstChildNode == nullptr)
	{
		const FString& Content = Node.GetContent();
		if(Content.Len() == 0)
		{
			Output += TEXT(" />");
			Output += LINE_TERMINATOR;
		}
		else
		{
			Output += TEXT(">") + Content + FString::Printf(TEXT("</%s>"), *Node.GetTag()) + LINE_TERMINATOR;
		}
	}
	else
	{
		Output += TEXT(">");
		Output += LINE_TERMINATOR;
		for(const FXmlNode* ChildNode = FirstChildNode; ChildNode != nullptr; ChildNode = ChildNode->GetNextNode())
		{
			WriteNodeHierarchy(*ChildNode, Indent + TEXT("\t"), Output);
		}
		Output += Indent + FString::Printf(TEXT("</%s>"), *Node.GetTag()) + LINE_TERMINATOR;
	}
}
