#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <grid.h>
#include <stdbool.h>

static const char *window_title = "game of life";
static const int window_width = (grid_width * grid_cell_size) + 1;
static const int window_height = (grid_height * grid_cell_size) + 1;

extern SDL_Window *window;
extern SDL_Renderer *renderer;
extern bool is_running;

int initialize_window();
void destroy_window();
void handle_event();
void render();

#endif