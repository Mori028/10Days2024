#pragma once
#include "Math.h"
#include <thread>

// マップの定義
enum MapInfo
{
	NONE,         // 0
	BLOCK,        // 1
	MOVE_BLOCK,   // 2
	DAMAGE_BLOCK, // 3
	GOAL_BLOCK,    // 4 
	NONBREAK_BLOCK,	//5
};

class Block
{
private:

	//位置
	Vector2 pos_;

	//サイズ
	Vector2 size_;

	//種類
	int kind_;

public:

	void SetPos(Vector2 pos) { pos_ = pos; };
	Vector2 GetPos() { return pos_; };

	void SetSize(Vector2 size) { size_ = size; };
	Vector2 GetSize() { return size_; };

	void SetKind(int kind) { kind_ = kind; };
	int GetKind() { return kind_; };
};

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
	/// UI描画
	/// </summary>
	void UIDraw();

	/// <summary>
	/// 破棄
	/// </summary>
	void Finalize();

	/// <summary>
	/// 当たり判定
	/// </summary>
	bool CheckHit(Vector2 pos, Vector2 size);
	bool CheckHitX(Vector2 pos, float size);
	bool CheckHitY(Vector2 pos, float size);

	/// <summary>
	/// ブロックの情報を得る
	/// </summary>
	void SetBlockPos(Vector2 pos, Vector2 size, int kind);

	/// <summary>
	/// ブロック情報リセット
	/// </summary>
	void ResetBlock() { blocks_.clear(); };

	/// <summary>
	/// マップチップのスクロール変数と最大値の取得・設定
	/// </summary>
	/// <returns></returns>
	float GetMapChipMove() { return mapChipMoveY_; }
	void SetMapChipMoveMax(float mapChipMoveMax) { mapChipMoveMax_ = mapChipMoveMax; }

	/// <summary>
	/// 次のシーンへ行くか
	/// </summary>
	/// <returns></returns>
	bool GetNextSceneFlag() { return nextFlag_; };

	/// <summary>
	/// リセット
	/// </summary>
	void Reset();

	/// <summary>
	/// 当たった処理
	/// </summary>
	void OnCollision();

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	bool AddTime();

private:

	//ブロック情報
	std::vector<Block*> blocks_;

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
	size_t BLOCK_TEXTURE;
	size_t MOVE_BLOCK_TEXTURE;
	size_t DAMAGE_BLOCK_TEXTURE;
	size_t GOAL_BLOCK_TEXTURE;
	size_t NONBREAK_BLOCK_TEXTURE;

	//スクロール値
	float mapChipMoveY_ = 0;
	float mapChipMoveMax_ = 0;

	//最大落下回数
	size_t MaxHipDrop_ = 3;
	float hipDrop_ = 5;

	//次のシーンに行く用
	bool nextFlag_ = false;

	//ダメージブロックに触れたか
	bool hitFlag_;
	size_t hitEffect_ = 0;

	//BGM
	int jumpSound_;
	int breakSound_;
	int damageSound_;

	size_t ui_;
	size_t hipCount_;
};