#include<stdio.h>
#include<stdlib.h>
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include"json.h"

int collison(trigger trigger1, SDL_Rect player_rect){
    // make a rect for trigger
    SDL_Rect trigger_rect;
    trigger_rect.h = trigger1.dim_y;
    trigger_rect.w = trigger1.dim_y;
    trigger_rect.x = trigger1.pos_x;
    trigger_rect.y = trigger1.pos_y;


    // blanket if statement to see if the player rect is touching the box
    if(player_rect.y <= trigger_rect.y && player_rect.y >= (trigger_rect.y+trigger_rect.h) && player_rect.y >= trigger_rect.x && player_rect.y<= (trigger_rect.x+trigger_rect.w)){
        // specific if statments to see what side of the trigger is being touched and how to deal with it
        if(player_rect.y <= trigger_rect.y) printf("do something");
        if(player_rect.y >= (trigger_rect.y+trigger_rect.h))printf("do something");
        if(player_rect.x <= trigger_rect.y)printf("do something");
        if(player_rect.x >= (trigger_rect.y+trigger_rect.w))printf("do something");
    }

    return 1;

}



int check_triggers(trigger_list *trigger_list, SDL_Rect player_rect){
    if(trigger_list == NULL) return 0;

    for(int i = 0; i <= trigger_list->number_of_triggers; i++){
        trigger temp_trigger = trigger_list->trigger_list[i];
        collison(temp_trigger, player_rect);
    }

    return 1;

}