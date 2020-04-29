#include "header.h"
#include "utility.h"

//��� ���� ������� ���������. ���������������� � ������������� � main
HWND hwnd;
HDC hdc;



int main(int argc, char* argv[])
{
	hwnd = GetConsoleWindow();
	hdc = GetDC(hwnd);
	Current drawField;
	if (argc > 1)
	{
		drawField.FromFile(argv[1]);
	}
	int helpv;
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
			drawField.AddObj();
		case 2:
			/*�������� ����������*/
			drawField.DelObj();
			break;
		case 3:
			/*����� ����������*/
			drawField.Select(drawField.Select() + 1);
			break;
		case 4:
			/*����� �����������*/
			drawField.Select(drawField.Select() - 1);
			break;
		case 5:
			/*���� ���������� �������*/
			cout << "For help press - F1" << endl;
			do
			{
				helpv = _getch();
				if (helpv == 59)
					HelpMenu();
			} while (helpv != 27);

			break;
		case 6:
			/*������������� ���� ��������*/
			break;
		case 7:
			/*������������ ���� ���������*/
			drawField.Refresh();
			break;
		case 8:
			/*������ ������������ � ����*/
			char adres[260];
			cin >> adres;
			drawField.WriteFile(adres);
			break;
		case 0:
			/*�����*/
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