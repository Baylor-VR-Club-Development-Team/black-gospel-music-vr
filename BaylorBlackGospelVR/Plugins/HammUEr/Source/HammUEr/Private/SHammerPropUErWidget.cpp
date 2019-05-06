// HammUEr
// Copyright 2015-2016 Turfster / NT Entertainment
// All Rights Reserved.


// This code is held together with kitten whiskers and toothpicks.
// There's nothing to see or learn here.
// Seriously.
// Turn back.

#include "HammUErPrivatePCH.h"
#include "SHammerPropUErWidget.h"
#include "ModelFormats/SMDLoader.h"
#include "ModelFormats/MDLLoader.h"
#include "ModelFormats/LWOLoader.h"
#include "ModelFormats/ASELoader.h"
#include "ModuleManager.h"
#include "DesktopPlatformModule.h"
#include "MainFrame.h"
#include "SRotatorInputBox.h"
#include "HammUErSettings.h"

#include "AssetRegistryModule.h"
#include "MapShared/VMFTri.h"
#include "MapShared/MAPConverters.h"
#include "ArrayStructs.h"

#include "TextureManipulation.h"

#include "ObjectTools.h"

#include <algorithm>
#include <fstream>
#include <locale>

#define LOCTEXT_NAMESPACE "SHammerPropUErWidget"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SHammerPropUErWidget::Construct(const FArguments & InArgs)
{
	FString imagePath = FPaths::ProjectPluginsDir() + TEXT("HammUEr/Resources/headertest.png");
	if (!FPaths::FileExists(imagePath))
		imagePath = FPaths::EnginePluginsDir() + TEXT("HammUEr/Resources/headertest.png");
	FName brushName = FName(*imagePath);
	ChildSlot
		[
			SNew(SBox)
			.WidthOverride(400)
			.Padding(2)
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
					.MaxDesiredWidth(400)
					.HeightOverride(40)
					[
					SNew(SImage)
					.Image(new FSlateDynamicImageBrush(brushName, FVector2D(400, 40), FLinearColor::White, ESlateBrushTileType::NoTile, ESlateBrushImageType::FullColor))
					]
				]
				+ SVerticalBox::Slot()
				.Padding(3.0f, 1.0f)
				.AutoHeight()
				[
					SNew(SBox)
					.WidthOverride(450)
					[
						SNew(SBorder)
						.Padding(FMargin(3))
						[
							SNew(SVerticalBox)
							+ SVerticalBox::Slot()
							.Padding(FMargin(3))
							.AutoHeight()
							[
								SNew(SHorizontalBox)
								+ SHorizontalBox::Slot()
								.VAlign(VAlign_Center)
								.MaxWidth(100.f)
								.AutoWidth()
								[
									SNew(STextBlock)
									.Text(LOCTEXT("import_textureDirectory", "Import to: "))
								]
								+ SHorizontalBox::Slot()
								.VAlign(VAlign_Center)
								[
									SNew(SEditableTextBox)
									.BackgroundColor(FSlateColor(FLinearColor(FColor::White)))
									.OnTextCommitted(this, &SHammerPropUErWidget::ModelDirectoryChanged)
									.Text(this, &SHammerPropUErWidget::GetModelImportDirectory)
									.ToolTipText(FText::FromString(TEXT("Content directory to import models to")))
								]
							]
							+ SVerticalBox::Slot()
							.AutoHeight()
							.VAlign(VAlign_Center)
							.Padding(FMargin(3))
							[
								SNew(SHorizontalBox)
								+ SHorizontalBox::Slot()
								.AutoWidth()
								.MaxWidth(150.f)
								.VAlign(VAlign_Center)
								[
									SNew(SButton)
									.Text(LOCTEXT("import_sourcedirectory", "Choose source directory"))
									.ToolTipText(FText::FromString(TEXT("Directory containing supported model files you want to import")))
									.HAlign(HAlign_Center)
									.IsEnabled(this, &SHammerPropUErWidget::CanImport)
									.OnClicked(this, &SHammerPropUErWidget::GetImportDir)
								]
								+ SHorizontalBox::Slot()
								.AutoWidth()
								.MaxWidth(150.f)
								.VAlign(VAlign_Center)
								[
									SNew(SButton)
									.Text(LOCTEXT("import_go", "Get list of items"))
									.HAlign(HAlign_Center)
									.IsEnabled(this, &SHammerPropUErWidget::CanRunGetter)
									.OnClicked(this, &SHammerPropUErWidget::RunGetter)
								]
								+ SHorizontalBox::Slot()
								.AutoWidth()
								.MaxWidth(150.f)
								.Padding(3.0f, 0.0f)
								.VAlign(VAlign_Center)
								[
									SNew(STextBlock)
									.Text(LOCTEXT("smoothModel", "Recalculate model normals"))
								]
								+ SHorizontalBox::Slot()
								.AutoWidth()
								.MaxWidth(20)
								.Padding(FMargin(3.0f, 0.0f))
								.VAlign(VAlign_Center)
								[
									SNew(SCheckBox)
									.IsChecked(this, &SHammerPropUErWidget::GetSmoothActive)
									.OnCheckStateChanged(this, &SHammerPropUErWidget::OnSmoothChanged)
									.ToolTipText(LOCTEXT("smoothTooltip", "Recalculates vertex normals from face normals, discarding source normals."))
								]
							]
							+ SVerticalBox::Slot()
							.AutoHeight()
							.Padding(3.f)
							[
								SNew(SBorder)
								.Padding(FMargin(3))
								.Visibility(this, &SHammerPropUErWidget::GetImportVisibility)
								[
									SNew(SVerticalBox)
									+ SVerticalBox::Slot()
									.AutoHeight()
									.Padding(2)
									[
										SNew(SHorizontalBox)
										+SHorizontalBox::Slot()
										.AutoWidth()
										[
											SNew(SBox)
											.WidthOverride(300.f)
											[
												SNew(SBorder)
												.Padding(1.f)
												[
													SNew(SHorizontalBox)
													+ SHorizontalBox::Slot()
													.MaxWidth(60.f)
													.Padding(3.f, 1.f)
													.VAlign(VAlign_Center)
													[
															SNew(STextBlock)
															.Text(LOCTEXT("import_seek", "Highlight: "))
													]
													+ SHorizontalBox::Slot()
													.AutoWidth()
													.Padding(1.f)
													.VAlign(VAlign_Center)
													[
														SNew(SBox)
														.WidthOverride(200.f)
														[
															SAssignNew(importSeekBlock, SEditableTextBox)
															.BackgroundColor(FSlateColor(FLinearColor(FColor::White)))
															.OnTextCommitted(this, &SHammerPropUErWidget::OnSeekNameChanged)
															.Text(this, &SHammerPropUErWidget::GetSeekName)
															.ToolTipText(LOCTEXT("import_seek_tooltip","Model name(s) to find"))
														]
													]
												]
											]
										]
										+ SHorizontalBox::Slot()
										.MaxWidth(60.f)
										[
											SNew(SBorder)
											[
												SNew(SButton)
												.Text(LOCTEXT("import_toggle", "Toggle"))
												.HAlign(HAlign_Center)
												.OnClicked(this, &SHammerPropUErWidget::ToggleSelection)
												.ToolTipText(FText::FromString(TEXT("Toggle importing selection")))
											]
										]
										+ SHorizontalBox::Slot()
										.AutoWidth()
										[
											SNew(STextBlock)
											.Text(LOCTEXT("import_blank",""))
										]
									]
									+SVerticalBox::Slot()
									.AutoHeight()
									.Padding(2)
									[
										SNew(SHorizontalBox)
										+SHorizontalBox::Slot()
										.AutoWidth()
										[
											SNew(SBorder)
											[
												SNew(SBox)
												.WidthOverride(360.f)
												[
													SNew(SHorizontalBox)
													+SHorizontalBox::Slot()
													.Padding(3.f, 1.f)
													.MaxWidth(60.f)
													[
														SNew(SBox)
														.WidthOverride(60.f)
														.VAlign(VAlign_Center)
														[
															SNew(STextBlock)
															.Text(LOCTEXT("import_rotation","Rotation: "))
														]
													]
													+SHorizontalBox::Slot()
													.MaxWidth(200.f)
													[
														SNew(SBox)
														.WidthOverride(200.f)
														[
															SNew(SRotatorInputBox)
															.Roll(this, &SHammerPropUErWidget::GetImportRoll)
															.Pitch(this, &SHammerPropUErWidget::GetImportPitch)
															.Yaw(this, &SHammerPropUErWidget::GetImportYaw)
															.AllowSpin(false)
															.bColorAxisLabels(true)
															.AllowResponsiveLayout(true)
															.OnRollCommitted(this, &SHammerPropUErWidget::OnSetImportRotation, 0)
															.OnPitchCommitted(this, &SHammerPropUErWidget::OnSetImportRotation, 1)
															.OnYawCommitted(this, &SHammerPropUErWidget::OnSetImportRotation, 2)
															.ToolTipText(LOCTEXT("modelRotationtooltip", "Rotation fix to bake in imported models"))
														]
													]
													+SHorizontalBox::Slot()
													.Padding(2.f)
													[
														SNew(SButton)
														.HAlign(HAlign_Center)
														.OnClicked(this, &SHammerPropUErWidget::ApplyRotation)
														.Text(LOCTEXT("apply_rotation","Bake rotation"))
													]
												]
											]
										]
										+SHorizontalBox::Slot()
										.AutoWidth()
										[
											SNew(STextBlock)
											.Text(LOCTEXT("import_blank", ""))
										]
									]
									+SVerticalBox::Slot()
									.AutoHeight()
									.Padding(2)
									[
										SNew(SHorizontalBox)
										+SHorizontalBox::Slot()
										.AutoWidth()
										[
											SNew(SBox)
											.WidthOverride(210.f)
											[
												SNew(SBorder)
												[
													SNew(SHorizontalBox)
													+SHorizontalBox::Slot()
													.Padding(3.f, 1.f)
													.MaxWidth(50.f)
													.VAlign(VAlign_Center)
													[
														SNew(STextBlock)
														.Text(LOCTEXT("import_selection", "Import: "))
													]
													+SHorizontalBox::Slot()
													.MaxWidth(50.f)
													[
														SNew(SButton)
														.Text(LOCTEXT("import_all", "All"))
														.HAlign(HAlign_Center)
														.OnClicked(this, &SHammerPropUErWidget::SelectAll)
														.ToolTipText(FText::FromString(TEXT("Select all models to import")))
													]
													+ SHorizontalBox::Slot()
													.MaxWidth(50.f)
													[
														SNew(SButton)
														.Text(LOCTEXT("import_none", "Clear"))
														.HAlign(HAlign_Center)
														.OnClicked(this, &SHammerPropUErWidget::SelectNone)
														.ToolTipText(FText::FromString(TEXT("Clear selection completely")))
													]
													+ SHorizontalBox::Slot()
													.MaxWidth(50.f)
													[
														SNew(SButton)
														.Text(LOCTEXT("import_inverse", "Invert"))
														.HAlign(HAlign_Center)
														.OnClicked(this, &SHammerPropUErWidget::SelectInverse)
														.ToolTipText(FText::FromString(TEXT("Inverse model importing selections")))
													]
												]
											]
										]
										+ SHorizontalBox::Slot()
										.AutoWidth()
										[
											SNew(SBox)
											.WidthOverride(100.f)
											[
												SNew(SBorder)
												[
													SNew(SButton)
													.Text(LOCTEXT("import_import", "Import"))
													.HAlign(HAlign_Center)
													.OnClicked(this, &SHammerPropUErWidget::DoImport)
													.ToolTipText(FText::FromString(TEXT("Import selected models")))
												]
											]
										]
										+SHorizontalBox::Slot()
										.AutoWidth()
										[
											SNew(STextBlock)
											.Text(LOCTEXT("import_blank",""))
										]
										+ SHorizontalBox::Slot()
										.AutoWidth()
										[
											SNew(SCheckBox)
											.IsChecked(this, &SHammerPropUErWidget::GetDiffNames)
											.OnCheckStateChanged(this, &SHammerPropUErWidget::SetDiffNames)
											.ToolTipText(FText::FromString(TEXT("Create duplicates if model name doesn't match filename")))
										]
									]
									+ SVerticalBox::Slot()
									.MaxHeight(300)
									[
											SNew(SBox)
											.HeightOverride(300.f)
											[
												SAssignNew(modelListWidget, SListView<TSharedPtr<FModelListEntry>>)
												.ItemHeight(30)
												.Visibility(this, &SHammerPropUErWidget::GetImportVisibility)
												.ListItemsSource(&modelList)
												.SelectionMode(ESelectionMode::Multi)
												.OnGenerateRow(this, &SHammerPropUErWidget::MakeListViewWidget)
												.HeaderRow(
												SNew(SHeaderRow)
												+ SHeaderRow::Column("name").DefaultLabel(LOCTEXT("header_name","Name")).HAlignCell(HAlign_Left).HAlignHeader(HAlign_Left)
												+ SHeaderRow::Column("rotation").DefaultLabel(LOCTEXT("header_rotation","Rotation to bake")).HAlignCell(HAlign_Left).HAlignHeader(HAlign_Left).FixedWidth(150.f)
												+ SHeaderRow::Column("doImport").DefaultLabel(LOCTEXT("header_doImport","Import")).HAlignCell(HAlign_Center).HAlignHeader(HAlign_Center).FixedWidth(50.0f)
												)
											]
									]
								]
							]
						]
					]
				]
				+ SVerticalBox::Slot()
				.Padding(3.0f, 1.0f)
				.AutoHeight()
				[
					SNew(SBox)
					.WidthOverride(200)
					[
					SNew(SHorizontalBox)
					/*+SHorizontalBox::Slot()
					[
						SNew(SButton)
						.Text(LOCTEXT("unstitch", "Unstitch"))
						.HAlign(HAlign_Center)
						.OnClicked(this, &SHammerPropUErWidget::Unstitch)
						.ToolTipText(FText::FromString(TEXT("Unstitch selected actor(s)")))
					]
					+SHorizontalBox::Slot()
					[
						SNew(SButton)
						.Text(LOCTEXT("stitch", "Stitch"))
						.HAlign(HAlign_Center)
						.OnClicked(this, &SHammerPropUErWidget::Stitch)
						.ToolTipText(FText::FromString(TEXT("Stitch selected actors")))
					]
					+ SHorizontalBox::Slot()
					[
						SNew(SButton)
						.Text(LOCTEXT("smoother", "Smoother"))
						.HAlign(HAlign_Center)
						.OnClicked(this, &SHammerPropUErWidget::Smooth)
						.ToolTipText(FText::FromString(TEXT("Smooth selected mesh(es), should be handled by VMF import at this point, but if you're just working with old data...")))
					]*/
					+ SHorizontalBox::Slot()
					.MaxWidth(16)
					.VAlign(VAlign_Center)
					[
						SNew(STextBlock)
						.Text(LOCTEXT("empty", ""))
					]
/*
				+ SHorizontalBox::Slot()
					[
						SNew(SButton)
						.Text(LOCTEXT("packUEr", "PackUEr"))
					.HAlign(HAlign_Center)
					.OnClicked(this, &SHammerPropUErWidget::PackUEr)
					.ToolTipText(FText::FromString(TEXT("Do that voodoo")))
					]*/
					]
				]
			]
		];
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION

