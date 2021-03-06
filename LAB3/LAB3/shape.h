#pragma once
#include "utility.h"
#include "mvector.h"



class Shape
{
public:
	Shape();
	~Shape();
	/*Shape(const Shape&);*/
	virtual Shape& Create() = 0;
	void Show();
	void Hide();
	void Move(int, int);
	void Increase();
	void Reduce();
	void Track();
	void SetColor(int, int, int);
	virtual void Draw() = 0;
	int GetX();
	int GetY();
	int GetRadius();
	virtual int GetType();
	virtual mvector<int> AgregationTypes() = 0;
	void SetX(int);
	void SetY(int);
	void SetRadius(int);

protected:
	int r, g, b;
	int centerX;
	int centerY;
	int radius;
	bool track;
	mvector<point> tracking;
};