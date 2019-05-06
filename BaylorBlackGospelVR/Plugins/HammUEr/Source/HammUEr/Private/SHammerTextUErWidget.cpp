// HammUEr
// Copyright 2015-2016 Turfster / NT Entertainment
// All Rights Reserved.


// This code is held together with kitten whiskers and toothpicks.
// There's nothing to see or learn here.
// Seriously.
// Turn back.

// TODO: Fix the doom3 MTR & quake3 SHADER importer
//       Also, refactor the whole thing because this code is damn cruddy


#include "HammUErPrivatePCH.h"
#define STB_DXT_IMPLEMENTATION
#include "Engine.h"
#include "Engine/Texture.h"
#include "a_stb_dxt.h"
#include "SHammerTextUErWidget.h"
#include "SlateOptMacros.h"
#include "UnrealEd.h"
#include "HammUEr.h"
#include "ModuleManager.h"
#include "DesktopPlatformModule.h"
#include "MainFrame.h"
#include "HammUErSettings.h"

#include "PropertyCustomizationHelpers.h"
#include "ImageUtils.h"


#include "Materials/MaterialInstanceConstant.h"

#include "Runtime/Launch/Resources/Version.h"  // needed to catch the moved IImageWrapper stuff since 4.11 preview 5
#if ENGINE_MINOR_VERSION>=18
#include "Runtime/ImageWrapper/Public/IImageWrapper.h"
#include "Runtime/ImageWrapper/Public/IImageWrapperModule.h"
#else
#include "Runtime/ImageWrapper/Public/Interfaces/IImageWrapper.h"
#include "Runtime/ImageWrapper/Public/Interfaces/IImageWrapperModule.h"
#endif

#include "Developer/AssetTools/Public/AssetToolsModule.h"
#include "PackageTools.h"
#include "AssetRegistryModule.h"

#include "TextureManipulation.h"

#define LOCTEXT_NAMESPACE "SHammerTextUErWidget"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SHammerTextUErWidget::Tick(const FGeometry& AllottedGeometry, const double InCurrentTime, const float InDeltaTime)
{
	SCompoundWidget::Tick(AllottedGeometry, InCurrentTime, InDeltaTime);
	if (running)
		DoNextMaterial();
	if (discovering)
		DoNextDiscovery();
}

TOptional<float> SHammerTextUErWidget::GetPercentage() const
{
	return completionPercentage;
}

TArray<uint8> ConvertShort(int32 input)
{
	TArray<uint8> result;
	result.Add((input & 0x000000FF));
	result.Add((input & 0x0000FF00) >> 8);
	return result;
}

TArray<uint8> ConvertUint32(int32 input)
{
	TArray<uint8> result;
	result.Add((input & 0x000000FF));
	result.Add((input & 0x0000FF00) >> 8);
	result.Add((input & 0x00FF0000) >> 16);
	result.Add((input & 0xFF000000) >> 24);
	return result;
}

TArray<uint8> ConvertFloat(float input)
{
	TArray<uint8> result;
	result.AddUninitialized(4);
	FMemory::Memcpy(result.GetData(), &input, 4);
	return result;
}

FString ConvertSourceFormat(ETextureSourceFormat inFormat)
{
	switch (inFormat)
	{
	case ETextureSourceFormat::TSF_Invalid:
		return "TSF_Invalid";
		break;
	case ETextureSourceFormat::TSF_G8:
		return "TSF_G8";
		break;
	case ETextureSourceFormat::TSF_BGRA8:
		return "TSF_BGRA8";
		break;
	case ETextureSourceFormat::TSF_BGRE8:
		return "TSF_BGRE8";
		break;
	case ETextureSourceFormat::TSF_RGBA16:
		return "TSF_RGBA16";
		break;
	case ETextureSourceFormat::TSF_RGBA16F:
		return "TSF_RGBA16F";
		break;
	case ETextureSourceFormat::TSF_RGBA8:
		return "TSF_RGBA8";
		break;
	case ETextureSourceFormat::TSF_RGBE8:
		return "TSF_RGBE8";
		break;
	case ETextureSourceFormat::TSF_MAX:
		return "TSF_Max";
		break;
	default:
		return "Something went catastrophically wrong getting the source texture format";
		break;
	}
	return "CODE SHOULD NEVER GET HERE";
}

void SHammerTextUErWidget::Construct(const FArguments& InArgs)
{
	FString imagePath = FPaths::ProjectPluginsDir() + TEXT("HammUEr/Resources/headertest.png");
	sourceMaterial = NULL;
	decalMaterial = NULL;
	if (!FPaths::FileExists(imagePath))
		imagePath = FPaths::EnginePluginsDir() + TEXT("HammUEr/Resources/headertest.png");
	FName brushName = FName(*imagePath);
	ChildSlot
		[
			SNew(SBox)
			.WidthOverride(400)
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
			[
				SNew(SBorder)
				.Padding(FMargin(3))
		[
			SNew(SVerticalBox)
			+ SVerticalBox::Slot()
		.Padding(FMargin(3))
		.AutoHeight()
		[
			SNew(SHeader)
			.Content()
		[
			SNew(STextBlock)
			.Text(LOCTEXT("exporttext", "Export"))
		]
		]
	+ SVerticalBox::Slot()
		.AutoHeight()
		[
			SNew(SBorder)
			[
				SNew(SVerticalBox)
				+ SVerticalBox::Slot()
		.AutoHeight()
		.Padding(FMargin(3))
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
		.MaxWidth(150.f)
		.AutoWidth()
		[
			SNew(SButton)
			.OnClicked(this, &SHammerTextUErWidget::HandleChooseFileButtonClicked)
		.Text(LOCTEXT("BrowseButtonText", "Choose export directory"))
		.ToolTipText(LOCTEXT("BrowseButtonTool", "The directory where you want to export all\r\nmaterials in the current project to VTF files to\r\nfor use in Hammer."))
		]
	+ SHorizontalBox::Slot()
		.HAlign(HAlign_Center)
		.MaxWidth(190.f)
		.AutoWidth()
		[
			SNew(SButton)
			.OnClicked(this, &SHammerTextUErWidget::ExportAllTextures)
		.IsEnabled(this, &SHammerTextUErWidget::CanExport)
		.Text(LOCTEXT("ExportAllTextures", "Export all textures from materials"))
		.ToolTipText(LOCTEXT("BrowseButtonTool", "Export all applicable materials\r\nin the current project for use in Hammer."))
		]
	+ SHorizontalBox::Slot()
		.AutoWidth()
		.MaxWidth(20.0f)
		.Padding(3.0f)
		.VAlign(VAlign_Center)
		[
			SNew(STextBlock)
			.Text(LOCTEXT("Export_CurrentExportDirTitle", "To: "))
		]
	+ SHorizontalBox::Slot()
		.AutoWidth()
		.VAlign(VAlign_Center)
		[
			SNew(SEditableText)
			.Text(this, &SHammerTextUErWidget::GetExportDirectory)
		]

		]
	+ SVerticalBox::Slot()
		.AutoHeight()
		[
			SNew(SBorder)
			[
				SNew(SVerticalBox) 
				+ SVerticalBox::Slot()
				.AutoHeight()
				.Padding(FMargin(3))
				[
					SNew(SHeader)
					.Content()
					[
						SNew(STextBlock)
						.Text(LOCTEXT("ExportFinetuneKeepHeader", "Finetune exporting to include only"))
					]
				]
				+ SVerticalBox::Slot()
				[
					SNew(SSplitter)
				]
				+ SVerticalBox::Slot()
				.AutoHeight()
				.Padding(FMargin(3))
				[
					SNew(SVerticalBox)
					+ SVerticalBox::Slot()
					.AutoHeight()
					.Padding(FMargin(3))
					[
						SNew(SHorizontalBox)
						+ SHorizontalBox::Slot()
						.AutoWidth()
						.VAlign(VAlign_Center)
						[
							SNew(STextBlock)
							.Text(LOCTEXT("ExportKeepContainsWith", "materials containing: "))
						]
						+ SHorizontalBox::Slot()
						.VAlign(VAlign_Center)
						[
							SNew(SEditableTextBox)
							.BackgroundColor(FSlateColor(FLinearColor(FColor::White)))
							.OnTextCommitted(this, &SHammerTextUErWidget::OnKeepContainsWithChanged)
							.Text(this, &SHammerTextUErWidget::GetKeepContainsWithList)
							.ToolTipText(FText::FromString(TEXT("Comma separated list of segments, can use /<dirname>/ for example to narrow it down to a single directory")))
						]
						+ SHorizontalBox::Slot()
						.VAlign(VAlign_Center)
						.MaxWidth(154)
						.AutoWidth()
						[
							SNew(SBox)
							[
								SNew(SButton)
								.OnClicked(this, &SHammerTextUErWidget::DoExportOnly)
								.IsEnabled(this, &SHammerTextUErWidget::CanExport)
							.Text(LOCTEXT("ExportKeepTextures", "Export finetuned materials"))
							.ToolTipText(LOCTEXT("ExportKeepTool", "Export only the materials that match the list on the left."))
							]
						]
						+SHorizontalBox::Slot()
							.MaxWidth(16)
							.VAlign(VAlign_Center)
							[
								SNew(STextBlock)
								.Text(LOCTEXT("empty", ""))
							]
					
					]
				]

				+ SVerticalBox::Slot()
					[
						SNew(SSplitter)
					]

	+ SVerticalBox::Slot()
		.AutoHeight()
		.Padding(FMargin(3))
		[
			SNew(SHeader)
			.Content()
		[
			SNew(STextBlock)
			.Text(LOCTEXT("ExportFinetuneHeader", "Finetune exporting by filtering out textures with names"))
		]
		]
	+ SVerticalBox::Slot()
		[
			SNew(SSplitter)
		]
	+ SVerticalBox::Slot()
		.AutoHeight()
		.Padding(FMargin(3))
		[
			SNew(SVerticalBox)
			+ SVerticalBox::Slot()
		.AutoHeight()
		.Padding(FMargin(3))
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
		.AutoWidth()
		.VAlign(VAlign_Center)
		[
			SNew(STextBlock)
			.Text(LOCTEXT("ExportStartsWith", "beginning with: "))
		]
	+ SHorizontalBox::Slot()
		.VAlign(VAlign_Center)
		[
			SNew(SEditableTextBox)
			.BackgroundColor(FSlateColor(FLinearColor(FColor::White)))
		.OnTextCommitted(this, &SHammerTextUErWidget::OnBeginsWithChanged)
		.Text(this, &SHammerTextUErWidget::GetBeginsWithList)
		.ToolTipText(FText::FromString(TEXT("Comma separated list of segments")))

		]
		]
	+ SVerticalBox::Slot()
		.AutoHeight()
		.Padding(FMargin(3))
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
		.AutoWidth()
		.VAlign(VAlign_Center)
		[
			SNew(STextBlock)
			.Text(LOCTEXT("ExportContains", "containing anywhere: "))
		]
	+ SHorizontalBox::Slot()
		.VAlign(VAlign_Center)
		[
			SNew(SEditableTextBox)
			.BackgroundColor(FSlateColor(FLinearColor(FColor::White)))
		.OnTextCommitted(this, &SHammerTextUErWidget::OnContainsChanged)
		.Text(this, &SHammerTextUErWidget::GetContainsList)
		.ToolTipText(FText::FromString(TEXT("Comma separated list of segments")))

		]
		]
	+ SVerticalBox::Slot()
		.AutoHeight()
		.Padding(FMargin(3))
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
		.AutoWidth()
		.VAlign(VAlign_Center)
		[
			SNew(STextBlock)
			.Text(LOCTEXT("ExportEndsWith", "ending with: "))
		]
	+ SHorizontalBox::Slot()
		.VAlign(VAlign_Center)
		[
			SNew(SEditableTextBox)
			.BackgroundColor(FSlateColor(FLinearColor(FColor::White)))
		.OnTextCommitted(this, &SHammerTextUErWidget::OnEndsWithChanged)
		.Text(this, &SHammerTextUErWidget::GetEndsWithList)
		.ToolTipText(FText::FromString(TEXT("Comma separated list of segments")))
		]
		]
		]
			]
		]
			]
		]
		]
			]
		]
	+ SVerticalBox::Slot()
		.MaxHeight(10.f)
		.Padding(3.0f, 1.0f)
		[
			SNew(SBox)
			[
				SAssignNew(myProgressbar, SProgressBar)
				.BarFillType(EProgressBarFillType::LeftToRight)
		.FillColorAndOpacity(FSlateColor(FColor::Red))
		.RefreshRate(1.f)
		.Percent(this, &SHammerTextUErWidget::GetPercentage)
			]
		] + SVerticalBox::Slot()
			.AutoHeight()
			.Padding(3.0f, 1.0f)
			[
				SNew(SBox)
				[
					SNew(SBorder)
					.Padding(FMargin(3))
			[
				SNew(SVerticalBox)
				+ SVerticalBox::Slot()
			.Padding(FMargin(3))
			.AutoHeight()
			[
				SNew(SHeader)
				.Content()
			[
				SNew(STextBlock)
				.Text(LOCTEXT("importtext", "Import"))
			]
			]
		+ SVerticalBox::Slot()
			.AutoHeight()
			[
				SNew(SBorder)
				[
					SNew(SVerticalBox)
					+ SVerticalBox::Slot()
			.AutoHeight()
			.VAlign(VAlign_Center)
			.Padding(FMargin(3))
			[
				SNew(SHorizontalBox)
				+ SHorizontalBox::Slot()
			.VAlign(VAlign_Center)
			.MaxWidth(100.f)
			.AutoWidth()
			[
				SNew(STextBlock)
				.Text(LOCTEXT("import_sourcematerial", "Source material: "))
			]
		+ SHorizontalBox::Slot()
			.AutoWidth()
			.VAlign(VAlign_Center)
			[
				SNew(SObjectPropertyEntryBox)
				.ObjectPath(this, &SHammerTextUErWidget::GetCurrentPath)
			.OnObjectChanged(this, &SHammerTextUErWidget::OnMaterialChanged)
			.AllowClear(false)
			.AllowedClass(UMaterialInterface::StaticClass())
			]
		+ SHorizontalBox::Slot()
			.VAlign(VAlign_Center)
			.MaxWidth(100.f)
			.Padding(5.0f, 0.0f)
			.AutoWidth()
			[
				SNew(STextBlock)
				.Text(LOCTEXT("import_sourceparameter", "Base parameter: "))
			]
		+ SHorizontalBox::Slot()
			.AutoWidth()
			.MaxWidth(150.f)
			.VAlign(VAlign_Center)
			[
				SNew(SComboBox<TSharedPtr<FString>>)
				.OptionsSource(&parameterDropNamesList)
			.InitiallySelectedItem(InitialSelected)
			.OnSelectionChanged(this, &SHammerTextUErWidget::HandleComboSelectionChanged)
			.OnGenerateWidget(this, &SHammerTextUErWidget::HandleComboGenerateWidget)
			[
				SNew(STextBlock)
				.Text(this, &SHammerTextUErWidget::HandleComboText)
			]
			]
		+ SHorizontalBox::Slot()
			.VAlign(VAlign_Center)
			.MaxWidth(100.f)
			.Padding(5.0f, 0.0f)
			.AutoWidth()
			[
				SNew(STextBlock)
				.Text(LOCTEXT("import_sourcenormalparameter", "Normal parameter: "))
			.Visibility(this, &SHammerTextUErWidget::GetNormalVisibility)
			.IsEnabled(this, &SHammerTextUErWidget::HasNormalParameter)
			]
		+ SHorizontalBox::Slot()
			.AutoWidth()
			.MaxWidth(150.f)
			.VAlign(VAlign_Center)
			[
				SNew(SComboBox<TSharedPtr<FString>>)
				.OptionsSource(&normalParameterDropNamesList)
			.InitiallySelectedItem(InitialNormalSelected)
			.OnSelectionChanged(this, &SHammerTextUErWidget::HandleNormalComboSelectionChanged)
			.OnGenerateWidget(this, &SHammerTextUErWidget::HandleNormalComboGenerateWidget)
			.Visibility(this, &SHammerTextUErWidget::GetNormalVisibility)
			.IsEnabled(this, &SHammerTextUErWidget::HasNormalParameter)
			[
				SNew(STextBlock)
				.Text(this, &SHammerTextUErWidget::HandleNormalComboText)
			]
			]
		+ SHorizontalBox::Slot()
			.VAlign(VAlign_Center)
			.MaxWidth(100.f)
			.Padding(5.0f, 0.0f)
			.AutoWidth()
			[
				SNew(STextBlock)
				.Text(LOCTEXT("import_sourcespecularparameter", "Specular parameter: "))
			.Visibility(this, &SHammerTextUErWidget::GetSpecularVisibility)
			.IsEnabled(this, &SHammerTextUErWidget::HasSpecularParameter)
			]
		+ SHorizontalBox::Slot()
			.AutoWidth()
			.MaxWidth(150.f)
			.VAlign(VAlign_Center)
			[
				SNew(SComboBox<TSharedPtr<FString>>)
				.OptionsSource(&specularParameterDropNamesList)
			.InitiallySelectedItem(InitialSpecularSelected)
			.OnSelectionChanged(this, &SHammerTextUErWidget::HandleSpecularComboSelectionChanged)
			.OnGenerateWidget(this, &SHammerTextUErWidget::HandleSpecularComboGenerateWidget)
			.Visibility(this, &SHammerTextUErWidget::GetSpecularVisibility)
			.IsEnabled(this, &SHammerTextUErWidget::HasSpecularParameter)
			[
				SNew(STextBlock)
				.Text(this, &SHammerTextUErWidget::HandleSpecularComboText)
			]
			]
			]

			+SVerticalBox::Slot()
			.Padding(FMargin(3.f,0))
			[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
			.VAlign(VAlign_Center)
			.MaxWidth(100.f)
			.AutoWidth()
				[
					SNew(STextBlock)
					.Text(LOCTEXT("import_decalmaterial", "Decal material: "))
				]
			+ SHorizontalBox::Slot()
			.AutoWidth()
			.VAlign(VAlign_Center)
				[
					SNew(SObjectPropertyEntryBox)
					.ObjectPath(this, &SHammerTextUErWidget::GetDecalCurrentPath)
					.OnObjectChanged(this, &SHammerTextUErWidget::OnDecalMaterialChanged)
					.AllowClear(false)
					.AllowedClass(UMaterialInterface::StaticClass())
				]
			+ SHorizontalBox::Slot()
			.VAlign(VAlign_Center)
			.MaxWidth(100.f)
			.Padding(5.0f, 0.0f)
			.AutoWidth()
				[
					SNew(STextBlock)
					.Text(LOCTEXT("import_decalparameter", "Decal parameter: "))
				]
			+ SHorizontalBox::Slot()
			.AutoWidth()
			.MaxWidth(150.f)
			.VAlign(VAlign_Center)
				[
					SNew(SComboBox<TSharedPtr<FString>>)
					.OptionsSource(&decalParameterDropNamesList)
					.InitiallySelectedItem(InitialDecalSelected)
					.OnSelectionChanged(this, &SHammerTextUErWidget::HandleDecalComboSelectionChanged)
					.OnGenerateWidget(this, &SHammerTextUErWidget::HandleComboGenerateWidget)
					[
						SNew(STextBlock)
						.Text(this, &SHammerTextUErWidget::HandleDecalComboText)
					]
				]
			]
		+ SVerticalBox::Slot()
			.AutoHeight()
			.VAlign(VAlign_Center)
			.Padding(FMargin(3))
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
				.MaxWidth(200.f)
				[
					SNew(SBox)
					.WidthOverride(200.f)
					[
						SNew(SEditableTextBox)
						.BackgroundColor(FSlateColor(FLinearColor(FColor::White)))
						.OnTextCommitted(this, &SHammerTextUErWidget::TextureDirectoryChanged)
						.Text(this, &SHammerTextUErWidget::GetTextureImportDirectory)
						.ToolTipText(LOCTEXT("import_textureDirectory_tooltip","Content directory to import things to"))
					]
				]
				+SHorizontalBox::Slot()
				.Padding(FMargin(3.f))
				.MaxWidth(100.f)
				.VAlign(VAlign_Center)
				.AutoWidth()
				[
					SNew(STextBlock)
					.Text(LOCTEXT("import_textureMats", "Import: "))
					.ToolTipText(LOCTEXT("import_textureMats_tooltip","Types to import during this session"))
				]
				+ SHorizontalBox::Slot()
				.MaxWidth(350.f)
				.AutoWidth()
				[
					SNew(SHorizontalBox)
					+ SHorizontalBox::Slot()
					.MaxWidth(50)
					[
						SNew(SBox)
						.WidthOverride(50.f)
						[
							CreateRadioButton(LOCTEXT("Both", "Both"), Radio0)
						]
					]
					+ SHorizontalBox::Slot()
					.MaxWidth(80)
					[
						SNew(SBox)
						.WidthOverride(80.f)
						[
							CreateRadioButton(LOCTEXT("Tex", "Textures"), Radio1)
						]
					]
				+ SHorizontalBox::Slot()
					.MaxWidth(100)
					[
						SNew(SBox)
						.WidthOverride(100.f)
						[
							CreateRadioButton(LOCTEXT("Mat", "Materials"), Radio2)
						]
					]
				]
			]
		+ SVerticalBox::Slot()
			.AutoHeight()
			.Padding(FMargin(3))
			[
				SNew(SVerticalBox)
				+ SVerticalBox::Slot()
			.AutoHeight()
			.Padding(FMargin(3))
			[
				SNew(SHorizontalBox)
				+ SHorizontalBox::Slot()
			.AutoWidth()
			.VAlign(VAlign_Center)
			[
				SNew(STextBlock)
				.Text(LOCTEXT("ImportEndsWith", "Normal texture names end with: "))
			]
		+ SHorizontalBox::Slot()
			.VAlign(VAlign_Center)
			[
				SNew(SEditableTextBox)
				.BackgroundColor(FSlateColor(FLinearColor(FColor::White)))
			.OnTextCommitted(this, &SHammerTextUErWidget::OnNormalsEndChanged)
			.Text(this, &SHammerTextUErWidget::GetNormalsEndList)
			.ToolTipText(FText::FromString(TEXT("Comma separated list of segments")))
			]
			]
			]
		+ SVerticalBox::Slot()
			.AutoHeight()
			.Padding(FMargin(3))
			[
				SNew(SVerticalBox)
				+ SVerticalBox::Slot()
			.AutoHeight()
			.Padding(FMargin(3))
			[
				SNew(SHorizontalBox)
				+ SHorizontalBox::Slot()
			.AutoWidth()
			.VAlign(VAlign_Center)
			[
				SNew(STextBlock)
				.Text(LOCTEXT("ImportIgnoreEndsWith", "Don't build materials for texture names ending with: "))
			]
		+ SHorizontalBox::Slot()
			.VAlign(VAlign_Center)
			[
				SNew(SEditableTextBox)
				.BackgroundColor(FSlateColor(FLinearColor(FColor::White)))
			.OnTextCommitted(this, &SHammerTextUErWidget::OnIgnoreEndChanged)
			.Text(this, &SHammerTextUErWidget::GetIgnoreEndList)
			.ToolTipText(FText::FromString(TEXT("Comma separated list of segments")))
			]
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
			.ToolTipText(FText::FromString(TEXT("Directory containing VTF, PNG and BMP files you want to import")))
			.HAlign(HAlign_Center)
			.IsEnabled(this, &SHammerTextUErWidget::CanImport)
			.OnClicked(this, &SHammerTextUErWidget::GetImportDir)
			]
		+ SHorizontalBox::Slot()
			.AutoWidth()
			.MaxWidth(150.f)
			.VAlign(VAlign_Center)
			[
				SNew(SButton)
				.Text(LOCTEXT("import_go", "Import"))
			.HAlign(HAlign_Center)
			.IsEnabled(this, &SHammerTextUErWidget::CanRunImport)
			.OnClicked(this, &SHammerTextUErWidget::RunImport)

			]
		+ SHorizontalBox::Slot()
			.AutoWidth()
			.Padding(5.f, 0.0f)
			.VAlign(VAlign_Center)
			[
				SNew(STextBlock)
				.Text(this, &SHammerTextUErWidget::GetImportFolderName)
			]
			]
				]
			]
			]
				]
			]
		+ SVerticalBox::Slot()
			.AutoHeight()
			.Padding(3.0f, 1.0f)
			[
				SNew(SBox)
				[
					SNew(SBorder)
					.Padding(FMargin(3))
			[
				SNew(SVerticalBox)
				+ SVerticalBox::Slot()
			.Padding(FMargin(3))
			.AutoHeight()
			[
SNew(SHeader)
.Content()
[
	SNew(STextBlock)
	.Text(LOCTEXT("discovertext", "Discovery"))
]
			]
			+ SVerticalBox::Slot()
				.AutoHeight()
				[
					SNew(SBorder)
					[
						SNew(SVerticalBox)
						+ SVerticalBox::Slot()
				.AutoHeight()
				.VAlign(VAlign_Center)
				.Padding(FMargin(3))
				[
					SNew(SHorizontalBox)
					+ SHorizontalBox::Slot()
				.VAlign(VAlign_Center)
				.HAlign(HAlign_Center)
				.MaxWidth(300.f)
				.AutoWidth()
				[
					SNew(SButton)
					.Text(LOCTEXT("discoverybutton", "Discover materials in project"))
				.ToolTipText(FText::FromString(TEXT("Discover materials in project that aren't in the HammUEr master list and add them")))
				.HAlign(HAlign_Center)
				.IsEnabled(this, &SHammerTextUErWidget::CanDiscover)
				.OnClicked(this, &SHammerTextUErWidget::DoDiscovery)
				]
			+ SHorizontalBox::Slot()
				.VAlign(VAlign_Center)
				.HAlign(HAlign_Center)
				.AutoWidth()
				.Padding(3.0f, 1.0f)
				[
					SNew(SHorizontalBox)
					+ SHorizontalBox::Slot()
				.AutoWidth()
				.MaxWidth(250)
				.VAlign(VAlign_Center)
				.Padding(3.0f, 1.0f)
				[
					SNew(STextBlock)
					.Text(LOCTEXT("rebuild", "Rebuild entire master material list"))
				]
			+ SHorizontalBox::Slot()
				.AutoWidth()
				.MaxWidth(20)
				.VAlign(VAlign_Center)
				.Padding(3.0f, 1.0f)
				[
					SNew(SCheckBox)
					.IsChecked(this, &SHammerTextUErWidget::GetRebuild)
				.OnCheckStateChanged(this, &SHammerTextUErWidget::OnRebuildChanged)
				.ToolTipText(LOCTEXT("rebuildtooltip", "Rebuild the master material list. You'll lose all special substitutions you made."))
				]
				]
				]
					]
				]
			]
				]
			]
		]
		];
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION

