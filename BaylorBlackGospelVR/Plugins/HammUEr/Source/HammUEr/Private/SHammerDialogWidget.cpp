// HammUEr
// Main map loader tab
// Copyright 2015-2016 Turfster / NT Entertainment
// All Rights Reserved.


// This code is held together with kitten whiskers and toothpicks.
// There's nothing to see or learn here.
// Seriously.
// Turn back.

#include "HammUErPrivatePCH.h"
#include "SHammerDialogWidget.h"
#include "UnrealEd.h"

#include "ModuleManager.h"
#include "DesktopPlatformModule.h"
#include "MainFrame.h"
#include "HammUEr.h"

#include "SlateBasics.h"
#include "SlateExtras.h"

#include "AssetRegistryModule.h"
#include "HammUErSettings.h"
#include "HammUErStyle.h"

#include "PropertyCustomizationHelpers.h"


// level test stuff
/*#include "EditorLevelUtils.h"
#include "Editor/WorldBrowser/Private/StreamingLevels/StreamingLevelModel.h"
#include "CoreUObject.h"
#include "UnrealEd.h"
#include "ScopedTransaction.h"
#include "ISourceControlModule.h"
#include "LevelUtils.h"
//#include "EditorLevelUtils.h"
#include "ActorEditorUtils.h"
#include "LevelDragDropOp.h"

#include "WorldBrowserModule.h" 
#include "LevelCollectionCommands.h"   
#include "LevelModel.h"
#include "LevelCollectionModel.h"
*/
#define LOCTEXT_NAMESPACE "SHammerDialogWidget"


