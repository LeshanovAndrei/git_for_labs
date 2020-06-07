#pragma once
#include "current.h"

class Agregate : public Shape 
{
public:
	Agregate(Current);
	virtual void Draw();
	friend class Current;
	virtual Shape& Create();

private:
	mvector<Shape*> vec;
};