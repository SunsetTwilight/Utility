#ifndef _FLOAT2
#define _FLOAT2

//#include <stdafx.h> (Precompiled header files)

#pragma warning( push )
#pragma warning( disable : 26495 ) 
//Float2::i[2] に対する警告：C26495(メンバ変数は必ず初期化してください) 無効化

NAMESPACE_UTILITY
{
	class Float2
	{
	public:
		union
		{
			struct
			{
				float x;
				float y;
			};
			float i[2];
			/*
				&(i[0]) = (&)x
				&(i[1]) = (&)y
			*/
		};

	public:
		Float2() : x(0.0f), y(0.0f) {}

		Float2(float _x, float _y) : x(_x), y(_y) {}

		Float2& operator=(const Float2& f2) { x = f2.x; y = f2.y; return *this; }

		const Float2 operator+(const Float2& f2) { return Float2(x + f2.x, y + f2.y); }
		const Float2 operator-(const Float2& f2) { return Float2(x - f2.x, y - f2.y); }
		const Float2 operator*(const Float2& f2) { return Float2(x * f2.x, y * f2.y); }
		const Float2 operator/(const Float2& f2) { return Float2(x / f2.x, y / f2.y); }

		Float2& operator+=(const Float2& f2) { x += f2.x; y += f2.y; return *this; }
		Float2& operator-=(const Float2& f2) { x -= f2.x; y -= f2.y; return *this; }
		Float2& operator*=(const Float2& f2) { x *= f2.x; y *= f2.y; return *this; }
		Float2& operator/=(const Float2& f2) { x /= f2.x; y /= f2.y; return *this; }
	};
}

#pragma warning( pop )
//警告C26495(メンバ変数は必ず初期化してください) 有効化

#endif // !_FLOAT2
