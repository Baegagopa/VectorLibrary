// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
struct FBCSMatrix2
{
public:
	FBCSMatrix2();
	~FBCSMatrix2();

	float _11, _12;
	float _21, _22;

	FBCSMatrix2(float m11, float m12, float m21, float m22)
	{
		_11 = m11;
		_12 = m12;
		_21 = m21;
		_22 = m22;
	}

	FBCSMatrix2 operator+=(const FBCSMatrix2& M)
	{
		_11 += M._11;
		_12 += M._12;
		_21 += M._21;
		_22 += M._22;
		return *this;
	}
	FBCSMatrix2 operator-=(const FBCSMatrix2& M)
	{
		_11 -= M._11;
		_12 -= M._12;
		_21 -= M._21;
		_22 -= M._22;
		return *this;
	}

	FBCSMatrix2 operator+(const FBCSMatrix2& M) const;
	FBCSMatrix2 operator-(const FBCSMatrix2& M) const;
	FBCSMatrix2 operator*(const FBCSMatrix2& M) const;
	FBCSMatrix2 operator*(const float s) const;

	FBCSMatrix2 Tranposed() const;
	FBCSMatrix2 Identity() const;
};

FBCSMatrix2 FBCSMatrix2::operator+(const FBCSMatrix2& M) const
{
	return FBCSMatrix2(
		_11 + M._11,
		_12 + M._12,
		_21 + M._21,
		_22 + M._22 );
}

FBCSMatrix2 FBCSMatrix2::operator-(const FBCSMatrix2& M) const
{
	return FBCSMatrix2(
		_11 - M._11,
		_12 - M._12,
		_21 - M._21,
		_22 - M._22 );
}

FBCSMatrix2 FBCSMatrix2::operator*(const FBCSMatrix2& M) const
{
	return FBCSMatrix2(
		_11 * M._11 + _12 * M._21, 
		_11 * M._12 + _12 * M._22,
		_21 * M._11 + _22 * M._21,
		_21 * M._12 + _22 * M._22);
}

FBCSMatrix2 FBCSMatrix2::operator*(const float s) const
{
	return FBCSMatrix2(
		_11 *s,
		_11 *s,
		_21 *s,
		_21 *s);
}

FBCSMatrix2 FBCSMatrix2::Tranposed() const
{
	return FBCSMatrix2(_11, _21, _12, _22);
}

FBCSMatrix2 FBCSMatrix2::Identity() const
{
	return FBCSMatrix2(1.0f, 0.0f, 0.0f, 1.0f);
}