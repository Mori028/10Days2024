#include "ClearScene.h"
#include "DxLib.h"
#include "Input.h"

void ClearScene::Initialize()
{
	//�w�i
	backGround_ = LoadGraph("Resource//BackGroung3.png");

	//�^�C�g��
	clear_ = LoadGraph("Resource//Clear.png");
	clear1_ = LoadGraph("Resource//Clear1.png");

	//�X�y�[�X
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
	//2��ڗp
	isNextScene_ = false;

	colorTimer++;
	if (colorTimer >= 100) {
		colorTimer = 0;
	}

	//�X�y�[�X��������Q�[���V�[����
	if (Input::GetInstance()->KeyTrigger(KEY_INPUT_SPACE))
	{
		isNextScene_ = true;
		colorTimer = 0;
	}

	//����
}

void ClearScene::Draw()
{
	//��ʂ̏c��
	int width = 1200;
	int height = 800;

	//�ʒu���
	int x = 450;
	int y = 400;
	int size = 80;

	//�w�i�`��
	DrawExtendGraph(0, 0, width, height, backGround_, true);

	//���U���g
	//1000�b��������
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
		//�^�C�g��
		DrawGraph(300, 200, clear_, true);

		//�X�y�[�X
		DrawGraph(425, 600, space_, true);
	}
	//�J���[�`�F���W
	else {
		//�^�C�g��
		DrawGraph(300, 200, clear1_, true);

		//�X�y�[�X
		DrawGraph(425, 600, space1_, true);
	}

}

void ClearScene::Finalize()
{
}

void ClearScene::Reset()
{
}
