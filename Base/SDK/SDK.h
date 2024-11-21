#pragma once

#include "../Netvar/Netvar.h"

#include "buttoncode.h"
#include "Const.h"
#include "dt_common.h"
#include "dt_recv.h"
#include "interface.h"
#include "ClientClass.h"
#include "CViewSetup.h"
#include "CUserCmd.h"
#include "IMaterial.h"
#include "CGlobalVarsBase.h"
#include "C_DODGameRules.h"
#include "checksum_md5.h"
#include "CSteamID.h"
#include "Color.h"
#include "CGameEventListener.h"

#include "IClientUnknown.h"
#include "IClientRenderable.h"
#include "IClientNetworkable.h"
#include "IClientThinkable.h"
#include "IClientEntity.h"
#include "C_BaseEntity.h"
#include "C_BaseAnimating.h"
#include "C_BaseViewmodel.h"
#include "C_BaseFlex.h"
#include "C_BaseCombatWeapon.h"
#include "C_BaseCombatCharacter.h"
#include "C_BasePlayer.h"
#include "C_DODPlayer.h"
#include "C_WeaponDODBase.h"
#include "C_WeaponDODBaseGrenade.h"
#include "C_Team.h"
#include "C_DODTeam.h"

#include "Interfaces/IBaseClientDLL.h"
#include "Interfaces/IClientEntityList.h"
#include "Interfaces/IClientMode.h"
#include "Interfaces/IVEngineClient.h"
#include "Interfaces/IVModelRender.h"
#include "Interfaces/IStudioRender.h"
#include "Interfaces/IMaterialSystem.h"
#include "Interfaces/IVRenderView.h"
#include "Interfaces/IPlayerInfoManager.h"
#include "Interfaces/IPrediction.h"
#include "Interfaces/IGameMovement.h"
#include "Interfaces/IMoveHelper.h"
#include "Interfaces/IEngineTrace.h"
#include "Interfaces/IVDebugOverlay.h"
#include "Interfaces/IUniformRandomStream.h"
#include "Interfaces/IMatSystemSurface.h"
#include "Interfaces/IPanel.h"