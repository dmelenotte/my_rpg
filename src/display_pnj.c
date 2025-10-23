/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-myrpg-guillaume1.blondel
** File description:
** display_pnj.c
*/

#include "../include/rpg.h"

void init_display_quest(rpg_t *rpg, entity_t *list_entity)
{
    if (rpg->current_quest == 0)
        display_sprite((component_sprite_t *) find_component(list_entity,
            "chapter1_text", COMPONENT_SPRITE), rpg->window);
    if (rpg->current_quest == 1)
        display_sprite((component_sprite_t *) find_component(list_entity,
            "chapter2_text", COMPONENT_SPRITE), rpg->window);
    if (rpg->current_quest == 2)
        display_sprite((component_sprite_t *) find_component(list_entity,
            "chapter3_text", COMPONENT_SPRITE), rpg->window);
    if (rpg->current_quest == 3)
        display_sprite((component_sprite_t *) find_component(list_entity,
            "chapter4_text", COMPONENT_SPRITE), rpg->window);
}

void talk_pnj(rpg_t *rpg, entity_t *list_entity, map_t *maps)
{
    int i = 0;

    if (sfKeyboard_isKeyPressed(sfKeyE) == sfTrue &&
        check_time(find_component(list_entity, "quester_pnj",
        COMPONENT_FRAME), 1.0f, SUPERIOR) == true){
        rpg->current_quest += 1;
        if (rpg->current_quest >= 5)
            rpg->current_quest = 0;
        restart_time(find_component(list_entity, "quester_pnj",
        COMPONENT_FRAME));
    }
    if (rpg->main_character->position.x >= 880 &&
        rpg->main_character->position.x <= 1000 &&
        rpg->main_character->position.y >= 1000 &&
        rpg->main_character->position.y <= 1100 &&
        rpg->current_quest < 4 && maps->current_map == 0) {
        init_display_quest(rpg, list_entity);
    }
}
