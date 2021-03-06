#include "GameObject_Bullet.h"

#include "mygpio.h"

void GameObject_Bullet_Init(
	GameObject_Bullet* self,
	uint16_t ttl, unsigned damage,
	uint16_t pos_x, uint16_t pos_y,
	float speed_x, float speed_y,
	uint16_t collider,
	uint16_t width, uint16_t height,
	Color* img,
	bool is_enemy
){
	GameObject_Initialize(
		&self->base,
		pos_x, pos_y,
		collider,
		width, height,
		img
	);
	self->ttl = ttl;
	self->damage = damage;
	self->base.speed_x = speed_x;
	self->base.speed_y = speed_y;
	self->is_enemy = is_enemy;
}

void inline GameObject_Bullet_OnCreate(GameObject_Bullet* self)
{
	GameObject_OnCreate(&self->base);
}

void inline GameObject_Bullet_OnUpdate(GameObject_Bullet* self)
{
	// printlnf("ttl: %hu", self->ttl);
	// printlnf("location of bullet: %d", self);
	// if (self->base.__to_destroy)
	// 	printlnf("to destroy");
	// printlnf("location of father object: %d", &self->base);
	// if (((GameObject*)self)->__to_destroy)
	// 	printlnf("to destroy");
	
	if (!self->ttl)
		self->base.__to_destroy = true;
	else
		self->ttl -= 1;
	GameObject_OnUpdate(&self->base);
}

void inline GameObject_Bullet_OnRender(GameObject_Bullet* self, Color** screen)
{
	GameObject_OnRender(&self->base, screen);
}

bool inline __GameObject_Bullet_Created(GameObject_Bullet* self)
{
	return __GameObject_Created(&self->base);
}

bool inline __GameObject_Bullet_ToDestroy(GameObject_Bullet* self)
{
	return __GameObject_ToDestroy(&self->base);
}

