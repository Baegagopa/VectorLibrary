// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//#include "CoreMinimal.h"
#include "Vector.h"

// float ¿ÀÂ÷ °ª
#define VERY_SMALL_NUMBER (1.e-4f)

struct FBCSVector3
{
public:
	float X;
	float Y;
	float Z;

public:
	FBCSVector3();
	~FBCSVector3();
	FBCSVector3(float InX, float InY, float InZ);

	FBCSVector3 operator+=(const FBCSVector3& V);
	FBCSVector3 operator-=(const FBCSVector3& V);
	FBCSVector3 operator*=(const FBCSVector3& V);
	FBCSVector3 operator/=(const FBCSVector3& V);
	FBCSVector3 operator-() const;
	FBCSVector3 operator*(const FBCSVector3& V) const;
	FBCSVector3 operator^(const FBCSVector3& V) const;
	float operator|(const FBCSVector3& V) const;

	friend FVector operator+(const FVector& ls, const FBCSVector3& rs)
	{
		return FVector(ls.X + rs.X, ls.Y + rs.Y, ls.Z + rs.Z);
	}

	friend FVector operator+(const FBCSVector3& ls, const FVector& rs)
	{
		return FVector(ls.X + rs.X, ls.Y + rs.Y, ls.Z + rs.Z);
	}

	bool ContainNaN() const
	{
		return (_finite(X) || _finite(Y) || _finite(Z) || _isnan(X) || _isnan(Y) || _isnan(Z));
	}
	bool Equals(const FBCSVector3& v, float Tolerance = VERY_SMALL_NUMBER)  const;

	FVector Convert() { return FVector(X, Y, Z); }
};

FBCSVector3::FBCSVector3(float InX, float InY, float InZ) : X(InX), Y(InY), Z(InZ)
{

}

FBCSVector3 FBCSVector3::operator+=(const FBCSVector3& V)
{
	X += V.X;	Y += V.Y;	Z += V.Z;
	return *this;
}

FBCSVector3 FBCSVector3::operator-=(const FBCSVector3& V)
{
	X -= V.X;	Y -= V.Y;	Z -= V.Z;
	return *this;
}

FBCSVector3 FBCSVector3::operator*=(const FBCSVector3& V)
{
	X *= V.X;	Y *= V.Y;	Z *= V.Z;
	return *this;
}

FBCSVector3 FBCSVector3::operator/=(const FBCSVector3& V)
{
	X /= V.X;	Y /= V.Y;	Z /= V.Z;
	return *this;
}

FBCSVector3 FBCSVector3::operator-() const
{
	return FBCSVector3(-X,-Y,-Z);
}

FBCSVector3 FBCSVector3::operator*(const FBCSVector3& V) const
{
	return FBCSVector3(X*V.X, Y*V.Y, Z*V.Z);
}

FBCSVector3 FBCSVector3::operator^(const FBCSVector3& V) const
{
	return FBCSVector3(Y * V.Z - V.Y * Z, Z * V.X - V.Z * X, X * V.Y - V.X * Y);
}

float FBCSVector3::operator|(const FBCSVector3& V) const
{
	return X * V.X + Y * V.Y + Z * V.Z;
}


bool FBCSVector3::Equals(const FBCSVector3& v, float Tolerance) const
{
	return (fabsf(v.X - X) < Tolerance) &&
				(fabsf(v.Y - Y) < Tolerance) &&
				(fabsf(v.Z - Z) < Tolerance);
}