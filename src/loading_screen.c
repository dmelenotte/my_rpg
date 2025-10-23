/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-myrpg-guillaume1.blondel
** File description:
** loading_screen
*/

#include "../include/rpg.h"

void init_loading_screen(rpg_t *rpg, sfVector2f position, sfVector2f size,
    sfVector2f new_pos)
{
    rpg->loading_screen = malloc(sizeof(loading_screen_t));
    rpg->loading_screen->mode = (sfVideoMode){1920, 1080, 32};
    sfRenderWindow_setFramerateLimit(rpg->window, 60);
    rpg->loading_screen->font = sfFont_createFromFile("assets/DS-DIGIB.TTF");
    rpg->loading_screen->text = sfText_create();
    rpg->loading_screen->music_loading =
    sfMusic_createFromFile("assets/music/boum.ogg");
    sfText_setString(rpg->loading_screen->text, "Loading game...");
    sfText_setFont(rpg->loading_screen->text, rpg->loading_screen->font);
    sfText_setCharacterSize(rpg->loading_screen->text, 26);
    sfText_setPosition(rpg->loading_screen->text, new_pos);
    rpg->loading_screen->progress_bar = sfRectangleShape_create();
    sfRectangleShape_setSize(rpg->loading_screen->progress_bar, size);
    sfRectangleShape_setFillColor(rpg->loading_screen->progress_bar, sfGreen);
    sfRectangleShape_setPosition(rpg->loading_screen->progress_bar, position);
}

void load_screen(rpg_t *rpg, float progress)
{
    sfRenderWindow_clear(rpg->window, sfBlack);
    sfRenderWindow_drawText(rpg->window,
        rpg->loading_screen->text, NULL);
    sfRectangleShape_setSize(rpg->loading_screen->progress_bar,
        (sfVector2f){500 * progress, 50});
    sfRenderWindow_drawRectangleShape(rpg->window,
        rpg->loading_screen->progress_bar, NULL);
    sfRenderWindow_display(rpg->window);
}

void destroy_loading_screen(rpg_t *rpg, sfClock *clock)
{
    sfText_destroy(rpg->loading_screen->text);
    sfFont_destroy(rpg->loading_screen->font);
    sfRectangleShape_destroy(rpg->loading_screen->progress_bar);
    sfClock_destroy(clock);
    sfMusic_destroy(rpg->loading_screen->music_loading);
    free(rpg->loading_screen);
}

void display_loading_screen(rpg_t *rpg)
{
    sfTime time;
    sfClock* clock;
    sfVector2f size = {500, 50};
    sfVector2f position = {sfRenderWindow_getSize(rpg->window).x / 2 - size.x
        / 2, sfRenderWindow_getSize(rpg->window).y / 2 - size.y / 2};
    sfVector2f new_pos = {position.x, position.y - 50};
    float progress;

    init_loading_screen(rpg, position, size, new_pos);
    clock = sfClock_create();
    sfMusic_play(rpg->loading_screen->music_loading);
    while (sfRenderWindow_isOpen(rpg->window)) {
        time = sfClock_getElapsedTime(clock);
        progress = sfTime_asSeconds(time) / 2.0f;
        if (progress > 1.0f)
            break;
        load_screen(rpg, progress);
    }
    destroy_loading_screen(rpg, clock);
}
