#ifndef __GAME_EVENT_H
#define __GAME_EVENT_H

#include <stdbool.h>
#include <stdlib.h>
#include "lcd.h"

typedef struct GameEvent
{
	void *game_object;

	void (*OnCreate)(void*);
	void (*OnUpdate)(void*);
	void (*OnDestroy)(void*);
	void (*OnRender)(void*, Color**);

} GameEvent;

GameEvent* RegistGameEvent
(
	void* game_object,
	void (*OnCreate)(void*),
	void (*OnUpdate)(void*),
	void (*OnDestroy)(void*),
	void (*OnRender)(void*, Color**)
);

#endif