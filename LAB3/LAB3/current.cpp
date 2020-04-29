#include "header.h"
#include "current.h"


extern HWND hwnd;
extern HDC hdc;

Current::Current()
{
	selected = -1;
}

void Current::Refresh()
{
	Rectangle(hdc, 300, 0, 1200, 1000);
	for (size_t i = 0; i < currentSituation.Size(); i++)
	{
		currentSituation[i]->Draw();
	}
}

void Current::AddObj()
{
	Shape* tmp;
	system("cls");
	CreateMenuPrint();
	int variant;
	variant = Num(0, 3);
	switch (variant)
	{
	case 1:
		tmp = new Square;
		break;
	case 2:
		tmp = new Star;
		break;
	case 3:
		tmp = new Triangle;
		break;
	default:
		return;
	}
	currentSituation.Add(tmp);
	Select(currentSituation.Size() - 1);
	Refresh();
}

void Current::DelObj()
{
	currentSituation[selected]->Hide();
	currentSituation.Del(currentSituation[selected]);
	Refresh();
}

int Current::Select()
{
	return selected;
}

void Current::Select(int x)
{
	selected = x;
	currentSituation[selected]->SetColor(255, 0, 0);
	Refresh();
}

bool Current::CollisionCheck()
{
	
}

bool Current::BorderCheck()
{
	if (currentSituation[selected]->GetX - currentSituation[selected]->GetRadius() < 300
		or
		currentSituation[selected]->GetY + currentSituation[selected]->GetRadius() > 900
		or
		currentSituation[selected]->GetX + currentSituation[selected]->GetRadius() > 1100
		or
		currentSituation[selected]->GetY - currentSituation[selected]->GetRadius() < 0)
	{
		return true;
	}
}