/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-myrpg-guillaume1.blondel
** File description:
** init_enemy.c
*/

#include "../include/rpg.h"

static void init_demon_assign(global_data_t global_data, entity_t *list_entity,
    char *entity_name, char *sprite_name)
{
    change_state(find_component(list_entity, entity_name, COMPONENT_STATE),
        SET_ACTIVE | SET_DISPLAY, false, true);
    assign_sprite(find_component(list_entity, entity_name,
        COMPONENT_SPRITE), sprite_name, global_data);
    assign_scale(find_component(list_entity, entity_name, COMPONENT_SCALE),
        0.8f, 0.8f);
    assign_sprite_scale(find_component(list_entity, entity_name,
        COMPONENT_SPRITE), find_component(list_entity, entity_name,
        COMPONENT_SCALE));
    change_rect_display_values(find_component(list_entity, entity_name,
        COMPONENT_RECT_DISPLAY), (sfFloatRect){0, 0, 50, 50}, ASSIGN);
}

static void init_demon(global_data_t global_data, entity_t *list_entity,
    char *entity_name, char *sprite_name)
{
    append_component_to_entity(list_entity, entity_name,
        COMPONENT_SPRITE, set_sprite());
    append_component_to_entity(list_entity, entity_name,
        COMPONENT_POSITION, set_position());
    append_component_to_entity(list_entity, entity_name,
        COMPONENT_SCALE, set_scale());
    append_component_to_entity(list_entity, entity_name,
        COMPONENT_RECT_DISPLAY, set_rect_display());
    append_component_to_entity(list_entity, entity_name,
        COMPONENT_FRAME, set_clock());
    append_component_to_entity(list_entity, entity_name,
        COMPONENT_STATE, set_state());
    append_component_to_entity(list_entity, entity_name,
        COMPONENT_HEALTH, set_health());
    init_demon_assign(global_data, list_entity, entity_name, sprite_name);
}

void init_enemies(global_data_t global_data, entity_t *list_entity)
{
    for (int i = 0; name[i] != NULL; i++) {
        init_demon(global_data, list_entity, (char *)name[i],
            (char *)sprite_name[i]);
    }
}
