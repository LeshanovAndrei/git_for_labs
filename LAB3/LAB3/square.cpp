#include "square.h"

extern HWND hwnd;
extern HDC hdc;

void Square::Draw()
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
	POINT poly[5];
	int offset = static_cast<int>(radius / 1.414);
	poly[0].x = centerX - offset;
	poly[0].y = centerY - offset;
	poly[1].x = centerX + offset;
	poly[1].y = centerY - offset;
	poly[2].x = centerX + offset;
	poly[2].y = centerY + offset;
	poly[3].x = centerX - offset;
	poly[3].y = centerY + offset;
	poly[4].x = centerX - offset;
	poly[4].y = centerY - offset;
	Polyline(hdc, poly, 5);
	
	DeleteObject(hPen);
}

int Square::GetType()
{
	return -1;
}

Shape& Square:: Create()
{
	return *new Square(*this);
}

mvector<int> Square:: AgregationTypes()
{
	return *new mvector<int>{ 0 };
}