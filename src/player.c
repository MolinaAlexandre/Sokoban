/*
** EPITECH PROJECT, 2022
** player
** File description:
** player
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
#include "move1.h"
#include "map.h"
#include "utils.h"
#include "move2.h"
#include "check.h"
#include "touches.h"
#include "struct_point_define.h"
#include "player.h"

int is_blocked (info_def *data, char **map)
{
    int x = data->obj_x;
    int y = data->obj_y;
    data->nb_murs = 0;
    if (map[y][x] == OBJET){
        data->nb_objects += 1;
        nb_murs_coins(MUR, MUR, data, map);
        nb_murs_coins(MUR, OBJET_DEST, data, map);
        nb_murs_coins(OBJET_DEST, MUR, data, map);
        nb_murs_coins(OBJET_DEST, OBJET_DEST, data, map);
        nb_murs_coins(MUR, OBJET, data, map);
        nb_murs_coins(OBJET, MUR, data, map);
    }
    return data->nb_murs;
}

void find_player_inside(int yy, int xx, char **map1, info_def *data)
{
    if (map1[yy][xx] == JOUEUR){
        data->man_x = xx;
        data->man_y = yy;
        map1[yy][xx] = ' ';
    }
}

int find_player(info_def *data, char **map1)
{
    for (int yy = 0; yy < data->max_y; yy++){
        for (int xx = 0; xx < data->max_x; xx++){
            find_player_inside(yy, xx, map1, data);
        }
    }
}
