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
	gravityFlag = true;

	//重力
	gravityPower = 10;
}

void Player::Draw()
{
	//代入
	int color = GetColor(color_.x_, color_.y_, color_.z_);

	//描画
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
	//移動値
	Vector2 move = { 0,0 };

	//速度
	size_t speed = 3;

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
	//space押したときどこにいるか
	if (Input::GetInstance()->KeyPush(KEY_INPUT_SPACE))
	{
		switch (1)
		{
		case 1:

			break;

		case 2:

			break;

		default:
			break;
		}
	}

	//重力
	pos_.y_ += gravityPower;

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