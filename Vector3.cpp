#include "Vector3.h"

#include <cmath>

Vector3::Vector3()
	:x_(0), y_(0), z_(0)
{
}

Vector3::Vector3(float x, float y, float z)
	: x_(x), y_(y), z_(z)
{
}

float Vector3::length() const
{
	return sqrt(x_ * x_ + y_ * y_ + z_ * z_);
}

Vector3& Vector3::normalize()
{
	float len = length();
	if (len != 0)
	{
		return *this /= len;
	}
	return *this;
}

float Vector3::dot(const Vector3& v) const
{
	return x_ * v.x_ + y_ * v.y_ + z_ * v.z_;
}

Vector3 Vector3::cross(const Vector3& v) const
{
	return Vector3(y_ * v.z_ - z_ * v.y_, z_ * v.x_ - x_ * v.z_, x_ * v.y_ - y_ * v.x_);
}

Vector3 Vector3::operator+() const
{
	return *this;
}

Vector3 Vector3::operator-() const
{
	return Vector3(-x_, -y_, -z_);
}

Vector3& Vector3::operator+=(const Vector3& v)
{
	x_ += v.x_;
	y_ += v.y_;
	z_ += v.z_;
	return *this;
}

Vector3& Vector3::operator-=(const Vector3& v)
{
	x_ -= v.x_;
	y_ -= v.y_;
	z_ -= v.z_;
	return *this;
}

Vector3& Vector3::operator/=(float s)
{
	x_ /= s;
	y_ /= s;
	z_ /= s;
	return *this;
}

Vector3& Vector3::operator*=(float s)
{
	x_ *= s;
	y_ *= s;
	z_ *= s;
	return *this;
}

Vector3& Vector3::ope(const float& v)
{
	x_ -= v;
	y_ -= v;
	z_ -= v;
	return *this;
}

const Vector3 operator-(const Vector3& v1, const Vector3& v2)
{
	Vector3 temp(v1);
	return temp -= v2;
}

const Vector3 operator*(const Vector3& v, float s)
{
	Vector3 temp(v);
	return temp *= s;
}

const Vector3 operator*(float s, const Vector3& v)
{
	return v * s;
}

Vector3 CreatePolygonNormal(Vector3 a, Vector3 b, Vector3 c)
{
	Vector3 AB(b - a);
	Vector3 BC(c - b);

	Vector3 normal = AB;
	normal.cross(BC);
	normal.normalize();

	return normal;
}
