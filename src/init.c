/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-myrpg-guillaume1.blondel
** File description:
** init
*/

#include "../include/rpg.h"
#include "string.h"

static void init_map(rpg_t *rpg, global_data_t global_data,
    entity_t *list_entity)
{
    component_position_t position = {10, -15};

    append_component_to_entity(list_entity, "world_map",
        COMPONENT_SPRITE, set_sprite());
    assign_sprite(find_component(list_entity, "world_map",
        COMPONENT_SPRITE), "world_map_sprite", global_data);
    append_component_to_entity(list_entity, "world_map",
        COMPONENT_POSITION, set_position());
    assign_sprite_position(find_component(list_entity,
        "world_map", COMPONENT_SPRITE), &position);
}

static void init_mc_rect(main_character_t *mc)
{
    mc->nb_rect = 0;
    mc->rect = malloc(sizeof(component_rect_display_t *) * 4);
    mc->rect[DOWN] = malloc(sizeof(component_rect_display_t) * 3);
    mc->rect[DOWN][0] = (component_rect_display_t){50, 0, 50, 48};
    mc->rect[DOWN][1] = (component_rect_display_t){100, 0, 50, 48};
    mc->rect[DOWN][2] = (component_rect_display_t){0, 0, 50, 48};
    mc->rect[UP] = malloc(sizeof(component_rect_display_t) * 3);
    mc->rect[UP][0] = (component_rect_display_t){50, 146, 50, 48};
    mc->rect[UP][1] = (component_rect_display_t){100, 146, 50, 48};
    mc->rect[UP][2] = (component_rect_display_t){0, 146, 50, 48};
    mc->rect[LEFT] = malloc(sizeof(component_rect_display_t) * 3);
    mc->rect[LEFT][0] = (component_rect_display_t){50, 48, 50, 48};
    mc->rect[LEFT][1] = (component_rect_display_t){100, 48, 50, 48};
    mc->rect[LEFT][2] = (component_rect_display_t){0, 48, 50, 48};
    mc->rect[RIGHT] = malloc(sizeof(component_rect_display_t) * 3);
    mc->rect[RIGHT][0] = (component_rect_display_t){50, 98, 50, 48};
    mc->rect[RIGHT][1] = (component_rect_display_t){100, 98, 50, 48};
    mc->rect[RIGHT][2] = (component_rect_display_t){0, 98, 50, 48};
}

static void init_mc(rpg_t *rpg, global_data_t global_data,
    entity_t *list_entity)
{
    init_mc_rect(rpg->main_character);
    rpg->main_character->position = (component_position_t){1030, 1230};
    init_mc_life(rpg, global_data, list_entity);
    append_component_to_entity(list_entity, "mc",
        COMPONENT_SPRITE, set_sprite());
    assign_sprite(find_component(list_entity, "mc", COMPONENT_SPRITE),
        "mc_sprite", global_data);
    append_component_to_entity(list_entity, "mc",
        COMPONENT_POSITION, set_position());
    assign_sprite_position(find_component(list_entity,
        "mc", COMPONENT_SPRITE), &rpg->main_character->position);
    append_component_to_entity(list_entity, "mc", COMPONENT_RECT_DISPLAY,
        set_rect_display());
    assign_sprite_rect_display(&rpg->main_character->rect[DOWN][0],
        find_component(list_entity, "mc", COMPONENT_SPRITE));
    append_component_to_entity(list_entity, "mc", COMPONENT_SCALE,
        set_scale());
    assign_sprite_scale(find_component(list_entity, "mc", COMPONENT_SPRITE),
        &(component_scale_t){0.7, 0.7});
}

static void init_sword_pos(rpg_t *rpg)
{
    rpg->main_character->side = 0;
    rpg->main_character->sword = rpg->main_character->position;
    rpg->main_character->sword.y += 28;
    rpg->main_character->sword.x += 23;
    rpg->main_character->left_sword = rpg->main_character->position;
    rpg->main_character->left_sword.y += 22;
    rpg->main_character->left_sword.x -= 28;
}

