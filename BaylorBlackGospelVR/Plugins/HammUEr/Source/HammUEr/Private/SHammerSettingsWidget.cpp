// HammUEr
// Copyright 2015-2016 Turfster / NT Entertainment
// All Rights Reserved.


// This code is held together with kitten whiskers and toothpicks.
// There's nothing to see or learn here.
// Seriously.
// Turn back.

#include "HammUErPrivatePCH.h"
#include "SHammerSettingsWidget.h"
#include "SlateOptMacros.h"
#include "UnrealEd.h"
#include "HammUEr.h"
#include "HammUErSettings.h"

#define LOCTEXT_NAMESPACE "SHammerSettingsWidget"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION

void SHammerSettingsWidget::Construct(const FArguments& InArgs)
{
	RadioChoice = (ERadioChoice)HammUErSettings::defaultDisplacementAlphaChannel;
	FString imagePath = FPaths::ProjectPluginsDir() + TEXT("HammUEr/Resources/headertest.png");
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
					[
						SNew(SBorder)
						.Padding(FMargin(3))
						[
							SNew(SBox)
							.Padding(FMargin(3))
							[
								SNew(SVerticalBox)
								+ SVerticalBox::Slot()
								.AutoHeight()
								[
									SNew(SHeader)
									.Content()
									[
										SNew(STextBlock)
										.Text(LOCTEXT("general","General settings"))
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
											.Padding(FMargin(3.f, 1.f))
											[
												SNew(SHorizontalBox)
												+ SHorizontalBox::Slot()
												.AutoWidth()
												.VAlign(VAlign_Center)
												[
													SNew(SBox)
													.WidthOverride(250)
													[
														SNew(SHorizontalBox)
														+ SHorizontalBox::Slot()
														.AutoWidth()
														.MaxWidth(250)
														.VAlign(VAlign_Center)
														[
															SNew(STextBlock)
															.Text(LOCTEXT("Import_Scale", "Scale conversion: "))
														]
														+ SHorizontalBox::Slot()
														.MaxWidth(80)
														.VAlign(VAlign_Center)
														[
															SNew(SNumericEntryBox<float>)
															.Delta(0.001f)
															.MinValue(1.0f)
															.MaxValue(300.0f)
															.AllowSpin(false)
															.Value(this, &SHammerSettingsWidget::GetConversionRate)
															.OnValueChanged(this, &SHammerSettingsWidget::SetConversionRate)
															.ToolTipText(LOCTEXT("scaletooltip", "Scale to use when importing. 100 cm is X original units.\r\nThe smaller the value, the larger your map becomes.\r\nTry around 39.37 for classic Source maps, for example."))
														]
													]
												]
												+SHorizontalBox::Slot()
												.AutoWidth()
												.VAlign(VAlign_Center)
												[
													SNew(SBox)
													.WidthOverride(400)
													[
														SNew(SHorizontalBox)
														+ SHorizontalBox::Slot()
														.AutoWidth()
														.MaxWidth(150)
														.VAlign(VAlign_Center)
														[
															SNew(STextBlock)
															.Text(LOCTEXT("Import_PropScale", "Adjust prop scale: "))
															.ToolTipText(LOCTEXT("importscaletooltip", "In PropUEr: bakes the scale conversion into the UE version of the static mesh.\r\nUE scale: keeps original X/Y/Z values, adjusts transform scale on VMF import."))
														]
														+ SHorizontalBox::Slot()
														.Padding(FMargin(3.f, 1.f))
														.MaxWidth(230)
														[
															SNew(SHorizontalBox)
															+ SHorizontalBox::Slot()
															.MaxWidth(60)
															[
																CreateRadioButton(LOCTEXT("on_never", "Ignore"), LOCTEXT("on_never_tooltip", "Ignore scaling when importing or placing props."), ScaleRadio0)
															]
															+ SHorizontalBox::Slot()
															.MaxWidth(100)
															[
																CreateRadioButton(LOCTEXT("on_import", "In PropUEr"), LOCTEXT("on_import_tooltip", "Bakes the scale conversion into the UE static mesh when importing it the first time."), ScaleRadio1)
															]
															+ SHorizontalBox::Slot()
															.MaxWidth(70)
															[
																CreateRadioButton(LOCTEXT("on_scale", "UE scale"), LOCTEXT("on_scale_tooltip", "Keeps original X/Y/Z values, adjust transform scale on VMF import when placing entities."), ScaleRadio2)
															]
														]
													]
												]
											]
								+ SVerticalBox::Slot()
									.AutoHeight()
									.Padding(FMargin(3.f, 1.f))
									[
										SNew(SHorizontalBox)
										+ SHorizontalBox::Slot()
										.AutoWidth()
										.VAlign(VAlign_Center)
										[
											SNew(SBox)
											.WidthOverride(250)
											[
												SNew(SHorizontalBox)
												+SHorizontalBox::Slot()
												.MaxWidth(250)
												.VAlign(VAlign_Center)
												[
													SNew(STextBlock)
													.Text(LOCTEXT("Import_LightFactor", "Light intensity factor: "))
												]
												+ SHorizontalBox::Slot()
												.MaxWidth(50)
												.VAlign(VAlign_Center)
												[
													SNew(SNumericEntryBox<float>)
													.Delta(1.0f)
													.MinValue(1.0f)
													.MaxValue(2048.0f)
													.AllowSpin(false)
													.Value(this, &SHammerSettingsWidget::GetLightFactor)
													.OnValueChanged(this, &SHammerSettingsWidget::SetLightFactor)
													.ToolTipText(LOCTEXT("lightfactortip", "Amount to *multiply* original light values by.\r\nUnused for Quake .MAP import."))
												]
											]
										]
										+SHorizontalBox::Slot()
										.AutoWidth()
										.VAlign(VAlign_Center)
										[
											SNew(SBox)
											.WidthOverride(300)
											[
												SNew(SHorizontalBox)
												+ SHorizontalBox::Slot()
												.AutoWidth()
												.MaxWidth(250)
												.VAlign(VAlign_Center)
												[
													SNew(STextBlock)
													.Text(LOCTEXT("twosidedCull", "NoDraw brushes have two-sided shadowing"))
												]
												+ SHorizontalBox::Slot()
												.AutoWidth()
												.MaxWidth(20)
												.Padding(FMargin(3.0f, 0.0f))
												.VAlign(VAlign_Center)
												[
													SNew(SCheckBox)
													.IsChecked(this, &SHammerSettingsWidget::GetTwoSidedActive)
													.OnCheckStateChanged(this, &SHammerSettingsWidget::OnTwoSidedChanged)
													.ToolTipText(LOCTEXT("twosidedtooltip", "If for example your ceiling has a nodraw side, but you still want it to stop light passing through, use this."))
												]
											]
										]
									]
											+ SVerticalBox::Slot()
												[
													SNew(SSeparator)//SSpacer)
												]
											+ SVerticalBox::Slot()
												.AutoHeight()
												.Padding(FMargin(3.0f, 1.0f))
												[
													SNew(SHorizontalBox)
													+ SHorizontalBox::Slot()
													.AutoWidth()
													.MaxWidth(250)
													.VAlign(VAlign_Center)
													[
														SNew(STextBlock)
														.Text(LOCTEXT("round", "Round brush points"))
													]
													+ SHorizontalBox::Slot()
														.Padding(FMargin(3.0f, 1.0f))
														.MaxWidth(20)
														.VAlign(VAlign_Center)
														[
															SNew(SCheckBox)
															.IsChecked(this, &SHammerSettingsWidget::GetRoundPoints)
															.OnCheckStateChanged(this, &SHammerSettingsWidget::OnRoundPointsChanged)
															.ToolTipText(LOCTEXT("roundtooltip", "Can fix missing side / protrusion errors by removing as many chances of floating point errors as possible.\r\nThis happens at an early stage in the process, and is the thermonuclear option.\r\nTry the other one first."))
														]
													+ SHorizontalBox::Slot()
														.MaxWidth(16)
														.VAlign(VAlign_Center)
														[
															SNew(STextBlock)
															.Text(LOCTEXT("empty", ""))
														]
													+ SHorizontalBox::Slot()
														.AutoWidth()
														.MaxWidth(250)
														.VAlign(VAlign_Center)
														[
															SNew(STextBlock)
															.Text(LOCTEXT("roundmesh", "Round accepted points"))
														]
													+ SHorizontalBox::Slot()
														.Padding(FMargin(3.0f, 1.0f))
														.MaxWidth(20)
														.VAlign(VAlign_Center)
														[
															SNew(SCheckBox)
															.IsChecked(this, &SHammerSettingsWidget::GetRoundPointsMesh)
														.OnCheckStateChanged(this, &SHammerSettingsWidget::OnRoundPointsMeshChanged)
														.ToolTipText(LOCTEXT("roundmeshtooltip", "Happens at a later stage than the first one.\r\nMuch less aggressive and doesn't actually remove any possible sides, unlike the other one.\r\nShould be safe for all but the most tiny and intricate work."))
														]
													+ SHorizontalBox::Slot()
														.MaxWidth(16)
														.VAlign(VAlign_Center)
														[
															SNew(STextBlock)
															.Text(LOCTEXT("empty", ""))
														]
													+ SHorizontalBox::Slot()
														.AutoWidth()
														.MaxWidth(250)
														.VAlign(VAlign_Center)
														[
															SNew(STextBlock)
															.Text(LOCTEXT("rounddisplacements", "Round displacements"))
														]
													+ SHorizontalBox::Slot()
														.Padding(FMargin(3.0f, 1.0f))
														.MaxWidth(20)
														.VAlign(VAlign_Center)
														[
															SNew(SCheckBox)
															.IsChecked(this, &SHammerSettingsWidget::GetRoundDisplacementPoints)
														.OnCheckStateChanged(this, &SHammerSettingsWidget::OnRoundDisplacementPointsChanged)
														.ToolTipText(LOCTEXT("rounddisplacementtooltip", "Rounds off displacement points to the nearest integer."))
														]
												]
											+ SVerticalBox::Slot()
											.AutoHeight()
											.Padding(FMargin(3.0f, 1.0f))
											[
												SNew(SHorizontalBox)
												+ SHorizontalBox::Slot()
													.AutoWidth()
													.MaxWidth(250)
													.VAlign(VAlign_Center)
												[
													SNew(STextBlock)
													.Text(LOCTEXT("errorRange", "Error correction range: "))
												]
												+ SHorizontalBox::Slot()
												    .Padding(FMargin(3.f, 1.f))
													.AutoWidth()
													.MaxWidth(150)
													.VAlign(VAlign_Center)
												[
													SNew(SNumericEntryBox<float>)
													.Delta(0.01f)
													.MinValue(0.01f)
													.MaxValue(9.0f)
													.AllowSpin(false)
													.Value(this, &SHammerSettingsWidget::GetErrorMargin)
													.OnValueChanged(this, &SHammerSettingsWidget::SetErrorMargin)
													.ToolTipText(LOCTEXT("errormargintooltip", "Can fix erroneous triangles appearing by being looser when discarding bad points.\r\nSetting this too high will also remove valid points, so be careful.\r\nRecommended value is in the 0.5-1.5 range"))
												]
												+SHorizontalBox::Slot()
													.MaxWidth(16)
													.VAlign(VAlign_Center)
													[
														SNew(STextBlock)
														.Text(LOCTEXT("empty",""))
													]
												+ SHorizontalBox::Slot()
													.AutoWidth()
													.MaxWidth(250)
													.VAlign(VAlign_Center)
													[
														SNew(STextBlock)
														.Text(LOCTEXT("intersectRange", "Intersect factor: "))
													]
												+ SHorizontalBox::Slot()
													.Padding(FMargin(3.f, 1.f))
													.AutoWidth()
													.MaxWidth(250)
													.VAlign(VAlign_Center)
													[
														SNew(SNumericEntryBox<float>)
														.Delta(1.0f)
														.MinValue(10.0f)
														.MaxValue(10000.0f)
														.AllowSpin(false)
														.Value(this, &SHammerSettingsWidget::GetIntersectMargin)
														.OnValueChanged(this, &SHammerSettingsWidget::SetIntersectMargin)
														.ToolTipText(LOCTEXT("intersecttooltip", "Can fix import errors. The lower this is set, the more options will be discarded as false positives.\r\nYou *normally* shouldn't touch this, but lowering it will make it stricter,\r\nso if there's no minuscule detail in your map, you should be able to drop this to 100 safely if you're getting errors."))
													]
												+ SHorizontalBox::Slot()
													.MaxWidth(16)
													.VAlign(VAlign_Center)
													[
														SNew(STextBlock)
														.Text(LOCTEXT("empty", ""))
													]
												+ SHorizontalBox::Slot()
													.AutoWidth()
													.MaxWidth(250)
													.VAlign(VAlign_Center)
													[
														SNew(STextBlock)
														.Text(LOCTEXT("weldRange", "Vector weld margin: "))
													]
												+ SHorizontalBox::Slot()
													.Padding(FMargin(3.f, 1.f))
													.AutoWidth()
													.MaxWidth(150)
													.VAlign(VAlign_Center)
													[
														SNew(SNumericEntryBox<float>)
														.Delta(0.01f)
													.MinValue(0.01f)
													.MaxValue(9.0f)
													.AllowSpin(false)
													.Value(this, &SHammerSettingsWidget::GetWeldMargin)
													.OnValueChanged(this, &SHammerSettingsWidget::SetWeldMargin)
													.ToolTipText(LOCTEXT("weldRangetooltip", "Nearness value used to merge vectors together when smoothing"))
													]
											]
											//
											+ SVerticalBox::Slot()
												[
													SNew(SSeparator)//SSpacer)
												]
											+ SVerticalBox::Slot()
												.AutoHeight()
												.Padding(FMargin(3.0f, 1.0f))
												[
													SNew(SHorizontalBox)
													+ SHorizontalBox::Slot()
													.AutoWidth()
													.MaxWidth(250)
													.VAlign(VAlign_Center)
													[
														SNew(STextBlock)
														.Text(LOCTEXT("decouple","Decouple brush meshes from origin"))
													]
													+ SHorizontalBox::Slot()
														.MaxWidth(50)
														.Padding(FMargin(3.0f,1.0f))
														.VAlign(VAlign_Center)
														[
															SNew(SCheckBox)
															.IsChecked(this, &SHammerSettingsWidget::GetCenterCheckedActive)
															.OnCheckStateChanged(this, &SHammerSettingsWidget::OnCenterCheckboxChanged)
															.ToolTipText(LOCTEXT("decoupletooltip","Recenters origin to inside the mesh for each separate mesh\r\ninstead of building everything relative to 0,0,0."))
														]
													+ SHorizontalBox::Slot()
														.AutoWidth()
														.MaxWidth(250)
														.VAlign(VAlign_Center)
														[
															SNew(STextBlock)
															.Text(LOCTEXT("Import_patchSubDiv", "Patch subdivisions: "))
														.ToolTipText(LOCTEXT("patchSubDiv_tooltip", "How many subdivisions to use for the quadratic patches in Q3 onwards"))
														]
													+ SHorizontalBox::Slot()
														.MaxWidth(150)
														.VAlign(VAlign_Center)
														[
															SNew(SHorizontalBox)
															+ SHorizontalBox::Slot()
														.MaxWidth(70)
														[
															SNew(SNumericEntryBox<int32>)
															.Delta(1)
														.MinValue(1)
														.MaxValue(32)
														.AllowSpin(false)
														.Value(this, &SHammerSettingsWidget::GetPatchH)
														.OnValueChanged(this, &SHammerSettingsWidget::SetPatchH)
														.ToolTipText(LOCTEXT("patchSubDivH_tooltip", "Horizontal subdivisions"))
														]
													+ SHorizontalBox::Slot()
														.MaxWidth(10)
														.VAlign(VAlign_Center)
														.Padding(FMargin(3.f, 0.f))
														[
															SNew(STextBlock)
															.Text(LOCTEXT(",", ","))
														]
													+ SHorizontalBox::Slot()
														.MaxWidth(70)
														[
															SNew(SNumericEntryBox<int32>)
															.Delta(1)
														.MinValue(1)
														.MaxValue(32)
														.AllowSpin(false)
														.Value(this, &SHammerSettingsWidget::GetPatchV)
														.OnValueChanged(this, &SHammerSettingsWidget::SetPatchV)
														.ToolTipText(LOCTEXT("patchSubDivV_tooltip", "Vertical subdivisions"))
														]
														]
												]
											+ SVerticalBox::Slot()
												.AutoHeight()
												.Padding(FMargin(0.f, 1.f))
												[
													SNew(SHorizontalBox)
													+SHorizontalBox::Slot()
													.AutoWidth()
													[
														SNew(SBox)
														.Padding(FMargin(3.f, 1.f))
														.WidthOverride(292)
														[
															SNew(SHorizontalBox)
															+ SHorizontalBox::Slot()
															.AutoWidth()
															.MaxWidth(125)
															.VAlign(VAlign_Center)
															[
																SNew(STextBlock)
																.Text(LOCTEXT("importNonZero", "Import level with offset"))
															]
															+ SHorizontalBox::Slot()
															.MaxWidth(16)
															.AutoWidth()
															.Padding(FMargin(3.0f, 1.0f))
															.VAlign(VAlign_Center)
															[
																SNew(SCheckBox)
																.IsChecked(this, &SHammerSettingsWidget::GetNonZeroChecked)
																.OnCheckStateChanged(this, &SHammerSettingsWidget::OnNonZeroCheckboxChanged)
																.ToolTipText(LOCTEXT("importNonZerotooltip", "Imports level to a specified non 0,0,0 location.\r\nNote that offsets are applied *after* rotations,\r\nso if you import with 90 yaw, your X offset will become an Y offset."))
															]
															+ SHorizontalBox::Slot()
															.VAlign(VAlign_Center)
															.MaxWidth(150)
															.AutoWidth()
															[
																SNew(SVectorInputBox)
																.AllowResponsiveLayout(true)
																.bColorAxisLabels(true)
																.X(this, &SHammerSettingsWidget::GetImportX)
																.Y(this, &SHammerSettingsWidget::GetImportY)
																.Z(this, &SHammerSettingsWidget::GetImportZ)
																.OnXCommitted(this, &SHammerSettingsWidget::OnSetImportLocation, 0)
																.OnYCommitted(this, &SHammerSettingsWidget::OnSetImportLocation, 1)
																.OnZCommitted(this, &SHammerSettingsWidget::OnSetImportLocation, 2)
																.ToolTipText(LOCTEXT("importNonZeroLocationtooltip", "Location to import hammer levels to"))
															]
														]
													]
													+ SHorizontalBox::Slot()
													.MaxWidth(16)
													.VAlign(VAlign_Center)
													[
														SNew(STextBlock)
														.Text(LOCTEXT("empty", ""))
													]
													+SHorizontalBox::Slot()
													.AutoWidth()
													[
														SNew(SBox)
														.Padding(FMargin(3.f, 1.f))
														.WidthOverride(320)
														[
															SNew(SHorizontalBox)
															+ SHorizontalBox::Slot()
															.AutoWidth()
															.MaxWidth(146)
															.VAlign(VAlign_Center)
															[
																SNew(STextBlock)
																.Text(LOCTEXT("importRotate", "Rotate level after import"))
															]
															+ SHorizontalBox::Slot()
															.MaxWidth(16)
															.AutoWidth()
															.VAlign(VAlign_Center)
															.Padding(FMargin(3.0f, 1.0f))
															[
																SNew(SCheckBox)
																.IsChecked(this, &SHammerSettingsWidget::GetRotateChecked)
																.OnCheckStateChanged(this, &SHammerSettingsWidget::OnRotateCheckboxChanged)
																.ToolTipText(LOCTEXT("importRotatetooltip", "Rotates the imported hammer level"))
															]
															+ SHorizontalBox::Slot()
															.VAlign(VAlign_Center)
															.MaxWidth(150)
															.AutoWidth()
															[
																SNew(SRotatorInputBox)
																.AllowResponsiveLayout(true)
																.AllowSpin(false)
																.bColorAxisLabels(true)
																.Roll(this, &SHammerSettingsWidget::GetImportRoll)
																.Pitch(this, &SHammerSettingsWidget::GetImportPitch)
																.Yaw(this, &SHammerSettingsWidget::GetImportYaw)
																.OnRollCommitted(this, &SHammerSettingsWidget::OnSetImportRotation, 0)
																.OnPitchCommitted(this, &SHammerSettingsWidget::OnSetImportRotation, 1)
																.OnYawCommitted(this, &SHammerSettingsWidget::OnSetImportRotation, 2)
																.ToolTipText(LOCTEXT("importRotationtooltip", "Amount to rotate imported meshes by.\r\nNote that this *may* break your map if you decoupled them from origin. Shouldn't, but may."))
															]
														]
													]
												]
											+ SVerticalBox::Slot()
												.AutoHeight()
												.Padding(FMargin(3, 1.f))
												[
													SNew(SHorizontalBox)
													+SHorizontalBox::Slot()
													.AutoWidth()
													.MaxWidth(330)
													[
														SNew(SBox)
														.WidthOverride(320)
														[	
															SNew(SHorizontalBox)
															+ SHorizontalBox::Slot()
															.AutoWidth()
															.MaxWidth(300)
															.VAlign(VAlign_Center)
															[
																SNew(STextBlock)
																.Text(LOCTEXT("NonSmooth", "Do not generate smoothing groups & normals"))
															]
															+ SHorizontalBox::Slot()
															.AutoWidth()
															.MaxWidth(20)
															.Padding(FMargin(3.0f, 0.0f))
															.VAlign(VAlign_Center)
															[
																SNew(SCheckBox)
																.IsChecked(this, &SHammerSettingsWidget::GetNoSmoothActive)
																.OnCheckStateChanged(this, &SHammerSettingsWidget::OnNoSmoothChanged)
																.ToolTipText(LOCTEXT("NonSmooth_tooltip", "Do not use the new smoothing algorithm, but use the old flat shading for brush meshes and aggressive smoothing for displacements"))
															]
														]
													]
													+ SHorizontalBox::Slot()
													.AutoWidth()
													.MaxWidth(330)
													[
														SNew(SBox)
														.WidthOverride(320)
														[
															SNew(SHorizontalBox)
															+ SHorizontalBox::Slot()
															.AutoWidth()
															.MaxWidth(300)
															.VAlign(VAlign_Center)
															[
																SNew(STextBlock)
																.Text(LOCTEXT("SmoothAngle", "Maximum angle to smooth: "))
															]
															+ SHorizontalBox::Slot()
															.AutoWidth()
															.MaxWidth(40)
															.Padding(FMargin(3.0f, 0.0f))
															.VAlign(VAlign_Center)
															[
																SNew(SNumericEntryBox<float>)
																.Delta(1.0f)
																.MinValue(0.0f)
																.MaxValue(180.0f)
																.AllowSpin(false)
																.Value(this, &SHammerSettingsWidget::GetSmoothAngle)
																.OnValueChanged(this, &SHammerSettingsWidget::SetSmoothAngle)
															]
														]
													]
												]
											//
											+ SVerticalBox::Slot()
												[
													SNew(SSeparator)//SSpacer)
												]
											+ SVerticalBox::Slot()
												.AutoHeight()
												.Padding(FMargin(3.f, 1.f))
												[
													SNew(SHorizontalBox)
													+ SHorizontalBox::Slot()
													.AutoWidth()
													.MaxWidth(250)
													.VAlign(VAlign_Center)
													[
														SNew(STextBlock)
														.Text(LOCTEXT("Import_Lightmap", "Lightmap size: "))
													]
													+ SHorizontalBox::Slot()
														.AutoWidth()
														.MaxWidth(150)
														.VAlign(VAlign_Center)
														[
															SNew(SNumericEntryBox<float>)
															.Delta(1.0f)
															.MinValue(1.0f)
															.MaxValue(2048.0f)
															.AllowSpin(false)
															.Value(this, &SHammerSettingsWidget::GetLightmapSize)
															.OnValueChanged(this, &SHammerSettingsWidget::SetLightmapSize)
														.ToolTipText(LOCTEXT("lightmapTooltip", "Default lightmap size to use for generated brush meshes."))
														]
													+ SHorizontalBox::Slot()
														.MaxWidth(16)
														.VAlign(VAlign_Center)
														[
															SNew(SSpacer)
															.Visibility(EVisibility::Hidden)
														]
													+ SHorizontalBox::Slot()
														.AutoWidth()
														.MaxWidth(250)
														.VAlign(VAlign_Center)
														[
															SNew(STextBlock)
															.Text(LOCTEXT("Import_DefaultSize", "Default texture size: "))
														]
													+ SHorizontalBox::Slot()
														.MaxWidth(150)
														.VAlign(VAlign_Center)
														[
															SNew(SHorizontalBox)
															+ SHorizontalBox::Slot()
															.MaxWidth(70)
															[
																SNew(SNumericEntryBox<int32>)
																.Delta(1)
																.MinValue(1)
																.MaxValue(8192)
																.AllowSpin(false)
																.Value(this, &SHammerSettingsWidget::GetDefaultWidth)
																.OnValueChanged(this, &SHammerSettingsWidget::SetDefaultWidth)
																.ToolTipText(LOCTEXT("defaultTextureW_tooltip", "default texture width to use when no material is found"))
															]
															+ SHorizontalBox::Slot()
															.MaxWidth(10)
															.VAlign(VAlign_Center)
															.Padding(FMargin(3.f, 0.f))
															[
																SNew(STextBlock)
																.Text(LOCTEXT("x", "x"))
															]
															+ SHorizontalBox::Slot()
															.MaxWidth(70)
															[
																SNew(SNumericEntryBox<int32>)
																.Delta(1)
																.MinValue(1)
																.MaxValue(8192)
																.AllowSpin(false)
																.Value(this, &SHammerSettingsWidget::GetDefaultHeight)
																.OnValueChanged(this, &SHammerSettingsWidget::SetDefaultHeight)
																.ToolTipText(LOCTEXT("defaultTextureH_tooltip", "default texture height to use when no material is found"))
															]
														]
													
												]
											+ SVerticalBox::Slot()
											.AutoHeight()
											.Padding(FMargin(3.0f, 1.0f))
											[
													SNew(SHorizontalBox)
													+ SHorizontalBox::Slot()
													.AutoWidth()
													.MaxWidth(250)
													.VAlign(VAlign_Center)
													[
														SNew(STextBlock)
														.Text(LOCTEXT("useAlpha", "Do not use texture alpha on import"))
													]
													+ SHorizontalBox::Slot()
													.MaxWidth(16)
													.Padding(FMargin(3.0f, 1.0f))
													.VAlign(VAlign_Center)
													[
														SNew(SCheckBox)
														.IsChecked(this, &SHammerSettingsWidget::GetTextureAlpha)
														.OnCheckStateChanged(this, &SHammerSettingsWidget::OnTextureAlphaChanged)
														.ToolTipText(LOCTEXT("alphatooltip", "Ignore the texture alpha.\r\nTurning this on can help, because most Source engine games\r\nseem to have a *lot* of bad alpha in textures."))
													]	
													+ SHorizontalBox::Slot()
														.MaxWidth(16)
														.VAlign(VAlign_Center)
														[
															SNew(SSpacer)
															.Visibility(EVisibility::Hidden)
														]
													+ SHorizontalBox::Slot()
														.AutoWidth()
														.MaxWidth(250)
														.VAlign(VAlign_Center)
														[
															SNew(STextBlock)
															.Text(LOCTEXT("useMemsaving", "Save mem on importing textures & mats"))
														]
													+ SHorizontalBox::Slot()
														.MaxWidth(16)
														.Padding(FMargin(3.0f, 1.0f))
														.VAlign(VAlign_Center)
														[
															SNew(SCheckBox)
															.IsChecked(this, &SHammerSettingsWidget::GetUseMemsave)
														.OnCheckStateChanged(this, &SHammerSettingsWidget::OnMemsaveChanged)
														.ToolTipText(LOCTEXT("MemsavingTooltip", "Check this if you have less than 8 gigs of memory.\r\nIt'll unload as many textures and materials as it can while importing\r\nto try and keep memory usage down.\r\n\r\nNote: When turned on, imported items will be 'invisible' until the next time you restart the engine."))
														]
											]
											+ SVerticalBox::Slot()
												.AutoHeight()
												.Padding(FMargin(3.f, 1.f))
												[
													SNew(SHorizontalBox)
													+ SHorizontalBox::Slot()
													.AutoWidth()
													.MaxWidth(250)
													.VAlign(VAlign_Center)
													[
														SNew(STextBlock)
														.Text(LOCTEXT("Import_DefaultAlpha", "Default channel for displacement alpha: "))
														.ToolTipText(LOCTEXT("importDisplacementalphatooltip", "Channel you want to use in your blending material as alpha map to blend two textures."))
													]
											
													+ SHorizontalBox::Slot()
													.Padding(FMargin(3.f, 1.f))
														.MaxWidth(200)
													[
														SNew(SHorizontalBox)
														+ SHorizontalBox::Slot()
														.MaxWidth(50)
														[
															CreateRadioButton(LOCTEXT("Red", "Red"), LOCTEXT("Red_tooltip", "Blending map for material is stored in the red channel of vertex colors"), Radio0)
														]
														+ SHorizontalBox::Slot()
															.MaxWidth(50)
														[
															CreateRadioButton(LOCTEXT("Green", "Green"), LOCTEXT("Green_tooltip", "Blending map for material is stored in the green channel of vertex colors"), Radio1)
														]
														+ SHorizontalBox::Slot()
															.MaxWidth(50)
														[
															CreateRadioButton(LOCTEXT("Blue", "Blue"), LOCTEXT("Blue_tooltip", "Blending map for material is stored in the blue channel of vertex colors"), Radio2)
														]
														+ SHorizontalBox::Slot()
															.MaxWidth(50)
														[
															CreateRadioButton(LOCTEXT("Alpha", "Alpha"), LOCTEXT("Alpha_tooltip", "Blending map for material is stored in the alpha channel of vertex colors"), Radio3)
														]
													]
												]
											+ SVerticalBox::Slot()
												.Padding(FMargin(3.f, 1.f))
												.AutoHeight()
												[
													SNew(SHorizontalBox)
													+ SHorizontalBox::Slot()
													.AutoWidth()
													.MaxWidth(250)
													.VAlign(VAlign_Center)
													[
														SNew(STextBlock)
														.Text(LOCTEXT("Import_HL1Alpha", "Masking color when importing HL1 textures: "))
													]
													+ SHorizontalBox::Slot()
													.AutoWidth()
													.MaxWidth(250)
													.VAlign(VAlign_Center)
													[
														SNew(SButton)
														.OnClicked(this, &SHammerSettingsWidget::HandleHL1Clicked)
														.IsEnabled(true)
														.Text(LOCTEXT("HL1eButtonText", "Choose color"))
													]
													+ SHorizontalBox::Slot()
														.AutoWidth()
														.MaxWidth(50)
														.Padding(3.0f, 1.0f)
														.VAlign(VAlign_Center)
														[
															SNew(SColorBlock)
															.Color(this, &SHammerSettingsWidget::GetHL1Color)
														.IsEnabled(true)
														]
												]
											//
											+ SVerticalBox::Slot()
												[
													SNew(SSeparator)//SSpacer)
												]
											+ SVerticalBox::Slot()
												.AutoHeight()
												.Padding(FMargin(3.f, 1.f))
												[
													SNew(SHorizontalBox)
													+ SHorizontalBox::Slot()
													.AutoWidth()
													.MaxWidth(250)
													.VAlign(VAlign_Center)
													[
														SNew(STextBlock)
														.Text(LOCTEXT("unknownmodels", "Generate placeholders for unknown models"))
													]
													+ SHorizontalBox::Slot()
													.AutoWidth()
													.Padding(FMargin(3.f, 1.f))
													.MaxWidth(20)
													.VAlign(VAlign_Center)
													[
														SNew(SCheckBox)
														.IsChecked(this, &SHammerSettingsWidget::GetUnknownModels)
														.OnCheckStateChanged(this, &SHammerSettingsWidget::SetUnknownModels)
														.ToolTipText(LOCTEXT("unknownmodelstooltip", "Generates temporary meshes for all unknown models the maps try to import."))
													]
													+ SHorizontalBox::Slot()
														.AutoWidth()
														.Padding(FMargin(3.f, 1.f))
														.MaxWidth(250)
														.VAlign(VAlign_Center)
														[
															SNew(STextBlock)
															.Text(LOCTEXT("Unknown_Scale", " Scale: "))
														]
													+ SHorizontalBox::Slot()
													.MaxWidth(50)
													.VAlign(VAlign_Center)
													[
														SNew(SNumericEntryBox<float>)
														.Delta(0.001f)
														.MinValue(0.01f)
														.MaxValue(50.0f)
														.AllowSpin(false)
														.Value(this, &SHammerSettingsWidget::GetUnknownScaleRate)
														.OnValueChanged(this, &SHammerSettingsWidget::SetUnknownScaleRate)
														.ToolTipText(LOCTEXT("unknown_scale_tooltip", "Scale to use for the unknown model question marks. Too small? Increase the scale. Too big? decrease the scale."))
													]
												]
												+ SVerticalBox::Slot()
												.AutoHeight()
												.Padding(FMargin(3.f, 1.f))
												[
													SNew(SHorizontalBox)
													+ SHorizontalBox::Slot()
													.AutoWidth()
													.MaxWidth(120)
													.Padding(FMargin(0.f, 1.f))
													.VAlign(VAlign_Center)
													[
														SNew(STextBlock)
														.Text(LOCTEXT("generateThumbs", "Generate thumbnails"))
													]
													+ SHorizontalBox::Slot()
														.AutoWidth()
														.Padding(FMargin(3.f, 1.f))
														.MaxWidth(20)
														.VAlign(VAlign_Center)
														[
															SNew(SCheckBox)
															.IsChecked(this, &SHammerSettingsWidget::GetGenerateThumbs)
														.OnCheckStateChanged(this, &SHammerSettingsWidget::SetGenerateThumbs)
														.ToolTipText(LOCTEXT("generateThumbsTooltip", "Generates thumbnails for textures, materials and meshes.\r\nWARNING: There is currently a huge memory leak in the Unreal Editor.\r\nCheck UE-34672 on the UE issues page before turning this on."))
													]
													+ SHorizontalBox::Slot()
														.AutoWidth()
														.MaxWidth(154)
														.Padding(FMargin(3.f, 1.f))
														.VAlign(VAlign_Center)
														[
															SNew(STextBlock)
															.Text(LOCTEXT("MatPremissive", "Relax ungenerated materials"))
														]
													+ SHorizontalBox::Slot()
														.AutoWidth()
														.Padding(FMargin(3.f, 1.f))
														.MaxWidth(20)
														.VAlign(VAlign_Center)
														[
															SNew(SCheckBox)
															.IsChecked(this, &SHammerSettingsWidget::GetGeneratePermissive)
														.OnCheckStateChanged(this, &SHammerSettingsWidget::SetGeneratePermissive)
														.ToolTipText(LOCTEXT("MatPermissiveTooltip", "When generating materials for unused textures, relax the rules."))
														]
													+ SHorizontalBox::Slot()
														.AutoWidth()
														.MaxWidth(154)
														.Padding(FMargin(3.f, 1.f))
														.VAlign(VAlign_Center)
														[
															SNew(STextBlock)
															.Text(LOCTEXT("OverlapBrushes", "Generate overlap events"))
														]
													+ SHorizontalBox::Slot()
														.AutoWidth()
														.Padding(FMargin(3.f, 1.f))
														.MaxWidth(20)
														.VAlign(VAlign_Center)
														[
															SNew(SCheckBox)
															.IsChecked(this, &SHammerSettingsWidget::GetOverlapEvents)
														.OnCheckStateChanged(this, &SHammerSettingsWidget::SetOverlapEvents)
														.ToolTipText(LOCTEXT("OverlapBrushesTooltip", "Set brushes to 'generate overlap events'."))
														]
												]
											+ SVerticalBox::Slot()
												.AutoHeight()
												.Padding(FMargin(3.f, 1.f))
												[
													SNew(SHorizontalBox)
													+ SHorizontalBox::Slot()
												.AutoWidth()
												.MaxWidth(300)
												.VAlign(VAlign_Center)
												[
													SNew(STextBlock)
													.Text(LOCTEXT("replaceReimport", "Remove brush meshes that no longer exist on reimport"))
												]
											+ SHorizontalBox::Slot()
												.AutoWidth()
												.Padding(FMargin(3.f, 1.f))
												.MaxWidth(20)
												.VAlign(VAlign_Center)
												[
													SNew(SCheckBox)
													.IsChecked(this, &SHammerSettingsWidget::GetReimportCleanup)
												.OnCheckStateChanged(this, &SHammerSettingsWidget::OnReimportCleanupChanged)
												.ToolTipText(LOCTEXT("replaceReimporttooltip", "When importing a map into a level, deletes all actors from the level that weren't reimported."))
												]
											]
											+ SVerticalBox::Slot()
												[
													SNew(SSeparator)//SSpacer)
												]
											+ SVerticalBox::Slot()
												.AutoHeight()
												.Padding(FMargin(3.f, 1.f))
												[
													SNew(SHorizontalBox)
													+ SHorizontalBox::Slot()
													.AutoWidth()
													.VAlign(VAlign_Center)
													[
														SNew(SBox)
														.WidthOverride(220)
														[
															SNew(STextBlock)
															.Text(LOCTEXT("verbosedebug","Verbose debug messages to output log"))
														]
													]
													+ SHorizontalBox::Slot()
													.AutoWidth()
													.Padding(FMargin(3.f, 1.f))
													.VAlign(VAlign_Center)
													[
														SNew(SBox)
														.WidthOverride(26)
														[
															SNew(SCheckBox)
															.IsChecked(this, &SHammerSettingsWidget::GetVerboseCheckedActive)
															.OnCheckStateChanged(this, &SHammerSettingsWidget::OnVerboseCheckboxChanged)
															.ToolTipText(LOCTEXT("verbosetooltip","Logs verbose information to the output log.\r\nThis has a performance impact."))
														]
													]
													+ SHorizontalBox::Slot()
													.AutoWidth()
													[
														SNew(SBox)
														[
															SNew(SHorizontalBox)
															+SHorizontalBox::Slot()
															.VAlign(VAlign_Center)
															[
																SNew(SBox)
																[
																	SNew(STextBlock)
																	.Text(LOCTEXT("SVNsetting","SVN-able config"))
																]
															]
															+ SHorizontalBox::Slot()
															[
																SNew(SBox)
																[
																	SNew(SCheckBox)
																	.IsChecked(this, &SHammerSettingsWidget::GetSVNActive)
																	.OnCheckStateChanged(this, &SHammerSettingsWidget::OnSVNChanged)
																	.ToolTipText(LOCTEXT("SVNtooltip", "Creates a secondary, shared config file for the base settings that will override the normal config file."))
																]
														]
														]
													]
													+ SHorizontalBox::Slot()
														.AutoWidth()
														.MaxWidth(250)
														.VAlign(VAlign_Center)
														[
															SNew(STextBlock)
															.Text(LOCTEXT("prependdebug", "Prepend all actors with level name"))
														]
													+ SHorizontalBox::Slot()
														.AutoWidth()
														.Padding(FMargin(3.f, 1.f))
														.MaxWidth(20)
														.VAlign(VAlign_Center)
														[
															SNew(SCheckBox)
															.IsChecked(this, &SHammerSettingsWidget::GetPrependCheckedActive)
														.OnCheckStateChanged(this, &SHammerSettingsWidget::OnPrependCheckboxChanged)
														.ToolTipText(LOCTEXT("prependtooltip", "Prepends every actor name with the imported level name."))
														]
													+ SHorizontalBox::Slot()
														.HAlign(HAlign_Right)
														.Padding(3.0f, 1.0f)
														[
															SNew(SBox)
															.WidthOverride(100)
															[
																SNew(SButton)
																.OnClicked(this, &SHammerSettingsWidget::SaveSettings)
																.IsEnabled(true)
																.HAlign(HAlign_Center)
																.VAlign(VAlign_Center)
																.Text(LOCTEXT("SaveButtonText", "Save settings"))
															]
														]
												]
										]
									]
								+ SVerticalBox::Slot()
									.AutoHeight()
									[
										SNew(SHeader)
										.Content()
										[
											SNew(STextBlock)
											.Text(LOCTEXT("sessionsettings","Session specific settings"))
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
											.Padding(FMargin(3.0f, 1.0f))
											[
												SNew(SHorizontalBox)
												+ SHorizontalBox::Slot()
												.AutoWidth()
												[
													SNew(SBox)
													.WidthOverride(450)
													[
														SNew(SHorizontalBox)
														+ SHorizontalBox::Slot()
														.AutoWidth()
														.Padding(FMargin(3.0f, 1.0f))
														.VAlign(VAlign_Center)
														[
															SNew(STextBlock)
															.Text(LOCTEXT("Ignore_rotations", "Ignore rotations when placing models"))
															.ToolTipText(LOCTEXT("ignoreRotationsTooltip", "This is one of those toggles you probably won't need, but since the rotation stuff is kinda hacky,\r\nsometimes you might want to just ignore one of these, possibly pitch."))
														]
														+ SHorizontalBox::Slot()
														.MaxWidth(20)
														.AutoWidth()
														[
															SNew(SCheckBox)
															.IsChecked(this, &SHammerSettingsWidget::GetIgnorePitch)
															.OnCheckStateChanged(this, &SHammerSettingsWidget::SetIgnorePitch)
															.ToolTipText(LOCTEXT("ignorePitchTooltip", "Ignore Pitch"))
														]
														+ SHorizontalBox::Slot()
														.MaxWidth(20)
														.AutoWidth()
														[
															SNew(SCheckBox)
															.IsChecked(this, &SHammerSettingsWidget::GetIgnoreRoll)
															.OnCheckStateChanged(this, &SHammerSettingsWidget::SetIgnoreRoll)
															.ToolTipText(LOCTEXT("ignoreRollTooltip", "Ignore Roll"))
														]
														+ SHorizontalBox::Slot()
														.MaxWidth(20)
														.AutoWidth()
														[
															SNew(SCheckBox)
															.IsChecked(this, &SHammerSettingsWidget::GetIgnoreYaw)
															.OnCheckStateChanged(this, &SHammerSettingsWidget::SetIgnoreYaw)
															.ToolTipText(LOCTEXT("ignoreYawTooltip", "Ignore Yaw"))
														]
														+ SHorizontalBox::Slot()
														.MaxWidth(30)
															.AutoWidth()
															.Padding(FMargin(3.0f, 1.0f))
															.VAlign(VAlign_Center)
															[
																SNew(STextBlock)
																.Text(LOCTEXT("Empty",""))
															]
														+SHorizontalBox::Slot()
															.MaxWidth(150)
															.AutoWidth()
															.Padding(FMargin(3.0f, 1.0f))
															.VAlign(VAlign_Center)
															[
																SNew(STextBlock)
																.Text(LOCTEXT("checkDegenerate","Check for degenerate tris"))
															]
														+ SHorizontalBox::Slot()
															.MaxWidth(20)
															.AutoWidth()
															[
																SNew(SCheckBox)
																.IsChecked(this, &SHammerSettingsWidget::GetDegenerate)
															.OnCheckStateChanged(this, &SHammerSettingsWidget::SetDegenerate)
															.ToolTipText(LOCTEXT("checkDegenerateTooltip", "Additional check for degenerate triangles before passing them to UE.\r\nShouldn't usually need this."))
															]
													]
												]
												+SHorizontalBox::Slot()
												.AutoWidth()
												.VAlign(VAlign_Center)
												[
													SNew(STextBlock)
													.Text(LOCTEXT("DoIgnoreLabel", " Ignore tagged "))
												]
												+ SHorizontalBox::Slot()
												.AutoWidth()
												[
													SNew(SBox)
													.WidthOverride(20)
													[
														SNew(SCheckBox)
														.IsChecked(this, &SHammerSettingsWidget::GetIgnoreActors)
														.OnCheckStateChanged(this, &SHammerSettingsWidget::SetIgnoreActors)
														.ToolTipText(LOCTEXT("ignoreIgnoreActorsTooltip","When checked, ignores actors tagged to be ignored"))
													]
												]
												+ SHorizontalBox::Slot()
												.AutoWidth()
												[
													SNew(SBox)
													.WidthOverride(35)
													[
														SNew(SButton)
														.OnClicked(this, &SHammerSettingsWidget::TagSelectedAsIgnore)
														.IsEnabled(true)
														.HAlign(HAlign_Center)
														.VAlign(VAlign_Center)
														.Text(LOCTEXT("TagIgnoreSelectedMeshes", "Tag"))
														.ToolTipText(LOCTEXT("TagIgnoreSelectedTooltip", "Tags current selection to ignore"))
													]
												]
												+ SHorizontalBox::Slot()
												.AutoWidth()
												[
													SNew(SBox)
													.WidthOverride(45)
													[
														SNew(SButton)
														.OnClicked(this, &SHammerSettingsWidget::UntagSelected)
														.IsEnabled(true)
														.HAlign(HAlign_Center)
														.VAlign(VAlign_Center)
														.Text(LOCTEXT("UntagSelected", "Untag"))
														.ToolTipText(LOCTEXT("UnTagIgnoreSelectedTooltip", "Untags current selection"))
													]
												]

											]
									+ SVerticalBox::Slot()
									.AutoHeight()
									.Padding(FMargin(3.f, 1.f))
									[
										SNew(SHorizontalBox)
										+ SHorizontalBox::Slot()
										.AutoWidth()
										.VAlign(VAlign_Center)
										[
											SNew(STextBlock)
											.Text(LOCTEXT("Import_smallerlist", "Load only (brushes & groups): "))
										]
										+ SHorizontalBox::Slot()
										.VAlign(VAlign_Center)
										[
											SNew(SEditableTextBox)
											.BackgroundColor(FSlateColor(FLinearColor(FColor::White)))
											.OnTextCommitted(this, &SHammerSettingsWidget::OnImportListChanged)
											.Text(this, &SHammerSettingsWidget::GetImportList)
											.ToolTipText(LOCTEXT("smallerlisttooltip","Comma separated list of brushes or groups"))
										]
										+ SHorizontalBox::Slot()
										.VAlign(VAlign_Center)
										.MaxWidth(100)
										[
											SNew(SButton)
											.OnClicked(this, &SHammerSettingsWidget::GetSelectedOnes)
											.IsEnabled(true)
											.HAlign(HAlign_Center)
											.VAlign(VAlign_Center)
											.Text(LOCTEXT("GetSelection1", "Get Selection"))
											.ToolTipText(LOCTEXT("GetSelectiontooltip", "Grab all brush meshes from selection."))
										]
									]
								+ SVerticalBox::Slot()
								.AutoHeight()
								.Padding(FMargin(3.f, 1.f))
								[
									SNew(SHorizontalBox)
									+ SHorizontalBox::Slot()
									.AutoWidth()
									.VAlign(VAlign_Center)
									[
										SNew(STextBlock)
										.Text(LOCTEXT("Import_smallerlistEntity", "Load only (entities): "))
									]
								+ SHorizontalBox::Slot()
									.VAlign(VAlign_Center)
									[
										SNew(SEditableTextBox)
										.BackgroundColor(FSlateColor(FLinearColor(FColor::White)))
									.OnTextCommitted(this, &SHammerSettingsWidget::OnImportEntityListChanged)
									.Text(this, &SHammerSettingsWidget::GetImportEntityList)
									.ToolTipText(LOCTEXT("smallerlistEntitytooltip", "Comma separated list of entities"))
									]
								+ SHorizontalBox::Slot()
									.VAlign(VAlign_Center)
									.MaxWidth(100)
									[
										SNew(SButton)
										.OnClicked(this, &SHammerSettingsWidget::GetSelectedEntitiesOnes)
										.IsEnabled(true)
										.HAlign(HAlign_Center)
										.VAlign(VAlign_Center)
										.Text(LOCTEXT("GetSelection2", "Get Selection"))
										.ToolTipText(LOCTEXT("GetSelection2tooltip", "Grab all entity meshes from selection."))
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

TOptional<float> SHammerSettingsWidget::GetSmoothAngle() const
{
	return HammUErSettings::smoothingAngle;
}

void SHammerSettingsWidget::SetSmoothAngle(const float inRate)
{
	HammUErSettings::smoothingAngle = FMath::ClampAngle(inRate, 0, 180);
}

TOptional<float> SHammerSettingsWidget::GetUnknownScaleRate() const
{
	return HammUErSettings::scaleUnknownModels;
}

void SHammerSettingsWidget::SetUnknownScaleRate(float inRate) const
{
	HammUErSettings::scaleUnknownModels = inRate;
}

TOptional<float> SHammerSettingsWidget::GetConversionRate() const
{
	return HammUErSettings::localConversionRate;
}

void SHammerSettingsWidget::SetConversionRate(float inRate) const
{
	HammUErSettings::localConversionRate = inRate;
}

TOptional<float> SHammerSettingsWidget::GetLightFactor() const
{
	return HammUErSettings::lightFactor;
}

void SHammerSettingsWidget::SetLightFactor(const float inRate)
{
	HammUErSettings::lightFactor = inRate;
}

TOptional<int32> SHammerSettingsWidget::GetDefaultWidth() const
{
	return HammUErSettings::defaultWidth;
}

void SHammerSettingsWidget::SetDefaultWidth(const int32 inRate)
{
	HammUErSettings::defaultWidth = inRate;
}

TOptional<int32> SHammerSettingsWidget::GetDefaultHeight() const
{
	return HammUErSettings::defaultHeight;
}

void SHammerSettingsWidget::SetDefaultHeight(const int32 inRate)
{
	HammUErSettings::defaultHeight = inRate;
}

TOptional<int32> SHammerSettingsWidget::GetPatchH() const
{
	return HammUErSettings::patchSubDivH;
}

void SHammerSettingsWidget::SetPatchH(const int32 inRate)
{
	HammUErSettings::patchSubDivH = inRate;
}

TOptional<int32> SHammerSettingsWidget::GetPatchV() const
{
	return HammUErSettings::patchSubDivV;
}

void SHammerSettingsWidget::SetPatchV(const int32 inRate)
{
	HammUErSettings::patchSubDivV = inRate;
}

TOptional<float> SHammerSettingsWidget::GetLightmapSize() const
{
	return HammUErSettings::LightmapPrecision;
}

void SHammerSettingsWidget::SetLightmapSize(const float inRate)
{
	HammUErSettings::LightmapPrecision = inRate;
}

TOptional<float> SHammerSettingsWidget::GetErrorMargin() const
{
	return HammUErSettings::discardErrorRange;
}

void SHammerSettingsWidget::SetErrorMargin(const float inRate)
{
	HammUErSettings::discardErrorRange = inRate;
}

TOptional<float> SHammerSettingsWidget::GetWeldMargin() const
{
	return HammUErSettings::smoothWeldRange;
}

void SHammerSettingsWidget::SetWeldMargin(const float inRate)
{
	HammUErSettings::smoothWeldRange = inRate;
}


TOptional<float> SHammerSettingsWidget::GetIntersectMargin() const
{
	float value = 1.0f / HammUErSettings::intersectRange;
	value = pow(10.f,(float)FMath::CeilToInt(FMath::LogX(10.f, value)));
	return value;
}

void SHammerSettingsWidget::SetIntersectMargin(const float inRate)
{
	float value = pow(10.f, (float)FMath::CeilToInt(FMath::LogX(10.f, inRate)));
	HammUErSettings::intersectRange = 1.0f / value;
}

void SHammerSettingsWidget::OnImportListChanged(const FText& InLabel, ETextCommit::Type TextType)
{
	if (TextType == ETextCommit::OnEnter || TextType == ETextCommit::Default || TextType == ETextCommit::OnUserMovedFocus)
	{
		FString newList = InLabel.ToString();
		FString temp;
		int32 pos;
		newList.TrimStartInline();
		newList.TrimEndInline();
		HammUErSettings::reducedImportList.Empty();
		while (newList.Len() > 0)
		{
			pos = newList.Find(",");
			if (pos == -1)
				pos = newList.Len();
			temp = newList.Mid(0, pos);
			temp.TrimEndInline();
			int32 found = FCString::Atoi(*temp);
			HammUErSettings::reducedImportList.Add(found);
			newList.RemoveAt(0, pos + 1);
		}
	}
}

FText SHammerSettingsWidget::GetImportList() const
{
	FString result = "";
	for (int i = 0; i < HammUErSettings::reducedImportList.Num(); i++)
		result += (FString::FromInt(HammUErSettings::reducedImportList[i]) + (i == HammUErSettings::reducedImportList.Num() - 1 ? "" : ","));
	return FText::FromString(result);
}

void SHammerSettingsWidget::OnImportEntityListChanged(const FText& InLabel, ETextCommit::Type TextType)
{
	if (TextType == ETextCommit::OnEnter || TextType == ETextCommit::Default || TextType == ETextCommit::OnUserMovedFocus)
	{
		FString newList = InLabel.ToString();
		FString temp;
		int32 pos;
		newList.TrimStartInline();
		newList.TrimEndInline();
		HammUErSettings::reducedImportEntityList.Empty();
		while (newList.Len() > 0)
		{
			pos = newList.Find(",");
			if (pos == -1)
				pos = newList.Len();
			temp = newList.Mid(0, pos);
			temp.TrimEndInline();
			int32 found = FCString::Atoi(*temp);
			HammUErSettings::reducedImportEntityList.Add(found);
			newList.RemoveAt(0, pos + 1);
		}
	}
}

FText SHammerSettingsWidget::GetImportEntityList() const
{
	FString result = "";
	for (int i = 0; i < HammUErSettings::reducedImportEntityList.Num(); i++)
		result += (FString::FromInt(HammUErSettings::reducedImportEntityList[i]) + (i == HammUErSettings::reducedImportEntityList.Num() - 1 ? "" : ","));
	return FText::FromString(result);
}


#undef LOCTEXT_NAMESPACE