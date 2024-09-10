#include "GameScene.h"
#include "Input.h"

void GameScene::Initialize()
{
	//player‰Šú‰»
	player_ = std::make_unique<Player>();
	player_->Initialize();

	//map‰Šú‰»
	map->Initialize();

	//”wŒi
	backGround_ = LoadGraph("Resource//BackGround1.png");

	//
	isNextScene_ = false;
}

void GameScene::Update()
{
	//2‰ñ–Ú—p
	isNextScene_ = false;

	//XV
	player_->Update();
	map->Update();

	//”»’è
	if (Input::GetInstance()->KeyTrigger(KEY_INPUT_N))
	{
		isNextScene_ = true;
	}

	SetFontSize(24);
	//Dubug
	DrawFormatString(500, 128, GetColor(200, 200, 200), "NƒL[‚ÅŸ‚ÌƒV[ƒ“‚Ö", true);

	SetFontSize(16);
}

void GameScene::Draw()
{
	//‰æ–Ê‚Ìc‰¡
	int width = 1200;
	int height = 800;

	//”wŒi•`‰æ
	//DrawExtendGraph(0, 0, width, height, backGround_, true);

	//•`‰æ
	map->Draw();

	player_->Draw();
}

void GameScene::Finalize()
{

}
