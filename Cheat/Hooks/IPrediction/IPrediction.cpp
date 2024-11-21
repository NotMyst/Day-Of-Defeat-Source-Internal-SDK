#include "IPrediction.h"

void Hooks::IPrediction::Init()
{
	VTable.Init(gPrediction);
	VTable.Hook(RunCommand::Detour, RunCommand::Index);
}

void Hooks::IPrediction::Unhook()
{
	VTable.Unhook(RunCommand::Index);
}

void __fastcall Hooks::IPrediction::RunCommand::Detour(::IPrediction* __this, void*, ::C_BasePlayer* player, CUserCmd* ucmd, IMoveHelper* moveHelper)
{

	return VTable.Original<T>(Index)(__this, player, ucmd, moveHelper);
}