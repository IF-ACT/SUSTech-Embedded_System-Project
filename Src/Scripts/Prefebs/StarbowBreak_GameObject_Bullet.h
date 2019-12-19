#ifndef __STARBOWBREAK_GAMEOBJECT_BULLET_H
#define __STARBOWBREAK_GAMEOBJECT_BULLET_H

#include "GameObject_Bullet.h"

typedef struct StarbowBreak_GameObject_Bullet
{
	GameObject_Bullet base;
	bool* active;

} StarbowBreak_GameObject_Bullet;

StarbowBreak_GameObject_Bullet* StarbowBreak_Init(
	uint16_t pos_x, uint16_t pos_y,
	float speed_x, float speed_y,
	bool* active
);

void StarbowBreak_OnCreate(StarbowBreak_GameObject_Bullet* self);
void StarbowBreak_OnUpdate(StarbowBreak_GameObject_Bullet* self);
void StarbowBreak_OnDestroy(StarbowBreak_GameObject_Bullet* self);
void StarbowBreak_OnRender(StarbowBreak_GameObject_Bullet* self, Color** screen);

#endif