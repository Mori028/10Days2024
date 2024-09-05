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

private:

	/// <summary>
	/// 移動
	/// </summary>
	void Move();

	/// <summary>
	/// ジャンプ
	/// </summary>
	void Jump();

	//画面内に収まるように
	void FlameIn();

	//重力フラグ
	bool gravityFlag;
	size_t gravityPower;

	//位置
	Vector2 pos_;

	//色
	Vector3 color_;

	//半径
	size_t size_;
};