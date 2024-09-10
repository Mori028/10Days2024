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
	pos_ = { 50,50 };

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
}

void Player::Draw()
{
	//代入
	int color = GetColor((int)color_.x_, (int)color_.y_, (int)color_.z_);

	//Dubug
	DrawFormatString(0, 48, GetColor(100, 100, 100), "pos %f,%f", pos_.x_, pos_.y_, true);

	//描画
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
	//速度
	float speed = 5;

	//移動
	move_.x_ += Input::GetInstance()->KeyPush(KEY_INPUT_D) - Input::GetInstance()->KeyPush(KEY_INPUT_A);
	//move_.y_ += Input::GetInstance()->KeyPush(KEY_INPUT_S) - Input::GetInstance()->KeyPush(KEY_INPUT_W);

	//速度を掛ける
	move_.x_ *= speed;

	//削除
	ans = false;

	//移動
	pos_.x_ += move_.x_;

	//判定
	//test
	//ステージに当たったら壊す
	if (CheckHit(testS, size))
	{
		if (hipDropF_)
		{
			testS = { -100,-100 };
		}
		else
		{
			//修正
			while (CheckHit(testS, size))
			{
				//横修正
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

	//移動
	pos_.y_ += move_.y_;

	//判定
	//test
	//ステージに当たったら壊す
	if (CheckHit(testS, size))
	{
		if (hipDropF_)
		{
			testS = { -100,-100 };
		}
		else
		{
			//縦修正
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
	}

	//Dubug
	DrawFormatString(0, 0, GetColor(100, 100, 100), "earthFlags %d", earthFlags, true);

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
		jumpFlags_ = false;
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
	DrawFormatString(0, 16, GetColor(100, 100, 100), "hipDropF_ %d", hipDropF_, true);

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

bool Player::CheckHit(Vector2 pos, float size)
{
	// 値が0未満ならめり込んでる。
	bool X = std::abs(pos.x_ - pos_.x_) - (size + size_.x_) < 0;
	bool Y = std::abs(pos.y_ - pos_.y_) - (size + size_.y_) < 0;

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
