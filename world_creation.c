#include "maze.h"

/**
 * build_world_from_args - Create the game depending of the map(s) passed
 * @num_of_lvls: Numbers of files passed
 * @level_files: Array with the name of the files passed
 *
 * Return: A list with the path of the files passed, NULL if it fails
 */
level *build_world_from_args(int num_of_lvls, char *level_files[])
{
	level stage = { NULL, 0, {0, 0}, {2, 2}, {-1, 0}, {0, 0.5} };
	level *levels;
	int i, lvl;

	levels = malloc(sizeof(level) * (num_of_lvls - 1));
	if (levels == NULL)
		return (NULL);
	lvl = 0;
	for (i = 1; i < num_of_lvls; i++)
	{
		stage.map = create_map(level_files[i], &stage.play,
							   &stage.win, &stage.height);
		if (stage.map == NULL)
			return (NULL);
		levels[lvl] = stage;
		lvl++;
	}
	return (levels);
}
