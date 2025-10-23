/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-myrpg-guillaume1.blondel
** File description:
** game_over
*/

#include "../include/rpg.h"

void init_game_over(rpg_t *rpg, global_data_t global_data,
    entity_t *list_entity)
{
    append_component_to_entity(list_entity, "game_over",
        COMPONENT_SPRITE, set_sprite());
    assign_sprite(find_component(list_entity, "game_over",
        COMPONENT_SPRITE), "gameover_sprite", global_data);
    append_component_to_entity(list_entity, "game_over",
        COMPONENT_POSITION, set_position());
    append_component_to_entity(list_entity, "game_over",
        COMPONENT_FRAME, set_clock());
    assign_sprite_position(find_component(list_entity,
        "game_over", COMPONENT_SPRITE), &(component_position_t)
        {rpg->main_character->position.x - 310,
        rpg->main_character->position.y - 210});
    append_component_to_entity(list_entity, "game_over",
        COMPONENT_SCALE, set_scale());
    assign_sprite_scale(find_component(list_entity, "game_over",
        COMPONENT_SPRITE), &(component_scale_t) {0.28, 0.32});
}

void game_over(rpg_t *rpg, entity_t *list_entity, global_data_t global_data)
{
    sfRenderWindow_clear(rpg->window, sfBlack);
    assign_sprite_position(find_component(list_entity,
        "game_over", COMPONENT_SPRITE), &(component_position_t)
        {rpg->main_character->position.x - 310,
        rpg->main_character->position.y - 210});
    display_sprite(find_component(list_entity, "game_over",
        COMPONENT_SPRITE), rpg->window);
    restart_time(find_component(list_entity,
        "game_over", COMPONENT_FRAME));
    sfRenderWindow_display(rpg->window);
}

void init_win_screen(rpg_t *rpg, global_data_t global_data,
    entity_t *list_entity)
{
    append_component_to_entity(list_entity, "win",
        COMPONENT_SPRITE, set_sprite());
    assign_sprite(find_component(list_entity, "win",
        COMPONENT_SPRITE), "win_sprite", global_data);
    append_component_to_entity(list_entity, "win",
        COMPONENT_FRAME, set_clock());
    append_component_to_entity(list_entity, "win",
        COMPONENT_POSITION, set_position());
    assign_sprite_position(find_component(list_entity,
        "win", COMPONENT_SPRITE), &(component_position_t)
        {rpg->main_character->position.x - 310,
        rpg->main_character->position.y - 210});
    append_component_to_entity(list_entity, "win",
        COMPONENT_SCALE, set_scale());
    assign_sprite_scale(find_component(list_entity, "win",
        COMPONENT_SPRITE), &(component_scale_t) {0.6, 0.6});
}

void win(rpg_t *rpg, entity_t *list_entity, global_data_t global_data)
{
    sfRenderWindow_clear(rpg->window, sfBlack);
    assign_sprite_position(find_component(list_entity,
        "win", COMPONENT_SPRITE), &(component_position_t)
        {rpg->main_character->position.x - 280,
        rpg->main_character->position.y - 300});
    display_sprite(find_component(list_entity, "win",
        COMPONENT_SPRITE), rpg->window);
    restart_time(find_component(list_entity,
        "win", COMPONENT_FRAME));
    sfRenderWindow_display(rpg->window);
}