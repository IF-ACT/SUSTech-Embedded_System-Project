#ifndef __DEMO2_GAME_OBJECT_ENEMY_H
#define __DEMO2_GAME_OBJECT_ENEMY_H

#include "GameObject_Enemy.h"

typedef struct Demo2_GameObject_Enemy
{
	GameObject_Enemy base;

}Demo2_GameObject_Enemy;

void Demo2_Init(
	Demo2_GameObject_Enemy* self,
	unsigned life,
	uint16_t pos_x, uint16_t pos_y, 
	uint16_t collider
);

void Demo2_OnCreate(Demo2_GameObject_Enemy* self);
void Demo2_OnUpdate(Demo2_GameObject_Enemy* self);
void Demo2_OnDestroy(Demo2_GameObject_Enemy* self);
void Demo2_OnRender(Demo2_GameObject_Enemy* self, Color** screen);

#endif
