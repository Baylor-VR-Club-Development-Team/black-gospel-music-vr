// HammUEr
// Copyright 2015-2016 Turfster / NT Entertainment
// All Rights Reserved.


// This code is held together with kitten whiskers and toothpicks.
// There's nothing to see or learn here.
// Seriously.
// Turn back.

#pragma once
#include <cmath>

#define tSMALL_NUMBER (1.e-8f)
#define tKINDA_SMALL_NUMBER	(1.e-4f)
#define f_PI (3.1415926535897932f)


struct MAPColor
{
public:
	int R;
	int G;
	int B;
	int A;

	const static MAPColor White;

	MAPColor();
	MAPColor(int inR, int inG, int inB);
	MAPColor(int inR, int inG, int inB, int inA);
	MAPColor(float inR, float inG, float inB, float inA);
};

struct MAPVector
{
public: 
	float X;
	float Y;
	float Z;

	static const MAPVector ZeroVector;
	static const MAPVector UpVector;

	MAPVector();
	MAPVector(float x, float y, float z);
	static float DistSquared(const MAPVector &V1, const MAPVector &V2);
	bool operator==(const MAPVector& V) const;
	MAPVector operator*(float Scale) const;
	MAPVector operator*(const MAPVector &V) const;
	bool operator!=(const MAPVector &V1)const;
	MAPVector operator-() const;
	float Size() const;
	float& operator[] (int index);
	float operator[] (int index) const;
	MAPVector operator*=(const float Scale);
	MAPVector operator/(float Scale) const;
	MAPVector operator/=(const float Scale);
	static float Dist(const MAPVector &V1, const MAPVector &V2);
	float SizeSquared() const;
	MAPVector operator+(MAPVector v2) const;
	MAPVector operator+=(const MAPVector v2);
	MAPVector operator-(MAPVector v2) const;
	static float DotProduct(const MAPVector &A, const MAPVector &B);
	static MAPVector CrossProduct(const MAPVector A, const MAPVector B);
	bool Normalize(float Tolerance = tSMALL_NUMBER);
	MAPVector GetSafeNormal(float Tolerance = tSMALL_NUMBER) const;
	static bool PointsAreNear(const MAPVector &Point1, const MAPVector &Point2, float Dist);
};

struct MAPVector2D
{
public:
	float X;
	float Y;

	static const MAPVector2D ZeroVector;

	MAPVector2D();
	MAPVector2D(float x, float y);
	float& operator[] (int index);
	float operator[] (int index) const;
	bool operator==(const MAPVector2D& V) const;
	MAPVector2D operator-() const;
	MAPVector2D operator*(float Scale) const;
	MAPVector2D operator+(const MAPVector2D& V) const;
	MAPVector2D operator-(const MAPVector2D& V) const;
	MAPVector2D operator/(float Scale) const;
	MAPVector2D operator/=(const float Scale);
	static float DotProduct(const MAPVector2D &A, const MAPVector2D &B);
};


struct MAPQuat 
{
public:
	float X;
	float Y;
	float Z;
	float W;

	static const MAPQuat Identity;
	MAPQuat();
	MAPQuat(float inX, float inY, float inZ, float inW);
	MAPQuat(MAPVector axis, float angle);
	MAPVector RotateVector(MAPVector V) const;
	MAPVector operator*(const MAPVector v) const;
	MAPQuat operator*(const float Scale);
};

struct MAPMatrix
{
public:
	float M[4][4];

	MAPMatrix();
	MAPMatrix(float a1, float a2, float a3, float a4, float b1, float b2, float b3, float b4, float c1, float c2, float c3, float c4, float d1, float d2, float d3, float d4);
	float Determinant();
};