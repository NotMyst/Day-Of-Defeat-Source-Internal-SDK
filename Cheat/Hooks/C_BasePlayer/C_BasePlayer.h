#pragma once

#include "../../Features/Features.h"

namespace Hooks::CBasePlayer
{
	void Init();
	void Unhook();

	namespace CalcPlayerView
	{
		typedef void(__thiscall* T)(::C_BasePlayer*, Vector&, Vector&, float&);
		inline T o;

		void __fastcall Detour(::C_BasePlayer* __this, void*, Vector& eyeOrigin, Vector& eyeAngles, float& fov);
	}
}