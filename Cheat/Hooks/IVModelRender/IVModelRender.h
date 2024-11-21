#pragma once

#include "../../Features/Features.h"

namespace Hooks::IVModelRender
{
	void Init();
	void Unhook();

	inline VMT VTable;

	namespace DrawModelExecute
	{
		constexpr int Index = 19;
		typedef void(__thiscall* T)(::IVModelRender*, DrawModelState_t&, const ModelRenderInfo_t&, matrix3x4_t*);

		void __fastcall Detour(::IVModelRender* __this, void*, DrawModelState_t& state, const ModelRenderInfo_t& pInfo, matrix3x4_t* pCustomBoneToWorld);
	}
}