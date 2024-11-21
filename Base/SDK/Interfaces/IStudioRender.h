#pragma once

class ITexture;
class CUtlBuffer;
class Vector4D;
class VMatrix;
struct LightDesc_t;
struct StudioRenderConfig_t;
struct DrawModelResults_t;
struct FlashlightState_t;
struct model_array_instance_t;
struct GetTriangles_Output_t;

class IStudioRender
{
public:
	virtual void* Connect(void* (*)(char const*, int*)) = 0;
	virtual void* Disconnect(void) = 0;
	virtual void* QueryInterface(char const*) = 0;
	virtual void* Init(void) = 0;
	virtual void* Shutdown(void) = 0;
	virtual void* BeginFrame(void) = 0;
	virtual void* EndFrame(void) = 0;
	virtual void* Mat_Stub(IMaterialSystem*) = 0;
	virtual void* UpdateConfig(StudioRenderConfig_t const&) = 0;
	virtual void* GetCurrentConfig(StudioRenderConfig_t&) = 0;
	virtual void* LoadModel(studiohdr_t*, void*, studiohwdata_t*) = 0;
	virtual void* UnloadModel(studiohwdata_t*) = 0;
	virtual void* RefreshStudioHdr(studiohdr_t*, studiohwdata_t*) = 0;
	virtual void* SetEyeViewTarget(studiohdr_t const*, int, Vector const&) = 0;
	virtual void* GetNumAmbientLightSamples(void) = 0;
	virtual void* GetAmbientLightDirections(void) = 0;
	virtual void* SetAmbientLightColors(Vector4D const*) = 0;
	virtual void* SetAmbientLightColors(Vector const*) = 0;
	virtual void* SetLocalLights(int, LightDesc_t const*) = 0;
	virtual void* SetViewState(Vector const&, Vector const&, Vector const&, Vector const&) = 0;
	virtual void* LockFlexWeights(int, float**, float**) = 0;
	virtual void* UnlockFlexWeights(void) = 0;
	virtual void* LockBoneMatrices(int) = 0;
	virtual void* UnlockBoneMatrices(void) = 0;
	virtual void* GetNumLODs(studiohwdata_t const&)const = 0;
	virtual void* GetLODSwitchValue(studiohwdata_t const&, int)const = 0;
	virtual void* SetLODSwitchValue(studiohwdata_t&, int, float) = 0;
	virtual void SetColorModulation(float const* pColor) = 0;
	virtual void SetAlphaModulation(float flAlpha) = 0;
	virtual void* DrawModel(DrawModelResults_t*, DrawModelInfo_t const&, matrix3x4_t*, float*, float*, Vector const&, int) = 0;
	virtual void* DrawModelStaticProp(DrawModelInfo_t const&, matrix3x4_t const&, int) = 0;
	virtual void* DrawStaticPropDecals(DrawModelInfo_t const&, matrix3x4_t const&) = 0;
	virtual void* DrawStaticPropShadows(DrawModelInfo_t const&, matrix3x4_t const&, int) = 0;
	virtual void ForcedMaterialOverride(IMaterial*, OverrideType_t nOverrideType = OVERRIDE_NORMAL) = 0;
	virtual void* CreateDecalList(studiohwdata_t*) = 0;
	virtual void* DestroyDecalList(StudioDecalHandle_t__*) = 0;
	virtual void* AddDecal(StudioDecalHandle_t__*, studiohdr_t*, matrix3x4_t*, Ray_t const&, Vector const&, IMaterial*, float, int, bool, int) = 0;
	virtual void* ComputeLighting(Vector const*, int, LightDesc_t*, Vector const&, Vector const&, Vector&) = 0;
	virtual void* ComputeLightingConstDirectional(Vector const*, int, LightDesc_t*, Vector const&, Vector const&, Vector&, float) = 0;
	virtual void* AddShadow(IMaterial*, void*, FlashlightState_t*, VMatrix*, ITexture*) = 0;
	virtual void* ClearAllShadows(void) = 0;
	virtual void* ComputeModelLod(studiohwdata_t*, float, float*) = 0;
	virtual void* GetPerfStats(DrawModelResults_t*, DrawModelInfo_t const&, CUtlBuffer*)const = 0;
	virtual void* GetTriangles(DrawModelInfo_t const&, matrix3x4_t*, GetTriangles_Output_t&) = 0;
	virtual void* GetMaterialList(studiohdr_t*, int, IMaterial**) = 0;
	virtual void* GetMaterialListFromBodyAndSkin(unsigned short, int, int, int, IMaterial**) = 0;
	virtual void* DrawModelArray(DrawModelInfo_t const&, int, model_array_instance_t*, int, int) = 0;
};

inline IStudioRender* gStudioRender = nullptr;