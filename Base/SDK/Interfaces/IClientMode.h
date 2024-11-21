#pragma once

namespace vgui
{
	class Panel;
}

class IClientMode
{
public:
	virtual ~IClientMode() = 0;
	virtual void* InitViewport(void) = 0;
	virtual void* Init(void) = 0;
	virtual void* VGui_Shutdown(void) = 0;
	virtual void* Shutdown(void) = 0;
	virtual void* Enable(void) = 0;
	virtual void* Disable(void) = 0;
	virtual void* Layout(void) = 0;
	virtual void* GetViewport(void) = 0;
	virtual void* GetViewportAnimationController(void) = 0;
	virtual void* ProcessInput(bool) = 0;
	virtual void* ShouldDrawDetailObjects(void) = 0;
	virtual void* ShouldDrawEntity(C_BaseEntity*) = 0;
	virtual void* ShouldDrawLocalPlayer(C_BasePlayer*) = 0;
	virtual void* ShouldDrawParticles(void) = 0;
	virtual void* ShouldDrawFog(void) = 0;
	virtual void OverrideView(CViewSetup* pSetup) = 0;
	virtual void* KeyInput(int, ButtonCode_t, char const*) = 0;
	virtual void* StartMessageMode(int) = 0;
	virtual void* GetMessagePanel(void) = 0;
	virtual void* OverrideMouseInput(float*, float*) = 0;
	virtual bool CreateMove(float flInputSampleTime, CUserCmd*) = 0;
	virtual void* LevelInit(char const*) = 0;
	virtual void* LevelShutdown(void) = 0;
	virtual void* ShouldDrawViewModel(void) = 0;
	virtual void* ShouldDrawCrosshair(void) = 0;
	virtual void* AdjustEngineViewport(int&, int&, int&, int&) = 0;
	virtual void* PreRender(CViewSetup*) = 0;
	virtual void* PostRender(void) = 0;
	virtual void* PostRenderVGui(void) = 0;
	virtual void* ActivateInGameVGuiContext(vgui::Panel*) = 0;
	virtual void* DeactivateInGameVGuiContext(void) = 0;
	virtual float GetViewModelFOV(void) = 0;
	virtual void* CanRecordDemo(char*, int)const = 0;
	virtual void* ComputeVguiResConditions(KeyValues*) = 0;
	virtual void* GetServerName(void) = 0;
	virtual void* SetServerName(wchar_t*) = 0;
	virtual void* GetMapName(void) = 0;
	virtual void* SetMapName(wchar_t*) = 0;
	virtual void* DoPostScreenSpaceEffects(CViewSetup const*) = 0;
	virtual void* DisplayReplayMessage(char const*, float, bool, char const*, bool) = 0;
	virtual void* Update(void) = 0;
	virtual void* ShouldBlackoutAroundHUD(void) = 0;
	virtual void* ShouldOverrideHeadtrackControl(void) = 0;
	virtual void* IsInfoPanelAllowed(void) = 0;
	virtual void* InfoPanelDisplayed(void) = 0;
	virtual void* IsHTMLInfoPanelAllowed(void) = 0;
	virtual void* ReloadScheme(bool) = 0;
	virtual void* HudElementKeyInput(int, ButtonCode_t, char const*) = 0;
	virtual void* FireGameEvent(IGameEvent*) = 0;
	virtual void* HandleSpectatorKeyInput(int, ButtonCode_t, char const*) = 0;
	virtual void* UpdateReplayMessages(void) = 0;

};

inline IClientMode* gClientMode = nullptr;