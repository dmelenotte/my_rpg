/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-myrpg-guillaume1.blondel
** File description:
** load_map
*/

#include "../include/rpg.h"

static void which_map(rpg_t *rpg, global_data_t global_data,
    entity_t *list_entity, map_t *maps)
{
    if (maps->current_map == 0) {
        display_sprite((component_sprite_t *)find_component(list_entity,
        "world_map", COMPONENT_SPRITE), rpg->window);
    }
    if (maps->current_map == 1) {
        display_sprite((component_sprite_t *)find_component(list_entity,
        "ice_cave", COMPONENT_SPRITE), rpg->window);
    }
    if (maps->current_map == 2) {
        display_sprite((component_sprite_t *)find_component(list_entity,
        "town", COMPONENT_SPRITE), rpg->window);
    }
    if (maps->current_map == 3) {
        display_sprite((component_sprite_t *)find_component(list_entity,
        "boss_map", COMPONENT_SPRITE), rpg->window);
    }
}

static void show_pnj_texte(rpg_t *rpg, global_data_t global_data,
    entity_t *list_entity, map_t *maps)
{
    if (rpg->main_character->position.x - 360 > -100 &&
        rpg->main_character->position.x - 360 < 100 &&
        rpg->main_character->position.y - 680 > -100 &&
        rpg->main_character->position.y - 680 < 100) {
        display_sprite((component_sprite_t *) find_component(list_entity,
        "pnj2_texte", COMPONENT_SPRITE), rpg->window);
    }
    if (rpg->main_character->position.x - 1100 > -100 &&
        rpg->main_character->position.x - 1100 < 100 &&
        rpg->main_character->position.y - 780 > -100 &&
        rpg->main_character->position.y - 780 < 100) {
        display_sprite((component_sprite_t *) find_component(list_entity,
        "pnj3_texte", COMPONENT_SPRITE), rpg->window);
    }
}

static void show_pnj(rpg_t *rpg, global_data_t global_data,
    entity_t *list_entity, map_t *maps)
{
    if (maps->current_map == 2) {
        display_sprite((component_sprite_t *)find_component(list_entity,
        "pnj", COMPONENT_SPRITE), rpg->window);
        display_sprite((component_sprite_t *)find_component(list_entity,
        "pnj2", COMPONENT_SPRITE), rpg->window);
        display_sprite((component_sprite_t *)find_component(list_entity,
        "pnj3", COMPONENT_SPRITE), rpg->window);
        show_pnj_texte(rpg, global_data, list_entity, maps);
        if (rpg->main_character->position.x - 780 > -100 &&
            rpg->main_character->position.x - 780 < 100 &&
            rpg->main_character->position.y - 680 > -100 &&
            rpg->main_character->position.y - 680 < 100) {
            display_sprite((component_sprite_t *) find_component(list_entity,
            "pnj_texte", COMPONENT_SPRITE), rpg->window);
        }
    } else if (maps->current_map == 0) {
        display_sprite((component_sprite_t *) find_component(list_entity,
        "quester_pnj", COMPONENT_SPRITE), rpg->window);
        talk_pnj(rpg, list_entity, maps);
    }
}

void music_create(rpg_t *rpg, char *str)
{
    rpg->main_music = sfMusic_createFromFile(str);
    sfMusic_setLoop(rpg->main_music, sfTrue);
    sfMusic_play(rpg->main_music);
}

static void wich_music(rpg_t *rpg, global_data_t global_data,
    entity_t *list_entity, map_t *maps)
{
    if (maps->current_map == 2) {
        if (maps->current_map != maps->previus_map) {
            sfMusic_destroy(rpg->main_music);
            music_create(rpg, "assets/music/music.ogg");
        }
        maps->previus_map = 2;
    }
    if (maps->current_map == 3) {
        if (maps->current_map != maps->previus_map) {
            sfMusic_destroy(rpg->main_music);
            music_create(rpg, "assets/music/music_boss.ogg");
        }
        maps->previus_map = 3;
    }
}

void play_music(rpg_t *rpg, global_data_t global_data, entity_t *list_entity,
    map_t *maps)
{
    if (maps->current_map == 0) {
        if (maps->current_map != maps->previus_map) {
            sfMusic_destroy(rpg->main_music);
            music_create(rpg, "assets/music/music.ogg");
        }
        maps->previus_map = 0;
    }
    if (maps->current_map == 1) {
        if (maps->current_map != maps->previus_map) {
            sfMusic_destroy(rpg->main_music);
            music_create(rpg, "assets/music/music.ogg");
        }
        maps->previus_map = 1;
    }
    wich_music(rpg, global_data, list_entity, maps);
}

void load_main_caracter(rpg_t *rpg, global_data_t global_data,
    entity_t *list_entity, map_t *maps)
{
    display_sprite((component_sprite_t *) find_component(list_entity,
        "sword", COMPONENT_SPRITE), rpg->window);
    if (rpg->inventory->is_open == 0)
        display_sprite((component_sprite_t *) find_component(list_entity,
        "mc", COMPONENT_SPRITE), rpg->window);
    if (rpg->inventory->is_open == 0 && rpg->main_character->side == 0)
        return_sword(rpg, list_entity, global_data);
    else if (rpg->inventory->is_open == 0 && rpg->main_character->side == 1)
        return_left_sword(rpg, list_entity, global_data);
}

void active_sprite(rpg_t *rpg, global_data_t global_data,
    entity_t *list_entity, map_t *maps)
{
    if (check_active(find_component(list_entity, "ball_attack",
        COMPONENT_STATE))) {
        display_sprite(find_component(list_entity,
            "ball_attack", COMPONENT_SPRITE), rpg->window);
    }
    if (check_active(find_component(list_entity, "boss",
        COMPONENT_STATE))) {
        display_sprite(find_component(list_entity,
            "boss", COMPONENT_SPRITE), rpg->window);
    }
    if (check_display(find_component(list_entity, "hit", COMPONENT_STATE))) {
        display_sprite(find_component(list_entity,
            "hit", COMPONENT_SPRITE), rpg->window);
    }
}

void load_map(rpg_t *rpg, global_data_t global_data, entity_t *list_entity,
    map_t *maps)
{
    sfRenderWindow_setView(rpg->window, rpg->view);
    which_map(rpg, global_data, list_entity, maps);
    show_pnj(rpg, global_data, list_entity, maps);
    display_sprite((component_sprite_t *) find_component(list_entity,
        "boat", COMPONENT_SPRITE), rpg->window);
    for (int i = 0; name[i] != NULL; i++) {
        if (check_active(find_component(list_entity, (char *)name[i],
            COMPONENT_STATE))) {
            display_sprite(find_component(list_entity,
                (char *)name[i], COMPONENT_SPRITE), rpg->window);
        }
    }
    active_sprite(rpg, global_data, list_entity, maps);
    inventory(rpg, list_entity, global_data);
    load_main_caracter(rpg, global_data, list_entity, maps);
}
