/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-myrpg-guillaume1.blondel
** File description:
** sword_attack.c
*/

#include "../include/rpg.h"

static void set_hit(entity_t *list_entity, entity_t *enemy_entity)
{
    component_position_t *enemy_position = NULL;

    enemy_position = find_component(list_entity, enemy_entity->name_entity,
        COMPONENT_POSITION);
    assign_position(find_component(list_entity, "hit", COMPONENT_POSITION),
        enemy_position->x, enemy_position->y);
    assign_sprite_position(find_component(list_entity, "hit",
        COMPONENT_SPRITE), find_component(list_entity, "hit",
        COMPONENT_POSITION));
    change_state(find_component(list_entity, "hit", COMPONENT_STATE),
        SET_DISPLAY, true);
}

static void check_touch_entity(entity_t *list_entity)
{
    entity_t *enemy_entity = NULL;

    enemy_entity = find_entity_by_type(list_entity, ENEMY, true);
    while (enemy_entity != NULL) {
        if (global_enter_in_collision(find_component(list_entity,
            "sword", COMPONENT_SPRITE), find_component(list_entity,
            enemy_entity->name_entity, COMPONENT_SPRITE)) == true) {
            change_health(find_component(list_entity,
                enemy_entity->name_entity, COMPONENT_HEALTH), -3);
            set_hit(list_entity, enemy_entity);
        }
        enemy_entity = find_entity_by_type(list_entity, ENEMY, false);
    }
    if (global_enter_in_collision(find_component(list_entity,
        "sword", COMPONENT_SPRITE), find_component(list_entity,
        "boss", COMPONENT_SPRITE)) == true) {
        change_health(find_component(list_entity,
            "boss", COMPONENT_HEALTH), -3);
        set_hit(list_entity, find_entity(list_entity, "boss"));
    }
}

static void init_shifting(sfFloatRect *shifting)
{
    shifting->left = 150;
    shifting->height = 70;
}

static void change_left_rotation(rpg_t *rpg, entity_t *list_entity)
{
    if (rpg->main_character->side == 1 || rpg->main_character->side == 2) {
        assign_rotation((component_rotation_t *)find_component(list_entity,
            "sword", COMPONENT_ROTATION), -135);
        assign_sprite_rotation(find_component(list_entity, "sword",
            COMPONENT_SPRITE), find_component(list_entity,
            "sword", COMPONENT_ROTATION));
    }
    if (rpg->main_character->side == 3) {
        assign_rotation((component_rotation_t *)find_component(list_entity,
        "sword", COMPONENT_ROTATION), 0);
        assign_sprite_rotation(find_component(list_entity, "sword",
        COMPONENT_SPRITE), find_component(list_entity,
        "sword", COMPONENT_ROTATION));
    }
}

static void make_animation(entity_t *list_entity, int *i_shift_attack)
{
    sfFloatRect shifting = {0};

    init_shifting(&shifting);
    if (check_time(find_component(list_entity, "sword",
        COMPONENT_FRAME), 0.1f, SUPERIOR) == true) {
        change_rect_display_values(find_component(list_entity, "sword",
            COMPONENT_RECT_DISPLAY), shifting, ADD);
        assign_sprite_rect_display(find_component(list_entity, "sword",
            COMPONENT_RECT_DISPLAY), find_component(list_entity,
            "sword", COMPONENT_SPRITE));
        restart_time(find_component(list_entity, "sword", COMPONENT_FRAME));
        *i_shift_attack += 1;
    }
}

static void reset_sides(rpg_t *rpg, entity_t *list_entity,
    int *i_shift_attack, bool *is_pressed)
{
    if (rpg->main_character->side == 2) {
        assign_rotation((component_rotation_t *)find_component(list_entity,
            "sword", COMPONENT_ROTATION), -45);
        assign_sprite_rotation(find_component(list_entity, "sword",
            COMPONENT_SPRITE), find_component(list_entity,
            "sword", COMPONENT_ROTATION));
    }
    if (rpg->main_character->side == 3) {
        assign_rotation((component_rotation_t *)find_component(list_entity,
            "sword", COMPONENT_ROTATION), 70);
        assign_sprite_rotation(find_component(list_entity, "sword",
            COMPONENT_SPRITE), find_component(list_entity,
            "sword", COMPONENT_ROTATION));
    }
}

static void reset_animation(entity_t *list_entity, int *i_shift_attack,
    bool *is_pressed, bool *is_attack)
{
    if (*i_shift_attack > 4) {
        change_rect_display_values(find_component(list_entity, "sword",
            COMPONENT_RECT_DISPLAY), (sfFloatRect){0, 0, 150, 150}, ASSIGN);
        assign_sprite_rect_display(find_component(list_entity, "sword",
            COMPONENT_RECT_DISPLAY), find_component(list_entity,
            "sword", COMPONENT_SPRITE));
        *i_shift_attack = 0;
        *is_pressed = false;
        *is_attack = false;
        change_state(find_component(list_entity, "hit", COMPONENT_STATE),
            SET_DISPLAY, false);
    }
}

void sword_attack(rpg_t *rpg, entity_t *list_entity)
{
    static bool is_pressed = false;
    static bool is_attack = false;
    static int i_shift_attack = 0;

    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        is_pressed = true;
        change_left_rotation(rpg, list_entity);
    }
    if (is_pressed == true) {
        if (is_attack == false) {
            check_touch_entity(list_entity);
            is_attack = true;
        }
        make_animation(list_entity, &i_shift_attack);
        reset_animation(list_entity, &i_shift_attack, &is_pressed, &is_attack);
        if (i_shift_attack == 0) {
            reset_sides(rpg, list_entity, &i_shift_attack, &is_pressed);
        }
    }
}
