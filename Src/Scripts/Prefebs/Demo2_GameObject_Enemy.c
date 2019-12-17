#include "Demo2_GameObject_Enemy.h"

void Demo2_Init(
	Demo2_GameObject_Enemy* self,
	unsigned life,
	uint16_t pos_x, uint16_t pos_y, 
	uint16_t collider,
	uint16_t width, uint16_t height,
	Color* img
){
	GameObject_Enemy_Init(
		&self->base,
		life,
		pos_x, pos_y,
		collider,
		width, height,
		img
	);
}

void Demo2_OnCreate(Demo2_GameObject_Enemy* self)
{
	self->base.base.speed_x = 1.0f;
	GameObject_Enemy_OnCreate(&self->base);
}

void Demo2_OnUpdate(Demo2_GameObject_Enemy* self)
{
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

bool __Demo2_Created(Demo2_GameObject_Enemy* self)
{
	return __GameObject_Enemy_Created(&self->base);
}

bool __Demo2_ToDestroy(Demo2_GameObject_Enemy* self)
{
	return __GameObject_Enemy_ToDestroy(&self->base);
}
