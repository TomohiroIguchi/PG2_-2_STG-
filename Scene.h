#ifndef SCENE
#define SCENE
#include "Player.h"
#include "Enemy.h"

class SceneManager {
public:
    enum Scene {
        TITLE,
        GAMEPLAY,
        WIN,
        GAMEOVER
    };

    Scene currentScene;

    SceneManager();
    void SceneChange(Scene newScene);
    void Reset(Player& player, Enemy& enemy1, Enemy& enemy2, Enemy& enemy3, Enemy& enemy4,Enemy& enemy5);
};

#endif 

