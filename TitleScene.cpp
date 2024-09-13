#include "TitleScene.h"
#include "DxLib.h"
#include "Input.h"

void TitleScene::Initialize()
{
	//�w�i
	backGround_ = LoadGraph("Resource//title.png");

	//�^�C�g��
	title_ = LoadGraph("Resource//GameTitle.png");

	//�X�y�[�X
	space_ = LoadGraph("Resource//Space.png");

	//�V�[���J�ڈÓ]
	sceneChange1Png_ = LoadGraph("Resource//Black2.png");
	sceneChange2Png_ = LoadGraph("Resource//Black3.png");
	sceneChange3Png_ = LoadGraph("Resource//Black4.png");


	//
	isNextScene_ = false;
}

void TitleScene::Update()
{
	//2��ڗp
	isNextScene_ = false;

	//�X�y�[�X��������Q�[���V�[����
	if (Input::GetInstance()->KeyTrigger(KEY_INPUT_SPACE))
	{
		isSceneChange_ = true;

	}
	if (isSceneChange_ == true) {
		sceneChangeTimer++;
		if (sceneChangeTimer >= 61) {
			sceneChangeCount = 1;
		}

		if (sceneChangeCount == 1) {
			sceneChangeTimer = 0;
			isNextScene_ = true;
			sceneChangeCount = 0;
		}
	}


	//�^�C�g���ɓ���

}

void TitleScene::Draw()
{
	//��ʂ̏c��
	int width = 1200;
	int height = 800;

	//�w�i�`��
	DrawExtendGraph(0, 0, width, height, backGround_, true);

	//�^�C�g��
	DrawGraph(300, 200, title_, true);

	//�X�y�[�X
	DrawGraph(425, 600, space_, true);

	if (sceneChangeTimer >= 1 && sceneChangeTimer <= 20) {
		DrawGraph(0, 0, sceneChange1Png_, true);
	}
	else if (sceneChangeTimer >= 21 && sceneChangeTimer <= 40) {
		DrawGraph(0, 0, sceneChange2Png_, true);
	}
	else if (sceneChangeTimer >= 41 && sceneChangeTimer <= 60) {
		DrawGraph(0, 0, sceneChange3Png_, true);
	}

}

void TitleScene::Finalize()
{

}

void TitleScene::Reset()
{
}
