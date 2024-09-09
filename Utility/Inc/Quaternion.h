#ifndef _QUATERNION
#define _QUATERNION

//#include <stdafx.h> (Precompiled header files)

#pragma warning( push )
#pragma warning( disable : 26495 ) 
//Vector4::data[4] に対する警告：C26495(メンバ変数は必ず初期化してください) 無効化

NAMESPACE_UTILITY
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
			/*
				&(data[0]) = (&)x
				&(data[1]) = (&)y
				&(data[2]) = (&)z
				&(data[3]) = (&)w
			*/
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

#pragma warning( pop )
//警告C26495(メンバ変数は必ず初期化してください) 有効化

#endif // !_QUATERNION