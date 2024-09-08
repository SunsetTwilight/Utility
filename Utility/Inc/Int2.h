#ifndef _INT2
#define _INT2

namespace Utility
{
	class Int2
	{
	public:
		union
		{
			struct
			{
				int x;
				int y;
			};
			int i[2];
		};

	public:
		Int2() : x(0), y(0) {}

		Int2(int _x, int _y) : x(_x), y(_y) {}

		Int2& operator=(const Int2& i2) { x = i2.x; y = i2.y; return *this; }

		const Int2 operator+(const Int2& i2) { return Int2(x + i2.x, y + i2.y); }
		const Int2 operator-(const Int2& i2) { return Int2(x - i2.x, y - i2.y); }
		const Int2 operator*(const Int2& i2) { return Int2(x * i2.x, y * i2.y); }
		const Int2 operator/(const Int2& i2) { return Int2(x / i2.x, y / i2.y); }

		Int2& operator+=(const Int2& i2) { x += i2.x; y += i2.y; return *this; }
		Int2& operator-=(const Int2& i2) { x -= i2.x; y -= i2.y; return *this; }
		Int2& operator*=(const Int2& i2) { x *= i2.x; y *= i2.y; return *this; }
		Int2& operator/=(const Int2& i2) { x /= i2.x; y /= i2.y; return *this; }
	};
}

#endif // !_INT2
