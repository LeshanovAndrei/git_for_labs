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
	bool BorderCheck();

	//Контролы объекта
	void Show();
	void Hide();
	void Move(int);
	void Increase();
	void Reduce();
	void Track();

	//Файлы
	void WriteFile(char*);
	void FromFile(char*);

private:
	void CollisionCheck();// Возвращает номер старшей фигуры, с которой пересекается выбранная, в параметры
	int selected;
	vctor<Shape*> currentSituation;

};
