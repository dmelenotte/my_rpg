/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-myrpg-guillaume1.blondel
** File description:
** find_component.c
*/

#include <string.h>
#include <stdio.h>
#include "../ecs_list_components.h"
#include "../../Entity/ecs_entity.h"

void *find_component(entity_t *list_entity,
    char *name_entity, enum components_types_s type)
{
    list_components_t *tmp_component = NULL;
    entity_t *entity = NULL;

    entity = find_entity(list_entity, name_entity);
    if (entity == NULL) {
        dprintf(2, "Entity not found\n");
        return NULL;
    }
    tmp_component = entity->components;
    if (tmp_component == NULL) {
        dprintf(2, "Nothing component to entity\n");
        return NULL;
    }
    for (; tmp_component != NULL; tmp_component = tmp_component->next) {
        if (tmp_component->type == type) {
            return tmp_component->component;
        }
    }
    return NULL;
}
