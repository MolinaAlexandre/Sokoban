/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** player
*/

#ifndef _PLAYER_
    #define _PLAYER_
    #include "struct_info_def.h"
void find_player_inside(int yy, int xx, char **map1, info_def *data);
int find_player(info_def *data, char **map1);
int is_blocked (info_def *data, char **map);
#endif
