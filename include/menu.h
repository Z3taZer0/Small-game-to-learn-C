#ifndef MENU_H
#define MENU_H

typedef enum { STATE_MENU, STATE_PLAYING, STATE_EXIT } GameState;

void show_menu();
GameState handle_menu_input();

#endif // MENU_H