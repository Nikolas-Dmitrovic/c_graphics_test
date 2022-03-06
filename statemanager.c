#include"statemanager.h"
#include<stdio.h>
#include<stdlib.h>

int STATEMANAGER_INIT(statemanager *statemanager) {
    statemanager->capacity = 3;
    statemanager-> stack = malloc(statemanager -> capacity * sizeof(state*));
    statemanager->top = -1;
}

int STATEMANAGER_UPDATE(statemanager *statemanager){
    state *state = STATEMANAGER_TOP(statemanager);
    if(state ->update != NULL) return state->update();
    return 1;
}

int STATEMANAGER_DRAW(statemanager *statemanager){
    state *state = STATEMANAGER_TOP(statemanager);
    if(state->draw != NULL) return state->draw();
    return 1;
}

int STATEMANAGER_SCALE(statemanager *statemanager){
    statemanager->capacity *= 2;
    statemanager->stack = realloc(statemanager->stack ,statemanager->capacity * sizeof(state*));
    return statemanager->capacity;
}

int STATEMANAGER_PUSH(statemanager *statemanager, state *state){
    if(statemanager->top+1 == statemanager->capacity) STATEMANAGER_SCALE(statemanager);
    statemanager->top++;
    statemanager->stack[statemanager->top] = state;
    state->on_stack = 1;
    //FIXME: make sure to null the init of the state after it gets init is called on it
    // or idk just figure out something that works lol
    if(state-> init != NULL) state->init;
    return statemanager->top;
}

int STATEMANAGER_FREE(statemanager *statemanager){
    do {
    STATEMANAGER_pop(statemanager);
  } while (statemanager -> top > -1);
  free(statemanager -> stack);
  return 0;
}

int STATEMANAGER_POP(statemanager *statemanager){
    if(statemanager ->top == -1) return 0;
    state *top = STATEMANAGER_TOP(statemanager);
    if(top -> destroy != NULL) top->destroy;
    statemanager -> stack[statemanager -> top] = NULL;
    statemanager -> top--;
    return statemanager -> top;
}
