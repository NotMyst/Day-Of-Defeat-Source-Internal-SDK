#pragma once

#ifdef CreateFont
#undef CreateFont
#endif

#ifdef PlaySound
#undef PlaySound
#endif

struct InputEvent_t
{
	int m_nType;				// Type of the event (see InputEventType_t)
	int m_nTick;				// Tick on which the event occurred
	int m_nData;				// Generic 32-bit data, what it contains depends on the event
	int m_nData2;				// Generic 32-bit data, what it contains depends on the event
	int m_nData3;				// Generic 32-bit data, what it contains depends on the event
};

typedef unsigned int VPANEL;

typedef unsigned long HCursor;
typedef unsigned long HTexture;
typedef unsigned long HFont;

struct Vertex_t;

enum FontDrawType_t
{
	// Use the "additive" value from the scheme file
	FONT_DRAW_DEFAULT = 0,

	// Overrides
	FONT_DRAW_NONADDITIVE,
	FONT_DRAW_ADDITIVE,

	FONT_DRAW_TYPE_COUNT = 2,
};

namespace vgui
{
	struct CharRenderInfo
	{
		// Text pos
		int				x, y;
		// Top left and bottom right
		// This is now a pointer to an array maintained by the surface, to avoid copying the data on the 360
		Vertex_t* verts;
		int				textureId;
		int				abcA;
		int				abcB;
		int				abcC;
		int				fontTall;
		HFont			currentFont;
		// In:
		FontDrawType_t	drawType;
		wchar_t			ch;

		// Out
		bool			valid;
		// In/Out (true by default)
		bool			shouldclip;
	};

	struct IntRect
	{
		int x0;
		int y0;
		int x1;
		int y1;
	};

	enum FontDrawType_t
	{
		// Use the "additive" value from the scheme file
		FONT_DRAW_DEFAULT = 0,

		// Overrides
		FONT_DRAW_NONADDITIVE,
		FONT_DRAW_ADDITIVE,

		FONT_DRAW_TYPE_COUNT = 2,
	};

	struct Vertex_t
	{
		Vertex_t() {}
		Vertex_t(const Vector2D& pos, const Vector2D& coord = Vector2D(0, 0))
		{
			m_Position = pos;
			m_TexCoord = coord;
		}
		void Init(const Vector2D& pos, const Vector2D& coord = Vector2D(0, 0))
		{
			m_Position = pos;
			m_TexCoord = coord;
		}

		Vector2D	m_Position;
		Vector2D	m_TexCoord;
	};

	// handle to an internal vgui panel
	// this is the only handle to a panel that is valid across dll boundaries
	typedef unsigned int VPANEL;

	// handles to vgui objects
	// NULL values signify an invalid value
	typedef unsigned long HScheme;
	// Both -1 and 0 are used for invalid textures. Be careful.
	typedef unsigned long HTexture;
	typedef unsigned long HCursor;
	typedef unsigned long HPanel;
	const HPanel INVALID_PANEL = 0xffffffff;
	typedef unsigned long HFont;
	const HFont INVALID_FONT = 0; // the value of an invalid font handle

	class IHTML;
	class IHTMLEvents;

	class ISurface
	{
	public:
		enum SurfaceFeature_e
		{
			ANTIALIASED_FONTS = 1,
			DROPSHADOW_FONTS = 2,
			ESCAPE_KEY = 3,
			OPENING_NEW_HTML_WINDOWS = 4,
			FRAME_MINIMIZE_MAXIMIZE = 5,
			OUTLINE_FONTS = 6,
			DIRECT_HWND_RENDER = 7,
		};

		enum EFontFlags
		{
			FONTFLAG_NONE,
			FONTFLAG_ITALIC = 0x001,
			FONTFLAG_UNDERLINE = 0x002,
			FONTFLAG_STRIKEOUT = 0x004,
			FONTFLAG_SYMBOL = 0x008,
			FONTFLAG_ANTIALIAS = 0x010,
			FONTFLAG_GAUSSIANBLUR = 0x020,
			FONTFLAG_ROTARY = 0x040,
			FONTFLAG_DROPSHADOW = 0x080,
			FONTFLAG_ADDITIVE = 0x100,
			FONTFLAG_OUTLINE = 0x200,
			FONTFLAG_CUSTOM = 0x400,		// custom generated font - never fall back to asian compatibility mode
			FONTFLAG_BITMAP = 0x800,		// compiled bitmap font - no fallbacks
		};
	};
}

