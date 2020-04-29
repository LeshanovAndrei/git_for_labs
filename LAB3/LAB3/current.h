#pragma once
#include "header.h"

/*
Поле рисования начинается с x = 300
*/

class Current //Класс для управления текущей ситуацией поля рисования
{
public:
	Current();
	void Refresh();
	void AddObj();
	void DelObj();
	int Select();
	void Select(int);
	bool CollisionCheck();
	bool BorderCheck();
private:
	int selected;
	vctor<Shape*> currentSituation;

};