void SHammerDialogWidget::Construct(const FArguments& InArgs)
{
	ChildSlot
		[
			SNew(SVerticalBox)
			+ SVerticalBox::Slot()
			.AutoHeight()
			.Padding(3.0f, 1.0f)
			[
				SNew(SBox)
				.HAlign(HAlign_Center)
				.VAlign(VAlign_Center)
				.WidthOverride(400)
				.HeightOverride(40)
				[
					SNew(SImage)
					.Image(FHammUErStyle::Get().GetBrush("HammUEr.Header"))
				]
			]
			+ SVerticalBox::Slot()
				.AutoHeight()
				.Padding(3.0f, 1.0f)
				[
					SNew(SBorder)
					.Padding(FMargin(3))
					[
						SNew(SVerticalBox)
						+ SVerticalBox::Slot()
						.AutoHeight()
						[
							SNew(SBox)
							.WidthOverride(450)
							[
								SNew(SHorizontalBox)
								+ SHorizontalBox::Slot()
								.AutoWidth()
								.VAlign(VAlign_Center)
								[
									SNew(STextBlock)
									.Text(LOCTEXT("Import_CurrentFileTitle", "Current File: "))
								]
								+ SHorizontalBox::Slot()
									.VAlign(VAlign_Center)
									[
										SNew(SEditableText)
										.OnTextChanged(this, &SHammerDialogWidget::OnFileNameChanged)
										.Text(this, &SHammerDialogWidget::GetVMFileName)
									]
								+ SHorizontalBox::Slot()
									.AutoWidth()
									[
										SNew(SButton)
										.OnClicked(this, &SHammerDialogWidget::HandleChooseFileButtonClicked)
										.IsEnabled(true)
										.Text(LOCTEXT("BrowseButtonText", "Choose File"))
									]
							]
						]
					]
				]
			+ SVerticalBox::Slot()
				.AutoHeight()
				.Padding(2)
				[
					SNew(SBorder)
					.Padding(FMargin(3))
					[
						SNew(SVerticalBox)
						+ SVerticalBox::Slot()
						.AutoHeight()
						[
							SNew(SHorizontalBox)
							+ SHorizontalBox::Slot()
							.VAlign(VAlign_Center)
							.HAlign(HAlign_Left)
							.AutoWidth()
							[
								SNew(SBox)
								.WidthOverride(91)
								[
									SNew(STextBlock)
									.Text(LOCTEXT("Import_DirectoryTitle", "Import directory: "))
								]
							]
							+ SHorizontalBox::Slot()
							.VAlign(VAlign_Center)
							.HAlign(HAlign_Left)
							.AutoWidth()
							[
								SNew(SBox)
								.WidthOverride(200)
								[
									SNew(SHorizontalBox)
									+SHorizontalBox::Slot()
									.AutoWidth()
									[
										SNew(SBox)
										.WidthOverride(175)
										[
										SAssignNew(importDirBlock, SEditableTextBox)
										.BackgroundColor(FSlateColor(FLinearColor(FColor::White)))
										.OnTextChanged(this, &SHammerDialogWidget::OnImportDirNameChanged)
										.Text(this, &SHammerDialogWidget::GetImportDirName)
										.ToolTipText(LOCTEXT("Import_DirectoryTitle_tooltip","Location in content browser to import meshes to"))
										]
									]
									+SHorizontalBox::Slot()
										.AutoWidth()
										[
											SNew(SButton)
											.OnClicked(this, &SHammerDialogWidget::GetImportHeader)
											.IsEnabled(true)
										.HAlign(HAlign_Center)
										.VAlign(VAlign_Center)
										.Text(LOCTEXT("ImportHeaderText", "..."))
										]
								]
							]
							+ SHorizontalBox::Slot()
								.FillWidth(1)
								.VAlign(VAlign_Center)
								[
									SNew(SSeparator)
									.IsEnabled(false)
								] 
							+ SHorizontalBox::Slot()
								.AutoWidth()
								.VAlign(VAlign_Center)
								.HAlign(HAlign_Center)
								[
									SNew(SBox)
									.VAlign(VAlign_Center)
									.HAlign(HAlign_Center)
									.WidthOverride(90)
									[
										SNew(SHorizontalBox)
										+ SHorizontalBox::Slot()
										.VAlign(VAlign_Center)
										.HAlign(HAlign_Center)
										.Padding(FMargin(1.f,0.f))
										.AutoWidth()
										.MaxWidth(20)
										[
											SNew(STextBlock)
											.Text(LOCTEXT("DoMeshes", "M"))
										]
										+ SHorizontalBox::Slot()
										.MaxWidth(24)
										.AutoWidth()
										.VAlign(VAlign_Center)
										.HAlign(HAlign_Center)
										.Padding(FMargin(0.f, 0.f))
										[
											SNew(SCheckBox)
											.IsChecked(this, &SHammerDialogWidget::GetGenerateMeshesActive)
											.OnCheckStateChanged(this, &SHammerDialogWidget::OnGenerateMeshesChanged)
											.ToolTipText(LOCTEXT("DoMeshesTooltip", "Generate meshes when importing the map"))
										]
										+ SHorizontalBox::Slot()
										.VAlign(VAlign_Center)
										.HAlign(HAlign_Center)
										.AutoWidth()
										.MaxWidth(20)
										.Padding(FMargin(1.f, 0.f))
										[
											SNew(STextBlock)
											.Text(LOCTEXT("DoEntities", "E"))
										]
										+ SHorizontalBox::Slot()
										.MaxWidth(24)
										.AutoWidth()
										.HAlign(HAlign_Center)
										.VAlign(VAlign_Center)
										.Padding(FMargin(0.f, 0.f))
										[
											SNew(SCheckBox)
											.IsChecked(this, &SHammerDialogWidget::GetGenerateEntitiesActive)
											.OnCheckStateChanged(this, &SHammerDialogWidget::OnGenerateEntitiesChanged)
											.ToolTipText(LOCTEXT("DoEntitiesTooltip", "Import entities when importing the map"))
										]
										+ SHorizontalBox::Slot()
										.VAlign(VAlign_Center)
										.HAlign(HAlign_Center)
										.Padding(FMargin(1.f, 0.f))
										.AutoWidth()
										.MaxWidth(20)
										[
											SNew(STextBlock)
											.Text(LOCTEXT("DoUnknown", "?"))
										]
										+ SHorizontalBox::Slot()
										.MaxWidth(24)
										.AutoWidth()
										.Padding(FMargin(0.f, 0.f))
										.HAlign(HAlign_Center)
										.VAlign(VAlign_Center)
										[
											SNew(SCheckBox)
											.IsChecked(this, &SHammerDialogWidget::GetGenerateUnknownsActive)
											.OnCheckStateChanged(this, &SHammerDialogWidget::OnGenerateUnknownsChanged)
											.ToolTipText(LOCTEXT("DoUnknownEntitiesTooltip", "Generate notes for unknown entities when importing the map"))
										]
									]
								]
							+SHorizontalBox::Slot()
								.FillWidth(1)
								.VAlign(VAlign_Center)
								[
									SNew(SSeparator)
									.IsEnabled(false)
								]
							+ SHorizontalBox::Slot()
								.AutoWidth()
								.VAlign(VAlign_Center)
								[
									SNew(SButton)
									.Text(LOCTEXT("Import_openFile", "Open file"))
									.HAlign(HAlign_Center)
									.IsEnabled(this, &SHammerDialogWidget::CanRunFirstPhase)
									.ContentPadding(3)
									.OnClicked(this, &SHammerDialogWidget::RunFirstPhase)
									.ToolTipText(LOCTEXT("Import_openFile_tooltip","First data run"))
								]
						]
					]
				]
			+ SVerticalBox::Slot()
				.AutoHeight()
				.Padding(2)
				[
					SNew(SBorder)
					.Padding(FMargin(3))
					.Visibility(this, &SHammerDialogWidget::GetSeekVisibility)
					[
						SNew(SVerticalBox)
						+SVerticalBox::Slot()
						.AutoHeight()
						.Padding(2)
						[
							SNew(SHorizontalBox)
							+ SHorizontalBox::Slot()
							.AutoWidth()
							.MaxWidth(150.f)
							.Padding(3.f, 1.f)
							.VAlign(VAlign_Center)
							[
								SNew(STextBlock)
								.Text(LOCTEXT("Seek", "Find material: "))
								.Visibility(this, &SHammerDialogWidget::GetSeekVisibility)

							]
							+ SHorizontalBox::Slot()
							.Padding(3.f, 1.f)
							.VAlign(VAlign_Center)
							[
								SAssignNew(importSeekBlock, SEditableTextBox)
								.BackgroundColor(FSlateColor(FLinearColor(FColor::White)))
								.OnTextCommitted(this, &SHammerDialogWidget::OnSeekNameChanged)
								.Text(this, &SHammerDialogWidget::GetSeekName)
								.Visibility(this, &SHammerDialogWidget::GetSeekVisibility)
								.ToolTipText(LOCTEXT("import_original_mat_tooltip","Original material(s) to find"))
							]
							+ SHorizontalBox::Slot()
							.AutoWidth()
							.VAlign(VAlign_Center)
							[
								SNew(SButton)
								.Text(LOCTEXT("Import_toggleButton", "Toggle NoDraw"))
								.HAlign(HAlign_Center)
								.IsEnabled(this, &SHammerDialogWidget::CanToggle)
								.ContentPadding(3)
								.OnClicked(this, &SHammerDialogWidget::RunToggle)
								.ToolTipText(LOCTEXT("Import_toggleButton_tooltip", "Toggle selected materials nodraw on/off"))
							]
						]
				+ SVerticalBox::Slot()
				.MaxHeight(300)
				[
					/*SNew(SScrollBox)
					+ SScrollBox::Slot()
					[*/
					SNew(SBox)
					.HeightOverride(300.f)
					[
						SAssignNew(materialListWidget, SListView<TSharedPtr<FMaterialListEntry>>)
							.ItemHeight(30)
							.ListItemsSource(&materialList)
							.SelectionMode(ESelectionMode::Multi)
							.OnGenerateRow(this, &SHammerDialogWidget::MakeListViewWidget)
							.HeaderRow(
								SNew(SHeaderRow)
									+ SHeaderRow::Column("OldName").DefaultLabel(LOCTEXT("header_oldName", "Old name")).HAlignCell(HAlign_Left).HAlignHeader(HAlign_Left).ToolTipText(LOCTEXT("header_origMat_tooltip", "Original material name"))
									+ SHeaderRow::Column("texWidth").DefaultLabel(LOCTEXT("header_width", "Width")).HAlignCell(HAlign_Left).HAlignHeader(HAlign_Left).FixedWidth(50.0f).ToolTipText(LOCTEXT("header_texWidth_tooltip", "Texture width"))
									+ SHeaderRow::Column("texHeight").DefaultLabel(LOCTEXT("header_height", "Height")).HAlignCell(HAlign_Left).HAlignHeader(HAlign_Left).FixedWidth(50.0f).ToolTipText(LOCTEXT("header_texHeight_tooltip", "Texture height"))
									+ SHeaderRow::Column("ignore").DefaultLabel(LOCTEXT("header_noDraw", "ND")).HAlignCell(HAlign_Center).HAlignHeader(HAlign_Left).FixedWidth(24.0f).ToolTipText(LOCTEXT("header_noDraw_tooltip", "Toggle for nodraw"))
									+ SHeaderRow::Column("NewMat").DefaultLabel(LOCTEXT("header_material", "Material")).HAlignCell(HAlign_Center).HAlignHeader(HAlign_Center).FixedWidth(150.0f).ToolTipText(LOCTEXT("header_newMat_tooltip", "Unreal Engine material to use"))
									)
								]
							//]
						]
					]
				]
			+ SVerticalBox::Slot()
				.AutoHeight()
				.Padding(2)
				[
					SNew(SBorder)
					.Padding(FMargin(3))
					[
						SNew(SVerticalBox)
						+ SVerticalBox::Slot()
						.AutoHeight()
						[
							SNew(SHorizontalBox)
							+ SHorizontalBox::Slot()
							.AutoWidth()
							.Padding(FMargin(3.0f))
							.VAlign(VAlign_Center)
							.HAlign(HAlign_Center)
							[
								SNew(STextBlock)
								.Justification(ETextJustify::Center)
								.Text(FText::FromString(versionString))
							]
							+ SHorizontalBox::Slot()
							.FillWidth(2)
							.VAlign(VAlign_Center)
							[
								SNew(SButton)
								.Text(LOCTEXT("Import_goButton","Go"))
								.HAlign(HAlign_Center)
								.IsEnabled(this, &SHammerDialogWidget::CanConvert)
								.ContentPadding(3)
								.OnClicked(this, &SHammerDialogWidget::RunConvert)
								.ToolTipText(LOCTEXT("Import_goButton_tooltip","Import data"))
							]
							+ SHorizontalBox::Slot()
							.VAlign(VAlign_Center)
							.AutoWidth()
							[
								SNew(SButton)
								.Text(LOCTEXT("Import_instanceButton", "Go (for instances)"))
								.HAlign(HAlign_Center)
								.IsEnabled(this, &SHammerDialogWidget::CanConvert)
								.ContentPadding(3)
								.OnClicked(this, &SHammerDialogWidget::RunInstance)
								.ToolTipText(LOCTEXT("Import_instanceButton_tooltip", "Import data *as instance*"))
							]
						]
					]
				]
		];

	HammUErSettings::LoadConfig(false);
}

