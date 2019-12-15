#include "GameEvent.h"

GameEvent* RegistGameEvent
(
	void* game_object,
	void (*OnCreate)(void*),
	void (*OnUpdate)(void*),
	void (*OnDestroy)(void*),
	void (*OnRender)(void*, Color**),
	bool (*__Created)(void*),
	bool (*__ToDestroy)(void*)
){
	GameEvent* ge = malloc(sizeof(GameEvent));

	ge->game_object = game_object;
	ge->OnCreate = OnCreate;
	ge->OnDestroy = OnDestroy;
	ge->OnRender = OnRender;
	ge->__Created = __Created;
	ge->__ToDestroy = __ToDestroy;

	return ge;
}