#pragma once
#include "BaseScene.h"
#include "Player.h"
#include "Map.h"
#include "Time.h"

class GameScene : public BaseScene
{

public:

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize()override;

	/// <summary>
	/// 更新
	/// </summary>
	void Update()override;

	/// <summary>
	/// 描画
	/// </summary>
	void Draw()override;

	/// <summary>
	/// 破棄
	/// </summary>
	void Finalize()override;

	/// <summary>
	/// 次のシーンに行くかどうか
	/// </summary>
	/// <returns></returns>
	bool IsNextScene() { return isNextScene_; };

	/// <summary>
	/// リセット
	/// </summary>
	void Reset();

	/// <summary>
	/// 時間を返す
	/// </summary>
	/// <returns></returns>
	size_t GetTime() { return time_->GetTime(); };

private:

	//次のシーンへ
	bool isNextScene_;

	//画像
	size_t backGround_;
	//player
	std::unique_ptr<Player> player_;
	std::unique_ptr<Time> time_;

	//map
	std::unique_ptr<Map> map = std::make_unique<Map>();

	// マップチップ
	static const int MAP_SIZE_HEIGHT = 27;
	static const int MAP_SIZE_WIDTH = 20;
	const int blockSize = 60;
};