FIntPoint RoundTexSizeToNext(FIntPoint inPoint)
{
	return FIntPoint(FMath::Pow(2, FMath::CeilLogTwo(inPoint.X)), FMath::Pow(2, FMath::CeilLogTwo(inPoint.Y)));
}

FReply SHammerPropUErWidget::ApplyRotation()
{
	TArray<TSharedPtr<FModelListEntry>> selectionList = modelListWidget->GetSelectedItems();
	for (int i = 0; i < selectionList.Num(); i++)
		selectionList[i]->fixRotation = FRotator(bakeRotation.Y, bakeRotation.Z, bakeRotation.X );

	return FReply::Handled();
}

FReply SHammerPropUErWidget::SelectAll()
{
	for (int i = 0; i < modelList.Num(); i++)
		modelList[i]->doImport = true;
	return FReply::Handled();
}

FReply SHammerPropUErWidget::SelectNone()
{
	for (int i = 0; i < modelList.Num(); i++)
		modelList[i]->doImport = false;
	return FReply::Handled();
}

FReply SHammerPropUErWidget::SelectInverse()
{
	for (int i = 0; i < modelList.Num(); i++)
		modelList[i]->doImport = !modelList[i]->doImport;
	return FReply::Handled();
}

FReply SHammerPropUErWidget::ToggleSelection()
{
	TArray<TSharedPtr<FModelListEntry>> selectionList = modelListWidget->GetSelectedItems();
	for (int i = 0; i < selectionList.Num(); i++)
		selectionList[i]->doImport = !selectionList[i]->doImport;
	return FReply::Handled();
}

