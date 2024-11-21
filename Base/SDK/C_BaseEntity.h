#pragma once

class CTakeDamageInfo;
class CEntityMapData;
class C_BaseEntity;
class CStudioHdr;
class CGameTrace;
class CChoreoScene;
class CChoreoActor;
class C_BaseViewModel;
class CCollisionProperty;
class CDamageModifier;
class C_BaseAnimating;
class C_BaseCombatWeapon;
class CSceneEventInfo;
class CChoreoEvent;
class KeyValues;
struct model_t;
struct Quaternion;
class IGameEvent;
class IBoneSetup;
class C_Team;
class CBoneBitList;
class CBoneAccessor;
struct bf_read;
struct bf_write;
class CSteamID;
class CViewSetup;
class IClientVehicle;
class Color;
class CNewParticleEffect;
struct ClientModelRenderInfo_t;
struct flexsettinghdr_t;
struct EmitSound_t;
class CSoundParameters;
class CDmgAccumulator;
struct stepsoundtimes_t;
struct surfacedata_t;
class ITraceFilter;
class IPhysicsObject;
class ISave;
class IRestore;
class CUserCmd;
struct SpatializationInfo_t;
struct FireBulletsInfo_t;
struct Ray_t;
struct datamap_t;
class CGameTrace;
enum SolidType_t;
typedef CGameTrace trace_t;

enum CollideType_t
{
	ENTITY_SHOULD_NOT_COLLIDE = 0,
	ENTITY_SHOULD_COLLIDE,
	ENTITY_SHOULD_RESPOND
};

enum
{
	ADDDECAL_TO_ALL_LODS = -1
};

typedef CHandle<C_BaseEntity> EHANDLE;

