#include "GameObject_Self.h"

#include "Time.h"
#include "mygpio.h"
#include "GameEngine.h"
#include "Renderer.h"

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

void inline GameObject_Self_OnCreate(GameObject_Self* self)
{
	GameObject_OnCreate(&self->base);
}

void inline GameObject_Self_OnUpdate(GameObject_Self* self)
{
	if (Engine_KeyPressed > 0)
		self->base.speed_x = -0.7f;
	else if (Engine_KeyPressed < 0)
		self->base.speed_x = 0.7f;
	else
		self->base.speed_x = 0.0f;

	self->base.pos_x += self->base.speed_x * delta_time;
	
	if (self->base.pos_x < 0)
		self->base.pos_x = 0;
	else if (self->base.pos_x >= __WIDTH)
		self->base.pos_x = __WIDTH - 1;
}

void inline GameObject_Self_OnRender(GameObject_Self* self, Color** screen)
{
	GameObject_OnRender(&self->base, screen);
}

bool inline __GameObject_Self_Created(GameObject_Self* self)
{
	return self->base.__created;
}

bool inline __GameObject_Self_ToDestroy(GameObject_Self* self)
{
	return self->base.__to_destroy;
}
