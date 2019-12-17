#include "GameObject.h"

#include "Renderer.h"
#include "Time.h"

void GameObject_Initialize
(
	GameObject* self, uint16_t pos_x, uint16_t pos_y, 
	uint16_t collider, uint16_t width, uint16_t height,
	Color* img
){
	self->speed_x = 0.0f;
	self->speed_y = 0.0f;
	self->pos_x = (float)pos_x;
	self->pos_y = (float)pos_y;
	self->collider = collider;
	self->width = width;
	self->height = height;
	self->img = img;
	self->__created = false;
	self->__to_destroy = false;
}

void inline GameObject_OnCreate(GameObject* self)
{
	self->__created = true;
}

void inline GameObject_OnUpdate(GameObject* self)
{
	self->pos_x += self->speed_x * delta_time;
	self->pos_y += self->speed_y * delta_time;
}

void inline GameObject_OnRender(GameObject* self, Color** screen)
{
	Render(self, screen);
}
