#include "Player.h"
#include "DxLib.h"
#include "Input.h"

void Player::Update()
{
	//�ړ��l
	Vector2 move = { 0,0 };

	//���x
	size_t speed = 3;

	//�ړ�
	move.x_ += Input::GetInstance()->KeyPush(KEY_INPUT_D) - Input::GetInstance()->KeyPush(KEY_INPUT_A);
	move.y_ += Input::GetInstance()->KeyPush(KEY_INPUT_S) - Input::GetInstance()->KeyPush(KEY_INPUT_W);

	//���x���|����
	move *= speed;

	//�ړ�
	pos_ += move;
}

void Player::Initialize()
{
	//�����ʒu
	pos_ = { 50,50 };

	//�����J���[
	color_ = { 200,0,0 };

	size_ = 16;
}

void Player::Draw()
{
	//���
	int color = GetColor(color_.x_, color_.y_, color_.z_);

	//�`��
	DrawBox(
		pos_.x_, 
		pos_.y_, 
		pos_.x_ + size_, 
		pos_.y_ + size_, 
		color, true);
}

void Player::Finalize()
{
}
