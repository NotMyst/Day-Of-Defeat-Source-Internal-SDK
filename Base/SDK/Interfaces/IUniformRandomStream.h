#pragma once

class IUniformRandomStream
{
public:
	virtual void* SetSeed(int) = 0;
	virtual float RandomFloat(float, float) = 0;
	virtual void* RandomInt(int, int) = 0;
	virtual void* RandomFloatExp(float, float, float) = 0;
};

inline IUniformRandomStream* gRandomStream = nullptr;