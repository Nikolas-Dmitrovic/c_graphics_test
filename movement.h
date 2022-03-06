#ifndef MOVEMENT_H
#define MOVEMENT_H

// handels movement of character on screen
int movement(SDL_Event *event ,SDL_Rect *player_rect, int *close_requested, vectorPos *points, directions *dir);

// stops the character/movement if called
// basicly the opposite of movement 
int stop_movement(SDL_Rect *player_rect, vectorPos *points, directions *dir);


#endif