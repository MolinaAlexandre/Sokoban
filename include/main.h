/*
** EPITECH PROJECT, 2022
** main.h
** File description:
** header file
*/

#ifndef _MAIN_
    #define _MAIN_
    #include "struct_info_def.h"
int find_player(info_def *data, char **map1);
int is_blocked (info_def *data, char **map);
int sokoban (int argc, char **argv, info_def *data,char **map1);
#endif
