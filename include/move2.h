/*
** EPITECH PROJECT, 2022
** move2.h
** File description:
** header
*/

#ifndef _MOVE2_
    #define _MOVE2_
    #include "struct_info_def.h"
int change_dir (info_def *m, int dx, int dy, char **map);
int move_destination (info_def *m, int dx, int dy, char **map);
int move_mur (info_def *m, int dx, int dy, char **map);
int move_couloir (info_def *m, int dx, int dy, char **map);
#endif
