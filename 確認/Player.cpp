#include "Player.h"

Player::Player(float posX, float posY, float radius, float speedX, float speedY, unsigned int color) :
    Object(posX, posY, radius), isAlive(true), bulletCoolTime(0.0f), speedX_(speedX), speedY_(speedY), color_(color) {
    for (int i = 0; i < BulletCount; i++) {
        bullets[i] = Bullet();
    }
}

Player::~Player() {}

void Player::Update() {
    if (isAlive) {
        for (int i = 0; i < BulletCount; i++) {
            bullets[i].Update();
        }
    }
}

void Player::Draw() {
    if (isAlive) {
        Novice::DrawEllipse(static_cast<int>(posX), static_cast<int>(posY), static_cast<int>(radius), static_cast<int>(radius), 0.0f, color_, kFillModeSolid);
        for (int i = 0; i < BulletCount; i++) {
            bullets[i].Draw();
        }
    }
}

void Player::Move(char *keys) {
    if (isAlive) {
        if (keys[DIK_W] && posY - radius > 0.0f) {
            posY -= speedY_;
        }
        if (keys[DIK_S] && posY + radius < HEIGHT) {
            posY += speedY_;
        }
        if (keys[DIK_A] && posX - radius > 0.0f) {
            posX -= speedX_;
        }
        if (keys[DIK_D] && posX + radius < WIDTH) {
            posX += speedX_;
        }

        if (keys[DIK_SPACE] && bulletCoolTime <= 0.0f) {
            bulletCoolTime = 10.0f;
            for (int i = 0; i < BulletCount; i++) {
                if (!bullets[i].GetIsShot()) {
                    bullets[i].Shot(posX, posY);
                    break;
                }
            }
        }
        if (bulletCoolTime > 0.0f) {
            bulletCoolTime--;
        }
    }
}

//:::::::::::::::::::::::::::::::::::::::::::::::::::::
//                   弾の包含
//:::::::::::::::::::::::::::::::::::::::::::::::::::::
Bullet *Player::GetBullets() {
    return bullets;
}
//:::::::::::::::::::::::::::::::::::::::::::::::::::::


//:::::::::::::::::::::::::::::::::::::::::::::::::::::
//                   当たり判定の関数
//:::::::::::::::::::::::::::::::::::::::::::::::::::::
bool Player::CollisionCheck(Enemy &enemy) {
    float deltaX = posX - enemy.GetPosX();
    float deltaY = posY - enemy.GetPosY();
    float distance = deltaX * deltaX + deltaY * deltaY;
    float radiusSum = radius + enemy.GetRadius();
    return distance <= (radiusSum * radiusSum);
}
//:::::::::::::::::::::::::::::::::::::::::::::::::::::


//:::::::::::::::::::::::::::::::::::::::::::::::::::::
//                プレイヤーのリセット関数
//:::::::::::::::::::::::::::::::::::::::::::::::::::::
void Player::Reset() {
    isAlive = true;
    posX = 640.0f;
    posY = 600.0f;

    for (int i = 0; i < BulletCount; i++) {
        bullets[i].SetPosX(0.0f);
        bullets[i].SetPosY(0.0f);
        bullets[i].SetIsShot(false);
    }
}
//:::::::::::::::::::::::::::::::::::::::::::::::::::::