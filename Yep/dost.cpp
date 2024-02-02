#include "dots.h"

int randomBetween(int min, int max)
{
	return rand() % (max - min + 1) + min;
}

Dots::Dots(int count) : count(count)
{
	dots = new Dot[count];
}

Dots::~Dots()
{
	delete[] dots;
}

void Dots::generateRandom()
{
	for (int i = 0; i < count; i++)
	{
		Vector2 pos = { (float)randomBetween(0, WINDOW_WIDTH), (float)randomBetween(0, WINDOW_HEIGHT) };

		dots[i] = Dot(pos);
	}
}

void Dots::setTargetPos(Vector2 pos)
{
	for (int i = 0; i < count; i++)
	{
		dots[i].setTargetPos(pos);
	}
}

void Dots::update()
{
	for (int i = 0; i < count; i++)
	{
		dots[i].update();
	}
}

void Dots::draw()
{
	for (int i = 0; i < count; i++)
	{
		dots[i].draw();
	}
}
