#pragma once

void MenuPrint();

void CreateMenuPrint();

int Num(int, int);

void HelpMenu();

int CenterDistance(int x0, int y0, int x1, int y1);

struct poit
{
	int x;
	int y;
	bool operator !=(poit a)
	{
		if (x != a.x || y != a.y)
			return true;
		return false;
	}
	bool operator <(poit a)
	{
		if (x < a.x && y < a.y)
			return true;
		return false;
	}
	bool operator >(poit a)
	{
		if (x < a.x && y < a.y)
			return false;
		return true;
	}
};