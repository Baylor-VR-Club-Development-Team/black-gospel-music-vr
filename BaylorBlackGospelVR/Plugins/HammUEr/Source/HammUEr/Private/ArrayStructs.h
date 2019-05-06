// HammUEr
// Copyright 2015-2016 Turfster / NT Entertainment
// All Rights Reserved.


// This code is held together with kitten whiskers and toothpicks.
// There's nothing to see or learn here.
// Seriously.
// Turn back.

#pragma once

struct VectorArray
{
public:
	TArray<FVector> data;

	void Add(FVector input)
	{
		data.Add(input);
	}

	void AddUnique(FVector input)
	{
		data.AddUnique(input);
	}

	int32 Num()
	{
		return data.Num();
	}

	void Initialize(int numitems)
	{
		for (int i = 0; i < numitems; i++)
			data.Add(FVector::ZeroVector);
	}

	FVector Get(int32 index)
	{
		if (data.IsValidIndex(index))
			return data[index];
		else
			return FVector(0.f, 0.f, 0.f);
	}

	void ReplaceAt(int32 index, FVector newVector)
	{
		if (data.IsValidIndex(index))
			data[index] = newVector;
	}

	void RemoveAt(int32 index)
	{
		if (data.IsValidIndex(index))
			data.RemoveAt(index);
	}

	int32 FindApproximate(FVector input, float maxDistance)
	{
		return data.IndexOfByPredicate([&](FVector inVector) {return FVector::DistSquared(input, inVector) < maxDistance; });
	}

	int32 Find(FVector input)
	{
		return data.Find(input);
	}

};


struct Vector2DArray
{
public:
	TArray<FVector2D> data;

	void Add(FVector2D input)
	{
		data.Add(input);
	}

	int32 Num()
	{
		return data.Num();
	}

	void Initialize(int numitems)
	{
		for (int i = 0; i < numitems; i++)
			data.Add(FVector2D::ZeroVector);
	}

	FVector2D Get(int32 index)
	{
		if (data.IsValidIndex(index))
			return data[index];
		else
			return FVector2D(0.f, 0.f);
	}

	void ReplaceAt(int32 index, FVector2D newVector)
	{
		if (data.IsValidIndex(index))
			data[index] = newVector;
	}

	void RemoveAt(int32 index)
	{
		if (data.IsValidIndex(index))
			data.RemoveAt(index);
	}

	int32 Find(FVector2D input)
	{
		return data.Find(input);
	}

};


struct FloatArray
{
public:
	TArray<float> data;

	void Add(float input)
	{
		data.Add(input);
	}

	int32 Num()
	{
		return data.Num();
	}

	float Get(int32 index)
	{
		if (data.IsValidIndex(index))
			return data[index];
		else
			return 0.0f;
	}

	void ReplaceAt(int32 index, float newVector)
	{
		if (data.IsValidIndex(index))
			data[index] = newVector;
	}

	void RemoveAt(int32 index)
	{
		if (data.IsValidIndex(index))
			data.RemoveAt(index);
	}

	int32 Find(float input)
	{
		return data.Find(input);
	}

};


struct Int32Array
{
public:
	TArray<int32> data;

	void Add(int32 input)
	{
		data.Add(input);
	}

	void AddUnique(int32 input)
	{
		data.AddUnique(input);
	}

	int32 Num()
	{
		return data.Num();
	}

	int32 Get(int32 index)
	{
		if (data.IsValidIndex(index))
			return data[index];
		else
			return 0.0f;
	}
	void Append(Int32Array input)
	{
		data.Append(input.data);
	}

	void ReplaceAt(int32 index, int32 newVector)
	{
		if (data.IsValidIndex(index))
			data[index] = newVector;
	}

	void RemoveAt(int32 index)
	{
		if (data.IsValidIndex(index))
			data.RemoveAt(index);
	}

	int32 Find(int32 input)
	{
		return data.Find(input);
	}

};