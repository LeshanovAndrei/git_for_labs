#include "header.h"
#include "triangle.h"

extern HWND hwnd;
extern HDC hdc;

void Triangle::Draw()
{
	HPEN hPen = CreatePen(PS_SOLID, 3, RGB(r, g, b)); //����������� � ��������� �����
	SelectObject(hdc, hPen); //������ �������� �������
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
	poly[1].x = centerX - static_cast<int>(0.866 * radius);
	poly[1].y = centerY + static_cast<int>(0.5 * radius);
	poly[2].x = centerX + static_cast<int>(0.866 * radius);
	poly[2].y = centerY + static_cast<int>(0.5 * radius);
	poly[3].x = centerX;
	poly[3].y = centerY - radius;
	Polyline(hdc, poly, 4);
	if (track)
	{
		for (size_t i = 0; i < tracking.size(); i++)
		{
			SetPixel(hdc, tracking[i].x, tracking[i].y, RGB(r, g, b));
		}
	}
	DeleteObject(hPen);
}

int Triangle::GetType()
{
	return -3;
}

Shape& Triangle::Create()
{
	return *new Triangle(*this);
}

mvector<int> Triangle::AgregationTypes()
{
	return *new mvector<int>{ 0 };
}