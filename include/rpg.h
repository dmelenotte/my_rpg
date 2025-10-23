/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-myrpg-guillaume1.blondel
** File description:
** rpg
*/

#ifndef RPG_H_
    #define RPG_H_
    #include <SFML/Graphics.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include <SFML/Graphics/RenderWindow.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <SFML/Audio.h>
    #include "../ECS/Components/ecs_components.h"
    #include "../ECS/Data/data.h"
    #include "../ECS/ECS_List_Components/ecs_list_components.h"
    #include "../ECS/Entity/ecs_entity.h"

typedef struct loading_screen_s {
    sfVideoMode mode;
    sfText *text;
    sfFont *font;
    sfMusic *music_loading;
    sfRectangleShape *progress_bar;
} loading_screen_t;

typedef struct main_character_s {
    component_position_t position;
    component_position_t sword;
    component_position_t left_sword;
    component_rect_display_t **rect;
    component_rect_display_t *hearts;
    int side;
    int nb_rect;
    int hp;
} main_character_t;

typedef struct clocks_s {
    sfClock *general_clock;
    sfClock *clock;
    sfClock *clock_anim;
} clocks_t;

typedef struct main_menu_s {
    sfText *text;
    sfFont *font;
    bool play_pressed;
    bool exit_pressed;
    bool play_released;
    bool exit_released;
} main_menu_t;

typedef struct pause_menu_s {
    int is_paused;
    sfRectangleShape *rect;
    sfClock *clock;
} pause_menu_t;

typedef struct inventory_s {
    sfRectangleShape *rect;
    sfClock *clock;
    char **items;
    int nb_items;
    int is_open;
} inventory_t;

typedef struct rpg_s {
    sfRenderWindow *window;
    sfEvent event;
    sfVideoMode mode;
    sfMusic *main_music;
    sfView *view;
    clocks_t *clocks;
    loading_screen_t *loading_screen;
    main_character_t *main_character;
    main_menu_t *main_menu;
    pause_menu_t *pause_menu;
    int current_quest;
    inventory_t *inventory;
    bool fast_travel;
} rpg_t;

typedef struct map_s {
    char **world;
    sfVector2f world_size;
    char **ice_cave;
    sfVector2f ice_cave_size;
    char **demon_castle;
    sfVector2f demon_castle_size;
    char **town;
    sfVector2f town_size;
    int current_map;
    int previus_map;
} map_t;

static const config_texture_t textures[] = {
    {"world_map_texture", "assets/world_map.png", false},
    {"boss_map_texture", "assets/Demon Castle 3F.png", false},
    {"town_texture", "assets/Normal Town.png", false},
    {"ice_cave_texture", "assets/ice_cave.png", false},
    {"mc_texture", "assets/walking_mc.png", false},
    {"sword_texture", "assets/mc_sword.png", false},
    {"pnj_quest_texture", "assets/quester_pnj.png", false},
    {"first_pnj_texture", "assets/pnj.png", false},
    {"second_pnj_texture", "assets/pnj2.png", false},
    {"third_pnj_texture", "assets/pnj3.png", false},
    {"chapter1_texture", "assets/chapter1.png", false},
    {"chapter2_texture", "assets/chapter2.png", false},
    {"chapter3_texture", "assets/chapter3.png", false},
    {"chapter4_texture", "assets/chapter4.png", false},
    {"play_texture", "assets/play.png", false},
    {"save_texture", "assets/save.png", false},
    {"load_texture", "assets/load.png", false},
    {"exit_texture", "assets/exit.png", false},
    {"main_menu_texture", "assets/main_menu.jpg", false},
    {"pause_play_texture", "assets/pause_play.png", false},
    {"pause_exit_texture", "assets/pause_exit.png", false},
    {"boat_texture", "assets/Ship_full.png", false},
    {"demon_texture", "assets/enemy1.png", false},
    {"hit_texture", "assets/hit.png", false},
    {"pnj2_text_texture", "assets/pnj2_texte.png", false},
    {"pnj_text_texture", "assets/pnj_text.png", false},
    {"pnj3_text_texture", "assets/pnj3_texte.png", false},
    {"inventory_texture", "assets/inventory.png", false},
    {"heart_texture", "assets/heart.png", false},
    {"empty_heart_texture", "assets/empty_heart.png", false},
    {"gameover_texture", "assets/gameover.jpeg", false},
    {"health_texture", "assets/health_potion.png", false},
    {"play_pressed_texture", "assets/play_pressed.png", false},
    {"exit_pressed_texture", "assets/exit_pressed.png", false},
    {"ball_texture", "assets/ball.png", false},
    {"boss_texture", "assets/boss.png", false},
    {"win_texture", "assets/Win.jpg", false},
    {NULL, NULL, true}
};

