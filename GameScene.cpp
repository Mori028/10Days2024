#include "GameScene.h"
#include "Input.h"

void GameScene::Initialize()
{
	//playerϊ»
	player_ = std::make_unique<Player>();
	player_->Initialize();

	//mapϊ»
	map->Initialize();

	//wi
	backGround_ = LoadGraph("Resource//BackGround1.png");

	//
	isNextScene_ = false;
}

void GameScene::Update()
{
	//2ρΪp
	isNextScene_ = false;

	//XV
	player_->Update();
	map->Update();

	//»θ
	if (Input::GetInstance()->KeyTrigger(KEY_INPUT_N))
	{
		isNextScene_ = true;
	}

	SetFontSize(24);
	//Dubug
	DrawFormatString(500, 128, GetColor(200, 200, 200), "NL[ΕΜV[Φ", true);

	SetFontSize(16);
}

void GameScene::Draw()
{
	//ζΚΜc‘
	int width = 1200;
	int height = 800;

	//wi`ζ
	//DrawExtendGraph(0, 0, width, height, backGround_, true);

	//`ζ
	map->Draw();

	player_->Draw();
}

void GameScene::Finalize()
{

}
