#ifndef _INT4
#define _INT4

//#include <stdafx.h> (Precompiled header files)

#pragma warning( push )
#pragma warning( disable : 26495 ) 
//Int4::i[4] に対する警告：C26495(メンバ変数は必ず初期化してください) 無効化

NAMESPACE_UTILITY
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
			/*
				&(i[0]) = (&)x
				&(i[1]) = (&)y
				&(i[2]) = (&)z
				&(i[3]) = (&)w
			*/
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

#pragma warning( pop )
//警告C26495(メンバ変数は必ず初期化してください) 有効化

#endif // !_INT4