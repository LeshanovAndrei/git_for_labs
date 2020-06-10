#include "header.h"
#include "utility.h"

//��� ���� ������� ���������. ���������������� � ������������� � main
HWND hwnd;
HDC hdc;



int main(int argc, char** argv)
{
	//vctor<poit> a;
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
	drawField.Refresh();
	variant = Num(0, 9);
	while (variant)
	{
		switch (variant)
		{
		case 1:
			/*�������� ������*/
			drawField.AddObj();
			drawField.Show();
			break;
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
			if (drawField.Size())
			{
				cout << "CONTROL MODE\nFor help press - F1\n";
				do
				{
					helpv = _getch();
					if (helpv == 59)
						HelpMenu();
					else
						drawField.Move(helpv);

				} while (helpv != 27);
			}
			else
			{
				cout << "Add an object first\n";
				system("pause");
			}

			break;
		case 6:
			/*������������� ���� ��������*/
			drawField.Agregation();
			break;
		case 7:
			/*������������ ���� ���������*/
			drawField.Refresh();
			break;
		case 8:
			/*������ ������������ � ����*/
			char adres[260];
			cout << "Enter the adres of file\n";
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
		drawField.Refresh();
		variant = Num(0, 9);
	}
	ReleaseDC(hwnd, hdc); 
	return 0;
}