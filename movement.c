#include<stdio.h>
#include<SDL2/SDL.h>
#include"main.h"
#include"movement.h"

int movement(SDL_Event *event ,SDL_Rect *player_rect, int *close_requested, vectorPos *points, directions *dir){


    while(SDL_PollEvent(event)){
        switch(event->type){
            case SDL_QUIT:
                *close_requested = 1;
                break;
            case SDL_KEYDOWN:
                    switch(event->key.keysym.scancode){
                        case SDL_SCANCODE_W:
                        case SDL_SCANCODE_UP:
                            dir->up = 1;
                            break;
                        case SDL_SCANCODE_S:
                        case SDL_SCANCODE_DOWN:
                            dir->down = 1;
                            break;
                        case SDL_SCANCODE_A:
                        case SDL_SCANCODE_LEFT:
                            dir->left = 1;
                            break;
                        case SDL_SCANCODE_D:
                        case SDL_SCANCODE_RIGHT:
                            dir->right = 1;
                            break;
                        case SDL_SCANCODE_ESCAPE:
                            *close_requested = 1;
                            break;
                    }
                    break;
                case SDL_KEYUP:
                    switch(event->key.keysym.scancode){
                        case SDL_SCANCODE_W:
                        case SDL_SCANCODE_UP:
                            dir->up = 0;
                            break;
                        case SDL_SCANCODE_S:
                        case SDL_SCANCODE_DOWN:
                            dir->down = 0;
                            break;
                        case SDL_SCANCODE_A:
                        case SDL_SCANCODE_LEFT:
                            dir->left = 0;
                            break;
                        case SDL_SCANCODE_D:
                        case SDL_SCANCODE_RIGHT:
                            dir->right = 0;
                            break;
                        case SDL_SCANCODE_ESCAPE:
                            *close_requested = 1;
                            break;
                    }
                    break;
        }
    }
    // determin velocity
    points->x_vel = points->y_vel = 0;
    if(dir->up && !dir->down) points->y_vel = -SPEED;
    if(dir->down && !dir->up) points->y_vel = SPEED;
    if(dir->left && !dir->right) points->x_vel = -SPEED;
    if(dir->right && !dir->left) points->x_vel = SPEED;

    //collison detection with bounds
    if(points->x_pos <= 0) points->x_pos = 0;
    if(points->y_pos <=0 ) points->y_pos = 0;
    if(points->x_pos >= WINDOW_WIDTH - player_rect->w) points->x_pos =WINDOW_WIDTH - player_rect->w;
    if(points->y_pos >= WINDOW_HEIGHT - player_rect->h) points->y_pos = WINDOW_HEIGHT - player_rect->h;

    // update pos
    points->x_pos += points->x_vel/60;
    points->y_pos += points->y_vel/60;
}

int stop_movement(SDL_Rect *player_rect, vectorPos *points, directions *dir){
    // determin velocity
    points->x_vel = points->y_vel = 0;
    if(dir->up && !dir->down) points->y_vel = SPEED;
    if(dir->down && !dir->up) points->y_vel = -SPEED;
    if(dir->left && !dir->right) points->x_vel = +SPEED;
    if(dir->right && !dir->left) points->x_vel = -SPEED;

    // update pos
    points->x_pos += points->x_vel/30;
    points->y_pos += points->y_vel/30;
}