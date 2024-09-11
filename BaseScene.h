#pragma once

class BaseScene
{
public:

	/// <summary>
	/// XV
	/// </summary>
	virtual void Update() = 0;

	/// <summary>
	/// ‰Šú‰»
	/// </summary>
	virtual void Initialize() = 0;

	/// <summary>
	/// •`‰æ
	/// </summary>
	virtual void Draw() = 0;

	/// <summary>
	/// ”jŠü
	/// </summary>
	virtual void Finalize() = 0;


private:

};