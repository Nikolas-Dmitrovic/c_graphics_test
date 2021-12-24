#ifndef TRIGGER_H
#define TRIGGER_H

#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include"json.h"
#include"main.h"

typedef struct
{
    int number_of_rects;
    SDL_Rect *rect_list;
}RECT_list;

// fills a list of sdl rects
int fill_trigger_rect_list(trigger_list *trigger_list, RECT_list *rect_list);


/*
returns 1 = empty trigger list
returns 0 = succses
*/
int check_triggers(trigger_list *trigger_list, SDL_Rect player_rect, vectorPos *points);

int collison(trigger trigger1, SDL_Rect player_rect, vectorPos *points);

// displayes the outline of all the triggers on screen
int show_triggers(RECT_list *rect_list, SDL_Renderer *rend, int fill);

int show_player_rect(SDL_Rect player_rect, SDL_Renderer *rend, int fill);


#endif