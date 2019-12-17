#include "GameEngine.h"

#include "Renderer.h"
#include "Time.h"
#include "mygpio.h"

void GameEngineInit()
{
	Game_Life = 3;
	Game_KillCount = 0;
	Game_Score = 0;
	Game_BombNum = 0;
	Game_ChapterNum = 0;
	Game_ChapterPassed = false;

	Engine_KeyPressed = 0;
}

void GameEngineLoop()
{
	Node *it;
	void *self_object;
	unsigned i, j;

	Time_OnStart();

	while (!Game_ChapterPassed)
	{
		// init
		i = 0; j = 0;
		screen = InitScreen(screen);
		Time_OnUpdate();
		
		// freshing self plane
		if (Engine_SelfEvent)
		{
			self_object = Engine_SelfEvent->game_object;

			// Create
			if (!Engine_SelfEvent->__Created(self_object))
			{
				Engine_SelfEvent->OnCreate(self_object);
			}
			// Update
			Engine_SelfEvent->OnUpdate(self_object);
			// Destroy
			if (Engine_SelfEvent->__ToDestroy(self_object))
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
				i++;
			}
		}
		else
		{
			GameOver();
		}

		// object loops
		i += __ObjectEvent_LoopOnce(&Engine_EnemyEvents);
		i += __ObjectEvent_LoopOnce(&Engine_BulletEvents);
		// UI loop
		for (it = Engine_UIEvents.head; it; it = it->next)
		{
			j++;
			// TODO
		}
		
		// Reset
		Engine_KeyPressed = 0;
		// Flush
		screen = Flush(screen);

		printlnf("%u gameobject and %u UI freshed", i, j);
	}

	Game_ChapterNum++;
	Game_ChapterPassed = false;
}

void GameOver()
{
	
}

unsigned __ObjectEvent_LoopOnce(LinkedList* events)
{
	unsigned i = 0;
	Node *it;
	GameEvent *event;
	void *game_object;

	// object loop
	for (it = events->head; it; it = it->next)
	{
		event = ((GameEvent*)it->object);
		game_object = event->game_object;

		// Create
		if (!event->__Created(game_object))
		{
			event->OnCreate(game_object);
		}
		// Update
		event->OnUpdate(game_object);
		// Destroy
		if (event->__ToDestroy(game_object))
		{
			event->OnDestroy(game_object);

			free(event);
			it = it->prev;
			RemoveNode(it->next);
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
