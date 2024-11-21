#pragma once

class C_BaseEntity;
class C_BaseCombatCharacter;
class C_BasePlayer;
class C_BaseCombatWeapon;
typedef void* edict_t;
class C_DODGameRules
{
public:
	virtual void* Name(void) = 0;
	virtual void* Init(void) = 0;
	virtual void* PostInit(void) = 0;
	virtual void* Shutdown(void) = 0;
	virtual void* LevelInitPreEntity(void) = 0;
	virtual void* LevelInitPostEntity(void) = 0;
	virtual void* LevelShutdownPreClearSteamAPIContext(void) = 0;
	virtual void* LevelShutdownPreEntity(void) = 0;
	virtual void* LevelShutdownPostEntity(void) = 0;
	virtual void* OnSave(void) = 0;
	virtual void* OnRestore(void) = 0;
	virtual void* SafeRemoveIfDesired(void) = 0;
	virtual void* IsPerFrame(void) = 0;
private:
	virtual void* unk01() = 0;
	virtual void* unk02() = 0;
public:
	virtual void* PreRender(void) = 0;
	virtual void* Update(float) = 0;
	virtual void* PostRender(void) = 0;
	virtual void* Damage_IsTimeBased(int) = 0;
	virtual void* Damage_ShouldGibCorpse(int) = 0;
	virtual void* Damage_ShowOnHUD(int) = 0;
	virtual void* Damage_NoPhysicsForce(int) = 0;
	virtual void* Damage_ShouldNotBleed(int) = 0;
	virtual void* Damage_GetTimeBased(void) = 0;
	virtual void* Damage_GetShouldGibCorpse(void) = 0;
	virtual void* Damage_GetShowOnHud(void) = 0;
	virtual void* Damage_GetNoPhysicsForce(void) = 0;
	virtual void* Damage_GetShouldNotBleed(void) = 0;
	virtual void* SwitchToNextBestWeapon(C_BaseCombatCharacter*, C_BaseCombatWeapon*) = 0;
	virtual void* GetNextBestWeapon(C_BaseCombatCharacter*, C_BaseCombatWeapon*) = 0;
	virtual void* ShouldCollide(int, int) = 0;
	virtual float DefaultFOV(void) = 0;
	virtual void* GetViewVectors(void)const = 0;
	virtual void* GetAmmoDamage(C_BaseEntity*, C_BaseEntity*, int) = 0;
	virtual float GetDamageMultiplier(void) = 0;
	virtual void* IsMultiplayer(void) = 0;
	virtual void* GetEncryptionKey(void) = 0;
	virtual void* InRoundRestart(void) = 0;
	virtual void* AllowThirdPersonCamera(void) = 0;
	virtual void* ClientCommandKeyValues(edict_t*, KeyValues*) = 0;
	virtual void* IsConnectedUserInfoChangeAllowed(C_BasePlayer*) = 0;
	virtual void* IsBonusChallengeTimeBased(void) = 0;
	virtual void* AllowMapParticleEffect(char const*) = 0;
	virtual void* AllowWeatherParticles(void) = 0;
	virtual void* AllowMapVisionFilterShaders(void) = 0;
	virtual void* TranslateEffectForVisionFilter(char const*, char const*) = 0;
	virtual bool IsLocalPlayer(int) = 0;
	virtual void* ModifySentChat(char*, int) = 0;
	virtual void* ShouldWarnOfAbandonOnQuit(void) = 0;
	virtual void* GetGameTypeName(void) = 0;
	virtual void* GetGameType(void) = 0;
	virtual void* ShouldDrawHeadLabels(void) = 0;
	virtual void* ClientSpawned(edict_t*) = 0;
	virtual void* OnFileReceived(char const*, unsigned int) = 0;
	virtual void* IsHolidayActive(int)const = 0;
	virtual void* IsManualMapChangeOkay(char const**) = 0;
	virtual void* GetCaptureValueForPlayer(C_BasePlayer*) = 0;
	virtual void* TeamMayCapturePoint(int, int) = 0;
	virtual void* PlayerMayCapturePoint(C_BasePlayer*, int, char*, int) = 0;
	virtual void* PlayerMayBlockPoint(C_BasePlayer*, int, char*, int) = 0;
	virtual void* PointsMayBeCaptured(void) = 0;
	virtual void* SetLastCapPointChanged(int) = 0;
	virtual void* GetDODViewVectors(void)const = 0;
};