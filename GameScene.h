#pragma once
#include "BaseScene.h"
#include "Player.h"
#include "Map.h"
#include "Time.h"

class GameScene : public BaseScene
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
	/// ���Ԃ�Ԃ�
	/// </summary>
	/// <returns></returns>
	size_t GetTime() { return time_->GetTime(); };

private:

	//���̃V�[����
	bool isNextScene_;

	//�摜
	size_t backGround_;
	//player
	std::unique_ptr<Player> player_;
	std::unique_ptr<Time> time_;

	//map
	std::unique_ptr<Map> map = std::make_unique<Map>();

	// �}�b�v�`�b�v
	static const int MAP_SIZE_HEIGHT = 27;
	static const int MAP_SIZE_WIDTH = 20;
	const int blockSize = 60;
};