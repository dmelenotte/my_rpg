/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-myrpg-guillaume1.blondel
** File description:
** mc_mouvement.c
*/

#include "../include/rpg.h"

static void anim_mc(rpg_t *rpg)
{
    if (sfTime_asSeconds(sfClock_getElapsedTime(
            rpg->clocks->clock_anim)) > 0.1) {
        if (rpg->main_character->nb_rect == 2)
            rpg->main_character->nb_rect = 0;
        else
            rpg->main_character->nb_rect++;
        sfClock_restart(rpg->clocks->clock_anim);
    }
}

static void check_t_mvmt(rpg_t *rpg, entity_t *list_entity, map_t *maps)
{
    if (rpg->main_character->side != 1) {
        rpg->main_character->side = 1;
    }
    assign_rotation((component_rotation_t *)find_component(list_entity,
        "sword", COMPONENT_ROTATION), -45);
    assign_sprite_rotation(find_component(list_entity, "sword",
        COMPONENT_SPRITE), find_component(list_entity,
        "sword", COMPONENT_ROTATION));
    sfView_move(rpg->view, (sfVector2f){0, -10});
    rpg->main_character->position.y -= 10;
    rpg->main_character->left_sword = rpg->main_character->position;
    rpg->main_character->left_sword.y += 20;
    rpg->main_character->left_sword.x += 10;
    assign_sprite_position((component_sprite_t *) find_component(
        list_entity, "mc", COMPONENT_SPRITE),
        &rpg->main_character->position);
    assign_sprite_position((component_sprite_t *) find_component(
        list_entity, "sword", COMPONENT_SPRITE),
        &rpg->main_character->left_sword);
}

static void handle_t_mvmt(rpg_t *rpg, entity_t *list_entity, map_t *maps)
{
    if (sfKeyboard_isKeyPressed(sfKeyZ) == sfTrue &&
        sfTime_asSeconds(sfClock_getElapsedTime(rpg->clocks->clock)) > 0.05) {
        if (is_u_possible(rpg, list_entity, maps) == 0)
            check_t_mvmt(rpg, list_entity, maps);
        assign_sprite_rect_display(&rpg->main_character->rect
            [UP][rpg->main_character->nb_rect],
            (component_sprite_t *)find_component(list_entity, "mc",
            COMPONENT_SPRITE));
        anim_mc(rpg);
        sfClock_restart(rpg->clocks->clock);
    }
}

static void check_b_mvmt(rpg_t *rpg, entity_t *list_entity, map_t *maps)
{
    if (rpg->main_character->side != 0) {
        rpg->main_character->side = 0;
    }
    assign_rotation((component_rotation_t *)find_component(list_entity,
        "sword", COMPONENT_ROTATION), 70);
    assign_sprite_rotation(find_component(list_entity, "sword",
        COMPONENT_SPRITE), find_component(list_entity,
        "sword", COMPONENT_ROTATION));
    sfView_move(rpg->view, (sfVector2f){0, 10});
    rpg->main_character->position.y += 10;
    rpg->main_character->sword = rpg->main_character->position;
    rpg->main_character->sword.y += 28;
    rpg->main_character->sword.x += 23;
    assign_sprite_position((component_sprite_t *) find_component(
        list_entity, "mc", COMPONENT_SPRITE),
            &rpg->main_character->position);
    assign_sprite_position((component_sprite_t *) find_component(
        list_entity, "sword", COMPONENT_SPRITE),
        &rpg->main_character->sword);
}

static void handle_b_mvmt(rpg_t *rpg, entity_t *list_entity, map_t *maps)
{
    if (sfKeyboard_isKeyPressed(sfKeyS) == sfTrue &&
        sfTime_asSeconds(sfClock_getElapsedTime(rpg->clocks->clock)) > 0.05) {
        if (is_d_possible(rpg, list_entity, maps) == 0)
            check_b_mvmt(rpg, list_entity, maps);
        assign_sprite_rect_display(&rpg->main_character->rect
            [DOWN][rpg->main_character->nb_rect],
            (component_sprite_t *)find_component(list_entity, "mc",
            COMPONENT_SPRITE));
        anim_mc(rpg);
        sfClock_restart(rpg->clocks->clock);
    }
}

