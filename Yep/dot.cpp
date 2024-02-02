#include "dot.h"

#include "properties.h"

float Dot::getDist(Vector2 vec)
{
	float dx = pos.x - vec.x;
	float dy = pos.y - vec.y;

	float dist = sqrt((dx * dx) + (dy * dy));

	return dist == 0.0f ? 1.0f : dist;
}

Vector2 Dot::getNormal(Vector2 vec)
{
	float dist = getDist(vec);

	float dx = pos.x - vec.x;
	float dy = pos.y - vec.y;

	return Vector2{ dx * (1 / dist), dy * (1 / dist) };
}

void Dot::setMaxVel(float value)
{
	maxVel = value;
}

void Dot::setFriction(float value)
{
	friction = value;
}

void Dot::setTargetPos(Vector2 vec)
{
	float dist = fmax(getDist(vec), maxVel);
	Vector2 normal = getNormal(vec);

	vel.x -= normal.x / dist;
	vel.y -= normal.y / dist;
}

void Dot::update()
{
	vel.x *= friction;
	vel.y *= friction;

	pos.x += vel.x * speedMultiplier;
	pos.y += vel.y * speedMultiplier;

	if (pos.x < 0) { pos.x += WINDOW_WIDTH; }
	if (pos.x > WINDOW_WIDTH) { pos.x -= WINDOW_WIDTH; }
	if (pos.y < 0) { pos.y += WINDOW_HEIGHT; }
	if (pos.y > WINDOW_HEIGHT) { pos.y -= WINDOW_HEIGHT; }
}

void Dot::draw()
{
	DrawPixelV(pos, color);
}
