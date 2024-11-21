#pragma once

#define IN_ATTACK		(1 << 0)
#define IN_JUMP			(1 << 1)
#define IN_DUCK			(1 << 2)
#define IN_FORWARD		(1 << 3)
#define IN_BACK			(1 << 4)
#define IN_USE			(1 << 5)
#define IN_CANCEL		(1 << 6)
#define IN_LEFT			(1 << 7)
#define IN_RIGHT		(1 << 8)
#define IN_MOVELEFT		(1 << 9)
#define IN_MOVERIGHT	(1 << 10)
#define IN_ATTACK2		(1 << 11)
#define IN_RUN			(1 << 12)
#define IN_RELOAD		(1 << 13)
#define IN_ALT1			(1 << 14)
#define IN_ALT2			(1 << 15)
#define IN_SCORE		(1 << 16)   // Used by client.dll for when scoreboard is held down
#define IN_SPEED		(1 << 17)	// Player is holding the speed key
#define IN_WALK			(1 << 18)	// Player holding walk key
#define IN_ZOOM			(1 << 19)	// Zoom key for HUD zoom
#define IN_WEAPON1		(1 << 20)	// weapon defines these bits
#define IN_WEAPON2		(1 << 21)
#define IN_BULLRUSH		(1 << 22)
#define IN_GRENADE1		(1 << 23)
#define IN_GRENADE2		(1 << 24)
#define	IN_ATTACK3		(1 << 25)

#define TEXTURE_GROUP_LIGHTMAP						"Lightmaps"
#define TEXTURE_GROUP_WORLD							"World textures"
#define TEXTURE_GROUP_MODEL							"Model textures"
#define TEXTURE_GROUP_VGUI							"VGUI textures"
#define TEXTURE_GROUP_PARTICLE						"Particle textures"
#define TEXTURE_GROUP_DECAL							"Decal textures"
#define TEXTURE_GROUP_SKYBOX						"SkyBox textures"
#define TEXTURE_GROUP_CLIENT_EFFECTS				"ClientEffect textures"
#define TEXTURE_GROUP_OTHER							"Other textures"
#define TEXTURE_GROUP_PRECACHED						"Precached"				// TODO: assign texture groups to the precached materials
#define TEXTURE_GROUP_CUBE_MAP						"CubeMap textures"
#define TEXTURE_GROUP_RENDER_TARGET					"RenderTargets"
#define TEXTURE_GROUP_RUNTIME_COMPOSITE				"Runtime Composite"
#define TEXTURE_GROUP_UNACCOUNTED					"Unaccounted textures"	// Textures that weren't assigned a texture group.
#define TEXTURE_GROUP_STATIC_INDEX_BUFFER			"Static Indices"
#define TEXTURE_GROUP_STATIC_VERTEX_BUFFER_DISP		"Displacement Verts"
#define TEXTURE_GROUP_STATIC_VERTEX_BUFFER_COLOR	"Lighting Verts"
#define TEXTURE_GROUP_STATIC_VERTEX_BUFFER_WORLD	"World Verts"
#define TEXTURE_GROUP_STATIC_VERTEX_BUFFER_MODELS	"Model Verts"
#define TEXTURE_GROUP_STATIC_VERTEX_BUFFER_OTHER	"Other Verts"
#define TEXTURE_GROUP_DYNAMIC_INDEX_BUFFER			"Dynamic Indices"
#define TEXTURE_GROUP_DYNAMIC_VERTEX_BUFFER			"Dynamic Verts"
#define TEXTURE_GROUP_DEPTH_BUFFER					"DepthBuffer"
#define TEXTURE_GROUP_VIEW_MODEL					"ViewModel"
#define TEXTURE_GROUP_PIXEL_SHADERS					"Pixel Shaders"
#define TEXTURE_GROUP_VERTEX_SHADERS				"Vertex Shaders"
#define TEXTURE_GROUP_RENDER_TARGET_SURFACE			"RenderTarget Surfaces"
#define TEXTURE_GROUP_MORPH_TARGETS					"Morph Targets"

#define	CONTENTS_EMPTY			0		// No contents

