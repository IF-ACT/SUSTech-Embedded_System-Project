#ifndef __DEMO4_ROUTINE_H
#define __DEMO4_ROUTINE_H

#include <stdlib.h>
#include "Remo_GameObject_Self.h"
#include "Demo2_GameObject_Enemy.h"
#include "GameEvent.h"
#include "GameEngine.h"

void Demo4_Routine(){

	GameEngineInit();

	// regester demo 1
	Remo_GameObject_Self* remo = malloc(sizeof(Remo_GameObject_Self));
	Remo_Init(remo, 28, 65);
	GameEvent* event = RegistGameEvent(
		remo, Remo_OnCreate, Remo_OnUpdate, Remo_OnDestroy, Remo_OnRender
	);

	Engine_SelfEvent = event;

	GameEngineLoop();
}

#endif
