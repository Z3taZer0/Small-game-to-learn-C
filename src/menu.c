#include "menu.h"
#include <stdio.h>


void show_menu() {
  printf("\n--- GAME MENU ---\n");
  printf("1. Play Game\n");
  printf("2. Exit\n");
  printf("Selection: ");
}

GameState handle_menu_input() {
  int choice;
  if (scanf("%d", &choice) != 1) {
    // Clear invalid input
    while (getchar() != '\n')
      ;
    return STATE_MENU;
  }

  switch (choice) {
  case 1:
    return STATE_PLAYING;
  case 2:
    return STATE_EXIT;
  default:
    printf("Invalid selection!\n");
    return STATE_MENU;
  }
}
