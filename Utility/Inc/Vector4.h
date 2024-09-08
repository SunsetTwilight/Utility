#ifndef _VECTOR4
#define _VECTOR4

namespace Utility
{
	class Vector4
	{
	public:
		union
		{
			struct
			{
				float x;
				float y;
				float z;
				float w;
			};
			float data[4];
		};

		const float magnitude() const;
		const Vector4 normalized() const;
		const float sqrMagnitude() const;
		const Vector4 inverse() const;

		void Set(float _x, float _y, float _z, float _w);

	public:
		static Vector4 one;
		static Vector4 zero;

	public:

		Vector4() : x(0.0f), y(0.0f), z(0.0f), w(0.0f) {}

		Vector4(float _x, float _y)						: x(_x), y(_y), z(0.0f), w(0.0f) {}
		Vector4(float _x, float _y, float _z)			: x(_x), y(_y), z(_z),	 w(0.0f) {}
		Vector4(float _x, float _y, float _z, float _w) : x(_x), y(_y), z(_z),	 w(_w)	 {}

		Vector4& operator=(const Vector4& v4) { x = v4.x; y = v4.y; z = v4.z; w = v4.w; return *this; }

		float& operator[](size_t i) { return data[i % 4]; }

		const Vector4 operator+(const Vector4& v4) const { return Vector4(x + v4.x, y + v4.y, z + v4.z, w + v4.w); }
		const Vector4 operator-(const Vector4& v4) const { return Vector4(x - v4.x, y - v4.y, z - v4.z, w - v4.w); }
		const Vector4 operator*(const float& f) const { return Vector4(x * f, y * f, z * f, w * f); }
		const Vector4 operator/(const float& f) const { return Vector4(x / f, y / f, z / f, w / f); }

		Vector4& operator+=(const Vector4& v4) { x += v4.x; y += v4.y; z += v4.z; w += v4.w; return *this; }
		Vector4& operator-=(const Vector4& v4) { x -= v4.x; y -= v4.y; z -= v4.z; w -= v4.w; return *this; }
		Vector4& operator/=(const float& f) { x /= f; y /= f; z /= f; w /= f; return *this; }
		Vector4& operator*=(const float& f) { x *= f; y *= f; z *= f; w *= f; return *this; }

		const bool operator== (const Vector4& v4) const { return x == v4.x && y == v4.y && z == v4.z && w == v4.w ? true : false; }
		const bool operator!= (const Vector4& v4) const { return x == v4.x && y == v4.y && z == v4.z && w == v4.w ? false : true; }

		static const float Distance(const Vector4& vec4_0, const Vector4& vec4_1);
		static const float Dot(const Vector4& vec4_0, const Vector4& vec4_1);
		static const Vector4 Max(const Vector4& vec4_0, const Vector4& vec4_1);
		static const Vector4 Min(const Vector4& vec4_0, const Vector4& vec4_1);
		static const Vector4 Scale(const Vector4& vec4_0, const Vector4& vec4_1);
		
	};
}
#endif // !_VECTOR4
