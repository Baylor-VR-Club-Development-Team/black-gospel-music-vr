// Fill out your copyright notice in the Description page of Project Settings.

#include <vector>

#include "DBXMLFFunctions.h"

DBXMLFFunctions::DBXMLFFunctions()
{
}

DBXMLFFunctions::~DBXMLFFunctions()
{
}

vector<pair<int, string>> DBXMLFFunctions::getSearchableRecordList(string xml) {
	return new vector<pair<int, string>>();
}

RecordData DBXMLFFunctions::getRecordData(string xml) {
	return new RecordData();
}

void DBXMLFFunctions::populateSongAndImageFiles(RecordData& recordData, string xml) {

}
