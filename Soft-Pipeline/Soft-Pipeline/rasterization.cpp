
#include"rasterization.h"
#include<Windows.h>


extern ColorRgb g_framebuffer[WINDOW_WIDTH][WINDOW_HEIGHT];

void rasterzization::bresenham_DrawLine(int x1, int y1, int x2, int y2)
{
	int dx = x2 - x1;
	int dy = y2 - y1;
	int ux = ((dx > 0) << 1) - 1;//x的增量方向，取或-1
	int uy = ((dy > 0) << 1) - 1;//y的增量方向，取或-1
	int x = x1, y = y1, eps;//eps为累加误差

	int r = 255, g = 0 , b = 0;

	eps = 0; dx = abs(dx); dy = abs(dy);
	if (dx > dy)
	{
		for (x = x1; x != x2 + ux; x += ux)
		{
			g_framebuffer[x][y].setColor(r,g,b);
			eps += dy;
			if ((eps << 1) >= dx)
			{
				y += uy; eps -= dx;
			}
		}
	}
	else
	{
		for (y = y1; y != y2 + uy; y += uy)
		{
			g_framebuffer[x][y].setColor(r, g, b);
			eps += dx;
			if ((eps << 1) >= dy)
			{
				x += ux; eps -= dy;
			}
		}
	}
}

void rasterzization::bresenham_DrawLine(int x1, int y1, int x2, int y2,HDC hdc)
{
	int dx = x2 - x1;
	int dy = y2 - y1;
	int ux = ((dx > 0) << 1) - 1;//x的增量方向，取或-1
	int uy = ((dy > 0) << 1) - 1;//y的增量方向，取或-1
	int x = x1, y = y1, eps;//eps为累加误差

	int r = 0, g = 255, b = 0;

	eps = 0; dx = abs(dx); dy = abs(dy);
	if (dx > dy)
	{
		for (x = x1; x != x2 + ux; x += ux)
		{
			SetPixel(hdc, x, y, RGB(255, 0, 0));
			eps += dy;
			if ((eps << 1) >= dx)
			{
				y += uy; eps -= dx;
			}
		}
	}
	else
	{
		for (y = y1; y != y2 + uy; y += uy)
		{
			SetPixel(hdc, x, y, RGB(255, 0, 0));
			eps += dx;
			if ((eps << 1) >= dy)
			{
				x += ux; eps -= dy;
			}
		}
	}
}
