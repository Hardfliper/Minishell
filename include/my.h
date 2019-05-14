/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** remove warnings
*/

#ifndef MY_H
#define MY_H

#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct command {
    char *first_arg;
    char **other_arg;
}command_t;

int check_no_command(char *command);
int my_strdif(char *str1, char *str2);
void leave_handle(int sig);
void mini_shell(char **env);
char *strcpy_after(char *dest, char const *src, int *start);
char **tab_to_double(char *str, char chr);
int my_putstr(char const *str);
void my_putchar(char c);
int my_strlen(char const *str);
int my_getnbr(char const *str);
char *my_strcpy(char *dest, char const *src);
char *my_revstr(char *str);
int my_put_nbr(int nb);
int ls(char *path);
int number(char *str);
void my_printf(char *str, ...);
int exec(char *arg, char **env);
void my_put_error(char *str);
int my_same_str(char *src, char *dest);
char *my_strcat(char *dest, char const *src);
void cd_management(char *command, char **env);
void environment(char **env);
int check_empty_cd(char *cd);
int builtin(char **env, char **command);

#endif
