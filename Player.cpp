#include "Player.h"
#include "DxLib.h"
#include "Input.h"

//�q�b�v�h���b�v���Ƀp�[�e�B�N��

void Player::Update()
{
	//�W�����v����
	Jump();

	//�ړ�����
	Move();

	//�u���b�N����
	//Collision();

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
	size_.x_ = 20;
	size_.y_ = 40;

	//�d�͂���
	gravityFlag_ = true;

	//�d��
	gravityPower_ = 10;

	//�W�����v�֌W
	jumpFlags_ = false;
	jumpPower_ = 0;

	//�q�b�v�h���b�v�t���Ooff
	hipDropF_ = false;

	//
	move_ = { 0,0 };

	//
	blockF_ = false;

	//�摜�ǂݍ���
	playerPng_ = LoadGraph("Resource//player.png");
}

void Player::Draw()
{
	//���
	int color = GetColor((int)color_.x_, (int)color_.y_, (int)color_.z_);

	//Dubug
	DrawFormatString(0, 48, GetColor(100, 100, 100), "pos %f,%f", pos_.x_, pos_.y_, true);

	//�`��
	DrawBox(
		(int)pos_.x_ - size_.x_,
		(int)pos_.y_ - size_.y_ + 1,
		(int)(pos_.x_ + size_.x_),
		(int)(pos_.y_ + 1 + size_.y_),
		color, true);

	DrawExtendGraph(
		(int)pos_.x_ - size_.x_,
		(int)pos_.y_ - size_.y_ + 1,
		(int)(pos_.x_ + size_.x_),
		(int)(pos_.y_ + 1 + size_.y_),
		playerPng_, true);
}

void Player::Finalize()
{

}

void Player::Move()
{
	//���x
	float speed = 5;

	//�ړ�
	move_.x_ += Input::GetInstance()->KeyPush(KEY_INPUT_D) - Input::GetInstance()->KeyPush(KEY_INPUT_A);
	//move_.y_ += Input::GetInstance()->KeyPush(KEY_INPUT_S) - Input::GetInstance()->KeyPush(KEY_INPUT_W);

	//���x���|����
	move_.x_ *= speed;

	//�폜
	ans = false;

	//�ړ�
	pos_.x_ += move_.x_;

	//����
	//test
	//�X�e�[�W�ɓ����������
	if (CheckHit(testS, size))
	{
		if (hipDropF_)
		{
			testS = { -100,-100 };
		}
		else
		{
			//�C��
			while (CheckHit(testS, size))
			{
				//���C��
				if (CheckHitX(testS, size))
				{
					while (CheckHitX(testS, size))
					{
						bool X = move_.x_ > 0;

						if (X)
						{
							pos_.x_ -= 1.0f;
						}
						else
						{
							pos_.x_ += 1.0f;
						}
					}
				}
			}
		}
	}
	else
	{
		ans = true;
		blockF_ = false;
	}

	//�ړ�
	pos_.y_ += move_.y_;

	//����
	//test
	//�X�e�[�W�ɓ����������
	if (CheckHit(testS, size))
	{
		if (hipDropF_)
		{
			testS = { -100,-100 };
		}
		else
		{
			//�c�C��
			if (CheckHitY(testS, size))
			{
				while (CheckHitY(testS, size))
				{
					bool  Y = move_.y_ > 0;

					if (Y)
					{
						pos_.y_ -= 1.0f;
						blockF_ = true;
					}
					else
					{
						pos_.y_ += 1.0f;
						jumpPower_ = 0;
					}
				}
			}
		}
	}
	else
	{
		ans = true;
		blockF_ = false;
	}

	//Dubug
	DrawFormatString(0, 32, GetColor(100, 100, 100), "ans %d", ans, true);
	DrawBox(testS.x_ - size, testS.y_ - size, testS.x_ + size, testS.y_ + size, GetColor(200, 0, 255), ans);
}

void Player::Jump()
{
	//�ړ��l
	move_ = { 0,0 };

	//���n��
	int stageLine = 600;

	//�n�ʂɂ��邩
	bool earthFlags = pos_.y_ + 1 > stageLine + size_.y_;

	//�n�ʂɂ�����true��
	if (earthFlags)
	{
		hipDropF_ = false;
	}

	//Dubug
	DrawFormatString(0, 0, GetColor(100, 100, 100), "earthFlags %d", earthFlags, true);

	//�d�͂̍ő�l 
	const float MaxGravity = 5;

	//�W�����v�̍ő�l
	const float MaxJump = 30;

	//space�������Ƃ��ǂ��ɂ��邩
	if (Input::GetInstance()->KeyTrigger(KEY_INPUT_SPACE))
	{
		switch (earthFlags || blockF_)
		{
			//�n�ʂ���̃W�����v
		case true:

			//�d�͂�0��
			gravityPower_ = 0;

			//�W�����v�͂��ő��
			jumpPower_ = MaxJump;

			//�W�����v�t���O
			jumpFlags_ = true;

			//�u���b�N�ɐG��Ă��邩
			blockF_ = false;

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

				jumpPower_ = 0;
			}

			break;
		}
	}

	//�d�͉��Z
	if (gravityPower_ < MaxGravity)
	{
		gravityPower_ += 1.0f;
	}

	//���͌��Z
	if (jumpPower_ > 0)
	{
		jumpPower_ -= 1.0f;
	}
	else
	{
		jumpFlags_ = false;
		jumpPower_ = 0;
	}

	//
	if (hipDropF_)
	{
		//�������x
		size_t speed = 10;

		//�d��
		move_.y_ += gravityPower_ * speed;
	}
	else
	{
		//�d��
		move_.y_ += gravityPower_ - jumpPower_;
	}

	//Dubug
	DrawFormatString(0, 16, GetColor(100, 100, 100), "hipDropF_ %d", hipDropF_, true);

}

void Player::Particle()
{

}

void Player::FlameIn()
{
	//���n��
	int stageLine = 600;

	//��ʒ[
	int LeftMax = 0;
	int RightMax = 1200;

	//��ʊO�ɂ����Ȃ��悤��
	pos_.x_ = min(pos_.x_, RightMax - size_.x_);
	pos_.x_ = max(pos_.x_, LeftMax);

	//��ʊO�ɂ����Ȃ��悤��
	pos_.y_ = min(pos_.y_, stageLine + size_.y_);
	pos_.y_ = max(pos_.y_, size_.y_);
}

bool Player::CheckHit(Vector2 pos, float size)
{
	// �l��0�����Ȃ�߂荞��ł�B
	bool X = std::abs(pos.x_ - pos_.x_) - (size + size_.x_) < 0;
	bool Y = std::abs(pos.y_ - pos_.y_) - (size + size_.y_) < 0;

	return X && Y;
}

bool Player::CheckHitX(Vector2 pos, float size)
{
	// �l��0�����Ȃ�߂荞��ł�B
	bool X = std::abs(pos.x_ - pos_.x_) - (size + size_.x_) < 0;

	return X;
}

bool Player::CheckHitY(Vector2 pos, float size)
{
	// �l��0�����Ȃ�߂荞��ł�B
	bool Y = std::abs(pos.y_ - pos_.y_) - (size + size_.y_) < 0;

	return Y;
}
