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
    char animation_images_left[1][100];
    char animation_images_right[1][100];
    char animation_images_forward[1][100];
    char animation_images_backword[1][100];

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
    int starting_pos[2];
    int npc_rect_dim[2];

    // use for loops and shit to create array and assign it to this pointer
    int *npc_movement_path;
    char *npc_trigger_index;
}npc_info;


typedef struct{
    int number_of_npcs;
    npc_info npc_info[];


}npc;

typedef struct{
    char *type;

    int cords[2];
    int dims[2];
    
    char *trigger_event;

}trigger;

typedef struct{
    int trigger_exist;
    int number_of_triggers;
}trigger_list;

typedef struct{
    int hello;
}level;


int parse_file();



#endif