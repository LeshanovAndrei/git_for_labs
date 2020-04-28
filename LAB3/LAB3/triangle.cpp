#include "header.h"
#include "triangle.h"

extern HWND hwnd;
extern HDC hdc;

void Triangle::Draw(int r, int g, int b)
{
	HPEN hPen = CreatePen(PS_SOLID, 3, RGB(r, g, b)); //����������� � ��������� �����
	SelectObject(hdc, hPen); //������ �������� �������
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

	}
	DeleteObject(hPen);
}

