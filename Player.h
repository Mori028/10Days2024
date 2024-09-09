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

	/// <summary>
	/// �����蔻��
	/// </summary>
	void BoxCollision();

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
	float gravityPower_;

	//�W�����v�֌W
	bool jumpFlags_;
	float jumpPower_;

	//�������Ă��邩
	bool hipDropF_;

	//�ʒu
	Vector2 pos_;

	//�F
	Vector3 color_;

	//���a
	int32_t size_;
};