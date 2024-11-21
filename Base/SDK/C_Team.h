#pragma once

class C_Team : public C_BaseEntity
{
public:
	NETVAR(int, m_iTeamNum, "CTeam");
	NETVAR(int, m_iScore, "CTeam");
	NETVAR(int, m_iRoundsWon, "CTeam");
	NETVAR(const char*, m_szTeamname, "CTeam");

public:
	virtual char* Get_Name(void) = 0;
	virtual int Get_Score(void) = 0;
	virtual int Get_Deaths(void) = 0;
	virtual int	Get_Ping(void) = 0;
	virtual int Get_Number_Players(void) = 0;
	virtual bool ContainsPlayer(int iPlayerIndex) = 0;
	virtual int GetNumPlayers(void) = 0;
};