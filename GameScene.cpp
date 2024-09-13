#include "GameScene.h"
#include "Input.h"

void GameScene::Initialize()
{
	//player初期化
	player_ = std::make_unique<Player>();
	player_->Initialize();

	//map初期化
	map->Initialize();

	//背景
	backGround_ = LoadGraph("Resource//BackGround1.png");

	//
	isNextScene_ = false;

	//ブロック情報
	for (int y = 0; y < MAP_SIZE_HEIGHT; y++) {
		for (int x = 0; x < MAP_SIZE_WIDTH; x++) {

			if (map->GetBlockNum(y, x) != 0)
			{
				//位置、サイズ、種類を格納
				player_->SetBlockPos(Vector2{ map->GetBlockPosition(y, x).x_,map->GetBlockPosition(y, x).y_ }, Vector2{ (float)blockSize ,(float)blockSize }, map->GetBlockNum(y, x));
			}
		}
	}

	//スクロールの最大値格納
	player_->SetMapChipMoveMax(map->GetMapChipMoveMax() - 800);
}

void GameScene::Update()
{
	//2回目用
	isNextScene_ = false;

	//スクロール値渡
	map->SetMapChipMove(player_->GetMapChipMove());

	//更新
	player_->Update();
	map->Update();

	//判定
	if (player_->GetNextSceneFlag())
	{
		isNextScene_ = true;
	}
}

void GameScene::Draw()
{
	//画面の縦横
	int width = 1200;
	int height = 800;

	//背景描画
	DrawExtendGraph(0, 0, width, height, backGround_, true);

	//描画
	//map->Draw();

	player_->Draw();
}

void GameScene::Finalize()
{

}

void GameScene::Reset()
{
	//プレイヤー関係初期化
	player_->Reset();
	player_->ResetBlock();

	//ブロック情報
	for (int y = 0; y < MAP_SIZE_HEIGHT; y++) {
		for (int x = 0; x < MAP_SIZE_WIDTH; x++) {

			if (map->GetBlockNum(y, x) != 0)
			{
				//位置、サイズ、種類を格納
				player_->SetBlockPos(Vector2{ map->GetBlockPosition(y, x).x_,map->GetBlockPosition(y, x).y_ }, Vector2{ (float)blockSize ,(float)blockSize }, map->GetBlockNum(y, x));
			}
		}
	}

	//スクロールの最大値格納
	player_->SetMapChipMoveMax(map->GetMapChipMoveMax() - 800);
}
