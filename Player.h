#pragma once
#include "Math.h"
#include <thread>

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

private:

	/// <summary>
	/// �ړ�
	/// </summary>
	void Move();

	/// <summary>
	/// �W�����v
	/// </summary>
	void Jump();

	//��ʓ��Ɏ��܂�悤��
	void FlameIn();

	//�d�̓t���O
	bool gravityFlag_;
	size_t gravityPower_;

	//�W�����v�֌W
	bool jumpFlags_;
	size_t jumpPower_;

	//�ʒu
	Vector2 pos_;

	//�F
	Vector3 color_;

	//���a
	size_t size_;
};