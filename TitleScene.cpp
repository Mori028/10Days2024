#include "TitleScene.h"
#include "DxLib.h"
#include "Input.h"

void TitleScene::Initialize()
{
	//背景
	backGround_ = LoadGraph("Resource//title.png");

	//タイトル
	title_ = LoadGraph("Resource//GameTitle.png");
	title1_ = LoadGraph("Resource//GameTitle1.png");
	title2_ = LoadGraph("Resource//GameTitle2.png");
	title3_ = LoadGraph("Resource//GameTitle3.png");
	title4_ = LoadGraph("Resource//GameTitle4.png");
	title5_ = LoadGraph("Resource//GameTitle5.png");

	//スペース
	space_ = LoadGraph("Resource//Space.png");
	blueSpace_ = LoadGraph("Resource//buleSpace.png");

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

	colorTimer++;
	if (colorTimer >= 100) {
		colorTimer = 0;
	}

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
			colorTimer = 0;
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


	//スペース
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
