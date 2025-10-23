/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-myrpg-guillaume1.blondel
** File description:
** system_collision.c
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../ecs_components.h"

bool global_enter_in_collision(component_sprite_t *sprite1,
    component_sprite_t *sprite2)
{
    sfFloatRect box_sprite1 = {0};
    sfFloatRect box_sprite2 = {0};
    sfFloatRect intersect = {0};

    box_sprite1 = sfSprite_getGlobalBounds(sprite1->sprite);
    box_sprite2 = sfSprite_getGlobalBounds(sprite2->sprite);
    if (sfFloatRect_intersects(&box_sprite1, &box_sprite2, &intersect)) {
        return true;
    }
    return false;
}

bool local_enter_in_collision(component_sprite_t *sprite1,
    component_sprite_t *sprite2)
{
    sfFloatRect box_sprite1 = {0};
    sfFloatRect box_sprite2 = {0};
    sfFloatRect intersect = {0};

    box_sprite1 = sfSprite_getLocalBounds(sprite1->sprite);
    box_sprite2 = sfSprite_getLocalBounds(sprite2->sprite);
    if (sfFloatRect_intersects(&box_sprite1, &box_sprite2, &intersect)) {
        return true;
    }
    return false;
}
