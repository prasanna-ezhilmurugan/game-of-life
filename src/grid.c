#include <grid.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

void grid_print_matrix() {
  for (int i = 0; i < grid_width; i++) {
    for (int j = 0; j < grid_height; j++) {
      printf("%d ", grid_matrix[i][j]);
    }
    printf("\n");
  }
}

void grid_generate_random() {
  srand(time(0));
  for (int i = 0; i < grid_width; i++) {
    for (int j = 0; j < grid_height; j++) {
      grid_matrix[i][j] = rand() % 2;
    }
  }
  memcpy(grid_matrix_copy, grid_matrix, sizeof(int) * grid_width * grid_height);
}

void grid_render_matrix(SDL_Renderer *renderer) {
  SDL_Delay(100);
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

bool is_valid(int i, int j) {
  return i >= 0 && j >= 0 && i < grid_width && j < grid_height;
}
int grid_get_alive_neighbours(int i, int j) {
  int alive_neighbours = 0;
  if (is_valid(i - 1, j) && grid_matrix[i - 1][j])
    alive_neighbours++;
  if (is_valid(i, j - 1) && grid_matrix[i][j - 1])
    alive_neighbours++;
  if (is_valid(i - 1, j - 1) && grid_matrix[i - 1][j - 1])
    alive_neighbours++;
  if (is_valid(i + 1, j) && grid_matrix[i + 1][j])
    alive_neighbours++;
  if (is_valid(i, j + 1) && grid_matrix[i][j + 1])
    alive_neighbours++;
  if (is_valid(i + 1, j + 1) && grid_matrix[i + 1][j + 1])
    alive_neighbours++;
  if (is_valid(i - 1, j + 1) && grid_matrix[i - 1][j + 1])
    alive_neighbours++;
  if (is_valid(i + 1, j - 1) && grid_matrix[i + 1][j - 1])
    alive_neighbours++;
  return alive_neighbours;
}

void grid_matrix_update() {
  int alive_neighbours = 0;
  for (int i = 0; i < grid_width; i++) {
    for (int j = 0; j < grid_height; j++) {
      alive_neighbours = grid_get_alive_neighbours(i, j);
      if (grid_matrix[i][j] && (alive_neighbours < 2 || alive_neighbours > 3)) {
        grid_matrix_copy[i][j] = 0;
      } else if (!grid_matrix[i][j] && alive_neighbours == 3) {
        grid_matrix_copy[i][j] = 1;
      }
    }
  }
  memcpy(grid_matrix, grid_matrix_copy, sizeof(int) * grid_height * grid_width);
}