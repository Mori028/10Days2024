#include "TitleScene.h"
#include "DxLib.h"
#include "Input.h"

void TitleScene::Initialize()
{
	//背景
	backGround_ = LoadGraph("Resource//title.png");

	//タイトル
	title_ = LoadGraph("Resource//GameTitle.png");

	//スペース
	space_ = LoadGraph("Resource//Space.png");

	//シーン遷移暗転
	sceneChange1Png_ = LoadGraph("Resource//Black2.png");
	sceneChange2Png_ = LoadGraph("Resource//Black3.png");
	sceneChange3Png_ = LoadGraph("Resource//Black4.png");


	//
	isNextScene_ = false;
}

void TitleScene::Update()
{
	//2回目用
	isNextScene_ = false;

	//スペース押したらゲームシーンに
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


	//タイトルに動き

}

void TitleScene::Draw()
{
	//画面の縦横
	int width = 1200;
	int height = 800;

	//背景描画
	DrawExtendGraph(0, 0, width, height, backGround_, true);

	//タイトル
	DrawGraph(300, 200, title_, true);

	//スペース
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
