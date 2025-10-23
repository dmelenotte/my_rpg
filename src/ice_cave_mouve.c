/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-myrpg-guillaume1.blondel
** File description:
** world_map_mouve.c
*/

#include "../include/rpg.h"

int mouve_cad(rpg_t *rpg, entity_t *list_entity, map_t *maps)
{
    if (maps->ice_cave[(((int)rpg->main_character->position.y + 10) /
    (int)maps->ice_cave_size.y) + 1][((int)rpg->main_character->position.x /
    (int)maps->ice_cave_size.x) - 1] == '#') {
        return 1;
    }
    if (maps->ice_cave[(((int)rpg->main_character->position.y + 10) /
    (int)maps->ice_cave_size.y) + 1][((int)rpg->main_character->position.x /
    (int)maps->ice_cave_size.x) - 1] == 'S') {
        rpg->main_character->position = (component_position_t){1370, 680};
        assign_sprite_position((component_sprite_t *) find_component(
            list_entity, "mc", COMPONENT_SPRITE),
            &rpg->main_character->position);
        sfView_setCenter(rpg->view, (sfVector2f){1390, 690});
        maps->current_map = 0;
        spawn_enemies(list_entity, maps);
    }
    return 0;
}

int mouve_cau(rpg_t *rpg, entity_t *list_entity, map_t *maps)
{
    if (maps->ice_cave[(((int)rpg->main_character->position.y - 10) /
    (int)maps->ice_cave_size.y) + 1][((int)rpg->main_character->position.x /
    (int)maps->ice_cave_size.x) - 1] == '#') {
        return 1;
    }
    if (maps->ice_cave[(((int)rpg->main_character->position.y - 10) /
    (int)maps->ice_cave_size.y) + 1][((int)rpg->main_character->position.x /
    (int)maps->ice_cave_size.x) - 1] == 'S') {
        rpg->main_character->position = (component_position_t){1370, 680};
        assign_sprite_position((component_sprite_t *) find_component(
            list_entity, "mc", COMPONENT_SPRITE),
            &rpg->main_character->position);
        sfView_setCenter(rpg->view, (sfVector2f){1390, 690});
        maps->current_map = 0;
        spawn_enemies(list_entity, maps);
    }
    return 0;
}

int mouve_cal(rpg_t *rpg, entity_t *list_entity, map_t *maps)
{
    if (maps->ice_cave[(((int)rpg->main_character->position.y) /
    (int)maps->ice_cave_size.y) + 1]
    [(((int)rpg->main_character->position.x - 10)
    / (int)maps->ice_cave_size.x) - 1] == '#') {
        return 1;
    }
    return 0;
}

int mouve_car(rpg_t *rpg, entity_t *list_entity, map_t *maps)
{
    if (maps->ice_cave[(((int)rpg->main_character->position.y) /
    (int)maps->ice_cave_size.y) + 1]
    [(((int)rpg->main_character->position.x + 10)
    / (int)maps->ice_cave_size.x) - 1] == '#') {
        return 1;
    }
    return 0;
}
