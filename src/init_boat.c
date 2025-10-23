/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-myrpg-guillaume1.blondel
** File description:
** init_boat.c
*/

#include "../include/rpg.h"

void init_boat(global_data_t global_data, entity_t *list_entity)
{
    component_scale_t scale = {0.3, 0.3};

    append_component_to_entity(list_entity, "boat",
        COMPONENT_SPRITE, set_sprite());
    assign_sprite(find_component(list_entity, "boat", COMPONENT_SPRITE),
        "boat_sprite", global_data);
    append_component_to_entity(list_entity, "boat",
        COMPONENT_POSITION, set_position());
    assign_sprite_position(find_component(list_entity,
        "boat", COMPONENT_SPRITE), &(component_position_t){1120, 1460});
    append_component_to_entity(list_entity, "boat", COMPONENT_RECT_DISPLAY,
        set_rect_display());
    assign_sprite_rect_display(&(component_rect_display_t){0, 0, 256, 191},
        find_component(list_entity, "boat", COMPONENT_SPRITE));
    append_component_to_entity(list_entity, "boat", COMPONENT_SCALE,
        set_scale());
    assign_sprite_scale(find_component(list_entity, "boat", COMPONENT_SPRITE),
        &scale);
    append_component_to_entity(list_entity, "boat",
        COMPONENT_FRAME, set_clock());
}

void init_the_sword_again(rpg_t *rpg, global_data_t global_data,
    entity_t *list_entity)
{
    change_rect_display_values(find_component(list_entity, "sword",
        COMPONENT_RECT_DISPLAY), (sfFloatRect){0, 0, 100, 70}, ASSIGN);
    assign_sprite_rect_display(find_component(list_entity, "sword",
        COMPONENT_RECT_DISPLAY), find_component(list_entity, "sword",
        COMPONENT_SPRITE));
    assign_scale(find_component(list_entity, "sword", COMPONENT_SCALE),
        0.3f, 0.3f);
    assign_sprite_scale(find_component(list_entity, "sword", COMPONENT_SPRITE),
        find_component(list_entity, "sword", COMPONENT_SCALE));
    origin_sprite(find_component(list_entity, "sword", COMPONENT_SPRITE),
        (sfVector2f){35, 65});
    assign_rotation(find_component(list_entity, "sword",
        COMPONENT_ROTATION), 70);
    assign_sprite_rotation(find_component(list_entity, "sword",
        COMPONENT_SPRITE), find_component(list_entity,
        "sword", COMPONENT_ROTATION));
}

sfVector2f init_enemy_position(component_position_t *enemy_position)
{
    sfVector2f position = {0};

    position.x = enemy_position->x;
    position.y = enemy_position->y;
    return position;
}

void init_mc_life(rpg_t *rpg, global_data_t global_data,
    entity_t *list_entity)
{
    rpg->main_character->hp = 3;
    append_component_to_entity(list_entity, "mc",
        COMPONENT_FRAME, set_clock());
}
