#pragma once

#include "DxLib.h"
#include <memory>
#include <math.h>
#include <DirectXMath.h>

class Map 
{
public:
	/// <summary>
	/// ‰Šú‰»
	/// </summary>
	void Initialize();

	/// <summary>
	/// XV
	/// </summary>
	void Update();

	/// <summary>
	/// •`‰æ
	/// </summary>
	void Draw();

private:
	DirectX::XMFLOAT2 floor = { 100,500 };
	bool isFloorMove_ = false;
	int floorMoveTime_ = 0;
};
