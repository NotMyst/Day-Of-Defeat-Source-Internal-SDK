#pragma once

#include "../../Util/Util.h"

class C_DODPlayer;

namespace G
{
	inline Module_t Server;
	inline Module_t Client;
	inline Module_t Engine;
	inline Module_t StudioRender;
	inline Module_t MaterialSystem;
	inline Module_t Vstdlib;
	inline Module_t Vgui;

	inline C_DODPlayer* Player;

	inline HWND Window;

	void Init();
}