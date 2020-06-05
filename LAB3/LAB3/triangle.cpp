#include "header.h"
#include "triangle.h"

extern HWND hwnd;
extern HDC hdc;

void Triangle::Draw()
{
	HPEN hPen = CreatePen(PS_SOLID, 3, RGB(r, g, b)); //Объявляется и создается кисть
	SelectObject(hdc, hPen); //Объект делается текущим
	if (track)
	{


		for (size_t i = 0; i < tracking.size(); i++)
		{
			SetPixel(hdc, tracking[i].x, tracking[i].y, RGB(r, g, b));
		}
	}
	POINT poly[4];
	poly[0].x = centerX;
	poly[0].y = centerY - radius;
	poly[1].x = centerX - 0.866 * radius;
	poly[1].y = centerY + 0.5 * radius;
	poly[2].x = centerX + 0.866 * radius;
	poly[2].y = centerY + 0.5 * radius;
	poly[3].x = centerX;
	poly[3].y = centerY - radius;
	Polyline(hdc, poly, 4);
	if (track)
	{
		SetPixel(hdc, centerX, centerY, RGB(r, g, b));
	}
	DeleteObject(hPen);
}

int Triangle::GetType()
{
	return 3;
}
