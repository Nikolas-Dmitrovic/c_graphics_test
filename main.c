#include<stdio.h>
#include<SDL2/SDL.h>
#include<SDL2/SDL_timer.h>
#include<SDL2/SDL_image.h>
#include"main.h"
#include"movement.h"
#include"loader.h"
#include"json.h"
#include"trigger.h"


int main(int argc, char* argv[]){
    // IMG_Init(0);
    if(SDL_Init(SDL_INIT_VIDEO|| SDL_INIT_TIMER) != 0){
        printf("Error initializing SDL%s\n", SDL_GetError()); //
        return 1;
    }
    SDL_Window* win =SDL_CreateWindow("hello c99",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,WINDOW_WIDTH, WINDOW_HEIGHT,0); 

    if(!win){
        printf("error creating window %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }
    // create render flags to set up hardware
    Uint32 render_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
    SDL_Renderer* rend = SDL_CreateRenderer(win, -1, render_flags);
    if(!rend){
        printf("error creating window %s\n", SDL_GetError());
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }


    level level1 = parse_file("level_data.json");
    // struct to hold position and size of sprite
    imageLoad image1 = load(rend,win,level1.background_data.file_name, 4);

    imageLoad image2 = load(rend,win,level1.main_character_data.file_name, 4);
    SDL_Rect dest = image2.rect;
    SDL_Texture* tex = image2.texture;




    // position the sprite at the bottom center of the window
    //origin is the top left corner, positive y is down
    vectorPos points;
    points.x_pos = (WINDOW_WIDTH - image2.rect.w)/2;
    points.y_pos = (WINDOW_HEIGHT - image2.rect.y)/2;
    points.y_vel = 0;
    points.x_vel = 0;


    image2.rect.x = points.x_pos;
    image2.rect.y = points.y_pos;

    // keep track of wich inputs given
    directions dir;
    dir.up = 0;
    dir.down = 0;
    dir.left = 0;
    dir.right = 0;

    //set 1 to close window when x is pressed
    int close_requested = 0;


    // animation loop
    while(!close_requested){
        

        // process events
        SDL_Event event;
        // keep track of wich inputs given

        movement(&event,&dest,&close_requested,&points,&dir);


        // determin velocity

        dest.x = (int)points.x_pos;
        dest.y = (int)points.y_pos;


        //clear the window
        SDL_RenderClear(rend);


        printf("%i \n", image2.rect.x);
        image1.rect.x = 89;
        image1.rect.y = 410;
        //draw image to window
        printf("%i \n", image2.rect.x);
        SDL_RenderCopy(rend,image1.texture, NULL, NULL);
        //SDL_RenderPresent(rend);

        //printf("%i \n", dest1.y);
        SDL_RenderCopy(rend,image2.texture, NULL, &dest);
        SDL_RenderPresent(rend);


        // wait 1/60th of a second
        SDL_Delay(1000/60);


    }




    // clean up recourses before exiting
    SDL_DestroyTexture(tex);
    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(win);
    SDL_Quit();
    return 0;
}