static const config_sprite_t sprites[] = {
    {"world_map_sprite", "world_map_texture", false},
    {"boss_map_sprite", "boss_map_texture", false},
    {"ice_cave_sprite", "ice_cave_texture", false},
    {"town_sprite", "town_texture", false},
    {"mc_sprite", "mc_texture", false},
    {"weapon_sprite", "sword_texture", false},
    {"pnj_quest_sprite", "pnj_quest_texture", false},
    {"first_pnj_sprite", "first_pnj_texture", false},
    {"second_pnj_sprite", "second_pnj_texture", false},
    {"third_pnj_sprite", "third_pnj_texture", false},
    {"chapter1_sprite", "chapter1_texture", false},
    {"chapter2_sprite", "chapter2_texture", false},
    {"chapter3_sprite", "chapter3_texture", false},
    {"chapter4_sprite", "chapter4_texture", false},
    {"play_sprite", "play_texture", false},
    {"save_sprite", "save_texture", false},
    {"load_sprite", "load_texture", false},
    {"exit_sprite", "exit_texture", false},
    {"main_menu_sprite", "main_menu_texture", false},
    {"pause_play_sprite", "pause_play_texture", false},
    {"pause_exit_sprite", "pause_exit_texture", false},
    {"boat_sprite", "boat_texture", false},
    {"demon_sprite", "demon_texture", false},
    {"demon_sprite2", "demon_texture", false},
    {"demon_sprite3", "demon_texture", false},
    {"demon_sprite4", "demon_texture", false},
    {"demon_sprite5", "demon_texture", false},
    {"hit_sprite", "hit_texture", false},
    {"pnj2_text_sprite", "pnj2_text_texture", false},
    {"pnj_text_sprite", "pnj_text_texture", false},
    {"pnj3_text_sprite", "pnj3_text_texture", false},
    {"inventory_sprite", "inventory_texture", false},
    {"heart_sprite", "heart_texture", false},
    {"empty_heart_sprite", "empty_heart_texture", false},
    {"gameover_sprite", "gameover_texture", false},
    {"win_sprite", "win_texture", false},
    {"health_potion_sprite", "health_texture", false},
    {"play_pressed_sprite", "play_pressed_texture", false},
    {"exit_pressed_sprite", "exit_pressed_texture", false},
    {"ball_sprite", "ball_texture", false},
    {"boss_sprite", "boss_texture", false},
    {NULL, NULL, true}
};

static const char *name[] = {
    "demon_enemy",
    "demon_enemy2",
    "demon_enemy3",
    "demon_enemy4",
    "demon_enemy5",
    NULL,
};

static const char *sprite_name[] = {
    "demon_sprite",
    "demon_sprite2",
    "demon_sprite3",
    "demon_sprite4",
    "demon_sprite5",
    NULL,
};

    #define DEFAULT -1
    #define UP 0
    #define DOWN 1
    #define LEFT 2
    #define RIGHT 3

void talk_pnj(rpg_t *rpg, entity_t *list_entity, map_t *maps);
void display_loading_screen(rpg_t *rpg);
int main(void);
void mouvement(rpg_t *rpg, entity_t *list_entity, map_t *maps);
void city_reading(map_t *map_reading);
void map_reading(map_t *map_reading);
void cave_reading(map_t *map_reading);
void boss_reading(map_t *map_reading);
void init_mc_life(rpg_t *rpg, global_data_t global_data,
    entity_t *list_entity);
void load_map(rpg_t *rpg, global_data_t global_data, entity_t *entity,
    map_t *maps);
void window_event_handler(rpg_t *rpg, entity_t *entity,
    global_data_t global_data);
int main_menu_event_handler(rpg_t *rpg, entity_t *entity,
    global_data_t global_data);
void main_menu(rpg_t *rpg, entity_t *entity, global_data_t global_data);
int check_close(rpg_t *rpg, entity_t *entity, global_data_t global_data);
void init_win_screen(rpg_t *rpg, global_data_t global_data,
    entity_t *list_entity);
void init_all(rpg_t *rpg, global_data_t global_data, entity_t *entity);
void init_pause_play(rpg_t *rpg, global_data_t global_data, entity_t *entity);
void init_pause_exit(rpg_t *rpg, global_data_t global_data, entity_t *entity);
void init_pause_background(rpg_t *rpg, global_data_t global_data,
    entity_t *entity);
void play_music(rpg_t *rpg, global_data_t global_data, entity_t *list_entity,
    map_t *maps);
