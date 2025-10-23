/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-myrpg-guillaume1.blondel
** File description:
** system_clock.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../ecs_components.h"

component_frame_t *set_clock(void)
{
    component_frame_t *frame = NULL;

    frame = malloc(sizeof(component_frame_t));
    if (frame == NULL) {
        exit(84);
    }
    memset(frame, 0, sizeof(component_frame_t));
    return frame;
}

void increment_clock_time(component_frame_t *frame, sfClock *clock_process)
{
    sfTime tmp_frame_time = {0};

    if (frame == NULL) {
        dprintf(2, "Error: frame component probably don't assigned\n");
        return;
    }
    if (clock_process == NULL) {
        dprintf(2, "Error: clock_process probably not init\n");
    }
    tmp_frame_time = sfClock_getElapsedTime(clock_process);
    frame->frame_time.microseconds += tmp_frame_time.microseconds;
}

bool check_time(component_frame_t *frame, float time,
    enum time_comparison_s comp)
{
    float time_seconds = 0.f;

    if (frame == NULL) {
        return false;
    }
    time_seconds = sfTime_asSeconds(frame->frame_time);
    if (comp == INFERIOR) {
        if (time_seconds < time) {
            return true;
        }
    } else {
        if (time_seconds > time) {
            return true;
        }
    }
    return false;
}

void restart_time(component_frame_t *frame)
{
    if (frame == NULL) {
        return;
    }
    memset(&frame->frame_time, 0, sizeof(sfTime));
}
