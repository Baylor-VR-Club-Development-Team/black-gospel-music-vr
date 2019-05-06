// HammUEr
// Copyright 2015-2016 Turfster / NT Entertainment
// All Rights Reserved.


// This code is held together with kitten whiskers and toothpicks.
// There's nothing to see or learn here.
// Seriously.
// Turn back.

#pragma once
#include "Doom3Model.h"
#include "../MapShared/MapLoaderBase.h"

class D3Proc:public MapLoaderBase
{
public:
	D3Proc();
	void Open(std::string fName) override;
	
	bool PhaseOne() override;
	void PhaseTwo(std::vector<int> tws, std::vector<int> ths, std::vector<bool> tnd) override;

private:
	std::string fileName;
	std::vector<std::string> procFile;

	std::vector<Doom3Model*> models;

	std::string RemoveComments(std::string input);
	int ParseModel(int startLine);
};