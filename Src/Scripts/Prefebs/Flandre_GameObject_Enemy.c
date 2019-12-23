#include "Flandre_GameObject_Enemy.h"

#include "Renderer.h"
#include "Time.h"
#include "GameEngine.h"
#include "GameEvent.h"
#include "BasicBullet_GameObject_Bullet.h"
#include "Catadioptric_GameObject_Bullet.h"
#include "Img_Flandre.h"
#include "Img_Leavatain.h"
#include "Img_KagomeKagome.h"
#include "Img_BigBullet.h"

#include "mygpio.h"
#include "Random.h"

#define Flandre_MAX_LIFE 40000

void __Flandre_Normal(Flandre_GameObject_Enemy* self)
{
	if (!(GetTime()%8))
	{
		BasicBullet_GameObject_Bullet* bullet;
		GameEvent* e;
		bullet = BasicBullet_Init(
			100, 12, self->base.base.pos_x, self->base.base.pos_x,
			((float)os_rand())/__UINT32_MAX__*3 - 0.5f, ((float)os_rand())/__UINT32_MAX__*3 - 0.5f,
			5, 10, 10, Img_BigBullet, true
		);
		e = RegistGameEvent(
			bullet, BasicBullet_OnCreate, BasicBullet_OnUpdate,
			BasicBullet_OnDestroy, BasicBullet_OnRender
		);
		Push(&Engine_BulletEvents, e);
	}
}

void __Flandre_Leavatain(Flandre_GameObject_Enemy* self)
{
	BasicBullet_GameObject_Bullet* bullet;
	GameEvent* e;

	// move left
	if (self->skill_param == 0)
	{
		self->base.base.speed_x = -0.6f;

		if (self->base.base.pos_x < 0)
		{
			self->base.base.pos_x = 0;
			self->skill_param = 1;
			self->aim = __WIDTH/2 + __WIDTH/4;
		}
		else
		{
			__Flandre_Normal(self);
		}
	}
	// Leavatain ->
	else if (self->skill_param == 1)
	{
		for (uint16_t i = self->base.base.pos_y; i <= __HEIGHT; i += 4)
		{
			bullet = BasicBullet_Init(
				1, 8, self->base.base.pos_x, i, 0, 0, 2, 4, 4, Img_Leavatain, true
			);
			e = RegistGameEvent(
				bullet, BasicBullet_OnCreate, BasicBullet_OnUpdate,
				BasicBullet_OnDestroy, BasicBullet_OnRender
			);
			Push(&Engine_BulletEvents, e);
		}

		self->base.base.speed_x = 0.75f;

		if (self->base.base.pos_x >= self->aim)
			self->skill_param = 2;
	}
	// move rigtht
	else if (self->skill_param == 2)
	{
		self->base.base.speed_x = 0.6f;

		if (self->base.base.pos_x >= __WIDTH)
		{
			self->base.base.pos_x = __WIDTH - 1;
			self->skill_param = 3;
			self->aim = __WIDTH/4;
		}
		else
		{
			__Flandre_Normal(self);
		}
		
	}
	// Leavatain <-
	else if (self->skill_param == 3)
	{
		for (uint16_t i = self->base.base.pos_y; i <= __HEIGHT; i += 4)
		{
			bullet = BasicBullet_Init(
				1, 8, self->base.base.pos_x, i, 0, 0, 2, 4, 4, Img_Leavatain_R, true
			);
			e = RegistGameEvent(
				bullet, BasicBullet_OnCreate, BasicBullet_OnUpdate,
				BasicBullet_OnDestroy, BasicBullet_OnRender
			);
			Push(&Engine_BulletEvents, e);
		}

		self->base.base.speed_x = -0.75f;

		if (self->base.base.pos_x <= self->aim)
			self->skill_param = 0;
	}
}

