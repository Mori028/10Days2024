#include "TitleScene.h"
#include "DxLib.h"
#include "Input.h"

void TitleScene::Initialize()
{
	//�w�i
	backGround_ = LoadGraph("Resource//BackGround2.png");

	//�^�C�g��
	title_ = LoadGraph("Resource//GameTitle.png");

	//�X�y�[�X
	space_ = LoadGraph("Resource//Space.png");

	//
	isNextScene_ = false;
}

void TitleScene::Update()
{
	//2��ڗp
	isNextScene_ = false;

	//�X�y�[�X��������Q�[���V�[����
	if (Input::GetInstance()->KeyTrigger(KEY_INPUT_SPACE))
	{
		isNextScene_ = true;
	}

	//�^�C�g���ɓ���

}

void TitleScene::Draw()
{
	//��ʂ̏c��
	int width = 1200;
	int height = 800;

	//�w�i�`��
	DrawExtendGraph(0, 0, width, height, backGround_, true);

	//�^�C�g��
	DrawGraph(300, 200, title_, true);

	//�X�y�[�X
	DrawGraph(425, 600, space_, true);
}

void TitleScene::Finalize()
{

}
