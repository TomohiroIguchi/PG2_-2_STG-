#pragma once
#include <Novice.h>

#define WIDTH 1280
#define HEIGHT 720

class Object {
public:
	virtual void Update() = 0;
	virtual void Draw() = 0;

	float GetPosX() const { return posX; }
	float GetPosY() const { return posY; }
	float GetRadius() const { return radius; }
	void SetPosX(float x) { posX = x; }
	void SetPosY(float y) { posY = y; }
	void SetRadius(float r) { radius = r; }

	Object(float posX, float posY, float radius) : posX(posX), posY(posY), radius(radius) {}

protected:
	float posX;
	float posY;
	float radius;
};