#define	CONTENTS_SOLID			0x1		// an eye is never valid in a solid
#define	CONTENTS_WINDOW			0x2		// translucent, but not watery (glass)
#define	CONTENTS_AUX			0x4
#define	CONTENTS_GRATE			0x8		// alpha-tested "grate" textures.  Bullets/sight pass through, but solids don't
#define	CONTENTS_SLIME			0x10
#define	CONTENTS_WATER			0x20
#define	CONTENTS_BLOCKLOS		0x40	// block AI line of sight
#define CONTENTS_OPAQUE			0x80	// things that cannot be seen through (may be non-solid though)
#define	LAST_VISIBLE_CONTENTS	0x80

#define ALL_VISIBLE_CONTENTS (LAST_VISIBLE_CONTENTS | (LAST_VISIBLE_CONTENTS-1))

#define CONTENTS_TESTFOGVOLUME	0x100
#define CONTENTS_UNUSED			0x200	

// unused 
// NOTE: If it's visible, grab from the top + update LAST_VISIBLE_CONTENTS
// if not visible, then grab from the bottom.
#define CONTENTS_UNUSED6		0x400

#define CONTENTS_TEAM1			0x800	// per team contents used to differentiate collisions 
#define CONTENTS_TEAM2			0x1000	// between players and objects on different teams

// ignore CONTENTS_OPAQUE on surfaces that have SURF_NODRAW
#define CONTENTS_IGNORE_NODRAW_OPAQUE	0x2000

// hits entities which are MOVETYPE_PUSH (doors, plats, etc.)
#define CONTENTS_MOVEABLE		0x4000

// remaining contents are non-visible, and don't eat brushes
#define	CONTENTS_AREAPORTAL		0x8000

#define	CONTENTS_PLAYERCLIP		0x10000
#define	CONTENTS_MONSTERCLIP	0x20000

// currents can be added to any other contents, and may be mixed
#define	CONTENTS_CURRENT_0		0x40000
#define	CONTENTS_CURRENT_90		0x80000
#define	CONTENTS_CURRENT_180	0x100000
#define	CONTENTS_CURRENT_270	0x200000
#define	CONTENTS_CURRENT_UP		0x400000
#define	CONTENTS_CURRENT_DOWN	0x800000

#define	CONTENTS_ORIGIN			0x1000000	// removed before bsping an entity

#define	CONTENTS_MONSTER		0x2000000	// should never be on a brush, only in game
#define	CONTENTS_DEBRIS			0x4000000
#define	CONTENTS_DETAIL			0x8000000	// brushes to be added after vis leafs
#define	CONTENTS_TRANSLUCENT	0x10000000	// auto set if any surface has trans
#define	CONTENTS_LADDER			0x20000000
#define CONTENTS_HITBOX			0x40000000	// use accurate hitboxes on trace


// NOTE: These are stored in a short in the engine now.  Don't use more than 16 bits
#define	SURF_LIGHT		0x0001		// value will hold the light strength
#define	SURF_SKY2D		0x0002		// don't draw, indicates we should skylight + draw 2d sky but not draw the 3D skybox
#define	SURF_SKY		0x0004		// don't draw, but add to skybox
#define	SURF_WARP		0x0008		// turbulent water warp
#define	SURF_TRANS		0x0010
#define SURF_NOPORTAL	0x0020	// the surface can not have a portal placed on it
#define	SURF_TRIGGER	0x0040	// FIXME: This is an xbox hack to work around elimination of trigger surfaces, which breaks occluders
#define	SURF_NODRAW		0x0080	// don't bother referencing the texture

#define	SURF_HINT		0x0100	// make a primary bsp splitter

#define	SURF_SKIP		0x0200	// completely ignore, allowing non-closed brushes
#define SURF_NOLIGHT	0x0400	// Don't calculate light
#define SURF_BUMPLIGHT	0x0800	// calculate three lightmaps for the surface for bumpmapping
#define SURF_NOSHADOWS	0x1000	// Don't receive shadows
#define SURF_NODECALS	0x2000	// Don't receive decals
#define SURF_NOCHOP		0x4000	// Don't subdivide patches on this surface 
#define SURF_HITBOX		0x8000	// surface is part of a hitbox

