/*
** EPITECH PROJECT, 2022
** touches.h
** File description:
** header
*/

#ifndef _TOUCHES_
    #define _TOUCHES_
    #include "struct_info_def.h"
    #define K_UP 65
    #define K_DOWN 66
    #define K_RIGHT 67
    #define K_LEFT 68
    #define K_QUIT 113
    #define k_RESTART ' '
void touches (info_def *data, char **map1, int *fin, int c);
#endif
