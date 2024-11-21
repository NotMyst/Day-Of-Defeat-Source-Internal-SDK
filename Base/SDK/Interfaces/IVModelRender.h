#pragma once

class IMaterial;
struct Ray_t;
struct StaticPropRenderInfo_t;
struct DrawModelInfo_t;
struct studiohdr_t;
struct studiohwdata_t;
typedef struct LightCacheHandle_t__* LightCacheHandle_t;
typedef struct StudioDecalHandle_t__* StudioDecalHandle_t;

struct DrawModelState_t
{
	studiohdr_t* m_pStudioHdr;
	studiohwdata_t* m_pStudioHWData;
	IClientRenderable* m_pRenderable;
	const matrix3x4_t* m_pModelToWorld;
	StudioDecalHandle_t		m_decals;
	int						m_drawFlags;
	int						m_lod;
};

struct ModelRenderInfo_t
{
	Vector origin;
	QAngle angles;
	IClientRenderable* pRenderable;
	const model_t* pModel;
	const matrix3x4_t* pModelToWorld;
	const matrix3x4_t* pLightingOffset;
	const Vector* pLightingOrigin;
	int flags;
	int entity_index;
	int skin;
	int body;
	int hitboxset;
	// ModelInstanceHandle_t instance;
};

class IVModelRender
{
public:
	virtual void* DrawModel(int, IClientRenderable*, unsigned short, int, model_t const*, Vector const&, QAngle const&, int, int, int, matrix3x4_t const*, matrix3x4_t const*) = 0;
	virtual void ForcedMaterialOverride(IMaterial* newMaterial, OverrideType_t nOverrideType = OVERRIDE_NORMAL) = 0;
	virtual void* SetViewTarget(CStudioHdr const*, int, Vector const&) = 0;
	virtual void* CreateInstance(IClientRenderable*, LightCacheHandle_t__**) = 0;
	virtual void* DestroyInstance(unsigned short) = 0;
	virtual void* SetStaticLighting(unsigned short, LightCacheHandle_t__**) = 0;
	virtual void* GetStaticLighting(unsigned short) = 0;
	virtual void* ChangeInstance(unsigned short, IClientRenderable*) = 0;
	virtual void* AddDecal(unsigned short, Ray_t const&, Vector const&, int, int, bool, int) = 0;
	virtual void* RemoveAllDecals(unsigned short) = 0;
	virtual void* RemoveAllDecalsFromAllModels(void) = 0;
	virtual void* DrawModelShadowSetup(IClientRenderable*, int, int, DrawModelInfo_t*, matrix3x4_t*) = 0;
	virtual void* DrawModelShadow(IClientRenderable*, DrawModelInfo_t const&, matrix3x4_t*) = 0;
	virtual void* RecomputeStaticLighting(unsigned short) = 0;
	virtual void* ReleaseAllStaticPropColorData(void) = 0;
	virtual void* RestoreAllStaticPropColorData(void) = 0;
	virtual void* DrawModelEx(ModelRenderInfo_t&) = 0;
	virtual void* DrawModelExStaticProp(ModelRenderInfo_t&) = 0;
	virtual void* DrawModelSetup(ModelRenderInfo_t&, DrawModelState_t*, matrix3x4_t*, matrix3x4_t**) = 0;
	virtual void DrawModelExecute(const DrawModelState_t&, const ModelRenderInfo_t&, matrix3x4_t* = NULL) = 0;
	virtual void* SetupLighting(Vector const&) = 0;
	virtual void* DrawStaticPropArrayFast(StaticPropRenderInfo_t*, int, bool) = 0;
	virtual void* SuppressEngineLighting(bool) = 0;
	virtual void* SetupColorMeshes(int) = 0;
	virtual void* AddColoredDecal(unsigned short, Ray_t const&, Vector const&, int, int, Color, bool, int) = 0;
	virtual void* GetItemName(unsigned int, void const*, char*, unsigned int) = 0;

};

inline IVModelRender* gModelRender = nullptr;