/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-myrpg-guillaume1.blondel
** File description:
** ECS_List_Components.h
*/

#ifndef ECS_LIST_COMPONENTS
    #define ECS_LIST_COMPONENTS

    #include "../Components/ecs_components.h"

typedef struct entity_s entity_t;

typedef struct list_components_s {
    enum components_types_s type;
    void *component;
    struct list_components_s *next;
} list_components_t;

void append_component_to_entity(entity_t *list_entity, char *name_entity,
    enum components_types_s type, void *component);
list_components_t *free_components(list_components_t *components);
void *find_component(entity_t *list_entity,
    char *name_entity, enum components_types_s type);

#endif
