/*
** EPITECH PROJECT, 2022
** get_number
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

void get_nbr_cols (info_def *data)
{
    char ch[10];
    int cpt = 0;
    int rdsize = 0;
    int txtfile = open(data->f_name,O_RDONLY);
    while ((rdsize = read (txtfile,ch,1)) > 0){
        while (ch[0] != '\n' && rdsize > 0) {
            cpt++;
            rdsize = read (txtfile, ch, 1);
        }
        if (cpt > data->max_x) data->max_x = cpt;
        cpt = 0;
        data->max_y += 1;
    }
}

void get_nbr_lines (info_def *data)
{
    int offset_number = 0; int temp_y = 0; int cpt = 0;
    int txtfile = open(data->f_name,O_RDONLY); char ch[1]; char nb_lignes[10];
    read (txtfile, ch, 1);
    while (read(txtfile, ch, 1) > 0) {
        if (ch[0] == '\n') {
            temp_y++;
        }
    }
    data->max_y = temp_y + 1;
}

void nb_murs_coins (int element1, int element2, info_def *data, char **map)
{
    int x = data->obj_x;
    int y = data->obj_y;
    if (map[y][x - 1] == element1 && \
map[y - 1][x] == element2) data->nb_murs += 2;
    if (map[y - 1][x] == element1 && \
map[y][x + 1] == element2) data->nb_murs += 2;
    if (map[y][x + 1] == element1 && \
map[y + 1][x] == element2) data->nb_murs += 2;
    if (map[y + 1][x] == element1 && \
map[y][x - 1] == element2) data->nb_murs += 2;
}
