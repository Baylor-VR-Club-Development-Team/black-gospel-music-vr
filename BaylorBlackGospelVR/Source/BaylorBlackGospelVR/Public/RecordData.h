// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <vector>

#include "CoreMinimal.h"

using namespace std;

/**
 * 
 */
class BAYLORBLACKGOSPELVR_API RecordData
{
public:
	string title;
	string altTitle;
	string seriesTitle;
	string artist;
	string performers;
	string level;
	string publisher;
	string originalDate;
	string originalDateSearch;
	string originalFormat;
	string textContributors;
	string composers;
	string directors;
	string producers;
	string otherContributors;
	string recordingStudio;
	string labelNumber;
	string matrixNumber;
	string otherNumber;
	string resourceType;
	string contents;
	string digitalDate;
	string rights;
	string digitalFormat;
	string recordingNotes;
	string note;
	string provenance;
	string subject;
	string collectionTitle;
	string ics_notes;
	string format;
	string custodian;
	string custodialHistory;
	string metadataCreator;
	string giftNote;
	string fullResolution;
	string oclcNumber;
	string dateCreated;
	string dateModified;
	string dmNumber;
	string dmFileName;

	vector<string> imageFiles;
	vector<string> songFilesSide1;
	vector<string> songFilesSide2;

	RecordData();
	~RecordData();
};