TSharedRef<ITableRow> SHammerPropUErWidget::MakeListViewWidget(TSharedPtr<FModelListEntry> Item, const TSharedRef<STableViewBase>& OwnerTable)
{
	class SModelComboWidget : public SMultiColumnTableRow< TSharedPtr<FModelListEntry> >
	{
	public:
		SLATE_BEGIN_ARGS(SModelComboWidget) {}
		SLATE_END_ARGS()

			TSharedPtr<SSpinBox<int32>> texWidthWidget, texHeightWidget;

		void Construct(const FArguments& InArgs, const TSharedRef<STableViewBase>& InOwnerTable, TSharedPtr<FModelListEntry> InItem)
		{
			Item = InItem;
			SMultiColumnTableRow< TSharedPtr<FModelListEntry> >::Construct(FSuperRowType::FArguments(), InOwnerTable);
		}

		ECheckBoxState GetImport() const
		{
			if (Item->doImport) return ECheckBoxState::Checked; else return ECheckBoxState::Unchecked;
		}

		void SetImport(ECheckBoxState inState)
		{
			Item->doImport = (inState == ECheckBoxState::Checked);
		}

		FText BuildRotationString() const
		{
			return FText::FromString("P: " + FString::SanitizeFloat(Item->fixRotation.Pitch) + " R: " + FString::SanitizeFloat(Item->fixRotation.Roll) + " Y: " + FString::SanitizeFloat(Item->fixRotation.Yaw));
		}

		TSharedRef<SWidget> GenerateWidgetForColumn(const FName& ColumnName)
		{
			FText ItemText = FText::GetEmpty();
			if (ColumnName == "name")
			{
				ItemText = FText::FromString(Item->name);
				return SNew(STextBlock)
					.Margin(3.f)
					.Text(ItemText);
			}
			if (ColumnName == "rotation")
			{
				return SNew(STextBlock)
					.Margin(3.f)
					.Text(this, &SModelComboWidget::BuildRotationString);
			}
			if (ColumnName == "doImport")
			{
				return
					SNew(SCheckBox)
					.IsChecked(this, &SModelComboWidget::GetImport)
					.OnCheckStateChanged(this, &SModelComboWidget::SetImport);
			}
			return SNew(STextBlock)
				.Text(FText::FromString("What"));
		}
		TSharedPtr<FModelListEntry> Item;
	};
	return SNew(SModelComboWidget, OwnerTable, Item);
}


