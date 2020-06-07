#include "agregate.h"

Agregate::Agregate(Current field)
{
	r = 0; g = 0; b = 0;
	centerX = field.currentSituation[0]->GetX();
	centerY = field.currentSituation[0]->GetY();
	radius = field.currentSituation[0]->GetRadius();
	for (size_t i = 0; i < field.currentSituation.size(); i++)
	{
		if (radius < field.currentSituation[i]->GetRadius())
			radius = field.currentSituation[i]->GetRadius();
	}
	track = 0;
	for (size_t i = 0; i < field.currentSituation.size(); i++)
	{
		vec.push_back(&field.currentSituation[i]->Create());
	}
}

void Agregate::Draw()
{
	for (size_t i = 0; i < vec.size(); i++)
	{
		vec[i]->SetX(centerX);
		vec[i]->SetY(centerY);
		vec[i]->Draw();
	}
}

Shape& Agregate::Create()
{
	return *new Agregate(*this);
}