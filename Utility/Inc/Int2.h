#ifndef _INT2
#define _INT2

//#include <stdafx.h> (Precompiled header files)

#pragma warning( push )
#pragma warning( disable : 26495 ) 
//Int2::i[2] に対する警告：C26495(メンバ変数は必ず初期化してください) 無効化

NAMESPACE_UTILITY
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
			/*
				&(i[0]) = (&)x
				&(i[1]) = (&)y
			*/
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

#pragma warning( pop )
//警告C26495(メンバ変数は必ず初期化してください) 有効化

#endif // !_INT2
