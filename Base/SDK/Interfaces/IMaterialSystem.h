#pragma once

class IMesh;
struct Sampler_t;
class CPrimList;
class IMaterialInternal;
class IMatRenderContext;
class KeyValues;
class IMaterial;
class IFileList;
class IAsyncTextureOperationReceiver;
class IShader;
class IMaterialProxyFactory;
struct MaterialVideoMode_t;
struct MaterialSystem_SortInfo_t;
struct ShaderColorCorrectionInfo_t;
struct MaterialAdapterInfo_t;
struct MaterialSystem_Config_t;

typedef struct MaterialLock_t__* MaterialLock_t;

enum StandardTextureId_t;
enum VertexTextureSampler_t;

enum RenderTargetSizeMode_t
{
	RT_SIZE_NO_CHANGE = 0,			// Only allowed for render targets that don't want a depth buffer
	// (because if they have a depth buffer, the render target must be less than or equal to the size of the framebuffer).
	RT_SIZE_DEFAULT = 1,				// Don't play with the specified width and height other than making sure it fits in the framebuffer.
	RT_SIZE_PICMIP = 2,				// Apply picmip to the render target's width and height.
	RT_SIZE_HDR = 3,					// frame_buffer_width / 4
	RT_SIZE_FULL_FRAME_BUFFER = 4,	// Same size as frame buffer, or next lower power of 2 if we can't do that.
	RT_SIZE_OFFSCREEN = 5,			// Target of specified size, don't mess with dimensions
	RT_SIZE_FULL_FRAME_BUFFER_ROUNDED_UP = 6, // Same size as the frame buffer, rounded up if necessary for systems that can't do non-power of two textures.
	RT_SIZE_REPLAY_SCREENSHOT = 7,	// Rounded down to power of 2, essentially...
	RT_SIZE_LITERAL = 8,			// Use the size passed in. Don't clamp it to the frame buffer size. Really.
	RT_SIZE_LITERAL_PICMIP = 9		// Use the size passed in, don't clamp to the frame buffer size, but do apply picmip restrictions.

};

enum MaterialPrimitiveType_t
{
	MATERIAL_POINTS = 0x0,
	MATERIAL_LINES,
	MATERIAL_TRIANGLES,
	MATERIAL_TRIANGLE_STRIP,
	MATERIAL_LINE_STRIP,
	MATERIAL_LINE_LOOP,	// a single line loop
	MATERIAL_POLYGON,	// this is a *single* polygon
	MATERIAL_QUADS,
	MATERIAL_INSTANCED_QUADS, // (X360) like MATERIAL_QUADS, but uses vertex instancing

	// This is used for static meshes that contain multiple types of
	// primitive types.	When calling draw, you'll need to specify
	// a primitive type.
	MATERIAL_HETEROGENOUS
};

enum MaterialMatrixMode_t
{
	MATERIAL_VIEW = 0,
	MATERIAL_PROJECTION,

	// Texture matrices
	MATERIAL_TEXTURE0,
	MATERIAL_TEXTURE1,
	MATERIAL_TEXTURE2,
	MATERIAL_TEXTURE3,
	MATERIAL_TEXTURE4,
	MATERIAL_TEXTURE5,
	MATERIAL_TEXTURE6,
	MATERIAL_TEXTURE7,

	MATERIAL_MODEL,

	// Total number of matrices
	NUM_MATRIX_MODES = MATERIAL_MODEL + 1,

	// Number of texture transforms
	NUM_TEXTURE_TRANSFORMS = MATERIAL_TEXTURE7 - MATERIAL_TEXTURE0 + 1
};

enum MaterialContextType_t
{
	MATERIAL_HARDWARE_CONTEXT,
	MATERIAL_QUEUED_CONTEXT,
	MATERIAL_NULL_CONTEXT
};

enum MaterialThreadMode_t
{
	MATERIAL_SINGLE_THREADED,
	MATERIAL_QUEUED_SINGLE_THREADED,
	MATERIAL_QUEUED_THREADED
};

enum MaterialRenderTargetDepth_t
{
	MATERIAL_RT_DEPTH_SHARED = 0x0,
	MATERIAL_RT_DEPTH_SEPARATE = 0x1,
	MATERIAL_RT_DEPTH_NONE = 0x2,
	MATERIAL_RT_DEPTH_ONLY = 0x3,
};

enum HDRType_t
{
	HDR_TYPE_NONE,
	HDR_TYPE_INTEGER,
	HDR_TYPE_FLOAT,
};

