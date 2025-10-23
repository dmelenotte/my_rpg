/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-myrpg-guillaume1.blondel
** File description:
** free_components.c
*/

#include <stdlib.h>
#include <string.h>
#include "../ecs_list_components.h"

list_components_t *free_components(list_components_t *components)
{
    list_components_t *tmp_component = NULL;

    if (components == NULL) {
        return NULL;
    }
    tmp_component = components;
    for (; components != NULL;) {
        components = components->next;
        free(tmp_component->component);
        free(tmp_component);
    }
    return NULL;
}