FReply SHammerTextUErWidget::DoExportOnly()
{
	if (HammUErSettings::textureKeepContains.Num() > 0)
	{
		HammUErSettings::LoadConfig(true); // make sure to reload the master list first
		if (HammUErSettings::verboseDebugEnabled)
			UE_LOG(LogTemp, Log, TEXT("Getting all materials in the project..."));
		AssetData.Empty();
		FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");
		AssetRegistryModule.Get().GetAssetsByClass("Material", AssetData, true);
		TArray<FAssetData> AssetData2;
		AssetRegistryModule.Get().GetAssetsByClass("MaterialInstance", AssetData2, true);
		AssetData.Append(AssetData2);

//		if (HammUErSettings::verboseDebugEnabled)
			UE_LOG(LogTemp, Log, TEXT("Finding materials that match the search..."));
		FScopedSlowTask VerySlowTask(AssetData.Num(), FText::FromString("Finding materials that match the search..."));
		VerySlowTask.MakeDialog();
		TArray<UMaterialInterface*> toDo;
		TArray<FString> toDoNames;
		TArray<int> toDoIndex;
		for (int i = 0; i < AssetData.Num(); i++)
		{
			VerySlowTask.EnterProgressFrame(1);
			if (AssetData[i].PackagePath.ToString().Contains("Engine/"))
			{
				UE_LOG(LogTemp, Warning, TEXT("Skipping Engine texture %s"), *AssetData[i].PackageName.ToString());
				continue;
			}
			for (int j = 0; j < HammUErSettings::textureKeepContains.Num(); j++)
				if (AssetData[i].PackageName.ToString().Contains(HammUErSettings::textureKeepContains[j]))
				{
					UE_LOG(LogTemp, Warning, TEXT("Adding match %s"), *AssetData[i].PackageName.ToString());
					toDo.Add((UMaterialInterface*)AssetData[i].GetAsset());
					toDoNames.Add((AssetData[i].ObjectPath).ToString());
					toDoIndex.Add(i);
					break;
				}
		}
		//if (HammUErSettings::verboseDebugEnabled)
			UE_LOG(LogTemp, Log, TEXT("Found %i matches."), toDo.Num());

		if (toDo.Num() > 0)
		{
			FScopedSlowTask SlowTask(toDo.Num(), FText::FromString("Exporting materials..."));
			SlowTask.MakeDialog();

			for (int i = 0; i < toDo.Num(); i++)
			{
				UE_LOG(LogTemp, Log, TEXT("Item %i of %i"), i, toDo.Num());
				SlowTask.EnterProgressFrame(1);
				ExportMaterial(toDo[i], toDoNames[i], toDoIndex[i]);
			}
			toDo.Empty();
			toDoNames.Empty();
		}
		else
			UE_LOG(LogTemp, Warning, TEXT("Nothing found. Aborting."));

		HammUErSettings::SaveConfig();

	}
	else
		UE_LOG(LogTemp, Warning, TEXT("Nothing specified! Aborted."));
	FMessageDialog::Open(EAppMsgType::Ok, FText::FromString("Done."));
//	UE_LOG(LogTemp, Log, TEXT("Done"));
	return FReply::Handled();
}

void SHammerTextUErWidget::ExportMaterial(UMaterialInterface* workMaterial, FString newMatName, int index)
{
	TArray<uint8> builtArray;

	UTexture2D* testTexture = NULL;
	int32 textureWidth, textureHeight;

	TArray<UPackage*> unloadArray;

	FString materialFileString;
	FString VTFfileName;
	FString VMTfileName;

	TArray<UTexture*> chainTextures;
	TArray<UTexture*> parentTextures;
	TArray<FName> parameterNames;
	TArray<FName>parentparameterNames;
	FString oldMat = "HammUEr/" + workMaterial->GetName();
	FString fullName = workMaterial->GetPathName();
	fullName = fullName.Replace(TEXT("/Game/"), TEXT("HammUEr/"));
	fullName = fullName.Replace(*workMaterial->GetName(), TEXT(".VTF"));

	VTFfileName = HammUErSettings::VTFExportDirectory + "/" + oldMat + ".vtf";
	VMTfileName = HammUErSettings::VTFExportDirectory + "/" + oldMat + ".vmt";
	if (HammUErSettings::doUnload)
	unloadArray.AddUnique(workMaterial->GetOutermost());

	if (!FPaths::FileExists(VMTfileName))
	{
		if (workMaterial->GetTexturesInPropertyChain(EMaterialProperty::MP_BaseColor, chainTextures, &parameterNames, NULL))
		{
			materialFileString = "LightMappedGeneric\r\n{\r\n$basetexture HammUEr\\" + workMaterial->GetName() + "\r\n\"%keywords\" \"";
			TArray<FString> brokenUp;
			fullName.ParseIntoArray(brokenUp, TEXT("/"), true);
			brokenUp.RemoveAt(0);
			brokenUp.RemoveAt(brokenUp.Num() - 1);
			TArray<FString> keywordList; 
			for (int keyword = 0; keyword < brokenUp.Num(); keyword++)
				keywordList.AddUnique(brokenUp[keyword].ToLower());
			for (int keyword = 0; keyword < keywordList.Num(); keyword++)
				materialFileString += keywordList[keyword] + ",";
			materialFileString+="hammUEr\"\r\n}";
			UMaterialInterface* myParent = ((UMaterialInstance*)workMaterial)->Parent;
			if (myParent != NULL)
			{

				// this is an instance
				myParent->GetTexturesInPropertyChain(EMaterialProperty::MP_BaseColor, parentTextures, &parentparameterNames, NULL);
				if (HammUErSettings::verboseDebugEnabled)UE_LOG(LogTemp, Log, TEXT("Material instance, filtering all parent textures"));
				for (int i = 0; i < parentTextures.Num(); i++)
					chainTextures.Remove(parentTextures[i]);
				myParent = NULL;
			}
			testTexture = NULL;

			if (chainTextures.Num() > 0)
			{
				if (chainTextures.Num() == 1)
					testTexture = (UTexture2D*)chainTextures[0];
				else
				{
					for (int i = 0; i < chainTextures.Num(); i++)
					{
						if (chainTextures[i]->GetName().EndsWith("_D"))
						{
							testTexture = (UTexture2D*)chainTextures[i];
							break;
						}
					}
					if (testTexture == NULL) // okay, so we've got nothing
					{
						if (HammUErSettings::verboseDebugEnabled)UE_LOG(LogTemp, Log, TEXT("Filtering textures..."));
						for (int i = 0; i < chainTextures.Num(); i++)
						{
							bool filterOK = true;
							FString testTextureName = chainTextures[i]->GetName();
							for (int j = 0; j < HammUErSettings::textureBeginsWith.Num(); j++)
							{
								if (testTextureName.StartsWith(HammUErSettings::textureBeginsWith[j]))
								{
									filterOK = false;
									break;
								}
							}
							if (!filterOK)
								break;
							for (int j = 0; j < HammUErSettings::textureContains.Num(); j++)
							{
								if (testTextureName.Contains(HammUErSettings::textureContains[j]))
								{
									filterOK = false;
									break;
								}
							}
							if (!filterOK)
								break;
							for (int j = 0; j < HammUErSettings::textureEndsWith.Num(); j++)
							{
								if (testTextureName.EndsWith(HammUErSettings::textureEndsWith[j]))
								{
									filterOK = false;
									break;
								}
							}
							if (filterOK)
							{
								testTexture = (UTexture2D*)chainTextures[i];
								break;
								// yeah, sure, whatever, it passed the test, let's go with this one
							}
						}
					}
					if (testTexture == NULL) // no texture to use?
					{
						UE_LOG(LogTemp, Warning, TEXT("Did not find anything for %s"), *newMatName);
						return;
					}
				}

				textureWidth = testTexture->Source.GetSizeX();
				textureHeight = testTexture->Source.GetSizeY();
				shrinkTextures = true;
			
				ETextureSourceFormat whatFormat = testTexture->Source.GetFormat();


				builtArray.Add(0x56); // VTF\0
				builtArray.Add(0x54);
				builtArray.Add(0x46);
				builtArray.Add(0x00);
				builtArray.Append(ConvertUint32(7));  // version number
				builtArray.Append(ConvertUint32(2));
				builtArray.Append(ConvertUint32(80)); // header size
				builtArray.Append(ConvertShort(textureWidth));
				builtArray.Append(ConvertShort(textureHeight));
				int32 flags = (int)VTFTextureFlags::TEXTUREFLAGS_NOMIP | (int)VTFTextureFlags::TEXTUREFLAGS_NOLOD;

				builtArray.Append(ConvertUint32(flags));
				builtArray.Append(ConvertShort(1)); // animation frames. None
				builtArray.Append(ConvertShort(0));
				builtArray.Append(ConvertUint32(0)); // Padding0
				builtArray.Append(ConvertFloat(1.0f)); // Reflectivity vectors
				builtArray.Append(ConvertFloat(1.0f)); // Reflectivity vectors
				builtArray.Append(ConvertFloat(1.0f)); // Reflectivity vectors
				builtArray.Append(ConvertUint32(0)); // Padding1
				builtArray.Append(ConvertFloat(1.0f)); // bump map scale

				TArray<uint8> rawData;
				TArray<uint8> tempArray;

				switch (whatFormat)
				{
				case ETextureSourceFormat::TSF_BGRA8:
					testTexture->Source.GetMipData(tempArray, 0);
					rawData.AddZeroed(tempArray.Num());
					for (int y = 0; y < textureHeight; y++)
						for (int x = 0; x < textureWidth; x++)
						{
							rawData[(x + y*textureWidth) * 4] = tempArray[((x + y*textureWidth) * 4) + 2];
							rawData[((x + y*textureWidth) * 4) + 1] = tempArray[((x + y*textureWidth) * 4) + 1];
							rawData[((x + y*textureWidth) * 4) + 2] = tempArray[((x + y*textureWidth) * 4)];
							rawData[((x + y*textureWidth) * 4) + 3] = tempArray[((x + y*textureWidth) * 4) + 3];
						}
					builtArray.Append(ConvertUint32((int)VTFImageFormat::IMAGE_FORMAT_DXT5));
					break;
				case ETextureSourceFormat::TSF_RGBA8:
					testTexture->Source.GetMipData(rawData, 0);
					builtArray.Append(ConvertUint32((int)VTFImageFormat::IMAGE_FORMAT_DXT5));
					break;
				case ETextureSourceFormat::TSF_RGBA16:
					testTexture->Source.GetMipData(tempArray, 0);
					rawData.AddZeroed(tempArray.Num() / 2);
					for (int y = 0; y < textureHeight; y++)
						for (int x = 0; x < textureWidth; x++)
						{
							rawData[(x + y*textureWidth) * 4] = tempArray[((x + y*textureWidth) * 8)];
							rawData[((x + y*textureWidth) * 4) + 1] = tempArray[((x + y*textureWidth) * 8) + 2];
							rawData[((x + y*textureWidth) * 4) + 2] = tempArray[((x + y*textureWidth) * 8) + 4];
							rawData[((x + y*textureWidth) * 4) + 3] = tempArray[((x + y*textureWidth) * 8) + 6];
						}
					builtArray.Append(ConvertUint32((int)VTFImageFormat::IMAGE_FORMAT_DXT5));
					break;
				case ETextureSourceFormat::TSF_Invalid:
					// okay, let's see if it's a Substance Texture? Or another weird format?
					// I don't want to include the damn Substance dependency for everyone, so we're going to try to do an end run on this
				/*	UE_LOG(LogTemp, Log, TEXT("Expected size: %i x %i"), textureWidth, textureHeight);
					if (testTexture->GetNumMips() > 0)
					{
						FIntPoint size = testTexture->GetImportedSize();
						if (size.X < 1 || size.Y < 1)
						{
							UE_LOG(LogTemp, Error, TEXT("Texture size read attempt returned a %i x %i texture!"), size.X, size.Y);
							return;
						}
						textureWidth = size.X;
						textureHeight = size.Y;
						UE_LOG(LogTemp, Log, TEXT("New size: %i x %i"), textureWidth, textureHeight);

						TArray<uint8*> rawArray;
						rawArray.AddZeroed(testTexture->GetNumMips());
						if (testTexture->PlatformData->TryLoadMips(0, (void**)rawArray.GetData()) == false)
						{
							UE_LOG(LogTemp, Error, TEXT("Could not get mipmap data for 'Invalid' texture."));
							return;
						}
						uint32 totalSize = testTexture->PlatformData->Mips[0].BulkData.GetElementCount();
						tempArray.AddZeroed(totalSize);
						FMemory::Memcpy(tempArray.GetData(), rawArray[0], totalSize);
						for (auto MipData : rawArray)
							FMemory::Free(MipData);
						for (int i = 0; i < tempArray.Num(); i += 4)
						{
							Swap(tempArray[i + 2], tempArray[i]); // repeat after me. UE LIES AND 'RGBA' DATA IS NOT ACTUALLY RGBA
																  // we're going to assume a Texture2D doesn't need its alpha flattened
						}
						rawData.AddZeroed(tempArray.Num());
						for (int y = 0; y < textureHeight; y++)
							for (int x = 0; x < textureWidth; x++)
							{
								rawData[(x + y*textureWidth) * 4] = tempArray[((x + y*textureWidth) * 4) + 2];
								rawData[((x + y*textureWidth) * 4) + 1] = tempArray[((x + y*textureWidth) * 4) + 1];
								rawData[((x + y*textureWidth) * 4) + 2] = tempArray[((x + y*textureWidth) * 4)];
								rawData[((x + y*textureWidth) * 4) + 3] = tempArray[((x + y*textureWidth) * 4) + 3];
							}
						builtArray.Append(ConvertUint32((int)VTFImageFormat::IMAGE_FORMAT_DXT5));
					}
					else*/
					{
						UE_LOG(LogTemp, Warning, TEXT("Not implemented source format %s yet! %s"), *ConvertSourceFormat(whatFormat), *newMatName);
						return;
					}
					break;
				default:
					UE_LOG(LogTemp, Warning, TEXT("Not implemented source format %s yet! %s"), *ConvertSourceFormat(whatFormat), *newMatName);
					return;
				}
				int mipLevels = FMath::Log2(FMath::Min(textureHeight, textureWidth));
				if (textureHeight < 8 || textureWidth < 8)
				{
					mipLevels = 3;
				}
				builtArray.Add(mipLevels); 
	
				int thumbW = 0;
				int thumbH = 0;

				builtArray.Append(ConvertUint32((int)VTFImageFormat::IMAGE_FORMAT_NONE)); // screw this, it doesn't matter // I mean it
				builtArray.Add(thumbW);
				builtArray.Add(thumbH);
				builtArray.Append(ConvertShort(1));
				
				builtArray.AddZeroed(15); // 80 char header
				
				TArray<uint8> dxtData;
				if (HammUErSettings::doUnload)
					for (int unloadLoop = 0; unloadLoop < chainTextures.Num(); unloadLoop++)
						unloadArray.AddUnique(chainTextures[unloadLoop]->GetOutermost());

				if (HammUErSettings::FindInMaster(oldMat) == -1) // wait we didn't actually know this material yet?
				{
					TSharedPtr<FMaterialListEntry> newEntry;
					newEntry = MakeShareable(new FMaterialListEntry());
					newEntry->textureHeight =textureHeight;
					newEntry->textureWidth =textureWidth;
					newEntry->oldName = oldMat.ToUpper();
					newEntry->newMaterialName = newMatName; //(AssetData[currentMaterial].ObjectPath).ToString();
					newEntry->newMaterial = NULL; //workMaterial;
					newEntry->AssetDatabaseIndex = index;
					workMaterial = NULL; // FIXME
					if (oldMat.Contains("nodraw") || oldMat.ToLower() == "clip" || oldMat.ToLower() == "origin" || oldMat.Contains("toolsorigin") || oldMat.Contains("toolsclip"))
						newEntry->ignore = true;
					HammUErSettings::masterMaterialList.AddUnique(newEntry);
				}

				int32 newtextureWidth, newtextureHeight;
				TArray<uint8> shrunkTexture;
				unsigned char* inTex;
				unsigned char* outTex;
				for (int mips = mipLevels; mips >= 0; mips--)
				{
					int divider = FMath::Pow(2,mips);
					newtextureHeight = textureHeight / divider;
					newtextureWidth = textureWidth / divider;
					shrunkTexture.Empty();
					shrunkTexture.AddZeroed(newtextureHeight*newtextureWidth * 4);
					for (int y = 0; y < newtextureHeight; y++)
						for (int x = 0; x < newtextureWidth; x++)
						{
							shrunkTexture[(x + y*newtextureWidth) * 4] = rawData[((x * divider) + (y * divider)*textureWidth) * 4];
							shrunkTexture[((x + y*newtextureWidth) * 4) + 1] = rawData[(((x * divider) + (y * divider)*textureWidth) * 4) + 1];
							shrunkTexture[((x + y*newtextureWidth) * 4) + 2] = rawData[(((x * divider) + (y * divider)*textureWidth) * 4) + 2];
							shrunkTexture[((x + y*newtextureWidth) * 4) + 3] = rawData[(((x * divider) + (y * divider)*textureWidth) * 4) + 3];
						}
					if (shrunkTexture.Num() < 64)
						shrunkTexture.AddZeroed(64 - shrunkTexture.Num());
					dxtData.AddUninitialized(shrunkTexture.Num() / 4);
					
					inTex = shrunkTexture.GetData();
					outTex = dxtData.GetData();
					rygCompress(outTex, inTex, newtextureWidth, newtextureHeight, 1);
					builtArray.Append(dxtData);
					dxtData.Empty();
				}
					
				FFileHelper::SaveArrayToFile(builtArray, *VTFfileName);
				FFileHelper::SaveStringToFile(materialFileString, *VMTfileName);
			}
		}
		else
			UE_LOG(LogTemp, Warning, TEXT("No textures in the basecolor chain for %s, skipping."), *newMatName);
	}
	else
		if (HammUErSettings::verboseDebugEnabled)UE_LOG(LogTemp, Warning, TEXT("VTF file for %s already exists at destination, skipping."), *newMatName);

	if (HammUErSettings::doUnload)
		PackageTools::UnloadPackages(unloadArray);
}

