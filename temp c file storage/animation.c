#include<stdio.h>
#include<SDL2/SDL.h>
#include<SDL2/SDL_timer.h>
#include<SDL2/SDL_image.h>

#define WINDOW_WIDTH (640)
#define WINDOW_HEIGHT (480)

//speed in pixels per second
#define SPEED (300)


int main(int argc, char* argv[]){
    // IMG_Init(0);
    if(SDL_Init(SDL_INIT_VIDEO|| SDL_INIT_TIMER) != 0){
        printf("Error initializing SDL%s\n", SDL_GetError()); //
        return 1;
    }
    SDL_Window* win =SDL_CreateWindow("hello c99",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, 640,460,0); 

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

    SDL_Surface* surface = IMG_Load("sprite_standing.png");
    if(!surface){
        printf("error creating window %s\n", SDL_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }

    // loads image into grpahics hardaware memory
    SDL_Texture* tex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    if(!tex){
        printf("error creating window %s\n", SDL_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;

    }


    // struct to hold position and size of sprite
    SDL_Rect dest;

    // get dimensions of image
    SDL_QueryTexture(tex, NULL, NULL, &dest.w, &dest.h);

    // position the sprite at the bottom center of the window
    //origin is the top left corner, positive y is down
    float x_pos = (WINDOW_WIDTH - dest.w)/2;
    float y_pos = (WINDOW_HEIGHT - dest.y)/2;
    float x_vel = SPEED;
    float y_vel = SPEED;

    //set 1 to close window when x is pressed
    int close_requested = 0;

    // animation loop
    while(!close_requested){
        

        // process events
        SDL_Event event;
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT){
                close_requested = 1;
            }
        }

        // collison dectect with bounds
        if(x_pos <= 0){
            x_pos = 0;
            x_vel = -x_vel;
        };
        if(y_pos <= 0){
            y_pos = 0;
            y_vel = -y_vel;
        }
        if(x_pos >= WINDOW_WIDTH - dest.w){
            x_pos = WINDOW_WIDTH - dest.w;
            x_vel = -x_vel;
        }
        if(y_pos >= WINDOW_HEIGHT - dest.h){
            y_pos = WINDOW_HEIGHT - dest.h;
            y_vel = -y_vel;
        }

        // update pos
        x_pos += x_vel/60;
        y_pos += y_vel/60;

        dest.x = (int)x_pos;
        dest.y = (int)y_pos;


        //clear the window
        SDL_RenderClear(rend);


        //draw image to window
        SDL_RenderCopy(rend,tex, NULL, &dest);
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