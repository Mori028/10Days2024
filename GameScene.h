#pragma once
#include "BaseScene.h"
#include "Player.h"
#include "Map.h"

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

private:

	//���̃V�[����
	bool isNextScene_;

	//�摜
	size_t backGround_;

	//player
	std::unique_ptr<Player> player_;

	//map
	std::unique_ptr<Map> map = std::make_unique<Map>();
};