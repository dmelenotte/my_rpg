/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-myrpg-guillaume1.blondel
** File description:
** handle_clock.c
*/

#include "../include/rpg.h"

void handle_clock(rpg_t *rpg, entity_t *list_entity)
{
    increment_clock_time(find_component(list_entity, "sword", COMPONENT_FRAME),
        rpg->clocks->general_clock);
    increment_clock_time(find_component(list_entity, "boat", COMPONENT_FRAME),
        rpg->clocks->general_clock);
    increment_clock_time(find_component(list_entity, "quester_pnj",
        COMPONENT_FRAME),
        rpg->clocks->general_clock);
    for (int i = 0; name[i] != NULL; i++) {
        increment_clock_time(find_component(list_entity, (char *)name[i],
            COMPONENT_FRAME), rpg->clocks->general_clock);
    }
    increment_clock_time(find_component(list_entity, "mc",
        COMPONENT_FRAME), rpg->clocks->general_clock);
    increment_clock_time(find_component(list_entity, "boss",
        COMPONENT_FRAME), rpg->clocks->general_clock);
    increment_clock_time(find_component(list_entity, "ball_attack",
        COMPONENT_FRAME), rpg->clocks->general_clock);
    sfClock_restart(rpg->clocks->general_clock);
}
