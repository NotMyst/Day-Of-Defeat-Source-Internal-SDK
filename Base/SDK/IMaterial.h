#pragma once

class KeyValues;
class IMaterialVar;
class IFileList;

enum ImageFormat
{
	IMAGE_FORMAT_UNKNOWN = -1,
	IMAGE_FORMAT_RGBA8888 = 0,
	IMAGE_FORMAT_ABGR8888,
	IMAGE_FORMAT_RGB888,
	IMAGE_FORMAT_BGR888,
	IMAGE_FORMAT_RGB565,
	IMAGE_FORMAT_I8,
	IMAGE_FORMAT_IA88,
	IMAGE_FORMAT_P8,
	IMAGE_FORMAT_A8,
	IMAGE_FORMAT_RGB888_BLUESCREEN,
	IMAGE_FORMAT_BGR888_BLUESCREEN,
	IMAGE_FORMAT_ARGB8888,
	IMAGE_FORMAT_BGRA8888,
	IMAGE_FORMAT_DXT1,
	IMAGE_FORMAT_DXT3,
	IMAGE_FORMAT_DXT5,
	IMAGE_FORMAT_BGRX8888,
	IMAGE_FORMAT_BGR565,
	IMAGE_FORMAT_BGRX5551,
	IMAGE_FORMAT_BGRA4444,
	IMAGE_FORMAT_DXT1_ONEBITALPHA,
	IMAGE_FORMAT_BGRA5551,
	IMAGE_FORMAT_UV88,
	IMAGE_FORMAT_UVWQ8888,
	IMAGE_FORMAT_RGBA16161616F,
	IMAGE_FORMAT_RGBA16161616,
	IMAGE_FORMAT_UVLX8888,
	IMAGE_FORMAT_R32F,			// Single-channel 32-bit floating point
	IMAGE_FORMAT_RGB323232F,
	IMAGE_FORMAT_RGBA32323232F,

	// Depth-stencil texture formats for shadow depth mapping
	IMAGE_FORMAT_NV_DST16,		// 
	IMAGE_FORMAT_NV_DST24,		//
	IMAGE_FORMAT_NV_INTZ,		// Vendor-specific depth-stencil texture
	IMAGE_FORMAT_NV_RAWZ,		// formats for shadow depth mapping 
	IMAGE_FORMAT_ATI_DST16,		// 
	IMAGE_FORMAT_ATI_DST24,		//
	IMAGE_FORMAT_NV_NULL,		// Dummy format which takes no video memory

	// Compressed normal map formats
	IMAGE_FORMAT_ATI2N,			// One-surface ATI2N / DXN format
	IMAGE_FORMAT_ATI1N,			// Two-surface ATI1N format

	IMAGE_FORMAT_DXT1_RUNTIME,
	IMAGE_FORMAT_DXT5_RUNTIME,

	NUM_IMAGE_FORMATS
};

enum MaterialVarFlags_t
{
	MATERIAL_VAR_DEBUG = (1 << 0),
	MATERIAL_VAR_NO_DEBUG_OVERRIDE = (1 << 1),
	MATERIAL_VAR_NO_DRAW = (1 << 2),
	MATERIAL_VAR_USE_IN_FILLRATE_MODE = (1 << 3),

