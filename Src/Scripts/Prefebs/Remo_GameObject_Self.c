#include "Remo_GameObject_Self.h"

#include "Img_TestImages.h"
#include "GameEvent.h"
#include "GameEngine.h"
#include "Renderer.h"
#include "RoyalCoin_GameObject_Bullet.h"
#include "mygpio.h"

void Remo_Init(
	// 指向自身的指针
	Remo_GameObject_Self* self,
	// 初始横纵坐标
	uint16_t pos_x, uint16_t pos_y
){
	GameObject_Self_Init(
		&self->base,
		1,
		pos_x, pos_y,
		1,
		4, 4,
		Img_GreenBlock_4x4
	);
	self->fire_rank = 1;
}

void Remo_OnCreate(Remo_GameObject_Self* self)
{
	GameObject_Self_OnCreate(&self->base);
}

void Remo_OnUpdate(Remo_GameObject_Self* self)
{
	RoyalCoin_GameObject_Bullet* bullet;
	GameEvent* e;

	if (Game_KillCount > 20 && self->fire_rank <= 5)
	{
		self->fire_rank++;
		Game_KillCount -= 20;
	}
	// fire
	switch (self->fire_rank)
	{
	case 1:
		bullet = malloc(sizeof(RoyalCoin_GameObject_Bullet));
		RoyalCoin_Init(bullet, self->base.base.pos_x, self->base.base.pos_y, 0.0f, -3.5f);
		e = RegistGameEvent(
			bullet,
			RoyalCoin_OnCreate, RoyalCoin_OnUpdate,
			RoyalCoin_OnDestroy, RoyalCoin_OnRender
		);
		Push(&Engine_BulletEvents, e);
		break;
	
	default:
		break;
	}
	bullet = NULL;
	e = NULL;
	GameObject_Self_OnUpdate(&self->base);
}

void Remo_OnDestroy(Remo_GameObject_Self* self)
{
	if (!Game_Life)
	{
		free(self);
	}
	else
	{
		self->fire_rank = 1;
	}
}

void Remo_OnRender(Remo_GameObject_Self* self, Color** screen)
{
	GameObject_Self_OnRender(&self->base, screen);
}
