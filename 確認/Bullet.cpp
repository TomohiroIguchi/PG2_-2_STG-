#include "Bullet.h"

Bullet::Bullet() : posX(0.0f), posY(0.0f), isShot(false), size(10.0f), speed(20.0f) {}

Bullet::~Bullet() {}

void Bullet::Update() {
    if (isShot) {
        posY -= speed;
        if (posY < 0.0f - size) {
            isShot = false;
            posX = 0.0f;
            posY = 0.0f;
        }
    }
}

void Bullet::Shot(float startPosX, float startPosY) {
    if (!isShot) {
        isShot = true;
        posX = startPosX;
        posY = startPosY;
    }
}

void Bullet::Draw() {
    if (isShot) {
        Novice::DrawTriangle(static_cast<int>(posX) - static_cast<int>(size), static_cast<int>(posY), static_cast<int>(posX),
            static_cast<int>(posY) - static_cast<int>(size * 2.0f), static_cast<int>(posX + size), static_cast<int>(posY), WHITE, kFillModeSolid);
    }
}
