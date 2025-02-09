#include "Enemy.h"


Enemy::Enemy(float posX, float posY, float radius, float speedX, float speedY, unsigned int color) :
    Object(posX, posY, radius), isAlive(true), speedX_(speedX), speedY_(speedY), color_(color) {
}

Enemy::~Enemy() {}

void Enemy::Update() {
    if (isAlive) {
        posX += speedX_;
        posY += speedY_;

        if (posX - (radius / 2.0f) < 0.0f || posX + (radius / 2.0f) > 1280.0f) {
            speedX_ *= -1.0f;
        }
        if (posY - (radius / 2.0f) < 0.0f || posY + (radius / 2.0f) > 720.0f) {
            speedY_ *= -1.0f;
        }
    }
}

void Enemy::Update2() {
    if (isAlive) {
        posX += speedX_;
        if (posX - (radius / 2.0f) < 0.0f || posX + (radius / 2.0f) > 1280.0f) {
            speedX_ *= -1.0f;
        }
    }
}

void Enemy::Update3() {
    if (isAlive) {
        posY += speedY_;
        if (posY - (radius / 2.0f) < 0.0f || posY + (radius / 2.0f) > 720.0f) {
            speedY_ *= -1.0f;
        }
    }
}

void Enemy::Draw() {
    if (isAlive) {
        Novice::DrawEllipse(static_cast<int>(posX), static_cast<int>(posY), static_cast<int>(radius),
            static_cast<int>(radius), 0.0f, color_, kFillModeSolid);
    }
}
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::


//:::::::::::::::::::::::::::::::::::::::::::::::::::::
//                   当たり判定の関数
//:::::::::::::::::::::::::::::::::::::::::::::::::::::
bool Enemy::CollisionCheck(Bullet& bullet) {
    float deltaX = posX - bullet.GetPosX();
    float deltaY = posY - bullet.GetPosY();
    float distance = deltaX * deltaX + deltaY * deltaY;
    float radiusSum = radius + bullet.GetSize();
    return distance <= (radiusSum * radiusSum);
    //:::::::::::::::::::::::::::::::::::::::::::::::::::::

}
