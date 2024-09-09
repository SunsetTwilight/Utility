#ifndef _FLOAT2
#define _FLOAT2

//#include <stdafx.h> (Precompiled header files)

#pragma warning( push )
#pragma warning( disable : 26495 ) 
//Float2::i[2] �ɑ΂���x���FC26495(�����o�ϐ��͕K�����������Ă�������) ������

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
//�x��C26495(�����o�ϐ��͕K�����������Ă�������) �L����

#endif // !_FLOAT2
