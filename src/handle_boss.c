/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-myrpg-guillaume1.blondel
** File description:
** handle_boss.c
*/

#include "../include/rpg.h"
#include <string.h>

static sfVector2f compute_move_vector(component_position_t *ball_pos,
    sfVector2f player_pos)
{
    sfVector2f move_vector = {0};

    move_vector.x = player_pos.x - ball_pos->x;
    move_vector.y = player_pos.y - ball_pos->y;
    return move_vector;
}

static float check_touch_entity(rpg_t *rpg, entity_t *list_entity)
{
    entity_t *enemy_entity = NULL;

    enemy_entity = find_entity_by_type(list_entity, BOSS, true);
    while (enemy_entity != NULL) {
        if (global_enter_in_collision(find_component(list_entity,
            "mc", COMPONENT_SPRITE), find_component(list_entity,
            enemy_entity->name_entity, COMPONENT_SPRITE)) == true) {
            rpg->main_character->hp -= 1;
        }
        enemy_entity = find_entity_by_type(list_entity, BOSS, false);
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

static bool check_ball_conditions(entity_t *list_entity,
    component_position_t *boss_pos)
{
    component_position_t *ball_pos = NULL;

    ball_pos = find_component(list_entity, "ball_attack", COMPONENT_POSITION);
    if (!check_active(find_component(list_entity,
        "ball_attack", COMPONENT_STATE))) {
        return true;
    }
    if (compute_distance(ball_pos,
        (sfVector2f){boss_pos->x, boss_pos->y}) > 200) {
        return true;
    }
    return false;
}

static void move_ball_attack(entity_t *list_entity, sfVector2f move_vector)
{
    component_position_t *ball_pos = NULL;

    ball_pos = find_component(list_entity, "ball_attack", COMPONENT_POSITION);
    if (check_time(find_component(list_entity, "ball_attack",
        COMPONENT_FRAME), 0.09f, SUPERIOR)) {
        ball_pos->x += move_vector.x / 12;
        ball_pos->y += move_vector.y / 12;
        assign_sprite_position(find_component(list_entity, "ball_attack",
            COMPONENT_SPRITE), find_component(list_entity,
            "ball_attack", COMPONENT_POSITION));
        restart_time(find_component(list_entity,
            "ball_attack", COMPONENT_FRAME));
    }
}

static void set_ball_attack(entity_t *list_entity,
    component_position_t *boss_pos, sfVector2f player_pos,
    sfVector2f *move_vector)
{
    change_state(find_component(list_entity, "ball_attack",
        COMPONENT_STATE), SET_ACTIVE | SET_DISPLAY, true, true);
    assign_position(find_component(list_entity, "ball_attack",
        COMPONENT_POSITION), boss_pos->x + 35, boss_pos->y + 60);
    assign_sprite_position(find_component(list_entity, "ball_attack",
        COMPONENT_SPRITE), find_component(list_entity, "ball_attack",
        COMPONENT_POSITION));
    *move_vector = compute_move_vector(find_component(list_entity,
        "ball_attack", COMPONENT_POSITION), player_pos);
}

static void handle_ball_attack(entity_t *list_entity)
{
    sfVector2f player_pos = {0};
    static sfVector2f move_vector = {0};
    component_sprite_t *player = NULL;
    component_position_t *boss_pos = NULL;

    player = find_component(list_entity, "mc", COMPONENT_SPRITE);
    player_pos = sfSprite_getPosition(player->sprite);
    boss_pos = find_component(list_entity,
        "boss", COMPONENT_POSITION);
    if (compute_distance(boss_pos, player_pos) < 200) {
        if (check_ball_conditions(list_entity, boss_pos)) {
            set_ball_attack(list_entity, boss_pos, player_pos, &move_vector);
        }
        move_ball_attack(list_entity, move_vector);
    } else {
        change_state(find_component(list_entity, "ball_attack",
            COMPONENT_STATE), SET_ACTIVE | SET_DISPLAY, false, true);
        memset(&move_vector, 0, sizeof(sfVector2f));
    }
}

void handle_boss(entity_t *list_entity, map_t *maps, rpg_t *rpg)
{
    sfVector2f move = {0};
    int moving = 0;

    if (check_time(find_component(list_entity, "boss",
        COMPONENT_FRAME), 0.1f, SUPERIOR) == true) {
        move = move_enemy_to_player(list_entity, "boss", &moving, maps);
        assign_position(find_component(list_entity, "boss",
            COMPONENT_POSITION), move.x, move.y);
        handle_animation(list_entity, "boss", moving);
        assign_sprite_rect_display(find_component(list_entity,
            "boss", COMPONENT_RECT_DISPLAY), find_component(list_entity,
            "boss", COMPONENT_SPRITE));
        assign_sprite_position(find_component(list_entity,
            "boss", COMPONENT_SPRITE), find_component(list_entity,
            "boss", COMPONENT_POSITION));
        restart_time(find_component(list_entity,
            "boss", COMPONENT_FRAME));
        attak_cd(rpg, list_entity, maps);
    }
    handle_ball_attack(list_entity);
}
