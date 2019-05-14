/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main
*/

#include "my.h"

void leave_handle(int sig)
{
    (void)sig;
    my_putstr("\n$> ");
}

int main(int ac, char **av, char **env)
{
    signal(SIGINT, leave_handle);
    mini_shell(env);
    return 0;
}
