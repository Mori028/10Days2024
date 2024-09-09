#pragma once

#include "DxLib.h"
#include <memory>
#include <math.h>
#include <DirectXMath.h>

class Map 
{
public:
	// コンストラクタ
	Map();
	// デストラクタ
	~Map();

public:
	// マップの定義
	enum MapInfo 
	{
		NONE,      // 0
		BLOCK,     // 1
		MOVE_BLOCK // 2
	};

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

public:
	const DirectX::XMFLOAT2& GetBlockPosition(int y,int x) const { return blockPosition[y][x]; }

private:
	// 床のフラグやタイマーetc.
	bool isFloorMove_ = false;
	int floorMoveTime_ = 0;

	// 画像
	int BLOCK_TEXTURE;

	// マップチップ
	static const int MAP_SIZE_HEIGHT = 20;
	static const int MAP_SIZE_WIDTH = 20;
	DirectX::XMFLOAT2 blockPosition[MAP_SIZE_HEIGHT][MAP_SIZE_WIDTH];
	const int blockSize = 60;
	float blockX,blockY;
	float addSpeed = 0.0f;
	int map[MAP_SIZE_HEIGHT][MAP_SIZE_WIDTH] = {
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,2,0,0,0,0,0,0,0,0,0,0,0,0,2,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0}
	};
};
