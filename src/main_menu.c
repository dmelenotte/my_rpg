/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-myrpg-guillaume1.blondel
** File description:
** main_menu
*/

#include "../include/rpg.h"

static void init_play_button(global_data_t global_data, entity_t *list_entity)
{
    append_component_to_entity(list_entity, "play_button",
        COMPONENT_SPRITE, set_sprite());
    assign_sprite(find_component(list_entity, "play_button",
        COMPONENT_SPRITE), "play_sprite", global_data);
    append_component_to_entity(list_entity, "play_button",
        COMPONENT_POSITION, set_position());
    assign_sprite_position(find_component(list_entity,
        "play_button", COMPONENT_SPRITE), &(component_position_t){846, 700});
    append_component_to_entity(list_entity, "play_button",
        COMPONENT_BOX, set_box());
    assign_sprite_box(find_component(list_entity,
        "play_button", COMPONENT_BOX),
        find_component(list_entity, "play_button", COMPONENT_SPRITE));
    append_component_to_entity(list_entity, "play_button",
        COMPONENT_SCALE, set_scale());
    assign_scale(find_component(list_entity, "play_button",
        COMPONENT_SCALE), 0.6, 0.6);
    assign_sprite_scale(find_component(list_entity, "play_button",
        COMPONENT_SPRITE), find_component(list_entity, "play_button",
        COMPONENT_SCALE));
}

static void init_exit_button(global_data_t global_data, entity_t *list_entity)
{
    append_component_to_entity(list_entity, "exit_button",
        COMPONENT_SPRITE, set_sprite());
    assign_sprite(find_component(list_entity, "exit_button",
        COMPONENT_SPRITE), "exit_sprite", global_data);
    append_component_to_entity(list_entity, "exit_button",
        COMPONENT_POSITION, set_position());
    assign_sprite_position(find_component(list_entity,
        "exit_button", COMPONENT_SPRITE), &(component_position_t){860, 850});
    append_component_to_entity(list_entity, "exit_button",
        COMPONENT_BOX, set_box());
    assign_sprite_box(find_component(list_entity,
        "exit_button", COMPONENT_BOX),
        find_component(list_entity, "exit_button", COMPONENT_SPRITE));
    append_component_to_entity(list_entity, "exit_button",
        COMPONENT_SCALE, set_scale());
    assign_scale(find_component(list_entity, "exit_button",
        COMPONENT_SCALE), 0.6, 0.6);
    assign_sprite_scale(find_component(list_entity, "exit_button",
        COMPONENT_SPRITE), find_component(list_entity, "exit_button",
        COMPONENT_SCALE));
}

static void init_main_menu(global_data_t global_data, entity_t *list_entity,
    rpg_t *rpg)
{
    append_component_to_entity(list_entity, "main_menu",
        COMPONENT_SPRITE, set_sprite());
    assign_sprite(find_component(list_entity, "main_menu",
        COMPONENT_SPRITE), "main_menu_sprite", global_data);
    append_component_to_entity(list_entity, "main_menu",
        COMPONENT_POSITION, set_position());
    assign_sprite_position(find_component(list_entity,
        "main_menu", COMPONENT_SPRITE), &(component_position_t){0, -20});
    append_component_to_entity(list_entity, "main_menu",
        COMPONENT_SCALE, set_scale());
    assign_scale(find_component(list_entity, "main_menu",
        COMPONENT_SCALE), 0.626, 0.56);
    assign_sprite_scale(find_component(list_entity, "main_menu",
        COMPONENT_SPRITE), find_component(list_entity, "main_menu",
        COMPONENT_SCALE));
    rpg->main_menu->play_pressed = false;
    rpg->main_menu->exit_pressed = false;
    rpg->main_menu->play_released = false;
    rpg->main_menu->exit_released = false;
}

void init_title(rpg_t *rpg, global_data_t global_data, entity_t *list_entity)
{
    rpg->main_menu->text = sfText_create();
    rpg->main_menu->font = sfFont_createFromFile(
        "assets/AlexBrush-Regular.ttf");
    sfText_setString(rpg->main_menu->text, "Alexis' Quest");
    sfText_setFont(rpg->main_menu->text, rpg->main_menu->font);
    sfText_setCharacterSize(rpg->main_menu->text, 175);
    sfText_setStyle(rpg->main_menu->text, sfTextBold);
    sfText_setColor(rpg->main_menu->text, sfBlack);
    sfText_setPosition(rpg->main_menu->text, (sfVector2f){523, 200});
}

