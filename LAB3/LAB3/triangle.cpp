#include "header.h"
#include "triangle.h"

extern HWND hwnd;
extern HDC hdc;

void Triangle::Draw(int r, int g, int b)
{
	HPEN hPen = CreatePen(PS_SOLID, 3, RGB(r, g, b)); //Объявляется и создается кисть
	SelectObject(hdc, hPen); //Объект делается текущим
	POINT poly[3];
	BYTE polytype[3];
	poly[0].x = centerX;
	poly[0].y = centerY - radius;
	poly[1].x = centerX - 0.866 * radius;
	poly[1].y = centerY + 0.5 * radius;
	poly[2].x = centerX + 0.866 * radius;
	poly[2].y = centerY + 0.5 * radius;
	polytype[0] = PT_LINETO;
	polytype[1] = PT_LINETO;
	polytype[2] = PT_LINETO;
	PolyDraw(hdc, poly, polytype, 3);
	if (track)
	{

	}
}