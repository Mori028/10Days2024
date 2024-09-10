#pragma once
#include "BaseScene.h"

class TitleScene : public BaseScene
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

private:

	//次のシーンへ
	bool isNextScene_;

	//画像
	size_t backGround_;
	size_t title_;
	size_t space_;
};