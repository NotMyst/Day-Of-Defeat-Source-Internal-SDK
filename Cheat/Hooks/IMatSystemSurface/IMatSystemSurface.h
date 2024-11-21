#pragma once

#include "../../Features/Features.h"

class C_BasePlayer;

namespace Hooks::IMatSystemSurface
{
	void Init();
	void Unhook();

	inline VMT VTable;

	namespace PaintTraverse
	{
		constexpr int Index = 88;
		typedef void(__thiscall* T)(::IMatSystemSurface*, VPANEL);

		void __fastcall Detour(::IMatSystemSurface* __this, void*, VPANEL panel);
	}
}