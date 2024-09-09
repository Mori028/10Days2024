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

	//�q�b�v�h���b�v�t���Ooff
	hipDropF_ = false;
}

void Player::Draw()
{
	//���
	int color = GetColor((int)color_.x_, (int)color_.y_, (int)color_.z_);

	//�`��
	DrawBox(
		(int)pos_.x_,
		(int)pos_.y_,
		(int)(pos_.x_ + size_),
		(int)(pos_.y_ + size_),
		color, true);
}

void Player::Finalize()
{

}

bool Player::BoxCollision()
{

}

void Player::Move()
{
	//�ړ��l
	Vector2 move = { 0,0 };

	//���x
	float speed = 3;

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

	//�n�ʂɂ�����true��
	if (earthFlags)
	{
		hipDropF_ = false;
	}

	//Dubug
	DrawFormatString(0, 0, GetColor(100, 100, 100), "earthFlags %d", earthFlags, true);

	//�d�͂̍ő�l 
	const float MaxGravity = 15;

	//�W�����v�̍ő�l
	const float MaxJump = 10;

	//space�������Ƃ��ǂ��ɂ��邩
	if (Input::GetInstance()->KeyTrigger(KEY_INPUT_SPACE))
	{
 		switch (earthFlags)
		{
			//�n�ʂ���̃W�����v
		case true:

			//�d�͂�0��
			gravityPower_ = 0;

			//�W�����v�͂��ő��
			jumpPower_ = MaxJump;

			//�W�����v�t���O
			jumpFlags_ = true;

			break;

			//�󒆂ɂ���Ƃ�
		case false:

			//��x�W�����v���Ă��邩
			if (jumpFlags_)
			{
				//2��ȏ�łȂ��悤��
				jumpFlags_ = false;

				//
				hipDropF_ = true;
			}

			break;
		}
	}

	//�d�͉��Z
	if (gravityPower_ < MaxGravity)
	{
		gravityPower_ += 0.2f;
	}

	//���͌��Z
	if (jumpPower_ > 0)
	{
		jumpPower_ -= 0.2f;
	}

	//
	if (hipDropF_)
	{
		//�������x
		size_t speed = 5;

		//�d��
		pos_.y_ += gravityPower_ * speed;

		//�X�e�[�W�ɓ����������
		if (BoxCollision())
		{

		}
	}
	else
	{
		//�d��
		pos_.y_ += gravityPower_ - jumpPower_;
	}

	//Dubug
	DrawFormatString(0, 16, GetColor(100, 100, 100), "hipDropF_ %d", hipDropF_, true);

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