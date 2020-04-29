#include "square.h"

extern HWND hwnd;
extern HDC hdc;

void Square::Draw()
{
	HPEN hPen = CreatePen(PS_SOLID, 3, RGB(r, g, b)); //Объявляется и создается кисть
	SelectObject(hdc, hPen); //Объект делается текущим
	POINT poly[5];
	poly[0].x = centerX - (radius / 1.414);
	poly[0].y = centerY - (radius / 1.414);
	poly[1].x = centerX + (radius / 1.414);
	poly[1].y = centerY - (radius / 1.414);
	poly[2].x = centerX + (radius / 1.414);
	poly[2].y = centerY + (radius / 1.414);
	poly[3].x = centerX - (radius / 1.414);
	poly[3].y = centerY + (radius / 1.414);
	poly[4].x = centerX - (radius / 1.414);
	poly[4].y = centerY - (radius / 1.414);
	Polyline(hdc, poly, 5);
	if (track)
	{
		SetPixel(hdc, centerX, centerY, RGB(r, g, b));
	}
	DeleteObject(hPen);
}