TSharedRef<ITableRow> SHammerDialogWidget::MakeListViewWidget(TSharedPtr<FMaterialListEntry> Item, const TSharedRef<STableViewBase>& OwnerTable)
{
	class SMaterialComboWidget : public SMultiColumnTableRow< TSharedPtr<FMaterialListEntry> >
	{
	public:
		SLATE_BEGIN_ARGS(SMaterialComboWidget){}
		SLATE_END_ARGS()

		TSharedPtr<SSpinBox<int32>> texWidthWidget, texHeightWidget;

		void Construct(const FArguments& InArgs, const TSharedRef<STableViewBase>& InOwnerTable, TSharedPtr<FMaterialListEntry> InItem)
		{
			Item = InItem;
			SMultiColumnTableRow< TSharedPtr<FMaterialListEntry> >::Construct(FSuperRowType::FArguments(), InOwnerTable);
		}

		TSharedRef<SWidget> HandleComboBoxGenerateWidget(TSharedPtr<FString> InItem)
		{
			return SNew(STextBlock)
				.Text(FText::FromString(*InItem));
		}
	
		FText HandleComboBoxText() const
		{
			if (Item->newMaterial == NULL)
				return FText::FromString("NOT FOUND");
			else
				return FText::FromString(Item->newMaterial->GetName());
		}

		void OnMaterialChanged(const FAssetData& AssetData)
		{
			Item->newMaterial = Cast<UMaterialInterface>(AssetData.GetAsset());
			if (Item->newMaterial != NULL)
			{
				FString name = Item->newMaterial->GetName();
				int masterIndex = HammUErSettings::FindInMaster(name);
				if (masterIndex > -1)
				{
					if (HammUErSettings::verboseDebugEnabled)
						UE_LOG(LogTemp, Log, TEXT("Found new material selected in master list, updating texture info"));
					texWidthWidget->SetValue(HammUErSettings::masterMaterialList[masterIndex]->textureWidth);
					texHeightWidget->SetValue(HammUErSettings::masterMaterialList[masterIndex]->textureHeight);
				}
				else
				{
					if (HammUErSettings::verboseDebugEnabled)
						UE_LOG(LogTemp, Log, TEXT("New material selected not in master list, updating texture info"));
					int height, width;
					HammUErSettings::GetMaterialSizes((UMaterial*)Item->newMaterial, width, height);
					texWidthWidget->SetValue(width);
					texHeightWidget->SetValue(height);
				}
			}
		}

		FString GetCurrentPath() const
		{
			if (Item->newMaterial)
				return Item->newMaterial->GetPathName();
			else
				return FString("");
		}

		ECheckBoxState GetIgnore() const
		{
			if (Item->ignore) return ECheckBoxState::Checked; else return ECheckBoxState::Unchecked;
		}

		void SetIgnore(ECheckBoxState inState)
		{
			Item->ignore = (inState == ECheckBoxState::Checked);
		}

		TSharedRef<SWidget> GenerateWidgetForColumn(const FName& ColumnName)
		{
			FText ItemText = FText::GetEmpty();
			if (ColumnName == "OldName")
			{
				ItemText = FText::FromString(Item->oldName);
				return SNew(STextBlock)
					.Margin(3.f)
					.Text(ItemText);
			}
			if (ColumnName == "texWidth")
			{
				return
					SAssignNew(texWidthWidget, SSpinBox<int32>)
					.ContentPadding(2.0f)
					.MinValue(1)
					.MaxValue(8192)
					.Value(Item->textureWidth)
					.OnValueChanged(Item.Get(), &FMaterialListEntry::SetTexWidth);
			}
			if (ColumnName == "ignore")
			{
				return
					SNew(SCheckBox)
					.IsChecked(this, &SMaterialComboWidget::GetIgnore)
					.OnCheckStateChanged(this, &SMaterialComboWidget::SetIgnore);
			}
			if (ColumnName == "texHeight")
			{
				return
					SAssignNew(texHeightWidget, SSpinBox<int32>)
					.ContentPadding(2.0f)
					.MinValue(1)
					.MaxValue(8192)
					.Value(Item->textureHeight)
					.OnValueChanged(Item.Get(), &FMaterialListEntry::SetTexHeight);
			}
			if (ColumnName == "NewMat")
			{
				return SNew(SObjectPropertyEntryBox)
					.ObjectPath(this, &SMaterialComboWidget::GetCurrentPath)
					.OnObjectChanged(this, &SMaterialComboWidget::OnMaterialChanged)
					.AllowClear(true)
					.AllowedClass(UMaterialInterface::StaticClass());
			}
			return SNew(STextBlock)
				.Text(FText::FromString("What"));
		}
		TSharedPtr<FMaterialListEntry> Item;
	};
	return SNew(SMaterialComboWidget, OwnerTable, Item);
}

bool SHammerDialogWidget::CanChooseFile() const
{
	return !firstPhaseHasRun;
}

bool SHammerDialogWidget::CanRunFirstPhase() const
{
	bool result = (VMFileName != "") && (FPaths::FileExists(VMFileName) && !firstPhaseHasRun);
	return result;
}

bool SHammerDialogWidget::CanConvert() const
{
	return firstPhaseHasRun;
}

bool SHammerDialogWidget::CanToggle() const
{
	return (materialListWidget->GetNumItemsSelected()>0);
}

FText SHammerDialogWidget::GetVMFileName() const
{
	return FText::FromString(VMFileName);
}

