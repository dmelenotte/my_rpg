/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-myrpg-guillaume1.blondel
** File description:
** append_component.c
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../ecs_list_components.h"
#include "../../Entity/ecs_entity.h"

static void assign_data(list_components_t *new_component,
    enum components_types_s type, void *component)
{
    new_component->type = type;
    new_component->component = component;
}

static void append_to_queue(list_components_t **components,
    list_components_t *new_component)
{
    list_components_t *tmp_component = NULL;

    tmp_component = (*components);
    for (; tmp_component->next != NULL; tmp_component = tmp_component->next);
    tmp_component->next = new_component;
}

static list_components_t *append_component(list_components_t *components,
    enum components_types_s type, void *component)
{
    list_components_t *new_component = NULL;

    new_component = malloc(sizeof(list_components_t));
    memset(new_component, 0, sizeof(list_components_t));
    if (new_component == NULL) {
        exit(84);
    }
    assign_data(new_component, type, component);
    if (components == NULL) {
        components = new_component;
        return components;
    }
    append_to_queue(&components, new_component);
    return components;
}

void append_component_to_entity(entity_t *list_entity, char *name_entity,
    enum components_types_s type, void *component)
{
    entity_t *entity = NULL;

    entity = find_entity(list_entity, name_entity);
    if (entity == NULL) {
        dprintf(2, "Entity not found\n");
        return;
    }
    entity->components = append_component(entity->components, type, component);
}
