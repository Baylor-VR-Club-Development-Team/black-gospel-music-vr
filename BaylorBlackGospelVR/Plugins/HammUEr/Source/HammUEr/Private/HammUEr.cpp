// HammUEr
// Plugin button/window  code
// Copyright 2015-2016 Turfster / NT Entertainment
// All Rights Reserved.


// This code is held together with kitten whiskers and toothpicks.
// There's nothing to see or learn here.
// Seriously.
// Turn back.


#include "HammUErPrivatePCH.h"

#include "SlateBasics.h"
#include "SlateExtras.h"

#include "TabManager.h"

#include "HammUErStyle.h"
#include "HammUErCommands.h"
#include "SHammerDialogWidget.h"
#include "SHammerPropUErWidget.h"
#include "SHammerSettingsWidget.h"
#include "SHammerTextUErWidget.h"
#include "LevelEditor.h"

#include "./EditorMode/HammUErEdEdMode.h"


#define LOCTEXT_NAMESPACE "FHammUErModule"

static const FName HammUErTabName = FName("HammUEr");

void FHammUErModule::StartupModule()
{
	FHammUErStyle::Initialize();
	FHammUErStyle::ReloadTextures();

	FHammUErCommands::Register();
	
	PluginCommands = MakeShareable(new FUICommandList);

	PluginCommands->MapAction(
		FHammUErCommands::Get().OpenPluginWindow,
		FExecuteAction::CreateRaw(this, &FHammUErModule::PluginButtonClicked),
		FCanExecuteAction());
		
	FLevelEditorModule& LevelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");
	
	{
		TSharedPtr<FExtender> MenuExtender = MakeShareable(new FExtender());
		MenuExtender->AddMenuExtension("WindowLayout", EExtensionHook::After, PluginCommands, FMenuExtensionDelegate::CreateRaw(this, &FHammUErModule::AddMenuExtension));

		LevelEditorModule.GetMenuExtensibilityManager()->AddExtender(MenuExtender);
	}
	
	{
		TSharedPtr<FExtender> ToolbarExtender = MakeShareable(new FExtender);
		ToolbarExtender->AddToolBarExtension("Settings", EExtensionHook::After, PluginCommands, FToolBarExtensionDelegate::CreateRaw(this, &FHammUErModule::AddToolbarExtension));
		
		LevelEditorModule.GetToolBarExtensibilityManager()->AddExtender(ToolbarExtender);
	}

	FGlobalTabmanager::Get()->RegisterTabSpawner(HammUErTabName, FOnSpawnTab::CreateRaw(this, &FHammUErModule::OnSpawnPluginTab))
		.SetDisplayName(LOCTEXT("FHammUErTabTitle", "HammUEr"))
		.SetMenuType(ETabSpawnerMenuType::Hidden);
		
	FEditorModeRegistry::Get().RegisterMode<FHammUErEdEdMode>(FHammUErEdEdMode::EM_HammUErEdEdModeId, LOCTEXT("HammUErEdEdModeName", "HammUEr"), FSlateIcon("HammUErStyle","HammUEr.EdModeIcon"), true);
}

void FHammUErModule::ShutdownModule()
{
	FHammUErStyle::Shutdown();

	FHammUErCommands::Unregister();

	FGlobalTabmanager::Get()->UnregisterNomadTabSpawner(HammUErTabName);
	
	FEditorModeRegistry::Get().UnregisterMode(FHammUErEdEdMode::EM_HammUErEdEdModeId);
}

TSharedRef<SDockTab> FHammUErModule::OnSpawnPluginTab(const FSpawnTabArgs& SpawnTabArgs)
{
	return SAssignNew(mainHammUErTab,SDockTab)
		.TabRole(ETabRole::MajorTab)
		.OnTabClosed(SDockTab::FOnTabClosedCallback::CreateRaw(this, &FHammUErModule::OnMainTabClosed))
		.ShouldAutosize(true)
		[
				SNew(SHammerDialogWidget)
		];
}

void FHammUErModule::ExtraTabs()
{
	if (textUErTab.IsValid())
		textUErTab->ActivateInParent(ETabActivationCause::SetDirectly);
	else
	{
		FGlobalTabmanager::Get()->RestoreDocumentTab(HammUErTabName, FTabManager::ESearchPreference::PreferLiveTab,
			SAssignNew(textUErTab, SDockTab)
			.TabRole(ETabRole::NomadTab)
			.Label(LOCTEXT("textuertitle","TextUEr"))
			.OnTabClosed(SDockTab::FOnTabClosedCallback::CreateRaw(this, &FHammUErModule::OnTextUErTabClosed))
			.ShouldAutosize(false)
			[
				SNew(SHammerTextUErWidget)
			]);
	}
	if (propUErTab.IsValid())
		propUErTab->ActivateInParent(ETabActivationCause::SetDirectly);
	else
	{
		FGlobalTabmanager::Get()->RestoreDocumentTab(HammUErTabName, FTabManager::ESearchPreference::PreferLiveTab,
			SAssignNew(propUErTab, SDockTab)
			.TabRole(ETabRole::NomadTab)
			.Label(LOCTEXT("propuertitle","PropUEr"))
			.OnTabClosed(SDockTab::FOnTabClosedCallback::CreateRaw(this, &FHammUErModule::OnPropUErTabClosed))
			.ShouldAutosize(false)
			[
				SNew(SHammerPropUErWidget)
			]);
	}
	if (settingsTab.IsValid())
		settingsTab->ActivateInParent(ETabActivationCause::SetDirectly);
	else
	{
		FGlobalTabmanager::Get()->RestoreDocumentTab(HammUErTabName, FTabManager::ESearchPreference::PreferLiveTab,
			SAssignNew(settingsTab, SDockTab)
			.TabRole(ETabRole::NomadTab)
			.Label(LOCTEXT("configuertitle","ConfigUEr"))
			.OnTabClosed(SDockTab::FOnTabClosedCallback::CreateRaw(this, &FHammUErModule::OnSettingTabClosed))
			.ShouldAutosize(false)
			[
				SNew(SHammerSettingsWidget)
			]);
	}
}

void FHammUErModule::PluginButtonClicked()
{
	buttonPushed = true;
	TSharedPtr<SDockTab> previousActive = FGlobalTabmanager::Get()->InvokeTab(HammUErTabName);
	
	ExtraTabs();
	
	FGlobalTabmanager::Get()->InvokeTab(HammUErTabName); // switch back to main tab
}

void FHammUErModule::AddMenuExtension(FMenuBuilder& Builder)
{
	Builder.AddMenuEntry(FHammUErCommands::Get().OpenPluginWindow);
}

void FHammUErModule::AddToolbarExtension(FToolBarBuilder& Builder)
{
	Builder.AddToolBarButton(FHammUErCommands::Get().OpenPluginWindow);
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FHammUErModule, HammUEr)