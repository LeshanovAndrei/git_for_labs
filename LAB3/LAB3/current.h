#pragma once
#include"header.h"
#include "mvector.h"

/*
Поле рисования начинается с x = 300
*/

class Current //Класс для управления полем рисования
{
public:
	friend class Agregate;
	Current();
	void Refresh();
	void AddObj();
	void DelObj();
	int  Select();
	void Select(int);
	bool BorderCheck();
	size_t Size();
	void Agregation();
	void ObjectInfoOut();
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
	void CollisionCheck();
	int selected;
	mvector<Shape*> currentSituation;

};
