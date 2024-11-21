#pragma once

#define INVALID_EHANDLE_INDEX 0xFFFFFFFF

class CBaseHandle;

class IHandleEntity
{
public:
	virtual ~IHandleEntity() = 0;
	virtual void SetRefEHandle(const CBaseHandle& handle) = 0;
	virtual const CBaseHandle& GetRefEHandle() const = 0;
};

class CBaseHandle
{
public:
	unsigned long m_Index;

	inline CBaseHandle()
	{
		m_Index = INVALID_EHANDLE_INDEX;
	}

	inline operator bool()
	{
		return m_Index != INVALID_EHANDLE_INDEX;
	}

	inline bool IsValid()
	{
		return m_Index != INVALID_EHANDLE_INDEX;
	}

	inline bool operator ==(const CBaseHandle& other) const
	{
		return m_Index == other.m_Index;
	}

	inline bool operator ==(const IHandleEntity* pEnt) const
	{
		return Get() == pEnt;
	}

	inline const CBaseHandle& Set(const IHandleEntity* pEntity)
	{
		if (pEntity)
			*this = pEntity->GetRefEHandle();
		else
			m_Index = INVALID_EHANDLE_INDEX;

		return *this;
	}

	inline const CBaseHandle& operator=(const IHandleEntity* pEntity)
	{
		return Set(pEntity);
	}

	IHandleEntity* Get() const;
};

template< class T >
class CHandle : public CBaseHandle
{
public:
	inline T* Get() const
	{
		return reinterpret_cast<T*>(Get());
	}
};