#pragma once
#include "header.h"

class Shape abstract
{
public:
	Shape();
	Shape(const Shape&);
	void Show();
	void Hide();
	void Move();
	void Increase();
	void Reduce();
	virtual void Draw(int, int, int) = 0;

protected:

	int centerX;
	int centerY;
	int radius;
	bool track;
};
