#pragma once

#include "DxLib.h"
#include "Math.h"
#include "Vector2.h"
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
		NONE,         // 0
		BLOCK,        // 1
		MOVE_BLOCK,   // 2
		DAMAGE_BLOCK, // 3
		GOAL_BLOCK    // 4 
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

	/// <summary>
	/// �}�b�v�`�b�v�̓����蔻��
	/// </summary>
	void MapChipHitCheck();

public:
	/// <summary>
	/// �u���b�N�̍��W�̎擾
	/// </summary>
	const Vector2& GetBlockPosition(int y,int x) const { return blockPosition[y][x]; }

	/// <summary>
	/// �}�b�v�`�b�v�̔ԍ��̎擾
	/// </summary>
	int GetBlockNum(int y, int x) { return map[y][x]; }

	/// <summary>
	/// �u���b�N�̃V�F�C�N�t���O�̎擾�Ɛݒ�
	/// </summary>
	bool GetIsShake() { return isShake_; }
	void SetIsShake(bool isShake) { isShake_ = isShake; }

	/// <summary>
	/// �}�b�v�`�b�v�̃X�N���[���ϐ��ƍő�l�̎擾�E�ݒ�
	/// </summary>
	/// <returns></returns>
	float GetMapChipMove() { return mapChipMoveY_; }
	void SetMapChipMove(float mapChipMove) { mapChipMoveY_ = mapChipMove; }
	float GetMapChipMoveMax() { return mapChipMoveMax_; }
	void SetMapChipMoveMax(float mapChipMoveMax) { mapChipMoveMax_ = mapChipMoveMax; }

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
	int MOVE_BLOCK_TEXTURE;
	int DAMAGE_BLOCK_TEXTURE;
	int GOAL_BLOCK_TEXTURE;

	// �}�b�v�`�b�v
	static const int MAP_SIZE_HEIGHT = 27;
	static const int MAP_SIZE_WIDTH = 20;
	Vector2 blockPosition[MAP_SIZE_HEIGHT][MAP_SIZE_WIDTH];
	Vector2 block;
	const int blockSize = 60;
	float mapChipMoveY_ = 0.0f;
	float mapChipMoveMax_ = 1620.0f;
	float addSpeed = 0.0f;
	float screenY_ = 0.0f;

	int map[MAP_SIZE_HEIGHT][MAP_SIZE_WIDTH] = 
	{
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,1,1,1,1,1,1,0,0,4,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0}
	};
};