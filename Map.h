#pragma once

#include "DxLib.h"
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

	/// <summary>
	/// マップチップのシェイク
	/// </summary>
	void Shake();

public:
	/// <summary>
	/// ブロックの座標の取得
	/// </summary>
	const DirectX::XMFLOAT2& GetBlockPosition(int y,int x) const { return blockPosition[y][x]; }

	/// <summary>
	/// マップチップの番号の取得
	/// </summary>
	const int GetBlockNum(int y, int x) const { return map[y][x]; }

	/// <summary>
	/// ブロックのシェイクフラグの取得と設定
	/// </summary>
	const bool GetIsShake() { return isShake_; }
	void SetIsShake(bool isShake) { isShake_ = isShake; }

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

	// マップチップ
	static const int MAP_SIZE_HEIGHT = 40;
	static const int MAP_SIZE_WIDTH = 20;
	DirectX::XMFLOAT2 blockPosition[MAP_SIZE_HEIGHT][MAP_SIZE_WIDTH];
	const int blockSize = 60;
	float blockX,blockY;
	float addSpeed = 0.0f;

	int map[MAP_SIZE_HEIGHT][MAP_SIZE_WIDTH] = 
	{
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,2,2,0,0,0,0,0,0,0,0,0,0,2,2,0,1,0},
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
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,1,0},
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
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0}
	};
};