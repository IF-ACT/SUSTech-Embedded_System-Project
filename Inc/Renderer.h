#ifndef __RENDERER_H
#define __RENDERER_H

#include <stdlib.h>
#include "GameObject.h"

#define TRANSPARENT 0x0000

void Render(GameObject* game_object, Color **screen);

// return a new screen, after calling this, don't use former screen again
Color** Flush(Color **screen);

#endif