FText SHammerDialogWidget::GetImportDirName() const
{
	return FText::FromString(importDirName);
}

FReply SHammerDialogWidget::HandleChooseFileButtonClicked()
{
	
	FString ExtensionStr = TEXT("All supported formats|*.vmf;*.map;*.proc|Valve Hammer Map File|*.vmf|Quake/Doom3 Map File|*.map|Doom3 Proc File|*.proc");
	IDesktopPlatform* DesktopPlatform = FDesktopPlatformModule::Get();
	firstPhaseHasRun = false;
	bool bOpen = false;
	if (DesktopPlatform)
	{
		void* ParentWindowWindowHandle = NULL;

		IMainFrameModule& MainFrameModule = FModuleManager::LoadModuleChecked<IMainFrameModule>(TEXT("MainFrame"));
		const TSharedPtr<SWindow>& MainFrameParentWindow = MainFrameModule.GetParentWindow();
		if (MainFrameParentWindow.IsValid() && MainFrameParentWindow->GetNativeWindow().IsValid())
			ParentWindowWindowHandle = MainFrameParentWindow->GetNativeWindow()->GetOSWindowHandle();

		TArray<FString> FileNames;
		bOpen = DesktopPlatform->OpenFileDialog(ParentWindowWindowHandle, "Open file", HammUErSettings::previousDirectory, "", ExtensionStr, EFileDialogFlags::None, FileNames);
		if (bOpen)
		{
			if (FileNames.Num() == 1)
			{
				VMFileName = FileNames[0];
				HammUErSettings::previousDirectory = FPaths::GetPath(FileNames[0]);
			}
			else
				UE_LOG(LogTemp, Error, TEXT("Pick one file!"));
		}
	}
	materialList.Empty();
//	importDirName = "";
	importDirBlock->SetText(FText::FromString(""));
	materialListWidget->RequestListRefresh();
	return FReply::Handled();
}

void SHammerDialogWidget::WriteMaterialFile()
{
	if (!HammUErSettings::generateVMFList)
		return;
	FString SaveFile = VMFileName + "materialList";
	FString SaveText;
	for (int i = 0; i < materialList.Num(); i++)
	{
		// make sure there's no 0x0 textures in there anywhere
		if (materialList[i]->textureWidth < 1 || materialList[i]->textureWidth > 65535)
			materialList[i]->textureWidth = 1;
		if (materialList[i]->textureHeight < 1 || materialList[i]->textureHeight > 65535)
			materialList[i]->textureHeight = 1;

		SaveText += materialList[i]->oldName + "," + FString::FromInt(materialList[i]->textureWidth) + "," + FString::FromInt(materialList[i]->textureHeight) + "," + FString::FromInt((int)materialList[i]->ignore)+",";
		if (materialList[i]->newMaterial != NULL)
			SaveText += materialList[i]->newMaterial->GetName();
		SaveText += "\r\n";
	}
	FFileHelper::SaveStringToFile(SaveText, *SaveFile);
}

