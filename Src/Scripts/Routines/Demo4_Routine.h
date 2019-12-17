#ifndef __DEMO4_ROUTINE_H
#define __DEMO4_ROUTINE_H

#include <stdlib.h>
#include "Demo1_GameObject_Self.h"
#include "Img_TestImages.h"
#include "GameEvent.h"
#include "GameEngine.h"

void Demo4_Routine(){

	Demo1_GameObject_Self *self = malloc(sizeof(GameObject_Self));

	Demo1_Init(self, 1, 15, 20, 10, 10, 10, Img_GreenBlock_10x10, "Demo1");

	GameEvent *event = RegistGameEvent(
							self,
							Demo1_OnCreate, Demo1_OnUpdate, Demo1_OnDestroy,
							Demo1_OnRender, __Demo1_Created, __Demo1_ToDestroy
						);

	println("regested");

	Push(&objects, event);

	println("pushed");

	GameEngineLoop();
}

#endif
