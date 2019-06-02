/**
*@file MainGameScene.cpp
*/
#include "MainGameScene.h"
#include "StatusScene.h"
#include "GameOverScene.h"
#include "GLFWEW.h"


/*
*シーンを初期化する
*
*@retval true 初期化成功
*@retval false 初期化失敗。ゲーム進行不可につき、プログラムを終了すること
*/
bool MainGameScene::Initialize() {
	spriteRenderer.Init(1000, "Res/Sprite.vert", "Res/Sprite.frag");
	sprites.reserve(100);
	Sprite spr(Texture::Image2D::Create("Res/TitleLogo.tga"));
	spr.Scale(glm::vec2(2));
	sprites.push_back(spr);

	return true;
}

/**
*プレイヤーの入力を処理する.
*/
void MainGameScene::ProcessInput() {
	GLFWEW::Window& window = GLFWEW::Window::Instance();

	/*if (!flag) {
		if (window.GetGamePad().buttonDown & GamePad::START) {
			flag = true;
			SceneStack::Instance().Push(std::make_shared<StatusScene>());
		}
	}
	else {*/
		if (window.GetGamePad().buttonDown & GamePad::START) {
			SceneStack::Instance().Replace(std::make_shared<GameOverScene>());
		}	
	//}
}

/*
*シーンを更新する
*
*@param deltaTime 前回からの更新からの経過時間（秒）
*/
void MainGameScene::Update(float deltaTime) {
	spriteRenderer.BeginUpdate();
	for (const Sprite& e : sprites) {
		spriteRenderer.AddVertices(e);
	}
	spriteRenderer.EndUpdate();
}

/*
*シーンを描画する
*/
void MainGameScene::Render() {
	const GLFWEW::Window& window = GLFWEW::Window::Instance();
	const glm::vec2 screenSize(window.Width(), window.Height());
	spriteRenderer.Draw(screenSize);
}

void Finalize(){

}