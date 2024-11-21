#pragma once

class CMoveData;
class IMoveHelper;

class IPrediction
{
public:
	virtual ~IPrediction() = 0;
	virtual void* Init(void) = 0;
	virtual void* Shutdown(void) = 0;
	virtual void* Update(int, bool, int, int) = 0;
	virtual void* PreEntityPacketReceived(int, int) = 0;
	virtual void* PostEntityPacketReceived(void) = 0;
	virtual void* PostNetworkDataReceived(int) = 0;
	virtual void* OnReceivedUncompressedPacket(void) = 0;
	virtual void* GetViewOrigin(Vector&) = 0;
	virtual void* SetViewOrigin(Vector&) = 0;
	virtual void* GetViewAngles(QAngle&) = 0;
	virtual void* SetViewAngles(QAngle&) = 0;
	virtual void* GetLocalViewAngles(QAngle&) = 0;
	virtual void* SetLocalViewAngles(QAngle&) = 0;
	virtual void* InPrediction(void)const = 0;
	virtual void* IsFirstTimePredicted(void)const = 0;
	virtual void* GetIncomingPacketNumber(void)const = 0;
	virtual void RunCommand(C_BasePlayer*, CUserCmd*, IMoveHelper*) = 0;
	virtual void* SetupMove(C_BasePlayer*, CUserCmd*, IMoveHelper*, CMoveData*) = 0;
	virtual void* FinishMove(C_BasePlayer*, CUserCmd*, CMoveData*) = 0;
	virtual void* SetIdealPitch(C_BasePlayer*, Vector const&, QAngle const&, Vector const&) = 0;
	virtual void* _Update(bool, bool, int, int) = 0;
};

inline IPrediction* gPrediction = nullptr;