#ifndef MENU_H
#define MENU_H

typedef enum { 
    STATE_MENU,
    STATE_PLAYING,
    STATE_EXIT
} GameState;

void update_menu(GameState *currentState);
void draw_menu();

#endif // MENU_H