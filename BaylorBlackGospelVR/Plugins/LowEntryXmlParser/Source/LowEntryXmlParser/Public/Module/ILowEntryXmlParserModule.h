// Copyright Low Entry. All Rights Reserved.

#pragma once


#include "Modules/ModuleManager.h"


class ILowEntryXmlParserModule : public IModuleInterface
{
public:
	/**
	 * Singleton-like access to this module's interface. This is just for convenience!
	 * Beware of calling this during the shutdown phase, though. Your module might have been unloaded already.
	 *
	 * @return Returns singleton instance, loading the module on demand if needed
	 */
	static inline ILowEntryXmlParserModule& Get()
	{
		return FModuleManager::LoadModuleChecked<ILowEntryXmlParserModule>("LowEntryXmlParser");
	}

	/**
	 * Checks to see if this module is loaded and ready. It is only valid to call Get() if IsAvailable() returns true.
	 *
	 * @return True if the module is loaded and ready to use
	 */
	static inline bool IsAvailable()
	{
		return FModuleManager::Get().IsModuleLoaded("LowEntryXmlParser");
	}
};
