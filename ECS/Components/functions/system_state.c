/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-myrpg-guillaume1.blondel
** File description:
** system_state.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include "../ecs_components.h"

component_state_t *set_state(void)
{
    component_state_t *state = NULL;

    state = malloc(sizeof(component_state_t));
    if (state == NULL) {
        exit(84);
    }
    memset(state, 0, sizeof(component_state_t));
    return state;
}

void change_state(component_state_t *state, int setting, ...)
{
    va_list args = {0};

    va_start(args, setting);
    if (setting & SET_ACTIVE) {
        state->state_active = va_arg(args, int);
    }
    if (setting & SET_DISPLAY) {
        state->state_display = va_arg(args, int);
    }
    va_end(args);
}

bool check_active(component_state_t *state)
{
    if (state->state_active == true) {
        return true;
    }
    return false;
}

bool check_display(component_state_t *state)
{
    if (state->state_display == true) {
        return true;
    }
    return false;
}
