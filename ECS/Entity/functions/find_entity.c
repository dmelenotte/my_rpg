/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-myrpg-guillaume1.blondel
** File description:
** find_entity.c
*/

#include <string.h>
#include "../ecs_entity.h"

entity_t *find_entity(entity_t *list_entity, char *name_entity)
{
    entity_t *tmp_entity = list_entity;

    for (; tmp_entity != NULL; tmp_entity = tmp_entity->next) {
        if (!strcmp(tmp_entity->name_entity, name_entity)) {
            return tmp_entity;
        }
    }
    return NULL;
}

entity_t *find_entity_by_type(entity_t *list_entity,
    enum type_entity_s type, bool reset)
{
    static entity_t *entity_find = NULL;
    entity_t *tmp_entity = NULL;

    if (reset == true) {
        tmp_entity = list_entity;
        entity_find = NULL;
    } else {
        if (entity_find != NULL) {
            tmp_entity = entity_find->next;
        }
    }
    for (; tmp_entity != NULL; tmp_entity = tmp_entity->next) {
        if (tmp_entity->type == type) {
            entity_find = tmp_entity;
            return entity_find;
        }
    }
    return NULL;
}
