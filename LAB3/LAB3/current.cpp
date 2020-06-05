#include "header.h"
#include "current.h"
#include "utility.h"
#include "vector.h"


extern HWND hwnd;
extern HDC hdc;

Current::Current()
{
	selected = -1;
}

void Current::Refresh()
{
	
	CollisionCheck();
	Rectangle(hdc, 300, 0, 1200, 1000);
	for (size_t i = 0; i < currentSituation.size(); i++)
	{
		/*if (i = selected)
		{
			currentSituation[i]->SetColor(255, 0, 0); ÍÅ ÐÀÁÎÒÀÅÒ, ÏÐÎÈÑÕÎÄÈÒ ÏÈÇÄÅÖ
		}*/
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
	currentSituation.push_back(tmp);
	Select(currentSituation.size() - 1);
	//Refresh();
}

void Current::DelObj()
{
	currentSituation[selected]->Hide();
	currentSituation.erase(selected);
	if (selected > 0)
	{
		selected--;
	}
	Refresh();
}

int Current::Select()
{
	return selected;
}

void Current::Select(int x)
{
	if (x < currentSituation.size() || x < 0)
	{
		selected = x;
		currentSituation[selected]->SetColor(255, 0, 0);
	}
	Refresh();
}

void Current::CollisionCheck()
{
	for (int i = 0; i < currentSituation.size(); i++)
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


void Current::WriteFile(char* adres)
{
	ofstream out;
	out.open(adres);
	if (out.is_open())
	{
		for (size_t i = 0; i < currentSituation.size(); i++)
		{
			out << currentSituation[i]->GetType() << ' ' << currentSituation[i]->GetX() << ' ' << currentSituation[i]->GetY() << ' ' << currentSituation[i]->GetRadius() << endl;
		}
	}
	else
		cout << "File writing Error!!!";
}


void Current::FromFile(char* adres)
{
	Shape* tempShape;
	tempShape = new Square;
	ifstream fin;
	
	fin.open(adres);
	if (fin.is_open())
	{
		for (; !fin.eof();)
		{
			int tmp;
			fin >> tmp;//Òèï
			switch (tmp)
			{
			case 1:
				tempShape = new Square;
				break;
			case 2 :
				tempShape = new Star;
				break;
			case 3:
				tempShape = new Triangle;
				break;
			default:
				tempShape = new Square;
				break;
			}
			fin >> tmp;
			tempShape->SetX(tmp);
			fin >> tmp;
			tempShape->SetY(tmp);
			fin >> tmp;
			tempShape->SetRadius(tmp);
		}
		currentSituation.push_back(tempShape);
	}
	else
	{
		cout << "File reading error!!!";
	}
}