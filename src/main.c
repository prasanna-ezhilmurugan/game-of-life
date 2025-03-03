#include <game.h>

int main() {
  is_running = initialize_window();
  while (is_running) {
    handle_event();
    render();
  }
  destroy_window();
}