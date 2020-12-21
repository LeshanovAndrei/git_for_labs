#pragma once

void MenuPrint();

void CreateMenuPrint();

int Num(int, int);

void HelpMenu();

int CenterDistance(int x0, int y0, int x1, int y1);

struct point
{
	int x;
	int y;
	bool operator !=(point a)
	{
		if (x != a.x || y != a.y)
			return true;
		return false;
	}
	bool operator <(point a)
	{
		if (x < a.x && y < a.y)
			return true;
		return false;
	}
	bool operator >(point a)
	{
		if (x < a.x && y < a.y)
			return false;
		return true;
	}
};

