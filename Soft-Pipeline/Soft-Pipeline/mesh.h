#pragma once

#include"3dlib.h"
class Mesh
{
public:
	Mesh();
	Vertex4 vertex[8];
	int indices[12][3];//12¸öÈı½ÇÃæ
};