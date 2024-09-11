#pragma once

#include "DxLib.h"
#include <memory>
#include <DirectXMath.h>

class Map 
{
public:
	// �R���X�g���N�^
	Map();
	// �f�X�g���N�^
	~Map();

public:
	// �}�b�v�̒�`
	enum MapInfo 
	{
		NONE,      // 0
		BLOCK,     // 1
		MOVE_BLOCK // 2
	};

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

	/// <summary>
	/// �}�b�v�`�b�v�̃V�F�C�N
	/// </summary>
	void Shake();

public:
	/// <summary>
	/// �u���b�N�̍��W�̎擾
	/// </summary>
	const DirectX::XMFLOAT2& GetBlockPosition(int y,int x) const { return blockPosition[y][x]; }

	/// <summary>
	/// �}�b�v�`�b�v�̔ԍ��̎擾
	/// </summary>
	const int GetBlockNum(int y, int x) const { return map[y][x]; }

	/// <summary>
	/// �u���b�N�̃V�F�C�N�t���O�̎擾�Ɛݒ�
	/// </summary>
	const bool GetIsShake() { return isShake_; }
	void SetIsShake(bool isShake) { isShake_ = isShake; }

private:
	// ���̃t���O��^�C�}�[etc.
	bool isFloorMove_ = false;
	int floorMoveTime_ = 0;

	// �u���b�N�̃V�F�C�N
	bool isShake_ = false;
	int shakeTime_ = 0;
	float addShakeX_ = 0.0f;
	float addShakeY_ = 0.0f;
	float shakePosX_ = 0.0f;
	float shakePosY_ = 0.0f;
	float shakeDefaultPos_ = 0.0f;
	const int shakeMin_ = -3;
	const int shakeMax_ = 3;
	const int defaultShakeTimer_ = 0;
	const int shakeTimer10_ = 10;
	const int shakeTimer20_ = 20;
	const float shakeMdX_ = 2.5f;
	const float shakeMdY_ = 20.0f;

	// �摜
	int BLOCK_TEXTURE;

	// �}�b�v�`�b�v
	static const int MAP_SIZE_HEIGHT = 40;
	static const int MAP_SIZE_WIDTH = 20;
	DirectX::XMFLOAT2 blockPosition[MAP_SIZE_HEIGHT][MAP_SIZE_WIDTH];
	const int blockSize = 60;
	float blockX,blockY;
	float addSpeed = 0.0f;

	int map[MAP_SIZE_HEIGHT][MAP_SIZE_WIDTH] = 
	{
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,2,2,0,0,0,0,0,0,0,0,0,0,2,2,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0}
	};
};