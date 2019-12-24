#include "RoyalCoin_GameObject_Bullet.h"

#include "Img_RoyalCoin.h"
#include "mygpio.h"

void RoyalCoin_Init(
	RoyalCoin_GameObject_Bullet* self,
	uint16_t pos_x, uint16_t pos_y,
	float speed_x, float speed_y
){
	GameObject_Bullet_Init(
		&self->base,
		22, 75, // damage
		pos_x, pos_y,
		speed_x, speed_y,
		1,
		1, 2,
		Img_RoyalCoin,
		false
	);
}

void RoyalCoin_OnCreate(RoyalCoin_GameObject_Bullet* self)
{
	GameObject_Bullet_OnCreate(&self->base);
}

void RoyalCoin_OnUpdate(RoyalCoin_GameObject_Bullet* self)
{
	GameObject_Bullet_OnUpdate(&self->base);
}

void RoyalCoin_OnDestroy(RoyalCoin_GameObject_Bullet* self)
{
	free(self);
}

void RoyalCoin_OnRender(RoyalCoin_GameObject_Bullet* self, Color** screen)
{
	GameObject_Bullet_OnRender(&self->base, screen);
}
