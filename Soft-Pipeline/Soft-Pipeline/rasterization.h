#pragma once

#include"setting.h"
#include<math.h>

namespace rasterzization
{
	void bresenham_DrawLine(int x1, int y1, int x2, int y2);
	void bresenham_DrawLine(int x1, int y1, int x2, int y2, HDC hdc);
}