#include "header.h"

void MenuPrint()
{
	cout << "1. Create new object\n"
		<< "2. Delete selected\n"
		<< "3. Next object\n"
		<< "4. Prev object\n"
		<< "5. Control\n"
		<< "6. Agregate all\n"
		<< "7. Refresh\n"
		<< "8. Upload configuration file\n"
		<< "0. Exit\n"
		<< "Enter number:";
}

void CreateMenuPrint()
{
	cout << "1. Square\n"
		<< "2. Star\n"
		<< "3. Triangle\n"
		<< "0. Cancel\n";
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
	cout << "Keyboard arrows - movement\nEsc - exit control mode\n"
		 << "Space - tracking on\n"
		 << "Automatic movement:\n"
		 << "W - up\nS - down\nD - right\nA - left\n";
}


int CenterDistance(int x0, int y0, int x1, int y1)
{
	return sqrt(((x1 - x0) * (x1 - x0)) + ((y1 - y0) * (y1 - y0)));
}