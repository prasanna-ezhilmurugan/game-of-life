#include <SDL.h>
#include <SDL_render.h>
#include <game.h>
#include <stdio.h>

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;
bool is_running = false;

int initialize_window() {
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    fprintf(stderr, "error: cannot initialize SDL: %s", SDL_GetError());
    return false;
  }
  window = SDL_CreateWindow("window", SDL_WINDOWPOS_CENTERED,
                            SDL_WINDOWPOS_CENTERED, 600, 400, SDL_WINDOW_SHOWN);
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
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderClear(renderer);
  /*
   * render here
   */
  SDL_RenderPresent(renderer);
}
