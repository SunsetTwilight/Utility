#ifndef _MATRIX4X4
#define _MATRIX4X4

#include "Vector4.h"

NAMESPACE_UTILITY
{
	class Vector3;
	class Vector4;
	class Quaternion;

	class Matrix4x4
	{
	public:
		union
		{
			struct
			{
				float _11, _12, _13, _14;
				float _21, _22, _23, _24;
				float _31, _32, _33, _34;
				float _41, _42, _43, _44;
			};
			float m[4][4];
			Vector4 vec4[4];
		};

	public:
		const static Matrix4x4 identity;
		const static Matrix4x4 zero;

	public:
		//Matrix4x4 decomposeProjection;
		const float deteminant() const;
		const Matrix4x4 inverse() const;
		const bool isidentity() const;
		const Vector3 lossyScale() const;
		//const Quaternion rotation();

	public:
		const Vector4 GetColumn(size_t i) const;
		const Vector4 GetRow(size_t i) const;

	public:
		Matrix4x4();
		Matrix4x4(const Vector4& v4_0, const Vector4& v4_1, const Vector4& v4_2, const Vector4& v4_3);
		Matrix4x4(
			float _11, float _12, float _13, float _14,
			float _21, float _22, float _23, float _24,
			float _31, float _32, float _33, float _34,
			float _41, float _42, float _43, float _44
		);

		Matrix4x4& operator=(const Matrix4x4& mat);

		Vector4& operator[](size_t index) { return vec4[index % 4]; }

		const Matrix4x4 operator+(const Matrix4x4& mat) const;
		const Matrix4x4 operator-(const Matrix4x4& mat) const;
		const Matrix4x4 operator*(const float& scaler) const;
		const Matrix4x4 operator/(const float& scaler) const;

		const Matrix4x4 operator*(const Matrix4x4& mat) const;

	public:
		static const Matrix4x4 LookAt(
			const Vector3& from, 
			const Vector3& to, 
			const Vector3& up
		);
		static const Matrix4x4 Ortho(
			const float& left, const float& right, 
			const float& bottom, const float& top,
			const float& zNear, const float& zFar
		);
		static const Matrix4x4 Perspective(
			const float& fov, const float& aspect,
			const float& zNear, const float& zFar
		);
		static const Matrix4x4 Scale(const Vector3& v);
		static const Matrix4x4 TRS(const Vector3& pos, const Quaternion& q, const Vector3& s);

		// The order of rotation is 'Z' 'X' 'Y'
		static const Matrix4x4 ConvertFromEular(const float& x, const float& y, const float& z);
		static const Matrix4x4 ConvertFromQuaternion(const Quaternion& quat);
	};
}

#endif // !_MATRIX4X4
