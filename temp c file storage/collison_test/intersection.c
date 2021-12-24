#include<stdio.h> 
#include<stdlib.h>

// try to make code to see if two rects itersect

/*

-> positive x

|
v
positive y

x E [0, 1920]
y E [0, 1080]

*/


// two test rects

typedef struct
{
    int x;
    int y;
    int h;
    int w;
}rect;

typedef int line[2];


int main()
{
    // rect perameters

    rect rect1;
    rect rect2;

    rect1.x = 11;
    rect1.y = 10;
    rect1.h =10;
    rect1.w = 10;

    rect2.x = 10;
    rect2.y = 10;
    rect2.h =10;
    rect2.w = 10;






    // set up if statments to see the region of where the shit is curently
    // or see the relitive positions of the shit and calulate the intersection based on that
    //printf("%i", rect1.w)

    // 1 2 3 4 5 6
    // 

    // detect which corner of the rectagle is intersecting
    // let rect 2 be the rect that gets intersected and is static

    // top left corner
    //if(rect1.x >rect2.x && rect1.x < (rect2.x+rect2.w)) printf("1");
    //if(rect1.y >rect2.y && rect1.y < (rect2.y+rect2.h)) printf("2");

    // top right corner
    if((rect1.x >rect2.x && rect1.x < (rect2.x+rect2.w)) || rect1.y >rect2.y && rect1.y < (rect2.y+rect2.h) ) printf("top right\n");

    //bottom right corner
    if((rect1.x >rect2.x && rect1.x < (rect2.x+rect2.w)) || (rect1.y+rect1.h) >rect2.y && (rect1.y+rect1.h) < (rect2.y+rect2.h) ) printf("bottom right\n");

    //top left corner
    if(((rect1.x + rect1.w) >rect2.x && (rect1.x + rect1.w) < (rect2.x+rect2.w)) || rect1.y >rect2.y && rect1.y < (rect2.y+rect2.h) ) printf("top left\n");

    //bottom left
    if(((rect1.x + rect1.w) >rect2.x && (rect1.x + rect1.w) < (rect2.x+rect2.w)) || rect1.y >rect2.y && rect1.y < (rect2.y+rect2.h) ){

    printf("top left\n");
    }

    
    // set up switch statement to do shit



    return 0;
}
