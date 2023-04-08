/*
** EPITECH PROJECT, 2022
** utils
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

int	read_one_line(int fd, int len, char **line)
{
    *line = malloc(sizeof(char *) * (len));
}
