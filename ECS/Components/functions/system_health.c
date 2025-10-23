/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-myrpg-guillaume1.blondel
** File description:
** system_health.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../ecs_components.h"

component_health_t *set_health(void)
{
    component_health_t *health = NULL;

    health = malloc(sizeof(component_health_t));
    if (health == NULL) {
        exit(84);
    }
    memset(health, 0, sizeof(component_health_t));
    return health;
}

void assign_max_health(component_health_t *health, int value)
{
    health->max_health = value;
    health->current_health = value;
}

void change_health(component_health_t *health, int value)
{
    health->current_health += value;
    if (health->current_health >= health->max_health) {
        health->current_health = health->max_health;
    }
}

bool check_health(component_health_t *health, int threshold)
{
    if (health->current_health <= threshold) {
        return true;
    }
    return false;
}
