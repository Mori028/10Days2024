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
	// ブロックの番号
	enum MapInfo
	{
		NONE,         // 0
		BLOCK,        // 1
		MOVE_BLOCK,   // 2
		DAMAGE_BLOCK, // 3
		GOAL_BLOCK,   // 4 
		BREAK_BLOCK   // 5
	};

	// ステージ番号
	enum Stage
	{
		STAGE_1 = 1, // 1
		STAGE_2,     // 2
		STAGE_3,     // 3
		STAGE_4,     // 4
		STAGE_5      // 5
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
	const Vector2& GetBlockPosition(int mapNum, int y, int x) const { return blockPosition[mapNum][y][x]; }

	/// <summary>
	/// マップチップの番号の取得
	/// </summary>
	int GetBlockNum(int mapNum, int y, int x) { return map[mapNum][y][x]; }

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
	float GetMapChipSizeMax() { return stageSize; }

	/// <summary>
	/// 現在のステージ番号の取得と設定
	/// </summary>
	int GetStageNum() { return stage_; }
	void SetStageNum(int stage) { stage_ = stage; }
	int GetStageMaxNum() { return maxStage_; }

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

	// 画像の読み込み変数
	int BLOCK_TEXTURE;
	int MOVE_BLOCK_TEXTURE;
	int DAMAGE_BLOCK_TEXTURE;
	int GOAL_BLOCK_TEXTURE;
	int BREAK_BLOCK_TEXTURE;

	static const int STAGE_MAP_SIZE_HEIGHT = 200;
	// マップチップ
	static const int STAGE_MAP_SIZE_WIDTH = 20;
	float stageSize = 200;
	Vector2 mapCount[5];
	Vector2 blockPosition[5][STAGE_MAP_SIZE_HEIGHT][STAGE_MAP_SIZE_WIDTH];
	Vector2 block[5];
	const int blockSize = 60;
	float mapChipMoveY_ = 0.0f;
	float mapChipMoveMax_ = static_cast<float>(stageSize * 60.0f);
	float addSpeed = 0.0f;
	float screenY_ = 0.0f;
	int stage_ = 1;
	int maxStage_ = 5;

	int map[5][STAGE_MAP_SIZE_HEIGHT][STAGE_MAP_SIZE_WIDTH] =
	{
		{
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,5,5,5,5,5,5,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,5,5,5,5,5,5,5,5,5,5,0,5,5,5,5,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,3,3,0,0,0,0,0,0,0,0,0,0,0,0,3,3,5,0},
			{0,5,5,5,0,0,0,0,0,0,0,0,0,0,0,0,5,5,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,1,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,5,5,5,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,5,5,5,5,5,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,3,3,0,0,0,0,0,3,3,0,0,0,0,0,3,3,5,0},
			{0,5,5,5,0,0,0,0,0,5,5,0,0,0,0,0,5,5,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,3,3,0,0,0,0,0,0,3,3,0,0,0,5,0},
			{0,5,0,0,0,5,5,0,0,0,0,0,0,5,5,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,5,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,3,0,0,0,0,0,3,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,5,0,0,0,0,0,5,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,5,3,3,5,0,0,0,0,0,0,5,0},
			{0,5,3,3,0,0,0,0,0,5,5,0,0,0,0,0,3,3,5,0},
			{0,5,5,5,0,0,0,0,0,0,0,0,0,0,0,0,5,5,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,5,5,5,0,0,0,0,0,0,5,5,5,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,5,5,5,5,5,5,5,5,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,5,5,5,5,5,5,5,5,5,5,0,0,0,5,5,5,5,0},
			{0,5,5,5,5,5,5,5,5,5,5,0,0,0,5,5,5,5,5,0},
			{0,5,5,5,5,5,5,5,5,5,0,0,0,5,5,5,5,5,5,0},
			{0,5,5,5,5,5,5,5,5,0,0,0,5,5,5,5,5,5,5,0},
			{0,5,5,5,5,5,5,5,0,0,0,5,5,5,5,5,5,5,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,5,5,5,5,5,5,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,3,3,0,0,0,0,0,0,0,0,0,0,0,0,3,3,5,0},
			{0,5,5,5,0,0,0,0,0,0,0,0,0,0,0,0,5,5,5,0},
			{0,5,0,0,0,0,0,0,3,3,3,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,5,5,5,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5,0},
			{0,5,5,5,0,0,0,5,5,5,5,5,5,5,5,5,5,5,5,0},
			{0,5,5,5,5,0,0,0,5,5,5,5,5,5,5,5,5,5,5,0},
			{0,5,5,5,5,5,0,0,0,5,5,5,5,5,5,5,5,5,5,0},
			{0,5,5,5,5,5,5,0,0,0,5,5,5,5,5,5,5,5,5,0},
			{0,5,5,5,5,5,5,5,0,0,0,5,5,5,5,5,5,5,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,3,3,3,3,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,5,5,5,5,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,5,0},
			{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
			{0,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,0}
		}
	};
};