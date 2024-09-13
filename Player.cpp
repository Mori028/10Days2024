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
	//FlameIn();
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

	//�ړ��l�i�[�p�ϐ�
	move_ = { 0,0 };

	//�u���b�N�ɐG��Ă��邩
	blockF_ = false;

	//�摜�ǂݍ���
	playerPng_ = LoadGraph("Resource//player.png");

	ui_ = LoadGraph("Resource//sousa.png");
	hipCount_ = LoadGraph("Resource//Down.png");

	// �摜�̊��蓖��
	BLOCK_TEXTURE = LoadGraph("Resource/1.png", TRUE);

	//�X�N���[���l
	mapChipMoveY_ = 0;
	mapChipMoveMax_ = 0;

	//���̃V�[���ɍs���t���O
	nextFlag_ = false;

	//��
	MaxHipDrop_ = 5;

	//hit�֌W
	hitFlag_;
	hitEffect_ = 0;

	// �摜�̊��蓖��
	BLOCK_TEXTURE = LoadGraph("Resource/Block4.png", TRUE);
	MOVE_BLOCK_TEXTURE = LoadGraph("Resource/1.png", TRUE);
	DAMAGE_BLOCK_TEXTURE = LoadGraph("Resource/DamageBlock.png", TRUE);
	GOAL_BLOCK_TEXTURE = LoadGraph("Resource/goal.png", TRUE);
	NONBREAK_BLOCK_TEXTURE = LoadGraph("Resource/Block.png", TRUE);

	//BGM
	jumpSound_ = LoadSoundMem("Resource//Sound//Jump.wav");
	breakSound_ = LoadSoundMem("Resource//Sound//break.wav");
	damageSound_ = LoadSoundMem("Resource//Sound//damege.wav");

	//���ʒ���
	int Volume = 75;
	ChangeVolumeSoundMem(Volume, jumpSound_);
	ChangeVolumeSoundMem(Volume, breakSound_);

	Volume = 120;
	ChangeVolumeSoundMem(Volume, damageSound_);
}

void Player::Draw()
{
	//���
	int color = GetColor((int)color_.x_, (int)color_.y_, (int)color_.z_);

	int zure = 10;

	if (hitFlag_)
	{
		hitEffect_++;

		if (hitEffect_ == 60)
		{
			hitFlag_ = false;
			hitEffect_ = 0;
		}
	}

	if (hitEffect_ % 2 == 0)
	{
		DrawExtendGraph(
			(int)pos_.x_ + zure,
			(int)pos_.y_ + 1 - zure,
			(int)(pos_.x_ + (2 * size_.x_) + zure),
			(int)(pos_.y_ + 1 + (2 * size_.y_) - zure),
			playerPng_, true);
	}

	//���u���b�N�`��
	for (size_t i = 0; i < blocks_.size(); i++)
	{
		size_t graph = BLOCK_TEXTURE;

		if (blocks_[i]->GetKind() == BLOCK)
		{
			//�`��
			DrawExtendGraph(
				(int)blocks_[i]->GetPos().x_,
				(int)blocks_[i]->GetPos().y_ - mapChipMoveY_,
				(int)(blocks_[i]->GetPos().x_ + (blocks_[i]->GetSize().x_ * 2)),
				(int)(blocks_[i]->GetPos().y_ + (blocks_[i]->GetSize().y_ * 2) - mapChipMoveY_),
				BLOCK_TEXTURE, true);
		}

		if (blocks_[i]->GetKind() == DAMAGE_BLOCK)
		{
			//�`��
			DrawExtendGraph(
				(int)blocks_[i]->GetPos().x_,
				(int)blocks_[i]->GetPos().y_ - mapChipMoveY_,
				(int)(blocks_[i]->GetPos().x_ + (blocks_[i]->GetSize().x_ * 2)),
				(int)(blocks_[i]->GetPos().y_ + (blocks_[i]->GetSize().y_ * 2) - mapChipMoveY_),
				DAMAGE_BLOCK_TEXTURE, true);
		}

		if (blocks_[i]->GetKind() == GOAL_BLOCK)
		{
			//�`��
			DrawExtendGraph(
				(int)blocks_[i]->GetPos().x_,
				(int)blocks_[i]->GetPos().y_ - mapChipMoveY_,
				(int)(blocks_[i]->GetPos().x_ + (blocks_[i]->GetSize().x_ * 2)),
				(int)(blocks_[i]->GetPos().y_ + (blocks_[i]->GetSize().y_ * 2) - mapChipMoveY_),
				GOAL_BLOCK_TEXTURE, true);
		}

		if (blocks_[i]->GetKind() == NONBREAK_BLOCK)
		{
			//�`��
			DrawExtendGraph(
				(int)blocks_[i]->GetPos().x_,
				(int)blocks_[i]->GetPos().y_ - mapChipMoveY_,
				(int)(blocks_[i]->GetPos().x_ + (blocks_[i]->GetSize().x_ * 2)),
				(int)(blocks_[i]->GetPos().y_ + (blocks_[i]->GetSize().y_ * 2) - mapChipMoveY_),
				NONBREAK_BLOCK_TEXTURE, true);
		}
	}

	//UI�`��
	UIDraw();
}

