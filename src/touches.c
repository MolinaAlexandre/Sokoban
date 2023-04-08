/*
** EPITECH PROJECT, 2022
** touches
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
#include "move2.h"
#include "touches.h"

void touches (info_def *data, char **map1, int *fin, int c)
{
    data->key = c;
    switch (c) {
    case K_UP:
        if (data->man_y > 0) change_dir(data, 0, -1, map1);
        break;
    case K_DOWN:
        if (data->man_y < data->max_y) change_dir(data, 0, 1, map1);
        break;
    case K_LEFT:
        if (data->man_x > 0) change_dir(data, -1, 0, map1);
        break;
    case K_RIGHT:
        if (data->man_x < data->max_x) change_dir(data, 1, 0, map1);
        break;
    case K_QUIT:
        break;
    case k_RESTART:
        data->restart_game = 2; break;
    default: ;
    }
}
