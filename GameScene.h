#pragma once
#include "BaseScene.h"
#include "Player.h"
#include "Map.h"

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

private:

	//次のシーンへ
	bool isNextScene_;

	//画像
	size_t backGround_;

	//player
	std::unique_ptr<Player> player_;

	//map
	std::unique_ptr<Map> map = std::make_unique<Map>();
};