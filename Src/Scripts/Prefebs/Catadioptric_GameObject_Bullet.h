#ifndef __CATADOIPTRIC_GAMEOBJECT_H
#define __CATADOIPTRIC_GAMEOBJECT_H

#include "GameObject_Bullet.h"

typedef struct Catadioptric_GameObject_Bullet
{
	GameObject_Bullet base;

} Catadioptric_GameObject_Bullet;

Catadioptric_GameObject_Bullet* Catadioptric_Init(
	uint16_t pos_x, uint16_t pos_y,
	float speed_x, float speed_y
);

void Catadioptric_OnCreate(Catadioptric_GameObject_Bullet* self);
void Catadioptric_OnUpdate(Catadioptric_GameObject_Bullet* self);
void Catadioptric_OnDestroy(Catadioptric_GameObject_Bullet* self);
void Catadioptric_OnRender(Catadioptric_GameObject_Bullet* self, Color** screen);

#endif