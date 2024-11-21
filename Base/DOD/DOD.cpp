#include "DOD.h"

#include <TlHelp32.h>

void DOD::CDODS::Init()
{
	gEntityList = GetInterface<IClientEntityList*>(G::Client, "VClientEntityList003");
	gEngineClient = GetInterface<IVEngineClient*>(G::Engine, "VEngineClient014");
	gClient = GetInterface<IBaseClientDLL*>(G::Client, "VClient017");
	gModelRender = GetInterface<IVModelRender*>(G::Engine, "VEngineModel016");
	gStudioRender = GetInterface<IStudioRender*>(G::StudioRender, "VStudioRender025");
	gRenderView = GetInterface<IVRenderView*>(G::Engine, "VEngineRenderView014");
	gMaterialSystem = GetInterface<IMaterialSystem*>(G::MaterialSystem, "VMaterialSystem080");
	gPlayerInfoMgr = GetInterface<IPlayerInfoManager*>(G::Server, "PlayerInfoManager002");
	gPrediction = GetInterface<IPrediction*>(G::Client, "VClientPrediction001");
	gMovement = GetInterface<IGameMovement*>(G::Client, "GameMovement001");
	gTrace = GetInterface<IEngineTrace*>(G::Engine, "EngineTraceClient003");
	gDebugOverlay = GetInterface<IVDebugOverlay*>(G::Engine, "VDebugOverlay003");
	gMatSystemSurface = GetInterface<IMatSystemSurface*>(G::Vgui, "VGUI_Surface030");
	gPanel = GetInterface<IPanel*>(G::Vgui, "VGUI_Panel009");

	gClientMode = **reinterpret_cast<IClientMode***>(((*reinterpret_cast<DWORD**>(gClient))[10] + 0x5));
	gRandomStream = **reinterpret_cast<IUniformRandomStream***>(G::Vstdlib.GetExport("RandomSeed") + 0x5);
	
	if (gPlayerInfoMgr)
		GlobalVars = gPlayerInfoMgr->GetGlobalVars();

	GameRules = **reinterpret_cast<C_DODGameRules***>(Pattern::Find(G::Client, "8B 0D ? ? ? ? FF 77 ? FF 75") + 0x2);

	if(gEngineClient->IsInGame())
		G::Player = gEntityList->GetClientEntity(gEngineClient->GetLocalPlayer())->Cast<C_DODPlayer*>();
}

void DOD::CUtil::FixMovement(CUserCmd* cmd, CUserCmd oCmd)
{
	float yawRad = DEG2RADF(fmodf(cmd->viewangles.y - oCmd.viewangles.y, 360.f));

	float forwardX = cos(yawRad);
	float forwardY = sin(yawRad);

	float rightX = -sin(yawRad);
	float rightY = cos(yawRad);
	cmd->forwardmove = oCmd.forwardmove * forwardX + oCmd.sidemove * rightX;
	cmd->sidemove = oCmd.forwardmove * forwardY + oCmd.sidemove * rightY;
}