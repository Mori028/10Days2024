#include "GameScene.h"
#include "Input.h"

void GameScene::Initialize()
{
	//player������
	player_ = std::make_unique<Player>();
	player_->Initialize();

	//�^�C���֐�
	time_ = std::make_unique<Time>();
	time_->Initialize();

	//map������
	map->Initialize();

	//�w�i
	backGround_ = LoadGraph("Resource//BackGround1.png");
	//
	isNextScene_ = false;

	//�u���b�N���
	for (int i = 0; i < map->GetStageMaxNum(); i++) {
		for (int y = 0; y < map->GetMapChipSizeMax(); y++) {
			for (int x = 0; x < MAP_SIZE_WIDTH; x++) {

				if (map->GetBlockNum(0, y, x) != 0)
				{
					//�ʒu�A�T�C�Y�A��ނ��i�[
					player_->SetBlockPos(Vector2{ map->GetBlockPosition(i,y, x).x_,map->GetBlockPosition(i,y, x).y_ }, Vector2{ (float)blockSize ,(float)blockSize }, map->GetBlockNum(i, y, x));
				}
			}
		}
	}

	//�X�N���[���̍ő�l�i�[
		player_->SetMapChipMoveMax(map->GetMapChipMoveMax() - 800);
	}

void GameScene::Update()
{
	//2��ڗp
	isNextScene_ = false;

	//�X�N���[���l�n
	map->SetMapChipMove(player_->GetMapChipMove());

	//�X�V
	player_->Update();
	time_->Update();
	map->Update();

	//����
	if (player_->GetNextSceneFlag())
	{
		isNextScene_ = true;
	}

	//�Ƃ��̏�ɍs������^�C�����Z
	if (player_->AddTime())
	{
		size_t addTime = 5;
		time_->AddTime(addTime);
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
	time_->Draw();
}

void GameScene::Finalize()
{

}

void GameScene::Reset()
{
	//���ԃ��Z�b�g
	time_->Reset();

	//�v���C���[�֌W������
	player_->Reset();
	player_->ResetBlock();

	//�u���b�N���
	for (int i = 0; i < map->GetStageMaxNum(); i++) {
		for (int y = 0; y < map->GetMapChipSizeMax(); y++) {
			for (int x = 0; x < MAP_SIZE_WIDTH; x++) {

				if (map->GetBlockNum(0, y, x) != 0)
				{
					//�ʒu�A�T�C�Y�A��ނ��i�[
					player_->SetBlockPos(Vector2{ map->GetBlockPosition(i, y, x).x_,map->GetBlockPosition(i, y, x).y_ }, Vector2{ (float)blockSize ,(float)blockSize }, map->GetBlockNum(i, y, x));
				}
			}
		}
	}

	//�X�N���[���̍ő�l�i�[
		player_->SetMapChipMoveMax(map->GetMapChipMoveMax() - 800);
	}