void SHammerTextUErWidget::DoNextMaterial()  /// export the current material
{
	
	completionPercentage = ((float)currentMaterial / (float)AssetData.Num());
	if (AssetData[currentMaterial].PackagePath.ToString().Contains("/Game"))  // skip the engine stuff because it crashes
	{
		if (HammUErSettings::verboseDebugEnabled)
		{
			FString outputString = ". Working on " + FString::FromInt(currentMaterial) + " of " + FString::FromInt(AssetData.Num());
			UE_LOG(LogTemp, Warning, TEXT("%s"), *outputString);
		}

		bool doContinue = false;
		if (HammUErSettings::textureKeepContains.Num() > 0)
		{
			for (int i = 0; i < HammUErSettings::textureKeepContains.Num(); i++)
			{
				if (AssetData[currentMaterial].PackageName.ToString().Contains(HammUErSettings::textureKeepContains[i]))
				{
					doContinue = true;
					break;
				}
			}
		}
		else
			doContinue = true; // always continue if there's nothing in the list

		if (doContinue)
			ExportMaterial((UMaterialInterface*)AssetData[currentMaterial].GetAsset(), (AssetData[currentMaterial].ObjectPath).ToString(), currentMaterial);
	}
	else
		if (HammUErSettings::verboseDebugEnabled)UE_LOG(LogTemp, Warning, TEXT("Skipping non-game material %s"), *AssetData[currentMaterial].PackagePath.ToString());

	currentMaterial++;
	if (currentMaterial == AssetData.Num())
	{
		running = false;
		FMessageDialog::Open(EAppMsgType::Ok, FText::FromString("Done."));
		completionPercentage = 1.0f;
		HammUErSettings::SaveConfig();
	}
}

// discovery stuff
bool SHammerTextUErWidget::CanDiscover() const
{
	return (!running && !importRunning && !discovering);
}

FReply SHammerTextUErWidget::DoDiscovery()
{
	HammUErSettings::LoadConfig(true); // make sure to reload the master list first
	if (HammUErSettings::discoverRebuild)
	{
		HammUErSettings::masterMaterialList.Empty();
	}

	AssetData.Empty();
	FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");
	AssetRegistryModule.Get().GetAssetsByClass("Material", AssetData, true);
	TArray<FAssetData> AssetData2;
	AssetRegistryModule.Get().GetAssetsByClass("MaterialInstance", AssetData2, true);
	AssetData.Append(AssetData2);

	if (HammUErSettings::verboseDebugEnabled)
	{
		FString outputString = "--- Complete Asset Database ---";
		UE_LOG(LogTemp, Warning, TEXT("%s"), *outputString);
		for (int i = 0; i < AssetData.Num(); i++)
		{
			outputString = "[" + FString::FromInt(i) + "] = " + AssetData[i].PackageName.ToString();
			UE_LOG(LogTemp, Warning, TEXT("%s"), *outputString);
		}
	}
	discovering = true;
	currentMaterial = 0;
	return FReply::Handled();
}

void SHammerTextUErWidget::DoNextDiscovery()
{
	UMaterialInterface* workMaterial;
	UTexture2D* testTexture = NULL;
	int32 textureWidth, textureHeight;
	FString materialFileString;

	TArray<UPackage*> unloadArray;

	completionPercentage = ((float)currentMaterial / (float)AssetData.Num());
	if (currentMaterial > AssetData.Num())
	{
		discovering = false;
		return;
	}
	if (AssetData[currentMaterial].PackagePath.ToString().Contains("/Game"))  // skip the engine stuff because it crashes
	{
		if (AssetData[currentMaterial].PackageName.ToString().Contains("M_ColorGrid_LowSpec"))
		{
			currentMaterial++;
			return;
		}
		if (HammUErSettings::verboseDebugEnabled)
		{
			FString outputString = ". Working on " + FString::FromInt(currentMaterial) + " of " + FString::FromInt(AssetData.Num());
			UE_LOG(LogTemp, Warning, TEXT("%s"), *outputString);
		}

		bool doContinue = false;
		if (HammUErSettings::textureKeepContains.Num() > 0)
		{
			for (int i = 0; i < HammUErSettings::textureKeepContains.Num(); i++)
			{

			}
		}
		else
			doContinue = true; // always continue if there's nothing in the list

		if (!doContinue)
		{
			currentMaterial++;
			return;
		}

		workMaterial = (UMaterialInterface*)AssetData[currentMaterial].GetAsset();
		unloadArray.AddUnique(workMaterial->GetOutermost());

		TArray<UTexture*> chainTextures;
		TArray<UTexture*> parentTextures;
		TArray<FName> parameterNames;
		TArray<FName>parentparameterNames;

		FString matString;
		matString = workMaterial->GetName();
		FString MatDir = workMaterial->GetPathName();
		MatDir.RemoveFromEnd(matString);
		MatDir.RemoveFromEnd(".");
		int firstslash = MatDir.Find("/", ESearchCase::IgnoreCase, ESearchDir::FromEnd);
		int secondslash = MatDir.Find("/", ESearchCase::IgnoreCase, ESearchDir::FromEnd, firstslash - 1);
		FString MatDirectoryName = MatDir.Mid(secondslash + 1, (firstslash - 1) - (secondslash));
		if (MatDirectoryName.ToUpper() != "GAME")
			matString = MatDirectoryName + "/" + matString;

		if (HammUErSettings::verboseDebugEnabled)
		{
			FString outputString = ".. Testing used textures in material";
			UE_LOG(LogTemp, Warning, TEXT("%s"), *outputString);
		}
		workMaterial->GetUsedTextures(parentTextures, EMaterialQualityLevel::High, true, ERHIFeatureLevel::SM5, true);
		if (parentTextures.Num() > 0)
		{
			parentTextures.Empty();
			if (HammUErSettings::verboseDebugEnabled)
			{
				FString outputString = "... Testing MP_BaseColor in material";
				UE_LOG(LogTemp, Warning, TEXT("%s"), *outputString);
			}
			if (workMaterial->GetTexturesInPropertyChain(EMaterialProperty::MP_BaseColor, chainTextures, &parameterNames, NULL))
			{
				UMaterialInterface* myParent = ((UMaterialInstance*)workMaterial)->Parent;
				if (myParent != NULL)
				{
					if (HammUErSettings::verboseDebugEnabled)
					{
						FString outputString = ".... Testing MP_BaseColor in parent";
						UE_LOG(LogTemp, Warning, TEXT("%s"), *outputString);
					}
					myParent->GetTexturesInPropertyChain(EMaterialProperty::MP_BaseColor, parentTextures, &parentparameterNames, NULL);
					if (HammUErSettings::verboseDebugEnabled)UE_LOG(LogTemp, Log, TEXT("Material instance, filtering all parent textures"));
					for (int i = 0; i < parentTextures.Num(); i++)
						chainTextures.Remove(parentTextures[i]);

				}
				testTexture = NULL;
				if (HammUErSettings::verboseDebugEnabled)
				{
					FString outputString = ".... Finding texture to use";
					UE_LOG(LogTemp, Warning, TEXT("%s"), *outputString);
				}

				for (int cleanup = 0; cleanup < chainTextures.Num(); cleanup++)
					unloadArray.AddUnique(chainTextures[cleanup]->GetOutermost());

				for (int cleanup = 0; cleanup < parentTextures.Num(); cleanup++)
					unloadArray.AddUnique(parentTextures[cleanup]->GetOutermost());

				if (chainTextures.Num() > 0)
				{
					if (chainTextures.Num() == 1)
						testTexture = (UTexture2D*)chainTextures[0];
					else
					{
						for (int i = 0; i < chainTextures.Num(); i++)
						{
							if (chainTextures[i]->GetName().EndsWith("_D"))
							{
								testTexture = (UTexture2D*)chainTextures[i];
								break;
							}
						}
						if (testTexture == NULL) // okay, so we've got nothing
						{
							if (HammUErSettings::verboseDebugEnabled)UE_LOG(LogTemp, Log, TEXT("Filtering textures..."));
							for (int i = 0; i < chainTextures.Num(); i++)
							{
								bool filterOK = true;
								FString testTextureName = chainTextures[i]->GetName();
								for (int j = 0; j < HammUErSettings::textureBeginsWith.Num(); j++)
								{
									if (testTextureName.StartsWith(HammUErSettings::textureBeginsWith[j]))
									{
										filterOK = false;
										break;
									}
								}
								if (!filterOK)
									break;
								for (int j = 0; j < HammUErSettings::textureContains.Num(); j++)
								{
									if (testTextureName.Contains(HammUErSettings::textureContains[j]))
									{
										filterOK = false;
										break;
									}
								}
								if (!filterOK)
									break;
								for (int j = 0; j < HammUErSettings::textureEndsWith.Num(); j++)
								{
									if (testTextureName.EndsWith(HammUErSettings::textureEndsWith[j]))
									{
										filterOK = false;
										break;
									}
								}
								if (filterOK)
								{
									testTexture = (UTexture2D*)chainTextures[i];
									break;
									// yeah, sure, whatever, it passed the test, let's go with this one
								}
							}
						}
						if (testTexture == NULL) // no texture to use?
						{
							UE_LOG(LogTemp, Warning, TEXT("Did not find anything for %s"), *AssetData[currentMaterial].PackagePath.ToString());
							currentMaterial++;
							if (currentMaterial == AssetData.Num())
							{
								discovering = false;
								FMessageDialog::Open(EAppMsgType::Ok, FText::FromString("Done."));
							}
							return;
						}
					}

					if (HammUErSettings::verboseDebugEnabled)	// why did I do this like this? I have no idea.
					{
						FString outputString = "..... Adding to master material list";
						UE_LOG(LogTemp, Warning, TEXT("%s"), *outputString);
					}

					textureWidth = testTexture->Source.GetSizeX();
					textureHeight = testTexture->Source.GetSizeY();

					testTexture = NULL;
					chainTextures.Empty();
					parentTextures.Empty();

					// Extra check
					int oldIndex = HammUErSettings::FindInMaster(matString);
					if (oldIndex > -1)
					{
						if (HammUErSettings::masterMaterialList[oldIndex]->newMaterial == NULL)
						{
							if (HammUErSettings::verboseDebugEnabled)
								UE_LOG(LogTemp, Warning, TEXT("Found an old empty %s, removing"), *matString);
							HammUErSettings::masterMaterialList.RemoveAt(oldIndex);
						}
					}
					if (HammUErSettings::FindInMaster(matString) == -1)//(!HammUErSettings::masterMaterialList.ContainsByPredicate([&](TSharedPtr<FMaterialListEntry> checkingAsset) {return checkingAsset->oldName == matString; }))
					{
						TSharedPtr<FMaterialListEntry> newEntry;
						newEntry = MakeShareable(new FMaterialListEntry());
						newEntry->textureHeight = textureHeight;
						newEntry->textureWidth = textureWidth;
						newEntry->oldName = matString.ToUpper();
						newEntry->newMaterialName = (AssetData[currentMaterial].ObjectPath).ToString();
						newEntry->newMaterial = NULL; //workMaterial;
						newEntry->AssetDatabaseIndex = currentMaterial;
						newEntry->ignore = false;
						if (matString.Contains("nodraw") || matString.ToLower() == "clip" || matString.ToLower() == "origin" || matString.Contains("toolsorigin") || matString.Contains("toolsclip"))
							newEntry->ignore = true;
						HammUErSettings::masterMaterialList.AddUnique(newEntry);
						workMaterial = NULL;

					}

				}
			}
		}
		if (HammUErSettings::doUnload)
			PackageTools::UnloadPackages(unloadArray);

	}
	currentMaterial++;
	if (currentMaterial == AssetData.Num())
	{
		discovering = false;
		FMessageDialog::Open(EAppMsgType::Ok, FText::FromString("Done."));
		completionPercentage = 1.0f;
		HammUErSettings::SaveConfig();
	}
}

// import stuff 
bool SHammerTextUErWidget::CanRunImport() const
{
	return (!discovering && !running && !importRunning && (sourceMaterial != NULL) && (currentParameter != "") && HammUErSettings::textureSourceDirectory != "" && HammUErSettings::textureImportDirectory != "");
}

void SHammerTextUErWidget::CreateTexture(int32 width, int32 height, TArray<FColor>& colorArray, FString ObjectName, bool hasAlpha)
{
	// last minute sanitizing, just in case we missed one
	ObjectName = ObjectName.Replace(TEXT("*"), TEXT("X"));
	ObjectName = ObjectName.Replace(TEXT("?"), TEXT("Q"));
	ObjectName = ObjectName.Replace(TEXT("!"), TEXT("I"));
	ObjectName = ObjectName.Replace(TEXT(":"), TEXT("_"));
	ObjectName = ObjectName.Replace(TEXT("."), TEXT("-"));
	ObjectName = ObjectName.Replace(TEXT("&"), TEXT("_"));
	ObjectName = ObjectName.Replace(TEXT(" "), TEXT("_"));


	FString NewPackageName = TEXT("/Game/") + (HammUErSettings::textureImportDirectory == "" ? "Textures/" : HammUErSettings::textureImportDirectory + "/Textures/") + ObjectName;
	UPackage* Package = CreatePackage(NULL, *NewPackageName);
	Package->FullyLoad();
	Package->Modify();

	FCreateTexture2DParameters FCT;
	FCT.bUseAlpha = hasAlpha;
	if (HammUErSettings::useTextureAlpha) 
		FCT.bUseAlpha = false;

	FString TextureName = ObjectName;
	if (TextureName.Contains("/"))
		TextureName = TextureName.Mid(TextureName.Find("/", ESearchCase::IgnoreCase, ESearchDir::FromEnd) + 1);

	UTexture2D* basetexture = FImageUtils::CreateTexture2D(width, height, colorArray, Package, *TextureName, RF_Public | RF_Standalone, FCT);
	FAssetRegistryModule::AssetCreated(basetexture);
	basetexture->PostEditChange();
	colorArray.Empty();

	FString PackageFileName = FPackageName::LongPackageNameToFilename(NewPackageName, FPackageName::GetAssetPackageExtension());
	try
	{
#if ENGINE_MINOR_VERSION>=11

		if (HammUErSettings::generateThumbs)
			ThumbnailTools::GenerateThumbnailForObjectToSaveToDisk(basetexture);
#endif
		if (GEditor->SavePackage(Package, basetexture, RF_Public | RF_Standalone, *PackageFileName, GError, nullptr, false, true, SAVE_None))
		{
			Package->PostEditChange();
			FAssetRegistryModule::AssetCreated(basetexture);
			importerTextureList.Add(ObjectName, ImporterTextureInfo(NewPackageName, width, height));

			unloadtest.AddUnique(Package);
		}
		else
			UE_LOG(LogTemp, Error, TEXT("Could not save package %s"), *PackageFileName);
	}
	catch (...)
	{
		UE_LOG(LogTemp, Error, TEXT("Something went catastrophically wrong trying to save an unreal package for %s. In unreal code."), *ObjectName);
	}

	createdTextures++;
	if (createdTextures > 50)
	{
		if (HammUErSettings::doUnload)
			PackageTools::UnloadPackages(unloadtest);
		unloadtest.Empty();
	}
}

bool SHammerTextUErWidget::ImporterMaterialsDoneContains(FString textureName)
{
	if (importerMaterialsDone.Num() == 0)  // nothing?
		return false;

	if (importerMaterialsDone.Contains(textureName))  // full match
		return true;

	for (int i = 0; i < importerMaterialsDone.Num(); i++)
	{
		if (importerMaterialsDone[i].EndsWith(textureName))
			return true;
		if (textureName.EndsWith(importerMaterialsDone[i]))
			return true;
	}
	if (HammUErSettings::permissiveMaterialCreation)
	for (int i = 0; i < importerMaterialsDone.Num(); i++)
	{
		if (importerMaterialsDone[i].Contains(textureName))
			return true;
	}

	return false;
}

bool SHammerTextUErWidget::ImporterTextureListContains(FString textureName, FString &foundName)
{
	if (importerTextureNames.Num() == 0) // first call?
		importerTextureList.GetKeys(importerTextureNames);
	
	if (importerTextureList.Num() == 0)
	{
		if (TextureDatabaseContains(textureName, foundName))
			return true;
	}

	if (importerTextureNames.Contains(textureName))
	{
		foundName = importerTextureList[textureName].textureLocation;  // we've got a simple match
		return true;
	}

	for (int i = 0; i < importerTextureNames.Num(); i++)
	{
		if (importerTextureNames[i].EndsWith(textureName))
		{
			foundName = importerTextureList[importerTextureNames[i]].textureLocation;
			return true;
		}
	}

	if (TextureDatabaseContains(textureName, foundName))
		return true;

	// still nothing
	foundName = "NotFound";
	return false;
}

bool SHammerTextUErWidget::TextureDatabaseContains(FString textureName, FString &foundName)
{
	if (TextureAssets.Num() == 0) // first call?
		ReloadTextureDatabase();

	for (int i = 0; i < TextureAssets.Num(); i++)
	{
		if (TextureAssets[i].PackageName.ToString().EndsWith(textureName))
		{
			foundName = TextureAssets[i].PackageName.ToString();
			return true;
		}
	}
	UE_LOG(LogTemp, Warning, TEXT("Could not find %s, cutting down to smallest identifier."), *textureName);
	int offset = textureName.Find("/", ESearchCase::IgnoreCase, ESearchDir::FromEnd);
	textureName = textureName.RightChop(offset);
	for (int i = 0; i < TextureAssets.Num(); i++)
	{
		if (TextureAssets[i].PackageName.ToString().EndsWith(textureName))
		{
			foundName = TextureAssets[i].PackageName.ToString();
			return true;
		}
	}
	foundName = "none";
	return false;
}


void SHammerTextUErWidget::ReloadTextureDatabase()
{
	FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");
	TextureAssets.Empty();
	AssetRegistryModule.Get().GetAssetsByClass("Texture2D", TextureAssets, true);
}

UTexture2D* SHammerTextUErWidget::GetTextureFromAssetDatabase(FString textureName)
{
	if (TextureAssets.Num() == 0) // first call?
		ReloadTextureDatabase();

	for (int i = 0; i < TextureAssets.Num(); i++)
	{
		if (TextureAssets[i].PackageName.ToString() == textureName)
			return (UTexture2D*)TextureAssets[i].GetAsset();
	}

	for (int i = 0; i < TextureAssets.Num(); i++)
	{
		if (TextureAssets[i].PackageName.ToString().EndsWith(textureName))
			return (UTexture2D*)TextureAssets[i].GetAsset();
	}
	UTexture2D* toReturn = NULL;

	// try and load it explicitly, since apparently the asset database is slow to update
	toReturn = Cast<UTexture2D>(StaticLoadObject(UTexture2D::StaticClass(), NULL, *textureName));

	return (UTexture2D*)toReturn;
}