class IMaterialSystem
{
public:
	virtual void* Connect(void* (*)(char const*, int*)) = 0;
	virtual void* Disconnect(void) = 0;
	virtual void* QueryInterface(char const*) = 0;
	virtual void* Init(void) = 0;
	virtual void* Shutdown(void) = 0;
	virtual void* Init(char const*, IMaterialProxyFactory*, void* (*)(char const*, int*), void* (*)(char const*, int*)) = 0;
	virtual void* SetShaderAPI(char const*) = 0;
	virtual void* SetAdapter(int, int) = 0;
	virtual void* ModInit(void) = 0;
	virtual void* ModShutdown(void) = 0;
	virtual void* SetThreadMode(MaterialThreadMode_t, int) = 0;
	virtual void* GetThreadMode(void) = 0;
	virtual void* IsRenderThreadSafe(void) = 0;
	virtual void* ExecuteQueued(void) = 0;
	virtual void* GetHardwareConfig(char const*, int*) = 0;
	virtual void* UpdateConfig(bool) = 0;
	virtual void* OverrideConfig(MaterialSystem_Config_t const&, bool) = 0;
	virtual void* GetCurrentConfigForVideoCard(void)const = 0;
	virtual void* GetRecommendedConfigurationInfo(int, KeyValues*) = 0;
	virtual void* GetDisplayAdapterCount(void)const = 0;
	virtual void* GetCurrentAdapter(void)const = 0;
	virtual void* GetDisplayAdapterInfo(int, MaterialAdapterInfo_t&)const = 0;
	virtual void* GetModeCount(int)const = 0;
	virtual void* GetModeInfo(int, int, MaterialVideoMode_t&)const = 0;
	virtual void* AddModeChangeCallBack(void (*)(void)) = 0;
	virtual void* GetDisplayMode(MaterialVideoMode_t&)const = 0;
	virtual void* SetMode(void*, MaterialSystem_Config_t const&) = 0;
	virtual void* SupportsMSAAMode(int) = 0;
	virtual void* GetVideoCardIdentifier(void)const = 0;
	virtual void* SpewDriverInfo(void)const = 0;
	virtual void* GetDXLevelDefaults(unsigned int&, unsigned int&) = 0;
	virtual void* GetBackBufferDimensions(int&, int&)const = 0;
	virtual void* GetBackBufferFormat(void)const = 0;
	virtual void* SupportsHDRMode(HDRType_t) = 0;
	virtual void* AddView(void*) = 0;
	virtual void* RemoveView(void*) = 0;
	virtual void* SetView(void*) = 0;
	virtual void* BeginFrame(float) = 0;
	virtual void* EndFrame(void) = 0;
	virtual void* Flush(bool) = 0;
	virtual void* SwapBuffers(void) = 0;
	virtual void* EvictManagedResources(void) = 0;
	virtual void* ReleaseResources(void) = 0;
	virtual void* ReacquireResources(void) = 0;
	virtual void* AddReleaseFunc(void (*)(void)) = 0;
	virtual void* RemoveReleaseFunc(void (*)(void)) = 0;
	virtual void* AddRestoreFunc(void (*)(int)) = 0;
	virtual void* RemoveRestoreFunc(void (*)(int)) = 0;
	virtual void* ResetTempHWMemory(bool) = 0;
	virtual void* HandleDeviceLost(void) = 0;
	virtual void* ShaderCount(void)const = 0;
	virtual void* GetShaders(int, int, IShader**)const = 0;
	virtual void* ShaderFlagCount(void)const = 0;
	virtual void* ShaderFlagName(int)const = 0;
	virtual void* GetShaderFallback(char const*, char*, int) = 0;
	virtual void* GetMaterialProxyFactory(void) = 0;
	virtual void* SetMaterialProxyFactory(IMaterialProxyFactory*) = 0;
	virtual void* EnableEditorMaterials(void) = 0;
	virtual void* SetInStubMode(bool) = 0;
	virtual void* DebugPrintUsedMaterials(char const*, bool) = 0;
	virtual void* DebugPrintUsedTextures(void) = 0;
	virtual void* ToggleSuppressMaterial(char const*) = 0;
	virtual void* ToggleDebugMaterial(char const*) = 0;
	virtual void* UsingFastClipping(void) = 0;
	virtual void* StencilBufferBits(void) = 0;
	virtual void* UncacheAllMaterials(void) = 0;
	virtual void* UncacheUnusedMaterials(bool) = 0;
	virtual void* CacheUsedMaterials(void) = 0;
	virtual void* ReloadTextures(void) = 0;
	virtual void* ReloadMaterials(char const*) = 0;
	virtual void* CreateMaterial(char const*, KeyValues*) = 0;
	virtual IMaterial* FindMaterial(char const* pMaterialName, const char* pTextureGroupName = nullptr, bool complain = true, const char* pComplainPrefix = NULL) = 0;
	virtual void* IsMaterialLoaded(char const*) = 0;
	virtual void* FirstMaterial(void)const = 0;
	virtual void* NextMaterial(unsigned short)const = 0;
	virtual void* InvalidMaterial(void)const = 0;
	virtual void* GetMaterial(unsigned short)const = 0;
	virtual void* GetNumMaterials(void)const = 0;
	virtual void* SetAsyncTextureLoadCache(void*) = 0;
	virtual void* FindTexture(char const*, char const*, bool, int) = 0;
	virtual void* IsTextureLoaded(char const*)const = 0;
	virtual void* CreateProceduralTexture(char const*, char const*, int, int, ImageFormat, int) = 0;
	virtual void* BeginRenderTargetAllocation(void) = 0;
	virtual void* EndRenderTargetAllocation(void) = 0;
	virtual void* CreateRenderTargetTexture(int, int, RenderTargetSizeMode_t, ImageFormat, MaterialRenderTargetDepth_t) = 0;
	virtual void* CreateNamedRenderTargetTextureEx(char const*, int, int, RenderTargetSizeMode_t, ImageFormat, MaterialRenderTargetDepth_t, unsigned int, unsigned int) = 0;
	virtual void* CreateNamedRenderTargetTexture(char const*, int, int, RenderTargetSizeMode_t, ImageFormat, MaterialRenderTargetDepth_t, bool, bool) = 0;
	virtual void* CreateNamedRenderTargetTextureEx2(char const*, int, int, RenderTargetSizeMode_t, ImageFormat, MaterialRenderTargetDepth_t, unsigned int, unsigned int) = 0;
	virtual void* BeginLightmapAllocation(void) = 0;
	virtual void* EndLightmapAllocation(void) = 0;
	virtual void* AllocateLightmap(int, int, int*, IMaterial*) = 0;
	virtual void* AllocateWhiteLightmap(IMaterial*) = 0;
	virtual void* UpdateLightmap(int, int*, int*, float*, float*, float*, float*) = 0;
	virtual void* GetNumSortIDs(void) = 0;
	virtual void* GetSortInfo(MaterialSystem_SortInfo_t*) = 0;
	virtual void* GetLightmapPageSize(int, int*, int*)const = 0;
	virtual void* ResetMaterialLightmapPageInfo(void) = 0;
	virtual void* ClearBuffers(bool, bool, bool) = 0;
	virtual void* GetRenderContext(void) = 0;
	virtual void* SupportsShadowDepthTextures(void) = 0;
	virtual void* BeginUpdateLightmaps(void) = 0;
	virtual void* EndUpdateLightmaps(void) = 0;
	virtual void* Lock(void) = 0;
	virtual void* Unlock(MaterialLock_t__*) = 0;
	virtual void* GetShadowDepthTextureFormat(void) = 0;
	virtual void* SupportsFetch4(void) = 0;
	virtual void* CreateRenderContext(MaterialContextType_t) = 0;
	virtual void* SetRenderContext(IMatRenderContext*) = 0;
	virtual void* SupportsCSAAMode(int, int) = 0;
	virtual void* RemoveModeChangeCallBack(void (*)(void)) = 0;
	virtual void* FindProceduralMaterial(char const*, char const*, KeyValues*) = 0;
	virtual void* GetNullTextureFormat(void) = 0;
	virtual void* AddTextureAlias(char const*, char const*) = 0;
	virtual void* RemoveTextureAlias(char const*) = 0;
	virtual void* AllocateDynamicLightmap(int*, int*, int) = 0;
	virtual void* SetExcludedTextures(char const*) = 0;
	virtual void* UpdateExcludedTextures(void) = 0;
	virtual void* IsInFrame(void)const = 0;
	virtual void* CompactMemory(void) = 0;
	virtual void* ReloadFilesInList(IFileList*) = 0;
	virtual void* AllowThreading(bool, int) = 0;
	virtual void* FindMaterialEx(char const*, char const*, int, bool, char const*) = 0;
	virtual void* DoStartupShaderPreloading(void) = 0;
	virtual void* SetRenderTargetFrameBufferSizeOverrides(int, int) = 0;
	virtual void* GetRenderTargetFrameBufferDimensions(int&, int&) = 0;
	virtual void* GetDisplayDeviceName(void)const = 0;
	virtual void* CreateTextureFromBits(int, int, int, ImageFormat, int, unsigned char*) = 0;
	virtual void* OverrideRenderTargetAllocation(bool) = 0;
	virtual void* NewTextureCompositor(int, int, char const*, int, unsigned long long, KeyValues*, unsigned int) = 0;
	virtual void* AsyncFindTexture(char const*, char const*, IAsyncTextureOperationReceiver*, void*, bool, int) = 0;
	virtual void* CreateNamedTextureFromBitsEx(char const*, char const*, int, int, int, ImageFormat, int, unsigned char*, int) = 0;
	virtual void* GetCurrentMaterial(void) = 0;
	virtual void* GetLightmapPage(void) = 0;
	virtual void* GetLightmapWidth(int)const = 0;
	virtual void* GetLightmapHeight(int)const = 0;
	virtual void* GetLocalCubemap(void) = 0;
	virtual void* ForceDepthFuncEquals(bool) = 0;
	virtual void* GetHeightClipMode(void) = 0;
	virtual void* AddMaterialToMaterialList(IMaterialInternal*) = 0;
	virtual void* RemoveMaterial(IMaterialInternal*) = 0;
	virtual void* RemoveMaterialSubRect(IMaterialInternal*) = 0;
	virtual void* InFlashlightMode(void)const = 0;
	virtual void* CanUseEditorMaterials(void)const = 0;
	virtual void* GetForcedTextureLoadPathID(void) = 0;
	virtual void* GetRenderCallQueue(void) = 0;
	virtual void* UnbindMaterial(IMaterial*) = 0;
	virtual void* GetRenderThreadId(void)const = 0;
	virtual void* DetermineProxyReplacements(IMaterial*, KeyValues*) = 0;
	virtual void* GetConfig(void) = 0;
	virtual void* NoteAnisotropicLevel(int) = 0;
	virtual void* ReleaseShaderObjects(void) = 0;
	virtual void* RestoreShaderObjects(void* (*)(char const*, int*), int) = 0;
	virtual void* InEditorMode(void)const = 0;
	virtual void* IsInStubMode(void) = 0;
	virtual void* ImageFormatInfo(ImageFormat)const = 0;
	virtual void* GetMemRequired(int, int, int, ImageFormat, bool) = 0;
	virtual void* ConvertImageFormat(unsigned char*, ImageFormat, unsigned char*, ImageFormat, int, int, int, int) = 0;
	virtual void* OnDrawMesh(IMesh*, int, int) = 0;
	virtual void* OnDrawMesh(IMesh*, CPrimList*, int) = 0;
	virtual void* OnSetFlexMesh(IMesh*, IMesh*, int) = 0;
	virtual void* OnSetColorMesh(IMesh*, IMesh*, int) = 0;
	virtual void* OnSetPrimitiveType(IMesh*, MaterialPrimitiveType_t) = 0;
	virtual void* SyncMatrices(void) = 0;
	virtual void* SyncMatrix(MaterialMatrixMode_t) = 0;
	virtual void* OnFlushBufferedPrimitives(void) = 0;
	virtual void* OnThreadEvent(unsigned int) = 0;
	virtual void* BindStandardTexture(Sampler_t, StandardTextureId_t) = 0;
	virtual void* BindStandardVertexTexture(VertexTextureSampler_t, StandardTextureId_t) = 0;
	virtual void* GetLightmapDimensions(int*, int*) = 0;
	virtual void* GetStandardTextureDimensions(int*, int*, StandardTextureId_t) = 0;
	virtual void* GetBoundMorphFormat(void) = 0;
	virtual void* GetRenderTargetEx(int) = 0;
	virtual void* DrawClearBufferQuad(unsigned char, unsigned char, unsigned char, unsigned char, bool, bool, bool) = 0;
	virtual void* MaxHWMorphBatchCount(void)const = 0;
	virtual void* GetCurrentColorCorrection(ShaderColorCorrectionInfo_t*) = 0;
};

inline IMaterialSystem* gMaterialSystem = nullptr;