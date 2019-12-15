#ifndef __GAME_OBJECT_BULLET_H
#define __GAME_OBJECT_BULLET_H

#include "GameObject.h"

typedef struct GameObject_Bullet
{
	GameObject base;

} GameObject_Bullet;

GameObject* Bullet_GetBase(GameObject_Bullet* self);

#endif