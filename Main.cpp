#include <iostream>
#include <SDL.h>
#include "Character.h"
#include "Game.h"

// NOTE: SDL main requires argc, argv
int main(int argc, char *argv[])
{
	Game game;
	game.Init();

	SDL_Event event;  // Event -> System Message

	// How long has the game been running?
	Uint64 Now = SDL_GetPerformanceCounter();
	// The clock count last frame
	Uint64 Last = 0;
	// The time (in seconds) that have passed since
	//	the last frame
	float deltaTime = 0;

	// This will loop until the queue of events is empty!
	while (game.GetIsPlaying())
	{
		// Begin Frame...

		// Calculate Delta Time
		Last = Now;
		Now = SDL_GetPerformanceCounter();

		deltaTime = (float)((Now - Last) * 1000 /
			SDL_GetPerformanceFrequency()) / 1000.0;

		// ----
		// Handle Input
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				game.Quit();
				break;
			}
			if (event.type == SDL_KEYDOWN)
			{
				if (event.key.keysym.sym == SDLK_ESCAPE)
				{
					game.Quit();
					break;
				}
			}
			game.HandleEvent(event);
		}

		game.Update(deltaTime);
		game.Draw();
		// ----
		// Update World

		//	mario.Update(deltaTime);

		//	// ----
		//	// Render

		//	mario.Draw(Renderer);

	}

	game.Cleanup();
	return 0;
}