#define	MASK_ALL					(0xFFFFFFFF)
#define	MASK_SOLID					(CONTENTS_SOLID|CONTENTS_MOVEABLE|CONTENTS_WINDOW|CONTENTS_MONSTER|CONTENTS_GRATE)
#define	MASK_PLAYERSOLID			(CONTENTS_SOLID|CONTENTS_MOVEABLE|CONTENTS_PLAYERCLIP|CONTENTS_WINDOW|CONTENTS_MONSTER|CONTENTS_GRATE)
#define	MASK_NPCSOLID				(CONTENTS_SOLID|CONTENTS_MOVEABLE|CONTENTS_MONSTERCLIP|CONTENTS_WINDOW|CONTENTS_MONSTER|CONTENTS_GRATE)
#define	MASK_WATER					(CONTENTS_WATER|CONTENTS_MOVEABLE|CONTENTS_SLIME)
#define	MASK_OPAQUE					(CONTENTS_SOLID|CONTENTS_MOVEABLE|CONTENTS_OPAQUE)
#define MASK_OPAQUE_AND_NPCS		(MASK_OPAQUE|CONTENTS_MONSTER)
#define MASK_BLOCKLOS				(CONTENTS_SOLID|CONTENTS_MOVEABLE|CONTENTS_BLOCKLOS)
#define MASK_BLOCKLOS_AND_NPCS		(MASK_BLOCKLOS|CONTENTS_MONSTER)
#define	MASK_VISIBLE					(MASK_OPAQUE|CONTENTS_IGNORE_NODRAW_OPAQUE)
#define MASK_VISIBLE_AND_NPCS		(MASK_OPAQUE_AND_NPCS|CONTENTS_IGNORE_NODRAW_OPAQUE)
#define	MASK_SHOT					(CONTENTS_SOLID|CONTENTS_MOVEABLE|CONTENTS_MONSTER|CONTENTS_WINDOW|CONTENTS_DEBRIS|CONTENTS_HITBOX)
#define MASK_SHOT_HULL				(CONTENTS_SOLID|CONTENTS_MOVEABLE|CONTENTS_MONSTER|CONTENTS_WINDOW|CONTENTS_DEBRIS|CONTENTS_GRATE)
#define MASK_SHOT_PORTAL			(CONTENTS_SOLID|CONTENTS_MOVEABLE|CONTENTS_WINDOW|CONTENTS_MONSTER)
#define MASK_SOLID_BRUSHONLY		(CONTENTS_SOLID|CONTENTS_MOVEABLE|CONTENTS_WINDOW|CONTENTS_GRATE)
#define MASK_PLAYERSOLID_BRUSHONLY	(CONTENTS_SOLID|CONTENTS_MOVEABLE|CONTENTS_WINDOW|CONTENTS_PLAYERCLIP|CONTENTS_GRATE)
#define MASK_NPCSOLID_BRUSHONLY		(CONTENTS_SOLID|CONTENTS_MOVEABLE|CONTENTS_WINDOW|CONTENTS_MONSTERCLIP|CONTENTS_GRATE)
#define MASK_NPCWORLDSTATIC			(CONTENTS_SOLID|CONTENTS_WINDOW|CONTENTS_MONSTERCLIP|CONTENTS_GRATE)
#define MASK_SPLITAREAPORTAL		(CONTENTS_WATER|CONTENTS_SLIME)
#define MASK_CURRENT				(CONTENTS_CURRENT_0|CONTENTS_CURRENT_90|CONTENTS_CURRENT_180|CONTENTS_CURRENT_270|CONTENTS_CURRENT_UP|CONTENTS_CURRENT_DOWN)
#define	MASK_DEADSOLID				(CONTENTS_SOLID|CONTENTS_PLAYERCLIP|CONTENTS_WINDOW|CONTENTS_GRATE)

