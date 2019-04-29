// HammUEr
// Copyright 2015-2016 Turfster / NT Entertainment
// All Rights Reserved.


// This code is held together with kitten whiskers and toothpicks.
// There's nothing to see or learn here.
// Seriously.
// Turn back.

#pragma once

#include "ModuleManager.h"
#include "SlateBasics.h"
#include "HammUErSettings.h"


class FToolBarBuilder;
class FMenuBuilder;

class FHammUErModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	
	/** This function will be bound to Command (by default it will bring up plugin window) */
	void PluginButtonClicked();
	
	FString VMFileName;

private:
	void AddToolbarExtension(FToolBarBuilder& Builder);
	void AddMenuExtension(FMenuBuilder& Builder);

	void ExtraTabs();

	bool buttonPushed = false;

	TSharedRef<class SDockTab> OnSpawnPluginTab(const class FSpawnTabArgs& SpawnTabArgs);

	TSharedPtr<class FUICommandList> PluginCommands;

	TSharedPtr<SDockTab> textUErTab;
	TSharedPtr<SDockTab> settingsTab;
	TSharedPtr<SDockTab> propUErTab;
	TSharedPtr<SDockTab> mainHammUErTab;

	void OnMainTabClosed(TSharedRef<SDockTab> ClosedTab)
	{
		mainHammUErTab = NULL;
	}

	void OnTextUErTabClosed(TSharedRef<SDockTab> ClosedTab)
	{
		textUErTab = NULL;
	}

	void OnSettingTabClosed(TSharedRef<SDockTab> ClosedTab)
	{
		settingsTab = NULL;
	}

	void OnPropUErTabClosed(TSharedRef<SDockTab> ClosedTab)
	{
		propUErTab = NULL;
	}
};