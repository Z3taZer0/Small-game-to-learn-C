#include "game.h"
#include "raylib.h"

void run_game(GameState *currentState) {
  // This function is called every frame when in STATE_PLAYING
  ClearBackground(DARKGRAY);
  DrawText("GAME IS RUNNING", 250, 200, 30, WHITE);
  DrawText("Press ESC to return to Menu", 250, 250, 20, WHITE);

  if (IsKeyPressed(KEY_ESCAPE)) {
    *currentState = STATE_MENU;
  }
}
