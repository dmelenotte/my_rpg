/*
** EPITECH PROJECT, 2023
** B-MUL-200-TLS-2-1-myrpg-guillaume1.blondel
** File description:
** quest.c
*/

#include "../include/rpg.h"

static void init_chapter4(global_data_t global_data,
    entity_t *list_entity, rpg_t *rpg)
{
    component_scale_t scale = {0.3, 0.3};

    append_component_to_entity(list_entity, "chapter4_text",
        COMPONENT_SPRITE, set_sprite());
    assign_sprite(find_component(list_entity, "chapter4_text",
        COMPONENT_SPRITE),
        "chapter4_sprite", global_data);
    append_component_to_entity(list_entity, "chapter4_text",
        COMPONENT_POSITION, set_position());
    assign_sprite_position(find_component(list_entity,
        "chapter4_text", COMPONENT_SPRITE), &(component_position_t){850, 920});
    append_component_to_entity(list_entity, "chapter4_text",
        COMPONENT_RECT_DISPLAY, set_rect_display());
    assign_sprite_rect_display(&(component_rect_display_t){0, 0, 940, 234},
        find_component(list_entity, "chapter4_text", COMPONENT_SPRITE));
    append_component_to_entity(list_entity, "chapter4_text", COMPONENT_SCALE,
        set_scale());
    assign_sprite_scale(find_component(list_entity, "chapter4_text",
        COMPONENT_SPRITE), &scale);
    rpg->current_quest = 0;
}

static void init_chapter3(global_data_t global_data,
    entity_t *list_entity, rpg_t *rpg)
{
    component_scale_t scale = {0.3, 0.3};

    append_component_to_entity(list_entity, "chapter3_text",
        COMPONENT_SPRITE, set_sprite());
    assign_sprite(find_component(list_entity, "chapter3_text",
        COMPONENT_SPRITE),
        "chapter3_sprite", global_data);
    append_component_to_entity(list_entity, "chapter3_text",
        COMPONENT_POSITION, set_position());
    assign_sprite_position(find_component(list_entity,
        "chapter3_text", COMPONENT_SPRITE), &(component_position_t){850, 920});
    append_component_to_entity(list_entity, "chapter3_text",
        COMPONENT_RECT_DISPLAY, set_rect_display());
    assign_sprite_rect_display(&(component_rect_display_t){0, 0, 940, 234},
        find_component(list_entity, "chapter3_text", COMPONENT_SPRITE));
    append_component_to_entity(list_entity, "chapter3_text", COMPONENT_SCALE,
        set_scale());
    assign_sprite_scale(find_component(list_entity, "chapter3_text",
        COMPONENT_SPRITE), &scale);
    init_chapter4(global_data, list_entity, rpg);
}

static void init_chapter2(global_data_t global_data,
    entity_t *list_entity, rpg_t *rpg)
{
    component_scale_t scale = {0.3, 0.3};

    append_component_to_entity(list_entity, "chapter2_text",
        COMPONENT_SPRITE, set_sprite());
    assign_sprite(find_component(list_entity, "chapter2_text",
        COMPONENT_SPRITE),
        "chapter2_sprite", global_data);
    append_component_to_entity(list_entity, "chapter2_text",
        COMPONENT_POSITION, set_position());
    assign_sprite_position(find_component(list_entity,
        "chapter2_text", COMPONENT_SPRITE), &(component_position_t){850, 920});
    append_component_to_entity(list_entity, "chapter2_text",
        COMPONENT_RECT_DISPLAY, set_rect_display());
    assign_sprite_rect_display(&(component_rect_display_t){0, 0, 935, 272},
        find_component(list_entity, "chapter2_text", COMPONENT_SPRITE));
    append_component_to_entity(list_entity, "chapter2_text", COMPONENT_SCALE,
        set_scale());
    assign_sprite_scale(find_component(list_entity, "chapter2_text",
        COMPONENT_SPRITE), &scale);
    init_chapter3(global_data, list_entity, rpg);
}

void init_quest_text(global_data_t global_data,
    entity_t *list_entity, rpg_t *rpg)
{
    component_scale_t scale = {0.3, 0.3};

    append_component_to_entity(list_entity, "chapter1_text",
        COMPONENT_SPRITE, set_sprite());
    assign_sprite(find_component(list_entity, "chapter1_text",
        COMPONENT_SPRITE),
        "chapter1_sprite", global_data);
    append_component_to_entity(list_entity, "chapter1_text",
        COMPONENT_POSITION, set_position());
    assign_sprite_position(find_component(list_entity,
        "chapter1_text", COMPONENT_SPRITE), &(component_position_t){850, 920});
    append_component_to_entity(list_entity, "chapter1_text",
        COMPONENT_RECT_DISPLAY, set_rect_display());
    assign_sprite_rect_display(&(component_rect_display_t){0, 0, 954, 253},
        find_component(list_entity, "chapter1_text", COMPONENT_SPRITE));
    append_component_to_entity(list_entity, "chapter1_text", COMPONENT_SCALE,
        set_scale());
    assign_sprite_scale(find_component(list_entity, "chapter1_text",
        COMPONENT_SPRITE), &scale);
    init_chapter2(global_data, list_entity, rpg);
}
