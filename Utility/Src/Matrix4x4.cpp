#include "Matrix4x4.h"

#include "Vector3.h"
#include "Quaternion.h"

//#include <stdafx.h> (Precompiled header files)

#pragma warning( push )
#pragma warning( disable : 26495 ) 
//Vector4::data[4] に対する警告：C26495(メンバ変数は必ず初期化してください) 無効化

NAMESPACE_UTILITY
{
	const Matrix4x4 Matrix4x4::identity
	(
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	);
	const Matrix4x4 Matrix4x4::zero
	(
		0.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 0.0f
	);




	const Vector4 Matrix4x4::GetColumn(size_t i) const
	{
		return Vector4(m[0][i], m[1][i], m[2][i], m[3][i]);
	}

	const Vector4 Matrix4x4::GetRow(size_t i) const
	{
		return Vector4(vec4[i]);
	}

	Matrix4x4::Matrix4x4() :
		_11(0.0f), _12(0.0f), _13(0.0f), _14(0.0f),
		_21(0.0f), _22(0.0f), _23(0.0f), _24(0.0f),
		_31(0.0f), _32(0.0f), _33(0.0f), _34(0.0f),
		_41(0.0f), _42(0.0f), _43(0.0f), _44(0.0f)
	{

	}

	Matrix4x4::Matrix4x4(const Vector4& v4_0, const Vector4& v4_1, const Vector4& v4_2, const Vector4& v4_3)
	{
		vec4[0] = v4_0;
		vec4[1] = v4_1;
		vec4[2] = v4_2;
		vec4[3] = v4_3;
	}

	Matrix4x4::Matrix4x4(
		float _11, float _12, float _13, float _14,
		float _21, float _22, float _23, float _24,
		float _31, float _32, float _33, float _34,
		float _41, float _42, float _43, float _44)
	{
		vec4[0].Set(_11, _12, _13, _14);
		vec4[1].Set(_21, _22, _23, _24);
		vec4[2].Set(_31, _32, _33, _34);
		vec4[3].Set(_41, _42, _43, _44);
	}

	inline Matrix4x4& Matrix4x4::operator=(const Matrix4x4& mat)
	{
		this->_11 = mat._11;
		this->_12 = mat._12;
		this->_13 = mat._13;
		this->_14 = mat._14;

		this->_21 = mat._21;
		this->_22 = mat._22;
		this->_23 = mat._23;
		this->_24 = mat._24;

		this->_31 = mat._31;
		this->_32 = mat._32;
		this->_33 = mat._33;
		this->_34 = mat._34;

		this->_41 = mat._41;
		this->_42 = mat._42;
		this->_43 = mat._43;
		this->_44 = mat._44;

		return *this;
	}

	const Matrix4x4 Matrix4x4::operator+(const Matrix4x4& mat) const
	{
		return Matrix4x4(
			vec4[0] + mat.vec4[0],
			vec4[1] + mat.vec4[1],
			vec4[2] + mat.vec4[2],
			vec4[3] + mat.vec4[3]
		);
	}
	const Matrix4x4 Matrix4x4::operator-(const Matrix4x4& mat) const
	{
		return Matrix4x4(
			vec4[0] - mat.vec4[0],
			vec4[1] - mat.vec4[1],
			vec4[2] - mat.vec4[2],
			vec4[3] - mat.vec4[3]
		);
	}
	const Matrix4x4 Matrix4x4::operator*(const float& scaler) const
	{
		return Matrix4x4(
			vec4[0] * scaler,
			vec4[1] * scaler,
			vec4[2] * scaler,
			vec4[3] * scaler
		);
	}
	const Matrix4x4 Matrix4x4::operator/(const float& scaler) const
	{
		return Matrix4x4(
			vec4[0] / scaler,
			vec4[1] / scaler,
			vec4[2] / scaler,
			vec4[3] / scaler
		);
	}


#define MATRIX_MUM_ELEMENT(r, c, num_r, num_c) r[num_r][0] * c[num_c][0] + r[num_r][1] * c[num_c][1] + r[num_r][2] * c[num_c][2] + r[num_r][3] * c[num_c][3]

	const Matrix4x4 Matrix4x4::operator*(const Matrix4x4& mat) const
	{
		Vector4 r[4];
		r[0] = this->GetRow(0);
		r[1] = this->GetRow(1);
		r[2] = this->GetRow(2);
		r[3] = this->GetRow(3);

		Vector4 c[4];
		c[0] = mat.GetColumn(0);
		c[1] = mat.GetColumn(1);
		c[2] = mat.GetColumn(2);
		c[3] = mat.GetColumn(3);

		return Matrix4x4(
			MATRIX_MUM_ELEMENT(r, c, 0, 0), MATRIX_MUM_ELEMENT(r, c, 0, 1), MATRIX_MUM_ELEMENT(r, c, 0, 2), MATRIX_MUM_ELEMENT(r, c, 0, 3),
			MATRIX_MUM_ELEMENT(r, c, 1, 0), MATRIX_MUM_ELEMENT(r, c, 1, 1), MATRIX_MUM_ELEMENT(r, c, 1, 2), MATRIX_MUM_ELEMENT(r, c, 1, 3),
			MATRIX_MUM_ELEMENT(r, c, 2, 0), MATRIX_MUM_ELEMENT(r, c, 2, 1), MATRIX_MUM_ELEMENT(r, c, 2, 2), MATRIX_MUM_ELEMENT(r, c, 2, 3),
			MATRIX_MUM_ELEMENT(r, c, 3, 0), MATRIX_MUM_ELEMENT(r, c, 3, 1), MATRIX_MUM_ELEMENT(r, c, 3, 2), MATRIX_MUM_ELEMENT(r, c, 3, 3)
		);
	}

	const Matrix4x4 Matrix4x4::Scale(const Vector3& v)
	{
		Matrix4x4 mat = identity;
		mat[0][0] = v.x;
		mat[1][1] = v.x;
		mat[2][2] = v.x;

		return mat;
	}

	const Matrix4x4 Matrix4x4::TRS(const Vector3& p, const Quaternion& q, const Vector3& s)
	{
		Matrix4x4 matRot = Matrix4x4::ConvertFromQuaternion(q);
		Matrix4x4 matScr = Matrix4x4::identity;
		Matrix4x4 matPos = Matrix4x4::identity;

		matScr._11 = s.x;
		matScr._22 = s.y;
		matScr._33 = s.z;

		matPos._14 = p.x;
		matPos._24 = p.y;
		matPos._34 = p.z;

		return matScr * matRot * matPos;
	}

	// The order of rotation is 'Z' 'X' 'Y'
	const Matrix4x4 Matrix4x4::ConvertFromEular(const float& x, const float& y, const float& z)
	{
		Matrix4x4 mat_x, mat_y, mat_z;
		mat_x = Matrix4x4::identity;
		mat_y = Matrix4x4::identity;
		mat_z = Matrix4x4::identity;

		float sin = std::sinf(x * UTL_DEG_RAD);
		float cos = std::cosf(x * UTL_DEG_RAD);

		mat_x._22 = cos;
		mat_x._23 = -sin;
		mat_x._32 = sin;
		mat_x._33 = cos;

		sin = std::sinf(y * UTL_DEG_RAD);
		cos = std::cosf(y * UTL_DEG_RAD);

		mat_y._11 = cos;
		mat_y._13 = sin;
		mat_y._31 = -sin;
		mat_y._33 = cos;

		sin = std::sinf(z * UTL_DEG_RAD);
		cos = std::cosf(z * UTL_DEG_RAD);

		mat_z._11 = cos;
		mat_z._12 = -sin;
		mat_z._21 = sin;
		mat_z._22 = cos;

		return mat_z * mat_x * mat_y;
	}

	const Matrix4x4 Matrix4x4::ConvertFromQuaternion(const Quaternion& quat)
	{
		return Matrix4x4
		(
			2 * (quat.w * quat.w + quat.x * quat.x) - 1, 2 * (quat.x * quat.y - quat.z * quat.w), 2 * (quat.x * quat.z + quat.y * quat.w), 0.0f,
			2 * (quat.x * quat.y + quat.z * quat.w), 2 * (quat.w * quat.w + quat.y * quat.y) - 1, 2 * (quat.y * quat.z - quat.x * quat.w), 0.0f,
			2 * (quat.x * quat.z - quat.y * quat.w), 2 * (quat.y * quat.z + quat.x * quat.w), 2 * (quat.w * quat.w + quat.z * quat.z) - 1, 0.0f,
			0.0f, 0.0f, 0.0f, 1.0f
		);
	}
}

#pragma warning( pop )
//警告C26495(メンバ変数は必ず初期化してください) 有効化
