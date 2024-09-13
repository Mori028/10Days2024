#include "Player.h"
#include "DxLib.h"
#include "Input.h"

//ヒップドロップ時にパーティクル

void Player::Update()
{
	//ジャンプ処理
	Jump();

	//移動処理
	Move();

	//ブロック判定
	//Collision();

	//画面内に収まる処理
	//FlameIn();
}

void Player::Initialize()
{
	//初期位置
	pos_ = { 250,50 };

	//初期カラー
	color_ = { 200,0,0 };

	//直径
	size_.x_ = 20;
	size_.y_ = 40;

	//重力あり
	gravityFlag_ = true;

	//重力
	gravityPower_ = 10;

	//ジャンプ関係
	jumpFlags_ = false;
	jumpPower_ = 0;

	//ヒップドロップフラグoff
	hipDropF_ = false;

	//移動値格納用変数
	move_ = { 0,0 };

	//ブロックに触れているか
	blockF_ = false;

	//画像読み込み
	playerPng_ = LoadGraph("Resource//player.png");

	ui_ = LoadGraph("Resource//sousa.png");
	hipCount_ = LoadGraph("Resource//Down.png");

	// 画像の割り当て
	BLOCK_TEXTURE = LoadGraph("Resource/1.png", TRUE);

	//スクロール値
	mapChipMoveY_ = 0;
	mapChipMoveMax_ = 0;

	//次のシーンに行くフラグ
	nextFlag_ = false;

	//回数
	MaxHipDrop_ = 5;

	//hit関係
	hitFlag_;
	hitEffect_ = 0;

	// 画像の割り当て
	BLOCK_TEXTURE = LoadGraph("Resource/Block4.png", TRUE);
	MOVE_BLOCK_TEXTURE = LoadGraph("Resource/1.png", TRUE);
	DAMAGE_BLOCK_TEXTURE = LoadGraph("Resource/DamageBlock.png", TRUE);
	GOAL_BLOCK_TEXTURE = LoadGraph("Resource/goal.png", TRUE);
	NONBREAK_BLOCK_TEXTURE = LoadGraph("Resource/Block.png", TRUE);

	//BGM
	jumpSound_ = LoadSoundMem("Resource//Sound//Jump.wav");
	breakSound_ = LoadSoundMem("Resource//Sound//break.wav");
	damageSound_ = LoadSoundMem("Resource//Sound//damege.wav");

	//音量調整
	int Volume = 75;
	ChangeVolumeSoundMem(Volume, jumpSound_);
	ChangeVolumeSoundMem(Volume, breakSound_);

	Volume = 120;
	ChangeVolumeSoundMem(Volume, damageSound_);
}

void Player::Draw()
{
	//代入
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

	//仮ブロック描画
	for (size_t i = 0; i < blocks_.size(); i++)
	{
		size_t graph = BLOCK_TEXTURE;

		if (blocks_[i]->GetKind() == BLOCK)
		{
			//描画
			DrawExtendGraph(
				(int)blocks_[i]->GetPos().x_,
				(int)blocks_[i]->GetPos().y_ - mapChipMoveY_,
				(int)(blocks_[i]->GetPos().x_ + (blocks_[i]->GetSize().x_ * 2)),
				(int)(blocks_[i]->GetPos().y_ + (blocks_[i]->GetSize().y_ * 2) - mapChipMoveY_),
				BLOCK_TEXTURE, true);
		}

		if (blocks_[i]->GetKind() == DAMAGE_BLOCK)
		{
			//描画
			DrawExtendGraph(
				(int)blocks_[i]->GetPos().x_,
				(int)blocks_[i]->GetPos().y_ - mapChipMoveY_,
				(int)(blocks_[i]->GetPos().x_ + (blocks_[i]->GetSize().x_ * 2)),
				(int)(blocks_[i]->GetPos().y_ + (blocks_[i]->GetSize().y_ * 2) - mapChipMoveY_),
				DAMAGE_BLOCK_TEXTURE, true);
		}

		if (blocks_[i]->GetKind() == GOAL_BLOCK)
		{
			//描画
			DrawExtendGraph(
				(int)blocks_[i]->GetPos().x_,
				(int)blocks_[i]->GetPos().y_ - mapChipMoveY_,
				(int)(blocks_[i]->GetPos().x_ + (blocks_[i]->GetSize().x_ * 2)),
				(int)(blocks_[i]->GetPos().y_ + (blocks_[i]->GetSize().y_ * 2) - mapChipMoveY_),
				GOAL_BLOCK_TEXTURE, true);
		}

		if (blocks_[i]->GetKind() == NONBREAK_BLOCK)
		{
			//描画
			DrawExtendGraph(
				(int)blocks_[i]->GetPos().x_,
				(int)blocks_[i]->GetPos().y_ - mapChipMoveY_,
				(int)(blocks_[i]->GetPos().x_ + (blocks_[i]->GetSize().x_ * 2)),
				(int)(blocks_[i]->GetPos().y_ + (blocks_[i]->GetSize().y_ * 2) - mapChipMoveY_),
				NONBREAK_BLOCK_TEXTURE, true);
		}
	}

	//UI描画
	UIDraw();
}

