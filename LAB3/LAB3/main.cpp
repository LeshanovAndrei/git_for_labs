#include "header.h"


int main()
{
	HWND hwnd = GetConsoleWindow();
	HDC hdc = GetDC(hwnd);
	int variant;
	MenuPrint();
	Rectangle(hdc, 300, 0, 800, 300);
	variant = Num(0, 9);
	while (variant)
	{
		switch (variant)
		{
		case 1:
			/*создание нового*/
			break;	
		case 2:
			/*удаление выбранного*/
			break;
		case 3:
			/*выбор следующего*/
			break;
		case 4:
			/*выбор предыдущего*/
			break;
		case 5:
			/*Меню управления объекта*/
			break;
		case 8:
			/*Перезагрузка поля рисования*/
			break;
		case 9:
			/*помощь*/
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




