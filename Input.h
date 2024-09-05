#pragma once

class Input
{
private:	
	// �ŐV�̃L�[�{�[�h���p
	char keys[256] = { 0 };

	// 1���[�v(�t���[��)�O�̃L�[�{�[�h���
	char oldkeys[256] = { 0 };

public:
	//�V���O���g��
	static Input* GetInstance()
	{
		static Input input;
		return &input;
	}

	//�X�V
	void Update();

	///�����Ă��
	bool KeyPush(size_t key);

	//�������u��
	bool KeyTrigger(size_t key);

	//�������u��
	bool KeyRelease(size_t key);
};