void SHammerDialogWidget::ReadMaterialFile()
{
	FString SaveFile = VMFileName + "materialList";
	TArray <FString> materialLines;
	FString oldmatname;
	FString newmatname;
	FString newmatdir;

	if (FFileHelper::LoadANSITextFileToStrings(*(SaveFile), NULL, materialLines))
	{
		if (HammUErSettings::verboseDebugEnabled) UE_LOG(LogTemp, Log, TEXT("Found a VMF specific material file, reading..."));
		TArray<TSharedPtr<FMaterialListEntry>> oldMaterialList = TArray<TSharedPtr<FMaterialListEntry>>(materialList);
		materialList.Empty();
		materialListIndex.Empty();

		TSharedPtr<FMaterialListEntry> newEntry;
		bool rewrite = false;

		FString tempTest = "";
		int32 tempint, tempint2, tempint3;


		for (int i = 0; i < materialLines.Num(); i++)
		{
			int32 commaposition = materialLines[i].Find(TEXT(","), ESearchCase::IgnoreCase, ESearchDir::FromStart, 0);
			oldmatname = materialLines[i].Mid(0, commaposition);
			if (oldmatname == "")
				continue;
			materialLines[i].RemoveAt(0, commaposition + 1);
			materialLines[i].TrimStartInline();
			commaposition = materialLines[i].Find(TEXT(","), ESearchCase::IgnoreCase, ESearchDir::FromStart, 0);
			tempint = FCString::Atoi(*materialLines[i].Mid(0, commaposition));
			materialLines[i].RemoveAt(0, commaposition + 1);
			materialLines[i].TrimStartInline();
			commaposition = materialLines[i].Find(TEXT(","), ESearchCase::IgnoreCase, ESearchDir::FromStart, 0);
			tempint2 = FCString::Atoi(*materialLines[i].Mid(0, commaposition));
			materialLines[i].RemoveAt(0, commaposition + 1);
			materialLines[i].TrimStartInline();
			commaposition = materialLines[i].Find(TEXT(","), ESearchCase::IgnoreCase, ESearchDir::FromStart, 0);
			tempint3 = FCString::Atoi(*materialLines[i].Mid(0, commaposition));
			materialLines[i].RemoveAt(0, commaposition + 1);
			materialLines[i].TrimStartInline();
			newmatname = materialLines[i];
			newmatdir = "";
			if (newmatname.Contains("/"))
			{
				FString temp = newmatname;
				int32 slashpos = newmatname.Find("/", ESearchCase::IgnoreCase, ESearchDir::FromEnd);
				newmatname = newmatname.Mid(slashpos + 1);
				temp.RemoveAt(slashpos, temp.Len() - slashpos);
				if (temp.Contains("/"))
				{
					slashpos = newmatname.Find("/", ESearchCase::IgnoreCase, ESearchDir::FromEnd);
					newmatdir = temp.Mid(slashpos + 1);
				}
				else
					newmatdir = temp;
			}

			if (!oldMaterialList.ContainsByPredicate([&](TSharedPtr<FMaterialListEntry> result) {return result->oldName == oldmatname; }))
			{
				UE_LOG(LogTemp, Warning, TEXT("! Found material in material list not in VMF file. Ignoring."));
				rewrite = true;
				continue;
			}
			int masterIndex = HammUErSettings::FindInMaster(oldmatname);
			if (masterIndex != -1)
			{
				if (HammUErSettings::verboseDebugEnabled)UE_LOG(LogTemp, Log, TEXT("+ Material already exists in master list. Is it different?"));
				if ((HammUErSettings::masterMaterialList[masterIndex]->newMaterial == NULL &&newmatname == ""))
				{
					HammUErSettings::masterMaterialList.RemoveAt(masterIndex);
					if (HammUErSettings::verboseDebugEnabled)UE_LOG(LogTemp, Log, TEXT("Yes, old one was empty, removed."));
				}
				else
					if ((HammUErSettings::masterMaterialList[masterIndex]->newMaterial != NULL && newmatname != "" && 
						(HammUErSettings::masterMaterialList[masterIndex]->newMaterial->GetName() != newmatname) && 
						(HammUErSettings::masterMaterialList[masterIndex]->newMaterial->GetName() != oldmatname)) ||
						((tempint!=HammUErSettings::defaultWidth&&tempint2!=HammUErSettings::defaultHeight)&&
						 ((tempint != HammUErSettings::masterMaterialList[masterIndex]->textureWidth) ||
						 (tempint2 != HammUErSettings::masterMaterialList[masterIndex]->textureHeight))
					    ))
					{
						HammUErSettings::masterMaterialList.RemoveAt(masterIndex);
						if (HammUErSettings::verboseDebugEnabled)
						{
							UE_LOG(LogTemp, Log, TEXT("Yes, old one was not empty, but the names/texture info doesn't match."));
							if (HammUErSettings::masterMaterialList[masterIndex]->newMaterial->GetName() != newmatname)
								UE_LOG(LogTemp, Log, TEXT("REASON: NMN %s != %s"), *HammUErSettings::masterMaterialList[masterIndex]->newMaterial->GetName(), *newmatname);
							if (HammUErSettings::masterMaterialList[masterIndex]->newMaterial->GetName() != oldmatname)
								UE_LOG(LogTemp, Log, TEXT("REASON: OMN %s != %s"), *HammUErSettings::masterMaterialList[masterIndex]->newMaterial->GetName(), *oldmatname);
							if ((tempint != HammUErSettings::masterMaterialList[masterIndex]->textureWidth))
								UE_LOG(LogTemp, Log, TEXT("REASON: TextureWidth %s != %s"), *FString::FromInt(tempint), *FString::FromInt(HammUErSettings::masterMaterialList[masterIndex]->textureWidth));
							if ((tempint2 != HammUErSettings::masterMaterialList[masterIndex]->textureHeight))
								UE_LOG(LogTemp, Log, TEXT("REASON: TextureWidth %s != %s"), *FString::FromInt(tempint2), *FString::FromInt(HammUErSettings::masterMaterialList[masterIndex]->textureHeight));
						}
					}
					else
						if (HammUErSettings::masterMaterialList[masterIndex]->newMaterial != NULL && newmatname == "")
						{
							materialList.Add(HammUErSettings::masterMaterialList[masterIndex]);
							materialListIndex.Add(masterIndex);
							if (HammUErSettings::verboseDebugEnabled)UE_LOG(LogTemp, Log, TEXT("Yes, but it is blank, so we're keeping the old one."));
							continue;
						}
						else
						{
							materialList.Add(HammUErSettings::masterMaterialList[masterIndex]);
							materialListIndex.Add(masterIndex);
							if (HammUErSettings::verboseDebugEnabled)UE_LOG(LogTemp, Log, TEXT("No."));
							continue;
						}
			}
			newEntry = MakeShareable(new FMaterialListEntry());
			newEntry->textureHeight = tempint2;
			newEntry->textureWidth = tempint;
			newEntry->oldName = oldmatname;
			newEntry->ignore = (tempint3==1);
			int index = -1;

			TArray<int32> possiblesList;

			if (newmatname == "")
			{
				possiblesList.Empty();
				tempTest = oldmatname.Mid(oldmatname.Find("/", ESearchCase::IgnoreCase, ESearchDir::FromEnd) + 1, oldmatname.Len());
				if (tempTest == "")
				{
					newEntry->newMaterial = NULL;
					newEntry->newMaterialName = "";
					newEntry->AssetDatabaseIndex = -1;
					materialListIndex.Add(-1);
					continue;
				}
				for (int j = 0; j < HammUErSettings::AssetData.Num(); j++) // run everything to find all possible matches, so we don't run everything twice
				{
					if (HammUErSettings::AssetData[j].AssetName.ToString().ToUpper().Contains(tempTest.ToUpper()))
						possiblesList.Add(j);
				}
				for (int j = 0; j < possiblesList.Num(); j++)
				{
					if ((HammUErSettings::AssetData[possiblesList[j]].AssetName.ToString().ToUpper() == tempTest.ToUpper()) || (HammUErSettings::AssetData[possiblesList[j]].AssetName.ToString().ToUpper() == (tempTest + "_mat").ToUpper()))
					{
						index = possiblesList[j];
						if (HammUErSettings::verboseDebugEnabled)UE_LOG(LogTemp, Log, TEXT("Found a direct match in the asset database for unspecified material %s"), (*tempTest));
						break;
					}
				}
				if (possiblesList.Num() > 0 && index == -1)  // pick the first one
				{
					index = 0;
					if (HammUErSettings::verboseDebugEnabled)UE_LOG(LogTemp, Log, TEXT("No direct match in the asset database for unspecified material, picking close candidate %s"), *HammUErSettings::AssetData[possiblesList[index]].AssetName.ToString());
				}
				if (index > -1)
				{
					newEntry->newMaterialName = (HammUErSettings::AssetData[index].ObjectPath).ToString();
					newEntry->AssetDatabaseIndex = index;
					newEntry->newMaterial = NULL;//(UMaterial*)HammUErSettings::AssetData[index].GetAsset();
					materialListIndex.Add(index);
				}
				else
				{
					newEntry->newMaterialName = "";
					newEntry->AssetDatabaseIndex = -1;
					newEntry->newMaterial = NULL;
					materialListIndex.Add(-1);
				}
			}
			else
			{
				possiblesList.Empty();
				for (int j = 0; j < HammUErSettings::AssetData.Num(); j++)
				{
					if (HammUErSettings::AssetData[j].AssetName.ToString().Contains(newmatname))
					{
						if (newmatdir != "")
						{
							FString testdir = HammUErSettings::AssetData[j].PackagePath.ToString();
							if (testdir.Contains(newmatdir))
								possiblesList.Add(j);
						}
						else
							possiblesList.Add(j);
					}
				}
				for (int j = 0; j < possiblesList.Num(); j++)
				{
					FString upperVersion = HammUErSettings::AssetData[possiblesList[j]].AssetName.ToString().ToUpper();
					if ((upperVersion == newmatname.ToUpper()) || 
						(upperVersion == (newmatname + "_mat").ToUpper()) || 
						(upperVersion == oldmatname.ToUpper()) ||
						(upperVersion == (oldmatname + "_mat").ToUpper())
						)
					{
							index = possiblesList[j];
							if (HammUErSettings::verboseDebugEnabled)UE_LOG(LogTemp, Log, TEXT("Found a direct match in the asset database for specified material %s"), (*newmatname));
							break;
					}
				}
				if (possiblesList.Num() > 0 && index == -1)  // pick the first one
				{
					index = 0;
					if (HammUErSettings::verboseDebugEnabled)UE_LOG(LogTemp, Log, TEXT("No direct match in the asset database for specified material, picking close candidate %s"), *HammUErSettings::AssetData[possiblesList[index]].AssetName.ToString());
				}

				if (index > -1)
				{
					newEntry->newMaterialName = (HammUErSettings::AssetData[index].ObjectPath).ToString();
					newEntry->AssetDatabaseIndex = index;
					newEntry->newMaterial = NULL; //(UMaterial*)HammUErSettings::AssetData[index].GetAsset();
					materialListIndex.Add(index);
				}
				else
				{
					newEntry->newMaterialName = "";
					newEntry->AssetDatabaseIndex = index;
					newEntry->newMaterial = NULL;
					materialListIndex.Add(index);

				}
				newEntry->ignore = false;
				if (newEntry->oldName.Contains("nodraw") || newEntry->oldName.ToLower() == "clip" || newEntry->oldName.ToLower() == "origin" || newEntry->oldName.Contains("toolsorigin") || newEntry->oldName.Contains("toolsclip"))
					newEntry->ignore = true;

				materialList.AddUnique(newEntry);
				HammUErSettings::masterMaterialList.AddUnique(newEntry);
			}
		}
		TArray<int> oldPositions;
		oldPositions.AddZeroed(oldMaterialList.Num());
		for (int i = 0; i < oldMaterialList.Num(); i++)  // did anything change or get added?
		{
			if (HammUErSettings::FindInMaster(oldMaterialList[i]->oldName)==-1)//!HammUErSettings::masterMaterialList.ContainsByPredicate([&](TSharedPtr<FMaterialListEntry> other) {return other->oldName == oldMaterialList[i]->oldName; }))
			{
				if (oldMaterialList[i]->oldName.Contains("nodraw") || oldMaterialList[i]->oldName.ToLower() == "clip" || oldMaterialList[i]->oldName.ToLower() == "origin" || oldMaterialList[i]->oldName.Contains("toolsorigin") || oldMaterialList[i]->oldName.Contains("toolsclip"))
					oldMaterialList[i]->ignore = true;
				materialList.AddUnique(oldMaterialList[i]);
				materialListIndex.Add(-1);
				HammUErSettings::masterMaterialList.AddUnique(oldMaterialList[i]);
				rewrite = true;
				if (HammUErSettings::verboseDebugEnabled)UE_LOG(LogTemp, Log, TEXT("Found a material in the VMF not in the material list or master list. Adding..."));
			}
			if (!materialList.ContainsByPredicate([&](TSharedPtr<FMaterialListEntry> other) {return other->oldName == oldMaterialList[i]->oldName; }))
			{
				materialList.AddUnique(oldMaterialList[i]);
				materialListIndex.Add(-1);
				rewrite = true;
				if (HammUErSettings::verboseDebugEnabled)UE_LOG(LogTemp, Log, TEXT("Found a material in the VMF not in the material list but in the master list. Adding..."));
			}
			if (oldMaterialList[i]->oldName == materialList[i]->oldName)
				oldPositions[i] = i;		// stayed in the same position!
			else
			{
				int32 newpos = materialList.IndexOfByPredicate([&](TSharedPtr<FMaterialListEntry> other) {return other->oldName == oldMaterialList[i]->oldName; });  // just futzed with this
				if (newpos == -1)
					UE_LOG(LogTemp, Error, TEXT("You should never get this message?"));
				oldPositions[i] = newpos;
			}
		}
		if (oldPositions.Num() != materialList.Num())
			UE_LOG(LogTemp, Error, TEXT("MATERIAL COUNT MISMATCH"));

		TArray<TSharedPtr<FMaterialListEntry>> tempList;

		for (int i = 0; i < oldPositions.Num(); i++)
			tempList.Add(materialList[oldPositions[i]]);

		materialList = tempList;

		if (rewrite)
			WriteMaterialFile();
	}
}

