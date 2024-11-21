#pragma once

typedef enum
{
	WEAPON_NONE = 0,

	//Melee
	WEAPON_AMERKNIFE,
	WEAPON_SPADE,

	//Pistols
	WEAPON_COLT,
	WEAPON_P38,
	WEAPON_C96,

	//Rifles
	WEAPON_GARAND,
	WEAPON_M1CARBINE,
	WEAPON_K98,

	//Sniper Rifles
	WEAPON_SPRING,
	WEAPON_K98_SCOPED,

	//SMG
	WEAPON_THOMPSON,
	WEAPON_MP40,
	WEAPON_MP44,
	WEAPON_BAR,

	//Machine guns
	WEAPON_30CAL,
	WEAPON_MG42,

	//Rocket weapons
	WEAPON_BAZOOKA,
	WEAPON_PSCHRECK,

	//Grenades
	WEAPON_FRAG_US,
	WEAPON_FRAG_GER,

	WEAPON_FRAG_US_LIVE,
	WEAPON_FRAG_GER_LIVE,

	WEAPON_SMOKE_US,
	WEAPON_SMOKE_GER,

	WEAPON_RIFLEGREN_US,
	WEAPON_RIFLEGREN_GER,

	WEAPON_RIFLEGREN_US_LIVE,
	WEAPON_RIFLEGREN_GER_LIVE,

	WEAPON_THOMPSON_PUNCH,
	WEAPON_MP40_PUNCH,

	WEAPON_GARAND_ZOOMED,
	WEAPON_K98_ZOOMED,
	WEAPON_SPRING_ZOOMED,
	WEAPON_K98_SCOPED_ZOOMED,

	WEAPON_30CAL_UNDEPLOYED,
	WEAPON_MG42_UNDEPLOYED,

	WEAPON_BAR_SEMIAUTO,
	WEAPON_MP44_SEMIAUTO,

	WEAPON_MAX,

} DODWeaponID;

class C_WeaponDODBase : public C_BaseCombatWeapon
{
public:
	NETVAR(int, m_iViewModelIndex, "CWeaponDODBase");
	NETVAR(int, m_iWorldModelIndex, "CWeaponDODBase");
	NETVAR(int, m_iState, "CWeaponDODBase");
	NETVAR(CHandle<C_BaseCombatCharacter>, m_hOwner, "CWeaponDODBase");
	NETVAR(int, m_iReloadModelIndex, "CWeaponDODBase");
	NETVAR(Vector, m_vInitialDropVelocity, "CWeaponDODBase");
	NETVAR(float, m_flSmackTime, "CWeaponDODBase");

public:
	virtual bool DefaultReload(int iClipSize1, int iClipSize2, int iActivity) = 0;
	virtual Activity GetIdleActivity(void) = 0;
	virtual DODWeaponID GetWeaponID(void) const = 0;
	virtual DODWeaponID GetStatsWeaponID(void) = 0;
	virtual DODWeaponID GetAltWeaponID(void) const = 0;
	virtual bool IsSilenced(void) const = 0;
	virtual void SetWeaponModelIndex(const char* pName) = 0;
	virtual bool CanDrop(void) = 0;
	virtual bool ShouldDrawViewModel(void) = 0;
	virtual bool ShouldDrawMuzzleFlash(void) = 0;
	virtual float GetWeaponAccuracy(float flPlayerSpeed) = 0;
	virtual bool HideViewModelWhenZoomed(void) = 0;
	virtual bool CanAttack(void) = 0;
	virtual bool ShouldAutoReload(void) = 0;
	virtual bool ShouldAutoEjectBrass(void) = 0;
	virtual bool GetEjectBrassShellType(void) = 0;
	virtual void CheckForAltWeapon(int iCurrentState) = 0;
	virtual Vector GetDesiredViewModelOffset(C_DODPlayer* pOwner) = 0;
	virtual float GetViewModelSwayScale(void) = 0;
	virtual void OnWeaponDropped(void) = 0;
	virtual const char* GetSecondaryDeathNoticeName(void) = 0;
	virtual C_BaseEntity* MeleeAttack(int iDamageAmount, int iDamageType, float flDmgDelay, float flAttackDelay) = 0;
	virtual Activity GetMeleeActivity(void) = 0;
	virtual Activity GetStrongMeleeActivity(void) = 0;
	virtual float GetRecoil(void) = 0;

public:
	bool IsGrenade()
	{
		int id = (int)GetWeaponID();
		return id > 18 && id < 29;
	}

	bool IsLiveGrenade()
	{
		DODWeaponID id = GetWeaponID();
		return id == WEAPON_FRAG_US_LIVE || id == WEAPON_FRAG_GER_LIVE || id == WEAPON_RIFLEGREN_US_LIVE || id == WEAPON_RIFLEGREN_GER_LIVE;
	}
};