#ifndef JSON__h
#define JSON__h



typedef struct{
    char *base_level_location;
    char *file_name;
    int level_x_dim;
    int level_y_dim;
    int moveable;

}background;

typedef struct{
    char *defult_image;
    int number_of_animations;
    char *animations_folder;
    // dynamicly allocate the image information
    char animation_images_left[20][100];
    char animation_images_right[20][100];
    char animation_images_forward[20][100];
    char animation_images_backword[20][100];

    float starting_pos_y;
    float strating_pos_x;

    int rect_dim_x;
    int rect_dim_y;

    char *file_location;
    char *file_name;

    float image_scale_x;
    float image_scale_y;
    float image_rotation;

}main_character;

typedef struct{
    char *npc_name;
    char *npc_dialoge_location;
    float starting_pos_x;
    float starting_pos_y;

    float npc_rect_dim_x;
    float npc_rect_dim_y;

    // use for loops and shit to create array and assign it to this pointer
    int npc_movement_path[100][2];
    char *npc_trigger_index;
}npc_info;


typedef struct{
    int number_of_npcs;
    npc_info *npc_info_data;


}npc;

typedef struct{
    char *type;

    float pos_x;
    float pos_y;
    
    float dim_x;
    float dim_y;
    
    char *trigger_event;

}trigger;

typedef struct{
    int trigger_exist;
    int number_of_triggers;
    trigger *trigger_list;
}trigger_list;

typedef struct{
    background background_data;
    main_character main_character_data;
    npc npc_data;
    trigger_list trigger_data;

}level;


int parse_file();
background parse_background_json();
main_character parse_main_character_data();
npc parse_npc();
trigger_list parse_triggers();



#endif