/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-myrpg-guillaume1.blondel
** File description:
** init_global_data.c
*/

#include <stdlib.h>
#include <string.h>
#include "../data.h"

global_data_t init_global_data(void)
{
    global_data_t global_data = {0};

    global_data.textures_data = malloc(1 * sizeof(texture_t));
    memset(global_data.textures_data, 0, 1 * sizeof(texture_t));
    global_data.textures_data->end_tab = true;
    global_data.sprite_data = malloc(1 * sizeof(sprite_t));
    memset(global_data.sprite_data, 0, 1 * sizeof(sprite_t));
    global_data.sprite_data->end_tab = true;
    return global_data;
}
