#pragma once

/// <summary>
/// 要素数三つの物
/// </summary>
class Vector3
{
public:
	float x_;
	float y_;
	float z_;
public:
	Vector3();
	Vector3(float x, float y, float z);

	float length() const;

	Vector3& normalize();
	float dot(const Vector3& v) const;
	Vector3 cross(const Vector3& v) const;

	Vector3 operator+() const;
	Vector3& ope(const float& v);

	Vector3 operator-() const;

	Vector3& operator+=(const Vector3& v);
	Vector3& operator-=(const Vector3& v);

	Vector3& operator/=(float s);
	Vector3& operator*=(float s);

	void SetVector3(Vector3 vec) { x_ = vec.x_; y_ = vec.y_; z_ = vec.z_; };
};

const Vector3 operator-(const Vector3& v1, const Vector3& v2);
const Vector3 operator*(const Vector3& v, float s);
const Vector3 operator*(float s, const Vector3& v);

//頂点ABCで作られたポリゴンから法線を計算する。
Vector3 CreatePolygonNormal(Vector3 a, Vector3 b, Vector3 c);