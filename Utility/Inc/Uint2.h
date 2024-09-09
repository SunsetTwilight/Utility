#ifndef _UINT2
#define _UINT2

//#include <stdafx.h> (Precompiled header files)

#pragma warning( push )
#pragma warning( disable : 26495 ) 
//Uint2::i[2] に対する警告：C26495(メンバ変数は必ず初期化してください) 無効化

NAMESPACE_UTILITY
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
			/*
				&(i[0]) = (&)x
				&(i[1]) = (&)y
			*/
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

#pragma warning( pop )
//警告C26495(メンバ変数は必ず初期化してください) 有効化

#endif // !_UINT2