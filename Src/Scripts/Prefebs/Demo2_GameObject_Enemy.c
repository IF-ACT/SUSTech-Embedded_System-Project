#include "Demo2_GameObject_Enemy.h"

#include "mygpio.h"
#include "Time.h"
#include "BasicBullet_GameObject_Bullet.h"
#include "GameEngine.h"

Color Img_RedBlock_4x4[4][4] = {
	{RED, RED, RED, RED},
	{RED, RED, RED, RED},
	{RED, RED, RED, RED},
	{RED, RED, RED, RED}
};

void Demo2_Init(
	Demo2_GameObject_Enemy* self,
	unsigned life,
	uint16_t pos_x, uint16_t pos_y, 
	uint16_t collider
){
	GameObject_Enemy_Init(
		&self->base,
		life,
		pos_x, pos_y,
		collider,
		4, 4,
		Img_RedBlock_4x4
	);
}

void Demo2_OnCreate(Demo2_GameObject_Enemy* self)
{
	println("Demo2 create");
	GameObject_Enemy_OnCreate(&self->base);
}

void Demo2_OnUpdate(Demo2_GameObject_Enemy* self)
{
	if (!(GetTime()%20))
	{
		BasicBullet_GameObject_Bullet* bullet;
		GameEvent* e;
		bullet = BasicBullet_Init(50, 5, self->base.base.pos_x, self->base.base.pos_y, 0, 1.5, 1, 2, 2, Img_RedBlock_4x4, true);
		e = RegistGameEvent(bullet, BasicBullet_OnCreate, BasicBullet_OnUpdate, BasicBullet_OnDestroy, BasicBullet_OnRender);
		Push(&Engine_BulletEvents, e);
	}

	GameObject_Enemy_OnUpdate(&self->base);
}

void Demo2_OnDestroy(Demo2_GameObject_Enemy* self)
{
	free(self);
}

void Demo2_OnRender(Demo2_GameObject_Enemy* self, Color** screen)
{
	GameObject_Enemy_OnRender(&self->base, screen);
}
