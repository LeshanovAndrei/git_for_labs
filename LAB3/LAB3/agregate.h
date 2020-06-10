#pragma once
#include "current.h"

class Agregate : public Shape 
{
public:
	Agregate(Current);
	Agregate(mvector<Shape*>);
	virtual void Draw();
	friend class Current;
	virtual Shape& Create();
	virtual int GetType();
	virtual mvector<int> AgregationTypes();

private:
	int startRadius;
	mvector<Shape*> vec;
};