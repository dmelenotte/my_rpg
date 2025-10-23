/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-myrpg-guillaume1.blondel
** File description:
** system_rect_display.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../ecs_components.h"

component_rect_display_t *set_rect_display(void)
{
    component_rect_display_t *rect_display = NULL;

    rect_display = malloc(sizeof(component_rect_display_t));
    if (rect_display == NULL) {
        exit(84);
    }
    memset(rect_display, 0, sizeof(component_rect_display_t));
    return rect_display;
}

void change_rect_display_values(component_rect_display_t *rect_display,
    sfFloatRect rect, enum operation_s operation)
{
    if (rect_display == NULL) {
        return;
    }
    if (operation == ADD) {
        rect_display->rect.height += rect.height;
        rect_display->rect.left += rect.left;
        rect_display->rect.top += rect.top;
        rect_display->rect.width += rect.width;
    }
    if (operation == ASSIGN) {
        rect_display->rect.height = rect.height;
        rect_display->rect.left = rect.left;
        rect_display->rect.top = rect.top;
        rect_display->rect.width = rect.width;
    }
}

void assign_sprite_rect_display(component_rect_display_t *rect_display,
    component_sprite_t *sprite)
{
    if (rect_display != NULL && sprite != NULL) {
        if (sprite->sprite == NULL) {
            dprintf(2, "Error: sfSprite not assigned\n");
            return;
        }
        sfSprite_setTextureRect(sprite->sprite, rect_display->rect);
    } else {
        dprintf(2, "Error: rect_display / sprite "
            "component probably don't assigned\n");
    }
}
