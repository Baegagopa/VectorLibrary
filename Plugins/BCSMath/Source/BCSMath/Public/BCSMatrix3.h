// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"


struct FBCSMatrix3
{
public:
	FBCSMatrix3() {}
	~FBCSMatrix3() {}

	float _11, _12, _13;
	float _21, _22, _23;
	float _31, _32, _33;


	FBCSMatrix3(float m11, float m12, float m13, float m21, float m22, float m23, float m31, float m32, float m33)
	{
		_11 = m11;	_12 = m12;	_13 = m13;
		_21 = m21;	_22 = m22;	_23 = m23;
		_31 = m31;	_32 = m32;	_33 = m33;
	}

	FBCSMatrix3 operator+=(const FBCSMatrix3& M)
	{
		_11 += M._11; _12 += M._12; _13 += M._13;	
		_21 += M._21; _22 += M._22; _23 += M._23;		
		_31 += M._31; _32 += M._32; _33 += M._33;

		return *this;
	}
	FBCSMatrix3 operator-=(const FBCSMatrix3& M)
	{
		_11 -= M._11; _12 -= M._12; _13 -= M._13;
		_21 -= M._21; _22 -= M._22; _23 -= M._23;			
		_31 -= M._31; _32 -= M._32; _33 -= M._33;

		return *this;
	}

	FBCSMatrix3 operator+(const FBCSMatrix3& M) const;
	FBCSMatrix3 operator-(const FBCSMatrix3& M) const;
	FBCSMatrix3 operator*(const FBCSMatrix3& M) const;
	FBCSMatrix3 operator*(const float s) const;

	FBCSMatrix3 Tranposed() const;
	FBCSMatrix3 Identity() const;
};

FBCSMatrix3 FBCSMatrix3::operator+(const FBCSMatrix3& M) const
{
	return FBCSMatrix3(
		_11 + M._11, _12 + M._12, _13 + M._13,
		_21 + M._21, _22 + M._22, _23 + M._23,
		_31 + M._31, _32 + M._32, _33 + M._33);
}

FBCSMatrix3 FBCSMatrix3::operator-(const FBCSMatrix3& M) const
{
	return FBCSMatrix3(
		_11 - M._11, _12 - M._12, _13 - M._13,
		_21 - M._21, _22 - M._22, _23 - M._23,
		_31 - M._31, _32 - M._32, _33 - M._33);
}

FBCSMatrix3 FBCSMatrix3::operator*(const FBCSMatrix3& M) const
{
	float m11 = _11 * M._11 + _12 * M._21 + _13 * M._31;
	float m12 = _11 * M._12 + _12 * M._22 + _13 * M._32;
	float m13 = _11 * M._13 + _12 * M._23 + _13 * M._33;

	float m21 = _21 * M._11 + _22 * M._21 + _23 * M._31;
	float m22 = _21 * M._12 + _22 * M._22 + _23 * M._32;
	float m23 = _21 * M._13 + _22 * M._23 + _23 * M._33;

	float m31 = _31 * M._11 + _32 * M._21 + _33 * M._31;
	float m32 = _31 * M._12 + _32 * M._22 + _33 * M._32;
	float m33 = _31 * M._13 + _32 * M._23 + _33 * M._33;
	
	return FBCSMatrix3(
		m11, m12, m13,
		m21, m22, m23,
		m31, m32, m33);
}

FBCSMatrix3 FBCSMatrix3::operator*(const float s) const
{
	return FBCSMatrix3(
		_11 * s, _12 * s, _13 * s,
		_21 * s, _22 * s, _23 * s,
		_31 * s, _32 * s, _33 * s);
}

FBCSMatrix3 FBCSMatrix3::Tranposed() const
{
	return FBCSMatrix3(
		_11, _21, _31,
		_12, _22, _32,
		_13, _23, _33);
}

FBCSMatrix3 FBCSMatrix3::Identity() const
{
	return FBCSMatrix3(
		1.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 1.0f);
}