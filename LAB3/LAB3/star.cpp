#include "star.h"

extern HWND hwnd;
extern HDC hdc;

void Star::Draw(int r, int g, int b)
{
	HPEN hPen = CreatePen(PS_SOLID, 3, RGB(r, g, b)); //Объявляется и создается кисть
	SelectObject(hdc, hPen); //Объект делается текущим
	if (track)
	{

	}
	DeleteObject(hPen);
}