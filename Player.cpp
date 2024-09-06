#include "Player.h"
#include "DxLib.h"
#include "Input.h"

//�q�b�v�h���b�v���Ƀp�[�e�B�N��

void Player::Update()
{
	//�ړ�����
	Move();

	//�W�����v����
	Jump();

	//��ʓ��Ɏ��܂鏈��
	FlameIn();
}

void Player::Initialize()
{
	//�����ʒu
	pos_ = { 50,50 };

	//�����J���[
	color_ = { 200,0,0 };

	//���a
	size_ = 32;

	//�d�͂���
	gravityFlag_ = true;

	//�d��
	gravityPower_ = 10;

	//�W�����v�֌W
	jumpFlags_ = false;
	jumpPower_ = 0;
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

void Player::Move()
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

void Player::Jump()
{
	//���n��
	int stageLine = 600;

	//�n�ʂɂ��邩
	bool earthFlags = pos_.y_ + 1 > stageLine + size_;

	//space�������Ƃ��ǂ��ɂ��邩
	if (Input::GetInstance()->KeyPush(KEY_INPUT_SPACE))
	{
		switch (earthFlags)
		{
		case true:

			break;

		case false:

			break;

		default:
			break;
		}
	}

	//�d��
	pos_.y_ += gravityPower_;

}

void Player::FlameIn()
{
	//���n��
	int stageLine = 600;

	//��ʒ[
	int LeftMax = 0;
	int RightMax = 1200;

	//��ʊO�ɂ����Ȃ��悤��
	pos_.x_ = min(pos_.x_, RightMax - size_);
	pos_.x_ = max(pos_.x_, LeftMax);

	//��ʊO�ɂ����Ȃ��悤��
	pos_.y_ = min(pos_.y_, stageLine + size_);
	pos_.y_ = max(pos_.y_, size_);
}