#include<stdio.h>
#include<stdlib.h>
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include"json.h"
#include"main.h"
#include"trigger.h"

// TODO triggerlist has trigger exist atribute
// replace if(trigger_list == Null) return 1;
// with if(trigger_list->trigger_exist == 1) return 1;
// but double check what that atribute even does lol

int collison(trigger trigger1, SDL_Rect player_rect, vectorPos *points){
    // make a rect for trigger
    SDL_Rect trigger_rect;
    trigger_rect.h = trigger1.dim_y;
    trigger_rect.w = trigger1.dim_y;
    trigger_rect.x = trigger1.pos_x;
    trigger_rect.y = trigger1.pos_y;


    //top right corner
    if((player_rect.x >trigger_rect.x && player_rect.x < (trigger_rect.x+trigger_rect.w)) || player_rect.y >trigger_rect.y && player_rect.y < (trigger_rect.y+trigger_rect.h) )printf("top right \n");

    //bottom right corner
    if((player_rect.x >trigger_rect.x && player_rect.x < (trigger_rect.x+trigger_rect.w)) || (player_rect.y+player_rect.h) >trigger_rect.y && (player_rect.y+player_rect.h) < (trigger_rect.y+trigger_rect.h) ){
        printf("bottom right\n");}

    //top left corner
    if(((player_rect.x + player_rect.w) >trigger_rect.x && (player_rect.x + player_rect.w) < (trigger_rect.x+trigger_rect.w)) || player_rect.y >trigger_rect.y && player_rect.y < (trigger_rect.y+trigger_rect.h) ) printf("top left\n");

    //bottom left
    if(((player_rect.x + player_rect.w) >trigger_rect.x && (player_rect.x + player_rect.w) < (trigger_rect.x+trigger_rect.w)) || player_rect.y >trigger_rect.y && player_rect.y < (trigger_rect.y+trigger_rect.h) ){

    printf("top left\n");
    }

    return 1;

}

int check_triggers(trigger_list *trigger_list, SDL_Rect player_rect, vectorPos *points){
    if(trigger_list == NULL) return 1;
    for(int i = 0; i < trigger_list->number_of_triggers; i++){
        trigger temp_trigger = trigger_list->trigger_list[i];
        collison(temp_trigger, player_rect, points);
    }

    return 0;

}

// add colour input shit lol
int show_triggers(RECT_list *rect_list, SDL_Renderer *rend, int fill){
    if(rect_list == NULL) return 1;
    SDL_SetRenderDrawColor(rend, 0, 0, 0, 255);
    for(int i = 0; i< rect_list->number_of_rects; i++){
        SDL_Rect temp_rect = rect_list->rect_list[i];
        if(fill == 0) SDL_RenderDrawRect(rend, &temp_rect);
        if(fill == 1) SDL_RenderFillRect(rend, &temp_rect);
    }
    return 0;
}

int fill_trigger_rect_list(trigger_list *trigger_list, RECT_list *rect_list){
    if(trigger_list == NULL) return 1;

    rect_list->number_of_rects = trigger_list->number_of_triggers;
    // the size of the sdl2 rect stuct is 16 bytes
    // change this if problems arise or it isnt true
    rect_list->rect_list = malloc(16*rect_list->number_of_rects);
    for(int i = 0; i<trigger_list->number_of_triggers;i++){
        trigger temp_trigger = trigger_list->trigger_list[i];
        rect_list->rect_list[i].x = temp_trigger.pos_x;
        rect_list->rect_list[i].y = temp_trigger.pos_y;
        rect_list->rect_list[i].w = temp_trigger.dim_x;
        rect_list->rect_list[i].h = temp_trigger.dim_y;
    }
    return 0;
}


int show_player_rect(SDL_Rect player_rect, SDL_Renderer *rend, int fill){
    //if(player_rect == NULL) return 1;
    SDL_SetRenderDrawColor(rend, 0, 0, 0, 255);
    if(fill == 0) SDL_RenderDrawRect(rend, &player_rect);
    if(fill == 1) SDL_RenderFillRect(rend, &player_rect);

}