static void init_sword(rpg_t *rpg, global_data_t global_data,
    entity_t *list_entity)
{
    init_sword_pos(rpg);
    append_component_to_entity(list_entity, "sword",
        COMPONENT_SPRITE, set_sprite());
    assign_sprite((component_sprite_t *) find_component(list_entity, "sword",
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
    init_the_sword_again(rpg, global_data, list_entity);
}

static void init_town(rpg_t *rpg, global_data_t global_data,
    entity_t *list_entity)
{
    component_position_t position = {10, -15};

    append_component_to_entity(list_entity, "town",
        COMPONENT_SPRITE, set_sprite());
    assign_sprite(find_component(list_entity, "town",
        COMPONENT_SPRITE), "town_sprite", global_data);
    append_component_to_entity(list_entity, "town",
        COMPONENT_POSITION, set_position());
    assign_sprite_position(find_component(list_entity,
        "town", COMPONENT_SPRITE), &position);
}

static void init_ice_cave(rpg_t *rpg, global_data_t global_data,
    entity_t *list_entity)
{
    component_position_t position = {10, -15};

    append_component_to_entity(list_entity, "ice_cave",
        COMPONENT_SPRITE, set_sprite());
    assign_sprite(find_component(list_entity, "ice_cave",
        COMPONENT_SPRITE), "ice_cave_sprite", global_data);
    append_component_to_entity(list_entity, "ice_cave",
        COMPONENT_POSITION, set_position());
    assign_sprite_position(find_component(list_entity,
        "ice_cave", COMPONENT_SPRITE), &position);
}

static void init_boss_map(rpg_t *rpg, global_data_t global_data,
    entity_t *list_entity)
{
    component_position_t position = {-15, -15};

    append_component_to_entity(list_entity, "boss_map",
        COMPONENT_SPRITE, set_sprite());
    assign_sprite(find_component(list_entity, "boss_map",
        COMPONENT_SPRITE), "boss_map_sprite", global_data);
    append_component_to_entity(list_entity, "boss_map",
        COMPONENT_POSITION, set_position());
    assign_sprite_position(find_component(list_entity,
        "boss_map", COMPONENT_SPRITE), &position);
}

static void rpg_init(rpg_t *rpg, global_data_t global_data, entity_t *entity)
{
    rpg->mode = (sfVideoMode){1920, 1080, 32};
    rpg->window = sfRenderWindow_create(rpg->mode, "Alexis' Quest",
        sfClose | sfResize, NULL);
    sfRenderWindow_setFramerateLimit(rpg->window, 120);
    rpg->view = sfView_createFromRect(
        (sfFloatRect){0, 0, 640, 400});
    rpg->main_character = malloc(sizeof(main_character_t));
    rpg->clocks = malloc(sizeof(clocks_t));
    rpg->clocks->clock = sfClock_create();
    rpg->clocks->clock_anim = sfClock_create();
    rpg->main_menu = malloc(sizeof(main_menu_t));
    rpg->pause_menu = malloc(sizeof(pause_menu_t));
    rpg->pause_menu->is_paused = 0;
    rpg->pause_menu->clock = sfClock_create();
}

void init_all(rpg_t *rpg, global_data_t global_data, entity_t *entity)
{
    rpg_init(rpg, global_data, entity);
    init_ice_cave(rpg, global_data, entity);
    init_boss_map(rpg, global_data, entity);
    init_map(rpg, global_data, entity);
    init_town(rpg, global_data, entity);
    init_mc(rpg, global_data, entity);
    init_sword(rpg, global_data, entity);
    rpg->clocks = malloc(sizeof(clocks_t));
    rpg->clocks->general_clock = sfClock_create();
    rpg->clocks->clock = sfClock_create();
    rpg->clocks->clock_anim = sfClock_create();
    init_pnj(global_data, entity);
    init_boat(global_data, entity);
    rpg->fast_travel = false;
    init_pause_background(rpg, global_data, entity);
    init_pause_play(rpg, global_data, entity);
    init_pause_exit(rpg, global_data, entity);
    init_inventory_background(rpg, global_data, entity);
    init_inventory(rpg, global_data, entity);
    init_lives(rpg, global_data, entity);
}
