#include "GameEngine.h"

#include "Renderer.h"
#include "Time.h"
#include "mygpio.h"
#include "GameObject.h"
#include "GameObject_Bullet.h"
#include "GameObject_Self.h"
#include "GameObject_Enemy.h"
#include "BloodBar.h"

#include "lcd.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static bool __flash;

bool __Crash(GameObject* obj1, GameObject* obj2)
{
	float cdis = (float)(obj1->collider + obj2->collider);

	bool flag_1 = false;
	bool flag_2 = false;

	if (obj1->pos_x > obj2->pos_x)
	{
		if (obj1->pos_x - obj2->pos_x < cdis)
			flag_1 = true;
	}
	else
	{
		if (obj2->pos_x - obj1->pos_x < cdis)
			flag_1 = true;
	}

	if (obj1->pos_y > obj2->pos_y)
	{
		if (obj1->pos_y - obj2->pos_y < cdis)
			flag_2 = true;
	}
	else
	{
		if (obj2->pos_y - obj1->pos_y < cdis)
			flag_2 = true;
	}

	return flag_1 && flag_2;
}

unsigned __ObjectEvent_LoopOnce(LinkedList* events, bool is_bullet)
{
	unsigned i = 0;
	Node *it, *it_temp;
	GameEvent *event;
	void *game_object;

	// object loop
	for (it = events->head->next; it; it = it->next)
	{
		event = ((GameEvent*)it->object);
		game_object = event->game_object;

		// Create
		if (!((GameObject*)game_object)->__created)
		{
			event->OnCreate(game_object);
		}
		// Update
		event->OnUpdate(game_object);
		// Bullet crash
		if (is_bullet)
		{
			if (((GameObject_Bullet*)game_object)->is_enemy)
			{
				// Emeny bullet crash with self plane
				if (__Crash((GameObject*)game_object, (GameObject*)Engine_SelfEvent->game_object))
				{
					((GameObject*)game_object)->__to_destroy = true;
					if (
						((GameObject_Self*)Engine_SelfEvent->game_object)->life >
						((GameObject_Bullet*)game_object)->damage
					)
						((GameObject_Self*)Engine_SelfEvent->game_object)->life -=
						((GameObject_Bullet*)game_object)->damage;
					else
					{
						((GameObject_Self*)Engine_SelfEvent->game_object)->life = 0;
					}
					if (!__flash)
					{
						// TODO
						// open led
						HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_RESET);
						HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2, GPIO_PIN_RESET);
						__flash = true;
					}
				}	
			}
			else
			{
				// Self bullet crash with enemy plane
				for (it_temp = Engine_EnemyEvents.head->next; it_temp; it_temp = it_temp->next)
				{
					if (__Crash((GameObject*)game_object, (GameObject*)((GameEvent*)it_temp->object)->game_object))
					{
						((GameObject*)game_object)->__to_destroy = true;
						if (
							((GameObject_Enemy*)((GameEvent*)it_temp->object)->game_object)->life >
							((GameObject_Bullet*)game_object)->damage
						)
							((GameObject_Enemy*)((GameEvent*)it_temp->object)->game_object)->life -=
							((GameObject_Bullet*)game_object)->damage;
						else if (((GameObject_Enemy*)((GameEvent*)it_temp->object)->game_object)->life)
						{
							((GameObject_Enemy*)((GameEvent*)it_temp->object)->game_object)->life = 0;
							Game_KillCount++;
							Game_Score += 200;
						}
					}
				}
			}
		}
		// Destroy
		if (((GameObject*)game_object)->__to_destroy)
		{
			event->OnDestroy(game_object);

			free(event);
			it = it->prev;
			RemoveNode(events, it->next);
		}
		// Render
		else
		{
			event->OnRender(game_object, screen);
			i++;
		}
	}
	return i;
}

void GameEngineInit()
{
	Game_Life = 1;
	Game_KillCount = 0;
	Game_Score = 0;
	Game_BombNum = 0;
	Game_ChapterNum = 0;
	Game_ChapterPassed = false;

	Engine_KeyPressed = 0;

	Engine_EnemyEvents.head = malloc(sizeof(Node));
	Engine_EnemyEvents.head->next = NULL;
	Engine_EnemyEvents.tail = Engine_EnemyEvents.head;

	Engine_BulletEvents.head = malloc(sizeof(Node));
	Engine_BulletEvents.head->next = NULL;
	Engine_BulletEvents.tail = Engine_BulletEvents.head;

	Engine_UIEvents.head = malloc(sizeof(Node));
	Engine_UIEvents.head->next = NULL;
	Engine_UIEvents.tail = Engine_UIEvents.head;

	__flash = false;
	println("Init finished");
}

void GameEngineLoop(void (*OnLoop)(void))
{
	Node *it;
	void *self_object;
	unsigned i, j;

	Time_OnStart();

	BloodBar_Init();

	while (!Game_ChapterPassed)
	{
		// init
		i = 0; j = 0;
		screen = InitScreen(screen);
		Time_OnUpdate();

		if (__flash)
		{
			// TODO
			// close led
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2, GPIO_PIN_SET);
			__flash = false;
		}


		// Event on loop
		OnLoop();
		
		// freshing self plane
		if (Engine_SelfEvent)
		{
			self_object = Engine_SelfEvent->game_object;

			// Create
			if (!((GameObject*)self_object)->__created)
			{
				Engine_SelfEvent->OnCreate(self_object);
			}
			// Update
			Engine_SelfEvent->OnUpdate(self_object);
			// Destroy
			if (((GameObject*)self_object)->__to_destroy)
			{
				Engine_SelfEvent->OnDestroy(self_object);
				
				if (!Game_Life)
				{
					free(Engine_SelfEvent);
					Engine_SelfEvent = NULL;
				}
				else
				{
					Game_Life--;
				}
			}
			// Render
			else
			{
				Engine_SelfEvent->OnRender(self_object, screen);
				BloodBar_Update(
						(int)((((GameObject_Self*)self_object)->life)*10/SELF_LIFE_MAX)
				);
				i++;
			}
		}
		else
		{
			GameOver();
			break;
		}

		// object loops
		i += __ObjectEvent_LoopOnce(&Engine_EnemyEvents, false);
		i += __ObjectEvent_LoopOnce(&Engine_BulletEvents, true);
		// UI loop
		for (it = Engine_UIEvents.head->next; it; it = it->next)
		{
			j++;
			// TODO
		}
		
		// Reset
		Engine_KeyPressed = 0;
		// Flush
		screen = Flush(screen);
		// Score
		Game_Score++;

		if (Game_ChapterPassed)
			break;

		printlnf("Time: %d, %u gameobject and %u UI freshed", GetTime(), i, j);
	}

	Game_ChapterNum++;
	Game_ChapterPassed = false;
}

void GameOver()
{
	LCD_Clear(GRAY);
	BACK_COLOR = GRAY;
	//LCD_DrawRectangle(30, 40, 230, 64);
	//LCD_Color_Fill(30, 40, 230, 64,WHITE);
	LCD_ShowString(30, 10, 140, 24, 14, (uint8_t*) "Score :");
	LCD_ShowString(30, 80, 200, 24, 24, (uint8_t*) "Game Over ^_^");

	//LCD_Color_Fill(20, 110, 220, 112,BLACK);

	LCD_ShowNum(100, 30 ,Game_Score, 5,24);
	exit(0);
}




