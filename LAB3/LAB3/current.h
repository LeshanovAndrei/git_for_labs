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
	bool BorderCheck();
	void Move();

private:
	void CollisionCheck();// ���������� ����� ������� ������, � ������� ������������ ���������, � ���������
	int selected;
	vctor<Shape*> currentSituation;

};
