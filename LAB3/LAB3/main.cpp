#include "header.h"

//��� ���� ������� ���������. ���������������� � ������������� � main
HWND hwnd;
HDC hdc;



int main()
{
	hwnd = GetConsoleWindow();
	hdc = GetDC(hwnd);
	int variant;
	MenuPrint();
	Rectangle(hdc, 300, 0, 1200, 1000);
	variant = Num(0, 9);
	Shape* p = new Star;
	while (variant)
	{
		switch (variant)
		{
		case 1:
			/*�������� ������*/
			break;	
		case 2:
			/*�������� ����������*/
			break;
		case 3:
			/*����� ����������*/
			break;
		case 4:
			/*����� �����������*/
			break;
		case 5:
			/*���� ���������� �������*/
			break;
		case 8:
			/*������������ ���� ���������*/
			break;
		case 9:
			/*������*/
			break;
		default:
			break;
		}
		system("cls");
		MenuPrint();
		variant = Num(0, 9);
	}
	ReleaseDC(hwnd, hdc); 
	return 0;
}