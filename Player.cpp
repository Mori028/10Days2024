#include "Player.h"
#include "DxLib.h"
#include "Input.h"

//ヒップドロップ時にパーティクル

void Player::Update()
{
	//移動処理
	Move();

	//ジャンプ処理
	Jump();

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
	size_ = 32;

	//重力あり
	gravityFlag_ = true;

	//重力
	gravityPower_ = 10;

	//ジャンプ関係
	jumpFlags_ = false;
	jumpPower_ = 0;

	//ヒップドロップフラグoff
	hipDropF_ = false;
}

void Player::Draw()
{
	//代入
	int color = GetColor((int)color_.x_, (int)color_.y_, (int)color_.z_);

	//描画
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
	//移動値
	Vector2 move = { 0,0 };

	//速度
	float speed = 3;

	//移動
	move.x_ += Input::GetInstance()->KeyPush(KEY_INPUT_D) - Input::GetInstance()->KeyPush(KEY_INPUT_A);
	move.y_ += Input::GetInstance()->KeyPush(KEY_INPUT_S) - Input::GetInstance()->KeyPush(KEY_INPUT_W);

	//速度を掛ける
	move *= speed;

	//移動
	pos_ += move;
}

void Player::Jump()
{
	//仮地面
	int stageLine = 600;

	//地面にいるか
	bool earthFlags = pos_.y_ + 1 > stageLine + size_;

	//地面にいたらtrueに
	if (earthFlags)
	{
		hipDropF_ = false;
	}

	//Dubug
	DrawFormatString(0, 0, GetColor(100, 100, 100), "earthFlags %d", earthFlags, true);

	//重力の最大値 
	const float MaxGravity = 15;

	//ジャンプの最大値
	const float MaxJump = 10;

	//space押したときどこにいるか
	if (Input::GetInstance()->KeyTrigger(KEY_INPUT_SPACE))
	{
 		switch (earthFlags)
		{
			//地面からのジャンプ
		case true:

			//重力を0に
			gravityPower_ = 0;

			//ジャンプ力を最大に
			jumpPower_ = MaxJump;

			//ジャンプフラグ
			jumpFlags_ = true;

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
			}

			break;
		}
	}

	//重力加算
	if (gravityPower_ < MaxGravity)
	{
		gravityPower_ += 0.2f;
	}

	//浮力減算
	if (jumpPower_ > 0)
	{
		jumpPower_ -= 0.2f;
	}

	//
	if (hipDropF_)
	{
		//落下速度
		size_t speed = 5;

		//重力
		pos_.y_ += gravityPower_ * speed;

		//ステージに当たったら壊す
		if (BoxCollision())
		{

		}
	}
	else
	{
		//重力
		pos_.y_ += gravityPower_ - jumpPower_;
	}

	//Dubug
	DrawFormatString(0, 16, GetColor(100, 100, 100), "hipDropF_ %d", hipDropF_, true);

}

void Player::FlameIn()
{
	//仮地面
	int stageLine = 600;

	//画面端
	int LeftMax = 0;
	int RightMax = 1200;

	//画面外にいかないように
	pos_.x_ = min(pos_.x_, RightMax - size_);
	pos_.x_ = max(pos_.x_, LeftMax);

	//画面外にいかないように
	pos_.y_ = min(pos_.y_, stageLine + size_);
	pos_.y_ = max(pos_.y_, size_);
}