#pragma once
#include "BaseScene.h"

class TitleScene : public BaseScene
{

public:

	/// <summary>
	/// ‰Šú‰»
	/// </summary>
	void Initialize()override;

	/// <summary>
	/// XV
	/// </summary>
	void Update()override;

	/// <summary>
	/// •`‰æ
	/// </summary>
	void Draw()override;

	/// <summary>
	/// ”jŠü
	/// </summary>
	void Finalize()override;
};