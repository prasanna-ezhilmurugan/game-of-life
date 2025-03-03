#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <stdbool.h>

extern SDL_Window *window;
extern SDL_Renderer *renderer;
extern bool is_running;

int initialize_window();
void destroy_window();
void handle_event();
void render();

#endif