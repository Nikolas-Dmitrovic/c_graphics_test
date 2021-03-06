/*#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<string.h>
#include"cJSON.h"
#include"JSON.h"

//TODO refactor json format to be more consitant to compar to code so it does not fuck up lmao
// move all this shit into a .h file for fucks sake

int parse_file(char *filename, level *level_data){
    FILE *fp;

    // change this to dynamicaly alocate the memeory or someshit idk

    fp = fopen(filename, "r");

    size_t buffer_memory = 1024;

    char *buffer = _alloca(buffer_memory);

    read:
        fread(buffer, buffer_memory, 1, fp);
    //fread(buffer, 1024, 1, fp);
    // checks if the buffer file is full
    // if full it frees the buffer
    // allocates more memory
    // and goes back to read
    if(&buffer[buffer_memory-1] != NULL) printf("4 \n");
    buffer_memory = buffer_memory * 100;
    printf("%i \n", buffer_memory);
    buffer = realloc(buffer, buffer_memory);
    fread(buffer, 1024, 1, fp);
    //printf("%i", buffer[2]);
    if(&buffer[buffer_memory - 1] != NULL) printf("4 \n");
    printf("3 \n");

    if(&buffer[1023] == NULL) printf("this shit is finally done lmao\n");
    if(&buffer[1023] != NULL){
        printf("1 \n");
        buffer_memory = buffer_memory * 2;
        printf("2 \n");
        buffer = realloc(buffer, buffer_memory);
        printf("3 \n");
        //printf("hello \n");
        goto read;
    }
    //if(&buffer[1023] == NULL) printf("this shit is finally done lmao\n");
    
    printf("1 \n");
    cJSON *json = cJSON_Parse(buffer);
    printf("1 \n");
    level_data->background_data = parse_background_json(json);
    printf("2 \n");
    level_data->main_character_data = parse_main_character_data(json);
    printf("3 \n");
    level_data->npc_data = parse_npc(json);
    printf("4 \n");
    level_data->trigger_data = parse_triggers(json);
    printf("5 \n");
    

    //printf("%i", sizeof(buffer));



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
    cJSON *animation_images_left_json = NULL;
    cJSON *animation_images_right_json = NULL;
    cJSON *animation_images_forward_json = NULL;
    cJSON *animation_images_backword_json = NULL;

    cJSON *starting_pos_y;
    cJSON *starting_pos_x;

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
    animation_images_left_json = cJSON_GetObjectItemCaseSensitive(main_character_class, "animation_images_left");
    animation_images_right_json = cJSON_GetObjectItemCaseSensitive(main_character_class, "animation_images_right");
    animation_images_forward_json = cJSON_GetObjectItemCaseSensitive(main_character_class, "animation_images_forward");
    animation_images_backword_json = cJSON_GetObjectItemCaseSensitive(main_character_class, "animation_images_backword");

    fill_string_array(*main_character_data.animation_images_left, animation_images_left_json);
    fill_string_array(*main_character_data.animation_images_right, animation_images_right_json);
    fill_string_array(*main_character_data.animation_images_forward, animation_images_forward_json);
    fill_string_array(*main_character_data.animation_images_backword, animation_images_backword_json);

    starting_pos_y = cJSON_GetObjectItemCaseSensitive(main_character_class, "starting_pos_y");
    starting_pos_x = cJSON_GetObjectItemCaseSensitive(main_character_class, "starting_pos_x");

    rect_dim_x = cJSON_GetObjectItemCaseSensitive(main_character_class, "rect_dim_x");
    rect_dim_y = cJSON_GetObjectItemCaseSensitive(main_character_class, "rect_dim_y");

    file_location = cJSON_GetObjectItemCaseSensitive(main_character_class, "file_location");
    file_name = cJSON_GetObjectItemCaseSensitive(main_character_class, "file_name");

    image_scale_x = cJSON_GetObjectItemCaseSensitive(main_character_class, "image_scale_x");
    image_scale_y = cJSON_GetObjectItemCaseSensitive(main_character_class, "image_scale_y");
    image_rotation = cJSON_GetObjectItemCaseSensitive(main_character_class, "image_rotation");

    main_character_data.animations_folder = animations_folder->valuestring;
    main_character_data.defult_image = defult_image->valuestring;
    main_character_data.file_location  = file_location->valuestring;

    main_character_data.image_rotation = image_rotation->valuedouble;
    main_character_data.image_scale_x = image_scale_x->valuedouble;
    main_character_data.image_scale_y = image_scale_y->valuedouble;

    main_character_data.number_of_animations = number_of_animations->valueint;

    main_character_data.rect_dim_x = rect_dim_x->valueint;
    main_character_data.rect_dim_y = rect_dim_y->valueint;

    main_character_data.starting_pos_y = starting_pos_y->valuedouble;
    main_character_data.strating_pos_x = starting_pos_x->valuedouble;
};

int fill_string_array(char *animation_image_list,cJSON *json_list){
    int count = 0;
    cJSON *temp = NULL;

    cJSON_ArrayForEach(temp,json_list){
        strcpy(animation_image_list[count], temp->valuestring);
        count++;
    };

}

npc parse_npc(cJSON *json){
    npc npc_data;

    cJSON *npc_class = cJSON_GetObjectItemCaseSensitive(json,"npc");
    cJSON *number_of_npcs = cJSON_GetObjectItemCaseSensitive(npc_class, "number_of_npcs");
    cJSON *npc_information = cJSON_GetObjectItemCaseSensitive(npc_class, "npc_info");

    npc_data.npc_info_data;
    npc_info npc_list[number_of_npcs->valueint];
    int external_count = 0;

    cJSON *temp = NULL;
    cJSON_ArrayForEach(temp, npc_information){
        npc_info npc1;

        cJSON *npc_name_json = cJSON_GetObjectItemCaseSensitive(temp, "npc_name");
        cJSON *npc_dialoge_location_json = cJSON_GetObjectItemCaseSensitive(temp, "npc_dialoge_location");

        cJSON *npc_rect_dim_x_json = cJSON_GetObjectItemCaseSensitive(temp, "npc_rect_dim_x");
        cJSON *npc_rect_dim_y_json = cJSON_GetObjectItemCaseSensitive(temp, "npc_rect_dim_y");
        cJSON *npc_rect_pos_x_json = cJSON_GetObjectItemCaseSensitive(temp, "npc_rect_pos_x");
        cJSON *npc_rect_pos_y_json = cJSON_GetObjectItemCaseSensitive(temp, "npc_rect_pos_y");

        cJSON *npc_movement_path_json = cJSON_GetObjectItemCaseSensitive(temp, "npc_movemet_path");
        cJSON *npc_index_json  = cJSON_GetObjectItemCaseSensitive(temp, "npc_index");

        char *npc_name = npc_name_json->valuestring;
        char *npc_dialoge_location = npc_name_json->valuestring;

        float npc_rect_dim_x = npc_rect_dim_x_json->valuedouble;
        float npc_rect_dim_y = npc_rect_dim_y_json->valuedouble;
        float npc_rect_pos_x = npc_rect_pos_x_json->valuedouble;
        float npc_rect_pos_y = npc_rect_pos_y_json->valuedouble;

        float npc_movement_path[20][2];
        char *npc_index = npc_index_json->valuestring;

        cJSON *temp_movement = NULL;
        int movement_indexer = 0;
        int indexer_left_right = 0;
        cJSON_ArrayForEach(temp_movement, npc_movement_path_json){
            cJSON *temp_internal = NULL;
            cJSON_ArrayForEach(temp_internal, temp_movement){
                npc1.npc_movement_path[movement_indexer][indexer_left_right] = temp_internal->valuedouble;
                if(indexer_left_right == 1) indexer_left_right = 0;
                if(indexer_left_right == 0) indexer_left_right++;
            }
            movement_indexer++;
        };

        npc1.npc_dialoge_location = npc_dialoge_location;
        npc1.npc_name = npc_name;

        npc1.npc_rect_dim_x = npc_rect_dim_x;
        npc1.npc_rect_dim_y = npc_rect_dim_y;
        npc1.starting_pos_x = npc_rect_pos_x;
        npc1.starting_pos_y = npc_rect_pos_y;

        npc1.npc_trigger_index = npc_index;

        if(external_count <= number_of_npcs->valueint) npc_list[external_count] = npc1;
        external_count++;

    }

    npc_data.number_of_npcs = number_of_npcs->valueint;
    npc_data.npc_info_data = npc_list;



    return npc_data;
}

trigger_list parse_triggers(cJSON *json){
    trigger_list trigger_data;

    cJSON *triggers_json = cJSON_GetObjectItemCaseSensitive(json,"triggers");

    cJSON *triggers_exist_json = cJSON_GetObjectItemCaseSensitive(triggers_json, "trigger_exists");
    cJSON *number_of_triggers_json = cJSON_GetObjectItemCaseSensitive(triggers_json, "number_of_triggers");

    cJSON *temp_trigger = NULL;
    trigger trigger_list[number_of_triggers_json->valueint];
    int indexer = 0;
    cJSON_ArrayForEach(temp_trigger, triggers_json){
        cJSON *temp_internal = NULL;

        cJSON *type_json = cJSON_GetObjectItemCaseSensitive(temp_trigger,"type");
        cJSON *pos_x = cJSON_GetObjectItemCaseSensitive(temp_trigger, "pos_x");
        cJSON *pos_y = cJSON_GetObjectItemCaseSensitive(temp_trigger, "pos_y");
        cJSON *dim_x = cJSON_GetObjectItemCaseSensitive(temp_trigger, "dim_x");
        cJSON *dim_y = cJSON_GetObjectItemCaseSensitive(temp_trigger, "dim_y");
        cJSON *trigger_event = cJSON_GetObjectItemCaseSensitive(temp_trigger, "trigger_event");


        trigger trigger1;

        trigger1.type = type_json->valuestring;
        trigger1.trigger_event = trigger_event->valuestring;
        trigger1.pos_x = pos_x->valuedouble;
        trigger1.pos_y = pos_y->valuedouble;
        trigger1.dim_x = dim_x->valuedouble;
        trigger1.dim_y = dim_y->valuedouble;

        if(indexer <= number_of_triggers_json->valueint) trigger_list[indexer] = trigger1;
        indexer++;
    }

    trigger_data.number_of_triggers = number_of_triggers_json->valueint;
    trigger_data.trigger_exist = triggers_exist_json->valueint;
    trigger_data.trigger_list = trigger_list;

    return trigger_data;

};



int main(){

    level *level_data_test;

    char filename[] = "level_data.json";
    printf("whats good \n");
    parse_file(filename, level_data_test);
    printf("whats good \n");
    //printf("%i", level_data_test->background_data.level_x_dim);

    return 0;
};
*/ 