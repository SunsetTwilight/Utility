#ifndef _UINT3
#define _UINT3

//#include <stdafx.h> (Precompiled header files)

#pragma warning( push )
#pragma warning( disable : 26495 ) 
//Uint3::i[3] に対する警告：C26495(メンバ変数は必ず初期化してください) 無効化

NAMESPACE_UTILITY
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
			/*
				&(i[0]) = (&)x
				&(i[1]) = (&)y
				&(i[2]) = (&)z
			*/
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

#pragma warning( pop )
//警告C26495(メンバ変数は必ず初期化してください) 有効化

#endif // !_UINT3

