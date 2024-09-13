#pragma once

#include "DxLib.h"
#include "Math.h"
#include "Vector2.h"
#include <memory>
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
		NONE,         // 0
		BLOCK,        // 1
		MOVE_BLOCK,   // 2
		DAMAGE_BLOCK, // 3
		GOAL_BLOCK    // 4 
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

	/// <summary>
	/// マップチップのシェイク
	/// </summary>
	void Shake();

	/// <summary>
	/// マップチップの当たり判定
	/// </summary>
	void MapChipHitCheck();

public:
	/// <summary>
	/// ブロックの座標の取得
	/// </summary>
	const Vector2& GetBlockPosition(int y,int x) const { return blockPosition[y][x]; }

	/// <summary>
	/// マップチップの番号の取得
	/// </summary>
	int GetBlockNum(int y, int x) { return map[y][x]; }

	/// <summary>
	/// ブロックのシェイクフラグの取得と設定
	/// </summary>
	bool GetIsShake() { return isShake_; }
	void SetIsShake(bool isShake) { isShake_ = isShake; }

	/// <summary>
	/// マップチップのスクロール変数と最大値の取得・設定
	/// </summary>
	/// <returns></returns>
	float GetMapChipMove() { return mapChipMoveY_; }
	void SetMapChipMove(float mapChipMove) { mapChipMoveY_ = mapChipMove; }
	float GetMapChipMoveMax() { return mapChipMoveMax_; }
	void SetMapChipMoveMax(float mapChipMoveMax) { mapChipMoveMax_ = mapChipMoveMax; }

private:
	// 床のフラグやタイマーetc.
	bool isFloorMove_ = false;
	int floorMoveTime_ = 0;

	// ブロックのシェイク
	bool isShake_ = false;
	int shakeTime_ = 0;
	float addShakeX_ = 0.0f;
	float addShakeY_ = 0.0f;
	float shakePosX_ = 0.0f;
	float shakePosY_ = 0.0f;
	float shakeDefaultPos_ = 0.0f;
	const int shakeMin_ = -3;
	const int shakeMax_ = 3;
	const int defaultShakeTimer_ = 0;
	const int shakeTimer10_ = 10;
	const int shakeTimer20_ = 20;
	const float shakeMdX_ = 2.5f;
	const float shakeMdY_ = 20.0f;

	// 画像
	int BLOCK_TEXTURE;
	int MOVE_BLOCK_TEXTURE;
	int DAMAGE_BLOCK_TEXTURE;
	int GOAL_BLOCK_TEXTURE;

	// マップチップ
	static const int MAP_SIZE_HEIGHT = 27;
	static const int MAP_SIZE_WIDTH = 20;
	Vector2 blockPosition[MAP_SIZE_HEIGHT][MAP_SIZE_WIDTH];
	Vector2 block;
	const int blockSize = 60;
	float mapChipMoveY_ = 0.0f;
	float mapChipMoveMax_ = 1620.0f;
	float addSpeed = 0.0f;
	float screenY_ = 0.0f;

	int map[MAP_SIZE_HEIGHT][MAP_SIZE_WIDTH] = 
	{
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,1,1,1,1,1,1,0,0,4,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0}
	};
};