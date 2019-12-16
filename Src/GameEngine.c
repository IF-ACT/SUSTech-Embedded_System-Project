#include "GameEngine.h"

#include "GameEvent.h"
#include "Renderer.h"
#include "Time.h"
#include "mygpio.h"

void GameEngineLoop()
{
	Node *it;
	GameEvent *event;
	void *game_object;
	unsigned i, j;

	Time_OnStart();

	while (true)
	{
		// init
		i = 0; j = 0;
		screen = InitScreen(screen);
		// object loop
		for (it = objects.head; it; it = it->next)
		{
			event = ((GameEvent*)it->object);
			game_object = event->game_object;
			Time_OnUpdate();

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
		// UI loop
		for (it = UI.head; it; it = it->next)
		{
			j++;
			// TODO
		}
		// Flush
		screen = Flush(screen);

		printlnf("%u gameobject and %u UI freshed", i, j);
	}
}
