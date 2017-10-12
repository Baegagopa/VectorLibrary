// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
*
*/
struct FBCSMatrix4
{
public:
	FBCSMatrix4();
	~FBCSMatrix4();

	float _11, _12, _13, _14;
	float _21, _22, _23, _24;
	float _31, _32, _33, _34;
	float _41, _42, _43, _44;


	FBCSMatrix4(float m11, float m12, float m13, float m14,
				float m21, float m22, float m23, float m24,
				float m31, float m32, float m33, float m34,
				float m41, float m42, float m43, float m44)
	{
		_11 = m11; _12 = m12; _13 = m13; _14 = m14;
		_21 = m21; _22 = m22; _23 = m23; _24 = m24;
		_31 = m31; _32 = m32; _33 = m33; _34 = m34;
		_41 = m41; _42 = m42; _43 = m43; _44 = m44;
	}

	FBCSMatrix4 operator+=(const FBCSMatrix4& M)
	{
		_11 += M._11; _12 += M._12; _13 += M._13; _14 += M._14;
		_21 += M._21; _22 += M._22; _23 += M._23; _24 += M._24;
		_31 += M._31; _32 += M._32; _33 += M._33; _34 += M._34;
		_41 += M._41; _42 += M._42; _43 += M._43; _44 += M._44;
		return *this;
	}
	FBCSMatrix4 operator-=(const FBCSMatrix4& M)
	{
		_11 -= M._11; _12 -= M._12; _13 -= M._13; _14 -= M._14;
		_21 -= M._21; _22 -= M._22; _23 -= M._23; _24 -= M._24;
		_31 -= M._31; _32 -= M._32; _33 -= M._33; _34 -= M._34;
		_41 -= M._41; _42 -= M._42; _43 -= M._43; _44 -= M._44;
		return *this;
	}

	FBCSMatrix4 operator+(const FBCSMatrix4& M) const;
	FBCSMatrix4 operator-(const FBCSMatrix4& M) const;
	FBCSMatrix4 operator*(const FBCSMatrix4& M) const;
	FBCSMatrix4 operator*(const float s) const;

	FBCSMatrix4 Tranposed() const;
	FBCSMatrix4 Identity() const;
};

FBCSMatrix4 FBCSMatrix4::operator+(const FBCSMatrix4& M) const
{
	return FBCSMatrix4(
		_11 += M._11, _12 += M._12, _13 += M._13, _14 += M._14,
		_21 += M._21, _22 += M._22, _23 += M._23, _24 += M._24,
		_31 += M._31, _32 += M._32, _33 += M._33, _34 += M._34,
		_41 += M._41, _42 += M._42, _43 += M._43, _44 += M._44);
}

FBCSMatrix4 FBCSMatrix4::operator-(const FBCSMatrix4& M) const
{
	return FBCSMatrix4(
		_11 -= M._11, _12 -= M._12, _13 -= M._13, _14 -= M._14,
		_21 -= M._21, _22 -= M._22, _23 -= M._23, _24 -= M._24,
		_31 -= M._31, _32 -= M._32, _33 -= M._33, _34 -= M._34,
		_41 -= M._41, _42 -= M._42, _43 -= M._43, _44 -= M._44);
}

FBCSMatrix4 FBCSMatrix4::operator*(const FBCSMatrix4& M) const
{
	float m11 = _11 * M._11 + _12 * M._21 + _13 * M._31 + _14 * M._41;
	float m12 = _11 * M._12 + _12 * M._22 + _13 * M._32 + _14 * M._42;
	float m13 = _11 * M._13 + _12 * M._23 + _13 * M._33 + _14 * M._43;
	float m14 = _11 * M._14 + _12 * M._24 + _13 * M._34 + _14 * M._44;

	float m21 = _21 * M._11 + _22 * M._21 + _23 * M._31 + _24 * M._41;
	float m22 = _21 * M._12 + _22 * M._22 + _23 * M._32 + _24 * M._42;
	float m23 = _21 * M._13 + _22 * M._23 + _23 * M._33 + _24 * M._43;
	float m24 = _21 * M._14 + _22 * M._24 + _23 * M._34 + _24 * M._44;

	float m31 = _31 * M._11 + _32 * M._21 + _33 * M._31 + _34 * M._41;
	float m32 = _31 * M._12 + _32 * M._22 + _33 * M._32 + _34 * M._42;
	float m33 = _31 * M._13 + _32 * M._23 + _33 * M._33 + _34 * M._43;
	float m34 = _31 * M._14 + _32 * M._24 + _33 * M._34 + _34 * M._44;

	float m41 = _41 * M._11 + _42 * M._21 + _43 * M._31 + _44 * M._41;
	float m42 = _41 * M._12 + _42 * M._22 + _43 * M._32 + _44 * M._42;
	float m43 = _41 * M._13 + _42 * M._23 + _43 * M._33 + _44 * M._43;
	float m44 = _41 * M._14 + _42 * M._24 + _43 * M._34 + _44 * M._44;

	return FBCSMatrix4(
		m11, m12, m13, m14,
		m21, m22, m23, m24,
		m31, m32, m33, m34,
		m41, m42, m43, m44);
}

FBCSMatrix4 FBCSMatrix4::operator*(const float s) const
{
	return FBCSMatrix4(
		_11 *= s, _12 *= s, _13 *= s, _14 *= s,
		_21 *= s, _22 *= s, _23 *= s, _24 *= s,
		_31 *= s, _32 *= s, _33 *= s, _34 *= s,
		_41 *= s, _42 *= s, _43 *= s, _44 *= s);
}

FBCSMatrix4 FBCSMatrix4::Tranposed() const
{
	return FBCSMatrix4(
		_11, _21, _31, _41,
		_12, _22, _32, _42,
		_13, _23, _33, _43,
		_14, _24, _34, _44);
}

FBCSMatrix4 FBCSMatrix4::Identity() const
{
	return FBCSMatrix4(
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f);
}