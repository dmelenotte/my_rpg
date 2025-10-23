/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-myrpg-guillaume1.blondel
** File description:
** ECS_Entity.h
*/

#ifndef ECS_ENTITY
    #define ECS_ENTITY

    #include <stdbool.h>
    #include "../ECS_List_Components/ecs_list_components.h"

enum type_entity_s {
    PLAYER,
    ENEMY,
    BOSS,
    WEAPON,
    NPC,
    MAP,
    BUTTON,
    UI,
    OBJECT,
    PARTICLE
};

typedef struct entity_s {
    char *name_entity;
    enum type_entity_s type;
    list_components_t *components;
    struct entity_s *next;
} entity_t;

entity_t *load_entity(entity_t *list_entity, char *name_entity,
    enum type_entity_s type);
entity_t *erase_entity(entity_t *list_entity, char *name_entity);
entity_t *find_entity(entity_t *list_entity, char *name_entity);
entity_t *find_entity_by_type(entity_t *list_entity,
    enum type_entity_s type, bool reset);
void delete_list_entity(entity_t *list_entity);

#endif
