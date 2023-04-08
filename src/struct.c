/*
** EPITECH PROJECT, 2022
** struct
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

void struct_init_info_def (char *filename, info_def *data)
{
    data->max_x = 0;
    data->max_y = 0;
    data->steps = 0;
    data->dx = 0;
    data->dy = 0;
}

void struct_display_info_def (info_def *data)
{
    printw ("Nom du fichier :%s\n", data->f_name);
    printw ("Max X :%d\n", data->max_x);
    printw ("Max Y :%d\n", data->max_y);
}
