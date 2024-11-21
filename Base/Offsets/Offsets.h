#pragma once

#include "../SDK/SDK.h"

namespace G
{
	class COffsets
	{
	public:
		void Get();

		DWORD dwCalcPlayerView = 0x0;
	};

	inline COffsets* Offsets = new COffsets;
}