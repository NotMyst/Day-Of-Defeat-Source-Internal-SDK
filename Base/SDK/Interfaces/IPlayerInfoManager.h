#pragma once

typedef void* edict_t;

class IPlayerInfoManager
{
public:
	virtual void* GetPlayerInfo(edict_t* pEdict) = 0;
	virtual CGlobalVarsBase* GetGlobalVars() = 0;
};

inline IPlayerInfoManager* gPlayerInfoMgr = nullptr;