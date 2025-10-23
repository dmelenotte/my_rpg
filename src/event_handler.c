/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-myrpg-guillaume1.blondel
** File description:
** event_handler
*/

#include "../include/rpg.h"

void handle_key_event(rpg_t *rpg, entity_t *list_entity)
{
    if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue &&
        rpg->pause_menu->is_paused == 0 && rpg->inventory->is_open == 0) {
        rpg->pause_menu->is_paused = 1;
        sfClock_restart(rpg->pause_menu->clock);
    }
    if (sfKeyboard_isKeyPressed(sfKeyI) == sfTrue &&
        rpg->inventory->is_open == 0 && rpg->pause_menu->is_paused == 0) {
        rpg->inventory->is_open = 1;
        sfClock_restart(rpg->inventory->clock);
    }
}

void window_event_handler(rpg_t *rpg, entity_t *list_entity, global_data_t
    global_data)
{
    sfVector2i pixel_pos = sfMouse_getPositionRenderWindow(rpg->window);
    sfVector2f world_pos = sfRenderWindow_mapPixelToCoords(rpg->window,
    pixel_pos, sfRenderWindow_getView(rpg->window));

    if (rpg->event.type == sfEvtClosed)
        sfRenderWindow_close(rpg->window);
    handle_key_event(rpg, list_entity);
    if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue &&
    rpg->pause_menu->is_paused == 1) {
        if (sfFloatRect_contains(find_component(list_entity,
        "pause_play", COMPONENT_BOX), world_pos.x, world_pos.y))
            rpg->pause_menu->is_paused = 0;
        if (sfFloatRect_contains(find_component(list_entity,
        "pause_exit", COMPONENT_BOX), world_pos.x, world_pos.y))
                sfRenderWindow_close(rpg->window);
    }
}

int main_menu_event_handler(rpg_t *rpg, entity_t *list_entity,
    global_data_t global_data)
{
    if (rpg->event.type == sfEvtClosed)
        sfRenderWindow_close(rpg->window);
    if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
        sfRenderWindow_close(rpg->window);
}

int check_close(rpg_t *rpg, entity_t *list_entity, global_data_t global_data)
{
    if (rpg->main_menu->play_released) {
        rpg->main_menu->play_released = false;
        return 1;
    }
    if (rpg->main_menu->exit_released) {
        rpg->main_menu->exit_released = false;
        sfRenderWindow_close(rpg->window);
        return 0;
    }
    return 0;
}
