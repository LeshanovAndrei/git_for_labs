#pragma once
#include "vector.h"
#include "current.h"

class Agregate : public Shape
{
public:
	Agregate(Current);


private:
	vctor<Shape> vec;
};