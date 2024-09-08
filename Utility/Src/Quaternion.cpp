#include "Quaternion.h"

#include "Vector3.h"
#include "Matrix4x4.h"

namespace Utility
{
	const Quaternion Quaternion::identity(1.0f, 0.0f, 0.0f, 0.0f);
	const Quaternion Quaternion::zero(0.0f, 0.0f, 0.0f, 0.0f);

	Quaternion::Quaternion() : w(0.0f), x(0.0f), y(0.0f) ,z(0.0f) {}
	Quaternion::Quaternion(float w, float x, float y, float z) : w(w), x(x), y(y), z(z) {}

	const Quaternion Quaternion::operator+(const Quaternion& quat) const
	{
		return Quaternion(w + quat.w, x + quat.x, y + quat.y, z + quat.z);
	}
	const Quaternion Quaternion::operator-(const Quaternion& quat) const
	{
		return Quaternion(w - quat.w, x - quat.x, y - quat.y, z - quat.z);
	}
	const Quaternion Quaternion::operator*(const Quaternion& quat) const
	{
		return Quaternion(
			w * quat.w - x * quat.x - y * quat.y - z * quat.z,
			w * quat.x + x * quat.w + y * quat.z - z * quat.y,
			w * quat.y - x * quat.z + y * quat.w + z * quat.x,
			w * quat.z + x * quat.y - y * quat.x + z * quat.w
		);
	}

	const Quaternion Quaternion::AngleAxiz(const float& angle, const Vector3& axiz)
	{
		Vector3 normal = axiz.normalized();

		float rad = angle * UTL_DEG_RAD_HALF;
		float s = std::sinf(rad);
		
		return Quaternion
		(
			std::cosf(rad),
			normal.x * s,
			normal.y * s,
			normal.z * s
		);
	}
	const float Quaternion::Dot(const Quaternion& q1, const Quaternion& q2)
	{
		return q1.x * q2.x + q1.y * q2.y + q1.z * q2.z + q1.w * q2.w;
	}

	// The order of rotation is 'Z' 'X' 'Y'
	const Quaternion Quaternion::ConvertFromEular(const float& x, const float& y, const float& z)
	{
		Quaternion qx(
			std::cosf(x * UTL_DEG_RAD_HALF),
			std::sinf(x * UTL_DEG_RAD_HALF),
			0.0f,
			0.0f
		);
		Quaternion qy(
			std::cosf(y * UTL_DEG_RAD_HALF),
			0.0f,
			std::sinf(y * UTL_DEG_RAD_HALF),
			0.0f
		);
		Quaternion qz(
			std::cosf(z * UTL_DEG_RAD_HALF),
			0.0f,
			0.0f,
			std::sinf(z * UTL_DEG_RAD_HALF)
		);

		return qz * qx * qy;
	}

	const Quaternion Quaternion::ConvertFromMatrix(const Matrix4x4& matrix)
	{
		return Quaternion(matrix._11,0,0,0);
	}
	
}