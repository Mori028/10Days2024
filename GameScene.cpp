#include "GameScene.h"
#include "Input.h"

void GameScene::Initialize()
{
	//player������
	player_ = std::make_unique<Player>();
	player_->Initialize();

	//map������
	map->Initialize();

	//�w�i
	backGround_ = LoadGraph("Resource//BackGround1.png");

	//
	isNextScene_ = false;

	// �}�b�v�`�b�v
	static const int MAP_SIZE_HEIGHT = 27;
	static const int MAP_SIZE_WIDTH = 20;
	const int blockSize = 60;

	//�u���b�N���
	for (int y = 0; y < MAP_SIZE_HEIGHT; y++) {
		for (int x = 0; x < MAP_SIZE_WIDTH; x++) {

			if (map->GetBlockNum(y, x) != 0)
			{
				//�ʒu�A�T�C�Y�A��ނ��i�[
				player_->SetBlockPos(Vector2{ map->GetBlockPosition(y, x).x_,map->GetBlockPosition(y, x).y_ }, Vector2{ (float)blockSize ,(float)blockSize }, map->GetBlockNum(y, x));
			}
		}
	}

	//�X�N���[���̍ő�l�i�[
	player_->SetMapChipMoveMax(map->GetMapChipMoveMax() - 600);
}

void GameScene::Update()
{
	//2��ڗp
	isNextScene_ = false;

	//�X�N���[���l�n
	map->SetMapChipMove(player_->GetMapChipMove());

	//�X�V
	player_->Update();
	map->Update();

	//����
	if (player_->GetNextSceneFlag())
	{
		isNextScene_ = true;
	}
}

void GameScene::Draw()
{
	//��ʂ̏c��
	int width = 1200;
	int height = 800;

	//�w�i�`��
	DrawExtendGraph(0, 0, width, height, backGround_, true);

	//�`��
	map->Draw();

	player_->Draw();
}

void GameScene::Finalize()
{

}

void GameScene::Reset()
{
	player_->Reset();
}
