/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-myrpg-guillaume1.blondel
** File description:
** world_map_mouve.c
*/

#include "../include/rpg.h"

int mouve_bd(rpg_t *rpg, entity_t *list_entity, map_t *maps)
{
    if (maps->demon_castle[(((int)rpg->main_character->position.y + 10) /
    (int)maps->demon_castle_size.y) + 1][((int)rpg->main_character->position.x
    / (int)maps->demon_castle_size.x) - 1] == '#') {
        return 1;
    }
    if (maps->demon_castle[(((int)rpg->main_character->position.y + 10) /
    (int)maps->demon_castle_size.y) + 1][((int)rpg->main_character->position.x
    / (int)maps->demon_castle_size.x) - 1] == 'S') {
        rpg->main_character->position = (component_position_t){1540, 1388};
        sfView_setCenter(rpg->view, (sfVector2f){1560, 1398});
        assign_sprite_position((component_sprite_t *) find_component(
            list_entity, "mc", COMPONENT_SPRITE),
            &rpg->main_character->position);
        maps->current_map = 0;
        spawn_enemies(list_entity, maps);
    }
    return 0;
}

int mouve_bu(rpg_t *rpg, entity_t *list_entity, map_t *maps)
{
    if (maps->demon_castle[(((int)rpg->main_character->position.y - 10) /
    (int)maps->demon_castle_size.y) + 1][((int)rpg->main_character->position.x
    / (int)maps->demon_castle_size.x) - 1] == '#') {
        return 1;
    }
    if (maps->demon_castle[(((int)rpg->main_character->position.y - 10) /
    (int)maps->demon_castle_size.y) + 1][((int)rpg->main_character->position.x
    / (int)maps->demon_castle_size.x) - 1] == 'S') {
        rpg->main_character->position = (component_position_t){1540, 1388};
        sfView_setCenter(rpg->view, (sfVector2f){1560, 1398});
        assign_sprite_position((component_sprite_t *) find_component(
            list_entity, "mc", COMPONENT_SPRITE),
            &rpg->main_character->position);
        maps->current_map = 0;
        spawn_enemies(list_entity, maps);
    }
    return 0;
}

int mouve_bl(rpg_t *rpg, entity_t *list_entity, map_t *maps)
{
    if (maps->demon_castle[(((int)rpg->main_character->position.y) /
    (int)maps->demon_castle_size.y) + 1]
    [(((int)rpg->main_character->position.x - 10)
    / (int)maps->demon_castle_size.x) - 1] == '#') {
        return 1;
    }
    return 0;
}

int mouve_br(rpg_t *rpg, entity_t *list_entity, map_t *maps)
{
    if (maps->demon_castle[(((int)rpg->main_character->position.y) /
    (int)maps->demon_castle_size.y) + 1]
    [(((int)rpg->main_character->position.x + 10)
    / (int)maps->demon_castle_size.x) - 1] == '#') {
        return 1;
    }
    return 0;
}
