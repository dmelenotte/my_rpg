/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-myrpg-guillaume1.blondel
** File description:
** destroy_global_data.c
*/

#include <string.h>
#include <stdlib.h>
#include "../data.h"

static void destroy_sprite(sprite_t *sprites)
{
    for (int i = 0; sprites[i].end_tab != true; i++) {
        sfSprite_destroy(sprites[i].sprite);
        free(sprites[i].sprite_name);
        memset(&sprites[i], 0, sizeof(sprite_t));
    }
}

static void destroy_texture(texture_t *textures)
{
    for (int i = 0; textures[i].end_tab != true; i++) {
        sfTexture_destroy(textures[i].texture);
        free(textures[i].texture_name);
        memset(&textures[i], 0, sizeof(texture_t));
    }
}

void destroy_global_data(global_data_t *global_data)
{
    destroy_sprite(global_data->sprite_data);
    destroy_texture(global_data->textures_data);
    free(global_data->sprite_data);
    free(global_data->textures_data);
}
