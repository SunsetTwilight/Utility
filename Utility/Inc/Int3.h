#ifndef _INT3
#define _INT3

//#include <stdafx.h> (Precompiled header files)

#pragma warning( push )
#pragma warning( disable : 26495 ) 
//Int3::i[3] に対する警告：C26495(メンバ変数は必ず初期化してください) 無効化

NAMESPACE_UTILITY
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
			/*
				&(i[0]) = (&)x
				&(i[1]) = (&)y
				&(i[2]) = (&)z
			*/
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

#pragma warning( pop )
//警告C26495(メンバ変数は必ず初期化してください) 有効化

#endif // !_INT3
