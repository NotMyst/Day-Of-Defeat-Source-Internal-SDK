#pragma once

class VPlane;
class IWorldRenderList;
class IBrushRenderer;
struct dlight_t;
struct VisibleFogVolumeInfo_t;
struct VisOverrideData_t;
struct WorldListInfo_t;

enum ERenderDepthMode
{
	DEPTH_MODE_NORMAL = 0,
	DEPTH_MODE_SHADOW = 1,
	DEPTH_MODE_SSA0 = 2,
	DEPTH_MODE_OVERRIDE = 3,

	DEPTH_MODE_MAX
};


enum DrawBrushModelMode_t
{
	DBM_DRAW_ALL = 0,
	DBM_DRAW_OPAQUE_ONLY,
	DBM_DRAW_TRANSLUCENT_ONLY,
};

class IVRenderView
{
public:
	virtual void* DrawBrushModel(IClientEntity*, model_t*, Vector const&, QAngle const&, bool) = 0;
	virtual void* DrawIdentityBrushModel(IWorldRenderList*, model_t*) = 0;
	virtual void* TouchLight(dlight_t*) = 0;
	virtual void* Draw3DDebugOverlays(void) = 0;
	virtual void SetBlend(float blend) = 0;
	virtual float GetBlend(void) = 0;
	virtual void SetColorModulation(float const* blend) = 0;
	virtual void GetColorModulation(float* blend) = 0;
	virtual void* SceneBegin(void) = 0;
	virtual void* SceneEnd(void) = 0;
	virtual void* GetVisibleFogVolume(Vector const&, VisibleFogVolumeInfo_t*) = 0;
	virtual void* CreateWorldList(void) = 0;
	virtual void* BuildWorldLists(IWorldRenderList*, WorldListInfo_t*, int, VisOverrideData_t const*, bool, float*) = 0;
	virtual void* DrawWorldLists(IWorldRenderList*, unsigned long, float) = 0;
	virtual void* DrawTopView(bool) = 0;
	virtual void* TopViewBounds(Vector2D const&, Vector2D const&) = 0;
	virtual void* DrawLights(void) = 0;
	virtual void* DrawMaskEntities(void) = 0;
	virtual void* DrawTranslucentSurfaces(IWorldRenderList*, int, unsigned long, bool) = 0;
	virtual void* DrawLineFile(void) = 0;
	virtual void* DrawLightmaps(IWorldRenderList*, int) = 0;
	virtual void* ViewSetupVis(bool, int, Vector const*) = 0;
	virtual void* AreAnyLeavesVisible(int*, int) = 0;
	virtual void* VguiPaint(void) = 0;
	virtual void* ViewDrawFade(unsigned char*, IMaterial*) = 0;
	virtual void* OLD_SetProjectionMatrix(float, float, float) = 0;
	virtual void* GetLightAtPoint(Vector&) = 0;
	virtual void* GetViewEntity(void) = 0;
	virtual void* GetFieldOfView(void) = 0;
	virtual void* GetAreaBits(void) = 0;
	virtual void* SetFogVolumeState(int, bool) = 0;
	virtual void* InstallBrushSurfaceRenderer(IBrushRenderer*) = 0;
	virtual void* DrawBrushModelShadow(IClientRenderable*) = 0;
	virtual void* LeafContainsTranslucentSurfaces(IWorldRenderList*, int, unsigned long) = 0;
	virtual void* DoesBoxIntersectWaterVolume(Vector const&, Vector const&, int) = 0;
	virtual void* SetAreaState(unsigned char*, unsigned char*) = 0;
	virtual void* VGui_Paint(int) = 0;
	virtual void* Push3DView(CViewSetup const&, int, ITexture*, VPlane*) = 0;
	virtual void* Push2DView(CViewSetup const&, int, ITexture*, VPlane*) = 0;
	virtual void* PopView(VPlane*) = 0;
	virtual void* SetMainView(Vector const&, QAngle const&) = 0;
	virtual void* ViewSetupVisEx(bool, int, Vector const*, unsigned int&) = 0;
	virtual void* OverrideViewFrustum(VPlane*) = 0;
	virtual void* DrawBrushModelShadowDepth(IClientEntity*, model_t*, Vector const&, QAngle const&, ERenderDepthMode) = 0;
	virtual void* UpdateBrushModelLightmap(model_t*, IClientRenderable*) = 0;
	virtual void* BeginUpdateLightmaps(void) = 0;
	virtual void* EndUpdateLightmaps(void) = 0;
	virtual void* OLD_SetOffCenterProjectionMatrix(float, float, float, float, float, float, float, float) = 0;
	virtual void* OLD_SetProjectionMatrixOrtho(float, float, float, float, float, float) = 0;
	virtual void* Push3DView(CViewSetup const&, int, ITexture*, VPlane*, ITexture*) = 0;
	virtual void* GetMatricesForView(CViewSetup const&, VMatrix*, VMatrix*, VMatrix*, VMatrix*) = 0;
	virtual void* DrawBrushModelEx(IClientEntity*, model_t*, Vector const&, QAngle const&, DrawBrushModelMode_t) = 0;
	virtual void* EnumerateLeaf(int, int) = 0;
};

inline IVRenderView* gRenderView = nullptr;