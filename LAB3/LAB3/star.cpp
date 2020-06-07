#include "header.h"

extern HWND hwnd;
extern HDC hdc;

void Star::Draw()
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
	POINT poly[6];
	//Формула звездочки посчитана вручную
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
		for (size_t i = 0; i < tracking.size(); i++)
		{
			SetPixel(hdc, tracking[i].x, tracking[i].y, RGB(r, g, b));
		}
	}
	DeleteObject(hPen);
}

int Star::GetType()
{
	return -2;
}

Shape& Star::Create()
{
	return *new Star(*this);
}

mvector<int> Star::AgregationTypes()
{
	return *new mvector<int>{ 0 };
}