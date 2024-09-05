#include "Math.h"

size_t Math::GetRandom(size_t min, size_t max)
{
	std::random_device rd;
	std::default_random_engine eng(rd());
	std::uniform_int_distribution<> distr((int32_t)min, (int32_t)max);
	return (size_t)distr(eng);
}
