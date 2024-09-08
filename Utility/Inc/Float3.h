#ifndef _FLOAT3
#define _FLOAT3

namespace Utility
{
	class Float3
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
			float i[3];
		};

	public:
		Float3() : x(0.0f), y(0.0f), z(0.0f) {}

		Float3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}

		Float3& operator=(const Float3& f4) { x = f4.x; y = f4.y; z = f4.z; return *this; }

		const Float3 operator+(const Float3& f4) { return Float3(x + f4.x, y + f4.y, z + f4.z); }
		const Float3 operator-(const Float3& f4) { return Float3(x - f4.x, y - f4.y, z - f4.z); }
		const Float3 operator*(const Float3& f4) { return Float3(x * f4.x, y * f4.y, z * f4.z); }
		const Float3 operator/(const Float3& f4) { return Float3(x / f4.x, y / f4.y, z / f4.z); }

		Float3& operator+=(const Float3& f4) { x += f4.x; y += f4.y; z += f4.z; return *this; }
		Float3& operator-=(const Float3& f4) { x -= f4.x; y -= f4.y; z -= f4.z; return *this; }
		Float3& operator*=(const Float3& f4) { x *= f4.x; y *= f4.y; z *= f4.z; return *this; }
		Float3& operator/=(const Float3& f4) { x /= f4.x; y /= f4.y; z /= f4.z; return *this; }
	};
}

#endif // !_FLOAT3
