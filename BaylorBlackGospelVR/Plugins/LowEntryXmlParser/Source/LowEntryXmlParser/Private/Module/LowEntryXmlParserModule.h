// Copyright Low Entry. All Rights Reserved.

#pragma once


#include "ILowEntryXmlParserModule.h"


class FLowEntryXmlParserModule : public ILowEntryXmlParserModule
{
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
