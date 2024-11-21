#pragma once

class C_DODTeam : public C_Team
{
public:
	virtual void AddPlayerClass(const char* pszClassName) = 0;
};