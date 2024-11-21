#include "Globals.h"

void G::Init()
{
	Server.Handle = GetModuleHandleW(L"server.dll");
	Client.Handle = GetModuleHandleW(L"client.dll");
	Engine.Handle = GetModuleHandleW(L"engine.dll");
	StudioRender.Handle = GetModuleHandleW(L"studiorender.dll");
	MaterialSystem.Handle = GetModuleHandleW(L"materialsystem.dll");
	Vstdlib.Handle = GetModuleHandleW(L"vstdlib.dll");
	Vgui.Handle = GetModuleHandleW(L"vgui2.dll");

	Window = FindWindowW(L"Valve001", nullptr);
}