#pragma once
#include "header.h"

class Shape
{
public:
	Shape();
	~Shape();
	Shape(const Shape&);
	void Show();
	void Hide();
	void Move(int, int);
	void Increase();
	void Reduce();
	void Track();
	void SetColor(int, int, int);
	virtual void Draw();
	int GetX();
	int GetY();
	int GetRadius();
	virtual int GetType();

	void SetX(int);
	void SetY(int);
	void SetRadius(int);
protected:
	int r, g, b;

	int centerX;
	int centerY;
	int radius;
	bool track;
	vctor<POINT> tracking;
};