static int is_hover_second(rpg_t *rpg, entity_t *list_entity)
{
    if (sfFloatRect_contains(find_component(list_entity, "exit_button",
        COMPONENT_BOX), sfMouse_getPositionRenderWindow(rpg->window).x,
        sfMouse_getPositionRenderWindow(rpg->window).y)) {
        assign_sprite_scale(find_component(list_entity, "exit_button",
            COMPONENT_SPRITE), &(component_scale_t){0.7, 0.7});
        assign_sprite_position(find_component(list_entity, "exit_button",
            COMPONENT_SPRITE), &(component_position_t){843, 840});
    } else {
        assign_sprite_scale(find_component(list_entity, "exit_button",
            COMPONENT_SPRITE), &(component_scale_t){0.6, 0.6});
        assign_sprite_position(find_component(list_entity,
            "exit_button", COMPONENT_SPRITE),
            &(component_position_t){860, 850});
    }
}

int is_hover_first(rpg_t *rpg, entity_t *list_entity)
{
    if (sfFloatRect_contains(find_component(list_entity, "play_button",
    COMPONENT_BOX), sfMouse_getPositionRenderWindow(rpg->window).x,
    sfMouse_getPositionRenderWindow(rpg->window).y)) {
        assign_sprite_scale(find_component(list_entity, "play_button",
        COMPONENT_SPRITE), &(component_scale_t){0.7, 0.7});
        assign_sprite_position(find_component(list_entity, "play_button",
        COMPONENT_SPRITE), &(component_position_t){830, 695});
    } else {
        assign_sprite_scale(find_component(list_entity, "play_button",
        COMPONENT_SPRITE), &(component_scale_t){0.6, 0.6});
        assign_sprite_position(find_component(list_entity,
        "play_button", COMPONENT_SPRITE), &(component_position_t){846, 700});
    }
    is_hover_second(rpg, list_entity);
}

void is_pressed(rpg_t *rpg, entity_t *list_entity, global_data_t global_data)
{
    assign_sprite(find_component(list_entity, "play_button",
        COMPONENT_SPRITE), "play_sprite", global_data);
    assign_sprite(find_component(list_entity, "exit_button",
        COMPONENT_SPRITE), "exit_sprite", global_data);
    if (rpg->main_menu->play_pressed == true)
        assign_sprite(find_component(list_entity, "play_button",
        COMPONENT_SPRITE), "play_pressed_sprite", global_data);
    if (rpg->main_menu->exit_pressed == true)
        assign_sprite(find_component(list_entity, "exit_button",
        COMPONENT_SPRITE), "exit_pressed_sprite", global_data);
}

static void state_changing(rpg_t *rpg, entity_t *list_entity,
    global_data_t global_data)
{
    if (sfFloatRect_contains(find_component(list_entity, "play_button",
        COMPONENT_BOX), sfMouse_getPositionRenderWindow(rpg->window).x,
        sfMouse_getPositionRenderWindow(rpg->window).y)) {
        rpg->main_menu->play_pressed = true;
        rpg->main_menu->play_released = false;
    }
    if (sfFloatRect_contains(find_component(list_entity, "exit_button",
        COMPONENT_BOX), sfMouse_getPositionRenderWindow(rpg->window).x,
        sfMouse_getPositionRenderWindow(rpg->window).y)) {
        rpg->main_menu->exit_pressed = true;
        rpg->main_menu->exit_released = false;
    }
}

static void handle_clicks(rpg_t *rpg, entity_t *list_entity,
    global_data_t global_data)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
        state_changing(rpg, list_entity, global_data);
    } else {
        if (rpg->main_menu->play_pressed)
            rpg->main_menu->play_released = true;
        if (rpg->main_menu->exit_pressed)
            rpg->main_menu->exit_released = true;
        rpg->main_menu->play_pressed = false;
        rpg->main_menu->exit_pressed = false;
    }
    is_pressed(rpg, list_entity, global_data);
    is_hover_first(rpg, list_entity);
    display_sprite((component_sprite_t *) find_component(list_entity,
        "main_menu", COMPONENT_SPRITE), rpg->window);
}

void main_menu(rpg_t *rpg, entity_t *list_entity, global_data_t global_data)
{
    init_main_menu(global_data, list_entity, rpg);
    init_play_button(global_data, list_entity);
    init_exit_button(global_data, list_entity);
    init_title(rpg, global_data, list_entity);
    while (sfRenderWindow_isOpen(rpg->window)) {
        while (sfRenderWindow_pollEvent(rpg->window, &rpg->event)){
            window_event_handler(rpg, list_entity, global_data);
        }
        if (check_close(rpg, list_entity, global_data) == 1)
            return;
        sfRenderWindow_clear(rpg->window, sfBlack);
        handle_clicks(rpg, list_entity, global_data);
        display_sprite((component_sprite_t *) find_component(list_entity,
            "play_button", COMPONENT_SPRITE), rpg->window);
        display_sprite((component_sprite_t *) find_component(list_entity,
            "exit_button", COMPONENT_SPRITE), rpg->window);
        sfRenderWindow_drawText(rpg->window, rpg->main_menu->text, NULL);
        sfRenderWindow_display(rpg->window);
    }
}
