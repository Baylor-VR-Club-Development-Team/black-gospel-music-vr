// HammUEr
// Copyright 2015-2016 Turfster / NT Entertainment
// All Rights Reserved.


// This code is held together with kitten whiskers and toothpicks.
// There's nothing to see or learn here.
// Seriously.
// Turn back.

#pragma once
#include "HammUErPrivatePCH.h"
#include "MAPShared/VMFTri.h"
#include <vector>

class SHammerPropUErWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SHammerPropUErWidget)
	{}
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);

private:

	void ModelDirectoryChanged(const FText& InLabel, ETextCommit::Type TextType);
	FText GetModelImportDirectory() const;

	bool importRunning = false;
	bool CanImport() const;
	bool CanRunGetter() const;
	FReply GetImportDir();
	FReply RunGetter();

	bool createDuplicates = false;
	ECheckBoxState GetDiffNames() const
	{
		if (createDuplicates)
			return ECheckBoxState::Checked;
		else
			return ECheckBoxState::Unchecked;
	}

	void SetDiffNames(ECheckBoxState inState)
	{
		createDuplicates = (inState == ECheckBoxState::Checked);
	}

	bool canRunImport = false;

	EVisibility GetImportVisibility() const;
	void OnSeekNameChanged(const FText& InLabel, ETextCommit::Type TextType);
	FText GetSeekName() const;
	FString seekName;

	TArray<TSharedPtr<FModelListEntry>> modelList;
	TArray<int32> modelListIndex;

	TSharedPtr<SListView<TSharedPtr<FModelListEntry>>> modelListWidget;
	TSharedPtr<SEditableTextBox> importSeekBlock;
	TSharedRef<ITableRow> MakeListViewWidget(TSharedPtr<FModelListEntry> Item, const TSharedRef<STableViewBase>& OwnerTable);

	FReply ToggleSelection();
	FReply SelectAll();
	FReply SelectNone();
	FReply SelectInverse();

	FReply ApplyRotation();
	FReply DoImport();

	FVector bakeRotation = FVector::ZeroVector;

	// settings page code
	TOptional<float>  GetImportRoll() const
	{
		return bakeRotation.X;
	}

	TOptional<float>  GetImportPitch() const
	{
		return bakeRotation.Y;
	}

	TOptional<float>  GetImportYaw() const
	{
		return bakeRotation.Z;
	}

	void OnSetImportRotation(float InValue, ETextCommit::Type CommitType, int32 inAxis)
	{
		switch (inAxis)
		{
		case 0:
			bakeRotation.X = InValue;
			break;
		case 1:
			bakeRotation.Y = InValue;
			break;
		case 2:
			bakeRotation.Z = InValue;
			break;
		}
	}


	ECheckBoxState GetSmoothActive() const
	{
		return HammUErSettings::smoothModelNormals ? ECheckBoxState::Checked : ECheckBoxState::Unchecked;
	}

	void OnSmoothChanged(ECheckBoxState NewState)
	{
		HammUErSettings::smoothModelNormals = (NewState == ECheckBoxState::Checked);
	}


	void BuildRawMesh(std::vector<VMFTri*> triangles, FRawMesh& rawMesh, TArray<int32>& materialReindex);
};