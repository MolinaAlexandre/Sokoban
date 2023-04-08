/*
** EPITECH PROJECT, 2022
** move
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

int move_object_couloir (info_def *p, int dx, int dy, char **m)
{
    int x = p->man_x;
    int y = p->man_y;
    int xdx = p->man_x + dx;
    int ydy = p->man_y + dy;
    if ((m[ydy][xdx] == OBJET) && (m[y + 2 * dy][x + 2 * dx] == COULOIR) ){
        m[p->man_y + dy][p->man_x + dx] = COULOIR;
        m[p->man_y + 2 * dy][p->man_x + 2 * dx] = OBJET;
        p->man_y += dy;	p->man_x += dx;
        p->steps += 1;
        return 1;
    }
    return 0;
}

int move_object_destination (info_def *p, int dx, int dy, char **m)
{
    int x = p->man_x;
    int y = p->man_y;
    int xdx = p->man_x + dx;
    int ydy = p->man_y + dy;
    if ((m[ydy][xdx] == OBJET) && (m[y + 2 * dy][x + 2 * dx] == DESTINATION) ){
        m[y + dy][x + dx] = COULOIR;
        m[y + 2 * dy][x + 2 * dx] = OBJET_DEST;
        p->man_y += dy; p->man_x += dx;
        p->steps += 1;
        return 1;
    }
    return 0;
}

int move_objectdest_couloir (info_def *p, int dx, int dy, char **map)
{
    int x = p->man_x;
    int y = p->man_y;
    int xdx = p->man_x + dx;
    int ydy = p->man_y + dy;
    int x2dx = p->man_x + 2 * dx;
    int y2dy = p->man_y + 2 * dy;
    if ((map[ydy][xdx] == OBJET_DEST) && (map[y2dy][x2dx] == COULOIR) ){
        map[ydy][xdx] = DESTINATION;
        map[y2dy][x2dx] = OBJET;
        p->man_y += dy;	p->man_x += dx;
        p->steps += 1;
        return 1;
    }
    return 0;
}

int move_objectdest_destination (info_def *p, int dx, int dy, char **map)
{
    int x = p->man_x;
    int y = p->man_y;
    int xdx = p->man_x + dx;
    int ydy = p->man_y + dy;
    int x2dx = p->man_x + 2 * dx;
    int y2dy = p->man_y + 2 * dy;
    if ((map[ydy][xdx] == OBJET_DEST) && (map[y2dy][x2dx] == DESTINATION) ){
        map[ydy][xdx] = DESTINATION;
        map[y2dy][x2dx] = OBJET_DEST;
        p->man_y += dy;	p->man_x += dx;
        p->steps += 1;
        return 1;
    }
    return 0;
}

int move_objectdest_mur (info_def *m, int dx, int dy, char **map)
{
    if ((map[m->man_y + dy][m->man_x + dx] == OBJET_DEST) \
&& (map[m->man_y + 2 * dy][m->man_x + 2 * dx] == MUR)){
        return 1;
    }
    return 0;
}
