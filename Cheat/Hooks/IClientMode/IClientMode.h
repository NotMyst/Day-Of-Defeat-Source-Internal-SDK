#pragma once

#include "../../Features/Features.h"

namespace Hooks::IClientMode
{
	void Init();
	void Unhook();

	inline VMT VTable;

	namespace OverrideView
	{
		constexpr int Index = 16;
		typedef void(__thiscall* T)(::IClientMode*, CViewSetup* pSetup);

		void Detour(::IClientMode* __this, void*, CViewSetup* pSetup);
	}

	namespace CreateMove
	{
		constexpr int Index = 21;
		typedef bool(__thiscall* T)(::IClientMode*, float, CUserCmd*);

		bool __fastcall Detour(::IClientMode* __this, void*, float flInputSampleTime, CUserCmd* cmd);
	}

	namespace GetViewmodelFOV
	{
		constexpr int Index = 32;
		typedef float(__thiscall* T)(::IClientMode*);

		float __fastcall Detour(::IClientMode* __this, void*);
	}
}