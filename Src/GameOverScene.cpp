/**
*@file GameOverScene.cpp
*/

#include "GameOverScene.h"
#include "TitleScene.h"
#include "GLFWEW.h"


/*
*�V�[��������������
*
*@retval true ����������
*@retval false ���������s�B�Q�[���i�s�s�ɂ��A�v���O�������I�����邱��
*/
bool GameOverScene::Initialize() {
	spriteRenderer.Init(1000, "Res/Sprite.vert", "Res/Sprite.frag");
	sprites.reserve(100);
	Sprite spr(Texture::Image2D::Create("Res/GAMEOVER.tga"));
	spr.Scale(glm::vec2(2));
	sprites.push_back(spr);

	return true;
}

/**
*�v���C���[�̓��͂���������.
*/

void GameOverScene::ProcessInput() {

	GLFWEW::Window& window = GLFWEW::Window::Instance();

	if (window.GetGamePad().buttonDown & GamePad::START) {
			SceneStack::Instance().Replace(std::make_shared<TitleScene>());
	}	
}

/*
*�V�[�����X�V����
*
*@param deltaTime �O�񂩂�̍X�V����̌o�ߎ��ԁi�b�j
*/
void GameOverScene::Update(float deltaTime) {
	spriteRenderer.BeginUpdate();
	for (const Sprite& e : sprites) {
		spriteRenderer.AddVertices(e);
	}
	spriteRenderer.EndUpdate();
}

/*
*�V�[����`�悷��
*/
void GameOverScene::Render() {
	const GLFWEW::Window& window = GLFWEW::Window::Instance();
	const glm::vec2 screenSize(window.Width(), window.Height());
	spriteRenderer.Draw(screenSize);
}