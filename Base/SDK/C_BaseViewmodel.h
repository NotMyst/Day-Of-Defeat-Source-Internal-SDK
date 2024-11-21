#pragma once

class C_BaseCombatCharacter;
class C_BaseCombatWeapon;

class C_BaseViewmodel : public C_BaseAnimating
{
public:
	NETVAR(int, m_nModelIndex, "CBaseViewModel");
	NETVAR(int, m_nSkin, "CBaseViewModel");
	NETVAR(int, m_nBody, "CBaseViewModel");
	NETVAR(int, m_nSequence, "CBaseViewModel");
	NETVAR(short, m_nViewModelIndex, "CBaseViewModel");
	NETVAR(float, m_flPlaybackRate, "CBaseViewModel");
	NETVAR(int, m_fEffects, "CBaseViewModel");
	NETVAR(int, m_nAnimationParity, "CBaseViewModel");
	NETVAR(CHandle<C_BaseCombatWeapon>, m_hWeapon, "CBaseViewModel");
	NETVAR(CHandle<C_BaseCombatCharacter>, m_hOwner, "CBaseViewModel");
	NETVAR(int, m_nNewSequenceParity, "CBaseViewModel");
	NETVAR(int, m_nResetEventsParity, "CBaseViewModel");
	NETVAR(int, m_nMuzzleFlashParity, "CBaseViewModel");
	NETVAR(float, m_flPoseParameter, "CBaseViewModel");
};