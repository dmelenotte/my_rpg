/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-myrpg-guillaume1.blondel
** File description:
** spawn_enemies.c
*/

#include "../include/rpg.h"

static const sfVector2f ice_map_spawn[8] = {
    {690, 1280},
    {690, 1040},
    {250, 1240},
    {1120, 1240},
    {1120, 710},
    {260, 710},
    {260, 270},
    {1130, 260}
};

static int select_random(int rand_max)
{
    int i_rand = 0;

    i_rand = rand() % rand_max;
    return i_rand;
}

static void set_active_enemy(entity_t *list_entity,
    entity_t *enemy, int current_map)
{
    int i_rand = 0;

    if (current_map == 1) {
        i_rand = select_random(8);
        assign_position(find_component(list_entity, enemy->name_entity,
            COMPONENT_POSITION), ice_map_spawn[(int)i_rand].x,
                ice_map_spawn[(int)i_rand].y);
        assign_sprite_position(find_component(list_entity, enemy->name_entity,
            COMPONENT_SPRITE), find_component(list_entity, enemy->name_entity,
            COMPONENT_POSITION));
        change_state(find_component(list_entity, enemy->name_entity,
            COMPONENT_STATE), SET_ACTIVE | SET_DISPLAY, true, true);
        assign_max_health(find_component(list_entity, enemy->name_entity,
            COMPONENT_HEALTH), 9);
        return;
    }
    change_state(find_component(list_entity, enemy->name_entity,
        COMPONENT_STATE), SET_ACTIVE | SET_DISPLAY, false, true);
}

static void spawn_boss(entity_t *list_entity, int current_map)
{
    if (current_map == 3) {
        assign_position(find_component(list_entity, "boss",
            COMPONENT_POSITION), 408.f, 550.f);
        assign_sprite_position(find_component(list_entity, "boss",
            COMPONENT_SPRITE), find_component(list_entity,
                "boss", COMPONENT_POSITION));
        change_state(find_component(list_entity, "boss", COMPONENT_STATE),
            SET_ACTIVE | SET_DISPLAY, true, true);
        assign_max_health(find_component(list_entity, "boss",
            COMPONENT_HEALTH), 45);
        return;
    }
    change_state(find_component(list_entity, "boss", COMPONENT_STATE),
        SET_ACTIVE | SET_DISPLAY, false, true);
}

void spawn_enemies(entity_t *list_entity, map_t *maps)
{
    entity_t *enemy = NULL;

    enemy = find_entity_by_type(list_entity, ENEMY, true);
    while (enemy != NULL) {
        set_active_enemy(list_entity, enemy, maps->current_map);
        enemy = find_entity_by_type(list_entity, ENEMY, false);
    }
    spawn_boss(list_entity, maps->current_map);
}