#define	FL_ONGROUND				(1<<0)	// At rest / on the ground
#define FL_DUCKING				(1<<1)	// Player flag -- Player is fully crouched
#define FL_ANIMDUCKING			(1<<2)	// Player flag -- Player is in the process of crouching or uncrouching but could be in transition
// examples:                                   Fully ducked:  FL_DUCKING &  FL_ANIMDUCKING
//           Previously fully ducked, unducking in progress:  FL_DUCKING & !FL_ANIMDUCKING
//                                           Fully unducked: !FL_DUCKING & !FL_ANIMDUCKING
//           Previously fully unducked, ducking in progress: !FL_DUCKING &  FL_ANIMDUCKING
#define	FL_WATERJUMP			(1<<3)	// player jumping out of water
#define FL_ONTRAIN				(1<<4) // Player is _controlling_ a train, so movement commands should be ignored on client during prediction.
#define FL_INRAIN				(1<<5)	// Indicates the entity is standing in rain
#define FL_FROZEN				(1<<6) // Player is frozen for 3rd person camera
#define FL_ATCONTROLS			(1<<7) // Player can't move, but keeps key inputs for controlling another entity
#define	FL_CLIENT				(1<<8)	// Is a player
#define FL_FAKECLIENT			(1<<9)	// Fake client, simulated server side; don't send network messages to them
// NON-PLAYER SPECIFIC (i.e., not used by GameMovement or the client .dll ) -- Can still be applied to players, though
#define	FL_INWATER				(1<<10)	// In water

// NOTE if you move things up, make sure to change this value
#define PLAYER_FLAG_BITS		11

#define	FL_FLY					(1<<11)	// Changes the SV_Movestep() behavior to not need to be on ground
#define	FL_SWIM					(1<<12)	// Changes the SV_Movestep() behavior to not need to be on ground (but stay in water)
#define	FL_CONVEYOR				(1<<13)
#define	FL_NPC					(1<<14)
#define	FL_GODMODE				(1<<15)
#define	FL_NOTARGET				(1<<16)
#define	FL_AIMTARGET			(1<<17)	// set if the crosshair needs to aim onto the entity
#define	FL_PARTIALGROUND		(1<<18)	// not all corners are valid
#define FL_STATICPROP			(1<<19)	// Eetsa static prop!		
#define FL_GRAPHED				(1<<20) // worldgraph has this ent listed as something that blocks a connection
#define FL_GRENADE				(1<<21)
#define FL_STEPMOVEMENT			(1<<22)	// Changes the SV_Movestep() behavior to not do any processing
#define FL_DONTTOUCH			(1<<23)	// Doesn't generate touch functions, generates Untouch() for anything it was touching when this flag was set
#define FL_BASEVELOCITY			(1<<24)	// Base velocity has been applied this frame (used to convert base velocity into momentum)
#define FL_WORLDBRUSH			(1<<25)	// Not moveable/removeable brush entity (really part of the world, but represented as an entity for transparency or something)
#define FL_OBJECT				(1<<26) // Terrible name. This is an object that NPCs should see. Missiles, for example.
#define FL_KILLME				(1<<27)	// This entity is marked for death -- will be freed by game DLL
#define FL_ONFIRE				(1<<28)	// You know...
#define FL_DISSOLVING			(1<<29) // We're dissolving!
#define FL_TRANSRAGDOLL			(1<<30) // In the process of turning into a client side ragdoll.
#define FL_UNBLOCKABLE_BY_PLAYER (1<<31) // pusher that can't be blocked by the player

enum PLAYER_ANIM
{
	PLAYER_IDLE,
	PLAYER_WALK,
	PLAYER_JUMP,
	PLAYER_SUPERJUMP,
	PLAYER_DIE,
	PLAYER_ATTACK1,
	PLAYER_IN_VEHICLE,
};

enum RenderGroup_Config_t
{
	RENDER_GROUP_CFG_NUM_OPAQUE_ENT_BUCKETS = 4,
};

enum OverrideType_t
{
	OVERRIDE_NORMAL = 0,
	OVERRIDE_BUILD_SHADOWS,
	OVERRIDE_DEPTH_WRITE,
	OVERRIDE_SSAO_DEPTH_WRITE,
};

enum RenderGroup_t
{
	RENDER_GROUP_OPAQUE_STATIC_HUGE = 0,
	RENDER_GROUP_OPAQUE_ENTITY_HUGE = 1,
	RENDER_GROUP_OPAQUE_STATIC = RENDER_GROUP_OPAQUE_STATIC_HUGE + (RENDER_GROUP_CFG_NUM_OPAQUE_ENT_BUCKETS - 1) * 2,
	RENDER_GROUP_OPAQUE_ENTITY,
	RENDER_GROUP_TRANSLUCENT_ENTITY,
	RENDER_GROUP_TWOPASS,
	RENDER_GROUP_VIEW_MODEL_OPAQUE,
	RENDER_GROUP_VIEW_MODEL_TRANSLUCENT,
	RENDER_GROUP_OPAQUE_BRUSH,
	RENDER_GROUP_OTHER,
	RENDER_GROUP_COUNT
};