EVisibility SHammerPropUErWidget::GetImportVisibility() const
{
	if (canRunImport)
		return EVisibility::Visible;
	else
		return EVisibility::Hidden;
}

void SHammerPropUErWidget::OnSeekNameChanged(const FText& InLabel, ETextCommit::Type TextType)
{
	if (TextType == ETextCommit::OnEnter || TextType == ETextCommit::Default || TextType == ETextCommit::OnUserMovedFocus)
	{
		seekName = InLabel.ToString();
		bool found = false;
		int itemnum = 0;
		TArray<int32> selectionList;

		for (int i = 0; i < modelList.Num(); i++)
		{
			if(modelList[i]->name.Contains(seekName))
				selectionList.Add(i);
		}
		if (selectionList.Num()>0)
		{
			modelListWidget->ClearSelection();
			for (int count = 0; count < selectionList.Num(); count++)
				modelListWidget->SetItemSelection(modelList[selectionList[count]], true, ESelectInfo::Direct);
			if (!modelListWidget->IsItemVisible(modelList[selectionList[0]]))
				modelListWidget->RequestScrollIntoView(modelList[selectionList[0]]);
		}
	}
}

FText SHammerPropUErWidget::GetSeekName() const
{
	return FText::FromString(seekName);
}

bool SHammerPropUErWidget::CanImport() const
{
	return !importRunning;
}

bool SHammerPropUErWidget::CanRunGetter() const
{
	return (!importRunning && HammUErSettings::modelImportDirectory != ""&&HammUErSettings::modelSourceDirectory != "");
}

