#include "header.h"
#include "utility.h"

//Эти вещи сделаны глобально. Инициализируются и освобождаются в main
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
			/*создание нового*/
			drawField.AddObj();
		case 2:
			/*удаление выбранного*/
			drawField.DelObj();
			break;
		case 3:
			/*выбор следующего*/
			drawField.Select(drawField.Select() + 1);
			break;
		case 4:
			/*выбор предыдущего*/
			drawField.Select(drawField.Select() - 1);
			break;
		case 5:
			/*Меню управления объекта*/
			cout << "For help press - F1" << endl;
			do
			{
				helpv = _getch();
				if (helpv == 59)
					HelpMenu();
			} while (helpv != 27);

			break;
		case 6:
			/*Агрегирование всех объектов*/
			break;
		case 7:
			/*Перезагрузка поля рисования*/
			drawField.Refresh();
			break;
		case 8:
			/*Запись конфигурации в файл*/
			char adres[260];
			cin >> adres;
			drawField.WriteFile(adres);
			break;
		case 0:
			/*Выход*/
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