// TrickWare exclusive enums ( not in game )

enum ETeam : int
{
	SPECTATOR = 1,
	US,
	WEHRMACHT
};

enum EClientClass : int // 16.11.2024
{
	CTeamplayRoundBasedRulesProxy = 0,
	CBaseAnimating = 1,
	CBaseAnimatingOverlay = 2,
	CBaseCombatCharacter = 3,
	CBaseCombatWeapon = 4,
	CBaseDoor = 5,
	CBaseEntity = 6,
	CBaseFlex = 7,
	CBaseGrenade = 8,
	CBaseParticleEntity = 9,
	CBasePlayer = 10,
	CBaseProjectile = 11,
	CBasePropDoor = 12,
	CBaseTempEntity = 13,
	CBaseViewModel = 14,
	CBeam = 15,
	CBoneFollower = 16,
	CBreakableProp = 17,
	CBreakableSurface = 18,
	CColorCorrection = 19,
	CColorCorrectionVolume = 20,
	CDODBaseBombWeapon = 21,
	CDODBaseGrenade = 22,
	CDODBaseRocket = 23,
	CDODBaseRocketWeapon = 24,
	CDODBipodWeapon = 25,
	CDODBombDispenserMapIcon = 26,
	CDODBombTarget = 27,
	CDODFireSelectWeapon = 28,
	CDODFullAutoPunchWeapon = 29,
	CDODFullAutoWeapon = 30,
	CDODGameRulesProxy = 31,
	CDODObjectiveResource = 32,
	CDODPlayer = 33,
	CDODPlayerResource = 34,
	CDODRagdoll = 35,
	CDODRifleGrenadeGER = 36,
	CDODRifleGrenadeUS = 37,
	CDODRoundTimer = 38,
	CDODSemiAutoWeapon = 39,
	CDODSmokeGrenade = 40,
	CDODSniperWeapon = 41,
	CDODTeam = 42,
	CDODTeam_Allies = 43,
	CDODTeam_Axis = 44,
	CDODViewModel = 45,
	CDynamicLight = 46,
	CDynamicProp = 47,
	CEmbers = 48,
	CEntityDissolve = 49,
	CEntityFlame = 50,
	CEntityParticleTrail = 51,
	CEnvDetailController = 52,
	CEnvParticleScript = 53,
	CEnvProjectedTexture = 54,
	CEnvQuadraticBeam = 55,
	CEnvScreenEffect = 56,
	CEnvScreenOverlay = 57,
	CEnvTonemapController = 58,
	CEnvWind = 59,
	CFireSmoke = 60,
	CFireTrail = 61,
	CFish = 62,
	CFogController = 63,
	CFunc_Dust = 64,
	CFunc_LOD = 65,
	CFuncAreaPortalWindow = 66,
	CFuncConveyor = 67,
	CFuncLadder = 68,
	CFuncNewTeamWall = 69,
	CFuncOccluder = 70,
	CFuncReflectiveGlass = 71,
	CFuncRotating = 72,
	CFuncSmokeVolume = 73,
	CFuncTrackTrain = 74,
	CGameRulesProxy = 75,
	CGrenadeTrail = 76,
	CHandleTest = 77,
	CInfoLadderDismount = 78,
	CInfoLightingRelative = 79,
	CInfoOverlayAccessor = 80,
	CLightGlow = 81,
	CMaterialModifyControl = 82,
	CParticleFire = 83,
	CParticlePerformanceMonitor = 84,
	CParticleSystem = 85,
	CPhysBox = 86,
	CPhysBoxMultiplayer = 87,
	CPhysicsProp = 88,
	CPhysicsPropMultiplayer = 89,
	CPhysMagnet = 90,
	CPlasma = 91,
	CPlayerResource = 92,
	CPointCamera = 93,
	CPointCommentaryNode = 94,
	CPoseController = 95,
	CPrecipitation = 96,
	CPropVehicleDriveable = 97,
	CRagdollManager = 98,
	CRagdollProp = 99,
	CRagdollPropAttached = 100,
	CRopeKeyframe = 101,
	CSceneEntity = 102,
	CShadowControl = 103,
	CSlideshowDisplay = 104,
	CSmokeStack = 105,
	CSpotlightEnd = 106,
	CSprite = 107,
	CSpriteOriented = 108,
	CSpriteTrail = 109,
	CSteamJet = 110,
	CSun = 111,
	CTeam = 112,
	CTEArmorRicochet = 113,
	CTEBaseBeam = 114,
	CTEBeamEntPoint = 115,
	CTEBeamEnts = 116,
	CTEBeamFollow = 117,
	CTEBeamLaser = 118,
	CTEBeamPoints = 119,
	CTEBeamRing = 120,
	CTEBeamRingPoint = 121,
	CTEBeamSpline = 122,
	CTEBloodSprite = 123,
	CTEBloodStream = 124,
	CTEBreakModel = 125,
	CTEBSPDecal = 126,
	CTEBubbles = 127,
	CTEBubbleTrail = 128,
	CTEClientProjectile = 129,
	CTEDecal = 130,
	CTEDODExplosion = 131,
	CTEDust = 132,
	CTEDynamicLight = 133,
	CTEEffectDispatch = 134,
	CTEEnergySplash = 135,
	CTEExplosion = 136,
	CTEFireBullets = 137,
	CTEFizz = 138,
	CTEFootprintDecal = 139,
	CTEGaussExplosion = 140,
	CTEGlowSprite = 141,
	CTEImpact = 142,
	CTEKillPlayerAttachments = 143,
	CTELargeFunnel = 144,
	CTEMetalSparks = 145,
	CTEMuzzleFlash = 146,
	CTEParticleSystem = 147,
	CTEPhysicsProp = 148,
	CTEPlayerAnimEvent = 149,
	CTEPlayerDecal = 150,
	CTEProjectedDecal = 151,
	CTEShatterSurface = 152,
	CTEShowLine = 153,
	CTesla = 154,
	CTESmoke = 155,
	CTESparks = 156,
	CTESprite = 157,
	CTESpriteSpray = 158,
	CTest_ProxyToggle_Networkable = 159,
	CTestTraceline = 160,
	CTEWorldDecal = 161,
	CVGuiScreen = 162,
	CVoteController = 163,
	CWaterBullet = 164,
	CWaterLODControl = 165,
	CWeapon30cal = 166,
	CWeaponAmerKnife = 167,
	CWeaponBAR = 168,
	CWeaponBaseRifleGrenade = 169,
	CWeaponBazooka = 170,
	CWeaponC96 = 171,
	CWeaponColt = 172,
	CWeaponDODBase = 173,
	CWeaponDODBaseGrenade = 174,
	CWeaponDODBaseGun = 175,
	CWeaponDODBaseMelee = 176,
	CWeaponExplodingHandGrenade = 177,
	CWeaponExplodingStickGrenade = 178,
	CWeaponGarand = 179,
	CWeaponHandGrenade = 180,
	CWeaponIFMBase = 181,
	CWeaponIFMBaseCamera = 182,
	CWeaponIFMSteadyCam = 183,
	CWeaponK98 = 184,
	CWeaponK98Scoped = 185,
	CWeaponM1Carbine = 186,
	CWeaponMG42 = 187,
	CWeaponMP40 = 188,
	CWeaponMP44 = 189,
	CWeaponP38 = 190,
	CWeaponPschreck = 191,
	CWeaponRifleGrenadeGER = 192,
	CWeaponRifleGrenadeGER_Live = 193,
	CWeaponRifleGrenadeUS = 194,
	CWeaponRifleGrenadeUS_Live = 195,
	CWeaponSmokeGrenadeGER = 196,
	CWeaponSmokeGrenadeUS = 197,
	CWeaponSpade = 198,
	CWeaponSpring = 199,
	CWeaponStickGrenade = 200,
	CWeaponThompson = 201,
	CWorld = 202,
	DustTrail = 203,
	MovieExplosion = 204,
	ParticleSmokeGrenade = 205,
	RocketTrail = 206,
	SmokeTrail = 207,
	SporeExplosion = 208,
	SporeTrail = 209,
};