void init_the_sword_again(rpg_t *rpg, global_data_t global_data,
    entity_t *list_entity);
void pause_menu(rpg_t *rpg, entity_t *entity, global_data_t global_data);
void inventory(rpg_t *rpg, entity_t *list_entity, global_data_t global_data);
void init_inventory(rpg_t *rpg, global_data_t global_data, entity_t *entity);
void init_inventory_background(rpg_t *rpg, global_data_t global_data,
    entity_t *entity);
void return_sword(rpg_t *rpg, entity_t *list_entity,
    global_data_t global_data);
void return_left_sword(rpg_t *rpg, entity_t *list_entity,
    global_data_t global_data);
void mc_heart(rpg_t *rpg, global_data_t global_data, entity_t *list_entity,
    map_t *maps);
void init_heart(rpg_t *rpg, global_data_t global_data, entity_t *list_entity);
void init_empty_heart(rpg_t *rpg, global_data_t global_data,
    entity_t *list_entity);
void init_mc_hearts(rpg_t *rpg, global_data_t global_data,
    entity_t *list_entity);
void game_over(rpg_t *rpg, entity_t *list_entity, global_data_t global_data);
void init_game_over(rpg_t *rpg, global_data_t global_data,
    entity_t *list_entity);
void init_lives(rpg_t *rpg, global_data_t global_data, entity_t *list_entity);
int is_hover(rpg_t *rpg, entity_t *entity);
int is_d_possible(rpg_t *rpg, entity_t *list_entity, map_t *maps);
int is_u_possible(rpg_t *rpg, entity_t *list_entity, map_t *maps);
int is_l_possible(rpg_t *rpg, entity_t *list_entity, map_t *maps);
int is_r_possible(rpg_t *rpg, entity_t *list_entity, map_t *maps);
int mouve_car(rpg_t *rpg, entity_t *list_entity, map_t *maps);
int mouve_cal(rpg_t *rpg, entity_t *list_entity, map_t *maps);
int mouve_cad(rpg_t *rpg, entity_t *list_entity, map_t *maps);
int mouve_cau(rpg_t *rpg, entity_t *list_entity, map_t *maps);
int mouve_br(rpg_t *rpg, entity_t *list_entity, map_t *maps);
int mouve_bl(rpg_t *rpg, entity_t *list_entity, map_t *maps);
int mouve_bu(rpg_t *rpg, entity_t *list_entity, map_t *maps);
int mouve_bd(rpg_t *rpg, entity_t *list_entity, map_t *maps);
int mouve_wd(rpg_t *rpg, entity_t *list_entity, map_t *maps);
int mouve_wu(rpg_t *rpg, entity_t *list_entity, map_t *maps);
int mouve_wl(rpg_t *rpg, entity_t *list_entity, map_t *maps);
int mouve_wr(rpg_t *rpg, entity_t *list_entity, map_t *maps);
int mouve_cd(rpg_t *rpg, entity_t *list_entity, map_t *maps);
int mouve_cu(rpg_t *rpg, entity_t *list_entity, map_t *maps);
int mouve_cl(rpg_t *rpg, entity_t *list_entity, map_t *maps);
int mouve_cr(rpg_t *rpg, entity_t *list_entity, map_t *maps);
void init_quest_text(global_data_t global_data,
    entity_t *list_entity, rpg_t *rpg);
void handle_clock(rpg_t *rpg, entity_t *list_entity);
void music_create(rpg_t *rpg, char *str);
void sword_attack(rpg_t *rpg, entity_t *list_entity);
void init_pnj(global_data_t global_data, entity_t *entity);
void init_boat(global_data_t global_data, entity_t *entity);
void fast_travel(rpg_t *rpg, entity_t *list_entity, map_t *maps);
void init_enemies(global_data_t global_data, entity_t *list_entity);
void handle_enemies(rpg_t *rpg, map_t *maps, entity_t *list_entity);
sfVector2f move_enemy_to_player(entity_t *list_entity,
    char *name_entity, int *moving, map_t *maps);
sfVector2f init_enemy_position(component_position_t *enemy_position);
void handle_animation(entity_t *list_entity, char *name_entity, int moving);
void init_particle(entity_t *list_entity, global_data_t global_data);
void spawn_enemies(entity_t *list_entity, map_t *maps);
void music_create(rpg_t *rpg, char *str);
void init_boss_enemy(entity_t *list_entity, global_data_t global_data);
void handle_boss(entity_t *list_entity, map_t *maps, rpg_t *rpg);
float compute_distance(component_position_t *pos1, sfVector2f pos2);
void win(rpg_t *rpg, entity_t *list_entity, global_data_t global_data);

#endif