void Player::UIDraw()
{
	int x = 0, y = 800 - 109, size = 48;

	//�`��
	DrawGraph(
		x,
		y,
		ui_, true);

	x = 1200 - size;
	y = 800 - size;

	for (size_t i = 0; i < MaxHipDrop_; i++)
	{
		//�`��
		DrawExtendGraph(
			x - (i * size),
			y,
			x - (i * size) + size,
			y + size,
			hipCount_, true);
	}
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

	//�ړ��l�i�[�p�ϐ�
	move_ = { 0,0 };

	//�u���b�N�ɐG��Ă��邩
	blockF_ = false;

	//�X�N���[���l
	mapChipMoveY_ = 0;

	//���̃V�[���ɍs���t���O
	nextFlag_ = false;

	//��
	MaxHipDrop_ = 5;

	//hit�֌W
	hitFlag_;
	hitEffect_ = 0;
}

void Player::OnCollision()
{
	if (!hitFlag_)
	{
		hitFlag_ = true;
		hitEffect_ = 0;
		PlaySoundMem(damageSound_, DX_PLAYTYPE_BACK);
	}
}

bool Player::AddTime()
{
	if (hitEffect_ == 1)
	{
		return true;
	}

	return false;
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
				nextFlag_ = true;
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
			//�_���[�W�u���b�N�������ꍇ
			if (blocks_[i]->GetKind() == DAMAGE_BLOCK)
			{
				OnCollision();
			}

			if (blocks_[i]->GetKind() == GOAL_BLOCK)
			{
				nextFlag_ = true;
			}
			else if (!(blocks_[i]->GetKind() == NONBREAK_BLOCK) && hipDropF_ && !(blocks_[i]->GetKind() == DAMAGE_BLOCK))
			{
				blocks_[i]->SetPos({ -100, -100 });
				//�u���C�N
				PlaySoundMem(breakSound_, DX_PLAYTYPE_BACK);
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

	//�d�͂̍ő�l 
	const float MaxGravity = 13;

	//�W�����v�̍ő�l
	const float MaxJump = 30;

	//space�������Ƃ��ǂ��ɂ��邩
	if (Input::GetInstance()->KeyTrigger(KEY_INPUT_SPACE))
	{
		switch (blockF_)
		{
			//�n�ʂ���̃W�����v
		case true:

			//�W�����v
			PlaySoundMem(jumpSound_, DX_PLAYTYPE_BACK);

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
				//�񐔂��c���Ă��邩
				if (MaxHipDrop_ > 0)
				{
					//2��ȏ�łȂ��悤��
					jumpFlags_ = false;

					//�t���O��ON��
					hipDropF_ = true;

					//�W�����v�͂�0��
					jumpPower_ = 0;

					//�񐔂�����
					MaxHipDrop_--;

					//�l�����炷
					hipDrop_ = 0;
				}
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

	//����
	if (hipDropF_)
	{
		//�������x
		size_t speed = 5;

		//�d��
		move_.y_ += gravityPower_ * speed;

		//
		hipDrop_++;

		if (hipDrop_ > 10)
		{
			hipDropF_ = false;
		}
	}
	else
	{
		//�d��
		move_.y_ += gravityPower_ - jumpPower_;
	}

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
