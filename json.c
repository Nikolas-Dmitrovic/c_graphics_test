#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<string.h>
#include"cJSON.h"
#include"JSON.h"

// move all this shit into a .h file for fucks sake

int parse_file(char *filename, level level_data){
    FILE *fp;

    // change this to dynamicaly alocate the memeory or someshit idk

    fp = fopen(filename, "r");

    int buffer_memory = 1024;

    char *buffer = _alloca(buffer_memory);

    read:
        fread(buffer, 1024, 1, fp);

    // checks if the buffer file is full
    // if full it frees the buffer
    // allocates more memory
    // and goes back to read

    
    if(buffer[1023] != NULL){
        printf("hello \n");
        free(buffer);
        buffer_memory *= 2;
        buffer = _alloca(buffer_memory);
        goto read;
    }
    

    level leveldata;



    printf("%i", sizeof(buffer));

    return 1;
};

/*
int main(){

    /* FILE *fp;
    char buffer[1024];

    fp = fopen("test.json", "r");
    fread(buffer,1024,1,fp);

    const cJSON *name1 = NULL;
    const cJSON *name2 = NULL;
    const cJSON *age = NULL;
    const cJSON *friends = NULL;
    const cJSON *friend = NULL;
    char string[2][10];
    int i = 0;
    int len = 0;

    cJSON *json = cJSON_Parse(buffer);

    name1 = cJSON_GetObjectItemCaseSensitive(json, "name1");
    name2 = cJSON_GetObjectItemCaseSensitive(name1, "name2");

    friends = cJSON_GetObjectItemCaseSensitive(json, "friends");
    cJSON_ArrayForEach(friend, friends){
        strcpy(string[i],friend->valuestring);
        //printf("%s \n", friend->valuestring);
        i++;
        
    };
    //printf("%s \n", name2->valuestring);

    //printf("%s \n", string[0]);


    //printf("%i", sizeof(*friend->valuestring)/sizeof(friend->valuestring[0]));
    cJSON_Delete(json);

    char *f = "test.json";

    //parse_file(f);

    return 1;

}

*/