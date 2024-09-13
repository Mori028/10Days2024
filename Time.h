#pragma once

#include "DxLib.h"

class Time
{

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
	/// 破棄
	/// </summary>
	void Finalize();

	/// <summary>
	/// リセット
	/// </summary>
	void Reset();

	/// <summary>
	/// 時間を返す
	/// </summary>
	/// <returns></returns>
	size_t GetTime() { return drawTime_; };

	/// <summary>
	/// タイム加算
	/// </summary>
	void AddTime(size_t time) { drawTime_ += time; };

	/// <summary>
	/// 時間を止めるかどうか
	/// </summary>
	void SetTimeStop(bool flag) { timeStopFlag_ = flag; };

	/// <summary>
	/// 時間を止めているかどうか
	/// </summary>
	bool GetTimeStopFlag() { return timeStopFlag_; };

private:

	//計測用
	size_t time_;

	//描画用
	size_t drawTime_;

	//数字画像
	size_t timeGraph[10];

	//時間が止まっているか
	bool timeStopFlag_;
};