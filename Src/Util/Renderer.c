#include "Renderer.h"

#include "mygpio.h"

#define MAX(a, b) (a>b?a:b)
#define MIN(a, b) (a<b?a:b)

#define __WIDTH 38
#define __HEIGHT 48
#define __SCALE 6

Color **__last_screen = NULL;

void Render(GameObject* game_object, Color **screen)
{
	unsigned sx, sy, ex, ey;
	unsigned i, j;
	Color c;

	sx = game_object->pos_x - (game_object->width + 1) / 2;
	sy = game_object->pos_y - (game_object->height + 1) / 2;
	ex = game_object->pos_x + game_object->width / 2;
	ey = game_object->pos_y + game_object->height / 2;
	
	for (i = MAX(sy, 0); i < MIN(ey, __HEIGHT); i++)
		for (j = MAX(sx, 0); j < MIN(ex, __WIDTH); j++)
		{
			c = game_object->img[i - sy][j - sx];
			if (c != TRANSPARENT)
				screen[i][j] = c;
		}
}

Color** InitScreen(Color** screen)
{
	uint16_t i, j;

	if(!screen)
	{
		screen = calloc(sizeof(Color*), __HEIGHT);

		for (i = 0; i < __HEIGHT; i++)
		screen[i] = calloc(sizeof(Color), __WIDTH);
	}

	for (i = 0; i < __HEIGHT; i++)
		for (j = 0; j < __WIDTH; j++)
			screen[i][j] = TRANSPARENT;

	return screen;
}

Color** Flush(Color **screen)
{
	uint16_t i, j;
	uint16_t sx, sy, ex, ey;
	Color **temp;
	// init
	if (!__last_screen)
	{
		LCD_Clear(BLACK);
		__last_screen = InitScreen(__last_screen);
		println("Render init finished");
	}
	// flush
	for (i = 0; i < __HEIGHT; i++)
		for (j = 0; j < __WIDTH; j++)
		{
			if (screen[i][j] != __last_screen[i][j])
			{
				sx = j * __SCALE;
				sy = i * __SCALE;
				ex = sx + __SCALE;
				ey = sy + __SCALE;
				LCD_Fill(sx, sy, ex, ey, screen[i][j]);
				printlnf("flushing %hu, %hu", j, i);
			}
		}
	// cache
	temp = __last_screen;
	__last_screen = screen;
	return temp;

	println("Flushed");
}
