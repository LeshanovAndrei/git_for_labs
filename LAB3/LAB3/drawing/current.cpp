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
	
	CollisionCheck();
	Rectangle(hdc, 300, 0, 1200, 1000);
	for (size_t i = 0; i < currentSituation.size(); i++)
	{
		/*if (i = selected)
		{
			currentSituation[i]->SetColor(255, 0, 0); 
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
		//currentSituation[selected]->SetColor(255, 0, 0);
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

bool Current::BorderCheck()//1 if border
{
	if ((currentSituation[selected]->GetX()) - (currentSituation[selected]->GetRadius()) - 10 < 300 //Левая граница
		||
		(currentSituation[selected]->GetY()) + (currentSituation[selected]->GetRadius()) + 10 > 605 // Нижняя граница
		||
		(currentSituation[selected]->GetX()) + (currentSituation[selected]->GetRadius()) + 10 > 1050 // Правая граница
		||
		(currentSituation[selected]->GetY()) - (currentSituation[selected]->GetRadius()) - 10 < 0) // Верхняя граница
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
	if(selected >= 0)
		currentSituation[selected]->Show();
	Refresh();
}

void Current::Hide()
{
	if (selected >= 0)
		currentSituation[selected]->Hide();
	Refresh();
}

void Current::Increase()
{
	if (selected >= 0)
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
	if (selected >= 0)
		currentSituation[selected]->Track();
	Refresh();
}

void Current::Move(int push)
{
	switch (push)
	{
	case 72: //Вверх
			currentSituation[selected]->Move(0, -10);
		if (BorderCheck())
			currentSituation[selected]->Move(0, 15);
		break;
	case 80: //Вниз
			currentSituation[selected]->Move(0, 10);
		if (BorderCheck())
			currentSituation[selected]->Move(0, -15);
		break;
	case 77: //Вправо
			currentSituation[selected]->Move(10, 0);
		if (BorderCheck())
			currentSituation[selected]->Move(-15, 0);
		break;
	case 75: //Влево
			currentSituation[selected]->Move(-10, 0);
		if (BorderCheck())
			currentSituation[selected]->Move(15, 0);
		break;
	case 32:
		currentSituation[selected]->Track();
		break;
	case 119://Вверх W
	case 230:
		while (!BorderCheck())
		{
			currentSituation[selected]->Move(0, -10);
			Sleep(100);
		}
		currentSituation[selected]->Move(0, 15);
		break;
	case 100://Вправо D
	case 162:
		while (!BorderCheck())
		{
			currentSituation[selected]->Move(10, 0);
			Sleep(100);
		}
		currentSituation[selected]->Move(-15, 0);
		break;
	case 115://Вниз S
	case 63:
	case 235:
		while (!BorderCheck())
		{
			currentSituation[selected]->Move(0, 10);
			Sleep(100);
		}
		currentSituation[selected]->Move(0, -15);
		break;
	case 97://Влево A
	case 228:
		while (!BorderCheck())
		{
			currentSituation[selected]->Move(-10, 0);
			Sleep(100);
		}
		currentSituation[selected]->Move(15, 0);
		break;
	case 45:
		Reduce();
		break;
	case 43:
		Increase();
		break;
	default:
		break;
	}
	Refresh();
}


void Current::WriteFile(char* adres)
{
	ofstream out;
	out.open(adres);
	if (out.is_open())
	{
		for (size_t i = 0; i < currentSituation.size(); i++)
		{
			int tmp = currentSituation[i]->GetType();
			if (tmp < 0)
				out << tmp << ' ' << currentSituation[i]->GetX() << ' ' << currentSituation[i]->GetY() << ' ' << currentSituation[i]->GetRadius() << endl;
			else
			{
				out << tmp << ' ';
				for (size_t j = 0; j < tmp*2; j++)
				{
					out << currentSituation[i]->AgregationTypes()[j] << ' ';
				}
				out << currentSituation[i]->GetX() << ' ' << currentSituation[i]->GetY() << ' ' << currentSituation[i]->GetRadius();
			}
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
	int tmp;
	fin.open(adres);
	if (fin.is_open())
	{
		while (/*!fin.eof()*/fin >> tmp)
		{
			
			//fin >> tmp;//Тип
			switch (tmp)
			{
			case -1:
				tempShape = new Square;
				break;
			case -2 :
				tempShape = new Star;
				break;
			case -3:
				tempShape = new Triangle;
				break;
			default:
				mvector<Shape*> forAgr;
				for (size_t i = 0; i < tmp; i++)
				{
					int agTmp;
					Shape* agrTmp = new Square;
					fin >> agTmp;
					switch (agTmp)
					{
					case -1:
						agrTmp = new Square;
						break;
					case -2:
						agrTmp = new Star;
						break;
					case -3:
						agrTmp = new Triangle;
						break;
						
					}
					fin >> agTmp;
					agrTmp->SetRadius(agTmp);
					forAgr.push_back(agrTmp);
				}
				tempShape = new Agregate(forAgr);
				break;
			}
			fin >> tmp; // Центр
			tempShape->SetX(tmp);
			fin >> tmp;
			tempShape->SetY(tmp);
			fin >> tmp; // Радиус
			tempShape->SetRadius(tmp);
			currentSituation.push_back(tempShape);
			selected++;
		}
		
	}
	else
	{
		cout << "File reading error!!!";
	}
}

size_t Current::Size()
{
	return currentSituation.size();
}

void Current::Agregation()
{
	Shape* tmp = new Agregate(*this);
	currentSituation.push_back(tmp);
	selected = currentSituation.size() - 1;
}