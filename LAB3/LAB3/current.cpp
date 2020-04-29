#include "header.h"
#include "current.h"
#include "utility.h"


extern HWND hwnd;
extern HDC hdc;

Current::Current()
{
	selected = -1;
}

void Current::Refresh()
{
	Rectangle(hdc, 300, 0, 1200, 1000);
	CollisionCheck();
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
	if (x < currentSituation.Size() || x < 0)
	{
		selected = x;
		currentSituation[selected]->SetColor(255, 0, 0);
	}
	Refresh();
}

void Current::CollisionCheck()
{
	for (int i = 0; i < currentSituation.Size(); i++)
	{
		currentSituation[i]->SetColor(0, 0, 0);
		if (i != selected)
		{
			if ((currentSituation[selected]->GetRadius() + currentSituation[i]->GetRadius()
				>=
				CenterDistance(currentSituation[selected]->GetX(), currentSituation[selected]->GetY(), currentSituation[i]->GetX(), currentSituation[i]->GetY())))
			{
				currentSituation[selected]->SetColor(0, 255, 0);
				currentSituation[i]->SetColor(0, 255, 0);
			}
		}
	}
}

bool Current::BorderCheck()
{
	if ((currentSituation[selected]->GetX()) - (currentSituation[selected]->GetRadius()) < 300
		||
		(currentSituation[selected]->GetY()) + (currentSituation[selected]->GetRadius()) > 900
		||
		(currentSituation[selected]->GetX()) + (currentSituation[selected]->GetRadius()) > 1100
		||
		(currentSituation[selected]->GetY()) - (currentSituation[selected]->GetRadius()) < 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Current::Show()
{
	currentSituation[selected]->Show();
	Refresh();
}

void Current::Hide()
{
	currentSituation[selected]->Hide();
	Refresh();
}

void Current::Increase()
{
	currentSituation[selected]->Increase();
	Refresh();
}

void Current::Reduce()
{
	currentSituation[selected]->Reduce();
	Refresh();
}

void Current::Track()
{
	currentSituation[selected]->Track();
	Refresh();
}

void Current::Move(int push)
{
	switch (push)
	{
	case 72:
		currentSituation[selected]->Move(0, -2);
		break;
	case 80:
		currentSituation[selected]->Move(0, 2);
		break;
	case 77:
		currentSituation[selected]->Move(2, 0);
		break;
	case 75:
		currentSituation[selected]->Move(-2, 0);
		break;
	default:
		break;
	}
}