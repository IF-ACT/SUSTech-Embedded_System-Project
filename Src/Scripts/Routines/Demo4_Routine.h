#ifndef __DEMO4_ROUTINE_H
#define __DEMO4_ROUTINE_H

#include <stdlib.h>
#include "Demo1_GameObject_Self.h"
#include "Demo2_GameObject_Enemy.h"
#include "Img_TestImages.h"
#include "GameEvent.h"
#include "GameEngine.h"

void Demo4_Routine(){

	// regester demo 1
	Demo1_GameObject_Self *demo1 = malloc(sizeof(Demo1_GameObject_Self));
	Demo1_Init(demo1, 1, 15, 20, 10, 10, 10, Img_GreenBlock_10x10, "Demo1");
	GameEvent *event = RegistGameEvent(
							demo1,
							Demo1_OnCreate, Demo1_OnUpdate, Demo1_OnDestroy,
							Demo1_OnRender, __Demo1_Created, __Demo1_ToDestroy
						);

	Push(&objects, event);

	// regester demo 2
	Demo2_GameObject_Enemy* demo2 = malloc(sizeof(Demo2_GameObject_Enemy));
	Demo2_Init(demo2, 10, 25, 30, 2, 4, 4, Img_RedBlock_4x4);
	event = RegistGameEvent(
		demo2,
		Demo2_OnCreate, Demo2_OnUpdate, Demo2_OnDestroy,
		Demo2_OnRender, __Demo2_Created, __Demo2_ToDestroy
	);
	Push(&objects, event);

	GameEngineLoop();
}

#endif
