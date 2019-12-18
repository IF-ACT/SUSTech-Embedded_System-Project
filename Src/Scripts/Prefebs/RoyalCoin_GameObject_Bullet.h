#ifndef __ROYALCOIN_GAMEOBJECT_BULLET_H
#define __ROYALCOIN_GAMEOBJECT_BULLET_H

#include "GameObject_Bullet.h"

typedef struct RoyalCoin_GameObject_Bullet
{
	GameObject_Bullet base;

} RoyalCoin_GameObject_Bullet;

void RoyalCoin_Init(
	RoyalCoin_GameObject_Bullet* self,
	uint16_t pos_x, uint16_t pos_y,
	float speed_x, float speed_y
);

void RoyalCoin_OnCreate(RoyalCoin_GameObject_Bullet* self);
void RoyalCoin_OnUpdate(RoyalCoin_GameObject_Bullet* self);
void RoyalCoin_OnDestroy(RoyalCoin_GameObject_Bullet* self);
void RoyalCoin_OnRender(RoyalCoin_GameObject_Bullet* self, Color** screen);

#endif