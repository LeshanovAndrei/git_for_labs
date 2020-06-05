#pragma once
#include "current.h"

class Agregate : public Shape 
{
public:
	Agregate(Current);
	friend Current;

private:
	mvector<Shape*> vec;
};