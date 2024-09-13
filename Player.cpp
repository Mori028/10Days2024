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

	//debug
	if (mapChipMoveY_ <= mapChipMoveMax_ && mapChipMoveY_ >= 0)
	{
		mapChipMoveY_ += (Input::GetInstance()->KeyPush(KEY_INPUT_R) - Input::GetInstance()->KeyPush(KEY_INPUT_T));
	}
	else if (mapChipMoveY_ > mapChipMoveMax_)
	{
		mapChipMoveY_ = mapChipMoveMax_;
	}
	else if (mapChipMoveY_ < 0)
	{
		mapChipMoveY_ = 0;
	}
}

void Player::Initialize()
{
	//�����ʒu
	pos_ = { 250,50 };

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

	// �摜�̊��蓖��
	BLOCK_TEXTURE = LoadGraph("Resources/1.png", TRUE);

	//�X�N���[���l
	mapChipMoveY_ = 0;
	mapChipMoveMax_ = 0;

	nextFlag = false;
}

void Player::Draw()
{
	//���
	int color = GetColor((int)color_.x_, (int)color_.y_, (int)color_.z_);

	//Debug
	DrawFormatString(200, 48, GetColor(100, 100, 100), "pos %f,%f", pos_.x_, pos_.y_, true);

	//Debug
	DrawFormatString(200, 32, GetColor(100, 100, 100), "blockF %d", blockF_, true);

	//Debug
	DrawFormatString(200, 64, GetColor(100, 100, 100), "MoveXXX %f", move_.x_, true);

	int zure = 10;

	//�`��
	DrawBox(
		(int)pos_.x_ + zure,
		(int)pos_.y_ + 1 - zure,
		(int)(pos_.x_ + (2 * size_.x_) + zure),
		(int)(pos_.y_ + 1 + (2 * size_.y_) - zure),
		color, true);

	DrawExtendGraph(
		(int)pos_.x_ + zure,
		(int)pos_.y_ + 1 - zure,
		(int)(pos_.x_ + (2 * size_.x_) + zure),
		(int)(pos_.y_ + 1 + (2 * size_.y_) - zure),
		playerPng_, true);

	//���u���b�N�`��
	//for (size_t i = 0; i < blocks_.size(); i++)
	//{
	//	//�`��
	//	DrawExtendGraph(
	//		(int)blocks_[i]->GetPos().x_,
	//		(int)blocks_[i]->GetPos().y_,
	//		(int)(blocks_[i]->GetPos().x_ + (blocks_[i]->GetSize().x_ * 2)),
	//		(int)(blocks_[i]->GetPos().y_ + (blocks_[i]->GetSize().y_ * 2)),
	//		BLOCK_TEXTURE, true);
	//}
}

void Player::Finalize()
{

}

void Player::Reset()
{
	//�����ʒu
	pos_ = { 250,50 };

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

	//�X�N���[���l
	mapChipMoveY_ = 0;
	mapChipMoveMax_ = 0;

	nextFlag = false;
}

void Player::Move()
{
	//���x
	const float speed = 2;
	const float MaxSpeed = 14;

	//�ړ�
	move_.x_ += (Input::GetInstance()->KeyPush(KEY_INPUT_D) - Input::GetInstance()->KeyPush(KEY_INPUT_A)) * speed;

	//
	if (!Input::GetInstance()->KeyPush(KEY_INPUT_D) && !Input::GetInstance()->KeyPush(KEY_INPUT_A))
	{
		move_.x_ = 0;
	}

	if (move_.x_ > MaxSpeed)
	{
		move_.x_ = MaxSpeed;
	}

	if (-MaxSpeed > move_.x_)
	{
		move_.x_ = -MaxSpeed;
	}

	if (hipDropF_)
	{
		move_.x_ = 0;
	}

	//�ړ�
	pos_.x_ += move_.x_;

	//����
	//test
	//�X�e�[�W�ɓ����������

	//������
	for (size_t i = 0; i < blocks_.size(); i++)
	{
		//
		if (CheckHit(blocks_[i]->GetPos(), blocks_[i]->GetSize()))
		{
			if (blocks_[i]->GetKind() == GOAL_BLOCK)
			{
				nextFlag = true;
			}
			//���C��
			else if (CheckHitX(blocks_[i]->GetPos(), blocks_[i]->GetSize().x_))
			{
				while (CheckHit(blocks_[i]->GetPos(), blocks_[i]->GetSize()))
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
		else
		{
			blockF_ = false;
		}
	}

	//�X�N���[��
	if (pos_.y_ > 400 && mapChipMoveY_ < mapChipMoveMax_)
	{
		mapChipMoveY_ += move_.y_;
	}
	else
	{
		//�ړ�
		pos_.y_ += move_.y_;
	}

	//����
	//�c����
	for (size_t i = 0; i < blocks_.size(); i++)
	{
		//�X�e�[�W�ɓ����������
		if (CheckHit(blocks_[i]->GetPos(), blocks_[i]->GetSize()))
		{
			if (blocks_[i]->GetKind() == GOAL_BLOCK)
			{
				nextFlag = true;
			}
			//���C��
			else if (hipDropF_)
			{
				blocks_[i]->SetPos({ -100, -100 });
			}
			else
			{
				//�c�C��
				if (CheckHit(blocks_[i]->GetPos(), blocks_[i]->GetSize()))
				{
					while (CheckHitY(blocks_[i]->GetPos(), blocks_[i]->GetSize().y_))
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
	}
}

void Player::Jump()
{
	//�ړ��l
	move_.y_ = 0;

	//���n��
	int stageLine = 600;

	//�n�ʂɂ��邩
	bool earthFlags = pos_.y_ + 1 > stageLine + size_.y_;

	//�n�ʂɂ�����true��
	if (earthFlags)
	{
		hipDropF_ = false;
		jumpFlags_ = false;
	}

	//Dubug
	DrawFormatString(200, 0, GetColor(100, 100, 100), "earthFlags %d", earthFlags, true);

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

				//
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
	DrawFormatString(200, 16, GetColor(100, 100, 100), "hipDropF_ %d", hipDropF_, true);

	blockF_ = false;

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

bool Player::CheckHit(Vector2 pos, Vector2 size)
{
	// �l��0�����Ȃ�߂荞��ł�B
	bool X = std::abs(pos.x_ - pos_.x_) - (size.x_ + size_.x_) < 0;
	bool Y = std::abs(pos.y_ - pos_.y_ - mapChipMoveY_) - (size.y_ + size_.y_) < 0;

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
	bool Y = std::abs(pos.y_ - pos_.y_ - mapChipMoveY_) - (size + size_.y_) < 0;

	return Y;
}

void Player::SetBlockPos(Vector2 pos, Vector2 size, int kind)
{
	//���f�����w�肵��3D�I�u�W�F�N�g�𐶐�
	Block* newBlock_ = new Block();

	size /= 2;

	//���i�[
	newBlock_->SetPos(pos);
	newBlock_->SetSize(size);
	newBlock_->SetKind(kind);

	//�i�[
	blocks_.push_back(newBlock_);
}
