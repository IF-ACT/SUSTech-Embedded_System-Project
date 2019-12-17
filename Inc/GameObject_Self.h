#ifndef __GAME_OBJECT_SELF_H
#define __GAME_OBJECT_SELF_H

#include "GameObject.h"

typedef struct GameObject_Self
{
	GameObject base;
	unsigned life;

} GameObject_Self;

void GameObject_Self_Init(
	GameObject_Self* self,
	unsigned life,
	uint16_t pos_x, uint16_t pos_y, 
	uint16_t collider,
	uint16_t width, uint16_t height,
	Color* img
);

void GameObject_Self_OnCreate(GameObject_Self* self);
void GameObject_Self_OnUpdate(GameObject_Self* self);
void GameObject_Self_OnDestroy(GameObject_Self* self);
void GameObject_Self_OnRender(GameObject_Self* self, Color** screen);

bool __GameObject_Self_Created(GameObject_Self* self);
bool __GameObject_Self_ToDestroy(GameObject_Self* self);

#endif
