#include "Goast_GameObject_Enemy.h"

#include "GameEngine.h"
#include "Img_Goast.h"
#include "Time.h"
#include "BasicBullet_GameObject_Bullet.h"
#include "Renderer.h"

#define MAX(a, b) (a>b?a:b)

Color Goast_Img_Bullet[2][2] = {
	{GREEN, GRAYBLUE},
	{GRAYBLUE, GREEN}
};

Goast_GameObject_Enemy* Goast_Init(
	uint16_t pos_x, uint16_t pos_y,
	bool move_dir
){
	Goast_GameObject_Enemy* self = malloc(sizeof(Goast_GameObject_Enemy));
	GameObject_Enemy_Init(self, 1, pos_x, pos_y, 2, 4, 4, Img_Goast);
	self->create_time = GetTime();
	self->move_dir = move_dir;
	return self;
}

void Goast_OnCreate(Goast_GameObject_Enemy* self)
{
	GameObject_Enemy_OnCreate(&self->base);
}

void Goast_OnUpdate(Goast_GameObject_Enemy* self)
{
	if (!(GetTime()-self->create_time)%10)
	{
		float gx = ((GameObject*)Engine_SelfEvent->game_object)->pos_x;
		float gy = ((GameObject*)Engine_SelfEvent->game_object)->pos_y;
		
		BasicBullet_GameObject_Bullet* bullet = BasicBullet_Init(
			35, 10, self->base.base.pos_x, self->base.base.pos_y,
			(gx - self->base.base.pos_x) * 0.1f,
			(gy - self->base.base.pos_y) * 0.1f,
			1, 2, 2, Goast_Img_Bullet, true
		);
		GameEvent* e = RegistGameEvent(
			bullet, BasicBullet_OnCreate, BasicBullet_OnUpdate,
			BasicBullet_OnDestroy, BasicBullet_OnRender
		);
		Push(&Engine_BulletEvents, e);
	}

	if (!self->move_dir)
	{
		self->base.base.speed_x = - ((GetTime() - self->create_time)%5) * 0.2f;
		self->base.base.speed_y = ((GetTime() - self->create_time) % 3) * 0.2f;
		if (self->base.base.pos_x < 0)
			self->move_dir = 1;
	}
	else
	{
		self->base.base.speed_x = ((GetTime() - self->create_time) % 5) * 0.2f;
		self->base.base.speed_y = - ((GetTime() - self->create_time)%3) * 0.2f;
		if (self->base.base.pos_x >= __WIDTH)
			self->move_dir = 0;
	}

	GameObject_Enemy_OnUpdate(&self->base);
}

void Goast_OnDestroy(Goast_GameObject_Enemy* self)
{
	free(self);
}

void Goast_OnRender(Goast_GameObject_Enemy* self, Color** screen)
{
	GameObject_Enemy_OnRender(&self->base, screen);
}
