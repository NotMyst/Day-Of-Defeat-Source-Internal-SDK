#pragma once

class CGameTrace;
struct Vector;
struct soundlevel_t;
enum PLAYER_ANIM;

class IMoveHelper
{
public:
	virtual void* GetName(CBaseHandle)const = 0;
	virtual void* ResetTouchList(void) = 0;
	virtual void* AddToTouched(CGameTrace const&, Vector const&) = 0;
	virtual void* ProcessImpacts(void) = 0;
	virtual void* Con_NPrintf(int, char const*, ...) = 0;
	virtual void* StartSound(Vector const&, int, char const*, float, soundlevel_t, int, int) = 0;
	virtual void* StartSound(Vector const&, char const*) = 0;
	virtual void* PlaybackEventFull(int, int, unsigned short, float, Vector&, Vector&, float, float, int, int, int, int) = 0;
	virtual void* PlayerFallingDamage(void) = 0;
	virtual void* PlayerSetAnimation(PLAYER_ANIM) = 0;
	virtual void* GetSurfaceProps(void) = 0;
	virtual void* IsWorldEntity(CBaseHandle const&) = 0;
};