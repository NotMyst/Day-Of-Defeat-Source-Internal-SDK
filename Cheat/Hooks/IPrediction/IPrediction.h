#pragma once

#include "../../Features/Features.h"

class C_BasePlayer;

namespace Hooks::IPrediction
{
	void Init();
	void Unhook();

	inline VMT VTable;

	namespace RunCommand
	{
		constexpr int Index = 17;
		typedef void(__thiscall* T)(::IPrediction*, ::C_BasePlayer* player, CUserCmd* ucmd, IMoveHelper* moveHelper);

		void __fastcall Detour(::IPrediction* __this, void*, ::C_BasePlayer* player, CUserCmd* ucmd, IMoveHelper* moveHelper);
	}
}