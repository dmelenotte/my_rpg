/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-myrpg-guillaume1.blondel
** File description:
** load_entity.c
*/

#include <stdlib.h>
#include <string.h>
#include "../ecs_entity.h"

static entity_t *append_end_list_entity(entity_t *list_entity,
    entity_t *new_entity)
{
    entity_t *tmp_entity = list_entity;

    for (; tmp_entity->next != NULL; tmp_entity = tmp_entity->next);
    tmp_entity->next = new_entity;
    return list_entity;
}

entity_t *load_entity(entity_t *list_entity, char *name_entity,
    enum type_entity_s type)
{
    entity_t *new_entity = NULL;

    new_entity = malloc(sizeof(entity_t));
    if (new_entity == NULL) {
        exit(84);
    }
    memset(new_entity, 0, sizeof(entity_t));
    new_entity->name_entity = name_entity;
    new_entity->type = type;
    if (list_entity == NULL) {
        list_entity = new_entity;
        return list_entity;
    }
    list_entity = append_end_list_entity(list_entity, new_entity);
    return list_entity;
}
