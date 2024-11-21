#include "Movement.h"

void Features::CBhop::Run(CUserCmd* cmd)
{
	if (G::Player->deadflag())
		return;

	if (!(cmd->buttons & IN_JUMP))
		return;

	if (G::Player->m_hGroundEntity().IsValid())
		return;

	cmd->buttons &= ~IN_JUMP;
}