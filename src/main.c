#include "menu.h"
#include "game.h"
#include "raylib.h"

int main() {
  const int screenWidth = 1920;
  const int screenHeight = 1080;

  InitWindow(screenWidth, screenHeight, "Small C Game");

  // Force the window to open on the main screen
  int monitor = 0; //Main screen
  SetWindowMonitor(monitor); 

  //Center the window on the main screen
  int monitorWidth = GetMonitorWidth(monitor);
  int monitorHeight = GetMonitorHeight(monitor);
  SetWindowPosition(monitorWidth/2 - screenWidth/2, monitorHeight/2 - screenHeight/2);

  SetTargetFPS(120);
  SetExitKey(KEY_Q); //Close the window with Q and not ESC by default (it was very annoying)

  GameState currentState = STATE_MENU;

  while (!WindowShouldClose() && currentState != STATE_EXIT) {
    // Update logic
    switch (currentState) {
    case STATE_MENU:
      update_menu(&currentState);
      break;

    case STATE_PLAYING:
      // Logic handled in run_game below for simplicity
      break;

    case STATE_EXIT:
      break;
    }

    // Draw
    BeginDrawing();
    switch (currentState) {
    case STATE_MENU:
      draw_menu();
      break;

    case STATE_PLAYING:
      run_game(&currentState);
      break;

    case STATE_EXIT:
      break;
    }
    EndDrawing();
  }

  CloseWindow();

  return 0;
}
