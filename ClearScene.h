#pragma once
#include "BaseScene.h"

class ClearScene : public BaseScene
{

public:

	/// <summary>
	/// ������
	/// </summary>
	void Initialize()override;

	/// <summary>
	/// �X�V
	/// </summary>
	void Update()override;

	/// <summary>
	/// �`��
	/// </summary>
	void Draw()override;

	/// <summary>
	/// �j��
	/// </summary>
	void Finalize()override;

	/// <summary>
	/// ���̃V�[���ɍs�����ǂ���
	/// </summary>
	/// <returns></returns>
	bool IsNextScene() { return isNextScene_; };

	/// <summary>
	/// ���Z�b�g
	/// </summary>
	void Reset();

	/// <summary>
	/// ����
	/// </summary>
	/// <param name="time"></param>
	void SetResult(size_t time) { result_ = time; };

private:

	int colorTimer = 0;
	//���̃V�[����
	bool isNextScene_;

	//�摜
	size_t backGround_;
	size_t clear_;
	size_t clear1_;
	size_t space_;
	size_t space1_;
	//����
	size_t result_;
	size_t resultGraph_[10];
};