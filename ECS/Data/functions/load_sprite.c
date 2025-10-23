/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-myrpg-guillaume1.blondel
** File description:
** load_sprite.c
*/

#include <stdlib.h>
#include <string.h>
#include "../data.h"

static void append_sprite_to_data(global_data_t *global_data,
    sfSprite *new_sprite, char *sprite_name)
{
    int nb_sprites = 1;
    int i = 0;

    for (; global_data->sprite_data[i].end_tab != true; i++) {
        nb_sprites++;
    }
    global_data->sprite_data[i].sprite = new_sprite;
    global_data->sprite_data[i].sprite_name = strdup(sprite_name);
    global_data->sprite_data[i].id_sprite = i;
    global_data->sprite_data[i].end_tab = false;
    global_data->sprite_data = realloc(global_data->sprite_data,
        (nb_sprites + 1) * sizeof(sprite_t));
    memset(&global_data->sprite_data[nb_sprites], 0, sizeof(sprite_t));
    global_data->sprite_data[nb_sprites].end_tab = true;
}

static sfTexture *search_sprite(global_data_t *global_data, char *texture_name)
{
    for (int i = 0; global_data->textures_data[i].end_tab != true; i++) {
        if (!strcmp(global_data->textures_data[i].texture_name,
        texture_name)) {
            return global_data->textures_data[i].texture;
        }
    }
    return NULL;
}

void load_sprite(global_data_t *global_data, char *texture_name,
    char *sprite_name)
{
    sfSprite *new_sprite = NULL;
    sfTexture *research_texture = NULL;

    new_sprite = sfSprite_create();
    if (new_sprite == NULL) {
        exit(84);
    }
    research_texture = search_sprite(global_data, texture_name);
    if (research_texture == NULL) {
        sfSprite_destroy(new_sprite);
        return;
    }
    sfSprite_setTexture(new_sprite, research_texture, sfTrue);
    append_sprite_to_data(global_data, new_sprite, sprite_name);
}
