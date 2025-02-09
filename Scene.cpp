#include "Scene.h"

SceneManager::SceneManager() : currentScene(TITLE) {}

void SceneManager::SceneChange(Scene newScene) {
	currentScene = newScene;
}

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
//                       プレイヤーと敵のリセット
//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
void SceneManager::Reset(Player& player, Enemy& enemy1, Enemy& enemy2, Enemy& enemy3, Enemy& enemy4, Enemy& enemy5) {
	player.SetPosX(640.0f);
	player.SetPosY(600.0f);
	player.SetIsAlive(true);

	enemy1.SetPosX(640.0f);
	enemy1.SetPosY(200.0f);
	enemy1.SetIsAlive(true);

	enemy2.SetPosX(static_cast<float>(rand() % 800 + 100));
	enemy2.SetPosY(static_cast<float>(rand() % 500 + 100));
	enemy2.SetIsAlive(true);

	enemy3.SetPosX(640.0f);
	enemy3.SetPosY(200.0f);
	enemy3.SetIsAlive(true);

	enemy4.SetPosX(static_cast<float>(rand() % 800 + 100));
	enemy4.SetPosY(static_cast<float>(rand() % 500 + 100));
	enemy4.SetIsAlive(true);

	enemy5.SetPosX(static_cast<float>(rand() % 800 + 100));
	enemy5.SetPosY(static_cast<float>(rand() % 500 + 100));
	enemy5.SetIsAlive(true);
	//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::


		//::::::::::::::::::::::::::::::::::::::::::::
		//                  弾のリセット
		//::::::::::::::::::::::::::::::::::::::::::::
	for (int i = 0; i < BulletCount; i++) {
		Bullet* bullet = &player.GetBullets()[i];
		bullet->SetPosX(0.0f);
		bullet->SetPosY(0.0f);
		bullet->SetIsShot(false);
	}
	//::::::::::::::::::::::::::::::::::::::::::::

}
