/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-myrpg-guillaume1.blondel
** File description:
** world_map_mouve.c
*/

#include "../include/rpg.h"

static void boat_mouve(rpg_t *rpg, entity_t *list_entity, map_t *maps)
{
    rpg->fast_travel = false;
    rpg->main_character->position = (component_position_t) {1520, 1388};
    sfView_setCenter(rpg->view, (sfVector2f) {1540, 1398});
    assign_sprite_position((component_sprite_t *) find_component(
        list_entity, "mc", COMPONENT_SPRITE),
        &rpg->main_character->position);
    display_sprite((component_sprite_t *) find_component(list_entity,
        "mc", COMPONENT_SPRITE), rpg->window);
}

void fast_travel(rpg_t *rpg, entity_t *list_entity, map_t *maps)
{
    static float mouve = 1140;

    assign_sprite_position((component_sprite_t *) find_component(list_entity,
        "mc", COMPONENT_SPRITE), &(component_position_t){0, 0});
    assign_sprite_position((component_sprite_t *) find_component(list_entity,
        "sword", COMPONENT_SPRITE), &(component_position_t){0, 0});
    if (mouve < 1480) {
        rpg->fast_travel = true;
        if (check_time(find_component(list_entity, "boat",
            COMPONENT_FRAME), 0.1f, SUPERIOR) == true) {
            mouve += 5;
            assign_sprite_position((component_sprite_t *) find_component(
                list_entity, "boat", COMPONENT_SPRITE),
                &(component_position_t){mouve, 1470});
            sfView_setCenter(rpg->view, (sfVector2f){mouve, 1470});
            restart_time(find_component(list_entity, "boat", COMPONENT_FRAME));
        }
    } else
        boat_mouve(rpg, list_entity, maps);
}

static void mouve_wd_check(rpg_t *rpg, entity_t *list_entity, map_t *maps)
{
    if (maps->world[(((int)rpg->main_character->position.y + 10) /
    (int)maps->world_size.y) + 1][((int)rpg->main_character->position.x /
    (int)maps->world_size.x) - 1] == 'T') {
        rpg->main_character->position = (component_position_t){700, 1800};
        sfView_setCenter(rpg->view, (sfVector2f){720, 1810});
        maps->current_map = 1;
        spawn_enemies(list_entity, maps);
    }
    if (maps->world[(((int)rpg->main_character->position.y + 10) /
    (int)maps->world_size.y) + 1][((int)rpg->main_character->position.x /
    (int)maps->world_size.x) - 1] == 'C') {
        rpg->main_character->position = (component_position_t){800, 1700};
        sfView_setCenter(rpg->view, (sfVector2f){820, 1710});
        maps->current_map = 2;
        spawn_enemies(list_entity, maps);
    }
}

int mouve_wd(rpg_t *rpg, entity_t *list_entity, map_t *maps)
{
    if (maps->world[(((int)rpg->main_character->position.y + 10) /
    (int)maps->world_size.y) + 1][((int)rpg->main_character->position.x /
    (int)maps->world_size.x) - 1] == '#') {
        return 1;
    }
    if (maps->world[(((int)rpg->main_character->position.y + 10) /
    (int)maps->world_size.y) + 1][((int)rpg->main_character->position.x /
    (int)maps->world_size.x) - 1] == 'B') {
        rpg->main_character->position = (component_position_t){456, 1774};
        sfView_setCenter(rpg->view, (sfVector2f){476, 1784});
        maps->current_map = 3;
        spawn_enemies(list_entity, maps);
    }
    if (maps->world[(((int)rpg->main_character->position.y + 10) /
        (int)maps->world_size.y) + 1][((int)rpg->main_character->position.x /
        (int)maps->world_size.x) - 1] == 'P') {
        fast_travel(rpg, list_entity, maps);
    }
    mouve_wd_check(rpg, list_entity, maps);
    return 0;
}

static void mouve_wu_check(rpg_t *rpg, entity_t *list_entity, map_t *maps)
{
    if (maps->world[(((int)rpg->main_character->position.y - 10) /
    (int)maps->world_size.y) + 1][((int)rpg->main_character->position.x /
    (int)maps->world_size.x) - 1] == 'T') {
        rpg->main_character->position = (component_position_t){700, 1800};
        sfView_setCenter(rpg->view, (sfVector2f){720, 1810});
        maps->current_map = 1;
        spawn_enemies(list_entity, maps);
    }
    if (maps->world[(((int)rpg->main_character->position.y - 10) /
    (int)maps->world_size.y) + 1][((int)rpg->main_character->position.x /
    (int)maps->world_size.x) - 1] == 'C') {
        rpg->main_character->position = (component_position_t){800, 1700};
        sfView_setCenter(rpg->view, (sfVector2f){820, 1710});
        maps->current_map = 2;
        spawn_enemies(list_entity, maps);
    }
}

