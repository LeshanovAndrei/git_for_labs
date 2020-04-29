#pragma once
#include "header.h"

/*
ѕоле рисовани€ начинаетс€ с x = 300
*/

class Current // ласс дл€ управлени€ текущей ситуацией пол€ рисовани€
{
public:
	Current();
	void Refresh();
	void AddObj();
	void DelObj();
	int Select();
	void Select(int);
	bool BorderCheck();
	void Move();

private:
	void CollisionCheck();// ¬озвращает номер старшей фигуры, с которой пересекаетс€ выбранна€, в параметры
	int selected;
	vctor<Shape*> currentSituation;

};
