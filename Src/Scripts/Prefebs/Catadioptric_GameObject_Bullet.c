#include "Catadioptric_GameObject_Bullet.h"

#include "Renderer.h"

Color Img_Catadioptric[2][2] = {
	{GREEN, GREEN},
	{GREEN, GREEN}
};

Catadioptric_GameObject_Bullet* Catadioptric_Init(
	uint16_t pos_x, uint16_t pos_y,
	float speed_x, float speed_y
){
	Catadioptric_GameObject_Bullet* self = malloc(sizeof(Catadioptric_GameObject_Bullet));
	GameObject_Bullet_Init(
		&self->base, 30, 5, pos_x, pos_y, speed_x, speed_y,
		1, 2, 2, Img_Catadioptric, true
	);
	return self;
}

void Catadioptric_OnCreate(Catadioptric_GameObject_Bullet* self)
{
	GameObject_Bullet_OnCreate(&self->base);
}

void Catadioptric_OnUpdate(Catadioptric_GameObject_Bullet* self)
{
	if (self->base.base.pos_x < 0 || self->base.base.pos_x > __WIDTH - 1)
		self->base.base.speed_x = - self->base.base.speed_x;
	if (self->base.base.pos_y < 0 || self->base.base.pos_y > __HEIGHT - 1)
		self->base.base.speed_y = - self->base.base.speed_y;

	GameObject_Bullet_OnUpdate(&self->base);
}

void Catadioptric_OnDestroy(Catadioptric_GameObject_Bullet* self)
{
	free(self);
}

void Catadioptric_OnRender(Catadioptric_GameObject_Bullet* self, Color** screen)
{
	GameObject_Bullet_OnRender(&self->base, screen);
}
