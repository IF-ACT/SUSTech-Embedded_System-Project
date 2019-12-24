#include "BloodBar.h"

#include "lcd.h"

int __last;

void BloodBar_Init()
{
	__last = 10;
	LCD_Fill(0, 292, 100, 297, WHITE);
}

void BloodBar_Update(int present)
{
	if (present != __last)
	{
		LCD_Fill(0, 292, 100, 297, BLACK);
		LCD_Fill(0, 292, 10*present, 297, WHITE);
		__last = present;
	}
}
