#pragma once

typedef void* (*CreateInterfaceFn)(const char* pName, int* pReturnCode);
typedef void* (*InstantiateInterfaceFn)();

class InterfaceReg
{
public:
	InstantiateInterfaceFn	m_CreateFn;
	const char* m_pName;

	InterfaceReg* m_pNext; // For the global list.
	static InterfaceReg* s_pInterfaceRegs;
};