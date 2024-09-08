#ifndef _INT3
#define _INT3

namespace Utility
{
	class Int3
	{
	public:
		union
		{
			struct
			{
				int x;
				int y;
				int z;
			};
			int i[3];
		};

	public:
		Int3() : x(0), y(0), z(0) {}

		Int3(int _x, int _y, int _z) : x(_x), y(_y), z(_z) {}

		Int3& operator=(const Int3& f4) { x = f4.x; y = f4.y; z = f4.z; return *this; }

		const Int3 operator+(const Int3& i3) { return Int3(x + i3.x, y + i3.y, z + i3.z); }
		const Int3 operator-(const Int3& i3) { return Int3(x - i3.x, y - i3.y, z - i3.z); }
		const Int3 operator*(const Int3& i3) { return Int3(x * i3.x, y * i3.y, z * i3.z); }
		const Int3 operator/(const Int3& i3) { return Int3(x / i3.x, y / i3.y, z / i3.z); }

		Int3& operator+=(const Int3& i3) { x += i3.x; y += i3.y; z += i3.z; return *this; }
		Int3& operator-=(const Int3& i3) { x -= i3.x; y -= i3.y; z -= i3.z; return *this; }
		Int3& operator*=(const Int3& i3) { x *= i3.x; y *= i3.y; z *= i3.z; return *this; }
		Int3& operator/=(const Int3& i3) { x /= i3.x; y /= i3.y; z /= i3.z; return *this; }
	};
}

#endif // !_INT3
