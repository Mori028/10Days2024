#pragma once
#include "Vector2.h"	
#include "Vector3.h"	
#include <random>
#include <cmath>

class Math
{
public:

	/// <summary>
	/// ƒ‰ƒ“ƒ_ƒ€ŠÖ”
	/// </summary>
	/// <param name="min"></param>
	/// <param name="max"></param>
	/// <returns></returns>
	size_t GetRandom(size_t min, size_t max);

private:
	const float PI = 3.14159265358979f;
	const float PIx2 = 6.2831853071f;

};