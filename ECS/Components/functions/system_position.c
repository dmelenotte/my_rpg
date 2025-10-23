/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-myrpg-guillaume1.blondel
** File description:
** system_position.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../ecs_components.h"

component_position_t *set_position(void)
{
    component_position_t *position = NULL;

    position = malloc(sizeof(component_position_t));
    if (position == NULL) {
        exit(84);
    }
    memset(position, 0, sizeof(component_position_t));
    return position;
}

void assign_position(component_position_t *position, float x, float y)
{
    if (position != NULL) {
        position->x = x;
        position->y = y;
    } else {
        dprintf(2, "Error: position component probably don't assigned\n");
    }
}

void move_position(component_position_t *position, component_frame_t *frame,
    sfVector2f vector)
{
    if (position != NULL && frame != NULL) {
        position->x += vector.x * sfTime_asSeconds(frame->frame_time);
        position->y += vector.y * sfTime_asSeconds(frame->frame_time);
    } else {
        dprintf(2, "Error: position / frame component probably "
            "don't assigned\n");
    }
}
