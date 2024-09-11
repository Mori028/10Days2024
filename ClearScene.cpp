#include "ClearScene.h"
#include "DxLib.h"
#include "Input.h"

void ClearScene::Initialize()
{
	//�w�i
	backGround_ = LoadGraph("Resource//BackGroung3.png");

	//�^�C�g��
	clear_ = LoadGraph("Resource//Clear.png");

	//�X�y�[�X
	space_ = LoadGraph("Resource//Space.png");

	//
	isNextScene_ = false;
}

void ClearScene::Update()
{
	//2��ڗp
	isNextScene_ = false;

	//�X�y�[�X��������Q�[���V�[����
	if (Input::GetInstance()->KeyTrigger(KEY_INPUT_SPACE))
	{
		isNextScene_ = true;
	}

	//����
}

void ClearScene::Draw()
{
	//��ʂ̏c��
	int width = 1200;
	int height = 800;

	//�w�i�`��
	DrawExtendGraph(0, 0, width, height, backGround_, true);

	//�^�C�g��
	DrawGraph(300, 200, clear_, true);

	//�X�y�[�X
	DrawGraph(425, 600, space_, true);
}

void ClearScene::Finalize()
{
}
