#include <grid.h>
#include <stdlib.h>
#include <time.h>

void grid_generate_random() {
  srand(time(0));
  for (int i = 0; i < grid_width; i++) {
    for (int j = 0; j < grid_height; j++) {
      grid_matrix[i][j] = rand() % 2;
      printf("%d", grid_matrix[i][j]);
    }
    printf("\n");
  }
}

void grid_render_matrix(SDL_Renderer *renderer) {
  SDL_Rect current_cell = {
      .x = 0, .y = 0, .w = grid_cell_size, .h = grid_cell_size};
  SDL_SetRenderDrawColor(renderer, grid_alive_color.r, grid_alive_color.g,
                         grid_alive_color.b, grid_alive_color.a);

  for (int i = 0; i < grid_width; i++) {
    for (int j = 0; j < grid_height; j++) {
      if (grid_matrix[i][j]) {
        current_cell.x = grid_cell_size * i;
        current_cell.y = grid_cell_size * j;
        SDL_RenderFillRect(renderer, &current_cell);
      }
    }
  }
}