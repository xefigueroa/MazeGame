#ifndef _MAZE_H_
#define _MAZE_H_

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct SDL_Instance
{
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Texture *texture;
} SDL_Instance;

int init_instance(SDL_Instance *instance);
void draw_stuff(SDL_Instance instance);
int poll_events();
#endif
