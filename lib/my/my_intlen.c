/*
** EPITECH PROJECT, 2018
** my_intlen
** File description:
** lengh of an int
*/

#include "my.h"

int my_intlen(int nb)
{
    int i = 1;

    while (nb > 9) {
        i++;
        nb = nb / 10;
    }
    return (i);
}
