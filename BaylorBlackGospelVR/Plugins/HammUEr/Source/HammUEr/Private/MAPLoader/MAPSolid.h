// HammUEr
// Copyright 2015-2016 Turfster / NT Entertainment
// All Rights Reserved.


// This code is held together with kitten whiskers and toothpicks.
// There's nothing to see or learn here.
// Seriously.
// Turn back.

#pragma once
#include "../MapShared/BaseSolid.h"
#include "../MapShared/VMFTri.h"

class MAPSolid : public BaseSolid
{
public:
	bool containsPatch = false;
	bool isDoom3 = false;

	void AddNewSide(MAPNode* data, int materialIndex, bool nodraw) override;
	void AddD3Patch(MAPNode* data, int materialIndex, bool nodraw);
	void BuildMesh(float convertUE, std::vector<int>& textWidths, std::vector<int>& textHeights, std::vector<bool>& textNDs) override;

	MAPSolid(int numb)
	{
		id = numb;
		newOrigin = MAPVector(0, 0, 0);
	}
};

