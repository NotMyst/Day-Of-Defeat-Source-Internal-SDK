#include "Hooks.h"

void Hooks::Init()
{
	MH_Initialize();

	CBasePlayer::Init();
	IPrediction::Init();
	IBaseClientDLL::Init();
	IClientMode::Init();
	IVModelRender::Init();
	IMatSystemSurface::Init();

	MH_EnableHook(MH_ALL_HOOKS);
}

void Hooks::Unhook()
{
	IMatSystemSurface::Unhook();
	IVModelRender::Unhook();
	IClientMode::Unhook();
	IBaseClientDLL::Unhook();
	IPrediction::Unhook();
	CBasePlayer::Unhook();

	MH_Uninitialize();
}