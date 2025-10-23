/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-myrpg-guillaume1.blondel
** File description:
** system_color.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../ecs_components.h"

component_color_t *set_color(void)
{
    component_color_t *color = NULL;

    color = malloc(sizeof(component_color_t));
    if (color == NULL) {
        exit(84);
    }
    memset(color, 0, sizeof(component_color_t));
    return color;
}

void assign_fill_color(component_color_t *color, sfColor fill_color)
{
    if (color != NULL) {
        color->fill_color = fill_color;
    } else {
        dprintf(2, "Error: color component probably don't load");
    }
}

void assign_outline_color(component_color_t *color, sfColor outline_color)
{
    if (color != NULL) {
        color->outline_color = outline_color;
    } else {
        dprintf(2, "Error: color component probably don't load");
    }
}

void assign_outline_thickness(component_color_t *color,
    float outline_thickness)
{
    if (color != NULL) {
        color->outline_thickness = outline_thickness;
    } else {
        dprintf(2, "Error: color component probably don't load");
    }
}
