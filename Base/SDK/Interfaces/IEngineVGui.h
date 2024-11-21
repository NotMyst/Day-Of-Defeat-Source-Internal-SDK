#pragma once

class _XSESSION_SEARCHRESULT;

enum PaintMode_t {
	PAINT_UIPANELS = (1 << 0),
	PAINT_INGAMEPANELS = (1 << 1),
};

class IEngineVGui
{
public:
	/*virtual ~IEngineVGui() = 0;
	virtual void* GetPanel(VGuiPanel_t) = 0;
	virtual void* IsGameUIVisible(void) = 0;
	virtual void* Init(void) = 0;
	virtual void* Connect(void) = 0;
	virtual void* Shutdown(void) = 0;
	virtual void* SetVGUIDirectories(void) = 0;
	virtual void* IsInitialized(void)const = 0;
	virtual void* GetGameUIFactory(void) = 0;
	virtual void* Key_Event(InputEvent_t const&) = 0;
	virtual void* BackwardCompatibility_Paint(void) = 0;
	virtual void* UpdateButtonState(InputEvent_t const&) = 0;
	virtual void* PostInit(void) = 0;
	virtual void* Paint(PaintMode_t) = 0;
	virtual void* ActivateGameUI(void) = 0;
	virtual void* HideGameUI(void) = 0;
	virtual void* ShowConsole(void) = 0;
	virtual void* HideConsole(void) = 0;
	virtual void* IsConsoleVisible(void) = 0;
	virtual void* ClearConsole(void) = 0;
	virtual void* HideDebugSystem(void) = 0;
	virtual void* OnLevelLoadingStarted(void) = 0;
	virtual void* OnLevelLoadingFinished(void) = 0;
	virtual void* NotifyOfServerConnect(char const*, int, int, int) = 0;
	virtual void* NotifyOfServerDisconnect(void) = 0;
	virtual void* EnabledProgressBarForNextLoad(void) = 0;
	virtual void* UpdateProgressBar(LevelLoadingProgress_e) = 0;
	virtual void* UpdateCustomProgressBar(float, wchar_t const*) = 0;
	virtual void* StartCustomProgress(void) = 0;
	virtual void* FinishCustomProgress(void) = 0;
	virtual void* ShowErrorMessage(void) = 0;
	virtual void* ShouldPause(void) = 0;
	virtual void* SetGameDLLPanelsVisible(bool) = 0;
	virtual void* ShowNewGameDialog(int) = 0;
	virtual void* Simulate(void) = 0;
	virtual void* SetNotAllowedToHideGameUI(bool) = 0;
	virtual void* SetNotAllowedToShowGameUI(bool) = 0;
	virtual void* SessionNotification(int, int) = 0;
	virtual void* SystemNotification(int) = 0;
	virtual void* ShowMessageDialog(unsigned int, vgui::Panel*) = 0;
	virtual void* UpdatePlayerInfo(unsigned long long, char const*, int, unsigned char, int, bool) = 0;
	virtual void* SessionSearchResult(int, void*, _XSESSION_SEARCHRESULT*, int) = 0;
	virtual void* OnCreditsFinished(void) = 0;
	virtual void* ValidateStorageDevice(int*) = 0;
	virtual void* ConfirmQuit(void) = 0;*/
};

inline IEngineVGui* gVGui = nullptr;