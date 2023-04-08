/*
** EPITECH PROJECT, 2022
** struct_header
** File description:
** struct_point_define
*/

#ifndef _STRUCT_POINT_DEFINE_
    #define _STRUCT_POINT_DEFINE_
    #define TICKRATE 100
enum direction { UP, DOWN, RIGHT, LEFT };

typedef struct struct_point {
    int x;
    int y;
} point;
#endif
