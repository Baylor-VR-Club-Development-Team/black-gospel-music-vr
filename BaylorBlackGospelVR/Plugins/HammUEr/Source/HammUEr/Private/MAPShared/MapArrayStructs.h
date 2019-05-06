// HammUEr
// Copyright 2015-2016 Turfster / NT Entertainment
// All Rights Reserved.


// This code is held together with kitten whiskers and toothpicks.
// There's nothing to see or learn here.
// Seriously.
// Turn back.

#pragma once
#include <vector>
#include <algorithm>
#include "MAPVector.h"

struct MAPVectorArray
{
public:
	std::vector<MAPVector> data;

	void Add(MAPVector input)
	{
		data.push_back(input);
	}

	void AddUnique(MAPVector input)
	{
		if (std::find(data.begin(), data.end(), input)==data.end())
			data.push_back(input);
	}

	int Num()
	{
		return data.size();
	}

	void Initialize(int numitems)
	{
		for (int i = 0; i < numitems; i++)
			data.push_back(MAPVector::ZeroVector);
	}

	MAPVector Get(int index)
	{
		if (data.size()>index)
			return data[index];
		else
			return MAPVector(0.f, 0.f, 0.f);
	}

	void ReplaceAt(int index, MAPVector newVector)
	{
		if (data.size() > index)
			data[index] = newVector;
	}

	void RemoveAt(int index)
	{
		if (data.size() > index)
			data.erase(data.begin() + index);
	}

	int FindApproximate(MAPVector input, float maxDistance)
	{
		int index = -1;
		for (int i = 0; i < data.size(); i++)
		{
			if (MAPVector::DistSquared(input, data[i]) < maxDistance)
			{
				index = i;
				continue;
			}
		}
		return index;
	}

	int Find(MAPVector input)
	{
		int index = (std::find(data.begin(), data.end(), input) - data.begin());
		if (index < data.size())
			return index;
		else
			return -1;
	}

	void Empty()
	{
		data.clear();
	}

};


struct MAPVector2DArray
{
public:
	std::vector<MAPVector2D> data;

	void Add(MAPVector2D input)
	{
		data.push_back(input);
	}

	int Num()
	{
		return data.size();
	}

	void Initialize(int numitems)
	{
		for (int i = 0; i < numitems; i++)
			data.push_back(MAPVector2D::ZeroVector);
	}

	MAPVector2D Get(int index)
	{
		if (data.size()>index)
			return data[index];
		else
			return MAPVector2D(0.f, 0.f);
	}

	void ReplaceAt(int index, MAPVector2D newVector)
	{
		if (data.size()>index)
			data[index] = newVector;
	}

	void RemoveAt(int index)
	{
		if (data.size()>index)
			data.erase(data.begin() + index);
	}

	int Find(MAPVector2D input)
	{
		int index = (std::find(data.begin(), data.end(), input) - data.begin());
		if (index < data.size())
			return index;
		else
			return -1;
	}

	void Empty()
	{
		data.clear();
	}

};


struct MAPFloatArray
{
public:
	std::vector<float> data;

	void Add(float input)
	{
		data.push_back(input);
	}

	int Num()
	{
		return data.size();
	}

	float Get(int index)
	{
		if (data.size()>index)
			return data[index];
		else
			return 0.0f;
	}

	void ReplaceAt(int index, float newVector)
	{
		if (data.size()>index)
			data[index] = newVector;
	}

	void RemoveAt(int index)
	{
		if (data.size()>index)
			data.erase(data.begin()+index);
	}

	int Find(float input)
	{
		int index = (std::find(data.begin(), data.end(), input) - data.begin());
		if (index < data.size())
			return index;
		else
			return -1;
	}

	void Empty()
	{
		data.clear();
	}

};


struct MAPInt32Array
{
public:
	std::vector<int> data;

	void Add(int input)
	{
		data.push_back(input);
	}

	void AddUnique(int input)
	{
		if (std::find(data.begin(), data.end(), input) == data.end())
			data.push_back(input);
	}

	int Num()
	{
		return data.size();
	}

	int Get(int index)
	{
		if (data.size()>index)
			return data[index];
		else
			return 0;
	}
	void Append(MAPInt32Array input)
	{
		data.insert(data.end(),input.data.begin(), input.data.end());
	}

	void ReplaceAt(int index, int newVector)
	{
		if (data.size()>index)
			data[index] = newVector;
	}

	void RemoveAt(int index)
	{
		if (data.size()>(index))
			data.erase(data.begin()+index);
	}

	int Find(int input)
	{
		int index = (std::find(data.begin(), data.end(), input) - data.begin());
		if (index < data.size())
			return index;
		else
			return -1;
	}

	void Empty()
	{
		data.clear();
	}

};