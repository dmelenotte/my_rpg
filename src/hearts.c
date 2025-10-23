/*
** EPITECH PROJECT, 2024
** B-MUL-250-TLS-2-1-myrpg-guillaume1.blondel
** File description:
** hearts
*/

#include "../include/rpg.h"
#include "string.h"

void init_heart(rpg_t *rpg, global_data_t global_data, entity_t *list_entity)
{
    append_component_to_entity(list_entity, "heart",
        COMPONENT_SPRITE, set_sprite());
    assign_sprite(find_component(list_entity, "heart",
        COMPONENT_SPRITE), "heart_sprite", global_data);
    append_component_to_entity(list_entity, "heart",
        COMPONENT_POSITION, set_position());
    assign_sprite_position(find_component(list_entity,
        "heart", COMPONENT_SPRITE), &(component_position_t)
        {rpg->main_character->position.x - 310,
        rpg->main_character->position.y - 210});
    append_component_to_entity(list_entity, "heart",
        COMPONENT_SCALE, set_scale());
    assign_sprite_scale(find_component(list_entity, "heart",
        COMPONENT_SPRITE), &(component_scale_t) {0.3, 0.3});
    append_component_to_entity(list_entity, "heart",
        COMPONENT_RECT_DISPLAY, set_rect_display());
}

void init_empty_heart(rpg_t *rpg, global_data_t global_data,
    entity_t *list_entity)
{
    append_component_to_entity(list_entity, "empty_heart",
        COMPONENT_SPRITE, set_sprite());
    assign_sprite(find_component(list_entity, "empty_heart",
        COMPONENT_SPRITE), "empty_heart_sprite", global_data);
    append_component_to_entity(list_entity, "empty_heart",
        COMPONENT_POSITION, set_position());
    assign_sprite_position(find_component(list_entity,
        "empty_heart", COMPONENT_SPRITE), &(component_position_t)
        {rpg->main_character->position.x - 310,
        rpg->main_character->position.y - 210});
    append_component_to_entity(list_entity, "empty_heart",
        COMPONENT_SCALE, set_scale());
    assign_sprite_scale(find_component(list_entity, "empty_heart",
        COMPONENT_SPRITE), &(component_scale_t) {0.3, 0.3});
}

void init_mc_hearts(rpg_t *rpg, global_data_t global_data,
    entity_t *list_entity)
{
    rpg->main_character->hearts =
        malloc(sizeof(component_rect_display_t) * 4);
    rpg->main_character->hearts[0] =
        (component_rect_display_t) {0, 0, 120, 315};
    rpg->main_character->hearts[1] =
        (component_rect_display_t) {0, 0, 195, 315};
    rpg->main_character->hearts[2] =
        (component_rect_display_t) {0, 0, 300, 315};
}

static void display_heart(rpg_t *rpg, entity_t *list_entity)
{
    assign_sprite_position(find_component(list_entity,
        "heart", COMPONENT_SPRITE), &(component_position_t)
        {rpg->main_character->position.x - 310,
        rpg->main_character->position.y - 210});
    assign_sprite_position(find_component(list_entity,
        "empty_heart", COMPONENT_SPRITE), &(component_position_t)
        {rpg->main_character->position.x - 310,
        rpg->main_character->position.y - 210});
    assign_sprite_rect_display(&rpg->main_character->hearts[
        rpg->main_character->hp - 1],
        find_component(list_entity, "heart", COMPONENT_SPRITE));
    display_sprite(find_component(list_entity, "empty_heart",
        COMPONENT_SPRITE), rpg->window);
    display_sprite(find_component(list_entity, "heart", COMPONENT_SPRITE),
        rpg->window);
}

void init_lives(rpg_t *rpg, global_data_t global_data, entity_t *list_entity)
{
    init_heart(rpg, global_data, list_entity);
    init_empty_heart(rpg, global_data, list_entity);
    init_mc_hearts(rpg, global_data, list_entity);
    rpg->inventory = malloc(sizeof(inventory_t));
    rpg->inventory->is_open = 0;
    rpg->inventory->clock = sfClock_create();
    rpg->inventory->items = malloc((sizeof(char) * 20) * 10);
    rpg->inventory->nb_items = 3;
    rpg->inventory->items[0] = strdup("weapon");
    rpg->inventory->items[1] = strdup("health_potion");
    rpg->inventory->items[2] = strdup("health_potion");
    rpg->inventory->items[3] = NULL;
}

static void check_health_potion(rpg_t *rpg)
{
    for (int i = 0; i <= rpg->inventory->nb_items &&
    rpg->inventory->items[i] != NULL; i++)
        if (strcmp(rpg->inventory->items[i], "health_potion") == 0) {
            rpg->main_character->hp = 3;
            rpg->inventory->items[i] = "empty_slot";
            return;
        }
}

void mc_heart(rpg_t *rpg, global_data_t global_data, entity_t *list_entity,
    map_t *maps)
{
    display_heart(rpg, list_entity);
    if (sfKeyboard_isKeyPressed(sfKeyP) == sfTrue &&
        rpg->inventory->is_open == 0 &&
        rpg->pause_menu->is_paused == 0 &&
        sfTime_asSeconds(sfClock_getElapsedTime(
        rpg->inventory->clock)) > 0.2 &&
        rpg->main_character->hp < 3) {
            check_health_potion(rpg);
            sfClock_restart(rpg->inventory->clock);
    }
    if (rpg->main_character->hp == 0) {
        game_over(rpg, list_entity, global_data);
    }
    if (maps->current_map == 3 && check_health(find_component(list_entity,
        "boss", COMPONENT_HEALTH), 0) == true) {
        win(rpg, list_entity, global_data);
    }
}
