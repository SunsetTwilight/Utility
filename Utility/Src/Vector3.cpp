#include "Vector3.h"

#include <cmath>

namespace Utility
{
	const Vector3 Vector3::back(0.0f, 0.0f, -1.0f);
	const Vector3 Vector3::down(0.0f, -1.0f, 0.0f);
	const Vector3 Vector3::forward(0.0f, 0.0f, 1.0f);
	const Vector3 Vector3::left(-1.0f, 0.0f, 0.0f);
	const Vector3 Vector3::one(1.0f, 1.0f, 1.0f);
	const Vector3 Vector3::right(1.0f, 0.0f, 0.0f);
	const Vector3 Vector3::up(0.0f, 1.0f, 0.0f);
	const Vector3 Vector3::zero(0.0f, 0.0f, 0.0f);

	const float Vector3::magnitude() const
	{
		return std::sqrtf((x * x) + (y * y) + (z * z));
	}

	const Vector3 Vector3::normalized() const
	{
		float length = magnitude();
		return Vector3(x / length, y / length, z / length);
	}

	const float Vector3::sqrMagnitude() const
	{
		return (x * x) + (y * y) + (z * z);
	}

	const Vector3 Vector3::inverse() const
	{
		return Vector3(-x, -y, -z);
	}

	void Vector3::Set(float _x, float _y, float _z)
	{
		x = _x;
		y = _y;
		z = _z;
	}

	const float Vector3::Magnitude(const Vector3& vec3)
	{
		return std::sqrtf((vec3.x * vec3.x) + (vec3.y * vec3.y) + (vec3.z * vec3.z));
	}
	const Vector3 Vector3::Inverse(const Vector3& vec3)
	{
		return Vector3(-vec3.x, -vec3.y, -vec3.z);
	}

	const float Vector3::Angle(const Vector3& vec3_0, const Vector3& vec_3_1)
	{
		return Dot(vec3_0, vec_3_1) / (vec3_0.magnitude() * vec_3_1.magnitude());
	}

	const Vector3 Vector3::Cross(const Vector3& vec3_0, const Vector3& vec3_1)
	{
		return Vector3(
			vec3_0.y * vec3_1.z - vec3_0.z * vec3_1.y,
			vec3_0.z * vec3_1.x - vec3_0.x * vec3_1.z,
			vec3_0.x * vec3_1.y - vec3_0.y * vec3_1.x);
	}

	const float Vector3::Distance(const Vector3& vec3_0, const Vector3& vec3_1)
	{
		return sqrtf(powf(vec3_0.x - vec3_1.x, 2.0f) + powf(vec3_0.y - vec3_1.y, 2.0f) + powf(vec3_0.z - vec3_1.z, 2.0f));
	}

	const float Vector3::Dot(const Vector3& vec3_0, const Vector3& vec3_1)
	{
		return (vec3_0.x * vec3_1.x) + (vec3_0.y * vec3_1.y) + (vec3_0.z * vec3_1.z);
	}

	const Vector3 Vector3::Max(const Vector3& vec3_0, const Vector3& vec3_1)
	{
		return Vector3(
			(vec3_0.x < vec3_1.x) ? vec3_1.x : vec3_0.x,
			(vec3_0.y < vec3_1.y) ? vec3_1.y : vec3_0.y,
			(vec3_0.z < vec3_1.z) ? vec3_1.z : vec3_0.z
		);
	}

	const Vector3 Vector3::Min(const Vector3& vec3_0, const Vector3& vec3_1)
	{
		return Vector3(
			(vec3_0.x > vec3_1.x) ? vec3_1.x : vec3_0.x,
			(vec3_0.y > vec3_1.y) ? vec3_1.y : vec3_0.y,
			(vec3_0.z > vec3_1.z) ? vec3_1.z : vec3_0.z
		);
	}

	const Vector3 Vector3::Reflect(const Vector3& inDirection, const Vector3& inNormal)
	{
		Dot(inDirection.inverse(), inNormal);
		return Vector3();
	}
}