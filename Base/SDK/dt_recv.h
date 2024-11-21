#pragma once

#include "dt_common.h"

#ifdef GetProp
#undef GetProp
#endif

class SendProp;

class RecvTable;
class RecvProp;
class CRecvDecoder;
class CRecvProxyData;

typedef void (*RecvVarProxyFn)(const CRecvProxyData* pData, void* pStruct, void* pOut);
typedef void (*ArrayLengthRecvProxyFn)(void* pStruct, int objectID, int currentArrayLength);
typedef void (*DataTableRecvVarProxyFn)(const RecvProp* pProp, void** pOut, void* pData, int objectID);

#ifdef GetProp
#undef GetProp
#endif

class RecvProp
{
public:

	const char* m_pVarName;
	SendPropType			m_RecvType;
	int						m_Flags;
	int						m_StringBufferSize;

	inline int GetOffset() const
	{
		return m_Offset;
	}

	inline RecvTable* GetDataTable() const
	{
		return m_pDataTable;
	}

private:

	bool					m_bInsideArray;		// Set to true by the engine if this property sits inside an array.

	// Extra data that certain special property types bind to the property here.
	const void* m_pExtraData;

	// If this is an array (DPT_Array).
	RecvProp* m_pArrayProp;
	ArrayLengthRecvProxyFn	m_ArrayLengthProxy;

	RecvVarProxyFn			m_ProxyFn;
	DataTableRecvVarProxyFn	m_DataTableProxyFn;	// For RDT_DataTable.

	RecvTable* m_pDataTable;
	int						m_Offset;

	int						m_ElementStride;
	int						m_nElements;

	const char* m_pParentArrayPropName;
};

class RecvTable
{
public:
	typedef RecvProp	PropType;
public:
	RecvProp* m_pProps;
	int	m_nProps;
	CRecvDecoder* m_pDecoder;
	const char* m_pNetTableName;

	inline int GetNumProps()
	{
		return m_nProps;
	}

	inline RecvProp* GetProp(int i)
	{
		return &m_pProps[i];
	}
private:
	bool			m_bInitialized;
	bool			m_bInMainList;
};