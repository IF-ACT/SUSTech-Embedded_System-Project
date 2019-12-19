#include "Flandre_GameObject_Enemy.h"

#include "Renderer.h"
#include "Time.h"
#include "GameEngine.h"
#include "GameEvent.h"
#include "BasicBullet_GameObject_Bullet.h"
#include "Img_Flandre.h"
#include "Img_Leavatain.h"
#include "Img_KagomeKagome.h"

#define Flandre_MAX_LIFE 80000

void inline __Flandre_Normal(Flandre_GameObject_Enemy* self)
{
	
}

void inline __Flandre_Leavatain(Flandre_GameObject_Enemy* self)
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

		self->base.base.speed_x = 0.25f;

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

		self->base.base.speed_x = -0.25f;

		if (self->base.base.pos_x <= self->aim)
			self->skill_param = 0;
	}
}

void inline __Flandre_KagomeKagome(Flandre_GameObject_Enemy* self)
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
	
	for (; i <= i_max; i++)
	{
		if (!(i%16 + self->aim) || !((self->skill_param - i)%16))
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

	self->skill_param += 8;
}

void inline __Flandre_StarbowBreak(Flandre_GameObject_Enemy* self)
{
	
}

void inline __Flandre_Catadioptric(Flandre_GameObject_Enemy* self)
{

}

Flandre_GameObject_Enemy* Flandre_Init()
{
	Flandre_GameObject_Enemy* self = malloc(sizeof(Flandre_GameObject_Enemy));
	GameObject_Enemy_Init(
		self, Flandre_MAX_LIFE,
		__WIDTH/2, 15,
		4, 8, 8, Img_Flandre
	);
	self->create_time = GetTime();
	self->skill_param = 0;
	self->skill = 0;
}

void Flandre_OnCreate(Flandre_GameObject_Enemy* self)
{
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

void Flandre_OnUpdate(Flandre_GameObject_Enemy* self);
void Flandre_OnDestroy(Flandre_GameObject_Enemy* self);
void Flandre_OnRender(Flandre_GameObject_Enemy* self, Color** screen);
