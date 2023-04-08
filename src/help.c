/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** help
*/

#include <unistd.h>

void help(void)
{
    write(1, "USAGE\n\n     ./my_sokoban map\n", 30);
    write(1, "DESCRIPTION\n", 13);
    write(1, "\tmap file representing the warehouse map, containing '#' for walls,\n", 69);
    write(1, "\t'P' for the player, 'X' for boxes and 'O' for storage locations.\n", 67);
}
