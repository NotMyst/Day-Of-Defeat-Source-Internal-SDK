#include "Handle.h"

#include "Interfaces/IClientEntityList.h"

IHandleEntity* CBaseHandle::Get() const
{
	return reinterpret_cast<IHandleEntity*>(gEntityList->GetClientEntityFromHandle(*this));
}