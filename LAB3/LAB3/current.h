#pragma once
#include "header.h"

/*
���� ��������� ���������� � x = 300
*/

class Current //����� ��� ���������� ������� ��������� ���� ���������
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
