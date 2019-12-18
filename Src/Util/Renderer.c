#include "Renderer.h"

#include "mygpio.h"

#define MAX(a, b) (a>b?a:b)
#define MIN(a, b) (a<b?a:b)

void __PrintScreen(Color** screen)
{
	int i, j;
	for (i = 0; i < __HEIGHT; i++)
	{
		for (j = 0; j < __WIDTH; j++)
		{
			printlnf("%hu ", screen);
		}
	}
}

Color **__last_screen = NULL;

void Render(GameObject* game_object, Color** screen)
{
	int sx, sy, ex, ey;
	uint16_t rsx, rsy, rex, rey;
	int i, j;
	Color c;

	sx = (int)game_object->pos_x - (game_object->width + 1) / 2;
	sy = (int)game_object->pos_y - (game_object->height + 1) / 2;
	ex = (int)game_object->pos_x + game_object->width / 2;
	ey = (int)game_object->pos_y + game_object->height / 2;

	rsx = (uint16_t)MIN(MAX(sx, 0), __WIDTH);
	rsy = (uint16_t)MIN(MAX(sy, 0), __HEIGHT);
	rex = (uint16_t)MAX(MIN(ex, __WIDTH), 0);
	rey = (uint16_t)MAX(MIN(ey, __HEIGHT), 0);
	
	if (game_object == 536875992)
	{
		printlnf("sx: %d, sy: %d, ex: %d, ey: %d", sx,sy,ex,ey);
		printlnf("rsx: %hu, rsy: %hu, rex: %hu, rey: %hu",rsx,rsy,rex,rey);
	}

	for (i = 0; i < rey - rsy; i++)
		for (j = 0; j < rex - rsx; j++)
		{
			c = game_object->img[i * (rex - rsx) + j];
			if (c != TRANSPARENT)
			{
				screen[i + rsy][j + rsx] = c;
			}
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
			}
		}
	// cache
	temp = __last_screen;
	__last_screen = screen;
	
	return temp;
}

