#pragma once

enum EUniverse
{
	k_EUniverseInvalid = 0,
	k_EUniversePublic = 1,
	k_EUniverseBeta = 2,
	k_EUniverseInternal = 3,
	k_EUniverseDev = 4,
	// k_EUniverseRC = 5,				// no such universe anymore
	k_EUniverseMax
};

class CSteamID
{
public:
	union SteamID_t
	{
		struct SteamIDComponent_t
		{
			std::uint32_t				m_unAccountID : 32;			// unique account identifier
			unsigned int		m_unAccountInstance : 20;	// dynamic instance ID
			unsigned int		m_EAccountType : 4;			// type of account - can't show as EAccountType, due to signed / unsigned difference
			EUniverse			m_EUniverse : 8;	// universe this account belongs to
		} m_comp;

		std::uint64_t m_unAll64Bits;
	} m_steamid;
};