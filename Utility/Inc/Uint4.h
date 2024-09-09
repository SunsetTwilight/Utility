#ifndef _UINT4
#define _UINT4

//#include <stdafx.h> (Precompiled header files)

#pragma warning( push )
#pragma warning( disable : 26495 ) 
//Uint4::i[4] に対する警告：C26495(メンバ変数は必ず初期化してください) 無効化

NAMESPACE_UTILITY
{
	class Uint4
	{
	public:
		union
		{
			struct
			{
				unsigned int x;
				unsigned int y;
				unsigned int z;
				unsigned int w;
			};
			unsigned int i[4];
			/*
				&(i[0]) = (&)x
				&(i[1]) = (&)y
				&(i[2]) = (&)z
				&(i[3]) = (&)w
			*/
		};

	public:
		Uint4() : x(0), y(0), z(0), w(0) {}

		Uint4(unsigned int _x, unsigned int _y, unsigned int _z, unsigned int _w) : x(_x), y(_y), z(_z), w(_w) {}

		Uint4& operator=(const Uint4& i4) { x = i4.x; y = i4.y; z = i4.z; w = i4.w; return *this; }

		const Uint4 operator+(const Uint4& i4) { return Uint4(x + i4.x, y + i4.y, z + i4.z, w + i4.w); }
		const Uint4 operator-(const Uint4& i4) { return Uint4(x - i4.x, y - i4.y, z - i4.z, w - i4.w); }
		const Uint4 operator*(const Uint4& i4) { return Uint4(x * i4.x, y * i4.y, z * i4.z, w * i4.w); }
		const Uint4 operator/(const Uint4& i4) { return Uint4(x / i4.x, y / i4.y, z / i4.z, w / i4.w); }

		Uint4& operator+=(const Uint4& i4) { x += i4.x; y += i4.y; z += i4.z; w += i4.w; return *this; }
		Uint4& operator-=(const Uint4& i4) { x -= i4.x; y -= i4.y; z -= i4.z; w -= i4.w; return *this; }
		Uint4& operator*=(const Uint4& i4) { x *= i4.x; y *= i4.y; z *= i4.z; w *= i4.w; return *this; }
		Uint4& operator/=(const Uint4& i4) { x /= i4.x; y /= i4.y; z /= i4.z; w /= i4.w; return *this; }
	};
}

#pragma warning( pop )
//警告C26495(メンバ変数は必ず初期化してください) 有効化

#endif // !_UINT4


