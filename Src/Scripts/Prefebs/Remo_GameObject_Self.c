#include "Remo_GameObject_Self.h"

#include "Img_TestImages.h"
#include "GameEvent.h"
#include "GameEngine.h"
#include "Renderer.h"
#include "RoyalCoin_GameObject_Bullet.h"
#include "mygpio.h"
#include "Time.h"

void Remo_Init(
	Remo_GameObject_Self* self,
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

	if (Game_KillCount > 20 && self->fire_rank <= 4)
	{
		self->fire_rank++;
		Game_KillCount -= 20;
	}
	// fire
	if (GetTime()%2)
	{
		if (self->fire_rank == 1 || self->fire_rank == 4) // basic
		{
			bullet = malloc(sizeof(RoyalCoin_GameObject_Bullet));
			RoyalCoin_Init(bullet, self->base.base.pos_x, self->base.base.pos_y, 0.0f, -3.5f);
			e = RegistGameEvent(
				bullet,
				RoyalCoin_OnCreate, RoyalCoin_OnUpdate,
				RoyalCoin_OnDestroy, RoyalCoin_OnRender
			);
			Push(&Engine_BulletEvents, e);
		}
		if (self->fire_rank >= 2) // Double bullets
		{
			bullet = malloc(sizeof(RoyalCoin_GameObject_Bullet));
			RoyalCoin_Init(bullet, self->base.base.pos_x - 1, self->base.base.pos_y, 0.0f, -3.5f);
			e = RegistGameEvent(
				bullet,
				RoyalCoin_OnCreate, RoyalCoin_OnUpdate,
				RoyalCoin_OnDestroy, RoyalCoin_OnRender
			);
			Push(&Engine_BulletEvents, e);

			bullet = malloc(sizeof(RoyalCoin_GameObject_Bullet));
			RoyalCoin_Init(bullet, self->base.base.pos_x + 1, self->base.base.pos_y, 0.0f, -3.5f);
			e = RegistGameEvent(
				bullet,
				RoyalCoin_OnCreate, RoyalCoin_OnUpdate,
				RoyalCoin_OnDestroy, RoyalCoin_OnRender
			);
			Push(&Engine_BulletEvents, e);

			if (self->fire_rank >= 3) // Side bullets
			{
				bullet = malloc(sizeof(RoyalCoin_GameObject_Bullet));
				RoyalCoin_Init(bullet, self->base.base.pos_x - 1, self->base.base.pos_y, -1.0f, -3.0f);
				e = RegistGameEvent(
					bullet,
					RoyalCoin_OnCreate, RoyalCoin_OnUpdate,
					RoyalCoin_OnDestroy, RoyalCoin_OnRender
				);
				Push(&Engine_BulletEvents, e);

				bullet = malloc(sizeof(RoyalCoin_GameObject_Bullet));
				RoyalCoin_Init(bullet, self->base.base.pos_x + 1, self->base.base.pos_y, 1.0f, -3.0f);
				e = RegistGameEvent(
					bullet,
					RoyalCoin_OnCreate, RoyalCoin_OnUpdate,
					RoyalCoin_OnDestroy, RoyalCoin_OnRender
				);
				Push(&Engine_BulletEvents, e);
			}

			if (self->fire_rank == 4) // Full side
			{
				bullet = malloc(sizeof(RoyalCoin_GameObject_Bullet));
				RoyalCoin_Init(bullet, self->base.base.pos_x - 2, self->base.base.pos_y, -1.2f, -2.8f);
				e = RegistGameEvent(
					bullet,
					RoyalCoin_OnCreate, RoyalCoin_OnUpdate,
					RoyalCoin_OnDestroy, RoyalCoin_OnRender
				);
				Push(&Engine_BulletEvents, e);

				bullet = malloc(sizeof(RoyalCoin_GameObject_Bullet));
				RoyalCoin_Init(bullet, self->base.base.pos_x + 2, self->base.base.pos_y, 1.2f, -2.8f);
				e = RegistGameEvent(
					bullet,
					RoyalCoin_OnCreate, RoyalCoin_OnUpdate,
					RoyalCoin_OnDestroy, RoyalCoin_OnRender
				);
				Push(&Engine_BulletEvents, e);
			}
		}
	}	


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