void SHammerTextUErWidget::CreateMaterial(int i)
{
	FString textureToUse = "";

	int textureWidthFound = HammUErSettings::defaultWidth;
	int textureHeightFound = HammUErSettings::defaultHeight;

	if (!ImporterTextureListContains(importerVMTList[i]->baseTexture, textureToUse))
	{
		UE_LOG(LogTemp, Error, TEXT("Could not find texture %s for VMT %s, aborting creation of material"), *importerVMTList[i]->baseTexture, *importerVMTList[i]->VMTName);
		return;
	}

	FString originalName = importerVMTList[i]->VMTName;

	FString TextureName = importerVMTList[i]->VMTName;
	if (TextureName.Contains("/"))
		TextureName = TextureName.Mid(TextureName.Find("/", ESearchCase::IgnoreCase, ESearchDir::FromEnd) + 1);

	//auto MaterialFactory = NewObject<UMaterialFactoryNew>();

	FString MaterialName = importerVMTList[i]->VMTName + "_mat";

	MaterialName = MaterialName.Replace(TEXT(" "), TEXT("_"));
	MaterialName = MaterialName.Replace(TEXT("&"), TEXT("_"));
	MaterialName = MaterialName.Replace(TEXT("!"), TEXT("I"));
	MaterialName = MaterialName.Replace(TEXT("."), TEXT("-"));

	FString NMIDPackageName = TEXT("/Game/") + (HammUErSettings::textureImportDirectory == "" ? "Materials/" : HammUErSettings::textureImportDirectory + "/Materials/") + MaterialName;
	FString NMIDPackageFileName = FPackageName::LongPackageNameToFilename(NMIDPackageName, FPackageName::GetAssetPackageExtension());
	UPackage* NMIDPackage = CreatePackage(NULL, *NMIDPackageName);
	NMIDPackage->FullyLoad();
	NMIDPackage->Modify();

	if (MaterialName.Contains("/"))
		MaterialName = MaterialName.Mid(MaterialName.Find("/", ESearchCase::IgnoreCase, ESearchDir::FromEnd) + 1);

	UMaterialInstanceConstantFactoryNew* Factory = NewObject<UMaterialInstanceConstantFactoryNew>();
	if (importerVMTList[i]->isDecal)
	{
		if (decalMaterial)
			Factory->InitialParent = decalMaterial;
		else
		{
			UE_LOG(LogTemp, Error, TEXT("No decal material specified! Aborting %s!"), *MaterialName);
			return;
		}
	}
	else
		Factory->InitialParent = sourceMaterial;

	UMaterialInstanceConstant* newVMTMaterial = (UMaterialInstanceConstant*)Factory->FactoryCreateNew(UMaterialInstanceConstant::StaticClass(), NMIDPackage, *MaterialName, RF_Standalone | RF_Public, NULL, GWarn);

	UTexture2D* texToUse;

	if (HammUErSettings::useTextureAlpha)
	{
		if (importerVMTList[i]->isDecal || importerVMTList[i]->isMasked || importerVMTList[i]->isTranslucent)
		{  // well... crap
			UE_LOG(LogTemp, Warning, TEXT("Material %s requires texture alpha!"), *importerVMTList[i]->VMTName);
			// did we just import this texture?
			if (importerTextureList.Num() == 0)
			{
				UE_LOG(LogTemp, Error, TEXT("No textures imported this session. Reimport %s yourself with ignore alpha turned off."), *importerVMTList[i]->baseTexture);
			}
			else
			{ // yep!
				HammUErSettings::useTextureAlpha = !HammUErSettings::useTextureAlpha; // it's not cheating if it's working around your own code
				FString* reimportName = PendingImportFiles.FindByPredicate([&](FString toTest) { return toTest.EndsWith(importerVMTList[i]->baseTexture + ".vtf"); });
				if (reimportName)
				{
					ImportVTF(*reimportName);
				}
				HammUErSettings::useTextureAlpha = !HammUErSettings::useTextureAlpha; // see? nobody noticed anything
			}
		}
	}

	if (importerVMTList[i]->baseTexture != "")
	{
		if (ImporterTextureListContains(importerVMTList[i]->baseTexture, textureToUse))
		{
			texToUse = GetTextureFromAssetDatabase(textureToUse);
			if (texToUse != NULL)
			{
				textureWidthFound = texToUse->Source.GetSizeX();
				textureHeightFound = texToUse->Source.GetSizeY();
				if (importerVMTList[i]->isDecal)
					newVMTMaterial->SetTextureParameterValueEditorOnly(*decalParameter, texToUse);
				else
					newVMTMaterial->SetTextureParameterValueEditorOnly(*currentParameter, texToUse);
				importerMaterialsDone.AddUnique(importerVMTList[i]->baseTexture);
				unloadtest.AddUnique(texToUse->GetOutermost());
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("Something went wrong trying to get %s"), *textureToUse);
				failedMats.AddUnique(MaterialName);
			}
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("No base texture for material found"));
			failedMats.AddUnique(MaterialName);
		}
	}

	if (importerVMTList[i]->decalScale != 1)
		HammUErSettings::decalScales.Add(importerVMTList[i]->VMTName.ToUpper(), importerVMTList[i]->decalScale);

	if (!importerVMTList[i]->isDecal)
	{
		if (importerVMTList[i]->baseTexture2 != "")
		{
			if (currentBlendParameter != "")
			{
				if (ImporterTextureListContains(importerVMTList[i]->baseTexture2, textureToUse))
				{
					texToUse = GetTextureFromAssetDatabase(textureToUse);
					if (texToUse != NULL)
					{
						newVMTMaterial->SetTextureParameterValueEditorOnly(*currentBlendParameter, texToUse);
						importerMaterialsDone.AddUnique(importerVMTList[i]->baseTexture2);
						unloadtest.AddUnique(texToUse->GetOutermost());
					}
					else
					{
						UE_LOG(LogTemp, Warning, TEXT("Something went wrong trying to get %s"), *textureToUse);
						failedMats.AddUnique(MaterialName);
					}
				}
				else
				{
					UE_LOG(LogTemp, Warning, TEXT("No base texture for material found"));
					failedMats.AddUnique(MaterialName);
				}
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("No secondary BaseColor parameter in material."));
				failedMats.AddUnique(MaterialName);
			}
		}

		if (matContainsNormal)
		{
			if (importerVMTList[i]->normalTexture != "")
			{
				if (ImporterTextureListContains(importerVMTList[i]->normalTexture, textureToUse))
				{
					texToUse = GetTextureFromAssetDatabase(textureToUse);
					if (texToUse != NULL)
					{
						newVMTMaterial->SetTextureParameterValueEditorOnly(*currentNormalParameter, texToUse);
						importerMaterialsDone.AddUnique(importerVMTList[i]->normalTexture);
						unloadtest.AddUnique(texToUse->GetOutermost());
					}
					else
					{
						UE_LOG(LogTemp, Warning, TEXT("Something went wrong trying to get %s"), *textureToUse);
						failedMats.AddUnique(MaterialName);
					}
				}
				else
				{
					UE_LOG(LogTemp, Warning, TEXT("No normal texture for material found"));
					failedMats.AddUnique(MaterialName);
				}
			}
			if (importerVMTList[i]->normalTexture2 != "")
			{
				if (currentBlendNormalParameter != "")
				{
					if (ImporterTextureListContains(importerVMTList[i]->normalTexture2, textureToUse))
					{
						texToUse = GetTextureFromAssetDatabase(textureToUse);
						if (texToUse != NULL)
						{
							newVMTMaterial->SetTextureParameterValueEditorOnly(*currentBlendNormalParameter, texToUse);
							importerMaterialsDone.AddUnique(importerVMTList[i]->normalTexture2);
							unloadtest.AddUnique(texToUse->GetOutermost());
						}
						else
						{
							UE_LOG(LogTemp, Warning, TEXT("Something went wrong trying to get %s"), *textureToUse);
							failedMats.AddUnique(MaterialName);
						}
					}
				}
				else
				{
					UE_LOG(LogTemp, Warning, TEXT("No secondary Normal parameter in material."));
					failedMats.AddUnique(MaterialName);
				}
			}
		}

		if (matContainsSpecular)
		{
			if (importerVMTList[i]->specularTexture != "")
			{
				if (ImporterTextureListContains(importerVMTList[i]->specularTexture, textureToUse))
				{
					texToUse = GetTextureFromAssetDatabase(textureToUse);
					if (texToUse != NULL)
					{
						newVMTMaterial->SetTextureParameterValueEditorOnly(*currentSpecularParameter, texToUse);
						importerMaterialsDone.AddUnique(importerVMTList[i]->specularTexture);
						unloadtest.AddUnique(texToUse->GetOutermost());
					}
					else
					{
						UE_LOG(LogTemp, Warning, TEXT("Something went wrong trying to get %s"), *textureToUse);
						failedMats.AddUnique(MaterialName);
					}
				}
				else
				{
					UE_LOG(LogTemp, Warning, TEXT("No specular texture for material found"));
					failedMats.AddUnique(MaterialName);
				}
			}
		}
	}
	if (importerVMTList[i]->isMasked)
	{
		newVMTMaterial->BasePropertyOverrides.bOverride_BlendMode = true;
		newVMTMaterial->BasePropertyOverrides.BlendMode = BLEND_Masked;
	}
	else
	if (importerVMTList[i]->isTranslucent)
	{
		newVMTMaterial->BasePropertyOverrides.bOverride_BlendMode = true;
		newVMTMaterial->BasePropertyOverrides.BlendMode = BLEND_Translucent;
	}
	else if (!importerVMTList[i]->isDecal)
	{
		newVMTMaterial->BasePropertyOverrides.bOverride_BlendMode = true;
		newVMTMaterial->BasePropertyOverrides.BlendMode = BLEND_Opaque;
	}

	bool switchBlend = false;
	switch (importerVMTList[i]->shader)
	{
	case VMTShaderType::LightmappedGeneric:
		newVMTMaterial->BasePropertyOverrides.bOverride_ShadingModel = true;
		newVMTMaterial->BasePropertyOverrides.ShadingModel = EMaterialShadingModel::MSM_DefaultLit;
		break;
	case VMTShaderType::UnlitGeneric:
		newVMTMaterial->BasePropertyOverrides.bOverride_ShadingModel = true;
		newVMTMaterial->BasePropertyOverrides.ShadingModel = EMaterialShadingModel::MSM_DefaultLit;  // TODO: turn on selfillum
		break;
	case VMTShaderType::VertexLitGeneric:
		newVMTMaterial->BasePropertyOverrides.bOverride_ShadingModel = true;
		newVMTMaterial->BasePropertyOverrides.ShadingModel = EMaterialShadingModel::MSM_DefaultLit;
		break;
	case VMTShaderType::WorldVertexTransition:
		switchBlend = true;
		break;
	}

	bool testBool = false; 
	FGuid testGUID;

	if (importerVMTList[i]->isSelfIllum)
	{
		if (sourceMaterial->GetStaticSwitchParameterValue(FName("$SelfIllum"), testBool, testGUID))
		{
			FStaticParameterSet updatedParams;
			newVMTMaterial->GetStaticParameterValues(updatedParams);
			for (int paramIdx = 0; paramIdx < updatedParams.StaticSwitchParameters.Num(); paramIdx++)
			{
				if (updatedParams.StaticSwitchParameters[paramIdx].ParameterInfo.Name == FName("$SelfIllum"))
				{
					updatedParams.StaticSwitchParameters[paramIdx].Value = importerVMTList[i]->isSelfIllum;
					updatedParams.StaticSwitchParameters[paramIdx].bOverride = true;
					break;
				}
			}
#if ENGINE_MINOR_VERSION>11
			newVMTMaterial->UpdateStaticPermutation(updatedParams);
#else
			newVMTMaterial->UpdateStaticPermutation(updatedParams, true);
#endif
		}
	}

	if (sourceMaterial->GetStaticSwitchParameterValue(FName("WorldVertexTransition"), testBool, testGUID))
	{
		FStaticParameterSet updatedParams;
		newVMTMaterial->GetStaticParameterValues(updatedParams);
		for (int paramIdx = 0; paramIdx < updatedParams.StaticSwitchParameters.Num(); paramIdx++)
		{
			if (updatedParams.StaticSwitchParameters[paramIdx].ParameterInfo.Name == FName("WorldVertexTransition"))
			{
				updatedParams.StaticSwitchParameters[paramIdx].Value = switchBlend;
				updatedParams.StaticSwitchParameters[paramIdx].bOverride = true;
				break;
			}
		}
#if ENGINE_MINOR_VERSION>11
		newVMTMaterial->UpdateStaticPermutation(updatedParams);
#else
		newVMTMaterial->UpdateStaticPermutation(updatedParams, true);
#endif
	}
	else
		UE_LOG(LogTemp, Warning, TEXT("Could not find a switch 'WorldVertexTransition' in the source material."));

	FAssetRegistryModule::AssetCreated(newVMTMaterial);
	newVMTMaterial->PostEditChange();
	NMIDPackage->PostEditChange();
#if ENGINE_MINOR_VERSION>=11
	if (HammUErSettings::generateThumbs)
		ThumbnailTools::GenerateThumbnailForObjectToSaveToDisk(newVMTMaterial);
#endif

	GEditor->SavePackage(NMIDPackage, newVMTMaterial, RF_Public | RF_Standalone, *NMIDPackageFileName, GError, nullptr, false, true, SAVE_None);
	newVMTMaterial->PostEditImport();
	NMIDPackage->PostEditImport();
	// Extra check
	int oldIndex = HammUErSettings::FindInMaster(originalName.ToUpper());
	if (oldIndex > -1)
	{
		if (HammUErSettings::masterMaterialList[oldIndex]->newMaterial == NULL || HammUErSettings::masterMaterialList[oldIndex]->newMaterialName == "")
		{
			if (HammUErSettings::verboseDebugEnabled)
				UE_LOG(LogTemp, Warning, TEXT("Found an old empty %s, removing"), *originalName);
			HammUErSettings::masterMaterialList.RemoveAt(oldIndex);
		}
	}

	if (!HammUErSettings::masterMaterialList.ContainsByPredicate([&](TSharedPtr<FMaterialListEntry> checkingAsset) {return checkingAsset->oldName.ToUpper() == originalName.ToUpper(); }))
	{
		FAssetRegistryModule::AssetCreated(newVMTMaterial);
		TSharedPtr<FMaterialListEntry> newEntry;
		newEntry = MakeShareable(new FMaterialListEntry());

		newEntry->textureHeight = textureHeightFound;
		newEntry->textureWidth = textureWidthFound;

		newEntry->oldName = originalName.ToUpper();
		newEntry->newMaterialName = newVMTMaterial->GetPathName();
		newEntry->newMaterial = NULL;//newVMTMaterial;
		newEntry->ignore = false;
		if (HammUErSettings::verboseDebugEnabled)
			UE_LOG(LogTemp, Log, TEXT("Writing %s to master material list"), *originalName);
		if (originalName.Contains("nodraw") || (TextureName.ToLower() == "clip") || (TextureName.ToLower() == "origin") || TextureName.Contains("toolsorigin") || TextureName.Contains("toolsclip"))
			newEntry->ignore = true;
		HammUErSettings::masterMaterialList.AddUnique(newEntry);

	}
	else
	{
		if (HammUErSettings::verboseDebugEnabled)
			UE_LOG(LogTemp, Log, TEXT("Already found %s in master material list"), *originalName);
	}
	unloadtest.Insert(NMIDPackage,0);
	if (HammUErSettings::doUnload)
		PackageTools::UnloadPackages(unloadtest);
	unloadtest.Empty();
}

void SHammerTextUErWidget::CreateMaterials()
{
	UE_LOG(LogTemp, Log, TEXT("Starting material creation..."));
	
	failedMats.Empty();
	HammUErSettings::LoadDecalSettings();

	int textureWidthFound = HammUErSettings::defaultWidth;
	int textureHeightFound = HammUErSettings::defaultHeight;
	UE_LOG(LogTemp, Log, TEXT("Materials to import: %i"), importerVMTList.Num());
	if (importerVMTList.Num() > 0)
	{
		int totalScopedTask = importerVMTList.Num();
		FScopedSlowTask SlowTask(totalScopedTask, FText::FromString("Creating materials for all imported material files..."));
		SlowTask.MakeDialog();

		FString textureToUse = "";
		for (int i = 0; i < importerVMTList.Num(); i++)
		{
			SlowTask.EnterProgressFrame(1);
			CreateMaterial(i);
		}
	}
	HammUErSettings::SaveConfig();
	HammUErSettings::SaveDecalSettings();


	int totalScopedTask = importerTextureList.Num();
	if (importerVMTList.Num()>0 && importerTextureList.Num()>0)
	if (FMessageDialog::Open(EAppMsgType::YesNo, FText::FromString("Do you want to try creating materials for imported textures that might not have been used?\r\nWarning, there is a possibility of false positives.\r\n")) == EAppReturnType::No)
		return;
	FScopedSlowTask SlowTask(totalScopedTask, FText::FromString("Creating materials for all imported textures not used in materials..."));
	SlowTask.MakeDialog();
	TArray<FString> importedTextureNames;
	importerVMTList.Empty();
	importerTextureList.GenerateKeyArray(importedTextureNames);
	for (int i = 0; i < importedTextureNames.Num(); i++)
	{
		SlowTask.EnterProgressFrame(1);
		FString originalName = importedTextureNames[i];
		bool isNormal = false;
		for (int j = 0; j < HammUErSettings::importerNormalExtensions.Num(); j++)
		{
			if (originalName.EndsWith(HammUErSettings::importerNormalExtensions[j]))
			{
				isNormal = true;
				continue;
			}
		}
		if (!isNormal)
			for (int j = 0; j < HammUErSettings::importerIgnoreExtensions.Num(); j++)
			{
				if (originalName.EndsWith(HammUErSettings::importerIgnoreExtensions[j]))
				{
					isNormal = true;
					continue;
				}
			}

		if (isNormal)  // skip normal texturesi
			continue;

		if (ImporterMaterialsDoneContains(originalName))
			continue;
		else
		{
			FString TextureName = originalName;
			if (TextureName.Contains("/"))
				TextureName = TextureName.Mid(TextureName.Find("/", ESearchCase::IgnoreCase, ESearchDir::FromEnd) + 1);

	//		auto MaterialFactory = NewObject<UMaterialFactoryNew>();

			FString MaterialName = originalName + "_mat";

			FString NMIDPackageName = TEXT("/Game/") + (HammUErSettings::textureImportDirectory == "" ? "Materials/" : HammUErSettings::textureImportDirectory + "/Materials/") + MaterialName;
			FString NMIDPackageFileName = FPackageName::LongPackageNameToFilename(NMIDPackageName, FPackageName::GetAssetPackageExtension());
			UPackage* NMIDPackage = CreatePackage(NULL, *NMIDPackageName);
			NMIDPackage->FullyLoad();
			NMIDPackage->Modify();

			if (MaterialName.Contains("/"))
				MaterialName = MaterialName.Mid(MaterialName.Find("/", ESearchCase::IgnoreCase, ESearchDir::FromEnd) + 1);

			UMaterialInstanceConstantFactoryNew* Factory = NewObject<UMaterialInstanceConstantFactoryNew>();
			Factory->InitialParent = sourceMaterial;

			UMaterialInstanceConstant* newMaterial = (UMaterialInstanceConstant*)Factory->FactoryCreateNew(UMaterialInstanceConstant::StaticClass(), NMIDPackage, *MaterialName, RF_Standalone | RF_Public, NULL, GWarn);
			FString textureToUse;
			UTexture2D* texToUse;
			if (ImporterTextureListContains(originalName, textureToUse))
			{
				texToUse = GetTextureFromAssetDatabase(textureToUse);
				if (texToUse != NULL)
				{
					newMaterial->SetTextureParameterValueEditorOnly(*currentParameter, texToUse);
					if (HammUErSettings::useTextureAlpha)
					{
						newMaterial->BasePropertyOverrides.bOverride_BlendMode = true;
						newMaterial->BasePropertyOverrides.BlendMode = BLEND_Opaque;
					}
					else
					if (texToUse->HasAlphaChannel())
					{
						newMaterial->BasePropertyOverrides.bOverride_BlendMode = true;
						newMaterial->BasePropertyOverrides.BlendMode = BLEND_Masked;
					}
					unloadtest.AddUnique(texToUse->GetOutermost());
				}
				else
				{
					UE_LOG(LogTemp, Warning, TEXT("Something went wrong trying to get %s"), *textureToUse);
					failedMats.AddUnique(MaterialName);
				}
			}

			if (matContainsNormal)
			{
				FString toFind = "";
				bool found = false;
				for (int j = 0; j < HammUErSettings::importerNormalExtensions.Num(); j++)
				{
					toFind = (originalName + HammUErSettings::importerNormalExtensions[j]).ToUpper();
					found = ImporterTextureListContains(toFind, textureToUse);
					if (found)
						continue;
				}
				if (found)
				{
					texToUse = GetTextureFromAssetDatabase(textureToUse);
					if (texToUse != NULL)
					{
						newMaterial->SetTextureParameterValueEditorOnly(*currentNormalParameter, texToUse);
						unloadtest.AddUnique(texToUse->GetOutermost());
					}
					else
					{
						UE_LOG(LogTemp, Warning, TEXT("Something went wrong trying to get %s"), *textureToUse);
						failedMats.AddUnique(MaterialName);
					}
				}
				else
					if (HammUErSettings::verboseDebugEnabled) UE_LOG(LogTemp, Log, TEXT("No normal texture for material"));
			}


	//		newMaterial->ThumbnailInfo = NewObject<USceneThumbnailInfoWithPrimitive>(newMaterial);
			FAssetRegistryModule::AssetCreated(newMaterial);
			newMaterial->PostEditChange();
#if ENGINE_MINOR_VERSION>=11
			if (HammUErSettings::generateThumbs)
				ThumbnailTools::GenerateThumbnailForObjectToSaveToDisk(newMaterial);
#endif
			GEditor->SavePackage(NMIDPackage, newMaterial, RF_Public | RF_Standalone, *NMIDPackageFileName, GError, nullptr, false, true, SAVE_None);
		
			// Extra check
			int oldIndex = HammUErSettings::FindInMaster(originalName.ToUpper());
			if (oldIndex > -1)
			{
				if (HammUErSettings::masterMaterialList[oldIndex]->newMaterial == NULL)
				{
					if (HammUErSettings::verboseDebugEnabled)
						UE_LOG(LogTemp, Warning, TEXT("Found an old empty %s, removing"), *originalName);
					HammUErSettings::masterMaterialList.RemoveAt(oldIndex);
				}
			}

			if (!HammUErSettings::masterMaterialList.ContainsByPredicate([&](TSharedPtr<FMaterialListEntry> checkingAsset) {return checkingAsset->oldName.ToUpper() == originalName.ToUpper(); }))
			{
				TSharedPtr<FMaterialListEntry> newEntry;
				newEntry = MakeShareable(new FMaterialListEntry());
				newEntry->textureHeight = importerTextureList[originalName].height;
				newEntry->textureWidth = importerTextureList[originalName].width;
				newEntry->oldName = originalName.ToUpper();
				newEntry->newMaterialName = newMaterial->GetPathName();
				newEntry->newMaterial = NULL;//newMaterial;
				newMaterial = NULL; // FIXME
				newEntry->ignore = false;
				if (HammUErSettings::verboseDebugEnabled)
					UE_LOG(LogTemp, Log, TEXT("Writing %s to master material list"), *originalName);
				if (originalName.Contains("nodraw") || (TextureName.ToLower() == "clip") || (TextureName.ToLower() == "origin") || TextureName.Contains("toolsorigin") || TextureName.Contains("toolsclip"))
					newEntry->ignore = true;
				HammUErSettings::masterMaterialList.AddUnique(newEntry);

				unloadtest.AddUnique(NMIDPackage);
			}
			else
			{
				if (HammUErSettings::verboseDebugEnabled)
					UE_LOG(LogTemp, Log, TEXT("Already found %s in master material list"), *originalName);
			}
		}
		if (HammUErSettings::doUnload)
			PackageTools::UnloadPackages(unloadtest);
		unloadtest.Empty();
	}

	if (failedMats.Num() > 0)
	{
		UE_LOG(LogTemp, Error, TEXT("-------------------- FAILED MATERIALS --------------------"));
		for (int i = 0; i < failedMats.Num(); i++)
			UE_LOG(LogTemp, Error, TEXT("%i: %s"), i, *failedMats[i]);
	}

	importerTextureList.Empty();
	importerTextureNames.Empty();
}

