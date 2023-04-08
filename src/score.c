/*
** EPITECH PROJECT, 2022
** bonus
** File description:
** score
*/
#include "my_printf.h"
#include "my.h"
#include <ncurses.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <curses.h>
#include <stdio.h>
#include "struct_info_def.h"
#include "get_number.h"
#include "struct.h"
#include "move1.h"
#include "map.h"
#include "utils.h"
#include "move2.h"
#include "check.h"
#include "touches.h"
#include "struct_point_define.h"
#include "player.h"
#include "help.h"
#include "bonus.h"

int save_level1 (info_def *data)
{
    if (data->level1 == 0)
        data->level1 = data->steps;
    else if (data->steps < data->level1)
        data->level1 = data->steps;
}

int save_level2 (info_def *data)
{
    if (data->level2 == 0)
        data->level2 = data->steps;
    else if (data->steps < data->level2)
        data->level2 = data->steps;
}

int save_level3 (info_def *data)
{
    if (data->level3 == 0)
        data->level3 = data->steps;
    else if (data->steps < data->level3)
        data->level3 = data->steps;
}

int save_score (info_def *data)
{
    switch (data->currentLevel){
    case '1':
        save_level1(data);
        break;
    case '2':
        save_level2(data);
        break;
    case '3':
        save_level3(data);
        break;
    default:
        break;
    }
    data->steps = 0;
}
