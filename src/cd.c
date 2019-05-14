/*
** EPITECH PROJECT, 2019
** cd
** File description:
** chdir
*/

#include "my.h"

int check_empty_cd(char *cd)
{
    int i = 2;

    while (cd[i] != '\0') {
        if (cd[i] != ' ' && cd[i] != '\n')
            return 1;
        i++;
    }
    return 0;
}

void go_to_home(char **env)
{
    int y = 0;
    char *home = NULL;

    while (env[y] != NULL) {
        if (env[y][0] == 'H' && env[y][1] == 'O' &&
            env[y][2] == 'M' && env[y][3] == 'E')
            break;
        y++;
    }
    home = malloc(sizeof(char) * (my_strlen(&env[y][5]) + 1));
    home = my_strcpy(home, &env[y][5]);
    chdir(home);
    free(home);
}

void cd_management(char *command, char **env)
{
    int y = 0;
    int start = 3;

    if (check_empty_cd(command) == 0)
        go_to_home(env);
    else {
        if (chdir(&command[3]) == -1)
        return;
    }
}
