#ifndef loader_H
#define loader_H

#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>

typedef struct{
    SDL_Rect rect;
    SDL_Texture* texture;

}imageLoad;

imageLoad load(SDL_Renderer *rend, SDL_Window *win,char* image, float scale);
#endif