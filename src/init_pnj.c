/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-myrpg-guillaume1.blondel
** File description:
** init
*/

#include "../include/rpg.h"

static void init_third_sprite(global_data_t global_data,
    entity_t *list_entity)
{
    component_scale_t scale = {0.5, 0.5};

    append_component_to_entity(list_entity, "pnj3",
        COMPONENT_SPRITE, set_sprite());
    assign_sprite(find_component(list_entity, "pnj3", COMPONENT_SPRITE),
        "third_pnj_sprite", global_data);
    append_component_to_entity(list_entity, "pnj3",
        COMPONENT_POSITION, set_position());
    assign_sprite_position(find_component(list_entity,
        "pnj3", COMPONENT_SPRITE), &(component_position_t){1100, 810});
    append_component_to_entity(list_entity, "pnj3", COMPONENT_RECT_DISPLAY,
        set_rect_display());
    assign_sprite_rect_display(&(component_rect_display_t){0, 0, 60, 62},
        find_component(list_entity, "pnj3", COMPONENT_SPRITE));
    append_component_to_entity(list_entity, "pnj3", COMPONENT_SCALE,
        set_scale());
    assign_sprite_scale(find_component(list_entity, "pnj3", COMPONENT_SPRITE),
        &scale);
}

static void init_second_sprite(global_data_t global_data,
    entity_t *list_entity)
{
    component_scale_t scale = {0.5, 0.5};

    append_component_to_entity(list_entity, "pnj2",
        COMPONENT_SPRITE, set_sprite());
    assign_sprite(find_component(list_entity, "pnj2", COMPONENT_SPRITE),
        "second_pnj_sprite", global_data);
    append_component_to_entity(list_entity, "pnj2",
        COMPONENT_POSITION, set_position());
    assign_sprite_position(find_component(list_entity,
        "pnj2", COMPONENT_SPRITE), &(component_position_t){360, 720});
    append_component_to_entity(list_entity, "pnj2", COMPONENT_RECT_DISPLAY,
        set_rect_display());
    assign_sprite_rect_display(&(component_rect_display_t){0, 0, 60, 62},
        find_component(list_entity, "pnj2", COMPONENT_SPRITE));
    append_component_to_entity(list_entity, "pnj2", COMPONENT_SCALE,
        set_scale());
    assign_sprite_scale(find_component(list_entity, "pnj2", COMPONENT_SPRITE),
        &scale);
}

static void init_first_pnj(global_data_t global_data, entity_t *list_entity)
{
    component_scale_t scale = {0.5, 0.5};

    append_component_to_entity(list_entity, "pnj",
        COMPONENT_SPRITE, set_sprite());
    assign_sprite(find_component(list_entity, "pnj", COMPONENT_SPRITE),
        "first_pnj_sprite", global_data);
    append_component_to_entity(list_entity, "pnj",
        COMPONENT_POSITION, set_position());
    assign_sprite_position(find_component(list_entity,
        "pnj", COMPONENT_SPRITE), &(component_position_t){780, 710});
    append_component_to_entity(list_entity, "pnj", COMPONENT_RECT_DISPLAY,
        set_rect_display());
    assign_sprite_rect_display(&(component_rect_display_t){0, 0, 60, 62},
        find_component(list_entity, "pnj", COMPONENT_SPRITE));
    append_component_to_entity(list_entity, "pnj", COMPONENT_SCALE,
        set_scale());
    assign_sprite_scale(find_component(list_entity, "pnj", COMPONENT_SPRITE),
        &scale);
}

static void init_quest_pnj(global_data_t global_data, entity_t *list_entity)
{
    component_scale_t scale = {0.7, 0.7};

    append_component_to_entity(list_entity, "quester_pnj", COMPONENT_FRAME,
        set_clock());
    append_component_to_entity(list_entity, "quester_pnj",
        COMPONENT_SPRITE, set_sprite());
    assign_sprite(find_component(list_entity, "quester_pnj", COMPONENT_SPRITE),
        "pnj_quest_sprite", global_data);
    append_component_to_entity(list_entity, "quester_pnj",
        COMPONENT_POSITION, set_position());
    assign_sprite_position(find_component(list_entity,
        "quester_pnj", COMPONENT_SPRITE), &(component_position_t){970, 1030});
    append_component_to_entity(list_entity, "quester_pnj",
        COMPONENT_RECT_DISPLAY, set_rect_display());
    assign_sprite_rect_display(&(component_rect_display_t){95, 0, 50, 48},
        find_component(list_entity, "quester_pnj", COMPONENT_SPRITE));
    append_component_to_entity(list_entity, "quester_pnj", COMPONENT_SCALE,
        set_scale());
    assign_sprite_scale(find_component(list_entity, "quester_pnj",
        COMPONENT_SPRITE), &scale);
}

