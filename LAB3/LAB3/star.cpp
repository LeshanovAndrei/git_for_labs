#include "star.h"

extern HWND hwnd;
extern HDC hdc;

void Star::Draw(int r, int g, int b)
{
	HPEN hPen = CreatePen(PS_SOLID, 3, RGB(r, g, b)); //����������� � ��������� �����
	SelectObject(hdc, hPen); //������ �������� �������
	if (track)
	{

	}
	DeleteObject(hPen);
}