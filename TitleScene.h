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
};