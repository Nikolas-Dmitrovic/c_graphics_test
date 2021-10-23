#include<stdio.h>
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include"loader.h"
#include"main.h"

imageLoad load(SDL_Renderer *rend, SDL_Window *win,char* image, int scale){
    SDL_Surface* surface = IMG_Load(image);
        if(!surface){
            printf("error creating window%s\n",SDL_GetError());
            SDL_DestroyRenderer(rend);
            SDL_DestroyWindow(win);
            SDL_Quit();
    }



    // SDL_Surface* surface2 = SDL_ConvertSurface(surface, SDL_pixelFormat_)

    SDL_Texture* tex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    if(!tex){
        printf("error creating window %s\n", SDL_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
    }

    SDL_Rect rect;

    // get dimensions of image
    SDL_QueryTexture(tex, NULL, NULL, &rect.w, &rect.h);
    rect.x = 100;
    rect.y = 100;

    //if(scale){
        rect.w *= scale;
        rect.h *= scale;
        /*if(x == 0 && y == 0){
            rect.x = (WINDOW_WIDTH - rect.w)/2;
            rect.y = (WINDOW_HEIGHT - rect.y)/2;
        }*/
    //};

    imageLoad temp;
    temp.rect = rect;
    temp.texture = tex;

    return temp;
}
