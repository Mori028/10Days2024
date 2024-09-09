#include "Input.h"
#include "DxLib.h"

void Input::Update()
{
	for (int i = 0; i < 256; ++i)
	{
		oldkeys[i] = keys[i];
	}

	// �ŐV�̃L�[�{�[�h��񂾂������̂�1�t���[���O�̃L�[�{�[�h���Ƃ��ĕۑ�
	// �ŐV�̃L�[�{�[�h�����擾
	GetHitKeyStateAll(keys);
}

bool Input::KeyPush(size_t key)
{
	return keys[key];
}

bool Input::KeyTrigger(size_t key)
{
	return keys[key] && !oldkeys[key];
}

bool Input::KeyRelease(size_t key)
{
	return !keys[key] && oldkeys[key];
}
