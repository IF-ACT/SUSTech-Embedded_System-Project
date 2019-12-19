#include "Demo4_Routine.h"

#include <stdlib.h>
#include "Remo_GameObject_Self.h"
#include "Demo2_GameObject_Enemy.h"
#include "Goast_GameObject_Enemy.h"
#include "GameEvent.h"
#include "GameEngine.h"
#include "Time.h"
#include "mygpio.h"

void Demo4_OnLoop_1()
{
	if (GetTime() == 100)
	{
		GameEvent* event;
		Demo2_GameObject_Enemy* enemy = malloc(sizeof(Demo2_GameObject_Enemy));
		printlnf("enemy pointer: %d", enemy);
		Demo2_Init(
			enemy, 200,
			10, 10,
			2
		);
		event = RegistGameEvent(
			enemy,
			Demo2_OnCreate, Demo2_OnUpdate,
			Demo2_OnDestroy, Demo2_OnRender
		);
		Push(&Engine_EnemyEvents, event);
	}
	
	if (GetTime() == 200)
	{
		GameEvent* event;
		Demo2_GameObject_Enemy* enemy = malloc(sizeof(Demo2_GameObject_Enemy));
		printlnf("enemy pointer: %d", enemy);
		Demo2_Init(
			enemy, 200,
			30, 10,
			2
		);
		event = RegistGameEvent(
			enemy,
			Demo2_OnCreate, Demo2_OnUpdate,
			Demo2_OnDestroy, Demo2_OnRender
		);
		Push(&Engine_EnemyEvents, event);
	}

	if (GetTime() > 200 && !(GetTime()%15))
	{
		Goast_GameObject_Enemy* goast = Goast_Init(40, 10, 0);
		GameEvent* event = RegistGameEvent(
			goast,
			Goast_OnCreate, Goast_OnUpdate,
			Goast_OnDestroy, Goast_OnRender
		);
		Push(&Engine_EnemyEvents, event);
	}
}

void Demo4_Routine(){

	GameEngineInit();

	// regester demo 1
	Remo_GameObject_Self* remo = malloc(sizeof(Remo_GameObject_Self));
	Remo_Init(remo, 28, 65);
	GameEvent* event = RegistGameEvent(
		remo, Remo_OnCreate, Remo_OnUpdate, Remo_OnDestroy, Remo_OnRender
	);

	Engine_SelfEvent = event;

	GameEngineLoop(Demo4_OnLoop_1);
}