void SHammerTextUErWidget::ImportVTF(FString fileName)
{
	TArray<uint8> sourceArray;

	FFileHelper::LoadFileToArray(sourceArray, *fileName);

	if (sourceArray.Num() < 50)
	{
		UE_LOG(LogTemp, Error, TEXT("VTF file %s is empty?"), *fileName);
		return;
	}

	if (!(sourceArray[0] == 0x56 && sourceArray[1] == 0x54 && sourceArray[2] == 0x46 && sourceArray[3] == 0))
	{
		UE_LOG(LogTemp, Error, TEXT("%s is not a VTF file? Aborting."), *fileName);
		return;
	}

	uint8 headerSize = sourceArray[12];
	uint8 version = sourceArray[8];

	int32 width = sourceArray[17] * 256 + sourceArray[16];
	int32 height = sourceArray[19] * 256 + sourceArray[18];

	uint8 nummips = sourceArray[56];

	bool compressed = false;
	bool is24bit = false;
	int32 compressionType = sourceArray[52];

	int32 BlockSizeX = 1;
	int32 BlockSizeY = 1;
	int32 BlockBytes = 1;
	int32 BlockSize = 0;
	int32 toRead;

	BlockSizeX = 0;
	BlockSizeY = 0;

	EPixelFormat Format = EPixelFormat::PF_Unknown;

	switch (compressionType)
	{
	case (int)VTFImageFormat::IMAGE_FORMAT_A8:
		compressed = false;
		is24bit = false;
		BlockSize = 1;
		BlockSizeX = 1;
		BlockSizeY = 1;
		BlockBytes = 1;
		toRead = width*height;
		break;
	case (int)VTFImageFormat::IMAGE_FORMAT_ARGB8888:
		compressed = false;
		is24bit = false;
		BlockSizeX = 1;
		BlockSizeY = 1;
		BlockBytes = 4;
		toRead = width * height * 4;
		break;
	case (int)VTFImageFormat::IMAGE_FORMAT_ABGR8888:
		compressed = false;
		is24bit = false;
		BlockSizeX = 1;
		BlockSizeY = 1;
		BlockBytes = 4;
		toRead = width * height * 4;
		break;
	case (int)VTFImageFormat::IMAGE_FORMAT_BGRA8888:
		compressed = false;
		is24bit = false;
		BlockSizeX = 1;
		BlockSizeY = 1;
		BlockBytes = 4;
		toRead = width * height * 4;
		break;
	case (int)VTFImageFormat::IMAGE_FORMAT_RGBA8888:
		compressed = false;
		is24bit = false;
		BlockSizeX = 1;
		BlockSizeY = 1;
		BlockBytes = 4;
		toRead = width * height * 4;
		break;

	case (int)VTFImageFormat::IMAGE_FORMAT_RGB888:
		compressed = false;
		is24bit = true;
		toRead = width * height * 3;
		BlockSizeX = 1;
		BlockSizeY = 1;
		break;

	case (int)VTFImageFormat::IMAGE_FORMAT_BGR888:
		compressed = false;
		is24bit = true;
		toRead = width * height * 3;
		BlockSizeX = 1;
		BlockSizeY = 1;
		break;

	case (int)VTFImageFormat::IMAGE_FORMAT_DXT1:
		compressed = true;
		is24bit = true;
		Format = PF_DXT1;
		BlockSizeX = 4;
		BlockSizeY = 4;
		BlockBytes = 8;
		BlockSize = 8;
		toRead = ((width + 3) / 4) * ((height + 3) / 4) * 8;
		break;
	case (int)VTFImageFormat::IMAGE_FORMAT_DXT1_ONEBITALPHA:
		compressed = true;
		is24bit = false;
		Format = PF_DXT1;
		BlockSizeX = 4;
		BlockSizeY = 4;
		BlockBytes = 8;
		BlockSize = 8;
		toRead = ((width + 3) / 4) * ((height + 3) / 4) * 8;
		break;
	case (int)VTFImageFormat::IMAGE_FORMAT_DXT3:
		compressed = true;
		is24bit = false;
		Format = PF_DXT3;
		BlockSizeX = 4;
		BlockSizeY = 4;
		BlockSize = 8;
		BlockBytes = 16;
		toRead = ((width + 3) / 4) * ((height + 3) / 4) * 16;
		break;
	case (int)VTFImageFormat::IMAGE_FORMAT_DXT5:
		compressed = true;
		is24bit = false;
		Format = PF_DXT5;
		BlockSizeX = 4;
		BlockSizeY = 4;
		BlockBytes = 16;
		BlockSize = 16;
		toRead = ((width + 3) / 4) * ((height + 3) / 4) * 16;
		break;
	default:
		UE_LOG(LogTemp, Error, TEXT("! Unsupported texture type in %s"), *fileName);
		return;
		break;
	}

	int32 startOffset = sourceArray.Num() - toRead;

	FString ObjectName = fileName;
	ObjectName.RemoveFromStart(HammUErSettings::textureSourceDirectory);//FPaths::GetBaseFilename(fileName);
	if (ObjectName.StartsWith("/"))
		ObjectName.RemoveFromStart("/");
	ObjectName.RemoveFromEnd(".vtf");
	while (ObjectName.EndsWith("."))
		ObjectName.RemoveFromEnd(".");

	int32 numBlocksX = width / BlockSizeX;
	int32 numBlocksY = height / BlockSizeY;

	try 
	{
	TArray<FColor> colorArray;
	for (int y = 0; y < height; y++)
		for (int x = 0; x < width; x++)
			colorArray.Add(FColor::White);

	uint8* DataPtr = (uint8*)(sourceArray.GetData() + startOffset);

	uint8 r = 255;
	uint8 g = 255;
	uint8 b = 255;
	uint8 a = 255;

	if (compressed)
	{

		if (Format == PF_DXT1)
			DecompressDXT1Image(width, height, DataPtr, colorArray);
		else
		{
			// DXT1/3/5 decompress
			for (int32 y = 0; y < numBlocksY; y++) {
				for (int32 x = 0; x < numBlocksX; x++)
				{
					switch (Format)
					{
					case PF_DXT3:
						DecompressBlockDXT3(x * 4, y * 4, width, DataPtr + x * 8, colorArray);
					case PF_DXT5:
						DecompressBlockDXT5(x * 4, y * 4, width, DataPtr + x * 16, colorArray);
						break;
					}
				}
				DataPtr += numBlocksX * BlockSize;
			}
		}
	}
	else
	{
		for (int y = 0; y < height; y++)
			for (int x = 0; x < width; x++)
			{
				if (is24bit)
				{
					switch (compressionType)
					{
						case (int)VTFImageFormat::IMAGE_FORMAT_BGR888:
							b = *DataPtr;
							DataPtr++;
							g = *DataPtr;
							DataPtr++;
							r = *DataPtr;
							DataPtr++;
							a = 255;
							break;
						case (int)VTFImageFormat::IMAGE_FORMAT_RGB888:
							r = *DataPtr;
							DataPtr++;
							g = *DataPtr;
							DataPtr++;
							b = *DataPtr;
							DataPtr++;
							a = 255;
							break;
					}
				}
				else
				{
					switch (compressionType)
					{
					case (int)VTFImageFormat::IMAGE_FORMAT_A8:
						r = 255;
						g = 255;
						b = 255;
						a = *DataPtr;
						DataPtr++;
						break;
					case (int)VTFImageFormat::IMAGE_FORMAT_ARGB8888:
						a = *DataPtr;
						DataPtr++;
						r = *DataPtr;
						DataPtr++;
						g = *DataPtr;
						DataPtr++;
						b = *DataPtr;
						DataPtr++;
						break;
					case (int)VTFImageFormat::IMAGE_FORMAT_ABGR8888:
						a = *DataPtr;
						DataPtr++;
						b = *DataPtr;
						DataPtr++;
						g = *DataPtr;
						DataPtr++;
						r = *DataPtr;
						DataPtr++;
						break;
					case (int)VTFImageFormat::IMAGE_FORMAT_BGRA8888:
						b = *DataPtr;
						DataPtr++;
						g = *DataPtr;
						DataPtr++;
						r = *DataPtr;
						DataPtr++;
						a = *DataPtr;
						DataPtr++;
						break;
					case (int)VTFImageFormat::IMAGE_FORMAT_RGBA8888:
						r = *DataPtr;
						DataPtr++;
						g = *DataPtr;
						DataPtr++;
						b = *DataPtr;
						DataPtr++;
						a = *DataPtr;
						DataPtr++;
						break;
					}
				}
				colorArray[x + y*width] = FColor(r, g, b, a);
			}
	}

	if (ObjectName.EndsWith("ssbump"))
	{
		if (is24bit)
			UE_LOG(LogTemp, Warning, TEXT("Could not extract heightmap data from self-shadowed bumpmap %s"), *ObjectName)
		else
		{
			// extract the heightmap data, hopefully
			TArray<uint8> heightmapData;
			for (int i = 0; i < width*height; i++)
				heightmapData.Add(colorArray[i].A);
			for (int y = 0; y < height; y++)
				for (int x = 0; x < width; x++)
				{
					int topY = y - 1;
					int leftX = x - 1;
					int bottomY = y + 1;
					int rightX = x + 1;
					if (y == height - 1)
						bottomY = 0;
					if (y == 0)
						topY = height - 1;
					if (x == 0)
						leftX = width - 1;
					if (x == width - 1)
						rightX = 0;

					float topLeft = heightmapData[topY*width + leftX] / 255.f;
					float top = heightmapData[topY*width + x] / 255.f;
					float topRight = heightmapData[topY*width + rightX] / 255.f;
					float left = heightmapData[y*width + leftX] / 255.f;
					float right = heightmapData[y*width + rightX] / 255.f;
					float bottomLeft = heightmapData[bottomY*width + leftX] / 255.f;
					float bottom = heightmapData[bottomY*width + x] / 255.f;
					float bottomRight = heightmapData[bottomY*width + rightX] / 255.f;

					float newX = (topRight + 2.0f *right + bottomRight) - (topLeft + 2.0f * left + bottomLeft);
					float newY = (bottomLeft + 2.0f * bottom + bottomRight) - (topLeft + 2.0f * top + topRight);
					float newZ = 1.f / 2.f; // strength?

					FVector v = FVector(newX, newY, newZ);
					v.Normalize();
					colorArray[x + y*width] = FColor((v.X + 1.f)*(255.f / 2.f), (v.Y + 1.f)*(255.f / 2.f), (v.Z + 1.f)*(255.f / 2.f), 255);
				}
		}
	}


	CreateTexture/*AndMaterial*/(width, height, colorArray, ObjectName, (Format == PF_DXT5 || !is24bit));
	colorArray.Empty();
	sourceArray.Empty();
	 }
	 catch (...)
	 {
		 UE_LOG(LogTemp, Error, TEXT("Something went catastrophically wrong trying to read %s"),*ObjectName);
	 }
}

void SHammerTextUErWidget::ImportTGA(FString fileName)
{
	TArray<uint8> sourceArray;

	FFileHelper::LoadFileToArray(sourceArray, *fileName);

	int colorMapType = sourceArray[1];
	if (colorMapType > 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("Unsupported TARGA file format %s, only support uncompressed non-paletted images"), *fileName);
		return; // what 
	}
	int compressionType = sourceArray[2];
	if ((compressionType != 2) && (compressionType != 3))
	{
		UE_LOG(LogTemp, Warning, TEXT("Unsupported TARGA file format %s, only support uncompressed non-paletted images"), *fileName);
		return; // no seriously, what?
	}

	int colorMapStart = sourceArray[4] * 256 + sourceArray[3];
	int colorMapEntries = sourceArray[6] * 256 + sourceArray[5];
	int colorMapBPP = sourceArray[7];

	int xOrigin = sourceArray[9] * 256 + sourceArray[8];
	int yOrigin = sourceArray[11] * 256 + sourceArray[10];

	int width = sourceArray[13] * 256 + sourceArray[12];
	int height = sourceArray[15] * 256 + sourceArray[14];

	int bpp = sourceArray[16];
	if ((bpp != 24) && (bpp != 32))
	{
		UE_LOG(LogTemp, Warning, TEXT("Unsupported TARGA file format %s, only support 24 and 32 bit images"), *fileName);
		return; // no seriously, what?
	}

	if (colorMapType == 1)
		bpp = colorMapBPP;

	int imageDescriptor = sourceArray[17];
	bool flip = (imageDescriptor & 0x20) ? true : false;

	TArray<FColor> colorArray;
	for (int x = 0; x < width; x++)
		for (int y = 0; y < height; y++)
			colorArray.Add(FColor::Black);

	int currentPoint = sourceArray[0] + 18;
	int offset = 0;
	for (int y = 0; y < height; y++)
		for (int x = 0; x < width; x++)
		{
			offset = x + (flip?y : height - 1 - y)*width;
		//	offset = x + ((yOrigin != 0) ? y : height - 1 - y)*width;
			colorArray[offset] = FColor(sourceArray[currentPoint + 2], sourceArray[currentPoint + 1], sourceArray[currentPoint], (bpp == 32) ? sourceArray[currentPoint + 3] : 255); // BGRA
			currentPoint += bpp / 8;
		}

	if (yOrigin != 0)
	{

	}

	FString ObjectName = fileName;
	ObjectName.RemoveFromStart(HammUErSettings::textureSourceDirectory);
	ObjectName.RemoveFromEnd(FPaths::GetExtension(ObjectName, true));
	if (ObjectName.StartsWith("/"))
		ObjectName.RemoveFromStart("/");
	while (ObjectName.EndsWith("."))
		ObjectName.RemoveFromEnd(".");

	CreateTexture/*AndMaterial*/(width, height, colorArray, ObjectName, true);
	sourceArray.Empty();
	colorArray.Empty();
}

void SHammerTextUErWidget::ImportOther(FString fileName)
{
	IImageWrapperModule& imageWrapperModule = FModuleManager::LoadModuleChecked<IImageWrapperModule>(FName("ImageWrapper"));
	TSharedPtr<IImageWrapper> imageWrapperToUse;
	bool flipBGRA = false;
	if (fileName.EndsWith(".bmp", ESearchCase::IgnoreCase))
	{
		imageWrapperToUse = imageWrapperModule.CreateImageWrapper(EImageFormat::BMP);
		flipBGRA = true;  // somehow, these end up passing BGRA even though I'm asking for RGBA?
	}
	else
		if (fileName.EndsWith(".png", ESearchCase::IgnoreCase))
			imageWrapperToUse = imageWrapperModule.CreateImageWrapper(EImageFormat::PNG);
		else
			if (fileName.EndsWith(".jpg", ESearchCase::IgnoreCase))
			{
				imageWrapperToUse = imageWrapperModule.CreateImageWrapper(EImageFormat::JPEG);
				flipBGRA = true; // somehow, these end up passing BGRA even though I'm asking for RGBA?
			}
			else
				return; // unsupported

	TArray<uint8> sourceArray;

	if (FFileHelper::LoadFileToArray(sourceArray, *fileName))
	{
		if (imageWrapperToUse.IsValid() && imageWrapperToUse->SetCompressed(sourceArray.GetData(), sourceArray.Num()))
		{
			const TArray<uint8>* uncompressedRGBA;
			if (imageWrapperToUse->GetRaw(ERGBFormat::RGBA, 8, uncompressedRGBA))
			{
				FString ObjectName = fileName;
				ObjectName.RemoveFromStart(HammUErSettings::textureSourceDirectory);//FPaths::GetBaseFilename(fileName);
				ObjectName.RemoveFromEnd(FPaths::GetExtension(ObjectName, true));
				if (ObjectName.StartsWith("/"))
					ObjectName.RemoveFromStart("/");
				while (ObjectName.EndsWith("."))
					ObjectName.RemoveFromEnd(".");


				TArray<FColor> colorArray;
				int width = imageWrapperToUse->GetWidth();
				int height = imageWrapperToUse->GetHeight();
				TArray<uint8>* workArray = const_cast<TArray<uint8>*>(uncompressedRGBA);
				uint8* DataPtr = (uint8*)workArray->GetData();
				for (int y = 0; y < height; y++)
					for (int x = 0; x < width; x++)
					{
						colorArray.Add(flipBGRA?FColor(*(DataPtr+2), *(DataPtr + 1), *(DataPtr), *(DataPtr + 3)):FColor(*DataPtr, *(DataPtr + 1), *(DataPtr + 2), *(DataPtr + 3)));
						DataPtr += 4;
					}

				CreateTexture/*AndMaterial*/(width, height, colorArray, ObjectName, true);
				colorArray.Empty();
				workArray->Empty();
			}
		}
	}
}

struct WADDir
{
public:
	int32_t filePos;
	int32_t fileSize;
	int32_t uncompressedSize;
	int8_t nType;
	bool bCompressed;
	FString szName;
};

FColor Quake1Palette[256] =
{
FColor(0, 0, 0, 255), FColor(15, 15, 15, 255), FColor(31, 31, 31, 255), FColor(47, 47, 47, 255), FColor(63, 63, 63, 255), FColor(75, 75, 75, 255), FColor(91, 91, 91, 255), FColor(107, 107, 107, 255), FColor(123, 123, 123, 255), FColor(139, 139, 139, 255), FColor(155, 155, 155, 255), FColor(171, 171, 171, 255), FColor(187, 187, 187, 255), FColor(203, 203, 203, 255), FColor(219, 219, 219, 255), FColor(235, 235, 235, 255),
FColor(15, 11, 7, 255), FColor(23, 15, 11, 255), FColor(31, 23, 11, 255), FColor(39, 27, 15, 255), FColor(47, 35, 19, 255), FColor(55, 43, 23, 255), FColor(63, 47, 23, 255), FColor(75, 55, 27, 255), FColor(83, 59, 27, 255), FColor(91, 67, 31, 255), FColor(99, 75, 31, 255), FColor(107, 83, 31, 255), FColor(115, 87, 31, 255), FColor(123, 95, 35, 255), FColor(131, 103, 35, 255), FColor(143, 111, 35, 255),
FColor(11, 11, 15, 255), FColor(19, 19, 27, 255), FColor(27, 27, 39, 255), FColor(39, 39, 51, 255), FColor(47, 47, 63, 255), FColor(55, 55, 75, 255), FColor(63, 63, 87, 255), FColor(71, 71, 103, 255), FColor(79, 79, 115, 255), FColor(91, 91, 127, 255), FColor(99, 99, 139, 255), FColor(107, 107, 151, 255), FColor(115, 115, 163, 255), FColor(123, 123, 175, 255), FColor(131, 131, 187, 255), FColor(139, 139, 203, 255),
FColor(0, 0, 0, 255), FColor(7, 7, 0, 255), FColor(11, 11, 0, 255), FColor(19, 19, 0, 255), FColor(27, 27, 0, 255), FColor(35, 35, 0, 255), FColor(43, 43, 7, 255), FColor(47, 47, 7, 255), FColor(55, 55, 7, 255), FColor(63, 63, 7, 255), FColor(71, 71, 7, 255), FColor(75, 75, 11, 255), FColor(83, 83, 11, 255), FColor(91, 91, 11, 255), FColor(99, 99, 11, 255), FColor(107, 107, 15, 255),
FColor(7, 0, 0, 255), FColor(15, 0, 0, 255), FColor(23, 0, 0, 255), FColor(31, 0, 0, 255), FColor(39, 0, 0, 255), FColor(47, 0, 0, 255), FColor(55, 0, 0, 255), FColor(63, 0, 0, 255), FColor(71, 0, 0, 255), FColor(79, 0, 0, 255), FColor(87, 0, 0, 255), FColor(95, 0, 0, 255), FColor(103, 0, 0, 255), FColor(111, 0, 0, 255), FColor(119, 0, 0, 255), FColor(127, 0, 0, 255),
FColor(19, 19, 0, 255), FColor(27, 27, 0, 255), FColor(35, 35, 0, 255), FColor(47, 43, 0, 255), FColor(55, 47, 0, 255), FColor(67, 55, 0, 255), FColor(75, 59, 7, 255), FColor(87, 67, 7, 255), FColor(95, 71, 7, 255), FColor(107, 75, 11, 255), FColor(119, 83, 15, 255), FColor(131, 87, 19, 255), FColor(139, 91, 19, 255), FColor(151, 95, 27, 255), FColor(163, 99, 31, 255), FColor(175, 103, 35, 255),
FColor(35, 19, 7, 255), FColor(47, 23, 11, 255), FColor(59, 31, 15, 255), FColor(75, 35, 19, 255), FColor(87, 43, 23, 255), FColor(99, 47, 31, 255), FColor(115, 55, 35, 255), FColor(127, 59, 43, 255), FColor(143, 67, 51, 255), FColor(159, 79, 51, 255), FColor(175, 99, 47, 255), FColor(191, 119, 47, 255), FColor(207, 143, 43, 255), FColor(223, 171, 39, 255), FColor(239, 203, 31, 255), FColor(255, 243, 27, 255),
FColor(11, 7, 0, 255), FColor(27, 19, 0, 255), FColor(43, 35, 15, 255), FColor(55, 43, 19, 255), FColor(71, 51, 27, 255), FColor(83, 55, 35, 255), FColor(99, 63, 43, 255), FColor(111, 71, 51, 255), FColor(127, 83, 63, 255), FColor(139, 95, 71, 255), FColor(155, 107, 83, 255), FColor(167, 123, 95, 255), FColor(183, 135, 107, 255), FColor(195, 147, 123, 255), FColor(211, 163, 139, 255), FColor(227, 179, 151, 255),
FColor(171, 139, 163, 255), FColor(159, 127, 151, 255), FColor(147, 115, 135, 255), FColor(139, 103, 123, 255), FColor(127, 91, 111, 255), FColor(119, 83, 99, 255), FColor(107, 75, 87, 255), FColor(95, 63, 75, 255), FColor(87, 55, 67, 255), FColor(75, 47, 55, 255), FColor(67, 39, 47, 255), FColor(55, 31, 35, 255), FColor(43, 23, 27, 255), FColor(35, 19, 19, 255), FColor(23, 11, 11, 255), FColor(15, 7, 7, 255),
FColor(187, 115, 159, 255), FColor(175, 107, 143, 255), FColor(163, 95, 131, 255), FColor(151, 87, 119, 255), FColor(139, 79, 107, 255), FColor(127, 75, 95, 255), FColor(115, 67, 83, 255), FColor(107, 59, 75, 255), FColor(95, 51, 63, 255), FColor(83, 43, 55, 255), FColor(71, 35, 43, 255), FColor(59, 31, 35, 255), FColor(47, 23, 27, 255), FColor(35, 19, 19, 255), FColor(23, 11, 11, 255), FColor(15, 7, 7, 255),
FColor(219, 195, 187, 255), FColor(203, 179, 167, 255), FColor(191, 163, 155, 255), FColor(175, 151, 139, 255), FColor(163, 135, 123, 255), FColor(151, 123, 111, 255), FColor(135, 111, 95, 255), FColor(123, 99, 83, 255), FColor(107, 87, 71, 255), FColor(95, 75, 59, 255), FColor(83, 63, 51, 255), FColor(67, 51, 39, 255), FColor(55, 43, 31, 255), FColor(39, 31, 23, 255), FColor(27, 19, 15, 255), FColor(15, 11, 7, 255),
FColor(111, 131, 123, 255), FColor(103, 123, 111, 255), FColor(95, 115, 103, 255), FColor(87, 107, 95, 255), FColor(79, 99, 87, 255), FColor(71, 91, 79, 255), FColor(63, 83, 71, 255), FColor(55, 75, 63, 255), FColor(47, 67, 55, 255), FColor(43, 59, 47, 255), FColor(35, 51, 39, 255), FColor(31, 43, 31, 255), FColor(23, 35, 23, 255), FColor(15, 27, 19, 255), FColor(11, 19, 11, 255), FColor(7, 11, 7, 255),
FColor(255, 243, 27, 255), FColor(239, 223, 23, 255), FColor(219, 203, 19, 255), FColor(203, 183, 15, 255), FColor(187, 167, 15, 255), FColor(171, 151, 11, 255), FColor(155, 131, 7, 255), FColor(139, 115, 7, 255), FColor(123, 99, 7, 255), FColor(107, 83, 0, 255), FColor(91, 71, 0, 255), FColor(75, 55, 0, 255), FColor(59, 43, 0, 255), FColor(43, 31, 0, 255), FColor(27, 15, 0, 255), FColor(11, 7, 0, 255),
FColor(0, 0, 255, 255), FColor(11, 11, 239, 255), FColor(19, 19, 223, 255), FColor(27, 27, 207, 255), FColor(35, 35, 191, 255), FColor(43, 43, 175, 255), FColor(47, 47, 159, 255), FColor(47, 47, 143, 255), FColor(47, 47, 127, 255), FColor(47, 47, 111, 255), FColor(47, 47, 95, 255), FColor(43, 43, 79, 255), FColor(35, 35, 63, 255), FColor(27, 27, 47, 255), FColor(19, 19, 31, 255), FColor(11, 11, 15, 255),
FColor(43, 0, 0, 255), FColor(59, 0, 0, 255), FColor(75, 7, 0, 255), FColor(95, 7, 0, 255), FColor(111, 15, 0, 255), FColor(127, 23, 7, 255), FColor(147, 31, 7, 255), FColor(163, 39, 11, 255), FColor(183, 51, 15, 255), FColor(195, 75, 27, 255), FColor(207, 99, 43, 255), FColor(219, 127, 59, 255), FColor(227, 151, 79, 255), FColor(231, 171, 95, 255), FColor(239, 191, 119, 255), FColor(247, 211, 139, 255),
FColor(167, 123, 59, 255), FColor(183, 155, 55, 255), FColor(199, 195, 55, 255), FColor(231, 227, 87, 255), FColor(127, 191, 255, 255), FColor(171, 231, 255, 255), FColor(215, 255, 255, 255), FColor(103, 0, 0, 255), FColor(139, 0, 0, 255), FColor(179, 0, 0, 255), FColor(215, 0, 0, 255), FColor(255, 0, 0, 255), FColor(255, 243, 147, 255), FColor(255, 247, 199, 255), FColor(255, 255, 255, 255), FColor(159, 91, 83, 255)
};


