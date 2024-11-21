#pragma once

#include "../Math/Math.h"

#include <Windows.h>

struct Module_t
{
public:
	union
	{
		HMODULE Handle;
		DWORD Base;
		PIMAGE_DOS_HEADER DosHeaders;
	};

	template<typename T = DWORD>
	inline T GetExport(const char* name)
	{
		return reinterpret_cast<T>(GetProcAddress(Handle, name));
	}

	inline PIMAGE_NT_HEADERS GetHeaders()
	{
		return reinterpret_cast<PIMAGE_NT_HEADERS>(Base + DosHeaders->e_lfanew);
	}
};

namespace Memory
{
	template<typename T>
	inline T GetVFunc(void* instance, int index)
	{
		return (*static_cast<T**>(instance))[index];
	}

	template<typename T = DWORD>
	inline T Rip(DWORD address, unsigned int offset)
	{
		return reinterpret_cast<T>(reinterpret_cast<void*** (***)()>(address + *reinterpret_cast<DWORD*>(address + offset)));
	}
}