#ifndef _UINT2
#define _UINT2

namespace Utility
{
	class Uint2
	{
	public:
		union
		{
			struct
			{
				unsigned int x;
				unsigned int y;
			};
			unsigned int i[2];
		};

	public:
		Uint2() : x(0), y(0) {}

		Uint2(unsigned int _x, unsigned int _y) : x(_x), y(_y) {}

		Uint2& operator=(const Uint2& i2) { x = i2.x; y = i2.y; return *this; }

		const Uint2 operator+(const Uint2& i2) { return Uint2(x + i2.x, y + i2.y); }
		const Uint2 operator-(const Uint2& i2) { return Uint2(x - i2.x, y - i2.y); }
		const Uint2 operator*(const Uint2& i2) { return Uint2(x * i2.x, y * i2.y); }
		const Uint2 operator/(const Uint2& i2) { return Uint2(x / i2.x, y / i2.y); }

		Uint2& operator+=(const Uint2& i2) { x += i2.x; y += i2.y; return *this; }
		Uint2& operator-=(const Uint2& i2) { x -= i2.x; y -= i2.y; return *this; }
		Uint2& operator*=(const Uint2& i2) { x *= i2.x; y *= i2.y; return *this; }
		Uint2& operator/=(const Uint2& i2) { x /= i2.x; y /= i2.y; return *this; }
	};
}

#endif // !_UINT2