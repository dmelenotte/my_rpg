/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-myrpg-guillaume1.blondel
** File description:
** data.h
*/

#ifndef DATA
    #define DATA

    #include <stdbool.h>
    #include <SFML/Graphics.h>

typedef struct config_texture_s {
    char *texture_name;
    char *file_path;
    bool end_tab;
} config_texture_t;

typedef struct config_sprite_s {
    char *sprite_name;
    char *texture_name;
    bool end_tab;
} config_sprite_t;

typedef struct texture_s {
    sfTexture *texture;
    char *texture_name;
    int id_texture;
    bool end_tab;
} texture_t;

typedef struct sprite_s {
    sfSprite *sprite;
    char *sprite_name;
    int id_sprite;
    bool end_tab;
} sprite_t;

typedef struct global_data_s {
    texture_t *textures_data;
    sprite_t *sprite_data;
} global_data_t;

global_data_t init_global_data(void);
void read_config(global_data_t *global_data,
    const config_texture_t *conf_textures,
    const config_sprite_t *conf_sprites);
void load_texture(global_data_t *global_data, char *file_path,
    char *texture_name);
void load_sprite(global_data_t *global_data, char *texture_name,
    char *sprite_name);
void destroy_global_data(global_data_t *global_data);

#endif