FColor Quake2Palette[256] =
{
	FColor(0, 0, 0, 255), FColor(31, 31, 31, 255), FColor(63, 63, 63, 255), FColor(91, 91, 91, 255), FColor(123, 123, 123, 255), FColor(155, 155, 155, 255), FColor(187, 187, 187, 255), FColor(219, 219, 219, 255), FColor(255, 255, 255, 255),
	FColor(255, 255, 255, 255), FColor(255, 255, 255, 255), FColor(255, 255, 255, 255), FColor(255, 255, 255, 255), FColor(255, 255, 255, 255), FColor(255, 255, 255, 255), FColor(255, 255, 255, 255), FColor(207, 151, 75, 255),
	FColor(167, 123, 59, 255), FColor(167, 123, 59, 255), FColor(167, 123, 59, 255), FColor(139, 103, 47, 255), FColor(139, 103, 47, 255), FColor(111, 83, 39, 255), FColor(99, 75, 35, 255), FColor(99, 75, 35, 255),
	FColor(83, 63, 31, 255), FColor(79, 59, 27, 255), FColor(67, 43, 23, 255), FColor(51, 39, 19, 255), FColor(43, 31, 19, 255), FColor(39, 27, 15, 255), FColor(31, 23, 15, 255), FColor(179, 199, 211, 255),
	FColor(179, 199, 211, 255), FColor(187, 187, 187, 255), FColor(171, 171, 171, 255), FColor(155, 155, 155, 255), FColor(155, 155, 155, 255), FColor(139, 139, 139, 255), FColor(123, 123, 123, 255), FColor(107, 107, 107, 255),
	FColor(91, 91, 91, 255), FColor(91, 91, 91, 255), FColor(75, 75, 75, 255), FColor(71, 63, 67, 255), FColor(59, 55, 55, 255), FColor(47, 47, 47, 255), FColor(39, 39, 39, 255), FColor(255, 255, 167, 255),
	FColor(235, 151, 127, 255), FColor(235, 151, 127, 255), FColor(207, 151, 75, 255), FColor(255, 255, 167, 255), FColor(255, 255, 127, 255), FColor(255, 255, 83, 255), FColor(207, 151, 75, 255), FColor(255, 255, 83, 255),
	FColor(255, 255, 83, 255), FColor(255, 255, 83, 255), FColor(255, 215, 23, 255), FColor(235, 159, 39, 255), FColor(175, 119, 31, 255), FColor(119, 79, 23, 255), FColor(67, 43, 23, 255), FColor(235, 151, 127, 255),
	FColor(255, 147, 0, 255), FColor(239, 127, 0, 255), FColor(227, 107, 0, 255), FColor(211, 87, 0, 255), FColor(199, 71, 0, 255), FColor(199, 71, 0, 255), FColor(171, 43, 0, 255), FColor(155, 31, 0, 255),
	FColor(143, 23, 0, 255), FColor(115, 23, 11, 255), FColor(103, 23, 7, 255), FColor(87, 19, 0, 255), FColor(67, 15, 0, 255), FColor(51, 11, 0, 255), FColor(35, 11, 0, 255), FColor(215, 187, 183, 255),
	FColor(235, 151, 127, 255), FColor(235, 151, 127, 255), FColor(203, 155, 147, 255), FColor(191, 123, 111, 255), FColor(167, 139, 119, 255), FColor(143, 119, 83, 255), FColor(143, 119, 83, 255), FColor(135, 107, 87, 255),
	FColor(123, 95, 75, 255), FColor(103, 79, 59, 255), FColor(95, 71, 55, 255), FColor(75, 55, 43, 255), FColor(63, 47, 35, 255), FColor(43, 31, 19, 255), FColor(31, 23, 15, 255), FColor(203, 139, 35, 255),
	FColor(175, 119, 31, 255), FColor(159, 87, 51, 255), FColor(139, 103, 47, 255), FColor(99, 75, 35, 255), FColor(79, 59, 27, 255), FColor(51, 39, 19, 255), FColor(31, 23, 15, 255), FColor(255, 255, 167, 255),
	FColor(255, 255, 211, 255), FColor(255, 255, 255, 255), FColor(255, 255, 255, 255), FColor(255, 255, 255, 255), FColor(255, 255, 255, 255), FColor(255, 255, 255, 255), FColor(255, 255, 255, 255), FColor(255, 255, 255, 255),
	FColor(255, 255, 255, 255), FColor(203, 215, 223, 255), FColor(159, 183, 195, 255), FColor(119, 123, 207, 255), FColor(91, 135, 155, 255), FColor(71, 119, 139, 255), FColor(47, 103, 127, 255), FColor(47, 103, 127, 255),
	FColor(23, 83, 111, 255), FColor(19, 75, 103, 255), FColor(11, 63, 83, 255), FColor(7, 47, 63, 255), FColor(0, 31, 43, 255), FColor(0, 15, 19, 255), FColor(0, 0, 0, 255), FColor(235, 211, 199, 255),
	FColor(235, 151, 127, 255), FColor(235, 151, 127, 255), FColor(235, 151, 127, 255), FColor(191, 123, 111, 255), FColor(195, 115, 83, 255), FColor(179, 91, 79, 255), FColor(179, 91, 79, 255), FColor(159, 75, 63, 255),
	FColor(123, 71, 71, 255), FColor(99, 51, 51, 255), FColor(87, 43, 43, 255), FColor(63, 31, 31, 255), FColor(39, 27, 19, 255), FColor(23, 15, 11, 255), FColor(0, 0, 0, 255), FColor(255, 255, 255, 255),
	FColor(255, 255, 211, 255), FColor(255, 255, 211, 255), FColor(255, 255, 211, 255), FColor(255, 255, 211, 255), FColor(235, 211, 199, 255), FColor(215, 187, 183, 255), FColor(199, 171, 155, 255), FColor(199, 171, 155, 255),
	FColor(151, 159, 123, 255), FColor(135, 139, 107, 255), FColor(115, 115, 87, 255), FColor(91, 91, 67, 255), FColor(67, 67, 51, 255), FColor(47, 47, 35, 255), FColor(27, 27, 23, 255), FColor(235, 151, 127, 255),
	FColor(235, 151, 127, 255), FColor(235, 151, 127, 255), FColor(195, 115, 83, 255), FColor(195, 115, 83, 255), FColor(179, 91, 79, 255), FColor(167, 59, 43, 255), FColor(167, 59, 43, 255), FColor(159, 47, 35, 255),
	FColor(139, 39, 19, 255), FColor(107, 43, 27, 255), FColor(87, 31, 19, 255), FColor(67, 23, 11, 255), FColor(43, 11, 0, 255), FColor(27, 0, 0, 255), FColor(0, 0, 0, 255), FColor(255, 255, 255, 255),
	FColor(255, 255, 255, 255), FColor(255, 255, 255, 255), FColor(235, 235, 235, 255), FColor(203, 215, 223, 255), FColor(179, 199, 211, 255), FColor(159, 183, 195, 255), FColor(119, 123, 207, 255), FColor(119, 123, 207, 255),
	FColor(103, 107, 183, 255), FColor(91, 91, 155, 255), FColor(75, 79, 127, 255), FColor(63, 63, 103, 255), FColor(47, 47, 75, 255), FColor(35, 31, 47, 255), FColor(23, 15, 11, 255), FColor(255, 255, 255, 255),
	FColor(255, 255, 211, 255), FColor(255, 255, 211, 255), FColor(255, 255, 167, 255), FColor(255, 255, 167, 255), FColor(255, 255, 127, 255), FColor(155, 171, 123, 255), FColor(155, 171, 123, 255), FColor(135, 151, 99, 255),
	FColor(95, 167, 47, 255), FColor(95, 143, 51, 255), FColor(95, 123, 51, 255), FColor(63, 79, 27, 255), FColor(47, 59, 11, 255), FColor(35, 47, 7, 255), FColor(27, 35, 0, 255), FColor(0, 255, 0, 255),
	FColor(0, 255, 0, 255), FColor(255, 255, 39, 255), FColor(255, 255, 83, 255), FColor(255, 255, 83, 255), FColor(255, 255, 83, 255), FColor(255, 255, 83, 255), FColor(255, 255, 255, 255), FColor(255, 255, 255, 255),
	FColor(255, 255, 255, 255), FColor(255, 255, 255, 255), FColor(255, 255, 167, 255), FColor(255, 255, 83, 255), FColor(255, 255, 83, 255), FColor(255, 255, 39, 255), FColor(255, 255, 39, 255), FColor(255, 255, 39, 255),
	FColor(255, 255, 39, 255), FColor(255, 235, 31, 255), FColor(255, 215, 23, 255), FColor(255, 171, 7, 255), FColor(255, 147, 0, 255), FColor(255, 147, 0, 255), FColor(255, 147, 0, 255), FColor(255, 0, 0, 255),
	FColor(255, 0, 0, 255), FColor(255, 0, 0, 255), FColor(239, 0, 0, 255), FColor(155, 31, 0, 255), FColor(127, 15, 0, 255), FColor(95, 0, 0, 255), FColor(47, 0, 0, 255), FColor(255, 0, 0, 255),
	FColor(55, 55, 255, 255), FColor(255, 0, 0, 255), FColor(0, 0, 255, 255), FColor(91, 91, 67, 255), FColor(55, 55, 43, 255), FColor(35, 35, 27, 255), FColor(255, 255, 255, 255), FColor(255, 255, 167, 255),
	FColor(235, 151, 127, 255), FColor(235, 159, 39, 255), FColor(255, 255, 255, 255), FColor(255, 255, 255, 255), FColor(255, 255, 255, 255), FColor(235, 211, 199, 255), FColor(159, 91, 83, 255)
};

void SHammerTextUErWidget::ImportWAL(FString fileName)
{
	TArray<uint8> sourceArray;
	FFileHelper::LoadFileToArray(sourceArray, *fileName);
	FString ObjectName = fileName;
	ObjectName.RemoveFromStart(HammUErSettings::textureSourceDirectory);//FPaths::GetBaseFilename(fileName);
	ObjectName.RemoveFromEnd(FPaths::GetExtension(ObjectName, true));
	if (ObjectName.StartsWith("/"))
		ObjectName.RemoveFromStart("/");
	while (ObjectName.EndsWith("."))
		ObjectName.RemoveFromEnd(".");

	uint8* DataPtr = (uint8*)sourceArray.GetData();
	uint32_t width = *(uint32_t*)(DataPtr + 32);
	uint32_t height = *(uint32_t*)(DataPtr + 36);
	uint32_t offset = *(uint32_t*)(DataPtr + 40);
	DataPtr = DataPtr + offset;

	TArray<FColor> colorData;
	for (int y = 0; y < (int)height; y++)
		for (int x = 0; x < (int)width; x++)
		{
			uint8 paletteIndex = *(uint8*)(DataPtr + (x + y*width));
			colorData.Add(Quake2Palette[paletteIndex]);
		}
	CreateTexture/*AndMaterial*/(width, height, colorData, ObjectName, false);
	sourceArray.Empty();
}

void SHammerTextUErWidget::ImportWAD(FString fileName)
{
	TArray<uint8> sourceArray;
	FFileHelper::LoadFileToArray(sourceArray, *fileName);
	FString WADname = FPaths::GetBaseFilename(fileName) + "/";

	uint8* DataPtr = (uint8*)sourceArray.GetData();

	int32_t header = *(int32_t*)DataPtr;
	if (header != 0x32444157 && header != 0x33444157)  // support WAD3 too, why not
	{
		UE_LOG(LogTemp, Error, TEXT("%s is not a valid Quake WAD file"), *fileName);
		return;
	}
	bool isWAD3 = false;
	if (header == 0x33444157)
		isWAD3 = true;

	int32_t numEntries = *(int32_t*)(DataPtr + 4);
	int32_t dirOffset = *(int32_t*)(DataPtr + 8);

	TArray<WADDir> directory;
	DataPtr = DataPtr + dirOffset;

	FScopedSlowTask SlowTask(numEntries, FText::FromString("Importing WAD file..."));
	SlowTask.MakeDialog();
	int paletteIndex = -1;
	for (int i = 0; i < numEntries; i++)
	{
		WADDir newItem;
		newItem.filePos = *(int32_t*)DataPtr;
		newItem.fileSize = *(int32_t*)(DataPtr + 4);
		newItem.uncompressedSize = *(int32_t*)(DataPtr + 8);
		newItem.nType = *(int8_t*)(DataPtr + 12);
		if (newItem.nType == 0x40)
			paletteIndex = i;		// we need this
		newItem.bCompressed = (*(int8_t*)(DataPtr + 13) == 1);
		// don't forget to skip the dummy start from 16
		newItem.szName = "";
		for (int j = 0; j < 16; j++)
		{
			char testChar = (*(char*)(DataPtr + 16 + j));
			if (testChar != 0x0)
				newItem.szName += testChar;
			else
				break;
		}
		directory.Add(newItem);
		DataPtr = DataPtr + 32; // next one
	}
	// first, build the palette... if it exists
	TArray<FColor> palette;
	if (paletteIndex > -1)
	{
		DataPtr = (uint8*)sourceArray.GetData(); // go back to the beginning
		DataPtr = DataPtr + directory[paletteIndex].filePos;
		for (int i = 0; i < 256; i++)
		{
			palette.Add(FColor(*(uint8*)(DataPtr + 0), *(uint8*)(DataPtr + 1), *(uint8*)(DataPtr + 2), 255));
			DataPtr = DataPtr + 3;
		}
	}
	if ((paletteIndex == -1) && (!isWAD3))
	{
		for (int i = 0; i < 256; i++)
			palette.Add(Quake1Palette[i]);
	}

	DataPtr = (uint8*)sourceArray.GetData(); // go back to the beginning
	uint8* SubData = DataPtr;

	TArray<FColor> subpalette;
	if (palette.Num() > 0)
		subpalette = palette;
	else
		for (int i = 0; i < 256; i++)
			subpalette.Add(FColor::Black);

	for (int i = 0; i < numEntries; i++)
	{
		SlowTask.EnterProgressFrame(1);
		if (directory[i].nType == 0x44) // it's a Quake texture
		{
			if (directory[i].bCompressed)
			{
				UE_LOG(LogTemp, Error, TEXT("%s is compressed"), *directory[i].szName);
				continue;
			}

			SubData = DataPtr + directory[i].filePos + 16; // skip the repeat of the texture name
			uint32_t width = *(uint32_t*)SubData;
			uint32_t height = *(uint32_t*)(SubData + 4);
			uint32_t mip0 = *(uint32_t*)(SubData + 8) - 16;
			TArray<FColor> colorData;
			SubData = SubData + mip0;
			for (int y = 0; y < (int)height; y++)
				for (int x = 0; x < (int)width; x++)
				{
					uint8 inPaletteIndex = *(uint8*)(SubData + (x + y*width));
					colorData.Add(subpalette[inPaletteIndex]);
				}
			CreateTexture/*AndMaterial*/(width, height, colorData, WADname + directory[i].szName, false);

		}
		if (directory[i].nType == 0x43) // it's a HL1 texture?
		{
			if (directory[i].bCompressed)
			{
				UE_LOG(LogTemp, Error, TEXT("%s is compressed"), *directory[i].szName);
				continue;
			}
			SubData = DataPtr + directory[i].filePos + 16; // skip the repeat of the texture name
			uint32_t width = *(uint32_t*)SubData;
			uint32_t height = *(uint32_t*)(SubData + 4);
			uint32_t mip0 = *(uint32_t*)(SubData + 8);
			uint32_t mip1 = *(uint32_t*)(SubData + 12);
			uint32_t mip2 = *(uint32_t*)(SubData + 16);
			uint32_t mip3 = *(uint32_t*)(SubData + 20);

			// first load the subpalette
			//SubData = DataPtr + directory[i].filePos + directory[i].fileSize - 768;
			SubData = DataPtr + directory[i].filePos + mip3 + (width*height) / 64;
			uint16_t paletteSize = *(uint16_t*)SubData;
			SubData = SubData + 2;
			bool hasAlpha = false;
			for (int pal = 0; pal < paletteSize; pal++)
			{
				subpalette[pal] = (FColor(*(uint8*)(SubData), *(uint8*)(SubData + 1), *(uint8*)(SubData + 2), 255));
				if (subpalette[pal] == HammUErSettings::halfLifeAlphaColor)
				{
					subpalette[pal] = FColor(0, 0, 0, 0);
					hasAlpha = true;
				}
				SubData = SubData + 3;
			}
			if (paletteSize < 256)
				for (int pal = paletteSize; pal < 256; pal++)
					subpalette[pal] = FColor::Black;
			// then get the texture data
			TArray<FColor> colorData;
			SubData = DataPtr + directory[i].filePos + mip0;
			for (int y = 0; y < (int)height; y++)
				for (int x = 0; x < (int)width; x++)
				{
					uint8 inPaletteIndex = *(uint8*)(SubData + (x + y*width));
					colorData.Add(subpalette[inPaletteIndex]);
				}
			CreateTexture/*AndMaterial*/(width, height, colorData, WADname + directory[i].szName, hasAlpha);

		}
		// let's ignore the rest
	}
	sourceArray.Empty();
}

FString RemoveComments(FString input)
{
	int offset = input.Find("//");
	if (offset>-1)
	{
		input.RemoveAt(offset, input.Len() - offset);
	}
	return input;
}

