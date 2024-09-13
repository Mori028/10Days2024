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

	/// <summary>
	/// リセット
	/// </summary>
	void Reset();

private:

	//シーン遷移
	int sceneChangeTimer = 0;
	int sceneChangeCount = 0; //4カウントで暗転する
	int titleTimer = 0;
	int colorTimer = 0;

	//次のシーンへ
	bool isSceneChange_;
	bool isNextScene_;

	//画像
	size_t backGround_;
	size_t title_;
	size_t title1_;
	size_t title2_;
	size_t title3_;
	size_t title4_;
	size_t title5_;
	size_t space_;
	size_t blueSpace_;
	size_t sceneChange1Png_;
	size_t sceneChange2Png_;
	size_t sceneChange3Png_;

};