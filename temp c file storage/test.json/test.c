#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>

typedef struct
{
    char i[50];
}test;

typedef struct{
    test test1[3];
}tests;




int main(){
    test test2;
    test test3;
    test test4;

    tests tests1;
    strcpy(test2.i, "hello world");
    strcpy(test3.i, "hellow world");
    strcpy(test4.i, "hellow world");

    //test2.i = "hello world";
    //test3.i = "hello world";
    //test4.i = "hello world";

    test testlist[] = {test2,test3,test4};

    for(int i =0; i<sizeof(testlist)/sizeof(testlist[0]); i++){
        int x;
        tests1.test1[i] = testlist[i];

        x = 2;
        printf("%i", x);
    };

    //tests1.test1 = testlist;
    //strcpy(test2->test_char[0], tet);
    //strcpy(test3.test_char[0], "hellow world");
    //strcpy(test4.test_char[0], "hellow world");
    printf("%s", tests1.test1[0].i);
    //printf("%s 1",test2.test_char[0]);

    //for(int i = 0; i<10;i++){
    //    tests1.test1[i] = test2;
    //}
    
    //printf("%s", tests1.test1[0].test_char[0]);



    return 0;
}