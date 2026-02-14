#include "game.h"
#include "raylib.h"
#include "generator.h"

void run_game(GameState *currentState) {
  // This function is called every frame when in STATE_PLAYING
  ClearBackground(DARKGRAY);
  DrawText("GAME IS RUNNING", 800, 200, 30, WHITE);
  DrawText("Press ESC to return to Menu", 800, 1000, 20, WHITE);
  DrawText("Press 1 to upgrade basic generator", 800, 300, 20, WHITE);
  DrawText("Press 2 to upgrade multiply generator", 800, 350, 20, WHITE);
  
  double deltaTime = GetFrameTime();
  // Basic Generator Logic
  double basic_burst = basic_gen_up(1, basic_generator_level);
  basic_generator(1, basic_generator_level, basic_interval, &basic_timer, deltaTime);
  
  // Multiply Generator Logic
  multiply_generator(multiply_generator_level, basic_burst, multiply_interval, &multiply_timer, deltaTime);

  if (IsKeyPressed(KEY_ESCAPE)) {
    *currentState = STATE_MENU;
  }
  if (IsKeyPressed(KEY_ONE) && money >= basic_generator_price) {
    basic_generator_level++;
    money -= basic_generator_price;
    basic_generator_price *= 1.25;
  }
  if (IsKeyPressed(KEY_TWO) && money >= multiply_generator_price) {
    multiply_generator_level++;
    money -= multiply_generator_price;
    multiply_generator_price *= 2.25;
  }

  double current_basic_interval = basic_interval / (1.0 + basic_generator_level * 0.1 - 0.1);
  double current_multiply_interval = multiply_interval / (1.0 + multiply_generator_level * 0.1 - 0.1);
  double basic_avg = basic_burst / current_basic_interval;
  double multiply_avg = multiply_gen_up(multiply_generator_level, basic_burst) / current_multiply_interval;
  double total_avg = basic_avg + multiply_avg;

  DrawText(TextFormat("Money: %.0f", money), 800, 400, 20, WHITE);
  DrawText(TextFormat("Total Income: %.2f/s", total_avg), 1600, 50, 25, GREEN);
  
  DrawText(TextFormat("Basic generator level:      %.0f\nprice: %.0f\ninterval: %.2f\navg income/s: %.2f", basic_generator_level, basic_generator_price, current_basic_interval, basic_avg), 400, 450, 20, WHITE);
  DrawText(TextFormat("Multiply generator level:   %.0f\nprice: %.0f\ninterval: %.2f\navg income/s: %.2f", multiply_generator_level, multiply_generator_price, current_multiply_interval, multiply_avg), 1000, 450, 20, WHITE);
}