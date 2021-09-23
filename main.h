#ifndef MAIN_H
#define MAIN_H


#define WINDOW_WIDTH (640)
#define WINDOW_HEIGHT (480)

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
    int up;
    int down;
    int left;
    int right;
}directions;


#endif