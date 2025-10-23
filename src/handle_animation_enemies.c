/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-myrpg-guillaume1.blondel
** File description:
** handle_animation_enemies.c
*/

#include "../include/rpg.h"

static const sfFloatRect left_shift[4] = {
    {0, 48, 48, 48},
    {48, 48, 48, 48},
    {96, 48, 48, 48},
    {-1, -1, -1, -1},
};

static const sfFloatRect right_shift[4] = {
    {0, 96, 48, 48},
    {48, 96, 48, 48},
    {96, 96, 48, 48},
    {-1, -1, -1, -1},
};

static const sfFloatRect up_shift[4] = {
    {0, 0, 48, 48},
    {48, 0, 48, 48},
    {96, 0, 48, 48},
    {-1, -1, -1, -1},
};

static const sfFloatRect down_shift[4] = {
    {0, 144, 48, 48},
    {48, 144, 48, 48},
    {96, 144, 48, 48},
    {-1, -1, -1, -1},
};

static void animation_left_right(entity_t *list_entity, char *name_entity,
    int moving, int *i_anim)
{
    if (moving == LEFT) {
        if (left_shift[*i_anim].top == -1) {
            *i_anim = 0;
        }
        change_rect_display_values(find_component(list_entity, name_entity,
            COMPONENT_RECT_DISPLAY), left_shift[*i_anim], ASSIGN);
    }
    if (moving == RIGHT) {
        if (right_shift[*i_anim].top == -1) {
            *i_anim = 0;
        }
        change_rect_display_values(find_component(list_entity, name_entity,
            COMPONENT_RECT_DISPLAY), right_shift[*i_anim], ASSIGN);
    }
}

static void animation_up_down(entity_t *list_entity, char *name_entity,
    int moving, int *i_anim)
{
    if (moving == UP) {
        if (up_shift[*i_anim].top == -1) {
            *i_anim = 0;
        }
        change_rect_display_values(find_component(list_entity, name_entity,
            COMPONENT_RECT_DISPLAY), up_shift[*i_anim], ASSIGN);
    }
    if (moving == DOWN) {
        if (down_shift[*i_anim].top == -1) {
            *i_anim = 0;
        }
        change_rect_display_values(find_component(list_entity, name_entity,
            COMPONENT_RECT_DISPLAY), down_shift[*i_anim], ASSIGN);
    }
}

void handle_animation(entity_t *list_entity, char *name_entity, int moving)
{
    static int i_anim = 0;

    if (moving == DEFAULT) {
        return;
    }
    animation_left_right(list_entity, name_entity, moving, &i_anim);
    animation_up_down(list_entity, name_entity, moving, &i_anim);
    i_anim++;
}