void SHammerTextUErWidget::ImportSHADER(FString fileName)
{
	TArray<FString> MTRLines;
	TArray<FString> parseArray;
	int lineCounter = 0;
	int depth = 0;
	TCHAR* delimiter = new TCHAR;
	*delimiter = 0x9;  // tabs
	TCHAR spaceDelimiter = 0x20;

	if (FFileHelper::LoadANSITextFileToStrings(*fileName, NULL, MTRLines))
	{
		if (MTRLines.Num() > 1)
		{
			for (int i = 0; i < MTRLines.Num(); i++)
			{
				parseArray.Add(RemoveComments(MTRLines[i]));
			}

			MTRLines.Empty();
			for (int i = 0; i < parseArray.Num(); i++)
			{
				if (parseArray[i] != "" && parseArray[i] != "\t" && parseArray[i] != "\t\t")
				{
					if (parseArray[i].Contains("/*"))
					{
						if (!parseArray[i].Contains("*/"))
						{
							while (!parseArray[i].Contains("*/"))
								i++;
						}
					}
					else
						MTRLines.Add(parseArray[i]);
				}
			}
			while (lineCounter < MTRLines.Num())
			{
				if (MTRLines[lineCounter].Contains("table"))
				{
					// skip
				}
				else
					if ((lineCounter > 0) && MTRLines[lineCounter].Contains("{"))
					{
						VMTInfo* newInfo = new VMTInfo();
						newInfo->shader = VMTShaderType::LightmappedGeneric;
						FString workString = "";
						if (MTRLines[lineCounter].Contains("material"))
						{
							MTRLines[lineCounter].ParseIntoArray(parseArray, TEXT(" "));
							workString = parseArray[1];
						}
						else
						{
							workString = MTRLines[--lineCounter];
							lineCounter++;
							if (workString == "")
							{
								if (MTRLines[lineCounter][0] != 0x7B) // not {
									workString = MTRLines[lineCounter].Mid(0, MTRLines[lineCounter].Find(" "));
								else
								{
									workString = MTRLines[lineCounter - 2];
									if ((workString != "") && !workString.Contains("}"))
									{

									}
									else
									{
										workString = "brokenUnknownMaterialFrom" + fileName;
										workString = workString.Replace(TEXT(".mtr"), TEXT(""));
									}
								}
							}
							else
								if (workString.Contains("//"))
									workString = MTRLines[lineCounter - 2];
						}
						newInfo->VMTName = workString.Replace(TEXT(".tga"), TEXT("")).TrimStart().TrimEnd();
						lineCounter++;
						depth = 0;
						while (lineCounter<MTRLines.Num() && !(workString.Contains("}") && depth<0))
						{
							workString = MTRLines[lineCounter];
							if (workString.Contains("/*") && (!workString.Contains("//*")) && (!workString.Contains("*/")))
							{
								while (!workString.Contains("*/"))
									workString = MTRLines[lineCounter++];
								lineCounter--;
							}
							if (workString.Contains("//"))
							{

							}
							else
								if (workString.Contains("{"))
									depth++;
								else
									if (workString.Contains("}"))
									{
										depth--;
										if (workString == "}")
											depth = -1;
									}
									else
									{
										workString = workString.TrimStart();
										workString.ParseIntoArray(parseArray, TEXT(" "), true);
										if (parseArray.Num() == 2)
										{
											parseArray[1] = parseArray[1].Replace(TEXT(".tga"), TEXT(""));
											parseArray[0] = parseArray[0].Replace(TEXT(" "), TEXT(""));
											if (parseArray[0] == "map")
											{
												if (!parseArray[1].Contains("$lightmap"))
												{
													if (newInfo->baseTexture == "")
														newInfo->baseTexture = parseArray[1];
													else
														newInfo->baseTexture2 = parseArray[1];
												}
											}
											else
											if (parseArray[0] == "bumpmap")
											{
												if (parseArray[1].Contains("("))
												{
													workString = parseArray[1].Mid(parseArray[1].Find("(") + 1, parseArray[1].Find(",") - parseArray[1].Find("(") - 1);
													FString second = "";
													for (int i = 0; i < workString.Len(); i++)
													{
														if (workString[i] != spaceDelimiter)
															second += workString[i];
													}
													newInfo->normalTexture = second;
												}
												else
													newInfo->normalTexture = parseArray[1];
											}
											else
												if (parseArray[0] == "diffusemap")
												{
													if (newInfo->baseTexture == "")
														newInfo->baseTexture = parseArray[1];
													else
														newInfo->baseTexture2 = parseArray[1];
												}
												else
													if (parseArray[0] == "specularmap")
													{
														newInfo->specularTexture = parseArray[1];
													}
													else
														if (parseArray[0] == "blend")
														{
															FString oldone = parseArray[1];
															workString = "";
															newInfo->isTranslucent = 1;
															lineCounter++;
															while (!(workString.Contains("map") || workString.Contains("}")))
															{
																workString = MTRLines[lineCounter++];
																workString = workString.Replace(TEXT("\t"), TEXT(" "));
																if (workString.Contains("}"))
																	lineCounter--;
																workString.ParseIntoArray(parseArray, TEXT(" "));
																if (parseArray.Num() == 2)
																{
																	if (parseArray[0] == "map")
																	{
																		if (oldone == "specularmap")
																			newInfo->specularTexture = parseArray[1].Replace(TEXT(".tga"), TEXT(""));
																		if (oldone == "diffusemap")
																		{
																			if (newInfo->baseTexture == "")
																				newInfo->baseTexture = parseArray[1].Replace(TEXT(".tga"), TEXT(""));
																			else
																				newInfo->baseTexture2 = parseArray[1].Replace(TEXT(".tga"), TEXT(""));
																		}if (oldone == "bumpmap")
																			newInfo->normalTexture = parseArray[1].Replace(TEXT(".tga"), TEXT(""));
																	}
																}
															}
														}
														else
															if (parseArray[0] == "map")
															{
																if (parseArray[1].Contains("makealpha"))
																{
																	workString = parseArray[1].Mid(parseArray[1].Find(TEXT("(")) + 1, parseArray[1].Find(TEXT(")")) - (parseArray[1].Find(TEXT("(")) + 1));
																	newInfo->baseTexture = workString.Replace(TEXT(".tga"), TEXT(""));
																	newInfo->isTranslucent = true;
																}
															}
										}
										else
										{
											workString = workString.Replace(TEXT("\t"), TEXT(""));
											workString = workString.Replace(TEXT(" "), TEXT(""));
											workString = workString.ToLower();
											if (workString == "translucent")
												newInfo->isTranslucent = true;
											else
												if (workString == "blenddiffusemap" || workString == "blendblend" || (workString.Contains("blend") && workString.Contains("gl_")))
												{
													workString = "";
													lineCounter++;
													while (!(workString.Contains("map") || workString.Contains("}")))
													{
														workString = MTRLines[lineCounter++];
														workString = workString.Replace(TEXT("\t"), TEXT(" "));
														if (workString.Contains("}"))
															lineCounter--;
														workString.ParseIntoArray(parseArray, TEXT(" "));
														if (parseArray.Num() == 2)
															if (parseArray[0] == "map")
															{
																if (newInfo->baseTexture == "")
																	newInfo->baseTexture = parseArray[1].Replace(TEXT(".tga"), TEXT(""));
																else
																	newInfo->baseTexture2 = parseArray[1].Replace(TEXT(".tga"), TEXT(""));
															}
													}
												}
												else
													if (workString == "blendspecularmap")
													{
														workString = "";
														lineCounter++;
														while (!(workString.Contains("map") || workString.Contains("}")))
														{
															workString = MTRLines[lineCounter++];
															workString = workString.Replace(TEXT("\t"), TEXT(" "));
															if (workString.Contains("}"))
																lineCounter--;
															workString.ParseIntoArray(parseArray, TEXT(" "));
															if (parseArray.Num() == 2)
																if (parseArray[0] == "map")
																	newInfo->specularTexture = parseArray[1].Replace(TEXT(".tga"), TEXT(""));
														}
													}
													else
														if (workString == "blendbumpmap")
														{
															workString = "";
															lineCounter++;
															while (!(workString.Contains("map") || workString.Contains("}")))
															{
																workString = MTRLines[lineCounter++];
																workString = workString.Replace(TEXT("\t"), TEXT(" "));
																if (workString.Contains("}"))
																	lineCounter--;
																workString.ParseIntoArray(parseArray, TEXT(" "));
																if (parseArray.Num() == 2)
																	if (parseArray[0] == "map")
																		newInfo->normalTexture = parseArray[1].Replace(TEXT(".tga"), TEXT(""));
															}
														}
										}
									}
							lineCounter++;
						}
						importerVMTList.Add(newInfo);
					}
				lineCounter++;
			}
		}
		else
			UE_LOG(LogTemp, Error, TEXT("%s is empty?"), *fileName);
	}
	delete delimiter;
}

// This is kinda broken and shit. Need to rewrite to a full lexer, but eh...
void SHammerTextUErWidget::ImportMTR(FString fileName)
{
	TArray<FString> MTRLines;
	TArray<FString> parseArray;
	int lineCounter = 0;
	int depth = 0;
	TCHAR* delimiter = new TCHAR;
	*delimiter = 0x9;  // tabs
	TCHAR spaceDelimiter = 0x20;

	if (FFileHelper::LoadANSITextFileToStrings(*fileName, NULL, MTRLines))
	{
		if (MTRLines.Num() > 1)
		{
			for (int i = 0; i < MTRLines.Num(); i++)
			{
				parseArray.Add(RemoveComments(MTRLines[i]));
			}

			MTRLines.Empty();
			for (int i = 0; i < parseArray.Num(); i++)
			{
				parseArray[i] = parseArray[i].Replace(TEXT("\t"), TEXT(" "));
				parseArray[i] = parseArray[i].TrimStart();
				if (parseArray[i] != "")
				{
					if (parseArray[i].Contains("/*"))
					{
						if (!parseArray[i].Contains("*/"))
						{
							while (!parseArray[i].Contains("*/"))
								i++;
						}
					}
					else
						MTRLines.Add(parseArray[i]);
				}
			}

			while (lineCounter < MTRLines.Num())
			{
				if (MTRLines[lineCounter].Contains("table"))
				{
					// skip
				}
				else
				if ((lineCounter > 0) && MTRLines[lineCounter].Contains("{"))
				{
					depth++;
					VMTInfo* newInfo = new VMTInfo();
					newInfo->shader = VMTShaderType::LightmappedGeneric;
					FString workString= "";
					if (MTRLines[lineCounter].Contains("material"))
					{
						MTRLines[lineCounter].ParseIntoArray(parseArray, TEXT(" "));
						workString = parseArray[1];
					}
					else
					{
						if (MTRLines[lineCounter].Find("{") == 0)
						{
							workString = MTRLines[--lineCounter];
							lineCounter++;
						}
						else
						{
							workString = MTRLines[lineCounter].Mid(0, MTRLines[lineCounter].Find(" "));
						}
						/*
						
						if (workString == "")
						{
							if (MTRLines[lineCounter][0]!=0x7B) // not {
								workString = MTRLines[lineCounter].Mid(0, MTRLines[lineCounter].Find(" "));
							else
							{
								workString = MTRLines[lineCounter - 2];
								if ((workString != "") && !workString.Contains("}"))
								{

								}
								else
								{
									workString = "brokenUnknownMaterialFrom" + fileName;
									workString = workString.Replace(TEXT(".mtr"), TEXT(""));
								}
							}
						}
						else
							if (workString.Contains("//"))
								workString = MTRLines[lineCounter - 2];
								*/
					}
				
					newInfo->VMTName = workString.Replace(TEXT(".tga"), TEXT(""));
					lineCounter++;
					depth = 1;
					while (lineCounter<MTRLines.Num() && !(workString.Contains("}")&&depth==0))
					{
						workString = MTRLines[lineCounter];
						if (workString.Contains("/*") && (!workString.Contains("//*")) && (!workString.Contains("*/")))
						{
							while (!workString.Contains("*/"))
								workString = MTRLines[lineCounter++];
							lineCounter--;
						}
						if (workString.Contains("//"))
						{

						}
						else
						if (workString.Contains("{"))
							depth++;
						else
							if (workString.Contains("}"))
								depth--;
						else
						{
							workString.ParseIntoArray(parseArray, TEXT(" "), true);
							if (parseArray.Num() == 2)
							{
								parseArray[1] = parseArray[1].Replace(TEXT(".tga"), TEXT(""));
								parseArray[0] = parseArray[0].Replace(TEXT(" "), TEXT(""));
								if (parseArray[0] == "bumpmap")
								{
									if (parseArray[1].Contains("("))
									{
										workString = parseArray[1].Mid(parseArray[1].Find("(") + 1, parseArray[1].Find(",") - parseArray[1].Find("(")-1);
										FString second = "";
										for (int i = 0; i < workString.Len(); i++)
										{
											if (workString[i]!=spaceDelimiter)
												second += workString[i];
										}
										newInfo->normalTexture = second;
									}
									else
										newInfo->normalTexture = parseArray[1];
								}
								else
									if (parseArray[0] == "diffusemap")
									{
										if (newInfo->baseTexture=="")
											newInfo->baseTexture = parseArray[1];
										else
											newInfo->baseTexture2 = parseArray[1];
									}
									else
										if (parseArray[0] == "specularmap")
										{
											newInfo->specularTexture = parseArray[1];
										}
										else
											if (parseArray[0] == "blend")
											{
												FString oldone = parseArray[1];
												workString = "";
												if (parseArray[1] == "blend")
													newInfo->isTranslucent = 1;
												lineCounter++;
												while (!(workString.Contains("map") || workString.Contains("}")))
												{
													workString = MTRLines[lineCounter++];
													workString = workString.Replace(TEXT("\t"), TEXT(" "));
													if (workString.Contains("}"))
														lineCounter--;
													workString.ParseIntoArray(parseArray, TEXT(" "));
													if (parseArray.Num() == 2)
													{
														if (parseArray[0] == "map")
														{
															if (oldone == "specularmap")
																newInfo->specularTexture = parseArray[1].Replace(TEXT(".tga"), TEXT(""));
															else
															if (oldone == "bumpmap")
																newInfo->normalTexture = parseArray[1].Replace(TEXT(".tga"), TEXT(""));
															else
																{
																	if (newInfo->baseTexture == "")
																		newInfo->baseTexture = parseArray[1].Replace(TEXT(".tga"), TEXT(""));
																	else
																		newInfo->baseTexture2 = parseArray[1].Replace(TEXT(".tga"), TEXT(""));
																}
															lineCounter--;
														}
													}
												}
											}
											else
												if (parseArray[0] == "map")
												{
													if (parseArray[1].Contains("makealpha"))
													{
														workString = parseArray[1].Mid(parseArray[1].Find(TEXT("(")) + 1, parseArray[1].Find(TEXT(")")) - (parseArray[1].Find(TEXT("(")) + 1));
														newInfo->baseTexture = workString.Replace(TEXT(".tga"), TEXT(""));
														newInfo->isTranslucent = true;
													}
												}
							}
							else
							{
								workString = workString.Replace(TEXT("\t"), TEXT(""));
								workString = workString.Replace(TEXT(" "), TEXT(""));
								workString = workString.ToLower();
								if (workString == "translucent")
									newInfo->isTranslucent = true;
								else
									if (workString == "blenddiffusemap" || workString == "blendblend" || (workString.Contains("blend") && workString.Contains("gl_")))
									{
										workString = "";
										lineCounter++;
										while (!(workString.Contains("map") || workString.Contains("}")))
										{
											workString = MTRLines[lineCounter++];
											workString = workString.Replace(TEXT("\t"), TEXT(" "));
											if (workString.Contains("}"))
												lineCounter--;
											workString.ParseIntoArray(parseArray, TEXT(" "));
											if (parseArray.Num() == 2)
												if (parseArray[0] == "map")
												{
													if (newInfo->baseTexture == "")
														newInfo->baseTexture = parseArray[1].Replace(TEXT(".tga"), TEXT(""));
													else
														newInfo->baseTexture2 = parseArray[1].Replace(TEXT(".tga"), TEXT(""));
													lineCounter--;
												}
										}
									}
									else
										if (workString == "blendspecularmap")
										{
											workString = "";
											lineCounter++;
											while (!(workString.Contains("map") || workString.Contains("}")))
											{
												workString = MTRLines[lineCounter++];
												workString = workString.Replace(TEXT("\t"), TEXT(" "));
												if (workString.Contains("}"))
													lineCounter--;
												workString.ParseIntoArray(parseArray, TEXT(" "));
												if (parseArray.Num() == 2)
													if (parseArray[0] == "map")
														newInfo->specularTexture = parseArray[1].Replace(TEXT(".tga"), TEXT(""));
											}
										}
										else
											if (workString == "blendbumpmap")
											{
												workString = "";
												lineCounter++;
												while (!(workString.Contains("map") || workString.Contains("}")))
												{
													workString = MTRLines[lineCounter++];
													workString = workString.Replace(TEXT("\t"), TEXT(" "));
													if (workString.Contains("}"))
														lineCounter--;
													workString.ParseIntoArray(parseArray, TEXT(" "));
													if (parseArray.Num() == 2)
														if (parseArray[0] == "map")
															newInfo->normalTexture = parseArray[1].Replace(TEXT(".tga"), TEXT(""));
												}
											}
							}
						}
						lineCounter++;
					}
					importerVMTList.Add(newInfo);
					lineCounter--;
				}
				lineCounter++;
			}
		}
		else
			UE_LOG(LogTemp, Error, TEXT("%s is empty?"), *fileName);
	}
	delete delimiter;
}

void SHammerTextUErWidget::ImportVMT(FString fileName)
{
	TArray<FString> VMTLines;
	int lineCounter = 0;
	if (FFileHelper::LoadANSITextFileToStrings(*(fileName), NULL, VMTLines))
	{
		if (VMTLines.Num() > 1)
		{
			try
			{
				VMTInfo* newInfo = new VMTInfo();
				FString workString = VMTLines[lineCounter++];
				while (workString == "" || workString[0] == '/') // FIX HERE
				{
					if (lineCounter<VMTLines.Num())
						workString = VMTLines[lineCounter++];  // empty line fix
					else
					{
						UE_LOG(LogTemp, Error, TEXT("Ran out of file reading %s"), *fileName);
						return;
					}
				}
				int first = workString.Find("\"") + 1;
				int second = workString.Find("\"", ESearchCase::IgnoreCase, ESearchDir::FromEnd);
				bool skipCheck = workString.Contains("{");
				if (second >-1)
					workString = workString.Mid(first, second - first).ToUpper();

				if ((workString == "LIGHTMAPPEDGENERIC") || (workString == "PATCH") || (workString == "SPLINEROPE") || (workString == "DECALMODULATE"))
					newInfo->shader = VMTShaderType::LightmappedGeneric;
				else
					if (workString == "VERTEXLITGENERIC")
						newInfo->shader = VMTShaderType::VertexLitGeneric;
					else
						if (workString == "UNLITGENERIC")
							newInfo->shader = VMTShaderType::UnlitGeneric;
						else
							if (workString == "WORLDVERTEXTRANSITION")
								newInfo->shader = VMTShaderType::WorldVertexTransition;
							else
								newInfo->shader = VMTShaderType::Undefined;

				if (newInfo->shader == VMTShaderType::Undefined)
				{
					UE_LOG(LogTemp, Warning, TEXT("Unrecognised shader type %s in VMT %s"), *workString, *fileName);
					return;
				}
				else
					UE_LOG(LogTemp, Log, TEXT("VMT type %s"), *workString);
				workString = "";

				if (!skipCheck)
				while (((workString.Len() == 0) || (!workString.Contains("{"))) && lineCounter < VMTLines.Num()) // FIX HERE
					workString = VMTLines[lineCounter++];  // empty line fix
				if (lineCounter == VMTLines.Num())
				{
					UE_LOG(LogTemp, Warning, TEXT("Error reading VMT %s"), *fileName);
					return;
				}

				FString ObjectName = fileName;
				ObjectName.RemoveFromStart(HammUErSettings::textureSourceDirectory);//FPaths::GetBaseFilename(fileName);
				if (ObjectName.StartsWith("/"))
					ObjectName.RemoveFromStart("/");
				ObjectName.RemoveFromEnd(".vmt");
				while (ObjectName.EndsWith("."))
					ObjectName.RemoveFromEnd(".");
				newInfo->VMTName = ObjectName;

				bool foundBaseTexture = false;
				bool foundNormalTexture = false;

				TArray<FString> gotData;
				while ((lineCounter < VMTLines.Num()))
				{
					workString = VMTLines[lineCounter++];
					workString = workString.Replace(TEXT("\""), TEXT(" "));
					workString = workString.Replace(TEXT("\\"), TEXT("/"));
					workString = workString.Replace(TEXT("\t"), TEXT(" "));
					workString = workString.TrimStart().TrimEnd();
					if (workString == "")
						continue;

					if (workString[0] == '/')
						continue;

					if (workString.Contains("$"))
					{
						int position = workString.Find(TEXT(" "), ESearchCase::IgnoreCase, ESearchDir::FromStart, 1);
						FString parameter = "";
						if (position > -1)
						{
							parameter = workString.Mid(0, position);
							workString.RemoveAt(0, position);
							workString.TrimStartInline();
						}
						parameter = parameter.ToLower();
						if (workString == "")
							continue;
						position = workString.Find(TEXT(" "), ESearchCase::IgnoreCase, ESearchDir::FromStart, 1);
						FString value;
						if (position > 0)
							value = workString.Mid(0, position);
						else
							value = workString;
						value = value.Replace(TEXT(".vtf"), TEXT(""));
						/*		workString.RemoveAt(0, position);
								workString.TrimStart();*/

						if (parameter == "$basetexture")
						{
							if (!foundBaseTexture)
							{
								newInfo->baseTexture = value;
								foundBaseTexture = true;
							}
						}
						else
							if (parameter == "$basetexture2")
								newInfo->baseTexture2 = value;
							else
								if (parameter == "$bumpmap")
								{
									if (!foundNormalTexture)
									{
										newInfo->normalTexture = value;
										foundNormalTexture = true;
									}
								}
								else
									if (parameter == "$bumpmap2")
										newInfo->normalTexture2 = value;
									else
										if (parameter == "$surfaceprop")
											newInfo->surfaceType = value;
										else
											if (parameter == "$envmapmask")
												newInfo->specularTexture = value;
											else
												if (parameter == "$alphatest")
													newInfo->isMasked = (value == "1");
												else
													if (parameter == "$translucent")
														newInfo->isTranslucent = (value == "1");
													else
														if (parameter == "$envmap")
															newInfo->hasEnvMap = (value != "");
														else
															if (parameter == "$selfillum")
																newInfo->isSelfIllum = (value == "1");
															else
																if (parameter == "$seamless_scale")
																	newInfo->seamlessScale = FCString::Atof(*value);
																else
																	if (parameter == "$decal")
																		newInfo->isDecal = (value == "1");
																	else
																		if (parameter == "$decalscale")
																			newInfo->decalScale = FCString::Atof(*value);
					}
				}
				importerVMTList.Add(newInfo);
			}
			catch (...)
			{
				UE_LOG(LogTemp, Error, TEXT("Something went terribly wrong trying to load %s"), *fileName);
			}
		}
		else
			UE_LOG(LogTemp, Error, TEXT("%s is empty?"), *fileName);
	}
}