FReply SHammerPropUErWidget::GetImportDir()
{
	IDesktopPlatform* DesktopPlatform = FDesktopPlatformModule::Get();
	bool bOpen = false;
	if (DesktopPlatform)
	{
		void* ParentWindowWindowHandle = NULL;

		IMainFrameModule& MainFrameModule = FModuleManager::LoadModuleChecked<IMainFrameModule>(TEXT("MainFrame"));
		const TSharedPtr<SWindow>& MainFrameParentWindow = MainFrameModule.GetParentWindow();
		if (MainFrameParentWindow.IsValid() && MainFrameParentWindow->GetNativeWindow().IsValid())
			ParentWindowWindowHandle = MainFrameParentWindow->GetNativeWindow()->GetOSWindowHandle();

		FString inFolderName;
		bOpen = DesktopPlatform->OpenDirectoryDialog(ParentWindowWindowHandle, "Choose import directory", HammUErSettings::modelSourceDirectory, inFolderName);
		if (bOpen)
			HammUErSettings::modelSourceDirectory = inFolderName;
	}
	return FReply::Handled();
}

int SupportedModelCount = 4;
FString SupportedModelExtensions[] = { ".smd", ".mdl", ".lwo", ".ase" };

FReply SHammerPropUErWidget::RunGetter()
{
	struct FVisitor : public IPlatformFile::FDirectoryVisitor
	{
		TArray<FString>* PendingFiles;
		virtual bool Visit(const TCHAR* FilenameOrDirectory, bool bIsDirectory)
		{
			if (!bIsDirectory)
			{
				FString FileStr(FilenameOrDirectory);
				for (int i = 0; i < SupportedModelCount; i++)

				if (FileStr.EndsWith(SupportedModelExtensions[i], ESearchCase::IgnoreCase))
					PendingFiles->Add(MoveTemp(FileStr));
			}
			return true;
		}
	};

	struct FDirVisitor : public IPlatformFile::FDirectoryVisitor
	{
		TArray<FString>*PendingDirs;
		virtual bool Visit(const TCHAR* FilenameOrDirectory, bool bIsDirectory)
		{
			if (bIsDirectory)
			{
				FString DirStr(FilenameOrDirectory);
				PendingDirs->Add(MoveTemp(DirStr));
			}
			return true;
		}
	};

	FVisitor filenameVisitor;
	FDirVisitor directoryVisitor;

	TArray<FString> PendingImportFiles;
	TArray<FString> PendingDirectories;
	TArray<FString> directoriesToVisit;
	directoriesToVisit.Add(HammUErSettings::modelSourceDirectory);
	HammUErSettings::LoadModelSettings();


	if (!HammUErSettings::okayedModelsLegal)
	{
		EAppReturnType::Type answer = FMessageDialog::Open(EAppMsgType::OkCancel, FText::FromString("You cannot legally use *any* models you don't own or have permission for in your Unreal Engine projects.\r\nRemember that while you can import any and all models and use them to design your maps, you *must* replace anything that infringes copyright before publishing your project.\r\nYou take full responsibility for what you do with the files you've imported.\r\nThis message will only be shown once."));
		if (answer == EAppReturnType::Cancel)
			return FReply::Handled();
		HammUErSettings::okayedModelsLegal = true;
	}

	directoryVisitor.PendingDirs = &PendingDirectories;
	FPlatformFileManager::Get().GetPlatformFile().IterateDirectory(*HammUErSettings::modelSourceDirectory, directoryVisitor);
	while (PendingDirectories.Num() > 0)
	{
		FString dirToCheck = PendingDirectories[0];
		PendingDirectories.RemoveAt(0);
		directoriesToVisit.Add(dirToCheck);
		FPlatformFileManager::Get().GetPlatformFile().IterateDirectory(*dirToCheck, directoryVisitor);
	}

	filenameVisitor.PendingFiles = &PendingImportFiles;

	for (int i = 0; i < directoriesToVisit.Num(); i++)
		FPlatformFileManager::Get().GetPlatformFile().IterateDirectory(*directoriesToVisit[i], filenameVisitor);

	if (PendingImportFiles.Num() == 0)
	{
		FMessageDialog::Open(EAppMsgType::Ok, FText::FromString("No files found."));
		return FReply::Handled();
	}

	PendingImportFiles.Sort();
	modelList.Empty();
	for (int fillList = 0; fillList < PendingImportFiles.Num(); fillList++)
	{
		FRotator myRotator = HammUErSettings::FindRotationInModelDatabase(PendingImportFiles[fillList].Replace(TEXT("\\"), TEXT("/")));
		modelList.Add(MakeShareable(new FModelListEntry(PendingImportFiles[fillList], myRotator)));
	}

	canRunImport = true;
	modelListWidget->RequestListRefresh();
	return FReply::Handled();
}

