#include "Vector2.h"
#include <cmath>

Vector2::Vector2() :
	x_(0), y_(0)
{
}

Vector2::Vector2(float x, float y) :
	x_(x), y_(y)
{
}

Vector2 Vector2::operator+() const
{
	return *this;
}

Vector2& Vector2::operator+=(const Vector2& v)
{
	x_ += v.x_;
	y_ += v.y_;
	return *this;
}

Vector2& Vector2::operator-=(const Vector2& v)
{
	x_ -= v.x_;
	y_ -= v.y_;
	return *this;
}

float Vector2::length() const
{
	return sqrt(x_ * x_ + y_ * y_);
}

Vector2& Vector2::normalize()
{
	float len = length();
	if (len != 0)
	{
		return *this /= len;
	}
	return *this;
}

Vector2& Vector2::operator/=(float s)
{
	x_ /= s;
	y_ /= s;
	return *this;
}

Vector2& Vector2::operator*=(float s)
{
	x_ *= s;
	y_ *= s;
	return *this;
}

const Vector2 operator-(const Vector2& v1, const Vector2& v2)
{
	Vector2 temp(v1);
	return temp -= v2;
}

const Vector2 operator*(const Vector2& v, float s)
{
	Vector2 temp(v);
	return temp *= s;
}

const Vector2 operator*(float s, const Vector2& v)
{
	return v * s;
}
