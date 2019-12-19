#ifndef __GOAST_GAMEOBJECT_ENEMY_H
#define __GOAST_GAMEOBJECT_ENEMY_H

#include "GameObject_Enemy.h"

typedef struct Goast_GameObject_Enemy
{
	GameObject_Enemy base;
	int create_time;
	int move_dir;

} Goast_GameObject_Enemy;

Goast_GameObject_Enemy* Goast_Init(
	uint16_t pos_x, uint16_t pos_y,
	bool move_dir
);

void Goast_OnCreate(Goast_GameObject_Enemy* self);
void Goast_OnUpdate(Goast_GameObject_Enemy* self);
void Goast_OnDestroy(Goast_GameObject_Enemy* self);
void Goast_OnRender(Goast_GameObject_Enemy* self, Color** screen);

#endif