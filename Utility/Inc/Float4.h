#ifndef _FLOAT4
#define _FLOAT4

//#include <stdafx.h> (Precompiled header files)

#pragma warning( push )
#pragma warning( disable : 26495 ) 
//Float4::i[4] に対する警告：C26495(メンバ変数は必ず初期化してください) 無効化

NAMESPACE_UTILITY
{
	class Float4
	{
	public:
		union
		{
			struct
			{
				float x;
				float y;
				float z;
				float w;
			};
			float i[4];
			/*
				&(i[0]) = (&)x
				&(i[1]) = (&)y
				&(i[2]) = (&)z
				&(i[3]) = (&)w
			*/
		};

	public:
		Float4() : x(0.0f), y(0.0f) , z(0.0f), w(0.0f) {}

		Float4(float _x, float _y, float _z, float _w) : x(_x), y(_y), z(_z), w(_w) {}

		Float4& operator=(const Float4& f4) { x = f4.x; y = f4.y; z = f4.z; w = f4.w; return *this; }

		const Float4 operator+(const Float4& f4) { return Float4(x + f4.x, y + f4.y, z + f4.z, w + f4.w); }
		const Float4 operator-(const Float4& f4) { return Float4(x - f4.x, y - f4.y, z - f4.z, w - f4.w); }
		const Float4 operator*(const Float4& f4) { return Float4(x * f4.x, y * f4.y, z * f4.z, w * f4.w); }
		const Float4 operator/(const Float4& f4) { return Float4(x / f4.x, y / f4.y, z / f4.z, w / f4.w); }

		Float4& operator+=(const Float4& f4) { x += f4.x; y += f4.y; z += f4.z; w += f4.w; return *this; }
		Float4& operator-=(const Float4& f4) { x -= f4.x; y -= f4.y; z -= f4.z; w -= f4.w; return *this; }
		Float4& operator*=(const Float4& f4) { x *= f4.x; y *= f4.y; z *= f4.z; w *= f4.w; return *this; }
		Float4& operator/=(const Float4& f4) { x /= f4.x; y /= f4.y; z /= f4.z; w /= f4.w; return *this; }
	};
}

#pragma warning( pop )
//警告C26495(メンバ変数は必ず初期化してください) 有効化

#endif // !_FLOAT4
