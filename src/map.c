/*
** EPITECH PROJECT, 2022
** map
** File description:
** sokoban
*/

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
#include "utils.h"
#include "map.h"

void display_map (info_def *data, char **map1)
{
    for (int yy = 0; yy < data->max_y; yy++){
        for (int xx = 0; xx < data->max_x; xx++){
            mvprintw (yy,xx,"%c ",map1[yy][xx]);
        }
        printw ("\n");
    }
}

char **load_map(info_def *data, char **map1)
{
    int x = data->max_x;
    int y = data->max_y;
    char *lng;
    int txtfile = open(data->f_name, O_RDONLY);
    int ligne = 0;
    int col = 0;
    *map1 = malloc(sizeof(char) * ((x + 1)));
    lng = malloc((sizeof(char *)) * (x + 1));
    int size = read (txtfile, lng, 1);
    while (size > 0) {
        if (lng[0] == '\n'){
            map1[ligne][col] = lng[0];
            ligne++;
            col = 0;
            read_one_line (txtfile, x + 1, map1 + ligne);
        } else { map1[ligne][col++] = lng[0];}
        size = read(txtfile, lng, 1);
    }
    free(lng);
    return &*map1;
}

void map_display_inside (int y, int x, info_def *data, char **map)
{
    if (y == data->man_y && x == data->man_x) {
        attron(COLOR_PAIR(2));
        mvprintw (y + 1, x, "%c",JOUEUR);
        attroff(COLOR_PAIR(2));
    } else{
    switch (map[y][x]){
        case MUR:
            attron (COLOR_PAIR(3)); mvprintw (y + 1, x, "%c", map[y][x]);
            attroff(COLOR_PAIR(3)); break;
        case OBJET:
            attron(COLOR_PAIR(4)); mvprintw (y + 1, x, "%c", map[y][x]);
            attron(COLOR_PAIR(4)); break;
        case DESTINATION:
            attron(COLOR_PAIR(5));
            mvprintw (y + 1, x, "%c", map[y][x]);
            attron(COLOR_PAIR(5)); break;
        default: mvprintw(y + 1, x, "%c", map[y][x]);
        }
    }
}

void map_display (info_def *data, char **map)
{
    clear();
    mvprintw (0,0,"Moves:%d map:%s",data->steps, data->f_name);
    for (int y = 0; y < data->max_y ; y++){
        for (int x = 0; x < data->max_x ; x++){
            map_display_inside(y, x, data, map);
        }
    }
    int dx,dy;
    char *str = "enlarge the terminal.";
    getmaxyx(stdscr, dy, dx);
    if ((dx < data->max_x) || (dy < data->max_y) != 0)
        mvprintw(dy / 2, (dx - strlen(str)) / 2, str);
    refresh();
}

int do_this_inside(int c)
{
    if (c == 1 || c == 'q'){
        endwin();
        return 1;
    }
    if (c == 0){
        endwin();
        return 0;
    }
    if (c == 'c')
        endwin();
}
