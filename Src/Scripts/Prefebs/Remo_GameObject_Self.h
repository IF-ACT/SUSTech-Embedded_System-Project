#ifndef __REMO_GAMEOBJECT_SELF_H
#define __REMO_GAMEOBJECT_SELF_H

#include "GameObject_Self.h"

typedef struct Remo_GameObject_Self
{
	GameObject_Self base;
	unsigned fire_rank;

} Remo_GameObject_Self;

void Remo_Init(
	// 指向自身的指针
	Remo_GameObject_Self* self,
	// 初始横纵坐标
	uint16_t pos_x, uint16_t pos_y
);

void Remo_OnCreate(Remo_GameObject_Self* self);
void Remo_OnUpdate(Remo_GameObject_Self* self);
void Remo_OnDestroy(Remo_GameObject_Self* self);
void Remo_OnRender(Remo_GameObject_Self* self, Color** screen);

#endif
