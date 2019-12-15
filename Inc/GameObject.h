#ifndef __GAME_OBJECT_H
#define __GAME_OBJECT_H

// abstruct class

#include <stdbool.h>
#include <stdlib.h>
#include "lcd.h"

typedef struct GameObject
{
	float speed_x;
	float speed_y;
	// center x
	uint16_t pos_x;
	// center y
	uint16_t pos_y;
	// size of collider
	uint16_t collider;
	// image width
	uint16_t width;
	// image height
	uint16_t height;
	Color **img;

	bool __created;
	bool __to_destroy;

} GameObject;

void GameObject_Initialize
(
	GameObject* self, uint16_t pos_x, uint16_t pos_y, 
	uint16_t collider, uint16_t width, uint16_t height,
	Color** img
);
void GameObject_OnCreate(GameObject* self);
void GameObject_OnUpdate(GameObject* self);
void GameObject_OnDestroy(GameObject* self);
void GameObject_OnRender(GameObject* self, Color** screen);

#endif
