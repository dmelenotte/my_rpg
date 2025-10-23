/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-myrpg-guillaume1.blondel
** File description:
** pause_menu
*/

#include "../include/rpg.h"

void init_pause_play(rpg_t *rpg, global_data_t global_data,
    entity_t *list_entity)
{
    append_component_to_entity(list_entity, "pause_play",
        COMPONENT_SPRITE, set_sprite());
    assign_sprite(find_component(list_entity, "pause_play",
        COMPONENT_SPRITE), "pause_play_sprite", global_data);
    append_component_to_entity(list_entity, "pause_play",
        COMPONENT_POSITION, set_position());
    assign_sprite_position(find_component(list_entity,
        "pause_play", COMPONENT_SPRITE), &(component_position_t)
        {rpg->main_character->position.x - 32,
        rpg->main_character->position.y - 50});
    append_component_to_entity(list_entity, "pause_play",
        COMPONENT_BOX, set_box());
    append_component_to_entity(list_entity, "pause_play",
        COMPONENT_SCALE, set_scale());
    assign_scale(find_component(list_entity, "pause_play",
        COMPONENT_SCALE), 0.6, 0.6);
    assign_sprite_scale(find_component(list_entity, "pause_play",
        COMPONENT_SPRITE), find_component(list_entity, "pause_play",
        COMPONENT_SCALE));
}

void init_pause_exit(rpg_t *rpg, global_data_t global_data,
    entity_t *list_entity)
{
    append_component_to_entity(list_entity, "pause_exit",
        COMPONENT_SPRITE, set_sprite());
    assign_sprite(find_component(list_entity, "pause_exit",
        COMPONENT_SPRITE), "pause_exit_sprite", global_data);
    append_component_to_entity(list_entity, "pause_exit",
        COMPONENT_POSITION, set_position());
    assign_sprite_position(find_component(list_entity,
        "pause_exit", COMPONENT_SPRITE), &(component_position_t)
        {rpg->main_character->position.x - 30,
        rpg->main_character->position.y + 30});
    append_component_to_entity(list_entity, "pause_exit",
        COMPONENT_BOX, set_box());
    append_component_to_entity(list_entity, "pause_exit",
        COMPONENT_SCALE, set_scale());
    assign_scale(find_component(list_entity, "pause_exit",
        COMPONENT_SCALE), 0.6, 0.6);
    assign_sprite_scale(find_component(list_entity, "pause_exit",
        COMPONENT_SPRITE), find_component(list_entity, "pause_exit",
        COMPONENT_SCALE));
}

void init_pause_background(rpg_t *rpg, global_data_t global_data,
    entity_t *list_entity)
{
    rpg->pause_menu->rect = sfRectangleShape_create();
    sfRectangleShape_setSize(rpg->pause_menu->rect,
        (sfVector2f){1920, 1080});
    sfRectangleShape_setFillColor(rpg->pause_menu->rect,
        sfColor_fromRGBA(0, 0, 0, 150));
    sfRectangleShape_setPosition(rpg->pause_menu->rect, (sfVector2f)
        {rpg->main_character->position.x - 980,
        rpg->main_character->position.y - 540});
}

void set_pause_pos(rpg_t *rpg, entity_t *list_entity,
    global_data_t global_data)
{
    sfRectangleShape_setPosition(rpg->pause_menu->rect, (sfVector2f)
        {rpg->main_character->position.x - 980,
        rpg->main_character->position.y - 540});
    assign_sprite_position(find_component(list_entity,
        "pause_play", COMPONENT_SPRITE), &(component_position_t)
        {rpg->main_character->position.x - 32,
        rpg->main_character->position.y - 50});
    assign_sprite_box(find_component(list_entity,
        "pause_play", COMPONENT_BOX),
        find_component(list_entity, "pause_play", COMPONENT_SPRITE));
    assign_sprite_position(find_component(list_entity,
        "pause_exit", COMPONENT_SPRITE), &(component_position_t)
        {rpg->main_character->position.x - 30,
        rpg->main_character->position.y + 30});
    assign_sprite_box(find_component(list_entity,
        "pause_exit", COMPONENT_BOX),
        find_component(list_entity, "pause_exit", COMPONENT_SPRITE));
}

static void pause_hover_check_exit(rpg_t *rpg, entity_t *list_entity,
    sfVector2f world_pos)
{
    if (sfFloatRect_contains(find_component(list_entity,
        "pause_exit", COMPONENT_BOX), world_pos.x, world_pos.y)) {
        assign_sprite_scale(find_component(list_entity, "pause_exit",
            COMPONENT_SPRITE), &(component_scale_t){0.7, 0.7});
        assign_sprite_position(find_component(list_entity, "pause_exit",
            COMPONENT_SPRITE), &(component_position_t)
            {rpg->main_character->position.x - 38,
            rpg->main_character->position.y + 23});
    } else {
        assign_sprite_scale(find_component(list_entity, "pause_exit",
            COMPONENT_SPRITE), &(component_scale_t){0.6, 0.6});
        assign_sprite_position(find_component(list_entity,
            "pause_exit", COMPONENT_SPRITE), &(component_position_t)
            {rpg->main_character->position.x - 30,
            rpg->main_character->position.y + 30});
    }
}

static void pause_hover_check_pause(rpg_t *rpg, entity_t *list_entity,
    sfVector2f world_pos)
{
    if (sfFloatRect_contains(find_component(list_entity,
        "pause_play", COMPONENT_BOX), world_pos.x, world_pos.y)) {
        assign_sprite_scale(find_component(list_entity, "pause_play",
            COMPONENT_SPRITE), &(component_scale_t){0.7, 0.7});
        assign_sprite_position(find_component(list_entity, "pause_play",
            COMPONENT_SPRITE), &(component_position_t)
            {rpg->main_character->position.x - 40,
            rpg->main_character->position.y - 58});
    } else {
        assign_sprite_scale(find_component(list_entity, "pause_play",
            COMPONENT_SPRITE), &(component_scale_t){0.6, 0.6});
        assign_sprite_position(find_component(list_entity,
            "pause_play", COMPONENT_SPRITE), &(component_position_t)
            {rpg->main_character->position.x - 32,
            rpg->main_character->position.y - 50});
    }
}

static void pause_hover(rpg_t *rpg, entity_t *list_entity)
{
    sfVector2i pixel_pos = sfMouse_getPositionRenderWindow(rpg->window);
    sfVector2f world_pos = sfRenderWindow_mapPixelToCoords(rpg->window,
    pixel_pos, sfRenderWindow_getView(rpg->window));

    pause_hover_check_pause(rpg, list_entity, world_pos);
    pause_hover_check_exit(rpg, list_entity, world_pos);
}

void pause_menu(rpg_t *rpg, entity_t *list_entity, global_data_t global_data)
{
    if (rpg->pause_menu->is_paused == 0 || rpg->fast_travel == true)
        return;
    sfMusic_pause(rpg->main_music);
    set_pause_pos(rpg, list_entity, global_data);
    sfRenderWindow_drawRectangleShape(rpg->window, rpg->pause_menu->rect,
        NULL);
    pause_hover(rpg, list_entity);
    display_sprite((component_sprite_t *) find_component(list_entity,
        "pause_play", COMPONENT_SPRITE), rpg->window);
    display_sprite((component_sprite_t *) find_component(list_entity,
        "pause_exit", COMPONENT_SPRITE), rpg->window);
    if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue &&
    sfTime_asSeconds(sfClock_getElapsedTime(rpg->pause_menu->clock)) > 0.2) {
        rpg->pause_menu->is_paused = 0;
        sfMusic_play(rpg->main_music);
    }
}
