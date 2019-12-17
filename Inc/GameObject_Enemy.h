#ifndef __GAME_OBJECT_ENEMY_H
#define __GAME_OBJECT_ENEMY_H

#include "GameObject.h"

typedef struct GameObject_Enemy
{
	GameObject base;
	unsigned life;

} GameObject_Enemy;

void GameObject_Enemy_Init(
	GameObject_Enemy* self,
	unsigned life,
	uint16_t pos_x, uint16_t pos_y, 
	uint16_t collider,
	uint16_t width, uint16_t height,
	Color* img
);

void GameObject_Enemy_OnCreate(GameObject_Enemy* self);
void GameObject_Enemy_OnUpdate(GameObject_Enemy* self);
void GameObject_Enemy_OnDestroy(GameObject_Enemy* self);
void GameObject_Enemy_OnRender(GameObject_Enemy* self, Color** screen);

bool __GameObject_Enemy_Created(GameObject_Enemy* self);
bool __GameObject_Enemy_ToDestroy(GameObject_Enemy* self);

#endif
