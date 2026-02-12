#include "menu.h"
#include <stdio.h>


int main(int argc, char *argv[]) {
  GameState currentState = STATE_MENU;
  int running = 1;

  while (running) {
    switch (currentState) {
    case STATE_MENU:
      show_menu();
      currentState = handle_menu_input();
      break;

    case STATE_PLAYING:
      printf("\n--- GAME START ---\n");
      printf("Game is running! (Press Enter to return to menu)");
      getchar(); // Consume newline from menu input
      getchar(); // Wait for user enter
      currentState = STATE_MENU;
      break;

    case STATE_EXIT:
      printf("Exiting game. Goodbye!\n");
      running = 0;
      break;
    }
  }

  return 0;
}
