#ifndef _INT4
#define _INT4

namespace Utility
{
	class Int4
	{
	public:
		union
		{
			struct
			{
				int x;
				int y;
				int z;
				int w;
			};
			int i[4];
		};

	public:
		Int4() : x(0), y(0), z(0), w(0) {}

		Int4(int _x, int _y, int _z, int _w) : x(_x), y(_y), z(_z), w(_w) {}

		Int4& operator=(const Int4& i4) { x = i4.x; y = i4.y; z = i4.z; w = i4.w; return *this; }

		const Int4 operator+(const Int4& i4) { return Int4(x + i4.x, y + i4.y, z + i4.z, w + i4.w); }
		const Int4 operator-(const Int4& i4) { return Int4(x - i4.x, y - i4.y, z - i4.z, w - i4.w); }
		const Int4 operator*(const Int4& i4) { return Int4(x * i4.x, y * i4.y, z * i4.z, w * i4.w); }
		const Int4 operator/(const Int4& i4) { return Int4(x / i4.x, y / i4.y, z / i4.z, w / i4.w); }

		Int4& operator+=(const Int4& i4) { x += i4.x; y += i4.y; z += i4.z; w += i4.w; return *this; }
		Int4& operator-=(const Int4& i4) { x -= i4.x; y -= i4.y; z -= i4.z; w -= i4.w; return *this; }
		Int4& operator*=(const Int4& i4) { x *= i4.x; y *= i4.y; z *= i4.z; w *= i4.w; return *this; }
		Int4& operator/=(const Int4& i4) { x /= i4.x; y /= i4.y; z /= i4.z; w /= i4.w; return *this; }
	};
}

#endif // !_INT4