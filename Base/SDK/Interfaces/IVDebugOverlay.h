#pragma once

class OverlayText_t;

class IVDebugOverlay
{
public:
	virtual void* AddEntityTextOverlay(int, int, float, int, int, int, int, char const*, ...) = 0;
	virtual void* AddBoxOverlay(Vector const&, Vector const&, Vector const&, QAngle const&, int, int, int, int, float) = 0;
	virtual void* AddTriangleOverlay(Vector const&, Vector const&, Vector const&, int, int, int, int, bool, float) = 0;
	virtual void* AddLineOverlay(Vector const&, Vector const&, int, int, int, bool, float) = 0;
	virtual void* AddTextOverlay(Vector const&, float, char const*, ...) = 0;
	virtual void* AddTextOverlay(Vector const&, int, float, char const*, ...) = 0;
	virtual void* AddScreenTextOverlay(float, float, float, int, int, int, int, char const*) = 0;
	virtual void* AddSweptBoxOverlay(Vector const&, Vector const&, Vector const&, Vector const&, QAngle const&, int, int, int, int, float) = 0;
	virtual void* AddGridOverlay(Vector const&) = 0;
	virtual int ScreenPosition(const Vector& point, Vector& screen) = 0;
	virtual int ScreenPosition(float flXPos, float flYPos, Vector& screen) = 0;
	virtual void* GetFirst(void) = 0;
	virtual void* GetNext(OverlayText_t*) = 0;
	virtual void* ClearDeadOverlays(void) = 0;
	virtual void* ClearAllOverlays(void) = 0;
	virtual void* AddTextOverlayRGB(Vector const&, int, float, float, float, float, float, char const*, ...) = 0;
	virtual void* AddTextOverlayRGB(Vector const&, int, float, int, int, int, int, char const*, ...) = 0;
	virtual void* AddLineOverlayAlpha(Vector const&, Vector const&, int, int, int, int, bool, float) = 0;
	virtual void* AddBoxOverlay2(Vector const&, Vector const&, Vector const&, QAngle const&, Color const&, Color const&, float) = 0;
};

inline IVDebugOverlay* gDebugOverlay = nullptr;