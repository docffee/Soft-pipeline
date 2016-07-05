#include"math.h"


float vector_Length(Vector2 *v)
{
	return (float)sqrt(v->x * v->x + v->y * v->y);
}

float vector_Length(Vector3 &v)
{
	return (float)sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

float vector_Length(Vector4 *v)
{
	return (float)sqrt(v->x * v->x + v->y * v->y + v->z * v->z + v->w * v->w);
}

void vector_Add(Vector4 *z, const Vector4 *x, const Vector4 *y)
{
	z->x = x->x + y->x;
	z->y = x->y + y->y;
	z->z = x->z + y->z;
	z->w = 1.0;
}

void vector_Sub(Vector3 &z, Vector3 &x, Vector3 &y)
{
	z.x = x.x - y.x;
	z.y = x.y - y.y;
	z.z = x.z - y.z;
}

void vector_Cross(Vector3 &z, Vector3 &x, Vector3 &y)
{
	z.x = x.y * y.z - x.z * y.y;
	z.y = x.z * y.x - x.x * y.z;
	z.z = x.x * y.y - x.y * y.x;
}

float vector_Dot(Vector3 &x, Vector3 &y)
{
	return x.x * y.x + x.y * y.y + x.z * y.z;
}

void vector_Normal(Vector3 &v)
{
	float l = vector_Length(v);
	v.z /= l;
	v.x /= l;
	v.y /= l;
}

void MartrixIdentity(Matrix44 &matrix)
{
	matrix.m[0][1] = matrix.m[0][2] = matrix.m[0][3] =
	matrix.m[1][0] = matrix.m[1][2] = matrix.m[1][3] =
	matrix.m[2][0] = matrix.m[2][1] = matrix.m[2][3] =
	matrix.m[3][0] = matrix.m[3][1] = matrix.m[3][2] = 0.0f;

	matrix.m[0][0] = matrix.m[1][1] = matrix.m[2][2] = matrix.m[3][3] = 1.0f;
}

void MartrixMultiply(Vector4 &v, Vector4 &vector, Matrix44 &matrix)
{
	v.x = vector.x * matrix.m[0][0] + vector.y * matrix.m[1][0]
		+ vector.z * matrix.m[2][0] + vector.w * matrix.m[3][0];
	v.y = vector.x * matrix.m[0][1] + vector.y *matrix.m[1][1]
		+ vector.z * matrix.m[2][1] + vector.w * matrix.m[3][1];
	v.z = vector.x * matrix.m[0][2] + vector.y * matrix.m[1][2]
		+ vector.z * matrix.m[2][2] + vector.w * matrix.m[3][2];
	v.w = vector.x * matrix.m[0][3] + vector.y * matrix.m[1][3]
		+ vector.z * matrix.m[2][3] + vector.w * matrix.m[3][3];
}

void MartrixMultiply(Matrix44 &matrix,Matrix44 &mat1, Matrix44 &mat2)
{
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
		{
			matrix.m[i][j] = 0.0f;
			for (int k = 0; k < 4; ++k)
				matrix.m[i][j] += mat1.m[i][k] * mat2.m[k][j];
		}
}

void MartrixRotationX(Matrix44 &matrix, float theta)
{
	MartrixIdentity(matrix);
	float cos_theta, sin_theta;
	cos_theta = cosf(theta);
	sin_theta = sinf(theta);

	matrix.m[1][1] = cos_theta;
	matrix.m[1][2] = sin_theta;
	matrix.m[2][1] = -sin_theta;
	matrix.m[2][2] = cos_theta;
}

void MartrixRotationY(Matrix44 &matrix, float theta)
{
	MartrixIdentity(matrix);
	float cos_theta, sin_theta;
	cos_theta = cosf(theta);
	sin_theta = sinf(theta);
	matrix.m[0][0] = cos_theta;
	matrix.m[0][2] = -sin_theta;
	matrix.m[2][0] = sin_theta;
	matrix.m[2][2] = cos_theta;
}

void MartrixRotationZ(Matrix44 &matrix, float theta)
{
	MartrixIdentity(matrix);
	float cos_theta, sin_theta;
	cos_theta = cosf(theta);
	sin_theta = sinf(theta);
	matrix.m[0][0] = cos_theta;
	matrix.m[0][1] = sin_theta;
	matrix.m[1][0] = -sin_theta;
	matrix.m[1][1] = cos_theta;
}


Matrix44::Matrix44(Matrix44 & matrix)
{
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			this->m[i][j] = matrix.m[i][j];
}

Matrix44 Matrix44::operator * ( Matrix44 matrix)
{
	Matrix44 matT;
	MartrixMultiply(matT, *this, matrix);
	return matT;
}

Vector4::Vector4(float xx, float yy, float zz, float ww)
	:x(xx),y(yy),z(zz),w(ww)
{
}

Vector4::Vector4(Vector4 & v)
{
	this->x = v.x;
	this->y = v.y;
	this->z = v.z;
	this->w = v.w;
}

Vector4 Vector4::operator*(Matrix44 matrix)
{
	Vector4 v;
	MartrixMultiply(v, *this, matrix);
	return v;
}
