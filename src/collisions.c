/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-myrpg-guillaume1.blondel
** File description:
** collisions.c
*/

#include "../include/rpg.h"

#include <math.h>

int is_d_possible(rpg_t *rpg, entity_t *list_entity, map_t *maps)
{
    int test = 0;

    if (maps->current_map == 0) {
        test += mouve_wd(rpg, list_entity, maps);
    }
    if (maps->current_map == 1) {
        test += mouve_cad(rpg, list_entity, maps);
    }
    if (maps->current_map == 2) {
        test += mouve_cd(rpg, list_entity, maps);
    }
    if (maps->current_map == 3) {
        test += mouve_bd(rpg, list_entity, maps);
    }
    return test;
}

int is_u_possible(rpg_t *rpg, entity_t *list_entity, map_t *maps)
{
    int test = 0;

    if (maps->current_map == 0) {
        test += mouve_wu(rpg, list_entity, maps);
    }
    if (maps->current_map == 1) {
        test += mouve_cau(rpg, list_entity, maps);
    }
    if (maps->current_map == 2) {
        test += mouve_cu(rpg, list_entity, maps);
    }
    if (maps->current_map == 3) {
        test += mouve_bu(rpg, list_entity, maps);
    }
    return test;
}

int is_l_possible(rpg_t *rpg, entity_t *list_entity, map_t *maps)
{
    int test = 0;

    if (maps->current_map == 0) {
        test += mouve_wl(rpg, list_entity, maps);
    }
    if (maps->current_map == 1) {
        test += mouve_cal(rpg, list_entity, maps);
    }
    if (maps->current_map == 2) {
        test += mouve_cl(rpg, list_entity, maps);
    }
    if (maps->current_map == 3) {
        test += mouve_bl(rpg, list_entity, maps);
    }
    return test;
}

int is_r_possible(rpg_t *rpg, entity_t *list_entity, map_t *maps)
{
    int test = 0;

    if (maps->current_map == 0) {
        test += mouve_wr(rpg, list_entity, maps);
    }
    if (maps->current_map == 1) {
        test += mouve_car(rpg, list_entity, maps);
    }
    if (maps->current_map == 2) {
        test += mouve_cr(rpg, list_entity, maps);
    }
    if (maps->current_map == 3) {
        test += mouve_br(rpg, list_entity, maps);
    }
    return test;
}

float compute_distance(component_position_t *pos1, sfVector2f pos2)
{
    float distance = 0;

    distance = sqrt(pow(pos1->x - pos2.x, 2) +
        pow(pos1->y - pos2.y, 2));
    return distance;
}
