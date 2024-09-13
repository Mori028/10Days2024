#include "TitleScene.h"
#include "DxLib.h"
#include "Input.h"

void TitleScene::Initialize()
{
	//�w�i
	backGround_ = LoadGraph("Resource//title.png");

	//�^�C�g��
	title_ = LoadGraph("Resource//GameTitle.png");
	title1_ = LoadGraph("Resource//GameTitle1.png");
	title2_ = LoadGraph("Resource//GameTitle2.png");
	title3_ = LoadGraph("Resource//GameTitle3.png");
	title4_ = LoadGraph("Resource//GameTitle4.png");
	title5_ = LoadGraph("Resource//GameTitle5.png");

	//�X�y�[�X
	space_ = LoadGraph("Resource//Space.png");
	blueSpace_ = LoadGraph("Resource//buleSpace.png");

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

	colorTimer++;
	if (colorTimer >= 100) {
		colorTimer = 0;
	}

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
			colorTimer = 0;
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
	if (colorTimer >= 0 && colorTimer <= 25) {
		DrawGraph(300, 200, title_, true);
	}else if (colorTimer >= 26 && colorTimer <= 35) {
		DrawGraph(300, 200, title1_, true);
	}
	else if (colorTimer >= 36 && colorTimer <= 45) {
		DrawGraph(300, 200, title2_, true);
	}
	else if (colorTimer >= 46 && colorTimer <= 55) {
		DrawGraph(300, 200, title3_, true);
	}
	else if (colorTimer >= 56 && colorTimer <= 65) {
		DrawGraph(300, 200, title4_, true);
	}
	else{
		DrawGraph(300, 200, title5_, true);
	}


	//�X�y�[�X
	if (colorTimer >= 0 && colorTimer <= 65) {
		DrawGraph(425, 600, space_, true);
	}
	else {
		DrawGraph(425, 600, blueSpace_, true);
	}

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
	colorTimer = 0;
	isSceneChange_ = false;
}
