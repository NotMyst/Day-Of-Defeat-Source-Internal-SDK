#pragma once

class IGameEvent;

class CGameEventListener
{
public:
	virtual void FireGameEvent(IGameEvent* event) = 0;
};