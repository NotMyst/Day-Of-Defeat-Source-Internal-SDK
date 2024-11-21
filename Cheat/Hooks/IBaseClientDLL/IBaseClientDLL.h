#pragma once

#include "../../Features/Features.h"

namespace Hooks::IBaseClientDLL
{
	void Init();
	void Unhook();

	inline VMT VTable;

	namespace FrameStageNotify
	{
		constexpr int Index = 35;
		typedef void(__thiscall* T)(::IBaseClientDLL*, ClientFrameStage_t);

		void __fastcall Detour(::IBaseClientDLL* __this, void*, ClientFrameStage_t curStage);
	}
}