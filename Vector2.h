#pragma once

/// <summary>
/// óvëfêîìÒÇ¬ÇÃï®
/// </summary>
class Vector2
{
public:
	float x_;
	float y_;
public:
	Vector2();
	Vector2(float x, float y);

	Vector2 operator+() const;
	Vector2& operator+=(const Vector2& v);
	Vector2& operator-=(const Vector2& v);

	float length() const;

	Vector2& normalize();
	Vector2& operator/=(float s);
	Vector2& operator*=(float s);
};

const Vector2 operator-(const Vector2& v1, const Vector2& v2);
const Vector2 operator*(const Vector2& v, float s);
const Vector2 operator*(float s, const Vector2& v);