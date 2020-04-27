#pragma once

class Current
{
public:
	Current();
	void Refresh();
private:
	int selected;
	vctor<Shape> currentSituation;

};