class C_BaseEntity : public IClientEntity
{
public:
	NETVAR(float, m_flAnimTime, "CBaseEntity");
	NETVAR(float, m_flSimulationTime, "CBaseEntity");
	NETVAR(std::byte, m_ubInterpolationFrame, "CBaseEntity");
	NETVAR(Vector, m_vecOrigin, "CBaseEntity");
	NETVAR(QAngle, m_angRotation, "CBaseEntity");
	NETVAR(short, m_nModelIndex, "CBaseEntity");
	NETVAR(int, m_fEffects, "CBaseEntity");
	NETVAR(unsigned char, m_nRenderMode, "CBaseEntity");
	NETVAR(unsigned char, m_nRenderFX, "CBaseEntity");
	NETVAR(Color, m_clrRender, "CBaseEntity");
	NETVAR(int, m_iTeamNum, "CBaseEntity");
	NETVAR(int, m_CollisionGroup, "CBaseEntity");
	NETVAR(float, m_flElasticity, "CBaseEntity");
	NETVAR(float, m_flShadowCastDistance, "CBaseEntity");
	NETVAR(EHANDLE, m_hOwnerEntity, "CBaseEntity");
	NETVAR(EHANDLE, m_hEffectEntity, "CBaseEntity");
	NETVAR_(EHANDLE, m_pMoveParent, moveparent, "CBaseEntity");
	NETVAR(int, m_iParentAttachment, "CBaseEntity");
	NETVAR_(unsigned char, m_MoveType, movetype, "CBaseEntity");
	NETVAR_(unsigned char, m_MoveCollide, movecollide, "CBaseEntity");
	NETVAR(CCollisionProperty, m_Collision, "CBaseEntity");
	NETVAR(int, m_iTextureFrameIndex, "CBaseEntity");
	NETVAR(bool, m_bSimulatedEveryTick, "CBaseEntity");
	NETVAR(bool, m_bAnimatedEveryTick, "CBaseEntity");
	NETVAR(bool, m_bAlternateSorting, "CBaseEntity");

public:
	virtual datamap_t* GetDataDescMap() = 0;
	virtual void* YouForgotToImplementOrDeclareClientClass() = 0;
	virtual datamap_t* GetPredDescMap() = 0;
	virtual void FireBullets(const FireBulletsInfo_t& info) = 0;
	virtual void ModifyFireBulletsDamage(CTakeDamageInfo* dmgInfo) = 0;
	virtual bool ShouldDrawUnderwaterBulletBubbles() = 0;
	virtual bool ShouldDrawWaterImpacts(void) = 0;
	virtual bool HandleShotImpactingWater(const FireBulletsInfo_t& info, const Vector& vecEnd, ITraceFilter* pTraceFilter, Vector* pVecTracerDest) = 0;
	virtual ITraceFilter* GetBeamTraceFilter(void) = 0;
	virtual void DispatchTraceAttack(const CTakeDamageInfo& info, const Vector& vecDir, trace_t* ptr, CDmgAccumulator* pAccumulator = NULL) = 0;
	virtual void TraceAttack(const CTakeDamageInfo& info, const Vector& vecDir, trace_t* ptr, CDmgAccumulator* pAccumulator = NULL) = 0;
	virtual void DoImpactEffect(trace_t& tr, int nDamageType) = 0;
	virtual void MakeTracer(const Vector& vecTracerSrc, const trace_t& tr, int iTracerType) = 0;
	virtual int	GetTracerAttachment(void) = 0;
	virtual int BloodColor() = 0;
	virtual const char* GetTracerType() = 0;
	virtual void Spawn(void) = 0;
	virtual void SpawnClientEntity(void) = 0;
	virtual void Precache(void) = 0;
	virtual void Activate() = 0;
	virtual void ParseMapData(CEntityMapData* mapData) = 0;
	virtual bool KeyValue(const char* szKeyName, const char* szValue) = 0;
	virtual bool KeyValue(const char* szKeyName, float flValue) = 0;
	virtual bool KeyValue(const char* szKeyName, const Vector& vecValue) = 0;
	virtual bool GetKeyValue(const char* szKeyName, char* szValue, int iMaxLen) = 0;
	virtual bool Init(int entnum, int iSerialNum) = 0;
	virtual IClientUnknown* GetIClientUnknown() = 0;
	virtual C_BaseAnimating* GetBaseAnimating() = 0;
	virtual void SetClassname(const char* className) = 0;
	virtual void RecordToolMessage() = 0;
	virtual Vector GetObserverCamOrigin(void) = 0;
	virtual bool TestCollision(const Ray_t& ray, unsigned int fContentsMask, trace_t& tr) = 0;
	virtual bool TestHitboxes(const Ray_t& ray, unsigned int fContentsMask, trace_t& tr) = 0;
	virtual float GetAttackDamageScale(void) = 0;
	virtual void ValidateModelIndex(void) = 0;
	virtual void SetDormant(bool bDormant) = 0;
	virtual int GetEFlags() const = 0;
	virtual void SetEFlags(int iEFlags) = 0;
	virtual bool ShouldSavePhysics() = 0;
	virtual void OnSave() = 0;
	virtual void OnRestore() = 0;
	virtual int ObjectCaps(void) = 0;
	virtual int Save(ISave& save) = 0;
	virtual int	Restore(IRestore& restore) = 0;
	virtual bool CreateVPhysics() = 0;
	virtual void VPhysicsDestroyObject(void) = 0;
	virtual void VPhysicsUpdate(IPhysicsObject* pPhysics) = 0;
	virtual int VPhysicsGetObjectList(IPhysicsObject** pList, int listMax) = 0;
	virtual bool VPhysicsIsFlesh(void) = 0;
	virtual void AddEntity(void) = 0;
	virtual const Vector& GetPrevLocalOrigin() const = 0;
	virtual const QAngle& GetPrevLocalAngles() const = 0;
	virtual int CalcOverrideModelIndex() = 0;
	virtual const Vector& WorldAlignMins() const = 0;
	virtual const Vector& WorldAlignMaxs() const = 0;
	virtual const Vector& WorldSpaceCenter() const = 0;
	virtual void ComputeWorldSpaceSurroundingBox(Vector* pVecWorldMins, Vector* pVecWorldMaxs) = 0;
	virtual float GetHealthBarHeightOffset() const = 0;
	virtual SolidType_t	GetSolid(void) const = 0;
	virtual int GetSolidFlags(void) const = 0;
	virtual bool GetAttachment(int number, Vector& origin) = 0;
	virtual bool GetAttachmentVelocity(int number, Vector& originVel, Quaternion& angleVel) = 0;
	virtual C_Team* GetTeam(void) const = 0;
	virtual int GetTeamNumber(void) const = 0;
	virtual void ChangeTeam(int iTeamNum) = 0;
	virtual int GetRenderTeamNumber(void) = 0;
	virtual bool InSameTeam(const C_BaseEntity* pEntity) const = 0;
	virtual bool InLocalTeam(void) = 0;
	virtual bool IsValidIDTarget(void) = 0;
	virtual const char* GetIDString(void) = 0;
	virtual void ModifyEmitSoundParams(EmitSound_t& params) = 0;
	virtual bool InitializeAsClientEntity(const char* pszModelName, RenderGroup_t renderGroup) = 0;
	virtual void Simulate() = 0;
	virtual IClientVehicle* GetClientVehicle() = 0;
	virtual void GetAimEntOrigin(IClientEntity* pAttachedTo, Vector* pAbsOrigin, QAngle* pAbsAngles) = 0;
	virtual const Vector& GetOldOrigin() = 0;
	virtual RenderGroup_t GetRenderGroup() = 0;
	virtual void GetToolRecordingState(KeyValues* msg) = 0;
	virtual void CleanupToolRecordingState(KeyValues* msg) = 0;
	virtual CollideType_t GetCollideType(void) = 0;
	virtual void UpdateVisibility() = 0;
	virtual bool IsSelfAnimating() = 0;
	virtual	void OnLatchInterpolatedVariables(int flags) = 0;
	virtual CStudioHdr* OnNewModel() = 0;
	virtual void OnNewParticleEffect(const char* pszParticleName, CNewParticleEffect* pNewParticleEffect) = 0;
	virtual void ResetLatched() = 0;
	virtual bool Interpolate(float currentTime) = 0;
	virtual bool IsSubModel(void) = 0;
	virtual void CreateLightEffects(void) = 0;
	virtual void Clear(void) = 0;
	virtual int DrawBrushModel(bool bTranslucent, int nFlags, bool bTwoPass) = 0;
	virtual float GetTextureAnimationStartTime() = 0;
	virtual void TextureAnimationWrapped() = 0;
	virtual void SetNextClientThink(float nextThinkTime) = 0;
	virtual void SetHealth(int iHealth) = 0;
	virtual int GetHealth() const = 0;
	virtual int GetMaxHealth() const = 0;
	virtual bool IsVisibleToTargetID(void) const = 0;
	virtual bool IsHealthBarVisible(void) const = 0;
	virtual void AddDecal(const Vector& rayStart, const Vector& rayEnd, const Vector& decalCenter, int hitbox, int decalIndex, bool doTrace, trace_t& tr, int maxLODToDecal = ADDDECAL_TO_ALL_LODS) = 0;
	virtual void AddColoredDecal(const Vector& rayStart, const Vector& rayEnd, const Vector& decalCenter, int hitbox, int decalIndex, bool doTrace, trace_t& tr, Color cColor, int maxLODToDecal = ADDDECAL_TO_ALL_LODS) = 0;
	virtual bool IsClientCreated(void) const = 0;
	virtual void UpdateOnRemove(void) = 0;
	virtual void SUB_Remove(void) = 0;
	virtual void SetPredictable(bool state) = 0;
	virtual int RestoreData(const char* context, int slot, int type) = 0;
	virtual char const* DamageDecal(int bitsDamageType, int gameMaterial) = 0;
	virtual void DecalTrace(trace_t* pTrace, char const* decalName) = 0;
	virtual void ImpactTrace(trace_t* pTrace, int iDamageType, const char* pCustomImpactName) = 0;
	virtual bool ShouldPredict(void) = 0;
	virtual void Think(void) = 0;
	virtual bool CanBePoweredUp(void) = 0;
	virtual bool AttemptToPowerup(int iPowerup, float flTime, float flAmount = 0, C_BaseEntity* pAttacker = NULL, CDamageModifier* pDamageModifier = NULL) = 0;
	virtual bool IsCurrentlyTouching(void) const = 0;
	virtual void StartTouch(C_BaseEntity* pOther) = 0;
	virtual void Touch(C_BaseEntity* pOther) = 0;
	virtual void EndTouch(C_BaseEntity* pOther) = 0;
	virtual unsigned int PhysicsSolidMaskForEntity(void) const = 0;
	virtual void PhysicsSimulate(void) = 0;
	virtual bool IsAlive(void) = 0;
	virtual bool IsPlayer(void) const = 0;
	virtual bool IsBaseCombatCharacter(void) = 0;
	virtual C_BaseCombatCharacter* MyCombatCharacterPointer(void) = 0;
	virtual bool IsNPC(void) = 0;
	virtual bool IsNextBot() = 0;
	virtual bool IsBaseObject(void) const = 0;
	virtual bool IsBaseCombatWeapon(void) const = 0;
	virtual C_BaseCombatWeapon* MyCombatWeaponPointer() = 0;
	virtual bool IsCombatItem(void) const = 0;
	virtual bool IsBaseTrain(void) const = 0;
	virtual Vector EyePosition(void) = 0;
	virtual const QAngle& EyeAngles(void) = 0;
	virtual const QAngle& LocalEyeAngles(void) = 0;
	virtual Vector EarPosition(void) = 0;
	virtual bool ShouldCollide(int collisionGroup, int contentsMask) const = 0;
	virtual const Vector& GetViewOffset() const = 0;
	virtual void SetViewOffset(const Vector& v) = 0;
	virtual bool ShouldInterpolate() = 0;
	virtual unsigned char GetClientSideFade() = 0;
	virtual void BoneMergeFastCullBloat(Vector& localMins, Vector& localMaxs, const Vector& thisEntityMins, const Vector& thisEntityMaxs) const = 0;
	virtual bool OnPredictedEntityRemove(bool isbeingremoved, C_BaseEntity* predicted) = 0;
	virtual C_BaseEntity* GetShadowUseOtherEntity(void) const = 0;
	virtual void SetShadowUseOtherEntity(C_BaseEntity* pEntity) = 0;
	virtual bool AddRagdollToFadeQueue(void) = 0;
	virtual bool IsDeflectable() = 0;
	virtual int	GetStudioBody(void) = 0;
	virtual void PerformCustomPhysics(Vector* pNewPosition, Vector* pNewVelocity, QAngle* pNewAngles, QAngle* pNewAngVelocity) = 0;
	virtual float* GetRenderClipPlane(void) = 0;

public:
	inline ETeam GetETeam()
	{
		return static_cast<ETeam>(m_iTeamNum());
	}

	inline bool IsPlayer()
	{
		return GetClientClass()->m_ClassID == EClientClass::CDODPlayer;
	}

	inline bool IsViewModel()
	{
		return GetClientClass()->m_ClassID == EClientClass::CDODViewModel;
	}
};