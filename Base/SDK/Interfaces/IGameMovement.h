#pragma once

typedef CBaseHandle EntityHandle_t;

class CMoveData
{
public:
	bool			m_bFirstRunOfFunctions : 1;
	bool			m_bGameCodeMovedPlayer : 1;

	EntityHandle_t	m_nPlayerHandle;	// edict index on server, client entity handle on client

	int				m_nImpulseCommand;	// Impulse command issued.
	QAngle			m_vecViewAngles;	// Command view angles (local space)
	QAngle			m_vecAbsViewAngles;	// Command view angles (world space)
	int				m_nButtons;			// Attack buttons.
	int				m_nOldButtons;		// From host_client->oldbuttons;
	float			m_flForwardMove;
	float			m_flOldForwardMove;
	float			m_flSideMove;
	float			m_flUpMove;

	float			m_flMaxSpeed;
	float			m_flClientMaxSpeed;

	// Variables from the player edict (sv_player) or entvars on the client.
	// These are copied in here before calling and copied out after calling.
	Vector			m_vecVelocity;		// edict::velocity		// Current movement direction.
	QAngle			m_vecAngles;		// edict::angles
	QAngle			m_vecOldAngles;

	// Output only
	float			m_outStepHeight;	// how much you climbed this move
	Vector			m_outWishVel;		// This is where you tried 
	Vector			m_outJumpVel;		// This is your jump velocity

	// Movement constraints	(radius 0 means no constraint)
	Vector			m_vecConstraintCenter;
	float			m_flConstraintRadius;
	float			m_flConstraintWidth;
	float			m_flConstraintSpeedFactor;

private:
	Vector			m_vecAbsOrigin;		// edict::origin
};

class IGameMovement
{
public:
	typedef enum
	{
		GROUND = 0,
		STUCK,
		LADDER
	} IntervalType_t;

	virtual ~IGameMovement() = 0;

	virtual void ProcessMovement(C_BasePlayer*, CMoveData*) = 0;
	virtual void* StartTrackPredictionErrors(C_BasePlayer*) = 0;
	virtual void* FinishTrackPredictionErrors(C_BasePlayer*) = 0;
	virtual void* DiffPrint(char const*, ...) = 0;
	virtual void* GetPlayerMins(bool)const = 0;
	virtual void* GetPlayerMaxs(bool)const = 0;
	virtual void* GetPlayerViewOffset(bool)const = 0;
	virtual void* TracePlayerBBox(Vector const&, Vector const&, unsigned int, int, CGameTrace&) = 0;
	virtual void* TryTouchGround(Vector const&, Vector const&, Vector const&, Vector const&, unsigned int, int, CGameTrace&) = 0;
	virtual void* PlayerSolidMask(bool) = 0;
	virtual void* PlayerMove(void) = 0;
	virtual void* CalcRoll(QAngle const&, Vector const&, float, float) = 0;
	virtual void* DecayPunchAngle(void) = 0;
	virtual void* CheckWaterJump(void) = 0;
	virtual void* WaterMove(void) = 0;
	virtual void* AirAccelerate(Vector&, float, float) = 0;
	virtual void* AirMove(void) = 0;
	virtual void* GetAirSpeedCap(void) = 0;
	virtual void* CanAccelerate(void) = 0;
	virtual void* Accelerate(Vector&, float, float) = 0;
	virtual void* WalkMove(void) = 0;
	virtual void* FullWalkMove(void) = 0;
	virtual void* OnJump(float) = 0;
	virtual void* OnLand(float) = 0;
	virtual void* OnTryPlayerMoveCollision(CGameTrace&) = 0;
	virtual void* GetPlayerMins(void)const = 0;
	virtual void* GetPlayerMaxs(void)const = 0;
	virtual void* GetCheckInterval(IntervalType_t) = 0;
	virtual void* CheckJumpButton(void) = 0;
	virtual void* FullTossMove(void) = 0;
	virtual void* FullLadderMove(void) = 0;
	virtual void* TryPlayerMove(Vector*, CGameTrace*) = 0;
	virtual void* LadderMove(void) = 0;
	virtual void* OnLadder(CGameTrace&) = 0;
	virtual void* LadderDistance(void)const = 0;
	virtual void* LadderMask(void)const = 0;
	virtual void* ClimbSpeed(void)const = 0;
	virtual void* LadderLateralMultiplier(void)const = 0;
	virtual void* CheckStuck(void) = 0;
	virtual void* CheckWater(void) = 0;
	virtual void* CategorizePosition(void) = 0;
	virtual void* CheckParameters(void) = 0;
	virtual void* ReduceTimers(void) = 0;
	virtual void* CheckFalling(void) = 0;
	virtual void* PlayerRoughLandingEffects(float) = 0;
	virtual void* Duck(void) = 0;
	virtual void* HandleDuckingSpeedCrop(void) = 0;
	virtual void* FinishUnDuck(void) = 0;
	virtual void* FinishDuck(void) = 0;
	virtual void* CanUnduck(void) = 0;
	virtual void* TestPlayerPosition(Vector const&, int, CGameTrace&) = 0;
	virtual void* SetGroundEntity(CGameTrace*) = 0;
	virtual void* StepMove(Vector&, CGameTrace&) = 0;
	virtual void* GameHasLadders(void)const = 0;
};

inline IGameMovement* gMovement = nullptr;