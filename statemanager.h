#ifndef STATEMANAGER_H
#define STATEMANAGER_H

// create a stack that holds up to 5 states


// each state needs to have functions and atributes
// init, update, draw, and destroy
// stack index and on stack bool
// TODO: create a pointer for the json data


typedef unsigned int (*FnPrt)();

typedef struct{
    FnPrt init;
    FnPrt update;
    FnPrt draw;
    FnPrt destroy;
    int stack_index;
    int on_stack;

}state;


// statemanager function holds the stack, the size of the stack, and the top index
// size of stack is used to see capacity
// while top index is used to see how close it is to capacity so more memory can be allocated if needed
// stack points to the pointers of the states on the stack

typedef struct
{
    state **stack;
    int capacity;
    int top;
}statemanager;

//TODO: create state fucntions

// initilises the statemanager
int STATEMANAGER_INIT(statemanager *statemanager);

// calls the update function of the top state
int STATEMANAGER_UPDATE(statemanager *statemanager);

// calls the draw function of the top state
int STATEMANAGER_DRAW(statemanager *statemanager);

// pops the top state
int STATEMANAGER_POP(statemanager *statemanager);

// pushes a new state to the top
int STATEMANAGER_PUSH(statemanager *statemanager, state *state);

// scales the stack to increase capacity
int STATEMANAGER_SCALE(statemanager *statemanager);

//returns the top state
int STATEMANAGER_TOP(statemanager *statemanager);

//TODO: add descriptons for the functions

int STATE_INIT(state *state);
int STATE_UPDATE(state *state);
int STATE_DRAW(state *state);
int STATE_DESTROY(state *state);

#endif