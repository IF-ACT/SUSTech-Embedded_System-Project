#include "BasicBullet_GameObject_Bullet.h"

BasicBullet_GameObject_Bullet* BasicBullet_Init(
	uint16_t ttl, unsigned damage,
	uint16_t pos_x, uint16_t pos_y,
	float speed_x, float speed_y,
	uint16_t collider,
	uint16_t width, uint16_t height,
	Color* img,
	bool is_enemy
){
	BasicBullet_GameObject_Bullet* self = malloc(sizeof(BasicBullet_GameObject_Bullet));
	GameObject_Bullet_Init(
		&self->base, ttl, damage, pos_x, pos_y, speed_x, speed_y,
		collider, width, height, img, is_enemy
	);
	return self;
}

void BasicBullet_OnCreate(BasicBullet_GameObject_Bullet* self)
{
	GameObject_Bullet_OnCreate(&self->base);
}

void BasicBullet_OnUpdate(BasicBullet_GameObject_Bullet* self)
{
	GameObject_Bullet_OnUpdate(&self->base);
}

void BasicBullet_OnDestroy(BasicBullet_GameObject_Bullet* self)
{
	free(self);
}

void BasicBullet_OnRender(BasicBullet_GameObject_Bullet* self, Color** screen)
{
	GameObject_Bullet_OnRender(&self->base, screen);
}
