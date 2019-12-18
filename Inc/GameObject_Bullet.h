#ifndef __GAME_OBJECT_BULLET_H
#define __GAME_OBJECT_BULLET_H

#include "GameObject.h"

typedef struct GameObject_Bullet
{
	GameObject base;
	unsigned damage;
	uint16_t ttl;
	bool is_enemy;

} GameObject_Bullet;

void GameObject_Bullet_Init(
	GameObject_Bullet* self,
	uint16_t ttl, unsigned damage,
	uint16_t pos_x, uint16_t pos_y,
	float speed_x, float speed_y,
	uint16_t collider,
	uint16_t width, uint16_t height,
	Color* img,
	bool is_enemy
);

void GameObject_Bullet_OnCreate(GameObject_Bullet* self);
void GameObject_Bullet_OnUpdate(GameObject_Bullet* self);
void GameObject_Bullet_OnDestroy(GameObject_Bullet* self);
void GameObject_Bullet_OnRender(GameObject_Bullet* self, Color** screen);

bool __GameObject_Bullet_Created(GameObject_Bullet* self);
bool __GameObject_Bullet_ToDestroy(GameObject_Bullet* self);

#endif