void SHammerPropUErWidget::BuildRawMesh(std::vector<VMFTri*> triangles, FRawMesh& rawMesh, TArray<int32>& materialReindex)
{
	// prep stuff
	int32 numFaces = triangles.size();
	if (numFaces == 0)
		return;

	TArray<bool> loadTris;
	for (int i = 0; i < numFaces; i++)
		loadTris.Add(true);

	if (HammUErSettings::checkDegenerates) // UE faceplants hard when it runs into degenerate triangles when building a staticmesh
	{
		for (int tri = 0; tri < triangles.size(); tri++)
		{
			if (FVector::PointsAreSame(MAPConverters::MAPtoF(triangles[tri]->v1), MAPConverters::MAPtoF(triangles[tri]->v2)) ||
				FVector::PointsAreSame(MAPConverters::MAPtoF(triangles[tri]->v1), MAPConverters::MAPtoF(triangles[tri]->v3)) ||
				FVector::PointsAreSame(MAPConverters::MAPtoF(triangles[tri]->v2), MAPConverters::MAPtoF(triangles[tri]->v3)))
			{
				UE_LOG(LogTemp, Warning, TEXT("Degenerate triangle found. Skipping."));
				loadTris[tri] = false;
				numFaces--;
			}
		}
	}

	if (numFaces == 0)
		return;


	int32 numVertices = numFaces * 3;
	int32 verticesOffset = rawMesh.VertexPositions.Num(); // might as well add this for later combining // do I... actually still use this?
	int32 faceIndexOffset = rawMesh.FaceMaterialIndices.Num();

	rawMesh.FaceMaterialIndices.AddZeroed(numFaces);
	rawMesh.FaceSmoothingMasks.AddZeroed(numFaces);

	TArray<FVector> keptVertices;
	TArray<uint32> triVertexIndex;

	for (int i = 0; i < triangles.size(); i++) // okay, we need to rebuild the entire thing to have shared vertex pos + UVs... and normals I guess. God this is such a pain
	{											// actually, we don't, I just ran into a shitty bug
		if (loadTris[i])
		{
			triVertexIndex.Add(keptVertices.AddUnique(MAPConverters::MAPtoF(triangles[i]->v1)));//VertexInformation(MAPConverters::MAPtoF(triangles[i]->v1), MAPConverters::MAPtoF(triangles[i]->n1), MAPConverters::MAPtoF(triangles[i]->uv1), MAPConverters::MAPtoF(triangles[i]->c1))));
			triVertexIndex.Add(keptVertices.AddUnique(MAPConverters::MAPtoF(triangles[i]->v2)));//VertexInformation(MAPConverters::MAPtoF(triangles[i]->v2), MAPConverters::MAPtoF(triangles[i]->n2), MAPConverters::MAPtoF(triangles[i]->uv2), MAPConverters::MAPtoF(triangles[i]->c2))));
			triVertexIndex.Add(keptVertices.AddUnique(MAPConverters::MAPtoF(triangles[i]->v3)));//VertexInformation(MAPConverters::MAPtoF(triangles[i]->v3), MAPConverters::MAPtoF(triangles[i]->n3), MAPConverters::MAPtoF(triangles[i]->uv3), MAPConverters::MAPtoF(triangles[i]->c3))));
		}
	}
	if (triVertexIndex.Num() != numVertices)
	{
		UE_LOG(LogTemp, Error, TEXT("Something went wrong reducing vertices!"));
		return;
	}

	UE_LOG(LogTemp, Log, TEXT("Reduced vertices from %i to %i"), triangles.size() * 3, keptVertices.Num());

	rawMesh.VertexPositions.AddZeroed(keptVertices.Num());

	for (int i = 0; i < keptVertices.Num(); i++)
	{
		rawMesh.VertexPositions[i] = keptVertices[i];
	}

	int currentIndex = 0;

	for (int tri = 0; tri < triangles.size(); tri++)
	{
		if (!loadTris[tri])
			continue;

		rawMesh.WedgeTexCoords[0].Add(MAPConverters::MAPtoF(triangles[tri]->uv1));
		rawMesh.WedgeTangentX.Add(FVector::ZeroVector);
		rawMesh.WedgeTangentY.Add(FVector::ZeroVector);
		rawMesh.WedgeTangentZ.Add(MAPConverters::MAPtoF(triangles[tri]->n1));
		rawMesh.WedgeColors.Add(MAPConverters::MAPtoF(triangles[tri]->c1));
		rawMesh.WedgeIndices.Add(verticesOffset + triVertexIndex[currentIndex]);

		rawMesh.WedgeTexCoords[0].Add(MAPConverters::MAPtoF(triangles[tri]->uv3));
		rawMesh.WedgeTangentX.Add(FVector::ZeroVector);
		rawMesh.WedgeTangentY.Add(FVector::ZeroVector);
		rawMesh.WedgeTangentZ.Add(MAPConverters::MAPtoF(triangles[tri]->n3));
		rawMesh.WedgeColors.Add(MAPConverters::MAPtoF(triangles[tri]->c3));
		rawMesh.WedgeIndices.Add(verticesOffset + triVertexIndex[currentIndex + 2]);

		rawMesh.WedgeTexCoords[0].Add(MAPConverters::MAPtoF(triangles[tri]->uv2));
		rawMesh.WedgeTangentX.Add(FVector::ZeroVector);
		rawMesh.WedgeTangentY.Add(FVector::ZeroVector);
		rawMesh.WedgeTangentZ.Add(MAPConverters::MAPtoF(triangles[tri]->n2));
		rawMesh.WedgeColors.Add(MAPConverters::MAPtoF(triangles[tri]->c2));
		rawMesh.WedgeIndices.Add(verticesOffset + triVertexIndex[currentIndex + 1]);
		currentIndex += 3;

		int matIndex = 0;
		if (materialReindex.Contains(triangles[tri]->matId))
			matIndex = materialReindex.Find(triangles[tri]->matId);
		else
			matIndex = materialReindex.Add(triangles[tri]->matId);

		rawMesh.FaceMaterialIndices[faceIndexOffset++] = matIndex;
	}
}

