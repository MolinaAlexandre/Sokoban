/*
** EPITECH PROJECT, 2022
** move2
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
#include "utils.h"
#include "move1.h"

int move_couloir (info_def *m, int dx, int dy, char **map)
{
    if (map[m->man_y + dy][m->man_x + dx] == COULOIR){
        m->man_y += dy; m->man_x += dx;
        m->steps += 1;
        return 1;
    }
    return 0;
}

int move_mur(info_def *m, int dx, int dy, char **map)
{
    if (map[m->man_y + dy][m->man_x + dx] == MUR){
        return 1;
    }
    return 0;
}

int move_destination (info_def *m, int dx, int dy, char **map)
{
    if (map[m->man_y + dy][m->man_x + dx] == DESTINATION){
        m->man_y += dy; m->man_x += dx;
        m->steps += 1;
        return 1;
    }
    return 0;
}

int change_dir (info_def *m, int dx, int dy, char **map)
{
    if (move_couloir(m, dx, dy, map) == 1) return 0;
    if (move_destination(m, dx, dy, map) == 1) return 0;
    if (move_mur(m, dx, dy, map) == 1) return 0;
    if (move_object_couloir(m, dx, dy, map) == 1) return 0;
    if (move_object_destination(m, dx, dy, map) == 1) return 0;
    if (move_objectdest_couloir(m, dx, dy, map) == 1) return 0;
    if (move_objectdest_destination(m, dx, dy, map) == 1) return 0;
    if (move_objectdest_mur(m, dx, dy, map) == 1) return 0;
    return 0;
}
