/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-myrpg-guillaume1.blondel
** File description:
** rotate_sprite.c
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../../Data/data.h"
#include "../ecs_components.h"

component_rotation_t *set_rotation(void)
{
    component_rotation_t *rotation = NULL;

    rotation = malloc(sizeof(component_rotation_t));
    if (rotation == NULL) {
        exit(84);
    }
    memset(rotation, 0, sizeof(component_rotation_t));
    return rotation;
}

void assign_rotation(component_rotation_t *rotation, float angle)
{
    if (rotation == NULL) {
        return;
    }
    rotation->angle = angle;
}

void assign_sprite_rotation(component_sprite_t *sprite,
    component_rotation_t *rotation)
{
    if (sprite == NULL || rotation == NULL) {
        return;
    }
    sfSprite_setRotation(sprite->sprite, rotation->angle);
}

void change_rotation(component_rotation_t *rotation, float value,
    enum operation_s operation)
{
    if (rotation == NULL) {
        return;
    }
    if (operation == ADD) {
        rotation->angle += value;
    } else {
        rotation->angle -= value;
    }
}
