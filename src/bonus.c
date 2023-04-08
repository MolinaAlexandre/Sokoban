/*
** EPITECH PROJECT, 2022
** bonus
** File description:
** bonus
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
#include "score.h"

int activate_colors (void)
{
    start_color();
    init_pair(1,COLOR_WHITE, COLOR_BLACK);
    init_pair(2,COLOR_GREEN, COLOR_BLACK);
    init_pair(3,COLOR_YELLOW, COLOR_BLACK);
    init_pair(4,COLOR_CYAN, COLOR_BLACK);
    init_pair(5,COLOR_MAGENTA, COLOR_BLACK);
    init_pair(6,COLOR_RED, COLOR_BLACK);
    return 0;
}

int best(info_def *data)
{
    if (data->level1 == 0 && data->level2 == 0 && data->level3 == 0){
        mvprintw (18, 5, "Pas de meilleurs scores pour le moment !");
    } else { mvprintw (18, 5, "Meilleurs scores");
    }
    if (data->level1 > 0)
        mvprintw (19,10,"Niveau 1 : %d",data->level1);
    if (data->level2 > 0)
        mvprintw (20,10,"Niveau 2 : %d",data->level2);
    if (data->level3 > 0)
        mvprintw (21,10,"Niveau 3 : %d",data->level3);
    refresh();
}

int display_splash(info_def *data)
{
    activate_colors();
    int y; int x; getmaxyx(stdscr,y,x);
    char *welcome = "Bienvenue sur SOKOBAN";
    char *by = "Bonus - Alexandre MOLINA";
    char *n1 = "Appuyez sur 1 niveau débutant";
    char *n2 = "Appuyez sur 2 niveau intermédiaire";
    char *n3 = "Appuyez sur 3 niveau expert";
    char *quit = "Appuyez sur 0 pour quitter\n";
    mvprintw (2,(x - my_strlen(welcome)) / 2,welcome);
    mvprintw (5,(x - my_strlen(by)) / 2, by);
    attron(COLOR_PAIR(2)); mvprintw (8,(x - my_strlen(n1)) / 2, n1);
    attron(COLOR_PAIR(3)); mvprintw (10,(x - my_strlen(n2)) / 2, n2);
    attron(COLOR_PAIR(6)); mvprintw (12,(x - my_strlen(n3)) / 2, n3);
    attroff(COLOR_PAIR(12)); attroff(COLOR_PAIR(6));
    mvprintw (15,(x - my_strlen(quit)) / 2, quit); attroff(COLOR_PAIR(3));
    best(data);
    refresh();
}

int splash_screen (info_def *data)
{
    int ch;
    display_splash(data);
    while ((ch = getchar()) < '0' || (ch > '3')){
        flash();
    }
    return ch;
}

int select_level (info_def *data)
{
    int level = splash_screen(data);
    switch (level){
    case '1':
        my_strcpy(data->f_name, "maps/map_level1.txt");
        break;
    case '2':
        my_strcpy(data->f_name, "maps/map_level2.txt");
        break;
    case '3':
        my_strcpy(data->f_name, "maps/map_level3.txt");
        break;
    default:
        break;
    }
    return level;
}
