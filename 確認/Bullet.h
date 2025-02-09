#pragma once
#include "Object.h"

class Bullet {
public:
    float GetPosX() const { return posX; }
    float GetPosY() const { return posY; }
    bool GetIsShot() const { return isShot; }
    float GetSize() const { return size; }
    float GetSpeed() const { return speed; }

    void SetPosX(float x) { posX = x; }
    void SetPosY(float y) { posY = y; }
    void SetIsShot(bool shot) { isShot = shot; }
    void SetSize(float s) { size = s; }
    void SetSpeed(float s) { speed = s; }

    Bullet();
    ~Bullet();
    void Update();
    void Shot(float startPosX, float startPosY);
    void Draw();

private:
    float posX;
    float posY;
    bool isShot;
    float size;
    float speed;
};
