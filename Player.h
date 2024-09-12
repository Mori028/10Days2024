#pragma once
#include "Math.h"
#include <thread>

class Block
{
private:

	//�ʒu
	Vector2 pos_;

	//�T�C�Y
	Vector2 size_;

	//���
	int kind_;

public:

	void SetPos(Vector2 pos) { pos_ = pos; };
	Vector2 GetPos() { return pos_; };

	void SetSize(Vector2 size) { size_ = size; };
	Vector2 GetSize() { return size_; };

	void SetKind(int kind) { kind_ = kind; };
	int GetKind() { return kind_; };
};

class Player
{
public:

	/// <summary>
	/// �X�V
	/// </summary>
	void Update();

	/// <summary>
	/// ������
	/// </summary>
	void Initialize();

	/// <summary>
	/// �`��
	/// </summary>
	void Draw();

	/// <summary>
	/// �j��
	/// </summary>
	void Finalize();

	/// <summary>
	/// �����蔻��
	/// </summary>
	bool CheckHit(Vector2 pos, Vector2 size);
	bool CheckHitX(Vector2 pos, float size);
	bool CheckHitY(Vector2 pos, float size);

	/// <summary>
	/// �u���b�N�̏��𓾂�
	/// </summary>
	void SetBlockPos(Vector2 pos, Vector2 size, int kind);

	/// <summary>
	/// �u���b�N��񃊃Z�b�g
	/// </summary>
	void ResetBlock() { blocks_.clear(); };

	/// <summary>
	/// �}�b�v�`�b�v�̃X�N���[���ϐ��ƍő�l�̎擾�E�ݒ�
	/// </summary>
	/// <returns></returns>
	float GetMapChipMove() { return mapChipMoveY_; }
	void SetMapChipMoveMax(float mapChipMoveMax) { mapChipMoveMax_ = mapChipMoveMax; }

private:

	//�u���b�N���
	std::vector<Block*> blocks_;

	/// <summary>
	/// �ړ�
	/// </summary>
	void Move();

	/// <summary>
	/// �W�����v
	/// </summary>
	void Jump();

	/// <summary>
	/// �p�[�e�B�N��
	/// </summary>
	void Particle();

	//��ʓ��Ɏ��܂�悤��
	void FlameIn();

	//�d�̓t���O
	bool gravityFlag_;
	float gravityPower_;

	//�W�����v�֌W
	bool jumpFlags_;
	float jumpPower_;

	//
	bool blockF_;

	//�������Ă��邩
	bool hipDropF_;

	//�ʒu
	Vector2 pos_;

	//�F
	Vector3 color_;

	//���a
	Vector2 size_;

	//
	Vector2 move_ = { 0,0 };

	//�폜
	Vector2 testS = { 600 , 540 };
	float size = 20;
	bool ans = false;

	//�摜
	size_t playerPng_;
	size_t BLOCK_TEXTURE;

	//�X�N���[���l
	float mapChipMoveY_ = 0;
	float mapChipMoveMax_ = 0;
};