static void check_l_mvmt(rpg_t *rpg, entity_t *list_entity, map_t *maps)
{
    if (rpg->main_character->side != 2) {
        rpg->main_character->side = 2;
    }
    assign_rotation((component_rotation_t *)find_component(list_entity,
        "sword", COMPONENT_ROTATION), -70);
    assign_sprite_rotation(find_component(list_entity, "sword",
        COMPONENT_SPRITE), find_component(list_entity,
        "sword", COMPONENT_ROTATION));
    sfView_move(rpg->view, (sfVector2f){-10, 0});
    rpg->main_character->position.x -= 10;
    rpg->main_character->left_sword = rpg->main_character->position;
    rpg->main_character->left_sword.y += 25;
    rpg->main_character->left_sword.x += 10;
    assign_sprite_position((component_sprite_t *) find_component(
        list_entity, "mc", COMPONENT_SPRITE),
        &rpg->main_character->position);
    assign_sprite_position((component_sprite_t *) find_component(
        list_entity, "sword", COMPONENT_SPRITE),
        &rpg->main_character->left_sword);
}

static void handle_l_mvmt(rpg_t *rpg, entity_t *list_entity, map_t *maps)
{
    if (sfKeyboard_isKeyPressed(sfKeyQ) == sfTrue &&
        sfTime_asSeconds(sfClock_getElapsedTime(rpg->clocks->clock)) > 0.05) {
        if (is_l_possible(rpg, list_entity, maps) == 0)
            check_l_mvmt(rpg, list_entity, maps);
        assign_sprite_rect_display(&rpg->main_character->rect
            [LEFT][rpg->main_character->nb_rect],
            (component_sprite_t *)find_component(list_entity, "mc",
            COMPONENT_SPRITE));
        anim_mc(rpg);
        sfClock_restart(rpg->clocks->clock);
    }
}

static void check_r_mvmt(rpg_t *rpg, entity_t *list_entity, map_t *maps)
{
    if (rpg->main_character->side != 3) {
        rpg->main_character->side = 3;
    }
    assign_rotation((component_rotation_t *)find_component(list_entity,
        "sword", COMPONENT_ROTATION), 70);
    assign_sprite_rotation(find_component(list_entity, "sword",
        COMPONENT_SPRITE), find_component(list_entity,
        "sword", COMPONENT_ROTATION));
    sfView_move(rpg->view, (sfVector2f){10, 0});
    rpg->main_character->position.x += 10;
    rpg->main_character->sword = rpg->main_character->position;
    rpg->main_character->sword.y += 27;
    rpg->main_character->sword.x += 22;
    assign_sprite_position((component_sprite_t *) find_component(
        list_entity, "mc", COMPONENT_SPRITE),
        &rpg->main_character->position);
    assign_sprite_position((component_sprite_t *) find_component(
        list_entity, "sword", COMPONENT_SPRITE),
        &rpg->main_character->sword);
}

static void handle_r_mvmt(rpg_t *rpg, entity_t *list_entity, map_t *maps)
{
    if (sfKeyboard_isKeyPressed(sfKeyD) == sfTrue &&
        sfTime_asSeconds(sfClock_getElapsedTime(
            rpg->clocks->clock)) > 0.05) {
        if (is_r_possible(rpg, list_entity, maps) == 0)
            check_r_mvmt(rpg, list_entity, maps);
        assign_sprite_rect_display(&rpg->main_character->rect
            [RIGHT][rpg->main_character->nb_rect],
            (component_sprite_t *)find_component(list_entity, "mc",
            COMPONENT_SPRITE));
        anim_mc(rpg);
        sfClock_restart(rpg->clocks->clock);
    }
}

void mouvement(rpg_t *rpg, entity_t *list_entity, map_t *maps)
{
    if (rpg->fast_travel == true)
        return;
    if (rpg->pause_menu->is_paused == 0 && rpg->inventory->is_open == 0) {
        handle_t_mvmt(rpg, list_entity, maps);
        handle_b_mvmt(rpg, list_entity, maps);
        handle_l_mvmt(rpg, list_entity, maps);
        handle_r_mvmt(rpg, list_entity, maps);
    }
}
