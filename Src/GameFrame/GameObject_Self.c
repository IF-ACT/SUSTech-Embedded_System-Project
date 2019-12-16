#include "GameObject_Self.h"

#include "Time.h"
#include "mygpio.h"

void GameObject_Self_Init(
	GameObject_Self* self,
	unsigned life,
	uint16_t pos_x, uint16_t pos_y, 
	uint16_t collider,
	uint16_t width, uint16_t height,
	Color* img
){
	self->life = life;
	GameObject_Initialize(
		&self->base,
		pos_x, pos_y,
		collider,
		width, height,
		img
	);
}

void GameObject_Self_OnCreate(GameObject_Self* self)
{
	GameObject_OnCreate(&self->base);
}

void GameObject_Self_OnUpdate(GameObject_Self* self)
{
	GameObject_OnUpdate(&self->base);
}

void GameObject_Self_OnDestroy(GameObject_Self* self)
{
	println("self destroyed");
	GameObject_OnDestroy(&self->base);

	free(self);
}

void GameObject_Self_OnRender(GameObject_Self* self, Color** screen)
{
	GameObject_OnRender(&self->base, screen);
}

bool __GameObject_Self_Created(GameObject_Self* self)
{
	return self->base.__created;
}

bool __GameObject_Self_ToDestroy(GameObject_Self* self)
{
	return self->base.__to_destroy;
}
