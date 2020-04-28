#include "circle.h"

extern HWND hwnd;
extern HDC hdc;

void Circle::Draw(int r, int g, int b)
{
	HPEN hPen = CreatePen(PS_SOLID, 3, RGB(r, g, b)); //����������� � ��������� �����
	SelectObject(hdc, hPen); //������ �������� �������
	Ellipse(hdc, centerX - radius, centerY - radius, centerX + radius, centerY + radius);
	if (track)
	{

	}
}