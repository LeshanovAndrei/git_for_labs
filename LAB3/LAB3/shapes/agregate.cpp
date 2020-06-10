#include "agregate.h"

Agregate::Agregate(Current field)
{
	r = 0; g = 0; b = 0;
	centerX = 450;//field.currentSituation[0]->GetX();
	centerY = 500;//field.currentSituation[0]->GetY();
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

Agregate::Agregate(mvector<Shape*> currentSituation)
{
	r = 0; g = 0; b = 0;
	centerX = currentSituation[0]->GetX();
	centerY = currentSituation[0]->GetY();
	radius = currentSituation[0]->GetRadius();
	for (size_t i = 0; i < currentSituation.size(); i++)
	{
		if (radius < currentSituation[i]->GetRadius())
			radius = currentSituation[i]->GetRadius();
	}
	track = 0;
	for (size_t i = 0; i < currentSituation.size(); i++)
	{
		vec.push_back(&currentSituation[i]->Create());
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

int Agregate::GetType()
{
	return vec.size();
}

mvector<int> Agregate::AgregationTypes()
{
	mvector<int>tmp;
	for (size_t i = 0; i < vec.size(); i++)
	{
		tmp.push_back(vec[i]->GetType());
		tmp.push_back(vec[i]->GetRadius());
	}
	return tmp;
}