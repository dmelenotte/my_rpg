/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-myrpg-guillaume1.blondel
** File description:
** read_config_file.c
*/

#include <string.h>
#include "../data.h"

static void init_config_texture(global_data_t *global_data,
    const config_texture_t *conf_textures)
{
    for (int i = 0; conf_textures[i].end_tab != true; i++) {
        load_texture(global_data, conf_textures[i].file_path,
            conf_textures[i].texture_name);
    }
}

static void init_config_sprite(global_data_t *global_data,
    const config_sprite_t *conf_sprite)
{
    for (int i = 0; conf_sprite[i].end_tab != true; i++) {
        load_sprite(global_data, conf_sprite[i].texture_name,
            conf_sprite[i].sprite_name);
    }
}

void read_config(global_data_t *global_data,
    const config_texture_t *conf_textures,
    const config_sprite_t *conf_sprites)
{
    if (global_data->textures_data == NULL ||
        global_data->sprite_data == NULL) {
        return;
    }
    init_config_texture(global_data, conf_textures);
    init_config_sprite(global_data, conf_sprites);
}
