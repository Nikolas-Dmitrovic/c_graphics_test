#ifndef MAIN_H
#define MAIN_H


#define WINDOW_WIDTH (1920)
#define WINDOW_HEIGHT (1080)

//speed in pixels per second
#define SPEED (300)

typedef struct
{
    float y_pos;
    float x_pos;
    float y_vel;
    float x_vel;
}vectorPos;

typedef struct{
    int x;
    int y;
    int w;
    int h;
}rect;


#endif