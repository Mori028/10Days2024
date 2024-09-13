#pragma once
#include "BaseScene.h"

class TitleScene : public BaseScene
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

private:

	//�V�[���J��
	int sceneChangeTimer = 0;
	int sceneChangeCount = 0; //4�J�E���g�ňÓ]����
	int titleTimer = 0;
	int colorTimer = 0;

	//���̃V�[����
	bool isSceneChange_;
	bool isNextScene_;

	//�摜
	size_t backGround_;
	size_t title_;
	size_t title1_;
	size_t title2_;
	size_t title3_;
	size_t title4_;
	size_t title5_;
	size_t space_;
	size_t blueSpace_;
	size_t sceneChange1Png_;
	size_t sceneChange2Png_;
	size_t sceneChange3Png_;

};