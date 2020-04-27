#pragma once
#include "vector.h"


class Agregate : public Shape
{
public:
	Agregate(vctor<Shape>);


private:
	vctor<Shape> vec;
};