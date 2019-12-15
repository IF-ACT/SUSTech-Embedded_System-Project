#ifndef __GAME_ENGINE_H
#define __GAME_ENGINE_H

#include "LinkedList.h"
#include "lcd.h"

Color **screen;

LinkedList objects;

LinkedList UI;

void GameEngineLoop();

#endif