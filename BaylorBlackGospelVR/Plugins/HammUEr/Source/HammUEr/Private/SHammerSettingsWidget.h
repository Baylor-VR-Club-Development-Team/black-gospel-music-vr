// HammUEr
// Copyright 2015-2016 Turfster / NT Entertainment
// All Rights Reserved.


// This code is held together with kitten whiskers and toothpicks.
// There's nothing to see or learn here.
// Seriously.
// Turn back.

#pragma once

#include "HammUErPrivatePCH.h"
#include "HammUEr.h"
#include "SDockTab.h"
#include "SlateBasics.h"
#include "SlateExtras.h"
#include "HammUErSettings.h"
#include "SColorPicker.h"
/**
 * 
 */
class SHammerSettingsWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SHammerSettingsWidget)
	{}
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);


	enum ERadioChoice
	{
		Radio0,
		Radio1,
		Radio2,
		Radio3,
		ScaleRadio0,
		ScaleRadio1,
		ScaleRadio2
	};


private:

	// settings page code
	ECheckBoxState GetDebugCheckedActive() const
	{
		return HammUErSettings::DebugCheckboxEnabled ? ECheckBoxState::Checked : ECheckBoxState::Unchecked;
	}

	void OnDebugCheckboxChanged(ECheckBoxState NewState)
	{
		HammUErSettings::DebugCheckboxEnabled = (NewState == ECheckBoxState::Checked);
	}

	ECheckBoxState GetNoSmoothActive() const
	{
		return HammUErSettings::doNotUseSmoother ? ECheckBoxState::Checked : ECheckBoxState::Unchecked;
	}

	void OnNoSmoothChanged(ECheckBoxState NewState)
	{
		HammUErSettings::doNotUseSmoother = (NewState == ECheckBoxState::Checked);
	}


	ECheckBoxState GetTextureAlpha() const
	{
		return HammUErSettings::useTextureAlpha ? ECheckBoxState::Checked : ECheckBoxState::Unchecked;
	}

	void OnTextureAlphaChanged(ECheckBoxState NewState)
	{
		HammUErSettings::useTextureAlpha = (NewState == ECheckBoxState::Checked);
	}

	ECheckBoxState GetUseMemsave() const
	{
		return HammUErSettings::doUnload ? ECheckBoxState::Checked : ECheckBoxState::Unchecked;
	}

	void OnMemsaveChanged(ECheckBoxState NewState)
	{
		HammUErSettings::doUnload = (NewState == ECheckBoxState::Checked);
	}

	ECheckBoxState GetTwoSidedActive() const
	{
		return HammUErSettings::twoSidedCull ? ECheckBoxState::Checked : ECheckBoxState::Unchecked;
	}

	void OnTwoSidedChanged(ECheckBoxState NewState)
	{
		HammUErSettings::twoSidedCull = (NewState == ECheckBoxState::Checked);
	}

	// import changer
	TOptional<float>  GetImportX() const
	{
		return HammUErSettings::importOffset.X;
	}

	TOptional<float>  GetImportY() const
	{
		return HammUErSettings::importOffset.Y;
	}

	TOptional<float>  GetImportZ() const
	{
		return HammUErSettings::importOffset.Z;
	}

	void OnSetImportLocation(float InValue, ETextCommit::Type CommitType, int32 inAxis)
	{
		switch (inAxis)
		{
		case 0:
			HammUErSettings::importOffset.X = InValue;
			break;
		case 1:
			HammUErSettings::importOffset.Y = InValue;
			break;
		case 2:
			HammUErSettings::importOffset.Z = InValue;
			break;
		}
	}

	void OnNonZeroCheckboxChanged(ECheckBoxState NewState)
	{
		HammUErSettings::importNonZero = (NewState == ECheckBoxState::Checked);
	}

	ECheckBoxState GetNonZeroChecked() const
	{
		return HammUErSettings::importNonZero ? ECheckBoxState::Checked : ECheckBoxState::Unchecked;
	}

	TOptional<float> GetImportRoll() const
	{
		return HammUErSettings::importRotationValue.X;
	}

	TOptional<float> GetImportPitch() const
	{
		return HammUErSettings::importRotationValue.Y;
	}

	TOptional<float> GetImportYaw() const
	{
		return HammUErSettings::importRotationValue.Z;
	}

	void OnSetImportRotation(float InValue, ETextCommit::Type CommitType, int32 inAxis)
	{
		switch (inAxis)
		{
		case 0:
			HammUErSettings::importRotationValue.X = InValue;
			break;
		case 1:
			HammUErSettings::importRotationValue.Y = InValue;
			break;
		case 2:
			HammUErSettings::importRotationValue.Z = InValue;
			break;
		}
	}

	void OnRotateCheckboxChanged(ECheckBoxState NewState)
	{
		HammUErSettings::importRotation = (NewState == ECheckBoxState::Checked);
	}

	ECheckBoxState GetRotateChecked() const
	{
		return HammUErSettings::importRotation ? ECheckBoxState::Checked : ECheckBoxState::Unchecked;
	}

	// other settings
	ECheckBoxState GetVMFList() const
	{
		return HammUErSettings::generateVMFList ? ECheckBoxState::Unchecked : ECheckBoxState::Checked;
	}

	void OnVMFListChanged(ECheckBoxState NewState)
	{
		HammUErSettings::generateVMFList = (NewState == ECheckBoxState::Unchecked);
	}

	ECheckBoxState GetCenterCheckedActive() const
	{
		return HammUErSettings::CenterCheckboxEnabled ? ECheckBoxState::Checked : ECheckBoxState::Unchecked;
	}

	void OnCenterCheckboxChanged(ECheckBoxState NewState)
	{
		HammUErSettings::CenterCheckboxEnabled = (NewState == ECheckBoxState::Checked);
	}

	ECheckBoxState GetVerboseCheckedActive() const
	{
		return HammUErSettings::verboseDebugEnabled ? ECheckBoxState::Checked : ECheckBoxState::Unchecked;
	}

	void OnVerboseCheckboxChanged(ECheckBoxState NewState)
	{
		HammUErSettings::verboseDebugEnabled = (NewState == ECheckBoxState::Checked);
	}

	ECheckBoxState GetSVNActive() const
	{
		return HammUErSettings::saveSVN ? ECheckBoxState::Checked : ECheckBoxState::Unchecked;
	}

	void OnSVNChanged(ECheckBoxState NewState)
	{
		HammUErSettings::saveSVN = (NewState == ECheckBoxState::Checked);
	}


	ECheckBoxState GetPrependCheckedActive() const
	{
		return HammUErSettings::alwaysPrependFilename ? ECheckBoxState::Checked : ECheckBoxState::Unchecked;
	}

	void OnPrependCheckboxChanged(ECheckBoxState NewState)
	{
		HammUErSettings::alwaysPrependFilename = (NewState == ECheckBoxState::Checked);
	}

	ECheckBoxState GetRoundPoints() const
	{
		return HammUErSettings::roundPoints ? ECheckBoxState::Checked : ECheckBoxState::Unchecked;
	}

	void OnRoundPointsChanged(ECheckBoxState NewState)
	{
		HammUErSettings::roundPoints = (NewState == ECheckBoxState::Checked);
	}

	ECheckBoxState GetRoundPointsMesh() const
	{
		return HammUErSettings::roundMeshPoints ? ECheckBoxState::Checked : ECheckBoxState::Unchecked;
	}

	void OnRoundPointsMeshChanged(ECheckBoxState NewState)
	{
		HammUErSettings::roundMeshPoints = (NewState == ECheckBoxState::Checked);
	}

	ECheckBoxState GetRoundDisplacementPoints() const
	{
		return HammUErSettings::roundDisplacementPoints ? ECheckBoxState::Checked : ECheckBoxState::Unchecked;
	}

	void OnRoundDisplacementPointsChanged(ECheckBoxState NewState)
	{
		HammUErSettings::roundDisplacementPoints = (NewState == ECheckBoxState::Checked);
	}


	ECheckBoxState GetReimportCleanup() const
	{
		return HammUErSettings::reimportCleanup ? ECheckBoxState::Checked : ECheckBoxState::Unchecked;
	}

	void OnReimportCleanupChanged(ECheckBoxState NewState)
	{
		HammUErSettings::reimportCleanup = (NewState == ECheckBoxState::Checked);
	}



	ECheckBoxState GetIgnoreActors() const
	{
		return HammUErSettings::checkIgnore ? ECheckBoxState::Checked : ECheckBoxState::Unchecked;
	}

	void SetIgnoreActors(ECheckBoxState NewState)
	{
		HammUErSettings::checkIgnore = (NewState == ECheckBoxState::Checked);
	}



	FReply TagSelectedAsIgnore()
	{
		USelection* selected = GEditor->GetSelectedActors();
		for (int i = 0; i < selected->Num(); i++)
			((AActor*)selected->GetSelectedObject(i))->Tags.AddUnique(FName(*FString("HammUErIgnoreOnImport")));
		return FReply::Handled();
	}


	FReply UntagSelected()
	{
		USelection* selected = GEditor->GetSelectedActors();
		for (int i = 0; i < selected->Num(); i++)
			((AActor*)selected->GetSelectedObject(i))->Tags.Remove(FName(*FString("HammUErIgnoreOnImport")));
		return FReply::Handled();
	}


	FReply GetSelectedOnes()
	{
		USelection* selected = GEditor->GetSelectedActors();
		for (int i = 0; i < selected->Num(); i++)
		{
			FString name = selected->GetSelectedObject(i)->GetName();
			int index = FCString::Atoi(*name.Mid(name.Find("_", ESearchCase::IgnoreCase, ESearchDir::FromEnd)+1, name.Len()));
			if (name.Contains("_singlemesh_") || name.Contains("_groupmesh_") || name.Contains("_entity_mesh_")) // temporary, but since they're still uncoupled...
				HammUErSettings::reducedImportList.AddUnique(index);
		}
		HammUErSettings::reducedImportList.Sort();
		return FReply::Handled();
	}

	FReply GetSelectedEntitiesOnes()
	{
		USelection* selected = GEditor->GetSelectedActors();
		for (int i = 0; i < selected->Num(); i++)
		{
			if (((AActor*)selected->GetSelectedObject(i))->Tags.Num()>0)
			{
				FString name = ((AActor*)selected->GetSelectedObject(i))->Tags[0].ToString();
				int index = FCString::Atoi(*name.Mid(name.Find("_", ESearchCase::IgnoreCase, ESearchDir::FromEnd) + 1, name.Len()));
				if (name.StartsWith("Entity_"))
					HammUErSettings::reducedImportEntityList.AddUnique(index);
			}
		}
		HammUErSettings::reducedImportEntityList.Sort();
		return FReply::Handled();
	}
	
	// radio button 
	// Holds the current choice in the SCheckBox (as radio button) example.
	ERadioChoice RadioChoice;

	ECheckBoxState HandleRadioButtonIsChecked(ERadioChoice ButtonId) const
	{
		if ((int)ButtonId > 3)
		{
			return (HammUErSettings::propScaleType == (int)ButtonId-4)
				? ECheckBoxState::Checked
				: ECheckBoxState::Unchecked;
		}
		else
		return (HammUErSettings::defaultDisplacementAlphaChannel == (int)ButtonId)
			? ECheckBoxState::Checked
			: ECheckBoxState::Unchecked;
	}

	FReply SaveSettings()
	{
		FNotificationInfo Info(FText::FromString("Saving settings. This might take some time."));
		Info.bUseThrobber = true;
		Info.ExpireDuration = 3.0f;
		FSlateNotificationManager::Get().AddNotification(Info);
		FSlateNotificationManager::Get().Tick();
	
		HammUErSettings::LoadConfig(true);
		Info.ExpireDuration = 3.0f;
		HammUErSettings::SaveConfig();

		return FReply::Handled();
	}

	FReply HandleHL1Clicked()
	{
		TArray<FColor*> FColorArray;
		FColorArray.Add(&HammUErSettings::halfLifeAlphaColor);
		FColorPickerArgs PickerArgs;
		PickerArgs.DisplayGamma = TAttribute<float>::Create(TAttribute<float>::FGetter::CreateUObject(GEngine, &UEngine::GetDisplayGamma));
		PickerArgs.ColorArray = &FColorArray;

		OpenColorPicker(PickerArgs);
		HammUErSettings::halfLifeAlphaColor = *FColorArray[0];
		return FReply::Handled();
	}

	FLinearColor GetHL1Color() const
	{
		return (FLinearColor)HammUErSettings::halfLifeAlphaColor;
	}

	void HandleRadioButtonCheckStateChanged(ECheckBoxState NewRadioState, ERadioChoice RadioThatChanged)
	{
		if (NewRadioState == ECheckBoxState::Checked)
		{
			//RadioChoice = RadioThatChanged;
			if ((int)RadioThatChanged > 3)
			{
				HammUErSettings::propScaleType = (int)RadioThatChanged - 4;
			}
			else
			HammUErSettings::defaultDisplacementAlphaChannel = (int)RadioThatChanged;// Choice;
		}
	}

	TSharedRef<SWidget> CreateRadioButton(const FText& RadioText, const FText& RadioTextTooltip, ERadioChoice RadioButtonChoice)
	{
		return SNew(SCheckBox)
			.Style(FCoreStyle::Get(), "RadioButton")
			.ToolTipText(RadioTextTooltip)
			.IsChecked(this, &SHammerSettingsWidget::HandleRadioButtonIsChecked, RadioButtonChoice)
			.OnCheckStateChanged(this, &SHammerSettingsWidget::HandleRadioButtonCheckStateChanged, RadioButtonChoice)
			[
				SNew(STextBlock)
				.Text(RadioText)
				.ToolTipText(RadioTextTooltip)
			];
	}

	void SetUnknownScaleRate(float inRate) const;
	TOptional<float> GetUnknownScaleRate() const;

	void SetSmoothAngle(const float inRate);
	TOptional<float> GetSmoothAngle() const;

	void SetConversionRate(float inRate) const;
	TOptional<float> GetConversionRate() const;

	void SetLightFactor(const float inRate);
	TOptional<float> GetLightFactor() const;

	void SetLightmapSize(const float inRate);
	TOptional<float> GetLightmapSize() const;

	void SetDefaultWidth(const int32 inRate);
	TOptional<int32> GetDefaultWidth() const;

	void SetDefaultHeight(const int32 inRate);
	TOptional<int32> GetDefaultHeight() const;

	void SetPatchH(const int32 inRate);
	TOptional<int32> GetPatchH() const;

	void SetPatchV(const int32 inRate);
	TOptional<int32> GetPatchV() const;

	void OnImportListChanged(const FText& InLabel, ETextCommit::Type TextType);
	FText GetImportList() const;

	void OnImportEntityListChanged(const FText& InLabel, ETextCommit::Type TextType);
	FText GetImportEntityList() const;

	void SetErrorMargin(const float inRate);
	TOptional<float> GetErrorMargin() const;

	void SetIntersectMargin(const float inRate);
	TOptional<float> GetIntersectMargin() const;

	void SetWeldMargin(const float inRate);
	TOptional<float> GetWeldMargin() const;

	// dirty hacks, get your dirty hacks here!
	ECheckBoxState GetIgnorePitch() const
	{
		return HammUErSettings::ignorePitch ? ECheckBoxState::Checked : ECheckBoxState::Unchecked;
	}

	void SetIgnorePitch(ECheckBoxState NewState)
	{
		HammUErSettings::ignorePitch = (NewState == ECheckBoxState::Checked);
	}

	ECheckBoxState GetIgnoreRoll() const
	{
		return HammUErSettings::ignoreRoll ? ECheckBoxState::Checked : ECheckBoxState::Unchecked;
	}

	void SetIgnoreRoll(ECheckBoxState NewState)
	{
		HammUErSettings::ignoreRoll = (NewState == ECheckBoxState::Checked);
	}

	ECheckBoxState GetIgnoreYaw() const
	{
		return HammUErSettings::ignoreYaw ? ECheckBoxState::Checked : ECheckBoxState::Unchecked;
	}

	void SetIgnoreYaw(ECheckBoxState NewState)
	{
		HammUErSettings::ignoreYaw = (NewState == ECheckBoxState::Checked);
	}

	ECheckBoxState GetDegenerate() const
	{
		return HammUErSettings::checkDegenerates ? ECheckBoxState::Checked : ECheckBoxState::Unchecked;
	}

	void SetDegenerate(ECheckBoxState NewState)
	{
		HammUErSettings::checkDegenerates = (NewState == ECheckBoxState::Checked);
	}

	ECheckBoxState GetUnknownModels() const
	{
		return HammUErSettings::placeUnknownModels ? ECheckBoxState::Checked : ECheckBoxState::Unchecked;
	}

	void SetUnknownModels(ECheckBoxState NewState)
	{
		HammUErSettings::placeUnknownModels = (NewState == ECheckBoxState::Checked);
	}

	ECheckBoxState GetGenerateThumbs() const
	{
		return HammUErSettings::generateThumbs ? ECheckBoxState::Checked : ECheckBoxState::Unchecked;
	}

	void SetGenerateThumbs(ECheckBoxState NewState)
	{
		HammUErSettings::generateThumbs = (NewState == ECheckBoxState::Checked);
	}

	ECheckBoxState GetGeneratePermissive() const
	{
		return HammUErSettings::permissiveMaterialCreation ? ECheckBoxState::Checked : ECheckBoxState::Unchecked;
	}

	void SetGeneratePermissive(ECheckBoxState NewState)
	{
		HammUErSettings::permissiveMaterialCreation = (NewState == ECheckBoxState::Checked);
	}

	ECheckBoxState GetOverlapEvents() const
	{
		return HammUErSettings::generateOverlaps ? ECheckBoxState::Checked : ECheckBoxState::Unchecked;
	}

	void SetOverlapEvents(ECheckBoxState NewState)
	{
		HammUErSettings::generateOverlaps = (NewState == ECheckBoxState::Checked);
	}
};
