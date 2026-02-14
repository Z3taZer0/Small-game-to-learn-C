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
    DrawText("--- GAME MENU ---", 850, 400, 20, WHITE);
    DrawText("1. Play Game (P)", 850, 450, 20, WHITE);
    DrawText("2. Exit (E)", 850, 500, 20, WHITE);
}
