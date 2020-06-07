#pragma once
#include "header.h"

class Star : public Shape
{
public:
	virtual void Draw();
	virtual int GetType();
	virtual Shape& Create();

private:

};