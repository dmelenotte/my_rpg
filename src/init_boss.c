/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-myrpg-guillaume1.blondel
** File description:
** init_boss.c
*/

#include "../include/rpg.h"

static void init_ball_attack(entity_t *list_entity, global_data_t global_data)
{
    append_component_to_entity(list_entity, "ball_attack",
        COMPONENT_SPRITE, set_sprite());
    append_component_to_entity(list_entity, "ball_attack",
        COMPONENT_POSITION, set_position());
    append_component_to_entity(list_entity, "ball_attack",
        COMPONENT_SCALE, set_scale());
    append_component_to_entity(list_entity, "ball_attack",
        COMPONENT_STATE, set_state());
    append_component_to_entity(list_entity, "ball_attack",
        COMPONENT_FRAME, set_clock());
    assign_sprite(find_component(list_entity, "ball_attack",
        COMPONENT_SPRITE), "ball_sprite", global_data);
    change_state(find_component(list_entity, "ball_attack",
        COMPONENT_STATE), SET_ACTIVE | SET_DISPLAY, false, true);
    assign_scale(find_component(list_entity, "ball_attack",
        COMPONENT_SCALE), 0.04f, 0.04f);
    assign_sprite_scale(find_component(list_entity, "ball_attack",
        COMPONENT_SPRITE), find_component(list_entity,
        "ball_attack", COMPONENT_SCALE));
}

static void init_boss(global_data_t global_data, entity_t *list_entity)
{
    append_component_to_entity(list_entity, "boss",
        COMPONENT_SPRITE, set_sprite());
    append_component_to_entity(list_entity, "boss",
        COMPONENT_POSITION, set_position());
    append_component_to_entity(list_entity, "boss",
        COMPONENT_SCALE, set_scale());
    append_component_to_entity(list_entity, "boss",
        COMPONENT_RECT_DISPLAY, set_rect_display());
    append_component_to_entity(list_entity, "boss",
        COMPONENT_FRAME, set_clock());
    append_component_to_entity(list_entity, "boss",
        COMPONENT_STATE, set_state());
    append_component_to_entity(list_entity, "boss",
        COMPONENT_HEALTH, set_health());
    change_state(find_component(list_entity, "boss", COMPONENT_STATE),
        SET_ACTIVE | SET_DISPLAY, false, true);
    assign_sprite(find_component(list_entity, "boss",
        COMPONENT_SPRITE), "boss_sprite", global_data);
    assign_scale(find_component(list_entity, "boss", COMPONENT_SCALE),
        1.4f, 1.4f);
}

void init_boss_enemy(entity_t *list_entity, global_data_t global_data)
{
    init_boss(global_data, list_entity);
    assign_sprite_scale(find_component(list_entity, "boss",
        COMPONENT_SPRITE), find_component(list_entity, "boss",
        COMPONENT_SCALE));
    change_rect_display_values(find_component(list_entity, "boss",
        COMPONENT_RECT_DISPLAY), (sfFloatRect){0, 0, 48, 48}, ASSIGN);
    assign_sprite_rect_display(find_component(list_entity, "boss",
        COMPONENT_RECT_DISPLAY), find_component(list_entity, "boss",
        COMPONENT_SPRITE));
    init_ball_attack(list_entity, global_data);
    origin_sprite(find_component(list_entity, "ball_attack",
        COMPONENT_SPRITE), (sfVector2f){473.5, 421.5});
}
