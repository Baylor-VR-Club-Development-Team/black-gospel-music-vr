// HammUEr
// Copyright 2015-2016 Turfster / NT Entertainment
// All Rights Reserved.


// This code is held together with kitten whiskers and toothpicks.
// There's nothing to see or learn here.
// Seriously.
// Turn back.

#pragma once
#include "../MapShared/BaseEntity.h"

struct VMFOutput
{
public:
	std::string outputName;
	std::string targetEntity; // targetname or classname, accepts *
	std::string targetInput; // input of the target entity that will be triggered.
	std::string parameters; // data to pass
	int timeDelay; // number of seconds
	bool fireOnce; // delete output after it's been fired?

	VMFOutput();
};

class VMFLogic :public BaseEntity
{
public:
	VMFLogic();
	std::vector<VMFOutput*> myOutputs;

	VMFOutput* CreateOutput(std::string input, std::string output);
};