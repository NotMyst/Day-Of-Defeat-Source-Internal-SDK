#include "IVModelRender.h"

void Hooks::IVModelRender::Init()
{
	VTable.Init(gModelRender, 25);

	VTable.Hook(DrawModelExecute::Detour, DrawModelExecute::Index);
}

void Hooks::IVModelRender::Unhook()
{
	VTable.Unhook(DrawModelExecute::Index);
}

void __fastcall Hooks::IVModelRender::DrawModelExecute::Detour(::IVModelRender* __this, void*, DrawModelState_t& state, const ModelRenderInfo_t& pInfo, matrix3x4_t* pCustomBoneToWorld)
{

	return VTable.Original<T>(Index)(__this, state, pInfo, pCustomBoneToWorld);
}