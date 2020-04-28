#pragma once

class Current
{
public:
	Current();
	void Refresh();
	void AddObj();
	void DelObj();
private:
	int selected;
	vctor<Shape> currentSituation;

};
