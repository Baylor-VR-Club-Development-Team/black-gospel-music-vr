#pragma once
#include "VMFTri.h"
#include <string>
#include <vector>
#include <algorithm>

class MapBrush
{
public:
	int id = -1;
	bool containsNoDraw = false;
	bool containsDisplacements = false;
	std::string brushName = "none";
	std::vector<VMFTri*> triangles;
};

class BaseEntity
{
	public:
		int id;

		MAPVector origin;
		std::string classname;
		std::string name;

		MAPVector angles;

		BaseEntity();
};

enum MapEntityType :int
{
	Unknown,
	FuncBox,
	Instance,
	FuncBrush,
	FuncStatic,
	LogicRelay,
	LogicAuto,
	PropStatic,
	PropDynamic,
	Path,
	Light,
	Spotlight,
	EnvironmentLight,
	Overlay
};

