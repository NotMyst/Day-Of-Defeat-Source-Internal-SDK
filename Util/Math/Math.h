#pragma once

#include <cmath>
#include <math.h>
#include <numbers>

#include "../../Base/SDK/Vector.h"

#define M_RADPI		57.295779513082f
#define M_PI		3.14159265358979323846f

#define DEG2RADF(f)	(f * (M_PI / 180.0f))
#define RAD2DEGF(f)	(f * (180.0f / M_PI))

namespace Math
{
	void VectorAngles(Vector& forward, Vector& angles);
}