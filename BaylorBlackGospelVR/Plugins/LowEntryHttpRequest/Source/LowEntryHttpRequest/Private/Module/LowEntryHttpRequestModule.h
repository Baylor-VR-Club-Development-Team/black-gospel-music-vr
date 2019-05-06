// Copyright Low Entry. All Rights Reserved.

#pragma once


#include "ILowEntryHttpRequestModule.h"


class FLowEntryHttpRequestModule : public ILowEntryHttpRequestModule
{
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
