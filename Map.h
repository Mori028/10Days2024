#pragma once

#include "DxLib.h"
#include <memory>
#include <math.h>
#include <DirectXMath.h>

class Map 
{
public:
	// �R���X�g���N�^
	Map();
	// �f�X�g���N�^
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
	DirectX::XMFLOAT2 floor[2] = { { 100, 500 },{ 900, 500 } };
	bool isFloorMove_ = false;
	int floorMoveTime_ = 0;
};
