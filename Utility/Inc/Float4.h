#ifndef _FLOAT4
#define _FLOAT4

namespace Utility
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

#endif // !_FLOAT4
