#pragma once

#include "dot.h"

class Dots
{
private:
	int count;
	Dot* dots;

public:
	Dots(int count);
	~Dots();

	void generateRandom();
	void setTargetPos(Vector2 pos);
	void update();
	void draw();
};
