/*
** EPITECH PROJECT, 2022
** display
** File description:
** task03
*/

#include <stdarg.h>
#include "../../include/my.h"

void disp_stdarg(char *s, ...)
{
    int length = 0;
    va_list list;
    length = my_strlen(s);
    va_start(list,s);
    for (int i = 0; i < length; i++){
        if (s[i] == 'c') {
            char c = (char) va_arg(list, int);
            my_putchar(c);
        }
        if (s[i] == 's')
            my_putstr(va_arg(list,const char *));
        if (s[i] == 'i')
            my_putnbr(va_arg(list, int));
        my_putchar('\n');
    }
    va_end(list);
}
