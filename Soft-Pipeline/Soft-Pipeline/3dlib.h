#pragma once

#include"math.h"

//typedef Vector3 Vertex3D;

typedef Vector4 Vertex4;

struct ColorRgb
{
	int r, g, b;
	//void setColor(int &rr, int &gg, int &bb);
	void setColor(int rr, int gg, int bb);
};

void MatrixLookAtLH(Matrix44 &matrix, Vector3 &vEye, Vector3 &vAt, Vector3 &vUp);
void MatrixPerspectiveFovLH(Matrix44 &matrix, float theta, float aspect, float zn, float zf);
void Homogenize(float w, float h, Vertex4 &y, Vertex4 &x);
