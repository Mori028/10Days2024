#include "TitleScene.h"
#include "DxLib.h"
#include "Input.h"

void TitleScene::Initialize()
{
	//背景
	backGround_ = LoadGraph("Resource//BackGround2.png");

	//タイトル
	title_ = LoadGraph("Resource//GameTitle.png");

	//スペース
	space_ = LoadGraph("Resource//Space.png");

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
		isNextScene_ = true;
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
}

void TitleScene::Finalize()
{

}
