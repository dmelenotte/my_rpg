/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-myrpg-guillaume1.blondel
** File description:
** load_texture.c
*/

#include <stdlib.h>
#include <string.h>
#include "../data.h"

static void append_texture_to_data(global_data_t *global_data,
    sfTexture *new_texture, char *texture_name)
{
    int nb_textures = 1;
    int i = 0;

    for (; global_data->textures_data[i].end_tab != true; i++) {
        nb_textures++;
    }
    global_data->textures_data[i].texture = new_texture;
    global_data->textures_data[i].texture_name = strdup(texture_name);
    global_data->textures_data[i].id_texture = i;
    global_data->textures_data[i].end_tab = false;
    global_data->textures_data = realloc(global_data->textures_data,
        (nb_textures + 1) * sizeof(texture_t));
    memset(&global_data->textures_data[nb_textures], 0, sizeof(texture_t));
    global_data->textures_data[nb_textures].end_tab = true;
}

void load_texture(global_data_t *global_data, char *file_path,
    char *texture_name)
{
    sfTexture *new_texture = NULL;

    new_texture = sfTexture_createFromFile(file_path, NULL);
    if (new_texture == NULL) {
        exit(84);
    }
    append_texture_to_data(global_data, new_texture, texture_name);
}
