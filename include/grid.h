#ifndef GRID_H
#define GRID_H

#include <SDL2/SDL.h>

#define grid_cell_size 6
#define grid_width 6 * 29
#define grid_height 6 * 23

static const SDL_Color grid_background = {22, 22, 22, 255};     // Barely Black
static const SDL_Color grid_line_color = {44, 44, 44, 255};     // Dark grey
static const SDL_Color grid_alive_color = {255, 255, 255, 255}; // White

static int grid_matrix[grid_width][grid_height] = {0};
static int grid_matrix_copy[grid_width][grid_height] = {0};

int grid_get_alive_neighbours(int i, int j);

void grid_generate_random();
void grid_render_matrix(SDL_Renderer *renderer);
void grid_matrix_update();

#endif