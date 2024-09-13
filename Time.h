#pragma once

#include "DxLib.h"

class Time
{

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
	/// �j��
	/// </summary>
	void Finalize();

	/// <summary>
	/// ���Z�b�g
	/// </summary>
	void Reset();

	/// <summary>
	/// ���Ԃ�Ԃ�
	/// </summary>
	/// <returns></returns>
	size_t GetTime() { return drawTime_; };

	/// <summary>
	/// �^�C�����Z
	/// </summary>
	void AddTime(size_t time) { drawTime_ += time; };

	/// <summary>
	/// ���Ԃ��~�߂邩�ǂ���
	/// </summary>
	void SetTimeStop(bool flag) { timeStopFlag_ = flag; };

	/// <summary>
	/// ���Ԃ��~�߂Ă��邩�ǂ���
	/// </summary>
	bool GetTimeStopFlag() { return timeStopFlag_; };

private:

	//�v���p
	size_t time_;

	//�`��p
	size_t drawTime_;

	//�����摜
	size_t timeGraph[10];

	//���Ԃ��~�܂��Ă��邩
	bool timeStopFlag_;
};