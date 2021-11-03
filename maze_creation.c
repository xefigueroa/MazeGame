#include "maze.h"

/**
 * line_count - counts line number on a file
 * @file_string: Path to file to eval
 *
 * Return: Number of lines or 0 (fail)
 **/
size_t line_count(char *file_string)
{
	FILE *maze_file;
	char *line;
	ssize_t read = 0;
	size_t lines, line_len;

	maze_file = fopen(file_string, "r");
	if (maze_file == NULL)
	{
		printf("File does not exist\n");
		return (0);
	}
	lines = 0;
	read = getline(&line, &line_len, maze_file);
	if (read == -1)
	{
		return (0);
	}
	lines++;
	while (read != -1)
	{
		read = getline(&line, &line_len, maze_file);
		lines++;
	}
	fclose(maze_file);
	return (lines);
}

/**
 * char_count - Counts chars in a string
 * @line: String to eval
 *
 * Return: Value of charCount
 **/
size_t char_count(char *line)
{
	size_t charCount = 0;

	while (line[charCount] != '\0')
	{
		charCount++;
	}
	return (charCount);
}

/**
 * plot_grid_points - Plot the specific points in the maze
 * @maze: The 2D array representing the map grid
 * @play: The player's x/y position
 * @win: The x/y cooridinates of the win square
 * @cur_char: The current character in the line being read
 * @maze_line: The line in the maze currently being created
 * @line: The line being read from the file
 * @found_win: Was the win square in the maze found
 **/
void plot_grid_points(char **maze, double_s *play, int_s *win, size_t cur_char,
					  size_t maze_line, char *line, int *found_win)
{
	if (line[cur_char] == 'p')
	{
		play->y = cur_char;
		play->x = maze_line;
		maze[maze_line][cur_char] = '0';
	}
	else if (line[cur_char] == 'w')
	{
		*found_win = 1;
		win->y = cur_char;
		win->x = maze_line;
		maze[maze_line][cur_char] = '0';
	}
	else
	{
		if (line[cur_char] == '0' && *found_win == 0)
		{
			win->y = cur_char;
			win->x = maze_line;
		}
		maze[maze_line][cur_char] = line[cur_char];
	}
}

/**
 * create_map - Create a 2D array for the map of the maze
 * @file_string: Path to the file containing the representation of the map
 * @play: Player x/y position
 * @win: The x/y cooridinate of the winning space
 * @map_h: The height of the 2D array representing the play space
 *
 * Return: char ** to a representation of the map, NULL if it fails
 **/
char **create_map(char *file_string, double_s *play, int_s *win, size_t *map_h)
{
	FILE *maze_file;
	char **maze, *line = NULL;
	ssize_t read = 0;
	size_t lineCount, maze_line, charCount, cur_char, bufsize;
	int found_win = 0;

	found_win = 0;
	maze_line = 0;
	lineCount = line_count(file_string);
	*map_h = lineCount;
	if (lineCount == 0)
		return (NULL);
	maze = malloc(sizeof(int *) * lineCount);
	if (maze == NULL)
		return (NULL);
	maze_file = fopen(file_string, "r");
	if (maze_file == NULL)
		return (NULL);
	read = getline(&line, &bufsize, maze_file);
	while (read != -1)
	{
		charCount = char_count(line);
		maze[maze_line] = malloc(sizeof(char) * charCount + 1);
		if (maze == NULL)
			return (NULL);
		for (cur_char = 0; cur_char < charCount; cur_char++)
		{
			plot_grid_points(maze, play, win, cur_char, maze_line, line, &found_win);
		}
		maze_line++;
		read = getline(&line, &bufsize, maze_file);
	}
	fclose(maze_file);
	free(line);
	return (maze);
}
