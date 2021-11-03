#include "maze.h"

/**
 * main - runs Maze Game
 * @argc: number of arguments
 * @argv: arguments passed to program
 * Return: 1 if fail, 0 if success
 **/
int main(int argc, char *argv[])
{
	SDL_Instance instance;
	level *levels;
	int lvl, win_value, num_of_levels;
	keys key_press = {0, 0, 0, 0};

	lvl = win_value = 0;
	/* argc = levels included when running game */
	num_of_levels = argc;
	if (num_of_levels < 2)
		return (1);
	/* generate maps from levels entered */
	levels = build_world_from_args(argc, argv);
	if (levels == NULL)
		return (1);
	/* init SDL2/Window/renderer */
	if (init_instance(&instance) != 0)
		return (1);
	lvl = 0;
	while (1)
	{
		if (keyboard_events(&key_press))
		{
			free_memory(instance, levels[lvl].map, levels[lvl].height);
			break;
		}
		movement(key_press, &levels[lvl].plane, &levels[lvl].dir, &levels[lvl].play,
			 levels[lvl].map);
		if (check_win(levels[lvl].play, levels[lvl].win, &win_value))
		{
			free_map(levels[lvl].map, levels[lvl].height);
			lvl++;
			if (lvl == argc - 1)
				break;
			win_value = 0;
		}
		draw(instance, levels[lvl].map, levels[lvl].play, levels[lvl].dir,
		     levels[lvl].plane);
	}
	free_memory(instance, levels[lvl].map, levels[lvl].height);
	/* close_SDL(instance); */
	if (win_value)
		print_win();
	return (0);
}
