#include "maze.h"

int poll_events()
{
	SDL_Event event;
	SDL_KeyboardEvent key;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_QUIT:
				return (1);
			case SDL_KEYDOWN:
			{
				key = event.key;
				/* if 'ESCAPE' is pressed */
				if (key.keysym.scancode == 0x29)
					return (1);
				break;
			}
		}
	}
	return (0);
}
