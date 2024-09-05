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

	//�ʒu
	Vector2 pos_;

	//�F
	Vector3 color_;

	//���a
	size_t size_;
};