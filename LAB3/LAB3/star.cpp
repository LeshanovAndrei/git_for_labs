#include "star.h"

extern HWND hwnd;
extern HDC hdc;

void Star::Draw(int r, int g, int b)
{
	HPEN hPen = CreatePen(PS_SOLID, 3, RGB(r, g, b)); //Объявляется и создается кисть
	SelectObject(hdc, hPen); //Объект делается текущим
	POINT poly[6];
	poly[0].x = centerX;
	poly[0].y = centerY - radius;
	poly[1].x = centerX - (radius * 0.59);
	poly[1].y = centerY + (radius * 0.81);
	poly[2].x = centerX + (radius + 0.951);
	poly[2].y = centerY - (radius * 0.31);
	poly[3].x = centerX - (radius + 0.951);
	poly[3].y = centerY - (radius * 0.31);
	poly[4].x = centerX + (radius * 0.59);
	poly[4].y = centerY + (radius * 0.81);
	poly[5].x = centerX;
	poly[5].y = centerY - radius;
	Polyline(hdc, poly, 6);
	if (track)
	{

	}
	DeleteObject(hPen);
}