	MATERIAL_VAR_VERTEXCOLOR = (1 << 4),
	MATERIAL_VAR_VERTEXALPHA = (1 << 5),
	MATERIAL_VAR_SELFILLUM = (1 << 6),
	MATERIAL_VAR_ADDITIVE = (1 << 7),
	MATERIAL_VAR_ALPHATEST = (1 << 8),
	MATERIAL_VAR_MULTIPASS = (1 << 9),
	MATERIAL_VAR_ZNEARER = (1 << 10),
	MATERIAL_VAR_MODEL = (1 << 11),
	MATERIAL_VAR_FLAT = (1 << 12),
	MATERIAL_VAR_NOCULL = (1 << 13),
	MATERIAL_VAR_NOFOG = (1 << 14),
	MATERIAL_VAR_IGNOREZ = (1 << 15),
	MATERIAL_VAR_DECAL = (1 << 16),
	MATERIAL_VAR_ENVMAPSPHERE = (1 << 17),
	MATERIAL_VAR_NOALPHAMOD = (1 << 18),
	MATERIAL_VAR_ENVMAPCAMERASPACE = (1 << 19),
	MATERIAL_VAR_BASEALPHAENVMAPMASK = (1 << 20),
	MATERIAL_VAR_TRANSLUCENT = (1 << 21),
	MATERIAL_VAR_NORMALMAPALPHAENVMAPMASK = (1 << 22),
	MATERIAL_VAR_NEEDS_SOFTWARE_SKINNING = (1 << 23),
	MATERIAL_VAR_OPAQUETEXTURE = (1 << 24),
	MATERIAL_VAR_ENVMAPMODE = (1 << 25),
	MATERIAL_VAR_SUPPRESS_DECALS = (1 << 26),
	MATERIAL_VAR_HALFLAMBERT = (1 << 27),
	MATERIAL_VAR_WIREFRAME = (1 << 28),
	MATERIAL_VAR_ALLOWALPHATOCOVERAGE = (1 << 29),
	MATERIAL_VAR_IGNORE_ALPHA_MODULATION = (1 << 30),

	// NOTE: Only add flags here that either should be read from
	// .vmts or can be set directly from client code. Other, internal
	// flags should to into the flag enum in imaterialinternal.h
};


//-----------------------------------------------------------------------------
// Internal flags not accessible from outside the material system. Stored in Flags2
//-----------------------------------------------------------------------------
enum MaterialVarFlags2_t
{
	// NOTE: These are for $flags2!!!!!
//	UNUSED											= (1 << 0),

	MATERIAL_VAR2_LIGHTING_UNLIT = 0,
	MATERIAL_VAR2_LIGHTING_VERTEX_LIT = (1 << 1),
	MATERIAL_VAR2_LIGHTING_LIGHTMAP = (1 << 2),
	MATERIAL_VAR2_LIGHTING_BUMPED_LIGHTMAP = (1 << 3),
	MATERIAL_VAR2_LIGHTING_MASK =
	(MATERIAL_VAR2_LIGHTING_VERTEX_LIT |
		MATERIAL_VAR2_LIGHTING_LIGHTMAP |
		MATERIAL_VAR2_LIGHTING_BUMPED_LIGHTMAP),

	// FIXME: Should this be a part of the above lighting enums?
	MATERIAL_VAR2_DIFFUSE_BUMPMAPPED_MODEL = (1 << 4),
	MATERIAL_VAR2_USES_ENV_CUBEMAP = (1 << 5),
	MATERIAL_VAR2_NEEDS_TANGENT_SPACES = (1 << 6),
	MATERIAL_VAR2_NEEDS_SOFTWARE_LIGHTING = (1 << 7),
	// GR - HDR path puts lightmap alpha in separate texture...
	MATERIAL_VAR2_BLEND_WITH_LIGHTMAP_ALPHA = (1 << 8),
	MATERIAL_VAR2_NEEDS_BAKED_LIGHTING_SNAPSHOTS = (1 << 9),
	MATERIAL_VAR2_USE_FLASHLIGHT = (1 << 10),
	MATERIAL_VAR2_USE_FIXED_FUNCTION_BAKED_LIGHTING = (1 << 11),
	MATERIAL_VAR2_NEEDS_FIXED_FUNCTION_FLASHLIGHT = (1 << 12),
	MATERIAL_VAR2_USE_EDITOR = (1 << 13),
	MATERIAL_VAR2_NEEDS_POWER_OF_TWO_FRAME_BUFFER_TEXTURE = (1 << 14),
	MATERIAL_VAR2_NEEDS_FULL_FRAME_BUFFER_TEXTURE = (1 << 15),
	MATERIAL_VAR2_IS_SPRITECARD = (1 << 16),
	MATERIAL_VAR2_USES_VERTEXID = (1 << 17),
	MATERIAL_VAR2_SUPPORTS_HW_SKINNING = (1 << 18),
	MATERIAL_VAR2_SUPPORTS_FLASHLIGHT = (1 << 19),
};

