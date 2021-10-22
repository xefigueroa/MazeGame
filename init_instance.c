#include "maze.h"

int init_instance(SDL_Instance *instance)
{
	instance->window = NULL;
	instance->screenSurface = NULL;

	/* Initialize SDL */
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("Unable to initialize SDL. SDL_Error: %s\n", SDL_GetError());
		return (1);
	}
	else
	{
		/* Create a new window instance */
		instance->window = SDL_CreateWindow("SDL TUTORIAL", SDL_WINDOWPOS_CENTERED,
				SDL_WINDOWPOS_CENTERED, 1260, 720, SDL_WINDOW_SHOWN);
		
		if (instance->window == NULL)
		{
			printf("Window not created SDL_Error: %s\n", SDL_GetError());
			SDL_Quit();
			return (1);
		}
		else
		{
			/* Get window surface */
			instance->screenSurface = SDL_GetWindowSurface(instance->window);

			/* Fill surface white */
			SDL_FillRect(instance->screenSurface, NULL,
					SDL_MapRGB(instance->screenSurface->format, 0xFF, 0xFF, 0xFF));

			/* Update the surface */
			SDL_UpdateWindowSurface(instance->window);
			
			/* Wait two seconds */
			SDL_Delay(2000);

			/* Create a new Renderer instance linked to the Window */
			instance->renderer = SDL_CreateRenderer(instance->window, -1,
					SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

			if (instance->renderer == NULL)
			{
				SDL_DestroyWindow(instance->window);
				fprintf(stderr, "SDL_CreateRenderer Error: %s\n", SDL_GetError());
				SDL_Quit();
				return (1);
			}
		}
	}
	return (0);
}

