/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-myrpg-guillaume1.blondel
** File description:
** map_reading.c
*/

#include "../include/rpg.h"
# include <stdio.h>
# include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void map_reading(map_t *map_reading)
{
    int index = 0;
    FILE *file = fopen("./src/txt_map/collision_world_map.txt", "r");
    int eof = 0;
    char *pouet = NULL;
    size_t n;

    map_reading->current_map = 0;
    map_reading->world = malloc(101 * sizeof(char *));
    for (; eof != -1; index++) {
        eof = getline(&pouet, &n, file);
        map_reading->world[index] = malloc(strlen(pouet) + 1);
        strcpy(map_reading->world[index], pouet);
    }
    map_reading->world_size.x = 6720 / 140;
    map_reading->world_size.y = 4800 / 100;
    fclose(file);
}

void city_reading(map_t *map_reading)
{
    int index = 0;
    FILE *file = fopen("./src/txt_map/Ville.txt", "r");
    int eof = 0;
    char *pouet = NULL;
    size_t n;

    map_reading->town = malloc(41 * sizeof(char *));
    for (; eof != -1; index++) {
        eof = getline(&pouet, &n, file);
        map_reading->town[index] = malloc(strlen(pouet) + 1);
        strcpy(map_reading->town[index], pouet);
    }
    map_reading->town_size.x = 1680 / 35;
    map_reading->town_size.y = 1920 / 40;
    fclose(file);
}

void cave_reading(map_t *map_reading)
{
    int index = 0;
    FILE *file = fopen("./src/txt_map/ice_cave.txt", "r");
    int eof = 0;
    char *pouet = NULL;
    size_t n;

    map_reading->ice_cave = malloc(42 * sizeof(char *));
    for (; eof != -1; index++) {
        eof = getline(&pouet, &n, file);
        map_reading->ice_cave[index] = malloc(strlen(pouet) + 1);
        strcpy(map_reading->ice_cave[index], pouet);
    }
    map_reading->ice_cave_size.x = 1392 / 29;
    map_reading->ice_cave_size.y = 1968 / 41;
    fclose(file);
}

void boss_reading(map_t *map_reading)
{
    int index = 0;
    FILE *file = fopen("./src/txt_map/boss_map.txt", "r");
    int eof = 0;
    char *pouet = NULL;
    size_t n;

    map_reading->demon_castle = malloc(48 * sizeof(char *));
    for (; eof != -1; index++) {
        eof = getline(&pouet, &n, file);
        map_reading->demon_castle[index] = malloc(strlen(pouet) + 1);
        strcpy(map_reading->demon_castle[index], pouet);
    }
    map_reading->demon_castle_size.x = 912 / 20;
    map_reading->demon_castle_size.y = 2256 / 47;
    fclose(file);
}
