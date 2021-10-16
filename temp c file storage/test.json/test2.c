#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>

typedef struct
{
    char test_char[20][100];
}test;




int main(){
    char array[10][5] = {"12","34","56","78"};

    test test_struct;

    int num=0;
    int count = 0;
    //printf("%s", array[1]);
    //printf("%i", sizeof(array)/sizeof(array[0]));

    /*
    for(int i = 0; i<10;i++){
        printf("%s \n",array[i]);
    };*/

    
    for(int i = 0; i<(sizeof(array)/sizeof(array[0]));i++){
        strcpy(test_struct.test_char[i], array[i]);
        //printf("%s \n",array[i]);
    };

    //memcpy(test_struct.test_char, array, 100);

    printf("%s", test_struct.test_char[1]);

    return 0;
}