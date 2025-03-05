#include <game.h>

int main() {
  is_running = initialize_window();
  while (is_running) {
    handle_event();
    /*
     * something is wrong with my update function.
     */
    render();
    update();
  }
  destroy_window();
}