#pragma once
#include"header.h"
#include "mvector.h"

/*
���� ��������� ���������� � x = 300
*/

class Current //����� ��� ���������� ����� ���������
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
	//�������� �������
	void Show();
	void Hide();
	void Move(int);
	void Increase();
	void Reduce();
	void Track();

	//�����
	void WriteFile(char*);
	void FromFile(char*);

private:
	void CollisionCheck();
	int selected;
	mvector<Shape*> currentSituation;

};
