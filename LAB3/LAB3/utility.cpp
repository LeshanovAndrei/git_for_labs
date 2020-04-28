#include "header.h"

void MenuPrint()
{
	cout << "1. Create new object\n"
		<< "2. Delete selected\n"
		<< "3. Next object\n"
		<< "4. Prev object\n"
		<< "5. Control\n"
		<< "6. Agregate all\n"
		<< "7. Help\n"
		<< "8. Refresh\n"
		<< "0. Exit\n"
		<< "Enter number:";
}

void CreateMenuPrint()
{
	cout << "1. Square\n"
		<< "2. Circle\n"
		<< "3. Triangle\n";
}


int Num(int a, int b)
{
	char x[10];
	cin >> x;
	int c = x[0];
	while (c > 48 + b || c < 48 + a || strlen(x) > 1)
	{
		cout << "Wrong action! Try again!" << endl;
		//system("shutdown");
		cin >> x;
		c = x[0];
	} //защита
	return c - 48;
}

void HelpMenu()
{
	cout << "";
}