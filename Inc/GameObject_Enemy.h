#ifndef __GAME_OBJECT_ENEMY_H
#define __GAME_OBJECT_ENEMY_H

#include "GameObject.h"

typedef struct GameObject_Enemy
{
	GameObject base;
	unsigned life;

} GameObject_Enemy;

GameObject* Enemy_GetBase(GameObject_Enemy* self);

#endif