#include "ClearScene.h"
#include "DxLib.h"
#include "Input.h"

void ClearScene::Initialize()
{
	//背景
	backGround_ = LoadGraph("Resource//BackGroung3.png");

	//タイトル
	clear_ = LoadGraph("Resource//Clear.png");
	clear1_ = LoadGraph("Resource//Clear1.png");

	//スペース
	space_ = LoadGraph("Resource//Space.png");
	space1_ = LoadGraph("Resource//buleSpace.png");

	//
	isNextScene_ = false;

	//
	result_ = 0;

	//
	resultGraph_[0] = LoadGraph("Resource//Drop0.png");
	resultGraph_[1] = LoadGraph("Resource//Drop1.png");
	resultGraph_[2] = LoadGraph("Resource//Drop2.png");
	resultGraph_[3] = LoadGraph("Resource//Drop3.png");
	resultGraph_[4] = LoadGraph("Resource//Drop4.png");
	resultGraph_[5] = LoadGraph("Resource//Drop5.png");
	resultGraph_[6] = LoadGraph("Resource//Drop6.png");
	resultGraph_[7] = LoadGraph("Resource//Drop7.png");
	resultGraph_[8] = LoadGraph("Resource//Drop8.png");
	resultGraph_[9] = LoadGraph("Resource//Drop9.png");
}

void ClearScene::Update()
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
		isNextScene_ = true;
		colorTimer = 0;
	}

	//動き
}

void ClearScene::Draw()
{
	//画面の縦横
	int width = 1200;
	int height = 800;

	//位置情報
	int x = 450;
	int y = 400;
	int size = 80;

	//背景描画
	DrawExtendGraph(0, 0, width, height, backGround_, true);

	//リザルト
	//1000秒超えた時
	if (result_ > 999)
	{
		result_ = 999;
	}

	//
	if (result_ > 99)
	{
		int a = result_ / 100;
		DrawExtendGraph(x, y, x + size, y + size, resultGraph_[a], true);
	}
	else
	{
		DrawExtendGraph(x, y, x + size, y + size, resultGraph_[0], true);
	}

	if (result_ > 9)
	{
		if (result_ > 99)
		{
			int a = result_ - (result_ / 100 * 100);
			a = a / 10;
			DrawExtendGraph(x + size, y, x + size + size, y + size, resultGraph_[a], true);
		}
		else
		{
			int a = result_ / 10;
			DrawExtendGraph(x + size, y, x + size + size, y + size, resultGraph_[a], true);
		}
	}
	else
	{
		DrawExtendGraph(x + size, y, x + size + size, y + size, resultGraph_[0], true);
	}


	//
	int a = result_ - (result_ / 10 * 10);
	DrawExtendGraph(x + size + size, y, x + size + size + size, y + size, resultGraph_[a], true);


	if (colorTimer <= 50) {
		//タイトル
		DrawGraph(300, 200, clear_, true);

		//スペース
		DrawGraph(425, 600, space_, true);
	}
	//カラーチェンジ
	else {
		//タイトル
		DrawGraph(300, 200, clear1_, true);

		//スペース
		DrawGraph(425, 600, space1_, true);
	}

}

void ClearScene::Finalize()
{
}

void ClearScene::Reset()
{
}
