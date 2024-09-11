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
	FlameIn();
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

	//
	move_ = { 0,0 };

	//
	blockF_ = false;

	//画像読み込み
	playerPng_ = LoadGraph("Resource//player.png");

	// 画像の割り当て
	BLOCK_TEXTURE = LoadGraph("Resources/1.png", TRUE);
}

void Player::Draw()
{
	//代入
	int color = GetColor((int)color_.x_, (int)color_.y_, (int)color_.z_);

	//Dubug
	DrawFormatString(200, 48, GetColor(100, 100, 100), "pos %f,%f", pos_.x_, pos_.y_, true);

	//Dubug
	DrawFormatString(200, 32, GetColor(100, 100, 100), "blockF %d", blockF_, true);

	int zure = 10;

	//描画
	DrawBox(
		(int)pos_.x_+ zure,
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

	for (size_t i = 0; i < blocks_.size(); i++)
	{
		//描画
		DrawExtendGraph(
			(int)blocks_[i]->GetPos().x_,
			(int)blocks_[i]->GetPos().y_,
			(int)(blocks_[i]->GetPos().x_ + (blocks_[i]->GetSize().x_ * 2)),
			(int)(blocks_[i]->GetPos().y_  + (blocks_[i]->GetSize().y_ * 2)),
			BLOCK_TEXTURE, true);
	}
}

void Player::Finalize()
{

}

void Player::Move()
{
	//速度
	float speed = 5;

	//移動
	move_.x_ += Input::GetInstance()->KeyPush(KEY_INPUT_D) - Input::GetInstance()->KeyPush(KEY_INPUT_A);
	//move_.y_ += Input::GetInstance()->KeyPush(KEY_INPUT_S) - Input::GetInstance()->KeyPush(KEY_INPUT_W);

	//速度を掛ける
	move_.x_ *= speed;

	//移動
	pos_.x_ += move_.x_;

	//判定
	//test
	//ステージに当たったら壊す

	//横判定
	for (size_t i = 0; i < blocks_.size(); i++)
	{
		if (CheckHit(blocks_[i]->GetPos(), blocks_[i]->GetSize()))
		{
			if (hipDropF_)
			{
				blocks_[i]->SetPos({ -100, -100 });
			}
			else
			{
				//横修正
				if (CheckHitX(blocks_[i]->GetPos(), blocks_[i]->GetSize().x_))
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
		}
		else
		{
			blockF_ = false;
		}
	}

	//移動
	pos_.y_ += move_.y_;

	//判定
	//縦判定
	for (size_t i = 0; i < blocks_.size(); i++)
	{
		//ステージに当たったら壊す
		if (CheckHit(blocks_[i]->GetPos(), blocks_[i]->GetSize()))
		{
			if (hipDropF_)
			{
				blocks_[i]->SetPos({ -100, -100 });
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
	move_ = { 0,0 };

	//仮地面
	int stageLine = 600;

	//地面にいるか
	bool earthFlags = pos_.y_ + 1 > stageLine + size_.y_;

	//地面にいたらtrueに
	if (earthFlags)
	{
		hipDropF_ = false;
		jumpFlags_ = false;
	}

	//Dubug
	DrawFormatString(200, 0, GetColor(100, 100, 100), "earthFlags %d", earthFlags, true);

	//重力の最大値 
	const float MaxGravity = 5;

	//ジャンプの最大値
	const float MaxJump = 30;

	//space押したときどこにいるか
	if (Input::GetInstance()->KeyTrigger(KEY_INPUT_SPACE))
	{
		switch (earthFlags || blockF_)
		{
			//地面からのジャンプ
		case true:

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
				//2回以上でないように
				jumpFlags_ = false;

				//
				hipDropF_ = true;

				//
				jumpPower_ = 0;
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

	//
	if (hipDropF_)
	{
		//落下速度
		size_t speed = 10;

		//重力
		move_.y_ += gravityPower_ * speed;
	}
	else
	{
		//重力
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
	bool Y = std::abs(pos.y_ - pos_.y_) - (size.y_ + size_.y_) < 0;

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
	bool Y = std::abs(pos.y_ - pos_.y_) - (size + size_.y_) < 0;

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
