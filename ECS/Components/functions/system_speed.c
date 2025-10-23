/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-myrpg-guillaume1.blondel
** File description:
** system_speed.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../ecs_components.h"

component_speed_t *set_speed(void)
{
    component_speed_t *speed = NULL;

    speed = malloc(sizeof(component_speed_t));
    if (speed == NULL) {
        exit(84);
    }
    memset(speed, 0, sizeof(component_speed_t));
    return speed;
}

void assign_speed(component_speed_t *speed, float var_speed)
{
    if (speed != NULL) {
        speed->speed = var_speed;
    } else {
        dprintf(2, "Error: speed component probably don't assigned\n");
    }
}
