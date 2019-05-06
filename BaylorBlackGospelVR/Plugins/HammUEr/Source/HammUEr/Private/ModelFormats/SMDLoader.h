// HammUEr
// Basic ASCII SMD loader
// Copyright 2015-2016 Turfster / NT Entertainment
// All Rights Reserved.


// This code is held together with kitten whiskers and toothpicks.
// There's nothing to see or learn here.
// Seriously.
// Turn back.


#pragma once
#include "BaseModelLoader.h"


class SMDLoader :public BaseModelLoader
{

public:
	bool Open(std::string inFileName) override;

private:
	std::vector<std::string> SMDFileLines;
	void ParseString(std::string workString, int matID, MAPVector& vertex, MAPVector& normal, MAPVector2D& uv);
	int MaterialIndex(std::string input);
};