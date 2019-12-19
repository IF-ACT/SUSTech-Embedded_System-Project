#ifndef __BASICBULLET_GAMEOBJECT_BULLET_H
#define __BASICBULLET_GAMEOBJECT_BULLET_H

#include "GameObject_Bullet.h"

typedef struct BasicBullet_GameObject_Bullet
{
	GameObject_Bullet base;

} BasicBullet_GameObject_Bullet;

BasicBullet_GameObject_Bullet* BasicBullet_Init(
	uint16_t ttl, unsigned damage,
	uint16_t pos_x, uint16_t pos_y,
	float speed_x, float speed_y,
	uint16_t collider,
	uint16_t width, uint16_t height,
	Color* img,
	bool is_enemy
);

void BasicBullet_OnCreate(BasicBullet_GameObject_Bullet* self);
void BasicBullet_OnUpdate(BasicBullet_GameObject_Bullet* self);
void BasicBullet_OnDestroy(BasicBullet_GameObject_Bullet* self);
void BasicBullet_OnRender(BasicBullet_GameObject_Bullet* self, Color** screen);

#endif