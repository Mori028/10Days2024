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
}

void GameScene::Update()
{
	//2��ڗp
	isNextScene_ = false;

	//�X�V
	player_->Update();
	map->Update();

	//����
	if (Input::GetInstance()->KeyTrigger(KEY_INPUT_N))
	{
		isNextScene_ = true;
	}

	SetFontSize(24);
	//Dubug
	DrawFormatString(500, 128, GetColor(200, 200, 200), "N�L�[�Ŏ��̃V�[����", true);

	SetFontSize(16);
}

void GameScene::Draw()
{
	//��ʂ̏c��
	int width = 1200;
	int height = 800;

	//�w�i�`��
	//DrawExtendGraph(0, 0, width, height, backGround_, true);

	//�`��
	map->Draw();

	player_->Draw();
}

void GameScene::Finalize()
{

}
