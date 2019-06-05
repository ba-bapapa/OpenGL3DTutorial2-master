/**
*@file StatusScene.cpp
*/

#include "StatusScene.h"
#include "GLFWEW.h"


/*
*�V�[��������������
*
*@retval true ����������
*@retval false ���������s�B�Q�[���i�s�s�ɂ��A�v���O�������I�����邱��
*/
bool StatusScene::Initialize() {
	spriteRenderer.Init(1000, "Res/Sprite.vert", "Res/Sprite.frag");
	sprites.reserve(100);
	Sprite spr(Texture::Image2D::Create("Res/Title.tga"));
	spr.Scale(glm::vec2(2));
	sprites.push_back(spr);

	//font
	fontRenderer.Init(1000);
	fontRenderer.LoadFromFile("Res/font.fnt");

	return true;
}

/**
*�v���C���[�̓��͂���������.
*/
void StatusScene::ProcessInput() {

	GLFWEW::Window& window = GLFWEW::Window::Instance();

	if (window.GetGamePad().buttonDown & GamePad::START) {

		SceneStack::Instance().Pop();
	}
}

/*
*�V�[�����X�V����
*
*@param deltaTime �O�񂩂�̍X�V����̌o�ߎ��ԁi�b�j
*/
void StatusScene::Update(float deltaTime) {
	spriteRenderer.BeginUpdate();
	for (const Sprite& e : sprites) {
		spriteRenderer.AddVertices(e);
	}
	spriteRenderer.EndUpdate();

	const GLFWEW::Window& window = GLFWEW::Window::Instance();
	const float w = window.Width();
	const float h = window.Height();
	const float lineHeight = fontRenderer.LineHeight();
	fontRenderer.BeginUpdate();
	fontRenderer.AddString(glm::vec2(-w * 0.5f + 32, h * 0.5f - lineHeight), L"�X�e�[�^�X");
	fontRenderer.EndUpdate();
}

/*
*�V�[����`�悷��
*/
void StatusScene::Render() {
	const GLFWEW::Window& window = GLFWEW::Window::Instance();
	const glm::vec2 screenSize(window.Width(), window.Height());
	spriteRenderer.Draw(screenSize);

	fontRenderer.Draw(screenSize);
}