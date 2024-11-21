#include "IClientMode.h"

void Hooks::IClientMode::Init()
{
	VTable.Init(gClientMode);

	VTable.Hook(CreateMove::Detour, CreateMove::Index);
	VTable.Hook(GetViewmodelFOV::Detour, GetViewmodelFOV::Index);
}

void Hooks::IClientMode::Unhook()
{
	VTable.Unhook(GetViewmodelFOV::Index);
	VTable.Unhook(CreateMove::Index);
}

bool __fastcall Hooks::IClientMode::CreateMove::Detour(::IClientMode* __this, void*, float flInputSampleTime, CUserCmd* cmd)
{

	return VTable.Original<T>(Index)(__this, flInputSampleTime, cmd);
}

float __fastcall Hooks::IClientMode::GetViewmodelFOV::Detour(::IClientMode* __this, void*)
{

	return VTable.Original<T>(Index)(__this);
}

void Hooks::IClientMode::OverrideView::Detour(::IClientMode* __this, void*, CViewSetup* pSetup)
{

	return VTable.Original<T>(Index)(__this, pSetup);
}