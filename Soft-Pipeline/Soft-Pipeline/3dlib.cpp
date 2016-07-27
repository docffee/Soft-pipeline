#include"stdafx.h"
#include"3dlib.h"

void ColorRgb::setColor(int rr, int gg, int bb)
{
	r = rr;
	g = gg;
	b = bb;
}


void MatrixLookAtLH(Matrix44 &matrix, Vector3 &vEye, Vector3 &vAt, Vector3 &vUp)
{
	Vector3 vZaxis,vXaxis,vYaxis;

	vector_Sub(vZaxis, vAt, vEye);
	vector_Normal(vZaxis);
	vector_Cross(vXaxis,vUp, vZaxis);
	vector_Normal(vXaxis);
	vector_Cross(vYaxis, vZaxis, vXaxis);

	matrix.m[0][0] = vXaxis.x;
	matrix.m[0][1] = vYaxis.x;
	matrix.m[0][2] = vZaxis.x;

	matrix.m[1][0] = vXaxis.y;
	matrix.m[1][1] = vYaxis.y;
	matrix.m[1][2] = vZaxis.y;

	matrix.m[2][0] = vXaxis.z;
	matrix.m[2][1] = vYaxis.z;
	matrix.m[2][2] = vZaxis.z;
	
	matrix.m[0][3] = matrix.m[1][3] = matrix.m[2][3] = 0.0f;
	
	matrix.m[3][0] = -vector_Dot(vXaxis, vEye);
	matrix.m[3][1] = -vector_Dot(vYaxis, vEye);
	matrix.m[3][2] = -vector_Dot(vZaxis, vEye);
	matrix.m[3][3] = 1.0f;
}

void MatrixPerspectiveFovLH(Matrix44 &matrix, float theta, float aspect, float zn, float zf)
{
	matrix.m[1][1] = 1.0f / tanf(theta / 2.0f);
	matrix.m[0][0] = matrix.m[1][1] / aspect;
	matrix.m[2][2] = zf / (zf - zn);
	matrix.m[3][2] = -zn * zf / (zf - zn);
	matrix.m[2][3] = 1.0f;

	matrix.m[0][1] = matrix.m[0][2] = matrix.m[0][3] =
	matrix.m[1][0] = matrix.m[1][2] = matrix.m[1][3] =
	matrix.m[2][0] = matrix.m[2][1] =
	matrix.m[3][0] = matrix.m[3][1] = matrix.m[3][3] = 0.0f;
}

void Homogenize(float w, float h, Vertex4 &y, Vertex4 &x)
{

	float rhw = 1.0f / x.w;
	y.x = (x.x * rhw + 1.0f) * w * 0.5f;
	y.y = (1.0f - x.y * rhw) * h * 0.5f;
	y.z = x.z * rhw;
	y.w = 1.0f;
}