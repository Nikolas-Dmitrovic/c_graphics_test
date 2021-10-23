#ifndef TRIGGER_H
#define TRIGGER_H

#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include"json.h"

/*
1 = empty trigger list
*/
int check_triggers(trigger_list *trigger_list, SDL_Rect player_rect);


int collison(trigger trigger1, SDL_Rect player_rect);
int show_triggers();


#endif