FReply SHammerTextUErWidget::RunImport()
{

	
	createdTextures = 0;
	importerTextureList.Empty();
	importerMaterialsDone.Empty();
	importerVMTList.Empty();

	struct FVisitor : public IPlatformFile::FDirectoryVisitor
	{
		TArray<FString>* PendingFiles;
		virtual bool Visit(const TCHAR* FilenameOrDirectory, bool bIsDirectory)
		{
			if (!bIsDirectory)
			{
				FString FileStr(FilenameOrDirectory);
				if (HammUErSettings::importTexturesMats == 0 || HammUErSettings::importTexturesMats == 1)
				{
					if (FileStr.EndsWith(".vtf", ESearchCase::IgnoreCase) ||
						FileStr.EndsWith(".bmp", ESearchCase::IgnoreCase) ||
						FileStr.EndsWith(".png", ESearchCase::IgnoreCase) ||
						FileStr.EndsWith(".jpeg", ESearchCase::IgnoreCase) ||
						FileStr.EndsWith(".wad", ESearchCase::IgnoreCase) ||
						FileStr.EndsWith(".wal", ESearchCase::IgnoreCase) ||
						FileStr.EndsWith(".jpg", ESearchCase::IgnoreCase) ||
						FileStr.EndsWith(".tga", ESearchCase::IgnoreCase))
						PendingFiles->Add(MoveTemp(FileStr));
				}
				if (HammUErSettings::importTexturesMats == 0 || HammUErSettings::importTexturesMats == 2)
				{
					if (FileStr.EndsWith(".mtr")) // idtech4
						PendingFiles->Add(MoveTemp(FileStr));
					if (FileStr.EndsWith(".shader")) // idtech3
						PendingFiles->Add(MoveTemp(FileStr));
					if (FileStr.EndsWith(".vmt", ESearchCase::IgnoreCase)) //source
						PendingFiles->Add(MoveTemp(FileStr));
				}
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

	if (!HammUErSettings::okayedTexturesLegal)
	{
		EAppReturnType::Type answer = FMessageDialog::Open(EAppMsgType::OkCancel, FText::FromString("You cannot legally use *any* textures you don't own or have permission for in your Unreal Engine projects.\r\nRemember that while you can import any and all textures and use them to design your maps, you *must* replace anything that infringes copyright before publishing your project.\r\nYou take full responsibility for what you do with the files you've imported.\r\nThis message will only be shown once."));
		if (answer == EAppReturnType::Cancel)
			return FReply::Handled();
		HammUErSettings::okayedTexturesLegal = true;
	}

	HammUErSettings::LoadConfig(true); // make sure the master list is loaded
	HammUErSettings::SaveConfig();

	PendingImportFiles.Empty();
	TArray<FString> PendingDirectories;
	TArray<FString> directoriesToVisit;
	directoriesToVisit.Add(HammUErSettings::textureSourceDirectory);

	directoryVisitor.PendingDirs = &PendingDirectories;
	FPlatformFileManager::Get().GetPlatformFile().IterateDirectory(*HammUErSettings::textureSourceDirectory, directoryVisitor);
	while (PendingDirectories.Num() > 0)
	{
		FString dirToCheck = PendingDirectories[0];
		PendingDirectories.RemoveAt(0);
		directoriesToVisit.Add(dirToCheck);
		FPlatformFileManager::Get().GetPlatformFile().IterateDirectory(*dirToCheck, directoryVisitor);
	}

	TArray<FString> thisDir;
	filenameVisitor.PendingFiles = &thisDir;

	for (int i = 0; i < directoriesToVisit.Num(); i++)
	{
		thisDir.Empty();
		FPlatformFileManager::Get().GetPlatformFile().IterateDirectory(*directoriesToVisit[i], filenameVisitor);
		thisDir.Sort();
	/*	for (int j = 0; j < thisDir.Num(); j++)
		{
			if (thisDir[j].EndsWith(".ZZZ"))
				thisDir[j].Replace(TEXT(".ZZZ"), TEXT(".VMT"));
		}*/
		PendingImportFiles.Append(thisDir);
	}


	if (PendingImportFiles.Num() == 0)
	{
		FMessageDialog::Open(EAppMsgType::Ok, FText::FromString("No files found."));
		return FReply::Handled();
	}

	if (PendingImportFiles.Num() > 1000)
	{
		EAppReturnType::Type answer = FMessageDialog::Open(EAppMsgType::YesNo, FText::FromString("You're importing more than 1000 files in one go.\r\nThis might take a long time, and if it crashes, you lose all new data.\r\n\r\nAre you sure you want to continue?"));
		if (answer == EAppReturnType::No)
			return FReply::Handled();
	}

	if (HammUErSettings::verboseDebugEnabled)
	{
		UE_LOG(LogTemp, Warning, TEXT("---------------------------------------- PENDING LIST ------------------------"));
		for (int i = 0; i < PendingImportFiles.Num(); i++)
		{
			UE_LOG(LogTemp, Warning, TEXT("%i %s"), i, *PendingImportFiles[i]);
		}
		UE_LOG(LogTemp, Warning, TEXT("---------------------------------------- END OF LIST ------------------------"));
	}

	int totalFiles = PendingImportFiles.Num();
	FScopedSlowTask SlowTask(totalFiles, FText::FromString("Importing textures..."));
	SlowTask.MakeDialog();
	for (int currentImportFile =0; currentImportFile < totalFiles; currentImportFile++)
		{
			SlowTask.EnterProgressFrame(1);
			if (HammUErSettings::verboseDebugEnabled)
				UE_LOG(LogTemp, Log, TEXT("Importing file %i, %s"), currentImportFile, *PendingImportFiles[currentImportFile]);
			if (PendingImportFiles[currentImportFile].EndsWith(".vmt"))
				ImportVMT(PendingImportFiles[currentImportFile]);
			else
				if (PendingImportFiles[currentImportFile].EndsWith(".mtr"))
					ImportMTR(PendingImportFiles[currentImportFile]);
				else
					if (PendingImportFiles[currentImportFile].EndsWith(".shader"))
						ImportSHADER(PendingImportFiles[currentImportFile]);
					else
					if (PendingImportFiles[currentImportFile].EndsWith(".vtf"))
					ImportVTF(PendingImportFiles[currentImportFile]);
				else
					if (PendingImportFiles[currentImportFile].EndsWith(".tga"))
						ImportTGA(PendingImportFiles[currentImportFile]);
					else
						if (PendingImportFiles[currentImportFile].EndsWith(".wad"))
							ImportWAD(PendingImportFiles[currentImportFile]);
						else
							if (PendingImportFiles[currentImportFile].EndsWith(".wal"))
								ImportWAL(PendingImportFiles[currentImportFile]);
							else
								ImportOther(PendingImportFiles[currentImportFile]);
		}
	
	importRunning = false;
	if (HammUErSettings::importTexturesMats == 0 || HammUErSettings::importTexturesMats == 2)
	CreateMaterials();

	HammUErSettings::SaveConfig();
	FMessageDialog::Open(EAppMsgType::Ok, FText::FromString("Done."));
	//importRunning = true;
	return FReply::Handled();
}

bool SHammerTextUErWidget::CanImport() const
{
	return !importRunning && !running && !discovering;
}

FReply SHammerTextUErWidget::GetImportDir()
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
		bOpen = DesktopPlatform->OpenDirectoryDialog(ParentWindowWindowHandle, "Choose import directory", HammUErSettings::textureSourceDirectory, inFolderName);
		if (bOpen)
			HammUErSettings::textureSourceDirectory = inFolderName;
	}
	return FReply::Handled();
}

FString SHammerTextUErWidget::GetCurrentPath() const
{
	if ((sourceMaterial!=NULL) && (sourceMaterial))
		return sourceMaterial->GetPathName();
	else
		return FString("");
}

FString SHammerTextUErWidget::GetDecalCurrentPath() const
{
	if ((decalMaterial!=NULL) && (decalMaterial))
		return decalMaterial->GetPathName();
	else
		return FString("");
}

void SHammerTextUErWidget::OnMaterialChanged(const FAssetData& inAssetData)
{
	if (inAssetData.IsValid())
	{
		matContainsNormal = false;
		matContainsSpecular = false;
		normalParameterDropNamesList.Empty();
		InitialNormalSelected = NULL;
		currentNormalParameter = "";

		sourceMaterial = Cast<UMaterialInterface>(inAssetData.GetAsset());
		TArray<UTexture*> chainTextures;
		TArray<FName> parameterNames;
		sourceMaterial->GetTexturesInPropertyChain(EMaterialProperty::MP_BaseColor, chainTextures, &parameterNames, NULL);

		if (parameterNames.Num() > 0)
		{
			parameterDropNamesList.Empty();
			for (int i = 0; i < parameterNames.Num(); i++)
				parameterDropNamesList.Add(MakeShareable(new FString(parameterNames[i].ToString())));
			if (parameterDropNamesList.Num() > 0)
			{
				InitialSelected = parameterDropNamesList[0];
				currentParameter = *InitialSelected;
				if (parameterDropNamesList.Num() == 2)
					currentBlendParameter = *parameterDropNamesList[1];
			}

			parameterNames.Empty();
			chainTextures.Empty();
			sourceMaterial->GetTexturesInPropertyChain(EMaterialProperty::MP_Normal, chainTextures, &parameterNames, NULL);
			if (parameterNames.Num() > 0)
			{
				matContainsNormal = true;
				normalParameterDropNamesList.Empty();
				for (int i = 0; i < parameterNames.Num(); i++)
					normalParameterDropNamesList.Add(MakeShareable(new FString(parameterNames[i].ToString())));
				if (normalParameterDropNamesList.Num() > 0)
				{
					InitialNormalSelected = normalParameterDropNamesList[0];
					currentNormalParameter = *InitialNormalSelected;
					if (normalParameterDropNamesList.Num() == 2)
						currentBlendNormalParameter = *normalParameterDropNamesList[1];
				}
			}
			
			parameterNames.Empty();
			chainTextures.Empty();
			sourceMaterial->GetTexturesInPropertyChain(EMaterialProperty::MP_Roughness, chainTextures, &parameterNames, NULL);
			if (parameterNames.Num() > 0)
			{
				matContainsSpecular = true;
				specularParameterDropNamesList.Empty();
				for (int i = 0; i < parameterNames.Num(); i++)
					specularParameterDropNamesList.Add(MakeShareable(new FString(parameterNames[i].ToString())));
				if (specularParameterDropNamesList.Num() > 0)
				{
					if (specularParameterDropNamesList.Num() == 2)
						InitialSpecularSelected = specularParameterDropNamesList[1];
					else
						InitialSpecularSelected = specularParameterDropNamesList[0];
					currentSpecularParameter = *InitialSpecularSelected;
				}
			}
		}
		else
		{
			FMessageDialog::Open(EAppMsgType::Ok, FText::FromString("This material does not contain any BaseColor texture parameters."));
			parameterDropNamesList.Empty();
			currentParameter = "";
			InitialSelected = NULL;
			sourceMaterial = NULL;
		}
	}
}

void SHammerTextUErWidget::OnDecalMaterialChanged(const FAssetData& inAssetData)
{
	if (inAssetData.IsValid())
	{

		decalMaterial = Cast<UMaterialInterface>(inAssetData.GetAsset());
		TArray<UTexture*> chainTextures;
		TArray<FName> parameterNames;
		
		if (((UMaterial*)decalMaterial)->MaterialDomain == MD_DeferredDecal)
		{
			decalMaterial->GetTexturesInPropertyChain(EMaterialProperty::MP_BaseColor, chainTextures, &parameterNames, NULL);

			if (parameterNames.Num() > 0)
			{
				decalParameterDropNamesList.Empty();
				for (int i = 0; i < parameterNames.Num(); i++)
					decalParameterDropNamesList.Add(MakeShareable(new FString(parameterNames[i].ToString())));
				if (decalParameterDropNamesList.Num() > 0)
				{
					InitialDecalSelected = decalParameterDropNamesList[0];
					decalParameter = *InitialDecalSelected;
				}

				parameterNames.Empty();
				chainTextures.Empty();
			}
			else
			{
				FMessageDialog::Open(EAppMsgType::Ok, FText::FromString("This material does not contain any BaseColor texture parameters."));
				decalParameterDropNamesList.Empty();
				decalParameter = "";
				InitialDecalSelected = NULL;
				decalMaterial = NULL;
			}
		}
		else
		{
			FMessageDialog::Open(EAppMsgType::Ok, FText::FromString("This material does not use the Deferred Decal domain!"));
			decalParameterDropNamesList.Empty();
			decalParameter = "";
			InitialDecalSelected = NULL;
			decalMaterial = NULL;
		}
	}
}

void SHammerTextUErWidget::TextureDirectoryChanged(const FText& InLabel, ETextCommit::Type TextType)
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
		newItem = newItem.Replace(TEXT("."), TEXT("-"));
		newItem = newItem.Replace(TEXT("&"), TEXT("_"));

		HammUErSettings::textureImportDirectory = newItem;
	}
}

FText SHammerTextUErWidget::GetTextureImportDirectory() const
{
	return FText::FromString(HammUErSettings::textureImportDirectory);
}


// Export stuff

FText SHammerTextUErWidget::GetExportDirectory() const
{
	return FText::FromString(HammUErSettings::VTFExportDirectory);
}


FReply SHammerTextUErWidget::ExportAllTextures()
{
	if (!running && !importRunning)
	{
		HammUErSettings::LoadConfig(true);  // make sure we load the master list too
		// get everything
		AssetData.Empty();
		FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");
		AssetRegistryModule.Get().GetAssetsByClass("Material", AssetData, true);
		TArray<FAssetData> AssetData2;
		AssetRegistryModule.Get().GetAssetsByClass("MaterialInstance", AssetData2, true);
		AssetData.Append(AssetData2);

		running = true;
		currentMaterial = 0;
	}
	return FReply::Handled();
}

FReply SHammerTextUErWidget::HandleChooseFileButtonClicked()
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

		FString outFolderName;
		bOpen = DesktopPlatform->OpenDirectoryDialog(ParentWindowWindowHandle, "Choose export directory", HammUErSettings::VTFExportDirectory, outFolderName);
		if (bOpen)
			HammUErSettings::VTFExportDirectory = outFolderName;
	}
	return FReply::Handled();
}

void SHammerTextUErWidget::OnKeepContainsWithChanged(const FText& InLabel, ETextCommit::Type TextType)
{
	if (TextType == ETextCommit::OnEnter || TextType == ETextCommit::Default || TextType == ETextCommit::OnUserMovedFocus)
	{
		FString newList = InLabel.ToString();
		FString temp;
		int32 pos;
		newList.TrimStartInline();
		newList.TrimEndInline();
		HammUErSettings::textureKeepContains.Empty();
		while (newList.Len() > 0)
		{
			pos = newList.Find(",");
			if (pos == -1)
				pos = newList.Len();
			temp = newList.Mid(0, pos);
			temp.TrimStartInline();
			temp.TrimEndInline();
			HammUErSettings::textureKeepContains.Add(temp);
			newList.RemoveAt(0, pos + 1);
		}
	}
}

FText SHammerTextUErWidget::GetKeepContainsWithList() const
{
	FString result = "";
	for (int i = 0; i < HammUErSettings::textureKeepContains.Num(); i++)
		result += (HammUErSettings::textureKeepContains[i]) + (i == HammUErSettings::textureKeepContains.Num() - 1 ? "" : ",");
	return FText::FromString(result);
}


void SHammerTextUErWidget::OnBeginsWithChanged(const FText& InLabel, ETextCommit::Type TextType)
{
	if (TextType == ETextCommit::OnEnter || TextType == ETextCommit::Default || TextType == ETextCommit::OnUserMovedFocus)
	{
		FString newList = InLabel.ToString();
		FString temp;
		int32 pos;
		newList.TrimStartInline();
		newList.TrimEndInline();
		HammUErSettings::textureBeginsWith.Empty();
		while (newList.Len() > 0)
		{
			pos = newList.Find(",");
			if (pos == -1)
				pos = newList.Len();
			temp = newList.Mid(0, pos);
			temp.TrimStartInline();
			temp.TrimEndInline();
			HammUErSettings::textureBeginsWith.Add(temp);
			newList.RemoveAt(0, pos + 1);
		}
	}
}

FText SHammerTextUErWidget::GetBeginsWithList() const
{
	FString result = "";
	for (int i = 0; i < HammUErSettings::textureBeginsWith.Num(); i++)
		result += (HammUErSettings::textureBeginsWith[i]) + (i == HammUErSettings::textureBeginsWith.Num() - 1 ? "" : ",");
	return FText::FromString(result);
}

void SHammerTextUErWidget::OnNormalsEndChanged(const FText& InLabel, ETextCommit::Type TextType)
{
	if (TextType == ETextCommit::OnEnter || TextType == ETextCommit::Default || TextType == ETextCommit::OnUserMovedFocus)
	{
		FString newList = InLabel.ToString();
		FString temp;
		int32 pos;
		newList.TrimStartInline();
		newList.TrimEndInline();
		HammUErSettings::importerNormalExtensions.Empty();
		while (newList.Len() > 0)
		{
			pos = newList.Find(",");
			if (pos == -1)
				pos = newList.Len();
			temp = newList.Mid(0, pos);
			temp.TrimStartInline();
			temp.TrimEndInline();
			HammUErSettings::importerNormalExtensions.Add(temp);
			newList.RemoveAt(0, pos + 1);
		}
	}
}

FText SHammerTextUErWidget::GetNormalsEndList() const
{
	FString result = "";
	for (int i = 0; i < HammUErSettings::importerNormalExtensions.Num(); i++)
		result += (HammUErSettings::importerNormalExtensions[i]) + (i == HammUErSettings::importerNormalExtensions.Num() - 1 ? "" : ",");
	return FText::FromString(result);
}

void SHammerTextUErWidget::OnIgnoreEndChanged(const FText& InLabel, ETextCommit::Type TextType)
{
	if (TextType == ETextCommit::OnEnter || TextType == ETextCommit::Default || TextType == ETextCommit::OnUserMovedFocus)
	{
		FString newList = InLabel.ToString();
		FString temp;
		int32 pos;
		newList.TrimStartInline();
		newList.TrimEndInline();
		HammUErSettings::importerIgnoreExtensions.Empty();
		while (newList.Len() > 0)
		{
			pos = newList.Find(",");
			if (pos == -1)
				pos = newList.Len();
			temp = newList.Mid(0, pos);
			temp.TrimStartInline();
			temp.TrimEndInline();
			HammUErSettings::importerIgnoreExtensions.Add(temp);
			newList.RemoveAt(0, pos + 1);
		}
	}
}

FText SHammerTextUErWidget::GetIgnoreEndList() const
{
	FString result = "";
	for (int i = 0; i < HammUErSettings::importerIgnoreExtensions.Num(); i++)
		result += (HammUErSettings::importerIgnoreExtensions[i]) + (i == HammUErSettings::importerIgnoreExtensions.Num() - 1 ? "" : ",");
	return FText::FromString(result);
}


void SHammerTextUErWidget::OnEndsWithChanged(const FText& InLabel, ETextCommit::Type TextType)
{
	if (TextType == ETextCommit::OnEnter || TextType == ETextCommit::Default || TextType == ETextCommit::OnUserMovedFocus)
	{
		FString newList = InLabel.ToString();
		FString temp;
		int32 pos;
		newList.TrimStartInline();
		newList.TrimEndInline();
		HammUErSettings::textureEndsWith.Empty();
		while (newList.Len() > 0)
		{
			pos = newList.Find(",");
			if (pos == -1)
				pos = newList.Len();
			temp = newList.Mid(0, pos);
			temp.TrimStartInline();
			temp.TrimEndInline();
			HammUErSettings::textureEndsWith.Add(temp);
			newList.RemoveAt(0, pos + 1);
		}
	}
}

FText SHammerTextUErWidget::GetEndsWithList() const
{
	FString result = "";
	for (int i = 0; i < HammUErSettings::textureEndsWith.Num(); i++)
		result += (HammUErSettings::textureEndsWith[i]) + (i == HammUErSettings::textureEndsWith.Num() - 1 ? "" : ",");
	return FText::FromString(result);
}


void SHammerTextUErWidget::OnContainsChanged(const FText& InLabel, ETextCommit::Type TextType)
{
	if (TextType == ETextCommit::OnEnter || TextType == ETextCommit::Default || TextType == ETextCommit::OnUserMovedFocus)
	{
		FString newList = InLabel.ToString();
		FString temp;
		int32 pos;
		newList.TrimStartInline();
		newList.TrimEndInline();
		HammUErSettings::textureContains.Empty();
		while (newList.Len() > 0)
		{
			pos = newList.Find(",");
			if (pos == -1)
				pos = newList.Len();
			temp = newList.Mid(0, pos);
			temp.TrimStartInline();
			temp.TrimEndInline();
			HammUErSettings::textureContains.Add(temp);
			newList.RemoveAt(0, pos + 1);
		}
	}
}

FText SHammerTextUErWidget::GetContainsList() const
{
	FString result = "";
	for (int i = 0; i < HammUErSettings::textureContains.Num(); i++)
		result += (HammUErSettings::textureContains[i]) + (i == HammUErSettings::textureContains.Num() - 1 ? "" : ",");
	return FText::FromString(result);
}


#undef LOCTEXT_NAMESPACE