/*
** EPITECH PROJECT, 2022
** test
** File description:
** main.c
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
#include "score.h"

int sokoban (info_def *data, char **map1)
{
    char key; int c; int fin = 0;
    map_display(data, map1);
    while (fin == 0 && (c = getchar()) != K_QUIT && c != k_RESTART){
        touches(data, map1, &fin, c);
        map_display(data, map1);
        if (check_finish(data,map1) > 0 ){
            save_score(data); fin = 1;
        }
        if (check_no_moves(data,map1) == 0)
            fin = 2;
    }
    refresh();
    if (fin == 1){
        getchar(); return 1;
    }
    if (fin == 2 ){
        getchar(); return 0;
    }
    return c;
}

int maino(void)
{
    initscr();
    noecho();
    cbreak();
    timeout(TICKRATE);
    keypad(stdscr, TRUE);
    refresh();
    curs_set(0);
}

int do_this(info_def *data, char **map, int argc, char **argv)
{
    int c; struct_init_info_def(argv[argc - 1], data);
    get_nbr_cols(data);
    map = malloc (sizeof (char *) * (data->max_y + 1));
    data->restart_game = 1;
    while (data->restart_game >= 1){
        if (data->restart_game == 2)
            return 3;
        data->restart_game = 1;
        map = load_map (data, map);
        if (find_player(data, map) == 84)
            return 84;
        refresh(); display_map(data, map);
        refresh();
        c = sokoban(data, map);
        if (do_this_inside(c) == 1)
            return 1;
        if (do_this_inside(c) == 0)
            return 0;
    }
}

int main(int argc, char *argv[])
{
    WINDOW *w_sudokan; int offset_x = 0; int offset_y = 0; int i, ch;
    w_sudokan = newwin(13, 13, 0, 0); char **map = NULL;
    info_def *data = malloc (sizeof(info_def));
    if (argc == 2){
        if (argv[1][0] == '-' && argv[1][1] == 'h'){
            help();
            return 0;
        }
    }
    maino();
    while ((data->currentLevel = select_level(data)) != '0'){
        do_this(data, map, argc, argv);
        clear();
    }
    delwin(w_sudokan);
    curs_set(1);
    endwin();
    return 0;
}
