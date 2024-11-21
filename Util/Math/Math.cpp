#include "Math.h"

// pasted but i forgot from where :(
void Math::VectorAngles(Vector& forward, Vector& angles)
{
	float yaw, pitch;

	if (forward.y == 0.0f && forward.x == 0.0f)
	{
		yaw = 0.0f;
		pitch = (forward.z > 0.0f) ? 270.0f : 90.0f;
	}
	else
	{
		yaw = RAD2DEGF(::atan2f(forward.y, forward.x));
		yaw += (360.0f * (yaw < 0.0f));

		const float tmp = forward.Length2D();

		pitch = RAD2DEGF(::atan2f(-forward.z, tmp));
		pitch += (360.0f * (pitch < 0.0f));
	}

	angles.x = pitch;
	angles.y = yaw;
	angles.z = 0.0f;
}