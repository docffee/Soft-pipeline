#pragma once

#include<math.h>

#define PI  ((FLOAT)  3.141592654f)

typedef struct { float x, y; } Vector2;
typedef struct { float x, y, z; } Vector3;

typedef struct Matrix44
{
	float m[4][4];
	Matrix44() {};
	Matrix44(Matrix44 &matrix);
	Matrix44 operator * (Matrix44 matrix);
} Matrix44;

typedef struct Vector4
{ 
	float x, y, z, w;
	Vector4() {};
	Vector4(float, float, float, float);
	Vector4(Vector4 &v);
	Vector4 operator * (Matrix44 matrix);
} Vector4;

typedef struct { float m[4]; } Matrix14;






float vector_Length(Vector2 *v);
float vector_Length(Vector3 *v);
float vector_Length(Vector4 *v);

void vector_Add(Vector4 *z, const Vector4 *x, const Vector4 *y);

void vector_Sub(Vector3 &z, Vector3 &x, Vector3 &y);

void vector_Cross(Vector3 &z, Vector3 &x, Vector3 &y);

float vector_Dot(Vector3 &x, Vector3 &y);

void vector_Normal(Vector3 &v);

void MartrixIdentity(Matrix44 &matrix);
void MartrixMultiply(Vector4 &v, Vector4 &vector, Matrix44 &matrix);
void MartrixMultiply(Matrix44 &matrix, Matrix44 &mat1, Matrix44 &mat2);

void MartrixRotationX(Matrix44 &matrix, float theta);
void MartrixRotationY(Matrix44 &matrix, float theta);
void MartrixRotationZ(Matrix44 &matrix, float theta);

