#pragma once

class CTraceListData;
class IEntityEnumerator;

enum TraceType_t
{
	TRACE_EVERYTHING = 0,
	TRACE_WORLD_ONLY,				// NOTE: This does *not* test static props!!!
	TRACE_ENTITIES_ONLY,			// NOTE: This version will *not* test static props
	TRACE_EVERYTHING_FILTER_PROPS,	// NOTE: This version will pass the IHandleEntity for props through the filter, unlike all other filters
};

class ITraceFilter
{
public:
	virtual TraceType_t	GetTraceType() const
	{
		return TRACE_EVERYTHING;
	}

	bool ShouldHitEntity(void* pEntityHandle, int contentsMask)
	{
		return pEntityHandle != m_Skip;
	}

	IClientEntity* m_Skip;
};

struct csurface_t
{
	const char* name;
	short		surfaceProps;
	unsigned short	flags;		// BUGBUG: These are declared per surface, not per material, but this database is per-material now
};

struct Ray_t {
public:
	VectorAligned m_start;
	VectorAligned m_delta;
	VectorAligned m_start_offset;
	VectorAligned m_extents;
	const matrix3x4_t* m_world_axis_transform;
	bool m_is_ray;
	bool m_is_swept;

	void Init(Vector start, Vector end) {
		m_delta = end - start;

		m_is_swept = m_delta.LengthSqr() != 0;

		m_extents = VectorAligned{};

		m_world_axis_transform = nullptr;
		m_is_ray = true;

		m_start_offset = VectorAligned{};
		m_start = start;
	}
};

struct cplane_t
{
	Vector	normal;
	float	dist;
	byte	type;
	byte	signbits;
	byte	pad[2];
};

class CBaseTrace
{
public:
	Vector			startpos;				// start position
	Vector			endpos;					// final position
	cplane_t		plane;					// surface normal at impact

	float			fraction;				// time completed, 1.0 = didn't hit anything

	int				contents;				// contents on other side of surface hit
	unsigned short	dispFlags;				// displacement flags for marking surfaces with data

	bool			allsolid;				// if true, plane is not valid
	bool			startsolid;				// if true, the initial point was in a solid area

};

class CGameTrace : public CBaseTrace
{
public:
	inline bool DidHit() const
	{
		return fraction < 1 || allsolid || startsolid;
	}

	float		fractionleftsolid;		// time we left a solid, only valid if we started in solid
	csurface_t	surface;				// surface hit (impact surface)

	int			hitgroup;				// 0 == generic, non-zero is specific body part
	short		physicsbone;			// physics bone hit by trace in studio

	C_BaseEntity* m_pEnt;

	// NOTE: this member is overloaded.
	// If hEnt points at the world entity, then this is the static prop index.
	// Otherwise, this is the hitbox index.
	int			hitbox;					// box hit by trace in studio

private:
	// No copy constructors allowed
	//CGameTrace(const CGameTrace& vOther);
};

typedef CGameTrace trace_t;

class IEngineTrace
{
public:
	virtual void* GetPointContents(Vector const&, IHandleEntity**) = 0;
	virtual void* GetPointContents_Collideable(ICollideable*, Vector const&) = 0;
	virtual void* ClipRayToEntity(Ray_t const&, unsigned int, IHandleEntity*, CGameTrace*) = 0;
	virtual void* ClipRayToCollideable(Ray_t const&, unsigned int, ICollideable*, CGameTrace*) = 0;
	virtual void TraceRay(const Ray_t& ray, unsigned int fMask, ITraceFilter* pTraceFilter, trace_t* pTrace) = 0;
	virtual void* SetupLeafAndEntityListRay(Ray_t const&, CTraceListData&) = 0;
	virtual void* SetupLeafAndEntityListBox(Vector const&, Vector const&, CTraceListData&) = 0;
	virtual void* TraceRayAgainstLeafAndEntityList(Ray_t const&, CTraceListData&, unsigned int, ITraceFilter*, CGameTrace*) = 0;
	virtual void* SweepCollideable(ICollideable*, Vector const&, Vector const&, QAngle const&, unsigned int, ITraceFilter*, CGameTrace*) = 0;
	virtual void* EnumerateEntities(Ray_t const&, bool, IEntityEnumerator*) = 0;
	virtual void* EnumerateEntities(Vector const&, Vector const&, IEntityEnumerator*) = 0;
	virtual void* GetCollideable(IHandleEntity*) = 0;
	virtual void* GetStatByIndex(int, bool) = 0;
	virtual void* GetBrushesInAABB(Vector const&, Vector const&, void*, int) = 0;
	virtual void* GetCollidableFromDisplacementsInAABB(Vector const&, Vector const&) = 0;
	virtual void* GetBrushInfo(int, void*, int*) = 0;
	virtual void* PointOutsideWorld(Vector const&) = 0;
	virtual void* GetLeafContainingPoint(Vector const&) = 0;
	virtual void* HandleEntityToCollideable(IHandleEntity*, ICollideable**, char const**) = 0;
	virtual void* GetWorldCollideable(void) = 0;
	virtual void* SetTraceEntity(ICollideable*, CGameTrace*) = 0;
	virtual void* SpatialPartitionMask(void)const = 0;
	virtual void* SpatialPartitionTriggerMask(void)const = 0;
};

inline IEngineTrace* gTrace = nullptr;