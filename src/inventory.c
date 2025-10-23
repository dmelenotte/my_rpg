/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-myrpg-guillaume1.blondel
** File description:
** inventory
*/

#include "../include/rpg.h"
#include "string.h"

void init_inventory_background(rpg_t *rpg, global_data_t global_data,
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

void init_inventory(rpg_t *rpg, global_data_t global_data,
    entity_t *list_entity)
{
    append_component_to_entity(list_entity, "inventory",
        COMPONENT_SPRITE, set_sprite());
    assign_sprite(find_component(list_entity, "inventory",
        COMPONENT_SPRITE), "inventory_sprite", global_data);
    append_component_to_entity(list_entity, "inventory",
        COMPONENT_POSITION, set_position());
    assign_sprite_position(find_component(list_entity,
        "inventory", COMPONENT_SPRITE), &(component_position_t)
        {rpg->main_character->position.x - 130,
        rpg->main_character->position.y - 110});
    append_component_to_entity(list_entity, "inventory",
        COMPONENT_BOX, set_box());
    assign_sprite_box(find_component(list_entity, "inventory",
        COMPONENT_BOX), find_component(list_entity, "inventory",
        COMPONENT_SPRITE));
    append_component_to_entity(list_entity, "inventory",
        COMPONENT_SCALE, set_scale());
    assign_sprite_scale(find_component(list_entity, "inventory",
        COMPONENT_SPRITE), &(component_scale_t) {0.6, 0.6});
}

static void set_inventory_pos(rpg_t *rpg, entity_t *list_entity,
    global_data_t global_data)
{
    assign_sprite_position(find_component(list_entity,
        "inventory", COMPONENT_SPRITE), &(component_position_t)
        {rpg->main_character->position.x - 130,
        rpg->main_character->position.y - 110});
    assign_sprite_box(find_component(list_entity, "inventory",
        COMPONENT_BOX), find_component(list_entity, "inventory",
        COMPONENT_SPRITE));
    sfRectangleShape_setPosition(rpg->pause_menu->rect, (sfVector2f)
        {rpg->main_character->position.x - 980,
        rpg->main_character->position.y - 540});
}

static void display_inventory(rpg_t *rpg, entity_t *list_entity, global_data_t
    global_data)
{
    sfRenderWindow_drawRectangleShape(rpg->window, rpg->pause_menu->rect,
        NULL);
    display_sprite((component_sprite_t *) find_component(list_entity,
        "inventory", COMPONENT_SPRITE), rpg->window);
    if (sfKeyboard_isKeyPressed(sfKeyI) == sfTrue &&
    sfTime_asSeconds(sfClock_getElapsedTime(rpg->inventory->clock)) > 0.2)
        rpg->inventory->is_open = 0;
}

static void load_sword(rpg_t *rpg, entity_t *list_entity,
    global_data_t global_data)
{
    append_component_to_entity(list_entity, "item",
        COMPONENT_SPRITE, set_sprite());
    assign_sprite(find_component(list_entity, "item",
        COMPONENT_SPRITE), "weapon_sprite", global_data);
    append_component_to_entity(list_entity, "item",
        COMPONENT_POSITION, set_position());
    assign_sprite_position(find_component(list_entity,
        "item", COMPONENT_SPRITE), &(component_position_t)
        {rpg->main_character->position.x - 52,
        rpg->main_character->position.y + 4});
    append_component_to_entity(list_entity, "item",
        COMPONENT_SCALE, set_scale());
    assign_sprite_scale(find_component(list_entity, "item",
        COMPONENT_SPRITE), &(component_scale_t) {0.3, 0.3});
    assign_sprite_rotation(find_component(list_entity, "item",
        COMPONENT_SPRITE), &(component_rotation_t) {0});
    display_sprite(find_component(list_entity, "item",
        COMPONENT_SPRITE), rpg->window);
}

void return_sword(rpg_t *rpg, entity_t *list_entity, global_data_t global_data)
{
    append_component_to_entity(list_entity, "sword",
        COMPONENT_SPRITE, set_sprite());
    assign_sprite(find_component(list_entity, "sword",
        COMPONENT_SPRITE), "weapon_sprite", global_data);
    append_component_to_entity(list_entity, "sword",
        COMPONENT_SCALE, set_scale());
    append_component_to_entity(list_entity, "sword",
        COMPONENT_POSITION, set_position());
    append_component_to_entity(list_entity, "sword",
        COMPONENT_FRAME, set_clock());
    append_component_to_entity(list_entity, "sword",
        COMPONENT_ROTATION, set_rotation());
    append_component_to_entity(list_entity, "sword", COMPONENT_RECT_DISPLAY,
        set_rect_display());
    assign_sprite_position(find_component(list_entity, "sword",
        COMPONENT_SPRITE), &rpg->main_character->sword);
    assign_sprite_rotation(find_component(list_entity, "sword",
        COMPONENT_SPRITE), find_component(list_entity,
        "sword", COMPONENT_ROTATION));
}

void return_left_sword(rpg_t *rpg, entity_t *list_entity,
    global_data_t global_data)
{
    append_component_to_entity(list_entity, "sword",
        COMPONENT_SPRITE, set_sprite());
    assign_sprite(find_component(list_entity, "sword",
        COMPONENT_SPRITE), "weapon_sprite", global_data);
    append_component_to_entity(list_entity, "sword",
        COMPONENT_SCALE, set_scale());
    append_component_to_entity(list_entity, "sword",
        COMPONENT_POSITION, set_position());
    append_component_to_entity(list_entity, "sword",
        COMPONENT_FRAME, set_clock());
    append_component_to_entity(list_entity, "sword",
        COMPONENT_ROTATION, set_rotation());
    append_component_to_entity(list_entity, "sword", COMPONENT_RECT_DISPLAY,
        set_rect_display());
    assign_sprite_position(find_component(list_entity, "sword",
        COMPONENT_SPRITE), &rpg->main_character->left_sword);
    assign_sprite_rotation(find_component(list_entity, "sword",
        COMPONENT_SPRITE), find_component(list_entity, "sword",
        COMPONENT_ROTATION));
}

static void load_potion(rpg_t *rpg, entity_t *list_entity,
    global_data_t global_data, int i)
{
    append_component_to_entity(list_entity, "item",
        COMPONENT_SPRITE, set_sprite());
    assign_sprite(find_component(list_entity, "item",
        COMPONENT_SPRITE), "health_potion_sprite", global_data);
    append_component_to_entity(list_entity, "item",
        COMPONENT_POSITION, set_position());
    assign_sprite_position(find_component(list_entity, "item", COMPONENT_SPRITE
    ), &(component_position_t) {rpg->main_character->position.x - 34 + (i * 36)
    , rpg->main_character->position.y - 18 + i});
    append_component_to_entity(list_entity, "item",
        COMPONENT_SCALE, set_scale());
    assign_sprite_scale(find_component(list_entity, "item",
        COMPONENT_SPRITE), &(component_scale_t) {0.06, 0.06});
    assign_sprite_rotation(find_component(list_entity, "item",
        COMPONENT_SPRITE), &(component_rotation_t) {0});
    display_sprite(find_component(list_entity, "item",
        COMPONENT_SPRITE), rpg->window);
}

void inventory(rpg_t *rpg, entity_t *list_entity, global_data_t global_data)
{
    if (rpg->inventory->is_open == 0 || rpg->pause_menu->is_paused == 1)
        return;
    set_inventory_pos(rpg, list_entity, global_data);
    display_inventory(rpg, list_entity, global_data);
    load_sword(rpg, list_entity, global_data);
    for (int i = 0; i <= rpg->inventory->nb_items &&
    rpg->inventory->items[i] != NULL; i++) {
        if (strcmp(rpg->inventory->items[i], "health_potion") == 0)
            load_potion(rpg, list_entity, global_data, i - 1);
    }
}
