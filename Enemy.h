#pragma once
#include "Object.h"
#include "Vector2.h"
#include "Bullet.h"

class Enemy : public Object {
public:
	bool GetIsAlive() const { return isAlive; }
	void SetIsAlive(bool alive) { isAlive = alive; }
	float GetPosX() const { return posX; }
	float GetPosY() const { return posY; }
	float GetRadius() const { return radius; }

	Enemy(float posX, float posY, float radius, float speedX, float speedY, unsigned int color);
	~Enemy();
	void Update() override;
	void Update2();
	void Update3();
	void Draw() override;
	bool CollisionCheck(Bullet& bullet);

private:
	float speedX_;
	float speedY_;
	unsigned int color_;
	bool isAlive;
};

