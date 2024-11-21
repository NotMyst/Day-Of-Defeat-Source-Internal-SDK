#include "Offsets.h"

void G::COffsets::Get()
{
	dwCalcPlayerView = Pattern::Find(G::Client, "55 8B EC 83 EC ? 53 56 8B F1 8B 0D ? ? ? ? 57 8B 01 8B 40 ? FF D0 84 C0");
}