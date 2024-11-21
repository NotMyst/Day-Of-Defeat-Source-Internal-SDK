#include "Netvar.h"

#include "../SDK/ClientClass.h"
#include "../SDK/dt_common.h"
#include "../SDK/dt_recv.h"
#include "../SDK/Interfaces/IBaseClientDLL.h"

inline int GetVarOffsetInternal(RecvTable* pTable, const char* const szVar)
{
	for (int i = 0; i < pTable->GetNumProps(); i++)
	{
		RecvProp* prop = pTable->GetProp(i);

		if (!prop)
			continue;

		if (!strcmp(szVar, prop->m_pVarName))
			return prop->GetOffset();

		RecvTable* dataTable = prop->GetDataTable();

		if (!dataTable)
			continue;

		int offset = GetVarOffsetInternal(dataTable, szVar);

		if (offset)
			return (offset + prop->GetOffset());
	}

	return 0;
}

int Netvar::GetVarOffset(const char* Class, const char* const var)
{
	ClientClass* classes = gClient->GetAllClasses();

	while (classes)
	{
		if (!strcmp(Class, classes->m_pNetworkName))
			return GetVarOffsetInternal(classes->m_pRecvTable, var);

		classes = classes->m_pNext;
	}

	return 0;
}