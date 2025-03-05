#include "grid.h"
#include <game.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;
bool is_running = false;

int initialize_window() {
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    fprintf(stderr, "error: cannot initialize SDL: %s", SDL_GetError());
    return false;
  }
  window = SDL_CreateWindow(window_title, SDL_WINDOWPOS_CENTERED,
                            SDL_WINDOWPOS_CENTERED, window_width, window_height,
                            SDL_WINDOW_SHOWN);
  if (!window) {
    fprintf(stderr, "error: cannot create SDL window: %s", SDL_GetError());
    return false;
  }

  renderer = SDL_CreateRenderer(
      window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (!renderer) {
    fprintf(stderr, "error: cannot create SDL renderer: %s", SDL_GetError());
    return false;
  }

  grid_load_matrix();
  return true;
}

void destroy_window() {
  if (window != NULL) {
    SDL_DestroyWindow(window);
    window = NULL;
  }
  if (renderer != NULL) {
    SDL_DestroyRenderer(renderer);
    renderer = NULL;
  }
  SDL_Quit();
}

void handle_event() {
  SDL_Event event;
  while (SDL_PollEvent(&event)) {
    if (event.type == SDL_QUIT) {
      is_running = false;
    }
  }
}

void render() {
  SDL_SetRenderDrawColor(renderer, grid_background.r, grid_background.g,
                         grid_background.b, grid_background.a);
  SDL_RenderClear(renderer);
  /*
   * Draw grid lines
   */
  SDL_SetRenderDrawColor(renderer, grid_line_color.r, grid_line_color.g,
                         grid_line_color.b, grid_line_color.a);

  for (int x = 0; x < 1 + grid_width * grid_cell_size; x += grid_cell_size) {
    SDL_RenderDrawLine(renderer, x, 0, x, window_height);
  }
  for (int y = 0; y < 1 + grid_height * grid_cell_size; y += grid_cell_size) {
    SDL_RenderDrawLine(renderer, 0, y, window_width, y);
  }
  grid_render_matrix(renderer);
  SDL_RenderPresent(renderer);
}

void update() { grid_matrix_update(); }
