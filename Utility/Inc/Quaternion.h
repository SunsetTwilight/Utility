#ifndef _QUATERNION
#define _QUATERNION

namespace Utility
{
	class Vector3;
	class Matrix4x4;

	class Quaternion
	{
	public:
		union
		{
			struct
			{
				float w;
				float x;
				float y;
				float z;
			};
			float data[4];
		};

	public:
		const static Quaternion identity;
		const static Quaternion zero;

	public:
		Quaternion();
		Quaternion(float w, float x, float y, float z);

		float& operator[](size_t i) { return data[i % 4]; }


		const Quaternion operator+(const Quaternion& quat) const;
		const Quaternion operator-(const Quaternion& quat) const;
		const Quaternion operator*(const Quaternion& quat) const;

		static const Quaternion AngleAxiz(const float& angle, const Vector3& axiz);
		static const float Dot(const Quaternion& q1, const Quaternion& q2);
		
		// The order of rotation is 'Z' 'X' 'Y'
		static const Quaternion ConvertFromEular(const float& x, const float& y, const float& z);

		static const Quaternion ConvertFromMatrix(const Matrix4x4& matrix);

	};
}

#endif // !_QUATERNION