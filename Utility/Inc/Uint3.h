#ifndef _UINT3
#define _UINT3

namespace Utility
{
	class Uint3
	{
	public:
		union
		{
			struct
			{
				unsigned int x;
				unsigned int y;
				unsigned int z;
			};
			unsigned int i[3];
		};

	public:
		Uint3() : x(0), y(0), z(0) {}

		Uint3(unsigned int _x, unsigned int _y, unsigned int _z) : x(_x), y(_y), z(_z) {}

		Uint3& operator=(const Uint3& f4) { x = f4.x; y = f4.y; z = f4.z; return *this; }

		const Uint3 operator+(const Uint3& i3) { return Uint3(x + i3.x, y + i3.y, z + i3.z); }
		const Uint3 operator-(const Uint3& i3) { return Uint3(x - i3.x, y - i3.y, z - i3.z); }
		const Uint3 operator*(const Uint3& i3) { return Uint3(x * i3.x, y * i3.y, z * i3.z); }
		const Uint3 operator/(const Uint3& i3) { return Uint3(x / i3.x, y / i3.y, z / i3.z); }

		Uint3& operator+=(const Uint3& i3) { x += i3.x; y += i3.y; z += i3.z; return *this; }
		Uint3& operator-=(const Uint3& i3) { x -= i3.x; y -= i3.y; z -= i3.z; return *this; }
		Uint3& operator*=(const Uint3& i3) { x *= i3.x; y *= i3.y; z *= i3.z; return *this; }
		Uint3& operator/=(const Uint3& i3) { x /= i3.x; y /= i3.y; z /= i3.z; return *this; }
	};
}

#endif // !_UINT3

