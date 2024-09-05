#pragma once

#include "DxLib.h"
#include <memory>
#include <math.h>
#include <DirectXMath.h>

class Map 
{
public:
	Map();
	~Map();

public:
	/// <summary>
	/// ������
	/// </summary>
	void Initialize();

	/// <summary>
	/// �X�V
	/// </summary>
	void Update();

	/// <summary>
	/// �`��
	/// </summary>
	void Draw();

	/// <summary>
	/// �ړ�
	/// </summary>
	void Move();

private:
	// ���̃t���O��^�C�}�[etc.
	DirectX::XMFLOAT2 floor = { 100,500 };
	bool isFloorMove_ = false;
	int floorMoveTime_ = 0;
};
