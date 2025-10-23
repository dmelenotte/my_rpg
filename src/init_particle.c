/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-myrpg-guillaume1.blondel
** File description:
** init_particle.c
*/

#include "../include/rpg.h"

void init_particle(entity_t *list_entity, global_data_t global_data)
{
    append_component_to_entity(list_entity, "hit",
        COMPONENT_SPRITE, set_sprite());
    append_component_to_entity(list_entity, "hit",
        COMPONENT_POSITION, set_position());
    append_component_to_entity(list_entity, "hit",
        COMPONENT_SCALE, set_scale());
    append_component_to_entity(list_entity, "hit",
        COMPONENT_STATE, set_state());
    assign_sprite(find_component(list_entity, "hit", COMPONENT_SPRITE),
        "hit_sprite", global_data);
    assign_scale(find_component(list_entity, "hit",
        COMPONENT_SCALE), 0.3f, 0.3f);
    assign_sprite_scale(find_component(list_entity, "hit", COMPONENT_SPRITE),
        find_component(list_entity, "hit", COMPONENT_SCALE));
}
