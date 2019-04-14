// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <vector>

#include "CoreMinimal.h"
#include "DBXMLInterpreter.h"

using namespace std;

/**
 * 
 */
class BAYLORBLACKGOSPELVR_API DBXMLFFunctions : UDBXMLInterpreter
{
public:
	DBXMLFFunctions();
	~DBXMLFFunctions();

	static vector<pair<int, string>> getSearchableRecordList(string xml) {

	}

	static 
};
