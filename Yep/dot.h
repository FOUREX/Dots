#pragma once

#include <cmath>

#include "raylib.h"

#include "properties.h"

class Dot
{
private:
	Vector2 pos = { 0.0f, 0.0f };
	Vector2 vel = { 0.0f, 0.0f };
	Color color = { 255, 0, 0, 150 };

	float maxVel = 2.9f;
	float friction = 0.99f;

	float getDist(Vector2 vec);
	Vector2 getNormal(Vector2 vec);

public:
	Dot() {}
	Dot(Vector2 pos) : pos(pos) {}

	void setMaxVel(float value);
	void setFriction(float value);
	void setTargetPos(Vector2 vec);
	void update();
	void draw();
};
