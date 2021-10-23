#ifndef loader_H
#define loader_H

#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>

typedef struct{
    SDL_Rect rect;
    SDL_Texture* texture;

}imageLoad;

// set x and y to 0 to render image in the center of the screen
imageLoad load(SDL_Renderer *rend, SDL_Window *win,char* image, int scale);
#endif