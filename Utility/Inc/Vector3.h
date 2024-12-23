#ifndef _VECTOR3
#define _VECTOR3

//#include <stdafx.h> (Precompiled header files)

#pragma warning( push )
#pragma warning( disable : 26495 ) 
//Vector3::data[3] に対する警告：C26495(メンバ変数は必ず初期化してください) 無効化

NAMESPACE_UTILITY
{
	class Float3;

	class Vector3
	{
	public:
		union
		{
			struct
			{
				float x;
				float y;
				float z;
			};
			float data[3];
			/*
				&(data[0]) = (&)x
				&(data[1]) = (&)y
				&(data[2]) = (&)z
			*/
		};

		inline const float magnitude() const;
		inline const Vector3 normalized() const;
		inline const float sqrMagnitude() const;
		inline const Vector3 inverse() const;

		void Set(float _x, float _y, float _z);

	public:
		static const Vector3 back;
		static const Vector3 down;
		static const Vector3 forward;
		static const Vector3 left;
		static const Vector3 one;
		static const Vector3 right;
		static const Vector3 up;
		static const Vector3 zero;

	public:

		Vector3() : x(0.0f), y(0.0f), z(0.0f) {}

		Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}

		Vector3& operator=(const Vector3& v3) { x = v3.x; y = v3.y; z = v3.z; return *this; }

		float& operator[](size_t i) { return data[i % 3]; }

		const Vector3 operator+(const Vector3& v3) const { return Vector3(x + v3.x, y + v3.y, z + v3.z); }
		const Vector3 operator-(const Vector3& v3) const { return Vector3(x - v3.x, y - v3.y, z - v3.z); }
		const Vector3 operator*(const float& f) const { return Vector3(x * f, y * f, z * f); }
		const Vector3 operator/(const float& f) const { return Vector3(x / f, y / f, z / f); }

		Vector3& operator+=(const Vector3& v3) { x += v3.x; y += v3.y; z += v3.z; return *this; }
		Vector3& operator-=(const Vector3& v3) { x -= v3.x; y -= v3.y; z -= v3.z; return *this; }
		Vector3& operator*=(const float& f) { x *= f; y *= f; z *= f; return *this; }
		Vector3& operator/=(const float& f) { x /= f; y /= f; z /= f; return *this; }

		const bool operator== (const Vector3& v3) const { return x == v3.x && y == v3.y && z == v3.z ? true : false; }
		const bool operator!= (const Vector3& v3) const { return x == v3.x && y == v3.y && z == v3.z ? false : true; }

		inline static const float Magnitude(const Vector3& vec3);
		inline static const Vector3 Inverse(const Vector3& vec3);

		inline static const float Angle(const Vector3& from, const Vector3& to);
		inline static const Vector3 Cross(const Vector3& vec3_0, const Vector3& vec3_1);
		inline static const float Distance(const Vector3& vec3_0, const Vector3& vec3_1);
		inline static const float Dot(const Vector3& vec3_0, const Vector3& vec3_1);
		inline static const Vector3 Max(const Vector3& vec3_0, const Vector3& vec3_1);
		inline static const Vector3 Min(const Vector3& vec3_0, const Vector3& vec3_1);
		inline static const Vector3 Reflect(const Vector3& inDirection, const Vector3& inNormal);
		inline static const Vector3 Scale(const Vector3& vec3_0, const Vector3& vec3_1);
	};
}

#pragma warning( pop )
//警告C26495(メンバ変数は必ず初期化してください) 有効化

#endif // !_VECTOR3