FReply SHammerDialogWidget::RunFirstPhase()
{
/*	UWorld* EditorWorld = GEditor->GetEditorWorldContext().World();
	if (EditorWorld)
	{
		FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");
		TArray<FAssetData> AssetData;
		AssetRegistryModule.Get().GetAssetsByClass("World", AssetData, true);
		int index = AssetData.IndexOfByPredicate([](FAssetData fa) {return fa.ObjectPath.ToString().Contains("shittygallery"); });
		TArray<FString> WorldList;
		WorldList.Add(AssetData[index].PackageName.ToString());

		ULevel* testLevel = EditorLevelUtils::AddLevelsToWorld(EditorWorld, WorldList, ULevelStreamingKismet::StaticClass());
		if (testLevel == NULL)
			UE_LOG(LogTemp, Log, TEXT("Could not add level."));
		
		TWeakPtr<FStreamingLevelCollectionModel>	WorldModel;


		//testLevel->ApplyWorldOffset(FVector(0, 500, 20));
		
	}*/

	if (VMFileName != "")
	{
		if (HammUErSettings::verboseDebugEnabled)UE_LOG(LogTemp, Log, TEXT("Reloading master material list..."));
		HammUErSettings::LoadConfig(true);

		MapFileLoader::Open(VMFileName);
		MapFileLoader::Set(MapSettingType::ConversionRate, HammUErSettings::localConversionRate);
		MapFileLoader::Set(MapSettingType::RoundPoints, HammUErSettings::roundPoints);
		MapFileLoader::Set(MapSettingType::RoundMeshPoints, HammUErSettings::roundMeshPoints);
		MapFileLoader::Set(MapSettingType::DiscardErrorRange, HammUErSettings::discardErrorRange);
		MapFileLoader::Set(MapSettingType::IntersectRange, HammUErSettings::intersectRange);
		MapFileLoader::Set(MapSettingType::SmoothingAngle, HammUErSettings::smoothingAngle);
		MapFileLoader::Set(MapSettingType::SmoothWeldRange, HammUErSettings::smoothWeldRange);
		MapFileLoader::Set(MapSettingType::DontSmooth, HammUErSettings::doNotUseSmoother);
		MapFileLoader::Set(MapSettingType::DispAlphaChannel, (float)HammUErSettings::defaultDisplacementAlphaChannel);
		MapFileLoader::Set(MapSettingType::PatchDivH, (float)HammUErSettings::patchSubDivH);
		MapFileLoader::Set(MapSettingType::PatchDivV, (float)HammUErSettings::patchSubDivV);
		MapFileLoader::Set(MapSettingType::RoundDisplacementPoints, HammUErSettings::roundDisplacementPoints);

		if (!MapFileLoader::PhaseOne())
		{
			UE_LOG(LogTemp, Error, TEXT("Something went wrong trying to read the file!"));
			return FReply::Handled();
		}

		TArray<FString> inList = MapFileLoader::GetMaterials();
		materialList.Empty();
		if (HammUErSettings::verboseDebugEnabled)UE_LOG(LogTemp, Log, TEXT("Checking master material list for matches..."));
		TSharedPtr<FMaterialListEntry> newEntry;

		FScopedSlowTask SlowTask(inList.Num(), FText::FromString("Checking asset database for matches..."));
		SlowTask.MakeDialog();

		for (int i = 0; i < inList.Num(); i++)
		{
			SlowTask.EnterProgressFrame(1);
			int32 masterIndex = HammUErSettings::FindInMaster(inList[i]);
			if (masterIndex != -1)
			{
				if (HammUErSettings::verboseDebugEnabled)UE_LOG(LogTemp, Log, TEXT("Found %s"), *inList[i]);
				materialList.Add(MakeShareable(new FMaterialListEntry(HammUErSettings::masterMaterialList[masterIndex])));
				materialListIndex.Add(masterIndex);
				materialList[materialList.Num() - 1]->oldName = inList[i];
				materialList[materialList.Num() - 1]->newMaterial = NULL;
				if (HammUErSettings::AssetData.Num() > 0)
				{
					if (HammUErSettings::masterMaterialList[masterIndex]->AssetDatabaseIndex > -1)
						materialList[materialList.Num() - 1]->newMaterial = (UMaterial*)HammUErSettings::AssetData[HammUErSettings::masterMaterialList[masterIndex]->AssetDatabaseIndex].GetAsset();
				}
			}
			else
			{
				if (HammUErSettings::verboseDebugEnabled)UE_LOG(LogTemp, Warning, TEXT("Did not find %s in the master list, checking asset database"), *inList[i]);
				newEntry = MakeShareable(new FMaterialListEntry());
				newEntry->oldName = inList[i];
				if (HammUErSettings::verboseDebugEnabled)
					newEntry->newMaterial = HammUErSettings::MaterialInAssetDatabase(inList[i]);  // we already know it's not in the master list, but maybe it's just not been added yet?
				if (newEntry->newMaterial)
				{
					int width, height;
					HammUErSettings::GetMaterialSizes((UMaterial*)newEntry->newMaterial, width, height);
					newEntry->textureWidth = width;
					newEntry->textureHeight = height;
					newEntry->newMaterialName = newEntry->newMaterial->GetPathName();
					if (HammUErSettings::verboseDebugEnabled)UE_LOG(LogTemp, Log, TEXT("+ found a material for %s"), *inList[i]);
				}
				else
				{
					newEntry->textureWidth = HammUErSettings::defaultWidth;
					newEntry->textureHeight = HammUErSettings::defaultHeight;
					newEntry->newMaterialName = "";
					if (HammUErSettings::verboseDebugEnabled)UE_LOG(LogTemp, Error, TEXT("- did not find a material for %s"), *inList[i]);
				}
				newEntry->ignore = false;
				if (newEntry->oldName.Contains("nodraw") || newEntry->oldName.ToLower() == "clip" || newEntry->oldName.ToLower() == "origin" || newEntry->oldName.Contains("toolsorigin") || newEntry->oldName.Contains("toolsclip"))
					newEntry->ignore = true;
				materialList.Add(newEntry);
				materialListIndex.Add(HammUErSettings::masterMaterialList.AddUnique(newEntry));
			}
		}
		firstPhaseHasRun = true;
		if (!FPlatformFileManager::Get().GetPlatformFile().FileExists(*(VMFileName + "materialList")) && (HammUErSettings::generateVMFList))
		{
			WriteMaterialFile();
			FMessageDialog::Open(EAppMsgType::Ok, FText::FromString("Created a material list file in the vmf directory.\nFor a VMF with many materials, it's easier to edit that and re-open."));
			//firstPhaseHasRun = false;
		}
		else
			ReadMaterialFile();
		materialListWidget->RequestListRefresh();
		importDirName = FPaths::GetBaseFilename(VMFileName, true);
		if (HammUErSettings::defaultImportHeader != "")
		{
			if (HammUErSettings::defaultImportHeader.StartsWith("/"))
				HammUErSettings::defaultImportHeader.RemoveFromStart("/");
			if (HammUErSettings::defaultImportHeader.EndsWith("/"))
				HammUErSettings::defaultImportHeader.RemoveFromEnd("/");
			importDirName = HammUErSettings::defaultImportHeader + "/" + importDirName;
		}
		importDirName = importDirName.Replace(TEXT("."), TEXT("_"));
		importDirName = importDirName.Replace(TEXT(","), TEXT("_"));
		importDirName = importDirName.Replace(TEXT(";"), TEXT("_"));
		importDirName = importDirName.Replace(TEXT(":"), TEXT("_"));
		importDirName = importDirName.Replace(TEXT("="), TEXT("_"));
		importDirName = importDirName.Replace(TEXT("!"), TEXT("_"));
		importDirName = importDirName.Replace(TEXT(" "), TEXT("_"));
		importDirBlock->SetText(FText::FromString(importDirName));
		UE_LOG(LogTemp, Log, TEXT("Waiting for user input..."));
	}
	return FReply::Handled();
}