int mouve_wu(rpg_t *rpg, entity_t *list_entity, map_t *maps)
{
    if (maps->world[(((int)rpg->main_character->position.y - 10) /
    (int)maps->world_size.y) + 1][((int)rpg->main_character->position.x /
    (int)maps->world_size.x) - 1] == '#') {
        return 1;
    }
    if (maps->world[(((int)rpg->main_character->position.y - 10) /
    (int)maps->world_size.y) + 1][((int)rpg->main_character->position.x /
    (int)maps->world_size.x) - 1] == 'B') {
        rpg->main_character->position = (component_position_t){456, 1774};
        sfView_setCenter(rpg->view, (sfVector2f){476, 1784});
        maps->current_map = 3;
        spawn_enemies(list_entity, maps);
    }
    if (maps->world[(((int)rpg->main_character->position.y - 10) /
        (int)maps->world_size.y) + 1][((int)rpg->main_character->position.x /
        (int)maps->world_size.x) - 1] == 'P') {
        fast_travel(rpg, list_entity, maps);
    }
    mouve_wu_check(rpg, list_entity, maps);
    return 0;
}

static void mouve_wl_check(rpg_t *rpg, entity_t *list_entity, map_t *maps)
{
    if (maps->world[((int)rpg->main_character->position.y /
    (int)maps->world_size.y) + 1][(((int)rpg->main_character->position.x - 10)
    / (int)maps->world_size.x) - 1] == 'T') {
        rpg->main_character->position = (component_position_t){700, 1800};
        sfView_setCenter(rpg->view, (sfVector2f){720, 1810});
        maps->current_map = 1;
        spawn_enemies(list_entity, maps);
    }
    if (maps->world[(((int)rpg->main_character->position.y) /
    (int)maps->world_size.y) + 1][(((int)rpg->main_character->position.x - 10)
    / (int)maps->world_size.x) - 1] == 'C') {
        rpg->main_character->position = (component_position_t){800, 1700};
        sfView_setCenter(rpg->view, (sfVector2f){820, 1710});
        maps->current_map = 2;
        spawn_enemies(list_entity, maps);
    }
}

int mouve_wl(rpg_t *rpg, entity_t *list_entity, map_t *maps)
{
    if (maps->world[(((int)rpg->main_character->position.y) /
    (int)maps->world_size.y) + 1][(((int)rpg->main_character->position.x - 10)
    / (int)maps->world_size.x) - 1] == '#') {
        return 1;
    }
    if (maps->world[(((int)rpg->main_character->position.y) /
        (int)maps->world_size.y) + 1]
        [(((int)rpg->main_character->position.x - 10)
        / (int)maps->world_size.x) - 1] == 'P') {
        fast_travel(rpg, list_entity, maps);
    }
    mouve_wl_check(rpg, list_entity, maps);
    return 0;
}

static void mouve_wr_check(rpg_t *rpg, entity_t *list_entity, map_t *maps)
{
    if (maps->world[((int)rpg->main_character->position.y /
    (int)maps->world_size.y) + 1][(((int)rpg->main_character->position.x + 10)
    / (int)maps->world_size.x) - 1] == 'T') {
        rpg->main_character->position = (component_position_t){700, 1800};
        sfView_setCenter(rpg->view, (sfVector2f){720, 1810});
        maps->current_map = 1;
        spawn_enemies(list_entity, maps);
    }
    if (maps->world[(((int)rpg->main_character->position.y) /
    (int)maps->world_size.y) + 1][(((int)rpg->main_character->position.x + 10)
    / (int)maps->world_size.x) - 1] == 'C') {
        rpg->main_character->position = (component_position_t){800, 1700};
        sfView_setCenter(rpg->view, (sfVector2f){820, 1710});
        maps->current_map = 2;
        spawn_enemies(list_entity, maps);
    }
}

int mouve_wr(rpg_t *rpg, entity_t *list_entity, map_t *maps)
{
    if (maps->world[(((int)rpg->main_character->position.y) /
    (int)maps->world_size.y) + 1][(((int)rpg->main_character->position.x + 10)
    / (int)maps->world_size.x) - 1] == '#') {
        return 1;
    }
    if (maps->world[(((int)rpg->main_character->position.y) /
        (int)maps->world_size.y) + 1]
        [(((int)rpg->main_character->position.x + 10)
        / (int)maps->world_size.x) - 1] == 'P') {
        fast_travel(rpg, list_entity, maps);
    }
    mouve_wr_check(rpg, list_entity, maps);
    return 0;
}
