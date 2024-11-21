#pragma once

class KeyValues;

namespace vgui
{
	class IClientPanel;
	class SurfacePlat;
}

#ifdef GetClassName
#undef GetClassName
#endif

#ifdef SendMessage
#undef SendMessage
#endif

class IPanel
{
public:
	virtual ~IPanel() = 0;
	virtual void* Init(unsigned int, vgui::IClientPanel*) = 0;
	virtual void* SetPos(unsigned int, int, int) = 0;
	virtual void* GetPos(unsigned int, int&, int&) = 0;
	virtual void* SetSize(unsigned int, int, int) = 0;
	virtual void* GetSize(unsigned int, int&, int&) = 0;
	virtual void* SetMinimumSize(unsigned int, int, int) = 0;
	virtual void* GetMinimumSize(unsigned int, int&, int&) = 0;
	virtual void* SetZPos(unsigned int, int) = 0;
	virtual void* GetZPos(unsigned int) = 0;
	virtual void* GetAbsPos(unsigned int, int&, int&) = 0;
	virtual void* GetClipRect(unsigned int, int&, int&, int&, int&) = 0;
	virtual void* SetInset(unsigned int, int, int, int, int) = 0;
	virtual void* GetInset(unsigned int, int&, int&, int&, int&) = 0;
	virtual void* SetVisible(unsigned int, bool) = 0;
	virtual void* IsVisible(unsigned int) = 0;
	virtual void* SetParent(unsigned int, unsigned int) = 0;
	virtual void* GetChildCount(unsigned int) = 0;
	virtual void* GetChild(unsigned int, int) = 0;
	virtual void* GetChildren(unsigned int) = 0;
	virtual void* GetParent(unsigned int) = 0;
	virtual void* MoveToFront(unsigned int) = 0;
	virtual void* MoveToBack(unsigned int) = 0;
	virtual void* HasParent(unsigned int, unsigned int) = 0;
	virtual void* IsPopup(unsigned int) = 0;
	virtual void* SetPopup(unsigned int, bool) = 0;
	virtual void* IsFullyVisible(unsigned int) = 0;
	virtual void* GetScheme(unsigned int) = 0;
	virtual void* IsProportional(unsigned int) = 0;
	virtual void* IsAutoDeleteSet(unsigned int) = 0;
	virtual void* DeletePanel(unsigned int) = 0;
	virtual void* SetKeyBoardInputEnabled(unsigned int, bool) = 0;
	virtual void* SetMouseInputEnabled(unsigned int, bool) = 0;
	virtual void* IsKeyBoardInputEnabled(unsigned int) = 0;
	virtual void* IsMouseInputEnabled(unsigned int) = 0;
	virtual void* Solve(unsigned int) = 0;
	virtual const char* GetName(unsigned int) = 0;
	virtual void* GetClassName(unsigned int) = 0;
	virtual void* SendMessage(unsigned int, KeyValues*, unsigned int) = 0;
	virtual void* Think(unsigned int) = 0;
	virtual void* PerformApplySchemeSettings(unsigned int) = 0;
	virtual void* PaintTraverse(unsigned int, bool, bool) = 0;
	virtual void* Repaint(unsigned int) = 0;
	virtual void* IsWithinTraverse(unsigned int, int, int, bool) = 0;
	virtual void* OnChildAdded(unsigned int, unsigned int) = 0;
	virtual void* OnSizeChanged(unsigned int, int, int) = 0;
	virtual void* InternalFocusChanged(unsigned int, bool) = 0;
	virtual void* RequestInfo(unsigned int, KeyValues*) = 0;
	virtual void* RequestFocus(unsigned int, int) = 0;
	virtual void* RequestFocusPrev(unsigned int, unsigned int) = 0;
	virtual void* RequestFocusNext(unsigned int, unsigned int) = 0;
	virtual void* GetCurrentKeyFocus(unsigned int) = 0;
	virtual void* GetTabPosition(unsigned int) = 0;
	virtual void* Plat(unsigned int) = 0;
	virtual void* SetPlat(unsigned int, vgui::SurfacePlat*) = 0;
	virtual void* GetPanel(unsigned int, char const*) = 0;
	virtual void* IsEnabled(unsigned int) = 0;
	virtual void* SetEnabled(unsigned int, bool) = 0;
	virtual void* IsTopmostPopup(unsigned int) = 0;
	virtual void* SetTopmostPopup(unsigned int, bool) = 0;
	virtual void* SetSiblingPin(unsigned int, unsigned int, unsigned char, unsigned char) = 0;
	virtual void* Client(unsigned int) = 0;
	virtual void* GetModuleName(unsigned int) = 0;

};

inline IPanel* gPanel = nullptr;