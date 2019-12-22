#ifndef __IMG_BIGBULLET_H
#define __IMG_BIGBULLET_H

#include "lcd.h"

#define a0         	 0x0000
#define a1         	 0x89c7
#define a2       	 0xe9c7
#define a3         	 0xf6ba
#define a4           0xf6fb

Color Img_BigBullet[8][8] = {
	{a0,a0,a1,a1,a1,a1,a0,a0},
	{a0,a1,a2,a2,a2,a2,a1,a0},
	{a1,a2,a3,a3,a3,a3,a2,a1},
	{a1,a2,a3,a4,a4,a3,a2,a1},
	{a1,a2,a3,a4,a4,a3,a2,a1},
	{a1,a2,a3,a3,a3,a3,a2,a1},
	{a0,a2,a2,a2,a2,a2,a1,a0},
	{a0,a0,a1,a1,a1,a1,a0,a0}
};

#endif
