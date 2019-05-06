// HammUEr
// Copyright 2015-2016 Turfster / NT Entertainment
// All Rights Reserved.


// This code is held together with kitten whiskers and toothpicks.
// There's nothing to see or learn here.
// Seriously.
// Turn back.

#pragma once
#include "MAPArrayStructs.h"
#include <vector>
#include <map>

	enum class MAPNodeType :int
	{
		Unknown,
		Connections,
		VersionInfo,
		VisGroups,
		VisGroup,
		ViewSettings,
		World,
		Solid,
		Side,
		SideD3,
		Patch,
		DispInfo,
		Normals,
		Distances,
		Offsets,
		OffsetNormals,
		Alphas,
		TriangleTags,
		AllowedVerts,
		Group,
		Entity,
		EntityD3,
		Cameras,
		Cordons,
		Editor,
		Hidden
	};

class MAPNode
{
public:
	MAPNodeType nodeType;
	std::vector<MAPNode*> children;
	std::map<std::string, std::string> propertiesList;
	std::multimap<std::string, std::string> overflowList;

	MAPNode(std::string myType);
	MAPNode(std::string myType, MAPNode* myParent);

	MAPNode* parent() { return _parent; }
	void parent(MAPNode* value) {
		_parent = value;
		if (_parent != NULL)
			_parent->children.push_back(this);
	}
	
	void AddProperty(std::string inString);
	void AddProperty(std::string propertyName, std::string inString);
	
	static void ParseVector3(std::string vectorData, MAPVector& newVector);
	static void ParseVector2(std::string vectorData, MAPVector2D& newVector);
	static void ParseArray(std::string& inputData, int Count, std::vector<float>& newData);
	static void ParseArray(std::string& inputData, int Count, std::vector<std::string>& newData);
	static void ParseLight(std::string lightData, MAPColor& color, int& intensity);

	bool hasParent();

private:
	MAPNode* _parent;

	MAPNodeType ConvertType(std::string myType);
};

