#include "Player.h"
#include "DxLib.h"
#include "Input.h"

void Player::Update()
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

void Player::Initialize()
{
	//初期位置
	pos_ = { 50,50 };

	//初期カラー
	color_ = { 200,0,0 };

	size_ = 16;
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
