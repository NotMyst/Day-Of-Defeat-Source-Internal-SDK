#pragma once

#include "../Pattern/Pattern.h"

#include "minhook/MinHook.h"
#include <vector>

class VMT
{
private:
	void** vmt;
	std::vector<void*> o;

	DWORD size;
public:
	template<typename T>
	inline T Original(unsigned int index)
	{
		return reinterpret_cast<T>(o[index]);
	}

	void Hook(void* detour, unsigned int index)
	{
		MH_CreateHook(vmt[index], detour, &o[index]);
	}

	void Unhook(unsigned int index)
	{
		MH_RemoveHook(vmt[index]);
	}

	void Init(void* instance, int size = 0)
	{
		vmt = *reinterpret_cast<void***>(instance);

		if (size)
			o = std::vector<void*>(size);
		else
		{
			while (reinterpret_cast<unsigned int*>(*vmt)[size])
				size += 1u;

			o = std::vector<void*>(size);
		}
	}
};

#define M_HOOK(name, index, type) namespace name \
{ \
	constexpr unsigned int Index = index; \
	using T = type; \
	inline T* o; \
	T Detour; \
}