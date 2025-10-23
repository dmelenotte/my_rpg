/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-myrpg-guillaume1.blondel
** File description:
** system_scale.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../ecs_components.h"

component_scale_t *set_scale(void)
{
    component_scale_t *scale = NULL;

    scale = malloc(sizeof(component_scale_t));
    if (scale == NULL) {
        exit(84);
    }
    memset(scale, 0, sizeof(component_scale_t));
    return scale;
}

void assign_scale(component_scale_t *scale, float x, float y)
{
    if (scale != NULL) {
        scale->scale_x = x;
        scale->scale_y = y;
    } else {
        dprintf(2, "Error: scale component probably don't assigned\n");
    }
}