FReply SHammerPropUErWidget::DoImport()
{
/*	if (.Num() > 1000)
	{
		EAppReturnType::Type answer = FMessageDialog::Open(EAppMsgType::YesNo, FText::FromString("You're importing more than 1000 files in one go.\r\nThis might use up a lot of memory and could crash randomly.\r\n\r\nAre you sure you want to continue?"));
		if (answer == EAppReturnType::No)
			return FReply::Handled();
	}*/

	HammUErSettings::LoadConfig(true); // make sure the master list is loaded
	HammUErSettings::SaveConfig();

	int totalFiles = modelList.Num();
	FScopedSlowTask SlowTask(totalFiles, FText::FromString("Importing models..."));
	SlowTask.MakeDialog();
	for (int currentImportFile = 0; currentImportFile < totalFiles; currentImportFile++)
	{
		SlowTask.EnterProgressFrame(1);
		if (modelList[currentImportFile]->doImport)
		{
			if (HammUErSettings::verboseDebugEnabled)
				UE_LOG(LogTemp, Log, TEXT("Importing file %i, %s"), currentImportFile, *modelList[currentImportFile]->name);

			BaseModelLoader* modelLoader = NULL;

			if (modelList[currentImportFile]->name.EndsWith(".smd"))
				modelLoader = (BaseModelLoader*)new SMDLoader();

			if (modelList[currentImportFile]->name.EndsWith(".mdl"))
				modelLoader = (BaseModelLoader*)new MDLReader();

			if (modelList[currentImportFile]->name.EndsWith(".lwo"))
				modelLoader = (BaseModelLoader*)new LWOLoader();

			if (modelList[currentImportFile]->name.EndsWith(".ase"))
				modelLoader = (BaseModelLoader*)new ASELoader();

			if (modelLoader != NULL)
			{
				if (modelLoader->Open(TCHAR_TO_UTF8(*modelList[currentImportFile]->name)))
				{
					modelLoader->Import();
					std::vector<std::string> materialNames = modelLoader->GetMaterialData();
					std::vector<std::string> materialDirectories = modelLoader->GetMaterialDirectories();
					std::vector<VMFTri*> triangles = modelLoader->GetModelData();
					if (triangles.size() > 0)
					{
						if (HammUErSettings::propScaleType == 1)
						{
							float convertUE = 100.0f / HammUErSettings::localConversionRate;

							for (int cleanup2 = 0; cleanup2 < triangles.size(); cleanup2++)
							{
								triangles[cleanup2]->v1 = MAPConverters::FtoMAP(modelList[currentImportFile]->fixRotation.RotateVector(MAPConverters::MAPtoF(triangles[cleanup2]->v1)));
								triangles[cleanup2]->v2 = MAPConverters::FtoMAP(modelList[currentImportFile]->fixRotation.RotateVector(MAPConverters::MAPtoF(triangles[cleanup2]->v2)));
								triangles[cleanup2]->v3 = MAPConverters::FtoMAP(modelList[currentImportFile]->fixRotation.RotateVector(MAPConverters::MAPtoF(triangles[cleanup2]->v3)));

								triangles[cleanup2]->v1 *= convertUE;
								triangles[cleanup2]->v2 *= convertUE;
								triangles[cleanup2]->v3 *= convertUE;
							}
						}


						FString MeshName = modelLoader->GetName().c_str();
						if (MeshName.Contains("."))
						{
							FString Extension = FPaths::GetExtension(MeshName);
							MeshName.RemoveFromEnd("." + Extension);
						}
						MeshName.RemoveFromStart(HammUErSettings::modelSourceDirectory);
						MeshName = MeshName.Replace(TEXT("."), TEXT("_"));
						MeshName = MeshName.Replace(TEXT("\\"), TEXT("/"));
						MeshName = MeshName.Replace(TEXT("//"), TEXT("/"));
						MeshName = MeshName.Replace(TEXT(":"), TEXT("_"));
						MeshName = MeshName.Replace(TEXT("*"), TEXT("X"));
						MeshName = MeshName.Replace(TEXT("?"), TEXT("Q"));
						MeshName = MeshName.Replace(TEXT("!"), TEXT("I"));

						if (MeshName.StartsWith("/"))
							MeshName.RemoveFromStart("/");

						FString fileName = modelList[currentImportFile]->name;
						if (createDuplicates)
						{
							int slashPosition = -1;
							fileName.FindLastChar('/', slashPosition);
							if (slashPosition > -1)
							{
								fileName = fileName.RightChop(slashPosition + 1);

								if (fileName.Contains("."))
									fileName.RemoveFromEnd("." + FPaths::GetExtension(fileName));

								fileName = fileName.Replace(TEXT("."), TEXT("_"));
								fileName = fileName.Replace(TEXT("\\"), TEXT("/"));
								fileName = fileName.Replace(TEXT("//"), TEXT("/"));
								fileName = fileName.Replace(TEXT(":"), TEXT("_"));
								fileName = fileName.Replace(TEXT("*"), TEXT("X"));
								fileName = fileName.Replace(TEXT("?"), TEXT("Q"));
								fileName = fileName.Replace(TEXT("!"), TEXT("I"));

								int slashPosition2 = -1;
								MeshName.FindLastChar('/', slashPosition2);
								if (slashPosition2 > -1)
									fileName = MeshName.Left(slashPosition2+1) + fileName;

								if (fileName.ToUpper() != MeshName.ToUpper())
								{
									UE_LOG(LogTemp, Warning, TEXT("PropUEr! %s mismatch with %s"), *MeshName, *fileName);
								}
							}

						}
			

						int runs = createDuplicates?2:1;

						for (int createRuns = 0; createRuns < runs; createRuns++)
						{
							FString NewPackageName = "/Game/" + (HammUErSettings::modelImportDirectory != "" ? HammUErSettings::modelImportDirectory + "/Meshes/" : "Meshes/") + MeshName;
							UPackage* Package = CreatePackage(NULL, *NewPackageName);
							Package->FullyLoad();
							Package->Modify();

							FRawMesh rawMesh;
							TArray<int32> reIndexedMaterials;
							if (triangles.size() < 2)
							{
								UE_LOG(LogTemp, Error, TEXT("! less than 2 triangles in this model, aborting?"));
								continue;
							}
							BuildRawMesh(triangles, rawMesh, reIndexedMaterials);
							bool foundIt = false;
							TArray<UMaterialInterface*> meshMaterials;
							for (int i = 0; i < reIndexedMaterials.Num(); i++)
							{
								foundIt = false;
								if (materialDirectories.size() > 0)
								{
									FString dirSearch = materialNames[reIndexedMaterials[i]].c_str();
									if (dirSearch.Contains("."))
									{
										int dotIndex = dirSearch.Find(".");
										dirSearch = dirSearch.Left(dotIndex);
									}
									for (int j = 0; j < materialDirectories.size(); j++)
									{
										FString dirName = materialDirectories[j].c_str();
										if (!dirName.EndsWith("/"))
											dirName += "/";
										dirSearch = dirName + dirSearch;
										int index = HammUErSettings::FindInMaster(dirSearch);
										if (index > -1)
										{
											int adbi = HammUErSettings::masterMaterialList[index]->AssetDatabaseIndex;
											if (adbi > -1)
											{
												meshMaterials.Add((UMaterialInterface*)HammUErSettings::AssetData[adbi].GetAsset());
												foundIt = true;
												if (HammUErSettings::verboseDebugEnabled)
													UE_LOG(LogTemp, Log, TEXT("Found material %s in master as %s"), *dirSearch, *HammUErSettings::masterMaterialList[index]->oldName);
												break;
											}
											else
											{
												meshMaterials.Add((UMaterialInterface*)HammUErSettings::MaterialInAssetDatabase(dirSearch));
												foundIt = true;
												if (HammUErSettings::verboseDebugEnabled)
													UE_LOG(LogTemp, Warning, TEXT("Found material %s in master, but no match in Asset Database!"), *dirSearch);
												break;
											}
										}
									}
								}

								if (!foundIt)
								{
									FString toSearchfor;
									if (materialNames.size() > 0)
									{
										if ((reIndexedMaterials[i] > -1) && (reIndexedMaterials[i] < materialNames.size()))
										{
											toSearchfor = materialNames[reIndexedMaterials[i]].c_str();
											if (toSearchfor.Contains("."))
											{
												int dotIndex = toSearchfor.Find(".");
												toSearchfor = toSearchfor.Left(dotIndex);
											}
										}
										else
											toSearchfor = "fuckingASE";
									}
									else
										toSearchfor = "brokenandormissingmaterialname";
									UMaterialInterface* testMaterial = (UMaterialInterface*)HammUErSettings::MaterialInAssetDatabase(toSearchfor);
									meshMaterials.Add(testMaterial);
									if (HammUErSettings::verboseDebugEnabled)
										UE_LOG(LogTemp, Warning, TEXT("Did not find material %s in master, might be using the wrong material!"), *toSearchfor);
								}
							}
							MeshName = FPaths::GetCleanFilename(MeshName);

							HammUErSettings::modelTypes.Add(modelLoader->GetName().c_str(), new ModelImportInfo("", modelList[currentImportFile]->fixRotation));

							UStaticMesh* NewAsset = HammUErSettings::CreateStaticMesh(rawMesh, meshMaterials, Package, FName(*MeshName));
							FAssetRegistryModule::AssetCreated(NewAsset);
							NewAsset->PostEditChange();
							FString PackageFileName = FPackageName::LongPackageNameToFilename(NewPackageName, FPackageName::GetAssetPackageExtension());

							if (HammUErSettings::generateThumbs)
								ThumbnailTools::GenerateThumbnailForObjectToSaveToDisk(NewAsset);
							UPackage::SavePackage(Package, NewAsset, RF_Public | RF_Standalone, *PackageFileName, GError, nullptr, false, true, SAVE_NoError);

							if (createDuplicates)
								MeshName = fileName;
						}
					}

					modelLoader->CleanUp();
					delete modelLoader;
				}
				else
				{
					UE_LOG(LogTemp, Warning, TEXT("Errors reading file format!"));
					delete modelLoader;
				}
				
			}
			else
				UE_LOG(LogTemp, Warning, TEXT("No loader found."));
		}
	}

	HammUErSettings::SaveModelSettings();

	FMessageDialog::Open(EAppMsgType::Ok, FText::FromString("Done."));


	return FReply::Handled();
}

void SHammerPropUErWidget::ModelDirectoryChanged(const FText& InLabel, ETextCommit::Type TextType)
{
	if (TextType == ETextCommit::OnEnter || TextType == ETextCommit::Default || TextType == ETextCommit::OnUserMovedFocus)
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

		HammUErSettings::modelImportDirectory = newItem;
	}
}

FText SHammerPropUErWidget::GetModelImportDirectory() const
{
	return FText::FromString(HammUErSettings::modelImportDirectory);
}

#undef LOCTEXT_NAMESPACE