#pragma once
#include "Math.h"
#include <thread>

class Player
{
public:

	/// <summary>
	/// 更新
	/// </summary>
	void Update();

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

	/// <summary>
	/// 破棄
	/// </summary>
	void Finalize();

	/// <summary>
	/// 当たり判定
	/// </summary>
	bool CheckHit(Vector2 pos, float size);
	bool CheckHitX(Vector2 pos, float size);
	bool CheckHitY(Vector2 pos, float size);

private:

	/// <summary>
	/// 移動
	/// </summary>
	void Move();

	/// <summary>
	/// ジャンプ
	/// </summary>
	void Jump();

	/// <summary>
	/// パーティクル
	/// </summary>
	void Particle();

	//画面内に収まるように
	void FlameIn();

	//重力フラグ
	bool gravityFlag_;
	float gravityPower_;

	//ジャンプ関係
	bool jumpFlags_;
	float jumpPower_;

	//
	bool blockF_;
	
	//直下しているか
	bool hipDropF_;

	//位置
	Vector2 pos_;

	//色
	Vector3 color_;

	//半径
	Vector2 size_;

	//
	Vector2 move_ = { 0,0 };

	//削除
	Vector2 testS = { 600 , 540 };
	float size = 20;
	bool ans = false;

	//画像
	size_t playerPng_;
};