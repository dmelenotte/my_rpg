/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-myrpg-guillaume1.blondel
** File description:
** handle_enemies.c
*/

#include "../include/rpg.h"

static float check_touch_entity(rpg_t *rpg, entity_t *list_entity)
{
    entity_t *enemy_entity = NULL;

    enemy_entity = find_entity_by_type(list_entity, ENEMY, true);
    while (enemy_entity != NULL) {
        if (global_enter_in_collision(find_component(list_entity,
            "mc", COMPONENT_SPRITE), find_component(list_entity,
            enemy_entity->name_entity, COMPONENT_SPRITE)) == true) {
            rpg->main_character->hp -= 1;
        }
        enemy_entity = find_entity_by_type(list_entity, ENEMY, false);
    }
    if (rpg->main_character->hp <= 0)
        rpg->main_character->hp = 0;
}

static void attak_cd(rpg_t *rpg, entity_t *list_entity, map_t *maps)
{
    if (check_time(find_component(list_entity, "mc",
        COMPONENT_FRAME), 1.0f, SUPERIOR) == true) {
        check_touch_entity(rpg, list_entity);
        restart_time(find_component(list_entity, "mc", COMPONENT_FRAME));
    }
}

static void handle_demon(rpg_t *rpg, entity_t *list_entity, map_t *maps,
    char *entity_name)
{
    sfVector2f move = {0};
    int moving = 0;

    if (check_time(find_component(list_entity, entity_name,
    COMPONENT_FRAME), 0.1f, SUPERIOR) == true) {
        move = move_enemy_to_player(list_entity, entity_name, &moving,
            maps);
        assign_position(find_component(list_entity, entity_name,
            COMPONENT_POSITION), move.x, move.y);
        handle_animation(list_entity, entity_name, moving);
        assign_sprite_rect_display(find_component(list_entity,
            entity_name, COMPONENT_RECT_DISPLAY), find_component(
            list_entity, entity_name, COMPONENT_SPRITE));
        assign_sprite_position(find_component(list_entity,
            entity_name, COMPONENT_SPRITE), find_component(list_entity,
            entity_name, COMPONENT_POSITION));
        restart_time(find_component(list_entity, entity_name,
            COMPONENT_FRAME));
        attak_cd(rpg, list_entity, maps);
    }
}

static void check_no_life_enemies(entity_t *list_entity)
{
    entity_t *enemy_entity = NULL;

    enemy_entity = find_entity_by_type(list_entity, ENEMY, true);
    while (enemy_entity != NULL) {
        if (check_health(find_component(list_entity, enemy_entity->name_entity,
            COMPONENT_HEALTH), 0) == true) {
            change_state(find_component(list_entity, enemy_entity->name_entity,
                COMPONENT_STATE), SET_ACTIVE | SET_DISPLAY, false, false);
        }
        enemy_entity = find_entity_by_type(list_entity, ENEMY, false);
    }
    if (check_health(find_component(list_entity, "boss",
        COMPONENT_HEALTH), 0) == true) {
        change_state(find_component(list_entity, "boss",
            COMPONENT_STATE), SET_ACTIVE | SET_DISPLAY, false, true);
    }
}

void handle_enemies(rpg_t *rpg, map_t *maps, entity_t *list_entity)
{
    check_no_life_enemies(list_entity);
    for (int i = 0; name[i] != NULL; i++) {
        if (check_active(find_component(list_entity, (char *)name[i],
            COMPONENT_STATE))) {
            handle_demon(rpg, list_entity, maps, (char *)name[i]);
        }
    }
    if (check_active(find_component(list_entity, "boss",
        COMPONENT_STATE))) {
        handle_boss(list_entity, maps, rpg);
    }
}
