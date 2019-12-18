#include "GameEvent.h"

GameEvent* RegistGameEvent
(
	void* game_object,
	void (*OnCreate)(void*),
	void (*OnUpdate)(void*),
	void (*OnDestroy)(void*),
	void (*OnRender)(void*, Color**)
){
	GameEvent* ge = malloc(sizeof(GameEvent));

	ge->game_object = game_object;
	ge->OnCreate = OnCreate;
	ge->OnUpdate = OnUpdate;
	ge->OnDestroy = OnDestroy;
	ge->OnRender = OnRender;

	return ge;
}