#include<stdio.h>
#include<stdlib.h>


typedef struct
{
    int value;
    char* letters;
}test;






int main(int argc, char const *argv[])
{

    test t;
    t.value = 1;
    t.letters = malloc(sizeof("c")*t.value);
    t.letters[0] = 'c';
    t.letters[1] = 'h';

    printf("%c", *t.letters);
    printf("%i", sizeof(t.letters));

    return 0;
}
