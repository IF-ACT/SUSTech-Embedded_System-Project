#ifndef __GAME_OBJECT_SELF_H
#define __GAME_OBJECT_SELF_H

#include "GameObject.h"

typedef struct GameObject_Self
{
	GameObject base;
	unsigned life;

} GameObject_Self;

void GameObject_Self_OnCreate(GameObject_Self* self);
void GameObject_Self_OnUpdate(GameObject_Self* self);
void GameObject_Self_OnDestroy(GameObject_Self* self);
void GameObject_Self_OnRender(GameObject_Self* self, Color** screen);

bool __GameObject_Self_Created(GameObject_Self* self);
bool __GameObject_Self_ToDestroy(GameObject_Self* self);

#endif