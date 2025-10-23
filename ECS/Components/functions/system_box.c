/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-myrpg-guillaume1.blondel
** File description:
** system_box.c
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../ecs_components.h"

component_box_t *set_box(void)
{
    component_box_t *box = NULL;

    box = malloc(sizeof(component_box_t));
    if (box == NULL) {
        exit(84);
    }
    memset(box, 0, sizeof(component_box_t));
    return box;
}

void assign_sprite_box(component_box_t *box, component_sprite_t *sprite)
{
    if (box != NULL) {
        box->global_box = sfSprite_getGlobalBounds(sprite->sprite);
        box->local_box = sfSprite_getLocalBounds(sprite->sprite);
    } else {
        dprintf(2, "Error: box / sprite component probably don't assigned\n");
    }
}

void assign_rect_box(component_box_t *box, component_rect_t *rect)
{
    if (box != NULL) {
        box->global_box = sfRectangleShape_getGlobalBounds(rect->rect);
        box->local_box = sfRectangleShape_getLocalBounds(rect->rect);
    } else {
        dprintf(2, "Error: box / rect component probably don't assigned\n");
    }
}

void assign_circle_box(component_box_t *box, component_circle_t *circle)
{
    if (box != NULL) {
        box->global_box = sfCircleShape_getGlobalBounds(circle->circle);
        box->local_box = sfCircleShape_getLocalBounds(circle->circle);
    } else {
        dprintf(2, "Error: box / circle component probably don't assigned\n");
    }
}

static bool check_local_collision(component_box_t *box_1,
    component_box_t *box_2)
{
    sfFloatRect intersect = {0};

    if (sfFloatRect_intersects(&box_1->local_box,
        &box_2->local_box, &intersect)) {
        return true;
    }
    return false;
}

static bool check_global_collision(component_box_t *box_1,
    component_box_t *box_2)
{
    sfFloatRect intersect = {0};

    if (sfFloatRect_intersects(&box_1->global_box,
        &box_2->global_box, &intersect)) {
        return true;
    }
    return false;
}

bool check_collisions(component_box_t *box_1, component_box_t *box_2,
    enum get_collisions_s get)
{
    bool collisions = false;

    if (box_1 == NULL || box_2 == NULL) {
        dprintf(2, "Error: box_1 / box_2 component probably don't assigned\n");
        return false;
    }
    if (get == LOCAL) {
        collisions = check_local_collision(box_1, box_2);
    }
    if (get == GLOBAL) {
        collisions = check_global_collision(box_1, box_2);
    }
    return collisions;
}
