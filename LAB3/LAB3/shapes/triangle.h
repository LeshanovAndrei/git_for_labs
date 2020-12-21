#pragma once
#include "header.h"

class Triangle : public Shape
{
public:
	virtual void Draw();
	virtual int GetType();
	virtual Shape& Create();
	virtual mvector<int> AgregationTypes();

private:

};