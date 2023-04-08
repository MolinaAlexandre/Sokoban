/*
** EPITECH PROJECT, 2022
** my_strcpy
** File description:
** task1
*/

char *my_strcpy(char *dest, char const *str)
{
    int a = 0;
    while (str[a] != '\0'){
        dest[a] = str[a];
        a++;
    }
    if (dest[a] != '\0'){
        dest[a] = '\0';
        return dest;
    }
}
