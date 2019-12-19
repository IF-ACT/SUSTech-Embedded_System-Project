#include "StarbowBreak_GameObject_Bullet.h"

Color Img_StarbowBreak[2][2] = {
	{BLUE, BLUE},
	{BLUE, BLUE}
};

StarbowBreak_GameObject_Bullet* StarbowBreak_Init(
	uint16_t pos_x, uint16_t pos_y,
	float speed_x, float speed_y,
	bool* active
){
	StarbowBreak_GameObject_Bullet* self = malloc(sizeof(StarbowBreak_GameObject_Bullet));
	GameObject_Bullet_Init(
		self, 20, 5, pos_x, pos_y, speed_x, speed_y,
		1, 2, 2, Img_StarbowBreak, true
	);
	self->active = active;
	return self;
}

void StarbowBreak_OnCreate(StarbowBreak_GameObject_Bullet* self)
{
	GameObject_Bullet_OnCreate(&self->base);
}

void StarbowBreak_OnUpdate(StarbowBreak_GameObject_Bullet* self)
{
	if (*self->active)
		GameObject_Bullet_OnUpdate(&self->base);
}

void StarbowBreak_OnDestroy(StarbowBreak_GameObject_Bullet* self)
{
	free(self);
}

void StarbowBreak_OnRender(StarbowBreak_GameObject_Bullet* self, Color** screen)
{
	GameObject_Bullet_OnRender(&self->base, screen);
}
