#include "square.h"

extern HWND hwnd;
extern HDC hdc;

void Square::Draw(int r, int g, int b)
{
	HPEN hPen = CreatePen(PS_SOLID, 3, RGB(r, g, b)); //����������� � ��������� �����
	SelectObject(hdc, hPen); //������ �������� �������
	Rectangle(hdc, (centerX - (radius / (1.414))), (centerY - (radius / (1.414))), (centerX + (radius / (1.414))), (centerY + (radius / (1.414))));
	if (track)
	{
		
	}
	DeleteObject(hPen);
}

