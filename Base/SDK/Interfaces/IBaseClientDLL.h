#pragma once

class CGlobalVarsBase;
class CEngineSprite;
class CSaveRestoreData;
class IFileList;
class IClientUnknown;
class IConVar;
class CViewSetup;
struct ScreenFade_t;
struct vrect_t;
struct datamap_t;
struct typedescription_t;
struct StartSoundParams_t;
struct bf_read;
struct bf_write;
struct Vector;
typedef Vector QAngle;
enum ButtonCode_t;

enum ClientFrameStage_t
{
	FRAME_UNDEFINED = -1,
	FRAME_START,
	FRAME_NET_UPDATE_START,
	FRAME_NET_UPDATE_POSTDATAUPDATE_START,
	FRAME_NET_UPDATE_POSTDATAUPDATE_END,
	FRAME_NET_UPDATE_END,
	FRAME_RENDER_START,
	FRAME_RENDER_END
};

class IBaseClientDLL
{
public:
	virtual void* Init(void* (*)(char const*, int*), void* (*)(char const*, int*), CGlobalVarsBase*) = 0;
	virtual void* PostInit(void) = 0;
	virtual void* Shutdown(void) = 0;
	virtual void* ReplayInit(void* (*)(char const*, int*)) = 0;
	virtual void* ReplayPostInit(void) = 0;
	virtual void* LevelInitPreEntity(char const*) = 0;
	virtual void* LevelInitPostEntity(void) = 0;
	virtual void* LevelShutdown(void) = 0;
	virtual ClientClass* GetAllClasses(void) = 0;
	virtual void* HudVidInit(void) = 0;
	virtual void* HudProcessInput(bool) = 0;
	virtual void* HudUpdate(bool) = 0;
	virtual void* HudReset(void) = 0;
	virtual void* HudText(char const*) = 0;
	virtual void* IN_ActivateMouse(void) = 0;
	virtual void* IN_DeactivateMouse(void) = 0;
	virtual void* IN_Accumulate(void) = 0;
	virtual void* IN_ClearStates(void) = 0;
	virtual void* IN_IsKeyDown(char const*, bool&) = 0;
	virtual void* IN_OnMouseWheeled(int) = 0;
	virtual void* IN_KeyEvent(int, ButtonCode_t, char const*) = 0;
	virtual void* CreateMove(int, float, bool) = 0;
	virtual void* ExtraMouseSample(float, bool) = 0;
	virtual void* WriteUsercmdDeltaToBuffer(bf_write*, int, int, bool) = 0;
	virtual void* EncodeUserCmdToBuffer(bf_write&, int) = 0;
	virtual void* DecodeUserCmdFromBuffer(bf_read&, int) = 0;
	virtual void* View_Render(vrect_t*) = 0;
	virtual void* RenderView(CViewSetup const&, int, int) = 0;
	virtual void* View_Fade(ScreenFade_t*) = 0;
	virtual void* SetCrosshairAngle(QAngle const&) = 0;
	virtual void* InitSprite(CEngineSprite*, char const*) = 0;
	virtual void* ShutdownSprite(CEngineSprite*) = 0;
	virtual void* GetSpriteSize(void)const = 0;
	virtual void* VoiceStatus(int, int) = 0;
	virtual void* InstallStringTableCallback(char const*) = 0;
	virtual void FrameStageNotify(ClientFrameStage_t) = 0;
	virtual void* DispatchUserMessage(int, bf_read&) = 0;
	virtual void* SaveInit(int) = 0;
	virtual void* SaveWriteFields(CSaveRestoreData*, char const*, void*, datamap_t*, typedescription_t*, int) = 0;
	virtual void* SaveReadFields(CSaveRestoreData*, char const*, void*, datamap_t*, typedescription_t*, int) = 0;
	virtual void* PreSave(CSaveRestoreData*) = 0;
	virtual void* Save(CSaveRestoreData*) = 0;
	virtual void* WriteSaveHeaders(CSaveRestoreData*) = 0;
	virtual void* ReadRestoreHeaders(CSaveRestoreData*) = 0;
	virtual void* Restore(CSaveRestoreData*, bool) = 0;
	virtual void* DispatchOnRestore(void) = 0;
	virtual void* GetStandardRecvProxies(void) = 0;
	virtual void* WriteSaveGameScreenshot(char const*) = 0;
	virtual void* EmitSentenceCloseCaption(char const*) = 0;
	virtual void* EmitCloseCaption(char const*, float) = 0;
	virtual void* CanRecordDemo(char*, int)const = 0;
	virtual void* OnDemoRecordStart(char const*) = 0;
	virtual void* OnDemoRecordStop(void) = 0;
	virtual void* OnDemoPlaybackStart(char const*) = 0;
	virtual void* OnDemoPlaybackStop(void) = 0;
	virtual void* ShouldDrawDropdownConsole(void) = 0;
	virtual void* GetScreenWidth(void) = 0;
	virtual void* GetScreenHeight(void) = 0;
	virtual void* WriteSaveGameScreenshotOfSize(char const*, int, int, bool, bool) = 0;
	virtual void* GetPlayerView(CViewSetup&) = 0;
	virtual void* SetupGameProperties(void*, void*) = 0;
	virtual void* GetPresenceID(char const*) = 0;
	virtual void* GetPropertyIdString(unsigned int) = 0;
	virtual void* GetPropertyDisplayString(unsigned int, unsigned int, char*, int) = 0;
	virtual void* InvalidateMdlCache(void) = 0;
	virtual void* IN_SetSampleTime(float) = 0;
	virtual void* ReloadFilesInList(IFileList*) = 0;
	virtual void* StartStatsReporting(void*, bool) = 0;
	virtual void* HandleUiToggle(void) = 0;
	virtual void* ShouldAllowConsole(void) = 0;
	virtual void* GetRenamedRecvTableInfos(void) = 0;
	virtual void* GetClientUIMouthInfo(void) = 0;
	virtual void* FileReceived(char const*, unsigned int) = 0;
	virtual void* TranslateEffectForVisionFilter(char const*, char const*) = 0;
	virtual void* ClientAdjustStartSoundParams(StartSoundParams_t&) = 0;
	virtual void* DisconnectAttempt(void) = 0;
	virtual void* IsConnectedUserInfoChangeAllowed(IConVar*) = 0;
};

inline IBaseClientDLL* gClient = nullptr;