// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <vector>

#include "CoreMinimal.h"
#include "DBXMLInterpreter.h"
#include "RecordData.h"

using namespace std;

/**
 * 
 */
class BAYLORBLACKGOSPELVR_API DBXMLFFunctions : UDBXMLInterpreter
{
public:
	DBXMLFFunctions();
	~DBXMLFFunctions();

	static vector<pair<int, string>> getSearchableRecordList(string xml);

	static RecordData getRecordData(string xml);

	static void populateSongAndImageFiles(RecordData& recordData, string xml);
};
