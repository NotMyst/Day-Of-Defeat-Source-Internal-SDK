#include "Cheat.h"

void Cheat::Entry()
{
	G::Init();

	DOD::S->Init();

	G::Offsets->Get();

	Hooks::Init();

	// sleep thread until game is being unloaded to prevent game being unable to close sometimes
	while (!Close)
		std::this_thread::sleep_for(std::chrono::milliseconds(10));

	Hooks::Unhook();

	FreeLibraryAndExitThread(Handle, 0);
}