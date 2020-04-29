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
	void CollisionCheck();// ���������� ����� ������� ������, � ������� ������������ ���������, � ���������
	int selected;
	vctor<Shape*> currentSituation;

};