enum VertexCompressionType_t
{
	// This indicates an uninitialized VertexCompressionType_t value
	VERTEX_COMPRESSION_INVALID = 0xFFFFFFFF,

	// 'VERTEX_COMPRESSION_NONE' means that no elements of a vertex are compressed
	VERTEX_COMPRESSION_NONE = 0,

	// Currently (more stuff may be added as needed), 'VERTEX_COMPRESSION_ON' means:
	//  - if a vertex contains VERTEX_ELEMENT_NORMAL, this is compressed
	//    (see CVertexBuilder::CompressedNormal3f)
	//  - if a vertex contains VERTEX_ELEMENT_USERDATA4 (and a normal - together defining a tangent
	//    frame, with the binormal reconstructed in the vertex shader), this is compressed
	//    (see CVertexBuilder::CompressedUserData)
	//  - if a vertex contains VERTEX_ELEMENT_BONEWEIGHTSx, this is compressed
	//    (see CVertexBuilder::CompressedBoneWeight3fv)
	VERTEX_COMPRESSION_ON = 1
};

enum MaterialPropertyTypes_t
{
	MATERIAL_PROPERTY_NEEDS_LIGHTMAP = 0,					// bool
	MATERIAL_PROPERTY_OPACITY,								// int (enum MaterialPropertyOpacityTypes_t)
	MATERIAL_PROPERTY_REFLECTIVITY,							// vec3_t
	MATERIAL_PROPERTY_NEEDS_BUMPED_LIGHTMAPS				// bool
};

