/*
** EPITECH PROJECT, 2022
** structinfo.h
** File description:
** header
*/

#ifndef _STRUCT_INFO_DEF_
    #define _STRUCT_INFO_DEF_
typedef struct info {
    int max_x;
    int max_y;
    int man_x;
    int man_y;
    int dx;
    int dy;
    int key;
    int steps;
    int currentLevel;
    int level1;
    int level2;
    int level3;
    int obj_x;
    int obj_y;
    int nb_objects;
    int nb_murs;
    int restart_game;
    char f_name[256];
} info_def;
#endif
