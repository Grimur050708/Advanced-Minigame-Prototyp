#include "Math.h"

float Math::Clamp(float _val, float _min, float _max)
{
	if (_val < _min)
		return _min;

	if (_val > _max)
		return _max;

	return _val;
}

int Math::Clamp(int _val, int _min, int _max)
{
	if (_val < _min)
		return _min;

	if (_val > _max)
		return _max;

	return _val;
}