class IMaterial
{
public:
	virtual void* GetName(void)const = 0;
	virtual void* GetTextureGroupName(void)const = 0;
	virtual void* GetPreviewImageProperties(int*, int*, ImageFormat*, bool*)const = 0;
	virtual void* GetPreviewImage(unsigned char*, int, int, ImageFormat)const = 0;
	virtual void* GetMappingWidth(void) = 0;
	virtual void* GetMappingHeight(void) = 0;
	virtual void* GetNumAnimationFrames(void) = 0;
	virtual void* InMaterialPage(void) = 0;
	virtual void* GetMaterialOffset(float*) = 0;
	virtual void* GetMaterialScale(float*) = 0;
	virtual void* GetMaterialPage(void) = 0;
	virtual void* FindVar(char const*, bool*, bool) = 0;
	virtual void IncrementReferenceCount(void) = 0;
	virtual void* DecrementReferenceCount(void) = 0;
	virtual void* GetEnumerationID(void)const = 0;
	virtual void* GetLowResColorSample(float, float, float*)const = 0;
	virtual void* RecomputeStateSnapshots(void) = 0;
	virtual void* IsTranslucent(void) = 0;
	virtual void* IsAlphaTested(void) = 0;
	virtual void* IsVertexLit(void) = 0;
	virtual void* GetVertexFormat(void)const = 0;
	virtual void* HasProxy(void)const = 0;
	virtual void* UsesEnvCubemap(void) = 0;
	virtual void* NeedsTangentSpace(void) = 0;
	virtual void* NeedsPowerOfTwoFrameBufferTexture(bool) = 0;
	virtual void* NeedsFullFrameBufferTexture(bool) = 0;
	virtual void* NeedsSoftwareSkinning(void) = 0;
	virtual void AlphaModulate(float alpha) = 0;
	virtual void ColorModulate(float r, float g, float b) = 0;
	virtual void SetMaterialVarFlag(MaterialVarFlags_t flag, bool on) = 0;
	virtual void* GetMaterialVarFlag(MaterialVarFlags_t)const = 0;
	virtual void* GetReflectivity(Vector&) = 0;
	virtual void* GetPropertyFlag(MaterialPropertyTypes_t) = 0;
	virtual void* IsTwoSided(void) = 0;
	virtual void* SetShader(char const*) = 0;
	virtual void* GetNumPasses(void) = 0;
	virtual void* GetTextureMemoryBytes(void) = 0;
	virtual void* Refresh(void) = 0;
	virtual void* NeedsLightmapBlendAlpha(void) = 0;
	virtual void* NeedsSoftwareLighting(void) = 0;
	virtual void* ShaderParamCount(void)const = 0;
	virtual void* GetShaderParams(void) = 0;
	virtual void* IsErrorMaterial(void)const = 0;
	virtual void* SetUseFixedFunctionBakedLighting(bool) = 0;
	virtual float GetAlphaModulation(void) = 0;
	virtual void GetColorModulation(float* r, float* g, float* b) = 0;
	virtual void* GetMorphFormat(void)const = 0;
	virtual void* FindVarFast(char const*, unsigned int*) = 0;
	virtual void* SetShaderAndParams(KeyValues*) = 0;
	virtual void* GetShaderName(void)const = 0;
	virtual void* DeleteIfUnreferenced(void) = 0;
	virtual void* IsSpriteCard(void) = 0;
	virtual void* CallBindProxy(void*) = 0;
	virtual void* CheckProxyReplacement(void*) = 0;
	virtual void* RefreshPreservingMaterialVars(void) = 0;
	virtual void* WasReloadedFromWhitelist(void) = 0;
	virtual void* IsPrecached(void)const = 0;
	virtual void* GetReferenceCount(void)const = 0;
	virtual void* SetEnumerationID(int) = 0;
	virtual void* SetNeedsWhiteLightmap(bool) = 0;
	virtual void* GetNeedsWhiteLightmap(void)const = 0;
	virtual void* Uncache(bool) = 0;
	virtual void* Precache(void) = 0;
	virtual void* PrecacheVars(KeyValues*, KeyValues*, void*, int) = 0;
	virtual void* ReloadTextures(void) = 0;
	virtual void* SetMinLightmapPageID(int) = 0;
	virtual void* SetMaxLightmapPageID(int) = 0;
	virtual void* GetMinLightmapPageID(void)const = 0;
	virtual void* GetMaxLightmapPageID(void)const = 0;
	virtual void* GetShader(void)const = 0;
	virtual void* IsPrecachedVars(void)const = 0;
	virtual void* DrawMesh(/*VertexCompressionType_t*/) = 0;
	virtual void* GetVertexUsage(void)const = 0;
	virtual void* PerformDebugTrace(void)const = 0;
	virtual void* NoDebugOverride(void)const = 0;
	virtual void* ToggleSuppression(void) = 0;
	virtual void* IsSuppressed(void)const = 0;
	virtual void* ToggleDebugTrace(void) = 0;
	virtual void* UseFog(void)const = 0;
	virtual void* AddMaterialVar(IMaterialVar*) = 0;
	virtual void* GetRenderState(void) = 0;
	virtual void* IsManuallyCreated(void)const = 0;
	virtual void* NeedsFixedFunctionFlashlight(void)const = 0;
	virtual void* IsUsingVertexID(void)const = 0;
	virtual void* MarkAsPreloaded(bool) = 0;
	virtual void* IsPreloaded(void)const = 0;
	virtual void* ArtificialAddRef(void) = 0;
	virtual void* ArtificialRelease(void) = 0;
	virtual void* ReportVarChanged(IMaterialVar*) = 0;
	virtual void* GetChangeID(void)const = 0;
	virtual void* IsTranslucentInternal(float)const = 0;
	virtual void* IsRealTimeVersion(void)const = 0;
	virtual void* ClearContextData(void) = 0;
	virtual void* GetRealTimeVersion(void) = 0;
	virtual void* GetQueueFriendlyVersion(void) = 0;
	virtual void* PrecacheMappingDimensions(void) = 0;
	virtual void* FindRepresentativeTexture(void) = 0;
	virtual void* DecideShouldReloadFromWhitelist(IFileList*) = 0;
	virtual void* ReloadFromWhitelistIfMarked(void) = 0;
};