/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-myrpg-guillaume1.blondel
** File description:
** handle_move_enemies.c
*/

#include "../include/rpg.h"

static void change_move_x_axis(sfVector2f *move, int value,
    int *moving, int shifting)
{
    move->x += value;
    *moving = shifting;
}

static void change_move_y_axis(sfVector2f *move, int value,
    int *moving, int shifting)
{
    move->y += value;
    *moving = shifting;
}

static int check_right(component_position_t *position, map_t *maps)
{
    if (maps->current_map == 1) {
        if (maps->ice_cave[(((int) position->y) /
            (int) maps->ice_cave_size.y) + 1][(((int) position->x + 5) /
            (int) maps->ice_cave_size.x) - 1] == '#') {
            return 1;
        }
    }
    if (maps->current_map == 3) {
        if (maps->demon_castle[(((int) position->y) /
            (int) maps->demon_castle_size.y) + 1][(((int) position->x + 5) /
            (int) maps->demon_castle_size.x) - 1] == '#') {
            return 1;
        }
    }
    return 0;
}

static int check_left(component_position_t *position, map_t *maps)
{
    if (maps->current_map == 1) {
        if (maps->ice_cave[(((int) position->y) /
            (int) maps->ice_cave_size.y) + 1][(((int) position->x - 5) /
            (int) maps->ice_cave_size.x) - 1] == '#') {
            return 1;
        }
    }
    if (maps->current_map == 3) {
        if (maps->demon_castle[(((int) position->y) /
            (int) maps->demon_castle_size.y) + 1][(((int) position->x - 5) /
            (int) maps->demon_castle_size.x) - 1] == '#') {
            return 1;
        }
    }
    return 0;
}

static int check_up(component_position_t *position, map_t *maps)
{
    if (maps->current_map == 1) {
        if (maps->ice_cave[(((int) position->y - 5) /
            (int) maps->ice_cave_size.y) + 1][(((int) position->x) /
            (int) maps->ice_cave_size.x) - 1] == '#') {
            return 1;
        }
    }
    if (maps->current_map == 3) {
        if (maps->demon_castle[(((int) position->y - 5) /
            (int) maps->demon_castle_size.y) + 1][(((int) position->x) /
            (int) maps->demon_castle_size.x) - 1] == '#') {
            return 1;
        }
    }
    return 0;
}

static int check_down(component_position_t *position, map_t *maps)
{
    if (maps->current_map == 1) {
        if (maps->ice_cave[(((int) position->y + 5) /
            (int) maps->ice_cave_size.y) + 1][(((int) position->x) /
            (int) maps->ice_cave_size.x) - 1] == '#') {
            return 1;
        }
    }
    if (maps->current_map == 3) {
        if (maps->demon_castle[(((int) position->y + 5) /
            (int) maps->demon_castle_size.y) + 1][(((int) position->x) /
            (int) maps->demon_castle_size.x) - 1] == '#') {
            return 1;
        }
    }
    return 0;
}

static sfVector2f change_x_move(sfVector2f sprite_position,
    component_position_t *enemy_position, int *moving, map_t *maps)
{
    sfVector2f move = {0};

    move = init_enemy_position(enemy_position);
    if (sprite_position.x > enemy_position->x) {
        if (!check_right(enemy_position, maps)) {
            change_move_x_axis(&move, 5, moving, RIGHT);
        }
    } else {
        if (!check_left(enemy_position, maps)) {
            change_move_x_axis(&move, -5, moving, LEFT);
        }
    }
    return move;
}

static sfVector2f change_y_move(sfVector2f sprite_position,
    component_position_t *enemy_position, int *moving, map_t *maps)
{
    sfVector2f move = {0};

    move = init_enemy_position(enemy_position);
    if (sprite_position.y > enemy_position->y) {
        if (!check_up(enemy_position, maps)) {
            change_move_y_axis(&move, 5, moving, UP);
        }
    } else {
        if (!check_down(enemy_position, maps)) {
            change_move_y_axis(&move, -5, moving, DOWN);
        }
    }
    return move;
}

static int check_limit(int x_y1, int x_y2)
{
    int limit = 0;

    limit = x_y1 - x_y2;
    if (limit < 0) {
        limit = -limit;
    }
    return limit;
}

sfVector2f move_enemy_to_player(entity_t *list_entity,
    char *name_entity, int *moving, map_t *maps)
{
    sfVector2f move = {0};
    sfVector2f sprite_position = {0};
    component_sprite_t *sprite = NULL;
    component_position_t *enemy_position = NULL;

    *moving = DEFAULT;
    sprite = find_component(list_entity, "mc", COMPONENT_SPRITE);
    sprite_position = sfSprite_getPosition(sprite->sprite);
    enemy_position = find_component(list_entity,
        name_entity, COMPONENT_POSITION);
    move = init_enemy_position(enemy_position);
    if (check_limit(enemy_position->x, sprite_position.x) > 10 && *moving
    == DEFAULT && compute_distance(enemy_position, sprite_position) < 300)
        move = change_x_move(sprite_position, enemy_position, moving, maps);
    if (check_limit(enemy_position->y, sprite_position.y) > 10
        && *moving == DEFAULT && compute_distance(enemy_position,
        sprite_position) < 300) {
        move = change_y_move(sprite_position, enemy_position, moving, maps);
    }
    return move;
}
