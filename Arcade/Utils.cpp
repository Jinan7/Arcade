#include "Utils.h"
#include <cmath>
#include "Utils.h"



bool isEqual(float x, float y) {
	return fabsf(x - y) < EPSILON;
}

bool isGreaterThanOrEqual(float x, float y) {
	return x > y || isEqual(x, y);
}
bool isLessThanOrEqual(float x, float y) {
	return x < y || isEqual(x, y);
}

float MillisecondsToSeconds(unsigned int milliseconds)
{
	return static_cast<float>(milliseconds) / 1000.0f;
}

