#ifndef _FLOAT3
#define _FLOAT3

//#include <stdafx.h> (Precompiled header files)

#pragma warning( push )
#pragma warning( disable : 26495 ) 
//Float3::i[3] �ɑ΂���x���FC26495(�����o�ϐ��͕K�����������Ă�������) ������

NAMESPACE_UTILITY
{
	class Float3
	{
	public:
		union
		{
			struct
			{
				float x;
				float y;
				float z;
			};
			float i[3];
			/*
				&(i[0]) = (&)x
				&(i[1]) = (&)y
				&(i[2]) = (&)z
			*/
		};

	public:
		Float3() : x(0.0f), y(0.0f), z(0.0f) {}

		Float3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}

		Float3& operator=(const Float3& f4) { x = f4.x; y = f4.y; z = f4.z; return *this; }

		const Float3 operator+(const Float3& f4) { return Float3(x + f4.x, y + f4.y, z + f4.z); }
		const Float3 operator-(const Float3& f4) { return Float3(x - f4.x, y - f4.y, z - f4.z); }
		const Float3 operator*(const Float3& f4) { return Float3(x * f4.x, y * f4.y, z * f4.z); }
		const Float3 operator/(const Float3& f4) { return Float3(x / f4.x, y / f4.y, z / f4.z); }

		Float3& operator+=(const Float3& f4) { x += f4.x; y += f4.y; z += f4.z; return *this; }
		Float3& operator-=(const Float3& f4) { x -= f4.x; y -= f4.y; z -= f4.z; return *this; }
		Float3& operator*=(const Float3& f4) { x *= f4.x; y *= f4.y; z *= f4.z; return *this; }
		Float3& operator/=(const Float3& f4) { x /= f4.x; y /= f4.y; z /= f4.z; return *this; }
	};
}

#pragma warning( pop )
//�x��C26495(�����o�ϐ��͕K�����������Ă�������) �L����

#endif // !_FLOAT3
