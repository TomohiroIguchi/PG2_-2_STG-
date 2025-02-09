#pragma once
#include "Object.h"
#include "Bullet.h"
#include "Enemy.h"

const int BulletCount = 10;

class Player : public Object {
private:
    Bullet bullets[BulletCount];
    float bulletCoolTime;
    float speedX_;
    float speedY_;
    unsigned int color_;
    bool isAlive;

public:

    bool GetIsAlive() const { return isAlive; }
    void SetIsAlive(bool alive) { isAlive = alive; }


    Bullet* GetBullets();
    Player(float posX, float posY, float radius, float speedX, float speedY, unsigned int color);
    ~Player();
    void Update() override;
    void Draw() override;
    void Move(char *keys);
    bool CollisionCheck(Enemy &enemy);
    void Reset();

};
