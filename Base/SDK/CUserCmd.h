#pragma once

class CUserCmd
{
public:
	void* vtable;

	int command_number;
	int tick_count;
	QAngle viewangles;
	float forwardmove;
	float sidemove;
	float upmove;
	int	buttons;
	byte impulse;
	int weaponselect;
	int weaponsubtype;
	int random_seed;
	short mousedx;
	short mousedy;
	bool hasbeenpredicted;
};