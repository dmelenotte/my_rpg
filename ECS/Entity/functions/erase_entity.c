/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-myrpg-guillaume1.blondel
** File description:
** erase_entity.c
*/

#include <stdlib.h>
#include <string.h>
#include "../ecs_entity.h"

static void free_entity(entity_t *entity)
{
    free(entity->name_entity);
    free_components(entity->components);
    free(entity);
}

entity_t *erase_entity(entity_t *list_entity, char *name_entity)
{
    entity_t *tmp_entity = list_entity;
    entity_t *entity_to_erase = NULL;

    if (!strcmp(list_entity->name_entity, name_entity)) {
        entity_to_erase = list_entity;
        list_entity = list_entity->next;
        free_entity(entity_to_erase);
    }
    for (; tmp_entity->next != NULL; tmp_entity = tmp_entity->next) {
        if (!strcmp(tmp_entity->next->name_entity, name_entity)) {
            entity_to_erase = tmp_entity->next;
            tmp_entity->next = tmp_entity->next->next;
            free(entity_to_erase);
        }
    }
    return list_entity;
}

void delete_list_entity(entity_t *list_entity)
{
    entity_t *tmp_entity = NULL;

    while (list_entity != NULL) {
        tmp_entity = list_entity;
        list_entity = list_entity->next;
        free(tmp_entity->name_entity);
        free_components(list_entity->components);
        free(tmp_entity);
        tmp_entity = NULL;
    }
}