void Player::UIDraw()
{
	int x = 0, y = 800 - 109, size = 48;

	//描画
	DrawGraph(
		x,
		y,
		ui_, true);

	x = 1200 - size;
	y = 800 - size;

	for (size_t i = 0; i < MaxHipDrop_; i++)
	{
		//描画
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
	//初期位置
	pos_ = { 250,50 };

	//初期カラー
	color_ = { 200,0,0 };

	//直径
	size_.x_ = 20;
	size_.y_ = 40;

	//重力あり
	gravityFlag_ = true;

	//重力
	gravityPower_ = 10;

	//ジャンプ関係
	jumpFlags_ = false;
	jumpPower_ = 0;

	//ヒップドロップフラグoff
	hipDropF_ = false;

	//移動値格納用変数
	move_ = { 0,0 };

	//ブロックに触れているか
	blockF_ = false;

	//スクロール値
	mapChipMoveY_ = 0;

	//次のシーンに行くフラグ
	nextFlag_ = false;

	//回数
	MaxHipDrop_ = 5;

	//hit関係
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
	//速度
	const float speed = 2;
	const float MaxSpeed = 14;

	//移動
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

	//移動
	pos_.x_ += move_.x_;

	//判定
	//test
	//ステージに当たったら壊す

	//横判定
	for (size_t i = 0; i < blocks_.size(); i++)
	{
		//
		if (CheckHit(blocks_[i]->GetPos(), blocks_[i]->GetSize()))
		{
			if (blocks_[i]->GetKind() == GOAL_BLOCK)
			{
				nextFlag_ = true;
			}
			//横修正
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

	//スクロール
	if (pos_.y_ > 400 && mapChipMoveY_ < mapChipMoveMax_)
	{
		mapChipMoveY_ += move_.y_;
	}
	else
	{
		//移動
		pos_.y_ += move_.y_;
	}

	//判定
	//縦判定
	for (size_t i = 0; i < blocks_.size(); i++)
	{
		//ステージに当たったら壊す
		if (CheckHit(blocks_[i]->GetPos(), blocks_[i]->GetSize()))
		{
			//ダメージブロックだった場合
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
				//ブレイク
				PlaySoundMem(breakSound_, DX_PLAYTYPE_BACK);
			}
			else
			{
				//縦修正
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
	//移動値
	move_.y_ = 0;

	//重力の最大値 
	const float MaxGravity = 13;

	//ジャンプの最大値
	const float MaxJump = 30;

	//space押したときどこにいるか
	if (Input::GetInstance()->KeyTrigger(KEY_INPUT_SPACE))
	{
		switch (blockF_)
		{
			//地面からのジャンプ
		case true:

			//ジャンプ
			PlaySoundMem(jumpSound_, DX_PLAYTYPE_BACK);

			//重力を0に
			gravityPower_ = 0;

			//ジャンプ力を最大に
			jumpPower_ = MaxJump;

			//ジャンプフラグ
			jumpFlags_ = true;

			//ブロックに触れているか
			blockF_ = false;

			break;

			//空中にいるとき
		case false:

			//一度ジャンプしているか
			if (jumpFlags_)
			{
				//回数が残っているか
				if (MaxHipDrop_ > 0)
				{
					//2回以上でないように
					jumpFlags_ = false;

					//フラグをONに
					hipDropF_ = true;

					//ジャンプ力を0に
					jumpPower_ = 0;

					//回数を引く
					MaxHipDrop_--;

					//値を減らす
					hipDrop_ = 0;
				}
			}
			break;
		}
	}

	//重力加算
	if (gravityPower_ < MaxGravity)
	{
		gravityPower_ += 1.0f;
	}

	//浮力減算
	if (jumpPower_ > 0)
	{
		jumpPower_ -= 1.0f;
	}
	else
	{
		jumpPower_ = 0;
	}

	//直下
	if (hipDropF_)
	{
		//落下速度
		size_t speed = 5;

		//重力
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
		//重力
		move_.y_ += gravityPower_ - jumpPower_;
	}

	blockF_ = false;

}

void Player::Particle()
{

}

void Player::FlameIn()
{
	//仮地面
	int stageLine = 600;

	//画面端
	int LeftMax = 0;
	int RightMax = 1200;

	//画面外にいかないように
	pos_.x_ = min(pos_.x_, RightMax - size_.x_);
	pos_.x_ = max(pos_.x_, LeftMax);

	//画面外にいかないように
	pos_.y_ = min(pos_.y_, stageLine + size_.y_);
	pos_.y_ = max(pos_.y_, size_.y_);
}

bool Player::CheckHit(Vector2 pos, Vector2 size)
{
	// 値が0未満ならめり込んでる。
	bool X = std::abs(pos.x_ - pos_.x_) - (size.x_ + size_.x_) < 0;
	bool Y = std::abs(pos.y_ - pos_.y_ - mapChipMoveY_) - (size.y_ + size_.y_) < 0;

	return X && Y;
}

bool Player::CheckHitX(Vector2 pos, float size)
{
	// 値が0未満ならめり込んでる。
	bool X = std::abs(pos.x_ - pos_.x_) - (size + size_.x_) < 0;

	return X;
}

bool Player::CheckHitY(Vector2 pos, float size)
{
	// 値が0未満ならめり込んでる。
	bool Y = std::abs(pos.y_ - pos_.y_ - mapChipMoveY_) - (size + size_.y_) < 0;

	return Y;
}

void Player::SetBlockPos(Vector2 pos, Vector2 size, int kind)
{
	//モデルを指定して3Dオブジェクトを生成
	Block* newBlock_ = new Block();

	size /= 2;

	//情報格納
	newBlock_->SetPos(pos);
	newBlock_->SetSize(size);
	newBlock_->SetKind(kind);

	//格納
	blocks_.push_back(newBlock_);
}
