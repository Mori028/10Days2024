#pragma once

#include "DxLib.h"
#include <memory>
#include <math.h>
#include <DirectXMath.h>

class Map 
{
public:
	Map();
	~Map();

public:
	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 更新
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

	/// <summary>
	/// 移動
	/// </summary>
	void Move();

private:
	// 床のフラグやタイマーetc.
	DirectX::XMFLOAT2 floor = { 100,500 };
	bool isFloorMove_ = false;
	int floorMoveTime_ = 0;
};
