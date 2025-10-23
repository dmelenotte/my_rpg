/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-myrpg-guillaume1.blondel
** File description:
** set_sprite_origin.c
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../../Data/data.h"
#include "../ecs_components.h"

void origin_sprite(component_sprite_t *sprite, sfVector2f origin)
{
    if (sprite->sprite == NULL) {
        return;
    }
    sfSprite_setOrigin(sprite->sprite, origin);
}
