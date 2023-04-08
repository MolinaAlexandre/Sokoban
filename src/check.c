/*
** EPITECH PROJECT, 2022
** check.c
** File description:
** sokoban
*/

#include <ncurses.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <curses.h>
#include <stdio.h>
#include "struct_info_def.h"
#include "get_number.h"
#include "struct.h"
#include "main.h"
#include "move1.h"
#include "player.h"

int check_finish(info_def *data, char **map)
{
    int end = 0;
    int mur_present = 0;
    data->nb_objects = 0;
    for (int y = 1; y < data->max_y ; y++){
        for (int x = 1; x < data->max_x ; x++){
            data->obj_x = x;
            data->obj_y = y;
            mur_present += is_blocked(data, map);
        }
    }
    if (data->nb_objects * 2 <= mur_present){
        end = 1;
    }
    return end;
}

int check_inside (info_def *data, char **map, int y, int end)
{
    for (int x = 0; x < data->max_x; x++){
        if (map[y][x] == DESTINATION)
            end ++;
    }
    return end;
}

int check_no_moves (info_def *data,char **map)
{
    int end = 0;
    for (int y = 0; y < data->max_y ; y++) {
        end = check_inside (data, map, y, end);
    }
    return end;
}

int check_map_inside(int char_bad, char **map, int x, int y)
{
    if ((map[y][x] == JOUEUR) || (map[y][x] == MUR) || \
(map[y][x] == COULOIR) || (map[y][x] == OBJET) || \
(map[y][x] == DESTINATION) || (map[y][x] == ' ')) {
    return char_bad *= 1;
} else {
    return char_bad = 0;
    }
}

int check_map(info_def *data, char **map)
{
    int char_bad = 1;
    for (int y = 0; y < data->max_y ; y++) {
        for (int x = 0; x < data->max_x ; x++){
            char_bad = check_map_inside(char_bad,map,x,y);
        }
    }
    return char_bad;
}
