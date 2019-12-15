#include "GameEngine.h"

#include "GameEvent.h"
#include "Renderer.h"

void GameEngineLoop()
{
	Node *it;
	GameEvent *event;
	void *game_object;

	while (true)
	{
		// object loop
		for (it = objects.head; it; it = it->next)
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
			// Render
			event->OnRender(game_object, screen);
			// Destroy
			if (event->__ToDestroy(game_object))
			{
				event->OnDestroy(game_object);

				free(event);
				it = it->prev;
				RemoveNode(it->next);
			}
		}
		// UI loop
		for (it = UI.head; it; it = it->next)
		{
			// TODO
		}
		// Flush
		screen = Flush(screen);
	}
}
