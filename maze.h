#ifndef MAZE_H
#define MAZE_H

/* libraries */
#include <SDL2/SDL.h>
#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* predefined variables (global) */
#define SCREEN_HEIGHT 768
#define SCREEN_WIDTH 1024
#define MAP_WIDTH 24
#define MAP_HEIGHT 24

/**
 * struct SDL_Instance - Struct SDL renderer & window
 * @window: window to display game render
 * @renderer: renders graphics
 **/
typedef struct SDL_Instance
{
	SDL_Window *window;
	SDL_Renderer *renderer;
} SDL_Instance;

/**
 * struct double_s - x/y values of doubles
 * @x: X value
 * @y: Y value
 **/
typedef struct double_s
{
	double x;
	double y;
} double_s;

/**
 * struct int_s - x/y values of ints
 * @x: X value
 * @y: Y value
 **/
typedef struct int_s
{
	int x;
	int y;
} int_s;

/**
 * struct keys - key presses for event handlers
 * @up: if pressed (1) or not (0)
 * @down: if pressed (1) or not (0)
 * @right: if pressed (1) or not (0)
 * @left: if pressed (1) or not (0)
 **/
typedef struct keys
{
	int up;
	int down;
	int right;
	int left;
} keys;

/**
 * struct level - contains levels and starting values
 * @map: map of level
 * @height: height of map
 * @win: x/y coordinate of win space
 * @play: x/y starting position of player
 * @dir: x/y of direction vector the player is looking
 * @plane: x/y direction vector of projection plane
 **/
typedef struct level
{
	char **map;
	size_t height;
	int_s win;
	double_s play;
	double_s dir;
	double_s plane;
} level;

/* init_instance.c */
int init_instance(SDL_Instance *);

/* event_handlers.c */
int keyboard_events(keys *);
void check_key_release_events(SDL_Event, keys *);
int check_key_press_events(SDL_Event, keys *);

/* maze_creation.c */
char **create_map(char *, double_s *, int_s *, size_t *);
void plot_grid_points(char **, double_s *, int_s *, size_t, size_t, char *,
		      int *);
size_t get_line_count(char *);
size_t get_char_count(char *);

/* world_creation.c */
level *build_world_from_args(int, char **);

/* draw_stuff.c */
void draw(SDL_Instance, char **, double_s, double_s, double_s);
void draw_walls(char **, double_s, SDL_Instance, double_s, double_s);
void choose_color(SDL_Instance, char **, int_s, int);
void draw_background(SDL_Instance);

/* movement.c */
void rotate(double_s *, double_s *, int);
void movement(keys, double_s *, double_s *, double_s *, char **);

/* func_win.c */
void print_win(void);
int check_win(double_s, int_s, int *);

/* dist_checks.c */
double get_wall_dist(char **, double_s *, int_s *, int_s *, double_s *, int *,
		     double_s *, double_s *);
void check_ray_dir(int_s *, double_s *, double_s, int_s, double_s, double_s);

/* free_mem.c */
void free_memory(SDL_Instance, char **, size_t);
void free_map(char **, size_t);
void close_SDL(SDL_Instance);

/* coming soon better textures */

#endif
