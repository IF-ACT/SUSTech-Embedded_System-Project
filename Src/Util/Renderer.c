#include "Renderer.h"

#define MAX(a, b) (a>b?a:b)
#define MIN(a, b) (a<b?a:b)

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
	
	for (i = MAX(sy, 0); i < MIN(ey, lcddev.height); i++)
		for (j = MAX(sx, 0); j < MIN(ex, lcddev.width); j++)
		{
			c = game_object->img[i - sy][j - sx];
			if (c != TRANSPARENT)
				screen[i][j] = c;
		}
}

Color** Flush(Color **screen)
{
	uint16_t i, j;
	Color **temp;
	// init
	if (!__last_screen)
	{
		__last_screen = calloc(sizeof(Color*), lcddev.height);
		for (i = 0; i < lcddev.height; i++)
			__last_screen[i] = calloc(sizeof(Color), lcddev.width);

		for (i = 0; i < lcddev.height; i++)
			for (j = 0; j < lcddev.width; j++)
				__last_screen[i][j] = TRANSPARENT;
	}
	// flush
	for (i = 0; i < lcddev.height; i++)
		for (j = 0; j < lcddev.width; j++)
			if (screen[i][j] != __last_screen[i][j])
				LCD_Fast_DrawPoint(i, j, screen[i][j]);
	// cache
	temp = __last_screen;
	__last_screen = screen;
	return temp;
}
