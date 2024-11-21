#pragma once

#include "../Globals/Globals.h"

#include <fstream>
#include "../SDK/Handle.h"

namespace Netvar
{
	int GetVarOffset(const char* Class, const char* const var);

	inline std::vector<const char*> dumped{};
}

#define NETVAR(type, name, table) inline type& name() \
{ \
	static std::ptrdiff_t offset = Netvar::GetVarOffset(table, #name); \
	return *reinterpret_cast<type*>(reinterpret_cast<DWORD>(this) + offset); \
}

#define NETVAR_(type, fn, name, table) inline type& fn() \
{ \
	static std::ptrdiff_t offset = Netvar::GetVarOffset(table, #name); \
	return *reinterpret_cast<type*>(reinterpret_cast<DWORD>(this) + offset); \
}