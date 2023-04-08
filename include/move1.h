/*
** EPITECH PROJECT, 2022
** move1.h
** File description:
** header
*/

#ifndef _MOVE1_
    #define _MOVE1_
    #define MAP_MAX1 10
    #define MUR '#'
    #define COULOIR ' '
    #define JOUEUR 'P'
    #define OBJET 'X'
    #define DESTINATION 'O'
    #define OBJET_DEST '@'
    #include "struct_info_def.h"
int move_objectdest_mur (info_def *m, int dx, int dy, char **map);
int move_objectdest_destination (info_def *p, int dx, int dy, char **map);
int move_objectdest_couloir (info_def *p, int dx, int dy, char **map);
int move_object_destination (info_def *p, int dx, int dy, char **m);
int move_object_couloir (info_def *p, int dx, int dy, char **m);
#endif
