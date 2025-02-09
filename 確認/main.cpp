#define _USE_MATH_DEFINES
#include <Novice.h>
#include "Object.h"
#include "Bullet.h"
#include "Player.h"
#include "Enemy.h"
#include "Scene.h"
#include "math.h"
#include "time.h"


const char kWindowTitle[] = "GC1B_02_イグチ‗トモヒロ_評価課題2_STGクラス化";
const int kWindowWidth = 1280;
const int kWindowHeight = 720;



// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, kWindowWidth, kWindowHeight);

	srand(static_cast<int>(time(nullptr)));

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	//const int enemyCount = 10;

	SceneManager sceneManager;

	Player player(kWindowWidth / 2.0f, 600.0f, 30.0f, 8.0f, 8.0f, GREEN);
	Enemy enemy1(kWindowWidth / 2.0f, 200.0f, 20.0f, 10.0f, 10.0f, RED);
	Enemy enemy2(static_cast<float>(rand() % 800 + 100), static_cast<float>(rand() % 500 + 100), 5.0f, 14.0f, 14.0f, RED);
	Enemy enemy3(kWindowWidth / 2.0f, 200.0f, 20.0f, 10.0f, 10.0f, RED);
	Enemy enemy4(static_cast<float>(rand() % 800 + 100), static_cast<float>(rand() % 500 + 100), 20.0f, 10.0f, 10.0f, RED);
	//Enemy* enemys[enemyCount];

	/*for (int i = 0; i < enemyCount; i++){
		Enemy enemys[i](static_cast<float>(rand() % 800 + 100), static_cast<float>(rand() % 600 - 100), 20.0f, 14.0f, 14.0f, RED);
	}*/
	
	//enemys[i](static_cast<float>(rand() % 800 + 100), static_cast<float>(rand() % 600 - 100), 20.0f, 14.0f, 14.0f, RED);

	int titleGraph = Novice::LoadTexture("./Resources/title.png");
	int pressSpaceToStartGraph = Novice::LoadTexture("./Resources/PressSPACEToStart.png");
	int gameOverGraph = Novice::LoadTexture("./Resources/gameOver.png");

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		switch (sceneManager.currentScene) {
		case SceneManager::TITLE:
			if (keys[DIK_SPACE]) {
				sceneManager.Reset(player, enemy1, enemy2, enemy3, enemy4);
				sceneManager.SceneChange(SceneManager::GAMEPLAY);
			}
			break;

		case SceneManager::GAMEPLAY:
			player.Move(keys);
			player.Update();
			enemy1.Update();
			enemy2.Update();
			enemy3.Update2();
			enemy4.Update3();

			//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
			//                              当たり判定
			//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
			for (int i = 0; i < BulletCount; i++) {
				Bullet *bullet = &player.GetBullets()[i];
				if (bullet->GetIsShot()) {
					if (enemy1.CollisionCheck(*bullet) && enemy1.GetIsAlive()) {
						enemy1.SetIsAlive(false);
						bullet->SetIsShot(false);
					} else if (enemy2.CollisionCheck(*bullet) && enemy2.GetIsAlive()) {
						enemy2.SetIsAlive(false);
						bullet->SetIsShot(false);
					} else if (enemy3.CollisionCheck(*bullet) && enemy3.GetIsAlive()) {
						enemy3.SetIsAlive(false);
						bullet->SetIsShot(false);
					} else if (enemy4.CollisionCheck(*bullet) && enemy4.GetIsAlive()) {
						enemy4.SetIsAlive(false);
						bullet->SetIsShot(false);
					}
				}
			}

			if (player.CollisionCheck(enemy1) && enemy1.GetIsAlive()) {
				player.SetIsAlive(false);
			}
			if (player.CollisionCheck(enemy2) && enemy2.GetIsAlive()) {
				player.SetIsAlive(false);
			}
			if (player.CollisionCheck(enemy3) && enemy3.GetIsAlive()) {
				player.SetIsAlive(false);
			}
			if (player.CollisionCheck(enemy4) && enemy4.GetIsAlive()) {
				player.SetIsAlive(false);
			}
			//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::



			//:::::::::::::::::::::::::::::::::::::::::::::::::::
			//                    シーンチェンジ
			//:::::::::::::::::::::::::::::::::::::::::::::::::::
			if (!enemy1.GetIsAlive() && !enemy2.GetIsAlive() && !enemy3.GetIsAlive() && !enemy4.GetIsAlive()) {
				sceneManager.SceneChange(SceneManager::WIN);
			}
			if (!player.GetIsAlive()) {
				sceneManager.SceneChange(SceneManager::GAMEOVER);
			}
			break;
			//:::::::::::::::::::::::::::::::::::::::::::::::::::


		case SceneManager::WIN:
		case SceneManager::GAMEOVER:

			//::::::::::::::::::::::::::::::::::::::::::::::::
			//                  タイトルに戻る
			//::::::::::::::::::::::::::::::::::::::::::::::::
			if (keys[DIK_RETURN]) {
				sceneManager.SceneChange(SceneManager::TITLE);
			}
			break;
			//::::::::::::::::::::::::::::::::::::::::::::::::

		}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		switch (sceneManager.currentScene) {
		case SceneManager::TITLE:
			//Novice::DrawBox(0, 0, 1280, 720, 0.0f, BLACK, kFillModeSolid);
			Novice::DrawSprite(0, 0, titleGraph, 1.0f, 1.0f, 0.0f, WHITE);
			Novice::DrawSprite(0, 0, pressSpaceToStartGraph, 1.0f, 1.0f, 0.0f, WHITE);
			//Novice::ScreenPrintf(550, 360, "Press SPACE to Start", WHITE);
			break;
		case SceneManager::GAMEPLAY:
			Novice::DrawBox(0, 0, 1280, 720, 0.0f, BLACK, kFillModeSolid);
			player.Draw();
			enemy1.Draw();
			enemy2.Draw();
			enemy3.Draw();
			enemy4.Draw();

			Novice::ScreenPrintf(10, 10, "Enemy1 isAlive = %d", enemy1.GetIsAlive());
			Novice::ScreenPrintf(10, 30, "Enemy2 isAlive = %d", enemy2.GetIsAlive());
			Novice::ScreenPrintf(10, 50, "Enemy3 isAlive = %d", enemy3.GetIsAlive());
			Novice::ScreenPrintf(10, 70, "Enemy3 isAlive = %d", enemy4.GetIsAlive());
			Novice::ScreenPrintf(10, 90, "WASD : player Move");
			Novice::ScreenPrintf(10, 110, "shoot : SPACE");
			Novice::ScreenPrintf(10, 130, "enemy respawn : R");
			break;
		case SceneManager::WIN:
			Novice::ScreenPrintf(600, 360, "You Win!", WHITE);
			Novice::ScreenPrintf(600, 380, "press R to return to title", WHITE);
			break;
		case SceneManager::GAMEOVER:
			Novice::DrawSprite(0, 0, gameOverGraph, 1.0f, 1.0f, 0.0f, WHITE);
			/*Novice::ScreenPrintf(600, 360, "Game Over", WHITE);
			Novice::ScreenPrintf(600, 380, "press ENTER to return to title", WHITE);*/
			break;
		}

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
