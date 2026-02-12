#include "menu.h"
#include "raylib.h"

void update_menu(GameState *currentState) {
    if (IsKeyPressed(KEY_P)) {
        *currentState = STATE_PLAYING;
    }
    else if (IsKeyPressed(KEY_E)) {
        *currentState = STATE_EXIT;
    }
}

void draw_menu() {
    ClearBackground(DARKGRAY);
    DrawText("--- GAME MENU ---", 190, 100, 20, WHITE);
    DrawText("1. Play Game (P)", 190, 150, 20, WHITE);
    DrawText("2. Exit (E)", 190, 180, 20, WHITE);
}
