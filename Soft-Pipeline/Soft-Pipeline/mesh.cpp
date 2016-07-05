
#include"mesh.h"

Mesh::Mesh()
{
	//顶点数据
	vertex[0] = { -20.0,	20.0,	-20.0,	1.0 };
	vertex[1] = { -20.0,	20.0,	20.0,	1.0 };
	vertex[2] = { 20.0,		20.0,	20.0,	1.0 };
	vertex[3] = { 20.0,		20.0,	-20.0,	1.0 };
	vertex[4] = { -20.0,	-20.0,	-20.0,	1.0 };
	vertex[5] = { -20.0,	-20.0,	20.0,	1.0 };
	vertex[6] = { 20.0,		-20.0,	20.0,	1.0 };
	vertex[7] = { 20.0,		-20.0,	-20.0,	1.0 };

	//顶点索引
	//顶面
	indices[0][0] = 0;	indices[0][1] = 1;	indices[0][2] = 2;
	indices[1][0] = 0;	indices[1][1] = 2;	indices[1][2] = 3;

	//正面
	indices[2][0] = 0;	indices[2][1] = 3;	indices[2][2] = 7;
	indices[3][0] = 0;	indices[3][1] = 7;	indices[3][2] = 4;

	//左侧面
	indices[4][0] = 0;	indices[4][1] = 4;	indices[4][2] = 5;
	indices[5][0] = 0;	indices[5][1] = 5;	indices[5][2] = 1;

	//右侧面
	indices[6][0] = 2;	indices[6][1] = 6;	indices[6][2] = 7;
	indices[7][0] = 2;	indices[7][1] = 7;	indices[7][2] = 3;

	//背面
	indices[8][0] = 2;	indices[8][1] = 5;	indices[8][2] = 6;
	indices[9][0] = 2;	indices[9][1] = 1;	indices[9][2] = 5;

	//底面
	indices[10][0] = 4;	indices[10][1] = 6;	indices[10][2] = 5;
	indices[11][0] = 4;	indices[11][1] = 7;	indices[11][2] = 6;

}