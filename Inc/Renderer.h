#ifndef __RENDERER_H
#define __RENDERER_H

#include <stdlib.h>
#include "GameObject.h"

#define TRANSPARENT 0x0000

#define __WIDTH 76
#define __HEIGHT 96
#define __SCALE 3

void Render(GameObject* game_object, Color **screen);

void Render_Img(float pos_x, float pos_y, uint16_t width, uint16_t height, Color* img, Color** screen);

Color** InitScreen(Color** screen);

// return a new screen, after calling this, don't use former screen again
Color** Flush(Color **screen);

#endif