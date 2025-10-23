/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-myrpg-guillaume1.blondel
** File description:
** system_sprite.c
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../../Data/data.h"
#include "../ecs_components.h"

component_sprite_t *set_sprite(void)
{
    component_sprite_t *sprite = NULL;

    sprite = malloc(sizeof(component_sprite_t));
    if (sprite == NULL) {
        exit(84);
    }
    memset(sprite, 0, sizeof(component_sprite_t));
    return sprite;
}

void assign_sprite(component_sprite_t *sprite, char *sprite_name,
    global_data_t global_data)
{
    if (sprite == NULL || sprite_name == NULL) {
        dprintf(2, "Error: sprite / sprite_name probably don't assigned\n");
        return;
    }
    for (int i = 0; global_data.sprite_data[i].end_tab != true; i++) {
        if (!strcmp(sprite_name, global_data.sprite_data[i].sprite_name)) {
            sprite->sprite = global_data.sprite_data[i].sprite;
            return;
        }
    }
}

void assign_sprite_position(component_sprite_t *sprite,
    component_position_t *position)
{
    if (position != NULL) {
        if (sprite->sprite == NULL) {
            return;
        }
        sfSprite_setPosition(sprite->sprite,
            (sfVector2f){position->x, position->y});
    } else {
        dprintf(2, "Error: sprite / position probably don't assigned\n");
    }
}

void assign_sprite_scale(component_sprite_t *sprite, component_scale_t *scale)
{
    if (scale != NULL) {
        if (sprite->sprite == NULL) {
            return;
        }
        sfSprite_setScale(sprite->sprite,
            (sfVector2f){scale->scale_x, scale->scale_y});
    } else {
        dprintf(2, "Error: sprite / scale probably don't assigned\n");
    }
}

void display_sprite(component_sprite_t *sprite, sfRenderWindow *window)
{
    if (sprite != NULL) {
        if (sprite->sprite == NULL) {
            return;
        }
        sfRenderWindow_drawSprite(window, sprite->sprite, NULL);
    } else {
        dprintf(2, "Error: sprite probably don't assigned\n");
    }
}
