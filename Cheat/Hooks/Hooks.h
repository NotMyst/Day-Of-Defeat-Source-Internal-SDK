#pragma once

#include "C_BasePlayer/C_BasePlayer.h"
#include "IBaseClientDLL/IBaseClientDLL.h"
#include "IClientMode/IClientMode.h"
#include "IVModelRender/IVModelRender.h"
#include "IPrediction/IPrediction.h"
#include "IMatSystemSurface/IMatSystemSurface.h"

namespace Hooks
{
	void Init();
	void Unhook();
}