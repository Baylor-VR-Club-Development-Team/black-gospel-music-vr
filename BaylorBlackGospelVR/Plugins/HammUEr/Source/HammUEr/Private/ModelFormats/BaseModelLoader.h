// HammUEr
// Base model loader
// Copyright 2015-2016 Turfster / NT Entertainment
// All Rights Reserved.

// This code is held together with kitten whiskers and toothpicks.
// There's nothing to see or learn here.
// Seriously.
// Turn back.

#pragma once
#include "../MAPShared/VMFTri.h"
#include "string"
#include "vector"

class BaseModelLoader
{
public:
	BaseModelLoader()
	{}

	virtual ~BaseModelLoader()
	{}

	virtual bool Open(std::string inFileName)
	{
		return false;
	}

	virtual void Import()
	{}

	std::vector<std::string> GetMaterialData()
	{
		return materialList;
	}

	std::vector<std::string> GetMaterialDirectories()
	{
		return materialDirectories;
	}

	std::vector<VMFTri*> GetModelData()
	{
		return triangles;
	}

	std::string GetName()
	{
		return name;
	}

	virtual void CleanUp()
	{}

protected:
	std::vector<VMFTri*> triangles;
	std::vector<std::string> materialList;
	std::vector<std::string> materialDirectories;
	std::string fileName;
	std::string name;
};