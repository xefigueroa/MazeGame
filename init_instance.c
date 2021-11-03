#include "maze.h"

/**
 * init_instance - Initializes SDL2, window & renderer instances
 * @instance: Instance that will be initialized
 * Return: 0 Success 1 Fail
 **/
int init_instance(SDL_Instance *instance)
{
	instance->window = NULL;
	instance->renderer = NULL;

	/* Initialize SDL */
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		printf("Unable to initialize SDL. SDL_Error: %s\n", SDL_GetError());
		return (1);
	}

	/* Create a new window instance */
	instance->window = SDL_CreateWindow("Maze Game", SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);

	if (instance->window == NULL)
	{
		printf("Window not created SDL_Error: %s\n", SDL_GetError());
		SDL_Quit();
		return (1);
	}

	/* Create a new Renderer instance linked to the Window */
	instance->renderer = SDL_CreateRenderer(instance->window, -1,
			SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if (instance->renderer == NULL)
	{
		printf("SDL_CreateRenderer Error: %s\n", SDL_GetError());
		SDL_DestroyWindow(instance->window);
		SDL_Quit();
		return (1);
	}
	return (0);
}
