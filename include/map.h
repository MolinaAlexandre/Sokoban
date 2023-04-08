/*
** EPITECH PROJECT, 2022
** map.h
** File description:
** header
*/

#ifndef _MAP_
    #define _MAP_
    #define MAP_MAX1 10
    #define MUR '#'
    #define COULOIR ' '
    #define JOUEUR 'P'
    #define OBJET 'X'
    #define DESTINATION 'O'
    #define OBJET_DEST '@'
    #include "struct_info_def.h"
void display_map (info_def *data, char **map1);
char **load_map (info_def *data, char **map1);
void map_display (info_def *data, char **map);
int do_this_inside(int c);
#endif
