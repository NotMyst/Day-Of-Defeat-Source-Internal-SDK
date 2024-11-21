#include "IMatSystemSurface.h"

void Hooks::IMatSystemSurface::Init()
{
	VTable.Init(gMatSystemSurface, 176);
	VTable.Hook(PaintTraverse::Detour, PaintTraverse::Index);
}

void Hooks::IMatSystemSurface::Unhook()
{
	VTable.Unhook(PaintTraverse::Index);
}

void __fastcall Hooks::IMatSystemSurface::PaintTraverse::Detour(::IMatSystemSurface* __this, void*, VPANEL vpanel)
{

	return VTable.Original<T>(Index)(__this, vpanel);
}