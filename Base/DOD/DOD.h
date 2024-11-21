#pragma once

#include "../Offsets/Offsets.h"

namespace DOD
{
	class CDODS
	{
	public:
		template<typename T>
		inline T GetInterface(Module_t mod, const char* version)
		{
			return mod.GetExport<T(*)(const char*, void*)>("CreateInterface")(version, nullptr);
		}

		void Init();
	};

	inline CDODS* S = new CDODS;

	class CUtil
	{
	public:
		void FixMovement(CUserCmd* cmd, CUserCmd oCmd);
	};

	inline CUtil* Util = new CUtil;

	inline CGlobalVarsBase* GlobalVars = nullptr;
	inline C_DODGameRules* GameRules = nullptr;
}