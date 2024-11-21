#pragma once

class C_DODPlayer : public C_BasePlayer
{
public:
	NETVAR(float, m_flStamina, "CDODPlayer");
	NETVAR(float, m_flSlowedUntilTime, "CDODPlayer");
	NETVAR(bool, m_bProne, "CDODPlayer");
	NETVAR(bool, m_bIsSprinting, "CDODPlayer");
	NETVAR(float, m_flGoProneTime, "CDODPlayer");
	NETVAR(float, m_flUnProneTime, "CDODPlayer");
	NETVAR(float, m_flDeployChangeTime, "CDODPlayer");
	NETVAR(float, m_flDeployedHeight, "CDODPlayer");
	NETVAR(bool, m_bPlanting, "CDODPlayer");
	NETVAR(bool, m_bDefusing, "CDODPlayer");
	NETVAR(int, m_iPlayerClass, "CDODPlayer");
	NETVAR(int, m_iDesiredPlayerClass, "CDODPlayer");
	NETVAR(float, m_flDeployedYawLimitLeft, "CDODPlayer");
	NETVAR(float, m_flDeployedYawLimitRight, "CDODPlayer");
	NETVAR(int, m_iCPIndex, "CDODPlayer");
	NETVAR(bool, m_bPlayerDominated, "CDODPlayer");
	NETVAR(bool, m_bPlayerDominatingMe, "CDODPlayer");
	NETVAR(float, m_flStunDuration, "CDODPlayer");
	NETVAR(float, m_flStunMaxAlpha, "CDODPlayer");
	NETVAR(int, m_iProgressBarDuration, "CDODPlayer");
	NETVAR(float, m_flProgressBarStartTime, "CDODPlayer");
	NETVAR(EHANDLE, m_hRagdoll, "CDODPlayer");
	NETVAR(bool, m_bSpawnInterpCounter, "CDODPlayer");
	NETVAR(int, m_iAchievementAwardsMask, "CDODPlayer");

public:
	virtual bool SetFOV(C_BaseEntity* pRequester, int FOV, float zoomRate = 0.0f) = 0;
};