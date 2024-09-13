#pragma once
#include "BaseScene.h"

class ClearScene : public BaseScene
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
	/// 結果
	/// </summary>
	/// <param name="time"></param>
	void SetResult(size_t time) { result_ = time; };

private:

	int colorTimer = 0;
	//次のシーンへ
	bool isNextScene_;

	//画像
	size_t backGround_;
	size_t clear_;
	size_t clear1_;
	size_t space_;
	size_t space1_;
	//結果
	size_t result_;
	size_t resultGraph_[10];
};