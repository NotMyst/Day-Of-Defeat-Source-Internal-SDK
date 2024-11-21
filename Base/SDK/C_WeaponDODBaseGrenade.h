#pragma once

class C_WeaponDODBaseGrenade : public C_WeaponDODBase
{
public:
	NETVAR(int, m_iReloadModelIndex, "CWeaponDODBaseGrenade");
	NETVAR(Vector, m_vInitialDropVelocity, "CWeaponDODBaseGrenade");
	NETVAR(float, m_flSmackTime, "CWeaponDODBaseGrenade");
	NETVAR(bool, m_bPinPulled, "CWeaponDODBaseGrenade");
	NETVAR(bool, m_bArmed, "CWeaponDODBaseGrenade");
};