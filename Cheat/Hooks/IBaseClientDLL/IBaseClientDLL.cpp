#include "IBaseClientDLL.h"

void Hooks::IBaseClientDLL::Init()
{
	VTable.Init(gClient);

	VTable.Hook(FrameStageNotify::Detour, FrameStageNotify::Index);
}

void Hooks::IBaseClientDLL::Unhook()
{
	VTable.Unhook(FrameStageNotify::Index);
}

void __fastcall Hooks::IBaseClientDLL::FrameStageNotify::Detour(::IBaseClientDLL* __this, void*, ClientFrameStage_t curStage)
{

	return VTable.Original<T>(Index)(__this, curStage);
}