void __Flandre_KagomeKagome(Flandre_GameObject_Enemy* self)
{
	uint16_t i;
	uint16_t i_max;
	BasicBullet_GameObject_Bullet* bullet;
	GameEvent* e;

	if (self->skill_param >= __WIDTH + __HEIGHT - 2)
	{
		self->skill_param = 0;
	}

	if (self->skill_param <= __WIDTH - 1)
	{
		i = 0;
		i_max = self->skill_param;
	}
	else if (self->skill_param <= __HEIGHT - 1)
	{
		i = 0;
		i_max = __WIDTH - 1;
	}
	else
	{
		i = self->skill_param - __HEIGHT + 1;
		i_max = __WIDTH - 1;
	}
	
	for (; i <= i_max; i += 1)
	{
		if (!(i%19))
		{
			bullet = BasicBullet_Init(
				10, 10, i, self->skill_param - i,
				0, 0, 1, 3, 3, Img_KagomeKagome, true
			);
			e = RegistGameEvent(
				bullet, BasicBullet_OnCreate, BasicBullet_OnUpdate,
				BasicBullet_OnDestroy, BasicBullet_OnRender
			);
			Push(&Engine_BulletEvents, e);
		}
	}

	self->skill_param += 4;
}

void __Flandre_StarbowBreak(Flandre_GameObject_Enemy* self)
{
	
}

void __Flandre_Catadioptric(Flandre_GameObject_Enemy* self)
{
	Catadioptric_GameObject_Bullet* bullet;
	GameEvent* e;
	bullet = Catadioptric_Init(
		self->base.base.pos_x, self->base.base.pos_x,
		((float)os_rand())/__UINT32_MAX__*8 - 2.0f, ((float)os_rand())/__UINT32_MAX__*8 - 2.0f
	);
	e = RegistGameEvent(
		bullet, Catadioptric_OnCreate, Catadioptric_OnUpdate,
		Catadioptric_OnDestroy, Catadioptric_OnRender
	);
	Push(&Engine_BulletEvents, e);
}

Flandre_GameObject_Enemy* Flandre_Init()
{
	Flandre_GameObject_Enemy* self = malloc(sizeof(Flandre_GameObject_Enemy));
	GameObject_Enemy_Init(
		&self->base, Flandre_MAX_LIFE,
		__WIDTH/2, 25,
		10, 20, 20, Img_Flandre
	);
	self->create_time = GetTime();
	self->skill_param = 0;
	self->skill = 0;
	return self;
}

void Flandre_OnCreate(Flandre_GameObject_Enemy* self)
{
	GameObject_Enemy_OnCreate(&self->base);
}

void Flandre_OnUpdate(Flandre_GameObject_Enemy* self)
{
	if (self->base.life > 30000)
	{
		self->skill = 0;
	}
	else if (self->base.life > 20000)
	{
		if (self->skill != 1)
		{
			self->skill = 1;
			self->skill_param = 0;
		}
	}
	else if (self->base.life > 10000)
	{
		if (self->skill != 2)
		{
			self->skill = 2;
			self->skill_param = 0;
			self->base.base.pos_x = __WIDTH/2;
			self->base.base.pos_y = 25;
			self->base.base.speed_x = 0;
		}
	}
	else
	{
		if (self->skill != 4)
		{
			self->skill = 4;
			self->skill_param = 0;
		}
	}
	
	switch (self->skill)
	{
	case 0:
		self->skill_param = 0;
		__Flandre_Normal(self);
		break;
	case 1:
		__Flandre_Leavatain(self);
		break;
	case 2:
		__Flandre_Normal(self);
		__Flandre_KagomeKagome(self);
		break;
	case 3:
		__Flandre_StarbowBreak(self);
		break;
	case 4:
		__Flandre_Catadioptric(self);
		break;
	default:
		break;
	}
	GameObject_Enemy_OnUpdate(&self->base);
}

void Flandre_OnDestroy(Flandre_GameObject_Enemy* self)
{
	free(self);
}

void Flandre_OnRender(Flandre_GameObject_Enemy* self, Color** screen)
{
	GameObject_Enemy_OnRender(&self->base, screen);
}
