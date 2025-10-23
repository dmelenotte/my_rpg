/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-myrpg-guillaume1.blondel
** File description:
** main.c
*/

#include "../include/rpg.h"
#include <time.h>

static void free_rpg(rpg_t *rpg)
{
    sfClock_destroy(rpg->clocks->clock);
    sfClock_destroy(rpg->clocks->clock_anim);
    free(rpg->clocks);
    free(rpg->main_character->rect[DOWN]);
    free(rpg->main_character->rect[UP]);
    free(rpg->main_character->rect[RIGHT]);
    free(rpg->main_character->rect[LEFT]);
    free(rpg->main_character->rect);
    free(rpg->main_character);
    sfRectangleShape_destroy(rpg->pause_menu->rect);
    sfClock_destroy(rpg->pause_menu->clock);
    free(rpg->pause_menu);
    sfView_destroy(rpg->view);
    sfRenderWindow_destroy(rpg->window);
    free(rpg);
}

static void free_all(rpg_t *rpg, global_data_t global_data,
    entity_t *list_entity, map_t *maps)
{
    free_rpg(rpg);
    free(maps->world);
    free(maps->demon_castle);
    free(maps->ice_cave);
    free(maps->town);
    free(maps);
    free(list_entity->components);
    free(list_entity->next);
    free(list_entity);
}

static void initialisation(global_data_t *global_data, entity_t *list_entity,
    rpg_t *rpg, map_t *maps)
{
    while (sfRenderWindow_isOpen(rpg->window)) {
        while (sfRenderWindow_pollEvent(rpg->window, &rpg->event))
            window_event_handler(rpg, list_entity, *global_data);
        play_music(rpg, *global_data, list_entity, maps);
        if (rpg->fast_travel == true)
            fast_travel(rpg, list_entity, maps);
        mouvement(rpg, list_entity, maps);
        if (rpg->inventory->is_open == 0)
            sword_attack(rpg, list_entity);
        sfRenderWindow_clear(rpg->window, sfBlack);
        handle_enemies(rpg, maps, list_entity);
        load_map(rpg, *global_data, list_entity, maps);
        pause_menu(rpg, list_entity, *global_data);
        talk_pnj(rpg, list_entity, maps);
        mc_heart(rpg, *global_data, list_entity, maps);
        sfRenderWindow_display(rpg->window);
        handle_clock(rpg, list_entity);
    }
}

static entity_t *loading_second(global_data_t *global_data,
    entity_t *list_entity, rpg_t *rpg, map_t *maps)
{
    list_entity = load_entity(list_entity, "inventory", UI);
    list_entity = load_entity(list_entity, "win", UI);
    list_entity = load_entity(list_entity, "item", UI);
    list_entity = load_entity(list_entity, "heart", UI);
    list_entity = load_entity(list_entity, "empty_heart", UI);
    list_entity = load_entity(list_entity, "game_over", UI);
    list_entity = load_entity(list_entity, "health_potion", UI);
    list_entity = load_entity(list_entity, "hit", PARTICLE);
    list_entity = load_entity(list_entity, "ball_attack", BOSS);
    list_entity = load_entity(list_entity, "boss", BOSS);
    list_entity = load_entity(list_entity, "quester_pnj", NPC);
    maps->previus_map = 0;
    return list_entity;
}

static entity_t *load_ennemy(global_data_t *global_data, entity_t *list_entity,
    rpg_t *rpg, map_t *maps)
{
    for (int i = 0; name[i] != NULL; i++) {
        list_entity = load_entity(list_entity, (char *)name[i], ENEMY);
    }
    list_entity = load_entity(list_entity, "chapter1_text", NPC);
    list_entity = load_entity(list_entity, "chapter2_text", NPC);
    list_entity = load_entity(list_entity, "chapter3_text", NPC);
    list_entity = load_entity(list_entity, "chapter4_text", NPC);
    list_entity = load_entity(list_entity, "pnj", NPC);
    list_entity = load_entity(list_entity, "pnj2", NPC);
    list_entity = load_entity(list_entity, "pnj3", NPC);
    list_entity = load_entity(list_entity, "pnj_texte", NPC);
    list_entity = load_entity(list_entity, "pnj2_texte", NPC);
    list_entity = load_entity(list_entity, "pnj3_texte", NPC);
    list_entity = load_entity(list_entity, "boss_map", MAP);
    list_entity = load_entity(list_entity, "town", MAP);
    list_entity = load_entity(list_entity, "ice_cave", MAP);
    list_entity = load_entity(list_entity, "world_map", MAP);
    return list_entity;
}

static entity_t *loading(global_data_t *global_data, entity_t *list_entity,
    rpg_t *rpg, map_t *maps)
{
    map_reading(maps);
    city_reading(maps);
    cave_reading(maps);
    boss_reading(maps);
    list_entity = loading_second(global_data, list_entity, rpg, maps);
    list_entity = load_entity(list_entity, "mc", PLAYER);
    list_entity = load_entity(list_entity, "sword", PLAYER);
    list_entity = load_entity(list_entity, "play_button", UI);
    list_entity = load_entity(list_entity, "exit_button", UI);
    list_entity = load_entity(list_entity, "main_menu", UI);
    list_entity = load_entity(list_entity, "pause_play", UI);
    list_entity = load_entity(list_entity, "pause_exit", UI);
    list_entity = load_entity(list_entity, "boat", OBJECT);
    list_entity = load_ennemy(global_data, list_entity, rpg, maps);
    read_config(global_data, textures, sprites);
    init_all(rpg, *global_data, list_entity);
    main_menu(rpg, list_entity, *global_data);
    return list_entity;
}

void free_main_menu(rpg_t *rpg)
{
    sfText_destroy(rpg->main_menu->text);
    sfFont_destroy(rpg->main_menu->font);
    free(rpg->main_menu);
}

static void loadinge(global_data_t *global_data, entity_t *list_entity,
    rpg_t *rpg, map_t *maps)
{
    init_enemies(*global_data, list_entity);
    init_particle(list_entity, *global_data);
    init_game_over(rpg, *global_data, list_entity);
    init_enemies(*global_data, list_entity);
    init_particle(list_entity, *global_data);
    init_boss_enemy(list_entity, *global_data);
    init_quest_text(*global_data, list_entity, rpg);
    init_lives(rpg, *global_data, list_entity);
    init_win_screen(rpg, *global_data, list_entity);
    initialisation(global_data, list_entity, rpg, maps);
}

int main(void)
{
    entity_t *list_entity = NULL;
    rpg_t *rpg = malloc(sizeof(rpg_t));
    map_t *maps = malloc(sizeof(map_t));
    global_data_t global_data = init_global_data();

    srand(time(NULL));
    list_entity = loading(&global_data, list_entity, rpg, maps);
    free_main_menu(rpg);
    display_loading_screen(rpg);
    sfView_setCenter(rpg->view, (sfVector2f){1050, 1240});
    init_pause_background(rpg, global_data, list_entity);
    init_pause_play(rpg, global_data, list_entity);
    init_pause_exit(rpg, global_data, list_entity);
    music_create(rpg, "assets/music/music.ogg");
    loadinge(&global_data, list_entity, rpg, maps);
    destroy_global_data(&global_data);
    free_all(rpg, global_data, list_entity, maps);
    return 0;
}