FReply SHammerDialogWidget::RunToggle()
{
	if (materialListWidget->GetNumItemsSelected() > 0)
	{
		TArray<TSharedPtr<FMaterialListEntry>> selectedList = materialListWidget->GetSelectedItems();
		for (int i = 0; i < selectedList.Num(); i++)
			selectedList[i]->ignore = !selectedList[i]->ignore;
	}
	materialListWidget->RequestListRefresh();
	return FReply::Handled();
}

FReply SHammerDialogWidget::RunInstance()
{
	FString InstanceFileName = FPaths::ProjectConfigDir() + "instance_data/" + FPaths::GetBaseFilename(VMFileName) + ".hi";
	MapFileLoader::ToggleInstance(true);
	MapFileLoader::SetInstanceFilename(InstanceFileName);
	RunConvert();
	MapFileLoader::ToggleInstance(false);
	HammUErSettings::AddInstance(FPaths::GetCleanFilename(VMFileName), InstanceFileName);

	return FReply::Handled();
}


FReply SHammerDialogWidget::RunConvert()
{
	FScopedSlowTask SlowTask(6, FText::FromString("Importing map..."));
	SlowTask.MakeDialog();
	GEditor->SelectNone(true, true, false); // make sure we unselect everything, otherwise it crashes
	FString oldName;
	HammUErSettings::toDeleteList.Empty();

	if (HammUErSettings::reimportCleanup)
	{
		FString testhead = FPaths::GetBaseFilename(VMFileName);
		testhead = testhead.Replace(TEXT(" "), TEXT("_"));
		testhead = testhead.Replace(TEXT("!"), TEXT("I"));

		UWorld* myWorld = GEditor->GetEditorWorldContext().World();
		if (myWorld != NULL)
		{
			for (TActorIterator<AStaticMeshActor> ActorIterator(myWorld); ActorIterator; ++ActorIterator)
			{
				if (ActorIterator->GetName().StartsWith(testhead))
					HammUErSettings::toDeleteList.AddUnique(ActorIterator->GetName());
			}
		}
		else
			UE_LOG(LogTemp, Error, TEXT("Could not get engine world."));
		
	}

	SlowTask.EnterProgressFrame(1);
	if (materialList.Num() == materialListIndex.Num())
	{
	
			for (int i = 0; i < materialListIndex.Num(); i++)
			if (materialListIndex[i] != -1)
			{
				oldName = HammUErSettings::masterMaterialList[materialListIndex[i]]->oldName;
				HammUErSettings::masterMaterialList[materialListIndex[i]] = materialList[i];
				HammUErSettings::masterMaterialList[materialListIndex[i]]->oldName = oldName;
			}
	}
	else
	{
		for (int i = 0; i < materialList.Num(); i++)
		{
			int index = HammUErSettings::FindInMaster(materialList[i]->oldName);
			if (index != -1)
			{
				oldName = HammUErSettings::masterMaterialList[index]->oldName;
				HammUErSettings::masterMaterialList[index] = materialList[i];
				HammUErSettings::masterMaterialList[index]->oldName = oldName;
			}
		}
	}

	HammUErSettings::SaveConfig();
	SlowTask.EnterProgressFrame(1);

	TArray<UMaterialInterface*> newMaterials;
	TArray<int32> textureWidths;
	TArray<int32> textureHeights;
	TArray<bool> textureNoDraws;

	textureWidths.Empty();
	textureHeights.Empty();
	textureNoDraws.Empty();
	newMaterials.Empty();

	WriteMaterialFile();
	SlowTask.EnterProgressFrame(1);

	for (int i = 0; i < materialList.Num(); i++)
	{
		newMaterials.Add(materialList[i]->newMaterial);
		textureNoDraws.Add(materialList[i]->ignore);
		if (materialList[i]->newMaterial)
		{
			if (materialList[i]->textureWidth<1)
				textureWidths.Add(HammUErSettings::defaultWidth);
			else
				textureWidths.Add(materialList[i]->textureWidth);
			if (materialList[i]->textureHeight<1)
				textureHeights.Add(HammUErSettings::defaultHeight);
			else
				textureHeights.Add(materialList[i]->textureHeight);
		}
		else
		{
			if (MapFileLoader::textureCheat)
			{
				textureWidths.Add(-451); // special case for non-found textures
				textureHeights.Add(-451);
			}
			else
			{
				textureWidths.Add(HammUErSettings::defaultWidth);
				textureHeights.Add(HammUErSettings::defaultHeight);
			}
		}
	}

	importDirName = importDirName.Replace(TEXT(" "), TEXT("_"));
	importDirName = importDirName.Replace(TEXT("*"), TEXT("X"));
	importDirName = importDirName.Replace(TEXT("?"), TEXT("Q"));
	importDirName = importDirName.Replace(TEXT(":"), TEXT("_"));
	importDirName = importDirName.Replace(TEXT("!"), TEXT("I"));
	importDirName = importDirName.Replace(TEXT("."), TEXT("-"));
	importDirName = importDirName.Replace(TEXT("&"), TEXT("_"));

	MapFileLoader::SetImportDir(importDirName);
	SlowTask.EnterProgressFrame(1);
	MapFileLoader::PhaseTwo(textureWidths, textureHeights, textureNoDraws);
	SlowTask.EnterProgressFrame(1);
	MapFileLoader::ImportIntoWorld(newMaterials, true);
	SlowTask.EnterProgressFrame(1);
	textureWidths.Empty();
	textureHeights.Empty();
	textureNoDraws.Empty();
	newMaterials.Empty();

	if (HammUErSettings::toDeleteList.Num() > 0)
	{
		UWorld* myWorld = GEditor->GetEditorWorldContext().World();
		if (myWorld != NULL)
		{
			for (TActorIterator<AStaticMeshActor> ActorIterator(myWorld); ActorIterator; ++ActorIterator)
			{
				if (HammUErSettings::toDeleteList.Contains(ActorIterator->GetName()))
				{
					ActorIterator->K2_DestroyActor();
					HammUErSettings::toDeleteList.Remove(ActorIterator->GetName());
				}
			}
			GEngine->ForceGarbageCollection(true);
		}
		if (HammUErSettings::toDeleteList.Num() > 0)
		{
			UE_LOG(LogTemp, Warning, TEXT("Problem deleting extraneous brushes?"));
			for (int i = 0; i < HammUErSettings::toDeleteList.Num(); i++)
				UE_LOG(LogTemp, Warning, TEXT("%i %s"), i, *HammUErSettings::toDeleteList[i]);
			HammUErSettings::toDeleteList.Empty();
		}
	}

	firstPhaseHasRun = false;
	return FReply::Handled();
}

