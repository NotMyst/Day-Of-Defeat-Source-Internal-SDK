#pragma once

#include "../../../Base/Base.h"

namespace Features
{
	class CBhop
	{
	public:
		bool Enabled = true;

		void Run(CUserCmd* cmd);
	};

	inline CBhop* Bhop = new CBhop;
}