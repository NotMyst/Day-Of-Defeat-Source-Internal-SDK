#include "Cheat/Cheat.h"

BOOL WINAPI DllMain(HMODULE mod, DWORD reason, LPVOID)
{
	if (reason == DLL_PROCESS_ATTACH)
	{
		Cheat::Handle = mod;

		HANDLE thread = CreateThread(0, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>(Cheat::Entry), 0, 0, 0);

		if (thread)
			CloseHandle(thread);
	}
	else if (reason == DLL_PROCESS_DETACH)
		Cheat::Close = true;

	return TRUE;
}