#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<string.h>
#include"cJSON.h"
#include"JSON.h"

//TODO refactor json format to be more consitant to compar to code so it does not fuck up lmao
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
    
    cJSON *json = cJSON_Parse(buffer);
    level_data.background_data = parse_background_json(json);





    printf("%i", sizeof(buffer));



    return 1;
};

background parse_background_json(cJSON *json){
    background background_data;

    cJSON *background_class = NULL;
    cJSON *base_level_location = NULL;
    cJSON *file_name = NULL;
    cJSON *level_x_dim = NULL;
    cJSON *level_y_dim = NULL;
    cJSON *moveable = NULL;

    background_class = cJSON_GetObjectItemCaseSensitive(json, "background");

    base_level_location = cJSON_GetObjectItemCaseSensitive(background_class,"base_level_location");
    file_name = cJSON_GetObjectItemCaseSensitive(background_class,"file_name");
    level_x_dim = cJSON_GetObjectItemCaseSensitive(background_class,"level_x_dim");
    level_y_dim = cJSON_GetObjectItemCaseSensitive(background_class, "level_y_dim");
    moveable = cJSON_GetObjectItemCaseSensitive(background_class, "movable");

    background_data.base_level_location = base_level_location->valuestring;
    background_data.file_name = file_name->valuestring;
    background_data.level_x_dim = level_x_dim->valueint;
    background_data.level_y_dim = level_y_dim->valueint;

    if(moveable->valuestring == "true"){
        background_data.moveable = 1;
    }else if (moveable->valuestring == "false"){
        background_data.moveable = 0;
    }
    
    return background_data;
    
};

main_character parse_main_character_data(cJSON *json){
    main_character main_character_data;

    cJSON *main_character_class;

    cJSON *defult_image;
    cJSON *number_of_animations;
    cJSON *animations_folder;

    //TODO try this shit lmao
    // dynamicly allocate the image information
    cJSON *animation_images_left = NULL;
    cJSON *animation_images_right[1][100];
    cJSON *animation_images_forward[1][100];
    cJSON *animation_images_backword[1][100];

    cJSON *starting_pos_y;
    cJSON *strating_pos_x;

    cJSON *rect_dim_x;
    cJSON *rect_dim_y;

    cJSON *file_location;
    cJSON *file_name;

    cJSON *image_scale_x;
    cJSON *image_scale_y;
    cJSON *image_rotation;


    main_character_class = cJSON_GetObjectItemCaseSensitive(json, "main_character");

    defult_image = cJSON_GetObjectItemCaseSensitive(main_character_class, "defult_image");
    number_of_animations = cJSON_GetObjectItemCaseSensitive(main_character_class, "number_of_animations");
    animations_folder = cJSON_GetObjectItemCaseSensitive(main_character_class, "animations_folder");

    // see if you need to parse these into a list
    animation_images_left = cJSON_GetObjectItemCaseSensitive(main_character_class, "animation_images_left");

    char *animation_image_left;
    do{

    }while (2>1);
    



};


int main(){

    FILE *fp;
    char buffer[1024];

    fp = fopen("test.json", "r");
    fread(buffer,1024,1,fp);

    const cJSON *name1 = NULL;
    const cJSON *name2 = NULL;
    const cJSON *age = NULL;
    const cJSON *friends = NULL;
    const cJSON *friend = NULL;
    char *string;
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