class IMatSystemSurface
{
public:
	virtual void* Connect(void* (*)(char const*, int*)) = 0;
	virtual void* Disconnect(void) = 0;
	virtual void* QueryInterface(char const*) = 0;
	virtual void* Init(void) = 0;
	virtual void* Shutdown(void) = 0;
	virtual void* RunFrame(void) = 0;
	virtual void* GetEmbeddedPanel(void) = 0;
	virtual void* SetEmbeddedPanel(unsigned int) = 0;
	virtual void* PushMakeCurrent(unsigned int, bool) = 0;
	virtual void* PopMakeCurrent(unsigned int) = 0;
	virtual void* DrawSetColor(int, int, int, int) = 0;
	virtual void* DrawSetColor(Color) = 0;
	virtual void* DrawFilledRect(int, int, int, int) = 0;
	virtual void* DrawFilledRectArray(vgui::IntRect*, int) = 0;
	virtual void* DrawOutlinedRect(int, int, int, int) = 0;
	virtual void* DrawLine(int, int, int, int) = 0;
	virtual void* DrawPolyLine(int*, int*, int) = 0;
	virtual void* DrawSetTextFont(unsigned long) = 0;
	virtual void* DrawSetTextColor(int, int, int, int) = 0;
	virtual void* DrawSetTextColor(Color) = 0;
	virtual void* DrawSetTextPos(int, int) = 0;
	virtual void* DrawGetTextPos(int&, int&) = 0;
	virtual void* DrawPrintText(wchar_t const*, int, vgui::FontDrawType_t) = 0;
	virtual void* DrawUnicodeChar(wchar_t, vgui::FontDrawType_t) = 0;
	virtual void* DrawFlushText(void) = 0;
	virtual void* CreateHTMLWindow(vgui::IHTMLEvents*, unsigned int) = 0;
	virtual void* PaintHTMLWindow(vgui::IHTML*) = 0;
	virtual void* DeleteHTMLWindow(vgui::IHTML*) = 0;
	virtual void* DrawGetTextureId(char const*) = 0;
	virtual void* DrawGetTextureFile(int, char*, int) = 0;
	virtual void* DrawSetTextureFile(int, char const*, int, bool) = 0;
	virtual void* DrawSetTextureRGBA(int, unsigned char const*, int, int, int, bool) = 0;
	virtual void* DrawSetTexture(int) = 0;
	virtual void* DrawGetTextureSize(int, int&, int&) = 0;
	virtual void* DrawTexturedRect(int, int, int, int) = 0;
	virtual void* IsTextureIDValid(int) = 0;
	virtual void* DeleteTextureByID(int) = 0;
	virtual void* CreateNewTextureID(bool) = 0;
	virtual void* GetScreenSize(int&, int&) = 0;
	virtual void* SetAsTopMost(unsigned int, bool) = 0;
	virtual void* BringToFront(unsigned int) = 0;
	virtual void* SetForegroundWindow(unsigned int) = 0;
	virtual void* SetPanelVisible(unsigned int, bool) = 0;
	virtual void* SetMinimized(unsigned int, bool) = 0;
	virtual void* IsMinimized(unsigned int) = 0;
	virtual void* FlashWindow(unsigned int, bool) = 0;
	virtual void* SetTitle(unsigned int, wchar_t const*) = 0;
	virtual void* SetAsToolBar(unsigned int, bool) = 0;
	virtual void* CreatePopup(unsigned int, bool, bool, bool, bool, bool) = 0;
	virtual void* SwapBuffers(unsigned int) = 0;
	virtual void* Invalidate(unsigned int) = 0;
	virtual void* SetCursor(unsigned long) = 0;
	virtual void* SetCursorAlwaysVisible(bool) = 0;
	virtual void* IsCursorVisible(void) = 0;
	virtual void* ApplyChanges(void) = 0;
	virtual void* IsWithin(int, int) = 0;
	virtual void* HasFocus(void) = 0;
	virtual void* SupportsFeature(vgui::ISurface::SurfaceFeature_e) = 0;
	virtual void* RestrictPaintToSinglePanel(unsigned int) = 0;
	virtual void* SetModalPanel(unsigned int) = 0;
	virtual void* GetModalPanel(void) = 0;
	virtual void* UnlockCursor(void) = 0;
	virtual void* LockCursor(void) = 0;
	virtual void* SetTranslateExtendedKeys(bool) = 0;
	virtual void* GetTopmostPopup(void) = 0;
	virtual void* SetTopLevelFocus(unsigned int) = 0;
	virtual void* CreateFont(void) = 0;
	virtual void* SetFontGlyphSet(unsigned long, char const*, int, int, int, int, int, int, int) = 0;
	virtual void* AddCustomFontFile(char const*, char const*) = 0;
	virtual void* GetFontTall(unsigned long) = 0;
	virtual void* GetFontTallRequested(unsigned long) = 0;
	virtual void* GetFontAscent(unsigned long, wchar_t) = 0;
	virtual void* IsFontAdditive(unsigned long) = 0;
	virtual void* GetCharABCwide(unsigned long, int, int&, int&, int&) = 0;
	virtual void* GetCharacterWidth(unsigned long, int) = 0;
	virtual void* GetTextSize(unsigned long, wchar_t const*, int&, int&) = 0;
	virtual void* GetNotifyPanel(void) = 0;
	virtual void* SetNotifyIcon(unsigned int, unsigned long, unsigned int, char const*) = 0;
	virtual void* PlaySound(char const*) = 0;
	virtual void* GetPopupCount(void) = 0;
	virtual void* GetPopup(int) = 0;
	virtual void* ShouldPaintChildPanel(unsigned int) = 0;
	virtual void* RecreateContext(unsigned int) = 0;
	virtual void* AddPanel(unsigned int) = 0;
	virtual void* ReleasePanel(unsigned int) = 0;
	virtual void* MovePopupToFront(unsigned int) = 0;
	virtual void* MovePopupToBack(unsigned int) = 0;
	virtual void* SolveTraverse(unsigned int, bool) = 0;
	virtual void PaintTraverse(VPANEL panel) = 0;
	virtual void* EnableMouseCapture(unsigned int, bool) = 0;
	virtual void* GetWorkspaceBounds(int&, int&, int&, int&) = 0;
	virtual void* GetAbsoluteWindowBounds(int&, int&, int&, int&) = 0;
	virtual void* GetProportionalBase(int&, int&) = 0;
	virtual void* CalculateMouseVisible(void) = 0;
	virtual void* NeedKBInput(void) = 0;
	virtual void* HasCursorPosFunctions(void) = 0;
	virtual void* SurfaceGetCursorPos(int&, int&) = 0;
	virtual void* SurfaceSetCursorPos(int, int) = 0;
	virtual void* DrawTexturedLine(vgui::Vertex_t const&, vgui::Vertex_t const&) = 0;
	virtual void* DrawOutlinedCircle(int, int, int, int) = 0;
	virtual void* DrawTexturedPolyLine(vgui::Vertex_t const*, int) = 0;
	virtual void* DrawTexturedSubRect(int, int, int, int, float, float, float, float) = 0;
	virtual void* DrawTexturedPolygon(int, vgui::Vertex_t*, bool) = 0;
	virtual void* GetTitle(unsigned int) = 0;
	virtual bool IsCursorLocked(void)const = 0;
	virtual void* SetWorkspaceInsets(int, int, int, int) = 0;
	virtual void* DrawGetUnicodeCharRenderInfo(wchar_t, vgui::CharRenderInfo&) = 0;
	virtual void* DrawRenderCharFromInfo(vgui::CharRenderInfo const&) = 0;
	virtual void* DrawSetAlphaMultiplier(float) = 0;
	virtual void* DrawGetAlphaMultiplier(void) = 0;
	virtual void* SetAllowHTMLJavaScript(bool) = 0;
	virtual void* OnScreenSizeChanged(int, int) = 0;
	virtual void* CreateCursorFromFile(char const*, char const*) = 0;
	virtual void* DrawGetTextureMatInfoFactory(int) = 0;
	virtual void* PaintTraverseEx(unsigned int, bool) = 0;
	virtual void* GetZPos(void)const = 0;
	virtual void* SetPanelForInput(unsigned int) = 0;
	virtual void* DrawFilledRectFastFade(int, int, int, int, int, int, unsigned int, unsigned int, bool) = 0;
	virtual void* DrawFilledRectFade(int, int, int, int, unsigned int, unsigned int, bool) = 0;
	virtual void* DrawSetTextureRGBAEx(int, unsigned char const*, int, int, ImageFormat) = 0;
	virtual void* DrawSetTextScale(float, float) = 0;
	virtual void* SetBitmapFontGlyphSet(unsigned long, char const*, float, float, int) = 0;
	virtual void* AddBitmapFontFile(char const*) = 0;
	virtual void* SetBitmapFontName(char const*, char const*) = 0;
	virtual void* GetBitmapFontName(char const*) = 0;
	virtual void* ClearTemporaryFontCache(void) = 0;
	virtual void* GetIconImageForFullPath(char const*) = 0;
	virtual void* DrawUnicodeString(wchar_t const*, vgui::FontDrawType_t) = 0;
	virtual void* PrecacheFontCharacters(unsigned long, wchar_t const*) = 0;
	virtual void* GetResolutionKey(void)const = 0;
	virtual void* GetFontName(unsigned long) = 0;
	virtual void* GetFontFamilyName(unsigned long) = 0;
	virtual void* GetKernedCharWidth(unsigned long, wchar_t, wchar_t, wchar_t, float&, float&) = 0;
	virtual void* ForceScreenSizeOverride(bool, int, int) = 0;
	virtual void* ForceScreenPosOffset(bool, int, int) = 0;
	virtual void* OffsetAbsPos(int&, int&) = 0;
	virtual void* ResetFontCaches(void) = 0;
	virtual void* GetTextureNumFrames(int) = 0;
	virtual void* DrawSetTextureFrame(int, int, unsigned int*) = 0;
	virtual void* IsScreenSizeOverrideActive(void) = 0;
	virtual void* IsScreenPosOverrideActive(void) = 0;
	virtual void* DestroyTextureID(int) = 0;
	virtual void* DrawUpdateRegionTextureRGBA(int, int, int, unsigned char const*, int, int, ImageFormat) = 0;
	virtual void* BHTMLWindowNeedsPaint(vgui::IHTML*) = 0;
	virtual void* GetWebkitHTMLUserAgentString(void) = 0;
	virtual void* Deprecated_AccessChromeHTMLController(void) = 0;
	virtual void* SetFullscreenViewport(int, int, int, int) = 0;
	virtual void* GetFullscreenViewport(int&, int&, int&, int&) = 0;
	virtual void* PushFullscreenViewport(void) = 0;
	virtual void* PopFullscreenViewport(void) = 0;
	virtual void* SetSoftwareCursor(bool) = 0;
	virtual void* PaintSoftwareCursor(void) = 0;
	virtual void* AttachToWindow(void*, bool) = 0;
	virtual void* EnableWindowsMessages(bool) = 0;
	virtual void* Begin3DPaint(int, int, int, int, bool) = 0;
	virtual void* End3DPaint(void) = 0;
	virtual void* DisableClipping(bool) = 0;
	virtual void* GetClippingRect(int&, int&, int&, int&, bool&) = 0;
	virtual void* SetClippingRect(int, int, int, int) = 0;
	virtual void* SetMouseCallbacks(void (*)(int&, int&), void (*)(int, int)) = 0;
	virtual void* InstallPlaySoundFunc(void (*)(char const*)) = 0;
	virtual void* DrawColoredCircle(int, int, float, int, int, int, int) = 0;
	virtual void* DrawColoredText(unsigned long, int, int, int, int, int, int, char const*, ...) = 0;
	virtual void* DrawColoredTextRect(unsigned long, int, int, int, int, int, int, int, int, char const*, ...) = 0;
	virtual void* DrawTextHeight(unsigned long, int, int&, char const*, ...) = 0;
	virtual void* DrawTextLen(unsigned long, char const*, ...) = 0;
	virtual void* DrawPanelIn3DSpace(unsigned int, VMatrix const&, int, int, float, float) = 0;
	virtual void* DrawSetTextureMaterial(int, IMaterial*) = 0;
	virtual void* HandleInputEvent(InputEvent_t const&) = 0;
	virtual void* Set3DPaintTempRenderTarget(char const*) = 0;
	virtual void* Reset3DPaintTempRenderTarget(void) = 0;
	virtual void* DrawGetTextureMaterial(int) = 0;
	virtual void* GetFullscreenViewportAndRenderTarget(int&, int&, int&, int&, ITexture**) = 0;
	virtual void* SetFullscreenViewportAndRenderTarget(int, int, int, int, ITexture*) = 0;
	virtual void* DrawGetTextureId(ITexture*) = 0;
	virtual void* BeginSkinCompositionPainting(void) = 0;
	virtual void* EndSkinCompositionPainting(void) = 0;
};

inline IMatSystemSurface* gMatSystemSurface = nullptr;