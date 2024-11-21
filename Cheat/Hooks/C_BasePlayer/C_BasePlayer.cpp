#include "C_BasePlayer.h"

void Hooks::CBasePlayer::Init()
{
	MH_CreateHook(reinterpret_cast<LPVOID>(G::Offsets->dwCalcPlayerView), CalcPlayerView::Detour, reinterpret_cast<LPVOID*>(&CalcPlayerView::o));
}

void Hooks::CBasePlayer::Unhook()
{
	MH_RemoveHook(reinterpret_cast<LPVOID>(G::Offsets->dwCalcPlayerView));
}

void __fastcall Hooks::CBasePlayer::CalcPlayerView::Detour(::C_BasePlayer* __this, void*, Vector& eyeOrigin, Vector& eyeAngles, float& fov)
{
	return o(__this, eyeOrigin, eyeAngles, fov);
}