void SHammerDialogWidget::OnFileNameChanged(const FText& InLabel)
{
	VMFileName = InLabel.ToString();
}

void SHammerDialogWidget::OnImportDirNameChanged(const FText& InLabel)
{
	FString newItem = InLabel.ToString();
	newItem.TrimStartInline();
	newItem.TrimEndInline();
	while (newItem.StartsWith("/"))
		newItem.RemoveFromStart("/");
	while (newItem.EndsWith("/"))
		newItem.RemoveFromEnd("/");

	newItem = newItem.Replace(TEXT(" "), TEXT("_"));
	newItem = newItem.Replace(TEXT("*"), TEXT("X"));
	newItem = newItem.Replace(TEXT("?"), TEXT("Q"));
	newItem = newItem.Replace(TEXT("!"), TEXT("I"));
	newItem = newItem.Replace(TEXT(":"), TEXT("_"));
	newItem = newItem.Replace(TEXT("."), TEXT("-"));
	newItem = newItem.Replace(TEXT("&"), TEXT("_"));

	importDirName = newItem;
}

void SHammerDialogWidget::OnSeekNameChanged(const FText& InLabel, ETextCommit::Type TextType)
{
	if (TextType == ETextCommit::OnEnter || TextType == ETextCommit::Default || TextType == ETextCommit::OnUserMovedFocus)
	{
		seekName = InLabel.ToString();

		TArray<int32> selectionList;


		for (int i = 0; i < materialList.Num(); i++)
		{
			if (materialList[i]->oldName.Contains(seekName))
				selectionList.Add(i);
		}
		if (selectionList.Num()>0)
		{
			materialListWidget->ClearSelection();
			for (int count = 0; count < selectionList.Num(); count++)
				materialListWidget->SetItemSelection(materialList[selectionList[count]], true, ESelectInfo::Direct);
			if (!materialListWidget->IsItemVisible(materialList[selectionList[0]]))
				materialListWidget->RequestScrollIntoView(materialList[selectionList[0]]);
		}
	}
}

FText SHammerDialogWidget::GetSeekName() const
{
	return FText::FromString(seekName);
}

#undef LOCTEXT_NAMESPACE