static void init_third_sprite_texte(global_data_t global_data,
    entity_t *list_entity)
{
    component_scale_t scale = {0.3, 0.3};

    append_component_to_entity(list_entity, "pnj3_texte",
        COMPONENT_SPRITE, set_sprite());
    assign_sprite(find_component(list_entity, "pnj3_texte", COMPONENT_SPRITE),
        "pnj3_text_sprite", global_data);
    append_component_to_entity(list_entity, "pnj3_texte",
        COMPONENT_POSITION, set_position());
    assign_sprite_position(find_component(list_entity,
        "pnj3_texte", COMPONENT_SPRITE), &(component_position_t){1100, 780});
    append_component_to_entity(list_entity, "pnj3_texte",
        COMPONENT_RECT_DISPLAY, set_rect_display());
    assign_sprite_rect_display(&(component_rect_display_t){0, 0, 225, 101},
        find_component(list_entity, "pnj3_texte", COMPONENT_SPRITE));
    append_component_to_entity(list_entity, "pnj3_texte", COMPONENT_SCALE,
        set_scale());
    assign_sprite_scale(find_component(list_entity, "pnj3_texte",
        COMPONENT_SPRITE), &scale);
}

static void init_second_sprite_texte(global_data_t global_data,
    entity_t *list_entity)
{
    component_scale_t scale = {0.3, 0.3};

    append_component_to_entity(list_entity, "pnj2_texte",
        COMPONENT_SPRITE, set_sprite());
    assign_sprite(find_component(list_entity, "pnj2_texte", COMPONENT_SPRITE),
        "pnj2_text_sprite", global_data);
    append_component_to_entity(list_entity, "pnj2_texte",
        COMPONENT_POSITION, set_position());
    assign_sprite_position(find_component(list_entity,
        "pnj2_texte", COMPONENT_SPRITE), &(component_position_t){360, 680});
    append_component_to_entity(list_entity, "pnj2_texte",
        COMPONENT_RECT_DISPLAY, set_rect_display());
    assign_sprite_rect_display(&(component_rect_display_t){0, 0, 225, 101},
        find_component(list_entity, "pnj2_texte", COMPONENT_SPRITE));
    append_component_to_entity(list_entity, "pnj2_texte", COMPONENT_SCALE,
        set_scale());
    assign_sprite_scale(find_component(list_entity, "pnj2_texte",
        COMPONENT_SPRITE), &scale);
}

static void init_first_pnj_texte(global_data_t global_data,
    entity_t *list_entity)
{
    component_scale_t scale = {0.3, 0.3};

    append_component_to_entity(list_entity, "pnj_texte",
        COMPONENT_SPRITE, set_sprite());
    assign_sprite(find_component(list_entity, "pnj_texte", COMPONENT_SPRITE),
        "pnj_text_sprite", global_data);
    append_component_to_entity(list_entity, "pnj_texte",
        COMPONENT_POSITION, set_position());
    assign_sprite_position(find_component(list_entity,
        "pnj_texte", COMPONENT_SPRITE), &(component_position_t){780, 660});
    append_component_to_entity(list_entity, "pnj_texte",
        COMPONENT_RECT_DISPLAY, set_rect_display());
    assign_sprite_rect_display(&(component_rect_display_t){0, 0, 225, 101},
        find_component(list_entity, "pnj_texte", COMPONENT_SPRITE));
    append_component_to_entity(list_entity, "pnj_texte", COMPONENT_SCALE,
        set_scale());
    assign_sprite_scale(find_component(list_entity, "pnj_texte",
        COMPONENT_SPRITE), &scale);
}

void init_pnj(global_data_t global_data, entity_t *entity)
{
    init_quest_pnj(global_data, entity);
    init_first_pnj(global_data, entity);
    init_second_sprite(global_data, entity);
    init_third_sprite(global_data, entity);
    init_first_pnj_texte(global_data, entity);
    init_second_sprite_texte(global_data, entity);
    init_third_sprite_texte(global_data, entity);
}
